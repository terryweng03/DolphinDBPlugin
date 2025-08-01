#pragma once
#include "coptcpp.idl.h"
#include "exception.h"
#include "ndarray.h"

class PsdExpr;
class SymMatrix;
class SymMatExpr;

class PsdVar {
public:
  PsdVar(Copt::IPsdVar* var) : m_var(var) {}

  int GetIdx() const
  {
    return m_var->GetIdx();
  }
  int GetDim() const
  {
    return m_var->GetDim();
  }
  int GetLen() const
  {
    return m_var->GetLen();
  }
  int GetSize() const
  {
    return m_var->GetSize();
  }

  const char* GetName() const
  {
    return m_var->GetName();
  }
  void SetName(const char* szName)
  {
    m_var->SetName(szName);
    CHECKERROR(m_var);
  }

  void Get(const char* szAttr, double* pOut, int sz)
  {
    m_var->Get(szAttr, pOut, sz);
    CHECKERROR(m_var);
  }

  NdArray<double, 2> Get(const char* szAttr)
  {
    NdArray<double, 2> ret = m_var->Get(szAttr);
    CHECKERROR(m_var);
    return ret;
  }

  void Remove()
  {
    m_var->Remove();
  }

  Copt::IPsdVar* Get() const
  {
    return &(*m_var);
  }

  friend std::ostream& operator<<(std::ostream& out, const PsdVar& var)
  {
    out << "PSDVar(" << var.GetName();
    if (var.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

  // Declare operator overloadings here and refer to utils.h for actual definitions,
  // because they depend on each other.
  friend PsdExpr operator*(const PsdVar& var, const SymMatrix& mat);
  friend PsdExpr operator*(const SymMatrix& mat, const PsdVar& var);
  friend PsdExpr operator*(const PsdVar& var, const SymMatExpr& expr);
  friend PsdExpr operator*(const SymMatExpr& expr, const PsdVar& var);

private:
  std::shared_ptr<Copt::IPsdVar> m_var;
};
