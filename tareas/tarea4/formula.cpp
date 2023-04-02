/*
Name: Juan Diego Valencia
code: 8977467
tarea4 - Estructuras de datos - 2023-1
UVa code: 11835

Complejidad computacional:

Primero que todo, dividiremos el programa en dos partes, la lectura de datos y
el proceso logico. Para empezar, este punto se resolvió mediante el registro de
los datos en forma semimatricial, es decir, cada linea de input se ingresó a un
vector de vector, la primera matriz tiene tamaño nG * nP, que corresponden a la
cantidad de carreras por el numero de pilotos, la segunda semimatriz es la compuesta
por el numero de sistemas de puntuación por la cantidad de lugares que se puntuan,
la llamo semi matriz porque en algunos casos no es rectangular. Por lo tanto, la
lectura de datos tiene una complejidad de O(nG*nP + nSys*m), siendo m el parametro
para estimar las columnas de la segunda matriz

En segundo lugar la parte logica se desarrolla en la función sumPoints(), la cual
calcula las puntos de cada piloto mediante el recorrido de las dos matrices, por
lo que se analiza el total de la carreras con cada sistema de puntuación, por lo que
la complejidad de esta función es O(nSys * nG * m * nP) que sería el recorrido de las 
dos matrices, finalmente la función winner recorre el vector que contiene los puntos 
acorde con cada sistema de puntuación por lo que su complejidad sería O(nSys * nP).

Por lo tanto la complejidad del programa por inspección es O(nG*nP + nSys*m + nSys * nG * m * nP + nSys * nP)
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void winner(vector<int> points)
{
    int max = points[0], cont = 0;
    for (int i = 1; i < points.size(); i++)
    {
        if (max < points[i])
        {
            max = points[i];
            cont = i;
        }
        if (points[i] == max)
        {
            cont = i;
        }
    }

    for (int i = 0; i < points.size(); i++)
    {
        if (points[i] == max)
        {
            if (i != cont)
            {
                cout << i + 1 << " ";
            }
            else
            {
                cout << i + 1;
            }
        }
    }
    cout << endl;
}

void sumPoints(vector<vector<int>> totalGrandP, vector<vector<int>> totalSystems, int nG, int nP, int nSys)
{
    vector<int> sumPt;
    int n;
    int k, flag;
    for (int i = 0; i < nSys; i++)
    {
        sumPt.resize(nP, 0);
        int position;
        for (int j = 0; j < nG; j++)
        {
            position = 1;
            for (int m = 0; m < totalSystems[i].size(); m++)
            {
                k = 0;
                flag = 0;
                while (k < nP && flag == 0)
                {
                    if (position <= totalSystems[i].size())
                    {
                        if (totalGrandP[j][k] == position)
                        {
                            n = sumPt[k];
                            n += totalSystems[i][position - 1];
                            sumPt[k] = n;
                            position++;
                            flag = 1;
                            k = 0;
                        }
                    }
                    else
                    {
                        flag = 1;
                    }
                    k++;
                }
            }
        }

        winner(sumPt);
        sumPt.clear();
    }
}

int main()
{
    int nG = 1, nP = 1, x, nSys, pointed, pt;
    vector<vector<int>> tG;
    vector<vector<int>> tSysPt;
    vector<int> individual;
    vector<int> ans;
    while (nG != 0 && nP != 0)
    {
        scanf("%d", &nG);
        scanf("%d", &nP);
        for (int i = 0; i < nG; i++)
        {
            for (int j = 0; j < nP; j++)
            {
                scanf("%d", &x);
                individual.push_back(x);
            }
            tG.push_back(individual);
            individual.clear();
        }
        if (nG != 0 && nP != 0)
        {
            scanf("%d", &nSys);
        }
        else
        {
            nSys = 0;
        }
        for (int i = 0; i < nSys; i++)
        {
            scanf("%d", &pointed);
            for (int j = 0; j < pointed; j++)
            {
                scanf("%d", &pt);
                individual.push_back(pt);
            }
            tSysPt.push_back(individual);
            individual.clear();
        }

        sumPoints(tG, tSysPt, nG, nP, nSys);
        tG.clear();
        tSysPt.clear();
    }
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void winner(vector<int> points)
{
    int max = points[0], cont = 0;
    for (int i = 1; i < points.size(); i++)
    {
        if (max < points[i])
        {
            max = points[i];
            cont = i;
        }
        if (points[i] == max)
        {
            cont = i;
        }
    }

    for (int i = 0; i < points.size(); i++)
    {
        if (points[i] == max)
        {
            if (i != cont)
            {
                cout << i + 1 << " ";
            }
            else
            {
                cout << i + 1;
            }
        }
    }
    cout << endl;
}

void sumPoints(vector<vector<int>> totalGrandP, vector<vector<int>> totalSystems, int nG, int nP, int nSys)
{
    vector<int> sumPt;
    int n;
    int k, flag;
    for (int i = 0; i < nSys; i++)
    {
        sumPt.resize(nP, 0);
        int position;
        for (int j = 0; j < nG; j++)
        {
            position = 1;
            for (int m = 0; m < totalSystems[i].size(); m++)
            {
                k = 0;
                flag = 0;
                while (k < nP && flag == 0)
                {
                    if (position <= totalSystems[i].size())
                    {
                        if (totalGrandP[j][k] == position)
                        {
                            n = sumPt[k];
                            n += totalSystems[i][position - 1];
                            sumPt[k] = n;
                            position++;
                            flag = 1;
                            k = 0;
                        }
                    }
                    else
                    {
                        flag = 1;
                    }
                    k++;
                }
            }
        }

        winner(sumPt);
        sumPt.clear();
    }
}

int main()
{
    int nG = 1, nP = 1, x, nSys, pointed, pt;
    vector<vector<int>> tG;
    vector<vector<int>> tSysPt;
    vector<int> individual;
    vector<int> ans;
    while (nG != 0 && nP != 0)
    {
        scanf("%d", &nG);
        scanf("%d", &nP);
        for (int i = 0; i < nG; i++)
        {
            for (int j = 0; j < nP; j++)
            {
                scanf("%d", &x);
                individual.push_back(x);
            }
            tG.push_back(individual);
            individual.clear();
        }
        if (nG != 0 && nP != 0)
        {
            scanf("%d", &nSys);
        }
        else
        {
            nSys = 0;
        }
        for (int i = 0; i < nSys; i++)
        {
            scanf("%d", &pointed);
            for (int j = 0; j < pointed; j++)
            {
                scanf("%d", &pt);
                individual.push_back(pt);
            }
            tSysPt.push_back(individual);
            individual.clear();
        }

        sumPoints(tG, tSysPt, nG, nP, nSys);
        tG.clear();
        tSysPt.clear();
    }
    return 0;
}
