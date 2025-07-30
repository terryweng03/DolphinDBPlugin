#pragma once
#include <cmath>
#include "coptcpp.idl.h"
#include "vararray.h"
#include "var.h"
#include "expr.h"

class NlExpr;
class QConstrBuilder;

class QuadExpr {
public:
  QuadExpr(double constant = 0.0) : m_expr(CreateQuadExpr1(constant)) {}
  QuadExpr(const Var& var, double coeff = 1.0) : m_expr(CreateQuadExpr2(var.Get(), coeff)) {}
  QuadExpr(const Expr& expr) : m_expr(CreateQuadExpr3(expr.Get())) {}
  QuadExpr(const Expr& expr, const Var& var) : m_expr(CreateQuadExpr4(expr.Get(), var.Get())) {}
  QuadExpr(const Expr& left, const Expr& right) : m_expr(CreateQuadExpr5(left.Get(), right.Get())) {}
  QuadExpr(Copt::IQuadExpr* expr) : m_expr(expr) {}

  size_t Size() const
  {
    return m_expr->Size();
  }
  Var GetVar1(int i) const
  {
    return m_expr->GetVar1(i);
  }
  Var GetVar2(int i) const
  {
    return m_expr->GetVar2(i);
  }
  double GetCoeff(int i) const
  {
    return m_expr->GetCoeff(i);
  }
  double GetConstant() const
  {
    return m_expr->GetConstant();
  }
  Expr GetLinExpr() const
  {
    return m_expr->GetLinExpr();
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
  void AddTerm(const Var& var1, const Var& var2, double coeff = 1.0)
  {
    m_expr->AddTerm(var1.Get(), var2.Get(), coeff);
  }
  int AddTerms(const VarArray& vars, double* pCoeff, int len)
  {
    return m_expr->AddTerms(vars.Get(), pCoeff, len);
  }
  int AddTerms(const VarArray& vars1, const VarArray& vars2, double* pCoeff, int len)
  {
    return m_expr->AddTerms(vars1.Get(), vars2.Get(), pCoeff, len);
  }
  void AddLinExpr(const Expr& expr, double mult = 1.0)
  {
    m_expr->AddLinExpr(expr.Get(), mult);
  }
  void AddQuadExpr(const QuadExpr& expr, double mult = 1.0)
  {
    m_expr->AddQuadExpr(expr.Get(), mult);
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

  QuadExpr Clone() const
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
    AddLinExpr(expr, 1.0);
  }

  void operator+=(const QuadExpr& expr)
  {
    size_t sz = expr.Size();

    for (size_t i = 0; i < sz; i++)
    {
      AddTerm(expr.GetVar1(i), expr.GetVar2(i), expr.GetCoeff(i));
    }
    AddLinExpr(expr.GetLinExpr(), 1.0);
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
    AddLinExpr(expr, -1.0);
  }

  void operator-=(const QuadExpr& expr)
  {
    size_t sz = expr.Size();

    for (size_t i = 0; i < sz; i++)
    {
      AddTerm(expr.GetVar1(i), expr.GetVar2(i), 0.0 - expr.GetCoeff(i));
    }
    AddLinExpr(expr.GetLinExpr(), -1.0);
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

  QuadExpr operator/(double c)
  {
    QuadExpr ret = this->Clone();
    ret /= c;
    return ret;
  }

  QuadExpr operator*(double c)
  {
    QuadExpr ret = this->Clone();
    ret *= c;
    return ret;
  }

  friend QuadExpr operator+(const QuadExpr& left, double c)
  {
    QuadExpr ret = left.Clone();
    ret.AddConstant(c);
    return ret;
  }

  friend QuadExpr operator+(double c, const QuadExpr& right)
  {
    QuadExpr ret = right.Clone();
    ret.AddConstant(c);
    return ret;
  }

  friend QuadExpr operator+(const QuadExpr& left, const Var& var)
  {
    QuadExpr ret = left.Clone();
    ret.AddTerm(var, 1.0);
    return ret;
  }

  friend QuadExpr operator+(const Var& var, const QuadExpr& right)
  {
    QuadExpr ret = right.Clone();
    ret.AddTerm(var, 1.0);
    return ret;
  }

  friend QuadExpr operator+(const QuadExpr& left, const Expr& right)
  {
    QuadExpr ret = left.Clone();
    ret += right;
    return ret;
  }

  friend QuadExpr operator+(const Expr& left, const QuadExpr& right)
  {
    QuadExpr ret = right.Clone();
    ret += left;
    return ret;
  }

  friend QuadExpr operator+(const QuadExpr& left, const QuadExpr& right)
  {
    QuadExpr ret = left.Clone();
    ret += right;
    return ret;
  }

  friend QuadExpr operator-(const QuadExpr& left, double c)
  {
    QuadExpr ret = left.Clone();
    ret.AddConstant(-c);
    return ret;
  }

  friend QuadExpr operator-(double c, const QuadExpr& right)
  {
    QuadExpr ret = right.Clone();
    ret *= -1.0;
    ret.AddConstant(c);
    return ret;
  }

  friend QuadExpr operator-(const QuadExpr& expr)
  {
    return 0.0 - expr;
  }

  friend QuadExpr operator-(const QuadExpr& left, const Var& var)
  {
    QuadExpr ret = left.Clone();
    ret.AddTerm(var, -1.0);
    return ret;
  }

  friend QuadExpr operator-(const Var& var, const QuadExpr& right)
  {
    QuadExpr ret = right.Clone();
    ret *= -1.0;
    ret.AddTerm(var, 1.0);
    return ret;
  }

  friend QuadExpr operator-(const QuadExpr& left, const Expr& right)
  {
    QuadExpr ret = left.Clone();
    ret -= right;
    return ret;
  }

  friend QuadExpr operator-(const Expr& left, const QuadExpr& right)
  {
    QuadExpr ret = right.Clone();
    ret -= left;
    return ret;
  }

  friend QuadExpr operator-(const QuadExpr& left, const QuadExpr& right)
  {
    QuadExpr ret = left.Clone();
    ret -= right;
    return ret;
  }

  friend QuadExpr operator*(double c, const QuadExpr& expr)
  {
    QuadExpr ret = expr.Clone();
    ret *= c;
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& out, const QuadExpr& expr)
  {
    out << expr.Represent();
    return out;
  }

  friend NlExpr operator*(const Var& var, const QuadExpr& expr);
  friend NlExpr operator*(const QuadExpr& expr, const Var& var);
  friend NlExpr operator*(const Expr& left, const QuadExpr& right);
  friend NlExpr operator*(const QuadExpr& left, const Expr& right);
  friend NlExpr operator*(const QuadExpr& left, const QuadExpr& right);

  friend NlExpr operator/(double a, const QuadExpr& right);
  friend NlExpr operator/(const Var& var, const QuadExpr& expr);
  friend NlExpr operator/(const QuadExpr& expr, const Var& var);
  friend NlExpr operator/(const Expr& left, const QuadExpr& right);
  friend NlExpr operator/(const QuadExpr& left, const Expr& right);
  friend NlExpr operator/(const QuadExpr& left, const QuadExpr& right);

  friend QConstrBuilder operator>=(const QuadExpr& left, const QuadExpr& right);
  friend QConstrBuilder operator>=(const QuadExpr& left, const Expr& right);
  friend QConstrBuilder operator>=(const Expr& left, const QuadExpr& right);
  friend QConstrBuilder operator>=(const QuadExpr& left, const Var& var);
  friend QConstrBuilder operator>=(const Var& var, const QuadExpr& right);
  friend QConstrBuilder operator>=(const QuadExpr& left, double c);
  friend QConstrBuilder operator>=(double c, const QuadExpr& right);
  friend QConstrBuilder operator<=(const QuadExpr& left, const QuadExpr& right);
  friend QConstrBuilder operator<=(const QuadExpr& left, const Expr& expr);
  friend QConstrBuilder operator<=(const Expr& expr, const QuadExpr& right);
  friend QConstrBuilder operator<=(const QuadExpr& left, const Var& var);
  friend QConstrBuilder operator<=(const Var& var, const QuadExpr& right);
  friend QConstrBuilder operator<=(const QuadExpr& left, double c);
  friend QConstrBuilder operator<=(double c, const QuadExpr& right);
  friend QConstrBuilder operator==(const QuadExpr& left, const QuadExpr& right);
  friend QConstrBuilder operator==(const QuadExpr& left, const Expr& expr);
  friend QConstrBuilder operator==(const Expr& expr, const QuadExpr& right);
  friend QConstrBuilder operator==(const QuadExpr& left, const Var& var);
  friend QConstrBuilder operator==(const Var& var, const QuadExpr& right);
  friend QConstrBuilder operator==(const QuadExpr& left, double c);
  friend QConstrBuilder operator==(double c, const QuadExpr& right);

  Copt::IQuadExpr* Get() const
  {
    return &(*m_expr);
  }

private:
  std::shared_ptr<Copt::IQuadExpr> m_expr;
};
