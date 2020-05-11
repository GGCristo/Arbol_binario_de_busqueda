#ifndef _ABB_
#define _ABB_

#include <iostream>
#include <vector>
#include <queue>
#include "nodoBB.hpp"

template<typename Clave>
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

    ~ABB()
    {
      Eliminar();
    }

    void Buscar (Clave X)
    {
      if (raiz->Buscar(X)) std::cout << "Encontrado: " << X << '\n';
      else std::cout << "No se encontro: " << X << '\n';
    }

    void Insertar (Clave X)
    {
      if (!raiz)
      {
        raiz = new nodoBB<Clave>(X);
      }
      else
      {
        raiz->Insertar(X);
      }
    }

    void Eliminar ()
    {
      raiz->Eliminar();
    }

    void Eliminar (Clave X)
    {
      nodoBB<Clave>* nodo = raiz->Buscar(X);
      if (nodo == nullptr) std::cout << "No se pudo encontrar y por ende eliminar: " << X << '\n';
      else nodo->Eliminar(X);
    }

    std::ostream& write(std::ostream& os)
    {
      std::vector<std::vector<nodoBB<Clave>*>> vectores;
      std::vector<nodoBB<Clave>*> vector_l;
      vector_l.push_back(raiz);
      vectores.push_back(vector_l);
      bool booleano = true;
      for (int i = 0; booleano ; i++)
      {
        booleano = false;
        vector_l.clear();
        for (unsigned j = 0; j < vectores[i].size(); j++)
        {
          if (!vectores[i][j])
          {
            vector_l.push_back(vectores[i][j]);
            vector_l.push_back(vectores[i][j]);
          }
          else
          {
            if (vectores[i][j]->hijo_l || vectores[i][j]->hijo_r)
            {
              booleano = true;
            }
            vector_l.push_back(vectores[i][j]->hijo_l);
            vector_l.push_back(vectores[i][j]->hijo_r);
          }
        }
        vectores.push_back(vector_l);
      }
      vectores.pop_back();
      for (unsigned i = 0; i < vectores.size(); i++)
      {
        std::cout << "Nivel " << i << ": ";
        for (unsigned j = 0; j < vectores[i].size(); j++)
        {
          if (vectores[i][j] == nullptr)
            std::cout << "." << ' ';
          else
            std::cout << vectores[i][j]->Valor_ << ' ';
        }
          std::cout << '\n';
      }
      return os;
    }
};

#endif
