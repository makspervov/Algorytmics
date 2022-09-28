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
 //---------------------------- zadanie 1

 void FlagaPolska(student *tab, int n, int granica)
{
    int i = 0;
    int j = n - 1;
    cout << "Podaj granice poszukiwania: ";
    cin >> granica;
    while (i < j)
    {
        while (i < j && tab[i].punkty <= granica) i++;
        while (i < j && tab[j].punkty > granica) j--;
        if (i < j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    if (tab[i].punkty <= granica) i++;
}

//---------------------------- zadanie 2

void SelectSort(int* tab, int n) //n - ilość elementów do posortowania
{
    int imin; //zmienna pomocnicza przechowująca indeks komórki z minimalną wartością
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        imin = i;
        for (j = i + 1; j < n; j++)
        {
            if (tab[j].punkty < tab[imin].punkty) imin = j;
        }
        swap(tab[i], tab[imin]);
    }
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

        //Код завдання 1

        return main();
    }
    if (opcja == 2)
    {
        cout << "\nZadanie 2" << endl << endl;

        //Код завдання 2

        return main();
    }
    if (opcja == 3)
    {
        cout << "\nZadanie 3" << endl << endl;

        //Код завдання 3

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
