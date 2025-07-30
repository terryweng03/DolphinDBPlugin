#pragma once
#include "coptcpp.idl.h"
#include "nlconstrbuilder.h"

class NlConstrBuilderArray {
public:
  NlConstrBuilderArray() : m_builders(CreateNlConstrBuilderArray()) {}
  NlConstrBuilderArray(Copt::INlConstrBuilderArray* ptr) : m_builders(ptr) {}

  void PushBack(const NlConstrBuilder& builder)
  {
    return m_builders->PushBack(builder.Get());
  }

  int Size() const
  {
    return m_builders->Size();
  }

  void Reserve(int n)
  {
    m_builders->Reserve(n);
  }

  NlConstrBuilder GetBuilder(int idx) const
  {
    return m_builders->GetBuilder(idx);
  }
  NlConstrBuilder operator[](int i) const
  {
    return m_builders->GetBuilder(i);
  }

  Copt::INlConstrBuilderArray* Get() const
  {
    return &(*m_builders);
  }

private:
  std::shared_ptr<Copt::INlConstrBuilderArray> m_builders;
};
