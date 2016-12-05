#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h> 
#define NULO '\0'
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <algorithm>

#include "../lib/CrtArvoreB.h"
#include "../lib/utils.h"

using namespace std;

int main (int argc, char *argv[]){
FILE *arquivo;
FILE *arquivo1, *arquivo2;
FILE *arqEntrada;
FILE *arqSaida;
	int line = 0;
	int linhas = 0;
	int i,cont=0,x;
	char textoArquivo[130],str[130],txt[130];
	char nomev[15],sobrenome[15],empresa[30],endereco[50],cidade[15],bairro[15],sigla[2],numero[10], cod1[15], cod2[15];
	

ifstream txtFile;
string linha;

int lin=0,mod;

char nome[100],date[50],developer[50];

	CrtArvoreB crtArvoreB;

	std::string fileName;
	std::string fileType;

	int choice = 0;
	//bool success = false;

	if(argc != 4 || strcmp(argv[2],"-r") != 0 ){
		std::cout<<"Uso incorreto do programa. (main data.txt -r (1|2))"<<std::endl;
		return 0;
	}

	if(!strcmp(argv[3],"1")){
		std::cout<<"Registro de tamanho variavel."<<std::endl;
		fileType = "rvar";
		mod=1;
	}else if(!strcmp(argv[3],"2")){
		std::cout<<"Registro de tamanho fixo."<<std::endl;
		fileType = "rfixo";
		mod=2;
	} else {
		std::cout<<"Uso incorreto do programa."<<std::endl;
		return 0;
	}

	fileName=argv[1];
	crtArvoreB.setUp(fileType,fileName);

	while(true){

		Utils util;		
		util.clear();

		std::cout<<"**********MENU PRINCIPAL**********"<<std::endl;
		std::cout<<"* 1 - Buscar Registro            *"<<std::endl;
		std::cout<<"* 2 - Inserir Registro           *"<<std::endl;
		std::cout<<"* 3 - Mostrar Arvore-B           *"<<std::endl;
		std::cout<<"* 4 - Sair                       *"<<std::endl;
		std::cout<<"**********************************"<<std::endl;
		std::cout<<std::endl;

		std::cout<<"Escolha um item: ";
		std::cin>>choice;

		if(choice>4 || choice<=0) return 0;

		switch(choice){
			case 1:
printf("BUSCA\n\n");
				//success=memoryController.writeMemory(files,myMemory);
				//if(success) files++;
				//crtArvoreB.buscar();
if (mod==1){
if((arqEntrada = fopen("../data1.txt", "r")) == 0){ //testa se o arquivo pode ser aberto
	printf("Impossivel abrir arquivo...\n"); //informa o erro
	exit(1); //finaliza execução
}
}
else if (mod==2){
if((arqEntrada = fopen("../data2.txt", "r")) == 0){ //testa se o arquivo pode ser aberto
	printf("Impossivel abrir arquivo...\n"); //informa o erro
	exit(1); //finaliza execução
}
}
if((arqSaida = fopen("../encoded.txt", "w")) == 0){ //testa se o arquivo pode ser aberto
	printf("Impossivel abrir arquivo...\n"); //informa o erro
	exit(1); //finaliza execução
}

if (mod==1)
printf("Digite a chave primária a ser lida no arquivo: XX"); //pede a linha
else if (mod==2)
printf("Digite a chave primária a ser lida no arquivo: ID"); //pede a linha

scanf("%d", &line); //le a linha e armazena na variável 'line'
rewind(arqEntrada); //certifica de que o cursor esta no primeiro caractere do arquivo

for(i = 0; !feof(arqEntrada);i++){ //incrementa 'i' enquanto não for fim de arquivo
		
	
	//memset(textoArquivo, NULO, 130); //inicializa e/ou limpa string 'textoArquivo'
	fgets(textoArquivo, 131, arqEntrada); //pega uma string de 130 caracteres
if (i+1==line)
strcpy(txt, textoArquivo);
	if(linhas+1 == line){ //se a linha for a escolhida
		//fputc('\n', arqSaida); //troca a linha que o usuario quer por nova linha
		linhas = linhas + 1; //incrementa o contador de linhas
		continue; //volta ao inicio do loop sem executar o resto
	}
	linhas = linhas + 1; //incrementa o contador de linas
	fputs(textoArquivo, arqSaida); //coloca a string 'textoArquivo' no arquivo encoded.txt

}
printf ("\n%s\n",txt);
//printf("Linhas: %d\n", (linha-1)); //imprime quantas linhas tem o arquivo lido
fclose(arqEntrada); //fecha a stream 'arqEntrada'
fclose(arqSaida); //fecha a stream 'arqSaida'
linhas=0;
remove("../encoded.txt");	
			break;
			case 2:
				cont++;
				//crtArvoreB.inserir();


if (mod==1)
txtFile.open("../data1.txt");
else if (mod==2)
txtFile.open("../data2.txt");

while(!txtFile.eof())
{

getline(txtFile,linha);

cout << linha << endl;
if(!txtFile.eof())

lin++;
}

txtFile.close();

cout << lin << " linhas" << endl;

if (mod==1){
arquivo = fopen("../data1.txt","a+");

printf("Digite o nome: ");
scanf("%s",nomev);
printf("Digite o sobrenome: ");
scanf("%s",sobrenome);
printf("Digite o nome da empresa: ");
scanf(" %[^\n]s",empresa);
printf("Digite o endereço: ");
scanf(" %[^\n]s",endereco);
printf("Digite o nome da cidade: ");
scanf(" %[^\n]s",cidade);
printf("Digite o nome do bairro: ");
scanf(" %[^\n]s",bairro);
printf("Digite a sigla do estado (2 letras maiúsculas): ");
scanf("%s",sigla);
printf("Digite o número: ");
scanf("%s",numero);
printf("Digite o primeiro código no formato 000-000-0000: ");
scanf("%s",cod1);
printf("Digite o segundo código no formato 000-000-0000: ");
scanf("%s",cod2);

fprintf(arquivo, "%s", sigla);
lin++;
if (lin<10)
fprintf(arquivo, "0000%d", lin);
if (lin>=10 && lin<100)
fprintf(arquivo, "000%d", lin);

fprintf(arquivo, ";");
fprintf(arquivo, "%s", nomev);
fprintf(arquivo, ";");
fprintf(arquivo, "%s", sobrenome);
fprintf(arquivo, ";");
fprintf(arquivo, "%s", empresa);
fprintf(arquivo, ";");
fprintf(arquivo, "%s", endereco);
fprintf(arquivo, ";");
fprintf(arquivo, "%s", cidade);
fprintf(arquivo, ";");
fprintf(arquivo, "%s", bairro);
fprintf(arquivo, ";");
fprintf(arquivo, "%s", cod1);
fprintf(arquivo, ";");
fprintf(arquivo, "%s\n", cod2);


printf("\nNovo registro cadastrado com sucesso!\n");
fclose(arquivo);
}

else if (mod==2){
arquivo = fopen("../data2.txt","a+");


printf("\nInserir registro!\n\nDigite o nome do jogo: ");

scanf(" %[^\n]s", nome);

if (strlen(nome)>63){ 
	do{
		printf("\nTamanho de nome muito grande!\nDigite o nome do jogo novamente: ");
		scanf(" %[^\n]s", nome);
	}while (strlen(nome)>63);
}

printf("\nEscreva a data no formato Mouth d, yyyy: ");
scanf(" %[^\n]s", date);

printf("\nEscreva o nome do desenvolvedor: ");
scanf(" %[^\n]s", developer);

lin++;

if (lin<10)
fprintf(arquivo, "ID0%d ", lin);
if (lin>=10 && lin<100)
fprintf(arquivo, "ID%d ", lin);


//Regula o tamanho de tabulação
if (strlen(nome)<=2){
fprintf(arquivo, "%s", nome);
fprintf(arquivo, "\t\t\t\t\t\t\t\t\t  %s", date);
}

else if (strlen(nome)>=3 && strlen(nome)<=10){
fprintf(arquivo, "%s", nome);
fprintf(arquivo, "\t\t\t\t\t\t\t\t  %s", date);
}

else if (strlen(nome)>=11 && strlen(nome)<=18){ 
fprintf(arquivo, "%s", nome);
fprintf(arquivo, "\t\t\t\t\t\t\t  %s", date);
}

else if (strlen(nome)>=19 && strlen(nome)<=26){ 
fprintf(arquivo, "%s", nome);
fprintf(arquivo, "\t\t\t\t\t\t  %s", date);
}

else if (strlen(nome)>=27 && strlen(nome)<=34){ 
fprintf(arquivo, "%s", nome);
fprintf(arquivo, "\t\t\t\t\t  %s", date);
}

else if (strlen(nome)>=35 && strlen(nome)<=42){ 
fprintf(arquivo, "%s", nome);
fprintf(arquivo, "\t\t\t\t  %s", date);
}

else if (strlen(nome)>=43 && strlen(nome)<=50){ 
fprintf(arquivo, "%s", nome);
fprintf(arquivo, "\t\t\t  %s", date);
}

else if (strlen(nome)>=51 && strlen(nome)<=58){ 
fprintf(arquivo, "%s", nome);
fprintf(arquivo, "\t\t  %s", date);
}

else if (strlen(nome)>=59){ 
fprintf(arquivo, "%s", nome);
fprintf(arquivo, "\t  %s", date);
}

fprintf(arquivo, "\t%s\n", developer);

/////////////////////////////////////////

printf("Novo registro cadastrado com sucesso!\n");
fclose(arquivo);
}

lin=0;

				break;
			case 3:
				crtArvoreB.mostrar();
				break;
			case 4:
for (x=cont;x>0;x--){	

				if (mod==1){
	if((arqEntrada = fopen("../data1.txt", "r")) == 0){ //testa se o arquivo pode ser aberto
		printf("Impossivel abrir arquivo...\n"); //informa o erro
		exit(1); //finaliza execução
	}}
else if (mod==2){
if((arqEntrada = fopen("../data2.txt", "r")) == 0){ //testa se o arquivo pode ser aberto
		printf("Impossivel abrir arquivo...\n"); //informa o erro
		exit(1); //finaliza execução
	}
}

	if((arqSaida = fopen("../encoded.txt", "w")) == 0){ //testa se o arquivo pode ser aberto
		printf("Impossivel abrir arquivo...\n"); //informa o erro
		exit(1); //finaliza execução
	}

	//printf("Digite a linha a ser apagada no arquivo: "); //pede a linha
	//scanf("%d", &line); //le a linha e armazena na variável 'line'
	if (mod==1)
		line=40+x;
	else if (mod==2)
		line=47+x;
	
	rewind(arqEntrada); //certifica de que o cursor esta no primeiro caractere do arquivo
	
	for(i = 0; !feof(arqEntrada);i++){ //incrementa 'i' enquando não for fim de arquivo
		memset(textoArquivo, NULO, 130); //inicializa e/ou limpa string 'textoArquivo'
		fgets(textoArquivo, 131, arqEntrada); //pega uma string de 130 caracteres
		if(linhas+1 == line){ //se a linha for a escolhida
			//fputc('', arqSaida); //troca a linha que o usuario quer por nova linha
			linhas = linhas + 1; //incrementa o contador de linhas
		continue; //volta ao inicio do loop sem executar o resto
		}
		linhas = linhas + 1; //incrementa o contador de linhas
		fputs(textoArquivo, arqSaida); //coloca a string 'textoArquivo' no arquivo encoded.txt
	}
	//printf("Linhas: %d\n", (linhas-1)); //imprime quantas linhas tem o arquivo lido
	

	fclose(arqEntrada); //fecha a stream 'arqEntrada'
	fclose(arqSaida); //fecha a stream 'arqSaida'

				arquivo1 = fopen("../encoded.txt", "r");
if (mod==1)  				
arquivo2 = fopen("../data1.txt", "w");
else if (mod==2)
arquivo2 = fopen("../data2.txt", "w");
		
				while(fgets(str, 100, arquivo1) != NULL)
				fputs(str,arquivo2);
    linhas=0;
    fclose(arquivo2);
    fclose(arquivo1);			

}
remove("../encoded.txt");
return 0;
				
				break;
		}

		std::cout<<"\nPressione ENTER para continuar..."<<std::endl;
		std::getchar();
		std::getchar();
	}

	return 0;
}
