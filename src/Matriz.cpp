#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>
#include "Matriz.hpp"
using namespace std;

Matriz::Matriz(){
    this->ordem=0;
    this->inicio=this->final=NULL;
}


void Matriz::setMatriz(int ordem, vector<string> v){


	
	
	int x=0;
	this->ordem=ordem;
	this->v.clear();
	this->vb.clear();
	for (int i=0 ; i < v.size();i++){
	    this->v.push_back(v[i]);
	    this->vb.push_back(0);
	    
	}
	
	this->inicio=&this->v[0];
	this->final=&this->v[(ordem*ordem)-1];
	this->iniciob=&this->vb[0];
	this->finalb=&this->vb[(ordem*ordem)-1];
	this->pontos=0;
	this->contCasas = 0;
	this->contPerigo = 0;
	this->v2=v;
}

void Matriz::imprimeMatriz(){
    int contl=1;
    string *p=this->inicio,*p2=this->final;
    
	while(p<=p2){
	 
	    cout << *p << " ";
	    
	    if(contl%ordem==0){
	        cout << "\n";
	    }
	    
	    contl++;
	    p++;
	}
	cout << "\n\n\n";
}



void Matriz::imprimeMatriz2(){
    int contl=1;
    string *p=this->inicio,*p2=this->final;
    
	while(p<=p2){
	 
	    cout << *p << " ";
	    
	    if(contl%ordem==0){
	        cout << "\n";
	    }
	    
	    contl++;
	    p++;
	}
	cout << "\n\n\nPontos da fase: " << this->pontos;
	cout << "	Perigos enfrentados: " << this->contPerigo;
	cout << "	Casas percorridas ao menos uma vez nessa matriz: " << this->contCasas;
}

vector<string> Matriz::getMatriz(){
	return this->v;
}

int Matriz::getOrdem(){
	return this->ordem;
}





int Matriz::getNuml(){
	return this->numl;
}

int Matriz::getNumc(){
	return this->numc;
}

int Matriz::getContPerigo(){
	return this->contPerigo;
}

void Matriz::setNuml(int l){
	this->numl = l;
}

void Matriz::setNumc(int c){
	this->numc = c;
}
















void Matriz::moverDireita(string **p, int *contc, int **b){
    *p = *p + 1;
    *b = *b + 1;
    //**b=1;
    if(**p=="#"){
        //**b=0;
        *p = *p - 1;
        *b = *b - 1;
        *contc = *contc - 1;
        
    }
    else if(**p=="*"){
    	this->reiniciar=true;
        this->contPerigo++;
        **b = 1;
    }
    else if(**p=="1"){
        **p = "0";
        **b = 1;
        this->pontos++;
        
    }
    else if(**p == "?" ){
    	this->fim=true;
    	**b=1;
    }
    *contc = *contc + 1;
}

void Matriz::moverDiagonalDireitaBaixo(string **p, int ordem, int *contc, int *contl, int **b){
    *p = *p + 1 + ordem;
    *b = *b + 1 + ordem;
    //**b=1;
    if(**p=="#"){
       //**b=0;
       *p = *p - 1 - ordem;
       *b = *b - 1 - ordem;
       *contc = *contc -1;
       *contl = *contl - 1;
    }
    else if(**p=="*"){
    	this->reiniciar=true;
        this->contPerigo++;
        **b = 1;
    }
    else if(**p=="1"){
        **p = "0";
        **b = 1;
        this->pontos++;
        
    }
    else if(**p == "?" ){
    	this->fim=true;
    	**b = 1;
    }
    *contc = *contc + 1;
    *contl = *contl + 1;
}

void Matriz::moverDiagonalDireitaAlto(string **p, int ordem, int *contc, int *contl, int **b){
    *p = *p + 1 - ordem;
    *b = *b + 1 - ordem;
    //**b = 1;
    if(**p=="#"){
      // **b = 0;
       *p = *p - 1 + ordem;
       *b = *b - 1 + ordem;
       *contc = *contc - 1;
       *contl = *contl + 1;
       
    }
    else if(**p=="*"){
    	this->reiniciar=true;
        this->contPerigo++;
        **b = 1;
    }
    else if(**p=="1"){
        **p = "0";
        **b = 1;
        this->pontos++;
        
    }
    else if(**p == "?" ){
    	this->fim=true;
    	**b = 1;
    }
    *contc = *contc + 1;
    *contl = *contl - 1;
    
}

void Matriz::moverBaixo(string **p,int ordem, int *contl, int **b){
    *p = *p + ordem;
    *b = *b + ordem;
    //**b = 1;
    if(**p=="#"){
    	//**b = 0;
        *p = *p - ordem;
        *b = *b - ordem;
        *contl = *contl - 1;
        
    }
    else if(**p=="*"){
    	this->reiniciar=true;
        this->contPerigo++;
        **b = 1;
    }
    else if(**p=="1"){
        **p ="0";
        **b = 1;
        this->pontos++;
        
    }
    else if(**p == "?" ){
    	this->fim=true;
    	**b=1;
    }
    *contl = *contl + 1;
}

void Matriz::moverAlto(string **p, int ordem, int *contl, int **b){
	*p = *p - ordem;
	*b = *b - ordem;
	//**b=1;
	if(**p=="#"){
		//**b=0;
		*p = *p + ordem;
		*b = *b + ordem;
		*contl = *contl + 1;
	}
	else if(**p=="*"){
		this->reiniciar=true;
		this->contPerigo++;
		**b = 1;
	}
	else if(**p=="1"){
		**p = "0";
		**b = 1;
        this->pontos++;
        
	}
	else if(**p == "?" ){
		this->fim=true;
		**b = 1;
	}
	*contl = *contl - 1;

}

void Matriz::moverEsquerda(string **p, int *contc, int **b){
    *p = *p - 1;
    *b = *b - 1;
    //**b=1;
    if(**p=="#"){
    	//**b=0;
        *p = *p + 1;
        *b = *b + 1;
        *contc = *contc + 1;
    }
    else if(**p=="*"){
    	this->reiniciar=true;
        this->contPerigo++;
        **b = 1;
    }
    else if(**p=="1"){
        **p = "0";
        **b = 1;
        this->pontos++;
        
    }
    else if(**p == "?" ){
    	this->fim=true;
    	**b = 1;
    }
    *contc = *contc - 1;
}

void Matriz::moverDiagonalEsquerdaBaixo(string **p, int ordem, int *contc, int *contl, int **b){
     *p = *p - 1 + ordem;
     *b = *b - 1 + ordem;
     //**b=1;
    if(**p=="#"){
      // **b=0;
       *p = *p + 1 - ordem;
       *b = *b + 1 - ordem;
       *contc = *contc + 1;
       *contl = *contl - 1;
    }
    else if(**p=="*"){
    	this->reiniciar=true;
        this->contPerigo++;
        **b = 1;
    }
    else if(**p=="1"){
        **p = "0";
        **b = 1;
        this->pontos++;
        
    }
    else if(**p == "?" ){
    	this->fim=true;
    	**b = 1;
    }
    
    *contc = *contc - 1;
    *contl = *contl + 1;
}

void Matriz::moverDiagonalEsquerdaAlto(string **p, int ordem, int *contc, int *contl, int **b){
     *p = *p - 1 - ordem;
     *b = *b - 1 - ordem;
     //**b=1;
    if(**p=="#"){
   	//**b=0;
       *p = *p + 1 + ordem;
       *b = *b + 1 + ordem;
       *contc = *contc + 1;
       *contl = *contl + 1;
    }
    else if(**p=="*"){
    	this->reiniciar=true;
        this->contPerigo++;
        **b = 1;
    }
    else if(**p=="1"){
        **p = "0";
        **b = 1;
        this->pontos++;
        
    }
    else if(**p == "?" ){
    	this->fim=true;
    	**b = 1;
    }
    *contc = *contc - 1;
    *contl = *contl - 1;
}





void Matriz::percorreMatrizRandom(){
    
    string *p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) ), *p2=this->final;
    int contl = this->numl, contc = this->numc, move=0;
    int *b = ( this->iniciob + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
  // vector <string> vm = this->v;

  
	
    cout << "Posição Inicial: Fase[" << contl - 1 << "][" << contc - 1 << "] \n\n";
    cout << "CAMINHO:\n\n";
    *p="0";
    *b=1;
    
    while(this->fim == false ){
    		
    		 move = rand()%8;	
	   if(this->reiniciar==true){
	   
	   	cout << "\n\nMatrizDepoisDePercorrida: \n";
	   	imprimeMatriz();
	   	
	    	*p="1";

	   	p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	    	b = ( this->iniciob + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	    	
	    	while(p<=p2){
	    		if(*p =="0"){
	    			*p="1";
	    		}
	    		p++;
	    	}
	    	
	    	
	    	
	    	p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	    	*p = "0";
	    	contl = this->numl;
	    	contc = this->numc;
	    	
	    	cout <<"  p: " << p << "  *p= " << *p ; 
	    	
	    	cout << "\n\nREINICIOU:\n\n";
	    	cout << "\n\nMatriz: \n";
	    	this->pontos = 0; 
	    	imprimeMatriz();
	    	this->reiniciar=false;	
	    }	
           
            
            else if(move == 0 && contc < this->ordem){
                moverDireita(&p, &contc, &b);
                cout << "Direita, ";
            }
            else if(move== 1 && (p+ordem+1) <= p2 && contc < this-> ordem){		///////////////////////<=
                moverDiagonalDireitaBaixo(&p, this->ordem, &contc, &contl, &b);
                cout << "Diagonal direita para baixo, ";
            }
            else if((p+ordem <= p2) && move==2){
                moverBaixo(&p, this->ordem, &contl, &b);
                cout << "Baixo, ";
            }
            else if(move==3 && p > this->inicio && contc > 1){
                moverEsquerda(&p,&contc, &b);
                cout << "Esquerda, " ;
            }
            
            else if(move==4 && (p+this->ordem-1)<p2 && contc > 1 ){
                moverDiagonalEsquerdaBaixo(&p, this->ordem, &contc, &contl, &b );
                cout << "Diagonal esquerda para baixo, ";
            }
            
            else if(move==5 && (p - ordem + 1) > this->inicio && contc < this->ordem ){
                moverDiagonalDireitaAlto(&p, this->ordem, &contc, &contl, &b );
                cout << "Diagonal direita para cima, ";
            }
            
            else if(move == 6 && (p - this->ordem - 1) >= this->inicio && contc>1 ){
                moverDiagonalEsquerdaAlto(&p, this->ordem, &contc, &contl, &b );
                cout << "Diagonal esquerda para cima, ";
            }
            
            else if(move == 7 && (p - this->ordem) >= this->inicio){
            	moverAlto(&p, this->ordem, &contl, &b);
            	 cout << "Cima, ";
            }
            
            
            
            
     
    }
    cout << "\n\n\n";
  //  setMatriz(this->ordem,vm);
    this->fim=false;
}

void Matriz::reiniciarMatriz(){
	this->pontos = 0; 
	this->contPerigo = 0;
	this->contCasas = 0;
	this->v = this->v2;
	this->fim = false;
	this->reiniciar = false;
	this->numl = 1;
	this->numc = 1;
	int *b=this->iniciob;
	
	while( b < this->finalb ){
		if(*b == 1){
			*b = 0;
		}
		b++;
	}
}

void Matriz::salvaMatriz(int contMatriz){
	
	vector <string> vecs;
	string str,aux;
	string s="dataset/Matriz",a;
	stringstream ss;
	
	ss << contMatriz;
	ss >> a;
	s.append(a).append(".txt");
	ofstream file(s);
	
	int contl=1;
	string *p=this->inicio,*p2=this->final;
	
	while(p<=p2){
	
	    file << *p << " ";
	    
	    if(contl%ordem==0){
	        file << "\n";
	    }
	    
	    contl++;
	    p++;
	}
	
	file.close();
	

	s="dataset/MatrizB";
	ss << contMatriz;
	ss >> a;
	s.append(a).append(".txt");
	ifstream File3(s);
	
	while(getline(File3,str)){
		for(int i=0; i < str.size(); i++){
			
			if(str[i] == ' ' && aux!=""){
				vecs.push_back(aux);
				aux="";
			}
			else if(str[i] != ' '){
				aux.push_back(str[i]);
				
			}
		}
	}
	
	
	for(int i=0;i<vecs.size();i++){
		if(vecs[i]== "1"){
			this->vb[i]=1;
		}
	}
	
	
	
	
	contl=1;
	
	ofstream file2(s);
	int *pb=this->iniciob,*pb2=this->finalb;
	
	while(pb<=pb2){
	
	    file2 << to_string(*pb) << " ";
	    if(*pb == 1){
	    	this->contCasas++;
	    }
	    if(contl%this->ordem==0){
	        file2 << "\n";
	    }
	    
	    contl++;
	    pb++;
	}
	file2.close();
	

}

int Matriz::getPontos(){
	return this->pontos;
}



void Matriz::percorreMatrizProfundo(){

	Pilha pi;
	PilhaInt piv;
	string *ts;
	//string s;
	//int v;
	
	string *p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) ), *p2=this->final;
	int contl = this->numl, contc = this->numc, move=0;
	int *b = ( this->iniciob + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	bool baixo=false,direita=false,cima=false,ddbaixo=false,debaixo=false,ddcima=false,decima=false,esquerda=false,voltar=false;
	bool move2=false;
	// vector <string> vm = this->v;


	
	cout << "Posição Inicial: Fase[" << contl - 1 << "][" << contc - 1 << "] \n\n";
	cout << "CAMINHO:\n\n";
	*p="0";
	*b=1;
	
	pi.push(p);
	piv.push(b);
	
	
	int teste = 0;
	while(this->fim == false){
		teste++;
			
	   if(this->reiniciar==true){
	   
	   	//cout << "\n\nMatrizDepoisDePercorrida: \n";
	   	//imprimeMatriz();
	   	
	    	*p="1";

	   	p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	    	b = ( this->iniciob + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	    	
	    	while(p<=p2){
	    		if(*p =="0" || *p=="x"){
	    			*p="1";
	    		}
	    		p++;
	    	}
	    	
	    	
	    	
	    	p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	    	*p = "0";
	    	contl = this->numl;
	    	contc = this->numc;
	    	
	    	//cout <<"  p: " << p << "  *p= " << *p ; 
	    	
	    	//cout << "\n\nREINICIOU:\n\n";
	    	//cout << "\n\nMatriz: \n";
	    	this->pontos = 0; 
	    //	imprimeMatriz();
	    	this->reiniciar=false;	
	    	pi.clear();
	    	piv.clear();
	    	pi.push(p);
	    	move=0;
	    }
	    	/*if(p!=pi.getTopo()){
	    		pi.push(p);
	    	}*/
		/*cout << "\n\nValor de p:" << *p << "\n"; 
		cout << "Endereço de p:" << p << "\n"; 
		cout << "\n\n\n";
		
		imprimeMatriz();
	    	cout << "\n\nContl:" << contl;
	    	cout << "\n\nContc:" << contc;
	    	cout << "\n\nMove:" << move;
	    	cout << "\n\n";*/
		
		
		if( (p+1) <= p2 && (*(p+1)=="#" || *(p+1)=="x")){
			direita=true;
		}
		if((p+this->ordem) <= p2 && (*(p+this->ordem)=="#" || *(p+this->ordem)=="x")){
			baixo=true;
		}
		if( (p - this->ordem) >= this->inicio && (*(p - this->ordem)=="#"||*(p - this->ordem)=="x")){
			cima=true;
		}
		if( (p+this->ordem+1) <= p2 && (*(p+this->ordem+1)=="#" || *(p+this->ordem+1)=="x")){
			ddbaixo=true;
		}
		if( (p+this->ordem-1) <= p2 && (*(p+this->ordem-1)=="#" || *(p+this->ordem-1)=="x")){
			debaixo=true;
		}
		if( (p-this->ordem+1) >= this->inicio && (*(p-this->ordem+1)=="#" || *(p-this->ordem+1)=="x")){
			ddcima=true;
		}
		if( (p-this->ordem-1) >= this->inicio && (*(p-this->ordem-1)=="#" || *(p-this->ordem-1)=="x")){
			decima=true;
		}
		if( (p-1) >= this->inicio && (*(p-1)=="#" || *(p-1)=="x")){
			esquerda=true;
		}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		
	   if(contc==1){
	   	if(contl==this->ordem){
	   		if(direita && cima && ddcima){
	   			voltar=true;
	   		}
	   	}
	   	else if(contl>1){
	   		if(direita && ddbaixo && baixo && cima && ddcima){
	   			voltar=true;
	   		}
	   	}
	   
	   }
	   else if(contl==1){
	   	if(contc==this->ordem){
	   		if(baixo && debaixo && esquerda){
	   			voltar=true;
	   		}
	   	}
	   	else if (contc>1){
	   		if(debaixo && ddbaixo && baixo && direita && esquerda){
	   			voltar=true;
	   		}
	   	}
	   }
	   
	   else if(contc==this->ordem){
	   	if(contl==this->ordem){
	   		if(cima && decima && esquerda){
	   			voltar==true;
	   		}
	   	}
	   	else{
	   		if(debaixo && baixo && cima && decima && esquerda){
	   			voltar=true;
	   		}
	   	}
	   
	   }
	   
	   else if(contl==this->ordem){
	   	if(direita && cima && ddcima && decima && esquerda){
	   		voltar==true;
	   	}
	   }
	   
	   else{
	   	if(cima && direita && ddbaixo && debaixo && baixo && ddcima && decima && esquerda){
	   		voltar=true;
	   	}
	   
	   }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   
	   
	   direita=false;
	   cima=false;
	  // esquerda=false;
	   ddbaixo=false;
	   debaixo=false;
	   baixo=false;
	   ddcima=false;
	   decima=false;
	   esquerda=false;
	   /*if((*(p+1)=="#" || *(p+1)=="x") && (*(p+this->ordem)=="#" || *(p+this->ordem)=="x") && (*(p - this->ordem)=="#"||*(p - this->ordem)=="x") && (*(p+this->ordem+1)=="#" || *(p+this->ordem+1)=="x")){
	   //&& contc < this->ordem && (p+this->ordem+1 <= p2) && (p - this->ordem) >= this->inicio){*/
	   if(voltar==true){
	   
	   	if(p!=pi.getTopo()){
	    		pi.push(p);
	    		piv.push(b);
	    	}
	   	//cout << "\n\nPRIMEIRO IF\n";
	    	string *str;
	    	int *in;
	    	*p="x";
	    	*b=1;
	    	
	    	pi.pop(&str);
	    	piv.pop(&in);
	    	
	    	//cout <<"\n\nEXTOPO: " << str << "\n\n\n";
	    	
	    	p=pi.getTopo();
	    	b=piv.getTopo();
	    	
	    	
	    	
    		if((p+1)==str){
    			contc--;
    			move=0;
    		}
    		else if((p+this->ordem)==str){
    			contl--;
    			move=0;
    		}
    		else if((p-this->ordem)==str){
    			contl++;
    			move=0;
    		}
    		else if((p+this->ordem+1)==str){
    			contl--;
    			contc--;
    			move = 1;
    		}
    		else if((p+this->ordem-1)==str){
    			contl--;
    			contc++;
    			move = 0;
    		}
		else if((p-this->ordem+1)==str){
			contl++;
			contc--;
			move=0;
		}
		
		else if((p-this->ordem-1)==str){
			contl++;
			contc++;
			move=0;
		}
		//////////////////////////////////////////////
		else if((p-1)==str){
    			contc++;
	    		move=0;
    		}
    		////////////////////////////////////////////
	    	
	    	voltar=false;
	    	move2=false;
	   
	   }	////////////////////////////IF não cobre diagonal esquerda inferior*/
	   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
	  if(move== 0 && (p+ordem+1) <= p2 && contc < this-> ordem){
	  	//cout << "\n\nENTROU\n\n";
	  	*p="x";
	    	
	    	if(*(p+ordem+1)!="#" && *(p+ordem+1)!="x"){
			pi.push(p);
	    		piv.push(b);
	    	}
	    	if(*(p+ordem+1)!="x"){
	    		if(*(p+ordem+1)!="#"){
	    			move2=false;
	    		}
			moverDiagonalDireitaBaixo(&p, this->ordem, &contc, &contl, &b);
               		//cout << "Diagonal direita para baixo, ";
		}
		
		if(*(p+ordem+1)=="#" || (p+ordem+1) > p2 || *(p+ordem+1)== "x" ){ //|| *(p+ordem)== "x"){
			
			//move=-1;
            	 	move++;
            	 	
			
		}
	  
	  
	  		///////////////////////<=
                
                
                
                
          }
          
	  else if((p+this->ordem <= p2) && move==1){
	    	
	    	*p="x";
	    	
	    	if(*(p+ordem)!="#" && *(p+ordem)!="x"){
			pi.push(p);
	    		piv.push(b);
	    	}
	    	if(*(p+ordem)!="x"){
	    		if(*(p+ordem)!="#"){
	    			move2=false;
	    		}
			moverBaixo(&p, this->ordem, &contl, &b);
			//cout << "Baixo, ";
		}
		
		if(*(p+ordem)=="#" || (p+ordem > p2) || *(p+ordem)== "x" ){ //|| *(p+ordem)== "x"){
			
            	 	//move=-1;
            	 	move++;
            	 
		}
	    }
	    
	    
	    else if(move == 2 && contc < this->ordem){
	   	//string *str;
	   	
	   	*p="x";
	    	
	    	if(*(p+1)!="#" && *(p+1)!="x"){
			pi.push(p);
	   		piv.push(b);
	    	}
	    	if(*(p+1)!="x"){
	    		if(*(p+1)!="#"){
	    			move2=false;
	    		}
	    		//cout << "\n\n*(p+1)=" << *(p+1);
			moverDireita(&p, &contc, &b);
			//cout << "Direita, ";
		}
		
		if(*(p+1)=="#" || contc == this->ordem || *(p+1)=="x" ){//){
			
			//move=1;
            	 	move++;
            	 	
		}
		
		
	    }
	    
	    else if(move==3 && (p+this->ordem-1)<p2 && contc > 1 ){
	    
	    	*p="x";
	    	
	    	if(*(p+ordem-1)!="#" && *(p+ordem-1)!="x"){
			pi.push(p);
	    		piv.push(b);
	    	}
	    	if(*(p+ordem-1)!="x"){
	    		if(*(p+ordem-1)!="#"){
	    			move2=false;
	    		}
			moverDiagonalEsquerdaBaixo(&p, this->ordem, &contc, &contl, &b );
               		//cout << "Diagonal esquerda para baixo, ";
		}
		
		if(*(p+ordem-1)=="#" || (p+ordem-1 > p2) || *(p+ordem-1)== "x" ){ //|| *(p+ordem)== "x"){
			
            	 	//move=-1;
            	 	move++;
            	 	
		}
	    
                
                
            }
            
            
             else if(move==4 && (p - ordem + 1) > this->inicio && contc < this->ordem ){
            	*p="x";
	    	
	    	if(*(p-this->ordem+1)!="#" && *(p-this->ordem+1)!="x"){
			pi.push(p);
		    	piv.push(b);
	    	}
            	if(*(p-this->ordem+1)!="x"){
            		if(*(p-ordem+1)!="#"){
	    			move2=false;
	    		}
                	moverDiagonalDireitaAlto(&p, this->ordem, &contc, &contl, &b );
                	//cout << "Diagonal direita para cima, ";
                }
                if(*(p - this->ordem+1)=="#" || (p - this->ordem+1) < this->inicio || *(p - this->ordem+1)=="x" || contc==this->ordem){
            	 	
            	 	//move=-1;
            	 	move++;
            	 	
            	 }
                
            }
            
            
            else if(move == 5 && (p - this->ordem) >= this->inicio){
	    	
	    	*p="x";
	    	
	    	if(*(p-this->ordem)!="#" && *(p-this->ordem)!="x"){
			pi.push(p);
		    	piv.push(b);
	    	}
	    	
	    	if(*(p-this->ordem)!="x"){
	    		if(*(p-ordem)!="#"){
	    			move2=false;
	    		}
            		moverAlto(&p, this->ordem, &contl, &b);
            		//cout << "Cima, ";
            	 }
            	 if(*(p - this->ordem)=="#" || (p - this->ordem) < this->inicio || *(p - this->ordem)=="x"){// || *(p - this->ordem)=="x"
            	 	
            	 	//move=-1;
            	 	move++;
            	 }
            }
            
           
	    
	    
            
            else if(move == 6 && (p - this->ordem - 1) >= this->inicio && contc>1 ){
            	
            	*p="x";
	    	
	    	if(*(p-this->ordem-1)!="#" && *(p-this->ordem-1)!="x"){
			pi.push(p);
		    	piv.push(b);
	    	}
	    	
	    	if(*(p-this->ordem-1)!="x"){
	    		if(*(p-ordem-1)!="#"){
	    			move2=false;
	    		}
            		moverDiagonalEsquerdaAlto(&p, this->ordem, &contc, &contl, &b );
                	//cout << "Diagonal esquerda para cima, ";
            	 }
            	 
            	 if(*(p - this->ordem-1)=="#" || (p - this->ordem-1) < this->inicio || *(p - this->ordem-1)=="x"){// || *(p - this->ordem)=="x"
            	 	//move=-1;
            	 	move++;
            	 
            	 }
                
            }
	    //////////////////////////////////////////////////////////////////////////////////////
	    
	    else if(move==7 && p > this->inicio && contc > 1){
	    	
	    	*p="x";
	    	
	    	if(*(p-1)!="#" && *(p-1)!="x"){
			pi.push(p);
	   		piv.push(b);
	    	}
	    	if(*(p-1)!="x"){
	    		if(*(p-1)!="#"){
	    			move2=false;
	    		}
	    		//cout << "\n\n*(p-1)=" << *(p-1);
			moverEsquerda(&p,&contc, &b);
                	//cout << "Esquerda, " ;
		}
		
		if(*(p-1)=="#" || contc == 1 || *(p-1)=="x" ){//){
			
			if(move2==false){///////////////////////////////////ESSE FINAL PARECE DAR
				move=0;
			}
			else{
            	 		move++;
            	 	}
		}
	    
            }
            /////////////////////////////////////////////////////////////////////////////////////
	    
	    else{
	    	if(move2==false){
	    		move=0;
	    		move2=true;
	    		//cout << "\n\nELSE1move2=true\n";
	    	}
	    	else if(move<8){
	    		move++;
	    		//cout << "\n\nELSE2:move++\n";
	    	}
	    	else{
		    	//cout << "\n\nELSEelse\n";
		    	
		    	if(p!=pi.getTopo()){
		    		pi.push(p);
		    		piv.push(b);
		    	}
		    	string *str;
		    	int *in;
		    	*p="x";
		    	
		    	pi.pop(&str);
		    	piv.pop(&in);
		    	//cout <<"\n\nEXTOPO: " << str << "\n\n\n";
		    	
		    	p=pi.getTopo();
		    	b=piv.getTopo();
		    	
		    	
		    	/*
	    		if((p+1)==str){
	    			contc--;
	    			move=2;
	    		}
	    		else if((p+this->ordem)==str){
	    			contl--;
	    			move=0;
	    		}
	    		else if((p-this->ordem)==str){
	    			contl++;
	    			move=0;
	    		}
	    		*/
	    		
	    		if((p+1)==str){
	    			contc--;
	    			move=0;
	    		}
	    		else if((p+this->ordem)==str){
	    			contl--;
	    			move=0;
	    		}
	    		else if((p-this->ordem)==str){
	    			contl++;
	    			move=0;
	    		}
	    		else if((p+this->ordem+1)==str){
	    			contl--;
	    			contc--;
	    			move = 1;
	    		}
	    		else if((p+this->ordem-1)==str){
    				contl--;
    				contc++;
    				move = 0;
    			}
    			
    			else if((p-this->ordem+1)==str){
    				contl++;
    				contc--;
    				move=0;
    			}
    			
    			else if((p-this->ordem-1)==str){
    				contl++;
    				contc++;
    				move=0;
    			}
    			//////////////////////////////////////////////
    			else if((p-1)==str){
    				contc++;
	    			move=0;
    			}
    			////////////////////////////////////////////
    			move2=false;
	    		
	    	}
	    
	    }
	    
	  
	

	}
	//cout << "\n\nTeste: "<< teste << "\n\n";
	//  setMatriz(this->ordem,vm);
	this->fim=false;
	//pi.imprimePilha();
	pi.clear();
	piv.clear();
}




void Matriz::percorreMatrizLargura(){
    
    string *p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) ), *p2=this->final;
    int *b = ( this->iniciob + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
    bool baixo=true,direita=true,cima=true,ddbaixo=true,debaixo=true,ddcima=true,decima=true,esquerda=true,continuar=true;
  // vector <string> vm = this->v;
    //string *str;
    //int *in;
  
    Fila f;
    FilaInt fv;
    	
    cout << "Posição Inicial: Fase[" << 0 << "][" << 0 << "] \n\n";
    cout << "CAMINHO:\n\n";
    *p="x";
    *b=1;
    
    f.push(p);
    fv.push(b);
    while(this->fim == false){
    
    		 
	   if(this->reiniciar==true){
	   
	   	//cout << "\n\nMatrizDepoisDePercorrida: \n";
	   	//imprimeMatriz();
	   	
	    	*p="1";

	   	p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	    	b = ( this->iniciob + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	    	
	    	while(p<=p2){
	    		if(*p =="0" || *p=="x"){
	    			*p="1";
	    		}
	    		p++;
	    	}
	    	
	    	
	    	
	    	p = ( this->inicio + (this->numc - 1) + ( (this->numl - 1) * this->ordem ) );
	    	*p = "0";
	    	
	    	//cout <<"  p: " << p << "  *p= " << *p ; 
	    	
	    	//cout << "\n\nREINICIOU:\n\n";
	    	//cout << "\n\nMatriz: \n";
	    	this->pontos = 0; 
	    //	imprimeMatriz();
	    	this->reiniciar=false;
	    	continuar=true;
	    	f.clear();
	    	fv.clear();	
	    }	
           

		/*cout << "\n\nValor de p:" << *p << "\n"; 
		cout << "Endereço de p:" << p << "\n"; 
		cout << "\n\n\n";
		
		cout << "\n\nValor de inicio:" << *this->inicio << "\n"; 
		cout << "Endereço de inicio:" << this->inicio << "\n"; 
		cout << "\n\n\n";


		cout << "TESTE DE DISTANCIA:";
		cout << (p-this->inicio);
		cout << "\n\n\n";
		
		
		imprimeMatriz();
		cout << "\n\n";*/
		
		if((((p+ordem+1)-this->inicio)+1)%this->ordem == 1 || (p+ordem+1) > p2){
			ddbaixo = false;
		}
		
		if((p+ordem) > p2){
			baixo = false;
		}
		
		if((((p+1)-this->inicio)+1)%this->ordem == 1 || (p+1) > p2){
			direita = false;
		}
		
		if((((p+ordem-1)-this->inicio)+1)%this->ordem == 0 || (p+ordem-1) > p2){
			debaixo = false;
		}
		
		if((((p-ordem+1)-this->inicio)+1)%this->ordem == 1 || (p-ordem+1) < this->inicio){
			ddcima = false;
		}
		
		if((p-ordem) < this->inicio){
			cima = false;
		}
		
		if((((p-ordem-1)-this->inicio)+1)%this->ordem == 0 || (p-ordem-1) < this->inicio){
			decima = false;
		}
		
		if((((p-1)-this->inicio)+1)%this->ordem == 0 || (p-1) < this->inicio ){
			esquerda = false;
		}
		
		
		
		if( continuar && ddbaixo && (*(p+ordem+1) != "#" && *(p+ordem+1) != "x")){
			
			if(*(p+ordem+1)!="?"){
			
				if(*(p+ordem+1)=="*"){
					//cout << "\n\nDDBAIXO\n\n";
					//cout << "\n\nOrdem " << ordem << "\n\n";
					this->contPerigo++;
					this->reiniciar=true;
					continuar=false;
				}
				else{
					this->pontos++;
				}
			
				*(p+ordem+1)="x";
				*(b+ordem+1)=1;
				f.push((p+ordem+1));
				fv.push((b+ordem+1));
			}
			else{
				fim = true;
				*(b+ordem+1)=1;
				break;
			}
		
		}
		
		
		if( continuar && baixo && (*(p+ordem)!="x" && *(p+ordem)!="#") ){
		
			if(*(p+ordem)!="?"){
			
				if(*(p+ordem) =="*"){
					//cout << "\n\nBAIXO\n\n";
					this->contPerigo++;
					this->reiniciar=true;
					continuar=false;
				}
				else{
					this->pontos++;
				}
				*(p+ordem)="x";
				*(b+ordem)=1;
				f.push((p+ordem));
				fv.push((b+ordem));
				
			}
			else{
				fim = true;
				*(b+ordem)=1;
				break;
			}
		}
		
		if( continuar && direita && (*(p+1)!="x" && *(p+1)!="#") ){
			
			if(*(p+1)!="?"){
			
				if(*(p+1)=="*"){
					//cout << "\n\nDIREITA\n\n";
					this->contPerigo++;
					this->reiniciar=true;
					continuar=false;
				}
				else{
					this->pontos++;
				}
				*(p+1)="x";
				*(b+1)=1;
				f.push((p+1));
				fv.push((b+1));
				
			}
			else{
				fim = true;
				*(b+1)=1;
				break;
			}
		}
		
		if( continuar && debaixo && (*(p+ordem-1) != "#" && *(p+ordem-1) != "x")){
		
			if(*(p+ordem-1)!="?"){
			
				if(*(p+ordem-1)=="*"){
					//cout << "\n\nDEBAIXO\n\n";
					this->contPerigo++;
					this->reiniciar=true;
					continuar=false;
				}
				else{
					this->pontos++;
				}
				
				*(p+ordem-1)="x";
				*(b+ordem-1)=1;
				f.push((p+ordem-1));
				fv.push((b+ordem-1));
				
			}
			else{
				fim = true;
				*(b+ordem-1)=1;
				break;
			}
		
		}
		
		if( continuar && ddcima && (*(p-ordem+1) != "#" && *(p-ordem+1) != "x")){
			
			if(*(p-ordem+1)!="?"){
			
				if(*(p-ordem+1)=="*"){
					//cout << "\n\nDDCIMA\n\n";
					this->contPerigo++;
					this->reiniciar=true;
					continuar=false;
				}
				else{
					this->pontos++;
				}
				
				*(p-ordem+1)="x";
				*(b-ordem+1)=1;
				f.push((p-ordem+1));
				fv.push((b-ordem+1));
				
			}
			else{
				fim = true;
				*(b-ordem+1)=1;
				break;
			}
		
		}
		
		if( continuar && cima && (*(p-ordem)!="x" && *(p-ordem)!="#") ){
		
			if(*(p-ordem)!="?"){
			
				if(*(p-ordem)=="*"){
					
					//cout << "\n\nCIMA\n\n";
					this->contPerigo++;
					this->reiniciar=true;
					continuar=false;
				}
				else{
					this->pontos++;
				}
				
				*(p-ordem)="x";
				*(b-ordem)=1;
				f.push((p-ordem));
				fv.push((b-ordem));
				
			}
			else{
				fim = true;
				*(b-ordem)=1;
				break;
			}
		}
		
		if( continuar && decima && (*(p-ordem-1) != "#" && *(p-ordem-1) != "x")){
			
			if(*(p-ordem-1)!="?"){
			
				if(*(p-ordem-1)=="*"){
					//cout << "\n\nDECIMA\n\n";
					this->contPerigo++;
					this->reiniciar=true;
					continuar=false;
				}
				else{
					this->pontos++;
				}
				
				*(p-ordem-1)="x";
				*(b-ordem-1)=1;
				f.push((p-ordem-1));
				fv.push((b-ordem-1));
				
			}
			else{
				fim = true;
				*(b-ordem-1)=1;
				break;
			}
		
		}
		
		if( continuar && esquerda && (*(p-1)!="x" && *(p-1)!="#") ){
			
			if(*(p-1)!="?"){
			
				if(*(p-1)=="*"){
					//cout << "\n\nESQUERDA\n\n";
					this->contPerigo++;
					this->reiniciar=true;
					continuar=false;
				}
				else{
					this->pontos++;
				}
				*(p-1)="x";
				*(b-1)=1;
				f.push((p-1));
				fv.push((b-1));
				
			}
			else{
				fim = true;
				*(b-1)=1;
				break;
			}
		}
		
		
		
		f.pop(&p);
		fv.pop(&b);
		//p=str;
		//b=in;
		direita=true;
		cima=true;
		ddbaixo=true;
		debaixo=true;
		baixo=true;
		ddcima=true;
		decima=true;
		esquerda=true;
		
    }
    //cout << "\nTeste: " << teste <<"\n\n";
  //  setMatriz(this->ordem,vm);
    this->fim=false;
    f.clear();
    fv.clear();
}

