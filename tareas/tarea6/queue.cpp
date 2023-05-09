#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    list<int> ans;
    string n, in;
    int p, d, cases = 1, pos;
    cin >> p >> d;
    while (p != 0 && d != 0)
    {
        printf("Case %d:\n", cases);
        if (p < 2000)
        {
            for (int i = 1; i <= p; i++)
                ans.push_back(i);
        }
        else
        {
            for (int i = 1; i <= 2000; i++)
                ans.push_back(i);
        }

        for (int i = 0; i < d; i++)
        {
            cin >> in;
            if (in == "E")
            {
                cin >> pos;
                bool flag = true;
                for (list<int>::iterator it = ans.begin(); it != ans.end() && flag; it++)
                {
                    if (*it == pos)
                    {
                        ans.erase(it);
                        flag = false;
                    }
                }
                ans.push_front(pos);
            }
            else
            {
                list<int>::iterator ref = ans.begin();
                printf("%d\n", *ref);
                ans.erase(ref);
                ans.push_back(*ref);
            }
        }
        cases++;
        ans.clear();
        cin >> p >> d;
    }
    return 0;
}