#include <iostream>

int Demostracion()
{
  short opcion;
  do
  {
    std::cout << "|| MODO DEMOSTRACION ||" << '\n';
    std::cout << "[0] Salir" << '\n';
    std::cout << "[1] Insetar Clave" << '\n';
    std::cout << "[2] Eliminar Clave" << '\n';
    std::cin >> opcion;
  } while (opcion != 0 || opcion != 1 || opcion != 2);
  return 0;
}
