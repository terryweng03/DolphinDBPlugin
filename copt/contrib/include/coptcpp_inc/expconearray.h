#pragma once
#include "coptcpp.idl.h"
#include "coptcpp.h"
#include "expcone.h"

class ExpConeArray {
public:
  ExpConeArray() : m_coneArray(CreateExpConeArray()) {}
  ExpConeArray(Copt::IExpConeArray* ptr) : m_coneArray(ptr) {}

  void PushBack(const ExpCone& cone)
  {
    return m_coneArray->PushBack(cone.Get());
  }

  int Size() const
  {
    return m_coneArray->Size();
  }

  ExpCone GetCone(int idx) const
  {
    return m_coneArray->GetCone(idx);
  }
  ExpCone operator[](int i) const
  {
    return m_coneArray->GetCone(i);
  }

  Copt::IExpConeArray* Get() const
  {
    return &(*m_coneArray);
  }

private:
  std::shared_ptr<Copt::IExpConeArray> m_coneArray;
};
