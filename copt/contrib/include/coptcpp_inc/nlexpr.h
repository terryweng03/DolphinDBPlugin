#pragma once
#include <cmath>
#include <iostream>
#include "coptcpp.idl.h"
#include "expr.h"
#include "quadexpr.h"

class NlConstrBuilder;

class NlExpr {
public:
  NlExpr(double constant = 0.0) : m_expr(CreateNlExpr1(constant)) {}
  NlExpr(const Var& var, double coeff = 1.0) : m_expr(CreateNlExpr2(var.Get(), coeff)) {}
  NlExpr(const Expr& expr) : m_expr(CreateNlExpr3(expr.Get())) {}
  NlExpr(const QuadExpr& expr) : m_expr(CreateNlExpr4(expr.Get())) {}

  NlExpr(Copt::INlExpr* expr) : m_expr(expr) {}

  size_t Size() const
  {
    return m_expr->Size();
  }
  double GetConstant() const
  {
    return m_expr->GetConstant();
  }
  Expr GetLinExpr() const
  {
    return m_expr->GetLinExpr();
  }

  void AddConstant(double constant)
  {
    m_expr->AddConstant(constant);
  }
  void SetConstant(double constant)
  {
    m_expr->SetConstant(constant);
  }

  void AddTerm(const Var& var, double coeff = 1.0)
  {
    m_expr->AddTerm(var.Get(), coeff);
  }
  int AddTerms(const VarArray& vars, double* pCoeff, int len)
  {
    return m_expr->AddTerms(vars.Get(), pCoeff, len);
  }
  void AddLinExpr(const Expr& expr, double mult = 1.0)
  {
    m_expr->AddLinExpr(expr.Get(), mult);
  }
  void AddQuadExpr(const QuadExpr& expr, double mult = 1.0)
  {
    m_expr->AddQuadExpr(expr.Get(), mult);
  }
  void AddNlExpr(const NlExpr& expr, double mult = 1.0)
  {
    m_expr->AddNlExpr(expr.Get(), mult);
  }

  void Clear()
  {
    m_expr->Clear();
  }

  NlExpr Clone() const
  {
    return m_expr->Clone();
  }

  double Evaluate() const
  {
    return m_expr->Evaluate();
  }

  void Negate()
  {
    m_expr->Negate();
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
    m_expr->AddLinExpr(expr.Get(), 1.0);
  }

  void operator+=(const QuadExpr& expr)
  {
    m_expr->AddQuadExpr(expr.Get(), 1.0);
  }

  void operator+=(const NlExpr& expr)
  {
    m_expr->AddNlExpr(expr.Get(), 1.0);
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
    m_expr->AddLinExpr(expr.Get(), -1.0);
  }

  void operator-=(const QuadExpr& expr)
  {
    m_expr->AddQuadExpr(expr.Get(), -1.0);
  }

  void operator-=(const NlExpr& expr)
  {
    m_expr->AddNlExpr(expr.Get(), -1.0);
  }

  void operator*=(double c)
  {
    m_expr->iMultiply(c);
  }

  void operator*=(const Var& var)
  {
    m_expr->iMultiply(var.Get());
    CHECKERROR(m_expr);
  }

  void operator*=(const Expr& expr)
  {
    m_expr->iMultiply(expr.Get());
  }

  void operator*=(const QuadExpr& expr)
  {
    m_expr->iMultiply(expr.Get());
  }

  void operator*=(const NlExpr& expr)
  {
    m_expr->iMultiply(expr.Get());
  }

  void operator/=(double c)
  {
    m_expr->iDivide(c);
    CHECKERROR(m_expr);
  }

  void operator/=(const Var& var)
  {
    m_expr->iDivide(var.Get());
    CHECKERROR(m_expr);
  }

  void operator/=(const Expr& expr)
  {
    m_expr->iDivide(expr.Get());
    CHECKERROR(m_expr);
  }

  void operator/=(const QuadExpr& expr)
  {
    m_expr->iDivide(expr.Get());
    CHECKERROR(m_expr);
  }

  void operator/=(const NlExpr& expr)
  {
    m_expr->iDivide(expr.Get());
    CHECKERROR(m_expr);
  }

  // operator plus
  NlExpr operator+(const NlExpr& other) const
  {
    NlExpr ret = this->Clone();
    ret += other;
    return ret;
  }

  NlExpr operator+(const QuadExpr& other) const
  {
    NlExpr ret = this->Clone();
    ret += other;
    return ret;
  }

  NlExpr operator+(const Expr& other) const
  {
    NlExpr ret = this->Clone();
    ret += other;
    return ret;
  }

  NlExpr operator+(const Var& other) const
  {
    NlExpr ret = this->Clone();
    ret += other;
    return ret;
  }

  NlExpr operator+(double c) const
  {
    NlExpr ret = this->Clone();
    ret += c;
    return ret;
  }

  // operator minus
  NlExpr operator-(const NlExpr& other) const
  {
    NlExpr ret = this->Clone();
    ret -= other;
    return ret;
  }

  NlExpr operator-(const QuadExpr& other) const
  {
    NlExpr ret = this->Clone();
    ret -= other;
    return ret;
  }

  NlExpr operator-(const Expr& other) const
  {
    NlExpr ret = this->Clone();
    ret -= other;
    return ret;
  }

  NlExpr operator-(const Var& other) const
  {
    NlExpr ret = this->Clone();
    ret -= other;
    return ret;
  }

  NlExpr operator-(double c) const
  {
    NlExpr ret = this->Clone();
    ret -= c;
    return ret;
  }

  // operator multiply
  NlExpr operator*(const NlExpr& other) const
  {
    NlExpr ret = this->Clone();
    ret *= other;
    return ret;
  }

  NlExpr operator*(const QuadExpr& other) const
  {
    NlExpr ret = this->Clone();
    ret *= other;
    return ret;
  }

  NlExpr operator*(const Expr& other) const
  {
    NlExpr ret = this->Clone();
    ret *= other;
    return ret;
  }

  NlExpr operator*(const Var& other) const
  {
    NlExpr ret = this->Clone();
    ret *= other;
    return ret;
  }

  NlExpr operator*(double c) const
  {
    NlExpr ret = this->Clone();
    ret *= c;
    return ret;
  }

  // operator divide
  NlExpr operator/(const NlExpr& other) const
  {
    NlExpr ret = this->Clone();
    ret /= other;
    return ret;
  }

  NlExpr operator/(const QuadExpr& other) const
  {
    NlExpr ret = this->Clone();
    ret /= other;
    return ret;
  }

  NlExpr operator/(const Expr& other) const
  {
    NlExpr ret = this->Clone();
    ret /= other;
    return ret;
  }

  NlExpr operator/(const Var& other) const
  {
    NlExpr ret = this->Clone();
    ret /= other;
    return ret;
  }

  NlExpr operator/(double c) const
  {
    NlExpr ret = this->Clone();
    ret /= c;
    return ret;
  }

  // friend operator overloading plus
  friend NlExpr operator+(const QuadExpr& expr, const NlExpr& other)
  {
    NlExpr ret(expr);
    ret += other;
    return ret;
  }

  friend NlExpr operator+(const Expr& expr, const NlExpr& other)
  {
    NlExpr ret(expr);
    ret += other;
    return ret;
  }

  friend NlExpr operator+(const Var& var, const NlExpr& other)
  {
    NlExpr ret(var);
    ret += other;
    return ret;
  }

  friend NlExpr operator+(double c, const NlExpr& other)
  {
    NlExpr ret(c);
    ret += other;
    return ret;
  }

  // friend operator overloading minus
  friend NlExpr operator-(const QuadExpr& expr, const NlExpr& other)
  {
    NlExpr ret(expr);
    ret -= other;
    return ret;
  }

  friend NlExpr operator-(const Expr& expr, const NlExpr& other)
  {
    NlExpr ret(expr);
    ret -= other;
    return ret;
  }

  friend NlExpr operator-(const Var& var, const NlExpr& other)
  {
    NlExpr ret(var);
    ret -= other;
    return ret;
  }

  friend NlExpr operator-(double c, const NlExpr& other)
  {
    NlExpr ret(c);
    ret -= other;
    return ret;
  }

  friend NlExpr operator-(const NlExpr& expr)
  {
    NlExpr ret(expr);
    ret.Negate();
    return ret;
  }

  // friend operator overloading multiply
  friend NlExpr operator*(const QuadExpr& qexpr, const NlExpr& other)
  {
    NlExpr ret(qexpr);
    ret *= other;
    return ret;
  }

  friend NlExpr operator*(const Expr& expr, const NlExpr& other)
  {
    NlExpr ret(expr);
    ret *= other;
    return ret;
  }

  friend NlExpr operator*(const Var& var, const NlExpr& other)
  {
    NlExpr ret(var);
    ret *= other;
    return ret;
  }

  friend NlExpr operator*(double c, const NlExpr& other)
  {
    NlExpr ret(c);
    ret *= other;
    return ret;
  }

  // friend operator overloading divide
  friend NlExpr operator/(const QuadExpr& qexpr, const NlExpr& other)
  {
    NlExpr ret(qexpr);
    ret /= other;
    return ret;
  }

  friend NlExpr operator/(const Expr& expr, const NlExpr& other)
  {
    NlExpr ret(expr);
    ret /= other;
    return ret;
  }

  friend NlExpr operator/(const Var& var, const NlExpr& other)
  {
    NlExpr ret(var);
    ret /= other;
    return ret;
  }

  friend NlExpr operator/(double c, const NlExpr& other)
  {
    NlExpr ret(c);
    ret /= other;
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& out, const NlExpr& expr)
  {
    out << expr.Represent();
    return out;
  }

  friend NlConstrBuilder operator>=(const NlExpr& left, const NlExpr& right);
  friend NlConstrBuilder operator>=(const NlExpr& left, const QuadExpr& right);
  friend NlConstrBuilder operator>=(const NlExpr& left, const Expr& right);
  friend NlConstrBuilder operator>=(const NlExpr& left, const Var& right);
  friend NlConstrBuilder operator>=(const NlExpr& left, double a);
  friend NlConstrBuilder operator>=(double a, const NlExpr& left);
  friend NlConstrBuilder operator>=(const Var& left, const NlExpr& right);
  friend NlConstrBuilder operator>=(const Expr& left, const NlExpr& right);
  friend NlConstrBuilder operator>=(const QuadExpr& left, const NlExpr& right);

  friend NlConstrBuilder operator<=(const NlExpr& left, const NlExpr& right);
  friend NlConstrBuilder operator<=(const NlExpr& left, const QuadExpr& right);
  friend NlConstrBuilder operator<=(const NlExpr& left, const Expr& right);
  friend NlConstrBuilder operator<=(const NlExpr& left, const Var& right);
  friend NlConstrBuilder operator<=(const NlExpr& left, double a);
  friend NlConstrBuilder operator<=(double a, const NlExpr& left);
  friend NlConstrBuilder operator<=(const Var& left, const NlExpr& right);
  friend NlConstrBuilder operator<=(const Expr& left, const NlExpr& right);
  friend NlConstrBuilder operator<=(const QuadExpr& left, const NlExpr& right);

  friend NlConstrBuilder operator==(const NlExpr& left, const NlExpr& right);
  friend NlConstrBuilder operator==(const NlExpr& left, const QuadExpr& right);
  friend NlConstrBuilder operator==(const NlExpr& left, const Expr& right);
  friend NlConstrBuilder operator==(const NlExpr& left, const Var& right);
  friend NlConstrBuilder operator==(const NlExpr& left, double a);
  friend NlConstrBuilder operator==(double a, const NlExpr& left);
  friend NlConstrBuilder operator==(const Var& left, const NlExpr& right);
  friend NlConstrBuilder operator==(const Expr& left, const NlExpr& right);
  friend NlConstrBuilder operator==(const QuadExpr& left, const NlExpr& right);

  Copt::INlExpr* Get() const
  {
    return &(*m_expr);
  }

private:
  std::shared_ptr<Copt::INlExpr> m_expr;
};
