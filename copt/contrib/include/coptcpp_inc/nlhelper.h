#pragma once
#include "coptcpp.idl.h"
#include "nlexpr.h"

class NlHelper {
public:
  static NlHelper& Get()
  {
    static NlHelper helper;
    return helper;
  }

  Copt::INlExpr* Sum(const std::vector<Copt::INlExpr*>& exprs)
  {
    return m_helper->Sum(exprs);
  }

  Copt::INlExpr* Sum(const Copt::INlExpr* op1, const Copt::INlExpr* op2, const Copt::INlExpr* op3)
  {
    return m_helper->Sum(op1, op2, op3);
  }

  Copt::INlExpr*
  Sum(const Copt::INlExpr* op1, const Copt::INlExpr* op2, const Copt::INlExpr* op3, const Copt::INlExpr* op4)
  {
    return m_helper->Sum(op1, op2, op3, op4);
  }

  Copt::INlExpr* ATan2(double y, const Copt::INlExpr* x)
  {
    return m_helper->ATan2(y, x);
  }

  Copt::INlExpr* ATan2(const Copt::INlExpr* y, double x)
  {
    return m_helper->ATan2(y, x);
  }

  Copt::INlExpr* ATan2(const Copt::INlExpr* y, const Copt::INlExpr* x)
  {
    return m_helper->ATan2(y, x);
  }

  Copt::INlExpr* Pow(double base, const Copt::INlExpr* expo)
  {
    return m_helper->Pow(base, expo);
  }

  Copt::INlExpr* Pow(const Copt::INlExpr* base, double expo)
  {
    return m_helper->Pow(base, expo);
  }

  Copt::INlExpr* Pow(const Copt::INlExpr* base, const Copt::INlExpr* expo)
  {
    return m_helper->Pow(base, expo);
  }

  Copt::INlExpr* Sqrt(double c)
  {
    return m_helper->Sqrt(c);
  }

  Copt::INlExpr* Sqrt(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Sqrt(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Sqrt(const Copt::IExpr* expr)
  {
    return m_helper->Sqrt(expr);
  }

  Copt::INlExpr* Sqrt(const Copt::IQuadExpr* expr)
  {
    return m_helper->Sqrt(expr);
  }

  Copt::INlExpr* Sqrt(const Copt::INlExpr* expr)
  {
    return m_helper->Sqrt(expr);
  }

  Copt::INlExpr* Exp(double c)
  {
    return m_helper->Exp(c);
  }

  Copt::INlExpr* Exp(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Exp(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Exp(const Copt::IExpr* expr)
  {
    return m_helper->Exp(expr);
  }

  Copt::INlExpr* Exp(const Copt::IQuadExpr* expr)
  {
    return m_helper->Exp(expr);
  }

  Copt::INlExpr* Exp(const Copt::INlExpr* expr)
  {
    return m_helper->Exp(expr);
  }

  Copt::INlExpr* Log(double c)
  {
    return m_helper->Log(c);
  }

  Copt::INlExpr* Log(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Log(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Log(const Copt::IExpr* expr)
  {
    return m_helper->Log(expr);
  }

  Copt::INlExpr* Log(const Copt::IQuadExpr* expr)
  {
    return m_helper->Log(expr);
  }

  Copt::INlExpr* Log(const Copt::INlExpr* expr)
  {
    return m_helper->Log(expr);
  }

  Copt::INlExpr* Log10(double c)
  {
    return m_helper->Log10(c);
  }

  Copt::INlExpr* Log10(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Log10(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Log10(const Copt::IExpr* expr)
  {
    return m_helper->Log10(expr);
  }

  Copt::INlExpr* Log10(const Copt::IQuadExpr* expr)
  {
    return m_helper->Log10(expr);
  }

  Copt::INlExpr* Log10(const Copt::INlExpr* expr)
  {
    return m_helper->Log10(expr);
  }

  Copt::INlExpr* Neg(double c)
  {
    return m_helper->Neg(c);
  }

  Copt::INlExpr* Neg(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Neg(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Neg(const Copt::IExpr* expr)
  {
    return m_helper->Neg(expr);
  }

  Copt::INlExpr* Neg(const Copt::IQuadExpr* expr)
  {
    return m_helper->Neg(expr);
  }

  Copt::INlExpr* Neg(const Copt::INlExpr* expr)
  {
    return m_helper->Neg(expr);
  }

  Copt::INlExpr* Abs(double c)
  {
    return m_helper->Abs(c);
  }

  Copt::INlExpr* Abs(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Abs(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Abs(const Copt::IExpr* expr)
  {
    return m_helper->Abs(expr);
  }

  Copt::INlExpr* Abs(const Copt::IQuadExpr* expr)
  {
    return m_helper->Abs(expr);
  }

  Copt::INlExpr* Abs(const Copt::INlExpr* expr)
  {
    return m_helper->Abs(expr);
  }

  Copt::INlExpr* Floor(double c)
  {
    return m_helper->Floor(c);
  }

  Copt::INlExpr* Floor(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Floor(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Floor(const Copt::IExpr* expr)
  {
    return m_helper->Floor(expr);
  }

  Copt::INlExpr* Floor(const Copt::IQuadExpr* expr)
  {
    return m_helper->Floor(expr);
  }

  Copt::INlExpr* Floor(const Copt::INlExpr* expr)
  {
    return m_helper->Floor(expr);
  }

  Copt::INlExpr* Ceil(double c)
  {
    return m_helper->Ceil(c);
  }

  Copt::INlExpr* Ceil(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Ceil(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Ceil(const Copt::IExpr* expr)
  {
    return m_helper->Ceil(expr);
  }

  Copt::INlExpr* Ceil(const Copt::IQuadExpr* expr)
  {
    return m_helper->Ceil(expr);
  }

  Copt::INlExpr* Ceil(const Copt::INlExpr* expr)
  {
    return m_helper->Ceil(expr);
  }

  Copt::INlExpr* Cos(double c)
  {
    return m_helper->Cos(c);
  }

  Copt::INlExpr* Cos(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Cos(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Cos(const Copt::IExpr* expr)
  {
    return m_helper->Cos(expr);
  }

  Copt::INlExpr* Cos(const Copt::IQuadExpr* expr)
  {
    return m_helper->Cos(expr);
  }

  Copt::INlExpr* Cos(const Copt::INlExpr* expr)
  {
    return m_helper->Cos(expr);
  }

  Copt::INlExpr* Sin(double c)
  {
    return m_helper->Sin(c);
  }

  Copt::INlExpr* Sin(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Sin(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Sin(const Copt::IExpr* expr)
  {
    return m_helper->Sin(expr);
  }

  Copt::INlExpr* Sin(const Copt::IQuadExpr* expr)
  {
    return m_helper->Sin(expr);
  }

  Copt::INlExpr* Sin(const Copt::INlExpr* expr)
  {
    return m_helper->Sin(expr);
  }

  Copt::INlExpr* Tan(double c)
  {
    return m_helper->Tan(c);
  }

  Copt::INlExpr* Tan(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->Tan(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* Tan(const Copt::IExpr* expr)
  {
    return m_helper->Tan(expr);
  }

  Copt::INlExpr* Tan(const Copt::IQuadExpr* expr)
  {
    return m_helper->Tan(expr);
  }

  Copt::INlExpr* Tan(const Copt::INlExpr* expr)
  {
    return m_helper->Tan(expr);
  }

  Copt::INlExpr* CosH(double c)
  {
    return m_helper->CosH(c);
  }

  Copt::INlExpr* CosH(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->CosH(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* CosH(const Copt::IExpr* expr)
  {
    return m_helper->CosH(expr);
  }

  Copt::INlExpr* CosH(const Copt::IQuadExpr* expr)
  {
    return m_helper->CosH(expr);
  }

  Copt::INlExpr* CosH(const Copt::INlExpr* expr)
  {
    return m_helper->CosH(expr);
  }

  Copt::INlExpr* SinH(double c)
  {
    return m_helper->SinH(c);
  }

  Copt::INlExpr* SinH(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->SinH(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* SinH(const Copt::IExpr* expr)
  {
    return m_helper->SinH(expr);
  }

  Copt::INlExpr* SinH(const Copt::IQuadExpr* expr)
  {
    return m_helper->SinH(expr);
  }

  Copt::INlExpr* SinH(const Copt::INlExpr* expr)
  {
    return m_helper->SinH(expr);
  }

  Copt::INlExpr* TanH(double c)
  {
    return m_helper->TanH(c);
  }

  Copt::INlExpr* TanH(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->TanH(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* TanH(const Copt::IExpr* expr)
  {
    return m_helper->TanH(expr);
  }

  Copt::INlExpr* TanH(const Copt::IQuadExpr* expr)
  {
    return m_helper->TanH(expr);
  }

  Copt::INlExpr* TanH(const Copt::INlExpr* expr)
  {
    return m_helper->TanH(expr);
  }

  Copt::INlExpr* ACos(double c)
  {
    return m_helper->ACos(c);
  }

  Copt::INlExpr* ACos(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->ACos(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* ACos(const Copt::IExpr* expr)
  {
    return m_helper->ACos(expr);
  }

  Copt::INlExpr* ACos(const Copt::IQuadExpr* expr)
  {
    return m_helper->ACos(expr);
  }

  Copt::INlExpr* ACos(const Copt::INlExpr* expr)
  {
    return m_helper->ACos(expr);
  }

  Copt::INlExpr* ASin(double c)
  {
    return m_helper->ASin(c);
  }

  Copt::INlExpr* ASin(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->ASin(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* ASin(const Copt::IExpr* expr)
  {
    return m_helper->ASin(expr);
  }

  Copt::INlExpr* ASin(const Copt::IQuadExpr* expr)
  {
    return m_helper->ASin(expr);
  }

  Copt::INlExpr* ASin(const Copt::INlExpr* expr)
  {
    return m_helper->ASin(expr);
  }

  Copt::INlExpr* ATan(double c)
  {
    return m_helper->ATan(c);
  }

  Copt::INlExpr* ATan(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->ATan(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* ATan(const Copt::IExpr* expr)
  {
    return m_helper->ATan(expr);
  }

  Copt::INlExpr* ATan(const Copt::IQuadExpr* expr)
  {
    return m_helper->ATan(expr);
  }

  Copt::INlExpr* ATan(const Copt::INlExpr* expr)
  {
    return m_helper->ATan(expr);
  }

  Copt::INlExpr* ACosH(double c)
  {
    return m_helper->ACosH(c);
  }

  Copt::INlExpr* ACosH(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->ACosH(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* ACosH(const Copt::IExpr* expr)
  {
    return m_helper->ACosH(expr);
  }

  Copt::INlExpr* ACosH(const Copt::IQuadExpr* expr)
  {
    return m_helper->ACosH(expr);
  }

  Copt::INlExpr* ACosH(const Copt::INlExpr* expr)
  {
    return m_helper->ACosH(expr);
  }

  Copt::INlExpr* ASinH(double c)
  {
    return m_helper->ASinH(c);
  }

  Copt::INlExpr* ASinH(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->ASinH(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* ASinH(const Copt::IExpr* expr)
  {
    return m_helper->ASinH(expr);
  }

  Copt::INlExpr* ASinH(const Copt::IQuadExpr* expr)
  {
    return m_helper->ASinH(expr);
  }

  Copt::INlExpr* ASinH(const Copt::INlExpr* expr)
  {
    return m_helper->ASinH(expr);
  }

  Copt::INlExpr* ATanH(double c)
  {
    return m_helper->ATanH(c);
  }

  Copt::INlExpr* ATanH(const Copt::IVar* var)
  {
    Copt::INlExpr* ret = m_helper->ATanH(var);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INlExpr* ATanH(const Copt::IExpr* expr)
  {
    return m_helper->ATanH(expr);
  }

  Copt::INlExpr* ATanH(const Copt::IQuadExpr* expr)
  {
    return m_helper->ATanH(expr);
  }

  Copt::INlExpr* ATanH(const Copt::INlExpr* expr)
  {
    return m_helper->ATanH(expr);
  }

private:
  NlHelper() : m_helper(CreateNlHelper()) {}
  NlHelper(const NlHelper&);
  NlHelper& operator=(const NlHelper&);

  std::shared_ptr<Copt::INlHelper> m_helper;
};