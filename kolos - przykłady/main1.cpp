#include <iostream>
#include <iostream>
#include<fstream>

using namespace std;

void wczytaj(int*& tab, int *n, string nazwa_pliku) //n rozmiar tablicy, tab tablica
{
    ifstream odczyt;
    odczyt.open(nazwa_pliku.c_str());
    odczyt >> *n;
    tab = new int[*n];
    for (int i = 0; i < *n; i++)
    {
        odczyt >> tab[i];
    }
    odczyt.close();
}

void podziel3(int *tab, int n, int *&index){
    int i = -1, j = 0, k = n;

    while (j < k){
        if ((j / 3) <= 0){
            i ++;
            swap(tab[i], tab[j]);
            j ++;
        }
        else{
            if ((j / 3) > 1){
                k--;
                swap(tab[k], tab[j]);
            }
            else{
                j++;
            }
        }
    }
    index = new int[2];
    index[0] = i;
    index[1] = k;
}

void show3(int* tab, int n, int n1, int n2){
    for (int i = 0; i <= n1; i++){
        cout << tab[i]<< " Index: " << i << endl;
    }
    cout << endl;
    for (int i = n1+1; i < n2; i++){
         cout << tab[i]<< " Index: " << i << endl;
    }
    cout << endl;
    for (int i = n2; i < n; i++){
         cout << tab[i]<< " Index: " << i << endl;
    }

}


//-------------------------------------------------------

void sortowanieQuickSort(int* tab, int lewy, int prawy, int tryb){
    int srodek = (lewy + prawy)/2;

    int piwot  = tab[srodek];

    tab[srodek] = tab[prawy];

    int granica = lewy;

    for (int i = lewy; i < prawy; i++){
        if (tryb == 1){
            if (tab[i] < piwot){
                swap(tab[granica], tab[i]);
                granica ++ ;
            }
        }
        else{
            if (tab[i] > piwot){
                swap(tab[granica], tab[i]);
                granica ++ ;
            }
        }
    }
    tab[prawy] = tab[granica];
    tab[granica] = piwot;

    if (lewy  < granica-1)
        sortowanieQuickSort(tab, lewy, granica-1, tryb);
    if (prawy > granica+1)
        sortowanieQuickSort(tab, granica+1, prawy, tryb);
}

void sortowanieBabelkowe(int* tab, int n, int tryb) {
    int stan;
    for (int i = n - 1; 0 < i; i--) {
        stan = 1;
        for (int j = 0; j < i; j++) {
            if (tryb == 1) 
            {
                if (tab[j] > tab[j + 1]) 
                {
                    swap(tab[j], tab[j + 1]);
                    stan = 0;
                }
            }
            else {
                if (tab[j] < tab[j + 1]) {
                    swap(tab[j], tab[j + 1]);
                    stan = 0;
                }
            }
        }
        if (stan == 0) break;
    }
}

void wyswietlenieTablicy(int* tab, int n, int k)
{   cout << "Malejaco: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl << "Rosnaco: " << endl;
    for (int i = k; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}
int naj_min_max(int *Tab, int N, int *&index){
    int i = 0, j = 1;
    int i_min = 0, i_max = 0;
    int Max[(N/2)+1];
    int Min[(N/2)+1];
    int len = 0;

    for (int n = 0; n < N/2; n++){
        if (Tab[i] < Tab[j]){
            Max[i_max] = Tab[j];
            i_max ++ ;

            Min[i_min] = Tab[i];
            i_min ++ ;
        }
        else{
            Max[i_max] = Tab[i];
            i_max ++ ;

            Min[i_min] = Tab[j];
            i_min ++ ;
        }
        i += 2; j += 2;
        len ++;
    }


    if (N % 2 != 0){
        len ++;
        Max[i_max] = Tab[N-1];
        Min[i_min] = Tab[N-1];
        i_min ++; i_max ++;
    }

    int
        min1 = Min[0],
        min2 = Min[1],
        max1 = Max[0],
        max2 = Max[1];

    //Min
    for (int i = 0; i < i_min; i++){
        if (Min[i] < min1)
            min1 = Min[i];
        else if (Min[i] < min2)
            min2 = Min[i];
    }
    //Max
    for (int i = 0; i < i_max; i++){
        if (Max[i] > max1)
            max1 = Max[i];
        else if (Min[i] > max2)
            max2 = Min[i];
    }

    index = new int[2];
    index[0] = min1 + min2;
    index[1] = max1 + max2;

}


int wyszukiwanieBiosekuracyjne(int* x, int n, int wartosc)
{
    int lewy = 0;
    int prawy = n - 1;
    while (lewy <= prawy)
    {
        int srodek = (int)(lewy + prawy) / 2;
        if (x[srodek] == wartosc)
        {
            cout << "i=" << srodek << endl;
            return 1;
        }
        else
        {
            if (wartosc < x[srodek])
            {
                prawy = srodek - 1;
            }
            else
            {
                lewy = srodek + 1;
            }
        }
    }
    return 2;
}


int main()
{
    cout << "Zad 1" << endl;
    int* tab;
    int n;

    wczytaj(tab, &n, "grupaBzad1.csv");

    int *index;
    podziel3(tab, n, index);
    cout << index[0];
    show3(tab, n, index[0], index[1]);

    cout << endl << "Liczb jednocyfrowycj: " << n << endl;
    delete[] tab;

    cout << endl << endl << "Zad 2" << endl;
    int* tab2;

    wczytaj(tab2, &n, "grupaBzad2.csv");
    int k = n / 2;
    wyswietlenieTablicy(tab2, n, 0);
    sortowanieQuickSort(tab2, 0, k, 0);
    sortowanieQuickSort(tab2, k, n, 1);
    wyswietlenieTablicy(tab2, n, k);

    int *index_2;
    naj_min_max(tab2, k, index_2);
    cout << "Suma dwoch minimalny elementow: " << index_2[0] << endl;
    cout << "Suma dwoch maksymalnych elementow: " << index_2[1] << endl;



    delete[] tab2;
    cout << endl << endl << "Zad 3" << endl;
    int* tab3;
    wczytaj(tab3, &n, "grupaBzad3.csv");
    //tab3 = new int[n];
    int f = wyszukiwanieBiosekuracyjne(tab3, n, 10);
    cout << "Zwraca funkja " << f << endl;


    delete[] tab;

    return 0;
}
