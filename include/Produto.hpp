#pragma once

#include <string>
#include <ctime>

namespace Sistema_de_Loja {
	
	class Produto {
		
	private:
		std::string nome;
		double preco;
		int quantidade_em_estoque;
		
	public:
		Produto(std::string nome, double preco);
		~Produto();
	
		std::string get_nome() const;
		void set_nome(std::string nome);
		
		double get_preco() const;
		void set_preco(double preco);
		
		int get_quantidade_em_estoque();
		void set_quantidade_em_estoque(int qtt);
		
	};
	
}