#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#define DIM_SEQ 4
#define NUM_MAX 6
#define NUM_TENTATIVI 10
#define CHEAT 0 //DISATTIVATO PER DEFAULT


void gameins(int seq_generata[]){
  int pos_esatta, //numeri in posizione esatta
    presenti, //numeri presenti nella sequenza in qualsiasi posizione
    i,
    input[DIM_SEQ], //input utente
    tentativi = 0, //numero tentativo corrente
    conta_numeri[NUM_MAX], // ↓ ma che viene modificato durante l'iterazione
    conta_numeri2[NUM_MAX]; //conta del numero di occorrenze dei numeri possibili
    _Bool vinto = false, ignora;

    for (i = 0; i < NUM_MAX; i++)
        conta_numeri2[i] = 0; // inizializza array conta numeri

    for (i = 0; i < DIM_SEQ; i++)
        conta_numeri2[seq_generata[i] - 1]++; // conta numeri

    do {
        memcpy(conta_numeri, conta_numeri2, sizeof(int) * NUM_MAX); // copia conta numeri persistente nell'array che viene modificato
        pos_esatta = 0; // azzera variabili
        presenti = 0;
        ignora = false;

        printf("Tentativo %d\n"
               "Inserisci la sequenza: ", tentativi  + 1);
        for (i = 0; i < DIM_SEQ; i++)
            scanf("%d", &input[i]); // leggi input

        for (i = 0; i < DIM_SEQ; i++) { // Itera sull'input utente
            if (input[i] < 1 || input[i] > NUM_MAX) {
                printf("Numero non valido! Sequenza ignorata\n");
                ignora = true;
                break;
            }
            if (seq_generata[i] == input[i])  // Compara val i-esimo input utente con val i-esimo della sequenza generata, se sono uguali allora è in posizione esatta
                pos_esatta++;
            if (conta_numeri[input[i] - 1] > 0) { // Controlla se il valore i-esimo inserito dall'utente ha una conta non nulla
                presenti++; // Conta numero presente
                conta_numeri[input[i] - 1]--; // Decrementa conta del valore presente
            }
        }
        if (!ignora) {
            printf("%d numeri presenti di cui %d in posizione esatta\n", presenti, pos_esatta);
            tentativi++;
        }

        if (pos_esatta == DIM_SEQ) {
            printf("Hai vinto!\n");
            vinto = true;
            sleep(5);
        }
    } while (!vinto && tentativi < NUM_TENTATIVI);
    if (!vinto)
        printf("Tentativi esauriti!\n");

}

void genera_seq(int game[]){ //Crea numeri casuali
  int i;
  for(i = 0; i < DIM_SEQ; i++){
    game[i] = (rand() % NUM_MAX) + 1;
  }
}

void gioco(){ //manuale, regole del gioco
  printf("Hai %d tentativi per indovinare la sequenza corretta!\n", NUM_TENTATIVI);
  printf("Esempio: 1, 2, 3, 4\n");
//  printf("\nP, C: Presente e Corretto\n");
  printf("Buona Fortuna!\n");
  sleep(3);
  printf("\e[1;1H\e[2J"); //REGEX
}

int main(){
    srand(time(NULL));
  int seq_generata[DIM_SEQ]; //array dove ci sono i numeri casuali
    genera_seq(seq_generata);
    if (CHEAT) {
        for (int i = 0; i < DIM_SEQ; i++) { //debug
            setbuf(stdout, 0);
            printf("%d ", seq_generata[i]);
        }
        printf("\n---\n");
    }
    gioco();
  gameins(seq_generata);

  return 0;
}
