#pragma once
#include "coptcpp.idl.h"
#include "quadexpr.h"
#include "genconstrbuilder.h"

class QConstrBuilder {
public:
  QConstrBuilder() : m_builder(CreateQConstrBuilder()) {}
  QConstrBuilder(Copt::IQConstrBuilder* pcb) : m_builder(pcb) {}

  QuadExpr GetQuadExpr() const
  {
    return m_builder->GetQuadExpr();
  }
  char GetSense() const
  {
    return m_builder->GetSense();
  }

  void Set(const QuadExpr& expr, char sense, double rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs);
  }

  friend std::ostream& operator<<(std::ostream& out, const QConstrBuilder& builder)
  {
    char sense = builder.GetSense();

    switch (sense)
    {
    case COPT_LESS_EQUAL:
      out << builder.GetQuadExpr() << " <= 0.0";
      break;
    case COPT_GREATER_EQUAL:
      out << builder.GetQuadExpr() << " >= 0.0";
      break;
    case COPT_EQUAL:
      out << builder.GetQuadExpr() << " == 0.0";
      break;
    default:
      out << " UNKNOWN";
      break;
    }
    return out;
  }

  Copt::IQConstrBuilder* Get() const
  {
    return &(*m_builder);
  }

private:
  std::shared_ptr<Copt::IQConstrBuilder> m_builder;
};
