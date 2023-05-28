#include <iostream>
using namespace std;

#ifndef BLOCO_HPP
#define BLOCO_HPP

class Bloco{

	private:
		string *item = NULL;
		Bloco *prox = NULL;
	public:
		void setItem(string *item);
		string * getItem();
		void setProx( Bloco *p);
		Bloco *getProx();

};

#endif
