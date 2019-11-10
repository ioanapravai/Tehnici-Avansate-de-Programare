#include <iostream>
#include <vector>
using namespace std;
//Solutie: impartim problema in 4 submatrici
//1 << n = 2^n
// cadran 1: x, y: 0 - 2^(n-1)
// cadran 2: x: 0 - 2^(n-1), y: 2^(n-1) - (2^n)-1
// cadran 3: x: 2^(n-1) - (2^n)-1, y: 0 - 2^(n-1)
// cadran 4: x: 2^(n-1) - (2^n)-1, y: 2^(n-1) - (2^n)-1
//T(2^2n) = T(2^2n/4) + O(1) -> relatia de recurenta => O(n)
struct Pereche
{
    int x, y;
};

int determinaCadran(int n, Pereche pereche)
{
    if(pereche.x <= (1 << (n - 1)))
    {
        if(pereche.y <= (1 << (n - 1)))
        {
            return 1;
        }
        return 2;
    }

    if(pereche.y <= (1 << (n - 1)))
    {
        return 3;
    }
    return 4;
}

int dei(int n, Pereche pereche)
{
    if(n == 0)
        return 1;
    int cadran = determinaCadran(n, pereche);
    if(cadran == 1)
    {
        return dei(n - 1, pereche);
    }
    if(cadran == 2)
    {
        pereche.y = pereche.y - (1 << (n - 1));
        return (1 << (2*n-2)) + dei(n-1, pereche);
    }
    if(cadran == 3)
    {
        pereche.x = pereche.x - (1 << (n - 1));
        return (1 << (2*n - 2))*2 + dei(n - 1, pereche);
    }
    if(cadran == 4)
    {
        pereche.y = pereche.y - (1 << (n - 1));
        pereche.x = pereche.x - (1 << (n - 1));
        return (1 << (2*n - 2))*3 + dei(n - 1, pereche);
    }
}

int main() {
    int n, k;
    cout << "2^n * 2^n este dimensiunea matricei, iar k este numarul de elemente cautate in matrice: ";
    cin >> n >> k;
  //  vector<Pereche> coordonate;
    for(int i = 0; i < k; i++)
    {
        Pereche a;
        cout << "Introduceti coordonatele elementelor cautate: ";
        cin >> a.x >> a.y;
        cout << endl;
    //    coordonate.push_back(a);
        cout << dei(n, a) << endl;
    }



    return 0;
}