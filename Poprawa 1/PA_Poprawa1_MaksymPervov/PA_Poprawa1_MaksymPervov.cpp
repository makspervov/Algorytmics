#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <locale.h>

using namespace std;

int generatorLiczb() 
{
    int
        a = 1,
        b = 100;
    return rand() % (b - a + 1) + a;
}

void SelectSort(int* tab, int n) //n - ilość elementów do posortowania
{
    int imin; //zmienna pomocnicza przechowująca indeks komórki z minimalną wartością
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        imin = i;
        for (j = i + 1; j < n; j++)
        {
            if (tab[j] < tab[imin]) imin = j;
        }
        swap(tab[i], tab[imin]);
    }
}

void wyswietlenieTablicy(int* tab, int n, int k)
{
    cout << "Malejąco: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl << "Rosnąco: " << endl;
    for (int i = k; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

int srednia(int* tab, int n, int*& index) 
{
    int i = 0, j = 1;
    int i_min = 0;
    int Min[(n / 2) + 1];
    int len = 0;

    for (int a = 0; a < n / 2; a++) 
    {
        if (tab[i] < tab[j]) 
        {
            Min[i_min] = tab[i];
            i_min++;
        }
        else 
        {
            Min[i_min] = tab[j];
            i_min++;
        }
        i += 2; j += 2;
        len++;
    }


    if (n % 2 != 0) 
    {
        len++;
        Min[i_min] = tab[n - 1];
        i_min++;
    }

    int min1 = Min[0], min2 = Min[1];

    for (int i = 0; i < i_min; i++) 
    {
        if (Min[i] < min1)
            min1 = Min[i];
        else if (Min[i] < min2)
            min2 = Min[i];
    }

    index = new int[1];
    index[0] = min1 + min2;
}

int main()
{
    setlocale(LC_CTYPE, "Polish");

    int* tab2;
    int n;

    int k = n / 2;
    wyswietlenieTablicy(tab2, n, 0);
    SelectSort(tab2, n);
    SelectSort(tab2, n);
    wyswietlenieTablicy(tab2, n, k);

    int* index_2;
    srednia(tab2, k, index_2);
    cout << "Srednia z najmniejszych elementów: " << index_2[0] << endl;

    system("pause");
    return 0;
}