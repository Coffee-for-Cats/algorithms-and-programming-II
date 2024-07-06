/*
Desenvolver um programa como menu para manipulação de dados de clientes. O estabelecimento pode ter até 15 clientes e pode incluir mais dados cada vez que manipula o menu ou toda vez que executa o programa.
A estrutura de dados servirá para armazenar o cadastro dos clientes de uma loja: nome [30], CPF (tamanho 11), endereço [30], bairro, data de nascimento,  data da última compra, valor acumulado comprado.
Endereço: rua e número.

Menu:
  1 - Cadastrar cliente
  2 - Listar cliente que fez a última compra em uma data informada pelo teclado (informar CPF, nome e endereço)
  3 - Contar quantos clientes moram em um bairro informado pelo teclado
  4- Listar o nome do cliente que tem o maior valor acumulado de compras
  5 - Fim
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct endereco {
  char bairro[15],
  int  numero,
} Endereco;

typedef struct data {
  int dia,
  int mes,
  int ano,
} Data;

typedef struct cliente {
  char nome[30],
  char cpf[11],
  Endereco endereco,
  Data nascimento
} Cliente;

void erro() {
  printf("Valor incorreto digitado, tente novamente.");
}

void cadastrarCliente(Cliente* clientes) {

}

void listarCompraPorData(Cliente* clientes) {

}

void contarClientesPorBairro(Cliente* clientes) {

}

void clienteMaiorValorAcumulado(Cliente* clientes) {

}

int main() {

  char* menu = "
  1 - Cadastrar cliente
  2 - Listar cliente que fez a última compra em uma data informada pelo teclado (informar CPF, nome e endereço)
  3 - Contar quantos clientes moram em um bairro informado pelo teclado
  4 - Listar o nome do cliente que tem o maior valor acumulado de compras
  5 - Fim
  ";

  Cliente clientes[16];
  clientes[0] = null;

  int continuar = true;
  int op;

  while(op != 5) {
    printf(menu);
    scanf("%d", &op);
    switch(op) {
      case 1: cadastrarCliente(clientes);
        break;
      case 2: listarCompraPorData(clientes);
        break;
      case 3: contarClientesPorBairro(clientes);
        break;
      case 4: clienteMaiorValorAcumulado(clientes);
        break;
      case 5: printf("Saindo do programa...");
        break;
      default: erro();
    }
  }
}