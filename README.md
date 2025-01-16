# crapss.c
cassino
Objetivo do projeto e Dowload:
prototipo de um jogo de cassino desenvolvido todo em C todo codigo ultilizado esta na pasta crapsPROD.c. Para executar e so ir no crapsPROD e baixar ou entao no crapsPROD.exe
e diverta-se!

Objetivo do Jogo:

O objetivo principal do Craps é prever o resultado dos lançamentos dos dados. Os jogadores podem apostar em vários tipos de resultados, como o valor total dos dados, a possibilidade de um número específico aparecer, entre outros.
Como Funciona o Jogo:

    Primeiro Lançamento – Começo (Come Out Roll):
        O jogador que está lançando os dados é chamado de "shooting".
        O jogo começa com um lance inicial (come out roll). O jogador joga os dois dados e o resultado pode ser:
            7 ou 11: Se o jogador tirar 7 ou 11 no come out roll, ele ganha a aposta "Pass Line" (ou "Pass").
            2, 3 ou 12: Se o jogador tirar 2, 3 ou 12 no come out roll, ele perde a aposta "Pass Line" e a aposta "Don't Pass Line" ganha.
            Qualquer outro número (4, 5, 6, 8, 9 ou 10): O número lançado se torna o "ponto" (point). Nesse caso, o jogador continua jogando e tenta obter o "ponto" novamente antes de tirar um 7 para ganhar a aposta "Pass Line".

    Seguindo o Ponto:
        Se o número lançado no come out roll for 4, 5, 6, 8, 9 ou 10, ele se torna o ponto.
        O jogador deve tentar tirar o ponto novamente antes de tirar um 7.
            Se o jogador tirar o ponto novamente: Ele vence a aposta "Pass Line".
            Se o jogador tirar 7 antes do ponto: Ele perde a aposta "Pass Line" (isso é chamado de "seven out").

    Apostas: Existem várias apostas no Craps, mas as mais comuns incluem:
        Pass Line: O jogador aposta que o lance inicial (come out roll) será 7 ou 11, ou que o ponto será alcançado antes de um 7.
        Don't Pass Line: O oposto da "Pass Line". O jogador aposta que o lance inicial será 2, 3 ou 12, ou que o 7 sairá antes do ponto.
        Come: Funciona como a "Pass Line", mas pode ser feita a qualquer momento durante a partida, após o lance inicial. O jogador faz a aposta em um novo ponto.
        Don't Come: O oposto da aposta "Come". O jogador aposta que 2, 3 ou 12 vai sair antes do ponto.
        Field: O jogador aposta que o próximo lance será 2, 3, 4, 9, 10, 11 ou 12, ganhando dependendo do valor que sair.
        Place Bet: O jogador aposta em um número específico (4, 5, 6, 8, 9 ou 10), e ele ganha se esse número for lançado antes do 7.
