#include <iostream>

using namespace std;

void Wczytaj()
{
	cout << "Wybrales zadanie 'Wczytanie danych'\n\n";

	string napis, wzorzec;
	cout << "Podaj wzorzec: ";
	getline(cin, wzorzec);
	cout << "Podaj napis: ";
	getline(cin, napis);
	cout << "Podany wzorzec: " << wzorzec << endl;
	cout << "Podany napis: " << napis << endl;
}

void AlgorytmNaiwny()
{

}

void AlgorytmKMP()
{

}

void AlgorytmBM()
{

}

void Exit()
{
	cout << "Do widzenia! Milego dnia!" << endl;
	system("pause");
}

int main()
{
	int wybor;
	cout << "Podstawy Algorytmiki" << endl << "Laboratorium 5" << endl << endl;
	cout << "\n1 ---> Wczytanie danych \n2 ---> Algorytm naiwny \n3 ---> Algorytm Knutha-Morrisa-Pratta \n4 ---> Algorytm Boyer'a-Moore'a \n5 ---> Wyjscie z programu" << endl << "Wybierz zadanie: ";
	cin >> wybor;
	if (wybor >= 1 || wybor <= 5) {
		switch (wybor)
		{
			case 1: Wczytaj(); break;
			case 2: AlgorytmNaiwny(); break;
			case 3: AlgorytmKMP(); break;
			case 4: AlgorytmBM(); break;
			case 5: Exit(); break;
		}
	}
	return 0;
}
