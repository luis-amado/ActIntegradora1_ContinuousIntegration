#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// complejidad: O(n * m)
void longestSubstring(string s1, string s2, int &start, int &end)
{

    vector<vector<int>> matrix(s2.length() + 1,
                               vector<int>(s1.length() + 1, 0));

    int maxLength = 0;
    int endPosition = -1;

    for (int i = 1; i <= s2.length(); i++)
    {
        for (int j = 1; j <= s1.length(); j++)
        {
            if (s2[i - 1] == s1[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;

                if (matrix[i][j] > maxLength)
                {
                    maxLength = matrix[i][j];
                    endPosition = j;
                }
            }
        }
    }

    start = endPosition - maxLength + 1;
    end = endPosition;
}

string getFileContent(string fileName)
{
    ifstream file(fileName);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void part3(string file1, string file2)
{
    string file1Content = getFileContent(file1);
    string file2Content = getFileContent(file2);

    int substringStart, substringEnd;
    longestSubstring(file1Content, file2Content, substringStart, substringEnd);

    cout << substringStart << ' ' << substringEnd << ' ';

    for (int i = substringStart; i <= substringEnd; i++)
    {
        cout << file1Content[i - 1];
    }
    cout << endl;
}
