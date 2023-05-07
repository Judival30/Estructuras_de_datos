#ifndef BIG__INTEGER
#define BIG__INTEGER

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class BigInteger
{
private:
    vector<int> num;
    int sign;

public:
    // Constructores
    BigInteger();
    BigInteger(string n);
    BigInteger(vector<int> n, int s);

    // Operaciones que cambían el actual
    void add(BigInteger &est);
    void substract(BigInteger &est);
    void product(BigInteger &est);
    void quotient(BigInteger &est);
    void remainder(BigInteger &est);  
    void pow(BigInteger &est);

    // Sobrecargas de los operadores
    BigInteger operator+(BigInteger &est);
    BigInteger operator-(BigInteger &est);
    BigInteger operator*(BigInteger &est);
    BigInteger operator/(BigInteger &est);
    BigInteger operator%(BigInteger &est);
    bool operator==(BigInteger &est);
    bool operator<=(BigInteger &est);
    bool operator<(BigInteger &est);

    // Operaciones analizadoras
    string toString();
    int sizeInt();
    int infoNum(int v);
    int getSign();
    void printBigInt();

    BigInteger sumarListaValores(list<BigInteger> &n);
    BigInteger MultiplicarListaValores(list<BigInteger> &n);
};

#endif
