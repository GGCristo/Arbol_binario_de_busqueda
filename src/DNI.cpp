#include "../include/DNI.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

DNI::DNI ()
{
  Valor_ = rand() % 100;
}

DNI::DNI(const unsigned long& Valor)
{
  Valor_ = Valor;
}

void DNI::operator = (const int& valor)
{
  Valor_ = valor;
}

bool DNI::operator < (const DNI& dni)
{
  operar_modo(dni);
  return Valor_ < dni.Valor_;
}

bool DNI::operator <= (const DNI& dni)
{
  operar_modo(dni);
  return Valor_ <= dni.Valor_;
}

bool DNI::operator > (const DNI& dni)
{
  operar_modo(dni);
  return Valor_ > dni.Valor_;
}

bool DNI::operator >= (const DNI& dni)
{
  operar_modo(dni);
  return Valor_ >= dni.Valor_;
}

bool DNI::operator == (const DNI& dni)
{
  operar_modo(dni);
  return Valor_ == dni.Valor_;
}

void DNI::operar_modo (const DNI& dni)
{
  if (DNI::MODO)
  {
    if (DNI::MODO) std::cout << "Se compara el valor " << Valor_ << " con " << dni.Valor_ << '\n';
  }
  else
    CONTADOR++;
}
