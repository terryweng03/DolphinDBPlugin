#pragma once
#include "coptcpp.idl.h"
#include "exception.h"

class QConstraint {
public:
  QConstraint(Copt::IQConstraint* constr) : m_constr(constr) {}

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

  double GetRhs() const
  {
    double rhs = m_constr->GetRhs();
    CHECKERROR(m_constr);
    return rhs;
  }

  char GetSense() const
  {
    char sense = m_constr->GetSense();
    CHECKERROR(m_constr);
    return sense;
  }

  void SetRhs(double rhs)
  {
    m_constr->SetRhs(rhs);
    CHECKERROR(m_constr);
  }

  void SetSense(char sense)
  {
    m_constr->SetSense(sense);
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

  Copt::IQConstraint* Get() const
  {
    return &(*m_constr);
  }

  friend std::ostream& operator<<(std::ostream& out, const QConstraint& qcon)
  {
    out << "QRow(" << qcon.GetName();
    if (qcon.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::IQConstraint> m_constr;
};
