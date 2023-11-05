#include <iostream>
#include <string>

namespace Sistema_de_Loja {
	
	class ErrorHandler {
		public:
			ErrorHandler();
			
			void reportError(std::string message);
			
			void handleException(const std::exception& e);
	};

}
