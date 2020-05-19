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
  protected:
    nodoBB<Clave>* raiz;
  public:
    ABB()
    {
      raiz = nullptr;
    }

    ~ABB()
    {
      Eliminar();
    }

    nodoBB<Clave>* get_raiz(){return raiz;}

    nodoBB<Clave>* Buscar (Clave X, nodoBB<Clave>* nodo = nullptr)
    {
      assert (raiz);
      if (!nodo) nodo = raiz;

      if (X == nodo->Valor_) return nodo;
      else if (nodo->hijo_l && X < nodo->Valor_) return Buscar(X, nodo->hijo_l);
      else if (nodo->hijo_r && X > nodo->Valor_) return Buscar(X, nodo->hijo_r);
      return nullptr;
    }

    virtual void Insertar (Clave X)
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
    // const bool Equilibrado() {
    //   return EquilibrioRama(raiz); }

    // const bool EquilibrioRama(nodoBB<Clave>* nodo) {
    //   if (nodo == NULL) return true ;
    //   int eq = TamRama(nodo->hijo_l) - TamRama(nodo->hijo_r);
    //   switch (eq) {
    //     case -1:
    //     case 0:
    //     case 1:
    //       return EquilibrioRama(nodo->hijo_l) &&
    //         EquilibrioRama(nodo->hijo_r);
    //     default: return false;
    //   }
    // }
    // const int Tam() { return TamRama(raiz); }
    // const int TamRama(nodoBB<Clave>* nodo) {
    //   if (nodo == NULL) return 0 ;
    //   return (1 + TamRama(nodo->hijo_l) + TamRama(nodo->hijo_r) );
    // }
};

#endif
