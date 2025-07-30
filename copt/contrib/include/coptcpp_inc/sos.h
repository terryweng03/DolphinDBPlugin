#pragma once
#include "coptcpp.idl.h"

class Sos {
public:
  Sos(Copt::ISos* sos) : m_sos(sos) {}

  int GetIdx() const
  {
    return m_sos->GetIdx();
  }

  int GetIIS() const
  {
    return m_sos->GetIIS();
  }

  void Remove()
  {
    m_sos->Remove();
  }

  Copt::ISos* Get() const
  {
    return &(*m_sos);
  }

  friend std::ostream& operator<<(std::ostream& out, const Sos& sos)
  {
    out << "SOS(" << sos.GetIdx();
    if (sos.GetIdx() < 0)
    {
      out << " Removed";
    }
    out << ")";
    return out;
  }

private:
  std::shared_ptr<Copt::ISos> m_sos;
};
