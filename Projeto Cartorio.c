#include <stdio.h> //biblioteca de comunica��o com usuario.
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria.
#include <locale.h> //biblioteca de aloca��o de texto por regiao.
#include <string.h> //biblioteca responsavel pelas strings.


int registro() //Fun��o para definir um nome.
{
	//Cria��o de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF que deseja cadastrar: "); //Inserir cpf do usu�rio.
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copia os valores das string.
	
	FILE *file; //criando arquivo.
	file = fopen(arquivo, "w"); //cria o arquivo.
	fprintf(file,cpf); //salvando valor da variavel cpf.
	fclose(file); //fechando arquivo.
	
	file = fopen(arquivo, "a"); //atualizando arquivo.
	fprintf(file,",");
	fclose(file); //fechando arquivo.
	
	//////////////////////////////////////////////////////
	printf("Digite o nome que deseja cadastrar: "); //Inserir nome do usu�rio.
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //atualizando arquivo.
	fprintf(file,nome); //salvando valor da variavel nome.
	fclose(file); 
	
	file = fopen(arquivo, "a"); //atualizando arquivo.
	fprintf(file,",");
	fclose(file); //fechando arquivo.
	
	/////////////////////////////////////////////////////////////
	printf("Digite o sobrenome: "); //Inserir sobrenome do usu�rio.
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salvando valor da variavel sobrenome.
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando arquivo.
	fprintf(file,",");
	fclose(file); //fechando arquivo
	
	/////////////////////////////////////////////////////////////////
	printf("Digite o cargo a ser cadastrado: "); //Inserir cargo do usuario.
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //salvando valor da variavel cargo.
	fclose(file);
	
	system("pause");
	
	
}

int consultar() //Fun��o para consultar um nome.
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
	//Cria��o de variaveis.
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: "); //Informar cpf j� cadastrado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //L� tudo que est� no arquivo
	
	if(file == NULL) //Valida��o para caso o cpf n�o existir.
	{
		printf ("N�o foi possivel localizar este arquivo. Arquivo inexistente! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nDados do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Fun��o para deletar um nome.
{
	char cpf[40];
	
	printf("Informe o CPF do usuario que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf); //Deleta arquivo.
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
		
	
	
}

int main()
{
	int opcao=0; //Definindo variavel.
	int x=1; //Definindo variavel de repeti��o.
	
	for(x=1;x=1;)
	{
		system("cls"); //Limpa a tela.
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
	
		printf("\tCart�rio EBAC \n\n");
		printf("\tMenu\n"); 
		printf("Escolha a op��o desejada:\n\n"); //Inicio do menu.
		printf("1- Regristrar um Usu�rio\n"); //Op��o para registrar um nome.
		printf("2- Consultar um Usu�rio\n"); //Op��o para consultar um nome criado.
		printf("3- Deletar um Usu�rio\n"); //Op��o para deletar um nome que foi criado.
		printf("4- Sair do sistema\n\n"); //Op��o para fechar o sistema.
		printf("Op��o: ");
		
		scanf("%d", &opcao); //Armazenando op��o desejada.
		
		system("cls"); //Limpa a tela.
		switch(opcao)
		{
			case 1: //Regristro de nome.
				registro(); //Chamar fun��o registro.
				break;
			case 2: //Consulta de nome.
				consultar(); //Chamar fun��o consultar.
				break;
			case 3: //Deletar nome.
				deletar(); //Chamar fun��o deletar.
				break;	
			case 4: //Fechar o sistema.
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			default: //Op�ao invalida.
				printf("Op��o invalida!\n");
				system("pause");
				break;		
		}
		
	
	}
}

