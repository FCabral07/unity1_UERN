// Created by: Felipe Cabral.
// Code written and explained mostly in English
// but the game is only available in Portuguese
// Coded on the macOS big sur with the VSCode, in september, 9, 2021.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>

void cleanScreen();
void easyDifficult();
void mediumDifficult();
void hardDifficult();
void insaneDifficult();
void hardcoreDifficult();

int main(){
    //Permite uso de acentos:
    setlocale(LC_ALL, "");

    int menu, exit = 1;

    printf("Bem-vindo ao jogo da memória, aqui você tem acesso a um jogo com 5 dificuldades, boa sorte e escolha bem!");

    cleanScreen();

    printf("\n");

    sleep(3);

    cleanScreen();

    //Menu:
    do{
        printf("Escolha uma dificuldade no menu:\n1- Easy\n2- Medium\n3- Hard\n4- Insane\n5- Hardcore\n0- Sair.\nOBS.: A cada acerto ganharás um ponto, a cada erro perderás 1 ponto.\n_Se errar 3 seguidas o jogo acaba.\n>>> ");
        scanf("%d", &menu);

        switch(menu){
            case 0:
                cleanScreen();
                puts("Até mais!");
                sleep(2);
                cleanScreen();
                exit = 0;
                break;
            case 1:
                cleanScreen();
                sleep(1);
                easyDifficult();
                break;
            case 2:
                cleanScreen();
                sleep(1);
                mediumDifficult();
                break;
            case 3:
                cleanScreen();
                sleep(1);
                hardDifficult();
                break;
            case 4:
                cleanScreen();
                sleep(1);
                insaneDifficult();
                break;
            case 5:
                cleanScreen();
                sleep(1);
                hardcoreDifficult();
                break;
            default:
                cleanScreen();
                puts("Digite um número válido.");
                sleep(1);
                cleanScreen();
                break;
        }
    }while(exit!=0);




    return 0;
}

void easyDifficult(){
    //Contador/(Counter):
    int i, x, exit = 0, right = 0, wrong = 0, score = 0, v[5], vcomp[5];

    //Gerando números aleatórios e salvando/(Generating random numbers and saving):
    srand(time(NULL));
    for(i=0;i<5;i++){
        x = rand() % 101;
        v[i] = x;
        printf("%d ", v[i]);
    }

    //Apagando números/(Erasing numbers):
    printf("\n");
    sleep(5);
    cleanScreen();

    //Usuário digita número e compara/(User enters number and compares):
    for(i=0;i<5;i++){
        printf("Digite um número que apareceu na tela: ");
        scanf("%d", &vcomp[i]);
        if(v[i] == vcomp[i]){
            right++;
            score++;
            wrong = 0;
        }else{
            wrong++;
            if(score>0){
                score--;
            }
            //score--;
            if(wrong==3){
                puts("G A M E  O V E R!");
                exit++;
                break;
            }
        }
    }

    if(exit==0){

        //Identificando a quantidade de acertos e erros do usuário/(Identifying the number of hits and misses by the user):
        if(right<=2){
            puts("Podes melhorar!");
        }else if(right==5){
            puts("Excelente, tens uma ótima memória.");
        }else{
            puts("Parabéns! Sempre podes melhorar.");
        }

        //Calculando a pontuação/(calculating the score):
        if(score>=0){
            printf("Você obteve %d pts.\n", score);
        }else{
            puts("Você conseguiu 0 pts.");
        }
    }

    //Apagando informações da tela/(Clearing information from the screen):
    sleep(2);
    printf("\n");
    cleanScreen();
}

void mediumDifficult(){
    //Contador/(Counter):
    int i, x, score = 0, exit = 0, right = 0, wrong = 0, v[10], vcomp[10];

    //Gerando números aleatórios/(Generating random numbers and saving):
    srand(time(NULL));
    for(i=0;i<10;i++){
        x = rand() % 101;
        v[i] = x;
        printf("%d ", v[i]);
    }

    //Apagando números/(Erasing numbers):
    printf("\n");
    sleep(6);
    cleanScreen();

    //Usuário digita número e compara/(User enters number and compares):
    for(i=0;i<10;i++){
        printf("Digite um número que apareceu na tela: ");
        scanf("%d", &vcomp[i]);
        if(v[i] == vcomp[i]){
            right++;
            score++;
            wrong = 0;
        }else{
            wrong++;
            if(score>0){
                score--;
            }
            //score--;
            if(wrong==3){
                puts("G A M E  O V E R!");
                exit++;
                break;
            }
        }
    }

    if(exit==0){

        //Identificando a quantidade de acertos e erros do usuário/(Identifying the number of hits and misses by the user):
        if(right<=4){
            puts("Podes melhorar!");
        }else if(right>=8){
            puts("Excelente, tens uma ótima memória.");
        }else{
            puts("Parabéns! Sempre podes melhorar.");
        }

        //Calculando a pontuação/(calculating the score):
        if(score>=0){
            printf("Você obteve %d pts.\n", score);
        }else{
            puts("Você conseguiu 0 pts.");
        }
    }

    //Apagando informações da tela/(Clearing information from the screen):
    sleep(2);
    printf("\n");
    cleanScreen();
}


void hardDifficult(){
    //Contador/(Counter):
    int i, x, exit = 0, score = 0, right = 0, wrong = 0, v[15], vcomp[15];

    //Gerando números aleatórios/(Generating random numbers and saving):
    srand(time(NULL));
    for(i=0;i<15;i++){
        x = rand() % 101;
        v[i] = x;
        printf("%d ", v[i]);
    }

    //Apagando números/(Erasing numbers):
    printf("\n");
    sleep(7);
    cleanScreen();

    //Usuário digita número e compara/(User enters number and compares):
    for(i=0;i<15;i++){
        printf("Digite um número que apareceu na tela: ");
        scanf("%d", &vcomp[i]);
        if(v[i] == vcomp[i]){
            right++;
            score++;
            wrong = 0;
        }else{
            wrong++;
            if(score>0){
                score--;
            }
            //score--;
            if(wrong==3){
                puts("G A M E  O V E R!");
                exit++;
                break;
            }
        }
    }

    if(exit==0){

        //Identificando a quantidade de acertos e erros do usuário/(Identifying the number of hits and misses by the user):
        if(right<=6){
            puts("Podes melhorar!");
        }else if(right>=12){
            puts("Excelente, tens uma ótima memória.");
        }else{
            puts("Parabéns! Sempre podes melhorar.");
        }

        //Calculando a pontuação/(calculating the score):
        if(score>=0){
            printf("Você obteve %d pts.\n", score);
        }else{
            puts("Você conseguiu 0 pts.");
        }
    }

    //Apagando informações da tela/(Clearing information from the screen):
    sleep(2);
    printf("\n");
    cleanScreen();
}

void insaneDifficult(){
    //Contador/(Counter):
    int i, x, exit = 0, score = 0, right = 0, wrong = 0, v[20], vcomp[20];

    //Gerando números aleatórios/(Generating random numbers and saving):
    srand(time(NULL));
    for(i=0;i<20;i++){
        x = rand() % 101;
        v[i] = x;
        printf("%d ", v[i]);
    }

    //Apagando números/(Erasing numbers):
    printf("\n");
    sleep(8);
    cleanScreen();

    //Usuário digita número e compara/(User enters number and compares):
    for(i=0;i<20;i++){
        printf("Digite um número que apareceu na tela: ");
        scanf("%d", &vcomp[i]);
        if(v[i] == vcomp[i]){
            right++;
            score++;
            wrong = 0;
        }else{
            wrong++;
            if(score>0){
                score--;
            }
            //score--;
            if(wrong==3){
                puts("G A M E  O V E R!");
                exit++;
                break;
            }
        }
    }

    if(exit==0){

        //Identificando a quantidade de acertos e erros do usuário/(Identifying the number of hits and misses by the user):
        if(right<=8){
            puts("Podes melhorar!");
        }else if(right>=16){
            puts("Excelente, tens uma ótima memória.");
        }else{
            puts("Parabéns! Sempre podes melhorar.");
        }

        //Calculando a pontuação/(calculating the score):
        if(score>=0){
            printf("Você obteve %d pts.\n", score);
        }else{
            puts("Você conseguiu 0 pts.");
        }
    }

    //Apagando informações da tela/(Clearing information from the screen):
    sleep(2);
    printf("\n");
    cleanScreen();
}

void hardcoreDifficult(){
    //Contador/(Counter):
    int i, x, exit = 0, score = 0, right = 0, wrong = 0, v[30], vcomp[30];

    //Gerando números aleatórios/(Generating random numbers and saving):
    srand(time(NULL));
    for(i=0;i<30;i++){
        x = rand() % 101;
        v[i] = x;
        printf("%d ", v[i]);
    }

    //Apagando números/(Erasing numbers):
    printf("\n");
    sleep(9);
    cleanScreen();

    //Usuário digita número e compara/(User enters number and compares):
    for(i=0;i<30;i++){
        printf("Digite um número que apareceu na tela: ");
        scanf("%d", &vcomp[i]);
        if(v[i] == vcomp[i]){
            right++;
            score++;
            wrong = 0;
        }else{
            wrong++;
            if(score>0){
                score--;
            }
            //score--;
            if(wrong==3){
                puts("G A M E  O V E R!");
                exit++;
                break;
            }
        }
    }

    if(exit==0){

        //Identificando a quantidade de acertos e erros do usuário/(Identifying the number of hits and misses by the user):
        if(right<=12){
            puts("Podes melhorar!");
        }else if(right>=24){
            puts("Excelente, tens uma ótima memória.");
        }else{
            puts("Parabéns! Sempre podes melhorar.");
        }

        //Calculando a pontuação/(calculating the score):
        if(score>=0){
            printf("Você obteve %d pts.\n", score);
        }else{
            puts("Você conseguiu 0 pts.");
        }
    }

    //Apagando informações da tela/(Clearing information from the screen):
    sleep(2);
    printf("\n");
    cleanScreen();
}

void cleanScreen(){
    system("Clear");
}

