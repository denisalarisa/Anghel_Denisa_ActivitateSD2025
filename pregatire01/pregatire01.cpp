//P.O.O(PROGRAMARE ORIENTATA OBIECT[E])



#include<iostream>
#include<string>
//librariile au deja implementari facute, care ne ajuta pe noi in rezolvarea cerintelor
using namespace std;

//ce sunt variabilele? -> sunt locatii de memorie unde se stocheaza date(valori), ce pot fi utilizate si manipulate

//tipuri de data-> definesc natura si dimensiunea variabilelor/atributelor

//int--> numere intregi --> ocupa 4 bytes/octeti
//char--> pentru un caracter --> ocupa 1 byte/octet
//double --> pentru numere cu virgula foarte mari-->ocupa 8 bytes/octeti
//string --> colectie de caractere --> ocupa 40 bytes/octeti sau 28 bytes/octeti (in functie de numarul de biti de la windows)
//float --> pentru numere cu virgula --> ocupa 4 bytes/octeti
//bool --> true sau false(1 sau 0) --> ocupa 1 byte/octet

//cum aflam cat ocupa fiecare tip de data?
//R: cu comanda sizeof


//structurile sunt tipuri de date personalizate care contin mai multe variabile
//structurile se formeaza utilzand cuvantul cheie struct, urmat de numele structurii
//DENUMIREA STRUCTURII TREBUIE SA FIE UN SUBSTANTIV COMUN, LA NUMARUL SINGULAR, SCRIS CU MAJUSCULA


//INTOTDEAUNA DATI VALORI ATRIBUTELOR/OBIECTE DIN MAIN!!!
//DACA NU DATI VALORI, O SA PUNA COMPILATORUL SINGUR VALORI DE TIPUL GARBAGE

struct CardCredit {
	string numePropietar;
	int codPIN;
	float sold;
};

//structurile are by default modificatorul de acces public(adica toata lumea poate umbla in obiectele noastre)
//nu avem deloc securitate

//modificatorul de acces este un cuvant cheie care determina securitatea unui segment dintr-o clasa
//modificatorii de acces sunt de 3 tipuri:
//1)public --> toata lumea are acces
//2)private ---> anumite persoane au acces
//3)protected ---> mix intre public si private


//clasa este o structura mai avansata deoarece ofera securitate, de asemenea putem implementa metode/functii in interiorul clasei
//clasa este un tip de data personalizat, care poate contine mai multe atribute(exact ca structura)
//clasa are by default modificatorul de acces private

class Masina {
public:
	string denumire;
	int anProductie;
	float pret;
	bool esteAutomata;


	//constructorul este o functie speciala, care nu are tip returnat, are acelasi nume ca si clasa.
	//constructorul va construi obiectul pe baza cerintelor noastre(adica ii spunem noi cu ce valori sa populeze acele campuri)
	//exista 3 feluri de constructori
	//1)Constructor fara parametrii/default/implicit --> asta inseamna ca nu ii dam niciun parametru
	//2)Constructorul cu parametrii(de la 1 parametru pana la N parametrii, unde N este numarul de atribute)
	//3)constructorul de copiere

	//IN TOTI CONSTRUCTORII TREBUIE SA INITIALIZAM TOATE ATRIBUTELE CLASEI


	//constructorul default/implicit/fara parametrii
	Masina() {
		this->denumire = "Necunoscut";
		this->anProductie = 0;
		this->pret = 0;
		this->esteAutomata = 0;
	}


	//constructorul cu un parametru
	Masina(string denumire) {
		this->denumire = denumire;
		this->anProductie = 0;
		this->pret = 0;
		this->esteAutomata = 0;
	}

	//constructorul cu toti parametrii
	//pointeurl this primeste adresa obiectului curent asupra caruia se fac modificarile
	Masina(string denumire, int anProductie, float pret, bool esteAutomata) {
		this->denumire = denumire;
		this->anProductie = anProductie;
		this->pret = pret;
		this->esteAutomata = esteAutomata;
	}



};



int main() {
	string numeStudent = "Razvanel";
	cout << numeStudent << endl; //asa vedem ce valoare contine variabila ceruta
	//cout << &numeStudent << endl;//asa aflam adresa unei variabile
	int varsta = 25;
	cout << varsta << endl; //asa vedem ce valoare contine variabila ceruta

	float medie = 8.9;
	cout << medie << endl; //asa vedem ce valoare contine variabila ceruta
	cout << endl << endl;

	string numeStudent1 = "Roxana";
	cout << numeStudent1 << endl;
	int varsta1 = 21;
	cout << varsta1 << endl; //asa vedem ce valoare contine variabila ceruta

	float medie1 = 9.80;
	cout << medie1 << endl; //asa vedem ce valoare contine variabila ceruta

	//char-ul salveaza un singur caracter!!!!


	//structura contine mai multe variabile
	//cand instantam o structura in main(adica dam valori atributelor din ea) de fapt cream un obiect
	//un obiect este o instanta a unei structuri/clase

	CardCredit cc;
	cout << cc.numePropietar << endl;
	cout << cc.codPIN << endl;
	cout << cc.sold << endl;
	cout << endl << endl;

	cc.numePropietar = "Mihai Razvan";
	cc.codPIN = 1516;
	cc.sold = 99999999;

	cout << cc.numePropietar << endl;
	cout << cc.codPIN << endl;
	cout << cc.sold << endl;
	cout << endl << endl;

	cc.numePropietar = "Georgica";

	cout << endl << endl << endl;
	cout << "==================================CLASE==================================" << endl;
	//obiectul este o instanta a clasei
	//noi in main lucram cu obiecte
	Masina m;//obiect creat pe baza constructorului fara parametrii
	cout << m.denumire << endl;
	cout << m.anProductie << endl;
	cout << m.pret << endl;
	cout << m.esteAutomata << endl;
	cout << endl << endl;

	Masina m1("BMW", 2017, 50000, 1);//obiect creat pe baza constructorului cu toti parametrii
	cout << m1.denumire << endl;
	cout << m1.anProductie << endl;
	cout << m1.pret << endl;
	cout << m1.esteAutomata << endl;
	cout << endl << endl;


	Masina m2("Mercedes");//obiect creat pe baza constructorului cu un parametru
	cout << m2.denumire << endl;
	cout << m2.anProductie << endl;
	cout << m2.pret << endl;
	cout << m2.esteAutomata << endl;
	cout << endl << endl;

}