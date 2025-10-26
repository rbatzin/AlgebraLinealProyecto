//matriz 3x3 

#include <iostream>
using namespace std;

int main() {
    const int n = 3; 
    float matriz[n][n + 1]; 

    cout << " METODO DE GAUSS-JORDAN " << endl;
    cout << "Ingrese los coeficientes de las variables y los resultados:" << endl;

    
    for (int i = 0; i < n; i++) {
        cout << "\nEcuacion " << i + 1 << endl;
        for (int j = 0; j < n; j++) {
            cout << "Coeficiente a" << i + 1 << j + 1 << ": ";
            cin >> matriz[i][j];
        }
        cout << "Resultado b" << i + 1 << ": ";
        cin >> matriz[i][n]; 
    }

    
    cout << "\nMatriz aumentada inicial:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    

    for (int i = 0; i < n; i++) {
        float pivote = matriz[i][i];

        for (int j = 0; j < n + 1; j++) {
            matriz[i][j] = matriz[i][j] / pivote;
        }

        
        for (int k = 0; k < n; k++) {
            if (k != i) { 
                float factor = matriz[k][i];
                for (int j = 0; j < n + 1; j++) {
                    matriz[k][j] = matriz[k][j] - factor * matriz[i][j];
                }
            }
        }
    }

    cout << "\nMatriz reducida (identidad):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    cout << " SOLUCION FINAL " << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << matriz[i][n] << endl;
    }

    return 0;
}