#ifndef PILHAINT_HPP
#define PILHAINT_HPP

#include <iostream>
#include "BlocoInt.hpp"

using namespace std;

class PilhaInt{

	private:
		BlocoInt *fundo, *topo;
	
	public:
		PilhaInt();
		void push(int *s);
		void pop(int **s);
		void imprimePilha();
		int *getTopo();
		void clear();



};

#endif
