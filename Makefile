COMPILER = clang++
SRC_DIR = src
UTILS_DIR = src/utils
DEV_DIR = dev
OBJ_DIR = obj

.PHONY: clean

# 
# binario arquivo main
# 
main_bin: nota_fiscal error_handler
	$(COMPILER) $(DEV_DIR)/main.cpp $(OBJ_DIR)/*.obj -o $(DEV_DIR)/main.bin
	
nota_fiscal: armazem
	$(COMPILER) -c $(SRC_DIR)/NotaFiscal.cpp -o $(OBJ_DIR)/NotaFiscal.obj

armazem: unidade
	$(COMPILER) -c $(SRC_DIR)/Armazem.cpp -o $(OBJ_DIR)/Armazem.obj

unidade: produto
	$(COMPILER) -c $(SRC_DIR)/Unidade.cpp -o $(OBJ_DIR)/Unidade.obj

produto:
	$(COMPILER) -c $(SRC_DIR)/Produto.cpp -o $(OBJ_DIR)/Produto.obj

error_handler:
	$(COMPILER) -c $(UTILS_DIR)/ErrorHandler.cpp -o $(OBJ_DIR)/ErrorHandler.obj
	
# 
# clean
# 
clean:
	rm $(OBJ_DIR)/*.obj
	rm $(DEV_DIR)/*.bin
