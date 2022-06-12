// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include <iostream>
#include "StaticDeque.h"

using namespace std;

void PrintDeque(StaticDeque deque)
{
    if (IsEmpty(deque))
    {
        cout << "Deque vazia!\n";
    }
    else
    {
        cout << "\nDeque = ";
        for (char c : deque.values)
        {
            cout << c << " ";
        }
        cout << "\n";
    }
}

void Test(StaticDeque deque)
{
    StaticDeque dequeTemp = Create();
    char temp, empty;
    cout << "\nAdicionando o caractere 'A' no começo da deque...\n";
    InsertFront(dequeTemp, 'A');
    cout << "Adicionando o caractere 'B' no começo da deque...\n";
    InsertFront(dequeTemp, 'B');
    cout << "Adicionando o caractere 'C' no final da deque...\n";
    InsertBack(dequeTemp, 'C');
    cout << "Adicionando o caractere 'D' no final da deque...\n";
    InsertBack(dequeTemp, 'D');
    cout << "Mostrando a deque atual...\n";
    PrintDeque(dequeTemp);
    cout << "Removendo o primeiro caractere da deque...\n";
    temp = RemoveFront(dequeTemp);
    cout << "Caractere removido: " << temp << "\n";
    cout << "Mostrando a deque atualizada...\n";
    PrintDeque(dequeTemp);
    cout << "Removendo o último caractere da deque...\n";
    temp = RemoveBack(dequeTemp);
    cout << "Caractere removido: " << temp << "\n";
    cout << "Mostrando a deque atualizada...\n";
    PrintDeque(dequeTemp);
    cout << "Primeiro elemento da deque: " << Front(dequeTemp) << "\n";
    cout << "Último elemento da deque: " << Back(dequeTemp) << "\n";
    cout << "Quantidade de elementos na deque: " << Count(dequeTemp) << "\n";
    cout << "Capacidade de elementos na deque: " << Size(dequeTemp) << "\n";
    empty = IsEmpty(dequeTemp) ? 'S' : 'N';
    cout << "\nA deque está vazia? " << empty << "\n";
    cout << "\nEsvaziando a deque...\n";
    Clear(dequeTemp);
    empty = IsEmpty(dequeTemp) ? 'S' : 'N';
    cout << "\nA fila está vazia? " << empty << "\n";
    PrintDeque(dequeTemp);
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    cout << "PROJETO 1 - Estrutura de Dados I\n";
    StaticDeque deque = Create();
    int op = 0;
    do
    {
        cout << "\nMENU DE OPERAÇÕES:\n"
            << "0 - Sair\n"
            << "1 - Inserir o elemento no final da deque\n"
            << "2 - Inserir o elemento no início da deque\n"
            << "3 - Remover o último elemento da deque\n"
            << "4 - Remover o primeiro elemento da deque\n"
            << "5 - Mostrar todos os elementos da deque\n"
            << "6 - Verificar o primeiro elemento da deque\n"
            << "7 - Verificar o último elemento da deque\n"
            << "8 - Verificar a quantidade de elementos da deque\n"
            << "9 - Verificar a capacidade da deque\n"
            << "10 - Verificar se a deque está vazia\n"
            << "11 - Esvaziar a deque\n"
            << "12 - Teste\n";
        cout << "Opção escolhida: \n";
        cin >> op;
        cin.ignore();

        switch (op)
        {
        case 1:
            char elem1;
            cout << "\nDigite o caractere que deseja inserir no final da deque: \n";
            cin >> elem1;
            if (!InsertBack(deque, elem1))
            {
                cout << "Deque cheia!\n";
            }
            break;
        case 2:
            char elem2;
            cout << "\nDigite o caractere que deseja inserir no início da deque: \n";
            cin >> elem2;
            if (!InsertFront(deque, elem2))
            {
                cout << "Deque cheia!\n";
            }
            break;
        case 3:
            char removed1;
            cout << "\nRemovendo o último elemento da deque...\n";
            removed1 = RemoveBack(deque);
            cout << "Elemento removido: " << removed1 << "\n";
            break;
        case 4:
            char removed2;
            cout << "\nRemovendo o primeiro elemento da deque...\n";
            removed2 = RemoveFront(deque);
            cout << "Elemento removido: " << removed2 << "\n";
            break;
        case 5:
            PrintDeque(deque);
            break;
        case 6:
            cout << "\nPrimeiro elemento da deque: " << Front(deque) << "\n";
            break;
        case 7:
            cout << "\nÚltimo elemento da deque: " << Back(deque) << "\n";
            break;
        case 8:
            cout << "\nQuantidade de elementos da deque: " << Count(deque) << "\n";
            break;
        case 9:
            cout << "\nCapacidade de elementos da deque: " << Size(deque) << "\n";
            break;
        case 10:
            char empty;
            empty = IsEmpty(deque) ? 'S' : 'N';
            cout << "\nA deque está vazia? " << empty << "\n";
            cout << "\n";
            break;
        case 11:
            cout << "\nEsvaziando a deque...\n";
            Clear(deque);
            break;
        case 12:
            Test(deque);
            break;
        default:
            if (op != 0)
            {
                cout << "Operação inválida!\n";
            }
            break;
        }
} while (op != 0);
cout << "Encerrando o programa...";
}