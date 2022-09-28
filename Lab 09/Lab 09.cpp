#include <iostream>

using namespace std;
struct element
{
	int number;
	element* next;
};

void push_stos(element*& stos, int wartosc)
{
	element* el = new element;
	el->number = wartosc;
	el->next = stos;
	stos = el;
}

void pop_stos(element*& stos)
{
	if (stos == nullptr)
	{
		cout << "Stos jest pusty!" << endl;
	}
	element* temp = stos;
	stos = stos->next;
	delete temp;
}

bool czyPusty_Stos(element* stos)
{
	if (stos == nullptr)
	{
		cout << "Stos jest pusty" << endl;
		return true;
	}
	else
	{
		cout << "Stos cos zawiera" << endl;
		return false;
	}
}

int top_stos(element* stos)
{
	return stos->number;
}

int main()
{
	element* stos = nullptr;

	czyPusty_Stos(stos);
	push_stos(stos, 1);
	cout << top_stos(stos) << endl;

	czyPusty_Stos(stos);
	push_stos(stos, 2);
	cout << endl << top_stos(stos) << endl;

	czyPusty_Stos(stos);
	pop_stos(stos);
	cout << endl << top_stos(stos) << endl;

	czyPusty_Stos(stos);
	pop_stos(stos);
	czyPusty_Stos(stos);

	system("pause");
	return 0;
}