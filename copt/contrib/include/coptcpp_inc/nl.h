#pragma once
#include "nlhelper.h"

namespace NL {

static COPT_UNUSED NlExpr Sum(const std::vector<NlExpr>& exprs)
{
  std::vector<Copt::INlExpr*> ptrs;
  for (const NlExpr& expr : exprs)
  {
    ptrs.push_back(expr.Get());
  }
  return NlHelper::Get().Sum(ptrs);
}

static COPT_UNUSED NlExpr Sum(const NlExpr& op1, const NlExpr& op2, const NlExpr& op3)
{
  return NlHelper::Get().Sum(op1.Get(), op2.Get(), op3.Get());
}

static COPT_UNUSED NlExpr Sum(const NlExpr& op1, const NlExpr& op2, const NlExpr& op3, const NlExpr& op4)
{
  return NlHelper::Get().Sum(op1.Get(), op2.Get(), op3.Get(), op4.Get());
}

static COPT_UNUSED NlExpr ATan2(double y, const NlExpr& x)
{
  return NlHelper::Get().ATan2(y, x.Get());
}

static COPT_UNUSED NlExpr ATan2(const NlExpr& y, double x)
{
  return NlHelper::Get().ATan2(y.Get(), x);
}

static COPT_UNUSED NlExpr ATan2(const NlExpr& y, const NlExpr& x)
{
  return NlHelper::Get().ATan2(y.Get(), x.Get());
}

static COPT_UNUSED NlExpr Pow(double base, const NlExpr& expo)
{
  return NlHelper::Get().Pow(base, expo.Get());
}

static COPT_UNUSED NlExpr Pow(const NlExpr& base, double expo)
{
  return NlHelper::Get().Pow(base.Get(), expo);
}

static COPT_UNUSED NlExpr Pow(const NlExpr& base, const NlExpr& expo)
{
  return NlHelper::Get().Pow(base.Get(), expo.Get());
}

static COPT_UNUSED NlExpr Sqrt(double c)
{
  return NlHelper::Get().Sqrt(c);
}

static COPT_UNUSED NlExpr Sqrt(const Var& var)
{
  return NlHelper::Get().Sqrt(var.Get());
}

static COPT_UNUSED NlExpr Sqrt(const Expr& expr)
{
  return NlHelper::Get().Sqrt(expr.Get());
}

static COPT_UNUSED NlExpr Sqrt(const QuadExpr& expr)
{
  return NlHelper::Get().Sqrt(expr.Get());
}

static COPT_UNUSED NlExpr Sqrt(const NlExpr& expr)
{
  return NlHelper::Get().Sqrt(expr.Get());
}

static COPT_UNUSED NlExpr Exp(double c)
{
  return NlHelper::Get().Exp(c);
}

static COPT_UNUSED NlExpr Exp(const Var& var)
{
  return NlHelper::Get().Exp(var.Get());
}

static COPT_UNUSED NlExpr Exp(const Expr& expo)
{
  return NlHelper::Get().Exp(expo.Get());
}

static COPT_UNUSED NlExpr Exp(const QuadExpr& expo)
{
  return NlHelper::Get().Exp(expo.Get());
}

static COPT_UNUSED NlExpr Exp(const NlExpr& expo)
{
  return NlHelper::Get().Exp(expo.Get());
}

static COPT_UNUSED NlExpr Log(double c)
{
  return NlHelper::Get().Log(c);
}

static COPT_UNUSED NlExpr Log(const Var& var)
{
  return NlHelper::Get().Log(var.Get());
}

static COPT_UNUSED NlExpr Log(const Expr& expr)
{
  return NlHelper::Get().Log(expr.Get());
}

static COPT_UNUSED NlExpr Log(const QuadExpr& expr)
{
  return NlHelper::Get().Log(expr.Get());
}

static COPT_UNUSED NlExpr Log(const NlExpr& expr)
{
  return NlHelper::Get().Log(expr.Get());
}

static COPT_UNUSED NlExpr Log10(double c)
{
  return NlHelper::Get().Log10(c);
}

static COPT_UNUSED NlExpr Log10(const Var& var)
{
  return NlHelper::Get().Log10(var.Get());
}

static COPT_UNUSED NlExpr Log10(const Expr& expr)
{
  return NlHelper::Get().Log10(expr.Get());
}

static COPT_UNUSED NlExpr Log10(const QuadExpr& expr)
{
  return NlHelper::Get().Log10(expr.Get());
}

static COPT_UNUSED NlExpr Log10(const NlExpr& expr)
{
  return NlHelper::Get().Log10(expr.Get());
}

static COPT_UNUSED NlExpr Neg(double c)
{
  return NlHelper::Get().Neg(c);
}

static COPT_UNUSED NlExpr Neg(const Var& var)
{
  return NlHelper::Get().Neg(var.Get());
}

static COPT_UNUSED NlExpr Neg(const Expr& expr)
{
  return NlHelper::Get().Neg(expr.Get());
}

static COPT_UNUSED NlExpr Neg(const QuadExpr& expr)
{
  return NlHelper::Get().Neg(expr.Get());
}

static COPT_UNUSED NlExpr Neg(const NlExpr& expr)
{
  return NlHelper::Get().Neg(expr.Get());
}

static COPT_UNUSED NlExpr Abs(double c)
{
  return NlHelper::Get().Abs(c);
}

static COPT_UNUSED NlExpr Abs(const Var& var)
{
  return NlHelper::Get().Abs(var.Get());
}

static COPT_UNUSED NlExpr Abs(const Expr& expr)
{
  return NlHelper::Get().Abs(expr.Get());
}

static COPT_UNUSED NlExpr Abs(const QuadExpr& expr)
{
  return NlHelper::Get().Abs(expr.Get());
}

static COPT_UNUSED NlExpr Abs(const NlExpr& expr)
{
  return NlHelper::Get().Abs(expr.Get());
}

static COPT_UNUSED NlExpr Floor(double c)
{
  return NlHelper::Get().Floor(c);
}

static COPT_UNUSED NlExpr Floor(const Var& var)
{
  return NlHelper::Get().Floor(var.Get());
}

static COPT_UNUSED NlExpr Floor(const Expr& expr)
{
  return NlHelper::Get().Floor(expr.Get());
}

static COPT_UNUSED NlExpr Floor(const QuadExpr& expr)
{
  return NlHelper::Get().Floor(expr.Get());
}

static COPT_UNUSED NlExpr Floor(const NlExpr& expr)
{
  return NlHelper::Get().Floor(expr.Get());
}

static COPT_UNUSED NlExpr Ceil(double c)
{
  return NlHelper::Get().Ceil(c);
}

static COPT_UNUSED NlExpr Ceil(const Var& var)
{
  return NlHelper::Get().Ceil(var.Get());
}

static COPT_UNUSED NlExpr Ceil(const Expr& expr)
{
  return NlHelper::Get().Ceil(expr.Get());
}

static COPT_UNUSED NlExpr Ceil(const QuadExpr& expr)
{
  return NlHelper::Get().Ceil(expr.Get());
}

static COPT_UNUSED NlExpr Ceil(const NlExpr& expr)
{
  return NlHelper::Get().Ceil(expr.Get());
}

static COPT_UNUSED NlExpr Cos(double c)
{
  return NlHelper::Get().Cos(c);
}

static COPT_UNUSED NlExpr Cos(const Var& var)
{
  return NlHelper::Get().Cos(var.Get());
}

static COPT_UNUSED NlExpr Cos(const Expr& expr)
{
  return NlHelper::Get().Cos(expr.Get());
}

static COPT_UNUSED NlExpr Cos(const QuadExpr& expr)
{
  return NlHelper::Get().Cos(expr.Get());
}

static COPT_UNUSED NlExpr Cos(const NlExpr& expr)
{
  return NlHelper::Get().Cos(expr.Get());
}

static COPT_UNUSED NlExpr Sin(double c)
{
  return NlHelper::Get().Sin(c);
}

static COPT_UNUSED NlExpr Sin(const Var& var)
{
  return NlHelper::Get().Sin(var.Get());
}

static COPT_UNUSED NlExpr Sin(const Expr& expr)
{
  return NlHelper::Get().Sin(expr.Get());
}

static COPT_UNUSED NlExpr Sin(const QuadExpr& expr)
{
  return NlHelper::Get().Sin(expr.Get());
}

static COPT_UNUSED NlExpr Sin(const NlExpr& expr)
{
  return NlHelper::Get().Sin(expr.Get());
}

static COPT_UNUSED NlExpr Tan(double c)
{
  return NlHelper::Get().Tan(c);
}

static COPT_UNUSED NlExpr Tan(const Var& var)
{
  return NlHelper::Get().Tan(var.Get());
}

static COPT_UNUSED NlExpr Tan(const Expr& expr)
{
  return NlHelper::Get().Tan(expr.Get());
}

static COPT_UNUSED NlExpr Tan(const QuadExpr& expr)
{
  return NlHelper::Get().Tan(expr.Get());
}

static COPT_UNUSED NlExpr Tan(const NlExpr& expr)
{
  return NlHelper::Get().Tan(expr.Get());
}

static COPT_UNUSED NlExpr CosH(double c)
{
  return NlHelper::Get().CosH(c);
}

static COPT_UNUSED NlExpr CosH(const Var& var)
{
  return NlHelper::Get().CosH(var.Get());
}

static COPT_UNUSED NlExpr CosH(const Expr& expr)
{
  return NlHelper::Get().CosH(expr.Get());
}

static COPT_UNUSED NlExpr CosH(const QuadExpr& expr)
{
  return NlHelper::Get().CosH(expr.Get());
}

static COPT_UNUSED NlExpr CosH(const NlExpr& expr)
{
  return NlHelper::Get().CosH(expr.Get());
}

static COPT_UNUSED NlExpr SinH(double c)
{
  return NlHelper::Get().SinH(c);
}

static COPT_UNUSED NlExpr SinH(const Var& var)
{
  return NlHelper::Get().SinH(var.Get());
}

static COPT_UNUSED NlExpr SinH(const Expr& expr)
{
  return NlHelper::Get().SinH(expr.Get());
}

static COPT_UNUSED NlExpr SinH(const QuadExpr& expr)
{
  return NlHelper::Get().SinH(expr.Get());
}

static COPT_UNUSED NlExpr SinH(const NlExpr& expr)
{
  return NlHelper::Get().SinH(expr.Get());
}

static COPT_UNUSED NlExpr TanH(double c)
{
  return NlHelper::Get().TanH(c);
}

static COPT_UNUSED NlExpr TanH(const Var& var)
{
  return NlHelper::Get().TanH(var.Get());
}

static COPT_UNUSED NlExpr TanH(const Expr& expr)
{
  return NlHelper::Get().TanH(expr.Get());
}

static COPT_UNUSED NlExpr TanH(const QuadExpr& expr)
{
  return NlHelper::Get().TanH(expr.Get());
}

static COPT_UNUSED NlExpr TanH(const NlExpr& expr)
{
  return NlHelper::Get().TanH(expr.Get());
}

static COPT_UNUSED NlExpr ACos(double c)
{
  return NlHelper::Get().ACos(c);
}

static COPT_UNUSED NlExpr ACos(const Var& var)
{
  return NlHelper::Get().ACos(var.Get());
}

static COPT_UNUSED NlExpr ACos(const Expr& expr)
{
  return NlHelper::Get().ACos(expr.Get());
}

static COPT_UNUSED NlExpr ACos(const QuadExpr& expr)
{
  return NlHelper::Get().ACos(expr.Get());
}

static COPT_UNUSED NlExpr ACos(const NlExpr& expr)
{
  return NlHelper::Get().ACos(expr.Get());
}

static COPT_UNUSED NlExpr ASin(double c)
{
  return NlHelper::Get().ASin(c);
}

static COPT_UNUSED NlExpr ASin(const Var& var)
{
  return NlHelper::Get().ASin(var.Get());
}

static COPT_UNUSED NlExpr ASin(const Expr& expr)
{
  return NlHelper::Get().ASin(expr.Get());
}

static COPT_UNUSED NlExpr ASin(const QuadExpr& expr)
{
  return NlHelper::Get().ASin(expr.Get());
}

static COPT_UNUSED NlExpr ASin(const NlExpr& expr)
{
  return NlHelper::Get().ASin(expr.Get());
}

static COPT_UNUSED NlExpr ATan(double c)
{
  return NlHelper::Get().ATan(c);
}

static COPT_UNUSED NlExpr ATan(const Var& var)
{
  return NlHelper::Get().ATan(var.Get());
}

static COPT_UNUSED NlExpr ATan(const Expr& expr)
{
  return NlHelper::Get().ATan(expr.Get());
}

static COPT_UNUSED NlExpr ATan(const QuadExpr& expr)
{
  return NlHelper::Get().ATan(expr.Get());
}

static COPT_UNUSED NlExpr ATan(const NlExpr& expr)
{
  return NlHelper::Get().ATan(expr.Get());
}

static COPT_UNUSED NlExpr ACosH(double c)
{
  return NlHelper::Get().ACosH(c);
}

static COPT_UNUSED NlExpr ACosH(const Var& var)
{
  return NlHelper::Get().ACosH(var.Get());
}

static COPT_UNUSED NlExpr ACosH(const Expr& expr)
{
  return NlHelper::Get().ACosH(expr.Get());
}

static COPT_UNUSED NlExpr ACosH(const QuadExpr& expr)
{
  return NlHelper::Get().ACosH(expr.Get());
}

static COPT_UNUSED NlExpr ACosH(const NlExpr& expr)
{
  return NlHelper::Get().ACosH(expr.Get());
}

static COPT_UNUSED NlExpr ASinH(double c)
{
  return NlHelper::Get().ASinH(c);
}

static COPT_UNUSED NlExpr ASinH(const Var& var)
{
  return NlHelper::Get().ASinH(var.Get());
}

static COPT_UNUSED NlExpr ASinH(const Expr& expr)
{
  return NlHelper::Get().ASinH(expr.Get());
}

static COPT_UNUSED NlExpr ASinH(const QuadExpr& expr)
{
  return NlHelper::Get().ASinH(expr.Get());
}

static COPT_UNUSED NlExpr ASinH(const NlExpr& expr)
{
  return NlHelper::Get().ASinH(expr.Get());
}

static COPT_UNUSED NlExpr ATanH(double c)
{
  return NlHelper::Get().ATanH(c);
}

static COPT_UNUSED NlExpr ATanH(const Var& var)
{
  return NlHelper::Get().ATanH(var.Get());
}

static COPT_UNUSED NlExpr ATanH(const Expr& expr)
{
  return NlHelper::Get().ATanH(expr.Get());
}

static COPT_UNUSED NlExpr ATanH(const QuadExpr& expr)
{
  return NlHelper::Get().ATanH(expr.Get());
}

static COPT_UNUSED NlExpr ATanH(const NlExpr& expr)
{
  return NlHelper::Get().ATanH(expr.Get());
}

}  // namespace NL