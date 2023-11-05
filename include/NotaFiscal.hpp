#pragma once

#include <string>
#include <vector>

namespace Sistema_de_Loja {
	
	class Armazem;
	class Produto;
	class Unidade;
	
	class NotaFiscal {
		
	private:
		std::string cpf;
		std::vector<Unidade *> items;
		double valor_total = 0.0; // O valor da nota inicia como zero
		
	public:
		NotaFiscal(std::string cpf);
		~NotaFiscal();
		
		std::string get_cpf() const;
		
		double get_valor_total() const;
		
		std::vector<Unidade *> get_items() const;
		
		// Adicionar item para compra
		void adicionar_item(Armazem *armazem, int id);
		// Remover item para compra
		void remover_item(int id);
		// Emitir a nota final
		std::string emitir_nota_fiscal(Armazem *armazem);
	
	private:
		// Formatação da nota para impressão
		std::string formatar_nota_fiscal();
		
	};
	
}