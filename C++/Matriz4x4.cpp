#include <iostream>
#include <iomanip> //para alinear mejor los datos ;) (setw)
#include <cmath> //biblioteca para las op mate
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001); // es para que me acepte tildes y esas cosas
    SetConsoleCP(65001);

    double m4[4][4];
    double determinante[4];
    double A[4][5]; // Matriz aumentada

    cout << "_______ GAUSS JORDAN (4x4) _______\n";
    cout << "Ingrese los coeficientes de la matriz A y los determinantes\n";

    // Ingreso de datos
    for (int i = 0; i < 4; i++) {
        cout << "\n--- Fila " << i + 1 << " ---\n";
        for (int j = 0; j < 4; j++) {
            cout << "Digite un número (" << i << "," << j << "): ";
            cin >> m4[i][j];
        }
        cout << "Digite el determinante (Det " << i + 1 << "): ";
        cin >> determinante[i];
    }

    cout << "\nMatriz ingresada (A):\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << setw(8) << fixed << setprecision(2) << m4[i][j];
        cout << endl;
    }

    cout << "\nDeterminantes:\n";
    for (int i = 0; i < 4; i++)
        cout << setw(8) << determinante[i]<<endl;
    cout << endl;

    // Crear matriz aumentada
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            A[i][j] = m4[i][j];
        A[i][4] = determinante[i];
    }

    cout << "_MATRIZ AUMENTADA_\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            double val = A[i][j];
            if (fabs(val) < 1e-9) val = 0; // evita -0 funciona con números decimales (fabs)
            cout << setw(8) << fixed << setprecision(2) << val;
        }
        cout << endl;
    }

    cout << "-------------------------------------------------------------\n";

    // Procedimiento
    for (int i = 0; i < 4; i++) {
        if (fabs(A[i][i]) < 1e-9) { //uno por diez elevado a la novena potencia (1e-9)
            bool cambio = false;
            for (int k = i + 1; k < 4; k++) {
                if (fabs(A[k][i]) > 1e-9) {
                    for (int j = 0; j < 5; j++)
                        swap(A[i][j], A[k][j]); //Intercambia el contenido de dos variables (swap)
                    cambio = true;
                    cout << "\n<-- Intercambio de F" << i+1 << " con F" << k+1 << " -->\n";
                    for (int x = 0; x < 4; x++) {
                        for (int y = 0; y < 5; y++) {
                            double val = A[x][y];
                            if (fabs(val) < 1e-9) val = 0;
                            cout << setw(8) << val;
                        }
                        cout << endl;
                    }
                    break;
                }
            }
            if (!cambio) {
                cout << "_NO HAY SOLUCIÓN_";
                return 0;
            }
        }

        double pivote = A[i][i];
        if (fabs(pivote - 1.0) > 1e-9) {
            cout << "\n(1/" << pivote << ") * F" << i+1 << " --> F" << i+1 << "\n";
            for (int j = 0; j < 5; j++)
                A[i][j] /= pivote;
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 5; y++) {
                    double val = A[x][y];
                    if (fabs(val) < 1e-9) val = 0;
                    cout << setw(8) << val;
                }
                cout << endl;
            }
        }

        for (int k = 0; k < 4; k++) {
            if (k != i) {
                double factor = A[k][i];
                if (fabs(factor) > 1e-9) {
                    cout << "\n" << factor << " F" << i+1 << " + F" << k+1 << " --> F" << k+1 << "\n";
                    for (int j = 0; j < 5; j++)
                        A[k][j] -= factor * A[i][j];
                    for (int x = 0; x < 4; x++) {
                        for (int y = 0; y < 5; y++) {
                            double val = A[x][y];
                            if (fabs(val) < 1e-9) val = 0;
                            cout << setw(8) << val;
                        }
                        cout << endl;
                    }
                }
            }
        }
    }

    cout << "Los resultados son: \n";
    cout<< "W= " << A[0][4]<<endl;
    cout<< "X= " << A[1][4]<<endl;
    cout<< "Y= " << A[2][4]<<endl;
    cout<< "Z= " << A[3][4]<<endl;

    cout << ":) EL PROCESO SE HA COMPLETADO\n";

    return 0;
}