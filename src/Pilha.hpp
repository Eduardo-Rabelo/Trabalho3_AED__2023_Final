#ifndef PILHA_HPP
#define PILHA_HPP

#include <iostream>
#include "Bloco.hpp"

using namespace std;

class Pilha{

	private:
		Bloco *fundo, *topo;
	
	public:
		Pilha();
		void push(string *s);
		void pop(string **s);
		void imprimePilha();
		string *getTopo();
		void clear();



};

#endif
