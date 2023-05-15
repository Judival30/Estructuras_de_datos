/*
Name: Juan Diego Valencia
code: 8977467
tarea6 - Estructuras de datos - 2023-1

Complejidad computacional:
Este programa tiene una complejidad lineal O(n), ya que recorre la linea de texto ingresada y realiza los cambios al presionar Inicio y Fin,
haciendo todo su proceso en un ciclo for.

*/
#include <iostream>
#include <list>

using namespace std;

void printLista(list<char> &l)
{
    for (list<char>::iterator pos = l.begin(); pos != l.end(); pos++)
    {
        cout << *pos;
    }
    cout << endl;
}

int main()
{
    string n;

    while (cin >> n)
    {
        bool flagFront = false;
        list<char> ans;
        int pos = 0;

        for (int i = 0; i < n.size(); i++)
        {
            // ultimo cambio en el if pos = 0 a pos = 1
            if (flagFront && pos != 0 && n[i] == '[')
                pos = 0;

            if (n[i] == '[')
            {
                flagFront = true;
            }
            else if (n[i] == ']')
            {
                flagFront = false;
                pos = 0;
            }

            else if (flagFront)
            {
                list<char>::iterator it = ans.begin();
                advance(it, pos);
                ans.insert(it, n[i]);
                pos++;
            }
            else
                ans.push_back(n[i]);
        }

        printLista(ans);
        ans.clear();
    }

    return 0;
}