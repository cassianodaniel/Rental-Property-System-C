#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX_ARRAY 100

extern void ListaImoveis();

typedef struct {
	char rua[MAX_ARRAY];
	int num;
	char bairro[MAX_ARRAY];
	char cidade[MAX_ARRAY];
	char cep[15];
	int ativo;

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

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    //int ativo = 1;
	char crud = '.', tipoImovel; //crud = create, read, update and delete
	/*declaração de arrays com suas respectivas variáveis a seguir.*/
	tterreno terrenos[MAX_ARRAY];
	tcasa casas[MAX_ARRAY];
	tapt apts[MAX_ARRAY];
	int i, selecaoUpdate;

	//for para ativar todos os imóveis
    int j;
    for (j = 0; j< MAX_ARRAY; j++){
    terrenos[j].ativo = 0;
    casas[j].ativo = 0;
    apts[j].ativo = 0;
    }

	while(crud != 's'){

        printf("Seja bem-vindo(a) ao simulador de imobiliária!\n\n"
        "C. CADASTRAR IMÓVEIS\n"
		"R. VISUALIZAR IMÓVEIS\n"
		"U. ATUALIZAR IMÓVEIS\n"
		"D. DELETAR IMÓVEIS\n"
		"S. SAIR\n\n");
        scanf("%c%*c", &crud);

        switch (crud) {

                //CREATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

            case 'c':
            case 'C': //create

            printf("O que você deseja cadastrar?\n\n"
                   "T. TERRENO\n"
                   "C. CASA\n"
                   "A. APARTAMENTO\n");

            scanf("%*c%c", &tipoImovel);

            switch (tipoImovel){

            case 't':
            case 'T': //terreno
                for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0') //caso encontre algum terreno sem nenhum caracter, pare.
                        break;
                }

                printf("Por favor, digite a área do terreno.\n");
                scanf("%d%*c", &terrenos[i].area);
                printf("Por favor, digite o valor do terreno.\n");
                scanf("%d%*c", &terrenos[i].valor);
                puts("Por favor, digite o título do anúncio do terreno.");
                fgets(terrenos[i].titulo, MAX_ARRAY, stdin);
                puts("O terreno está para aluguel(a), ou para venda(v)?.");
                scanf("%c%*c", &terrenos[i].aouv);
                printf("Por favor, digite a cidade do terreno.\n");
                fgets(terrenos[i].endereco.cidade, MAX_ARRAY, stdin);
                printf("Por favor, digite o bairro do terreno.\n");
                fgets(terrenos[i].endereco.bairro, MAX_ARRAY, stdin);
                printf("Por favor, digite a rua do terreno.\n");
                fgets(terrenos[i].endereco.rua, MAX_ARRAY, stdin);
                printf("Por favor, digite o número do terreno na rua.\n");
                scanf("%d%*c", &terrenos[i].endereco.num);
                printf("Por favor, digite o CEP do terreno.");
                fgets(terrenos[i].endereco.cep, MAX_ARRAY, stdin);
                terrenos[i].ativo = 1;
                printf("\n\n%s foi cadastrado com sucesso!\n\n", terrenos[i].titulo);

                break;

            case 'c': //casas
            case 'C':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;
                }

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
                puts("Por favor, digite o titulo do anuncio da casa.");
                fgets(casas[i].titulo, MAX_ARRAY, stdin);
                printf("Por favor, digite a cidade da casa.\n");
                fgets(casas[i].endereco.cidade, MAX_ARRAY, stdin);
                printf("Por favor, digite o bairro da casa.\n");
                fgets(casas[i].endereco.bairro, MAX_ARRAY, stdin);
                printf("Por favor, digite a rua da casa.\n");
                fgets(casas[i].endereco.rua, MAX_ARRAY, stdin);
                printf("Por favor, digite o número da casa na rua.\n");
                scanf("%d%*c", &casas[i].endereco.num);
                printf("Por favor, digite o CEP da casa.");
                fgets(casas[i].endereco.cep, MAX_ARRAY, stdin);
                printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);
                casas[i].ativo = 1;

                break;

            case 'a': //apartamentos
            case 'A':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts[i].titulo[0] == '\0')
                        break;
                }

                puts("Por favor, digite o andar do apartamento:");
                scanf("%d%*c", &apts[i].andar);
                puts("Por favor, digite a área do apartamento:");
                scanf("%d%*c", &apts[i].area);
                puts("Por favor, digite o número de quartos do apartamento:");
                scanf("%d%*c", &apts[i].numQuartos);
                puts("Por favor, digite o número de vagas de garagem do apartamento:");
                scanf("%d%*c", &apts[i].numVagasG);
                puts("Por favor, digite o preço do condomínio:");
                scanf("%d%*c", &apts[i].valorCond);
                puts("Por favor, digite o valor do imóvel:");
                scanf("%d%*c", &apts[i].valor);
                puts("O apartamento está disponível para aluguel(a) ou para venda(v)?:");
                scanf("%c%*c", &apts[i].aouv);
                puts("Por favor, digite o titulo do anuncio do apartamento.");
                fgets(apts[i].titulo, MAX_ARRAY, stdin);
                printf("Por favor, digite a cidade do apartamento.\n");
                fgets(apts[i].endereco.cidade, MAX_ARRAY, stdin);
                printf("Por favor, digite o bairro do apartamento.\n");
                fgets(apts[i].endereco.bairro, MAX_ARRAY, stdin);
                printf("Por favor, digite a rua do apartamento.\n");
                fgets(apts[i].endereco.rua, MAX_ARRAY, stdin);
                printf("Por favor, digite o número do apartamento na rua.\n");
                scanf("%d%*c", &apts[i].endereco.num);
                printf("Por favor, digite o CEP do apartamento\n.");
                fgets(apts[i].endereco.cep, MAX_ARRAY, stdin);
                puts("Por favor, digite a posição do apartamento");
                fgets(apts[i].posicao, MAX_ARRAY, stdin);
                apts[i].ativo = 1;
                printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
                break;

            }

            break;

            //UPDATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

        case 'u':
        case 'U': //update
            printf("Voce deseja atualizar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
            scanf("%*c%c", &tipoImovel);
            switch (tipoImovel) {
            case 't': //terreno
            case 'T':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja atualizar\n");
                                        if (terrenos[i].ativo != 0){
                    printf("(%d): %s\n", i + 1, terrenos[i].titulo);
                        }
                    }

                scanf("%d%*c", &selecaoUpdate);
                selecaoUpdate--;

                puts("Por favor, digite a nova área do terreno:");
                scanf("%d%*c", &terrenos[selecaoUpdate].area);
                puts("Por favor, digite o novo valor do terreno:");
                scanf("%d%*c", &terrenos[selecaoUpdate].valor);
                puts("O terreno está disponível para aluguel ou para venda?:");
                scanf("%c%*c", &terrenos[selecaoUpdate].aouv);
                puts("Por favor digite o título do anúncio do terreno.");
                fgets(terrenos[selecaoUpdate].titulo, MAX_ARRAY, stdin);
                puts("Por favor, digite a rua do terreno.");
                fgets(terrenos[selecaoUpdate].endereco.rua, MAX_ARRAY, stdin);
                puts("Por favor, digite o número do terreno");
                scanf("%d%*c", &terrenos[selecaoUpdate].endereco.num);
                puts("Por favor, digite o bairro do terreno");
                fgets(terrenos[selecaoUpdate].endereco.bairro, MAX_ARRAY, stdin);
                puts("Por favor, digite a cidade do terreno");
                fgets(terrenos[selecaoUpdate].endereco.cidade, MAX_ARRAY, stdin);
                puts("Por favor, digite o CEP do terreno");
                fgets(terrenos[selecaoUpdate].endereco.cep, MAX_ARRAY, stdin);

                printf("\n\n%s foi atualizado com sucesso!\n\n", terrenos[i].titulo);
                break;

            case 'c'://casa
            case 'C':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;
                    printf("Selecione a casa que voce deseja atualizar\n");
                    printf("(%d): %s\n", i + 1, casas[i].titulo);
                }

                scanf("%d%*c", &selecaoUpdate);
                selecaoUpdate--;

                puts("Por favor digite a área do terreno");
                scanf("%d", &casas[selecaoUpdate].areaTerreno);
                puts("Por favor digite a área construída do terreno");
                scanf("%d", &casas[selecaoUpdate].areaConstruida);
                puts("Por favor digite o número de quartos do terreno");
                scanf("%d", &casas[selecaoUpdate].numQuartos);
                puts("Por favor digite o número de pavimentos do terreno");
                scanf("%d", &casas[selecaoUpdate].numPavimentos);
                puts("Por favor digite o valor da casa do terreno");
                scanf("%d", &casas[selecaoUpdate].valor);
                puts("Está disponível para aluguel(a) ou para venda(v)?");
                scanf("%c%*c", &casas[selecaoUpdate].aouv);
                puts("Por favor digite o titulo do anuncio da casa");
                fgets(casas[i].titulo, MAX_ARRAY, stdin);
                puts("Por favor digite a rua da casa");
                fgets(casas[i].endereco.rua, MAX_ARRAY, stdin);
                puts("Por favor digite o numero da casa");
                scanf("%d%*c", &casas[i].endereco.num);
                puts("Por favor digite o bairro da casa");
                fgets(casas[i].endereco.bairro, MAX_ARRAY, stdin);
                puts("Por favor digite o cidade da casa");
                fgets(casas[i].endereco.cidade, MAX_ARRAY, stdin);
                puts("Por favor digite o CEP da casa");
                fgets(casas[i].endereco.cep, MAX_ARRAY, stdin);
                printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);

                break;

            case 'a'://apartamento
            case 'A':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts
                        [i].titulo[0] == '\0')
                        break;
                    printf("Selecione o apartamento que voce deseja atualizar\n");
                    printf("(%d): %s\n", i + 1, apts[i].titulo);

                }

                scanf("%d%*c", &selecaoUpdate);
                selecaoUpdate--;
                printf("Por favor, digite o andar do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].andar);
                printf("Por favor, digite a área do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].area);
                printf("Por favor, digite o número de quartos do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].numQuartos);
                printf("Por favor, digite o número de vagas na garagem do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].numVagasG);
                printf("Por favor, digite o valor do condomínio do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].valorCond);
                printf("Por favor, digite o valor do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].valor);
                printf("O apartamento está para alugar(a) ou vender(v)?.\n");
                scanf("%d", &apts[selecaoUpdate].aouv);
                printf("Por favor digite o titulo do anuncio do apartamento.\n");
                fgets(apts[i].titulo, MAX_ARRAY, stdin);
                printf("Por favor digite a posicao do apartamento.\n");
                fgets(apts[i].posicao, MAX_ARRAY, stdin);
                printf("Por favor digite a rua do apartamento.\n");
                fgets(apts[i].endereco.rua, MAX_ARRAY, stdin);
                printf("Por favor digite o bairro do apartamento.\n");
                fgets(apts[i].endereco.bairro, MAX_ARRAY, stdin);
                printf("Por favor digite o número do apartamento.\n");
                scanf("%d%*c", &apts[i].endereco.num);
                printf("Por favor digite a cidade do apartamento.\n");
                fgets(apts[i].endereco.cidade, MAX_ARRAY, stdin);
                printf("Por favor digite o CEP do apartamento.\n");
                printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
                break;

                default:
                puts("Por favor, digite outra letra.");
            }



        //FUNÇÃO PARA REMOVER UM DETERMINADO IMÓVEL
            case 'd': //delete
            case 'D':
                printf("Voce deseja deletar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
                scanf("%*c%c", &tipoImovel);
                switch (tipoImovel) {
                case 't': //terreno
                case 'T':

                    puts("Digite o numero do terreno que voce deseja deletar:\n");

                    int numeroterreno;

                    for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja deletar:\n");
                    if (terrenos[i].ativo != 0){
                    printf("(%d): %s\n", i + 1, terrenos[i].titulo);
                        }
                    scanf("%d%*c", &numeroterreno+1);
                    terrenos[numeroterreno].ativo = 0;
                    puts("Terreno deletado com sucesso.");
                    break;
                    }
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
                    break;
                }
            }
        }
	}

/*
void ListaImoveis(){
puts("Esta é a lista de imóveis cadastrados em nossa imobiliária");
int auxt = 2;
int auxc = 2;
int auxa = 2;
        for (int i = 0; i < MAX_ARRAY; i++) {  //caso encontre algum terreno sem nenhum caracter, pare.
            if (terrenos[i].titulo[0] == '\0'){
                auxt = 1;}
                if (auxt > 1){
                    if (terrenos[i].ativo == 1){
                printf("%d%*c", terrenos[i].titulo);
                    }
                }
            else if(casas[i].titulo[0] == '\0'){
                auxc = 1;
                if (auxc > 1){
                    if (casas[i].ativo == 1){
                    printf("%d%*c", casas[i].titulo);
                }
            }
        }
            else if(apts[i].titulo[0] == '\0'){
                auxc = 1;
                if (auxa > 1){
                    if (apts[i].ativo == 1){
                printf("%d%*c", apts[i].titulo);
                }
            }
        }
}
*/
