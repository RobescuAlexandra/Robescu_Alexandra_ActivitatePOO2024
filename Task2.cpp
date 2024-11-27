#include <iostream>
#include <cstring>
using namespace std;

class Carte {
public:
    string titlu;
    string autor;
    int numarPagini;
    const int anPublicatie;
    static int numarCarti;
    float* pret;


    Carte() : anPublicatie(2000) {
        titlu = "Necunoscut";
        autor = "Necunoscut";
        numarPagini = 0;
        pret = new float(0.0);
        numarCarti++;
    }

    Carte(string t, string a, int pag) : anPublicatie(2000) {
        titlu = t;
        autor = a;
        numarPagini = pag;
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


    static void afiseazaNumarCarti() {
        cout << "Num?r total de c?r?i: " << numarCarti << endl;
    }


    ~Carte() {
        delete pret;
    }
};


int Carte::numarCarti = 0;


class Pix {
public:

    string marca;
    string culoare;
    bool esteReincarcabil;
    const int garantie;
    static int numarPixuri;
    float* pret;


    Pix() : garantie(12) {
        marca = "Necunoscut";
        culoare = "Albastru";
        esteReincarcabil = false;
        pret = new float(0.0);
        numarPixuri++;
    }

    Pix(string m, string c, bool r) : garantie(12) {
        marca = m;
        culoare = c;
        esteReincarcabil = r;
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


    static void afiseazaNumarPixuri() {
        cout << "Num?r total de pixuri: " << numarPixuri << endl;
    }


    ~Pix() {
        delete pret;
    }
};


int Pix::numarPixuri = 0;


class Agenda {
public:
    string tipCoperta;
    int numarPagini;
    bool esteDatata;
    const int anFabricatie;
    static int numarAgende;
    float* pret;


    Agenda() : anFabricatie(2022) {
        tipCoperta = "Necunoscut";
        numarPagini = 0;
        esteDatata = false;
        pret = new float(0.0);
        numarAgende++;
    }

    Agenda(string tip, int pag, bool datata) : anFabricatie(2022) {
        tipCoperta = tip;
        numarPagini = pag;
        esteDatata = datata;
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


    static void afiseazaNumarAgende() {
        cout << "Num?r total de agende: " << numarAgende << endl;
    }


    ~Agenda() {
        delete pret;
    }
};


int Agenda::numarAgende = 0;

int main() {
    Carte c1;
    Carte c2("Amintiri din copil?rie", "Ion Creang?", 120);
    Carte c3("Morome?ii", "Marin Preda", 300, 45.5, 1955);
    cout << "Carte 1: " << c1.titlu << ", " << c1.autor << ", pagini: " << c1.numarPagini << ", pret: " << *c1.pret << endl;
    cout << "Carte 2: " << c2.titlu << ", " << c2.autor << ", pagini: " << c2.numarPagini << ", pret: " << *c2.pret << endl;
    cout << "Carte 3: " << c3.titlu << ", " << c3.autor << ", pagini: " << c3.numarPagini << ", pret: " << *c3.pret << endl;
    Carte::afiseazaNumarCarti();


    Pix p1;
    Pix p2("BIC", "Ro?u", true);
    Pix p3("Pilot", "Negru", true, 10.5);
    cout << "Pix 1: " << p1.marca << ", culoare: " << p1.culoare << ", reincarcabil: " << p1.esteReincarcabil << ", pret: " << *p1.pret << endl;
    cout << "Pix 2: " << p2.marca << ", culoare: " << p2.culoare << ", reincarcabil: " << p2.esteReincarcabil << ", pret: " << *p2.pret << endl;
    cout << "Pix 3: " << p3.marca << ", culoare: " << p3.culoare << ", reincarcabil: " << p3.esteReincarcabil << ", pret: " << *p3.pret << endl;
    Pix::afiseazaNumarPixuri();


    Agenda a1;
    Agenda a2("Plastic", 200, true);
    Agenda a3("Piele", 300, false, 50.0, 2023);
    cout << "Agend? 1: copert?: " << a1.tipCoperta << ", pagini: " << a1.numarPagini << ", datat?: " << a1.esteDatata << ", pret: " << *a1.pret << endl;
    cout << "Agend? 2: copert?: " << a2.tipCoperta << ", pagini: " << a2.numarPagini << ", datat?: " << a2.esteDatata << ", pret: " << *a2.pret << endl;
    cout << "Agend? 3: copert?: " << a3.tipCoperta << ", pagini: " << a3.numarPagini << ", datat?: " << a3.esteDatata << ", pret: " << *a3.pret << endl;
    Agenda::afiseazaNumarAgende();

    return 0;
}