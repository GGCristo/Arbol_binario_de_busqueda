#include <iostream>
#include "../include/DNI.hpp"

int Demostracion();
int Estadistica();

bool::DNI::MODO = true;
unsigned DNI::CONTADOR = 0;

int main()
{
  bool modo;
  do
  {
    std::cout << "Elija el modo" << std::endl;
    std::cout << "[0] Demostracion" << '\n';
    std::cout << "[1] Estadística" << '\n';
    std::cin >> modo;
  } while (modo != 0 && modo != 1);

  if (modo == 0) Demostracion();
  else Estadistica();

  return 0;
}
