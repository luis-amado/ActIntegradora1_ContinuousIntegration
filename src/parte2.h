#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> manacher_odd(string s)
{
    int n = s.size();
    s = "$" + s + "^";
    vector<int> palindromes_length(n + 2);
    int left = 1, right = 1;
    for (int i = 1; i <= n; i++)
    {
        palindromes_length[i] =
            max(0, min(right - i, palindromes_length[left + (right - i)]));
        while (s[i - palindromes_length[i]] == s[i + palindromes_length[i]])
        {
            palindromes_length[i]++;
        }
        if (i + palindromes_length[i] > right)
        {
            left = i - palindromes_length[i], right = i + palindromes_length[i];
        }
    }
    return vector<int>(begin(palindromes_length) + 1,
                       end(palindromes_length) - 1);
}

// complexity o(n)
void manacher(string fileName)
{
    // getting the input
    ifstream file(fileName);
    string s, line;
    while (getline(file, line))
    {
        s += line;
        s += '\n';
    }
    // makes string of odd length
    string t;
    for (auto c : s)
    {
        t += string("#") + c;
    }
    // uses algorithm to solve for odd length palindromes
    auto res = manacher_odd(t + "#");
    vector<int> palindromes_length = vector<int>(begin(res) + 1, end(res) - 1);
    int max_length = 0;
    int start_pos = 0, end_pos = 0;

    // find largest palindrome and put it in right format
    for (int i = 0; i < palindromes_length.size(); i++)
    {
        int curr_lenght = palindromes_length[i];
        int full_length = ((curr_lenght - 1) * 2 + 1) / 2;

        if (full_length > max_length)
        {
            max_length = max(max_length, full_length);
            int center = i / 2;
            if (i % 2 == 0)
            {
                // odd
                start_pos = center - max_length / 2;
                end_pos = center + max_length / 2;
            }
            else
            {
                // even
                start_pos = center - max_length / 2 + 1;
                end_pos = center + max_length / 2;
            }
        }
    }
    string largest_palindrome = s.substr(start_pos, end_pos - start_pos + 1);

    cout << start_pos + 1 << ' ' << end_pos + 1 << ' ' << largest_palindrome << endl;
}
