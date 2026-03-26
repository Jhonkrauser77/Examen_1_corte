MAX_ESTUDIANTES = 5
NUM_NOTAS = 3


class Estudiante:
    def __init__(self, codigo=0, nombre="", edad=0):
        self.__codigo = codigo
        self.__nombre = nombre
        self.__edad = edad

    def set_datos(self, codigo, nombre, edad):
        self.__codigo = codigo
        self.__nombre = nombre
        self.__edad = edad

    def get_codigo(self):
        return self.__codigo

    def mostrar(self):
        print(f"Código: {self.__codigo}")
        print(f"Nombre: {self.__nombre}")
        print(f"Edad: {self.__edad}")
        print("------")


def main():
    estudiantes = []
    notas = []
    opcion = 0

    while opcion != 7:
        print("\n MENÚ")
        print("1. Registro de estudiante")
        print("2. Mostrar estudiantes")
        print("3. Buscar estudiante")
        print("4. Asignar notas")
        print("5. Mostrar promedio")
        print("6. Mostrar matriz de notas")
        print("7. Salir")

        try:
            opcion = int(input("Seleccione: "))
        except ValueError:
            print("Entrada inválida.")
            continue

        if opcion == 1:
            if len(estudiantes) < MAX_ESTUDIANTES:
                try:
                    c = int(input("Código: "))
                    n = input("Nombre: ")
                    e = int(input("Edad: "))
                    estudiantes.append(Estudiante(c, n, e))
                    notas.append([0.0] * NUM_NOTAS)
                    print("Estudiante registrado.")
                except ValueError:
                    print("Entrada inválida.")
            else:
                print("Límite alcanzado.")

        elif opcion == 2:
            for est in estudiantes:
                est.mostrar()

        elif opcion == 3:
            try:
                codigo_buscado = int(input("Ingrese código: "))
                encontrado = False
                for est in estudiantes:
                    if est.get_codigo() == codigo_buscado:
                        est.mostrar()
                        encontrado = True
                        break
                if not encontrado:
                    print("No encontrado.")
            except ValueError:
                print("Entrada inválida.")

        elif opcion == 4:
            try:
                codigo_buscado = int(input("Código del estudiante: "))
                for i, est in enumerate(estudiantes):
                    if est.get_codigo() == codigo_buscado:
                        for j in range(NUM_NOTAS):
                            notas[i][j] = float(input(f"Nota {j+1}: "))
                        print("Notas actualizadas.")
            except ValueError:
                print("Entrada inválida.")

        elif opcion == 5:
            try:
                codigo_buscado = int(input("Código: "))
                for i, est in enumerate(estudiantes):
                    if est.get_codigo() == codigo_buscado:
                        promedio = sum(notas[i]) / NUM_NOTAS
                        print(f"Promedio: {promedio:.2f}")
            except ValueError:
                print("Entrada inválida.")

        elif opcion == 6:
            for fila in notas:
                print(" ".join(str(n) for n in fila))

        elif opcion == 7:
            print("Saliendo...")

        else:
            print("Opción inválida.")


if __name__ == "__main__":
    main()