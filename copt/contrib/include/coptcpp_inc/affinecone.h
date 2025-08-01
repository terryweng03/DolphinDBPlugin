#pragma once
#include "coptcpp.idl.h"
#include "exception.h"

class AffineCone {
public:
  AffineCone(Copt::IAffineCone* cone) : m_cone(cone) {}

  int GetIdx() const
  {
    return m_cone->GetIdx();
  }

  const char* GetName() const
  {
    return m_cone->GetName();
  }

  void SetName(const char* szName)
  {
    m_cone->SetName(szName);
    CHECKERROR(m_cone);
  }

  void Remove()
  {
    m_cone->Remove();
  }

  Copt::IAffineCone* Get() const
  {
    return &(*m_cone);
  }

  friend std::ostream& operator<<(std::ostream& out, const AffineCone& cone)
  {
    out << "AffCone(" << cone.GetName();
    if (cone.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::IAffineCone> m_cone;
};
