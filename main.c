#include <iostream>
#include <string>
#include <Imovel.h>
#include <Casa.h>
#include <Terreno.h>
#include <Apartamento.h>
#include <locale.h>
#include <Endereco.h>
#include <SistemaImobiliaria.h>
#include <vector>
#include <fstream>

using namespace std;

int main(){
setlocale(LC_ALL, "Portuguese");
    int i, menu = 0;
    SistemaImobiliaria sist;
  while(menu != 6){
    cout <<("========Seja bem-vindo ao nosso sistema de imobiliária!========\n\n");
    cout << ("1. Criar Imóvel \n");
    cout << ("2. Buscar Imóvel \n");
    cout << ("3. Listar Imóvel \n");
    cout << ("4. Editar Imóvel \n");
    cout << ("5. Deletar Imóvel \n");
    cout << ("6. Sair\n\n");

    cin >> menu;
        switch(menu){
            case 1:{//Criar
                cout << "\n1. Criar terreno" << endl;
                cout << "2. Criar casa" << endl;
                cout << "3. Criar apartamento\n" << endl;
                int menu123;
                cin >> menu123;
                    switch(menu123){
                    case 1:
                        {
                        cout <<("Por favor, digite as informações referentes ao terreno.\n\n");
                        Terreno *t1 = new Terreno();
                        Endereco ende = Endereco();
                        cout <<("Título do anúncio do terreno:\n");
                        string vardescricao;
                        cin.ignore();
                        getline(cin, vardescricao);

                        t1->setTitulo(vardescricao);
                        cout <<("Descrição do terreno:\n");

                        getline(cin, vardescricao);

                        t1->setDescricao(vardescricao);
                        cout <<("Área do terreno:\n");
                        double vararea;
                        cin >> vararea;
                        t1->setArea(vararea);
                        cout <<("Valor do terreno:\n");
                        double varvalor;
                        cin >> varvalor;
                        t1->setValor(varvalor);
                        cout <<("O terreno está para venda(1), ou para aluguel(2)?\n");
                        int varaouv1;
                        bool varaouv2;
                        cin >> varaouv1;
                        if(varaouv1 == 1){
                            varaouv2 = true;
                        }
                        else{
                            varaouv2 = false;
                        }
                        t1->setAouV(varaouv2);
                        cout <<("Cidade do terreno:\n");
                        string varcidade;
                        cin.ignore();
                        getline(cin, varcidade);

                        ende.cidade = varcidade;
                        cout <<("Bairro do terreno:\n");
                        string varbairro;

                        getline(cin, varbairro);

                        ende.bairro = varbairro;
                        cout <<("Rua do terreno:\n");
                        string varrua;

                        getline(cin, varrua);

                        ende.rua = varrua;
                        cout <<("Número do terreno na rua:\n");
                        int varnumero;
                        cin >> varnumero;
                        ende.numero = varnumero;
                        cout <<("CEP do terreno:\n");
                        string varcep;
                        cin.ignore();
                        getline(cin, varcep);

                        ende.cep = varcep;
                        t1->disponivel = true;
                        t1->setEndereco(ende);
                        sist.cadastraImovel(t1);
                        cout << "O terreno " << t1->getTitulo() << " foi registrado com sucesso.\n\n" << endl;
                        break;
                        }
                    case 2:
                        {
                        cout <<("Por favor, digite as informações referentes à casa.\n\n");
                        Casa c1 = Casa();
                        cout <<("Título do anúncio da casa:");
                        string vardescricao2;
                            cin.ignore();
                        getline(cin, vardescricao2);

                        c1.setDescricao(vardescricao2);
                        cout << "Número de pavimentos: ";
                        int varpavimentos;
                        cin >> varpavimentos;
                        c1.setNUMPAVIMEN(varpavimentos);
                        cout << "Número de quartos: ";
                        int varnumquartos;
                        cin >> varnumquartos;
                        c1.setNUMQUARTOS(varnumquartos);
                        cout << "Área do terreno da casa: ";
                        double varareaterrenocasa;
                        cin >> varareaterrenocasa;
                        c1.setAREATER(varareaterrenocasa);
                        //area construida
                        cout << "Área construída:\n";
                        double varareaconstruidacasa;
                        cin >> varareaconstruidacasa;
                        c1.setAREACONST(varareaconstruidacasa);
                        cout <<("Valor da casa:\n");
                        double varvalor2;
                        cin >> varvalor2;
                        c1.setValor(varvalor2);
                        cout <<("A casa está para venda(1), ou para aluguel(2)?\n");
                        int varaouv1;
                        bool varaouv2;
                        cin >> varaouv1;
                        if(varaouv1 == 1){
                            varaouv2 = true;
                        }
                        else{
                            varaouv2 = false;
                        }
                        c1.setAouV(varaouv2);
                        cout <<("Cidade da casa:\n");
                        string varcidade2;
                        cin.ignore();
                        getline(cin, varcidade2);

                        c1.getEndereco().setCidade(varcidade2);
                        cout <<("Bairro da casa:\n");
                        string varbairro2;
                        cin.ignore();
                        getline(cin, varbairro2);

                        c1.getEndereco().setBairro(varbairro2);
                        cout <<("Rua da casa:\n");
                        string varrua2;
                        cin.ignore();
                        getline(cin, varrua2);

                        c1.getEndereco().setRua(varrua2);
                        cout <<("Número da casa na rua:\n");
                        int varnumero2;
                        cin >> varnumero2;
                        c1.getEndereco().setNumero(varnumero2);
                        cout <<("CEP da casa:\n");
                        string varcep2;
                        cin.ignore();
                        getline(cin, varcep2);

                        c1.getEndereco().setCEP(varcep2);
                        c1.disponivel = true;
                        cout << "A casa " << c1.getDescricao() << " foi registrada com sucesso." << endl;
                        }
                        break;
                    case 3:
                        {
                         cout <<("Por favor, digite as informações referentes ao apartamento.\n\n");
                        Apartamento ap1 = Apartamento();
                        cout <<("Título do anúncio do apartamento:");
                        string vardescricao3;
                        cin.ignore();
                        getline(cin, vardescricao3);

                        ap1.setDescricao(vardescricao3);
                        cout <<("Área do apartamento: \n");
                        double varareaapartamento;
                        cin >> varareaapartamento;
                        ap1.area = varareaapartamento;
                        cout <<("Número de quartos: \n");
                        int varnumeroquartos;
                        cin >> varnumeroquartos;
                        ap1.nquartos = varnumeroquartos;
                        cout <<("Posicao do apartamento: \n");
                        string varposicao;
                        cin.ignore();
                        getline(cin, varposicao);

                        cout <<("Número de andares do apartamento: \n");
                        int varandar;
                        cin >> varandar;
                        ap1.andar = varandar;
                        cout <<("Valor do condomínio do apartamento: \n");
                        double varvalorcondominio;
                        cin >> varvalorcondominio;
                        ap1.setValor(varvalorcondominio);
                        cout <<("Número de vagas na garagem do apartamento: \n");
                        int varnumerovagasgaragemapt;
                        cin >> varnumerovagasgaragemapt;
                        ap1.nvagasgaragem = varnumerovagasgaragemapt;
                        cout <<("O apartamento está para venda(1), ou para aluguel(2)?");
                        int varaouv1;
                        bool varaouv2;
                        cin >> varaouv1;
                        if(varaouv1 == 1){
                            varaouv2 = true;
                        }
                        else{
                            varaouv2 = false;
                        }
                        ap1.setAouV(varaouv2);
                        cout <<("Cidade do apartamento:\n");
                        string varcidade3;
                        cin.ignore();
                        getline(cin, varcidade3);

                        ap1.getEndereco().setCidade(varcidade3);
                        cout <<("Bairro do apartamento:\n");
                        string varbairro3;
                        cin.ignore();
                        getline(cin, varbairro3);

                        ap1.getEndereco().setBairro(varbairro3);
                        cout <<("Rua do apartamento:\n");
                        string varrua3;
                        cin.ignore();
                        getline(cin, varrua3);

                        ap1.getEndereco().setRua(varrua3);
                        cout <<("Número do apartamento na rua:\n");
                        int varnumero3;
                        cin >> varnumero3;
                        ap1.getEndereco().setNumero(varnumero3);
                        cout <<("CEP do apartamento:\n");
                        string varcep3;
                        getline(cin, varcep3);
                        ap1.getEndereco().setCEP(varcep3);
                        ap1.disponivel = true;
                        cout << "O apartamento " << ap1.getDescricao() << " foi registrado com sucesso." << endl;
                        break;
                        }
                    }
            }
            break;
            case 2:{//Buscar
                cout << ("1. Buscar imóvel por título: \n");
                cout << ("2. Buscar imóvel por bairro: \n");
                cout << ("3. Buscar imóvel por cidade: \n");
                cout << ("4. Buscar por preco de imóvel: \n");
                int opcao;
                cin >> opcao;
                switch(opcao){
                    case 1:{
                        cout << ("Busque o imóvel por título: \n");
                        string busca;
                        cin.ignore();
                        getline(cin, busca);

                        sist.buscaImovelTit(busca);
                        break;
                    }
                    case 2:{
                        cout << ("Busque o imóvel por bairro: \n");
                        string busca;
                        cin.ignore();
                        getline(cin, busca);

                        sist.buscaImovelBai(busca);
                        break;
                    }
                    case 3:{
                        cout << ("Busque o imóvel por cidade: \n");
                        string busca;
                        cin.ignore();
                        getline(cin, busca);

                        sist.buscaImovelCid(busca);
                        break;
                    }
                    case 4:{
                        cout << ("Busque o imóvel por valor: \n");
                        cout << ("Para não ter valor mínimo ou máximo, digite 0: \n");
                        int minimo;
                        int maximo;
                        cin >> minimo;
                        cin >> maximo;
                        sist.buscaImovelPreco(minimo, maximo);
                        break;
                    }
                }
            }
            break;
            case 3:{//Listar
                cout << "1. Visualizar todos os imóveis: \n";
                cout << "2. Visualizar os imóveis por tipo: \n";
                cout << "3. Visualizar os imóveis por aluguel ou venda: \n";
                int visualizar;
                cin >> visualizar;
                switch(visualizar){
                    case 1:{
                        sist.mostraTodos();
                        break;
                    }
                    case 2:{
                        cout << ("Tipo de imóvel: 1 - TERRENO, 2 - CASA, 3 - APARTAMENTO") << endl;
                        int tipo;
                        cin >> tipo;
                        sist.mostraPorTipo(tipo);
                        break;
                    }
                    case 3:{
                        cout << "A para ALUGUEL e V para VENDA: \n" << endl;
                        bool seletor;
                        cin >> seletor;
                        sist.mostraAouV(seletor);
                        break;
                    }
                }
            }
            break;
            case 4:{//Editar
                cout << ("Busque pelo imóvel: ");
                string busca;
                cin.ignore();
                getline(cin, busca);
                int tipo;
                cout << ("Digite o tipo do imóvel");
                cin >> tipo;
                sist.atualizaImovel(busca, tipo); //já contém os inputs do case 4: EDITAR
            }
            break;
            case 5:{//Deletar
                cout << ("Delete o imóvel: ");
                string busca;
                cin.ignore();
                getline(cin, busca);
                sist.removeImovel(busca);
            }
            break;
            case 6:{//Sair
                fstream arquivo;
                arquivo.open("lista.txt");
                arquivo << "Teste";
                for(int i=0; sist.imovs.size(); i++){
                    arquivo << sist.imovs[i]->getTitulo();
                }
                arquivo << sist.ImprimeImovel(*t1, 1) << endl;

                //ARQUIVO__________TERRENO__________________________________________
                /*arquivo << "Descrição: " << t1->getDescricao() << endl;
                arquivo << "Valor: " << t1->getValor() << endl;
                if (t1->getAouV()) {
                    arquivo << "Disponível para venda" << endl;
                }
                else {
                    arquivo << "Disponível para aluguel" << endl;
                }
                arquivo << "Área: " << t1->area << endl;
                arquivo << "   Endereco:" << endl;
                arquivo << "Rua: " << t1->getEndereco().rua << endl;
                arquivo << "Número: " << t1->getEndereco().numero << endl;
                arquivo << "CEP: " << t1->getEndereco().cep << endl;
                arquivo << "Bairro: " << t1->getEndereco().bairro << endl;
                arquivo << "Cidade: " << t1->getEndereco().cidade << endl;
                arquivo << "\n" << endl;
                //_______ARQUIVO_______CASAS______________________________________________
                arquivo << "Titulo: " << c1.getTitulo() << endl;
                arquivo << "Descrição: " << c1.getDescricao() << endl;
                arquivo << "Valor: " << c1.getValor() << endl;
                if (c1.getAouV()) {
                    arquivo << "Disponível para venda" << endl;
                }
                else {
                    arquivo << "Disponível para aluguel" << endl;
                }
                arquivo << "Área do terreno: " << c1.areaTer << endl;
                arquivo << "Área construída: " << c1.areaConst << endl;
                arquivo << "Número de pavimentos: " << c1.numPavimen << endl;
                arquivo << "Número de quartos: " << c1.numQuartos << endl;
                arquivo << "   Endereco:" << endl;
                arquivo << "Rua: " << c1.getEndereco().rua << endl;
                arquivo << "Número: " << c1.getEndereco().numero << endl;
                arquivo << "CEP: " << c1.getEndereco().cep << endl;
                arquivo << "Bairro: " << c1.getEndereco().bairro << endl;
                arquivo << "Cidade: " << c1.getEndereco().cidade << endl;
                arquivo << "\n" << endl;
                //_______ARQUIVO_______APARTAMENTO______________________________________________
                arquivo <<": " << ap1.getTitulo() << "\n" << endl;
                arquivo << "Descrição: " << ap1.getDescricao() << endl;
                arquivo << "Valor: " << ap1.getValor() << endl;
                if (ap1.getAouV()) {
                    arquivo << "Disponível para venda" << endl;
                }
                else {
                    arquivo << "Disponível para aluguel" << endl;
                }
                arquivo << "Área: " << ap1.area << endl;
                arquivo << "Andar: " << ap1.andar << endl;
                arquivo << "Número de vagas na garagem: " << ap1.nvagasgaragem << endl;
                arquivo << "Número de quartos: " << ap1.nquartos << endl;
                arquivo << "Posição do apartamento: " << ap1.posicao << endl;
                arquivo << "   Endereco:" << endl;
                arquivo << "Rua: " << ap1.getEndereco().rua << endl;
                arquivo << "Número: " << ap1.getEndereco().numero << endl;
                arquivo << "CEP: " << ap1.getEndereco().cep << endl;
                arquivo << "Bairro: " << ap1.getEndereco().bairro << endl;
                arquivo << "Cidade: " << ap1.getEndereco().cidade << endl;
                arquivo << "\n" << endl;
                arquivo.close();
                }*/
                return 0;
            }
            break;
            }
    }
return 0;
}
