#pragma once

#include <map>
#include <ctime>

namespace Sistema_de_Loja {
	
	class Produto;
	class Unidade;
	
	class Armazem {
		
	private:
		// Unidades mapeadas com inteiro id
		std::map<int, Unidade*> unidades;
		inline static Armazem *instancia;
		
		Armazem();
		~Armazem();
		
	public:
		// Singleton, só pode haver uma instância de armazem
		static Armazem *criar_armazem();
		void deletar_armazem();
		
		// Retorna o map com as unidades em estoque
		std::map<int, Unidade*> get_unidades();
		
		// Retorna a unidade com o id passado
		Unidade *get_unidade(int id);
		
		void cadastrar_unidade(int id, Produto *produto, std::tm data_fabricacao, std::tm data_validade);
		
		void vender_unidade(int id);
		
	};
	
}