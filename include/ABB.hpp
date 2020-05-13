#ifndef _ABB_
#define _ABB_

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include "nodoBB.hpp"

template <typename Clave>
using Matrix_de_Niveles = std::vector<std::vector<nodoBB<Clave>*>>;

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
      assert (raiz);
      raiz->Buscar(X);
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
      assert (raiz);
      raiz->Eliminar();
    }

    void Eliminar (const Clave& X)
    {
      assert (raiz);
      nodoBB<Clave>* padre = raiz;
      raiz->Eliminar(padre, X);
    }

    Matrix_de_Niveles<Clave> Recorrido_nivel()
    {
      Matrix_de_Niveles<Clave> vectores; // Matrix_de_Niveles = std::vector<std::vector<nodoBB<Clave>*>>
      std::vector<nodoBB<Clave>*> vector_l;

      vector_l.push_back(raiz);
      vectores.push_back(vector_l);
      bool booleano = true;
      for (int i = 0; booleano; i++)
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
      vectores.pop_back(); // Elimino porque me queda un nivel completo apuntando
      return vectores;     // a NULL, que no aporta nada.
    }

    std::ostream& write(std::ostream& os)
    {
      if (!raiz)
      {
        std::cout << "Árbol vacío" << '\n';
      }
      Matrix_de_Niveles<Clave> vectores = Recorrido_nivel();
      for (unsigned i = 0; i < vectores.size(); i++)
      {
        std::cout << "Nivel " << i << ": ";
        for (unsigned j = 0; j < vectores[i].size(); j++)
        {
          if (vectores[i][j] == nullptr)
            std::cout << "[.]" << ' ';
          else
            std::cout << vectores[i][j]->Valor_ << ' ';
        }
          std::cout << '\n';
      }
      return os;
    }
};

#endif
