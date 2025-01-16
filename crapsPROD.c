#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum Status {CONTINUE, WON, LOST};
double Probabilidade_PassLine_7(void);
double Probabilidade_PassLine_11(void);
double Probabilidade_DontPass(void);
int ScrollingDice(void);
#define MAX_INPUT_SIZE 100


void expression(void)
{
    printf("OLA SEJA BEM VINDO AO JOGO CRAPS.\n");
    printf("AS REGRAS SAO SIMPLES, ESCOLHA SE VOCE QUER APOSTAR EM PASS LINE\n ");
    printf("OU EM DONT'T PASS LINE E PLACE BETS\n");
    printf("SE VOCE JOGAR EM PASS LINE SE CAIR EM 7 OU EM 11 VOCE GANHA\n");
    printf("SE VOCE JOGAR EM DONT'T PASS LINE SE CAIR EM 2, 3 VOCE GANHA SE CAIR 12 VOCE EMPATA\n");
    printf("E SE FOR PLACE BETS, AI E DE ACORDO COM O DADO LANÇADO DA CASA\n");

    printf("\n");
}

void inputStart()
{
    char input[MAX_INPUT_SIZE];

    while(1)
    {
        printf("CLIQUE NA TECLA ENTER PARA INICIAR O JOGO: ");
        if(fgets(input, sizeof(input), stdin) != NULL)
        {
            input[strcspn(input, "\n")] = '\0';

            printf("\n");

            if(strlen(input) == 0)
            {
                printf("|RODADA INICIADA|\n DADO LANÇADO: ");
                break;
            }else
            {
                printf("Erro: Digite uma tecla Enter para confirmar e iniciar o jogo: ");

                printf("\n");

                while(getchar() != '\n');
            }
        }
    }
}

void clearBuffer(void)
{
    while(getchar() != '\n');
}

int main()
{ 
    expression();
    inputStart();

    int DadoBet;
    int DontLine;
    int PassLine;

    float saldo;
    float aposta;

    int myPoint;

    enum Status gameStatus;

    printf("digite o saldo da conta: ");
    scanf("%f", &saldo);
    clearBuffer();
     
    srand(time(NULL));
    
    while(saldo > 0.0)
    { 
        printf("\n");
        printf("Digite o valor da aposta: ");
        scanf("%f", &aposta);
        clearBuffer();

        if(aposta > saldo)
        {
            printf("Erro.\n coloque um valor valido");
            continue;
        }

        printf("escolha a aposta\n");
        printf("digite 1 para PassLine: \t");
        printf("Ou digite 2 para Dont't Pass Line: \t\n");
        printf("Ou digite 3 paraa Line Bet\n");

        scanf("%d", &PassLine);
        clearBuffer();
    
        if(PassLine == 1)
        {
            ScrollingDice();
            PassLine = ScrollingDice();

            switch(PassLine)
            {
                case 7:
                case 11:
                    gameStatus = WON;
            
                break;
                
                case 2:
                case 3:
                case 12:
                    gameStatus = LOST;
                break;

                default:
                    gameStatus = CONTINUE;
                    myPoint = PassLine;
                    printf("O Ponto do dado e: %d\n", myPoint);
                break;
            }

            while(gameStatus == CONTINUE)
            {
                PassLine = ScrollingDice();

                if(PassLine == myPoint)
                {
                    gameStatus = WON;
                }else 
                {
                    if(PassLine == 7)
                    {
                        gameStatus = LOST;
                    }
                }
            }

            if(gameStatus == WON)
            {
                
                saldo = saldo + (aposta / 1.8);
               
                printf("Jogador vence na rodada PassLine\n");
                printf("O saldo da conta ficou em: %f", saldo);
            }
            if(gameStatus == LOST)
             {
                saldo = saldo - (aposta / 0.6);
                printf("Jogador perde na rodada PassLine\n");
                printf("infelizmente voce perdeu: %f", saldo);
            }
               if(saldo <=0.0)
            {
                printf("saldo insuficiente para continuar jogando.\n");
                break;
            }
            printf("\n");
            printf("Deseja jogar novamente? (s|n): ");
            

            char resposta;
            scanf("%c", &resposta);
            clearBuffer();

            if(resposta != 'S' && resposta != 's')
            {
                break;
            }
        }

        if(PassLine == 2)
        {
            PassLine = ScrollingDice();
            switch(PassLine)
            {
                case 7:
                case 11:
                    gameStatus = LOST;
                break;
            
                case 2:
                case 3:
                    gameStatus = LOST;
                break;
            
                case 12:
                    gameStatus = CONTINUE;
                break;

                default:
                    gameStatus = CONTINUE;
                    myPoint = PassLine;
                    printf("O Ponto do dado e: %d\n", myPoint);
                break;
            }

            while(gameStatus == CONTINUE)
            {
                DontLine = ScrollingDice();

                if(DontLine == myPoint)
                {
                    gameStatus = WON;
                }else
                {
                    if(DontLine == 7)
                    {
                        gameStatus = WON;
                    }
                }
            }

            if(gameStatus == WON)
            {
                saldo = saldo + (aposta / 1.8);
                printf("Jogador vence na rodada Dont't Pass Line\n");
                printf("O saldo da conta ficou em: %f", saldo);
            }
            if(gameStatus == LOST)
            {
                saldo = saldo - (aposta / 0.6);
                printf("Jogador perde na rodada Dont't Pass Line\n");
                printf("Infelizmente voce perdeu : %f", saldo);
            }
               if(saldo <=0.0)
            {
                printf("saldo insuficiente para continuar jogando.\n");
                break;
            }
            printf("\n");
            printf("Deseja jogar novamente? (s|n): ");
            

            char resposta;
            scanf("%c", &resposta);
            clearBuffer();

            if(resposta != 'S' && resposta != 's')
            {
                break;
            }
        }

        if(PassLine == 3)
        {
            printf("Digite o seu palpite do valor da soma do dado entre: 4,5,6,8,9,10\n");
            scanf("%d", &DadoBet);
            clearBuffer();

            DadoBet = ScrollingDice();

            switch(DadoBet)
            {
                case 4:
                    gameStatus = WON;
                    printf("parabens voce ganhou");
                break;

                case 5:
                    gameStatus = WON;
                    printf("parabens voce ganhou");
                break;
        
                case 6:
                    gameStatus = WON;
                    printf("parabens voce ganhou;");
                break;

                case 8:
                    gameStatus = WON;
                    printf("parabens voce ganhou");
                break;

                case 9:
                    gameStatus = WON;
                    printf("parabens voce ganhou");
                break;

                case 10:
                    gameStatus = WON;
                    printf("parabens voce ganhou");
                break;

                case 7:
                case 2:
                case 3:
                case 11:
                case 12:
                
                    gameStatus = LOST;
                    printf("nao foi dessa vez voce perdeu.\n");
                break;

                default:
                    gameStatus = CONTINUE;
                    myPoint = PassLine;
                    printf("O Ponto do dado e: %d\n", myPoint);
                break;
    
            }

            while(gameStatus == CONTINUE)
            {
                DadoBet = ScrollingDice();

                if(DadoBet == myPoint)
                {
                    gameStatus = WON;
                }else
                {
                    if(DadoBet == 7 && DadoBet == 11 && DadoBet == 2 && DadoBet == 3 && DadoBet == 12 )
                    {
                        gameStatus = LOST;
                    }
                }
            }
            if(gameStatus == WON)
            {
                saldo = saldo + (aposta / 1.8);

                printf("Jogador vence na rodada PassLine\n");
                printf("O saldo da conta ficou em: %f", saldo);
            }
            if(gameStatus == LOST)
            {
                saldo = saldo - (aposta / 0.6);
                printf("Jogador perde na rodada PassLine\n");
                printf("Infelizmente voce perdeu: %f", saldo);
            }
            
            if(saldo <=0.0)
            {
                printf("saldo insuficiente para continuar jogando.\n");
                break;
            }
            printf("\n");
            printf("Deseja jogar novamente? (s|n): ");
            

            char resposta;
            scanf("%c", &resposta);
            clearBuffer();

            if(resposta != 'S' && resposta != 's')
            {
                break;
            }
        }
    }

        printf("Obrigado por jogar! continue jogando e ganhando!!");
        printf("O seu saldo final: %.2f\n", saldo);
        
        printf("\n");
        Probabilidade_PassLine_7();
        printf("\n");
        Probabilidade_PassLine_11();
        printf("\n");
        Probabilidade_DontPass();

    return 0;
}

int ScrollingDice(void)
{
    int dado1;
    int dado2;
    int SomaDado;

    dado1 = 1 + (rand() % 6);
    dado2 = 1 + (rand() % 6);

    SomaDado = dado1 + dado2;

    printf("Jogador rolou os dados %d + %d = %d\n", dado1, dado2, SomaDado);

    return SomaDado;
}

double Probabilidade_PassLine_7(void)
{
    int jogadasUsadas = 10;
    int contagem = 7;
    int soma = 0;
    int dadoPassLine1;
    int dadoPassLine2;
    
    for(int i = 0; i <= jogadasUsadas; i++)
    {
        dadoPassLine1 = 1 + (rand() % 6);
        dadoPassLine2 = 1 + (rand() % 6);
    
        if(dadoPassLine1 + dadoPassLine2 == contagem)
        {
            soma++;
        }
    }

    double chancePassLine = (double)contagem / jogadasUsadas;
    printf("|Jogadas: %d \t  | probabilidade de cair o numero 7: %4f%%|", jogadasUsadas, chancePassLine); 
   
    return chancePassLine;
}   
 
double Probabilidade_PassLine_11(void)
{
    int jogadasUsadas2 = 10;
    int contagem2 = 11;
    int soma2 = 0;
    int dadoPassLine3;
    int dadoPassLine4;
    
    for(int i = 0; i <= jogadasUsadas2; i++)
    {
        dadoPassLine3 = 1 + (rand() % 6);
        dadoPassLine4 = 1 + (rand() % 6);
    
        if(dadoPassLine3 + dadoPassLine4 == contagem2)
        {
            soma2++;
        }
    }

    double chancePassLine2 = (double)contagem2 / jogadasUsadas2;
    printf("|Jogadas: %d \t  | probabilidade de cair o numero 11: %4f%%|", jogadasUsadas2, chancePassLine2); 
   

    return chancePassLine2; 
}

double Probabilidade_DontPass(void)
{
    int jogadasUsadasNot = 10;
    int Arr[] = {2, 3, 12};
    int resultado = 0;
    int D1;
    int D2;
    int resultado1 = 0;
    int resultado2 = 0;

    for(int i = 0; i <= jogadasUsadasNot; i++)
    {
        D1 = 1 + (rand() % 6);
        D2 = 1 + (rand() % 6);

        if(D1 + D2 == Arr[0])
        {
            resultado++;
        }else if(D1 + D2 == Arr[1])
        {
            resultado1++;
        }else if(D1 + D2 == Arr[2])
        {
            resultado2++;
        }
    }

    double ChanceArr = (double)resultado / jogadasUsadasNot;
    printf("|Jogadas PassLineNot %d \t | probabilidade da Jogada Dont Pass: %4f%%", jogadasUsadasNot, ChanceArr);


    return ChanceArr;
}