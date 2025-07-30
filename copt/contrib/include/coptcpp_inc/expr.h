#pragma once
#include <cmath>
#include <iostream>
#include "coptcpp.idl.h"
#include "vararray.h"
#include "var.h"

class ConstrBuilder;
class NlExpr;
class QuadExpr;

class Expr {
public:
  Expr(double constant = 0.0) : m_expr(CreateExpr(constant)) {}
  Expr(const Var& var, double coeff = 1.0) : m_expr(CreateLinExpr(var.Get(), coeff)) {}
  Expr(Copt::IExpr* expr) : m_expr(expr) {}

  size_t Size() const
  {
    return m_expr->Size();
  }
  Var GetVar(int i) const
  {
    return m_expr->GetVar(i);
  }
  double GetCoeff(int i) const
  {
    return m_expr->GetCoeff(i);
  }
  double GetConstant() const
  {
    return m_expr->GetConstant();
  }

  void SetCoeff(int i, double value)
  {
    m_expr->SetCoeff(i, value);
  }
  void SetConstant(double constant)
  {
    m_expr->SetConstant(constant);
  }
  void AddConstant(double constant)
  {
    m_expr->AddConstant(constant);
  }

  void AddTerm(const Var& var, double coeff = 1.0)
  {
    m_expr->AddTerm(var.Get(), coeff);
  }
  int AddTerms(const VarArray& vars, double* pCoeff, int len)
  {
    return m_expr->AddTerms(vars.Get(), pCoeff, len);
  }
  void AddExpr(const Expr& expr, double mult = 1.0)
  {
    m_expr->AddExpr(expr.Get(), mult);
  }

  double Evaluate() const
  {
    double val = m_expr->Evaluate();
    CHECKERROR(m_expr);
    return val;
  }

  void Remove(int idx)
  {
    m_expr->Remove(idx);
  }
  void Remove(const Var& var)
  {
    m_expr->Remove(var.Get());
  }

  void Clear()
  {
    return m_expr->Clear();
  }

  Expr Clone() const
  {
    return m_expr->Clone();
  }

  void Reserve(size_t n)
  {
    m_expr->Reserve(n);
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_expr->Represent(maxlen);
  }

  void operator+=(double c)
  {
    m_expr->AddConstant(c);
  }

  void operator+=(const Var& var)
  {
    m_expr->AddTerm(var.Get(), 1.0);
  }

  void operator+=(const Expr& expr)
  {
    for (size_t i = 0; i < expr.Size(); i++)
    {
      m_expr->AddTerm(expr.GetVar(i).Get(), expr.GetCoeff(i));
    }
    m_expr->AddConstant(expr.GetConstant());
  }

  void operator-=(double c)
  {
    m_expr->AddConstant(-c);
  }

  void operator-=(const Var& var)
  {
    m_expr->AddTerm(var.Get(), -1.0);
  }

  void operator-=(const Expr& expr)
  {
    for (size_t i = 0; i < expr.Size(); i++)
    {
      m_expr->AddTerm(expr.GetVar(i).Get(), -expr.GetCoeff(i));
    }
    m_expr->AddConstant(-expr.GetConstant());
  }

  void operator/=(double c)
  {
    m_expr->iDivide(c);
    CHECKERROR(m_expr);
  }

  void operator*=(double c)
  {
    m_expr->iMultiply(c);
  }

  Expr operator/(double c)
  {
    Expr ret = this->Clone();
    ret /= c;
    return ret;
  }

  Expr operator*(double c)
  {
    Expr ret = this->Clone();
    ret *= c;
    return ret;
  }

  friend Expr operator+(const Expr& left, double c)
  {
    Expr ret = left.Clone();
    ret.AddConstant(c);
    return ret;
  }

  friend Expr operator+(double c, const Expr& right)
  {
    Expr ret = right.Clone();
    ret.AddConstant(c);
    return ret;
  }

  friend Expr operator+(const Expr& left, const Var& var)
  {
    Expr ret = left.Clone();
    ret.AddTerm(var, 1.0);
    return ret;
  }

  friend Expr operator+(const Var& var, const Expr& right)
  {
    Expr ret = right.Clone();
    ret.AddTerm(var, 1.0);
    return ret;
  }

  friend Expr operator+(const Expr& left, const Expr& right)
  {
    Expr ret = left.Clone();
    ret += right;
    return ret;
  }

  friend Expr operator-(const Expr& left, double c)
  {
    Expr ret = left.Clone();
    ret.AddConstant(-c);
    return ret;
  }

  friend Expr operator-(double c, const Expr& right)
  {
    Expr ret = right.Clone();
    ret *= -1.0;
    ret.AddConstant(c);
    return ret;
  }

  friend Expr operator-(const Expr& expr)
  {
    return 0.0 - expr;
  }

  friend Expr operator-(const Expr& left, const Var& var)
  {
    Expr ret = left.Clone();
    ret.AddTerm(var, -1.0);
    return ret;
  }

  friend Expr operator-(const Var& var, const Expr& right)
  {
    Expr ret = right.Clone();
    ret *= -1.0;
    ret.AddTerm(var, 1.0);
    return ret;
  }

  friend Expr operator-(const Expr& left, const Expr& right)
  {
    Expr ret = left.Clone();
    ret -= right;
    return ret;
  }

  friend Expr operator*(double c, const Expr& expr)
  {
    Expr ret = expr.Clone();
    ret *= c;
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& out, const Expr& expr)
  {
    out << expr.Represent();
    return out;
  }

  friend QuadExpr operator*(const Expr& expr, const Var& var);
  friend QuadExpr operator*(const Var& var, const Expr& expr);
  friend QuadExpr operator*(const Expr& left, const Expr& right);

  friend NlExpr operator/(double c, const Expr& expr);
  friend NlExpr operator/(const Var& var, const Expr& expr);
  friend NlExpr operator/(const Expr& expr, const Var& var);
  friend NlExpr operator/(const Expr& left, const Expr& right);

  friend ConstrBuilder operator>=(const Expr& left, const Expr& right);
  friend ConstrBuilder operator>=(const Expr& left, const Var& var);
  friend ConstrBuilder operator>=(const Var& var, const Expr& right);
  friend ConstrBuilder operator>=(const Expr& left, double c);
  friend ConstrBuilder operator>=(double c, const Expr& right);
  friend ConstrBuilder operator<=(const Expr& left, const Expr& right);
  friend ConstrBuilder operator<=(const Expr& left, const Var& var);
  friend ConstrBuilder operator<=(const Var& var, const Expr& right);
  friend ConstrBuilder operator<=(const Expr& left, double c);
  friend ConstrBuilder operator<=(double c, const Expr& right);
  friend ConstrBuilder operator==(const Expr& left, const Expr& right);
  friend ConstrBuilder operator==(const Expr& left, const Var& var);
  friend ConstrBuilder operator==(const Var& var, const Expr& right);
  friend ConstrBuilder operator==(const Expr& left, double c);
  friend ConstrBuilder operator==(double c, const Expr& right);

  Copt::IExpr* Get() const
  {
    return &(*m_expr);
  }

private:
  std::shared_ptr<Copt::IExpr> m_expr;
};
