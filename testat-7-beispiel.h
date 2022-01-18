#ifndef testat_7_beispiel
#define testat_7_beispiel 1

// alles vorgegeben

typedef struct  {
    char vorname[30];
	char nachname[30];
	unsigned int matrikelNr;
} studi ;

typedef struct {
	int x;
	int y;
	int z;
} vector3;

int cmp_vector3_x(const void* p1, const void* p2);
int cmp_vector3_y(const void* p1, const void* p2);
int cmp_vector3_z(const void* p1, const void* p2);
void vector3_print(char* filename, char* title);

int cmp_studi_nn(const void * p1, const void  * p2);
int cmp_studi_vn(const void * p1, const void  * p2);
int cmp_studi_mnr(const void * p1, const void  * p2);
void studi_print(char * filename, char * title);

int cmp_int(const void * p1, const void  * p2);
void int_print(char* filename, char* title);

#endif
