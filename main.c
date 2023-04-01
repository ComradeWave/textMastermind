#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

 
#define MAX 4
void casualitygenerator(int game[]){
	int i;
	srand(time(NULL));
	for(i=0;i<MAX;i++){
		game[i]=rand() % 7;
		printf("%d DEBUG\n", game[i]);
	}
	return;
}

void gamestart(){ //manuale, regole del gioco
	printf("\nHai 10 tentativi per indovinare 4 numeri!\n");
	printf("\nEsempio: #1\t1, 2, 3, 4\t2p 1c\n");
	printf("\nP, C: Presente e Corretto\n");
	printf("\nBuona Fortuna!\n");	
	sleep(10);
	printf("\e[1;1H\e[2J");
	return;
}

void gameplayer(int game[], int gamecompare[]){ //qui avviene il gioco
	int trials=10;
	int i,j,o; //servizio
	int perfection=0,presence=0;
	do{
		printf("\nInserisci i dati: "); //da rimpiazzare
		for(o=0;o<MAX;o++) scanf("%d",&gamecompare[o]); //ottimizzato
		for(i=0;i<MAX;i++){
			for(j=0;j<MAX;j++){
				if(game[i]==gamecompare[j]){
					presence++;
					if(i==j){
						perfection++;
					}else if(perfection>0){
						perfection--;
					}
				}else if(presence>0){
					presence--;
				}
			}
		}
		printf("\n#%d\t%d %d %d %d\tP:%d C:%d",trials,gamecompare[0],gamecompare[1],gamecompare[2],gamecompare[3],presence,perfection);
		trials--;
	}while(trials!=0);
}
int main(){
	int game[MAX];
	int gamecompare[MAX];
	casualitygenerator(game);
	gamestart();
	gameplayer(game, gamecompare);
	
	return 0;
}
