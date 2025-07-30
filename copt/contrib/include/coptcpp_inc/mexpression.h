#pragma once
#include "coptcpp.idl.h"
#include "expr.h"
#include "mfactory.h"

class MExpression {
public:
  MExpression(double constant = 0.0) : m_expr(MFactory::Get().CreateMExpression(constant)) {}
  MExpression(const Var& var) : m_expr(MFactory::Get().CreateMExpression(Expr(var).Get())) {}
  MExpression(const Expr& expr) : m_expr(MFactory::Get().CreateMExpression(expr.Get())) {}

  MExpression(Copt::IMExpression* expr) : m_expr(expr) {}

  double GetConstant() const
  {
    return m_expr->GetConstant();
  }

  void AddConstant(double constant)
  {
    m_expr->AddConstant(constant);
  }

  void SetConstant(double constant)
  {
    m_expr->SetConstant(constant);
  }

  void AddTerm(const Var& var, double coeff)
  {
    m_expr->AddTerm(var.Get(), coeff);
  }

  void AddExpr(const Expr& expr, double mult = 1.0)
  {
    m_expr->AddExpr(expr.Get(), mult);
  }

  void AddMExpr(const MExpression& expr, double mult = 1.0)
  {
    m_expr->AddMExpr(expr.Get(), mult);
  }

  MExpression Clone() const
  {
    return m_expr->Clone();
  }

  double Evaluate() const
  {
    double val = m_expr->Evaluate();
    CHECKERROR(m_expr);
    return val;
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_expr->Represent(maxlen);
  }

  void operator*=(double c)
  {
    m_expr->iMultiply(c);
  }

  friend std::ostream& operator<<(std::ostream& out, const MExpression& expr)
  {
    out << expr.Represent();
    return out;
  }

  Copt::IMExpression* Get() const
  {
    return &(*m_expr);
  }

private:
  std::shared_ptr<Copt::IMExpression> m_expr;
};
