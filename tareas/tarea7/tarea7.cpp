/*
Autor: Juan Diego Valencia Alomia
26/05/23
tarea7 - Estructuras de datos - 2023-1
*/
#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
// Punto 1
void eliminarPosicionesPila(stack<int> &pil, list<int> &l)
{
    /*  Complejidad:
        La complejidad de esta función es O(n), ya que primero vacía la pila pil
        con el fin de obtener una pila con los valores invertidos, así cuando se
        compara con el contenido de la lista se ingresa solo los valores que estan
        en una posición distinta a la que indica la lista, por lo tanto, realiza dos
        recorridos de tamaño n, dando consigo su comportamiento linel y por eso
        es O(n)
    */
    stack<int> tmp;
    while (!pil.empty())
    {
        tmp.push(pil.top());
        pil.pop();
    }
    int pos = 1;
    list<int>::iterator it = l.begin();
    while (!tmp.empty())
    {
        if (pos != *it)
            pil.push(tmp.top());
        else
            it++;
        tmp.pop();
        pos++;
    }
}
// Punto 3
bool verificarOrdenadoCola(queue<int> &q)
{
    /* La función verifica si la cola esta ordenada de mayor a menor
    o de menor a mayor

    Complejidad:
    La complejidad de esta función es O(n) siendo n el tamaño de la cola
    ya que para verificar si está ordenada recorre la cola verficando su
    orden. Por lo tanto tiene comportamiento lineal
*/
    bool ans = false, min = true, max = true;
    queue<int> tmp = q;
    int prev = tmp.front();
    tmp.pop();
    while (!tmp.empty())
    {
        int act = tmp.front();
        tmp.pop();
        if (prev > act)
            min = false;
        else if (prev < act)
            max = false;
        prev = act;
    }
    if (min || max)
        ans = true;

    return ans;
}
// Punto 4
int obtenerMenorCosto(list<int> l)
{
    /*  La función obtiene el menor costo de hacer las sumas consecutivas de la lista l.
     El menor costo se obtiene a partir de comenzar a sumar de menor a mayor, es decir,
     ordenar la lista en orden de menor a mayor

     Complejidad:
     La función recorre la lista L para realizar las sumas, por lo que tendría una complejidad
     O(n) siendo n el tamaño de la lista. Sin embargo como se hace uso de la función sort para
     ordenar la lista, entonces la función tiene una complejidad nlog(n).
     */
    l.sort();
    int cost = 0;
    int ref = l.front();
    l.pop_front();

    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cost += ref + *it;
        ref += *it;
    }

    return cost;
}
// Punto 6
int verificarRepetidos(queue<int> &col)
{
    /* Complejidad:
    la función recorre primero la cola, haciendo el conteo de los
    valores en un mapa donde la key es el valor, y el segundo valor
    es la veces en que se repite, para posteriormente revisar si
    hay valores repetidos y sumar al contador rep.
    Por lo tanto, tendría una complejidad de O(n) siendo n el tamaño
    de la cola
    */
    queue<int> tmp = col;
    map<int, int> cont;
    int rep = 0;
    while (!tmp.empty())
    {
        int num = tmp.front();
        cont[num]++;
        tmp.pop();
        cout << num << endl;
    }
    for (map<int, int>::iterator it = cont.begin(); it != cont.end(); it++)
    {
        if (it->second > 1)
            rep++;
    }
    return rep;
}
// Punto 7
map<char, list<int>> obtenerPosicionesOcurrencias(string &cad)
{
    /* Complejidad:
    La función recorre la cadena cad para obtener los caracteres de forma
    individual, de esta forma se intoduce al mapa la posición donde se
    econtró dicho caracter. Por lo tanto, la complejidad de esta función
    sería O(n) siendo n el tamaño de cad */
    map<char, list<int>> ans;
    for (int i = 0; i < cad.size(); i++)
        ans[cad[i]].push_back(i);
    return ans;
}
// Punto 8
vector<list<pair<int, int>>> crearMatrizDispersa(vector<vector<int>> mat)
{
    /* Complejidad:
        La funcióm recorre la matriz, por lo que tiene que recorrer primero
        los vectores pertenecientes a mat, y posteriormente busca en esos
        vectores valores distinos de 0, de esta forma si consideramos que
        la matriz mat es cuadrada, entonces si llamanos a n el tamaño de una
        fila entonces recorre n veces la matriz y cada fila también la recorre
        n veces. Por lo tanto la complejidad es O(n^2)
    */
    vector<list<pair<int, int>>> ans;
    for (int i = 0; i < mat.size(); i++)
    {
        list<pair<int, int>> l;
        ans.push_back(l);
        for (int j = 0; j < mat[i].size(); j++)
            if (mat[i][j] != 0)
                ans[i].push_back(make_pair(j, mat[i][j]));
    }
    return ans;
}

// Punto 9
bool verificarRepetidosCola(queue<int> &col)
{
    /* Complejidad:
    La función recorre la cola buscando valores repetidos,
    si lo hace entonces se sale del ciclo.

    Mejor caso:
    En el mejor de los escenarios los primeros dos valores
    estan repetidos, por lo que la complejidad es O(1)
    Peor caso:
    En este caso recorre la totalidad de la cola sin encontrar
    valores repetidos, por lo que tendría una complejidad de
    O(n) siendo n el tamaño de la cola

   */
    bool ans = false;
    queue<int> tmp = col;
    map<int, int> cont;

    while (!tmp.empty() && !ans)
    {
        int var = tmp.front();
        tmp.pop();
        cont[var]++;
        if (cont[var] > 1)
            ans = true;
    }
    return ans;
}

// Punto 10
stack<int> filtrarNParesCola(queue<int> col, int N)
{
    /* Complejidad:
    La función recorre la col y si encuentra un numero par entonces lo
    ingresa a la pila ans, esto siempre y cuando no haya pasado la cantidad
    de numeros pares N que se ingresaron. Por esta razón si llamamos n al
    tamaño de la cola entonces la complejidad es O(n).
    */
    stack<int> ans;
    int cont = 0;
    while (!col.empty() && cont < N)
    {
        int num = col.front();
        if (num % 2 == 0)
        {
            ans.push(num);
            cont++;
        }
        col.pop();
    }
    return ans;
}

int main()
{

    return 0;
}
