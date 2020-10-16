#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main (){
    int escolha, tamanho=0;
    char *agenda;

    do{
        escolha = Menu();
        switch(escolha){
            case 1:
                agenda = addNome (agenda, &tamanho); 
            break;
            case 2:
                imprimirNome(agenda);
            break;
            case 3:
                agenda = removeNome (agenda, &tamanho);
            break;
            case 4:
                exit(0);    
            break;
        }
    
    }while (escolha != 4);


return 0; 
}