#include <iostream>
#include <string>

using namespace std;

struct Bloc {
    string strada;
    int numarScari;
    int numarApartamente;
    int etaje;
    string tipBloc;  
};

void citesteBloc(Bloc* b) {
    cout << "Introduceti strada: ";
    cin.ignore(); 
    getline(cin, b->strada);

    cout << "Introduceti numarul de scari: ";
    cin >> b->numarScari;

    cout << "Introduceti numarul de apartamente: ";
    cin >> b->numarApartamente;

    cout << "Introduceti numarul de etaje: ";
    cin >> b->etaje;

    cout << "Introduceti tipul de bloc: ";
    cin.ignore();
    getline(cin, b->tipBloc);
}


void afiseazaBloc(const Bloc* b) {
    cout << "Blocul de pe strada " << b->strada
        << ", are " << b->numarScari << " scari si un numar total de "
        << b->numarApartamente << " apartamente, fiind un bloc cu "
        << b->etaje << " etaje. Tipul blocului este: " << b->tipBloc << "." << endl;
}

int main() {
    Bloc* blocuri[10];
    for (int i = 0; i < 10; i++) {
        blocuri[i] = new Bloc;  
        cout << "Introduceti informatii pentru blocul " << i + 1 << ":\n";
        citesteBloc(blocuri[i]);  
    }

    for (int i = 0; i < 10; i++) {
        afiseazaBloc(blocuri[i]);  
    }

    
    for (int i = 0; i < 10; i++) {
        delete blocuri[i];  
    }

    return 0;
}