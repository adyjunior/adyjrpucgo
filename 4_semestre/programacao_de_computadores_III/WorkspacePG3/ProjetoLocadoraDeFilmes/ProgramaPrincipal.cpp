#include<iostream>
#include"Cliente.h"
#include"Filme.h"
#include"Locacao.h"
#include"Persistencia.h"
#include"MapeadorDeDados.h"
#include"MapeadorDeDadosCliente.h"
#include"Interface.h"
using namespace std;
int main(void)
{
	// Criando Instancia da Persistencia
	Persistencia locadora;
	Interface::menu01(&locadora);
}



/*
	ControleCliente controleCliente(&locadora);


	// Testando a Classe Cliente
	Cliente cliente1(5);
	Cliente cliente2(6);
	Cliente cliente3(7);
	Cliente cliente4(8);
	
	cout<<endl<<"***********   TESTE CLIENTE  - GRAVACAO DO OBJETO ********************************"<<endl;
	cliente1.atribuirNome("Jose da Silva");
	cliente1.atribuirTelefone(9971);
	cliente1.atribuirEmail("josedasilva@email.com");
	
	cliente2.atribuirNome("Maria da Silva");
	cliente2.atribuirTelefone(9972);
	cliente2.atribuirEmail("Mariadasilva@email.com");
	
	cliente3.atribuirNome("Antonio da Silva");
	cliente3.atribuirTelefone(9973);
	cliente3.atribuirEmail("Antoniodasilva@email.com");
	
	cliente4.atribuirNome("Tania da Silva");
	cliente4.atribuirTelefone(9974);
	cliente4.atribuirEmail("Taniadasilva@email.com");
	
	if(controleCliente.incluirCliente(&cliente1)) cout<<"\n Gravacao 1 ok \n";
	else cout<< "\n Gravacao 1 errada \n";
	
	if(controleCliente.incluirCliente(&cliente2)) cout<<"\n Gravacao 2 ok \n";
	else cout<< "\n Gravacao 2 errada \n";

	if(controleCliente.incluirCliente(&cliente3)) cout<<"\n Gravacao 3 ok \n";
	else cout<< "\n Gravacao 3 errada \n";

	if(controleCliente.incluirCliente(&cliente4)) cout<<"\n Gravacao 4 ok \n";
	else cout<< "\n Gravacao 4 errada \n";

	cout<<endl<<"***********   TESTE CLIENTE  - RECUPERACAO DO OBJETO ********************************"<<endl;
	
	Cliente clienteRecuperado(6); 
	if(controleCliente.consultarCliente(&clienteRecuperado)){
		cout<<"\n Identificador: "<<clienteRecuperado.obterIdentificador();
		cout<<"\n Tipo da Classe: "<<clienteRecuperado.obterTipoDaClasse();
		cout<<"\n Nome: "<<clienteRecuperado.obterNome();
		cout<<"\n Telefone: "<<clienteRecuperado.obterTelefone();
		cout<<"\n Email: "<<clienteRecuperado.obterEmail()<<endl;
	}else cout<< "\n Recuperacao errada 6 \n";

	Cliente clienteRecuperado2(8); 
	if(controleCliente.consultarCliente(&clienteRecuperado2)){
		cout<<"\n Identificador: "<<clienteRecuperado2.obterIdentificador();
		cout<<"\n Tipo da Classe: "<<clienteRecuperado2.obterTipoDaClasse();
		cout<<"\n Nome: "<<clienteRecuperado2.obterNome();
		cout<<"\n Telefone: "<<clienteRecuperado2.obterTelefone();
		cout<<"\n Email: "<<clienteRecuperado2.obterEmail()<<endl;
	}else cout<< "\n Recuperacao errada 8 \n";

	Cliente clienteRecuperado3(18); 
	if(controleCliente.consultarCliente(&clienteRecuperado3)){
		cout<<"\n Identificador: "<<clienteRecuperado3.obterIdentificador();
		cout<<"\n Tipo da Classe: "<<clienteRecuperado3.obterTipoDaClasse();
		cout<<"\n Nome: "<<clienteRecuperado3.obterNome();
		cout<<"\n Telefone: "<<clienteRecuperado3.obterTelefone();
		cout<<"\n Email: "<<clienteRecuperado3.obterEmail()<<endl;
	}else cout<< "\n Recuperacao errada 18 \n";

	cout<<endl<<"***********   TESTE CLIENTE  - ALTERACAO DO OBJETO ********************************"<<endl;
	
	Cliente clienteAlterado(6);
	clienteAlterado.atribuirNome("Nome Alterado");
	clienteAlterado.atribuirTelefone(99999);
	clienteAlterado.atribuirEmail("nomealterado@email.com.br");
	controleCliente.alterarCliente(&clienteAlterado);
	

	
	// Testando a Classe Filme
	Filme filme(1);
	
	cout<<endl<<endl<<"***********   TESTE FILME  ********************************"<<endl;
	filme.atribuirTitulo("Gladiador");
	filme.atribuirValorDeCompra(15);
	filme.atribuirSituacao(true);
	
	cout<<endl<<"Identificador: "<<filme.obterIdentificador();
	cout<<endl<<"Tipo da Classe: "<<filme.obterTipoDaClasse();
	cout<<endl<<"Titulo: "<<filme.obterTitulo();
	cout<<endl<<"Valor de Compra: "<<filme.obterValorDeCompra();
	cout<<endl<<boolalpha<<"Situacao: "<<filme.obterSituacao();
	cout<<endl<<"Desmaterializar: "<<filme.desmaterializar();
	
	cout<<endl<<endl<<"Teste da Materializacao - 2;Tropa de Elite ;25;0;";
	filme.materializar("2;Tropa de Elite ;25;0");
	cout<<endl<<"Identificador: "<<filme.obterIdentificador();
	cout<<endl<<"Tipo da Classe: "<<filme.obterTipoDaClasse();
	cout<<endl<<"Titulo: "<<filme.obterTitulo();
	cout<<endl<<"Valor de Compra: "<<filme.obterValorDeCompra();
	cout<<endl<<boolalpha<<"Situacao: "<<filme.obterSituacao()<<endl;
	
	// Testando a Classe Locacao
	Locacao locar(99);
		
	cout<<endl<<endl<<"***********   TESTE LOCACAO  ********************************"<<endl;
	locar.atribuirIdCliente(5);
	locar.atribuirIdFilme(9);
	locar.atribuirValorDeCompra(15);
	locar.atribuirSituacao(false);
	
	cout<<endl<<"Identificador: "<<locar.obterIdentificador();
	cout<<endl<<"Tipo da Classe: "<<locar.obterTipoDaClasse();
	cout<<endl<<"Identificador Cliente: "<<locar.obterIdCliente();
	cout<<endl<<"Identificador Filme: "<<locar.obterIdFilme();
	cout<<endl<<"Valor de Compra: R$"<<locar.obterValorDeCompra();
	cout<<endl<<boolalpha<<"Situacao: "<<locar.obterSituacao()<<endl;
	cout<<endl<<"Desmaterializar: "<<locar.desmaterializar();
	
	cout<<endl<<endl<<"Teste da Materializacao - 2;99;98;55;1;";
	locar.materializar("2;99;98;55;true;");
	cout<<endl<<"Identificador: "<<locar.obterIdentificador();
	cout<<endl<<"Tipo da Classe: "<<locar.obterTipoDaClasse();
	cout<<endl<<"Identificador Cliente: "<<locar.obterIdCliente();
	cout<<endl<<"Identificador Filme: "<<locar.obterIdFilme();
	cout<<endl<<"Valor de Compra: R$"<<locar.obterValorDeCompra();
	cout<<endl<<boolalpha<<"Situacao: "<<locar.obterSituacao()<<endl;


}
*/
