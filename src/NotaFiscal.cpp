#include "../include/NotaFiscal.hpp"
#include "../include/Armazem.hpp"
#include "../include/Unidade.hpp"
#include "../include/Produto.hpp"

namespace Sistema_de_Loja {
	
	NotaFiscal::NotaFiscal(std::string cpf) : cpf(cpf) {}
	NotaFiscal::~NotaFiscal() {}
	
	std::string NotaFiscal::get_cpf() const {
		return cpf;
	}
	
	double NotaFiscal::get_valor_total() const {
		return valor_total;
	}
	
	std::vector<Unidade *> NotaFiscal::get_items() const {
		return items;
	}
	
	void NotaFiscal::adicionar_item(Armazem *armazem, int id) {
		try {
			Unidade *unidade = armazem->get_unidade(id);
			items.push_back(unidade);
			valor_total+=unidade->get_produto()->get_preco();
		} 
		catch (const std::exception& e) {
			throw; // Relança a exceção caso seja capturada
		}
	}
	
	void NotaFiscal::remover_item(int id) {
		for(int i=0; i<items.size(); i++)
			if(items[i]->get_id() == id) {
				Produto *produto_unidade = items[i]->get_produto();
				
				items.erase(items.begin() + i);
				valor_total-=produto_unidade->get_preco();
				
				produto_unidade = NULL;
				break;
			}
	}
	
	std::string NotaFiscal::emitir_nota_fiscal(Armazem *armazem) {
		std::string nota_impressa = formatar_nota_fiscal();
		
		for(Unidade* u : items) {
			Produto *produto_unidade = u->get_produto();
			
			armazem->vender_unidade(u->get_id());
			
			produto_unidade = NULL;
		}
		
		return nota_impressa;
	}
	
	// Método privado
	std::string NotaFiscal::formatar_nota_fiscal() {
		std::string nota;
		
		nota = "CPF: " + cpf;
		nota+="\n";
		
		for(Unidade* u : items) {
			Produto* produto_unidade = u->get_produto();
			
			nota+=produto_unidade->get_nome();
			nota+=" - ";
			nota+=std::to_string(produto_unidade->get_preco());
			nota+=" - ";
			nota+=std::to_string(u->get_id());
			nota+="\n";
			
			produto_unidade = NULL;
		}
		
		nota+="------------------------\n";
		nota+="VALOR TOTAL: " + std::to_string(valor_total);
		
		return nota;
	}
	
}