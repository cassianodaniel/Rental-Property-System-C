#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX_ARRAY 100

typedef struct {
	char rua[MAX_ARRAY];
	int num;
	char bairro[MAX_ARRAY];
	char cidade[MAX_ARRAY];
	char cep[15];

} tendereco;

typedef struct {
	char aouv; //área ou valor
	char titulo[MAX_ARRAY];
	int areaTerreno, areaConstruida, numQuartos, numPavimentos;
	int valor;
    int ativo;
	tendereco endereco;

} tcasa;

typedef struct {
	char aouv; //área ou valor
	char titulo[MAX_ARRAY];
	char posicao[MAX_ARRAY];
	int area, numQuartos, numVagasG, andar;
	int valor, valorCond;
	int ativo;
	tendereco endereco;

} tapt;

typedef struct {
	char aouv; //área ou valor
	char titulo[MAX_ARRAY];
	int area;
	int valor;
    int ativo;
	tendereco endereco;

} tterreno;

extern void Create();
extern void Read();
extern void Update();
extern void Delete();
extern void SalvaArquivo();

void ImprimeTerreno(tterreno *pTerreno){
    printf("\t\t%s\n", pTerreno->titulo);
    printf("\tÁrea: %d\n", pTerreno->area);
    printf("\tValor: %d\n", pTerreno->valor);
    if(pTerreno->aouv == 'a'){
    printf("\tDisponível para aluguel\n");
    }else{
    printf("\tDisponível para venda\n");
    }
    printf("\n\tEndereço:\n");
    printf("\tRua: %s", pTerreno->endereco.rua);
    printf("\tNúmero: %d\n\n", pTerreno->endereco.num);
    printf("\tCidade: %s", pTerreno->endereco.cidade);
    printf("\tBairro: %s", pTerreno->endereco.bairro);
    printf("\tCEP: %s\n\n", pTerreno->endereco.cep);
}

void ImprimeCasa(tcasa *pCasa){
    printf("\t\t%s\n", pCasa->titulo);
    printf("\tValor: %d\n", pCasa->valor);
    printf("\tÁrea do terreno: %d\n", pCasa->areaTerreno);
    printf("\tÁrea construída: %d\n", pCasa->areaConstruida);
    printf("\tNúmero de quartos: %d\n", pCasa->numQuartos);
    printf("\tNúmero de pavimentos: %d\n", pCasa->numPavimentos);
    if(pCasa->aouv == 'a'){
    printf("\tDisponível para aluguel\n");
    }else{
    printf("\tDisponível para venda\n");
    }
    printf("\n\tEndereço:\n");
    printf("\tRua: %s", pCasa->endereco.rua);
    printf("\tNúmero: %d\n\n", pCasa->endereco.num);
    printf("\tCidade: %s", pCasa->endereco.cidade);
    printf("\tBairro: %s", pCasa->endereco.bairro);
    printf("\tCEP: %s\n\n", pCasa->endereco.cep);
}

void ImprimeApt(tapt *pApt){
    printf("\t\t%s\n", pApt->titulo);
    printf("\tValor: %d\n", pApt->valor);
    printf("\tValor do condomínio: %d\n", pApt->valorCond);
    printf("\tÁrea: %d\n", pApt->area);
    printf("\tAndar: %d\n", pApt->andar);
    printf("\tNúmero de quartos: %d\n", pApt->numQuartos);
    printf("\tNúmero de vagas na garagem: %d\n", pApt->numVagasG);
    printf("\tPosição do apartamento: %s", pApt->posicao);
    if(pApt->aouv == 'a'){
    printf("\tDisponível para aluguel\n");
    }else{
    printf("\tDisponível para venda\n");
    }
    printf("\n\tEndereço:\n");
    printf("\tRua: %s", pApt->endereco.rua);
    printf("\tNúmero: %d\n\n", pApt->endereco.num);
    printf("\tCidade: %s", pApt->endereco.cidade);
    printf("\tBairro: %s", pApt->endereco.bairro);
    printf("\tCEP: %s\n\n", pApt->endereco.cep);
}

/*declaração de arrays com suas respectivas variáveis a seguir.*/
	tterreno terrenos[MAX_ARRAY];
	tcasa casas[MAX_ARRAY];
	tapt apts[MAX_ARRAY];
	int i, selecaoUpdate, crud = -1;
	char tituloBuscado[100];
	int j, k, igual[3];
    char tipoImovel, tipoArq;

int main(void) {

    setlocale(LC_ALL, "Portuguese");

	//for para ativar todos os imóveis

    for (j = 0; j< MAX_ARRAY; j++){
    terrenos[j].ativo = 0;
    casas[j].ativo = 0;
    apts[j].ativo = 0;
    }

    LeArquivo();

	while(crud != 5){

        printf("Seja bem-vindo(a) ao simulador de imobiliária!\n\n"
        "1) CADASTRAR IMÓVEIS\n"
		"2) VISUALIZAR IMÓVEIS\n"
		"3) ATUALIZAR IMÓVEIS\n"
		"4) DELETAR IMÓVEIS\n"
		"5) SAIR\n\n");
        scanf("%d%*c", &crud);

        switch (crud) {

//CREATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

        case 1:

        Create();

        break;

//UPDATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

        case 3:

        Update();

        break;

//READ------------------------------------------------------------------------------------------------------------------------------------------

        case 2:

        Read();

        break;

        //FUNÇÃO PARA REMOVER UM DETERMINADO IMÓVEL
        case 4:

        Delete();

        break;

            }
        }

    SalvaArquivo();

    return 0;
}

void SalvaArquivo(){

    FILE *fp2;

    fp2 = fopen("file1.txt", "w");

    if (fp2 == NULL){
        puts("Erro ao abrir FP.");
        return 1;
    }

    for(int i = 0; casas[i].titulo[0] != '\0' ; i++){

            if(!apts[i].ativo)
            continue;

            fprintf(fp2, "3\n");
            fprintf(fp2, "%c\n", casas[i].aouv);
            fprintf(fp2, "%s", casas[i].titulo);
            fprintf(fp2, "%d\n", casas[i].areaTerreno);
            fprintf(fp2, "%d\n", casas[i].areaConstruida);
            fprintf(fp2, "%d\n", casas[i].numQuartos);
            fprintf(fp2, "%d\n", casas[i].numPavimentos);
            fprintf(fp2, "%d\n", casas[i].valor);
            fprintf(fp2, "%s", casas[i].endereco.rua);
            fprintf(fp2, "%d\n", casas[i].endereco.num);
            fprintf(fp2, "%s", casas[i].endereco.bairro);
            fprintf(fp2, "%s", casas[i].endereco.cidade);
            fprintf(fp2, "%s", casas[i].endereco.cep);

    }

        for(int i = 0; apts[i].titulo[0] != '\0'; i++){

            if(!casas[i].ativo)
            continue;

            fprintf(fp2, "2\n");
            fprintf(fp2, "%s", apts[i].aouv);
            fprintf(fp2, "%s", apts[i].titulo);
            fprintf(fp2, "%d\n", apts[i].area);
            fprintf(fp2, "%d\n", apts[i].valor);
            fprintf(fp2, "%s", apts[i].endereco.rua);
            fprintf(fp2, "%d\n", apts[i].endereco.num);
            fprintf(fp2, "%s", apts[i].endereco.bairro);
            fprintf(fp2, "%s", apts[i].endereco.cidade);
            fprintf(fp2, "%s", apts[i].endereco.cep);
        }

        for(int i = 0; terrenos[i].titulo[0] != '\0' ; i++){

            if(!terrenos[i].ativo)
            continue;

            fprintf(fp2, "1");
            fprintf(fp2, "%s", terrenos[i].titulo);
            fprintf(fp2, "%c", terrenos[i].aouv);
            fprintf(fp2, "%d", terrenos[i].valor);
            fprintf(fp2, "%d", terrenos[i].area);
            fprintf(fp2, "%s", terrenos[i].endereco.rua);
            fprintf(fp2, "%d", terrenos[i].endereco.num);
            fprintf(fp2, "%s", terrenos[i].endereco.bairro);
            fprintf(fp2, "%s", terrenos[i].endereco.cidade);
            fprintf(fp2, "%s", terrenos[i].endereco.cep);

        }

    fclose(fp2);
}

void LeArquivo(){

    FILE *fp;

    fp = fopen("file1.txt", "r");

    if (!fp)
        puts("Erro ao abrir o arquivo");
    else{
        while(1){

            if (feof(fp))
                break;
            tipoArq = fgetc(fp);
            switch(tipoArq){
            case 1:

                fgets(terrenos[i].titulo, 100, fp);
                fscanf(fp, "%c", &terrenos[i].aouv);
                fscanf(fp, "%d", &terrenos[i].valor);
                fscanf(fp, "%d", &terrenos[i].area);
                fgets(terrenos[i].endereco.rua, 100, (FILE*)fp);
                fscanf(fp, "%d", &terrenos[i].endereco.num);
                fgets(terrenos[i].endereco.bairro, 100, (FILE*)fp);
                fgets(terrenos[i].endereco.cidade, 100, (FILE*)fp);
                fgets(terrenos[i].endereco.cep, 100, (FILE*)fp);
                i++;

            break;
            case 2:
               // LeCasa(&casas[j]);
                j++;
            break;
            case 3:
               // LeApt(&apts[k]);
                k++;
            }
        }
    fclose(fp);
    }
}

void Create(){

    char tipoImovel;

    printf("\nO que você deseja cadastrar?\n\n"
                   "T. TERRENO\n"
                   "C. CASA\n"
                   "A. APARTAMENTO\n\n");

    scanf("%c%*c", &tipoImovel);

    switch (tipoImovel){

    case 't':
    case 'T': //terreno
        for (i = 0; i < MAX_ARRAY; i++) {
            if (terrenos[i].titulo[0] == '\0' || terrenos[i].ativo == 0) //caso encontre algum terreno sem nenhum caracter, pare.
                break;
        }

        printf("Por favor, digite as informações referentes ao terreno.\n\n");
        puts("Título do anúncio do terreno:");
        fgets(terrenos[i].titulo, MAX_ARRAY, stdin);
        printf("Área do terreno:\n");
        scanf("%d%*c", &terrenos[i].area);
        printf("Valor do terreno:\n");
        scanf("%d%*c", &terrenos[i].valor);
        puts("O terreno está para aluguel(a), ou para venda(v)?");
        scanf("%c%*c", &terrenos[i].aouv);
        printf("Cidade do terreno:\n");
        fgets(terrenos[i].endereco.cidade, MAX_ARRAY, stdin);
        printf("Bairro do terreno:\n");
        fgets(terrenos[i].endereco.bairro, MAX_ARRAY, stdin);
        printf("Rua do terreno:\n");
        fgets(terrenos[i].endereco.rua, MAX_ARRAY, stdin);
        printf("Número do terreno na rua:\n");
        scanf("%d%*c", &terrenos[i].endereco.num);
        printf("CEP do terreno:\n");
        fgets(terrenos[i].endereco.cep, MAX_ARRAY, stdin);
        terrenos[i].ativo = 1;
        printf("\n\n%s foi cadastrado com sucesso!\n\n", terrenos[i].titulo);

        break;

    case 'c': //casas
    case 'C':

        for (i = 0; i < MAX_ARRAY; i++) {
            if (casas[i].titulo[0] == '\0' || casas[i].ativo == 0)
                break;
        }

        printf("Por favor, digite as informações referentes à casa.\n\n");
        puts("Por favor, digite o titulo do anuncio da casa.");
        fgets(casas[i].titulo, MAX_ARRAY, stdin);
        puts("Digite a área do terreno:");
        scanf("%d%*c", &casas[i].areaTerreno);
        puts("Digite a área construida:");
        scanf("%d%*c", &casas[i].areaConstruida);
        puts("Digite o número de quartos:");
        scanf("%d%*c", &casas[i].numQuartos);
        puts("Digite o número de pavimentos:");
        scanf("%d%*c", &casas[i].numPavimentos);
        puts("Digite o valor da casa:");
        scanf("%d%*c", &casas[i].valor);
        puts("A casa está disponível para aluguel(a) ou venda(v)?.");
        scanf("%c%*c", &casas[i].aouv);
        printf("Por favor, digite a cidade da casa.\n");
        fgets(casas[i].endereco.cidade, MAX_ARRAY, stdin);
        printf("Por favor, digite o bairro da casa.\n");
        fgets(casas[i].endereco.bairro, MAX_ARRAY, stdin);
        printf("Por favor, digite a rua da casa.\n");
        fgets(casas[i].endereco.rua, MAX_ARRAY, stdin);
        printf("Por favor, digite o número da casa na rua.\n");
        scanf("%d%*c", &casas[i].endereco.num);
        printf("Por favor, digite o CEP da casa.\n");
        fgets(casas[i].endereco.cep, MAX_ARRAY, stdin);
        printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);
        casas[i].ativo = 1;

        break;

    case 'a': //apartamentos
    case 'A':

        for (i = 0; i < MAX_ARRAY; i++) {
            if (apts[i].titulo[0] == '\0' || apts[i].ativo == 0)
                break;
        }

        printf("Por favor, digite as informações referentes ao apartamento.\n\n");
        puts("Título do anuncio do apartamento.");
        fgets(apts[i].titulo, MAX_ARRAY, stdin);
        puts("Andar do apartamento:");
        scanf("%d%*c", &apts[i].andar);
        puts("Área do apartamento:");
        scanf("%d%*c", &apts[i].area);
        puts("Número de quartos do apartamento:");
        scanf("%d%*c", &apts[i].numQuartos);
        puts("Número de vagas de garagem do apartamento:");
        scanf("%d%*c", &apts[i].numVagasG);
        puts("Preço do condomínio:");
        scanf("%d%*c", &apts[i].valorCond);
        puts("Valor do apartamento:");
        scanf("%d%*c", &apts[i].valor);
        puts("O apartamento está disponível para aluguel(a) ou para venda(v)?:");
        scanf("%c%*c", &apts[i].aouv);
        printf("Cidade do apartamento:\n");
        fgets(apts[i].endereco.cidade, MAX_ARRAY, stdin);
        printf("Bairro do apartamento.\n");
        fgets(apts[i].endereco.bairro, MAX_ARRAY, stdin);
        printf("Rua do apartamento:\n");
        fgets(apts[i].endereco.rua, MAX_ARRAY, stdin);
        printf("Número do apartamento na rua:\n");
        scanf("%d%*c", &apts[i].endereco.num);
        printf("CEP do apartamento:\n");
        fgets(apts[i].endereco.cep, MAX_ARRAY, stdin);
        puts("Posição do apartamento:\n");
        fgets(apts[i].posicao, MAX_ARRAY, stdin);
        apts[i].ativo = 1;
        printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);

        break;
    }
}

void Read(){

    int valorBuscado, tipoRead;
    char alugOuVenda, tituloBuscado[100];

    printf("\tSelecione de que forma você quer ver os imoveis cadastrados:\n");
        printf("1) Mostrar todos os imóveis\n");
        printf("2) Mostrar os imóveis a partir de um preço\n");
        printf("3) Mostrar os imóveis para aluguel ou para venda\n");
        printf("4) Buscar um imóvel por título\n");
        printf("5) Buscar um imóvel por bairro\n");

        scanf("%d%*c", &tipoRead);

        system("cls");

        switch(tipoRead){
        case 2:
            printf("Selecione o valor mínimo dos imóveis buscados: ");
            scanf("%d%*c", &valorBuscado);
        break;

        case 3:
            printf("Selecione se você deseja ver os imóveis disponíveis para aluguel ou para venda (a ou v):");
            scanf("%c%*c", &alugOuVenda);
        break;

        case 4:
            printf("Digite o título do imóvel que você deseja procurar:\n");
            fgets(tituloBuscado, 100, stdin);
        break;

        case 5:
            printf("Digite o título do bairro que você deseja procurar os imóveis:\n");
            fgets(tituloBuscado, 100, stdin);
        break;
        }

        printf("\n\tTERRENOS\n\n");

        for(i = 0, j = 0; i < MAX_ARRAY; i++, j++){
            if(terrenos[i].titulo[0] == '\0')
            break;

            printf("\n");

            if(!terrenos[i].ativo){
                continue;
            //Em caso de imoveis deletados
            }

            switch(tipoRead){
            case 1:
                ImprimeTerreno(&terrenos[i]);
            break;

            case 2:
                if(terrenos[i].valor >= valorBuscado){
                    ImprimeTerreno(&terrenos[i]);
                }
            break;

            case 3:
                if(terrenos[i].aouv == alugOuVenda){
                    ImprimeTerreno(&terrenos[i]);
                }
            break;

            case 4:
                igual[0] = 1;
                for(k = 0; tituloBuscado[k] != '\0'; k++){
                    if(tituloBuscado[k] != terrenos[i].titulo[k]){
                        igual[0] = 0;
                        break;
                    }
                }

                if(igual[0]){
                    ImprimeTerreno(&terrenos[i]);
                }

                break;

            case 5:
                igual[0] = 1;
                for(k = 0; tituloBuscado[k] != '\0'; k++){
                    if(tituloBuscado[k] != terrenos[i].endereco.bairro[k]){
                        igual[0] = 0;
                        break;
                    }
                }

                if(igual[0]){
                    ImprimeTerreno(&terrenos[i]);
                }

            break;
            }
        }

        printf("\n\tCASAS\n\n");

        for(i = 0; i < MAX_ARRAY; i++){
            if(casas[i].titulo[0] == '\0')
            break;

            printf("\n");

            if(!casas[i].ativo){
                continue;
            //Em caso de imoveis deletados
            }
            switch(tipoRead){
                case 1:
                ImprimeCasa(&casas[i]);
            break;

            case 2:
                if(casas[i].valor >= valorBuscado){
                    ImprimeCasa(&casas[i]);
                }
            break;

            case 3:
                if(casas[i].aouv == alugOuVenda){
                    ImprimeCasa(&casas[i]);
                }
            break;

            case 4:
                igual[1] = 1;
                for(k = 0; tituloBuscado[k] != '\0'; k++){
                    if(tituloBuscado[k] != casas[i].titulo[k]){
                        igual[1] = 0;
                        break;
                    }
                }

                if(igual[1]){
                    ImprimeCasa(&casas[i]);
                }

            break;

            case 5:
                igual[1] = 1;
                for(k = 0; tituloBuscado[k] != '\0'; k++){
                    if(tituloBuscado[k] != casas[i].endereco.bairro[k]){
                        igual[1] = 0;
                        break;
                    }
                }

                if(igual[1]){
                    ImprimeCasa(&casas[i]);
                }

            break;

            }
        }

        printf("\n\tAPARTAMENTOS\n\n");

        for(i = 0; i < MAX_ARRAY; i++){
            if(apts[i].titulo[0] == '\0')
            break;

            printf("\n");

            if(!apts[i].ativo){
                continue;
                //Em caso de imoveis deletados
            }
            switch(tipoRead){
            case 1:
                ImprimeApt(&apts[i]);
            break;

            case 2:
                if(apts[i].valor >= valorBuscado){
                    ImprimeApt(&apts[i]);
                }
            break;

            case 3:
                if(apts[i].aouv == alugOuVenda){
                    ImprimeApt(&apts[i]);
                }
            break;

            case 4:
                igual[2] = 1;
                for(k = 0; tituloBuscado[k] != '\0'; k++){
                    if(tituloBuscado[k] != apts[i].titulo[k]){
                        igual[2] = 0;
                        break;
                    }
                }

                if(igual[2]){
                    ImprimeApt(&apts[i]);
                }

            break;

            case 5:
                igual[2] = 1;
                for(k = 0; tituloBuscado[k] != '\0'; k++){
                    if(tituloBuscado[k] != apts[i].endereco.bairro[k]){
                        igual[2] = 0;
                        break;
                    }
                }

                if(igual[2]){
                    ImprimeApt(&apts[i]);
                }

            break;

            }
        }

}

void Delete(){

    printf("Você deseja deletar um terreno(t), uma casa(c) ou um apartamento(a)?\n");

    scanf("%c%*c", &tipoImovel);

    switch (tipoImovel) {

            case 't': //terreno
            case 'T':

                puts("Digite o numero do terreno que voce deseja deletar:\n");

                int numeroterreno;

                for (i = 0, j = 0; i < MAX_ARRAY; i++, j++) {
                if (terrenos[j].titulo[0] == '\0')
                    break;

                    if (terrenos[j].ativo != 0){
                    printf("(%d): %s\n", i + 1, terrenos[j].titulo);
                    }else{
                    j--;
                    }
                    }
                    scanf("%d%*c", &numeroterreno);
                    terrenos[numeroterreno - (i-j) - 1].ativo = 0;
                    puts("Terreno deletado com sucesso.\n");

                    break;

                case 'c': //casa
                case 'C':

                    puts("Digite o numero da casa que voce deseja deletar:");

                    int numerocasa;

                    for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja deletar:\n");
                    if (casas[i].ativo != 0){
                    printf("(%d): %s\n", i + 1, casas[i].titulo);
                        }
                    scanf("%d%*c", &numerocasa+1);
                    casas[numerocasa].ativo = 0;
                    puts("Casa deletada com sucesso.");
                    break;
                    }
                    break;

                case 'a': //apartamento
                case 'A':

                    puts("Digite o numero do apartamento que voce deseja deletar:");

                    int numeroapt;

                    for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja deletar:\n");
                    if (apts[i].ativo != 0){
                    printf("(%d): %s\n", i + 1, apts[i].titulo);
                        }
                    scanf("%d%*c", &numeroapt+1);
                    apts[numeroapt].ativo = 0;
                    puts("Apartamento deletado com sucesso.");
                    break;
                    }
            }
}

void Update(){

    printf("Voce deseja atualizar um terreno(t), uma casa(c) ou um apartamento(a)?\n");

            scanf("%c%*c", &tipoImovel);
            switch (tipoImovel) {
            case 't': //terreno
            case 'T':

                printf("Selecione o terreno que voce deseja atualizar\n");

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0')
                        break;

                    if (terrenos[i].ativo != 0)
                    printf("(%d): %s\n", i + 1, terrenos[i].titulo);

                }

                scanf("%d%*c", &selecaoUpdate);
                selecaoUpdate--;

                printf("Por favor, digite as informações referentes ao terreno.\n\n");
                puts("Título do anúncio:\n");
                fgets(terrenos[selecaoUpdate].titulo, MAX_ARRAY, stdin);
                puts("Nova área:\n");
                scanf("%d%*c", &terrenos[selecaoUpdate].area);
                puts("Novo valor:\n");
                scanf("%d%*c", &terrenos[selecaoUpdate].valor);
                puts("O terreno está disponível para aluguel ou para venda? (a ou v)\n");
                scanf("%c%*c", &terrenos[selecaoUpdate].aouv);
                puts("Rua do terreno:\n");
                fgets(terrenos[selecaoUpdate].endereco.rua, MAX_ARRAY, stdin);
                puts("Número do terreno:\n");
                scanf("%d%*c", &terrenos[selecaoUpdate].endereco.num);
                puts("Bairro do terreno:\n");
                fgets(terrenos[selecaoUpdate].endereco.bairro, MAX_ARRAY, stdin);
                puts("Cidade do terreno:\n");
                fgets(terrenos[selecaoUpdate].endereco.cidade, MAX_ARRAY, stdin);
                puts("CEP do terreno:\n");
                fgets(terrenos[selecaoUpdate].endereco.cep, MAX_ARRAY, stdin);

                printf("\n\nTerreno atualizado com sucesso!\n\n", terrenos[selecaoUpdate].titulo);
                break;

            case 'c'://casa
            case 'C':

                printf("Selecione a casa que voce deseja atualizar\n");

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;

                    if(casas[i].ativo != 0)
                    printf("(%d): %s\n", i + 1, casas[i].titulo);
                }

                scanf("%d%*c", &selecaoUpdate);
                selecaoUpdate--;

                printf("Por favor, digite as informações referentes à casa.\n\n");
                puts("Título do anúncio:\n");
                fgets(casas[i].titulo, MAX_ARRAY, stdin);
                puts("Área do terreno:\n");
                scanf("%d", &casas[selecaoUpdate].areaTerreno);
                puts("Área construída:\n");
                scanf("%d", &casas[selecaoUpdate].areaConstruida);
                puts("Número de quartos:\n");
                scanf("%d", &casas[selecaoUpdate].numQuartos);
                puts("Número de pavimentos:\n");
                scanf("%d%*c", &casas[selecaoUpdate].numPavimentos);
                puts("Valor da casa:\n");
                scanf("%d%*c", &casas[selecaoUpdate].valor);
                puts("Está disponível para aluguel(a) ou para venda(v)?");
                scanf("%c%*c", &casas[selecaoUpdate].aouv);
                puts("Rua da casa:\n");
                fgets(casas[i].endereco.rua, MAX_ARRAY, stdin);
                puts("Número da casa:\n");
                scanf("%d%*c", &casas[i].endereco.num);
                puts("Bairro da casa:\n");
                fgets(casas[i].endereco.bairro, MAX_ARRAY, stdin);
                puts("Cidade da casa:\n");
                fgets(casas[i].endereco.cidade, MAX_ARRAY, stdin);
                puts("CEP da casa:\n");
                fgets(casas[i].endereco.cep, MAX_ARRAY, stdin);
                printf("\n\nCasa atualizada com sucesso!\n\n", casas[selecaoUpdate].titulo);

                break;

            case 'a'://apartamento
            case 'A':

                printf("Selecione o apartamento que voce deseja atualizar\n");

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts[i].titulo[0] == '\0')
                        break;

                    if(apts[i].ativo != 0)
                    printf("(%d): %s\n", i + 1, apts[i].titulo);

                }

                scanf("%d%*c", &selecaoUpdate);
                selecaoUpdate--;

                printf("Por favor, digite as informações referentes ao apartamento.\n\n");
                printf("Título do anúncio:\n");
                fgets(apts[selecaoUpdate].titulo, MAX_ARRAY, stdin);
                printf("Andar do apartamento:\n");
                scanf("%d%*c", &apts[selecaoUpdate].andar);
                printf("Área do apartamento:\n");
                scanf("%d%*c", &apts[selecaoUpdate].area);
                printf("Número de quartos do apartamento:\n");
                scanf("%d%*c", &apts[selecaoUpdate].numQuartos);
                printf("Número de vagas na garagem do apartamento:\n");
                scanf("%d%*c", &apts[selecaoUpdate].numVagasG);
                printf("Valor do condomínio do apartamento:\n");
                scanf("%d%*c", &apts[selecaoUpdate].valorCond);
                printf("Valor do apartamento:\n");
                scanf("%d%*c", &apts[selecaoUpdate].valor);
                printf("O apartamento está para alugar(a) ou vender(v)?\n");
                scanf("%d%*c", &apts[selecaoUpdate].aouv);
                printf("Posicao do apartamento:\n");
                fgets(apts[selecaoUpdate].posicao, MAX_ARRAY, stdin);
                printf("Rua do apartamento:\n");
                fgets(apts[selecaoUpdate].endereco.rua, MAX_ARRAY, stdin);
                printf("Bairro do apartamento:\n");
                fgets(apts[selecaoUpdate].endereco.bairro, MAX_ARRAY, stdin);
                printf("Número do apartamento:\n");
                scanf("%d%*c", &apts[selecaoUpdate].endereco.num);
                printf("Cidade do apartamento:\n");
                fgets(apts[selecaoUpdate].endereco.cidade, MAX_ARRAY, stdin);
                printf("CEP do apartamento:\n");
                fgets(apts[selecaoUpdate].endereco.cep, MAX_ARRAY, stdin);
                printf("\n\nApartamento atualizado com sucesso!\n\n", apts[selecaoUpdate].titulo);
                break;

                default:
                puts("Por favor, digite outra letra.\n");
            }
}
