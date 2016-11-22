#include "../lib/No.h"

/**************************CONSTRUTOR**************************/
No::No(){

	nivel = 0;
	pagina=0;
	contador = 0;

	for(int i = 0; i < 5; i++){
		chave[i] = "";
		prr[0] = 0;
		filho[i] = NULL;
	}
	filho[5] = NULL;
	pai = NULL;

	std::cout<<"Objeto de No "<<this<<" criado."<<std::endl;
}

/**************************DESTRUTOR**************************/
No::~No(){

	std::cout<<"Objeto de No destruido."<<std::endl;
}


/**************************METODOS PUBLICOS**************************/
int No::insert(std::string chaveAInserir, int posNoDisco){

	bool troca = false;
	
	std::string tempS;
	int tempI;

	//Insere a chave em um espaco vazio
	chave[contador] = chaveAInserir;
	prr[contador] = posNoDisco;

	//E organiza em ordem cresncente as strings
	for(int i = 0; i < contador; i++){
		troca = false;
		for(int j = 0; j < contador; j++){
			if(chave[i].compare(chave[i+1])>0){
				troca = true;

				tempS = chave[i+1];
				chave[i+1] = chave[i];
				chave[i] = tempS;

				tempI = prr[i+1];
				prr[i+1] = prr[i];
				prr[i] = tempI;
			}
		}
		if(!troca) break;
	}

	contador++;
	
	for(int i = 0; i < contador; i++){
		if(chave[i] == chaveAInserir) return i;
	}

	return -1;
}

void No::erase(std::string chaveAApagar){
	
	for(int i = 0; i < contador; i++){
		if(chave[i] == chaveAApagar) {
			for(int j = i; j < contador; j++){
				if(j+1<contador){
					chave[j] = chave[j+1];
					prr[j] = prr[j+1];
					filho[j] = filho[j+1];
				}else{
					chave[j] = "";
					prr[j] = 0;
					filho[j] = NULL;
				}
			}
			break;

		}
	}

	contador--;

}
/**************************METODOS PRIVADOS**************************/

/**************************SETTERS & GETTERS**************************/
void No::setNivel(int n){
	nivel = n;
}

int No::getNivel(){
	return nivel;
}

void No::setContador(int c){
	contador = c;
}

int No::getContador(){
	return contador;
}

std::string No::getChave(int i){
	return chave[i];
}

int No::getPrr(int i){
	return prr[i];
}

void No::setFilho(No* node, int i){
	filho[i] = node;
}

No* No::getFilho(int i){
	return filho[i];
}

void No::setPai(No* node){
	pai = node;
}

No* No::getPai(){
	return pai;
}
