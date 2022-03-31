/*
    Boris Divkovic
    Komentarisan drugi zadatak sa prvog ispitnog roka osnova programiranja
    Sve trazene funkcionalnosti zadovoljene
    ! NAPOMENA: !
    a) ->
        oznacavaju izmedju kojih linija se nalaze zadaci
    a)
*/
#include <stdio.h> // osnovna biblioteka, potrebna za rad sa upisom i ispisom (printf, scanf..)
#include <stdlib.h> // osnovna biblioteka, preporuceno da se ubaci u svaki C projekat
#include <string.h> // biblioteka potrebna za rad sa stringovima jer sadrzi funkcije kao sto su strcpy, strcat itd.
#include <time.h> // biblioteka potrebna za generisanje 'seed-a' prilikom rada sa funkcijom za nasumicne brojeve,
                  // zavisi od kompajlera i biblioteke stdlib.h, preporucujem da ubacite u kod za svaki slucaj
#define UKUP_ISPIT 12       // a) -> definisanje konstante broja ukupnih ispita nekog studenta
                            // konstante su vrlo korisne jer su "vidljive" kroz citav kod
struct Student{ // deklaracija nove strukture student sa potrebnim podacima
    char index[10]; // niz karaktera
    char ime[15]; // niz karaktera
    char prezime[20]; // niz karaktera
    int ispiti; // broj ispita
    float prosjek; // prosjek ispita
};
        // a)

float moj_prosjek(struct Student BD); // c) - prototip funkcije za racunanje prosjeka ocijena instance strukture BD
void ispis_str(struct Student BD); // d) - prototip funkcije za ispis podataka iz instance strukture BD

int main(){
        // a) ->
    struct Student BD; // definisanje instance BD strukture Student.

    // ! NAZVATI INSTANCU STRUKTURE PO SVOJIM INICIJALIMA ! //

    // a)

        // b) ->
    srand(time(NULL)); // generise 'seed' koji svakim pokretanjem programa stvara nove random brojeve
    int r_num = (rand()%UKUP_ISPIT); // u varijablu r_num nakon deklaracije inicijalizira vrijednost da bude nasumicna izmedju 0 i 12

    strcpy(BD.ime, "Boris"); // unos imena u instancu BD strukture Student (varijabla ime)
    strcpy(BD.prezime, "Divkovic"); // unos prezimena u instancu BD strukture Student (varijabla prezime)
    strcpy(BD.index, "Index123"); // unos indexa u instancu BD strukture Student (varijabla index)
    BD.ispiti = r_num; // unos nasumicnog broja ispita sa linije 29 u instancu BD strukture Student (varijabla ispiti)

    printf("Struktura BD je velicine %dB\n\n", sizeof(BD)); // ispis velicine instance strukture pomocu sizeof(imeInstance);
    // b)
        // c) ->
    BD.prosjek = moj_prosjek(BD); // poziva funkciju koja trazi unos od strane korisnika i pohranjuje povratnu vrijednost u varijablu prosjek iz BD
    printf("Prosjek je %f\n\n", BD.prosjek); // ispisuje izracunati prosjek na osnovu unesenih ocijena
    // c)
        // d) ->
    ispis_str(BD); // poziva funkciju koja ispisuje sve podatke iz BD instance strukture Student
    //d)
        // e) -> // ! NAPOMENA ! - postoji laski nacin ali se na ovaj mnogo teze zbuniti i dobiti pogresan ispis (postepeni rad sa stringovima je preporucen)
        // u slucaju da dobijete trazeni string onda se mozete igrati sa strcpy i strcat unoseci vise parametara u funkcije //
        // ! pogledati dokumentaciju rada sa stringovima prije nego sto pokusate dobiti drugo rjesenje !
    printf("\n\n"); // odvaja dva nova reda
    char datoteka[40]; // pravi niz karaktera za unos naziva datoteke (trazeni format je ImePrezime.txt)
    char str1[15]; // definise prvi string u koji ce se ubaciti ime
    char str2[20]; // definise drugi string u koji ce se ubaciti prezime
    char str3[35]; // definise treci string u koji ce se spojiti ime i prezime i dodati ekstenzija da bi se dobio trazeni format
    strcpy(str1, BD.ime); // u string 1 pohranjuje ime (str1 = Boris)
    strcpy(str2, BD.prezime); // u string 2 pohranjuje prezime (str2 = Divkovic)
    strcpy(str3, (strcat(str1, str2))); // u string 3 pohranjuje ImePrezime (BorisDivkovic)
    strcat(str3, ".txt"); // na string tri dodaje ekstenziju .txt (BorisDivkovic.txt)
    strcpy(datoteka, str3); // varijabli datoteka dodjeljuje vrijednost stringa 3 (datoteka sada ima vrijednost BorisDivkovic.txt, te je pravilno imenovana)
    // e)
        // f) ->
    FILE *dat_p; // pravi pokazivac na FILE
    dat_p = fopen(datoteka, "w"); // pokazivacu dat_p daje vrijednost da li je napravljen file u koji se upisuje nesto (write mode)
    if(dat_p == NULL){ // ako je vrijednost pokazivaca NULL, znaci da file nije napravljen
        printf("\nDatoteka nije otvorena uspjesno.\n"); // u tom slucaju ispisuje poruku u kojoj je izrazena greska
    } else { // U SUPROTNOM
        fprintf(dat_p, "Broj indeksa\tIme i prezime\tProsjek\t\tBroj ispita\n%s\t%s %s\t%f\t%d",
                        BD.index, BD.ime, BD.prezime, BD.prosjek, BD.ispiti); // U datom formatu upisuje u datoteku vrijednosti varijabli iz BD instance
                                                                                                                                    // strukture Student
        fseek(dat_p, 0L, SEEK_END); // pocinje od pocetka datoteke, krece se kroz datoteku i broji mjesta u memoriji koja datoteka zauzima
        long int res = ftell(dat_p); // pohranjuje vrijednost velicine datoteke u byte-ima u novu varijablu 'res'
        printf("Datoteka je velicine %dB\n", res); // ispisuje taj rezultat koji je upisan u varijablu 'res'
        fclose(dat_p); // prekida konekciju sa datotekom nakon sto su svi procesi zavrseni - zatvara datoteku
    }
    // f)
    return 0; // prekida glavni dio programa nakon zavrsetka programa
}

float moj_prosjek(struct Student BD){ // funkcija koja racuna prosijek na osnovu broja ispita i unesenih ocijena
    float ocijena, suma_ocijena = 0; // deklaracija potrebnih varijabli
    printf("Broj ispita za unijeti - %d\n", BD.ispiti); // ispisuje koliki je nasumicno generisan broj ispita unesen u varijablu ispiti u instanci BD
    for(int i = 0; i < BD.ispiti; i++){ // for petlja koja ce za svaki ispit traziti da korisnik unese ocijenu
        do{
            printf("Unesite ocijenu sa %d. ispita -> ", i + 1); // ispis o kojem rednom broju ispita je rijec
            scanf("%f", &ocijena); // unos ocijene
            if(ocijena < 6 || ocijena > 10){ // provjera koja ne ispisuje gresku ako korisnik unese ocijenu manju od 6 ili vecu od 10 (5 se ne unosi u index)
                printf("\nGreska prilikom unosa - validan unos ocijena je 6 - 10\n");
            }
        }while(ocijena < 6 || ocijena > 10); // sve je unesena ocijena veca od 10 ili manja od 6, dodaj je na sumu ocijena
        suma_ocijena += ocijena;
    }
    return suma_ocijena/(float)BD.ispiti; // prosjek jednak je sumi ocijena podjeljenoj sa brojem ispita.
}
void ispis_str(struct Student BD){ // funkcija koja ispisuje strukturu u datom formatu
    printf("Broj indeksa\tIme i prezime\tProsjek\t\tBroj ispita\n%s\t%s %s\t%f\t%d",
           BD.index, BD.ime, BD.prezime, BD.prosjek, BD.ispiti);
           // nema potrebe za returnom, void funkcija samo obavlja neku radnju, ne mora vracati nikakav rezultat
}
