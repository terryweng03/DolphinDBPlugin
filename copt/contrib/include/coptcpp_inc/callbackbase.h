#pragma once
#include "coptcpp.h"
#include "callback.h"
#include "exception.h"
#include "constrbuilderarray.h"

class CallbackBase : public ICallback {
public:
  CallbackBase() : m_proxy(CreateCallbackProxy())
  {
    CHECKERROR(m_proxy);
  }

  // customized callback implemented by user
  virtual void callback() override {}

  void Interrupt()
  {
    m_proxy->Interrupt();
    CHECKERROR(m_proxy);
  }

  void AddUserCut(const Expr& lhs, char sense, double rhs)
  {
    m_proxy->AddUserCut(lhs.Get(), sense, rhs);
    CHECKERROR(m_proxy);
  }
  void AddUserCut(const Expr& lhs, char sense, const Expr& rhs)
  {
    m_proxy->AddUserCut(lhs.Get(), sense, rhs.Get());
    CHECKERROR(m_proxy);
  }
  void AddUserCut(const ConstrBuilder& builder)
  {
    m_proxy->AddUserCut(builder.Get());
    CHECKERROR(m_proxy);
  }
  void AddUserCuts(const ConstrBuilderArray& builders)
  {
    m_proxy->AddUserCuts(builders.Get());
    CHECKERROR(m_proxy);
  }

  void AddLazyConstr(const Expr& lhs, char sense, double rhs)
  {
    m_proxy->AddLazyConstr(lhs.Get(), sense, rhs);
    CHECKERROR(m_proxy);
  }
  void AddLazyConstr(const Expr& lhs, char sense, const Expr& rhs)
  {
    m_proxy->AddLazyConstr(lhs.Get(), sense, rhs.Get());
    CHECKERROR(m_proxy);
  }
  void AddLazyConstr(const ConstrBuilder& builder)
  {
    m_proxy->AddLazyConstr(builder.Get());
    CHECKERROR(m_proxy);
  }
  void AddLazyConstrs(const ConstrBuilderArray& builders)
  {
    m_proxy->AddLazyConstrs(builders.Get());
    CHECKERROR(m_proxy);
  }

  int GetIntInfo(const char* cbinfo)
  {
    int val = m_proxy->GetIntInfo(cbinfo);
    CHECKERROR(m_proxy);
    return val;
  }
  double GetDblInfo(const char* cbinfo)
  {
    double val = m_proxy->GetDblInfo(cbinfo);
    CHECKERROR(m_proxy);
    return val;
  }

  double GetIncumbent(const Var& var)
  {
    double sol = m_proxy->GetIncumbent(var.Get());
    CHECKERROR(m_proxy);
    return sol;
  }
  int GetIncumbent(const VarArray& vars, double* pOut)
  {
    int sz = m_proxy->GetIncumbent(vars.Get(), pOut);
    CHECKERROR(m_proxy);
    return sz;
  }
  int GetIncumbent(double* pOut, int len)
  {
    int sz = m_proxy->GetIncumbent(pOut, len);
    CHECKERROR(m_proxy);
    return sz;
  }
  double GetRelaxSol(const Var& var)
  {
    double sol = m_proxy->GetRelaxSol(var.Get());
    CHECKERROR(m_proxy);
    return sol;
  }
  int GetRelaxSol(const VarArray& vars, double* pOut)
  {
    int sz = m_proxy->GetRelaxSol(vars.Get(), pOut);
    CHECKERROR(m_proxy);
    return sz;
  }
  int GetRelaxSol(double* pOut, int len)
  {
    int sz = m_proxy->GetRelaxSol(pOut, len);
    CHECKERROR(m_proxy);
    return sz;
  }
  double GetSolution(const Var& var)
  {
    double sol = m_proxy->GetSolution(var.Get());
    CHECKERROR(m_proxy);
    return sol;
  }
  int GetSolution(const VarArray& vars, double* pOut)
  {
    int sz = m_proxy->GetSolution(vars.Get(), pOut);
    CHECKERROR(m_proxy);
    return sz;
  }
  int GetSolution(double* pOut, int len)
  {
    int sz = m_proxy->GetSolution(pOut, len);
    CHECKERROR(m_proxy);
    return sz;
  }

  void SetSolution(const Var& var, double val)
  {
    m_proxy->SetSolution(var.Get(), val);
    CHECKERROR(m_proxy);
  }
  void SetSolution(const VarArray& vars, const double* vals, int len)
  {
    m_proxy->SetSolution(vars.Get(), vals, len);
    CHECKERROR(m_proxy);
  }
  double LoadSolution()
  {
    double objval = m_proxy->LoadSolution();
    CHECKERROR(m_proxy);
    return objval;
  }

  int Where()
  {
    return m_proxy->Where();
  }

  Copt::ICallbackProxy* getProxy() const override
  {
    return &(*m_proxy);
  }

private:
  std::shared_ptr<Copt::ICallbackProxy> m_proxy;
};
