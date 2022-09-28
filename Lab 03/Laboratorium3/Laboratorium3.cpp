#include <iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>

using namespace std;
struct punkt
{
    int x;
    int y;
};
struct student
{
    string imie;
    string nazwisko;
    int punkty;
};

void sortowanieQuickSort(student* tab, int lewy, int prawy, int tryb)
{
    int srodek;
    srodek = (int)(lewy + prawy) / 2;
    int piwot = tab[srodek].punkty;
    int granica = lewy;
    for (int i = lewy; i < prawy; i++)
    {
        if (tab[i].punkty < piwot)
        {
            swap(tab[granica], tab[i]);
            granica = granica + 1;
        }
    }
    tab[prawy].punkty = tab[granica].punkty;
    tab[granica].punkty = piwot;
    if (lewy < granica - 1)
    {
        sortowanieQuickSort(tab, lewy, granica - 1, 1);
    }
    if (granica + 1 < prawy)
    {
        sortowanieQuickSort(tab, granica + 1, prawy, 1);
    }
}

void wczytajStudentow(student*& tab, int n)
{
    string line, help;
    ifstream plik;
    char sr;

    plik.open("studenci.csv");
    int temp;
    plik >> temp;
    for (int i = 0; i < 2; i++)
        plik >> sr;

    for (int i = 0; i < n; i++)
    {
        plik >> line;
        istringstream ss(line);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, help);
        tab[i].punkty = atoi(help.c_str());
    }
    plik.close();

}

void usunTabliceStudentow(student*& tab)
{
    delete[] tab;
}

void wyswietlStudentow(student* tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Imie: " << tab[i].imie << " \t\tNazwisko: " << tab[i].nazwisko << " \t\tPunkty: " << tab[i].punkty << endl;
    }
}

int main()
{
    int liczbaStudentow;
    ifstream plik;

    student* tab;
    plik.open("studenci.csv");
    plik >> liczbaStudentow;
    
    tab = new student[liczbaStudentow];
    plik.close();

    wczytajStudentow(tab, liczbaStudentow);
    cout << "Przed sortowaniem" << endl << endl;
    wyswietlStudentow(tab, liczbaStudentow);

    sortowanieQuickSort(tab, 0, liczbaStudentow, 1);
    cout << endl << "Po sortowaniu" << endl << endl;
    wyswietlStudentow(tab, liczbaStudentow);
    
    usunTabliceStudentow(tab);

    system("pause");
    return 0;
}