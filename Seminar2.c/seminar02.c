#include<stdio.h>
#include<malloc.h>

struct Masina {
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

void modifica_nrLocuri(struct Masina* m, int nrNou) {
	if (nrNou > 0) {
		m->nrLocuri = nrNou;
	}
}

void afisareVector(struct Masina* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisare(vector[i]);
	}
}

struct Masina* copiazaPrimeleMasini(struct Masina* vector, int nrElemente, int nrElementeCopiate) {
	//copiem intr-un vector nou pe care il vom returna primele nrElementeCopiate
	if (nrElementeCopiate > nrElemente)
		nrElementeCopiate = nrElemente;

	struct Masina* vectorNou = NULL;
	vectorNou = (struct Masina*)malloc(nrElementeCopiate * sizeof(struct Masina));

	for (int i = 0; i < nrElementeCopiate; i++) {
		vectorNou[i] = initializare(vector[i].id, vector[i].nrLocuri, vector[i].marca, vector[i].capacitateC, vector[i].normaPoluare);
	}
	return vectorNou;
}

void dezalocare(struct Masina** vector, int* nrElemente) {
	{
		for (int i = 0; i < nrElemente; i++) {
			free(vector[i].marca);
		}
	}
}

//void copiazaAnumiteElemente(struct Masina* vector, char nrElemente, float prag, struct Masina** vectorNou, int* dimensiune) {
//	parametrul prag poate fi modificat in functie de 
//	 tipul atributului ales pentru a indeplini o conditie
//	este creat un nou vector cu elementele care indeplinesc acea conditie
//}

//struct Masina getPrimulElementConditionat(struct Masina* vector, int nrElemente, const char* conditie) {
//	trebuie cautat elementul care indeplineste o conditie
//	dupa atributul de tip char*. Acesta este returnat.
//	struct Masina s;
//	s.id = 1;
//
//	return s;
//}



int main() {
	struct Masina* vector;
	int nrElem = 3;
	vector = (struct MAsina*)malloc(nrElem * sizeof(struct Masina));

	vector[0] = initializare(1, 3, "Dacia", 40, '5');
	vector[1] = initializare(2, 5, "Honda", 30, '6');
	vector[2] = initializare(3, 4, "Dacia", 50, '3');

	struct Masina* vectorMasiniCopiate;
	int nrElemCop = 2;
	vectorMasiniCopiate = copiazaPrimeleMasini(vector, nrElem, nrElemCop);
	afisareVector(vectorMasiniCopiate, nrElemCop);



	return 0;
}