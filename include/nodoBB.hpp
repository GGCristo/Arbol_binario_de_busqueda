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
  // A donde apunta el padre cuando el hijo muere
  void apuntar_padre(nodoBB<Clave>*& padre, nodoBB<Clave>* destino, const Clave& X)
  {
    if (padre->hijo_r && padre->hijo_r->Valor_ == X) padre->hijo_r = destino;
    else                                             padre->hijo_l = destino;
  }

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

  void Eliminar(nodoBB<Clave>* padre,  const Clave& X)
  {
    if (Valor_ == X)
    {
      if (!hijo_l && !hijo_r) //nodo_hoja
      {
        apuntar_padre(padre, nullptr, X);
        delete this;
      }
      else if (hijo_r && !hijo_l) // Si solo tiene un hijo
      {
        apuntar_padre(padre, hijo_r, X);
        delete this;
      }
      else if (hijo_l && !hijo_r) // Si solo tiene un hijo
      {
        apuntar_padre(padre, hijo_l, X);
        delete this;
      }
      else // Si los dos estan vivos
      {
        // Busco el más a la derecha del subarbol izquierdo
        nodoBB<Clave>* maximo = hijo_l;
        Buscar_derecha(maximo);
        Valor_ = maximo->Valor_;
        hijo_l->Eliminar(this, Valor_);
      }
    }
    // Busqueda
    else if (hijo_l && X < Valor_)
      hijo_l->Eliminar(this, X);

    else if (hijo_r && X > Valor_)
      hijo_r->Eliminar(this, X);

    else
    {
      std::cout << "No se ha encontrado y por ende no se puede eliminar" << '\n';
    }
  }

  void Buscar_derecha (nodoBB<Clave>*& nodo)
  {
    while (nodo->hijo_r)
      nodo = nodo->hijo_r;

    if (nodo->hijo_l && nodo->hijo_l->hijo_r)
      Buscar_derecha(nodo->hijo_l->hijo_r);
  }
};

#endif
