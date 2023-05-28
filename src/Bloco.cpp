#include "Bloco.hpp"

void Bloco::setItem(string *item){
	this->item=item;

}

string * Bloco::getItem(){
	return this->item;
}

void Bloco::setProx(Bloco *p){
	this->prox=p;
}

Bloco * Bloco::getProx(){
	return this->prox;
}
