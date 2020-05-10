#ifndef _nodoBB_
#define _nodoBB_


template<class Clave>
class nodoBB
{
  private:
    Clave Valor_;
    nodoBB<Clave>* nodo;
    nodoBB<Clave>* hijo1;
    nodoBB<Clave>* hijo2;
  public:
    nodoBB()
    {
      hijo1 = nullptr;
      hijo2 = nullptr;
    }
    nodoBB(const Clave& Valor)
    {
      Valor_ = Valor;
      hijo1 = nullptr;
      hijo2 = nullptr;
    }
};

#endif
