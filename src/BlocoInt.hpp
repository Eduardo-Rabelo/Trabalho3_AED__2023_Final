#include <iostream>
using namespace std;

#ifndef BLOCOINT_HPP
#define BLOCOINT_HPP

class BlocoInt{

	private:
		int *item = NULL;
		BlocoInt *prox = NULL;
	public:
		void setItem(int *item);
		int * getItem();
		void setProx( BlocoInt *p);
		BlocoInt *getProx();

};

#endif
