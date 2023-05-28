#include "Pilha.hpp"

Pilha::Pilha(){
	this->fundo = new Bloco;
	this->fundo->setProx(NULL);
	this->topo = this->fundo;
}

void Pilha::push(string *s){
	Bloco *aux = new Bloco;
	
	aux->setItem(s);
	aux->setProx(this->topo);
	this->topo = aux;
}

void Pilha::pop(string **s){
	Bloco *aux = new Bloco;
	
	if(this->topo == this->fundo){
		cout << "\n\nPilha Vazia\n\n";
	}
	else{
		aux=this->topo;
		topo = aux->getProx();
		*s = aux->getItem();
	}
	delete aux;
	//aux = NULL;
}


void Pilha::clear(){
	string *s;
	while( this->topo !=  this->fundo ){
		pop(&s);
	}

}










void Pilha::imprimePilha(){
	
	Pilha paux;
	string *s=NULL;
	int cont1=0,cont2=0;
	
	
	
	cout << "\n\nDo topo para o fundo:\n\n";
	while(this->topo != this->fundo){
		pop(&s);
		cout << "Valor:" << *s << "\n"; 
		cout << "Endereço:" << s << "\n"; 
		cout << "\n\n\n";
		
		paux.push(s);
		cont1++;
	}
	
	
	cout << "\n\nDo fundo para o topo:\n\n";
	while(cont2<cont1){
		paux.pop(&s);
		cout << "Valor:" << *s << "\n"; 
		cout << "Endereço:" << s << "\n"; 
		cout << "\n\n\n"; 
		push(s);
		cont2++;
	}
}



string * Pilha::getTopo(){
	return this->topo->getItem();
}

