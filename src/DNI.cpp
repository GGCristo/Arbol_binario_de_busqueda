#include "../include/DNI.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

DNI::DNI ()
{
  Valor_ = rand() % 100;
}

void DNI::operator = (const int& valor)
{
  Valor_ = valor;
}

bool DNI::operator < (const DNI& dni)
{
  if (DNI::MODO)
  {
    std::cin.get();
    if (DNI::MODO) std::cout << "Se compara el valor " << Valor_ << " con " << dni.Valor_ << '\n';
  }
  else
    CONTADOR++;
  return Valor_ < dni.Valor_;
}

bool DNI::operator <= (const DNI& dni)
{
  if (DNI::MODO)
  {
    std::cin.get();
    std::cout << "Se compara el valor " << Valor_ << " con " << dni.Valor_ << '\n';
  }
  else
    CONTADOR++;
  return Valor_ <= dni.Valor_;
}

bool DNI::operator > (const DNI& dni)
{
  if (DNI::MODO)
  {
    std::cin.get();
    std::cout << "Se compara el valor " << Valor_ << " con " << dni.Valor_ << '\n';
  }
  else
    CONTADOR++;
  return Valor_ > dni.Valor_;
}

bool DNI::operator >= (const DNI& dni)
{
  if (DNI::MODO)
  {
    std::cin.get();
    std::cout << "Se compara el valor " << Valor_ << " con " << dni.Valor_ << '\n';
  }
  else
    CONTADOR++;
  return Valor_ >= dni.Valor_;
}

bool DNI::operator == (const DNI& dni)
{
  if (DNI::MODO)
  {
    std::cin.get();
    std::cout << "Se compara el valor " << Valor_ << " con " << dni.Valor_ << '\n';
  }
  else
    CONTADOR++;
  return Valor_ == dni.Valor_;
}
