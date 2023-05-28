#include "BlocoInt.hpp"

void BlocoInt::setItem(int *item){
	this->item=item;

}

int * BlocoInt::getItem(){
	return this->item;
}

void BlocoInt::setProx(BlocoInt *p){
	this->prox=p;
}

BlocoInt * BlocoInt::getProx(){
	return this->prox;
}
