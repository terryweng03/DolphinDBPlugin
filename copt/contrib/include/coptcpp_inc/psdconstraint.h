#pragma once
#include "coptcpp.idl.h"
#include "exception.h"

class PsdConstraint {
public:
  PsdConstraint(Copt::IPsdConstraint* constr) : m_constr(constr) {}

  int GetIdx() const
  {
    return m_constr->GetIdx();
  }
  const char* GetName() const
  {
    return m_constr->GetName();
  }

  void SetName(const char* szName)
  {
    m_constr->SetName(szName);
    CHECKERROR(m_constr);
  }

  double Get(const char* szAttr)
  {
    double val = m_constr->Get(szAttr);
    CHECKERROR(m_constr);
    return val;
  }

  void Set(const char* szAttr, double value)
  {
    m_constr->Set(szAttr, value);
    CHECKERROR(m_constr);
  }

  void Remove()
  {
    m_constr->Remove();
  }

  Copt::IPsdConstraint* Get() const
  {
    return &(*m_constr);
  }

  friend std::ostream& operator<<(std::ostream& out, const PsdConstraint& con)
  {
    out << "PSDRow(" << con.GetName();
    if (con.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::IPsdConstraint> m_constr;
};
