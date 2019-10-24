//SISTEMA IMOBILIÁRIO
#include <stdio.h>

void MostrarTela(){
    printf("\tSeja bem-vindo(a) ao simulador de imobiliaria!\nNele, voce podera cadastrar"
           "novos imoveis, ler os cadastrados de diversas formas, edita-los e deleta-los.\n"
           "Digite a letra da opcao que voce deseja selecionar: cadastrar(c), visualizar(r), editar(u)"
           "ou deletar(d) um imovel.\n"
           "Se voce deseja sair do simulador, digite s.\n");
}

void SelecaodeImovel(){
    printf("Voce deseja cadastrar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
}

void MostrarTelaTerreno(){
    printf("Por favor digite a area, o valor e se o terreno esta disponivel para aluguel ou venda(a ou v).\n");
}
void MostrarTelaTerreno2(){
    printf("Por favor digite o titulo do terreno e seu endereco completo(Rua, numero, bairro, cidade e cep).\n");
}

typedef struct {
    char rua[100];
    int num;
    char bairro[100];
    char cidade[100];
    char cep[15];

} tendereco;

typedef struct {
    char aouv;
    char titulo[100];
    int area;
    int valor;
    tendereco endereco;

} tterreno;

int main(void){

    char crud = '.', tipoImovel;
    tterreno terrenos[100];
    int i;

    while(crud != 's'){

        MostrarTela();
        scanf("%c",&crud);

        switch(crud){
            case 'c':
                SelecaodeImovel();
                scanf("%*c%c",&tipoImovel);
                    switch(tipoImovel){
                        case 't':
                            for(i = 0; i < 100; i++){
                                if(terrenos[i].titulo[0] == '\0')
                                break;
                            }
                            MostrarTelaTerreno();
                            scanf("%d%d%*c%c%*c", &terrenos[i].area, &terrenos[i].valor, &terrenos[i].aouv);
                            MostrarTelaTerreno2();
                            fgets(&terrenos[i].titulo, 101, stdin);
                            fgets(&terrenos[i].endereco.rua, 101, stdin);
                            scanf("%d%*c", &terrenos[i].endereco.num);
                            fgets(&terrenos[i].endereco.bairro, 101, stdin);
                            fgets(&terrenos[i].endereco.cidade, 101, stdin);
                            fgets(&terrenos[i].endereco.cep, 101, stdin);
                            break;
                    }

            break;
            //case 'r':

            default:
                puts("Por favor, digite outra letra.");
        }
    }
    return 0;
}
