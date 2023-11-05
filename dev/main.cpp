#include <iostream>
#include <ctime>
#include "../include/Armazem.hpp"
#include "../include/Produto.hpp"
#include "../include/Unidade.hpp"
#include "../include/NotaFiscal.hpp"
#include "../src/utils/ErrorHandler.hpp"

using namespace std;
using namespace Sistema_de_Loja;

int main() {
	Armazem *armazem = Armazem::criar_armazem();
	ErrorHandler error_handler;
	
	tm df, dv;
	df.tm_mday = 19;
	df.tm_mon = 10;
	df.tm_year = 2022;
	
	dv.tm_mday = 2;
	dv.tm_mon = 4;
	dv.tm_year = 2025;
	
	Produto sabao("Sabão em pó Omo", 19.75);
	Produto arroz("Arroz celia", 10.50);
	Produto macarrao("Macarrao braz", 5.70);
	Produto vinho("Vinho São Bernardo", 12.20);
	
	try {
		armazem->cadastrar_unidade(1, &sabao, df, dv); 	// Unidade com id = 1, produto = sabao, data de fabricação = df e data de validade = dv
		armazem->cadastrar_unidade(2, &arroz, df, dv);
		armazem->cadastrar_unidade(2, &macarrao, df, dv);
		armazem->cadastrar_unidade(4, &vinho, df, dv);
	}
	catch (const std::exception& e) {
		error_handler.handleException(e);
	}
	
	NotaFiscal n("6578919191");
	
	try {
		n.adicionar_item(armazem, 1); // unidade de id 1 armazenada no armazem agora faz parte da nota
		n.adicionar_item(armazem, 2);
		n.adicionar_item(armazem, 3);
		n.adicionar_item(armazem, 78);
	}
	catch (const std::exception& e) {
		error_handler.handleException(e);
	}
	
	std::map<int, Unidade*>::iterator it; // iterator para acessar as unidades do armazem
	std::map<int, Unidade*> estoque = armazem->get_unidades();
	
	cout << "ESTOQUE: " << endl;
	for(it = estoque.begin(); it != estoque.end(); it++) {
		Unidade *u = it->second;	
		
		cout << u->get_id() << " - " << u->get_produto()->get_nome() << " - " << u->get_produto()->get_preco() << endl;
	}
	
	cout << endl << endl;
	
	cout << n.emitir_nota_fiscal(armazem) << endl << endl;
	
	estoque = armazem->get_unidades();
	
	cout << "ESTOQUE: " << endl;
	for(it = estoque.begin(); it != estoque.end(); it++) {
		Unidade *u = it->second;	
		
		cout << u->get_id() << " - " << u->get_produto()->get_nome() << " - " << u->get_produto()->get_preco() << endl;
	}
}