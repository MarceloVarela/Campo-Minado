#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define TAM 15
int status_player; //0 = perdeu, 1 = o jogo continua 
int tabuleiro_escondido[TAM][TAM];
char tabuleiro_mostrado[TAM][TAM];
//0 = nada, 1 = bomba

//Escorpo de funções (onde elas são definidas)
void initTabuleiro();
void printarTabuleiro();
int jogada();

int main() {
	system("TITLE Campo Minado BASICAO");
	setlocale (LC_ALL, "portuguese");
	srand((unsigned)time(NULL)); //Cria a semente do randomico 
	
	status_player = 1;
	initTabuleiro();
	
	while(status_player == 1){
		printarTabuleiro();
		status_player = jogada();
		system("cls");
	}
	
	return 0;
}

void initTabuleiro() {
	int i,j;
	for(i=0; i<TAM; i++) {
		for(j=0; j<TAM; j++) {
			tabuleiro_mostrado[i][j] = '*';
			tabuleiro_escondido[i][j] = 0;
		}
	}
	
	int num_bombas = (int)((TAM*TAM)*0.3f); //Conversão de float pra int (tirar a parte fracionaria)
	// Insere as bombas do tabuleiro
	while(num_bombas != 0) {
		//Sorteia um numero de 0 ~ (TAM-1)
		int x = rand()%TAM; //posição da bomba x na matrix
		int y = rand()%TAM; //posição da bomba y na matrix
		tabuleiro_escondido[x][y] = 1; // 1 é uma bomba!!
		num_bombas--;
	}
}

void printarTabuleiro() {
	int i,j,linha=0;
	printf("\n");
	
	//Mostra os identificadores da coluna
	for(i=0; i<TAM; i++){
		if(i<=10)
			printf("  %d", i);
		else
			printf(" %d", i);
	}
	printf("\n  ");
	
	//Mostra o espaçamento "-"
	for(i=0; i<TAM; i++){
		printf("---");
	}
	printf("\n");
	
	//Mostra o tabuleiro e o identificador de linha com espaçamento
	for(i=0; i<TAM; i++) {
		for(j=0; j<TAM; j++) {
			printf("  %c", tabuleiro_mostrado[i][j]);
			//printf("  %d", tabuleiro_escondido[i][j]);
		}
		printf(" | %d\n", linha); 
		linha++;
	}
}

int jogada() {
	int linha=0, coluna=0;
	// Confere as posições válidas
	do {
		printf("\n > Digite a coordenada da linha: ");
		scanf("%d", &linha);
		printf(" > Digite a coordenada da coluna: ");
		scanf("%d", &coluna);
		
		if(linha >= TAM && coluna >= TAM)
			printf(" > Coordenada inválida!\n");
		
	} while(linha >= TAM && coluna >= TAM);
	
	int num_bombas=0;
	//Verificar jogada
	if(tabuleiro_escondido[linha][coluna] == 1){
		return 0;
	}
	
	if(linha >= 1 && coluna >= 1 && linha <= TAM-1 && coluna <= TAM-1){
		//Somatório das posições adjacentes 
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna+1] + 
		tabuleiro_escondido[linha][coluna-1] + 
		tabuleiro_escondido[linha+1][coluna] + 
		tabuleiro_escondido[linha-1][coluna] + 
		tabuleiro_escondido[linha+1][coluna+1] +
		tabuleiro_escondido[linha-1][coluna-1] +
		tabuleiro_escondido[linha-1][coluna+1] +
		tabuleiro_escondido[linha+1][coluna-1];
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
		
	printf("\n%d\n", num_bombas);
	
	return 1;
}
