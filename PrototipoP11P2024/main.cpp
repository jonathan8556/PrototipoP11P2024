//Jonathan Samuel Gonz�lez Ixpat�
//9959-23-3184
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;

#define NUM_EMPRESAS 5
#define NUM_ANIOS 4
#define MAX_VENTA 1000

void llenarMatrices(int matrizVentas[][NUM_ANIOS], string nombresIndustrias[]);
void imprimirDetalleIndustria(int ventas[], string nombreIndustria);
void imprimirMatriz(int matrizVentas[][NUM_ANIOS], string nombresIndustrias[]);
void calcularEstadisticas(int matrizVentas[][NUM_ANIOS], string nombresIndustrias[]);

int main() {
    srand(time(nullptr));

    int matrizVentas[NUM_EMPRESAS][NUM_ANIOS];
    string nombresIndustrias[NUM_EMPRESAS] = {"C�mara de Industria", "C�mara de la Construcci�n", "C�mara de Transporte"};

    char opcion;
    bool repetir = true;

    do {
        llenarMatrices(matrizVentas, nombresIndustrias);
        imprimirMatriz(matrizVentas, nombresIndustrias);
        calcularEstadisticas(matrizVentas, nombresIndustrias);

        cout << "�Desea realizar otro c�lculo? (s/n): ";
        cin >> opcion;

        if (opcion != 's' && opcion != 'S') {
            repetir = false;
        }
    } while (repetir);

    return 0;
}

void llenarMatrices(int matrizVentas[][NUM_ANIOS], string nombresIndustrias[]) {
    for (int i = 0; i < NUM_EMPRESAS; ++i) {
        for (int j = 0; j < NUM_ANIOS; ++j) {
            matrizVentas[i][j] = rand() % (MAX_VENTA + 1);
        }
    }
}

void imprimirDetalleIndustria(int ventas[], string nombreIndustria) {
    cout << "Industria: " << nombreIndustria << endl;
    cout << "Ventas por a�o:" << endl;
    for (int i = 0; i < NUM_ANIOS; ++i) {
        cout << "A�o " << i + 2015 << ": Q" << ventas[i] << endl;
    }
}

void imprimirMatriz(int matrizVentas[][NUM_ANIOS], string nombresIndustrias[]) {
    for (int i = 0; i < NUM_EMPRESAS; ++i) {
        imprimirDetalleIndustria(matrizVentas[i], nombresIndustrias[i]);
        cout << endl;
    }

void calcularEstadisticas(int matrizVentas[][NUM_ANIOS], string nombresIndustrias[]) {
    int mejorIndustria = 0;
    float promedioMejorIndustria = 0;
    float promedioTotalMejorIndustria = 0;
    float mejorPromedio = 0;

    for (int i = 0; i < NUM_EMPRESAS; ++i) {
        float sumaVentas = 0;
        float promedioIndustria = 0;
        int ventaMasAlta = matrizVentas[i][0];
        int ventaMasBaja = matrizVentas[i][0];

        for (int j = 0; j < NUM_ANIOS; ++j) {
            sumaVentas += matrizVentas[i][j];
            if (matrizVentas[i][j] > ventaMasAlta) {
                ventaMasAlta = matrizVentas[i][j];
            }
            if (matrizVentas[i][j] < ventaMasBaja) {
                ventaMasBaja = matrizVentas[i][j];
            }
        }

        promedioIndustria = sumaVentas / NUM_ANIOS;
        promedioTotalMejorIndustria += promedioIndustria;

        cout << "Promedio de ventas para " << nombresIndustrias[i] << ": Q" << fixed << setprecision(2) << promedioIndustria << endl;
        cout << "Venta m�s alta para " << nombresIndustrias[i] << ": Q" << ventaMasAlta << endl;
        cout << "Venta m�s baja para " << nombresIndustrias[i] << ": Q" << ventaMasBaja << endl;

        if (promedioIndustria > mejorPromedio) {
            mejorPromedio = promedioIndustria;
            mejorIndustria = i;
            promedioMejorIndustria = promedioIndustria;
        }
    }

    cout << "La mejor industria es " << nombresIndustrias[mejorIndustria] << " con un promedio de ventas de: Q" << fixed << setprecision(2) << promedioMejorIndustria << endl;
    cout << "Promedio total de la mejor industria: Q" << fixed << setprecision(2) << promedioTotalMejorIndustria / NUM_EMPRESAS << endl;
}
