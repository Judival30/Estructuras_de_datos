#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <list>

using namespace std;

typedef int Elemento;

class Cola
{
    list<Elemento> l;

public:
    Cola(); // crearCola
    Elemento front();
    void deque();
    void enqueue(Elemento);
    bool vaciaCola();
};

#endif
