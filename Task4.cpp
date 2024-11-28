#include <iostream>
using namespace std;

class Carte {
private:
    string titlu;
    string autor;
    int numarPagini;
    const int anPublicatie;
    float* pret;
    static int numarCarti;

public:

    Carte() : anPublicatie(2000) {
        titlu = "Necunoscut";
        autor = "Necunoscut";
        numarPagini = 0;
        pret = new float(0.0);
        numarCarti++;
    }

    Carte(string t, string a, int pag, float p, int an) : anPublicatie(an) {
        titlu = t;
        autor = a;
        numarPagini = pag;
        pret = new float(p);
        numarCarti++;
    }

    Carte(const Carte& other) : anPublicatie(other.anPublicatie) {
        titlu = other.titlu;
        autor = other.autor;
        numarPagini = other.numarPagini;
        pret = new float(*other.pret);
    }

    ~Carte() {
        delete pret;
        numarCarti--;
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

    Carte operator+(const Carte& other) const {
        return Carte(titlu + " & " + other.titlu, autor + " & " + other.autor,
            numarPagini + other.numarPagini, *pret + *other.pret, anPublicatie);
    }

    bool operator==(const Carte& other) const { 
        return (titlu == other.titlu && autor == other.autor);
    }

    bool operator>(const Carte& other) const { 
        return *pret > *other.pret;
    }

    friend ostream& operator<<(ostream& os, const Carte& c) { 
        os << "Carte: " << c.titlu << ", Autor: " << c.autor
            << ", Pagini: " << c.numarPagini << ", Pret: " << *c.pret
            << ", An Publicatie: " << c.anPublicatie;
        return os;
    }

   
    friend void afiseazaReducereCarte(const Carte& c, float procent);
};

int Carte::numarCarti = 0;


void afiseazaReducereCarte(const Carte& c, float procent) {
    cout << "Reducere pentru cartea \"" << c.titlu << "\": "
        << (*c.pret * procent / 100) << " RON." << endl;
}


class Pix {
private:
    string marca;
    string culoare;
    bool esteReincarcabil;
    const int garantie;
    float* pret;
    static int numarPixuri;

public:
    Pix() : garantie(12) {
        marca = "Necunoscut";
        culoare = "Albastru";
        esteReincarcabil = false;
        pret = new float(0.0);
        numarPixuri++;
    }

    Pix(string m, string c, bool r, float p) : garantie(12) {
        marca = m;
        culoare = c;
        esteReincarcabil = r;
        pret = new float(p);
        numarPixuri++;
    }

    Pix(const Pix& other) : garantie(other.garantie) {
        marca = other.marca;
        culoare = other.culoare;
        esteReincarcabil = other.esteReincarcabil;
        pret = new float(*other.pret);
    }

    ~Pix() {
        delete pret;
        numarPixuri--;
    }

    
    Pix& operator=(const Pix& other) {
        if (this != &other) {
            marca = other.marca;
            culoare = other.culoare;
            esteReincarcabil = other.esteReincarcabil;
            *pret = *other.pret;
        }
        return *this;
    }

    Pix operator*(float factor) const { 
        return Pix(marca, culoare, esteReincarcabil, *pret * factor);
    }

    bool operator!=(const Pix& other) const { 
        return (marca != other.marca || culoare != other.culoare);
    }

    Pix& operator++() { 
        (*pret)++;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Pix& p) { 
        os << "Pix: " << p.marca << ", Culoare: " << p.culoare
            << ", Reincarcabil: " << (p.esteReincarcabil ? "Da" : "Nu")
            << ", Pret: " << *p.pret << ", Garantie: " << p.garantie << " luni";
        return os;
    }

    
    friend void afiseazaGarantiePix(const Pix& p);
};


int Pix::numarPixuri = 0;

void afiseazaGarantiePix(const Pix& p) {
    cout << "Pixul \"" << p.marca << "\" are o garanție de " << p.garantie << " luni." << endl;
}


class Agenda {
private:
    string tipCoperta;
    int numarPagini;
    bool esteDatata;
    const int anFabricatie;
    float* pret;
    static int numarAgende;

public:
    
    Agenda() : anFabricatie(2022) {
        tipCoperta = "Necunoscut";
        numarPagini = 0;
        esteDatata = false;
        pret = new float(0.0);
        numarAgende++;
    }

    Agenda(string tip, int pag, bool datata, float p, int an) : anFabricatie(an) {
        tipCoperta = tip;
        numarPagini = pag;
        esteDatata = datata;
        pret = new float(p);
        numarAgende++;
    }

    Agenda(const Agenda& other) : anFabricatie(other.anFabricatie) {
        tipCoperta = other.tipCoperta;
        numarPagini = other.numarPagini;
        esteDatata = other.esteDatata;
        pret = new float(*other.pret);
    }

    ~Agenda() {
        delete pret;
        numarAgende--;
    }

   
    Agenda& operator=(const Agenda& other) {
        if (this != &other) {
            tipCoperta = other.tipCoperta;
            numarPagini = other.numarPagini;
            esteDatata = other.esteDatata;
            *pret = *other.pret;
        }
        return *this;
    }

    
    Agenda operator-(int pag) const { 
        return Agenda(tipCoperta, numarPagini - pag, esteDatata, *pret, anFabricatie);
    }

    bool operator<=(const Agenda& other) const { 
        return numarPagini <= other.numarPagini;
    }

    Agenda& operator+=(float valoare) { 
        *pret += valoare;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Agenda& a) { 
        os << "Agenda: Coperta: " << a.tipCoperta << ", Pagini: " << a.numarPagini
            << ", Datată: " << (a.esteDatata ? "Da" : "Nu")
            << ", Pret: " << *a.pret << ", An Fabricatie: " << a.anFabricatie;
        return os;
    }
};


int Agenda::numarAgende = 0;


int main() {
    Carte c1("Ion", "Liviu Rebreanu", 300, 50, 1930);
    Carte c2("Morometii", "Marin Preda", 400, 60, 1955);
    Carte c3;
    c3 = c1 + c2; 
    cout << c3 << endl;
    cout << (c1 == c2 ? "Egale" : "Diferite") << endl; 
    cout << (c1 > c2 ? "Ion e mai scump" : "Morometii e mai scump") << endl; 
    afiseazaReducereCarte(c1, 10); 

    
    Pix p1("Pilot", "Negru", true, 10);
    Pix p2("Bic", "Albastru", false, 5);
    ++p1; 
    Pix p3 = p2 * 2; 
    cout << p1 << endl;
    cout << p3 << endl;
    cout << (p1 != p2 ? "Diferite" : "Identice") << endl; 
    afiseazaGarantiePix(p1); 

    
    Agenda a1("Piele", 200, true, 50, 2023);
    Agenda a2("Carton", 150, false, 30, 2021);
    Agenda a3 = a1 - 50; 
    cout << a3 << endl;
    cout << (a1 <= a2 ? "Mai puține sau egale pagini" : "Mai multe pagini") << endl; 
    a1 += 10; 
    cout << a1 << endl;

    return 0;
}

