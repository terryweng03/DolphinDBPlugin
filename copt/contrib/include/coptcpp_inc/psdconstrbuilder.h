#pragma once
#include "coptcpp.idl.h"
#include "psdexpr.h"
#include "psdconstrbuilder.h"

class PsdConstrBuilder {
public:
  PsdConstrBuilder() : m_builder(CreatePsdConstrBuilder()) {}
  PsdConstrBuilder(Copt::IPsdConstrBuilder* pcb) : m_builder(pcb) {}

  PsdExpr GetPsdExpr() const
  {
    return m_builder->GetPsdExpr();
  }

  char GetSense() const
  {
    return m_builder->GetSense();
  }

  double GetRange() const
  {
    return m_builder->GetRange();
  }

  void Set(const PsdExpr& expr, char sense, double rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs);
  }
  void SetRange(const PsdExpr& expr, double range)
  {
    m_builder->SetRange(expr.Get(), range);
  }

  friend std::ostream& operator<<(std::ostream& out, const PsdConstrBuilder& builder)
  {
    char sense = builder.GetSense();

    if (sense == COPT_RANGE)
    {
      out << -builder.GetRange() << " <= ";
      out << builder.GetPsdExpr() << " <= 0.0";
      return out;
    }

    switch (sense)
    {
    case COPT_LESS_EQUAL:
      out << builder.GetPsdExpr() << " <= 0.0";
      break;
    case COPT_GREATER_EQUAL:
      out << builder.GetPsdExpr() << " >= 0.0";
      break;
    case COPT_EQUAL:
      out << builder.GetPsdExpr() << " == 0.0";
      break;
    case COPT_FREE:
      out << builder.GetPsdExpr() << " FREE";
      break;
    default:
      out << " UNKNOWN";
      break;
    }
    return out;
  }

  Copt::IPsdConstrBuilder* Get() const
  {
    return &(*m_builder);
  }

private:
  std::shared_ptr<Copt::IPsdConstrBuilder> m_builder;
};
