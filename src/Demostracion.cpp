#include <iostream>
#include "../include/DNI.hpp"
#include  "../include/AVL.hpp"

int Demostracion()
{
  AVL<DNI> Arbol;
  Arbol.Buscar(DNI(4));
  short opcion;
  Arbol.write(std::cout);
  do
  {
    std::cout << "|| MODO DEMOSTRACION ||" << '\n';
    std::cout << "[0] Salir" << '\n';
    std::cout << "[1] Insertar Clave" << '\n';
    std::cout << "[2] Eliminar Clave" << '\n';
    std::cin >> opcion;
    if (opcion == 1 || opcion == 2)
    {
      std::cout << "Escribe el valor" << '\n';
      unsigned long dato;
      std::cin >> dato;
      if (opcion == 1)
        Arbol.Insertar(DNI(dato));
      else if (opcion == 2)
        Arbol.eliminar(DNI(dato));
      Arbol.write(std::cout);
    }
    else if (opcion != 0)
      std::cout << "Esa no es una opción" << '\n';

  } while (opcion);

  return 0;
}
