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
    BigInteger()
    {
    }
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
    BigInteger(const vector<int> &n, int s)
    {
        num = n;
        sign = s;
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
    int sizeInt()
    {
        int data = num.size();
        return data;
    }
    BigInteger abso()
    {
        BigInteger ans(num, 1);
        return ans;
    }
    int getSign()
    {
        return sign;
    }
    int infoNum(int v)
    {
        return num[v];
    }
    string toString()
    {
        string ans = "";
        if (sign == -1)
            ans += "-";
        for (int i = num.size() - 1; i >= 0; i--)
            ans += num[i] + 48;
        return ans;
    }
    BigInteger operator+(BigInteger &est)
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
};

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        string s1, s2, n1Int, n1Float, n2Int, n2Float;
        int posDot1, posDot2;
        cin >> s1 >> s2;
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
        s1 = n1Int + n1Float;
        s2 = n2Int + n2Float;
        BigInteger n1(s1);
        BigInteger n2(s2);
        n1 = n1 + n2;
        string ans = n1.toString();
        if (ans.size() < n1Float.size() + 1)
        {
            string::iterator i = ans.begin();
            while (ans.size() < n1Float.size() + 1)
            {
                ans.insert(i, '0');
                i++;
            }
        }
        string::iterator it = ans.begin();
        advance(it, ans.size() - n1Float.size());
        ans.insert(it, '.');
        int pos = ans.size() - 1;
        flag = true;
        while (ans[pos] == '0' && flag)
        {
            if (ans[pos] == '.')
                flag = false;
            else
                ans.pop_back();
            pos--;
        }
        if (ans[ans.size() - 1] == '.')
            ans.push_back('0');
        cout << ans << endl;
    }
    return 0;
}
