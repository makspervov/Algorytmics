#include <iostream>

using namespace std;

struct element
{
    int number;
    element* next;
};

struct single_list
{
    element* head;
    element* tail;
    int counter;
};

void add_head(single_list& l, int value)
{
    element* el = new element;
    el->number = value;
    el->next = l.head;
    l.head = el;
    if (l.tail == nullptr) l.tail = el;
}

void add_position(single_list& l, int value, int position)
{
    element* el = new element;
    el->number = value;
    element* temp = l.head;
    for (int i = 1;i < position-1;i++) temp = temp->next;
    el->next = temp->next;
    temp->next = el;
}

void add_tail(single_list &l, int value)
{
    element* el = new element;
    el->number = value;
    el->next = nullptr;
    if (l.tail != nullptr) l.tail->next = el;
    else l.head = el;
    l.tail = el;
}

void delete_head(single_list& l)
{
    element* temp = l.head;
    l.head = l.head->next;
    if (l.counter == 1) l.tail = nullptr;
    delete temp;
}

void delete_position(single_list& l, int position)
{
    element* prev = l.head;
    for (int i = 1; i < position - 1; i++) prev = prev->next;
    element* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void delete_tail(single_list& l)
{
    element* temp = l.tail;
    if (l.counter == 1)
    {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else
    {
        element* bef_temp = l.head;
        for (int i = 1; i < l.counter - 1; i++)
            bef_temp = bef_temp->next;
        l.tail = bef_temp;
        l.tail->next = nullptr;
    }
    delete temp;
}

int czyPusty(single_list& l)
{
    if (l.head == nullptr)
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

void pierwszy(single_list& l)
{
    if (l.head == nullptr) cout << "Lista jest pusta :(" << endl << endl;
    else cout << "Na poczatku lista jest taki znak:" << l.head->number << endl << endl;
}

void ostatni(single_list& l)
{
    if (l.head == nullptr) cout << "Lista jest pusta :(" << endl << endl;
    else cout << "Na koncu tego lista jest taki znak:" << l.tail->number << endl << endl;
}

void show(single_list l)
{
    element* temp = l.head;
    cout << "Lista jednokierunkowa\n";
    for (int i = 1; i <= l.counter - 1; i++) {
        cout << i << " - " << temp->number << endl;
        if (!czyPusty(temp))
            temp = temp->next;
    }
}

int main()
{
    single_list l;
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0;

    unsigned int opcja;
    bool wyjscie = false;
    cout << "Pervov Maksym, GL13" << endl << "Podstawy Algorytmiki" << endl << "Menu:" << endl;
    do
    {
        cout << endl << "1. Sprawdzenie, czy lista jest pusta" << endl
            << "2. Dodanie elementu na koniec listy" << endl
            << "3. Dodanie elementu na poczatek listy" << endl
            << "4. Dodanie elementu na na pozycje o podanym numerze" << endl
            << "5. Ususniecie elementu z konca listy" << endl
            << "6. Ususniecie elementu z z poczatku listy" << endl
            << "7. Ususniecie elementu znajdujacego sie na okreslonej pozycji" << endl
            << "8. Wyswietlenie elementow od poczatku do konca" << endl
            << "9. Wyswietlenie elementow od konca do poczatku" << endl
            << "10. Znalezienie elementu minimalnego w liscie" << endl
            << "11. Usuniecie wszystkich elementow z listy wraz ze zwolnieniem pamieci" << endl
            << "12. Wyjscie z programu" << endl;
        cout << endl << "Wybierz funkcje: ";
        cin >> opcja;
        switch (opcja)
        {
        case 1:
            czyPusty(l);
            cout << endl;
            break;
        case 2:
            int newel1;
            cout << "Wpisz nowy element: ";
            cin >> newel1;
            add_tail(l, newel1);
            cout << "Liczba " << newel1 << " zostala dodana do konca listy!" << endl;
            break;
        case 3:
            int newel2;
            cout << "Wpisz nowy element: ";
            cin >> newel2;
            add_head(l, newel2);
            cout << "Liczba " << newel2 << " zostala dodana do poczatku listy!" << endl;
            break;
        case 4:
            cout << "121212";
            break;
        case 5:
            cout << "121212";
            break;
        case 6:
            cout << "121212";
            break;
        case 7:
            cout << "121212";
            break;
        case 8:
            if (czyPusty(l))
                cout << "Lista jest pusta!" << endl;
            else
                show(l);
            break;
        case 9:
            cout << "121212";
            break;
        case 10:
            cout << "121212";
            break;
        case 11:
            cout << "121212";
            break;
        case 12:
            cout << "Do widzenia! :)" << endl;
            system("pause");
            return 0;
        }
    }     while (!wyjscie);
}
