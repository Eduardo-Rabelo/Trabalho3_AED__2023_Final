#include "PilhaInt.hpp"

PilhaInt::PilhaInt(){
	this->fundo = new BlocoInt;
	this->fundo->setProx(NULL);
	this->topo = this->fundo;
}








void PilhaInt::push(int *s){
	BlocoInt *aux = new BlocoInt;
	
	aux->setItem(s);
	aux->setProx(this->topo);
	this->topo = aux;
}

void PilhaInt::pop(int **s){
	BlocoInt *aux = new BlocoInt;
	
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



void PilhaInt::clear(){
	int *s;
	while( this->topo !=  this->fundo ){
		pop(&s);
	}

}








void PilhaInt::imprimePilha(){
	
	PilhaInt paux;
	int *s=NULL;
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



int * PilhaInt::getTopo(){
	return this->topo->getItem();
}

