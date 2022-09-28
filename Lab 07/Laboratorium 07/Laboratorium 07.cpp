#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<cstdlib>

using namespace std;

struct student
{
	string imie;
	string nazwisko;
	int punkty;
};

void wczytajStudentow(student tab[], int liczbaStudentow)
{
	ifstream plik;
	plik.open("studenci.csv");
	string linia, pomoc;
	int i;
	char sredniki;
	for (i = 0; i < 2; i++) plik >> sredniki;
	for (i = 0; i < liczbaStudentow; i++) {
		plik >> linia;
		istringstream ss(linia);
		getline(ss, tab[i].imie, ';');
		getline(ss, tab[i].nazwisko, ';');
		getline(ss, pomoc);
		tab[i].punkty = atoi(pomoc.c_str());
	}
}

void sortowanieBabelkowe(student tab[], int n)
{
	int j, i, zp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (tab[j].punkty > tab[j + 1].punkty) {
				swap(tab[j], tab[j + 1]);
			}
		}
	}
}
 
int wyszukiwanieLiniowe(student tab[], int t[], int n, int w) 
{
	int i, j = 0;
	for (i = 0; i < n; i++) {
		if (tab[i].punkty == w) {
			t[j] = i;
			j++;
		}
	}
	return j;
}

void bisekcja()
{

}

int main()
{
	int liczbaStudentow, op = 1, w, j, i;
	int prawy, lewy;
	ifstream plik;
	plik.open("studenci.csv");
	plik >> liczbaStudentow;
	student tab[liczbaStudentow];
	cout << "Menu" << endl << "1. Wczytanie danych\n2. Wyszukiwanie liniowe\n3. Wyszukiwanie bisekcyjne\n0. Wyjscie";
	while (op != 0) {
		cout << endl << "Podaj opcje: ";
		cin >> op;
		if (op == 1)
		{
			wczytajStudentow(tab, liczbaStudentow);
		}
		if (op == 2)
		{
			cout << "Podaj wyszukiwana wartosc: ";
			cin >> w;
			int t[liczbaStudentow];
			j = wyszukiwanieLiniowe(tab, t, liczbaStudentow, w);
			if (j == 0) cout << "Wzorca nie znaleziono";
			else
			{
				cout << "Studenci o podanej liczbie punktow:\n";
				for (i = 0; i < j; i++) {
					cout << tab[t[i]].imie << " " << tab[t[i]].nazwisko << endl;
				}
			}
		}
		if (op == 3)
		{
			cout << "Podaj wyszukiwana wartosc: ";
			/*cin >> w;
			sortowanieBabelkowe(tab, liczbaStudentow);
			//for(i=0; i<liczbaStudentow; i++) cout<<tab[i].punkty<<" ";
			j = bisekcja(tab, liczbaStudentow, w, prawy, lewy);
			if (j == 0) cout << "Wzorca nie znaleziono";
			else
			{
				cout << "Studenci o podanej liczbie punktow:\n";
				for (i = lewy; i <= prawy; i++) {
					cout << tab[i].imie << " " << tab[i].nazwisko << endl;
				}
			}*/
		}
	}
	plik.close();
	return 0;
}