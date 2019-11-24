#include <iostream>
#include <vector>
using namespace std;
/*
 * Se consideră un şir de n piese de domino. O piesă de domino are formă dreptunghiulară şi are înscrisă pe ea două numere.
 * Conform regulilor la domino, un lanţ de piese este un subşir al şirului de piese iniţial constituit din piese care respectă următoarea condiţie: pentru oricare două piese consecutive din lanţ, al doilea număr înscris pe prima din cele două piese coincide cu primul număr înscris pe cea de a doua piesă (piesele nu se pot roti).
 * Se citesc din fișierul date.in  un număr natural n și un șir de n perechi ordonate de numere reprezentând piese de domino.
 * a) Să se determine un lanţ de lungime maximă care se poate obţine cu piesele din şirul dat (adică un cel mai lung subșir de perechi cu proprietatea că, pentru oricare două perechi consecutive din subșir, ultimul număr din prima pereche coincide cu primul număr din cea de a doua pereche).
 * b) Determinați câte astfel de subșiruri de lungime maximă există.
 */

void show(vector< pair<int, int> > pieces, int dp[][100], int n, int i)
{
    cout << pieces[i].first << " " << pieces[i].second << endl;
    if(i == n - 1)
    {
        return;
    }
    for(int j = i + 1; j < n; j++)
    {
        if(dp[i][j] != dp[i][j - 1])
        {
            cout << pieces[j].first << " " << pieces[j].second << endl;
        }
    }
}

void showReverse(vector< pair<int, int> > pieces, int dp[][100], int n, int i)
{
    cout << pieces[i].first << " " << pieces[i].second << endl;
    if(i == 0)
    {
        return;
    }
    for(int j = i - 1; j >= 0; j--)
    {
        if(dp[i][j] != dp[i][j + 1])
        {
            cout << pieces[j].first << " " << pieces[j].second << endl;
        }
    }
}


int main() {

    vector < pair<int, int> > pieces;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pieces.push_back(make_pair(x, y));
    }

    //dp[i][j] - lungimea maxima a unui subsir format cu piesele de la i la j
    int dp[100][100];

    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 1; //diagonala principala = 1
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        pair<int, int> lastPiece = pieces[i];
        for(int j = i + 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if(lastPiece.second == pieces[j].first)
            {
                dp[i][j]++;
                lastPiece = pieces[j];
            }
        }

        if(i > 0)
        {
            lastPiece = pieces[i];
            for(int j = i - 1; j >= 0; j--)
            {
                dp[i][j] = dp[i][j + 1];
                if(lastPiece.first == pieces[j].second)
                {
                    dp[i][j]++;
                    lastPiece = pieces[j];
                }
            }
        }
    }

    int max = 0, position_i = 0, position_j = 0;
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

    if(position_j >= position_i)
    {
        show(pieces, dp, n, position_i);
    } else{
        showReverse(pieces, dp, n, position_i);
    }

    int maxCount = 0;

    for(int i = 0; i < n; i++)
    {
        bool foundMax = false;
        for(int j = 0; j < n; j++)
        {
            if(dp[i][j] == max)
            {
                foundMax = true;
            }
        }
        if(foundMax)
        {
            maxCount++;
        }
    }
    cout << maxCount;


    return 0;
}