#pragma once
#include "coptcpp.idl.h"
#include "coptcpp.h"
#include "affinecone.h"

class AffineConeArray {
public:
  AffineConeArray() : m_cones(CreateAffineConeArray()) {}
  AffineConeArray(Copt::IAffineConeArray* ptr) : m_cones(ptr) {}

  void PushBack(const AffineCone& cone)
  {
    return m_cones->PushBack(cone.Get());
  }

  int Size() const
  {
    return m_cones->Size();
  }

  AffineCone GetCone(int idx) const
  {
    return m_cones->GetCone(idx);
  }
  AffineCone operator[](int i) const
  {
    return m_cones->GetCone(i);
  }

  Copt::IAffineConeArray* Get() const
  {
    return &(*m_cones);
  }

private:
  std::shared_ptr<Copt::IAffineConeArray> m_cones;
};
