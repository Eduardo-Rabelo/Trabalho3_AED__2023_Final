#include <iostream>
#include "Jogo.hpp"
using namespace std;

Jogo::Jogo(){
	stringstream s;
	string str,aux;
	
	vector<string> vecs,vs;
	
	ifstream File("dataset/input.data");

	getline(File,str);
	
		for(int j=0;j<str.size();j++){
		
			if(str[j] == ' ' && aux!="" ){
				vecs.push_back(aux);
				aux="";
			}
			else if(str[j] != ' '){
				aux.push_back(str[j]);
			}
			
			
		}
		vecs.push_back(aux);
		
	aux="";
	
	this->ordem = stoi(vecs[0]);
	//this->numMatriz = stoi(vecs[2]);
	this->numMatriz = 1;
	
	vecs.clear();
	
	for(int i=0; i < this->numMatriz; i++){
		
		stringstream ss;
		string a,fileName="dataset/Matriz";
		ss << (i+1);
		ss >> a;
		fileName.append(a).append(".txt");
		ofstream File2(fileName);
    		for(int j=0; j < this->ordem + 1; j++){
    			getline(File,str);
    			File2 << str << "\n";
    		}
    		File2.close();
	}
	
	
	
	
	
	
	ifstream fileFase("dataset/Matriz1.txt");
	while(getline(fileFase,str)){
		vs.push_back(str);
	}
	
	for(int i=0;i<vs.size();i++){
		for(int j=0;j<vs[i].size();j++){
		
			if(vs[i][j] == ' ' && aux!="" ){
				vecs.push_back(aux);
				aux="";
			}
			else if(vs[i][j] != ' '){
				aux.push_back(vs[i][j]);
			}
			
			
		}
	
	}
	vs.clear();
	vecs.push_back(aux);
	cout << "\n\n\n";
	

	setFase(this->ordem,vecs);
	vecs.clear();
}

void Jogo::setFase(int ordem,vector<string>v){
    this->fase.setMatriz(ordem,v);
}

void Jogo::jogarRandon(){
	
		string s="Busca Aleatória:";
		cout << "\n\nPRIMEIRA FASE: "<< "\n\n";
		this->fase.imprimeMatriz();
		this->fase.percorreMatrizRandom();
		this->numPerigo = this->numPerigo + this->fase.getContPerigo();
		this->fase.salvaMatriz(this->numeroDaFase);
		cout << "\n\nPRIMEIRA FASE PERCORRIDA: " << "\n\n";
		this->fase.imprimeMatriz2();
		//this->fase.reiniciarMatriz();
		reiniciarJogo();
   		salvaJogo(s);
   		
}


void Jogo::reiniciarJogo(){
	this->fase.reiniciarMatriz();
	this->numPerigo=0;
	this->totalCasasPercorridas=0;
	//this->numl=1;
	//this->numc=1;
	//this->numeroDaFase=1;
	//this->notfim = true;
}


void Jogo::salvaJogo(string s){

	string str,aux;
	vector<string> vecs,vs;
	stringstream ss;
	string a,fileName="dataset/Matriz";
	
	fstream File;
	File.open("dataset/output.data", ios::app);
	
	File << s << "\n\n";
	
	File << this->ordem << " " << this->ordem << " " << this->numMatriz << endl;
//for(int i=0; i < this->numMatriz; i++){
	
	//stringstream ss;
	//string a,fileName="dataset/Matriz";
	ss << (1);
	ss >> a;
	fileName.append(a).append(".txt");
	ifstream File2(fileName);
	for(int j=0; j < this->ordem + 1; j++){
		getline(File2,str);
		File << str << "\n";
	}
	
	std::filesystem::remove(fileName);
//}

//File2.close();
	File << "\n\nMATRIZ VERDADE(1 = casa foi acessada pelo personagem, 0 = não foi):\n\n";
//for(int i=0; i < this->numMatriz; i++){
	
	//stringstream ss;
	//string a,
	
	fileName="dataset/MatrizB";
	ss << (1);
	ss >> a;
	fileName.append(a).append(".txt");
	ifstream File3(fileName);
	if(File3){
		File << "MATRIZ VERDADE " << 1 <<":\n\n";
    		for(int j=0; j < this->ordem + 1; j++){
    			getline(File3,str);
    			for(int k=0;k<str.size();k++){
    				if(str[k]=='1'){
    					this->totalCasasPercorridas++;
    				}
    			}
    			File << str << "\n";
    		}
	}
	
	File << "\n\n\n\n";
	File.close();
	std::filesystem::remove(fileName);
//}
	int c=((this->ordem*this->ordem*this->numMatriz)-this->totalCasasPercorridas);
	cout << "\n				TOTAL DE CASAS PERCORRIDAS AO MENOS UMA VEZ: " << this->totalCasasPercorridas << "\n\n";
	cout << "				TOTAL DE CASAS NUNCA PERCORRIDAS: " << c << "\n\n";
	//this->fase.reiniciarMatriz();
}










void Jogo::jogarProfundo(){

	string s="Busca em Profundidade:";
	cout << "\n\nPRIMEIRA FASE: "<< "\n\n";
	this->fase.imprimeMatriz();
	this->fase.percorreMatrizProfundo();
	this->numPerigo = this->numPerigo + this->fase.getContPerigo();
	this->fase.salvaMatriz(this->numeroDaFase);
	cout << "\n\nPRIMEIRA FASE PERCORRIDA: " << "\n\n";
	this->fase.imprimeMatriz2();
	//this->fase.reiniciarMatriz();
	reiniciarJogo();
	salvaJogo(s);

}

void Jogo::jogarLargura(){
	
	string s="Busca em Largura:";
	cout << "\n\nPRIMEIRA FASE: "<< "\n\n";
	this->fase.imprimeMatriz();
	this->fase.percorreMatrizLargura();
	this->numPerigo = this->numPerigo + this->fase.getContPerigo();
	this->fase.salvaMatriz(this->numeroDaFase);
	cout << "\n\nPRIMEIRA FASE PERCORRIDA: " << "\n\n";
	this->fase.imprimeMatriz2();
	//this->fase.reiniciarMatriz();
	reiniciarJogo();
	salvaJogo(s);

}








