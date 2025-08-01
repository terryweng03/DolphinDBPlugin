#pragma once
#include "coptcpp.idl.h"

class Cone {
public:
  Cone(Copt::ICone* cone) : m_cone(cone) {}

  int GetIdx() const
  {
    return m_cone->GetIdx();
  }

  void Remove()
  {
    m_cone->Remove();
  }

  Copt::ICone* Get() const
  {
    return &(*m_cone);
  }

  friend std::ostream& operator<<(std::ostream& out, const Cone& cone)
  {
    out << "Cone(" << cone.GetIdx();
    if (cone.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::ICone> m_cone;
};
