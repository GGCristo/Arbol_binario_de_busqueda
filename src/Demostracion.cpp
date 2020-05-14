#include <iostream>
#include "../include/DNI.hpp"
#include  "../include/ABB.hpp"

  int Demostracion()
  {
    ABB<DNI> Arbol;
    short opcion;
    Arbol.write(std::cout);
    do
    {
      std::cout << "|| MODO DEMOSTRACION ||" << '\n';
      std::cout << "[0] Salir" << '\n';
      std::cout << "[1] Insertar Clave" << '\n';
      std::cout << "[2] Eliminar Clave" << '\n';
      std::cout << "[3] Balanceado?" << '\n';
      std::cin >> opcion;
      if (opcion == 1 || opcion == 2)
      {
        std::cout << "Escribe el valor" << '\n';
        unsigned long dato;
        std::cin >> dato;
        if (opcion == 1)
          Arbol.Insertar(DNI(dato));
        else if (opcion == 2)
          Arbol.Eliminar(DNI(dato));
        Arbol.write(std::cout);
      }
      else if (opcion == 3)
      {
        if (Arbol.Equilibrado())
          std::cout << "Esta equilibrada" << '\n';
        else
          std::cout << "No esta equilibrada" << '\n';
        Arbol.write(std::cout);
      }
      else if (opcion != 0)
        std::cout << "Esa no es una opción" << '\n';

    } while (opcion);

  return 0;
}
