#include "bigInteger.h"
BigInteger::BigInteger()
{
}
BigInteger::BigInteger(string n)
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
BigInteger::BigInteger(vector<int> n, int s)
{
    num = n;
    sign = s;
}

// Funciones que se usarán con el fin de mantener el princio de los TAD
int BigInteger::sizeInt()
{
    int data = num.size();
    return data;
}
int BigInteger::infoNum(int v)
{
    return num[v];
}
int BigInteger::getSign()
{
    return sign;
}

bool BigInteger::operator<(BigInteger &est)
{
    bool ans;

    if (num.size() == est.sizeInt())
    {
        int k = num.size() - 1;
        while (num[k] == est.infoNum(k))
            k--;

        if (sign == 1)
            ans = num[k] < est.infoNum(k);
        else
            ans = num[k] > est.infoNum(k);
    }
    if (num.size() != est.sizeInt())
        ans = num.size() < est.sizeInt();
    if (sign != est.getSign())
        ans = sign < est.getSign();

    return ans;
}
// Funciones Modificadoras
BigInteger BigInteger::operator+(BigInteger &est)
{
    int size, sum, save = 0, subs = 0;
    vector<int> tmp;
    if (num.size() < est.sizeInt())
    {
        size = est.sizeInt();
    }
    else
    {
        size = num.size();
    }
    for (int i = 0; i < size; i++)
    {
        sum = save - subs;
        if (sign != est.getSign())
        {
            if (i < num.size())
                sum += num[i] * sign;
            if (i < est.sizeInt())
                sum += est.infoNum(i) * est.getSign();
        }
        else
        {
            if (i < num.size())
                sum += num[i];
            if (i < est.sizeInt())
                sum += est.infoNum(i);
        }

        if (sum < 0)
        {
            sum += 10;
            subs = 1;
        }
        else
        {
            subs = 0;
        }

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

    if (sign != est.getSign())
    {
        BigInteger n1(num, sign);
        if (n1 < est)
            s = est.getSign();

        else
            s = sign;
    }
    else
        s = sign;

    return BigInteger(tmp, s);
}

BigInteger BigInteger::operator-(BigInteger &est)
{
    int size, sum, save = 0, subs = 0;
    vector<int> tmp;
    if (num.size() < est.sizeInt())
    {
        size = est.sizeInt();
    }
    else
    {
        size = num.size();
    }
    for (int i = 0; i < size; i++)
    {

        sum = save - subs;

        if (sign != est.getSign())
        {
            if (i < num.size())
                sum += num[i] * sign;
            if (i < est.sizeInt())
                sum -= est.infoNum(i) * est.getSign();
        }
        else
        {
            if (i < num.size())
                sum += num[i];
            if (i < est.sizeInt())
                sum -= est.infoNum(i);
        }

        if (sum < 0)
        {
            sum += 10;
            subs = 1;
        }
        else
        {
            subs = 0;
        }

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

    if (sign != est.getSign())
    {
        BigInteger n1(num, sign);
        if (n1 < est)
            s = est.getSign();

        else
            s = sign;
    }
    else
        s = sign;

    return BigInteger(tmp, s);
}

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

void BigInteger::add(BigInteger &est)
{
    int size, sum, save = 0, subs = 0;
    vector<int> tmp;
    if (num.size() < est.sizeInt())
    {
        size = est.sizeInt();
    }
    else
    {
        size = num.size();
    }
    for (int i = 0; i < size; i++)
    {
        sum = save - subs;
        if (sign != est.getSign())
        {
            if (i < num.size())
                sum += num[i] * sign;
            if (i < est.sizeInt())
                sum += est.infoNum(i) * est.getSign();
        }
        else
        {
            if (i < num.size())
                sum += num[i];
            if (i < est.sizeInt())
                sum += est.infoNum(i);
        }

        if (sum < 0)
        {
            sum += 10;
            subs = 1;
        }
        else
        {
            subs = 0;
        }

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

    if (sign != est.getSign())
    {
        BigInteger n1(num, sign);
        if (n1 < est)
            sign = est.getSign();
    }
    num = tmp;
}

void BigInteger::substract(BigInteger &est)
{
    int size, sum, save = 0, subs = 0;
    if (num.size() < est.sizeInt())
    {
        size = est.sizeInt();
    }
    else
    {
        size = num.size();
    }
    for (int i = 0; i < size; i++)
    {
        sum = save - subs;
        if (i < num.size())
            sum += num[i] * sign;
        if (i < est.sizeInt())
            sum -= est.infoNum(i) * est.getSign();
        if (sum < 0)
        {
            sum += 10;
            subs = 1;
        }
        else
        {
            subs = 0;
        }
        num[i] = sum % 10;
        save = sum / 10;
    }
    if (save != 0)
        num.push_back(save);

    int j = num.size() - 1;
    while (j > 0 && num[j] == 0)
    {
        num.pop_back();
        j--;
    }
}

void BigInteger::product(BigInteger &est)
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
    num = tmp;
    sign *= est.getSign();
}
void BigInteger::pow(BigInteger &est)
{
    BigInteger one("1");
    BigInteger cero("0");

    BigInteger exp = est;
    BigInteger mult(num, sign);

    BigInteger ans("1");
    while (cero < exp)
    {

        ans = ans * mult;
        ans.printBigInt();
        exp = exp - one;
    }
    string n = ans.toString();
    int data;
    num.clear();
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
void BigInteger::printBigInt()
{
    if (sign == -1)
    {
        num[num.size() - 1] *= -1;
    }
    for (int i = num.size() - 1; i >= 0; i--)
    {
        cout << num[i];
    }
    cout << endl;
}
