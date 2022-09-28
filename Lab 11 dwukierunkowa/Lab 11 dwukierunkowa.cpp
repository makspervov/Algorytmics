#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

struct element
{
    int number;
    element* next;
    element* prev;
};

struct double_list
{
    element* head;
    element* tail;
    int counter;
};

int generatorLiczb() {
    int
        a = 1,
        b = 100;
    return rand() % (b - a + 1) + a;
}

void add_head(double_list& l, int value)
{
    element* el = new element;
    el->number = value;
    el->next = nullptr;
    el->prev = nullptr;
    l.head = el;
    if (l.head != nullptr)
    {
        l.head->prev = el;
        el->next = l.head;
    }
    else l.tail = el;
    l.head = el;
}

void add_position(double_list& l, int value, int position)
{
    element* temp = l.head;
    for (int i = 1;i < position - 1;i++) temp = temp->next;
    element* el = new element;
    el->number = value;
    el->prev = temp;
    el->next = temp->next;
    temp->next->prev = el;
    temp->next = el;
}

void add_tail(double_list& l, int value)
{
    element* el = new element;
    el->number = value;
    el->next = nullptr;
    el->prev = nullptr;
    if (l.tail != nullptr)
    {
        l.tail->next = el;
        el->prev = l.tail;
    }
    else l.head = el;
    l.tail = el;
}

void delete_head(double_list& l)
{
    element* temp = l.head;
    if (l.counter == 1)
    {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else
    {
        l.head = l.head->next;
        l.head->prev = nullptr;
    }
    delete temp;
}

void delete_position(double_list& l, int position)
{
    element* temp = l.head;
    for (int i = 1;i < position - 1;i++) temp = temp->next;
    element* temp_us = temp->next;
    temp->next = temp_us->next;
    temp->next->prev = temp;
    delete temp_us;
}

void delete_tail(double_list& l)
{
    element* temp = l.tail;
    if (l.counter == 1)
    {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else
    {
        l.tail = l.tail->prev;
        l.tail->next = nullptr;
    }
    delete temp;
}

int czyPusty(double_list& l)
{
    if (l.head == nullptr || l.tail == nullptr)
        return 1;
    else
        return 0;
}

bool czyPusty_element(element el)
{
    if (el.next == nullptr)
        return true;
    else
        return false;
}

void show(double_list l, int tryb) 
{
    cout << "Lista dwukierunkowa\n";

    if (tryb == 0) 
    {
        element* temp = l.head;
        for (int i = 1; i <= l.counter - 1; i++) 
        {
            cout << i << " - " << temp->number << endl;
            if (!czyPusty_element(*temp))
                temp = temp->next;
        }
    }
    else 
    {
        element *temp = l.tail;
        for (int i = 1; i <= l.counter - 1; i++)
        {
            cout << l.counter - i << " - " << temp->number << endl;
            if (temp->prev != nullptr)
                temp = temp->prev;
        }
    }
}

int min(double_list l) 
{
    int min = 0;
    element* temp = l.head;
    for (int i = 1; i <= l.counter - 1; i++) 
    {
        if (min > temp->number)
            min = temp->number;

        if (!czyPusty_element(*temp))
            temp = temp->next;
    }
    return min;
}


int main()
{
    double_list l;
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 1;

    unsigned int opcja, tempL, pos;
    bool wyjscie = false;
    cout << "Pervov Maksym, GL13" << endl << "Podstawy Algorytmiki" << endl << "Menu:" << endl;
    do
    {
        cout << endl << "1. Sprawdzenie, czy lista jest pusta" << endl
            << "2. Dodanie elementu na koniec listy" << endl
            << "3. Dodanie elementu na poczatek listy" << endl
            << "4. Dodanie elementu na pozycje o podanym numerze" << endl
            << "5. Ususniecie elementu z konca listy" << endl
            << "6. Ususniecie elementu z z poczatku listy" << endl
            << "7. Ususniecie elementu znajdujacego sie na okreslonej pozycji" << endl
            << "8. Wyswietlenie elementow od poczatku do konca" << endl
            << "9. Wyswietlenie elementow od konca do poczatku" << endl
            << "10. Znalezienie elementu minimalnego w liscie" << endl
            << "11. Usuniecie wszystkich elementow z listy wraz ze zwolnieniem pamieci" << endl
            << "12. Wyjscie z programu" << endl 
            << endl << ">>>>>>> ";
        cin >> opcja;
        switch (opcja)
        {
        case 1:
            if (czyPusty(l))
                cout << "Lista jest pusta!" << endl;
            else
                cout << "Lista ma " << l.counter - 1 << " elemetow" << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            tempL = generatorLiczb();
            add_tail(l, tempL);
            cout << "Liczba " << tempL << " zostala dodana do konca listy!" << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            tempL = generatorLiczb();
            add_tail(l, tempL);
            cout << "Liczba " << tempL << " zostala dodana do poczatku listy" << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            tempL = generatorLiczb();
            cout << "Podaj pozycje(1-" << l.counter - 1 << "): ";
            cin >> pos;
            add_head(l, tempL);
            if (pos <= 1)
            {
                add_head(l, tempL);
                cout << "Liczba " << tempL << " zostala dodana do poczatku listy!" << endl;
            }
            else if (pos > l.counter) 
            {
                add_tail(l, tempL);
                cout << "Liczba " << tempL << " zostala dodana do konca listy!" << endl;
            }
            else 
            {
                add_position(l, tempL, pos);
                cout << "Liczba " << tempL << " zostala dodana na pozycje " << pos << endl;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            if (czyPusty(l))
                cout << "Lista jest pusta!" << endl;
            else 
            {
                delete_tail(l);
                cout << "Zostal usuniety koncowy element z listy!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if (czyPusty(l))
                cout << "Lista jest pusta!" << endl;
            else 
            {
                delete_head(l);
                cout << "Zostal usuniety pierwszy element z listy!" << endl;
            }
            break;
            system("pause");
            system("cls");
        case 7:
            cout << "Podaj pozycje(1-" << l.counter - 1 << "): ";
            cin >> pos;
            if (czyPusty(l))
            {
                cout << "Lista jest pusta!" << endl;
                system("pause");
                system("cls");
                break;
            }
            else if (pos <= 1)
            {
                delete_head(l);
                cout << "Zostal usuniety pierwszy element z listy!" << endl;
            }
            else if (pos > l.counter)
            {
                delete_tail(l);
                cout << "Zostal usuniety koncowy element z listy!" << endl;
            }
            else
            {
                delete_position(l, pos);
                cout << "Zostal usuniety element z indeksem " << pos << "!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 8:
            if (czyPusty(l))
                cout << "Lista jest pusta!" << endl;
            else
                show(l, 0);
            system("pause");
            system("cls");
            break;
        case 9:
            if (czyPusty(l))
                cout << "Lista jest pusta!" << endl;
            else
                show(l, 1);
            system("pause");
            system("cls");
            break;
        case 10:
            if (czyPusty(l))
                cout << "Lista jest pusta!" << endl;
            else
                cout << "Minimalny element lista - " << min(l) << "!" << endl;
            system("pause");
            system("cls");
            break;
        case 11:
            if (czyPusty(l))
                cout << "Lista jest pusta!" << endl;
            else 
            {
                while (!czyPusty(l)) 
                {
                    delete_tail(l);
                }
                cout << "Wszystkie elementy zostaly usuniete!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 12:
            cout << "Do widzenia! :)" << endl;
            system("pause");
            return 0;
        }
    }
    while (!wyjscie);
}
