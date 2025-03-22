#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dosar {
    int cod;
    char* numeDosar;
    int nrDocumente;
    int* nrPaginiDocumente;
};

//Realizati o functie cu ajutorul careia sa cititi de la tastatura un articol de tipul construit de
//voi.Funcția returnează obiectul citit.

struct Dosar initializare(int cod, const char* numeDosar, int nrDocumente, int* nrPaginiDocumente) {
    struct Dosar d;
    d.cod = cod;
    d.nrDocumente = nrDocumente;

    d.numeDosar = (char*)malloc(strlen(numeDosar) + 1);
    strcpy_s(d.numeDosar, strlen(numeDosar) + 1, numeDosar);

    d.nrPaginiDocumente = (int*)malloc(sizeof(int) * nrDocumente);
    for (int i = 0; i < nrDocumente; i++) {
        d.nrPaginiDocumente[i] = nrPaginiDocumente[i];
    }

    return d;
}

//Realizati o functie care calculeaza ceva pentru un obiect de tipul implementat de voi. (o medie sau o suma, un maxim, un minim...
// sau orice altceva).

int totalPagini(struct Dosar d) {
    int total = 0;
    for (int i = 0; i < d.nrDocumente; i++) {
        total += d.nrPaginiDocumente[i];
    }
    return total;
}

//Realizati o functie care modifica pentru un obiect primit ca parametru, un anumit camp.Noua valoare este primita ca parametru.

void modificaNumeDosar(struct Dosar* d, const char* nouNume) {
    free(d->numeDosar);
    d->numeDosar = (char*)malloc(strlen(nouNume) + 1);
    strcpy_s(d->numeDosar, strlen(nouNume) + 1, nouNume);
}



//Realizați o funcție care afișează un obiect de tipul creat. Afișarea se face la console, și sunt
// afișate toate informațiile.

void afiseazaDosar(struct Dosar d) {
    printf("\n--- DOSAR ---\n");
    printf("Cod: %d\n", d.cod);
    printf("Nume dosar: %s\n", d.numeDosar);
    printf("Numar documente: %d\n", d.nrDocumente);
    for (int i = 0; i < d.nrDocumente; i++) {
        printf("  Document %d: %d pagini\n", i + 1, d.nrPaginiDocumente[i]);
    }
    printf("Total pagini in dosar: %d\n", totalPagini(d));
}


void elibereazaDosar(struct Dosar* d) {
    free(d->numeDosar);
    free(d->nrPaginiDocumente);
}



int main() {
    int pagini[] = { 12, 8, 15 };
    struct Dosar d = initializare(75854, "Dosar Admitere", 3, pagini);
    afiseazaDosar(d);

    modificaNumeDosar(&d, "Dosar Penal");
    afiseazaDosar(d);

    elibereazaDosar(&d);

    return 0;
}
