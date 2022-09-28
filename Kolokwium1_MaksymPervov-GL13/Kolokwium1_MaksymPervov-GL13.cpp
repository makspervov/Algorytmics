#include <iostream>
#include <fstream>

using namespace std;

//------------------------------------------------------------------------------------ Zadanie 1

void wczytaj(int*& tab, int& n, string nazwa_pliku) //n rozmiar tablicy, tab tablica
{
    ifstream odczyt;
    odczyt.open(nazwa_pliku.c_str());
    odczyt >> n;
    tab = new int[n];
    for (int i = 0; i < n; i++)
    {
        odczyt >> tab[i];
    }
    odczyt.close();
}

void FlagaFrancuska(int* tab, int n, int *&index)
{
    int i = -1;
    int j = 0;
    int k = n;
    while (j < k)
    {
        if (tab[j] < 10)
        {
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else
        {
            if (100 <= tab[j] < 1000)
            {
                k--;
                swap(tab[k], tab[j]);
            }
            else j++;
        }
    }
}

void wyswietl3(int* tab, int n, int n1, int n2){
    for (int i = 0; i <= n1; i++){
        cout << tab[i]<< " Index: " << i << endl;
    }
    cout << endl;
    for (int i = n1+1; i < n2; i++){
         cout << tab[i]<< " Index: " << i << endl;
    }
    cout << endl;
    for (int i = n2; i < n; i++){
         cout << tab[i]<< " Index: " << i << endl;
    }

}

//------------------------------------------------------------------------------------ Zadanie 2

void wczytaj1(string& wzorzec, string nazwa_pliku) //wzorzec, nazwa pliku
{
    ifstream odczyt;
    odczyt.open(nazwa_pliku.c_str());
    odczyt >> wzorzec;
    odczyt.close();
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

void wyswietl(int* tab, int n, int k)
{
    cout << "Malejaco: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl << "Rosnaco: " << endl;
    for (int i = k; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}


//------------------------------------------------------------------------------------ Zadanie 3

void wczytaj2(string& wzorzec, string& tekst, string nazwa_pliku)
{
    ifstream odczyt;
    odczyt.open(nazwa_pliku.c_str());
    odczyt >> wzorzec;
    odczyt >> tekst;
    odczyt.close();
}

void zadanie3algorytm(int* tab, int n) // Algorytm
{

}

int main()
{

    cout << "\nZadanie 1" << endl << endl;

    int* tab;
    int n;

    wczytaj(tab, wzorzec, "grupaDDzad1.csv");
    int *index;
    FlagaFrancuska(tab, n, index);

    cout << "\nZadanie 2" << endl << endl;

    string wz;
    wczytaj1(wz, "grupaDDzad2.csv");


    cout << "Srednia arytmetyczna dwoch elementow: " << index_2[0] << endl;

    cout << "\nZadanie 3" << endl << endl;

    string tekst;
    wczytaj2(wzorzec, tekst,"grupaDzad3.txt");

    system("pause");
    return 0;
}
