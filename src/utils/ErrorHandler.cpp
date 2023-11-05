#include "ErrorHandler.hpp"

namespace Sistema_de_Loja {
	
	ErrorHandler::ErrorHandler() {}
	
	void ErrorHandler::reportError(std::string message) {
		std::cerr << "Erro: " << message << std::endl;
	}
	
	void ErrorHandler::handleException(const std::exception& e) {
		reportError("Exceção lançada: " + std::string(e.what()));
	}
	
}