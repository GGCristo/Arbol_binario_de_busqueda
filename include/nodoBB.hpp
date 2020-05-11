#ifndef _nodoBB_
#define _nodoBB_

#include <iostream>

template<class Clave>
class ABB;

template<class Clave>
class nodoBB
{
  friend class ABB<Clave>;
  private:
    Clave Valor_;
    nodoBB<Clave>* hijo_l;
    nodoBB<Clave>* hijo_r;
  public:
    nodoBB()
    {
      hijo_l = nullptr;
      hijo_r = nullptr;
    }

    ~nodoBB()
    {
      Valor_ = 0;
      hijo_l = nullptr;
      hijo_r = nullptr;
    }

    explicit nodoBB(const Clave& Valor) : Valor_(Valor)
    {
      hijo_l = nullptr;
      hijo_r = nullptr;
    }

    nodoBB<Clave>* Buscar(Clave X)
    {
      if (Valor_ == X) return this;
      if (hijo_l && X < Valor_) return hijo_l->Buscar(X);
      if (hijo_r && X > Valor_) return hijo_r->Buscar(X);
      return nullptr;
    }

    void Insertar(Clave X)
    {
      if (X < Valor_)
      {
        if (hijo_l) hijo_l->Insertar(X);
        else
        {
          hijo_l = new nodoBB<Clave>(X);
        }
      }
      else if (X > Valor_)
      {
        if (hijo_r) hijo_r->Insertar(X);
        else
        {
          hijo_r = new nodoBB<Clave>(X);
        }
      }
      else
        std::cout << "Se ha intentado meter el elemento " << X << " pero ya estaba en el árbol" << '\n';
    }

    void Eliminar()
    {
      if (hijo_l) hijo_l->Eliminar();
      if (hijo_r) hijo_r->Eliminar();
      delete this;
    }

    void Eliminar(const Clave& X)
    {
      if (!hijo_l && !hijo_r) delete this;
      else std::cout << "No se ha podido eliminar" << '\n';
    }
};

#endif
