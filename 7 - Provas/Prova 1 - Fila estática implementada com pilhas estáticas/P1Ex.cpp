// Diego Souza Lima Marques
// TIA: 32039921
// P1 - Estrutura de Dados I

#include <iostream>
#include "StaticStack.h"
#include "StaticQueue.h"

using namespace std;
using namespace DataStructures;

void printFila(const Queue::StaticQueue queue)
{
    if (Queue::IsEmpty(queue))
    {
        cout << "Fila vazia!\n";
    }
    else
    {
        Stack::StaticStack stackTemp = queue.stackAux;
        cout << "\nFila = ";
        for (char c : stackTemp.values)
        {
            cout << c << " ";
        }
        cout << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    cout << "P1 - Estrutura de Dados I\n";
    Queue::StaticQueue queue = Queue::Create();
    int option = 0;
    do
    {
        cout << "\nMENU DE OPÇÕES:\n"
            << "0 - Sair\n"
            << "1 - Adicionar elemento no final da fila\n"
            << "2 - Remover o primeiro elemento da fila\n"
            << "3 - Mostrar todos os elementos da fila\n"
            << "4 - Verificar o primeiro elemento da fila\n"
            << "5 - Verificar a quantidade de elementos da fila\n"
            << "6 - Verificar a capacidade da fila\n"
            << "7 - Verificar se a fila está vazia\n"
            << "8 - Esvaziar a fila\n"
            << "9 - Teste\n";
        cout << "Opção escolhida: \n";
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
            char tempAdd;
            bool verif;
            cout << "\nDigite o caractere que deseja adicionar no final da fila: \n";
            cin >> tempAdd;
            verif = Queue::Enqueue(queue, tempAdd);
            if (verif == false)
            {
                cout << "Não foi possível adicionar o elemento, pois a fila está cheia.\n";
            }
            break;
        case 2:
            char temp;
            cout << "\nRemovendo o primeiro elemento da fila...\n";
            temp = Queue::Dequeue(queue);
            if (temp == '\0')
            {
                cout << "Não foi possível remover o primeiro elemento, pois a fila está vazia.\n";
            }
            break;
        case 3:
            printFila(queue);
            break;
        case 4:
            cout << "\nPrimeiro elemento da fila: " << Queue::Front(queue) << "\n";
            break;
        case 5:
            cout << "\nQuantidade de elementos na fila: " << Queue::Count(queue) << "\n";
            break;
        case 6:
            cout << "\nCapacidade da fila: " << Queue::Size(queue) << "\n";
            break;
        case 7:
            char empty;
            empty = Queue::IsEmpty(queue) ? 'S' : 'N';
            cout << "\nA fila está vazia? " << empty << "\n";
            break;
        case 8:
            cout << "\nEsvaziando a fila...\n";
            Queue::Clear(queue);
            break;
        case 9:
            Queue::StaticQueue queueTest = Queue::Create();
            char removed, vazio;
            cout << "\nAdicionando o caractere 'A' na fila...\n";
            Queue::Enqueue(queueTest, 'A');
            cout << "Adicionando o caractere 'B' na fila...\n";
            Queue::Enqueue(queueTest, 'B');
            cout << "Adicionando o caractere 'C' na fila...\n";
            Queue::Enqueue(queueTest, 'C');
            cout << "Mostrando a fila atual...\n";
            printFila(queueTest);
            cout << "Removendo o primeiro caractere da fila...\n";
            removed = Queue::Dequeue(queueTest);
            cout << "Caractere removido: " << removed << "\n";
            cout << "Mostrando a fila atualizada...\n";
            printFila(queueTest);
            cout << "Primeiro elemento da fila: " << Queue::Front(queueTest) << "\n";
            cout << "\nQuantidade de elementos na fila: " << Queue::Count(queueTest) << "\n";
            vazio = Queue::IsEmpty(queueTest) ? 'S' : 'N';
            cout << "\nA fila está vazia? " << vazio << "\n";
            cout << "\nEsvaziando a fila...\n";
            Queue::Clear(queueTest);
            vazio = Queue::IsEmpty(queueTest) ? 'S' : 'N';
            cout << "\nA fila está vazia? " << vazio << "\n";
            printFila(queueTest);
            break;
        default:
            if (option != 0)
            {
                cout << "Opção inválida!\n";
            }
            break;
        }
    } while (option != 0);
    cout << "Encerrando o programa...";
}

