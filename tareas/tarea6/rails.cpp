#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void compare(int n, int l)
{
    bool flag = true;
    int k;
    vector<int> ini;
    ini.push_back(l);
    for (int i = 0; i < n && flag; i++)
    {
        cin >> k;
        ini.push_back(k);
        // printf("k: %d ", k);
    }

    stack<int> ans;
    int pos = 1, i = 0;
    while (pos <= n + 1 && flag)
    {
        ans.push(pos);
        bool ansFlag = true;

        while (!ans.empty() && ans.top() == ini[i] && ansFlag)
        {
            ans.pop();

            i++;
            if (i > n)
                ansFlag = false;
        }
        pos++;
    }

    if (ans.empty())
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
    int n, k;
    cin >> n;
    while (n != 0)
    {
        cin >> k;
        while (k != 0)
        {
            compare(n - 1, k);
            cin >> k;
        }

        printf("\n");
        cin >> n;
    }

    return 0;
}
