#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUMERO_EQUIPOS = 5;
const int NUMERO_ANOS = 4;
const int MAXIMA_LONGITUD_CADENA = 100;

int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_ANOS + 1]);
void imprimirMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_ANOS + 1], char equipos[NUMERO_EQUIPOS][MAXIMA_LONGITUD_CADENA]);

int main() {
    srand(time(0));

    char inicio;
    do {
        cout << "\n\t**Bienvenidos al programa de gestión de partidos jugados**\n\n";
        cout << "¿Qué partido desea calcular?\n";
        cout << "\t1. Liga Nacional\n";
        cout << "\t2. Liga de Ascenso\n";
        cout << "\t3. Liga Segunda División\n";
        cout << "\t4. Liga Metropolitana\n";
        cout << "\t5. Liga Inter\n";
        cout << "Ingrese la opción: ";

        int opc;
        cin >> opc;

        if (opc >= 1 && opc <= 5) {
            float matriz[NUMERO_EQUIPOS][NUMERO_ANOS + 1];
            char equipos[NUMERO_EQUIPOS][MAXIMA_LONGITUD_CADENA];

            switch(opc) {
                case 1:
                    strncpy(equipos[0], "Equipo Barsa", MAXIMA_LONGITUD_CADENA);
                    strncpy(equipos[1], "Equipo Real", MAXIMA_LONGITUD_CADENA);
                    strncpy(equipos[2], "Equipo Paris", MAXIMA_LONGITUD_CADENA);
                    strncpy(equipos[3], "Equipo Municipal", MAXIMA_LONGITUD_CADENA);
                    strncpy(equipos[4], "Equipo Bayer", MAXIMA_LONGITUD_CADENA);
                    break;
                case 2:
                     strncpy(equipos[0], "Equipo Barsa", MAXIMA_LONGITUD_CADENA);
                    strncpy(equipos[1], "Equipo Real", MAXIMA_LONGITUD_CADENA);
                    strncpy(equipos[2], "Equipo Paris", MAXIMA_LONGITUD_CADENA);
                    strncpy(equipos[3], "Equipo Municipal", MAXIMA_LONGITUD_CADENA);
                    strncpy(equipos[4], "Equipo Bayer", MAXIMA_LONGITUD_CADENA);
                    break;
                // Puedes completar los casos restantes
            }

            llenarMatriz(matriz);
            imprimirMatriz(matriz, equipos);
        } else {
            cout << "Opción no válida. Intente de nuevo.\n";
        }

        cout << "\n¿Desea continuar (S/N)? ";
        cin >> inicio;
    } while (inicio == 'S' || inicio == 's');

    cout << "\n\t¡QUE TENGA UN EXCELENTE DÍA!\n";
    return 0;
}

int busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_ANOS + 1]) {
    for (int y = 0; y < NUMERO_EQUIPOS; y++) {
        float suma = 0;
        for (int x = 0; x < NUMERO_ANOS; x++) {
            int calificacion = busquedaAleatorios(0, 100);
            suma += calificacion;
            matriz[y][x] = calificacion;
        }
        matriz[y][NUMERO_ANOS] = suma / NUMERO_ANOS; // Calculando el promedio
    }
}

void imprimirMatriz(float matriz[NUMERO_EQUIPOS][NUMERO_ANOS + 1], char equipos[NUMERO_EQUIPOS][MAXIMA_LONGITUD_CADENA]) {
    cout << "\nTabla de Resultados:\n";
    cout << setw(20) << "Equipo";
    for (int i = 0; i < NUMERO_ANOS; i++) {
        cout << setw(10) << "Año " << i + 2010;
    }
    cout << setw(10) << "Promedio\n";

    for (int y = 0; y < NUMERO_EQUIPOS; y++) {
        cout << setw(20) << equipos[y];
        for (int x = 0; x < NUMERO_ANOS; x++) {
            cout << setw(10) << fixed << setprecision(2) << matriz[y][x];
        }
        cout << setw(10) << fixed << setprecision(2) << matriz[y][NUMERO_ANOS] << endl;
    }
}
