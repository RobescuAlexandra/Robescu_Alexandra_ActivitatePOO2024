#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Carte {
private:
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

    ~Carte() {
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

    friend ostream& operator<<(ostream& os, const Carte& c) {
        os << "Carte: " << c.titlu << ", Autor: " << c.autor
            << ", Pagini: " << c.numarPagini << ", Pret: " << *c.pret
            << ", An Publicatie: " << c.anPublicatie;
        return os;
    }
};

class Biblioteca {
private:
    string nume;
    string adresa;
    int capacitateMaxima;
    vector<Carte> carti; 

public:
    Biblioteca() {
        nume = "Biblioteca Necunoscuta";
        adresa = "Adresa Necunoscuta";
        capacitateMaxima = 100;
    }

    Biblioteca(string n, string a, int capMax) {
        nume = n;
        adresa = a;
        capacitateMaxima = capMax;
    }

    Biblioteca(const Biblioteca& other) {
        nume = other.nume;
        adresa = other.adresa;
        capacitateMaxima = other.capacitateMaxima;
        carti = other.carti;
    }

    ~Biblioteca() {
       
    }

    
    string getNume() const {
        return nume;
    }

    void setNume(const string& n) {
        nume = n;
    }

    string getAdresa() const {
        return adresa;
    }

    void setAdresa(const string& a) {
        adresa = a;
    }

    int getCapacitateMaxima() const {
        return capacitateMaxima;
    }

    void setCapacitateMaxima(int capMax) {
        capacitateMaxima = capMax;
    }

    vector<Carte> getCarti() const {
        return carti;
    }

    void setCarti(const vector<Carte>& c) {
        carti = c;
    }

 
    Biblioteca& operator+=(const Carte& c) {
        if ((int)carti.size() < capacitateMaxima) {
            carti.push_back(c);
        }
        else {
            cout << "Capacitate maxima atinsa! Nu se poate adauga cartea." << endl;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Biblioteca& b) {
        os << "Biblioteca: " << b.nume << ", Adresa: " << b.adresa << ", Capacitate: " << b.capacitateMaxima << endl;
        os << "Carti in biblioteca:\n";
        for (const auto& carte : b.carti) {
            os << carte << endl;
        }
        return os;
    }

    bool operator==(const Biblioteca& other) const {
        return carti.size() == other.carti.size();
    }
};

int main() {
    Carte c1("Hobbitul", "Tolkien", 310, 39.99, 1937);
    Carte c2("1984", "George Orwell", 328, 29.99, 1949);
    Carte c3("Micul Print", "Antoine de Saint-Exupery", 96, 19.99, 1943);

    Biblioteca b1("Biblioteca Centrala", "Strada Principala, nr. 1", 2);
    b1 += c1;
    b1 += c2;
    cout << b1;

    
    Biblioteca b2("Biblioteca Locala", "Strada Secundara, nr. 2", 3);
    b2 += c1;
    b2 += c2;
    b2 += c3;

    cout << (b1 == b2 ? "Bibliotecile au acelasi numar de carti.\n" : "Bibliotecile au un numar diferit de carti.\n");

    return 0;
}
