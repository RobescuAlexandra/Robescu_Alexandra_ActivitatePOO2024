#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Publicatie {
public:
    virtual void afiseaza() const = 0; 
    virtual ~Publicatie() {}           
};


class Nota {
public:
    virtual void afiseaza() const = 0; 
    virtual ~Nota() {}                 
};

class Carte : public Publicatie {
protected:
    string titlu;
    string autor;
    int numarPagini;

public:
    Carte() : titlu("Necunoscut"), autor("Necunoscut"), numarPagini(0) {}
    Carte(string t, string a, int pag) : titlu(t), autor(a), numarPagini(pag) {}
    virtual void afiseaza() const override {
        cout << "Carte: " << titlu << ", Autor: " << autor
            << ", Pagini: " << numarPagini << endl;
    }
};


class Enciclopedie : public Carte {
private:
    int numarVolume;

public:
    Enciclopedie() : Carte(), numarVolume(0) {}
    Enciclopedie(string t, string a, int pag, int vol)
        : Carte(t, a, pag), numarVolume(vol) {}
    virtual void afiseaza() const override {
        Carte::afiseaza();
        cout << "Numar volume: " << numarVolume << endl;
    }
};

class Agenda : public Nota {
protected:
    string numeAgenda;
    int numarPagini;

public:
    Agenda() : numeAgenda("Necunoscut"), numarPagini(0) {}
    Agenda(string nume, int pag) : numeAgenda(nume), numarPagini(pag) {}
    virtual void afiseaza() const override {
        cout << "Agenda: " << numeAgenda << ", Pagini: " << numarPagini << endl;
    }
};

class Jurnal : public Agenda {
private:
    string tipJurnal;

public:
    Jurnal() : Agenda(), tipJurnal("Necunoscut") {}
    Jurnal(string nume, int pag, string tip)
        : Agenda(nume, pag), tipJurnal(tip) {}
    virtual void afiseaza() const override {
        Agenda::afiseaza();
        cout << "Tip Jurnal: " << tipJurnal << endl;
    }
};


class Biblioteca {
private:
    vector<Publicatie*> publicatii;

public:
    void adaugaPublicatie(Publicatie* p) {
        publicatii.push_back(p);
    }

    void afiseazaPublicatii() const {
        for (const auto& p : publicatii) {
            p->afiseaza();
        }
    }
};

class Organizator {
private:
    vector<Nota*> note;

public:
    void adaugaNota(Nota* n) {
        note.push_back(n);
    }

    void afiseazaNote() const {
        for (const auto& n : note) {
            n->afiseaza();
        }
    }
};


int main() {

    vector<Publicatie*> vectorPublicatii;
    vectorPublicatii.push_back(new Carte("C++ Programming", "Bjarne Stroustrup", 800));
    vectorPublicatii.push_back(new Enciclopedie("Enciclopedia Naturii", "John Doe", 1200, 10));

    cout << "Publicatii:" << endl;
    for (const auto& pub : vectorPublicatii) {
        pub->afiseaza();
    }

    vector<Nota*> vectorNote;
    vectorNote.push_back(new Agenda("Agenda Business", 200));
    vectorNote.push_back(new Jurnal("Jurnal Personal", 150, "Emotional"));

    cout << "\nNote:" << endl;
    for (const auto& nota : vectorNote) {
        nota->afiseaza();
    }

    Biblioteca biblio;
    biblio.adaugaPublicatie(new Carte("Design Patterns", "Erich Gamma", 395));
    biblio.adaugaPublicatie(new Enciclopedie("Istoria Lumii", "Jane Doe", 1000, 5));
    cout << "\nBiblioteca:" << endl;
    biblio.afiseazaPublicatii();

    Organizator organizator;
    organizator.adaugaNota(new Agenda("Agenda de Proiect", 300));
    organizator.adaugaNota(new Jurnal("Jurnal de Calatorie", 250, "Aventuri"));
    cout << "\nOrganizator:" << endl;
    organizator.afiseazaNote();

    for (auto& pub : vectorPublicatii) {
        delete pub;
    }
    for (auto& nota : vectorNote) {
        delete nota;
    }

    return 0;
}
