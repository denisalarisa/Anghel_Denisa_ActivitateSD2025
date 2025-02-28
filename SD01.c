#include<stdio.h>
#include<stdlib.h>

struct Student {
	int id;
	int grupa;
	char* nume;
	float nota;


};

struct Student initializare_student(int id, int grupa, const char* nume, float nota) {
	struct Student s;
	s.id = id;
	s.grupa = grupa;
	s.nota = nota;
	s.nume = (char*)malloc(strlen(nume) + 1);
	strcpy_s(s.nume, strlen(nume) + 1, nume);

	return s;
}

void afisare_student(struct Student s) {
	printf("Id student= %d\n Nume= %s\n Grupa = %d\n Nota = %.2f\n", s.id, s.nume, s.grupa, s.nota);
}


void modifica_nota(struct Student* s, float notaNoua) {
	if (s != NULL) {
		s->nota = notaNoua;
	}

}

void dezalocare(struct Student* s) {
	free(s->nume);
	(*s).nume = NULL;

}


int main() {
	struct Student s = initializare_student(132456, 1053, "Anghel Denisa", 8.50);
	afisare_student(s);
	printf("\n");

	modifica_nota(&s, 9.21);
	afisare_student(s);
	printf("\n");

	dezalocare(&s);
	afisare_student(s);

	return 0;

}