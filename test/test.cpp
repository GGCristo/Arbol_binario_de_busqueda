#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>

#include "../include/AVL.hpp"
#include "../include/DNI.hpp"
typedef int TDato;

bool::DNI::MODO = true;
unsigned DNI::CONTADOR = 0;

TEST_CASE("Básico")
{
  SECTION("Construye y elimina vacío")
  {
    AVL<TDato> Arbol;
  }

  SECTION("Construyo árbol grande y elimino de forma natural")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI());
    Arbol.Insertar(DNI());
    Arbol.Insertar(DNI());
    Arbol.Insertar(DNI());
    Arbol.Insertar(DNI());
    Arbol.Insertar(DNI());
    Arbol.Insertar(DNI());
    Arbol.Insertar(DNI());
  }
}

TEST_CASE("Insertar")
{

  SECTION("Inserto un elemento")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(3));
  }

  SECTION("Inserto un elemento repetido")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(3));
    Arbol.Insertar(DNI(3));
  }
}

TEST_CASE("Buscar")
{

  SECTION("Busco un elemento")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(102));
    Arbol.Buscar(DNI(3));
  }

  SECTION("Busco un elemento que no esta")
  {
    AVL<TDato> Arbol;
    Arbol.Buscar(DNI(3));
  }
}

TEST_CASE("Eliminar")
{

  SECTION("Eliminar nodo raiz sin hijos")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(3));
    Arbol.eliminar(DNI(3));
  }

  SECTION("Eliminar un elemento (vacío)")
  {
    AVL<TDato> Arbol;
    Arbol.eliminar(DNI(4));
  }

  SECTION("Eliminar nodo raíz con un hijo derecho")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(3));
    Arbol.Insertar(DNI(4));
    Arbol.eliminar(DNI(3));
  }

  SECTION("Eliminar nodo raíz con un hijo izquierdo")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(3));
    Arbol.Insertar(DNI(2));
    Arbol.eliminar(DNI(3));
  }

  SECTION("Eliminar nodo raíz con dos hijo")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(3));
    Arbol.Insertar(DNI(2));
    Arbol.Insertar(DNI(4));
    Arbol.eliminar(DNI(3));
  }
}

TEST_CASE("Imprimir")
{
  SECTION("Imprimir nivel 0")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(3));
    Arbol.write(std::cout);
  }

  SECTION("Imprimir vacio")
  {
    AVL<TDato> Arbol;
    Arbol.write(std::cout);
  }

  SECTION("Imprimir árbol derecha")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(3));
    Arbol.Insertar(DNI(4));
    Arbol.Insertar(DNI(5));
    Arbol.write(std::cout);
  }

  SECTION("Imprimir árbol izquierda")
  {
    AVL<TDato> Arbol;
    Arbol.Insertar(DNI(3));
    Arbol.Insertar(DNI(2));
    Arbol.Insertar(DNI(1));
    Arbol.write(std::cout);
  }
}
