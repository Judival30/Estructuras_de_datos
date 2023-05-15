/*
Name: Juan Diego Valencia
code: 8977467
tarea6 - Estructuras de datos - 2023-1

Complejidad computacional:
Este programa tiene una complejidad cuadratica O(n^2), ya que en un primer instante leerá todas las instrucciones ingresadas (d), para posteriormente realizar
los cambios correspondientes a la prioridad de los pacientes que ingresan con la E, para esto se recorre la lista que representa la cola con el fin de encontrar
el iterador y poder borrar el valor. Por esta razón tiene una complejidad O(n^2)

pd:
(profe yo se que se puede lograr una complejidad lineal con los mapas, pero no tuve el tiempo de poder volver a retomar el problema, pido disculpas y espero 
que esto no tenga tanta repercusion en la nota, gracias)

*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    list<int> ans;
    string n, in;
    int p, d, cases = 1, pos;
    cin >> p >> d;
    while (p != 0 && d != 0)
    {
        printf("Case %d:\n", cases);
        if (p < 2000)
        {
            for (int i = 1; i <= p; i++)
                ans.push_back(i);
        }
        else
        {
            for (int i = 1; i <= 2000; i++)
                ans.push_back(i);
        }

        for (int i = 0; i < d; i++)
        {
            cin >> in;
            if (in == "E")
            {
                cin >> pos;
                bool flag = true;
                for (list<int>::iterator it = ans.begin(); it != ans.end() && flag; it++)
                {
                    if (*it == pos)
                    {
                        ans.erase(it);
                        flag = false;
                    }
                }
                ans.push_front(pos);
            }
            else
            {
                list<int>::iterator ref = ans.begin();
                printf("%d\n", *ref);
                ans.erase(ref);
                ans.push_back(*ref);
            }
        }
        cases++;
        ans.clear();
        cin >> p >> d;
    }
    return 0;
}
