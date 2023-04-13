#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#define MAX 4


bool gamecontrol(int *perfection, int *presence, int game[], int gamecompare[], int trials){
	int x, y; //servizio
	for(x=0;x<MAX;x++){
		for(y=0;y<MAX;y++){
			if(gamecompare[y]==game[x]){ //controllo VALORE degli array per determinare la presenza
				*presence=*presence+1;
				//printf("%d DBEUGGY\n", *presence);
				if(x==y){
					*perfection=*presence+1; //posizione e valore uguale
				//	printf("%d DBEUGGYA\n", *perfection);				
				}
			}
		}
	}
	if(*perfection==MAX){
		return 1;
	}else{
		printf("#%d\t\t%d\t%d\t%d\t%d \t Numeri Presenti: %d Numeri corretti: %d\n", trials, gamecompare[0], gamecompare[1], gamecompare[2], gamecompare[3], presence, perfection);
		return 0;
	}
}



bool gameins(int game[], int gamecompare[], int trials){
	int index; //servizio
	int perfection=0,presence=0;
	bool error=false;
	do{
		printf("\nInserisci i numeri: "); 
		scanf("%d %d %d %d", &gamecompare[0], &gamecompare[1], &gamecompare[2], &gamecompare[3]);
		for(index=0;index<MAX;index++){
			if(gamecompare[index]<1 || gamecompare[index]>6){
				printf("INPUT ERRATO\n");
				error=true;
			}else{
				error=false;
			}
		}
	}while(error==true);
	if(gamecontrol(&perfection, &presence, game, gamecompare, trials)==true){
		return 1;
	}else{
		return 0;
	}
	
}

void casualitygenerator(int game[]){ //Crea numeri casuali
	int i;
	srand(time(NULL));
	for(i=0;i<MAX;i++){
		game[i]=rand() % 6+1;
		printf("%d DEBUG\n", game[i]);
	}
	return;
}

void gamestart(){ //manuale, regole del gioco
	printf("\nHai 10 tentativi per indovinare 4 numeri!\n");
	printf("\nEsempio: #1\t1, 2, 3, 4");
//	printf("\nP, C: Presente e Corretto\n");
	printf("\nBuona Fortuna!\n");	
	sleep(3);
	printf("\e[1;1H\e[2J"); //REGEX
	return;
}

void gameplayer(int game[], int gamecompare[]){ //qui starta il gioco
	int trials=10;
	
	
	do{
		
			
		if(gameins(game, gamecompare, trials)==true){
			printf("HAI VINTOOO!\n");
			return;
		}
		
		trials--;
	}while(trials!=0);
}
int main(){
	int game[MAX]; //array dove ci sono i numeri casuali
	int gamecompare[MAX]; //dove il player mette i numeri
	casualitygenerator(game);
	gamestart();
	gameplayer(game, gamecompare);
	
	return 0;
}
