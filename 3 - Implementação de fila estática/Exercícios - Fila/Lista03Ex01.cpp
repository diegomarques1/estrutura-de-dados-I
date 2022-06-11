// Diego Souza Lima Marques
// TIA: 32039921

/*
Um vendedor de água pediu para você implementar um sistema que o ajude no trabalho.
Ele vende apenas duas marcas de água, A e B.
Para que o estoque dele esteja sempre com os produtos mais recentes, ele quer que seja possível cadastrar:
• O tipo (marca) da água;
• A data e hora em que o produto entrou no estoque;
• O número da estante onde o recipiente será armazenado;
• O número da prateleira onde o recipiente será armazenado;
• O número da gaveta onde o recipiente será armazenado.
Assim, na hora da venda, o sistema deve informar qual água ele deve retirar do estoque
(a mais antiga, de acordo com a marca escolhida pelo cliente).
Os clientes podem escolher entre comprar a água A, a água B ou qualquer uma (para o cliente, 
“tanto faz se é a água A ou B”).
Caso o cliente escolha:
• Água da marca A: O sistema deve apresentar as informações do produto A mais
antigo (marca, data/hora do cadastro, estante, prateleira e gaveta) e remover o produto do sistema.
Caso não exista mais água da marca A, o sistema deve exibir uma mensagem informando a falta no estoque.
• Água da marca B: O sistema deve apresentar as informações do produto B mais antigo e remover o produto do sistema.
Caso não exista mais água da marca B, o sistema deve exibir uma mensagem informando a falta no estoque.
• Qualquer uma: O sistema deve apresentar as informações do produto mais antigo do estoque, 
podendo ser da marca A ou B, e remover o produto do sistema.
Caso não exista mais nenhum produto no estoque, o sistema deve exibir uma mensagem informando que o estoque está vazio.
Para implementar esse sistema, você deve usar a estrutura de dados Fila (Queue), oferecendo operações como 
EnqueueA(), EnqueueB(), DequeueA(), DequeueB() e DequeueAny().
Na sua main(), escreva código que exemplifique o uso da sua implementação da fila e das operações disponíveis no sistema.
Opcional: Crie um menu de opções para cadastrar e remover produtos do estoque, assim como para encerrar a execução do sistema.
*/

/* COMENTÁRIOS DA CORREÇÃO:
No RemoveProduct(), a ordem do último if está incorreta, pois o if interno nunca é executado (há um return DequeueAny() antes). 
Há um warning também indicando que essa função pode não retornar um valor (ver lógica do código).

Como você está criando variáveis dentro dos cases do switch, coloque todas as instruções de cada case dentro de { }.

Futuramente, com o tempo, experiência e conhecimento, você começará a escrever soluções sem precisar duplicar códigos.
*/

#include <iostream>
#include "StaticQueue.h"
#include <ctime>
#include <string>

using namespace std;

Product RegisterProduct(StaticQueue &queueA, StaticQueue &queueB)
{
	Product newProduct;
	int estante, prateleira, gaveta;
	cout << "\nMarca da água (A ou B): ";
	cin >> newProduct.brand;
	while (toupper(newProduct.brand) != 'A' && toupper(newProduct.brand) != 'B') // Validação da marca
	{
		cout << "Marca inválida! Por favor, digite novamente: ";
		cin >> newProduct.brand;
	}
	cout << "\nNúmero da estante de armazenamento: ";
	cin >> newProduct.rack;
	cout << "\nNúmero da prateleira de armazenamento: ";
	cin >> newProduct.shelf;
	cout << "\nNúmero da gaveta de armazenamento: ";
	cin >> newProduct.drawer;
	time_t data = time(nullptr);
	newProduct.date = data;
	if (toupper(newProduct.brand == 'A'))
	{
		bool x = EnqueueA(queueA, newProduct);
		if (x == false)
		{
			cout << "Não foi possível adicionar o produto no estoque da marca A, pois está cheio! \n";
		}
	}
	if (toupper(newProduct.brand == 'B'))
	{
		bool y = EnqueueB(queueB, newProduct);
			if (y == false)
			{
				cout << "Não foi possível adicionar o produto no estoque da marca B, pois está cheio! \n";
			}
	}
	return newProduct;
}

void PrintProduct(const Product &prod)
{
	if (prod.brand != '0')
	{
		cout << "\nPRODUTO: \n";
		cout << "Marca da água: " << prod.brand << "\n";
		cout << "Data e hora em que o produto entrou no estoque: \n";
		tm timeInfo;
		localtime_s(&timeInfo, &prod.date);
		cout << "- Data: " << timeInfo.tm_mday << '/' << (timeInfo.tm_mon + 1) << "/" << (timeInfo.tm_year + 1900) << "\n" <<
			"- Hora: " << timeInfo.tm_hour << "h" << timeInfo.tm_min << "min" << timeInfo.tm_sec << "s\n";
		cout << "Estante de armazenamento: " << prod.rack << "\n";
		cout << "Prateleira de armazenamento: " << prod.shelf << "\n";
		cout << "Gaveta de armazenamento: " << prod.drawer << "\n";
	}
}

Product RemoveProduct(StaticQueue& queueA, StaticQueue& queueB)
{
	char marcaTemp;
	cout << "Deseja comprar o produto da marca A, B ou tanto faz (T)?\n";
	cin >> marcaTemp;
	while (toupper(marcaTemp) != 'A' && toupper(marcaTemp) != 'B' && toupper(marcaTemp) != 'T') // Validação da marca
	{
		cout << "Escolha inválida! Por favor, digite novamente (A, B ou T): ";
		cin >> marcaTemp;
	}
	if (toupper(marcaTemp) == 'A')
	{
		if (IsEmpty(queueA))
		{
			cout << "Não foi possível vender o produto da marca A, pois o estoque está vazio! \n";
		}
		return DequeueA(queueA);
		
	}
	else if (toupper(marcaTemp) == 'B')
	{
		if (IsEmpty(queueB))
		{
			cout << "Não foi possível vender o produto da marca B, pois o estoque está vazio! \n";
		}
		return DequeueB(queueB);
	}
	else if (toupper(marcaTemp) == 'T')
	{
		if (IsEmpty(queueA) && IsEmpty(queueB))
		{
			cout << "Não foi possível vender o produto de qualquer marca, pois ambos os estoques estão vazios! \n";
		}
		return DequeueAny(queueA, queueB);
	}
}

void Test(StaticQueue queueA, StaticQueue queueB)
{
	time_t data = time(nullptr);
	Product product1 = { 'A', data, 1, 2, 3 };
	Product product2 = { 'A', data, 1, 1, 1 };
	Product product3 = { 'B', data, 1, 2, 3 };
	EnqueueA(queueA, product1);
	EnqueueA(queueA, product2);
	EnqueueB(queueB, product3);
	cout << "Produtos adicionados em suas respectivas filas\n";
	cout << "Fila A vazia? " << IsEmpty(queueA) << '\n';
	cout << "Fila B vazia? " << IsEmpty(queueB) << '\n';
	Product remov1 = DequeueA(queueA);
	cout << "Removido o primeiro produto da fila A\n";
	cout << "Fila A vazia? " << IsEmpty(queueA) << '\n';
	cout << "Fila B vazia? " << IsEmpty(queueB) << '\n';
	Product remov2 = DequeueAny(queueA, queueB);
	cout << "Removido o mais antigo entre as duas filas\n";
	cout << "Fila A vazia? " << IsEmpty(queueA) << '\n';
	cout << "Fila B vazia? " << IsEmpty(queueB) << '\n';
	Product remov3 = DequeueAny(queueA, queueB);
	cout << "Removido o mais antigo entre as duas filas\n";
	cout << "Fila A vazia? " << IsEmpty(queueA) << '\n';
	cout << "Fila B vazia? " << IsEmpty(queueB) << '\n';
	Product product4 = RegisterProduct(queueA, queueB);
	cout << "Marca: " << product4.brand << '\n';
	cout << "Data: " << product4.date << '\n';
	cout << "Estante: " << product4.rack << '\n';
	cout << "Prateleira: " << product4.shelf << '\n';
	cout << "Gaveta: " << product4.drawer << '\n';
	Product remov4 = RemoveProduct(queueA, queueB);
	cout << "Marca: " << remov4.brand << '\n';
	cout << "Data: " << remov4.date << '\n';
	cout << "Estante: " << remov4.rack << '\n';
	cout << "Prateleira: " << remov4.shelf << '\n';
	cout << "Gaveta: " << remov4.drawer << '\n';
}

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	cout << "Lista de exercícios 03\n";
	StaticQueue queueA = Create();
	StaticQueue queueB = Create();
	int option = 0;
	do
	{
		cout << "\nMENU DE OPÇÕES:\n"
			<< "[0] Sair\n"
			<< "[1] Cadastrar produto\n"
			<< "[2] Vender produto\n"
			<< "[3] Teste\n"
			<< "Escolha uma opção: ";
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case 1:
		{
			Product prod = RegisterProduct(queueA, queueB);
			cout << "\nO produto foi adicionado com sucesso! \n";
			PrintProduct(prod);
		}
		break;
		case 2:
		{
			Product prod2 = RemoveProduct(queueA, queueB);
			if (toupper(prod2.brand) == 'A' || toupper(prod2.brand) == 'B' || toupper(prod2.brand) == 'T')
			{
				cout << "Produto vendido com sucesso! \n";
				PrintProduct(prod2);
			}
			else
			{
				cout << "Fora de estoque. \n";
			}
		}
		break;
		case 3:
			Test(queueA, queueB);
			break;
		default:
			if (option != 0)
			{
				cout << "\nOperação inválida!\n";
			}
			break;
		}
	} while (option != 0);
	cout << "\nEncerrando o programa...";
}



