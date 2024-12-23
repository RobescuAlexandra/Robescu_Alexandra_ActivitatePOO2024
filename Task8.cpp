#include <iostream>
#include <fstream>
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

    
    void scrieInFisierText(const string& numeFisier) const {
        ofstream fout(numeFisier, ios::app);
        if (fout.is_open()) {
            fout << titlu << "," << autor << "," << numarPagini << ","
                << *pret << "," << anPublicatie << endl;
            fout.close();
        }
    }

   
    void citesteDinFisierText(const string& numeFisier) {
        ifstream fin(numeFisier);
        if (fin.is_open()) {
            getline(fin, titlu, ',');
            getline(fin, autor, ',');
            fin >> numarPagini;
            fin.ignore(); 
            fin >> *pret;
            fin.ignore(); 
            fin.close();
        }
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

   
    void scrieInFisierBinar(const string& numeFisier) const {
        ofstream fout(numeFisier, ios::binary | ios::app);
        if (fout.is_open()) {
            size_t lungime = numeAgenda.size();
            fout.write((char*)&lungime, sizeof(lungime));
            fout.write(numeAgenda.c_str(), lungime);

            fout.write((char*)&numarPagini, sizeof(numarPagini));

            lungime = tipAgenda.size();
            fout.write((char*)&lungime, sizeof(lungime));
            fout.write(tipAgenda.c_str(), lungime);

            fout.close();
        }
    }

    
    void citesteDinFisierBinar(const string& numeFisier) {
        ifstream fin(numeFisier, ios::binary);
        if (fin.is_open()) {
            size_t lungime;

            fin.read((char*)&lungime, sizeof(lungime));
            numeAgenda.resize(lungime);
            fin.read(&numeAgenda[0], lungime);

            fin.read((char*)&numarPagini, sizeof(numarPagini));

            fin.read((char*)&lungime, sizeof(lungime));
            tipAgenda.resize(lungime);
            fin.read(&tipAgenda[0], lungime);

            fin.close();
        }
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

    
    void scrieInFisierText(const string& numeFisier) const {
        ofstream fout(numeFisier, ios::app);
        if (fout.is_open()) {
            fout << numarVolume << "," << domeniu << endl;
            fout.close();
        }
    }

    
    void citesteDinFisierText(const string& numeFisier) {
        ifstream fin(numeFisier);
        if (fin.is_open()) {
            fin >> numarVolume;
            fin.ignore();
            getline(fin, domeniu);
            fin.close();
        }
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

    
    void scrieInFisierBinar(const string& numeFisier) const {
        ofstream fout(numeFisier, ios::binary | ios::app);
        if (fout.is_open()) {
            size_t lungime = tipJurnal.size();
            fout.write((char*)&lungime, sizeof(lungime));
            fout.write(tipJurnal.c_str(), lungime);

            lungime = dataInceput.size();
            fout.write((char*)&lungime, sizeof(lungime));
            fout.write(dataInceput.c_str(), lungime);

            fout.close();
        }
    }

    
    void citesteDinFisierBinar(const string& numeFisier) {
        ifstream fin(numeFisier, ios::binary);
        if (fin.is_open()) {
            size_t lungime;

            fin.read((char*)&lungime, sizeof(lungime));
            tipJurnal.resize(lungime);
            fin.read(&tipJurnal[0], lungime);

            fin.read((char*)&lungime, sizeof(lungime));
            dataInceput.resize(lungime);
            fin.read(&dataInceput[0], lungime);

            fin.close();
        }
    }
};


int main() {
    Carte c1("C++ Programming", "Bjarne Stroustrup", 1234, 199.99, 1985);
    c1.scrieInFisierText("carti.txt");
    c1.citesteDinFisierText("carti.txt");
    c1.afiseaza();

    Agenda a1("Agenda Business", 200, "Business");
    a1.scrieInFisierBinar("agenda.dat");
    a1.citesteDinFisierBinar("agenda.dat");
    a1.afiseaza();

    return 0;
}
