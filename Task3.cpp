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

    
    string getTitlu() const 
    {
        return titlu;
    }
    string getAutor() const 
    {
        return autor; 
    }
    int getNumarPagini() const 
    {
        return numarPagini; 
    }
    int getAnPublicatie() const 
    {
        return anPublicatie; 
    }
    float getPret() const 
    {
        return *pret; 
    }

 
    void setTitlu(string t) 
    {
        titlu = t; 
    }
    void setAutor(string a) 
    {
        autor = a; 
    }
    void setNumarPagini(int pag) 
    {
        numarPagini = pag; 
    
    }
    void setPret(float p) 
    {
        *pret = p; 
    }

  
    static int getNumarCarti() { return numarCarti; }

    friend void modificaPret(Carte& c, float procent);
    friend void afiseazaCarte(const Carte& c);
};

int Carte::numarCarti = 0;

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

    string getMarca() const 
    {
        return marca; 
    }
    string getCuloare() const
    {
        return culoare; 
    }
    bool getEsteReincarcabil() const 
    {
        return esteReincarcabil; 
    }
    float getPret() const 
    {
        return *pret; 
    }
    int getGarantie() const 
    {
        return garantie; 
    }

    
    void setMarca(string m) 
    {
        marca = m;
    }
    void setCuloare(string c) 
    {
        culoare = c; 
    }
    void setEsteReincarcabil(bool r) 
    {
        esteReincarcabil = r; 
    }
    void setPret(float p) 
    {
        *pret = p;
    }

    
    static int getNumarPixuri() { return numarPixuri; }

   
    friend void schimbaCuloarePix(Pix& p, string culoareNoua);
    friend void afiseazaPix(const Pix& p);
};


int Pix::numarPixuri = 0;


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

    
    string getTipCoperta() const 
    {
        return tipCoperta;
    }
    int getNumarPagini() const 
    {
        return numarPagini;
    }
    bool getEsteDatata() const 
    {
        return esteDatata; 
    }
    float getPret() const 
    {
        return *pret; 
    }
    int getAnFabricatie() const 
    {
        return anFabricatie; 
    }

   
    void setTipCoperta(string tip) 
    {
        tipCoperta = tip; 
    }
    void setNumarPagini(int pag)
    {
        numarPagini = pag;
    }
    void setEsteDatata(bool datata) 
    {
        esteDatata = datata; 
    }
    void setPret(float p) 
    {
        *pret = p;
    }

    
    static int getNumarAgende() { return numarAgende; }

    friend void modificaNumarPagini(Agenda& a, int pag);
    friend void afiseazaAgenda(const Agenda& a);
};


int Agenda::numarAgende = 0;


void modificaPret(Carte& c, float procent) {
    *c.pret *= (1 + procent / 100);
}

void schimbaCuloarePix(Pix& p, string culoareNoua) {
    p.culoare = culoareNoua;
}

void modificaNumarPagini(Agenda& a, int pag) {
    a.numarPagini = pag;
}

void afiseazaCarte(const Carte& c) {
    cout << "Carte: " << c.titlu << ", Autor: " << c.autor
        << ", Pagini: " << c.numarPagini << ", Pret: " << *c.pret
        << ", An Publicatie: " << c.anPublicatie << endl;
}

void afiseazaPix(const Pix& p) {
    cout << "Pix: " << p.marca << ", Culoare: " << p.culoare
        << ", Reincarcabil: " << (p.esteReincarcabil ? "Da" : "Nu")
        << ", Pret: " << *p.pret << ", Garantie: " << p.garantie << " luni" << endl;
}

void afiseazaAgenda(const Agenda& a) {
    cout << "Agenda: Coperta: " << a.tipCoperta << ", Pagini: " << a.numarPagini
        << ", Datata: " << (a.esteDatata ? "Da" : "Nu")
        << ", Pret: " << *a.pret << ", An Fabricatie: " << a.anFabricatie << endl;
}


int main() {
    Carte c1("Ion", "Liviu Rebreanu", 300, 45.5, 1930);
    modificaPret(c1, 10);
    afiseazaCarte(c1);

    Pix p1("BIC", "Albastru", true, 10);
    schimbaCuloarePix(p1, "Verde");
    afiseazaPix(p1);

    Agenda a1("Piele", 200, true, 50, 2023);
    modificaNumarPagini(a1, 250);
    afiseazaAgenda(a1);

    return 0;
}
