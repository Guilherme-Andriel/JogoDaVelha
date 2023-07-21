#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printfDoJogo(int **jogo)
{
  printf("\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (jogo[i][j] == 'X')
      {
        printf("X ");
      }
      else if (jogo[i][j] == 'O')
      {
        printf("O ");
      }
      else
      {
        printf("%d ", jogo[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

int logica(int **jogo, int caracter)
{
  for (int i = 0; i < 3; i++)
  {
    if (jogo[i][0] == caracter && jogo[i][1] == caracter &&
        jogo[i][2] == caracter)
    {
      /* Nessa condição é feito a verificação horizontral (linha), se cada
       * posição é igual a 'X'. O "i" varia de 0 a 2 (sendo a linha) e a coluna
       * fica fixa sendo 0, 1, 2 para cada repetição */

      return 1; // Retorna 1 em caso de vitória do usuário
    }
    if (jogo[0][i] == caracter && jogo[1][i] == caracter &&
        jogo[2][i] == caracter)
    {
      /* Nessa outra condição é feito a verificação vertical(coluna) se cada
       * posição é igual a 'X'. O "i" varia de 0 a 2 (sendo a coluna) e a linha
       * fica fixa sendo 0, 1, 2 para cada repetição */

      return 1; // Retorna 1 em caso de vitória do usuário
    }
  }

  /*Já essas duas condições é para as duas diagonais: */
  if (jogo[0][0] == caracter && jogo[1][1] == caracter &&
      jogo[2][2] == caracter)
  {
    return 1; // Retorna 1 em caso de vitória do usuário
  }
  if (jogo[0][2] == caracter && jogo[1][1] == caracter &&
      jogo[2][0] == caracter)
  {
    return 1; // Retorna 1 em caso de vitória do usuário
  }

  return 0;
}

void Computador(int **jogo)
{
  int linha, coluna;
  do
  {
    linha = rand() % 3;  // Valor aleatório de linha entre 0 e 2
    coluna = rand() % 3; // Valor aleatório de coluna entre 0 e 2

  } while (jogo[linha][coluna] == 'X' ||
           jogo[linha][coluna] ==
               'O'); // A repetição continua até ter uma posição em que não
                     // tenha o valor 'X' ou 'O' ocupada.

  jogo[linha][coluna] = 'O'; // Adiciona 'O' em uma posição válida
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  int **jogo; // Declara um ponteiro para ponteiros de inteiros

  jogo = malloc(3 * sizeof(int *)); // alocando espaço para um array de 3 ponteiros de inteiros e atribuindo esse endereço ao ponteiro jogo

  for (int i = 0; i < 3; i++)
  { // percorrer cada posição dos 3 ponteiros, e pra cada posição será alocado um espaço para um inteiro.
    jogo[i] = malloc(3 * sizeof(int));
  }

  /*    Matriz Alocada:
         int* -> 1 2 3
         int* -> 4 5 6
         int* -> 7 8 9
 */

  int valores[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int cont = 0;
  // Atribuindo os inteiros do array valores na matriz alocada:
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
     jogo[i][j] = valores[cont];
     cont++;
    }
  }

  int local;

  int retornoDoPc = 0;
  int retornoDoUsuario = 0;
  int jogada = 0;

  srand(time(NULL)); // Gerador de números aleatórios para a jogada do computador

  printf("------> Jogo da Velha <------ \n");
  printfDoJogo(jogo);

  do
  {

    printf("Agora é a sua vez, digite a posição para X: ");
    scanf("%i", &local);

    while (local < 1 || local > 9)
    {
      printf("Essa posição não existe no Jogo, tente de novo: ");
      scanf("%i", &local);
    }

    int linha, coluna, iniciarComZero;
    iniciarComZero = local - 1; // 0 à 8.
    /*
      0 1 2
      3 4 5
      6 7 8
    */
    // primeirra linha
    if (iniciarComZero == 0)
    {
      linha = 0;
      coluna = 0;
    }
    else if (iniciarComZero == 1)
    {
      linha = 0;
      coluna = 1;
    }
    else if (iniciarComZero == 2)
    {
      linha = 0;
      coluna = 2;
    }
    // segunda linha
    else if (iniciarComZero == 3)
    {
      linha = 1;
      coluna = 0;
    }
    else if (iniciarComZero == 4)
    {
      linha = 1;
      coluna = 1;
    }
    else if (iniciarComZero == 5)
    {
      linha = 1;
      coluna = 2;
    }
    // terceira linha
    else if (iniciarComZero == 6)
    {
      linha = 2;
      coluna = 0;
    }
    else if (iniciarComZero == 7)
    {
      linha = 2;
      coluna = 1;
    }
    else if (iniciarComZero == 8)
    {
      linha = 2;
      coluna = 2;
    }

    int *ptr = &jogo[linha][coluna];

    if (*ptr == 'X' || *ptr == 'O')
    {
      printf("Essa posição já está ocupada.\n");
      continue;
    }

    *ptr = 'X';

    retornoDoUsuario = logica(jogo, *ptr);
    printfDoJogo(jogo);

    if (retornoDoUsuario == 1)
    {
      printf("Você venceu! Parabéns!\n");
      break;
    }

    jogada++;

    if (jogada == 9)
    {
      printf("Deu empate!\n");
      break;
    }

    printf(">> A Jogada do PC <<\n");

    Computador(jogo);
    retornoDoPc = logica(jogo, 'O');
    printfDoJogo(jogo);

    if (retornoDoPc == 1)
    {
      printf("O computador venceu!\n");
      break;
    }

    jogada++;

  } while (jogada < 9);

  // Liberar a memória alocada
  for (int i = 0; i < 3; i++)
  {
    free(jogo[i]);
  }
  free(jogo);

  return 0;
}
