#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

void WczytajDane(int*& tab, int *n, string plik) // n - rozmiar podanej tablicy tab
{
    ifstream odczyt;
    odczyt.open(plik.c_str()); // podajemy nazwe pliku
    odczyt >> *n;
    tab = new int[*n];
    for (int i = 0; i < *n; i++)
    {
        odczyt >> tab[i];
    }
    odczyt.close();
}

void FlagaPolska(int *tab, int n, int granica)
{
    int i = 0;
    int j = n - 1;
    cout << "Podaj granice poszukiwania: ";
    cin >> granica;
    while (i < j)
    {
        while (i < j && tab[i] <= granica) i++;
        while (i < j && tab[j] > granica) j--;
        if (i < j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    if (tab[i] <= granica) i++;
}

void FlagaFrancuska(int* tab, int n, int granica, int granica2)
{
    int i = -1;
    int j = 0;
    int k = n;
    while (j < k)
    {
        if (tab[j] % 3 == 0)
        {
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else
        {
            if (tab[j] % 3 == 2)
            {
                k--;
                swap(tab[k], tab[j]);
            }
            else j++;
        }
    }
}

void QuickSort(int* tab, int lewy, int prawy, int tryb)
{
    int srodek;
    srodek = (int)(lewy + prawy) / 2;
    int piwot = tab[srodek];
    tab[srodek] = tab[prawy];
    int granica = lewy;
    for (int i = lewy; i < prawy; i++)
    {
        if (tab[i] < piwot)
        {
            swap(tab[granica], tab[i]);
            granica = granica + 1;
        }
    }
    tab[prawy] = tab[granica];
    tab[granica] = piwot;
    if (lewy < granica - 1)
    {
        QuickSort(tab, lewy, granica - 1, 1);
    }
    if (granica + 1 < prawy)
    {
        QuickSort(tab, granica + 1, prawy, 1);
    }
}

void BubbleSort(int* tab, int n, int tryb)
{
    int stan;
    for (int i = n - 1;0 < i;i--)
    {
        stan = 1;
        for (int j = 0;j < i;j++)
        {
            if (tryb == 1)
            {
                if (tab[j] > tab[j + 1])
                {
                    swap(tab[j], tab[j + 1]);
                    stan = 0;
                }
            }
            else
            {
                if (tab[j] < tab[j + 1])
                {
                    swap(tab[j], tab[j + 1]);
                    stan = 0;
                }
            }
        }
        if (stan == 0) break;
    }
}

void InsertSort(int* tab, int n)
{
    /*int i, j, t;

    for (i = 1; i < n; ++i)
    {
        j = i;
        while ((j > 0) && (tab[j - 1] > tab[j]))
        {
            t = tab[j];
            tab[j] = tab[j - 1];
            tab[j - 1] = t;
            --j;
        }
    }*/
    int j, t;
    for (int i = 1; i < n; i++) {
        t = tab[i];
        j = i;
        while (j > 0 && tab[j - 1] > t) {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = t;
    }
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

int Liniowe(int tab[], int t[], int n, int w)
{
    int i, j = 0;
    for (i = 0; i < n; i++) 
    {
        if (tab[i] == w) 
        {
            t[j] = i;
            j++;
        }
    }
    return j;
}

int Bisekcja(int tab[], int n, int w, int& prawy, int& lewy)
{
    int j = 0, srodek, i;
    lewy = 0;
    prawy = n - 1;
    while (lewy <= prawy)
    {
        srodek = (int)(lewy + prawy) / 2;
        if (tab[srodek] == w)
        {
            j = srodek;
            break;
        }
        else if (w < tab[srodek]) prawy = srodek - 1;
        else lewy = srodek + 1;
    }
    if (j != 0)
    {
        int p = j;
        while (tab[j] == tab[j + 1] && tab[p] == tab[p - 1])
        {
            if (tab[j] == tab[j + 1])
            {
                prawy = j + 1;
                j++;
            }
            else prawy = j;
        }
        if (tab[p] == tab[p - 1])
        {
            lewy = p - 1;
            p--;
        }
        else lewy = p;
    }
    return j;
}

void AlgorytmKMP()
{

}

void Naiwny()
{

}

void AlgorytmKR()
{

}

int main()
{
    int opcja;
    cout << "Pervov Maksym, GL13" << endl << "Podstawy Algorytmiki" << endl << "Kolokwium 1\tGrupa B" << endl << "Menu:" << endl << "1 - Zadanie 1" << endl << "2 - Zadanie 2" << endl << "3 - Zadanie 3" << endl << "0 - Wyjscie" << endl;
    cout << endl << "Wybierz zadanie: ";
    cin >> opcja;
    if (opcja == 1)
    {
        cout << "\nZadanie 1" << endl << endl;

        int* tab;
        //Код завдання 1
        delete[] tab;
        return main();
    }
    if (opcja == 2)
    {   
        cout << "\nZadanie 2" << endl << endl;

        int* tab2;
        //Код завдання 2
        delete[] tab2;
        return main();
    }
    if (opcja == 3)
    {
        cout << "\nZadanie 3" << endl << endl;

        int* tab3;
        //Код завдання 3
        delete[] tab3;
                return main();
    }
    if (opcja == 0)
    {
        cout << "Do widzenia! :)" << endl;
    }
    if (opcja != 0 && opcja != 1 && opcja != 2 && opcja != 3)
    {
        cout << "Niepoprawna liczba! Sprobuj ponownie :)" << endl << endl;
        return main();
    }
    
    system("pause");
    return 0;
}
