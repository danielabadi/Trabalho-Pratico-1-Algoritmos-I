CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
EXEC=./tp1

${EXEC}: src/main.cpp src/vertice.cpp src/jogador.cpp src/grafo.cpp
	${CC} ${CFLAGS} src/main.cpp src/vertice.cpp src/jogador.cpp src/grafo.cpp -o ${EXEC}

test: ${EXEC}
	@bash run_tests.sh ${EXEC}
