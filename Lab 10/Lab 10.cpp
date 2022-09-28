#include <iostream>
#include <fstream>
using namespace std;

struct element
{
	char character;
	element* next;
};

struct queue
{
	element* head;
	element* tail;
};

void wczytaj()
{
	ifstream plik;
	plik.open("lab10_tekst.txt");


	plik.close();
}

void push(queue &q, char value)
{
	element* el = new element;
	el->character = value;
	el->next = nullptr;
	if (q.tail != nullptr)
	{
		q.tail->next = el;
	}
	else
	{
		q.head = el;
	}
	q.tail = el;
}

void pop(queue& q)
{
	element* temp = q.head;
	q.head = q.head->next;
	delete temp;
	if (q.head == nullptr)
	{
		q.tail = nullptr;
	}
}

int czyPusty(queue q)
{
	if (q.head == nullptr)
	{
		cout << "Lista jest pusta";
		return 1;
	}
	else
	{
		cout << "Lista nie jest pusta";
		return 0;
	}
}

int pierwszy(queue q)
{
	return q.head->character;
}

int main()
{
	int opcja;
	cout << "Pervov Maksym, GL13" << endl << "Podstawy Algorytmiki" << endl << "Menu:" << endl;
	cout << endl << "1. Sprawdzenie, czy kolejka jest pusta" << endl
		<< "2. Dodanie elementu do kolejki" << endl
		<< "3. Ususniecie elementu z kolejki" << endl
		<< "4. Pobranie elementu z kolejki" << endl
		<< "5. Usuniecie wszystkich elementow z kolejki" << endl
		<< "6. Wczytanie do kolejki duzych liter alfabetu lacinskiego" << endl
		<< "0. Wyjscie z programu" << endl;
	cout << endl << "Wybierz funkcje: ";
	cin >> opcja;
	if (opcja == 1)
	{
		if (czyPusty == 0) cout << "Kolejka jest pusta" << endl << endl << endl;
		else cout << "Kolejka nie jest pusta" << endl << endl << endl;
		return main();
	}
	if (opcja == 2)
	{
		char klzn;
		cout << "Dodaj kolejny znak: ";
		cin >> klzn;
		return main();
	}
	if (opcja == 3)
	{

		return main();
	}
	if (opcja == 4)
	{
		return main();
	}
	if (opcja == 5)
	{
		return main();
	}
	if (opcja == 6)
	{
		return main();
	}
	if (opcja == 0)
	{
		cout << "Do widzenia! :)" << endl;
		system("pause");
		return 0;
	}
	if (opcja != 0 && opcja != 1 && opcja != 2 && opcja != 3)
	{
		cout << "Niepoprawna liczba! Sprobuj ponownie :)" << endl << endl;
		cout << endl << "Wybierz funkcje: ";
		cin >> opcja;
	}
	queue q;
	q.head = nullptr;
	q.tail = nullptr;
}