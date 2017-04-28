#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int glo_bomb;


int texto() {
printf("");       
printf("      .--.                               .-..-. _                 .-.      "); 
printf("     : .--'                              : `' ::_;                : :      "); 
printf("     : :    .--.  ,-.,-.,-..---.  .--.   : .. :.-.,-.,-. .--.   .-' : .--. "); 
printf("     : :__ ' .; ; : ,. ,. :: .; `' .; :  : :; :: :: ,. :' .; ; ' .; :' .; :"); 
printf("     `.__.'`.__,_;:_;:_;:_;: ._.'`.__.'  :_;:_;:_;:_;:_;`.__,_;`.__.'`.__.'"); 
printf("                           : :                                        ");      
printf("                           :_;                                    "); 
}



void carrega_matriz(int mat1[10][10]){

	int x, y, z = 1;

	for(y=0; y<10; y++){
		for(x=0; x<10; x++){
			mat1[x][y] = z;
			z++;
		}
	}
}

/* Funcao que imprime a matriz a cada tentativa, atualizando
os numeros ja digitados pelo usuario como bomba=B e nao-bomba=N */
void imprime_matriz(int mat2[10][10]){

	int a,b;

	for(b=0; b<10; b++){
		for(a=0; a<10; a++){
			if(((mat2[a][b]) < 10))
				printf(" %d ", mat2[a][b]);
			else if((mat2[a][b]) >= 10 && (mat2[a][b]) < 100)
				printf("%d ", mat2[a][b]);
			else if((mat2[a][b] == 100))
				printf("%d", mat2[a][b]);
			else if((mat2[a][b] == 101))
				printf(" N ");
			else if((mat2[a][b] == 201))
				printf(" B ");

		}
		printf("\n");
	}

}

// Funcao que verifica no vetor das bombas se um determinado valor tem bomba
int tem_bomba(int bombs, int vetr_bomb[10]){
	int result = 0, i;

	for(i=0; i<9; i++){
		if(vetr_bomb[i] == bombs)
			result = 1;
	}

	return result;
}

/* Funcao que modifica a matriz original, colocando B se for bomba e N se nao for bomba.
Update: Essa funcao tambem simula o Campo Minador real, que quando ao redor de um valor
nao tem bomba, ele completa com N esses valores ao redor tambem, alem do numero */
void explode(int mat3[10][10], int bomb, int vet_bomb[10]){

	if ((bomb <= 10) && (tem_bomba(bomb, vet_bomb))){ //se o valor escolhido pelo usuario for menor ou igual a 10, E nesse lugar existir uma bomba...
		mat3[(bomb-1)][0] = 201; //se tiver bomba, muda o valor da casa para 201, que na impressao sera mudado para B
		glo_bomb++; //incrementa o contador de bombas encontradas
	}
	else if ((bomb <= 10) && !(tem_bomba(bomb, vet_bomb))){ //se o valor escolhido pelo usuario for menor ou igual a 10, E nesse lugar NAO existir uma bomba...
		mat3[(bomb-1)][0] = 101; //se NAO tiver bomba, muda o valor da casa para 101, que na impressao sera mudado para N
		if(bomb == 1){ ////transforma em N os valores em volta, caso neles NAO exista bomba, para o canto da esquerda
                if(!(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[1][0] = 101;
                         mat3[0][1] = 101;
                         mat3[1][1] = 101;
                }
        }
        else if(bomb == 10){ //transforma em N os valores em volta, caso neles NAO exista bomba, para o canto da direita
             if(!(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         mat3[8][0] = 101;
                         mat3[8][1] = 101;
                         mat3[9][1] = 101;
                }
        }
        else{ ////transforma em N os valores em volta, caso neles NAO exista bomba, para todos outros entre 2 e 9
             if(!(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[(bomb-2)][0] = 101;
                         mat3[bomb][0] = 101;
                         mat3[(bomb-2)][1] = 101;
                         mat3[(bomb-1)][1] = 101;
                         mat3[bomb][1] = 101;
                }
        }
    }


	else if ((bomb >= 11) && (bomb <= 20) && (tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-11)][1] = 201;
		glo_bomb++;
	}
	else if ((bomb >= 11) && (bomb <= 20) && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-11)][1] = 101;
		if(bomb == 11){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[0][0] = 101;
                         mat3[1][0] = 101;
                         mat3[1][1] = 101;
                         mat3[0][2] = 101;
                         mat3[1][2] = 101;
                }
        }
        else if(bomb == 20){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         mat3[8][0] = 101;
                         mat3[9][0] = 101;
                         mat3[8][1] = 101;
                         mat3[8][2] = 101;
                         mat3[9][2] = 101;
                }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[(bomb-12)][0] = 101;
                         mat3[(bomb-11)][0] = 101;
                         mat3[(bomb-10)][0] = 101;
                         mat3[(bomb-12)][1] = 101;
                         mat3[(bomb-10)][1] = 101;
                         mat3[(bomb-12)][2] = 101;
                         mat3[(bomb-11)][2] = 101;
                         mat3[(bomb-10)][2] = 101;
                }
        }
    }

	else if ((bomb >= 21) && (bomb <= 30) && (tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-21)][2] = 201;
		glo_bomb++;
	}
	else if ((bomb >= 21) && (bomb <= 30)  && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-21)][2] = 101;
		if(bomb == 21){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[0][1] = 101;
                         mat3[1][1] = 101;
                         mat3[1][2] = 101;
                         mat3[0][3] = 101;
                         mat3[1][3] = 101;
                }
        }
        else if(bomb == 30){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         mat3[8][1] = 101;
                         mat3[9][1] = 101;
                         mat3[8][2] = 101;
                         mat3[8][3] = 101;
                         mat3[9][3] = 101;
                }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[(bomb-22)][1] = 101;
                         mat3[(bomb-21)][1] = 101;
                         mat3[(bomb-20)][1] = 101;
                         mat3[(bomb-22)][2] = 101;
                         mat3[(bomb-20)][2] = 101;
                         mat3[(bomb-22)][3] = 101;
                         mat3[(bomb-21)][3] = 101;
                         mat3[(bomb-20)][3] = 101;
                }
        }
    }


	else if ((bomb >= 31) && (bomb <= 40) && (tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-31)][3] = 201;
		glo_bomb++;
	}
	else if ((bomb >= 31) && (bomb <= 40) && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-31)][3] = 101;
		if(bomb == 31){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[0][2] = 101;
                         mat3[1][2] = 101;
                         mat3[1][3] = 101;
                         mat3[0][4] = 101;
                         mat3[1][4] = 101;
                }
        }
        else if(bomb == 40){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         mat3[8][2] = 101;
                         mat3[9][2] = 101;
                         mat3[8][3] = 101;
                         mat3[8][4] = 101;
                         mat3[9][4] = 101;
                }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[(bomb-32)][2] = 101;
                         mat3[(bomb-31)][2] = 101;
                         mat3[(bomb-30)][2] = 101;
                         mat3[(bomb-32)][3] = 101;
                         mat3[(bomb-30)][3] = 101;
                         mat3[(bomb-32)][4] = 101;
                         mat3[(bomb-31)][4] = 101;
                         mat3[(bomb-30)][4] = 101;
                }
        }
    }


	else if ((bomb >= 41) && (bomb <= 50) && (tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-41)][4] = 201;
		glo_bomb++;
	}
	else if ((bomb >= 41) && (bomb <= 50) && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-41)][4] = 101;
		if(bomb == 41){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[0][3] = 101;
                         mat3[1][3] = 101;
                         mat3[1][4] = 101;
                         mat3[0][5] = 101;
                         mat3[1][5] = 101;
                }
        }
        else if(bomb == 50){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         mat3[8][3] = 101;
                         mat3[9][3] = 101;
                         mat3[8][4] = 101;
                         mat3[8][5] = 101;
                         mat3[9][5] = 101;
                }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[(bomb-42)][3] = 101;
                         mat3[(bomb-41)][3] = 101;
                         mat3[(bomb-40)][3] = 101;
                         mat3[(bomb-42)][4] = 101;
                         mat3[(bomb-40)][4] = 101;
                         mat3[(bomb-42)][5] = 101;
                         mat3[(bomb-41)][5] = 101;
                         mat3[(bomb-40)][5] = 101;
                }
        }
    }


	else if ((bomb >= 51) && (bomb <= 60) && (tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-51)][5] = 201;
		glo_bomb++;
	}
	else if ((bomb >= 51) && (bomb <= 60) && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-51)][5] = 101;
		if(bomb == 51){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[0][4] = 101;
                         mat3[1][4] = 101;
                         mat3[1][5] = 101;
                         mat3[0][6] = 101;
                         mat3[1][6] = 101;
                }
        }
        else if(bomb == 60){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         mat3[8][4] = 101;
                         mat3[9][4] = 101;
                         mat3[8][5] = 101;
                         mat3[8][6] = 101;
                         mat3[9][6] = 101;
                }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[(bomb-52)][4] = 101;
                         mat3[(bomb-51)][4] = 101;
                         mat3[(bomb-50)][4] = 101;
                         mat3[(bomb-52)][5] = 101;
                         mat3[(bomb-50)][5] = 101;
                         mat3[(bomb-52)][6] = 101;
                         mat3[(bomb-51)][6] = 101;
                         mat3[(bomb-50)][6] = 101;
                }
        }
    }


	else if ((bomb >= 61) && (bomb <= 70) && (tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-61)][6] = 201;
		glo_bomb++;
	}
	else if ((bomb >= 61) && (bomb <= 70) && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-61)][6] = 101;
		if(bomb == 61){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[0][5] = 101;
                         mat3[1][5] = 101;
                         mat3[1][6] = 101;
                         mat3[0][7] = 101;
                         mat3[1][7] = 101;
                }
        }
        else if(bomb == 70){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         mat3[8][5] = 101;
                         mat3[9][5] = 101;
                         mat3[8][6] = 101;
                         mat3[8][7] = 101;
                         mat3[9][7] = 101;
                }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[(bomb-62)][5] = 101;
                         mat3[(bomb-61)][5] = 101;
                         mat3[(bomb-60)][5] = 101;
                         mat3[(bomb-62)][6] = 101;
                         mat3[(bomb-60)][6] = 101;
                         mat3[(bomb-62)][7] = 101;
                         mat3[(bomb-61)][7] = 101;
                         mat3[(bomb-60)][7] = 101;
                }
        }
    }


	else if ((bomb >= 71) && (bomb <= 80) && (tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-71)][7] = 201;
		glo_bomb++;
	}
	else if ((bomb >= 71) && (bomb <= 80) && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-71)][7] = 101;
		if(bomb == 71){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[0][6] = 101;
                         mat3[1][6] = 101;
                         mat3[1][7] = 101;
                         mat3[0][8] = 101;
                         mat3[1][8] = 101;
                }
        }
        else if(bomb == 80){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         mat3[8][6] = 101;
                         mat3[9][6] = 101;
                         mat3[8][7] = 101;
                         mat3[8][8] = 101;
                         mat3[9][8] = 101;
                }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[(bomb-72)][6] = 101;
                         mat3[(bomb-71)][6] = 101;
                         mat3[(bomb-70)][6] = 101;
                         mat3[(bomb-72)][7] = 101;
                         mat3[(bomb-70)][7] = 101;
                         mat3[(bomb-72)][8] = 101;
                         mat3[(bomb-71)][8] = 101;
                         mat3[(bomb-70)][8] = 101;
                }
        }
    }


	else if ((bomb >= 81) && (bomb <= 90) && (tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-81)][8] = 201;
		glo_bomb++;
	}
	else if ((bomb >= 81) && (bomb <= 90) && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-81)][8] = 101;
		if(bomb == 81){
                if(!(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[0][7] = 101;
                         mat3[1][7] = 101;
                         mat3[1][8] = 101;
                         mat3[0][9] = 101;
                         mat3[1][9] = 101;
                }
        }
        else if(bomb == 90){
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb))){
                         mat3[8][7] = 101;
                         mat3[9][7] = 101;
                         mat3[8][8] = 101;
                         mat3[8][9] = 101;
                         mat3[9][9] = 101;
                }
        }
        else{
             if(!(tem_bomba((bomb-11), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb+9), vet_bomb)) && !(tem_bomba((bomb+10), vet_bomb)) && !(tem_bomba((bomb+11), vet_bomb))){
                         mat3[(bomb-82)][7] = 101;
                         mat3[(bomb-81)][7] = 101;
                         mat3[(bomb-80)][7] = 101;
                         mat3[(bomb-82)][8] = 101;
                         mat3[(bomb-80)][8] = 101;
                         mat3[(bomb-82)][9] = 101;
                         mat3[(bomb-81)][9] = 101;
                         mat3[(bomb-80)][9] = 101;
                }
        }
    }


	else if ((bomb >= 91) && (bomb <= 100) && (tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-91)][9] = 201;
		glo_bomb++;
	}
	else if ((bomb >= 91) && (bomb <= 100) && !(tem_bomba(bomb, vet_bomb))){
		mat3[(bomb-91)][9] = 101;
		if(bomb == 91){
                if(!(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb))){
                         mat3[1][9] = 101;
                         mat3[0][8] = 101;
                         mat3[1][8] = 101;
                }
        }
        else if(bomb == 100){
             if(!(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-11), vet_bomb))){
                         mat3[8][9] = 101;
                         mat3[8][8] = 101;
                         mat3[9][8] = 101;
                }
        }
        else{
             if(!(tem_bomba((bomb-1), vet_bomb)) && !(tem_bomba((bomb+1), vet_bomb)) && !(tem_bomba((bomb-9), vet_bomb)) && !(tem_bomba((bomb-10), vet_bomb)) && !(tem_bomba((bomb-11), vet_bomb))){
                         mat3[(bomb-92)][9] = 101;
                         mat3[bomb-90][9] = 101;
                         mat3[(bomb-92)][8] = 101;
                         mat3[(bomb-91)][8] = 101;
                         mat3[bomb-90][8] = 101;
                }
        }
    }

}


int main(){
	int matriz[10][10];
	int op, bomba, i, tentativas = 1;
	int vetor_bombas[10];
	
	puts("");       
	puts("      .--.                               .-..-. _                 .-.      "); 
	puts("     : .--'                              : `' ::_;                : :      "); 
	puts("     : :    .--.  ,-.,-.,-..---.  .--.   : .. :.-.,-.,-. .--.   .-' : .--. "); 
	puts("     : :__ ' .; ; : ,. ,. :: .; `' .; :  : :; :: :: ,. :' .; ; ' .; :' .; :"); 
	puts("     `.__.'`.__,_;:_;:_;:_;: ._.'`.__.'  :_;:_;:_;:_;:_;`.__,_;`.__.'`.__.'"); 
	puts("                           : :                                        ");      
	puts("                           :_;                                    "); 

	printf("Bem-vindo ao jogo de Campo Minado em C\n\n\n");
	printf("O que voce deseja?\n\n1 - Jogar\n2 - Sair\n\n");
	scanf("%d", &op);

	if(op == 2){
		exit(1);
	}
	else{
		system("cls"); // Limpa a tela 

		// Vai iniciar e criar o vetor de valores aleatorios de onde serao colocadas as bombas
		srand(time(NULL));
		for(i=0; i<10; i++){
			vetor_bombas[i] = 1 + rand() % (100 - 1);
		}

		carrega_matriz(matriz); // Carrega a matriz original
		glo_bomb = 0;
		printf("Intrucoes de Jogo:\n\n");
		printf("\tVoce devera escolher um numero de 1 a 100 para desarmar as bombas.\n\tExistem 10 bombas espalhadas pelo cenario. Caso voce escolha um \n\tnumero de onde se encontra uma bomba, aparecera o simbolo B no lugar.\n\tCaso voce escolha um numero de onde nao ha bomba, \n\taparecera o simbolo N.\n\tO objetivo do jogo é encontrar as 10 bombas em ate 35 tentativas.\n\n\tUpdate: Simulando um jogo real de Campo Minado, caso voce escolha \n\tum valor que nao exista bomba e que em todos ao redor deles tambem \n\tnao exista bomba, todos sao trocados por N.\n\n\n");
		printf("Esta pronto para comecar o jogo?\n\n1 - Jogar\n2 - Sair\n\n");
		scanf("%d", &op);

		if(op == 2){
			exit(1);
		}
		else{
			while((tentativas <= 36) && (glo_bomb <= 9)){
				system("cls"); // Limpa a tela 
				imprime_matriz(matriz); // Imprime a matriz, ja com as alteracoes
				printf("\n\n\n");
				if(tentativas < 36)
					printf("Tentativa: %da\tBombas encontradas: %d\n\n\n\n", tentativas, glo_bomb);
				else if (tentativas == 36){
					printf("Tentativa: %da\tBombas encontradas: %d\n\n\n\n", (tentativas-1), glo_bomb);
					break;
				}
				printf("Qual numero voce deseja explodir?\n");
				scanf("%d", &bomba);
				explode(matriz, bomba, vetor_bombas); // Manda a matriz, o valor escolhido e o vetor de bombas para verificar se era um B ou um N
				tentativas++;
			}
			if(glo_bomb <=9)
				printf("Que pena, voce nao conseguiu. Tente de novo!\n\n");
			else if(glo_bomb==10)
				printf("Parabens! voce conseguiu!\n\n");
		}
	}
	system("pause");
	return 0;
}
