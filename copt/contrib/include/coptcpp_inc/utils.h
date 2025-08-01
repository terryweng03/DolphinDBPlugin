#pragma once
#include "constrbuilder.h"
#include "expr.h"
#include "lmiexpr.h"
#include "nl.h"
#include "nlexpr.h"
#include "nlconstrbuilder.h"
#include "psdexpr.h"
#include "psdconstrbuilder.h"
#include "quadexpr.h"
#include "qconstrbuilder.h"
#include "var.h"
#include "psdvar.h"
#include "symmatrix.h"
#include "symmatexpr.h"
#include "mat.h"
#include "mconstrbuilder.h"
#include "mlinexpr.h"
#include "mqconstrbuilder.h"
#include "mpsdconstrbuilder.h"
#include "mpsdexpr.h"
#include "mquadexpr.h"
#include "mvar.h"

class Utils {
public:
  // Define operator overloadings, which depend on each other.
  friend Expr operator+(const Var& var, double a)
  {
    Expr tmp(var, 1.0);
    tmp.SetConstant(a);
    return tmp;
  }

  friend Expr operator+(double a, const Var& var)
  {
    Expr tmp(var, 1.0);
    tmp.SetConstant(a);
    return tmp;
  }

  friend Expr operator+(const Var& left, const Var& right)
  {
    Expr tmp(left, 1.0);
    tmp.AddTerm(right, 1.0);
    return tmp;
  }

  friend Expr operator-(const Var& var, double a)
  {
    Expr tmp(var, 1.0);
    tmp.SetConstant(-a);
    return tmp;
  }

  friend Expr operator-(double a, const Var& var)
  {
    Expr tmp(var, -1.0);
    tmp.SetConstant(a);
    return tmp;
  }

  friend Expr operator-(const Var& var)
  {
    return 0.0 - var;
  }

  friend Expr operator-(const Var& left, const Var& right)
  {
    Expr tmp(left, 1.0);
    tmp.AddTerm(right, -1.0);
    return tmp;
  }

  friend Expr operator*(double a, const Var& var)
  {
    return Expr(var, a);
  }

  friend Expr operator*(const Var& var, double a)
  {
    return Expr(var, a);
  }

  friend Expr operator/(const Var& left, double a)
  {
    Expr ret(left);
    ret /= a;
    return ret;
  }

  friend NlExpr operator/(double a, const Var& right)
  {
    if (a == 0.0)
    {
      return NlExpr(0.0);
    }
    NlExpr ret(a);
    ret /= right;
    return ret;
  }

  friend NlExpr operator/(const Var& left, const Var& right)
  {
    NlExpr ret(left);
    ret /= right;
    return ret;
  }

  friend PsdExpr operator*(const PsdVar& var, const SymMatrix& mat)
  {
    PsdExpr expr;
    expr.AddTerm(var, mat);
    return expr;
  }
  friend PsdExpr operator*(const SymMatrix& mat, const PsdVar& var)
  {
    return var * mat;
  }

  friend PsdExpr operator*(const PsdVar& var, const SymMatExpr& expr)
  {
    PsdExpr ret;
    ret.AddTerm(var, expr);
    return ret;
  }
  friend PsdExpr operator*(const SymMatExpr& expr, const PsdVar& var)
  {
    return var * expr;
  }

  friend LmiExpr operator*(const Var& var, const SymMatrix& mat)
  {
    LmiExpr expr;
    expr.AddTerm(var, mat);
    return expr;
  }
  friend LmiExpr operator*(const SymMatrix& mat, const Var& var)
  {
    return var * mat;
  }

  friend LmiExpr operator*(const Var& var, const SymMatExpr& expr)
  {
    LmiExpr ret;
    ret.AddTerm(var, expr);
    return ret;
  }
  friend LmiExpr operator*(const SymMatExpr& expr, const Var& var)
  {
    return var * expr;
  }

  friend QuadExpr operator*(const Var& var1, const Var& var2)
  {
    QuadExpr expr;
    expr.AddTerm(var1, var2);
    return expr;
  }

  friend QuadExpr operator*(const Expr& expr, const Var& var)
  {
    QuadExpr ret(expr, var);
    return ret;
  }

  friend QuadExpr operator*(const Var& var, const Expr& expr)
  {
    return expr * var;
  }

  friend QuadExpr operator*(const Expr& left, const Expr& right)
  {
    QuadExpr expr(left, right);
    return expr;
  }

  friend NlExpr operator*(const Var& var, const QuadExpr& expr)
  {
    NlExpr ret(var);
    ret *= expr;
    return ret;
  }

  friend NlExpr operator*(const QuadExpr& expr, const Var& var)
  {
    NlExpr ret(expr);
    ret *= var;
    return ret;
  }

  friend NlExpr operator*(const Expr& left, const QuadExpr& right)
  {
    NlExpr ret(left);
    ret *= right;
    return ret;
  }

  friend NlExpr operator*(const QuadExpr& left, const Expr& right)
  {
    NlExpr ret(left);
    ret *= right;
    return ret;
  }

  friend NlExpr operator*(const QuadExpr& left, const QuadExpr& right)
  {
    NlExpr ret(left);
    ret *= right;
    return ret;
  }

  friend NlExpr operator/(double c, const Expr& expr)
  {
    NlExpr ret(c);
    ret /= expr;
    return ret;
  }

  friend NlExpr operator/(const Var& var, const Expr& expr)
  {
    NlExpr ret(var);
    ret /= expr;
    return ret;
  }

  friend NlExpr operator/(const Expr& expr, const Var& var)
  {
    NlExpr ret(expr);
    ret /= var;
    return ret;
  }

  friend NlExpr operator/(const Expr& left, const Expr& right)
  {
    NlExpr ret(left);
    ret /= right;
    return ret;
  }

  friend NlExpr operator/(double c, const QuadExpr& expr)
  {
    NlExpr ret(c);
    ret /= expr;
    return ret;
  }

  friend NlExpr operator/(const Var& var, const QuadExpr& expr)
  {
    NlExpr ret(var);
    ret /= expr;
    return ret;
  }

  friend NlExpr operator/(const QuadExpr& expr, const Var& var)
  {
    NlExpr ret(expr);
    ret /= var;
    return ret;
  }

  friend NlExpr operator/(const Expr& left, const QuadExpr& right)
  {
    NlExpr ret(left);
    ret /= right;
    return ret;
  }

  friend NlExpr operator/(const QuadExpr& left, const Expr& right)
  {
    NlExpr ret(left);
    ret /= right;
    return ret;
  }

  friend NlExpr operator/(const QuadExpr& left, const QuadExpr& right)
  {
    NlExpr ret(left);
    ret /= right;
    return ret;
  }

  friend SymMatExpr operator+(const SymMatrix& left, const SymMatrix& right)
  {
    SymMatExpr expr(left);
    expr.AddTerm(right, 1.0);
    return expr;
  }

  friend SymMatExpr operator-(const SymMatrix& left, const SymMatrix& right)
  {
    SymMatExpr expr(left);
    expr.AddTerm(right, -1.0);
    return expr;
  }

  friend SymMatExpr operator*(const SymMatrix& mat, double c)
  {
    return SymMatExpr(mat, c);
  }

  friend SymMatExpr operator*(double c, const SymMatrix& mat)
  {
    return SymMatExpr(mat, c);
  }

  /* Constrbuilder operators */
  friend ConstrBuilder operator==(double a, const Var& right)
  {
    ConstrBuilder builder;
    builder.Set(right, COPT_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator==(const Var& left, double a)
  {
    ConstrBuilder builder;
    builder.Set(left, COPT_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator==(const Var& left, const Var& right)
  {
    ConstrBuilder builder;
    builder.Set(left - right, COPT_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator>=(double a, const Var& right)
  {
    ConstrBuilder builder;
    builder.Set(right, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator>=(const Var& left, double a)
  {
    ConstrBuilder builder;
    builder.Set(left, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator>=(const Var& left, const Var& right)
  {
    ConstrBuilder builder;
    builder.Set(left - right, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator<=(double a, const Var& right)
  {
    ConstrBuilder builder;
    builder.Set(right, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator<=(const Var& left, double a)
  {
    ConstrBuilder builder;
    builder.Set(left, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator<=(const Var& left, const Var& right)
  {
    ConstrBuilder builder;
    builder.Set(left - right, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator>=(const Expr& left, double a)
  {
    ConstrBuilder builder;
    builder.Set(left, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator>=(double a, const Expr& right)
  {
    ConstrBuilder builder;
    builder.Set(right, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator>=(const Expr& left, const Var& var)
  {
    ConstrBuilder builder;
    builder.Set(left - var, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator>=(const Var& var, const Expr& right)
  {
    ConstrBuilder builder;
    builder.Set(right - var, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator>=(const Expr& left, const Expr& right)
  {
    ConstrBuilder builder;
    builder.Set(left - right, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator<=(const Expr& left, double a)
  {
    ConstrBuilder builder;
    builder.Set(left, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator<=(double a, const Expr& right)
  {
    ConstrBuilder builder;
    builder.Set(right, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator<=(const Expr& left, const Var& var)
  {
    ConstrBuilder builder;
    builder.Set(left - var, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator<=(const Var& var, const Expr& right)
  {
    ConstrBuilder builder;
    builder.Set(right - var, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator<=(const Expr& left, const Expr& right)
  {
    ConstrBuilder builder;
    builder.Set(left - right, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator==(const Expr& left, double a)
  {
    ConstrBuilder builder;
    builder.Set(left, COPT_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator==(double a, const Expr& right)
  {
    ConstrBuilder builder;
    builder.Set(right, COPT_EQUAL, a);
    return builder;
  }

  friend ConstrBuilder operator==(const Expr& left, const Var& var)
  {
    ConstrBuilder builder;
    builder.Set(left - var, COPT_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator==(const Var& var, const Expr& right)
  {
    ConstrBuilder builder;
    builder.Set(right - var, COPT_EQUAL, 0.0);
    return builder;
  }

  friend ConstrBuilder operator==(const Expr& left, const Expr& right)
  {
    ConstrBuilder builder;
    builder.Set(left - right, COPT_EQUAL, 0.0);
    return builder;
  }

  /* NlConstrbuilder operator == */
  friend NlConstrBuilder operator==(double a, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right, COPT_EQUAL, a);
    return builder;
  }

  friend NlConstrBuilder operator==(const Var& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right - left, COPT_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator==(const Expr& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right - left, COPT_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator==(const QuadExpr& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right - left, COPT_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator==(const NlExpr& left, double a)
  {
    NlConstrBuilder builder;
    builder.Set(left, COPT_EQUAL, a);
    return builder;
  }

  friend NlConstrBuilder operator==(const NlExpr& left, const Var& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator==(const NlExpr& left, const Expr& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator==(const NlExpr& left, const QuadExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator==(const NlExpr& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_EQUAL, 0.0);
    return builder;
  }

  /* NlConstrbuilder operator >= */
  friend NlConstrBuilder operator>=(double a, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend NlConstrBuilder operator>=(const Var& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right - left, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator>=(const Expr& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right - left, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator>=(const QuadExpr& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right - left, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator>=(const NlExpr& left, double a)
  {
    NlConstrBuilder builder;
    builder.Set(left, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend NlConstrBuilder operator>=(const NlExpr& left, const Var& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator>=(const NlExpr& left, const Expr& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator>=(const NlExpr& left, const QuadExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator>=(const NlExpr& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  /* NlConstrbuilder operator <= */
  friend NlConstrBuilder operator<=(double a, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend NlConstrBuilder operator<=(const Var& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right - left, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator<=(const Expr& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right - left, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator<=(const QuadExpr& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(right - left, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator<=(const NlExpr& left, double a)
  {
    NlConstrBuilder builder;
    builder.Set(left, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend NlConstrBuilder operator<=(const NlExpr& left, const Var& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator<=(const NlExpr& left, const Expr& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator<=(const NlExpr& left, const QuadExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend NlConstrBuilder operator<=(const NlExpr& left, const NlExpr& right)
  {
    NlConstrBuilder builder;
    builder.Set(left - right, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  /* QConstrbuilder operators */
  friend QConstrBuilder operator>=(const QuadExpr& left, double a)
  {
    QConstrBuilder builder;
    builder.Set(left, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend QConstrBuilder operator>=(double a, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(right, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend QConstrBuilder operator>=(const QuadExpr& left, const Var& var)
  {
    QConstrBuilder builder;
    builder.Set(left - var, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator>=(const Var& var, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(right - var, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator>=(const QuadExpr& left, const Expr& expr)
  {
    QConstrBuilder builder;
    builder.Set(left - expr, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator>=(const Expr& expr, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(right - expr, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator>=(const QuadExpr& left, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(left - right, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator<=(const QuadExpr& left, double a)
  {
    QConstrBuilder builder;
    builder.Set(left, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend QConstrBuilder operator<=(double a, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(right, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend QConstrBuilder operator<=(const QuadExpr& left, const Var& var)
  {
    QConstrBuilder builder;
    builder.Set(left - var, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator<=(const Var& var, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(right - var, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator<=(const QuadExpr& left, const Expr& expr)
  {
    QConstrBuilder builder;
    builder.Set(left - expr, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator<=(const Expr& expr, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(right - expr, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator<=(const QuadExpr& left, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(left - right, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator==(const QuadExpr& left, double a)
  {
    QConstrBuilder builder;
    builder.Set(left, COPT_EQUAL, a);
    return builder;
  }

  friend QConstrBuilder operator==(double a, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(right, COPT_EQUAL, a);
    return builder;
  }

  friend QConstrBuilder operator==(const QuadExpr& left, const Var& var)
  {
    QConstrBuilder builder;
    builder.Set(left - var, COPT_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator==(const Var& var, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(right - var, COPT_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator==(const QuadExpr& left, const Expr& expr)
  {
    QConstrBuilder builder;
    builder.Set(left - expr, COPT_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator==(const Expr& expr, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(right - expr, COPT_EQUAL, 0.0);
    return builder;
  }

  friend QConstrBuilder operator==(const QuadExpr& left, const QuadExpr& right)
  {
    QConstrBuilder builder;
    builder.Set(left - right, COPT_EQUAL, 0.0);
    return builder;
  }

  /* PsdConstrbuilder operators */
  friend PsdConstrBuilder operator>=(const PsdExpr& left, double a)
  {
    PsdConstrBuilder builder;
    builder.Set(left, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend PsdConstrBuilder operator>=(double a, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(right, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend PsdConstrBuilder operator>=(const PsdExpr& left, const Var& var)
  {
    PsdConstrBuilder builder;
    builder.Set(left - var, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator>=(const Var& var, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(right - var, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator>=(const PsdExpr& left, const Expr& expr)
  {
    PsdConstrBuilder builder;
    builder.Set(left - expr, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator>=(const Expr& expr, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(right - expr, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator>=(const PsdExpr& left, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(left - right, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator<=(const PsdExpr& left, double a)
  {
    PsdConstrBuilder builder;
    builder.Set(left, COPT_LESS_EQUAL, a);
    return builder;
  }

  friend PsdConstrBuilder operator<=(double a, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(right, COPT_GREATER_EQUAL, a);
    return builder;
  }

  friend PsdConstrBuilder operator<=(const PsdExpr& left, const Var& var)
  {
    PsdConstrBuilder builder;
    builder.Set(left - var, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator<=(const Var& var, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(right - var, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator<=(const PsdExpr& left, const Expr& expr)
  {
    PsdConstrBuilder builder;
    builder.Set(left - expr, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator<=(const Expr& expr, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(right - expr, COPT_GREATER_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator<=(const PsdExpr& left, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(left - right, COPT_LESS_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator==(const PsdExpr& left, double a)
  {
    PsdConstrBuilder builder;
    builder.Set(left, COPT_EQUAL, a);
    return builder;
  }

  friend PsdConstrBuilder operator==(double a, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(right, COPT_EQUAL, a);
    return builder;
  }

  friend PsdConstrBuilder operator==(const PsdExpr& left, const Var& var)
  {
    PsdConstrBuilder builder;
    builder.Set(left - var, COPT_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator==(const Var& var, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(right - var, COPT_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator==(const PsdExpr& left, const Expr& expr)
  {
    PsdConstrBuilder builder;
    builder.Set(left - expr, COPT_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator==(const Expr& expr, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(right - expr, COPT_EQUAL, 0.0);
    return builder;
  }

  friend PsdConstrBuilder operator==(const PsdExpr& left, const PsdExpr& right)
  {
    PsdConstrBuilder builder;
    builder.Set(left - right, COPT_EQUAL, 0.0);
    return builder;
  }
};
