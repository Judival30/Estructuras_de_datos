#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void winner(vector<int> points)
{
    int max = points[0], cont = 0;
    for (int i = 1; i < points.size(); i++)
    {
        if (max < points[i])
        {
            max = points[i];
            cont = i;
        }
        if (points[i] == max)
        {
            cont = i;
        }
    }

    for (int i = 0; i < points.size(); i++)
    {
        if (points[i] == max)
        {
            if (i != cont)
            {
                cout << i + 1 << " ";
            }
            else
            {
                cout << i + 1;
            }
        }
    }
    cout << endl;
}

void sumPoints(vector<vector<int>> totalGrandP, vector<vector<int>> totalSystems, int nG, int nP, int nSys)
{
    vector<int> sumPt;
    int n;
    int k, flag;
    for (int i = 0; i < nSys; i++)
    {
        sumPt.resize(nP, 0);
        int position;
        for (int j = 0; j < nG; j++)
        {
            position = 1;
            for (int m = 0; m < totalSystems[i].size(); m++)
            {
                k = 0;
                flag = 0;
                while (k < nP && flag == 0)
                {
                    if (position <= totalSystems[i].size())
                    {
                        if (totalGrandP[j][k] == position)
                        {
                            n = sumPt[k];
                            n += totalSystems[i][position - 1];
                            sumPt[k] = n;
                            position++;
                            flag = 1;
                            k = 0;
                        }
                    }
                    else
                    {
                        flag = 1;
                    }
                    k++;
                }
            }
        }

        winner(sumPt);
        sumPt.clear();
    }
}

int main()
{
    int nG = 1, nP = 1, x, nSys, pointed, pt;
    vector<vector<int>> tG;
    vector<vector<int>> tSysPt;
    vector<int> individual;
    vector<int> ans;
    while (nG != 0 && nP != 0)
    {
        scanf("%d", &nG);
        scanf("%d", &nP);
        for (int i = 0; i < nG; i++)
        {
            for (int j = 0; j < nP; j++)
            {
                scanf("%d", &x);
                individual.push_back(x);
            }
            tG.push_back(individual);
            individual.clear();
        }
        if (nG != 0 && nP != 0)
        {
            scanf("%d", &nSys);
        }
        else
        {
            nSys = 0;
        }
        for (int i = 0; i < nSys; i++)
        {
            scanf("%d", &pointed);
            for (int j = 0; j < pointed; j++)
            {
                scanf("%d", &pt);
                individual.push_back(pt);
            }
            tSysPt.push_back(individual);
            individual.clear();
        }

        sumPoints(tG, tSysPt, nG, nP, nSys);
        tG.clear();
        tSysPt.clear();
    }
    return 0;
}
