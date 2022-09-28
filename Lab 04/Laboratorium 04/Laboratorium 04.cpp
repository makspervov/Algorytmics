#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
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

void FlagaPolska(student* tab, int n, int granica)
{
    int i = 0;
    int j = n-1;
    while (i < j)
    {
        while (i < j && tab[i].punkty <= granica) i++;
        while (i > j && tab[j].punkty > granica) j--;
        if (i < j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    
    if (tab[i].punkty <= granica) i++;

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

    FlagaPolska(tab, 0, liczbaStudentow, 1);
    cout << endl << "Po sortowaniu za Algorytmem Flagi Polksiej" << endl << endl;

    cout << endl
    wyswietlStudentow(tab, liczbaStudentow);

    usunTabliceStudentow(tab);

    system("pause");
    return 0;
}