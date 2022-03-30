#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define UKUP_ISPIT 12       // a) ->

struct Student{
    char index[10];
    char ime[15];
    char prezime[20];
    int ispiti;
    float prosjek;
};
                        // a)

float moj_prosjek(struct Student BD); // c)
void ispis_str(struct Student BD); // d)

int main(){
        // a) ->
    struct Student BD;
    // a)

        // b) ->
    srand(time(NULL));
    int r_num = (rand()%UKUP_ISPIT);

    strcpy(BD.ime, "Boris");
    strcpy(BD.prezime, "Divkovic");
    strcpy(BD.index, "Index123");
    BD.ispiti = r_num;

    printf("Struktura BD je velicine %dB\n\n", sizeof(BD));
    // b)
        // c) ->
    //BD.prosjek = moj_prosjek(BD);
    //printf("Prosjek je %f\n\n", BD.prosjek);
    // c)
        // d) ->
    ispis_str(BD);
    //d)
        // e) ->
    printf("\n\n");
    char datoteka[40];
    char str1[15];
    char str2[20];
    char str3[35];
    strcpy(str1, BD.ime);
    strcpy(str2, BD.prezime);
    strcpy(str3, (strcat(str1, str2)));
    strcat(str3, ".txt");
    strcpy(datoteka, str3);
    // e)
        // f) ->
    FILE *dat_p;
    dat_p = fopen(datoteka, "w");
    if(dat_p == NULL){
        printf("\nDatoteka nije otvorena uspjesno.\n");
    } else {
        fprintf(dat_p, "Broj indeksa\tIme i prezime\tProsjek\t\tBroj ispita\n%s\t%s %s\t%f\t%d",
                        BD.index, BD.ime, BD.prezime, BD.prosjek, BD.ispiti);
        fseek(dat_p, 0L, SEEK_END);
        long int res = ftell(dat_p);
        printf("Datoteka je velicine %dB\n", res);
        fclose(dat_p);
    }
    // f)
    return 0;
}

float moj_prosjek(struct Student BD){
    float ocijena, suma_ocijena = 0;
    printf("Broj ispita za unijeti - %d\n", BD.ispiti);
    for(int i = 0; i < BD.ispiti; i++){
        do{
            printf("Unesite ocijenu sa %d. ispita -> ", i + 1);
            scanf("%f", &ocijena);
            if(ocijena < 6 || ocijena > 10){
                printf("\nGreska prilikom unosa - validan unos ocijena je 6 - 10\n");
            }
        }while(ocijena < 6 || ocijena > 10);
        suma_ocijena += ocijena;
    }
    return suma_ocijena/(float)BD.ispiti;
}
void ispis_str(struct Student BD){
    printf("Broj indeksa\tIme i prezime\tProsjek\t\tBroj ispita\n%s\t%s %s\t%f\t%d",
           BD.index, BD.ime, BD.prezime, BD.prosjek, BD.ispiti);
}
