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
    BigInteger(const string n)
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
    bool operator==(BigInteger &est)
    {
        bool ans;
        if (num == est.num && sign == est.sign)
            ans = true;
        else
            ans = false;
        return ans;
    }
    bool operator<(BigInteger &est)
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
};

int main()
{
    string s1, s2, n1Int, n1Float, n2Int, n2Float;
    int cont = 1;
    while (cin >> s1 >> s2)
    {
        bool flag = false;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '.')
                flag = true;
            else if (flag)
                n1Float.push_back(s1[i]);
            else
                n1Int.push_back(s1[i]);
        }
        flag = false;
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == '.')
                flag = true;
            else if (flag)
                n2Float.push_back(s2[i]);
            else
                n2Int.push_back(s2[i]);
        }

        if (n1Float.size() < n2Float.size())
            while (n1Float.size() < n2Float.size())
                n1Float += "0";
        else if (n1Float.size() > n2Float.size())
            while (n1Float.size() > n2Float.size())
                n2Float += "0";

        BigInteger n1I(n1Int);
        BigInteger n1F(n1Float);
        BigInteger n2I(n2Int);
        BigInteger n2F(n2Float);
        if (n1I == n2I)
        {
            if (n1F == n2F)
                printf("Case %d: Same\n", cont);
            else if (n1F < n2F)
                printf("Case %d: Smaller\n", cont);
            else
                printf("Case %d: Bigger\n", cont);
        }
        else if (n1I < n2I)
            printf("Case %d: Smaller\n", cont);
        else
            printf("Case %d: Bigger\n", cont);

        cont++;
        n1Int.clear();
        n1Float.clear();
        n2Int.clear();
        n2Float.clear();
    }
    return 0;
}
