# Compila todos os arquivos e gera o executável
all: create_dir main

# Cria pasta para armazenar os arquivos objetos
create_dir:
	mkdir -p bin

# Compila o arquivo payoffTable.cpp e gera o arquivo objeto payoffTable.o
bin/payoffTable.o: src/payoffTable.cpp
	g++ src/payoffTable.cpp -Iinclude -O0  -Wall -pedantic -std=c++11 -c -o bin/payoffTable.o

# Compila o arquivo dadosAposta.cpp e gera o arquivo objeto dadosAposta.o
bin/dadosAposta.o: src/dadosAposta.cpp bin/payoffTable.o
	g++ src/dadosAposta.cpp -Iinclude -O0  -Wall -pedantic -std=c++11 -c -o bin/dadosAposta.o

# Compila o arquivo main.cpp, gera o arquivo objeto main.o e o executável
bin/main.o: main.cpp bin/dadosAposta.o
	g++ main.cpp -Iinclude -O0  -Wall -pedantic -std=c++11 -c  -o bin/main.o

# Cria o arquivo executável
main: bin/main.o
	g++ bin/*.o -Iinclude -O0  -Wall -pedantic -std=c++11 -o main

# Executa o programa com o arquivo
run: all
	./main bet.dat

# Apaga a pasta de arquivos objetos e o executável
clean:
	rm -rf bin main