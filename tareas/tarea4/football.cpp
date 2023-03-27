#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string transformCad(string cad)
{
    string comp, letter;
    int asc;
    for (int i = 0; i < cad.size(); i++)
    {
        asc = cad[i];
        if (asc >= 97 and asc <= 122)
        {
            letter = cad[i] - 32;
            comp += letter;
        }
        else
        {
            letter = cad[i];
            comp += letter;
        }
    }
    return comp;
}

class Team
{
public:
    int points;
    int nGames;
    int scoreG;
    int against;
    int goalDiff;
    double percentage;
    string name;

    Team()
    {
        points = 0;
        nGames = 0;
        scoreG = 0;
        against = 0;
        goalDiff = 0;
        percentage = 0;
        name;
    }

    void update(int goalsScore, int goalsAgainst)
    {
        scoreG += goalsScore;
        against += goalsAgainst;
        goalDiff = scoreG - against;
        if (goalsScore > goalsAgainst)
        {
            points += 3;
        }
        else if (goalsScore == goalsAgainst)
        {
            points++;
        }
        nGames++;
    }

    bool operator<(const Team &est)
    {
        bool ans = false;
        if (points != est.points)
        {
            ans = points > est.points;
        }
        else if (goalDiff != est.goalDiff)
        {
            ans = goalDiff > est.goalDiff;
        }
        else if (scoreG != est.scoreG)
        {
            ans = scoreG > est.scoreG;
        }
        else
        {
            string tname = transformCad(name), comp = transformCad(est.name);

            ans = tname < comp;
        }
        return ans;
    }
};

int main()
{
    int nT = 1, nG = 1;
    string indiTeam;
    while (nT != 0 && nG != 0)
    {
        scanf("%d", &nT);
        scanf("%d", &nG);
        vector<Team> teams;
        cin.ignore();
        for (int i = 0; i < nT; i++)
        {
            cin >> indiTeam;
            Team te;
            te.name = indiTeam;
            teams.push_back(te);
        }
        int homeGoals, visitantGoals;
        string home, visitant, line;
        for (int i = 0; i < nG; i++)
        {
            cin >> home >> homeGoals >> line >> visitantGoals >> visitant;
            for (vector<Team>::iterator it = teams.begin(); it != teams.end(); it++)
            {
                if ((*it).name == home)
                {
                    (*it).update(homeGoals, visitantGoals);
                }
                if ((*it).name == visitant)
                {
                    (*it).update(visitantGoals, homeGoals);
                }
            }
        }
        sort(teams.begin(), teams.end());
        int position = 1;
        for (vector<Team>::iterator it = teams.begin(); it != teams.end(); it++)
        {
            const char *cName = ((*it).name).c_str();
            if ((*it).nGames > 0)
            {
                (*it).percentage = ((*it).points * 100.0) / ((*it).nGames * 3);
                if (it != teams.begin())
                {
                    if ((*it).points == (*(it - 1)).points and (*it).goalDiff == (*(it - 1)).goalDiff and (*it).scoreG == (*(it - 1)).scoreG)
                    {
                        printf("%19s%4d%4d%4d%4d%4d%7.2f\n", cName, (*it).points, (*it).nGames, (*it).scoreG, (*it).against, (*it).goalDiff, ((*it).points * 100.0) / ((*it).nGames * 3));
                    }
                    else
                    {
                        printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n", position, cName, (*it).points, (*it).nGames, (*it).scoreG, (*it).against, (*it).goalDiff, ((*it).points * 100.0) / ((*it).nGames * 3));
                    }
                }
                else
                {
                    printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n", position, cName, (*it).points, (*it).nGames, (*it).scoreG, (*it).against, (*it).goalDiff, ((*it).points * 100.0) / ((*it).nGames * 3));
                }
                position++;
            }
            else
            {
                char noGame[4] = "N/A";
                if (it != teams.begin())
                {
                    if ((*it).points == (*(it - 1)).points and (*it).goalDiff == (*(it - 1)).goalDiff and (*it).scoreG == (*(it - 1)).scoreG)
                    {
                        printf("%19s%4d%4d%4d%4d%4d%7s\n", cName, (*it).points, (*it).nGames, (*it).scoreG, (*it).against, (*it).goalDiff, noGame);
                    }
                    else
                    {
                        printf("%2d.%16s%4d%4d%4d%4d%4d%7s\n", position, cName, (*it).points, (*it).nGames, (*it).scoreG, (*it).against, (*it).goalDiff, noGame);
                    }
                }
                else
                {
                    printf("%2d.%16s%4d%4d%4d%4d%4d%7s\n", position, cName, (*it).points, (*it).nGames, (*it).scoreG, (*it).against, (*it).goalDiff, noGame);
                }
                position++;
            }
        }
        printf("\n");
    }
    return 0;
}
