#pragma once
#include <cmath>
#include "coptcpp.idl.h"
#include "mexpression.h"
#include "psdvararray.h"
#include "psdvar.h"
#include "symmatexpr.h"
#include "symmatrix.h"
#include "symmatrixarray.h"

class PsdConstrBuilder;

// This client implemented class showing how to wrapper PSD expr class from copt cpp dll
class PsdExpr {
public:
  PsdExpr(double constant = 0.0) : m_expr(CreatePsdExpr1(constant)) {}
  PsdExpr(const Var& var, double coeff = 1.0) : m_expr(CreatePsdExpr2(var.Get(), coeff)) {}
  PsdExpr(const Expr& expr) : m_expr(CreatePsdExpr3(expr.Get())) {}
  PsdExpr(const MExpression& expr) : m_expr(CreatePsdExpr6(expr.Get())) {}
  PsdExpr(const PsdVar& var, const SymMatrix& mat) : m_expr(CreatePsdExpr4(var.Get(), mat.Get())) {}
  PsdExpr(const PsdVar& var, const SymMatExpr& expr) : m_expr(CreatePsdExpr5(var.Get(), expr.Get())) {}
  PsdExpr(Copt::IPsdExpr* expr) : m_expr(expr) {}

  size_t Size() const
  {
    return m_expr->Size();
  }
  PsdVar GetPsdVar(int i) const
  {
    return m_expr->GetPsdVar(i);
  }
  SymMatExpr GetCoeff(int i) const
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

  void SetCoeff(int i, const SymMatrix& mat)
  {
    m_expr->SetCoeff(i, mat.Get());
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
  void AddTerm(const PsdVar& var, const SymMatrix& mat)
  {
    m_expr->AddTerm(var.Get(), mat.Get());
  }
  void AddTerm(const PsdVar& var, const SymMatExpr& expr)
  {
    m_expr->AddTerm(var.Get(), expr.Get());
  }
  int AddTerms(const VarArray& vars, double* pCoeff, int len)
  {
    return m_expr->AddTerms(vars.Get(), pCoeff, len);
  }
  int AddTerms(const PsdVarArray& vars, const SymMatrixArray& mats)
  {
    return m_expr->AddTerms(vars.Get(), mats.Get());
  }
  void AddLinExpr(const Expr& expr, double mult = 1.0)
  {
    m_expr->AddLinExpr(expr.Get(), mult);
  }
  void AddPsdExpr(const PsdExpr& expr, double mult = 1.0)
  {
    m_expr->AddPsdExpr(expr.Get(), mult);
  }
  void AddMExpr(const MExpression& expr, double mult = 1.0)
  {
    m_expr->AddMExpr(expr.Get(), mult);
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
  void Remove(const PsdVar& var)
  {
    m_expr->Remove(var.Get());
  }
  void Reserve(size_t n)
  {
    m_expr->Reserve(n);
  }
  PsdExpr Clone() const
  {
    return m_expr->Clone();
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

  void operator+=(const PsdExpr& expr)
  {
    size_t sz = expr.Size();

    for (size_t i = 0; i < sz; i++)
    {
      AddTerm(expr.GetPsdVar(i), expr.GetCoeff(i));
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

  void operator-=(const PsdExpr& expr)
  {
    size_t sz = expr.Size();

    for (size_t i = 0; i < sz; i++)
    {
      AddTerm(expr.GetPsdVar(i), -1 * expr.GetCoeff(i));
    }
    AddLinExpr(expr.GetLinExpr(), -1.0);
  }

  void operator*=(double c)
  {
    m_expr->iMultiply(c);
  }

  friend PsdExpr operator+(const PsdExpr& left, double c)
  {
    PsdExpr ret = left.Clone();
    ret.AddConstant(c);
    return ret;
  }

  friend PsdExpr operator+(double c, const PsdExpr& right)
  {
    PsdExpr ret = right.Clone();
    ret.AddConstant(c);
    return ret;
  }

  friend PsdExpr operator+(const PsdExpr& left, const Var& var)
  {
    PsdExpr ret = left.Clone();
    ret.AddTerm(var, 1.0);
    return ret;
  }

  friend PsdExpr operator+(const Var& var, const PsdExpr& right)
  {
    PsdExpr ret = right.Clone();
    ret.AddTerm(var, 1.0);
    return ret;
  }

  friend PsdExpr operator+(const PsdExpr& left, const Expr& right)
  {
    PsdExpr ret = left.Clone();
    ret += right;
    return ret;
  }

  friend PsdExpr operator+(const Expr& left, const PsdExpr& right)
  {
    PsdExpr ret = right.Clone();
    ret += left;
    return ret;
  }

  friend PsdExpr operator+(const PsdExpr& left, const PsdExpr& right)
  {
    PsdExpr ret = left.Clone();
    ret += right;
    return ret;
  }

  friend PsdExpr operator-(const PsdExpr& left, double c)
  {
    PsdExpr ret = left.Clone();
    ret.AddConstant(-c);
    return ret;
  }

  friend PsdExpr operator-(double c, const PsdExpr& right)
  {
    PsdExpr ret = right.Clone();
    ret *= -1.0;
    ret.AddConstant(c);
    return ret;
  }

  friend PsdExpr operator-(const PsdExpr& expr)
  {
    return 0.0 - expr;
  }

  friend PsdExpr operator-(const PsdExpr& left, const Var& var)
  {
    PsdExpr ret = left.Clone();
    ret.AddTerm(var, -1.0);
    return ret;
  }

  friend PsdExpr operator-(const Var& var, const PsdExpr& right)
  {
    PsdExpr ret = right.Clone();
    ret *= -1.0;
    ret.AddTerm(var, 1.0);
    return ret;
  }

  friend PsdExpr operator-(const PsdExpr& left, const Expr& right)
  {
    PsdExpr ret = left.Clone();
    ret -= right;
    return ret;
  }

  friend PsdExpr operator-(const Expr& left, const PsdExpr& right)
  {
    PsdExpr ret = right.Clone();
    ret -= left;
    return ret;
  }

  friend PsdExpr operator-(const PsdExpr& left, const PsdExpr& right)
  {
    PsdExpr ret = left.Clone();
    ret -= right;
    return ret;
  }

  friend PsdExpr operator*(const PsdExpr& expr, double c)
  {
    PsdExpr ret = expr.Clone();
    ret *= c;
    return ret;
  }

  friend PsdExpr operator*(double c, const PsdExpr& expr)
  {
    PsdExpr ret = expr.Clone();
    ret *= c;
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& out, const PsdExpr& expr)
  {
    out << expr.GetLinExpr();

    for (size_t i = 0; i < expr.Size(); i++)
    {
      if (expr.GetPsdVar(i).GetIdx() < 0)
      {
        continue;
      }

      out << " +  (" << expr.GetCoeff(i) << ")";
      out << " * " << expr.GetPsdVar(i).GetName();
    }

    return out;
  }

  friend PsdConstrBuilder operator>=(const PsdExpr& left, const PsdExpr& right);
  friend PsdConstrBuilder operator>=(const PsdExpr& left, const Expr& right);
  friend PsdConstrBuilder operator>=(const Expr& left, const PsdExpr& right);
  friend PsdConstrBuilder operator>=(const PsdExpr& left, const Var& var);
  friend PsdConstrBuilder operator>=(const Var& var, const PsdExpr& right);
  friend PsdConstrBuilder operator>=(const PsdExpr& left, double c);
  friend PsdConstrBuilder operator>=(double c, const PsdExpr& right);
  friend PsdConstrBuilder operator<=(const PsdExpr& left, const PsdExpr& right);
  friend PsdConstrBuilder operator<=(const PsdExpr& left, const Expr& expr);
  friend PsdConstrBuilder operator<=(const Expr& expr, const PsdExpr& right);
  friend PsdConstrBuilder operator<=(const PsdExpr& left, const Var& var);
  friend PsdConstrBuilder operator<=(const Var& var, const PsdExpr& right);
  friend PsdConstrBuilder operator<=(const PsdExpr& left, double c);
  friend PsdConstrBuilder operator<=(double c, const PsdExpr& right);
  friend PsdConstrBuilder operator==(const PsdExpr& left, const PsdExpr& right);
  friend PsdConstrBuilder operator==(const PsdExpr& left, const Expr& expr);
  friend PsdConstrBuilder operator==(const Expr& expr, const PsdExpr& right);
  friend PsdConstrBuilder operator==(const PsdExpr& left, const Var& var);
  friend PsdConstrBuilder operator==(const Var& var, const PsdExpr& right);
  friend PsdConstrBuilder operator==(const PsdExpr& left, double c);
  friend PsdConstrBuilder operator==(double c, const PsdExpr& right);

  const Copt::IPsdExpr* Get() const
  {
    return &(*m_expr);
  }

private:
  std::shared_ptr<Copt::IPsdExpr> m_expr;
};
