#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct noData
{
    int dia;
    int mes;
    int ano;
} noData;

typedef struct noEndereco
{
    char rua[200];
    int numero;
    char cidade[200];
    char estado[200];
} noEndereco;

typedef struct noCliente
{
    char cpf[11];
    char nome[200];
    char telefone[50];
    struct noEndereco endereco_cliente;
    struct noData data_nascimento;
} noCliente;

typedef struct arvore
{
    struct noCliente cliente;
    struct arvore *left;
    struct arvore *right;
} arvore;
typedef struct arvore *tree;

tree createNode();
tree cadastrarCliente(tree root, tree node);
tree MaiorDireita(tree no);
tree removerCliente(tree root, char cpf[]);
void consultaCliente(tree root, char cpf[]);
void alterarDados(tree root, char cpf[]);
void mostrarTodosClientes(tree root);
void mostraClienteIdade(tree root, int idade);
void contadorCliente(tree root, int *cont);
void mostrarDadosClientes(tree root);

int main() {
   tree node;
   tree root = NULL;
   int ok=0, op_alternativa, op_principal, cont_cliente=0, idade;
   char cpf[11];
   do {
      printf("--------------------------------------------\n");
      printf("\t\t--MENU--\n");
      printf("1- CADASTRAR CLIENTE.\n");
      printf("2- CONSULTAR CLIENTE.\n");
      printf("3- MOSTRAR CLIENTES.\n");
      printf("4- ALTERAR DADOS CLIENTE.\n");
      printf("5- DELETAR CLIENTE.\n");
      printf("0- SAIR.\n");
      printf("--------------------------------------------\n\n");
      printf("ESCOLHA UMA OPCAO:");
      scanf("%d", &op_principal);
      printf("\n");
      system("cls");
      switch(op_principal) {
         case 1:
            printf("\t\t--CADASTRO DE CLIENTE--\n");
            node = createNode();
            root = cadastrarCliente(root, node);
            break;
         case 2:
            printf("\t\t--CONSULTA DE CLIENTE--\n");
            setbuf(stdin,NULL);
            printf("DIGITE O CPF PARA CONSULTA:");
            gets(cpf);
            consultaCliente(root, cpf);
            break;
         case 3:
            printf("\t\t--MOSTRAR CLIENTE--\n");
            do
            {
               printf("ESCOLHA UMA OPCAO:\n");
               printf("1- MOSTRAR TODOS CLIENTES CADASTRADOS.\n");
               printf("2- MOSTRAR QUANTOS CLIENTES CADASTRADOS.\n");
               printf("3- QUAIS CLIENTES ESTAO ACIMA DE CERTA IDADE.\n");
               scanf("%d", &op_alternativa);
               system("cls");
               switch(op_alternativa){
               case 1:
                  printf("\t\t--MOSTRAR TODOS OS CLIENTES CADASTRADOS--\n");
                  mostrarTodosClientes(root);
                  ok=1;
                  break;
               case 2:
                  printf("\t\t--MOSTRAR QUANTOS CLIENTES CADASTRADOS--\n");
                  contadorCliente(root, &cont_cliente);
                  printf("%d CLIENTES CADASTRADOS.\n", cont_cliente);
                  ok=1;
                  break;
               case 3:
                  printf("\t\t--QUAIS CLIENTES ESTAO ACIMA DE CERTA IDADE--\n");
                  printf("DIGITE A IDADE PARA COMPARACAO:");
                  scanf("%d", &idade);
                  mostraClienteIdade(root, idade);
                  ok=1;
                  break;
               default:
                 printf("OPCAO INVALIDA DIGITE NOVAMENTE!!\n");
               }
            }while(ok!=1);
            break;
            case 4:
               printf("\t\t--ALTERACAO DE DADOS--\n");
               printf("DIGITE O CPF PARA ALTERACAO:");
               setbuf(stdin,NULL);
               gets(cpf);
               alterarDados(root, cpf);
               break;
            case 5:
               printf("\t\t--DELETAR CLIENTE--\n");
               printf("DIGITE O CPF PARA DELECAO:");
               setbuf(stdin,NULL);
               gets(cpf);
               root=removerCliente(root, cpf);//ROOT RECEBE REMOVER PARA ATUALIZAR NOSSA ARVORE BINARIA
               break;
            case 0:
               printf("SAINDO...\n");
               break;
            default:
            printf("OPCAO INVALIDA DIGITE NOVAMENTE!!\n");
            break;
         }
      }while(op_principal!= 0);
   return 0;
}

tree createNode() {//FUNCAO QUE PERMITE O USUARIO DIGITAR OS DADOS DOS CLIENTES, SALVANDO EM UM NO PARA DEPOIS IMPLEMENTALO NA ARVORE

    tree root = (tree) malloc(sizeof(arvore));
    if(!root)
        return NULL;

    root->left = NULL;
    root->right = NULL;
    printf("DIGITE O CPF DO CLIENTE:");
    setbuf(stdin, NULL);
    gets(root->cliente.cpf);
    setbuf(stdin, NULL);
    printf("DIGTE O NOME DO CLIENTE:");
    gets(root->cliente.nome);
    setbuf(stdin, NULL);
    printf("DIGITE O TELEFONE PARA CONTATO:");
    gets(root->cliente.telefone);
    printf("DIGITE SEU ENDERECO:\n");
    printf("RUA:");
    setbuf(stdin,NULL);
    gets(root->cliente.endereco_cliente.rua);
    printf("NUMERO:");
    scanf("%d", &root->cliente.endereco_cliente.numero);
    printf("CIDADE:");
    setbuf(stdin,NULL);
    gets(root->cliente.endereco_cliente.cidade);
    printf("ESTADO:");
    setbuf(stdin,NULL);
    gets(root->cliente.endereco_cliente.estado);
    printf("DIGITE SUA DATA DE NASCIMENTO:\n");
    printf("DIA:");
    scanf("%d", &root->cliente.data_nascimento.dia);
    setbuf(stdin, NULL);
    printf("MES:");
    scanf("%d", &root->cliente.data_nascimento.mes);
    printf("ANO:");
    scanf("%d", &root->cliente.data_nascimento.ano);

    return root;
}

tree cadastrarCliente(tree root, tree node){//FUNCAO Q CRIA OS NOS E REALIZA O CADASTRO
   if(root==NULL){
      return node;
   }
   if(strcmp(node->cliente.cpf, root->cliente.cpf)<0){//VERIFICA SE O CPF DIGITADO E MENOR QUE O CPF DIGITADOS ANTERIORMENTE, REALIZANDO A ORDENACAO JOGANDO PARA O NO DA ESQUERDA
      root->left = cadastrarCliente(root->left, node);
      printf("CLIENTE CADASTRADO!!\n");
   }
   else if((strcmp(node->cliente.cpf, root->cliente.cpf)>0)){//VERUFUCA SE O CPF DIGITADO E MAIOR QUE OS CPFS DIGITADOS ANTERIORMENTE, REALIZANDO A ORDENACAO JOGANDO PARA O NO DA DIREITA
      root-> right = cadastrarCliente(root-> right, node);
      printf("CLIENTE CADASTRADO!!\n");
   }
   else if(strcmp(node->cliente.cpf, root->cliente.cpf) == 0){//VERIFICA SE POSSUI CPFS COM OS MESMOS NUMEROS CADASTRADOS, CASO HOUVER, NAO REALIZA O CADASTRO
      printf("CLIENTE JA CADASTRADOO!!\n");
   }
   return root;
}

tree MaiorDireita(tree no)
{
    if(no!= NULL)
    {
       return MaiorDireita(no->right);
    }
    else
    {
       tree aux = no;

       if(no->left != NULL)
        {
          no = no->left;
        }
        else
        {
            no = NULL;
            return aux;
        }
    }
    return NULL;
}


tree removerCliente(tree root, char cpf[])
{
    tree p;
    if(root == NULL)
        return root;
    if(strcmp(root->cliente.cpf, cpf) > 0)
    {
        root->right = removerCliente(root->right,cpf);
    }
    else
    {
        root->left = removerCliente(root->left,cpf);
    }
    if(strcmp(root-> cliente.cpf, cpf) == 0)
    {
        printf("CLIENTE REMOVIDO:\n");
        mostrarDadosClientes(root);
        printf("---------------------\n");
        if(!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        else if(!root->left)
        {
            p = root->right;
            free(root);
            return p;
        }
        else if(!root->right)
        {
            p = root->left;
            free(root);
            return p;
        }
        else if (root->left && root->right)
        {
            tree aux ;
            aux = MaiorDireita(root->left);
            aux->left = root->left;
            aux->right= root->right;
            root->left = root->right = NULL;
            free(root);
            root = aux;
            aux = NULL;
        }
    }
    return root;
}



void consultaCliente(tree root, char cpf[30])//CONSULTA CLIENTE PELO CPF, SE ACHAR MOSTRA OS DADOS DO MESMO
{

    if (root != NULL)
    {

        if(strcmp(root->cliente.cpf, cpf) == 0)
        {
            mostrarDadosClientes(root);
            return;
        }else{
            printf("CLIENTE NAO CADASTRADO!!\n");
        }
        consultaCliente(root-> left, cpf);
        consultaCliente(root-> right, cpf);
    }
}


void mostrarTodosClientes(tree root) {//FUNCAO QUE MOSTRA TODOS OS CLIENTES CADASTRADOS
    if(root != NULL) {
        mostrarTodosClientes(root-> left);
        mostrarDadosClientes(root);
        mostrarTodosClientes(root-> right);
    }
}

void mostraClienteIdade(tree root, int idade)//CONSULTA OS CLIENTES QUE POSSUIEM IDADE MAIOR QUE A O USUARIO DIGITOU
{
    int idade_comparar;
    if (root != NULL)
    {
        idade_comparar=2020-root->cliente.data_nascimento.ano;
        if(idade_comparar > idade)
        {
            mostrarDadosClientes(root);
        }
        mostraClienteIdade(root->left, idade);
        mostraClienteIdade(root->right, idade);
    }
}

void contadorCliente(tree root, int *cont)
{
   if(root != NULL)
    {
        *cont = *cont + 1;
        contadorCliente(root-> left, cont);
        contadorCliente(root-> right, cont);
    }
}

void alterarDados(tree root, char cpf[30])//FAZ UMA BUSCA POR CPF, VERIFICA SE O CLIENTE ESTA CADASTRADO OU NAO, CASO ESTIVER O USUARIO PODE ESCOLHER QUAIS DADOS ALTERAR
{
    int op_alternativa = 0;

    if(root != NULL)
    {

        if(strcmp(root-> cliente.cpf, cpf) == 0)
        {

            do
               {
               printf("ESCOLHA UMA OPCAO:\n");
               printf("1- ALTERAR CPF.\n");
               printf("2- ALTERAR NOME E TELEFONE.\n");
               printf("3- ALTERAR ENDERECO.\n");
               printf("4- ALTERAR DATA DE NASCIMENTO.\n");
               printf("0- SAIR.\n");
               printf("ESCOLHA UMA OPCAO:");
               scanf("%d", &op_alternativa);
               system("cls");
               switch(op_alternativa){
               case 1:
                  printf("\t\t--ALTERAR CPF--\n");
                  printf("CPF DO CLIENTE:");
                  printf("%s\n",root->cliente.cpf);
                  break;
               case 2:
                  printf("\t\t--ALTERAR NOME E ENDERECO--\n");
                  printf("NOME DO CLIENTE:");
                  printf("%s", root->cliente.nome);
                  printf("TELEFONE:");
                  printf("%s\n", root->cliente.telefone);
                  break;
               case 3:
                  printf("\t\t--ALTERAR ENDERECO--\n");
                  printf("DIGITE SEU NOVO ENDERECO:\n");
                  printf("RUA:");
                  setbuf(stdin,NULL);
                  gets(root->cliente.endereco_cliente.rua);
                  printf("NUMERO:");
                  scanf("%d", &root->cliente.endereco_cliente.numero);
                  printf("CIDADE:");
                  setbuf(stdin,NULL);
                  gets(root->cliente.endereco_cliente.cidade);
                  printf("ESTADO:");
                  setbuf(stdin,NULL);
                  gets(root->cliente.endereco_cliente.estado);
                  break;
               case 4:
                    printf("\t\t--ALTERAR DATA DE NASCIMENTO--\n");
                    printf("DIGITE SUA NOVA DATA DE NASCIMENTO:\n");
                    printf("DIA:");
                    scanf("%d", &root->cliente.data_nascimento.dia);
                    setbuf(stdin, NULL);
                    printf("MES:");
                    scanf("%d", &root->cliente.data_nascimento.mes);
                    printf("ANO:");
                    scanf("%d", &root->cliente.data_nascimento.ano);
                    break;
               case 0:
                    printf("SAINDO...");
               default:
                 printf("OPCAO INVALIDA DIGITE NOVAMENTE!!\n");
               }
            }while(op_alternativa!=0);
        }else{
            printf("CLIENTE NAO CADASTRADO!!\n");
        }
        alterarDados(root-> left, cpf);
        alterarDados(root-> right, cpf);
    }
}

void mostrarDadosClientes(tree root) {//FUNCAO PARA PRINTAR TODOS OS DADOS DO CLIENTE AO SE CHAMADA
    printf("NOME DO CLIENTE:");
    printf("%s\n", root->cliente.nome);
    printf("CPF DO CLIENTE:");
    printf("%s\n",root->cliente.cpf);
    printf("TELEFONE:");
    printf("%s\n", root->cliente.telefone);
    printf("DATA DE NASCIMENTO:");
    printf("%d/%d/%d\n", root->cliente.data_nascimento.dia, root->cliente.data_nascimento.mes, root->cliente.data_nascimento.ano);
    printf("ENDERECO:\n");
    printf("RUA:");
    printf("%s\n", root->cliente.endereco_cliente.rua);
    printf("NUMERO:");
    printf("%d\n", root->cliente.endereco_cliente.numero);
    printf("CIDADE:");
    printf("%s\n", root->cliente.endereco_cliente.cidade);
    printf("ESTADO:");
    printf("%s\n", root->cliente.endereco_cliente.estado);
    printf("\n");

    for(int i = 0; i < 20; i++) {
        printf("--");
    }
    printf("\n");
}
