#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int tela_inicial();
int instrucoes();
int descricao();
void initTabuleiro();
void printarTabuleirojogo();
void printarTabuleirofinal();
int jogada();
int main();

int tela_inicial() {
	int TAM,escolha, dificuldade,  matrizP, jogar, status_player, Inicio=0,reviver; 
	
	printf ("\n\n\n\t\t\t\t\t\tCAMPO MINADO\n\n");
	printf ("\n\n\t\t\t\t\t   O que você deseja fazer?");
	printf("\n\n\t\t\t\t    1- Jogar  2- Instruções  3- Descrição\n\n\t\t\t\t\t\t      ");
	
		do {
			scanf ("%d",&escolha);
		
			if(escolha < 1 || escolha > 3){
			printf ("\n\tCódigo inválido. Por favor digite novamente: ");
			}			
		} while (escolha < 1 || escolha > 3);
	
	if (escolha == 1){
			
		if (escolha == 1){
			
		system ("cls");
		printf("\n\n\t\t\t\t\t\t Selecione o nível de dificuldade: \n\n\t\t 1-Iniciante (10X10)  2-Intermediário (15X15)  3-Avançado (20X20)   4-Personalizado(?X?)\n\n\n\t\t\t\t\t\t\t  ");
		
		do{
		scanf("%d", &dificuldade);
		
		if (dificuldade == 1){
			
			TAM = 10;
			
		}else if (dificuldade == 2){
			
			TAM = 15;
			
		}else if (dificuldade == 3){
			
			TAM = 20;
			
		}else if(dificuldade == 4){
			
			system ("cls");
			printf("\n\n\t  Digite o tamanho da Campo que você quer jogar (Digite o número apenas uma vez: Ex.: 14. \n\tE que seja entre 2 e 30):  \t");
			do{
				scanf("%d", &matrizP);
				
				if (matrizP < 2 ){
				printf ("\n   Campo muito pequeno. Informe outro valor maior!:\t");
				}
				if (matrizP > 30){
				printf("\n   Campo muito grande. Informe outro valor menor!:\t");
				}
				
			} while (matrizP < 2 || matrizP > 30);
				
				TAM = matrizP;
		}
		if (dificuldade < 1 || dificuldade > 4){
			printf ("\n\tCódigo inválido. Por favor digite novamente: ");
		}
		} while (dificuldade < 1 || dificuldade > 4);	
		
		int tabuleiro_escondido[TAM][TAM];
		char tabuleiro_mostrado[TAM][TAM];
			
		system ("cls");	
	
		status_player = 1;
		
		while(status_player == 1){
		system("cls");
		if(Inicio==0){
		initTabuleiro(TAM, tabuleiro_escondido, tabuleiro_mostrado);
		Inicio++;
		}
		printarTabuleirojogo(TAM, tabuleiro_escondido, tabuleiro_mostrado);
		status_player = jogada(TAM,status_player, tabuleiro_escondido, tabuleiro_mostrado);
		}
		if (status_player == 2){
			system("cls");
			printf ("\n\t\t\tPARABÉNSSSS!!!!!! Você Venceu! Digite '1' e aperte 'enter' para jogar novamente");
		do {
			scanf ("%d",&reviver);
			if (reviver == 1){
				system ("cls");
				tela_inicial();
			}
		
			if(reviver < 1 || reviver > 1){
			printf ("\n\tCódigo inválido. Por favor digite novamente: ");
			}	
		} while (reviver < 1 || reviver > 1);
	}
		
		system ("cls");
		printf ("\n\t\t\tBOOOMMMM!!!! Você explodiu uma mina!\n\n");
		printarTabuleirofinal(TAM,tabuleiro_escondido,tabuleiro_mostrado);	
		printf ("\n\n  Não desanime! Você pode jogar novamente digitando '1' e apertando em 'enter'. Boa sorte na próxima tentativa!  ");
		do {
			scanf ("%d",&reviver);
			if (reviver == 1){
				system ("cls");
				tela_inicial();
			}
		
			if(reviver < 1 || reviver > 1){
			printf ("\n\tCódigo inválido. Por favor digite novamente: ");
			}	
		} while (reviver < 1 || reviver > 1);
	}
	
	}else if (escolha == 2){
		
		instrucoes();	
			
	}else if (escolha == 3){
		
		descricao();
		
	}
	return 0;
}

int instrucoes(){
	
	int jogar;
	
	system ("cls");
		printf ("\n\n\t\t\t\t\tBem vindo ao campo minado!!");
		printf ("\n\n\tAqui vão algumas instruções para o jogo: Primeiramente, o que significa 'Campo Minado?' \n\n\tBom, o nome já é bem sugestivo. É um campo que contém algumas minas terrestres nele. O \n\tobjetivo do nosso jogo é você descobrir todos os espaços do campo sem 'pisar' em nenhuma mina. \n");	
		printf ("\n\tAo iniciar o jogo aparecerá um campo com vários asteriscos '*'. Esses asteriscos são os espaços \n\tainda não abertos por você. Ao abrir cada espaço, aparecerá algum número entre 0 e 8. Esse número \n\tindica a quantidade de bombas que estão próximas a casa que você abriu. Ao dizer 'próximas', \n\tquero dizer que é o somatório das posições adjacentes à posição escolhida (cima, baixo, esquerda, \n\tdireita e diagonais)");
		printf ("\n\n\tComo fazer para abrir uma casa? Você verá que a primeira linha e a última coluna do campo \n\tnão contém asteriscos, e sim números. Você deverá se guiar por eles! Será solicitada uma coordenada \n\tpara a linha e uma coordenada para coluna. Após preencher ambos os espaços será revelado no \n\tcampo escolhido algum dos números de 0 a 8.");
		printf ("\n\n\tComo você sabe que perdeu? Nem todas as casas que você escolher serão casas livres de bombas, \n\taté porque uma campo minado possui bombas, não é mesmo? Ao escolher uma casa que possui uma \n\tbomba, o jogo será encerrado informando que você perdeu  e todas as bombas serão reveladas, sendo \n\t'0' os espaços vazios e '1' o lugar onde havia mina.");
		printf ("\n\n\tAgora você está pronto para jogar!! Digite '1' e aperte 'enter' para voltar ao menu para iniciar o jogo:\n\n\t\t\t\t\t\t\t  ");
	
		do {
			scanf ("%d",&jogar);
		
			if (jogar == 1){
			system ("cls");	
	
			tela_inicial();
			}
		
			if(jogar < 1 || jogar > 1){
			printf ("\n\tCódigo inválido. Por favor digite novamente: ");
			}
						
		} while (jogar < 1 || jogar > 1);
	

		
		
		
}

int descricao(){
	int jogar;
	
	system("cls");
	
	printf("\n\n\t\t\t\t\t\t\tOlá jogador!\n\n\tNós somos da primeira turma do curso de Engenharia Química da Faculdade de Tecnologia SENAI CIMATEC. \n\tA equipe é composta pelos seguintes alunos: Andresa Oliveira Tavares Lima, Catarina Bortoloto França \n\tFerracini, Iago Pereira Fernandes Santos e Luca Morais Costa. A equipe está envolvida na realização \n\tde um projeto acadêmico com o objetivo de projetar um campo minado, com o auxílio do professor e orientador \n\tMárcio Soussa designada à matéria de Introdução à Lógica de Programação.");
	printf ("\n\n\tAgora você está pronto para jogar!! Digite '1' e aperte 'enter' para voltar ao menu para iniciar o jogo:\n\n\t\t\t\t\t\t\t  ");
	
		do {
			scanf ("%d",&jogar);
		
			if (jogar == 1){
			system ("cls");	
	
			tela_inicial();
			}
		
			if(jogar < 1 || jogar > 1){
			printf ("\n\tCódigo inválido. Por favor digite novamente: ");
			}
						
		} while (jogar < 1 || jogar > 1);
	
}

void initTabuleiro(int TAM, int tabuleiro_escondido[TAM][TAM], char tabuleiro_mostrado[TAM][TAM]) {
	
	srand((unsigned)time(NULL)); //Cria a semente do randômico
	
	int i,j;
	
	for(i=0; i<TAM; i++) {
		for(j=0; j<TAM; j++) {
			tabuleiro_mostrado[i][j] = '*';
			tabuleiro_escondido[i][j] = 0;
		}
	}
	
	int num_bombas = (int)((TAM*TAM)*0.3); //Conversão de float pra int (tirar a parte fracionaria)
	// Insere as bombas do tabuleiro
	while(num_bombas != 0) {
		//Sorteia um numero de 0 ~ (TAM-1)
		int x = rand()%TAM; //posição da bomba x na matriz
		int y = rand()%TAM; //posição da bomba y na matriz
		if (tabuleiro_escondido[x][y] == 1){
			continue;
		}
		tabuleiro_escondido[x][y] = 1; // 1 é uma bomba!!
		num_bombas--;
	}
}

void printarTabuleirojogo(int TAM, int tabuleiro_escondido[TAM][TAM], char tabuleiro_mostrado[TAM][TAM]){
	int i,j,linha=0,status_player;
	
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

void printarTabuleirofinal(int TAM, int tabuleiro_escondido[TAM][TAM], char tabuleiro_mostrado[TAM][TAM]) {
	int i,j,linha=0,status_player;
	
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
			//printf("  %c", tabuleiro_mostrado[i][j]);
			printf("  %d", tabuleiro_escondido[i][j]);
		}
		printf(" | %d\n", linha); 
		linha++;
	}
}

int jogada(int TAM,int status_player,int tabuleiro_escondido[TAM][TAM],char tabuleiro_mostrado[TAM][TAM]) {
	int linha=0,coluna=0,sem_bombas=0;
	
	// Confere as posições válidas
	do {
		printf("\n > Digite a coordenada da linha: ");
		scanf("%d", &linha);
		printf(" > Digite a coordenada da coluna: ");
		scanf("%d", &coluna);
		
		if(linha >= TAM || coluna >= TAM)
			printf(" > Coordenada inválida!\n");
		sem_bombas++;	
	} while(linha >= TAM || coluna >= TAM);
	
	if(sem_bombas == (int)((TAM*TAM)*0.7)){
		status_player = 2;
	}
	
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

	
