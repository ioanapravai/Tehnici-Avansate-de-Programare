#include <iostream>
#include <vector>
using namespace std;
/*
 * Se dau n activități prin timpul de început, timpul de sfârșit și profitul asociat desfășurării activității (n intervale închise cu extremităţi numere reale care au asociate ponderi).
 * Să se determine o submulțime de activități compatibile (intervale disjuncte două câte două) care au profitul total maxim.
 * Se vor afişa profitul total şi activităţile O(n2)/O(nlog n)
 */

struct activity
{
    int start;
    int final;
    int profit;
};


void show(vector< activity > activities, int dp[][50], int n, int i)
{
    cout << activities[i].start << " " << activities[i].final << endl;
    if(i == n - 1)
    {
        return;
    }
    for(int j = i + 1; j < n; j++)
    {
        if(dp[i][j] != dp[i][j - 1])
        {
            cout << activities[j].start << " " << activities[j].final << endl;
        }
    }
}

void showReverse(vector< activity > activities, int dp[][50], int n, int i)
{
    cout << activities[i].start << " " << activities[i].final << endl;
    if(i == 0)
    {
        return;
    }
    for(int j = i - 1; j >= 0; j--)
    {
        if(dp[i][j] != dp[i][j + 1])
        {
            cout << activities[j].start << " " << activities[j].final << endl;
        }
    }
}

int main() {

    int n;
    vector<activity> activities;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        activity a;
        cin >> a.start >> a.final >> a.profit;
        activities.push_back(a);
    }
    //dp[i][j] - profitul maxim cu activitatile de la i pana la j
    int dp[50][50];
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = activities[i].profit;
    }
    activity lastActivity;
    for(int i = 0; i < n; i++)
    {
        lastActivity = activities[i];
        for(int j = i + 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1];

            if(lastActivity.final < activities[j].start)
            {
                dp[i][j] += activities[j].profit;
                lastActivity = activities[j];
            }
        }

        lastActivity = activities[i];
        if(i > 0)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                dp[i][j] = dp[i][j + 1];
                if(lastActivity.start > activities[j].final)
                {
                    dp[i][j] += activities[j].profit;
                    lastActivity = activities[j];
                }
            }
        }
    }

    int max = 0, position_i = 0, position_j;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dp[i][j] > max)
            {
                max = dp[i][j];
                position_i = i;
                position_j = j;
            }
        }
    }
    cout << max << endl;
    if(position_j >= position_i)
    {
        show(activities, dp, n, position_i);
    } else {
        showReverse(activities, dp, n, position_i);
    }

    return 0;
}