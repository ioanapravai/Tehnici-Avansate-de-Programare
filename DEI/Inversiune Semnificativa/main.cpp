#include <iostream>
using namespace std;

/*
 Se consideră un vector cu n elemente.
 Se numeşte inversiune semnificativă a vectorului o pereche perechi (i, j) cu proprietatea că i < j  şi ai > 2*aj.
 Să de determine numărul de inversiuni semnificative din vector.
 De exemplu, vectorul 4, 8, 11, 3, 5 are 3 inversiuni semnificative: (8,3), (11,3), (11,5)
 Complexitate - O(n log n)
*/


int merge(int v[], int temporar[], int stanga, int mijloc, int dreapta)
{
    int i, j, k, nrInv=0;
    i = stanga;
    j = mijloc;
    while ((i <= mijloc - 1) && (j <= dreapta))
    {
        if(v[i] > 2*v[j])
        {
            //vectorul este sortat asa ca luam inversiuni cu toate elementele de la i la mijloc
            nrInv += mijloc - i;
            j++;
        } else{
            i++;
        }
    }

    i = stanga;
    j = mijloc;
    //Folosim k pt a parcurge vectorul in care interclasam jumatatile
    k = stanga;
//interclasarea
    while ((i <= mijloc - 1) && (j <= dreapta)) {
        if (v[i] <= v[j]) {
            temporar[k++] = v[i++];
        }
        else {
            temporar[k++] = v[j++];
        }
    }

    while (i <= mijloc - 1)
    {
        temporar[k++] = v[i++];
    }

    while (j <= dreapta)
    {
        temporar[k++] = v[j++];
    }

    for(int i = stanga; i <= dreapta; i++)
    {
        v[i] = temporar[i];
    }
    return nrInv;
}

int _mergeSort(int v[], int temporar[], int stanga, int dreapta)
{
    int mijloc, nrInversiuni = 0;
    if(dreapta > stanga)
    {
        mijloc = (dreapta + stanga)/2;
        /* Cautam raspunsul la subproblema vectorului jumatatii din stanga
         * si din dreapta, apoi numaram inversiunile de la interclasare
         */
        nrInversiuni = _mergeSort(v, temporar, stanga, mijloc);
        nrInversiuni += _mergeSort(v, temporar, mijloc + 1, dreapta);
        nrInversiuni += merge(v, temporar, stanga, mijloc + 1, dreapta);
    }
    return nrInversiuni;
}

int mergeSort(int v[], int n)
{
    int temporar[n];
    return _mergeSort(v, temporar, 0, n-1);
}





int main()
{
    int v[100], n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << mergeSort(v, n);

    return 0;
}