#include<iostream>

using namespace std;

class Cofetarie
{
private:
	string nume;//
	int nrAngajati;//
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;
public:
	Cofetarie() :adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}


	Cofetarie(string nume, int nrAngajati, bool esteVegana, int an, float adaos) :anDeschidere(an)
	{
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = esteVegana;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}
	//CONSTTRUCTOR DE COPIERE
	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {

		this->nume = c.nume;


		this->nrAngajati = c.nrAngajati;


		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++)
			this->salarii[i] = c.salarii[i];


		this->esteVegana = c.esteVegana;


		this->adaos = c.adaos;
	}

	//DECONSTRUCTOR: ELIBERARI DIN MEMORIE HEAP:
	~Cofetarie()
	{
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}

	//Seminar 5:
	Cofetarie operator=(const Cofetarie& c) {
		//autoasignare-- n am ce sa copiez in cazul in care am sters
			// (in cazul in care e gol sa nu faca nimic)
		if (&c != this) {
			this->nume = c.nume;

			this->nrAngajati = c.nrAngajati;

			if (this->salarii != NULL)
				delete[]this->salarii;

			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++)
				this->salarii[i] = c.salarii[i];


			this->esteVegana = c.esteVegana;

			this->adaos = c.adaos;
			//operator=-> trebuie sa returnam ceva:
		}
		return *this;
	}



	//functiile set si get:

	string getNume()
	{
		return this->nume;
	}

	void setNume(string nume)
	{
		if (nume.length() > 1) {
			//setam atributul nume
			this->nume = nume;
		}
	}
	int getNrAngajati() {
		return this->nrAngajati;
	}


	void setNrAngajati(int nrAngajati, float* salarii)
	{
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL)
				delete[]this->salarii;
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii()
	{
		return this->salarii;
	}

	float getSalariu(int index)
	{
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	//Seminar 5:
	//operator+ =  metoda nu functie
	//operator pentru a aduna 2 cofetarii:
	// prin const, face this constanta
	Cofetarie operator+(Cofetarie c2)const {
		//trbuie declarat un obiect nou(pt ca e metoda)
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c2.nrAngajati;
		//alocam luu aux spatiul pe heap
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			//copiem in aux
			aux[i] = this->salarii[i];
		}
		//pt copiatul celor din c2 trrbuie fct alt for
		for (int i = 0; i < c2.nrAngajati; i++)
		{
			//pt ca deja am ocupat primele i spatii ale lui aux, ne deplasam
			aux[i + this->nrAngajati] = c2.salarii[i];
		}
		//eliberare memorie
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		//din cauza ca i am alocat memorie in HEAP, nu trebuie sters aux, putem scrie direct:
		temp.salarii = aux;
		return temp;

	}
	Cofetarie operator+(float salarii)const
	{
		//temp e posibil sa existe, asa ca il stergem in cazu in care nu este gol
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];

		//copiem:
		for (int i = 0; i < this->nrAngajati; i++)
		{
			temp.salarii[i] = this->salarii[i];
		}
		//adaugam salariul din main (linia de am zis ca i trebuie o supraincarcare la operator
		temp.salarii[temp.nrAngajati] = salarii;
		temp.nrAngajati++;
		return temp;
	}

	//metoda este privita ca functie cand pui friend:
	//copiat ala de mai sus, doar ca am schimbat this pt ca adaugand friend, nu mai exista parametrul this
	friend Cofetarie operator+(float salarii, Cofetarie c) {

		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];


		for (int i = 0; i < c.nrAngajati; i++)
		{
			temp.salarii[i] = c.salarii[i];
		}

		temp.salarii[temp.nrAngajati] = salarii;
		temp.nrAngajati++;
		return temp;
	}


	friend Cofetarie operator+(float salarii, Cofetarie c);

	void afisare()
	{
		cout << "Nume: " << this->nume << endl;
		cout << "Nr. angajati: " << this->nrAngajati << endl;
		cout << "E vegana?: " << (this->esteVegana ? "da" : "nu") << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << this->TVA << endl;
	}


	static void modificaTVA(int noulTVA)
	{
		if (noulTVA > 0)
			Cofetarie::TVA = noulTVA;

	}

	static int calculareNrTotalAngajati(int nrCofetarii, Cofetarie* vector)
	{
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++)
			suma += vector[i].nrAngajati;
		return suma;
	}

};

int Cofetarie::TVA = 9;

void f(Cofetarie c) {

}

//chiar daca o pun in afara clasei, am acces la zona privata a clasei pt ca am pus linia aceea cu friend
/*friend Cofetarie operator+(float salarii, Cofetarie c) {
	float valoare = c.nrAngajati;
	return c + salarii;
}
*/
//ANULEAZA rel de prietenie
/*
Cofetarie operator+(float salarii, Cofetarie &c) {
	float valoare = c.nrAngajati
		return c + salarii;
}
*/
int main()
{

	Cofetarie c1;
	Cofetarie c2("Minimal", 3, false, 2019, 10);

	int a = 9;
	int b = 6;
	int c = a + b;
	//c=15
	Cofetarie c3 = c1 + c2;
	Cofetarie c4 = c1.operator+(c2);
	//pentru a fi posibila ec de mai jos, ne fol de polimorfism si supraincarcam operatorul+
	Cofetarie c5 = c1 + 2000.0f; //c1.operator(2000.0f);

	//Cofetarie c6 = 3000.0f + c1;//nu merge scrisa ca cea de mai sus

}