#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<string> separator(string cad)
{
    vector<string> list;
    string newWord;
    int save = 0;
    int secondSpace = 0, mark = 0;
    for (int j = 0; j < cad.length(); j++)
    {
        if (cad[j] == ' ' && secondSpace == 1)
        {
            newWord = "/";
            list.push_back(newWord);
            save = j + 1;
        }
        else if (cad[j] == ' ')
        {

            newWord = cad.substr(save, j - save);
            list.push_back(newWord);
            save = j + 1;
            secondSpace = 1;
        }
        else
        {
            secondSpace = 0;
        }
    }
    newWord = cad.substr(save);
    list.push_back(newWord);
    return list;
}

int main()
{
    vector<string> key = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                          ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--",
                          "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-.", "/"};

    vector<string> var = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5",
                          "6", "7", "8", "9", ".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "@", " "};

    int n, k = 0, j = 0;
    scanf("%d", &n);
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string cad;
        getline(cin, cad);
        vector<string> ans = separator(cad);
        int j = 0, k;
        int flag = 0;
        cout << "Message #" << i << endl;
        while (j < ans.size())
        {
            k = 0;

            while (k < key.size() && flag == 0)
            {

                if (ans[j] == key[k])
                {
                    cout << var[k];
                    flag = 1;
                }
                k++;
            }
            flag = 0;
            j++;
        }
        cout << endl;
        if (i < n)
        {
            printf("\n");
        }
    }
    return 0;
}
