#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX_ARRAY 100


void MostrarTela() {
	printf("Seja bem-vindo(a) ao simulador de imobiliária!\n\n"
        "C. CADASTRAR IMÓVEIS\n"
		"R. VISUALIZAR IMÓVEIS\n"
		"U. ATUALIZAR IMÓVEIS\n"
		"D. DELETAR IMÓVEIS\n"
		"S. SAIR\n\n");
}
void SelecaodeImovelC() {
	printf("Voce deseja cadastrar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
}
void SelecaodeImovelU() {
	printf("Voce deseja atualizar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
}
void MostrarTelaTerreno() {
	printf("Por favor digite a area, o valor e se o terreno esta disponivel para aluguel ou venda(a ou v).\n");
}
void MostrarTelaTerreno2() {
	printf("Por favor digite o titulo do anuncio do terreno e seu endereco completo(Rua, numero, bairro, cidade e cep).\n");
}
void MostrarTelaCasa() {
	printf("Por favor digite a area do terreno, a area construida, o numero de quartos, "
		"o numero de pavimentos, o valor da casa e se ela esta disponivel para aluguel ou venda(a ou v).\n");
}
void MostrarTelaCasa2() {
	printf("Por favor digite o titulo do anuncio da casa e seu endereco completo(Rua, numero, bairro, cidade e cep).\n");
}
void MostrarTelaApt() {
	printf("Por favor digite o andar do apartamento, a sua area, o numero de quartos e de vagas na garagem, "
		"o preco do condominio, o valor do imovel e se ele esta disponivel para aluguel ou venda(a ou v).\n");
}
void MostrarTelaApt2() {
	printf("Por favor digite o titulo do anuncio do apartamento, sua posicao e seu endereco completo(Rua, numero, bairro, cidade e cep).\n");
}

void DeletarImovel() {
	printf("Voce deseja deletar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
}

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
    terrenos[j].ativo = 1;
    casas[j].ativo = 1;
    apts[j].ativo = 1;
    }

	while(crud != 's'){

        MostrarTela();
        scanf("%c", &crud);

        switch (crud) {

                //CREATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

        case 'c':
        case 'C': //create
            printf("O que você deseja cadastrar?\n\n"
                   "T. TERRENO\n"
                   "C. CASA\n"
                   "A. APARTAMENTO\n");
            scanf("%*c%c", &tipoImovel);
            switch (tipoImovel)
            {
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

                printf("\n\n%s foi cadastrado com sucesso!\n\n", terrenos[i].titulo);

                break;
            case 'c': //casas
            case 'C':
                for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;
                }

                puts("Digite a área do terreno:");
                scanf("%d", &casas[i].areaTerreno);
                puts("Digite a área construida:");
                scanf("%d", &casas[i].areaConstruida);
                puts("Digite o número de quartos:");
                scanf("%d", &casas[i].numQuartos);
                puts("Digite o número de pavimentos:");
                scanf("%d", &casas[i].numPavimentos);
                puts("Digite o valor da casa:");
                scanf("%d%*c", &casas[i].valor);
                puts("A casa está disponível para aluguel(a) ou venda(v)?.");
                scanf("%c", &casas[i].aouv);

                puts("Por favor, digite o titulo do anuncio da casa.");
                fgets(casas[i].titulo, MAX_ARRAY, stdin);

                printf("Por favor, digite a cidade da casa.\n");
                fgets(casas[i].endereco.cidade, MAX_ARRAY+1, stdin);

                printf("Por favor, digite o bairro da casa.\n");
                fgets(casas[i].endereco.bairro, MAX_ARRAY+1, stdin);

                printf("Por favor, digite a rua da casa.\n");
                fgets(casas[i].endereco.rua, MAX_ARRAY+1, stdin);

                printf("Por favor, digite o número da casa na rua.\n");
                scanf("%d%*c", &casas[i].endereco.num);

                printf("Por favor, digite o CEP da casa.");
                fgets(casas[i].endereco.cep, MAX_ARRAY+1, stdin);

                printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);
                break;

            case 'a': //apartamentos
            case 'A':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts[i].titulo[0] == '\0')
                        break;
                }
                puts("Por favor, digite o andar do apartamento:");
                scanf("%d", &apts[i].andar);
                puts("Por favor, digite a área do apartamento:");
                scanf("%d", &apts[i].area);
                puts("Por favor, digite o número de quartos do apartamento:");
                scanf("%d", &apts[i].numQuartos);
                puts("Por favor, digite o número de vagas de garagem do apartamento:");
                scanf("%d", &apts[i].numVagasG);
                puts("Por favor, digite o preço do condomínio:");
                scanf("%d", &apts[i].valorCond);
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

                printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
                break;

            }

            break;

            //UPDATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

        case 'u':
        case 'U': //update
            SelecaodeImovelU(); //"Voce deseja atualizar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
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

                scanf("%d", &selecaoUpdate);
                selecaoUpdate--;

                MostrarTelaTerreno(); //"Por favor digite a area, o valor e se o terreno esta disponivel para aluguel ou venda(a ou v).\n"

                scanf("%d%d%*c%c%*c", &terrenos[selecaoUpdate].area, &terrenos[selecaoUpdate].valor, &terrenos[selecaoUpdate].aouv);
                MostrarTelaTerreno2(); //"Por favor digite o titulo do anuncio do terreno e seu endereco completo(Rua, numero, bairro, cidade e cep).\n"
                fgets(terrenos[selecaoUpdate].titulo, MAX_ARRAY+1, stdin);
                fgets(terrenos[selecaoUpdate].endereco.rua, MAX_ARRAY+1, stdin);
                scanf("%d%*c", &terrenos[selecaoUpdate].endereco.num);
                fgets(terrenos[selecaoUpdate].endereco.bairro, MAX_ARRAY+1, stdin);
                fgets(terrenos[selecaoUpdate].endereco.cidade, MAX_ARRAY+1, stdin);
                fgets(terrenos[selecaoUpdate].endereco.cep, MAX_ARRAY+1, stdin);
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

                scanf("%d", &selecaoUpdate);
                selecaoUpdate--;

                MostrarTelaCasa();

                scanf("%d%d%d%d%d%*c%c%*c", &casas[selecaoUpdate].areaTerreno, &casas[selecaoUpdate].areaConstruida,
                    &casas[selecaoUpdate].numQuartos, &casas[selecaoUpdate].numPavimentos, &casas[selecaoUpdate].valor, &casas[selecaoUpdate].aouv);

                MostrarTelaCasa2();

                fgets(casas[i].titulo, MAX_ARRAY+1, stdin);
                fgets(casas[i].endereco.rua, MAX_ARRAY+1, stdin);
                scanf("%d%*c", &casas[i].endereco.num);
                fgets(casas[i].endereco.bairro, MAX_ARRAY+1, stdin);
                fgets(casas[i].endereco.cidade, MAX_ARRAY+1, stdin);
                fgets(casas[i].endereco.cep, MAX_ARRAY+1, stdin);
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

                scanf("%d", &selecaoUpdate);
                selecaoUpdate--;
                MostrarTelaApt();

                scanf("%d%d%d%d%d%d%*c%c%*c", &apts[selecaoUpdate].andar, &apts[selecaoUpdate].area,
                    &apts[selecaoUpdate].numQuartos, &apts[selecaoUpdate].numVagasG, &apts[selecaoUpdate].valorCond, &apts[selecaoUpdate].valor, &apts[selecaoUpdate].aouv);

                MostrarTelaApt2();

                fgets(apts[i].posicao, MAX_ARRAY+1, stdin);
                fgets(apts[i].titulo, MAX_ARRAY+1, stdin);
                fgets(apts[i].endereco.rua, MAX_ARRAY+1, stdin);
                scanf("%d%*c", &apts[i].endereco.num);
                fgets(apts[i].endereco.bairro, MAX_ARRAY+1, stdin);
                fgets(apts[i].endereco.cidade, MAX_ARRAY+1, stdin);
                fgets(apts[i].endereco.cep, MAX_ARRAY+1, stdin);
                printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
                break;


                default:
                puts("Por favor, digite outra letra.");
            }



        //FUNÇÃO PARA REMOVER UM DETERMINADO IMÓVEL
            case 'd': //delete
            case 'D':
                DeletarImovel(); //"Voce deseja deletar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
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
                printf("%d", terrenos[i].titulo);
                    }
                }
            else if(casas[i].titulo[0] == '\0'){
                auxc = 1;
                if (auxc > 1){
                    if (casas[i].ativo == 1){
                    printf("%d", casas[i].titulo);
                }
            }
        }
            else if(apts[i].titulo[0] == '\0'){
                auxc = 1;
                if (auxa > 1){
                    if (apts[i].ativo == 1){
                printf("%d", apts[i].titulo);
                }
            }
        }
}
*/
