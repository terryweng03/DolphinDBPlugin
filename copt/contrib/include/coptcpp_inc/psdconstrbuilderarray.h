#pragma once
#include "coptcpp.idl.h"
#include "psdconstrbuilder.h"

class PsdConstrBuilderArray {
public:
  PsdConstrBuilderArray() : m_builders(CreatePsdConstrBuilderArray()) {}
  PsdConstrBuilderArray(Copt::IPsdConstrBuilderArray* ptr) : m_builders(ptr) {}

  void PushBack(const PsdConstrBuilder& builder)
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

  PsdConstrBuilder GetBuilder(int idx) const
  {
    return m_builders->GetBuilder(idx);
  }
  PsdConstrBuilder operator[](int i) const
  {
    return m_builders->GetBuilder(i);
  }

  Copt::IPsdConstrBuilderArray* Get() const
  {
    return &(*m_builders);
  }

private:
  std::shared_ptr<Copt::IPsdConstrBuilderArray> m_builders;
};
