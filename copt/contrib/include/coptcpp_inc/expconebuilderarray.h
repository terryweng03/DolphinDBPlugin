#pragma once
#include "coptcpp.idl.h"
#include "expconebuilder.h"

class ExpConeBuilderArray {
public:
  ExpConeBuilderArray() : m_builders(CreateExpConeBuilderArray()) {}
  ExpConeBuilderArray(Copt::IExpConeBuilderArray* ptr) : m_builders(ptr) {}

  void PushBack(const ExpConeBuilder& builder)
  {
    return m_builders->PushBack(builder.Get());
  }

  int Size() const
  {
    return m_builders->Size();
  }
  ExpConeBuilder GetBuilder(int idx) const
  {
    return m_builders->GetBuilder(idx);
  }
  ExpConeBuilder operator[](int i) const
  {
    return m_builders->GetBuilder(i);
  }

  Copt::IExpConeBuilderArray* Get() const
  {
    return &(*m_builders);
  }

private:
  std::shared_ptr<Copt::IExpConeBuilderArray> m_builders;
};
