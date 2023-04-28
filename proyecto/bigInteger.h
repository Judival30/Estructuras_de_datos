#ifndef BIG__INTEGER
#define BIG__INTEGER

#include <iostream>
#include <vector>

using namespace std;

class BigInteger
{
private:
    vector<int> num;
    int sign;

public:
    BigInteger(string n);
    BigInteger(vector<int> n, int s);

    void add(BigInteger &est);
    void substract(BigInteger &est);
    void product(BigInteger &est);

    BigInteger operator+(BigInteger &est);
    BigInteger operator-(BigInteger &est);
    BigInteger operator*(BigInteger &est);

    int sizeInt();
    int infoNum(int v);
    int getSign();
    void printBigInt();
};

#endif
