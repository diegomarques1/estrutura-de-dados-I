// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 2:
Escreva um algoritmo que leia a distância (em Km) e o tempo (em horas) que um veículo percorreu entre um ponto A e um ponto B. 
Em seguida, indique a velocidade média do veículo durante o trecho percorrido e se a velocidade média ficou acima do limite de 90 Km/h.
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	float distance, duration;
	cout << "Digite a distância percorrida (quilômetros): \n";
	cin >> distance;
	cout << "Digite a duração do percurso (horas): \n";
	cin >> duration;
	float averageSpeed;
	averageSpeed = distance / duration; // fórmula da velocidade média
	cout << "Velocidade média: " << averageSpeed << "Km/h\n";
	if (averageSpeed > 90) // condição para verificar o limite de 90km/h
	{
		cout << "A velocidade média ficou acima do limite permitido. \n";
	}
	else 
	{
		cout << "A velocidade média ficou dentro do permitido. \n";
	}
	
}

