#ifndef _nodoAVL_
#define _nodoAVL_
#include "nodoBB.hpp"

template <class Clave>
class AVL;

template <class Clave>
class nodoAVL
{
  friend class AVL<Clave>;
  private:
    Clave Valor_;
    int bal;
    nodoAVL<Clave>* left;
    nodoAVL<Clave>* right;
  public:
    nodoAVL(const Clave& Valor = 0, const int& bal_ = 0) : Valor_(Valor)
    {
      bal = bal_;
      left = nullptr;
      right = nullptr;
    }
    void Eliminar()
    {
      if (left) left->Eliminar();
      if (right) right->Eliminar();
      delete this;
    }
};
#endif // _nodoAVL_
