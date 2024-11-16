#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// Complexity O(pattern.size() + fullText.size()))
vector<int> ZAlg(string pattern, string fullText)
{
    string s = pattern + "$" + fullText;

    vector<int> ZArr(s.size(), 0);
    int l, r;
    l = r = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (r < i || r == l)
        {
            int count = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (s[i + j] == s[j])
                {
                    count++;
                }
                else
                {
                    ZArr[i] = count;
                    l = i;
                    // R is inclusive
                    r =
                        count == 0 ? l
                                   : i + count - 1;
                    break;
                }
            }
        }
        else
        {
            // i is in Z box
            int prefix_index = i - l;
            if (ZArr[prefix_index] == 0)
            {
                ZArr[i] = 0;
                continue;
            }

            if (ZArr[prefix_index] + i >= r)
            {
                // Compare with normal alg, starting in r
                int count = r - i + 1;
                for (int j = r - i + 1; j < s.size(); j++)
                {
                    if (s[i + j] == s[j])
                    {
                        count++;
                    }
                    else
                    {
                        ZArr[i] = count;
                        l = i;
                        // R is inclusive
                        r =
                            count == 0 ? l
                                       : i + count - 1;
                        break;
                    }
                }
                continue;
            }

            // Else, ZArr[prefix_index] + i < r, we can copy
            ZArr[i] = ZArr[prefix_index];
        }
    }

    return ZArr;
}

// Complexity O(mcodeX.size() + transmissionX.size())
void printAnsP1_2(vector<int> v, int len)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == len)
        {
            int position = i - len - 1;
            cout << "true " << position + 1 << endl;
            return;
        }
    }
    cout << "false" << endl;
}

// Complexity O(mcodeX.size() + transmissionX.size())
void part1_2(string transmissionFilename, string mcodeFilename)
{
    ifstream transmissionFile(transmissionFilename);
    string transmission, line;
    while (getline(transmissionFile, line))
    {
        transmission += line;
        transmission += '\n';
    }

    ifstream mcodeFile(mcodeFilename);
    string mcode;
    while (getline(mcodeFile, line))
    {
        mcode += line;
        mcode += '\n';
    }

    // Apply Z algorithm to find all occurrences of mcode in transmission
    vector<int> ans = ZAlg(mcode, transmission);
    printAnsP1_2(ans, mcode.size());
}