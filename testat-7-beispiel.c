#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testat-7.h"
#include "testat-7-beispiel.h"

int cmp_studi_mnr(const void * p1, const void  * p2) {
	studi * pp1 = (studi *) p1, * pp2 = (studi *) p2;
	return pp1->matrikelNr - pp2->matrikelNr;
}

int cmp_studi_nn(const void * p1, const void  * p2) {
	studi * pp1 = (studi *) p1, * pp2 = (studi *) p2;
	return strcmp(pp1->nachname, pp2->nachname);
}

int cmp_studi_vn(const void * p1, const void  * p2) {
	studi * pp1 = (studi *) p1, * pp2 = (studi *) p2;
	return strcmp(pp1->vorname, pp2->vorname);
}

int cmp_int(const void * p1, const void  * p2) {
	int * pp1 = (int *) p1, * pp2 = (int *) p2;
	return *pp1 - *pp2;
}

void studi_print(char * filename, char * title) {
	studi s;
	FILE * f = fopen(filename, "r");
	printf("############\n%s %s\n", filename, title);
	if (f != NULL) {
		while (fread(&s, sizeof(s), 1, f) > 0)
			printf("%-32s %-32s %d\n", s.nachname, s.vorname, s.matrikelNr);
	}
	fclose(f);
}

int main() {
	studi s[] = {
		{"Otto", "Normalverbraucher", 12345},
		{"Erika", "Musterfrau", 34567},
		{"Lieschen", "Mueller", 23456},
		{"Max", "Mustermann", 45678}
	};
	int feld[] = {5,3,10,0,-2, 7, 9, 123};
	
	FILE * f;
	
	f = fopen("studi.db", "w");
	fwrite(s, sizeof(studi), sizeof (s) / sizeof(studi), f);
	fclose(f);

	f = fopen("int.db", "w");
	fwrite(feld, sizeof(int), sizeof (feld) / sizeof(int), f);
	fclose(f);

	fbsort("studi.db", sizeof(studi), cmp_studi_mnr);
	studi_print("studi.db", "nach Matrikelnummer");
	
	fbsort("studi.db", sizeof(studi), cmp_studi_nn);
	studi_print("studi.db", "nach Nachname");
	
	fbsort("studi.db", sizeof(studi), cmp_studi_vn);
	studi_print("studi.db", "nach Vorname");

	fbsort("int.db", sizeof(int), cmp_int);
	// ...
}
