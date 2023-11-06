#include <stdio.h> //biblioteca de comunicação com usuario.
#include <stdlib.h> //biblioteca de alocação de espaço em memoria.
#include <locale.h> //biblioteca de alocação de texto por regiao.
#include <string.h> //biblioteca responsavel pelas strings.


int registro() //Função para definir um nome.
{
	//Criação de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF que deseja cadastrar: "); //Inserir cpf do usuário.
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
	printf("Digite o nome que deseja cadastrar: "); //Inserir nome do usuário.
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //atualizando arquivo.
	fprintf(file,nome); //salvando valor da variavel nome.
	fclose(file); 
	
	file = fopen(arquivo, "a"); //atualizando arquivo.
	fprintf(file,",");
	fclose(file); //fechando arquivo.
	
	/////////////////////////////////////////////////////////////
	printf("Digite o sobrenome: "); //Inserir sobrenome do usuário.
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

int consultar() //Função para consultar um nome.
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
	//Criação de variaveis.
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: "); //Informar cpf já cadastrado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Lê tudo que está no arquivo
	
	if(file == NULL) //Validação para caso o cpf não existir.
	{
		printf ("Não foi possivel localizar este arquivo. Arquivo inexistente! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nDados do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Função para deletar um nome.
{
	char cpf[40];
	
	printf("Informe o CPF do usuario que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf); //Deleta arquivo.
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usuário não se encontra no sistema!\n");
		system("pause");
	}
	
		
	
	
}

int main()
{
	int opcao=0; //Definindo variavel.
	int x=1; //Definindo variavel de repetição.
	
	for(x=1;x=1;)
	{
		system("cls"); //Limpa a tela.
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
	
		printf("\tCartório EBAC \n\n");
		printf("\tMenu\n"); 
		printf("Escolha a opção desejada:\n\n"); //Inicio do menu.
		printf("1- Regristrar um Usuário\n"); //Opção para registrar um nome.
		printf("2- Consultar um Usuário\n"); //Opção para consultar um nome criado.
		printf("3- Deletar um Usuário\n"); //Opção para deletar um nome que foi criado.
		printf("4- Sair do sistema\n\n"); //Opção para fechar o sistema.
		printf("Opção: ");
		
		scanf("%d", &opcao); //Armazenando opção desejada.
		
		system("cls"); //Limpa a tela.
		switch(opcao)
		{
			case 1: //Regristro de nome.
				registro(); //Chamar função registro.
				break;
			case 2: //Consulta de nome.
				consultar(); //Chamar função consultar.
				break;
			case 3: //Deletar nome.
				deletar(); //Chamar função deletar.
				break;	
			case 4: //Fechar o sistema.
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			default: //Opçao invalida.
				printf("Opção invalida!\n");
				system("pause");
				break;		
		}
		
	
	}
}

