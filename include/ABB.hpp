#ifndef _ABB_
#define _ABB_


#include <iostream>
#include "nodoBB.hpp"

template<class Clave>
class ABB
{
  private:
    unsigned int nivel;
    nodoBB<Clave>* raiz;
  public:
    ABB()
    {
      nivel = 0;
      raiz = nullptr;
    }
    void Buscar (Clave X)
    {
      raiz->Buscar(X);
    }
    void Insertar (Clave X)
    {
      if (!raiz)
      {
        raiz = new nodoBB<Clave>;
      }
      else
      {
        raiz->Insertar(X);
      }
    }
    void Eliminar ()
    {

    }
    void Eliminar (Clave X);
};

#endif
