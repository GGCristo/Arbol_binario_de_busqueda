#include <iostream>
int Demostracion();

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
  Demostracion();
  return 0;
}
