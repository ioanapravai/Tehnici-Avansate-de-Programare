#include <iostream>
#include <vector>
using  namespace std;

/*
 * Se dă un vector a=(a1,…an) de tip munte
 * există un indice i astfel încât a1<a2<…<ai > ai+1>…>an; ai se numește vârful muntelui
 * Propuneți un algoritm O(log n) care determină vârful muntelui
 * în calculul complexității algoritmului nu se consideră și citirea vectorului
 */


int findPeakElement(int elements[], int start, int stop, int n)
{
    int middle = start + (stop - start)/2;
    if((middle == 0 || elements[middle - 1] <= elements[middle]) && (elements[middle + 1] <= elements[middle] || middle == n - 1))
    {
        return middle; //am gasit varful muntelui
    }
    else if(middle > 0 && elements[middle - 1] > elements[middle])
        {
            return findPeakElement(elements, start, (middle-1), n); //varful muntelui e in stanga vectorului
        } else
            {
                return findPeakElement(elements, (middle + 1), stop, n);//varful muntelui e in dreapta vectorului
            }
}

int findPeak(int elemente[], int n)
{
    findPeakElement(elemente, 0, n-1, n);
}

int main() {
    int elements[20];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> elements[i];
    }
    int peak = findPeak(elements, n);
    cout <<"Peak Element: " << elements[peak];
    return 0;
}