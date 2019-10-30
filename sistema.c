
#include <stdio.h>
#define MAX_ARRAY 100


void MostrarTela() {
	printf("\tSeja bem-vindo(a) ao simulador de imobiliaria!\nNele, voce podera cadastrar"
		"novos imoveis, ler os cadastrados de diversas formas, edita-los e deleta-los.\n"
		"Digite a letra da opcao que voce deseja selecionar: cadastrar(c), visualizar(r), editar(u)"
		"ou deletar(d) um imovel.\n"
		"Se voce deseja sair do simulador, digite s.\n");
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
    //int ativo = 1;
	char crud = '.', tipoImovel; //crud = create, read, update and delete
	/*declaração de arrays com suas respectivas variáveis a seguir.*/
	tterreno terrenos[MAX_ARRAY];
	tcasa casas[MAX_ARRAY];
	tapt apts[MAX_ARRAY];
	int i, selecaoUpdate;

	while(crud != 's'){

        MostrarTela();
        scanf("%c", &crud);

        switch (crud) {

                //CREATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

        case 'c': //create
            SelecaodeImovelC(); //"Voce deseja cadastrar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
            scanf("%*c%c", &tipoImovel);
            switch (tipoImovel)
            {
            case 't': //terreno
                for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0') //caso encontre algum terreno sem nenhum caracter, pare.
                        break;
                }
                MostrarTelaTerreno(); //"Por favor digite a area, o valor e se o terreno esta disponivel para aluguel ou venda(a ou v).\n"
                scanf("%d%d%*c%c%*c", &terrenos[i].area, &terrenos[i].valor, &terrenos[i].aouv); //cadastramento no array do terreno não existente
                MostrarTelaTerreno2(); //"Por favor digite o titulo do anuncio do terreno e seu endereco completo(Rua, numero, bairro, cidade e cep).\n"
                //fgets utilizado em vez de scanf por motivo das informações que serão incluídas no array conterem espaçamentos
                fgets(&terrenos[i].titulo, MAX_ARRAY+1, stdin);
                fgets(&terrenos[i].endereco.rua, MAX_ARRAY+1, stdin);
                scanf("%d%*c", &terrenos[i].endereco.num);
                fgets(&terrenos[i].endereco.bairro, MAX_ARRAY+1, stdin);
                fgets(&terrenos[i].endereco.cidade, MAX_ARRAY+1, stdin);
                fgets(&terrenos[i].endereco.cep, MAX_ARRAY+1, stdin);
                terrenos[i].ativo = 1;
                printf("\n\n%s foi cadastrado com sucesso!\n\n", terrenos[i].titulo);
                break;
            case 'c': //casas

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;
                }

                MostrarTelaCasa(); //"Digite área do terreno, a área construida, o numero de quartos, o numero de pavimentos, o valor da casa e se ela está disponível para aluguel ou venda(a ou v).\n"

                scanf("%d%d%d%d%d%*c%c%*c", &casas[i].areaTerreno, &casas[i].areaConstruida,
                    &casas[i].numQuartos, &casas[i].numPavimentos, &casas[i].valor, &casas[i].aouv);

                MostrarTelaCasa2(); //Por favor digite o titulo do anuncio da casa e seu endereco completo(Rua, numero, bairro, cidade e cep)
                //fgets utilizado em vez de scanf por motivo das informações que serão incluídas no array conterem espaçamentos
                fgets(&casas[i].titulo, MAX_ARRAY+1, stdin);
                fgets(&casas[i].endereco.rua, MAX_ARRAY+1, stdin);
                scanf("%d%*c", &casas[i].endereco.num);
                fgets(&casas[i].endereco.bairro, MAX_ARRAY+1, stdin);
                fgets(&casas[i].endereco.cidade, MAX_ARRAY+1, stdin);
                fgets(&casas[i].endereco.cep, MAX_ARRAY+1, stdin);
                printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);
                break;

            case 'a': //apartamentos

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts[i].titulo[0] == '\0')
                        break;
                }
                MostrarTelaApt();//"Por favor digite o andar do apartamento, a sua area, o numero de quartos e de vagas na garagem, o preco do condominio, o valor do imovel e se ele esta disponivel para aluguel ou venda(a ou v).\n"

                scanf("%d%d%d%d%d%d%*c%c%*c", &apts[i].andar, &apts[i].area,
                    &apts[i].numQuartos, &apts[i].numVagasG, &apts[i].valorCond, &apts[i].valor, &apts[i].aouv);

                MostrarTelaApt2(); //"Por favor digite o titulo do anuncio do apartamento, sua posicao e seu endereco completo(Rua, numero, bairro, cidade e cep).\n"
                //fgets utilizado em vez de scanf por motivo das informações que serão incluídas no array conterem espaçamentos
                fgets(&apts[i].posicao, MAX_ARRAY+1, stdin);
                fgets(&apts[i].titulo, MAX_ARRAY+1, stdin);
                fgets(&apts[i].endereco.rua, MAX_ARRAY+1, stdin);
                scanf("%d%*c", &apts[i].endereco.num);
                fgets(&apts[i].endereco.bairro, MAX_ARRAY+1, stdin);
                fgets(&apts[i].endereco.cidade, MAX_ARRAY+1, stdin);
                fgets(&apts[i].endereco.cep, MAX_ARRAY+1, stdin);
                printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
                break;

            }

            break;

            //UPDATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

        case 'u': //update
            SelecaodeImovelU(); //"Voce deseja atualizar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
            scanf("%*c%c", &tipoImovel);
            switch (tipoImovel) {
            case 't': //terreno

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja atualizar\n");
                    printf("(%d): %s\n", i + 1, terrenos[i].titulo);
                }

                scanf("%d", &selecaoUpdate);
                selecaoUpdate--;

                MostrarTelaTerreno(); //"Por favor digite a area, o valor e se o terreno esta disponivel para aluguel ou venda(a ou v).\n"

                scanf("%d%d%*c%c%*c", &terrenos[selecaoUpdate].area, &terrenos[selecaoUpdate].valor, &terrenos[selecaoUpdate].aouv);
                MostrarTelaTerreno2(); //"Por favor digite o titulo do anuncio do terreno e seu endereco completo(Rua, numero, bairro, cidade e cep).\n"
                fgets(&terrenos[selecaoUpdate].titulo, MAX_ARRAY+1, stdin);
                fgets(&terrenos[selecaoUpdate].endereco.rua, MAX_ARRAY+1, stdin);
                scanf("%d%*c", &terrenos[selecaoUpdate].endereco.num);
                fgets(&terrenos[selecaoUpdate].endereco.bairro, MAX_ARRAY+1, stdin);
                fgets(&terrenos[selecaoUpdate].endereco.cidade, MAX_ARRAY+1, stdin);
                fgets(&terrenos[selecaoUpdate].endereco.cep, MAX_ARRAY+1, stdin);
                printf("\n\n%s foi atualizado com sucesso!\n\n", terrenos[i].titulo);
                break;

            case 'c'://casa

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

                fgets(&casas[i].titulo, MAX_ARRAY+1, stdin);
                fgets(&casas[i].endereco.rua, MAX_ARRAY+1, stdin);
                scanf("%d%*c", &casas[i].endereco.num);
                fgets(&casas[i].endereco.bairro, MAX_ARRAY+1, stdin);
                fgets(&casas[i].endereco.cidade, MAX_ARRAY+1, stdin);
                fgets(&casas[i].endereco.cep, MAX_ARRAY+1, stdin);
                printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);
                break;

            case 'a'://apartamento

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

                fgets(&apts[i].posicao, MAX_ARRAY+1, stdin);
                fgets(&apts[i].titulo, MAX_ARRAY+1, stdin);
                fgets(&apts[i].endereco.rua, MAX_ARRAY+1, stdin);
                scanf("%d%*c", &apts[i].endereco.num);
                fgets(&apts[i].endereco.bairro, MAX_ARRAY+1, stdin);
                fgets(&apts[i].endereco.cidade, MAX_ARRAY+1, stdin);
                fgets(&apts[i].endereco.cep, MAX_ARRAY+1, stdin);
                printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
                break;


                default:
                puts("Por favor, digite outra letra.");
            }



        //FUNÇÃO PARA REMOVER UM DETERMINADO IMÓVEL
            case 'd': //delete
                DeletarImovel(); //"Voce deseja deletar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
                scanf("%*c%c", &tipoImovel);
                switch (tipoImovel) {
                case 't': //terreno

                    printf("Digite o numero do terreno que voce deseja deletar\n");

                    int numeroterreno;

                    for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja deletar\n");
                    if (terrenos[i].ativo != 0){
                    printf("(%d): %s\n", i + 1, terrenos[i].titulo);
                        }
                    scanf("%d%*c", &numeroterreno);
                    terrenos[numeroterreno].ativo = 0;
                    puts("Terreno deletado com sucesso.");
                    break;
                    }

                case 'c': //casa

                    printf("Digite o número da casa que voce deseja deletar\n");

                    int numerocasa;

                    for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;
                    printf("Selecione a casa que voce deseja deletar\n");
                    printf("(%d): %s\n", i + 1, casas[i].titulo);
                    }
                    scanf("%d%*c", &numerocasa);
                    casas[numerocasa].ativo = 0;
                    puts("Casa deletada com sucesso.");
                    break;

                case 'a': //apartamento
                    printf("Digite o número do apartamento que voce deseja deletar\n");
                    int numeroapartamento;

                    for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o apartamento que voce deseja deletar\n");
                    printf("(%d): %s\n", i + 1, apts[i].titulo);
                    }
                    scanf("%d%*c", &numeroapartamento);
                    apts[numeroapartamento].ativo = 0;
                    puts("Apartamento deletado com sucesso.");
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
