#pragma once
#include "coptcpp.idl.h"
#include "exception.h"

class GenConstr {
public:
  GenConstr(Copt::IGenConstr* ptr) : m_genc(ptr) {}

  int GetIdx() const
  {
    return m_genc->GetIdx();
  }
  const char* GetName() const
  {
    return m_genc->GetName();
  }

  void SetName(const char* szName)
  {
    m_genc->SetName(szName);
    CHECKERROR(m_genc);
  }

  int GetIIS() const
  {
    return m_genc->GetIIS();
  }

  void Remove()
  {
    m_genc->Remove();
  }

  Copt::IGenConstr* Get() const
  {
    return &(*m_genc);
  }

  friend std::ostream& operator<<(std::ostream& out, const GenConstr& gcon)
  {
    out << "GenConstr(" << gcon.GetName();
    if (gcon.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::IGenConstr> m_genc;
};
