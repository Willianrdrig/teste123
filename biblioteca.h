int Menu (){
    int escolha;
    do {
        printf("\n------- [ MENU ] -------");
        printf ("\n\n1 - Adicionar nome: \n");
        printf ("2 - Listar nomes: \n");
        printf ("3 - Remover nomes: \n");
        printf ("4 - Sair \n");
        printf("Digite: ");
        scanf("%i", &escolha);


        if (escolha <= 0 || escolha > 4 ){
            printf("\nIndisponivel, digite outro valor!\n\n");
            system ("pause");
        }
    
        limpar();
        return escolha;
    }while (escolha <= 0 || escolha > 4);
// ---------------------------------------------------------------------------------------------------        
}
// função para limpar a tela //
void limpar(){
    system ("cls");
}
// ----------------------------------------------------------------------------------------------------
char* addNome (char *agenda, int *tamanho){
    char nome[20];
    int tamanhoAux=0;
    
    fflush(stdin);
    printf("Digite o nome: ");
    fgets (nome, 20, stdin);                                        // leitura da string
    
    if (*tamanho == 0){                                        // malloc p/ primeira iteração
        *tamanho = *tamanho + strlen(nome) + 1;                // tamanho da string + 1 p/ colocar caracter nulo no final
        agenda = (char*) malloc((*tamanho) *sizeof(char));     // aloca o tamanho da memoria
        strcpy(agenda, nome);                                   
        agenda[*tamanho-1] = '\0';                              // add um caracter nulo no final da string

    }else{                                                           
        tamanhoAux = strlen(agenda);                            //tamanho da agenda até o momento
        *tamanho = *tamanho + strlen(nome) + 1;                     //calcula do tamanho do *tamanho + novo nome + 1 (caracter nulo)    
        agenda = (char*)realloc(agenda, (*tamanho) * sizeof(char)); //realloc no novo tamanho
        strcpy(agenda + tamanhoAux , nome);                         // copia o novo nome pro final da agenda
        agenda[*tamanho-1] = '\0';                                  //add no final da string para determina quando ela acaba
        
    }                                                                
    
    printf("\nNome adicionado com sucesso!\n\n");
    system("pause");
    limpar();
    return agenda;
    
    
}

void imprimirNome(char *agenda){
    int cont=0, i;
    printf("------- [ Listando todos os nomes ! ]--------\n");

    for (i = 0; agenda[i] != '\0'; i++){
             if (i == 0 || agenda[i-1] == '\n'){           //cont bota inteiro antes do nome
            printf("%i - ", cont);
            cont++;
        }
            printf("%c", agenda[i]);    
    }

    printf("\n------- [ Todos nomes listados ! ]--------\n\n");
    system("pause");
    limpar();
}

char* removeNome (char *agenda, int *tamanho){
    int i, remove, cont=0, posicaoNome=0, proximo=0;
    imprimirNome(agenda);
    for(i=0; agenda[i] != '\0'; i++){         // verifica quantos nomes tem
        if (agenda[i]== '\n')
            cont++;
    }
    do{
        printf("\n\n Digite o nome que deseja remove: ");
        scanf("%i", &remove); 

        if(remove>cont)                                         // escreve qual nome deseja remover
            printf("\nNao e possivel remover este nome");
    }while(remove>cont);

    for(i=0; agenda[i] != '\0'; i++){       //percorre toda a string até encontrar \0
        if(agenda[i-1] == '\n')             //percorre até achar \n, p/ saber onde o nome começa
            posicaoNome++;
        if(posicaoNome==remove){                    
            if(agenda[i] == '\n')
                agenda[i-proximo] = agenda[i+1];  //recebe o proximo caracter pos o \n do final da palavra removida
            else{
                agenda[i-proximo] = agenda[i];          //caracter vai sendo jogando para o final da string
                proximo++;}                              //conta quantos caracter tem a palavra removida
        }
        if(posicaoNome>remove)
            agenda[i-proximo] = agenda[i+1];    
    }

*tamanho = strlen(agenda);  //calcula o novo tamanho até o '\0'
agenda = (char*) realloc(agenda, (*tamanho)*sizeof(char)); // realoca memoria 
limpar();
return agenda;    

}
