#include<stdio.h>
#include<stdlib.h>

struct  Masina {
	int id;
	int nrLocuri;
	char* marca;
	float capacitateC;
	char normaPoluare;
};

struct Masina initializare(int id, int nrLocuri, const char* marca, float capacitateC, char  normaPoluare) {
	struct Masina m;
	m.id = id;
	m.nrLocuri = nrLocuri;
	m.capacitateC = capacitateC;
	m.normaPoluare = normaPoluare;
	m.marca = (char*)malloc(strlen(marca) + 1);
	strcpy_s(m.marca, strlen(marca) + 1, marca);
	return m;
}

void afisare(struct Masina m) {
	printf("id masina: %d\n Nr. Locuri: %d\n capacitateC : %f\n Marca: %s\n Euro%c\n", m.id, m.nrLocuri, m.capacitateC, m.marca, m.normaPoluare);
}

void modifica_Atribut(struct Masina* m, int nrNou) {
	if (nrNou > 0) {
		m->nrLocuri = nrNou;
	}
}

void dezalocare(struct Masina* m) {
	free(m->marca);
	(*m).marca = NULL;
}

int main() {
	struct Masina masina =  initializare(1, 5, "Dacia", 1.5, '4'); //"4" '4' 
	afisare(masina);

	modifica_Atribut(&masina, 6);
	afisare(masina);

	dezalocare(&masina);
	afisare(masina);

	printf("%d\n", sizeof(struct Masina*));
	printf("%d", sizeof(masina));

	struct Masina* vector;
	int nrElem = 3;
	vector = (struct MAsina*)malloc(nrElem * sizeof(struct Masina));

	vector[0] = initializare(1, 3, "Dacia", 40, '5');
	vector[1] = initializare(2, 5, "Honda", 30, '6');
	vector[2] = initializare(3, 4, "Dacia", 50, '3');
	return 0;
}
