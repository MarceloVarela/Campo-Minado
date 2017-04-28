#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int TAM = 10;
int tela_inicial();
int instrucoes();
int descricao();
void initTabuleiro();
void printarTabuleirojogo();
void printarTabuleirofinal();
int jogada();

int tela_inicial() {
	int escolha, dificuldade,  matrizP, status_player; 
	
	printf ("\n\n\n\t\t\t\t\t\tCAMPO MINADO\n\n");
	printf ("\n\n\t\t\t\t\t   O que você deseja fazer?");
	printf("\n\n\t\t\t\t    1- Jogar  2- Instruções  3- Descrição\n\n\t\t\t\t\t\t      ");
	scanf ("%d",&escolha);
	
	if (escolha == 1){
			
			if (escolha = 1){
			
		system ("cls");
		printf("\t\t\t\t\t\t Selecione o nível de dificuldade: \n\n\t\t 1-Iniciante (10X10)  2-Intermediário (15X15)  3-Avançado (20X20)   4-Personalizado(?X?)\n\t\t\t\t\t\t\t\t");
		scanf("%d", &dificuldade);
		
		if (dificuldade == 1){
			
			TAM = 10;
			
		}else if (dificuldade == 2){
			
			TAM = 15;
			
		}else if (dificuldade == 3){
			
			TAM = 20;
			
		}else if(dificuldade == 4){
			
			printf("Digite o tamanho da matriz que você quer jogar (Digite o núero apenas umas vez: Ex.: 14)");
				scanf("%d", &matrizP);
				TAM == matrizP;
				
		}else{
			
			printf ("\nComando incorreto");	
			scanf("%d", &matrizP);
			
		}
			
		system ("cls");	
		
		srand((unsigned)time(NULL)); //Cria a semente do randomico
		
		
		status_player = 1;
		initTabuleiro();
		
		while(status_player == 1){
		printarTabuleirojogo();
		status_player = jogada();
		system ("cls");
		}
		system ("cls");
		printf ("\n\t\t\t\tBOOOMMMM!!!! Você explodiu uma mina! Boa sorte na próxima!");
		printarTabuleirofinal();	
	}
	
	}else if (escolha == 2){
		
		instrucoes();	
			
	}else if (escolha == 3){
		
		descricao();
		
	}
	return 0;
}


int instrucoes(){
	
	int jogar,status_player;
	
	system ("cls");
		printf ("\n\n\t\t\t\t\tBem vindo ao campo minado!!");
		printf ("\n\n\tAqui vão algumas instruções para o jogo: Primeiramente, o que significa 'Campo Minado?' \n\n\tBom, o nome já é bem sugestivo. É um campo que contém algumas minas terrestres nele. O \n\tobjetivo do nosso jogo é você descobrir todos os espaços do campo sem 'pisar' em nenhuma mina. \n");	
		printf ("\n\tAo iniciar o jogo aparecerá um campo com vários asteriscos '*'. Esses asteriscos são os espaços \n\tainda não abertos por você. Ao abrir cada espaço, aparecerá algum número entre 0 e 8. Esse número \n\tindica a quantidade de bombas que estão próximas a casa que você abriu. Ao dizer 'próximas', \n\tquero dizer que é o somatório das posições adjacentes à posição escolhida (cima, baixo, esquerda, \n\tdireita e diagonais)");
		printf ("\n\n\tComo fazer para abrir uma casa? Você verá que a primeira linha e a última coluna do campo \n\tnão contém asteriscos, e sim números. Você deverá se guiar por eles! Será solicitada uma coordenada \n\tpara a linha e uma coordenada para coluna. Após preencher ambos os espaços será revelado no \n\tcampo algum dos números de 0 a 8.");
		printf ("\n\n\tComo você sabe que perdeu? Nem todas as casas que você escolher serão casas livres de bombas, \n\taté porque uma campo minado possui bombas, não é mesmo? Ao escolher uma casa que possui uma \n\tbomba, o jogo será encerrado informando que você perdeu  e todas as bombas serão reveladas.");
		printf ("\n\n\tAgora você está pronto para jogar!! Digite '1' e aperte 'enter' para iniciar o jogo:\t");
		scanf ("%d", jogar);
		
		if (jogar == 1){
			system ("cls");	
	
		
		status_player = 1;
		initTabuleiro();
		
		while(status_player == 1){
		printarTabuleirojogo();
		status_player = jogada();
		system("cls");
		}
		system ("cls");
		printf ("\n\t\t\t\tBOOOMMMM!!!! Você explodiu uma mina! Boa sorte na próxima!");
		printarTabuleirofinal();	
		}else {
			printf("Comando incorreto!");
		}
		return 0;
}

int descricao(){
	int jogar,status_player;
	
	system("cls");
	
	printf ("\n\n\tAgora você está pronto para jogar!! Digite '1' e aperte 'enter' para iniciar o jogo:\t");
		scanf ("%d", jogar);
		
		if (jogar == 1){
			
			system ("cls");	
	
		initTabuleiro();
		status_player = 1;
		initTabuleiro();
		
		while(status_player == 1){
		printarTabuleirojogo();
		status_player = jogada();
		system("cls");
		}
		system ("cls");
		printf ("\n\t\t\t\tBOOOMMMM!!!! Você explodiu uma mina! Boa sorte na próxima!");
		printarTabuleirofinal();	
		}else {
			printf("Comando incorreto!");
		}
		return 0;
		
	
}

void initTabuleiro() {
	

	
	int i,j,tabuleiro_escondido[TAM][TAM],status_player;
	char tabuleiro_mostrado[TAM][TAM];
	
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
		int x = rand()%TAM; //posição da bomba x na matriz
		int y = rand()%TAM; //posição da bomba y na matriz
		tabuleiro_escondido[x][y] = 1; // 1 é uma bomba!!
		num_bombas--;
	}
}

void printarTabuleirojogo() {
	int i,j,tabuleiro_escondido[TAM][TAM],linha=0,status_player;
	char tabuleiro_mostrado[TAM][TAM];
	
	
	//Mostra os identificadores da coluna
	for(i=0; i<TAM; i++){
		if(i<=TAM)
			printf("  %d", i);
		else
			printf(" %d", i);
	}
	
	//Mostra o espaçamento "-"
	for(i=0; i<TAM; i++){
		printf("---");
	}
	
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

void printarTabuleirofinal() {
	int i,j,tabuleiro_escondido[TAM][TAM],linha=0,status_player;
	char tabuleiro_mostrado[TAM][TAM];
	
	printf("\n");
	
	//Mostra os identificadores da coluna
	for(i=0; i<TAM; i++){
		if(i<TAM)
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
			//printf("  %c", tabuleiro_mostrado[i][j]);
			printf("  %d", tabuleiro_escondido[i][j]);
		}
		printf(" | %d\n", linha); 
		linha++;
	}
}

int jogada() {
	int tabuleiro_escondido[TAM][TAM],linha=0,coluna=0,status_player;
	char tabuleiro_mostrado[TAM][TAM];
	// Confere as posições válidas
	do {
		printf("\n > Digite a coordenada da linha: ");
		scanf("%d", &linha);
		printf(" > Digite a coordenada da coluna: ");
		scanf("%d", &coluna);
		
		if(linha >= TAM || coluna >= TAM)
			printf(" > Coordenada inválida!\n");
		
	} while(linha >= TAM && coluna >= TAM);
	
	int num_bombas=0;
	//Verificar jogada
	if(tabuleiro_escondido[linha][coluna] == 1){
		return 0;
	}
	
	if(linha >= 1 && coluna >= 1 && linha <= TAM-1 && coluna <= TAM-1){ //Somatório das posições adjacentes elementos centrais
		
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
	
	if(coluna == TAM-1 && linha > 0  && linha < TAM-1 ){ //Somatório das posições adjacentes da última coluna sem as quinas
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna-1] +  
		tabuleiro_escondido[linha-1][coluna] + 
		tabuleiro_escondido[linha-1][coluna-1] + 
		tabuleiro_escondido[linha+1][coluna] +
		tabuleiro_escondido[linha+1][coluna-1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(coluna == 0 && linha > 0  && linha < TAM-1 ){ //Somatório das posições adjacentes da primeira coluna sem as quinas
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna+1] +  
		tabuleiro_escondido[linha-1][coluna] + 
		tabuleiro_escondido[linha+1][coluna] + 
		tabuleiro_escondido[linha+1][coluna+1] +
		tabuleiro_escondido[linha-1][coluna+1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == 0 && coluna > 0  && coluna < TAM-1 ){ //Somatório das posições adjacentes da primeira linha sem as quinas
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna+1] +  
		tabuleiro_escondido[linha][coluna-1] + 
		tabuleiro_escondido[linha+1][coluna] + 
		tabuleiro_escondido[linha+1][coluna+1] +
		tabuleiro_escondido[linha+1][coluna-1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == TAM-1 && coluna > 0  && coluna < TAM-1 ){ //Somatório das posições adjacentes da última linha sem as quinas
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna+1] +  
		tabuleiro_escondido[linha][coluna-1] + 
		tabuleiro_escondido[linha-1][coluna] + 
		tabuleiro_escondido[linha-1][coluna+1] +
		tabuleiro_escondido[linha-1][coluna-1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == 0 && coluna == 0 ){ //Somatório das posições adjacentes da quina esquerda de cima
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha+1][coluna] +  
		tabuleiro_escondido[linha][coluna+1] + 
		tabuleiro_escondido[linha+1][coluna+1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
		if(linha == 0 && coluna == TAM-1 ){ //Somatório das posições adjacentes da quina direita de cima
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna-1] +  
		tabuleiro_escondido[linha+1][coluna] + 
		tabuleiro_escondido[linha+1][coluna-1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == TAM-1 && coluna == 0 ){ //Somatório das posições adjacentes da quina esquerda de baixo
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha-1][coluna] +  
		tabuleiro_escondido[linha][coluna+1] + 
		tabuleiro_escondido[linha-1][coluna+1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == TAM-1 && coluna == TAM-1 ){ //Somatório das posições adjacentes da quina direita de baixo
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha-1][coluna] +  
		tabuleiro_escondido[linha][coluna-1] + 
		tabuleiro_escondido[linha-1][coluna-1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
		
	printf("\n%d\n", num_bombas);
	
	return 1;
}

int main() {
	
	system("TITLE Campo Minado v0.1");//Nome do jogo
	setlocale (LC_ALL, "portuguese");// Coloca símbolos da língua portuguesa 
	
	tela_inicial();
	
	return 0;
}

	




