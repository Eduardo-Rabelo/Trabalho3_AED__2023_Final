#include <iostream>
#include <filesystem>
#include "Matriz.hpp"
#include "Pilha.hpp"
#ifndef JOGO_HPP
#define JOGO_HPP
using namespace std;
class Jogo{
    private:
        Matriz fase;
        //bool notfim = true;
        int numeroDaFase=1;
        int ordem=0,numMatriz=0,numPerigo=0,totalCasasPercorridas=0;//,numl=1,numc=1;
    public:
        Jogo();
        void setFase(int ordem,vector<string>v);
        void jogarRandon();
        void jogarProfundo();
        void jogarLargura();
        //void mudaFase();
        void salvaJogo(string s);
        void reiniciarJogo();
    
};

#endif
