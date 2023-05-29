/*
Implementación de la interfaz del tipo de dato Abstracto BigInteger:
*/
#include "bigInteger.h"

/*
Constructor por defecto
Entrada: -
Salida: -
Descripción: Este constructor inicializa un BigInteger
*/
BigInteger::BigInteger()
{
}

/*
Constructor
Entrada: String
Salida: -
Descripción: Este constructor recorre la cadena con el fin de
ingresarla a un vector de enteros. Este vector guarda el numero
de forma invertida, además guarda el signo en un entero que puede
ser 1 o -1
*/
BigInteger::BigInteger(const string &n)
{
    int data;
    sign = 1;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        if (n[i] == '-')
        {
            sign = -1;
        }
        else
        {
            data = n[i] - 48;
            num.push_back(data);
        }
    }
}

/*
Constructor
Entrada: vector<int>, int
Salida: -
Descripción: Este constructor tiene como funcion
inicializar un BigInteger ya con el vector y el signo
desde alguna función
*/
BigInteger::BigInteger(const vector<int> &n, int s)
{
    num = n;
    sign = s;
}

/*
Constructor de Copia
Entrada: BigInteger
Salida: -
Descripción: Este constructor tiene como función
copiar un BigInteger
*/
BigInteger::BigInteger(const BigInteger &est)
{
    this->num = est.num;
    this->sign = est.sign;
}
/* ===================================================================
Funciones que se usarán con el fin de mantener el princio de los TAD
=================================================================== */
/*
Función sizeInt
Entrada: -
Salida: int, entero positivo
Descripción: Esta función retorna el tamaño del numero, es decir la cantidad
de digitos que tiene el numero
*/
int BigInteger::sizeInt()
{
    int data = num.size();
    return data;
}

/*
Función infoNum
Entrada: int, entero positivo
Salida: int, entero positivo
Descripción: Esta función retorna el numero que se almacena en el vector en la
posición que es pasada por parametro
*/
int BigInteger::infoNum(int v)
{
    return num[v];
}

/*
Función getSign
Entrada: -
Salida: int, 1 o -1
Descripción: Esta función retorna signo del BigInteger
*/
int BigInteger::getSign()
{
    return sign;
}

/*
Función toString
Entrada: -
Salida: string
Descripción: Esta función retorna el BigInteger en forma de candena
*/
string BigInteger::toString()
{
    string ans = "";
    if (sign == -1)
        ans += "-";
    for (int i = num.size() - 1; i >= 0; i--)
        ans += num[i] + 48;
    return ans;
}

/*
Función abso (privada)
Entrada: -
Salida: BigInteger
Descripción: Esta función retorna el BigInteger actual en
valor absoluto
*/
BigInteger BigInteger::abso()
{
    BigInteger ans(num, 1);
    return ans;
}
/* ===================================================================
                      Operadores de comparación
=================================================================== */
/*
Función sobrecarga <
Entrada: BigInteger
Salida: bool
Descripción: Esta función compara el BigInteger actual con el que se le
pasa por parametro, retorna true si es menor, false si es mayor o igual
*/
bool BigInteger::operator<(BigInteger &est)
{
    bool ans = false;
    if (*this == est)
        ans = false;
    else if (sign != est.sign)
        ans = sign < est.sign;
    else if (num.size() == est.num.size())
    {
        int k = num.size() - 1;
        while (num[k] == est.num[k])
            k--;

        if (sign == 1 && est.sign == 1)
            ans = num[k] < est.num[k];
        else
            ans = num[k] > est.num[k];
    }
    else if (num.size() != est.num.size())
        if (sign == 1 && est.sign == 1)
            ans = num.size() < est.num.size();
        else
            ans = num.size() > est.num.size();

    return ans;
}

/*
Función sobrecarga <=
Entrada: BigInteger
Salida: bool
Descripción: Esta función compara el BigInteger actual con el que se le
pasa por parametro, retorna true si es menor o igual, false si es mayor
*/
bool BigInteger::operator<=(BigInteger &est)
{
    bool ans = false;
    if (*this == est)
        ans = true;
    else if (sign != est.sign)
        ans = sign < est.sign;
    else if (num.size() == est.num.size())
    {
        int k = num.size() - 1;
        while (num[k] == est.num[k])
            k--;

        if (sign == 1 && est.sign == 1)
            ans = num[k] < est.num[k];
        else
            ans = num[k] > est.num[k];
    }
    else if (num.size() != est.num.size())
        if (sign == 1 && est.sign == 1)
            ans = num.size() < est.num.size();
        else
            ans = num.size() > est.num.size();

    return ans;
}

/*
Función sobrecarga ==
Entrada: BigInteger
Salida: bool
Descripción: Esta función compara el BigInteger actual con el que se le
pasa por parametro, retorna true si son iguales, false si es diferente
*/
bool BigInteger::operator==(BigInteger &est)
{
    bool ans;
    if (num == est.num && sign == est.sign)
        ans = true;
    else
        ans = false;
    return ans;
}
/* ===================================================================
                      Sobrecargas + - * / %
=================================================================== */
/*
Función sobrecarga +
Entrada: BigInteger
Salida: BigInteger
Descripción: Esta función suma el BigInteger actual con el que se le
pasa por parametro, retorna un BigInteger con el resultado de la operación
Hay tres casos con los signos:
1. Signos iguales, en este caso se suman y se pone el signo de alguno al final
2. El mayor positivo y el menor negativo, en este caso se compara de nuevo con
   los numeros pero en su absoluto, si en esta comparación el menor resulta ser
   mayor entonces se intercambian los signos y al resultado se le asigna el signo
   del menor
3. Si no se cumplieron alguno de los casos antes mencionados, simplemente se
   le resta el menor al mayor
*/
BigInteger BigInteger::operator+(BigInteger &est)
{
    int sum, save = 0, subs = 0;
    vector<int> tmp;
    BigInteger greater, less;
    bool flag = false;
    if (*this < est)
    {
        greater = est;
        less = *this;
    }
    else
    {
        greater = *this;
        less = est;
    }
    if (greater.getSign() == 1 && less.getSign() == -1)
    {
        BigInteger n1, n2;
        n1 = greater.abso();
        n2 = less.abso();
        if (n1 < n2)
            flag = true;
    }

    for (int i = 0; i < greater.sizeInt() || i < less.sizeInt(); i++)
    {
        sum = save - subs;

        if (sign == est.sign)
        {
            if (i < greater.sizeInt())
                sum += greater.infoNum(i);
            if (i < less.sizeInt())
                sum += less.infoNum(i);
        }
        else if (flag)
        {
            if (i < greater.sizeInt())
                sum -= greater.infoNum(i);
            if (i < less.sizeInt())
                sum += less.infoNum(i);
            flag = true;
        }
        else
        {
            if (i < greater.sizeInt())
                sum += greater.infoNum(i);
            if (i < less.sizeInt())
                sum -= less.infoNum(i);
        }
        if (sum < 0)
        {
            sum += 10;
            subs = 1;
        }
        else
            subs = 0;

        tmp.push_back(sum % 10);
        save = sum / 10;
    }
    if (save != 0)
        tmp.push_back(save);

    int j = tmp.size() - 1;
    while (j > 0 && tmp[j] == 0)
    {
        tmp.pop_back();
        j--;
    }
    int s;
    if (flag)
        s = less.getSign();
    else if (sign != est.getSign())
        s = greater.getSign();
    else
        s = sign;

    return BigInteger(tmp, s);
}

/*
Función sobrecarga -
Entrada: BigInteger
Salida: BigInteger
Descripción: Esta función resta el BigInteger actual con el que se le
pasa por parametro, retorna un BigInteger con el resultado de la operación, antes
de eso se multiplica por -1 al BigIntger que se pasa por parametro y se prosigue
con la misma logica de la suma.
Hay tres casos con los signos:
1. Signos iguales, en este caso se suman y se pone el signo de alguno al final
2. El mayor positivo y el menor negativo, en este caso se compara de nuevo con
   los numeros pero en su absoluto, si en esta comparación el menor resulta ser
   mayor entonces se intercambian los signos y al resultado se le asigna el signo
   del menor
3. Si no se cumplieron alguno de los casos antes mencionados, simplemente se
   le resta el menor al mayor
*/
BigInteger BigInteger::operator-(BigInteger &est)
{
    int sum, save = 0, subs = 0;
    vector<int> tmp;
    BigInteger greater, less, n2;
    n2 = BigInteger(est.num, est.sign * -1);
    bool flag = false;
    if (*this < n2)
    {
        greater = n2;
        less = *this;
    }
    else
    {
        greater = *this;
        less = n2;
    }
    if (greater.getSign() == 1 && less.getSign() == -1)
    {
        BigInteger n1, n2;
        n1 = greater.abso();
        n2 = less.abso();
        if (n1 < n2)
            flag = true;
    }

    for (int i = 0; i < greater.sizeInt() || i < less.sizeInt(); i++)
    {
        sum = save - subs;

        if (sign == est.sign * -1)
        {
            if (i < greater.sizeInt())
                sum += greater.infoNum(i);
            if (i < less.sizeInt())
                sum += less.infoNum(i);
        }
        else if (flag)
        {
            if (i < greater.sizeInt())
                sum -= greater.infoNum(i);
            if (i < less.sizeInt())
                sum += less.infoNum(i);
            flag = true;
        }
        else
        {
            if (i < greater.sizeInt())
                sum += greater.infoNum(i);
            if (i < less.sizeInt())
                sum -= less.infoNum(i);
        }
        if (sum < 0)
        {
            sum += 10;
            subs = 1;
        }
        else
            subs = 0;

        tmp.push_back(sum % 10);
        save = sum / 10;
    }
    if (save != 0)
        tmp.push_back(save);

    int j = tmp.size() - 1;
    while (j > 0 && tmp[j] == 0)
    {
        tmp.pop_back();
        j--;
    }
    int s;
    if (flag)
        s = less.getSign();
    else if (sign != est.getSign() * -1)
        s = greater.getSign();
    else
        s = sign;

    return BigInteger(tmp, s);
}

/*
Función sobrecarga *
Entrada: BigInteger
Salida: BigInteger
Descripción: Esta función multiplica el BigInteger actual con el que se le
pasa por parametro, retorna un BigInteger con el resultado de la operación,
*/
BigInteger BigInteger::operator*(BigInteger &est)
{
    vector<int> tmp(num.size() + est.sizeInt(), 0);

    for (int i = 0; i < num.size(); i++)
    {
        int save = 0;
        for (int j = 0; j < est.sizeInt(); j++)
        {
            int prod = num[i] * est.infoNum(j) + save + tmp[i + j];
            save = prod / 10;
            tmp[i + j] = prod % 10;
        }
        tmp[i + est.sizeInt()] = save;
    }

    int j = tmp.size() - 1;
    while (j > 0 && tmp[j] == 0)
    {
        tmp.pop_back();
        j--;
    }
    int s = 1;
    if (sign * est.getSign() < 0)
        s = -1;

    return BigInteger(tmp, s);
}

/*
Función sobrecarga /
Entrada: BigInteger
Salida: BigInteger
Descripción: Esta función divide el BigInteger actual con el que se le
pasa por parametro, retorna un BigInteger con el resultado de la operación,
*/
BigInteger BigInteger::operator/(BigInteger &est)
{
    BigInteger result;
    if (*this < est)
        result = BigInteger("0");

    else
    {
        BigInteger ten("10");
        string act = (*this).toString(), fraction;
        int cont = 0;
        for (int i = 0; i < est.num.size(); i++)
        {
            fraction += act[i];
            cont++;
        }

        BigInteger save(fraction);
        if (save < est)
        {
            fraction += act[cont];
            cont++;
            save = BigInteger(fraction);
        }
        string ans;
        BigInteger tmp;
        while (cont <= act.size())
        {
            int i = 0;
            string digit;
            BigInteger n("0");
            while (n <= save && i < 10)
            {
                n = n + est;
                i++;
            }
            n = n - est;
            i--;
            save = save - n;
            digit += act[cont];
            tmp = BigInteger(digit);
            save = (save * ten) + tmp;
            ans += i + 48;
            cont++;
        }
        result = BigInteger(ans);
    }
    return result;
}

/*
Función sobrecarga %
Entrada: BigInteger
Salida: BigInteger
Descripción: Esta función divide el BigInteger actual con el que se le
pasa por parametro para entontrar el residuo, retorna un BigInteger con
el resultado de la operación.
*/
BigInteger BigInteger::operator%(BigInteger &est)
{
    BigInteger result;
    if (num.size() < est.num.size())
    {
        result = *this;
    }
    else
    {
        BigInteger ten("10");
        string act = (*this).toString(), fraction;
        int cont = 0;
        for (int i = 0; i < est.num.size(); i++)
        {
            fraction += act[i];
            cont++;
        }

        BigInteger save(fraction);
        if (save < est)
        {
            fraction += act[cont];
            cont++;
            save = BigInteger(fraction);
        }
        string ans;
        BigInteger tmp;
        while (cont <= act.size())
        {
            int i = 0;
            string digit;
            BigInteger n("0");
            while (n <= save && i < 10)
            {
                n = n + est;
                i++;
            }
            n = n - est;
            i--;
            save = save - n;
            digit += act[cont];
            tmp = BigInteger(digit);
            if (cont < act.size())
                save = (save * ten) + tmp;
            ans += i + 48;
            cont++;
        }
        result = save;
    }
    return result;
}

/* ===================================================================
                      Funciones Modificadoras
=================================================================== */
/*
Función add
Entrada: BigInteger
Salida: -
Descripción: Esta función suma el BigInteger actual con el que se le
pasa por parametro, modifica el actual con el resultado de la operación
*/
void BigInteger::add(BigInteger &est)
{
    *this = *this + est;
}

/*
Función substract
Entrada: BigInteger
Salida: -
Descripción: Esta función resta el BigInteger actual con el que se le
pasa por parametro, modifica el actual con el resultado de la operación
*/
void BigInteger::substract(BigInteger &est)
{
    *this = *this - est;
}

/*
Función product
Entrada: BigInteger
Salida: -
Descripción: Esta función multiplica el actual con el que se le
pasa por parametro, modifica el actual con el resultado de la operación
*/
void BigInteger::product(BigInteger &est)
{
    *this = *this * est;
}

/*
Función pow
Entrada: int, entero positivo
Salida: -
Descripción: Esta función eleva el actual con el que se le
pasa por parametro, modifica el actual con el resultado de la operación
*/
void BigInteger::pow(int est)
{

    BigInteger ans("1");
    while (est > 0)
    {
        ans = ans * (*this);
        est--;
    }
    *this = ans;
}

/*
Función quotient
Entrada: BigInteger
Salida: -
Descripción: Esta función divide el actual con el que se le
pasa por parametro, modifica el actual con el resultado de la operación
*/
void BigInteger::quotient(BigInteger &est)
{
    *this = *this / est;
}

/*
Función remainder
Entrada: BigInteger
Salida: -
Descripción: Esta función divide el actual con el que se le
pasa por parametro para calcula el residuo, modifica el actual
con el resultado de la operación.
*/
void BigInteger::remainder(BigInteger &est)
{
    *this = *this % est;
}
/* ===================================================================
            Operaciones de manejo de listas de BigInteger
=================================================================== */
/*
Función sumarListaValores
Entrada: list<BigInteger>
Salida: BigInteger
Descripción: Esta función suma todos los elementos de la lista que le pasa
por parametro, está función es estatica, por lo que se realiza sobre la clase
y no sobre un objeto, por lo cual retorna el resultado de la operación
*/
BigInteger BigInteger::sumarListaValores(list<BigInteger> &n)
{
    BigInteger ans("0");
    for (list<BigInteger>::iterator it = n.begin(); it != n.end(); it++)
        ans = ans + *it;
    return ans;
}

/*
Función multiplicarListaValores
Entrada: list<BigInteger>
Salida: BigInteger
Descripción: Esta función multiplica todos los elementos de la lista que le pasa
por parametro, está función es estatica, por lo que se realiza sobre la clase
y no sobre un objeto, por lo cual retorna el resultado de la operación
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger> &n)
{
    BigInteger ans("1");
    for (list<BigInteger>::iterator it = n.begin(); it != n.end(); it++)
        ans = ans * *it;
    return ans;
}
