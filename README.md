<h1>JogoDaVelha</h1>
<br>
<h2>Objetivo:</h2><br>
Fazer um programa em C que simule o jogo da velha. O programa deve gerar o tabuleiro (3x3) enumerados de 1 a 9 inicialmente e a medida que o jogador escolha a posição você deve substituir o número da posição por X. O outro jogador será o PC. Ele escolherá uma posição aleatória, dentro das possíveis, e o tabuleiro deve ser atualizado colocando o O na posição escolhida. Ao final, o programa deve informar quem é o vencedor ou dizer que houve empate.
<br>
<h2>Exigências:</h2><br>
<ul>
   <li>Alocação de memória dinâmica;</li>
   <li>Vetores ou matrizes;</li>
   <li>Ponteiros;</li>
</ul>
<br>
<h2>Breve Descrição:</h2><br>
Na função main o programa usa alocação dinâmica de memória para criar uma matriz 3x3 sendo ponteiros de ponteiros de inteiros (int **jogo). Em seguida é preenchido a matriz alocada com os números de 1 a 9, sendo esses números as posições que vão ser utilizadas. Para definir uma posição válida temos duas condições: se a posição digitada existe realmente no jogo e se a posição digitada já foi ocupada na jogada anterior, caso seja verdade, o jogo irá voltar ao scanf na repetição “Do” pedindo uma nova posição. É criado duas variáveis, sendo uma para o retorno do usuário e outra para o PC, cada uma irá ser associada a função lógica que recebe como parâmetro a matriz alocada e seu caractere. Essa função lógica verifica com o laço “for” duas condições, sendo uma para as 3 linhas da matriz alocada e outra para as 3 colunas, além dessa repetição a função possui duas condições para as diagonais. A função retorna o inteiro 1 caso seja verdade uma das condições. Fora da função lógica, é chamado a função para exibir as alterações e   tem uma condição para que se o retorno for 1, então o jogador venceu e será parado o laço “Do”, senão será somada essa jogada e o jogo continuará. Para a Jogada do computador é feito por meio da biblioteca time.h que ao ser iniciada determina números aleatórios de acordo com as posições possíveis na matriz alocada. Assim como o usuário, o computador também utiliza a função lógica para determinar se venceu. Se todas as jogadas forem feitas o jogo irá parar e exibir empate. Ao final, o programa libera a memória alocada por meio do free. 
<br>
