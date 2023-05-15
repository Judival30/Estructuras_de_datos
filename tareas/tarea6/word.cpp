/*
Name: Juan Diego Valencia
code: 8977467
tarea6 - Estructuras de datos - 2023-1

Complejidad computacional:
Este programa tiene una complejidad computacional O(n*m), siendo n la cantidad de conjuntos de letras que se le ingresan, y m la cantidad de palabras que 
se desean comprobar, ya que el programa compara cada conjunto de letras con la totalidad de las palabras.
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

void compare(list<string> &w, list<vector<char>> &l)
{

    for (auto letter = l.begin(); letter != l.end(); letter++)
    {
        int numW = 0;
        vector<char> tmp = *letter;
        for (auto word = w.begin(); word != w.end(); word++)
        {
            string p = *word;
            if (tmp.size() >= p.size())
            {
                int cont = 0;
                bool flag = true;

                vector<int> available(26, 0);
                for (int i = 0; i < tmp.size(); ++i)
                    available[tmp[i] - 97]++;

                for (int i = 0; i < p.size() && flag; ++i)
                {
                    if (available[p[i] - 97] <= 0)
                        flag = false;

                    available[p[i] - 97]--;
                }
                if (flag)
                    numW++;
            }
        }
        printf("%d\n", numW);
    }
}

int main()
{
    string n;
    cin >> n;
    list<string> word;
    while (n != "#")
    {
        word.push_back(n);
        cin >> n;
    }
    list<vector<char>> letter;
    cin.ignore();
    getline(cin, n);
    while (n != "#")
    {
        vector<char> tmp;
        for (int i = 0; i < n.size(); i += 2)
            tmp.push_back(n[i]);
        letter.push_back(tmp);
        tmp.clear();
        getline(cin, n);
    }
    compare(word, letter);
    word.clear();
    letter.clear();

    return 0;
}
