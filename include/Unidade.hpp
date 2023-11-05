#pragma once

#include <string>
#include <ctime> // Para as estruturas de data e hora tm

namespace Sistema_de_Loja {
	
	class Produto;
	
	class Unidade {
		
		private:
			int id;
			Produto *produto;
			std::tm data_fabricacao;
			std::tm data_validade;
			
		public:
			Unidade(int id, Produto *produto, std::tm data_fabricacao, std::tm data_validade);
			~Unidade();
			
			int get_id() const;
			
			Produto* get_produto() const;
			
			std::tm get_data_fabricacao() const;
			
			std::tm get_data_validade() const;
			
	};
	
}