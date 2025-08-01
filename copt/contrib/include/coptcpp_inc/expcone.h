#pragma once
#include "coptcpp.idl.h"

class ExpCone {
public:
  ExpCone(Copt::IExpCone* cone) : m_cone(cone) {}

  int GetIdx() const
  {
    return m_cone->GetIdx();
  }

  void Remove()
  {
    m_cone->Remove();
  }

  Copt::IExpCone* Get() const
  {
    return &(*m_cone);
  }

  friend std::ostream& operator<<(std::ostream& out, const ExpCone& cone)
  {
    out << "ExpCone(" << cone.GetIdx();
    if (cone.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::IExpCone> m_cone;
};
