#pragma once
#include "coptcpp.idl.h"
#include "exception.h"
#include "symmatrix.h"

class LmiConstraint {
public:
  LmiConstraint(Copt::ILmiConstraint* constr) : m_constr(constr) {}

  int GetIdx() const
  {
    return m_constr->GetIdx();
  }
  int GetDim() const
  {
    return m_constr->GetDim();
  }
  int GetLen() const
  {
    return m_constr->GetLen();
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

  void Get(const char* szAttr, double* pOut, int len)
  {
    m_constr->Get(szAttr, pOut, len);
    CHECKERROR(m_constr);
  }

  void SetRhs(const SymMatrix& mat)
  {
    m_constr->SetRhs(mat.Get());
    CHECKERROR(m_constr);
  }

  void Remove()
  {
    m_constr->Remove();
  }

  Copt::ILmiConstraint* Get() const
  {
    return &(*m_constr);
  }

  friend std::ostream& operator<<(std::ostream& out, const LmiConstraint& con)
  {
    out << "LMIRow(" << con.GetName();
    if (con.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::ILmiConstraint> m_constr;
};
