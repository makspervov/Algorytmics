[Forwarded from flexxxer]
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cstring>

using namespace std;

struct lista_wezel
{
    char zawartosc;
    lista_wezel* nastepny;
};

class lista
{
    lista_wezel* przod_ = nullptr;
    lista_wezel* tyl_ = nullptr;
    int ile_ = 0;
public:
    lista() { }

    lista_wezel* dane()
    {
        return this->przod_;
    }

    bool czy_jest_pusty()
    {
        return this->ile_ == 0;
    }
    int ile()
    {
        return this->ile_;
    }

    void do_tylu(char wartosc)
    {
        lista_wezel* nowy_wezel = new lista_wezel{ wartosc, nullptr };

        if (this->tyl_ != nullptr)
            this->tyl_->nastepny = nowy_wezel;
        if (this->przod_ == nullptr)
            this->przod_ = nowy_wezel;

        this->tyl_ = nowy_wezel;

        ++this->ile_;
    }
    void usun_tyl()
    {
        if (this->czy_jest_pusty())
            throw logic_error("lista is czy_jest_pusty");

        if (this->ile() == 1)
        {
            delete this->przod_;
            --this->ile_;
            return;
        }

        lista_wezel* przod = this->przod_;

        while (przod->nastepny != this->tyl_)
            przod = przod->nastepny;

        przod->nastepny = nullptr;
        delete this->tyl_;

        this->tyl_ = przod;

        --this->ile_;
    }
    char& tyl()
    {
        if (this->czy_jest_pusty())
            throw logic_error("lista is czy_jest_pusty");

        return this->tyl_->zawartosc;
    }

    void do_przodu(char wartosc)
    {
        lista_wezel* nowy_wezel = new lista_wezel{ wartosc, this->przod_ };

        if (this->tyl_ == nullptr)
            this->tyl_ = nowy_wezel;

        this->przod_ = nowy_wezel;

        ++this->ile_;
    }
    void pop_front() {
        if (this->czy_jest_pusty())
            throw logic_error("lista is czy_jest_pusty");

        if (this->ile_ == 1)
        {
            delete this->przod_;
            --this->ile_;
            return;
        }

        lista_wezel* nowy_wezel = this->przod_->nastepny;

        delete this->przod_;

        this->przod_ = nowy_wezel;
        --this->ile_;
    }
    char& front() {
        if (this->czy_jest_pusty())
            throw logic_error("lista is czy_jest_pusty");

        return this->przod_->zawartosc;
    }

    void usun_z(int indeks) {
        if (this->ile_ < indeks)
            throw std::out_of_range("indeks");

        if (indeks == 0)
        {
            this->pop_front();
            return;
        }
        if (this->ile_ - 1 == indeks)
        {
            this->usun_tyl();
            return;
        }

        lista_wezel* przod = this->przod_;

        while (indeks - 1 != 0)
        {
            przod = przod->nastepny;
            indeks--;
        }

        lista_wezel* wezel_do_usuniecia = przod->nastepny;
        lista_wezel* nastepny_do_usuniecia = przod->nastepny->nastepny;

        delete wezel_do_usuniecia;

        przod->nastepny = nastepny_do_usuniecia;

        --this->ile_;
    }
    void wstawic_do(int indeks, char wartosc)
    {
        if (this->ile_ < indeks)
            throw std::out_of_range("indeks");

        if (indeks == 0)
        {
            this->do_przodu(wartosc);
            return;
        }
        if (this->ile_ == indeks)
        {
            this->do_tylu(wartosc);
            return;
        }

        lista_wezel* przod = this->przod_;

        while (indeks - 1 != 0)
        {
            przod = przod->nastepny;
            indeks--;
        }

        lista_wezel* nowy_wezel = new lista_wezel{ wartosc, przod->nastepny };
        przod->nastepny = nowy_wezel;

        ++this->ile_;
    }
    char& at(int index)
    {
        lista_wezel* wezel = this->przod_;
        for (int i = 0; i < index; i++)
        {
            wezel = wezel->nastepny;
        }

        return wezel->zawartosc;
    }

    void print(ostream& stream)
    {
        lista_wezel* wezel = this->dane();
        [Forwarded from flexxxer]


        while (wezel != nullptr)
        {
            stream << wezel->zawartosc << " ";
            wezel = wezel->nastepny;
        }
        stream << endl;
    }

    bool czy_istnieje(char wartosc) {
        lista_wezel* wezel = this->przod_;

        while (wezel != nullptr) {
            if (wartosc == wezel->zawartosc) {
                return true;
            }

            wezel = wezel->nastepny;
        }

        return false;
    }

    ~lista()
    {
        if (this->ile_ == 0)
            return;

        this->ile_ = 0;
        lista_wezel* wezel = this->przod_;
        while (wezel != nullptr)
        {
            lista_wezel* tmp = wezel->nastepny;
            delete wezel;
            wezel = tmp;
        }
    }
};

void zad1() {
    ifstream file("zad1h.txt");
    std::string line;

    lista l;

    while (std::getline(file, line))
    {
        char c = line[0];

        if (isupper(c)) {
            l.do_przodu(c);
        }
        else {
            l.do_tylu(c);
        }
    }

    l.print(cout);
}

void zad2() {
    ifstream file("zad2h.txt");
    std::string line;
    lista l;

    while (std::getline(file, line))
    {
        char c = line[0];

        if (isupper(c)) {
            l.do_przodu(c);
        }
        else {
            l.do_tylu(c);
        }
    }

    string aba = "aba";
    int poziom = 0;
    int ile = 0;

    lista_wezel* wezel = l.dane();

    while (wezel != nullptr) {
        if (wezel->zawartosc == aba[poziom]) {
            poziom++;

            if (poziom == aba.length()) {
                ile++;
                poziom = 0;
            }
        }
        else {
            poziom = 0;
        }

        wezel = wezel->nastepny;
    }

    cout << "Lista: " << endl;
    l.print(cout);

    cout << "ile aba: " << ile << endl;
}

void zad3() {
    ifstream file("zad2h.txt");
    std::string line;
    lista l;

    while (std::getline(file, line))
    {
        char c = line[0];

        if (isupper(c)) {
            l.do_przodu(c);
        }
        else {
            l.do_tylu(c);
        }
    }

    cout << "Przed: " << endl;
    l.print(cout);

    lista l2;

    lista_wezel* wezel = l.dane();

    while (wezel != nullptr) {
        if (!l2.czy_istnieje(wezel->zawartosc)) {
            l2.do_tylu(wezel->zawartosc);
        }

        wezel = wezel->nastepny;
    }

    cout << "Po: " << endl;
    l2.print(cout);
}

int main()
{
    cout << "zad 1" << endl;
    zad1();

    cout << "zad 2" << endl;
    zad2();

    cout << "zad 3" << endl;
    zad3();

    return 0;
}