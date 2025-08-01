#pragma once
#include <cmath>
#include <iostream>

#include "coptcpp.idl.h"
#include "coptcpp.h"
#include "var.h"
#include "vararray.h"

class ExpConeBuilder {
public:
  ExpConeBuilder() : m_builder(CreateExpConeBuilder()) {}
  ExpConeBuilder(Copt::IExpConeBuilder* pcb) : m_builder(pcb) {}

  int GetType() const
  {
    return m_builder->GetType();
  }
  int GetSize() const
  {
    return m_builder->GetSize();
  }
  Var GetVar(int idx) const
  {
    return m_builder->GetVar(idx);
  }

  void Set(const VarArray& vars, int type)
  {
    m_builder->Set(vars.Get(), type);
  }

  Copt::IExpConeBuilder* Get() const
  {
    return &(*m_builder);
  }

  friend std::ostream& operator<<(std::ostream& out, const ExpConeBuilder& builder)
  {
    bool beg = true;
    for (int i = 0; i < builder.GetSize(); i++)
    {
      if (builder.GetVar(i).GetIdx() < 0)
      {
        continue;
      }

      if (!beg)
      {
        out << " + ";
      }

      beg = false;
      out << builder.GetVar(i).GetName();
    }
    out << "   <ExpCone Type " << builder.GetType() << ">";
    return out;
  }

private:
  std::shared_ptr<Copt::IExpConeBuilder> m_builder;
};
