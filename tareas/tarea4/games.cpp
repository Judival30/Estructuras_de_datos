#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<string> alpha, string letter)
{
    int flag = 0, ans;
    for (int i = 0; i < alpha.size() and flag == 0; i++)
    {
        if (alpha[i] == letter)
        {
            ans = i + 1;
            flag = 1;
        }
    }
    return ans;
}

string compare(string s1, string s2, int szs, vector<string> alpha)
{
    int n, m, flag = 0, x;
    string ans = "", letter, next;
    if (s1.size() > s2.size())
    {
        n = s1.size();
        m = s2.size();
    }
    else
    {
        n = s2.size();
        m = s1.size();
    }
    for (int i = 0; i < n and flag == 0; i++)
    {
        if (i == m)
        {
            flag = 1;
        }
        else if (s1[i] != s2[i])
        {
            flag = 1;
        }
        else if (s1[i] == s2[i])
        {
            ans += s1[i];
        }
    }
    return ans;
}

int main()
{
    vector<string> alpha = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    int n = 1;
    string word;
    vector<string> list;
    string s1, s2, wordAns, letter, ref;
    while (n != 0)
    {
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            getline(cin, word);
            list.push_back(word);
        }
        if (n != 0)
        {
            // ordenar
            sort(list.begin(), list.end());
            // escoger los dos elementos centrales
            s1 = list[(n / 2) - 1];
            s2 = list[n / 2];
            wordAns = compare(s1, s2, n, alpha);

            if (wordAns == s1 || wordAns == s2)
            {
                cout << wordAns << endl;
            }
            else if (s1.size() < s2.size() && wordAns.size() == s1.size() - 1)
            {
                cout << s1 << endl;
            }
            else
            {
                int x;
                letter = s1[wordAns.size()];
                x = find(alpha, letter);
                ref = wordAns;
                ref += alpha[x];
                if (ref == s2)
                {
                    wordAns += s1[wordAns.size()];
                    if (s1[wordAns.size()] == 'Z')
                    {
                        wordAns += s1[wordAns.size()];
                        letter = s1[wordAns.size()];
                        x = find(alpha, letter);
                        wordAns += alpha[x];
                        cout << wordAns << endl;
                    }
                    else
                    {
                        letter = s1[wordAns.size()];
                        x = find(alpha, letter);
                        wordAns += alpha[x];
                        cout << wordAns << endl;
                    }
                }
                else
                {
                    wordAns += alpha[x];
                    cout << wordAns << endl;
                }
            }
            list.clear();
        }
    }
    return 0;
}
