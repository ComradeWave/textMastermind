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
	
}
int main(){
	int game[MAX];
	int gamecompare[MAX];
	casualitygenerator(game);
	gamestart();
	gameplayer(game, gamecompare);
	
	return 0;
}
