// Diego Souza Lima Marques
// TIA: 32039921

/* Ex. 15:
Dois círculos se sobrepõem (colidem) se a soma dos seus raios é maior que ou igual a distância entre seus centros. 
A distância entre dois pontos pode ser calculada usando o teorema de Pitágoras (c = √𝑎2 + 𝑏2). 
Escreva uma função AreCirclesColliding() que recebe seis parâmetros:
a posição p1(x,y) e o raio r1 do primeiro círculo e a posição p2(x,y) e o raio r2 do segundo círculo.
Com os parâmetros informados, a função deve retornar true caso os círculos estejam sobrepostos ou false caso contrário.
*/

// Referência para a biblioteca math.h: http://linguagemc.com.br/a-biblioteca-math-h/

#include <iostream>
#include <math.h>

using namespace std;

bool AreCirclesColliding(float x1, float y1, float r1, float x2, float y2, float r2)
{
    float addRadius = r1 + r2;
    float distancex = fabs(x1 - x2); // módulo
    float distancey = fabs(y1 - y2); // módulo
    double distance = sqrt(pow(distancex, 2) + pow(distancey, 2)); // fórmula de pitágoras. Coloquei double porque, com sqrt, talvez o valor tenha bastante casa decimal.
    if (addRadius >= distance)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    float x1, y1, radius1, x2, y2, radius2;
    cout << "P1 - Digite o valor para x: \n";
    cin >> x1;
    cout << "P1 - Digite o valor para y: \n";
    cin >> y1;
    cout << "P1 = (" << x1 << ", " << y1 << ")\n";
    cout << "P1 - Digite o valor para o raio: \n";
    cin >> radius1;
    cout << "P2 - Digite o valor para x: \n";
    cin >> x2;
    cout << "P2 - Digite o valor para y: \n";
    cin >> y2;
    cout << "P2 = (" << x2 << ", " << y2 << ")\n";
    cout << "P2 - Digite o valor para o raio: \n";
    cin >> radius2;
    bool collision = AreCirclesColliding(x1, y1, radius1, x2, y2, radius2);
    if (collision == true)
    {
        cout << "Os círculos colidem.";
    }
    else
    {
        cout << "Os círculos não colidem.";
    }
}


