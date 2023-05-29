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

    BigInteger abso();

public:
    // Constructores
    BigInteger();
    BigInteger(const string &n);
    BigInteger(const vector<int> &n, int s);
    BigInteger(const BigInteger &est);

    // Operaciones que cambían el actual
    void add(BigInteger &est);
    void substract(BigInteger &est);
    void product(BigInteger &est);
    void quotient(BigInteger &est);
    void remainder(BigInteger &est);
    void pow(int est);

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

    static BigInteger sumarListaValores(list<BigInteger> &n);
    static BigInteger multiplicarListaValores(list<BigInteger> &n);
};

#endif