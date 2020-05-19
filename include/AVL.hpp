#ifndef _AVL_
#define _AVL_

#include <vector>
#include <cassert>

#include "nodoAVL.hpp"

template <class Clave>
using Matrix_de_Niveles = std::vector<std::vector<nodoAVL<Clave>*>>;

template <class Clave>
class AVL
{
  private:
    nodoAVL<Clave>* root;
  public:
    AVL()
    {
      root = nullptr;
    }

    ~AVL()
    {
      root->Eliminar();
    }

    nodoAVL<Clave>* Buscar (Clave X, nodoAVL<Clave>* nodo = nullptr)
    {
      assert (root);
      if (!nodo) nodo = root;

      if (X == nodo->Valor_) return nodo;
      else if (nodo->left && X < nodo->Valor_) return Buscar(X, nodo->left);
      else if (nodo->right && X > nodo->Valor_) return Buscar(X, nodo->right);
      return nullptr;
    }

    void rotacion_II (nodoAVL<Clave>*& nodo)
    {
      nodoAVL<Clave>* nodo1 = nodo->left;
      nodo->left = nodo1->right;
      nodo1->right = nodo;
      if(nodo1->bal == 1)
      {
        nodo->bal = 0;nodo1->bal = 0;
      }
      else //nodo1->bal == 0
      {
        nodo->bal = 1;
        nodo1->bal = -1;
      }
      nodo = nodo1;
    }

    void rotacion_DD (nodoAVL<Clave>*& nodo)
    {
      nodoAVL<Clave>* nodo1 = nodo->right;
      nodo->right = nodo1->left;
      nodo1->left = nodo;
      if (nodo->bal == -1)
      {
        nodo->bal = 0;
        nodo1->bal = 0;
      }
      else //nodo1->bal == 0
      {
        nodo->bal = -1;
        nodo1->bal = 1;
      }
      nodo = nodo1;
    }

    void rotacion_ID (nodoAVL<Clave>*& nodo)
    {
      nodoAVL<Clave>* nodo1 = nodo->left;
      nodoAVL<Clave>* nodo2 = nodo1->right;
      nodo->left = nodo2->right;
      nodo2->right = nodo;
      nodo1->right = nodo2->left;
      nodo2->left = nodo1;
      if (nodo2->bal == -1)
        nodo1->bal = 1;
      else
        nodo1->bal = 0;
      if (nodo2->bal == 1)
        nodo->bal = -1;
      else
        nodo->bal = 0;
      nodo2->bal = 0;
      nodo = nodo2;
    }

    void rotacion_DI (nodoAVL<Clave>*& nodo)
    {
      nodoAVL<Clave>* nodo1 = nodo->right;
      nodoAVL<Clave>* nodo2 = nodo1->left;
      nodo->right = nodo2->left;
      nodo2->left = nodo;
      nodo1->left = nodo2->right;
      nodo2->right = nodo1;
      if (nodo2->bal == 1)
        nodo1->bal = -1;
      else
        nodo1->bal = 0;
      if (nodo2->bal == -1)
        nodo->bal = 1;
      else
        nodo->bal = 0;
      nodo2->bal = 0;
      nodo = nodo2;
    }

    void Insertar(const Clave& X)
    {
      nodoAVL<Clave>* nuevo = new nodoAVL<Clave> (X, 0); // ???
      bool crece = false;
      insertar_bal(root, nuevo, crece);
    }

    void insertar_bal(nodoAVL<Clave>*& nodo, nodoAVL<Clave>* nuevo, bool& crece)
    {
      if (!nodo)
      {
        nodo = nuevo;
        crece = true;
      }
      else if (nuevo->Valor_ < nodo->Valor_)
      {
        insertar_bal(nodo->left, nuevo, crece);
        if (crece) insert_re_balancea_izda(nodo, crece);
      }
      else
      {
        insertar_bal(nodo->right, nuevo, crece);
        if (crece) insert_re_balancea_dcha(nodo, crece);
      }
    }
    void insert_re_balancea_izda(nodoAVL<Clave>*& nodo, bool& crece)
    {
      switch (nodo->bal) {
        case -1:
          nodo->bal = 0;
          crece = false;
          break;
        case 0:
          nodo->bal = 1;
          break;
        case 1:
          nodoAVL<Clave>* nodo1 = nodo->left;
          if (nodo1->bal == 1)
            rotacion_II(nodo);
          else
            rotacion_ID(nodo);
          crece = false;
      }
    }

    void insert_re_balancea_dcha(nodoAVL<Clave>*& nodo, bool& crece)
    {
      switch (nodo->bal) {
        case 1:
          nodo->bal = 0;
          crece = false;
          break;
        case 0:
          nodo->bal = -1;
          break;
        case -1:
          nodoAVL<Clave>* nodo1 = nodo->right;
          if (nodo1->bal == -1)
            rotacion_DD(nodo);
          else
            rotacion_DI(nodo);
          crece = false;
      }
    }

    void eliminar(const Clave& X) {
      bool decrece = false;
      elimina_rama(root, X, decrece);
    }

    void elimina_rama(nodoAVL<Clave>*& nodo, const Clave& ClaveDada, bool& decrece)
    {
      if (!nodo) return;
      if (ClaveDada < nodo->Valor_) {
        elimina_rama(nodo->left, ClaveDada, decrece);
        if (decrece) eliminar_re_balancea_izda(nodo, decrece);
      } else if (ClaveDada > nodo->Valor_) {
        elimina_rama(nodo->right, ClaveDada, decrece);
        if (decrece) eliminar_re_balancea_dcha(nodo, decrece);
      } else {  // nodo->Valor_ == ClaveDada(encontrado)
        nodoAVL<Clave>* Eliminado = nodo;
        if (nodo->left == NULL) {
          nodo = nodo->right;
          decrece = true;
        } else if (nodo->right == NULL) {
          nodo = nodo->left;
          decrece = true;
        } else {
          sustituye(Eliminado, nodo->left, decrece);
          if (decrece) eliminar_re_balancea_izda(nodo, decrece);
        }
      }
    }

    void sustituye(nodoAVL<Clave>*& eliminado, nodoAVL<Clave>*& sust, bool& decrece)
    {
      if (sust->right != NULL) {
        sustituye(eliminado, sust->right, decrece);
        if (decrece) eliminar_re_balancea_dcha(sust, decrece);
      } else {
        eliminado->Valor_ = sust->Valor_;
        eliminado = sust;
        sust = sust->left;
        decrece = true;
      }
    }

    void eliminar_re_balancea_izda (nodoAVL<Clave>*& nodo, bool& decrece)
    {
      switch(nodo->bal)
      {
        case -1:
          {
            nodoAVL<Clave>* nodo1 = nodo->right;
            if(nodo1->bal > 0) rotacion_DI(nodo);
            else
            {
              if(nodo1->bal == 0)
                decrece = false;
              rotacion_DD(nodo);
            }
            break;
          }
        case 0:
          {
            nodo->bal = -1;
            decrece = false;
            break;
          }
        case 1:
          {
            nodo->bal = 0;
            break;
          }
      }
    }

    void eliminar_re_balancea_dcha (nodoAVL<Clave>* &nodo, bool& decrece)
    {
      switch (nodo->bal)
      {
        case 1:
          {
            nodoAVL<Clave>* nodo1 = nodo->left;
            if (nodo1->bal < 0)
              rotacion_ID(nodo);
            else
            {
              if (nodo1->bal == 0)
                decrece = false;
              rotacion_II(nodo);
            }
            break ;
          }
        case 0:
          {
            nodo->bal = 1;
            decrece = false;
            break;
          }
        case -1:
          {
            nodo->bal = 0;
            break;
          }
      }
    }

    Matrix_de_Niveles<Clave> Recorrido_nivel()
    {
      Matrix_de_Niveles<Clave> vectores; // Matrix_de_Niveles = std::vector<std::vector<nodoAVL<Clave>*>>
      std::vector<nodoAVL<Clave>*> vector_l;

      vector_l.push_back(root);
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
            if (vectores[i][j]->left || vectores[i][j]->right)
            {
              booleano = true;
            }
            vector_l.push_back(vectores[i][j]->left);
            vector_l.push_back(vectores[i][j]->right);
          }
        }
        vectores.push_back(vector_l);
      }
      vectores.pop_back(); // Elimino porque me queda un nivel completo apuntando
      return vectores;     // a NULL, que no aporta nada.
    }

    std::ostream& write(std::ostream& os)
    {
      if (!root)
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
#endif // _AVL_
