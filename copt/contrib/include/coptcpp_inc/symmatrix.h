#pragma once
#include "coptcpp.idl.h"
#include "exception.h"

class SymMatExpr;

class SymMatrix {
public:
  SymMatrix(Copt::ISymMatrix* mat) : m_mat(mat) {}

  int GetIdx() const
  {
    return m_mat->GetIdx();
  }
  int GetDim() const
  {
    return m_mat->GetDim();
  }

  Copt::ISymMatrix* Get() const
  {
    return &(*m_mat);
  }

  friend std::ostream& operator<<(std::ostream& out, const SymMatrix& mat)
  {
    out << "SymMat(" << mat.GetIdx() << ")";
    return out;
  }

  friend SymMatExpr operator+(const SymMatrix& left, const SymMatrix& right);
  friend SymMatExpr operator-(const SymMatrix& left, const SymMatrix& right);
  friend SymMatExpr operator*(const SymMatrix& mat, double c);
  friend SymMatExpr operator*(double c, const SymMatrix& mat);

private:
  std::shared_ptr<Copt::ISymMatrix> m_mat;
};
