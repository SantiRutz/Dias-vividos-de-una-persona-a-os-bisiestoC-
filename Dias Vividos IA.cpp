#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    // Pedimos la fecha de nacimiento del usuario
    int diaNac, mesNac, anioNac;
    cout << "Ingresa tu fecha de nacimiento (DD MM AAAA): ";
    cin >> diaNac >> mesNac >> anioNac;

    // Obtenemos la fecha actual
    time_t t = time(NULL);
    tm* tiempo = localtime(&t);
    int diaActual = tiempo->tm_mday;
    int mesActual = tiempo->tm_mon + 1;
    int anioActual = tiempo->tm_year + 1900;

    // Calculamos el número de días vividos, tomando en cuenta los años bisiestos
    int diasVividos = (anioActual - anioNac) * 365;
    for (int i = anioNac; i <= anioActual; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            diasVividos++;
        }
    }
    diasVividos += ((mesActual - mesNac) * 30) + (diaActual - diaNac);
    if (mesNac <= 2 && diaNac <= 29 && ((anioNac % 4 == 0 && anioNac % 100 != 0) || anioNac % 400 == 0)) {
        diasVividos--;
    }
    if (mesActual <= 2 && diaActual <= 29 && ((anioActual % 4 == 0 && anioActual % 100 != 0) || anioActual % 400 == 0)) {
        diasVividos++;
    }

    // Mostramos el resultado
    cout << "Has vivido " << diasVividos << " días." << endl;

    return 0;
}
