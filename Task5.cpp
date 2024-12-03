#include <iostream>
#include <string>
#include <vector>
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

    friend istream& operator>>(istream& is, Carte& c) {
        cout << "Titlu (fara spatii): ";
        is >> c.titlu;
        cout << "Autor (fara spatii): ";
        is >> c.autor;
        cout << "Numar pagini: ";
        is >> c.numarPagini;
        cout << "Pret: ";
        is >> *c.pret;
        return is;
    }
};



int main() {
    int n;

    
    cout << "Cate carti doriti sa introduceti? ";
    cin >> n;
    vector<Carte> carti(n);
    for (int i = 0; i < n; ++i) {
        cout << "Introduceti datele pentru cartea " << i + 1 << ":\n";
        cin >> carti[i];
    }
    cout << "\nCartile introduse:\n";
    for (const auto& carte : carti) {
        cout << carte << endl;
    }

    
    int m;
    cout << "\nDimensiunea matricei de carti (linii, coloane): ";
    cin >> n >> m;
    vector<vector<Carte>> matrice;
    matrice.resize(n, vector<Carte>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "Introduceti datele pentru cartea [" << i + 1 << "][" << j + 1 << "]:\n";
            cin >> matrice[i][j];
        }
    }
    cout << "\nMatricea de carti introdusa:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
