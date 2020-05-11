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
      if (raiz->Buscar(X)) std::cout << "Encontrado" << '\n';
      else std::cout << "No se encontro" << '\n';
    }

    void Insertar (Clave X)
    {
      if (!raiz)
      {
        raiz = new nodoBB<Clave>(X);
        std::cout << "He insertado raiz " << raiz->Valor_ << '\n';
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
        for (int j = 0; j < vectores[i].size(); j++)
        {
          if (vectores[i][j]->hijo_l)
          {
            vector_l.push_back(vectores[i][j]->hijo_l);
            booleano = true;
          }
          if (vectores[i][j]->hijo_r)
          {
            vector_l.push_back(vectores[i][j]->hijo_r);
            booleano = true;
          }
        }
        vectores.push_back(vector_l);
      }

      for (int i = 0; i < vectores.size(); i++)
      {
        std::cout << "Nivel " << i << ": ";
        for (int j = 0; j < vectores[i].size(); j++)
        {
          if (vectores[i][j] == nullptr)
            std::cout << "." << '\n';
          else
            std::cout << vectores[i][j]->Valor_ << ' ';
        }
          std::cout << '\n';
      }
      return os;
    }
};

#endif
