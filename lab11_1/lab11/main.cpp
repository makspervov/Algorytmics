#include <iostream>
#include <cstdlib>
#include <time.h>
#include "lista.h"
//-std=c++0x

using namespace std;


int genLiczb(){
    int
        a = 1,
        b = 50;
    return rand()%(b-a+1)+a;
}

void zad_1();
void zad_2();
void zad_3();
void zad_4();

int main(){
    srand(time(NULL));
    unsigned int zad;
    bool wyjscie = false;
    do{
        cout << "Podaj nr zadania:" << endl
             << "0) - Wyscie" << endl
             << "1) - Lista jednokierunkowa" << endl
             << "2) - Lista dwukierunkowa"   << endl
             << "3) - Lista jednokierunkowa cykliczna" << endl
             << "4) - Lista dwukierunkowa cykloczna" << endl
             << ">>>>> ";
        cin >> zad;
        switch(zad){
            case 1:
                system("cls");
                zad_1();
                break;
            case 2:
                system("cls");
                zad_2();
                break;
            case 3:
                system("cls");
                zad_3();
                break;
            case 4:
                system("cls");
                zad_4();
                break;
            case 0:
                wyjscie = true;
                break;
            default:
                system("cls");
                break;
        }
    }while(!wyjscie);

    return 0;
}

void zad_1(){
    single_list lista;
    lista.head = nullptr;
    lista.tail = nullptr;
    lista.counter = 1;

    unsigned int
            zad,
            tempL,
            position
            ;
    bool wyjscie = false;
    do{
        cout << "Podaj nr dzialania:" << endl
             << "1)  - Sprawdzenie czy lista jest pusta" << endl
             << "2)  - Dodanie elementu na koniec listy" << endl
             << "3)  - Dodanie elementu na poczatek listy"   << endl
             << "4)  - Dodanie elementu na okreslona pozycje" << endl
             << "5)  - Usuniecie elementu z konca listy"   << endl
             << "6)  - Usuniecie elementu z poczatku listy" << endl
             << "7)  - Usuniecie elementu znajdujacego sie na okreslonej pozycji" << endl
             << "8)  - Pobranie pierwszego elementu z listy" << endl
             << "9)  - Pobranie ostatniego elementu z listy" << endl
             << "10) - Policzenie sredniej ary. elementow w liscie" << endl
             << "11) - Znalezienie elementu maksymalnego w liscie" << endl
             << "12) - Wyswietlenie calej listy" << endl
             << "13) - Usuniecie calej listy" << endl
             << "14) - Wyjscie" << endl
             << ">>>>> ";

        cin >> zad;

        switch(zad){

        case 1:
            if (isEmpty_lista_JK(lista))
                cout << "Lista jest pusta!" << endl;
            else
                cout << "Lista ma " << lista.counter-1 << " elemetow" << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            tempL = genLiczb();
            add_tail_JK(lista, tempL);
            cout << "Liczba " << tempL << " zostala dodana do konca listy!" << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            tempL = genLiczb();
            add_head_JK(lista, tempL);
            cout << "Liczba " << tempL << " zostala dodana do poczatku listy!" << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            tempL = genLiczb();
            cout << "Podaj pozycje(1-" << lista.counter << "): ";
            cin  >> position;
            if(position <= 1){
                add_head_JK(lista, tempL);
                cout << "Liczba " << tempL << " zostala dodana do poczatka listy!" << endl;
            }
            else if (position > lista.counter){
                add_tail_JK(lista, tempL);
                cout << "Liczba " << tempL << " zostala dodana do konca listy!" << endl;
            }
            else{
                add_position_JK(lista, tempL, position);
                cout << "Liczba " << tempL << " zostala dodana na pozycje " << position << "!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            if (isEmpty_lista_JK(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_tail_JK(lista);
                cout << "Zostal usuniety koncowy element z listy!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if (isEmpty_lista_JK(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_head_JK(lista);
                cout << "Zostal usuniety pierwszy element z listy!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 7:
            cout << "Podaj pozycje(1-" << lista.counter << "): ";
            cin  >> position;
            if (isEmpty_lista_JK(lista)){
                cout << "Lista jest pusta!" << endl;
                system("pause");
                system("cls");
                break;
            }
            else if(position <= 1){
                delete_head_JK(lista);
                cout << "Zostal usuniety pierwszy element z listy!" << endl;
            }
            else if (position > lista.counter){
                delete_tail_JK(lista);
                cout << "Zostal usuniety pierwszy element z listy!" << endl;
            }
            else{
                delete_position_JK(lista, position);
                cout << "Zostal usuniety element z indeksem " << position <<  "!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 8:
            if (isEmpty_lista_JK(lista))
                cout << "Lista jest pusta!" << endl;
            else
                cout << "Pierwszy element listy - " << lista.head->number << endl;
            system("pause");
            system("cls");
            break;
        case 9:
            if (isEmpty_lista_JK(lista))
                cout << "Lista jest pusta!" << endl;
            else
                cout << "Koncowy element listy - " << lista.tail->number << endl;
            system("pause");
            system("cls");
            break;
        case 10:
            if (isEmpty_lista_JK(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                cout << "Srednia arytmetyczna lista - " << srA_JK(lista) << endl;
            }
            system("pause");
            system("cls");
            break;
        case 11:
            if (isEmpty_lista_JK(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                cout << "Maksymalny element listy - " << max_JK(lista) << endl;
            }
            system("pause");
            system("cls");
            break;
        case 12:
            if (isEmpty_lista_JK(lista))
                cout << "Lista jest pusta!" << endl;
            else
                show_JK(lista);
            system("pause");
            system("cls");
            break;
        case 13:
            if (isEmpty_lista_JK(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                while(!isEmpty_lista_JK(lista)){
                    delete_tail_JK(lista);
                }
                cout << "Wszystkie elementy zostaly usuniete!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 14:
            system("cls");
            wyjscie = true;
            break;
        default:
            system("cls");
            break;
        }
    }while(!wyjscie);
}

void zad_2(){
    double_list lista;
    lista.head = nullptr;
    lista.tail = nullptr;
    lista.counter = 1;

    unsigned int
            zad,
            tempL,
            position
            ;
    bool wyjscie = false;
    do{
        cout << "Podaj nr dzialania:" << endl
             << "1)  - Sprawdzenie czy lista jest pusta" << endl
             << "2)  - Dodanie elementu na koniec listy" << endl
             << "3)  - Dodanie elementu na poczatek listy"   << endl
             << "4)  - Dodanie elementu na okreslona pozycje" << endl
             << "5)  - Usuniecie elementu z konca listy"   << endl
             << "6)  - Usuniecie elementu z poczatku listy" << endl
             << "7)  - Usuniecie elementu znajdujacego sie na okreslonej pozycji" << endl
             << "8)  - Wyswietlenie elementow od poczatku do konca" << endl
             << "9)  - Wyswietlenie elementow od konca do poczatku" << endl
             << "10) - Znalezienie elementu minimalnego w liscie" << endl
             << "11) - Usuniecie calej listy" << endl
             << "12) - Wyjscie" << endl
             << ">>>>> ";

        cin >> zad;

        switch(zad){

        case 1:
            if (isEmpty_DK(lista))
                cout << "Lista jest pusta!" << endl;
            else
                cout << "Lista ma " << lista.counter-1 << " elemetow" << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            tempL = genLiczb();
            add_tail_DK(lista, tempL);
            cout << "Liczba " << tempL << " zostala dodana do konca listy!" << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            tempL = genLiczb();
            add_head_DK(lista, tempL);
            cout << "Liczba " << tempL << " zostala dodana do poczatku listy!" << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            tempL = genLiczb();
            cout << "Podaj pozycje(1-" << lista.counter-1 << "): ";
            cin  >> position;
            if(position <= 1){
                add_head_DK(lista, tempL);
                cout << "Liczba " << tempL << " zostala dodana do poczatka listy!" << endl;
            }
            else if (position > lista.counter){
                add_tail_DK(lista, tempL);
                cout << "Liczba " << tempL << " zostala dodana do konca listy!" << endl;
            }
            else{
                add_position_DK(lista, tempL, position);
                cout << "Liczba " << tempL << " zostala dodana na pozycje " << position << "!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            if (isEmpty_DK(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_tail_DK(lista);
                cout << "Zostal usuniety koncowy element z listy!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if (isEmpty_DK(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_head_DK(lista);
                cout << "Zostal usuniety pierwszy element z listy!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 7:
            cout << "Podaj pozycje(1-" << lista.counter-1 << "): ";
            cin  >> position;
            if (isEmpty_DK(lista)){
                cout << "Lista jest pusta!" << endl;
                system("pause");
                system("cls");
                break;
            }
            else if(position <= 1){
                delete_head_DK(lista);
                cout << "Zostal usuniety pierwszy element z listy!" << endl;
            }
            else if (position > lista.counter){
                delete_tail_DK(lista);
                cout << "Zostal usuniety koncowy element z listy!" << endl;
            }
            else{
                delete_position_DK(lista, position);
                cout << "Zostal usuniety element z indeksem " << position <<  "!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 8:
            if (isEmpty_DK(lista))
                cout << "Lista jest pusta!" << endl;
            else
                show_DK(lista, 0);
            system("pause");
            system("cls");
            break;
        case 9:
            if (isEmpty_DK(lista))
                cout << "Lista jest pusta!" << endl;
            else
                show_DK(lista, 1);
            system("pause");
            system("cls");
            break;
        case 10:
            if (isEmpty_DK(lista))
                cout << "Lista jest pusta!" << endl;
            else
                cout << "Minimalny element lista - " << min_DK(lista) << "!" << endl;
            system("pause");
            system("cls");
            break;
        case 11:
            if (isEmpty_DK(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                while(!isEmpty_DK(lista)){
                    delete_tail_DK(lista);
                }
                cout << "Wszystkie elementy zostaly usuniete!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 12:
            system("cls");
            wyjscie = true;
            break;
        default:
            system("cls");
            break;
        }
    }while(!wyjscie);
}

void zad_3(){
    JednoKierunkowaCykliczna lista;
    lista.biezacy = nullptr;

    unsigned int
            zad,
            tempL,
            position
            ;
    bool wyjscie = false;
    do{
        cout << "Podaj nr dzialania:" << endl
             << "1) - Sprawdzenie czy lista jest pusta" << endl
             << "2) - Dodanie elementu za element biezacy" << endl
             << "3) - Dodanie elementu przed element biezacy"   << endl
             << "4) - Usuniecie elementu za elementem biezacym"   << endl
             << "5) - Usuniecie elementu przed elementem biezacym" << endl
             << "6) - Usuniecie elementu biezacego" << endl
             << "7) - Wyswietlenie calej listy" << endl
             << "8) - Usuniecie calej listy" << endl
             << "9) - Wyjscie" << endl
             << ">>>>> ";

        cin >> zad;

        switch(zad){

        case 1:
            if (isEmpty_lista_JKC(lista))
                cout << "Lista jest pusta!" << endl;
            else
                cout << "Lista czyms pelna!"<< endl;
            system("pause");
            system("cls");
            break;
        case 2:
            tempL = genLiczb();
            add_tail_JKC(lista, tempL);
            cout << "Liczba " << tempL << " zostala dodana za element biezacy!" << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            tempL = genLiczb();
            add_head_JKC(lista, tempL);
            cout << "Liczba " << tempL << " zostala dodana przed element biezacy!" << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            if (isEmpty_lista_JKC(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_za_JKC(lista);
                cout << "Zostalo usuniety element za elementem biezacym!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            if (isEmpty_lista_JKC(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_przed_JKC(lista);
                cout << "Zostalo usuniety element przed elementem biezacym!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if (isEmpty_lista_JKC(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_biezacy_JKC(lista);
                cout << "Zostalo usuniety element biezacy!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 7:
            if (isEmpty_lista_JKC(lista))
                cout << "Lista jest pusta!" << endl;
            else
                show_JKC(lista);
            system("pause");
            system("cls");
            break;
        case 8:
            if (isEmpty_lista_JKC(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                while(!isEmpty_lista_JKC(lista)){
                    delete_za_JKC(lista);
                }
                cout << "Wszystkie elementy zostaly usuniete!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 9:
            system("cls");
            wyjscie = true;
            break;
        default:
            system("cls");
            break;
        }
    }while(!wyjscie);
}

void zad_4(){
    DwuKierunkowaCykliczna lista;
    lista.biezacy = nullptr;

    unsigned int
            zad,
            tempL,
            position
            ;
    bool wyjscie = false;
    do{
        cout << "Podaj nr dzialania:" << endl
             << "1)  - Sprawdzenie czy lista jest pusta" << endl
             << "2)  - Dodanie elementu za element biezacy" << endl
             << "3)  - Dodanie elementu przed element biezacy"   << endl
             << "4)  - Usuniecie elementu za elementem biezacym"   << endl
             << "5)  - Usuniecie elementu przed elementem biezacym" << endl
             << "6)  - Usuniecie elementu biezacego" << endl
             << "7)  - Wyswietlenie calej listy" << endl
             << "8)  - Wyswietlenie calej listy wspak"       << endl
             << "9)  - Usuniecie calej listy" << endl
             << "10) - Wyjscie" << endl
             << ">>>>> ";

        cin >> zad;

        switch(zad){

        case 1:
            if (isEmpty_lista_DKC(lista))
                cout << "Lista jest pusta!" << endl;
            else
                cout << "Lista czyms pelna!"<< endl;
            system("pause");
            system("cls");
            break;
        case 2:
            tempL = genLiczb();
            add_tail_DKC(lista, tempL);
            cout << "Liczba " << tempL << " zostala dodana za element biezacy!" << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            tempL = genLiczb();
            add_head_DKC(lista, tempL);
            cout << "Liczba " << tempL << " zostala dodana przed element biezacy!" << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            if (isEmpty_lista_DKC(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_za_DKC(lista);
                cout << "Zostalo usuniety element za elementem biezacym!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            if (isEmpty_lista_DKC(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_przed_DKC(lista);
                cout << "Zostalo usuniety element przed elementem biezacym!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if (isEmpty_lista_DKC(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                delete_biezacy_DKC(lista);
                cout << "Zostalo usuniety element biezacy!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 7:
            if (isEmpty_lista_DKC(lista))
                cout << "Lista jest pusta!" << endl;
            else
                show_DKC(lista, 0);
            system("pause");
            system("cls");
            break;
        case 8:
            if (isEmpty_lista_DKC(lista))
                cout << "Lista jest pusta!" << endl;
            else
                show_DKC(lista, 1);
            system("pause");
            system("cls");
            break;
        case 9:
            if (isEmpty_lista_DKC(lista))
                cout << "Lista jest pusta!" << endl;
            else{
                while(!isEmpty_lista_DKC(lista)){
                    delete_za_DKC(lista);
                }
                cout << "Wszystkie elementy zostaly usuniete!" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 10:
            system("cls");
            wyjscie = true;
            break;
        default:
            system("cls");
            break;
        }
    }while(!wyjscie);
}

