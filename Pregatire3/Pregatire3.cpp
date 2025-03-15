﻿//P.O.O --> programare orientata pe obiecte

//Principiile P.O.O
//1)Abstractizare --> transpunerea unui obiect din realitate(si a trasaturilor acestuia) in linii de cod
//2)Incapsulare --> securizam parti ale clasei, care pot fi accesate doar in interiorul acesteia
//3)
//4)



#include<iostream>
#include<string>
using namespace std;

//librariile au deja implementari facute, care ne ajuta pe noi sa rezolvam cerintele avute

//noi putem comunica cu compilatorul prin intermediul variabilelor/atributelor
//Atributul/variabila este alcatuita din tip de data+ denumire(si o valoare)

//ce tipuri de data avem?
//int --> retine numere intregi --> 4 bytes/octeti
//char --> retine un singur caracter(acesta poate fi de orice natura) --> 1 byte/octet
//float --> retine numere cu virgula ---> 4 bytes/ octeti
//double --> retine numere cu virgula ---> 8 bytes/ octeti
//string --> retine un sir de caractere(colectie de caractere) --> 40 bytes/octeti
//bool --> retine true sau false(1 sau 0) --> 1 byte/octet

//cum aflam cat ocupa un tip de data --> folosind comanda sizeof();



//structurile sunt tipuri de date personalizate care contin mai multe variabile
//structurile se formeaza utilizand cuvantul cheie struct, urmat de numele structurii
//DENUMIREA STRUCTURII TREBUIE SA FIE UN SUBSTANTIV COMUN, LA NUMARUL SINGULAR, SCRIS CU MAJUSCULA
//problema cu structurile sunt urmatoarele:
//1) nu ofera deloc securitate, ele avand ca modificator de acces public
//2) nu putem crea metode/functii in cadrul unei structuri

struct CardDeCredit {
	string numePersoana;
	int codPIN;
	float sold;
};

//clasa este o structura mai avansata, deoarece ofera securitate si de asemenea, putem implementa in interiorul clasei
//diferite functi/metode

//Clasa fata de o structura, are si comportament

//modificatorul de acces by default intr-o clasa este private


class Institutie {

	string nume;
	int nrAngajati;
	float suprafata;
	bool esteNonStop;
public:
	//DomeniuActivitate domeniu;
	// in cadrul claselor putem crea constructori
	//Constructorii sunt functii speciale, care nu au tip returnat, au acelasi nume ca si clasa, si se ocupa
	//crearea obiectelor si de initializarea atributelor acestora

	//Putem avea 3 tipuri de constructori
	//1)Constructorul default/implicit/ fara parametrii
	//2)Constructorul cu parametrii( de la 1 parametru pana la N parametrii, unde N este numarul de atribute din clasa)
	//3)Constructorul de copiere

	//IN ORICE CONSTRUCTOR, TREBUIE SA INITIALIZAM TOATE VARIABILELE CLASEI, 
	// INDIFERENT DACA AVEM PARAMETRU SAU NU PENTRU UN ATRIBUT

	//constructorul default/implicit/fara parametrii trebuie intotdeauna facut!!!

	//POINTERUL THIS, ESTE UN POINTER CARE RETINE ADRESA OBIECTULUI CURENT, LA CARE FACEM REFERIRE
	Institutie() {
		this->nume = "X";
		this->nrAngajati = 0;
		this->suprafata = 0;
		this->esteNonStop = false;
	}


	//CONSTRUCTOR CU UN PARAMETRU
	Institutie(string nume) {
		this->nume = nume;
		this->nrAngajati = 0;
		this->suprafata = 0;
		this->esteNonStop = false;
	}


	Institutie(float suprafata) {
		this->nume = "X";
		this->nrAngajati = 0;
		this->suprafata = suprafata;
		this->esteNonStop = false;
	}

	//constructorul cu doi parametrii
	Institutie(string nume, float suprafata) {
		this->nume = nume;
		this->nrAngajati = 0;
		this->suprafata = suprafata;
		this->esteNonStop = false;
	}





	//CONSTRUCTORUL CU TOTI PARAMETRII
	//parametrul este un atribut care nu apartine clasei(vine din sursa externa)
	Institutie(string nume, int nrAngajati, float suprafata, bool esteNonStop) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->esteNonStop = esteNonStop;
	}


	//getteri/getters --> sunt functii/metode accesor care au ca scop extragerea/obtinerea valorii
	//unui atribut din zona privata a clasei
	//getter-ul se face pentru orice tip de data din clasa

	/*
		sablon pentru getter --> asa se face un getter

		tipDeDataAtribut getNumeAtribut(){
			return this->numeAtribut;
		}
	*/

	//asa se face getter pentru string
	string getNume() {
		return this->nume;
	}

	//asa se face getter pentru int
	int getNrAngajati() {
		return this->nrAngajati;
	}

	//asa se face getter pentru double/float
	float getSuprafata() {
		return this->suprafata;
	}

	//asa se face getter pentru bool
	bool getEsteNonStop() {
		return this->esteNonStop;
	}

	//setter -- functii/metode accesor care permit modificarea valorii unui atribut din clasa

	/*
		sablon pentru setter
		void setNumeAtribut(tipDeDataAtribut numeAtribut){
			this->numeAtribut = numeAtribut;
		}
	*/

	void setNume(string nume) {
		this->nume = nume;
	}

	void setNrAngajati(int nrAngajati) {
		this->nrAngajati = nrAngajati;
	}

	void setSuprafata(float suprafata) {
		this->suprafata = suprafata;
	}

	void setEsteNonStop(bool esteNonStop) {
		this->esteNonStop = esteNonStop;
	}

	string schimbaDenumirea(string nume) {
		this->nume = nume;
		return this->nume;
	}
};


/*string nume;
int nrAngajati;
float suprafata;
bool esteNonStop;*/


int main() {
	cout << "=========================CLASE=========================" << endl;
	Institutie inst;//obiect creat pe baza constructorului default/implicit/fara parametrii
	cout << inst.getNume() << endl;
	cout << inst.getNrAngajati() << endl;
	cout << inst.getSuprafata() << endl;
	cout << inst.getEsteNonStop() << endl;
	cout << endl << endl << endl;


	Institutie inst1("ASE", 900, 546.12, 0);//obiect creat pe baza constructorului cu toti parametrii
	cout << inst1.getNume() << endl;
	cout << inst1.getNrAngajati() << endl;
	cout << inst1.getSuprafata() << endl;
	cout << inst1.getEsteNonStop() << endl;
	cout << endl << endl << endl;


	inst1.setNume("Politehnica");
	inst1.setNrAngajati(890.15);
	inst1.setSuprafata(560.35);
	inst1.setEsteNonStop(true);


	cout << inst1.getNume() << endl;
	cout << inst1.getNrAngajati() << endl;
	cout << inst1.getSuprafata() << endl;
	cout << inst1.getEsteNonStop() << endl;
	cout << endl << endl << endl;

	Institutie inst2("Agronomie");
	cout << inst2.getNume() << endl;
	cout << inst2.getNrAngajati() << endl;
	cout << inst2.getSuprafata() << endl;
	cout << inst2.getEsteNonStop() << endl;
	cout << endl << endl << endl;


	Institutie inst3(100);
	cout << inst3.getNume() << endl;
	cout << inst3.getNrAngajati() << endl;
	cout << inst3.getSuprafata() << endl;
	cout << inst3.getEsteNonStop() << endl;
	cout << endl << endl << endl;

	Institutie inst4(134.13);
	cout << inst4.getNume() << endl;
	cout << inst4.getNrAngajati() << endl;
	cout << inst4.getSuprafata() << endl;
	cout << inst4.getEsteNonStop() << endl;
	cout << endl << endl << endl;

	Institutie inst5("FABIZ", 657.12);
	cout << inst5.getNume() << endl;
	cout << inst5.getNrAngajati() << endl;
	cout << inst5.getSuprafata() << endl;
	cout << inst5.getEsteNonStop() << endl;
	cout << endl << endl << endl;

}

//cate o clasa, care sa contina un string, un int, un float/double, un bool

class Prajitura { //Iulia
	string marca;
	int caiPutere;
	float pret;
	bool esteAutomata;
};

class Avion { //Lexy
	string companie;
	int nrLocuri;
	float kmParcursi;
	bool esteEconomy;
};

class Angajat {//Alexandra
	string nume;
	int varsta;
	float salariu;
	bool areContractDeterminat;
};