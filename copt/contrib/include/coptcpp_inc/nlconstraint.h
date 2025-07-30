#pragma once
#include "coptcpp.idl.h"
#include "exception.h"

class NlConstraint {
public:
  NlConstraint(Copt::INlConstraint* constr) : m_constr(constr) {}

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

  double Get(const char* szInfo)
  {
    double val = m_constr->Get(szInfo);
    CHECKERROR(m_constr);
    return val;
  }

  void Set(const char* szInfo, double value)
  {
    m_constr->Set(szInfo, value);
    CHECKERROR(m_constr);
  }

  void Remove()
  {
    m_constr->Remove();
  }

  Copt::INlConstraint* Get() const
  {
    return &(*m_constr);
  }

  friend std::ostream& operator<<(std::ostream& out, const NlConstraint& con)
  {
    out << "NLRow(" << con.GetName();
    if (con.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::INlConstraint> m_constr;
};
