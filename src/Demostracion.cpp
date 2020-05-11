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

  Arbol.Insertar(DNI(5));
  Arbol.Insertar(DNI(0));
  Arbol.Insertar(DNI(22));
  Arbol.Insertar(DNI(4));
  Arbol.Insertar(DNI(88));

  Arbol.Buscar(DNI(88));

  Arbol.write(std::cout);
  return 0;
}
