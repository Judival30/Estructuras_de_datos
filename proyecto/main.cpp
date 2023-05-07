/*
 *Implementación del TAD Biginteger
 *Autor: Juan Diego Valencia Alomia
 *Fecha: 6/05/23
 *Proyecto final Estructuras de datos 2023-1
 
 */
#include "bigInteger.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    BigInteger n1("17");
    BigInteger n2("-57");
    BigInteger n4("-8");
    BigInteger n5("1000");
    BigInteger n6("21");
    BigInteger n7("-65");

    BigInteger n3("");
    // Suma
    printf("Suma con +:\n");
    n3 = n1 + n2;
    n3.printBigInt();
    printf("Suma por ref:\n");
    n1.add(n4);
    n1.printBigInt();

    // Resta
    printf("Resta con - :\n");
    n3 = n5 - n2;
    n3.printBigInt();
    printf("Resta por ref:\n");
    n5.substract(n2);
    n5.printBigInt();

    // Multiplicación
    printf("Producto con * :\n");
    n3 = n6 * n7;
    n3.printBigInt();
    printf("Producto por ref:\n");
    n6.product(n7);
    n6.printBigInt();
    return 0;
}
