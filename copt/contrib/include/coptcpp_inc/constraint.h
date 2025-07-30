#pragma once
#include "coptcpp.idl.h"
#include "exception.h"

class Constraint {
public:
  Constraint(Copt::IConstraint* constr) : m_constr(constr) {}

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

  int GetBasis() const
  {
    int status = m_constr->GetBasis();
    CHECKERROR(m_constr);
    return status;
  }

  int GetLowerIIS() const
  {
    int loweriis = m_constr->GetLowerIIS();
    CHECKERROR(m_constr);
    return loweriis;
  }

  int GetUpperIIS() const
  {
    int upperiis = m_constr->GetUpperIIS();
    CHECKERROR(m_constr);
    return upperiis;
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

  Copt::IConstraint* Get() const
  {
    return &(*m_constr);
  }

  friend std::ostream& operator<<(std::ostream& out, const Constraint& con)
  {
    out << "Row(" << con.GetName();
    if (con.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::IConstraint> m_constr;
};
