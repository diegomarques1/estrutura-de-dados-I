// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 2:
Altere o programa anterior para verificar se uma data informada pelo usuário
usando o formato DD/MM/YYYY é uma data palíndroma.
Por exemplo, 12/02/2021 foi uma data palíndroma, mas 02/02/2021 não.

*/

#include <iostream>
#include <string>
#include "stack2.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    cout << "Exercício 02 - Lista de exercícios 02\n";
    string date;
    cout << "Digite uma data no formato DD/MM/YYYY: \n";
    getline(cin, date);
    date.erase(remove(date.begin(), date.end(), '/'), date.end());
    int length = date.length();
    StaticStack stack = Create();
    for (int i = 0; i < (length / 2); ++i) // Preenchimento da pilha
    {
        Push(stack, date[i]);
        if (date[i] == date[length - 1 - i]) // Compara o 1º com o último elemento da string
        {
            Pop(stack);
        }
    }
    if (IsEmpty(stack))
    {
        cout << "A data digitada é um palíndromo.";
    }
    else
    {
        cout << "A data digitada não é um palíndromo.";
    }
    //cout << "\n" << "VERIFICAÇÃO: \n";
    //cout << "Pilha: " << stack.values << '\n';   
    //cout << "Está vazia? " << IsEmpty(stack);
}

/* Professor, como usei o erase para remover o '/', não sei se era o ideal para a proposta da atividade.
Mas só consegui fazer assim para implementar a pilha da maneira mais ideal que encontrei.
Mandei por e-mail pra você uma dúvida sobre, mas acho que não deu tempo de ver porque mandei quinta bem tarde. Desculpe :c
De qualquer modo, creio que a implementação mais ideal desse ex., usando pilha, consista em dar um push() para o primeiro índice e
dar pop() caso o elemento seja igual ao elemento no índice [tamanho - índice do atual] (vale para os 2 exercícios de palíndromo).
Antes de entender isso, eu tinha feito o ex. 01 e o ex. 02 de uma maneira mais "robusta", talvez? Eu tinha utilizado um for each
para preencher a pilha inteira com todos os elementos da data menos '/' (if char != '/'). Nisso, eu comparava, dentro da pilha,
o elemento do índice atual com o seu equivalente e removia o último com um pop() caso fossem iguais.
Sempre que o tamanho da pilha fosse reduzido à metade e o stack.current fosse igual a esse valor (metade do length inicial),
eu poderia saber que a data era um palíndromo. Só que essa implementação me pareceu meio esquisita, mesmo sem usar o str.erase
Então, refiz fazendo dessa forma acima.
Caso queira, posso mandar os outros arquivos para o senhor ver se seria correto ou não.
Desculpe o comentário longo aqui no código, e provavelmente vou entender assim que ver um exemplo de implementação. =D
*/
