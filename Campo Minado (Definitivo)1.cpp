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
	printf ("\n\n\t\t\t\t\t   O que voc� deseja fazer?");
	printf("\n\n\t\t\t\t    1- Jogar  2- Instru��es  3- Descri��o\n\n\t\t\t\t\t\t      ");
	scanf ("%d",&escolha);
	
	if (escolha == 1){
			
			if (escolha = 1){
			
		system ("cls");
		printf("\t\t\t\t\t\t Selecione o n�vel de dificuldade: \n\n\t\t 1-Iniciante (10X10)  2-Intermedi�rio (15X15)  3-Avan�ado (20X20)   4-Personalizado(?X?)\n\t\t\t\t\t\t\t\t");
		scanf("%d", &dificuldade);
		
		if (dificuldade == 1){
			
			TAM = 10;
			
		}else if (dificuldade == 2){
			
			TAM = 15;
			
		}else if (dificuldade == 3){
			
			TAM = 20;
			
		}else if(dificuldade == 4){
			
			printf("Digite o tamanho da matriz que voc� quer jogar (Digite o n�ero apenas umas vez: Ex.: 14)");
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
		printf ("\n\t\t\t\tBOOOMMMM!!!! Voc� explodiu uma mina! Boa sorte na pr�xima!");
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
		printf ("\n\n\tAqui v�o algumas instru��es para o jogo: Primeiramente, o que significa 'Campo Minado?' \n\n\tBom, o nome j� � bem sugestivo. � um campo que cont�m algumas minas terrestres nele. O \n\tobjetivo do nosso jogo � voc� descobrir todos os espa�os do campo sem 'pisar' em nenhuma mina. \n");	
		printf ("\n\tAo iniciar o jogo aparecer� um campo com v�rios asteriscos '*'. Esses asteriscos s�o os espa�os \n\tainda n�o abertos por voc�. Ao abrir cada espa�o, aparecer� algum n�mero entre 0 e 8. Esse n�mero \n\tindica a quantidade de bombas que est�o pr�ximas a casa que voc� abriu. Ao dizer 'pr�ximas', \n\tquero dizer que � o somat�rio das posi��es adjacentes � posi��o escolhida (cima, baixo, esquerda, \n\tdireita e diagonais)");
		printf ("\n\n\tComo fazer para abrir uma casa? Voc� ver� que a primeira linha e a �ltima coluna do campo \n\tn�o cont�m asteriscos, e sim n�meros. Voc� dever� se guiar por eles! Ser� solicitada uma coordenada \n\tpara a linha e uma coordenada para coluna. Ap�s preencher ambos os espa�os ser� revelado no \n\tcampo algum dos n�meros de 0 a 8.");
		printf ("\n\n\tComo voc� sabe que perdeu? Nem todas as casas que voc� escolher ser�o casas livres de bombas, \n\tat� porque uma campo minado possui bombas, n�o � mesmo? Ao escolher uma casa que possui uma \n\tbomba, o jogo ser� encerrado informando que voc� perdeu  e todas as bombas ser�o reveladas.");
		printf ("\n\n\tAgora voc� est� pronto para jogar!! Digite '1' e aperte 'enter' para iniciar o jogo:\t");
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
		printf ("\n\t\t\t\tBOOOMMMM!!!! Voc� explodiu uma mina! Boa sorte na pr�xima!");
		printarTabuleirofinal();	
		}else {
			printf("Comando incorreto!");
		}
		return 0;
}

int descricao(){
	int jogar,status_player;
	
	system("cls");
	
	printf ("\n\n\tAgora voc� est� pronto para jogar!! Digite '1' e aperte 'enter' para iniciar o jogo:\t");
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
		printf ("\n\t\t\t\tBOOOMMMM!!!! Voc� explodiu uma mina! Boa sorte na pr�xima!");
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
	
	int num_bombas = (int)((TAM*TAM)*0.3f); //Convers�o de float pra int (tirar a parte fracionaria)
	// Insere as bombas do tabuleiro
	while(num_bombas != 0) {
		//Sorteia um numero de 0 ~ (TAM-1)
		int x = rand()%TAM; //posi��o da bomba x na matriz
		int y = rand()%TAM; //posi��o da bomba y na matriz
		tabuleiro_escondido[x][y] = 1; // 1 � uma bomba!!
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
	
	//Mostra o espa�amento "-"
	for(i=0; i<TAM; i++){
		printf("---");
	}
	
	//Mostra o tabuleiro e o identificador de linha com espa�amento
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
	
	//Mostra o espa�amento "-"
	for(i=0; i<TAM; i++){
		printf("---");
	}
	printf("\n");
	
	//Mostra o tabuleiro e o identificador de linha com espa�amento
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
	// Confere as posi��es v�lidas
	do {
		printf("\n > Digite a coordenada da linha: ");
		scanf("%d", &linha);
		printf(" > Digite a coordenada da coluna: ");
		scanf("%d", &coluna);
		
		if(linha >= TAM || coluna >= TAM)
			printf(" > Coordenada inv�lida!\n");
		
	} while(linha >= TAM && coluna >= TAM);
	
	int num_bombas=0;
	//Verificar jogada
	if(tabuleiro_escondido[linha][coluna] == 1){
		return 0;
	}
	
	if(linha >= 1 && coluna >= 1 && linha <= TAM-1 && coluna <= TAM-1){ //Somat�rio das posi��es adjacentes elementos centrais
		
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
	
	if(coluna == TAM-1 && linha > 0  && linha < TAM-1 ){ //Somat�rio das posi��es adjacentes da �ltima coluna sem as quinas
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna-1] +  
		tabuleiro_escondido[linha-1][coluna] + 
		tabuleiro_escondido[linha-1][coluna-1] + 
		tabuleiro_escondido[linha+1][coluna] +
		tabuleiro_escondido[linha+1][coluna-1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(coluna == 0 && linha > 0  && linha < TAM-1 ){ //Somat�rio das posi��es adjacentes da primeira coluna sem as quinas
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna+1] +  
		tabuleiro_escondido[linha-1][coluna] + 
		tabuleiro_escondido[linha+1][coluna] + 
		tabuleiro_escondido[linha+1][coluna+1] +
		tabuleiro_escondido[linha-1][coluna+1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == 0 && coluna > 0  && coluna < TAM-1 ){ //Somat�rio das posi��es adjacentes da primeira linha sem as quinas
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna+1] +  
		tabuleiro_escondido[linha][coluna-1] + 
		tabuleiro_escondido[linha+1][coluna] + 
		tabuleiro_escondido[linha+1][coluna+1] +
		tabuleiro_escondido[linha+1][coluna-1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == TAM-1 && coluna > 0  && coluna < TAM-1 ){ //Somat�rio das posi��es adjacentes da �ltima linha sem as quinas
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna+1] +  
		tabuleiro_escondido[linha][coluna-1] + 
		tabuleiro_escondido[linha-1][coluna] + 
		tabuleiro_escondido[linha-1][coluna+1] +
		tabuleiro_escondido[linha-1][coluna-1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == 0 && coluna == 0 ){ //Somat�rio das posi��es adjacentes da quina esquerda de cima
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha+1][coluna] +  
		tabuleiro_escondido[linha][coluna+1] + 
		tabuleiro_escondido[linha+1][coluna+1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
		if(linha == 0 && coluna == TAM-1 ){ //Somat�rio das posi��es adjacentes da quina direita de cima
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha][coluna-1] +  
		tabuleiro_escondido[linha+1][coluna] + 
		tabuleiro_escondido[linha+1][coluna-1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == TAM-1 && coluna == 0 ){ //Somat�rio das posi��es adjacentes da quina esquerda de baixo
	
		num_bombas = 
		tabuleiro_escondido[linha][coluna] + 
		tabuleiro_escondido[linha-1][coluna] +  
		tabuleiro_escondido[linha][coluna+1] + 
		tabuleiro_escondido[linha-1][coluna+1];
		
		tabuleiro_mostrado[linha][coluna] = '0' + num_bombas;
	}
	
	if(linha == TAM-1 && coluna == TAM-1 ){ //Somat�rio das posi��es adjacentes da quina direita de baixo
	
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
	setlocale (LC_ALL, "portuguese");// Coloca s�mbolos da l�ngua portuguesa 
	
	tela_inicial();
	
	return 0;
}

	




