#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Carte {
protected: 
    string titlu;
    string autor;
    int numarPagini;
    const int anPublicatie;
    float* pret;

public:
    Carte() : anPublicatie(2000) {
        titlu = "Necunoscut";
        autor = "Necunoscut";
        numarPagini = 0;
        pret = new float(0.0);
    }

    Carte(string t, string a, int pag, float p, int an) : anPublicatie(an) {
        titlu = t;
        autor = a;
        numarPagini = pag;
        pret = new float(p);
    }

    Carte(const Carte& other) : anPublicatie(other.anPublicatie) {
        titlu = other.titlu;
        autor = other.autor;
        numarPagini = other.numarPagini;
        pret = new float(*other.pret);
    }

    virtual ~Carte() { 
        delete pret;
    }

    Carte& operator=(const Carte& other) {
        if (this != &other) {
            titlu = other.titlu;
            autor = other.autor;
            numarPagini = other.numarPagini;
            *pret = *other.pret;
        }
        return *this;
    }

    virtual void afiseaza() const { 
        cout << "Carte: " << titlu << ", Autor: " << autor
            << ", Pagini: " << numarPagini << ", Pret: " << *pret
            << ", An Publicatie: " << anPublicatie << endl;
    }
};


class Agenda {
protected:
    string numeAgenda;
    int numarPagini;
    string tipAgenda;

public:
    Agenda() {
        numeAgenda = "Necunoscut";
        numarPagini = 0;
        tipAgenda = "Necunoscut";
    }

    Agenda(string nume, int pag, string tip) {
        numeAgenda = nume;
        numarPagini = pag;
        tipAgenda = tip;
    }

    Agenda(const Agenda& other) {
        numeAgenda = other.numeAgenda;
        numarPagini = other.numarPagini;
        tipAgenda = other.tipAgenda;
    }

    virtual ~Agenda() {}

    virtual void afiseaza() const { 
        cout << "Agenda: " << numeAgenda << ", Pagini: " << numarPagini
            << ", Tip: " << tipAgenda << endl;
    }
};


class Enciclopedie : public Carte {
private:
    int numarVolume;
    string domeniu;

public:
    Enciclopedie() : Carte() {
        numarVolume = 0;
        domeniu = "Necunoscut";
    }

    Enciclopedie(string t, string a, int pag, float p, int an, int vol, string dom)
        : Carte(t, a, pag, p, an) {
        numarVolume = vol;
        domeniu = dom;
    }

    Enciclopedie(const Enciclopedie& other)
        : Carte(other), numarVolume(other.numarVolume), domeniu(other.domeniu) {}

    void afiseaza() const override { 
        Carte::afiseaza();
        cout << "Numar volume: " << numarVolume << ", Domeniu: " << domeniu << endl;
    }
};


class Jurnal : public Agenda {
private:
    string tipJurnal;
    string dataInceput;

public:
    Jurnal() : Agenda() {
        tipJurnal = "Necunoscut";
        dataInceput = "Necunoscuta";
    }

    Jurnal(string nume, int pag, string tipAg, string tipJ, string data)
        : Agenda(nume, pag, tipAg) {
        tipJurnal = tipJ;
        dataInceput = data;
    }

    Jurnal(const Jurnal& other) : Agenda(other) {
        tipJurnal = other.tipJurnal;
        dataInceput = other.dataInceput;
    }

    void afiseaza() const override { 
        Agenda::afiseaza();
        cout << "Tip Jurnal: " << tipJurnal << ", Data Inceput: " << dataInceput << endl;
    }
};


int main() {
    
    Enciclopedie e1("Enciclopedie Universala", "Editura X", 1500, 499.99, 2021, 10, "Stiinta");
    e1.afiseaza();

    Jurnal j1("Jurnal de calatorie", 200, "personal", "caiet", "10/05/2022");
    j1.afiseaza();

    Carte* c = &e1;
    c->afiseaza();

    Agenda* a = &j1;
    a->afiseaza();

    return 0;
}
