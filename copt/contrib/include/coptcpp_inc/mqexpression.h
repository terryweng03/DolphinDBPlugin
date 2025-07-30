#pragma once
#include "coptcpp.idl.h"
#include "quadexpr.h"
#include "mfactory.h"
#include "var.h"
#include "mexpression.h"

class MQExpression {
public:
  MQExpression(double constant = 0.0) : m_qexpr(MFactory::Get().CreateMQExpression(constant)) {}
  MQExpression(const QuadExpr& expr) : m_qexpr(MFactory::Get().CreateMQExpression(expr.Get())) {}

  MQExpression(Copt::IMQExpression* expr) : m_qexpr(expr) {}

  double GetConstant() const
  {
    return m_qexpr->GetConstant();
  }

  void AddConstant(double constant)
  {
    m_qexpr->AddConstant(constant);
  }

  void AddTerm(const Var& var, double coeff)
  {
    m_qexpr->AddTerm(var.Get(), coeff);
  }

  void AddTerm(const Var& var1, const Var& var2, double coeff)
  {
    m_qexpr->AddTerm(var1.Get(), var2.Get(), coeff);
  }

  void AddExpr(const Expr& expr, double mult = 1.0)
  {
    m_qexpr->AddExpr(expr.Get(), mult);
  }

  void AddMExpr(const MExpression& expr, double mult = 1.0)
  {
    m_qexpr->AddMExpr(expr.Get(), mult);
  }

  void AddQuadExpr(const QuadExpr& qexpr, double mult = 1.0)
  {
    m_qexpr->AddQuadExpr(qexpr.Get(), mult);
  }

  void AddQuadExpr(const MExpression& expr, const Var& var)
  {
    m_qexpr->AddQuadExpr(expr.Get(), var.Get());
  }

  void AddQuadExpr(const MExpression& left, const Expr& right)
  {
    m_qexpr->AddQuadExpr(left.Get(), right.Get());
  }

  void AddQuadExpr(const MExpression& left, const MExpression& right)
  {
    m_qexpr->AddQuadExpr(left.Get(), right.Get());
  }

  void AddMQExpr(const MQExpression& qexpr, double mult = 1.0)
  {
    m_qexpr->AddMQExpr(qexpr.Get(), mult);
  }

  MQExpression Clone() const
  {
    return m_qexpr->Clone();
  }

  double Evaluate() const
  {
    double val = m_qexpr->Evaluate();
    CHECKERROR(m_qexpr);
    return val;
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_qexpr->Represent(maxlen);
  }

  void operator*=(double c)
  {
    m_qexpr->iMultiply(c);
  }

  friend std::ostream& operator<<(std::ostream& out, const MQExpression& qexpr)
  {
    out << qexpr.Represent();
    return out;
  }

  Copt::IMQExpression* Get() const
  {
    return &(*m_qexpr);
  }

private:
  std::shared_ptr<Copt::IMQExpression> m_qexpr;
};
