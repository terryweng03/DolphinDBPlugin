#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"

class View {
public:
  View() : m_view(MFactory::Get().CreateView()) {}
  View(Copt::IView* view) : m_view(view) {}

  View AddFull() const
  {
    return m_view->AddFull();
  }

  View AddScalar(int64_t n) const
  {
    return m_view->AddScalar(n);
  }

  View AddSlice(int64_t start) const
  {
    return m_view->AddSlice(start, 0, 1, 0x3);
  }

  View AddSlice(int64_t start, int64_t stop) const
  {
    return m_view->AddSlice(start, stop, 1, 0x0);
  }

  View AddSlice(int64_t start, int64_t stop, int64_t step, int flag = 0) const
  {
    return m_view->AddSlice(start, stop, step, flag);
  }

  Copt::IView* Get() const
  {
    return &(*m_view);
  }

  View operator()()
  {
    return AddFull();
  }

  View operator()(int64_t start, int64_t stop)
  {
    return AddSlice(start, stop, 1);
  }

  View operator()(int64_t start, int64_t stop, int64_t step)
  {
    return AddSlice(start, stop, step);
  }

  View operator()(int64_t n)
  {
    return AddScalar(n);
  }

private:
  std::shared_ptr<Copt::IView> m_view;
};

namespace Mat {

inline View make_view()
{
  return View()();
}

inline View make_view(int64_t n)
{
  return View()(n);
}

inline View make_view(int64_t start, int64_t stop, int64_t step = 1)
{
  return View()(start, stop, step);
}
}  // namespace Mat