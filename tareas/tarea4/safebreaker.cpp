/*
Name: Juan Diego Valencia
code:
tarea4 - Estructuras de datos - 2023-1
UVa code:

Complejidad computacional:
la complejidad del programa se puede decir que es en cierta manera constante, ya que
se puede describir como O(9999 * 4 * n), el 9999 corresponde a la generación de todos los
condigos posibles, ya que este ejercio se resuelve a la fuerza, el 4 se refiera a la segmentación
de cada numero en el vector, por último n correponde a la cantidad de pistas que se ingrese por lo que
interará en la función possible cuantas veces tenga pistas.

Cabe resaltar que el programa puede variar el tiempo de ejecución con ciertos factores, por ejemplo,
si encuentra dos numeros possibles significa que ya es imposible por lo que terminaría su ejeción, además
en la función possible depende de que ans se mantena en true, por lo que si el primer if no se cumple no continuará.
Sin embargo, para los casos donde solo hay un numero posible o es indeterminado el programa tendrá
que recorrer todos los 9999 codigos.

En sí la complejidad es O(n) siendo n la cantidad de pistas, sin embargo con una pendiente muy 
grande lo que hace que sea un poco pesado.

*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class InfoCode
{
public:
    int code;
    int correct;
    int misplaced;

    InfoCode()
    {
        code = 0;
        correct = 0;
        misplaced = 0;
    }
    void info(int c, int crt, int miss)
    {
        code = c;
        correct = crt;
        misplaced = miss;
    }
};
vector<int> seg(int number)
{
    vector<int> digits(4, 0);
    for (int i = 3; i >= 0; i--)
    {
        digits[i] = number % 10;
        number /= 10;
    }
    return digits;
}

bool possible(vector<int> &codeVec, vector<InfoCode> &guesses)
{
    bool ans = true;
    for (vector<InfoCode>::iterator it = guesses.begin(); it != guesses.end() and ans == true; it++)
    {
        vector<int> guessCode = seg(it->code);
        int correct = it->correct;
        int misplaced = it->misplaced;
        vector<int> mark;
        int cont1 = 0;

        for (int i = 0; i < 4; i++)
        {
            if (codeVec[i] == guessCode[i])
            {
                cont1++;
            }
        }
        if (cont1 != correct)
        {
            ans = false;
        }
        if (ans == true)
        {
            vector<int> num1(10, 0);
            vector<int> num2(10, 0);
            for (int j = 0; j < 4; j++)
            {
                num1[codeVec[j]]++;
            }
            for (int j = 0; j < 4; j++)
            {
                num2[guessCode[j]]++;
            }
            int cont2 = 0;
            for (int j = 0; j < 10; j++)
            {
                if (num1[j] < num2[j])
                {
                    cont2 += num1[j];
                }
                else
                {
                    cont2 += num2[j];
                }
            }
            if (cont2 - cont1 != misplaced)
            {
                ans = false;
            }
        }
    }
    return ans;
}

int main()
{
    int n, g;
    scanf("%d", &n);
    for (int k = 0; k < n; k++)
    {
        scanf("%d", &g);
        int c, cp, miss;
        char slash;
        vector<InfoCode> list;

        vector<int> segC;
        for (int j = 0; j < g; j++)
        {
            cin >> c >> cp >> slash >> miss;

            InfoCode code;
            code.info(c, cp, miss);
            list.push_back(code);
        }
        vector<int> ans;
        for (int i = 0; i <= 9999 && ans.size() < 2; i++)
        {

            vector<int> code = seg(i);
            double posi = possible(code, list);
            if (posi == true)
            {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0)
        {
            cout << "impossible" << endl;
        }
        else if (ans.size() == 1)
        {
            cout << ans[0] << endl;
        }
        else
        {
            cout << "indeterminate" << endl;
        }
    }
    return 0;
}
