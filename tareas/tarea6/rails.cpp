/*
Name: Juan Diego Valencia
code: 8977467
tarea6 - Estructuras de datos - 2023-1

Complejidad computacional:
Este programa tiene una complejidad computacional lineal O(n), siendo n el tamaño de la pila que se desea construir, ya que el programa comprueba
que si la combinación que se ingresó puede lograrse a partir de la fila ordenada, haciendo las modificaciones necesarias y posibles para encontrar si 
es posible, esto se revisa al chequear si la pila esta o no vacía.

*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void compare(int n, int l)
{
    bool flag = true;
    int k;
    vector<int> ini;
    ini.push_back(l);
    for (int i = 0; i < n && flag; i++)
    {
        cin >> k;
        ini.push_back(k);
        // printf("k: %d ", k);
    }

    stack<int> ans;
    int pos = 1, i = 0;
    while (pos <= n + 1 && flag)
    {
        ans.push(pos);
        bool ansFlag = true;

        while (!ans.empty() && ans.top() == ini[i] && ansFlag)
        {
            ans.pop();

            i++;
            if (i > n)
                ansFlag = false;
        }
        pos++;
    }

    if (ans.empty())
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
    int n, k;
    cin >> n;
    while (n != 0)
    {
        cin >> k;
        while (k != 0)
        {
            compare(n - 1, k);
            cin >> k;
        }

        printf("\n");
        cin >> n;
    }

    return 0;
}
