#include <iostream>
#include <vector>

using namespace std;
//Varianta 2 problema 2
/*
 *  Se consideră o tablă de șah nxm (n,m date). Pe fiecare careul al tablei este plasat câte un obiect, fiecare cu o anumită valoare (cunoscută, număr natural).
 *  Pe tablă se deplasează un robot astfel:  pornește de pe ultima linie și prima coloană (un colț al tablei) și se poate deplasa numai în direcțiile nord și est.
 *  La parcurgerea unei celule robotul adună obiectul din celulă. Să se determine un traseu al robotului până în poziția (1, m) (până în colțul opus celui din care a plecat) astfel încât valoarea totală a obiectelor adunate să fie maximă.
 *  Se vor afişa valoarea totală obţinută şi traseul optim. O(nm)
 */

int main() {

    int sah[50][50], n, m;
    int dp[50][50];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> sah[i][j];
            dp[i][j] = 0;
        }
    }

    //dp[i][j] - scorul maxim care se termina pe pozitia i, j;
    dp[n - 1][0] = sah[n - 1][0];
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i][0] = dp[i + 1][0] + sah[i][0];
    }

    for (int i = 1; i < m; i++)
    {
        dp[n - 1][i] = dp[n - 1][i - 1] + sah[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]) + sah[i][j];
        }
    }
    vector< pair<int, int> > path;
    int i = 0, j = m - 1;
    while (i < n - 1 && j > 0)
    {
        path.push_back(make_pair(i, j));
        if (dp[i][j - 1] > dp[i + 1][j])
        {
            j--;
        } else{
            i++;
        }
    }

    if (j == 0)
    {
        while (i < n)
        {
            path.push_back(make_pair(i, j));
            i++;
        }
    }

    if (i == n - 1)
    {
        while (j >= 0)
        {
            path.push_back(make_pair(i, j));
            j--;
        }
    }

    for (int k = path.size() - 1; k >= 0; k--)
    {
        cout << path[k].first << " " << path[k].second << endl;
    }

    cout << dp[0][m - 1];

    return 0;
}