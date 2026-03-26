#include <iostream>
#include <string>
using namespace std;
//use const para que etsos valores no cambien duarnte la ejecucion del codi
const int MAX_ESTUDIANTES = 50;
//lista con espacio para 50 
const int NUM_NOTAS = 3;
//lista para maximo de notas


// Clase Estudiante en private aplicando el encapsulamiento
class Estudiante {
private:
    int codigo;
    string nombre;
    int edad;

public:
    // Hice un constructor vacío para que se ejecute con lavores vacios 
    Estudiante() {

        codigo = 0;
        nombre = "";
        edad = 0;
    }

    // Constructor con parámetros con la sobrecarga del de arriba recibiendo los valores y asignandolos 
    Estudiante(int c, string n, int e) {
        codigo = c;
        nombre = n;
        edad = e;
    }
    
    //el setter pa modificar los atributos afuers de la clase
    void setDatos(int c, string n, int e) {
        codigo = c;
        nombre = n;
        edad = e;
    }
    
    //el getter los retorna afuera
    int getCodigo() {
        return codigo;
    }
    
    //la impreion en la consola
    void mostrar() {
        cout << "Ingresar Codigo: " << codigo << endl;
        cout << "Nombre del esytudiante: " << nombre << endl;
        cout << "Ingrese la Edad: " << edad << endl;
        cout << "------" << endl;
    }
};


//el main ya es el que ejecuta todo en el programa 
int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    //usando el construcor vacio  deja el espacio de (50) estduantes
    float notas[MAX_ESTUDIANTES][NUM_NOTAS] = {0};
    //i=estudiante:filas [50] , j=notas:columnas [3]
    int contador = 0;
    //lleva la cuenta de cuantos estudiantes van
    int opcion;
    //almacena la opcion elegida en el meu

    //el do pa que el menu se muestre hasta que se pida salir 
    do {
        cout << "\n MENU \n";
        cout << "1. Registro de estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Asignar notas\n";
        cout << "5. Mostrar promedio\n";
        cout << "6. Mostrar matriz de notas\n";
        cout << "7. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;
        

        //el switch ejecuta el valor asignado al bloque de codigo especifico
        switch(opcion) {

        case 1: {
            if (contador < MAX_ESTUDIANTES) {
                //sin superar el limite y genera el objeto estduante con los atibutos y lo guarda en el contaor
                int c, e;
                string n;
             5
                (cin.fail()) 
                { 
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "entrada invalida \n";
                    continue;
                }
                cout << "Codigo: ";
                cin >> c;
                cout << "Nombre: ";
                cin >> n;
                cout << "Edad: ";
                cin >> e;

                estudiantes[contador] = Estudiante(c, n, e);
                contador++;

                cout << "Estudiante registrado.\n";
            } else {
                cout << "Limite alcanzado.\n";
            }
            break;
        }

        case 2:
        //pasa por todos los obj estudiantes registrados ya y los muestra
            for (int i = 0; i < contador; i++) {
                estudiantes[i].mostrar();
            }
            break;

        case 3: {
             //recorre el arreglo comparando el codigo hasta encontrar el estudiante
            int codigoBuscado;
            bool encontrado = false;
            cout << "Ingrese codigo: ";
            cin >> codigoBuscado;
            //si lo encuentra lo muestra y sale del bucle con el break
            for (int i = 0; i < contador; i++) {
                if (estudiantes[i].getCodigo() == codigoBuscado) {
                    estudiantes[i].mostrar();
                    encontrado = true;
                    break;
                }
            }
            //pues si no lo ve imprime no encontrado 
            if (!encontrado) {
                cout << "No encontrado.\n";
            }
            break;
        }

        case 4: {
            int codigoBuscado;
            cout << "Codigo del estudiante: ";
            cin >> codigoBuscado;
           //usa un bucle para leer las 3 notas y guardarlas en la fila i
            for (int i = 0; i < contador; i++) {
                if (estudiantes[i].getCodigo() == codigoBuscado) {

                    for (int j = 0; j < NUM_NOTAS; j++) {
                        cout << "Nota " << j+1 << ": ";
                        cin >> notas[i][j];
                    }

                    cout << "Notas actualizadas.\n";
                }
            }
            break;
        }

        case 5: {
            int codigoBuscado;
            cout << "Codigo: ";
            cin >> codigoBuscado;
           //suma las 3 notas entre NUM_NOTAS y obtiene el promedio
            for (int i = 0; i < contador; i++) {
                if (estudiantes[i].getCodigo() == codigoBuscado) {

                    float suma = 0;
                    for (int j = 0; j < NUM_NOTAS; j++) {
                        suma += notas[i][j];
                    }

                    cout << "Promedio: " << suma / NUM_NOTAS << endl;
                }
            }
            break;
        }
        

        //imprime la matriz como i la fila de estduantes y j la colunma de notas
        case 6:
            for (int i = 0; i < contador; i++) {
                for (int j = 0; j < NUM_NOTAS; j++) {
                    cout << notas[i][j] << " ";
                }
                cout << endl;
            }
            break;
            

          //termina el bucle del while 
        case 7:
            cout << "Saliendo...\n";
            break;
            
        default:
            cout << "Opcion invalida.\n";
        }
        //se encarga de cualquier entrada no vista
    } while (opcion != 7);

    return 0;
}

