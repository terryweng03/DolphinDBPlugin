#pragma once
#include "copt.h"
#include "coptcpp.idl.h"

class GenConstrBuilder {
public:
  GenConstrBuilder() : m_builder(CreateGenConstrBuilder()) {}
  GenConstrBuilder(Copt::IGenConstrBuilder* pcb) : m_builder(pcb) {}

  Var GetBinVar() const
  {
    return m_builder->GetBinVar();
  }
  int GetBinVal() const
  {
    return m_builder->GetBinVal();
  }

  Expr GetExpr() const
  {
    return m_builder->GetExpr();
  }
  char GetSense() const
  {
    return m_builder->GetSense();
  }

  int GetIndType() const
  {
    return m_builder->GetIndType();
  }

  void Set(const Var& var, int val, const Expr& expr, char sense, int type = COPT_INDICATOR_IF)
  {
    m_builder->Set(var.Get(), val, expr.Get(), sense, type);
  }

  friend std::ostream& operator<<(std::ostream& out, const GenConstrBuilder& builder)
  {
    out << "(" << builder.GetBinVar().GetName();
    out << " == " << builder.GetBinVal() << ")";

    int type = builder.GetIndType();
    switch (type)
    {
    case COPT_INDICATOR_IF:
      out << " -> ";
      break;
    case COPT_INDICATOR_ONLYIF:
      out << " <- ";
      break;
    case COPT_INDICATOR_IFANDONLYIF:
      out << " <-> ";
      break;
    default:
      out << " INVALID TYPE ";
      break;
    }

    char sense = builder.GetSense();
    switch (sense)
    {
    case COPT_LESS_EQUAL:
      out << "(" << builder.GetExpr() << " <= 0.0)";
      break;
    case COPT_GREATER_EQUAL:
      out << "(" << builder.GetExpr() << " >= 0.0)";
      break;
    case COPT_EQUAL:
      out << "(" << builder.GetExpr() << " == 0.0)";
      break;
    default:
      out << " UNKNOWN";
      break;
    }
    return out;
  }

  Copt::IGenConstrBuilder* Get() const
  {
    return &(*m_builder);
  }

private:
  std::shared_ptr<Copt::IGenConstrBuilder> m_builder;
};
