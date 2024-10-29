#include<iostream>

using namespace std;

struct Ciocolata {
	int gramaj;
	float pret;
	string nume;
	bool esteAmaruie;


};

//tip_returnat nume_functie([params]){ }

void afisareCiocolata(Ciocolata c) {
	cout << "Nume ciocolata:" << c.nume << endl;
	cout << "Pret:" << c.pret << endl;
	cout << "Gramaj:" << c.gramaj << endl;
	cout << "Este amaruie:" << (c.esteAmaruie ? "DA" : "NU") << endl;

	//conditie?dacaEAdevarat:DacaEFals

}


void modificaPret(Ciocolata* c, float pretNou) {
	c->pret = pretNou;

}

void modificaPretRef(Ciocolata& c, float pretNou) {
	c.pret = pretNou;


}

Ciocolata initializareCiocolata(int gramaj, float pret, string nume, bool amaruie) {
	Ciocolata c;
	c.gramaj = gramaj;
	c.pret = pret;
	c.nume = nume;
	c.esteAmaruie = amaruie;
	return c;
}

int main() {
	Ciocolata c1;
	c1 = initializareCiocolata(50, 7, "Milka", 0);

	afisareCiocolata(c1)

		; cout << "Nume ciocolata:" << c1.nume << endl;
	; cout << "Pret:" << c1.pret << endl;
	; cout << "Gramaj:" << c1.gramaj << endl;
	; cout << "Este amaruie:" << c1.esteAmaruie << endl;


	Ciocolata c2;
	cout << "Nume ciocolata:"
		; cin >> c2.nume;
	cout << "Introduceti gramajul:";
	; cin >> c2.gramaj;
	cout << "Introduceti pretul:"
		; cin >> c2.pret;
	cout << "Este amaruie?(1 - DA; 0- NU):";
	; cin >> c2.esteAmaruie;

	afisareCiocolata(c2);

	modificaPret(&c2, 40);
	modificaPretRef(c2, 60);
	afisareCiocolata(c2);





}