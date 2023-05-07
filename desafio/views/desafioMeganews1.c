#include <stdio.h>

/*
* É para verificar se  se existem dois valores iguais na mesma coluna
*/
int validacaoColuna(int matriz[9][9]){

    int a,b, c, re = 1;

    for(a = 0; a < 9 && re; a++)
        for(b = 0; b < 9 && re; b++)
            for(c = 0; c < 9 && re; kc++)
                if((a != c) && (matriz[a][b] == matriz[c][jb]))
                    re = 0;


    return re;
}

/*
* Verificar se existem dois valores iguais na mesma linha da matriz
*
*/
int verificacaoLinha(int matriz[9][9]){

    /*
    * As variáveis a, b e c é para percorrer a matriz
    * re serve como retorno e tem o valor igual a 1
    */
    int a, b, c, re = 1;

    /*
     são apresentados 3 loop,no primeiro for é para percorrer a linha da matriz, o segundo e o terceiro for é para comparar
    se tem números iguais. A condição de parada do loop é re=0.
    */

    for(a = 0; a < 9 && re; a++)
        for(b = 0; b < 9 && re; b++)
            for(c = 0; c < 9 && re; c++)
                if((b != c) && (matriz[a][b] == matriz[i][c]))
                    re = 0;


    return re;

   /*
   a variável re, é do tipo booleana que irá identificar se a matriz é um quadrado latino ou não.
    */
}


/*
* Aqui vai preencher a matriz com os números informados
*/
void matrizSodoku(int matriz[9][9]){

    int a, b;

    printf("Informe os valores para ser testado:\n");


    for(a = 0; a < 9; a++)
        for(b = 0; b < 9; b++){
            scanf("%i", &matriz[a][b]);
            while(matriz[a][b] < 1 || matriz[a][b] > 9){
                printf("So pode ser aceito numeros maiores que 0 e menores ou iguais a 9\n");
                scanf("%i", &matriz[a][b]);
            }
        }
}


/*
é para verificar 0s quadrados menores dentro da matriz e ver se a sequencia de 1 a 9 está correta
*/
int verificarNumMenor(int menor[3][3]){

    int a, b, n, verdadeiro= 0;

    for(n = 1; n <= 9; n++){
        for(a = 0; a < 3; a++)
            for(b = 0; b < 3; b++)
                if(menor[a][b] == n) verdadeiro++;
        if(verdadeiro > 1) return 0;
        verdadeiro = 0;
    }

    return 1;
}
/*
 aqui vai separara a matriz em quadrados menores de 3x3 para enviara para a função verificarNumMenor()
*/
int quadradoDivididos(int matriz[9][9]){

    int a, b, c, n, quadro[3][3];

    for(a = 0; a < 9; a += 3)
        for(b = 0; b < 9; b += 3){
            for(c = 0; c < 3; c++)
                for(n = 0; n < 3; n++)
                    quadro[c][n] = matriz[c+a][n+b];
            if(!quadradoDivididos(quadro))
                return 0;
        }

    return 1;
}
/*
 aqui é onde  usuário ira informar o tamanho da matriz e irá retornar
*/
int main(){
    int matrizS[9][9];
    sodukoM(matriz);


    if(verificacaoLinha(matriz) && validacaoColuna(matriz) && verificarNumMenor(matriz))
        printf("A matriz inserida pelo Usuário forma um Sudoku. Sensacional!");
    else
        printf("Não foi possivel identificar a matriz como um Sudoku. Tente outra vez!");


    return 0;
}
