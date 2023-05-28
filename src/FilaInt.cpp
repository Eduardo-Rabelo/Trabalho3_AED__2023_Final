#include "FilaInt.hpp"

FilaInt::FilaInt(){
	this->frente = new BlocoInt;
	this->fundo = this->frente;
	this->fundo->setProx(this->frente);

}

void FilaInt::push(int *s){
	BlocoInt *aux = new BlocoInt;
	
	this->fundo->setProx(aux);
	this->fundo = this->fundo->getProx();
	this->fundo->setItem(s);
	this->fundo->setProx(this->frente);
}

void FilaInt::pop(int **s){
	BlocoInt *aux;
	
	aux = new BlocoInt;
	
	if(this->frente == this->fundo){
		cout << "\n\nFila Vazia\n\n";
	}
	else{
		aux=this->frente->getProx();
		this->frente->setProx(aux->getProx());
		
		if(aux == this->fundo){
			this->fundo = this->frente;
		}
		*s=aux->getItem();
	}
	delete aux;
}

void FilaInt::imprimeFila(){
	BlocoInt *aux,*deletar;
	int *s=NULL;
	if(this->fundo	!= this->frente){
		cout << "\n\nIMPRIMIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n\n";
		
		aux = new BlocoInt;
		deletar = new BlocoInt;
		
		aux=this->frente->getProx();
		
		cout << "\n\nDa Frente para o fundo:\n\n";
		while(aux!=this->fundo){
			s=aux->getItem();
			cout << "Valor:" << *s << "\n"; 
			cout << "Endereço:" << s << "\n"; 
			cout << "\n\n\n";
			aux=aux->getProx();
		}
			s=this->fundo->getItem();
			cout << "Valor:" << *s << "\n"; 
			cout << "Endereço:" << s << "\n"; 
			cout << "\n\n\n";
			
		aux=deletar;
		delete deletar;
	
	}
	else{
		cout << "\n\nFila Vazia!\n\n";
	}
	

}

void FilaInt::clear(){
	int *s;
	while( this->frente !=  this->fundo ){
		pop(&s);
	}

}
/*
void display(queue*q){
    if(emptyQUEUE(q)){
        printf (" empty queue;\n");
        return ;
    }
    queueELEM*aux = q->begin;
    printf ("\n  current queue: ");
    while(aux!=NULL){
        printf ("%i ", aux->data);
        aux = aux->next;
    }
    printf ("\n");
}
*/


