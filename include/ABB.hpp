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
    void Buscar (Clave X);
    void Insertar (Clave X)
    {
      if (nivel == 0)
      {
        raiz = new nodoBB<Clave>;
      }
    }
    void Eliminar (Clave X);
};

#endif
