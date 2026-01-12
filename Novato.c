#include <stdio.h>
#include <string.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

typedef struct Coordenada{
    int linha;
    int coluna;
} Coordenada;

void ClearConsole()
{
    //Limpa o console
    #ifdef _WIN32 //Forma melhorada para detectar o OS e limpar
        system("cls");
    #else
        system("clear");
    #endif
}

Coordenada ObterCoordenada(char coord[3])
{
    Coordenada c;

    c.coluna  = coord[0] - 'A';
    c.linha = coord[1] - '1';

    return c;
}

int PosicionarNavio(Coordenada coordenada ,int navio[3]
    ,int tamanho_tab, int tabuleirox[tamanho_tab][tamanho_tab], int vertical)
{
    //Verificar sobreposição dos navios já existentes  - Horizontal
    if(vertical==0)
    for (int j = 0; j < 3; j++)
    {
        if (tabuleirox[coordenada.linha][coordenada.coluna + j] != 0)
        {
            printf("Coordenada do Navio inválida!!\nPosição ocupada");
            return -1;
        }
    }
            
    //Verificar sobreposição dos navios já existentes  - Vertical
    if(vertical==1)
    for (int i = 0; i < 3; i++)
    {
        if (tabuleirox[coordenada.linha + i][coordenada.coluna] != 0)
        {
            printf("Coordenada do Navio inválida!!\nPosição ocupada");
            return -1;
        }
    }
    
    if (vertical)
    {
        for (int i = 0; i < 3; i++)
            tabuleirox[coordenada.linha + i][coordenada.coluna] = 3;
    }
    else
    {
        for (int i = 0; i < 3; i++)
            tabuleirox[coordenada.linha][coordenada.coluna + i] = 3;
    }
    return 0;
}

void VerTabuleiro(int tab, int tabuleirox[tab][tab])
{
    //Limpa o console
    //ClearConsole();

    //Printar
    printf("-------TABULEIRO NAVAL-------\n\n    ");
            
    for(int i = 0; i < tab; i++)
        printf(" %c ", 'A' + i); //Printa cada caractere por código em byte/int e vai adicionando para printar conforme cresce o número!

    printf("\n----------------------------------");
    
    for(int i = 0; i < tab; i++)
    {
        printf("\n%d %s|", i+1, i +1 > 9 ? "" : " ");
        for(int j = 0; j < tab; j++)
        {
            printf(" %d ", tabuleirox[i][j]);
        }
    }
    printf("\n\n");


}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //Limpa o console
    ClearConsole();

    //Créditos
    printf("Jogo de Batalha Naval - Estácio\nMiguel Ass. Queiroz(Bit.Raiden) - 2026\n\n");

    //Tabuleiro Naval
    int tamanho_tab = 10; //Em linhas e colunas(mesma quantia)
    int tabuleiro[tamanho_tab][tamanho_tab];

    //Navio Horizontal
    int navio_H[3] = {3,3,3}; 

    //Navio Vertical
    int navio_V[3][1] = {   
     {3},
     {3},
     {3}     
    };

    //Inicializar o Tabuleiro
    for(int i = 0; i < tamanho_tab; i++)
        for(int j = 0; j < tamanho_tab; j++)
            tabuleiro[i][j] = 0; // 0 --> ÁGUA

    //Coordenadas
    Coordenada Navio_H = ObterCoordenada("A1");
    Coordenada Navio_V = ObterCoordenada("E3");

    int posicionar_result = 0;

    //Posicionar os Navios e Validar tamanho do Navio e coordenada dentro dos Limites do Tabuleiro
    if(Navio_H.linha <= tamanho_tab - 3 && Navio_H.coluna <= tamanho_tab - 3)
        posicionar_result = PosicionarNavio(Navio_H, navio_H, tamanho_tab, tabuleiro, 0); //Horizontal
    if(Navio_V.linha <= tamanho_tab - 3 && Navio_V.coluna <= tamanho_tab - 3)
        posicionar_result = posicionar_result | PosicionarNavio(Navio_V, navio_V, tamanho_tab, tabuleiro, 1); //Vertical
    
    if(posicionar_result==0)
        VerTabuleiro(tamanho_tab, tabuleiro);
    return 0;
}


