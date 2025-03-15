//Principiile P.O.O
//1.Abstractizare -> transpunerea unui obiect(si al trasaturilor) in linii de cod 
// implica definirea unor concepte din viata reala prin intermediul limbajelor de program
//2.Incapsularea -> securizam parti ale clasei, care pot fi accesate doar in interiorul clasei
// 
//3.Polimorfism ->utilizarea unui comportament pentru obiecte de tipuri diferite
// 3.1 polimorfism parametric-> apare atunci cand avem aceleasi functii cu acelasi nume, dar cu un numar diferit de parametrii(ex. constructorul)
// 3.2 polimorfism prin mostenire -> apare atunci cand avem aceeasi functie(cu acelasi numar de parametrii, in aceeasi ordine)
//4.Mostenirea/Dericare -> utilizarea codului prin crearea de clase derivate din clase existente

#include <iostream>
#include<string>
using namespace std;

//class Farmacie {
//    string nume;
//    int nrMedicamente;
//    float profit;//float pt zecimal.
//    bool esteNonStop;
//};

class Masina {
public:
    string denumire;
    int anProductie;
    float pret;
    bool esteAutomata;



    //constructorii sunt niste functii speciale cu acelasi nume 
    //ca si clasa, nu au niciun tip returnat si ii folosim pt a da valori obiectelor din clasa
    // avem 3 tipuri de constructor: default, cu paramaterii, fara parametrii;

    //constructorul default/implicit/fara parametrii

    Masina() {
        this->denumire = "necunoscut";
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
    Masina(string denumire, int anProductie, float pret, bool esteAutomata) {
        this->denumire = denumire;
        this->anProductie = anProductie;
        this->pret = pret;
        this->esteAutomata = esteAutomata;
    }



    //getteri/getters-> sunt functii/metode accesor care au ca scop extragerea/obtinerea valorii unui atribut din zona privata a clasei
    // getterul se face pt oricare tip de data din clasa
    
    /*
    tipDataAtribut getNumeAtribut(){
    
    }
    
    */

    //asa se face un getter pt string
    string getDenumire() {
        return this->denumire;
    }

    // asa se face un getter pt int
    int getAnProductie() {
        return this->anProductie;
    }

    // asa se face un getter pt float
    float getPret() {
        return this->pret;
    }

    // asa se face un getter pt bool
    bool getEsteAutomata() {
        return this->esteAutomata;
    }

    //setteri

        /*
        void setNUmarAtribut(tipDeAtribut numeAtribut){
        this->numeAtribut = numeAtrobut;

        }
         */
    void setDenumire(string denumire) {
        this->denumire = denumire;
    }

};

int main()
{

    
}
