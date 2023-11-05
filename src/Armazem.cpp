#include "../include/Unidade.hpp"
#include "../include/Produto.hpp"
#include "../include/Armazem.hpp"

namespace Sistema_de_Loja {
	
	Armazem::Armazem() {}
	Armazem::~Armazem() {}
	
	// Singleton
	Armazem* Armazem::criar_armazem() {
		if(instancia == NULL)
			instancia = new Armazem();
				
		return instancia;
	}
	
	void Armazem::deletar_armazem() {
		std::map<int, Unidade*>::iterator it;
		
		// Liberando a memória alocada para as unidades	
		for(it = unidades.begin(); it != unidades.end(); ++it) {
			unidades[it->first] = NULL;
			delete unidades[it->first];
		}
			
		instancia = NULL;
		delete instancia;
	}
	
	std::map<int, Unidade*> Armazem::get_unidades() {
		return unidades;
	}
	
	Unidade* Armazem::get_unidade(int id) {
		auto it = unidades.find(id);
		
		if(it != unidades.end())
			return unidades[id];
		else
			throw std::runtime_error("Unidade " + std::to_string(id) + " não está presente no estoque!");
	}
	
	void Armazem::cadastrar_unidade(int id, Produto *produto, std::tm data_fabricacao, std::tm data_validade) {
		auto it = unidades.find(id);
		
		// Verificar se a chave já está em uso no map unidades
		if(it == unidades.end()) {
			unidades[id] = new Unidade(id, produto, data_fabricacao, data_validade);
			
			// Aumenta o estoque do produto
			produto->set_quantidade_em_estoque(produto->get_quantidade_em_estoque() + 1);
		}
		else 
			throw std::runtime_error("Id " + std::to_string(id) + " já está em uso!");
		
		
	}
	
	void Armazem::vender_unidade(int id) {
		auto it = unidades.find(id);
		
		if(it != unidades.end()) { // verifica se a unidade está no estoque
			// Diminui o estoque do produto
			Produto *p = unidades[id]->get_produto();
			p->set_quantidade_em_estoque(p->get_quantidade_em_estoque() - 1);
		
			// Apaga a unidade do armazem
			unidades[id] = NULL;
			delete unidades[id];
			unidades.erase(id);
		}
		else
			throw std::runtime_error("Unidade " + std::to_string(id) + " não está presente no estoque!");
	}
	
}