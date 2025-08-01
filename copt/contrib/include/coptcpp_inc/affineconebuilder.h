#pragma once
#include <cmath>
#include <iostream>

#include "coptcpp.idl.h"
#include "coptcpp.h"
#include "mpsdexpr.h"

class AffineConeBuilder {
public:
  AffineConeBuilder() : m_builder(CreateAffineConeBuilder()) {}
  AffineConeBuilder(Copt::IAffineConeBuilder* pcb) : m_builder(pcb) {}

  int GetType() const
  {
    return m_builder->GetType();
  }
  int GetSize() const
  {
    return m_builder->GetSize();
  }
  bool HasPsdTerm() const
  {
    return m_builder->HasPsdTerm();
  }
  Expr GetExpr(int i) const
  {
    return m_builder->GetExpr(i);
  }
  PsdExpr GetPsdExpr(int i) const
  {
    return m_builder->GetPsdExpr(i);
  }
  MLinExpr<1> GetExprs() const
  {
    return m_builder->GetExprs();
  }
  MPsdExpr<1> GetPsdExprs() const
  {
    return m_builder->GetPsdExprs();
  }

  void Set(const MPsdExpr<1>& exprs, int type)
  {
    m_builder->Set(exprs.Get(), type);
  }

  void Set(const std::vector<PsdExpr>& exprs, int type)
  {
    MPsdExpr<1> mex(Shape<1>(exprs.size()), exprs);
    m_builder->Set(mex.Get(), type);
  }

  void Set(const MLinExpr<1>& exprs, int type)
  {
    m_builder->Set(exprs.Get(), type);
  }

  void Set(const std::vector<Expr>& exprs, int type)
  {
    MLinExpr<1> mex(Shape<1>(exprs.size()), exprs);
    m_builder->Set(mex.Get(), type);
  }

  Copt::IAffineConeBuilder* Get() const
  {
    return &(*m_builder);
  }

  friend std::ostream& operator<<(std::ostream& out, const AffineConeBuilder& builder)
  {
    out << "Copt Affine Cone <type " << builder.GetType() << ">\n";
    for (int i = 0; i < builder.GetSize(); i++)
    {
      out << "  " << builder.GetPsdExpr(i) << std::endl;
    }
    return out;
  }

private:
  std::shared_ptr<Copt::IAffineConeBuilder> m_builder;
};
