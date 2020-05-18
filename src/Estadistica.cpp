#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

#include "../include/DNI.hpp"
#include "../include/AVL.hpp"

int Estadistica()
{
  srand(time(NULL));
  std::cout << "|| ESTADÍSTICA ||" << '\n';
  DNI::MODO = false;

  std::cout << "Tamaño del árbol" << '\n';
  unsigned  N;
  std::cin >> N;

  std::cout << "Numero de pruebas: " << '\n';
  unsigned  nPrueba;
  std::cin >> nPrueba;

  // Banco_de_Pruebas de pruebas
  std::vector<DNI> Banco_de_Pruebas (2*N);

  ABB<DNI> Arbol;
  for (unsigned i = 0; i < N; i++)
  {
    Arbol.Insertar(Banco_de_Pruebas[i]);
  }
  std::cout << "Arbol generado" << '\n';
  Arbol.write(std::cout);

  unsigned long int B_maximo = 0, CONTADOR_B = 0, B_minimo = 9999999999;
  unsigned long int I_maximo = 0, CONTADOR_I = 0, I_minimo = 9999999999;

  for (unsigned i = 0; i < nPrueba; i++)
  {
    Arbol.Buscar(Banco_de_Pruebas[rand() % N]);
    if (DNI::CONTADOR > B_maximo) B_maximo = DNI::CONTADOR;
    if (DNI::CONTADOR < B_minimo) B_minimo = DNI::CONTADOR;
    CONTADOR_B += DNI::CONTADOR;
    DNI::CONTADOR = 0;
  }
  for (unsigned i = 0; i < nPrueba; i++)
  {
    Arbol.Insertar(Banco_de_Pruebas[N + (rand() % N)]);
    if (DNI::CONTADOR > I_maximo) I_maximo = DNI::CONTADOR;
    if (DNI::CONTADOR < I_minimo) I_minimo = DNI::CONTADOR;
    CONTADOR_I += DNI::CONTADOR;
    DNI::CONTADOR = 0;
  }

  std::cout << "Arbol despues de insertar" << '\n';
  Arbol.write(std::cout);

  std::cout << "Número de Comparaciones" << '\n';
  std::cout << "             N  Pruebas  Mínimo  Medio  Máximo" << std::endl;
  std::cout << std::left << std::setw(14) << "Búsqueda: ";
  std::cout << std::setw(3)  << N;
  std::cout << std::setw(9)  << nPrueba;
  std::cout << std::setw(8) << B_minimo;
  std::cout << std::setw(7) << (CONTADOR_B)/nPrueba;
  std::cout << B_maximo << std::endl;
  std::cout << std::left << std::setw(14) << "Inserción: ";
  std::cout << std::setw(3)  << N;
  std::cout << std::setw(9)  << nPrueba;
  std::cout << std::setw(8) << I_minimo;
  std::cout << std::setw(7) << (CONTADOR_I)/nPrueba;
  std::cout << I_maximo << std::endl;
  return 0;
}
