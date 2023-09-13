#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro () // Função responsável por cadastrar os usuários no sistema
{
	// Início da criação das variáveis / String
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação das variáveis / String

	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); // %s se refere a string
	
	strcpy(arquivo,cpf); //responsável por copiar os valores das strings do cpf para arquivo
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo e o w significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Arquivo não localizado. Tente um CPF válido \n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\n Seguem as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado! \n");
		system("pause");
		
	}
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for (laco-1;laco=1;)
	{
	
		system("cls"); // responsavel por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
		printf("### CARTÓRIO DA EBAC ### \n\n"); // Início do menu
		printf ("Escolha a opção desejada do menu: \n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n"); 
		printf("\t4- Sair do sistema \n\n");
		printf("Digite a opção aqui: ");  
		 // Final do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário. uma pausa
	
		system("cls"); //Limpa toda a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro ();
			break;
			
			case 2:	
			consultar ();
			break;
			
			case 3:
			deletar ();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema \n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível. Escolha uma opção válida\n");
			system("pause");  
			break;	
		} // fim da seleção
	}
}

