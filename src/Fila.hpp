#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include "Bloco.hpp"

using namespace std;


class Fila{

	private:
		Bloco *frente,*fundo;
	public:
		Fila(); 
		void push(string *s);
		void pop(string **s);
		void imprimeFila();
		void clear();
		

};



#endif
