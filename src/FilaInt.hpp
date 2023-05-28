#ifndef FILAINT_HPP
#define FILAINT_HPP

#include <iostream>
#include "BlocoInt.hpp"

using namespace std;


class FilaInt{

	private:
		BlocoInt *frente,*fundo;
	public:
		FilaInt(); 
		void push(int *s);
		void pop(int **s);
		void imprimeFila();
		void clear();

};



#endif
