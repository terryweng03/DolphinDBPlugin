#pragma once
#include "coptcpp.idl.h"
#include "affineconebuilder.h"

class AffineConeBuilderArray {
public:
  AffineConeBuilderArray() : m_builders(CreateAffineConeBuilderArray()) {}
  AffineConeBuilderArray(Copt::IAffineConeBuilderArray* ptr) : m_builders(ptr) {}

  void PushBack(const AffineConeBuilder& builder)
  {
    return m_builders->PushBack(builder.Get());
  }

  int Size() const
  {
    return m_builders->Size();
  }
  AffineConeBuilder GetBuilder(int idx) const
  {
    return m_builders->GetBuilder(idx);
  }
  AffineConeBuilder operator[](int i) const
  {
    return m_builders->GetBuilder(i);
  }

  Copt::IAffineConeBuilderArray* Get() const
  {
    return &(*m_builders);
  }

private:
  std::shared_ptr<Copt::IAffineConeBuilderArray> m_builders;
};
