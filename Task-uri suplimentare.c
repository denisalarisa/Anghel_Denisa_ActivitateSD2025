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

//Realizati o functie care va creea un nou vector în care va copia dintr - un vector primit ca
//parametru obiectele care indeplinesc o anumita conditie.Stabiliti voi conditia in functie de
//un atribut sau doua atribute.

// conditie : un dosar sa aiba mai mult de doua documente

struct Dosar* maiMultDeDouaDocumente(struct Dosar* vector, int dim, int* dimNoua) {
    *dimNoua = 0;
    for (int i = 0; i < dim; i++) {
        if (vector[i].nrDocumente > 2) {
            (*dimNoua)++;
        }
    }

    struct Dosar* rezultat = (struct Dosar*)malloc(sizeof(struct Dosar) * (*dimNoua));
    int j = 0;
    for (int i = 0; i < dim; i++) {
        if (vector[i].nrDocumente > 2) {
            rezultat[j++] = vector[i];
        }
    }
    return rezultat;
}
//Realizati o functie care afiseaza un vector cu obiecte.
void afiseazaVector(struct Dosar* vector, int dim) {
    for (int i = 0; i < dim; i++) {
        afiseazaDosar(vector[i]);
    }
}

//Realizati o functie care muta intr - un nou vector obiectele care indeplinesc o alta conditie
//fata de cerinta precedenta.

// conditie : dosarul sa aiba mai mult de 25 de pagini

struct Dosar* nrPagini(struct Dosar* vector, int dim, int* dimNoua) {
    *dimNoua = 0;
    for (int i = 0; i < dim; i++) {
        if (totalPagini(vector[i]) > 25) {
            (*dimNoua)++;
        }
    }

    struct Dosar* rezultat = (struct Dosar*)malloc(sizeof(struct Dosar) * (*dimNoua));
    int j = 0;
    for (int i = 0; i < dim; i++) {
        if (totalPagini(vector[i]) > 25) {
            rezultat[j++] = vector[i];
        }
    }
    return rezultat;
}

//Realizati o functie care concateneaza doi vectori.

struct Dosar* concateneazaDoiVectori(struct Dosar* v1, int dim1, struct Dosar* v2, int dim2, int* dimRezultat) {
    *dimRezultat = dim1 + dim2;
    struct Dosar* rezultat = (struct Dosar*)malloc(sizeof(struct Dosar) * (*dimRezultat));
    for (int i = 0; i < dim1; i++) rezultat[i] = v1[i];
    for (int i = 0; i < dim2; i++) rezultat[dim1 + i] = v2[i];
    return rezultat;
}

int main() {
    int pagini[] = { 12, 8, 15 };
    struct Dosar d = initializare(75854, "Dosar Admitere", 3, pagini);
    afiseazaDosar(d);

    modificaNumeDosar(&d, "Dosar Penal");
    afiseazaDosar(d);

    elibereazaDosar(&d);

    //Creati in functia main un vector alocat dinamic cu cel putin 5 obiecte de tipul structurii voastre.
    int pagini1[] = { 10, 5 ,17};       
    int pagini2[] = { 8, 7, 6 };      
    int pagini3[] = { 15, 10, 3 };    
    int pagini4[] = { 21};           
    int pagini5[] = { 9, 9, 9, 9 };   

    struct Dosar* dosar = (struct Dosar*)malloc(sizeof(struct Dosar) * 5);
    dosar[0] = initializare(1, "Dosar 1", 2, pagini1);
    dosar[1] = initializare(2, "Dosar 2", 3, pagini2);
    dosar[2] = initializare(3, "Dosar 3", 3, pagini3);
    dosar[3] = initializare(4, "Dosar 4", 1, pagini4);
    dosar[4] = initializare(5, "Dosar 5", 4, pagini5);

    printf("\n============= Dosare cu mai mult de doua documente ==========================\n");
    int dimDosar;
    struct Dosar* dosare = maiMultDeDouaDocumente(dosar, 5, &dimDosar);
    afiseazaVector(dosare, dimDosar);
   // free(dosare);

    printf("\n============== Dosare cu mai mult de 25 de pagini in total ==================\n");
    int dimDosar2;
    struct Dosar* dosare2 = nrPagini(dosar, 5, &dimDosar2);
    afiseazaVector(dosare2, dimDosar2);
    //free(dosare2);
    
    printf("\n================= Vector concatenat ================\n");
    int dimVectorConcatenat;
    struct Dosar* vectorConcatenat = concateneazaDoiVectori(dosare, dimDosar, dosare2, dimDosar2, &dimVectorConcatenat);
    afiseazaVector(vectorConcatenat, dimVectorConcatenat);
    free(vectorConcatenat);
    free(dosare);
    free(dosare2);
    return 0;
}
