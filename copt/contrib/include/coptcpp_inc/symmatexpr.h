#pragma once
#include "coptcpp.idl.h"
#include "exception.h"
#include "symmatrixarray.h"

class SymMatExpr {
public:
  SymMatExpr() : m_expr(CreateSymMatExpr1()) {}
  SymMatExpr(const SymMatrix& mat, double coeff = 1.0) : m_expr(CreateSymMatExpr2(mat.Get(), coeff)) {}
  SymMatExpr(Copt::ISymMatExpr* expr) : m_expr(expr) {}

  int GetDim() const
  {
    return m_expr->GetDim();
  }

  size_t Size() const
  {
    return m_expr->Size();
  }

  SymMatrix GetSymMat(int i) const
  {
    return m_expr->GetSymMat(i);
  }
  double GetCoeff(int i) const
  {
    return m_expr->GetCoeff(i);
  }
  void SetCoeff(int i, double val) const
  {
    m_expr->SetCoeff(i, val);
  }

  bool AddTerm(const SymMatrix& mat, double coeff)
  {
    bool success = m_expr->AddTerm(mat.Get(), coeff);
    CHECKERROR(m_expr);
    return success;
  }
  int AddTerms(const SymMatrixArray& mats, double* pCoeff, int len)
  {
    int num = m_expr->AddTerms(mats.Get(), pCoeff, len);
    CHECKERROR(m_expr);
    return num;
  }
  void AddSymMatExpr(const SymMatExpr& expr, double mult = 1.0)
  {
    m_expr->AddSymMatExpr(expr.Get(), mult);
    CHECKERROR(m_expr);
  }

  void Remove(int idx)
  {
    m_expr->Remove(idx);
  }
  void Remove(const SymMatrix& mat)
  {
    m_expr->Remove(mat.Get());
  }
  void Reserve(size_t n)
  {
    m_expr->Reserve(n);
  }
  SymMatExpr Clone() const
  {
    return m_expr->Clone();
  }

  void operator+=(const SymMatrix& mat)
  {
    m_expr->AddTerm(mat.Get(), 1.0);
  }

  void operator+=(const SymMatExpr& expr)
  {
    m_expr->AddSymMatExpr(expr.Get(), 1.0);
  }

  void operator-=(const SymMatrix& mat)
  {
    m_expr->AddTerm(mat.Get(), -1.0);
  }

  void operator-=(const SymMatExpr& expr)
  {
    m_expr->AddSymMatExpr(expr.Get(), -1.0);
  }

  void operator*=(double c)
  {
    m_expr->iMultiply(c);
  }

  friend SymMatExpr operator+(const SymMatExpr& left, const SymMatrix& right)
  {
    SymMatExpr ret = left.Clone();
    ret += right;
    return ret;
  }

  friend SymMatExpr operator+(const SymMatrix& left, const SymMatExpr& right)
  {
    SymMatExpr ret = right.Clone();
    ret += left;
    return ret;
  }

  friend SymMatExpr operator+(const SymMatExpr& left, const SymMatExpr& right)
  {
    SymMatExpr ret = left.Clone();
    ret += right;
    return ret;
  }

  friend SymMatExpr operator-(const SymMatExpr& left, const SymMatrix& right)
  {
    SymMatExpr ret = left.Clone();
    ret -= right;
    return ret;
  }

  friend SymMatExpr operator-(const SymMatrix& left, const SymMatExpr& right)
  {
    SymMatExpr ret(left);
    ret.AddSymMatExpr(right, -1.0);
    return ret;
  }

  friend SymMatExpr operator-(const SymMatExpr& left, const SymMatExpr& right)
  {
    SymMatExpr ret = left.Clone();
    ret.AddSymMatExpr(right, -1.0);
    return ret;
  }

  friend SymMatExpr operator-(const SymMatExpr& expr)
  {
    SymMatExpr ret;
    ret.AddSymMatExpr(expr, -1.0);
    return ret;
  }

  friend SymMatExpr operator*(const SymMatExpr& expr, double c)
  {
    SymMatExpr ret;
    ret.AddSymMatExpr(expr, c);
    return ret;
  }

  friend SymMatExpr operator*(double c, const SymMatExpr& expr)
  {
    return expr * c;
  }

  friend std::ostream& operator<<(std::ostream& out, const SymMatExpr& expr)
  {
    size_t sz = expr.Size();
    if (sz == 0)
    {
      out << "0";
    }

    for (size_t i = 0; i < sz; i++)
    {
      if (i > 0)
      {
        out << " + ";
      }
      out << expr.GetSymMat(i);
      if (expr.GetCoeff(i) != 1.0)
      {
        out << " * " << expr.GetCoeff(i);
      }
    }
    return out;
  }

  Copt::ISymMatExpr* Get() const
  {
    return &(*m_expr);
  }

private:
  std::shared_ptr<Copt::ISymMatExpr> m_expr;
};
