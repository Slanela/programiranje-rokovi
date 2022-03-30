#include <stdio.h>
#include <stdlib.h>

#define CRVENA 176 // deklarisanje konstanti za upotrebu kroz program
#define SIVA 177
#define BIJELA 178
#define CRNA 32

#define REDOVI 6 // deklarisanje dimenzija matrice u vidu konstanti //
#define KOLONE 6 // ovo se radi da bi vrijednost bila dostupna kroz sve funkcije //

void ispuni_uzorak(int matrix[REDOVI][KOLONE]); // prototip funkcije za ispunjavanje matrice uzorak
void ispis_matrice(int matrix[REDOVI][KOLONE]); // // prototip funkcije za ispis matrice pomocu u vidu karaktera
void zamijeni_element(int matrix[REDOVI][KOLONE], int a, int b, int x, int y); // prototip funkcije za zamjenu elemenata matrice
void ispis_matrice1(int matrix[6][6]); // prototip funkcije za ispis matrice u vidu karaktera
int suma_dijagonala(int matrix[6][6]); // prototip funkcije koja vraca sumu obje dijagonale proslijedjene matrice

int main(){
    int rand_num; // deklaracija varijable za upisivanje nasumicnih brojeva
    int uzorak[REDOVI][KOLONE];  // a) - deklaracija matrice "uzorak" 6x6
    int dijagonala[REDOVI][KOLONE]; // deklaracije matrice "dijagonala" 6x6

    srand(time(NULL)); /* zapocinje seed za generaciju novih random brojeva svaki put kad se pokrene program
    bez linije gore se svaki put generisu isti random brojevi */

    ispuni_uzorak(&uzorak[REDOVI][KOLONE]); // b) - funkcija za ispunjavanje matrice uzorak
    ispis_matrice(&uzorak[REDOVI][KOLONE]); // funkcija za ispis matrice uzorak

    printf("\n"); // odvaja jednu liniju prostora unutar konzole prilikom ispisa

    zamijeni_element(&uzorak[REDOVI][KOLONE], 1, 1, 4, 4); // funkcija koja zamjenjuje prosljedjene elemente po indeksima iz prosljedjene matrice
    zamijeni_element(&uzorak[REDOVI][KOLONE], 4, 1, 1, 4); // funkcija koja zamjenjuje prosljedjene elemente po indeksima iz prosljedjene matrice
    ispis_matrice(&uzorak[REDOVI][KOLONE]); // funkcija za ispis matrice uzorak

    printf("\n"); // odvaja jednu liniju prostora unutar konzole prilikom ispisa

    for(int i = 0; i < REDOVI; i++) // ispunjava matricu dijagonala sa nasumicnim brojevima izmedju 40 i 130
    {
        for(int j = 0; j < KOLONE; j++){
                dijagonala[i][j] = (rand() % 100 ) + 40; // u dijagonalu upisuje nasumicne brojeve
        }
    }
    ispis_matrice1(&dijagonala); // poziv funkcije koja ispisuje matricu dijagonala
    printf("Suma svih elemenata na glavnoj i sporednoj dijagonali matrice je %d", suma_dijagonala(dijagonala)); // ispis sume na dijagonalama

    printf("\n"); // odvaja jednu liniju prostora unutar konzole prilikom ispisa

    return 0;
}

void ispuni_uzorak(int matrix[REDOVI][KOLONE]){   /* b) - funkcija ispunjava matricu uzorak tako sto odredjuje granice matrice
    po indeksima redova i kolona matrice */
    for(int i = 0; i < REDOVI; i++){
        for(int j = 0; j < KOLONE; j++){
            if(i < 3 && j < 3){
                matrix[i][j] = CRVENA; // u gornji lijevi cosak upisi konstantu crvena
            } else if(i < 3 && j >= 3){
                matrix[i][j] = SIVA; // u gornji desni cosak upisi konstantu siva
            } else if(i >= 3 && j < 3){
                matrix[i][j] = BIJELA; //  u donji lijevi cosak upisi konstantu bijela
            } else if(i >= 3 && j >= 3){
                matrix[i][j] = CRNA; // u donji desni cosak upisi kontantu crna
            }
        }
    }
    // ne vraca nista
}

void ispis_matrice(int matrix[REDOVI][KOLONE]){   /* c) - ispisuje matricu u vidu karaktera tako sto se krece po indeksima redova i kolona matrice i ispisuje
    polje po polje */
    for(int i = 0; i < REDOVI; i++){
        for(int j = 0; j < KOLONE; j++){
            printf("%c", matrix[i][j]);
        }
        printf("\n"); // nakon svakog reda, napravi prelazak u novi red
    }
    // ne vraca nista
}

void zamijeni_element(int matrix[REDOVI][KOLONE], int a, int b, int x, int y){  /* d) - osnovni algoritam koji mijenja mjesta dva elementa u matrici
    ili bilo koje dvije varijable ako se malo izmijeni */
    int temp = matrix[a][b];
    matrix[a][b] = matrix[x][y];
    matrix[x][y] = temp;
    // ne vraca nista
}

void ispis_matrice1(int matrix[REDOVI][KOLONE]){ // ispisuje matricu u vidu brojeva
    int i,j;
      for( i = 0; i < REDOVI; i++){
        for( j = 0 ; j < KOLONE; j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n"); // razmak izmedju redova
      }
      // ne vraca nista
}
int suma_dijagonala(int matrix[6][6]){ // izdvaja elemente sa glavne i sporedne dijagonale matrice pomocu provjera if 1 i 2 te ih sabira i vraca njihov zbir
    int suma = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(i == j){ // 1 - glavna dijagonala
                suma = suma + matrix[i][j];
            }
            if( (i + j) == 5){ // 2 - sporedna dijagonala
                suma = suma + matrix[i][j];
            }
        }
    }
    return suma; // vraca zbir zato jer je funkcija int
}
