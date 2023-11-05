#include "../include/Unidade.hpp"
#include "../include/Produto.hpp"

namespace Sistema_de_Loja {

	Unidade::Unidade(int id, Produto *produto, std::tm data_fabricacao, std::tm data_validade): id(id), produto(produto), data_fabricacao(data_fabricacao), data_validade(data_validade) {}
	Unidade::~Unidade() {}
	
	int Unidade::get_id() const {
		return id;
	}
	
	Produto* Unidade::get_produto() const {
		return produto;
	}
	
	std::tm Unidade::get_data_fabricacao() const {
		return data_fabricacao;
	}
	
	std::tm Unidade::get_data_validade() const {
		return data_validade;
	}
	
}