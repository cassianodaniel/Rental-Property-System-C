#include <stdio.h>

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

typedef struct {
	char rua[100];
	int num;
	char bairro[100];
	char cidade[100];
	char cep[15];

} tendereco;

typedef struct {
	char aouv; //área ou valor
	char titulo[100];
	int areaTerreno, areaConstruida, numQuartos, numPavimentos;
	int valor;
	tendereco endereco;

} tcasa;

typedef struct {
	char aouv; //área ou valor
	char titulo[100];
	char posicao[100];
	int area, numQuartos, numVagasG, andar;
	int valor, valorCond;
	tendereco endereco;

} tapt;

typedef struct {
	char aouv; //área ou valor
	char titulo[100];
	int area;
	int valor;
	tendereco endereco;

} tterreno;

int main(void) {

	char crud  = '.', tipoImovel; //crud = create, read, update and delete
	/*declaração de arrays com suas respectivas variáveis a seguir.*/
	tterreno terrenos[100]; 
	tcasa casas[100];
	tapt apts[100];
	int i, selecaoUpdate;

	while (crud != 's') {

		MostrarTela(); //bem-vindo 
		scanf("%c", &crud);

		switch (crud) {
		case 'c': //create
			SelecaodeImovelC(); //"Voce deseja cadastrar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
			scanf("%*c%c", &tipoImovel);
			switch (tipoImovel) {
				case 't': //terreno
					for (i = 0; i < 100; i++) {
						if (terrenos[i].titulo[0] == '\0') //caso encontre algum terreno sem nenhum caracter, pare.
							break;
					}
					MostrarTelaTerreno(); //"Por favor digite a area, o valor e se o terreno esta disponivel para aluguel ou venda(a ou v).\n"
					scanf("%d%d%*c%c%*c", &terrenos[i].area, &terrenos[i].valor, &terrenos[i].aouv); //cadastramento no array do terreno não existente
					MostrarTelaTerreno2(); //"Por favor digite o titulo do anuncio do terreno e seu endereco completo(Rua, numero, bairro, cidade e cep).\n"
					fgets(&terrenos[i].titulo, 101, stdin);
					fgets(&terrenos[i].endereco.rua, 101, stdin);
					scanf("%d%*c", &terrenos[i].endereco.num);
					fgets(&terrenos[i].endereco.bairro, 101, stdin);
					fgets(&terrenos[i].endereco.cidade, 101, stdin);
					fgets(&terrenos[i].endereco.cep, 101, stdin);
					printf("\n\n%s foi cadastrado com sucesso!\n\n", terrenos[i].titulo);
					break;
					}
				case 'c': //casas

					for (i = 0; i < 100; i++) {
						if (casas[i].titulo[0] == '\0')
							break;
					}

					MostrarTelaCasa();

					scanf("%d%d%d%d%d%*c%c%*c", &casas[i].areaTerreno, &casas[i].areaConstruida,
						&casas[i].numQuartos, &casas[i].numPavimentos, &casas[i].valor, &casas[i].aouv);

					MostrarTelaCasa2();

					fgets(&casas[i].titulo, 101, stdin);
					fgets(&casas[i].endereco.rua, 101, stdin);
					scanf("%d%*c", &casas[i].endereco.num);
					fgets(&casas[i].endereco.bairro, 101, stdin);
					fgets(&casas[i].endereco.cidade, 101, stdin);
					fgets(&casas[i].endereco.cep, 101, stdin);
					printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);
					break;

				case 'a': //apartamentos

					for (i = 0; i < 100; i++) {
						if (apts[i].titulo[0] == '\0')
							break;
					}

					MostrarTelaApt();

					scanf("%d%d%d%d%d%d%*c%c%*c", &apts[i].andar, &apts[i].area,
						&apts[i].numQuartos, &apts[i].numVagasG, &apts[i].valorCond, &apts[i].valor, &apts[i].aouv);

					MostrarTelaApt2();

					fgets(&apts[i].posicao, 101, stdin);
					fgets(&apts[i].titulo, 101, stdin);
					fgets(&apts[i].endereco.rua, 101, stdin);
					scanf("%d%*c", &apts[i].endereco.num);
					fgets(&apts[i].endereco.bairro, 101, stdin);
					fgets(&apts[i].endereco.cidade, 101, stdin);
					fgets(&apts[i].endereco.cep, 101, stdin);
					printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
					break;

				}

			break;

		case 'u':
			SelecaodeImovelU();
			scanf("%*c%c", &tipoImovel);
			switch (tipoImovel) {
			case 't':

				for (i = 0; i < 100; i++) {
					printf("Selecione o terreno que voce deseja atualizar\n");
					printf("(%d): %s\n", i + 1, terrenos[i].titulo);
					break;
				}

				scanf("%d", &selecaoUpdate);
				selecaoUpdate--;

				MostrarTelaTerreno();

				scanf("%d%d%*c%c%*c", &terrenos[selecaoUpdate].area, &terrenos[selecaoUpdate].valor, &terrenos[selecaoUpdate].aouv);
				MostrarTelaTerreno2();
				fgets(&terrenos[selecaoUpdate].titulo, 101, stdin);
				fgets(&terrenos[selecaoUpdate].endereco.rua, 101, stdin);
				scanf("%d%*c", &terrenos[selecaoUpdate].endereco.num);
				fgets(&terrenos[selecaoUpdate].endereco.bairro, 101, stdin);
				fgets(&terrenos[selecaoUpdate].endereco.cidade, 101, stdin);
				fgets(&terrenos[selecaoUpdate].endereco.cep, 101, stdin);
				printf("\n\n%s foi atualizado com sucesso!\n\n", terrenos[i].titulo);
				break;
				for (i = 0; i < 100; i++) {
					if (terrenos[i].titulo[0] == '\0')
						break;
				}
			case 'c':

				for (i = 0; i < 100; i++) {
					printf("Selecione a casa que voce deseja atualizar\n");
					printf("(%d): %s\n", i + 1, casas[i].titulo);
					break;
				}

				scanf("%d", &selecaoUpdate);
				selecaoUpdate--;

				MostrarTelaCasa();

				scanf("%d%d%d%d%d%*c%c%*c", &casas[selecaoUpdate].areaTerreno, &casas[selecaoUpdate].areaConstruida,
					&casas[selecaoUpdate].numQuartos, &casas[selecaoUpdate].numPavimentos, &casas[selecaoUpdate].valor, &casas[selecaoUpdate].aouv);

				MostrarTelaCasa2();

				fgets(&casas[i].titulo, 101, stdin);
				fgets(&casas[i].endereco.rua, 101, stdin);
				scanf("%d%*c", &casas[i].endereco.num);
				fgets(&casas[i].endereco.bairro, 101, stdin);
				fgets(&casas[i].endereco.cidade, 101, stdin);
				fgets(&casas[i].endereco.cep, 101, stdin);
				printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);
				break;

			case 'a':

				for (i = 0; i < 100; i++) {
					printf("Selecione o terreno que voce deseja atualizar\n");
					printf("(%d): %s\n", i + 1, apts[i].titulo);
					break;
				}

				scanf("%d", &selecaoUpdate);
				selecaoUpdate--;
				MostrarTelaApt();

				scanf("%d%d%d%d%d%d%*c%c%*c", &apts[selecaoUpdate].andar, &apts[selecaoUpdate].area,
					&apts[selecaoUpdate].numQuartos, &apts[selecaoUpdate].numVagasG, &apts[selecaoUpdate].valorCond, &apts[selecaoUpdate].valor, &apts[selecaoUpdate].aouv);

				MostrarTelaApt2();

				fgets(&apts[i].posicao, 101, stdin);
				fgets(&apts[i].titulo, 101, stdin);
				fgets(&apts[i].endereco.rua, 101, stdin);
				scanf("%d%*c", &apts[i].endereco.num);
				fgets(&apts[i].endereco.bairro, 101, stdin);
				fgets(&apts[i].endereco.cidade, 101, stdin);
				fgets(&apts[i].endereco.cep, 101, stdin);
				printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
				break;

			}

			break;

		default:
			puts("Por favor, digite outra letra.");
		}
	}
	return 0;
}
