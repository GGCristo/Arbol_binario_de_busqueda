#include <iostream>
#include "../include/DNI.hpp"
#include  "../include/ABB.hpp"

int Demostracion()
{
  ABB<DNI> Arbol;
  short opcion;
  do
  {
    std::cout << "|| MODO DEMOSTRACION ||" << '\n';
    std::cout << "[0] Salir" << '\n';
    std::cout << "[1] Insertar Clave" << '\n';
    std::cout << "[2] Eliminar Clave" << '\n';
    std::cin >> opcion;
  } while (opcion != 0 && opcion != 1 && opcion != 2);

  Arbol.Insertar(DNI(8));
  Arbol.Insertar(DNI(3));
  Arbol.Insertar(DNI(10));
  Arbol.Insertar(DNI(1));
  Arbol.Insertar(DNI(6));
  Arbol.Insertar(DNI(14));
  Arbol.Insertar(DNI(4));
  Arbol.Insertar(DNI(7));
  Arbol.Insertar(DNI(13));
  Arbol.Eliminar(DNI(13));

  Arbol.Buscar(DNI(6));

  Arbol.write(std::cout);
  return 0;
}
