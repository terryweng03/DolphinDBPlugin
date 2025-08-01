#pragma once
#include "coptcpp.idl.h"
#include "nlexpr.h"

class NlConstrBuilder {
public:
  NlConstrBuilder() : m_builder(CreateNlConstrBuilder()) {}
  NlConstrBuilder(Copt::INlConstrBuilder* pcb) : m_builder(pcb) {}

  NlExpr GetNlExpr() const
  {
    return m_builder->GetNlExpr();
  }

  char GetSense() const
  {
    return m_builder->GetSense();
  }
  double GetRange() const
  {
    return m_builder->GetRange();
  }

  void Set(const NlExpr& expr, char sense, double rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs);
  }

  void SetRange(const NlExpr& expr, double range)
  {
    m_builder->SetRange(expr.Get(), range);
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_builder->Represent(maxlen);
  }

  friend std::ostream& operator<<(std::ostream& out, const NlConstrBuilder& builder)
  {
    out << builder.Represent();
    return out;
  }

  Copt::INlConstrBuilder* Get() const
  {
    return &(*m_builder);
  }

private:
  std::shared_ptr<Copt::INlConstrBuilder> m_builder;
};
