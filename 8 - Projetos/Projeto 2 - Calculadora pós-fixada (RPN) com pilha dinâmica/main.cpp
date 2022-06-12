// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gon�alves - TIA: 32074964

#include <iostream>
#include <sstream>
#include <clocale>
#include "Stack.h"

int main()
{
	setlocale(LC_CTYPE, "pt_BR");
	Stack stack;
	int loop = 0;
	do
	{
		std::string input;
		std::getline(std::cin, input); // L� uma string inserida pelo usu�rio.

		if (input == "0")
		{
			loop = 1;
			break;
		}

		std::istringstream iss(input); // Passa o input para um istringstream.
		std::string str;

		// Cada string separada por um espa�o em branco � copiada na string str.
		while (iss >> str)
		{
			
			// Tenta converter uma string para um float com std::stof().
			// Caso n�o seja poss�vel realizar a convers�o, o c�digo dentro de catch � executado.
			try
			{
				float value = std::stof(str);
				stack.Push(value);
			}
			catch (std::invalid_argument e)
			{
				if (str != "+" && str != "-" && str != "*" && str != "/")
				{
					stack.Clear();
					break;
				}
				else
				{
					if (!stack.IsEmpty())
					{
						float temp1 = stack.Pop();
						if (!stack.IsEmpty())
						{
							float temp2 = stack.Pop();
							if (str == "+") stack.Push(temp2 + temp1);
							if (str == "-") stack.Push(temp2 - temp1);
							if (str == "*") stack.Push(temp2 * temp1);
							if (str == "/") stack.Push(temp2 / temp1);
						}
						else
						{
							stack.Clear();
							break;
						}

					}	
				}
			}
		}
		if (stack.IsEmpty())
		{
			std::cout << "Erro na express�o.\n";
		}
		else if (stack.Count() > 1)
		{
			std::cout << "Erro na express�o.\n";
		}
		else
		{
			std::cout << stack.ToString() << "\n";
		}
		stack.Clear();
		std::cout << "\n";
	} while (loop != 1);
	std::cout << "Fim.";
}