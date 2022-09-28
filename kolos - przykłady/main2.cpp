#include <iostream>
#include <string>
using namespace std;

/*

Imię:       Illia
Nazwisko:   Bahlai
Nr. albomu: 096483
data:       23.04.2021

Zadanie 4
Pobieramy od użytkownika dane o k samochodach. Są to: rocznik, marka oraz cena (liczba
całkowita dodatnia).
a. Posortować samochody na te o cenie nie wyższej niż 30 000, a następnie pozostałe.
b. Uporządkować malejąco algorytmem sortowania przez wybieranie według rocznika
samochody o cenie powyżej 30 000.
c. Wyznaczyć, ile samochodów o cenie nie wyższej niż 30 000 jest marki o podanej przez
użytkownika nazwie.
d. Wyznaczyć trzy (różne) liczby oznaczające roczniki najtańszych samochodów.
*/


struct samochod{
    unsigned short rocznik;
    string         marka;
    unsigned int   cena;
};


//Podtawa
void wyswietltablice(samochod * tab, int k);
void wczytajsamochod(samochod *&tab, int k);

//a
int  podPunkt_a     (samochod * tab, int k, int granica);
void wyswietlSamochod_a(samochod * tab, int k, int index_a);

//b
void sortowaniePrzezWybor(samochod* tab, int k, int granica);

//c
int wszukiwanie_naiwne(string tekst, string wzorzec);
void wyszukiwaniaMarek(samochod *tab, string wzorzec, int k);

//d
void naj_min_max(samochod *tab, int k, samochod *index);
void wyswietltablice_d(samochod* tab);


int main()
{
    int k = -1;

    do{
        system("cls");
        cout << "Prosze podac ilosc elementow tablicy: ";
        cin  >> k;

    }while(k == -1);

    samochod *tab = new samochod[k];
    wczytajsamochod(tab, k);
    wyswietltablice(tab, k);

    //a
    static int granica = 30000;

    cout << endl << endl << "A" << endl << endl;

    static int index_a = podPunkt_a(tab, k, granica);
    wyswietlSamochod_a(tab, k, index_a);

    //b

    cout << endl << endl << "B" << endl << endl;

    sortowaniePrzezWybor(tab, k, granica);
    wyswietltablice(tab, k);

    //c

    cout << endl << endl << "C" << endl << endl;

    string wzorzec;
    int *index = new int[k];
    cout << "Prosze podac wzorze marki do wyszukiwania: ";
    cin.ignore();
    getline(cin, wzorzec);

    wyszukiwaniaMarek(tab, wzorzec, k);

    //d

    cout << endl << endl << "D" << endl << endl;

    samochod *index_d = new samochod[3];
    naj_min_max(tab, k, index_d);
    wyswietltablice_d(tab);

    system("pause");

    return 0;
}

//Podstawa

void wczytajsamochod(samochod *&tab, int k){
    int temp_cena;
    cout << "Podaj dane tablice" << endl;
    for (int e=0; e<k; e++){
        cout << "E: " << e << endl;
        cout << "Marka: ";
        cin.ignore();
        getline(cin,tab[e].marka);
        cout << "Rocznik: ";
        cin  >> tab[e].rocznik;
        cout << "Cena: ";
        cin  >> temp_cena;
        if (temp_cena < 0){
            cout << "Podaj cene dadania!" << endl;
            do {
                cout << "Cena: ";
                cin  >> temp_cena;
            }while (temp_cena < 0);
        }
        tab[e].cena = temp_cena;
        cout << endl;
    }
}

void wyswietltablice(samochod* tab, int k){
    cout << "W tablice " << k
         << " samochodow" << endl;
    for (int i = 0; i < k; i++){
        cout << "E: " << i << "\t"
             << "Marka: "   << tab[i].marka << "\t"
             << "Rocznik: " << tab[i].rocznik << "\t"
             << "Cena: "    << tab[i].cena << endl;
    }
}

//Pod punkty

//A
int podPunkt_a(samochod * tab, int k, int granica){
    int i = 0, j = k-1;
    while (i < j){
        if      (tab[i].cena <= granica && i<j) i++;
        else if (tab[j].cena >  granica && i<j) j--;
        else if (i < j){
            swap(tab[i], tab[j]);
            i++; j--;
        }
    }
    if (tab[i].cena <= granica)
        return i+1;
    else
        return i;
}

void wyswietlSamochod_a(samochod * tab, int k, int index_a){
    cout << "W tablice " << k
         << " samochodow\n\n";

    cout << "Samochody, ktore maja cene <=" << 30000
         << " zlowych:\n";
    for (int i = 0; i < index_a; i++){
        cout << "E: " << i << "\t"
             << "Marka: "   << tab[i].marka << "\t"
             << "Rocznik: " << tab[i].rocznik << "\t"
             << "Cena: "    << tab[i].cena << endl;
    }
    cout << endl
         << "Samochody, ktore maja cene >" << 30000
         << " zlowych:\n";

    for (int i = index_a; i < k; i++){
        cout << "E: " << i << "\t"
             << "Marka: "   << tab[i].marka << "\t"
             << "Rocznik: " << tab[i].rocznik << "\t"
             << "Cena: "    << tab[i].cena << endl;
    }
}


//B

void sortowaniePrzezWybor(samochod* tab, int k, int granica){
    int ind;
    for (int i = k-1; 0<i; i --){
        ind = 0;
        for (int j = 1; j <= i; j ++){
            if ((tab[j].rocznik < tab[ind].rocznik) && tab[j].rocznik > granica)
                ind = j;
        }
        swap(tab[i], tab[ind]);
    }
}


//C
int wszukiwanie_naiwne(string tekst, string wzorzec){
    int
        dlt = tekst.length(),
        dlw = wzorzec.length(),
        j;
    for(int i=0; i <= dlt-dlw; i++){
        j = 0;
        while (j<dlw && wzorzec[j] == tekst[i+j])
            j++;
        if (j == dlw){
            return i;
        }
    }
    return -1;
}

void wyszukiwaniaMarek(samochod *tab, string wzorzec, int k){
    int *index = new int[k];
    int
        i = 0,
        findIndex;
    for (int e = 0; e < k; e++){
        findIndex = wszukiwanie_naiwne(tab[e].marka, wzorzec);
        if (findIndex != -1){
            index[i] = e;
            i ++;
        }
    }
    cout << "Znalaziono " << i
         << " maker z tym wzorcem" << endl;
    for (int j = 0; j < i; j++){
        cout << "E: " << i << "\t"
             << "Marka: "   << tab[index[j]].marka << "\t"
             << "Rocznik: " << tab[index[j]].rocznik << "\t"
             << "Cena: "    << tab[index[j]].cena << endl;
    }
}

//d

void naj_min_max(samochod *tab, int k, samochod *index){
    int i = 0, j = 1;
    int i_min = 0, i_max = 0;
    samochod *Max = new samochod[(k/2)+1];
    samochod *Min = new samochod[(k/2)+1];
    int len = 0;

    for (int n = 0; n < k/2; n++){
        if (tab[i].rocznik < tab[j].rocznik){
            Max[i_max] = tab[j];
            i_max ++ ;

            Min[i_min] = tab[i];
            i_min ++ ;
        }
        else{
            Max[i_max] = tab[i];
            i_max ++ ;

            Min[i_min] = tab[j];
            i_min ++ ;
        }
        i += 2; j += 2;
        len ++;
    }


    if (k % 2 != 0){
        len ++;
        Max[i_max] = tab[k-1];
        Min[i_min] = tab[k-1];
        i_min ++; i_max ++;
    }

    samochod minn = Min[0], maxx = Max[0];
    int el = 0;
    int max_el = 3;
    //Min
    for (int i = 0; i < i_min; i++){
        if (Min[i].rocznik < minn.rocznik){
            minn = Min[i];
            index[el] = minn;
            if (max_el == i)
                break;
        }
    }
    /*
    //Max
    for (int i = 0; i < i_max; i++){
        if (Max[i] > maxx){
            maxx = Max[i];
        }
    }
    MM.minn = minn;
    MM.maxx = maxx;
    MM.len  = len;
    return MM;
    */
}

void wyswietltablice_d(samochod* tab){
    cout << "W tablice " << 3
         << " samochodow" << endl;
    for (int i = 0; i < 3; i++){
        cout << "E: " << i << "\t"
             << "Marka: "   << tab[i].marka << "\t"
             << "Rocznik: " << tab[i].rocznik << "\t"
             << "Cena: "    << tab[i].cena << endl;
    }
}
