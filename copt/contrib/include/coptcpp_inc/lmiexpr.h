#pragma once
#include <cmath>
#include "coptcpp.idl.h"
#include "expr.h"
#include "symmatexpr.h"
#include "symmatrix.h"
#include "symmatrixarray.h"

class LmiConstrBuilder;

class LmiExpr {
public:
  LmiExpr() : m_expr(CreateLmiExpr1()) {}
  LmiExpr(const SymMatrix& mat) : m_expr(CreateLmiExpr2(mat.Get())) {}
  LmiExpr(const SymMatExpr& expr) : m_expr(CreateLmiExpr3(expr.Get())) {}
  LmiExpr(const Var& var, const SymMatrix& mat) : m_expr(CreateLmiExpr4(var.Get(), mat.Get())) {}
  LmiExpr(const Var& var, const SymMatExpr& expr) : m_expr(CreateLmiExpr5(var.Get(), expr.Get())) {}
  LmiExpr(Copt::ILmiExpr* expr) : m_expr(expr) {}

  size_t Size() const
  {
    return m_expr->Size();
  }
  Var GetVar(int i) const
  {
    return m_expr->GetVar(i);
  }
  SymMatExpr GetCoeff(int i) const
  {
    return m_expr->GetCoeff(i);
  }
  SymMatExpr GetConstant() const
  {
    return m_expr->GetConstant();
  }

  void SetCoeff(int i, const SymMatrix& mat)
  {
    m_expr->SetCoeff(i, mat.Get());
  }
  void SetConstant(const SymMatrix& mat)
  {
    m_expr->SetConstant(mat.Get());
  }
  void AddConstant(const SymMatExpr& expr)
  {
    m_expr->AddConstant(expr.Get());
  }

  void AddTerm(const Var& var, const SymMatrix& mat)
  {
    m_expr->AddTerm(var.Get(), mat.Get());
  }
  void AddTerm(const Var& var, const SymMatExpr& expr)
  {
    m_expr->AddTerm(var.Get(), expr.Get());
  }
  int AddTerms(const VarArray& vars, const SymMatrixArray& mats)
  {
    return m_expr->AddTerms(vars.Get(), mats.Get());
  }
  void AddLmiExpr(const LmiExpr& expr, double mult = 1.0)
  {
    m_expr->AddLmiExpr(expr.Get(), mult);
  }

  void Remove(int idx)
  {
    m_expr->Remove(idx);
  }
  void Remove(const Var& var)
  {
    m_expr->Remove(var.Get());
  }
  void Reserve(size_t n)
  {
    m_expr->Reserve(n);
  }
  LmiExpr Clone() const
  {
    return m_expr->Clone();
  }

  void operator+=(const SymMatrix& mat)
  {
    m_expr->AddConstant(SymMatExpr(mat).Get());
  }

  void operator+=(const SymMatExpr& expr)
  {
    m_expr->AddConstant(expr.Get());
  }

  void operator+=(const LmiExpr& expr)
  {
    m_expr->AddLmiExpr(expr.Get(), 1.0);
  }

  void operator-=(const SymMatrix& mat)
  {
    m_expr->AddConstant((mat * (-1.0)).Get());
  }

  void operator-=(const SymMatExpr& expr)
  {
    m_expr->AddConstant((-expr).Get());
  }

  void operator-=(const LmiExpr& expr)
  {
    m_expr->AddLmiExpr(expr.Get(), -1.0);
  }

  void operator*=(double c)
  {
    m_expr->iMultiply(c);
  }

  friend LmiExpr operator+(const LmiExpr& left, const SymMatrix& mat)
  {
    LmiExpr ret = left.Clone();
    ret.AddConstant(mat);
    return ret;
  }

  friend LmiExpr operator+(const SymMatrix& mat, const LmiExpr& right)
  {
    LmiExpr ret = right.Clone();
    ret.AddConstant(mat);
    return ret;
  }

  friend LmiExpr operator+(const LmiExpr& left, const SymMatExpr& expr)
  {
    LmiExpr ret = left.Clone();
    ret.AddConstant(expr);
    return ret;
  }

  friend LmiExpr operator+(const SymMatExpr& expr, const LmiExpr& right)
  {
    LmiExpr ret = right.Clone();
    ret.AddConstant(expr);
    return ret;
  }

  friend LmiExpr operator+(const LmiExpr& left, const LmiExpr& right)
  {
    LmiExpr ret = left.Clone();
    ret += right;
    return ret;
  }

  friend LmiExpr operator-(const LmiExpr& left, const SymMatrix& mat)
  {
    LmiExpr ret = left.Clone();
    ret -= mat;
    return ret;
  }

  friend LmiExpr operator-(const SymMatrix& mat, const LmiExpr& right)
  {
    LmiExpr ret = right.Clone();
    ret *= -1.0;
    ret += mat;
    return ret;
  }

  friend LmiExpr operator-(const LmiExpr& left, const SymMatExpr& expr)
  {
    LmiExpr ret = left.Clone();
    ret -= expr;
    return ret;
  }

  friend LmiExpr operator-(const SymMatExpr& expr, const LmiExpr& right)
  {
    LmiExpr ret = right.Clone();
    ret *= -1.0;
    ret += expr;
    return ret;
  }

  friend LmiExpr operator-(const LmiExpr& expr)
  {
    return expr * (-1.0);
  }

  friend LmiExpr operator-(const LmiExpr& left, const LmiExpr& right)
  {
    LmiExpr ret = left.Clone();
    ret -= right;
    return ret;
  }

  friend LmiExpr operator*(const LmiExpr& expr, double c)
  {
    LmiExpr ret = expr.Clone();
    ret *= c;
    return ret;
  }

  friend LmiExpr operator*(double c, const LmiExpr& expr)
  {
    LmiExpr ret = expr.Clone();
    ret *= c;
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& out, const LmiExpr& expr)
  {
    out << expr.GetConstant();

    for (size_t i = 0; i < expr.Size(); i++)
    {
      if (expr.GetVar(i).GetIdx() < 0)
      {
        continue;
      }

      out << " +  (" << expr.GetCoeff(i) << ")";
      out << " * " << expr.GetVar(i).GetName();
    }

    return out;
  }

  const Copt::ILmiExpr* Get() const
  {
    return &(*m_expr);
  }

private:
  std::shared_ptr<Copt::ILmiExpr> m_expr;
};
