#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include "Pilha.hpp"
#include "PilhaInt.hpp"
#include "Fila.hpp"
#include "FilaInt.hpp"
#ifndef MATRIZ_HPP
#define MATRIZ_HPP
using namespace std;

class Matriz{
	private:
		int ordem, numl=1, numc=1, pontos=0, contPerigo=0,contCasas=0;
		string *inicio,*final;
		vector<string> v,v2;
		bool fim=false, reiniciar = false;
		vector<int> vb;
		int *iniciob,*finalb; 

	public:
	    
	    Matriz();
		Matriz(int ordem, vector<string> v);
		
		void setMatriz(int ordem, vector<string> v);
		
		void reiniciarMatriz();
		
		void imprimeMatriz();
		
		void imprimeMatriz2();
		
		void percorreMatrizRandom();
		
		void percorreMatrizProfundo();
		
		void percorreMatrizLargura();
		
		vector<string> getMatriz();
		
		int getOrdem();
		
		int getNuml();
		
		int getNumc();
		
		int getContPerigo();
		
		int getPontos();
		
		void setNuml(int l);
		
		void setNumc(int c);
		
		bool getDireita();
		
		bool getBaixo();
		
		void salvaMatriz(int contMatriz);
		
		void moverDireita(string **p, int *contc, int **b);
		
		void moverDiagonalDireitaBaixo(string **p, int ordem, int *contc, int *contl, int **b);
		
		void moverDiagonalDireitaAlto(string **p, int ordem, int *contc, int *contl, int **b);
		
		void moverBaixo(string **p, int ordem, int *contl, int **b);
		
		void moverAlto(string **p, int ordem, int *contl, int **b);
		
		void moverEsquerda(string **p, int *contc, int **b);
		
		void moverDiagonalEsquerdaBaixo(string **p, int ordem, int *contc, int *contl, int **b);
		
		void moverDiagonalEsquerdaAlto(string **p, int ordem, int *contc, int *contl, int **b);
		
		
		
};
#endif
