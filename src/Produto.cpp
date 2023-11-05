#include "../include/Produto.hpp"
#include "../include/Unidade.hpp"

namespace Sistema_de_Loja {
	
	Produto::Produto(std::string nome, double preco) : nome(nome), preco(preco) {}
	Produto::~Produto() {}
	
	std::string Produto::get_nome() const {
		return nome;
	}
	void Produto::set_nome(std::string nome) {
		this->nome = nome;
	}
	
	double Produto::get_preco() const {
		return preco;
	}
	void Produto::set_preco(double preco) {
		this->preco = preco;
	}
	
	int Produto::get_quantidade_em_estoque() {
		return quantidade_em_estoque;
	}
	void Produto::set_quantidade_em_estoque(int qtt) {
		quantidade_em_estoque = qtt;
	}
	
}



