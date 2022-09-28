#include <iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>

using namespace std;

void AlgorytmKR(int dt, string napis, int dw, string wzor)
{
	int hashW = 0, hashT = 0, zpw, zow, zpm, zom, i, j, p;
	zpw = 65;			//kod ASCII pierwszego znaku A
	zow = 90;			//kod ASCII ostatniego znaku Z
	zpm = 97;			//kod ASCII pierwszego znaku a
	zom = 122;			//kod ASCII ostatniego znaku z
	p = 23;
	for (i = 1; i < dw; i++) {
		hashW = (hashW * zpw + indeks(wzor[i])) % p;
		hashT = (hashT * zpw + indeks(napis[i])) % p;
	}
	bM1 = 1;
	for (i = 1; i <= dw - 1; i++) bM1 = (b * bM1) % p;
	for (i = 1; i <= dt - dw + 1; i++)
	{
		if (hashW == hashT)
		{
			j = 0;
			while (wzor[j + 1] == napis[i + j] && j < m) j++;
			if (j == m) cout << "Wzorzec od pozycji" << i;
		}
	}
}

void WczytajDane()
{
	string line, help;
	ifstream plik;
	
	plik.open("tekst.txt");
	int temp;
	plik >> temp;


	plik.close();
}

void usunDane()
{

}

void wyswietlDane()
{

}

int main()
{
	int wzor;
	ifstream plik;


	plik.open("teskt.txt");
	plik >> wzor;


	plik.close();


	system("pause");
	return 0;
}