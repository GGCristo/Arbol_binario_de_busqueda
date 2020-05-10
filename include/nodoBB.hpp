#ifndef _nodoBB_
#define _nodoBB_


template<class Clave>
class nodoBB
{
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
    nodoBB(const Clave& Valor)
    {
      Valor_ = Valor;
      hijo_l = nullptr;
      hijo_r = nullptr;
    }
    nodoBB<Clave>* Buscar(Clave X)
    {
      if (Valor_ == X) return this;
      if (hijo_l && x < Valor_) return hijo_l->Buscar(X);
      if (hijo_r && x > Valor_) return hijo_r->Buscar(X);
      return nullptr;
    }
};

#endif
