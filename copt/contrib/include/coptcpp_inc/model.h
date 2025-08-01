#pragma once
#include <string.h>
#include "coptcpp.idl.h"
#include "var.h"
#include "column.h"
#include "columnarray.h"
#include "expr.h"
#include "quadexpr.h"
#include "exception.h"
#include "constraint.h"
#include "vararray.h"
#include "constrarray.h"
#include "constrbuilderarray.h"
#include "probbuffer.h"
#include "sosarray.h"
#include "sosbuilderarray.h"
#include "genconstrarray.h"
#include "genconstrbuilderarray.h"
#include "conearray.h"
#include "conebuilderarray.h"
#include "expconearray.h"
#include "expconebuilderarray.h"
#include "affineconearray.h"
#include "affineconebuilderarray.h"
#include "psdvar.h"
#include "psdvararray.h"
#include "psdconstraint.h"
#include "psdconstrarray.h"
#include "psdconstrbuilderarray.h"
#include "lmiexpr.h"
#include "lmiconstraint.h"
#include "lmiconstrarray.h"
#include "qconstraint.h"
#include "qconstrarray.h"
#include "qconstrbuilderarray.h"
#include "symmatrix.h"
#include "symmatrixarray.h"
#include "logcallback.h"
#include "callback.h"
#include "mconstr.h"
#include "mconstrbuilder.h"
#include "mqconstr.h"
#include "mqconstrbuilder.h"
#include "mpsdexpr.h"
#include "mpsdconstr.h"
#include "mpsdconstrbuilder.h"
#include "nlconstraint.h"
#include "nlconstrarray.h"
#include "nlconstrbuilder.h"
#include "nlconstrbuilderarray.h"

class Model {
public:
  Model(Copt::IEnvr* env, const char* szName) : m_model(CreateModel(env, szName))
  {
    CHECKERROR(m_model);
  }
  Model(Copt::IModel* model) : m_model(model) {}

  void Read(const char* szFileName)
  {
    m_model->Read(szFileName);
    CHECKERROR(m_model);
  }

  void ReadMps(const char* szFileName)
  {
    m_model->ReadMps(szFileName);
    CHECKERROR(m_model);
  }

  void ReadLp(const char* szFileName)
  {
    m_model->ReadLp(szFileName);
    CHECKERROR(m_model);
  }

  void ReadSdpa(const char* szFileName)
  {
    m_model->ReadSdpa(szFileName);
    CHECKERROR(m_model);
  }

  void ReadCbf(const char* szFileName)
  {
    m_model->ReadCbf(szFileName);
    CHECKERROR(m_model);
  }

  void ReadBin(const char* szFileName)
  {
    m_model->ReadBin(szFileName);
    CHECKERROR(m_model);
  }

  void ReadSol(const char* szFileName)
  {
    m_model->ReadSol(szFileName);
    CHECKERROR(m_model);
  }

  void ReadJsonSol(const char* szFileName)
  {
    m_model->ReadJsonSol(szFileName);
    CHECKERROR(m_model);
  }

  void ReadBasis(const char* szFileName)
  {
    m_model->ReadBasis(szFileName);
    CHECKERROR(m_model);
  }

  void ReadMst(const char* szFileName)
  {
    m_model->ReadMst(szFileName);
    CHECKERROR(m_model);
  }

  void ReadParam(const char* szFileName)
  {
    m_model->ReadParam(szFileName);
    CHECKERROR(m_model);
  }

  void ReadTune(const char* szFileName)
  {
    m_model->ReadTune(szFileName);
    CHECKERROR(m_model);
  }

  void GetParamInfo(const char* szParam, int* pnCur, int* pnDef, int* pnMin, int* pnMax)
  {
    m_model->GetParamInfo(szParam, pnCur, pnDef, pnMin, pnMax);
    CHECKERROR(m_model);
  }

  void GetParamInfo(const char* szParam, double* pdCur, double* pdDef, double* pdMin, double* pdMax)
  {
    m_model->GetParamInfo(szParam, pdCur, pdDef, pdMin, pdMax);
    CHECKERROR(m_model);
  }

  int GetIntParam(const char* szParam)
  {
    int val = m_model->GetIntParam(szParam);
    CHECKERROR(m_model);
    return val;
  }

  double GetDblParam(const char* szParam)
  {
    double val = m_model->GetDblParam(szParam);
    CHECKERROR(m_model);
    return val;
  }

  void SetIntParam(const char* szParam, int nVal)
  {
    m_model->SetIntParam(szParam, nVal);
    CHECKERROR(m_model);
  }

  void SetDblParam(const char* szParam, double dVal)
  {
    m_model->SetDblParam(szParam, dVal);
    CHECKERROR(m_model);
  }

  void Write(const char* szFileName)
  {
    m_model->Write(szFileName);
    CHECKERROR(m_model);
  }

  void WriteMps(const char* szFileName)
  {
    m_model->WriteMps(szFileName);
    CHECKERROR(m_model);
  }

  ProbBuffer WriteMpsStr()
  {
    ProbBuffer buffer = m_model->WriteMpsStr();
    CHECKERROR(m_model);
    return buffer;
  }

  void WriteLp(const char* szFileName)
  {
    m_model->WriteLp(szFileName);
    CHECKERROR(m_model);
  }

  void WriteCbf(const char* szFileName)
  {
    m_model->WriteCbf(szFileName);
    CHECKERROR(m_model);
  }

  void WriteBin(const char* szFileName)
  {
    m_model->WriteBin(szFileName);
    CHECKERROR(m_model);
  }

  void WriteNL(const char* szFileName)
  {
    m_model->WriteNL(szFileName);
    CHECKERROR(m_model);
  }

  void WriteIIS(const char* szFileName)
  {
    m_model->WriteIIS(szFileName);
    CHECKERROR(m_model);
  }

  void WriteRelax(const char* szFileName)
  {
    m_model->WriteRelax(szFileName);
    CHECKERROR(m_model);
  }

  void WriteSol(const char* szFileName)
  {
    m_model->WriteSol(szFileName);
    CHECKERROR(m_model);
  }

  void WriteJsonSol(const char* szFileName)
  {
    m_model->WriteJsonSol(szFileName);
    CHECKERROR(m_model);
  }

  void WritePoolSol(int iSol, const char* szFileName)
  {
    m_model->WritePoolSol(iSol, szFileName);
    CHECKERROR(m_model);
  }

  void WriteBasis(const char* szFileName)
  {
    m_model->WriteBasis(szFileName);
    CHECKERROR(m_model);
  }

  void WriteMst(const char* szFileName)
  {
    m_model->WriteMst(szFileName);
    CHECKERROR(m_model);
  }

  void WriteParam(const char* szFileName)
  {
    m_model->WriteParam(szFileName);
    CHECKERROR(m_model);
  }

  void WriteTuneParam(int idx, const char* szFileName)
  {
    m_model->WriteTuneParam(idx, szFileName);
    CHECKERROR(m_model);
  }

  int GetIntAttr(const char* szAttr)
  {
    int val = m_model->GetIntAttr(szAttr);
    CHECKERROR(m_model);
    return val;
  }

  double GetDblAttr(const char* szAttr)
  {
    double val = m_model->GetDblAttr(szAttr);
    CHECKERROR(m_model);
    return val;
  }

  Var AddVar(double lb, double ub, double obj, char vtype, const char* szName = nullptr)
  {
    Var var = m_model->AddVar(lb, ub, obj, vtype, szName);
    CHECKERROR(m_model);
    return var;
  }

  Var AddVar(double lb, double ub, double obj, char vtype, const Column& col, const char* szName = nullptr)
  {
    Var var = m_model->AddVar(lb, ub, obj, vtype, col.Get(), szName);
    CHECKERROR(m_model);
    return var;
  }

  VarArray AddVars(int count, char type, const char* szPrefix = "C")
  {
    VarArray vars = m_model->AddVars(count, type, szPrefix);
    CHECKERROR(m_model);
    return vars;
  }

  VarArray AddVars(int count, double lb, double ub, double obj, char vtype, const char* szPrefix = "C")
  {
    VarArray vars = m_model->AddVars(count, lb, ub, obj, vtype, szPrefix);
    CHECKERROR(m_model);
    return vars;
  }

  VarArray AddVars(int count, double* plb, double* pub, double* pobj, char* pvtype, const char* szPrefix = "C")
  {
    VarArray vars = m_model->AddVars(count, plb, pub, pobj, pvtype, szPrefix);
    CHECKERROR(m_model);
    return vars;
  }

  VarArray AddVars(int count,
    double* plb,
    double* pub,
    double* pobj,
    char* pvtype,
    const ColumnArray& cols,
    const char* szPrefix = "C")
  {
    VarArray vars = m_model->AddVars(count, plb, pub, pobj, pvtype, cols.Get(), szPrefix);
    CHECKERROR(m_model);
    return vars;
  }

  Var AddCol(double obj,
    int colCnt,
    const int* colIdx,
    const double* colElem,
    char vtype,
    double lb,
    double ub,
    const char* szName = NULL)
  {
    Var var = m_model->AddCol(obj, colCnt, colIdx, colElem, vtype, lb, ub, szName);
    CHECKERROR(m_model);
    return var;
  }

  VarArray AddCols(int count, double* pobj, char* pvtype, double* plb, double* pub, char const* const* names = NULL)
  {
    VarArray vars = m_model->AddCols(count, pobj, pvtype, plb, pub, names);
    CHECKERROR(m_model);
    return vars;
  }

  VarArray AddCols(int count,
    double* pobj,
    int* colBeg,
    int* colCnt,
    int* colIdx,
    double* colElem,
    char* pvtype,
    double* plb,
    double* pub,
    char const* const* names = NULL)
  {
    VarArray vars = m_model->AddCols(count, pobj, colBeg, colCnt, colIdx, colElem, pvtype, plb, pub, names);
    CHECKERROR(m_model);
    return vars;
  }

  template <int N> MVar<N> AddMVar(const Shape<N>& shp, char vtype, const char* szPrefix = "C")
  {
    MVar<N> vars = m_model->AddMVar(shp.Get(), vtype, szPrefix);
    CHECKERROR(m_model);
    return vars;
  }

  template <int N>
  MVar<N> AddMVar(const Shape<N>& shp, double lb, double ub, double obj, char vtype, const char* szPrefix = "C")
  {
    MVar<N> vars = m_model->AddMVar(shp.Get(), lb, ub, obj, vtype, szPrefix);
    CHECKERROR(m_model);
    return vars;
  }

  template <int N>
  MVar<N> AddMVar(const Shape<N>& shp, double* plb, double* pub, double* pobj, char* pvtype, const char* szPrefix = "C")
  {
    MVar<N> vars = m_model->AddMVar(shp.Get(), plb, pub, pobj, pvtype, szPrefix);
    CHECKERROR(m_model);
    return vars;
  }

  Constraint AddConstr(const Expr& expr, char sense, double rhs, const char* szName = nullptr)
  {
    Constraint constr = m_model->AddConstr(expr.Get(), sense, rhs, szName);
    CHECKERROR(m_model);
    return constr;
  }

  Constraint AddConstr(const Expr& lhs, char sense, const Expr& rhs, const char* szName = nullptr)
  {
    Constraint constr = m_model->AddConstr(lhs.Get(), sense, rhs.Get(), szName);
    CHECKERROR(m_model);
    return constr;
  }

  Constraint AddConstr(const Expr& expr, double lb, double ub, const char* szName = nullptr)
  {
    Constraint constr = m_model->AddConstr(expr.Get(), lb, ub, szName);
    CHECKERROR(m_model);
    return constr;
  }

  Constraint AddConstr(const ConstrBuilder& builder, const char* szName = nullptr)
  {
    Constraint constr = m_model->AddConstr(builder.Get(), szName);
    CHECKERROR(m_model);
    return constr;
  }

  ConstrArray AddConstrs(int count, char* pSense, double* pRhs, const char* szPrefix = "R")
  {
    ConstrArray constrs = m_model->AddConstrs(count, pSense, pRhs, szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  ConstrArray AddConstrs(int count, double* pLower, double* pUpper, const char* szPrefix = "R")
  {
    ConstrArray constrs = m_model->AddConstrs(count, pLower, pUpper, szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  ConstrArray AddConstrs(const ConstrBuilderArray& builders, const char* szPrefix = "R")
  {
    ConstrArray constrs = m_model->AddConstrs(builders.Get(), szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  Constraint
  AddRow(int rowCnt, const int* rowIdx, const double* rowElem, char sense, double rhs, const char* szName = NULL)
  {
    Constraint constr = m_model->AddRow(rowCnt, rowIdx, rowElem, sense, rhs, szName);
    CHECKERROR(m_model);
    return constr;
  }

  Constraint
  AddRow(int rowCnt, const int* rowIdx, const double* rowElem, double lb, double ub, const char* szName = NULL)
  {
    Constraint constr = m_model->AddRow(rowCnt, rowIdx, rowElem, lb, ub, szName);
    CHECKERROR(m_model);
    return constr;
  }

  ConstrArray AddRows(int count, char* pSense, double* pRhs, char const* const* names = NULL)
  {
    ConstrArray constrs = m_model->AddRows(count, pSense, pRhs, names);
    CHECKERROR(m_model);
    return constrs;
  }

  ConstrArray AddRows(int count, double* plb, double* pub, char const* const* names = NULL)
  {
    ConstrArray constrs = m_model->AddRows(count, plb, pub, names);
    CHECKERROR(m_model);
    return constrs;
  }

  ConstrArray AddRows(int count,
    int* rowBeg,
    int* rowCnt,
    int* rowIdx,
    double* rowElem,
    char* rowSense,
    double* rowBound,
    double* rowUpper,
    char const* const* names = NULL)
  {
    ConstrArray constrs = m_model->AddRows(count, rowBeg, rowCnt, rowIdx, rowElem, rowSense, rowBound, rowUpper, names);
    CHECKERROR(m_model);
    return constrs;
  }

  template <int N> MConstr<N> AddMConstr(const MLinExpr<N>& exprs, char sense, double rhs, const char* szPrefix = "R")
  {
    MConstr<N> constrs = m_model->AddMConstr(exprs.Get(), sense, rhs, szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  template <int N> MConstr<N> AddMConstr(const MConstrBuilder<N>& builder, const char* szPrefix = "R")
  {
    MConstr<N> constrs = m_model->AddMConstr(builder.Get(), szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  NlConstraint AddNlConstr(const NlExpr& expr, char sense, double rhs, const char* szName = NULL)
  {
    NlConstraint constr = m_model->AddNlConstr(expr.Get(), sense, rhs, szName);
    CHECKERROR(m_model);
    return constr;
  }

  NlConstraint AddNlConstr(const NlExpr& lhs, char sense, const NlExpr& rhs, const char* szName = NULL)
  {
    NlConstraint constr = m_model->AddNlConstr(lhs.Get(), sense, rhs.Get(), szName);
    CHECKERROR(m_model);
    return constr;
  }

  NlConstraint AddNlConstr(const NlExpr& expr, double lb, double ub, const char* szName = NULL)
  {
    NlConstraint constr = m_model->AddNlConstr(expr.Get(), lb, ub, szName);
    CHECKERROR(m_model);
    return constr;
  }

  NlConstraint AddNlConstr(const NlConstrBuilder& builder, const char* szName = NULL)
  {
    NlConstraint constr = m_model->AddNlConstr(builder.Get(), szName);
    CHECKERROR(m_model);
    return constr;
  }

  NlConstrArray AddNlConstrs(const NlConstrBuilderArray& builders, const char* szPrefix = "NR")
  {
    NlConstrArray constrs = m_model->AddNlConstrs(builders.Get(), szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  Sos AddSos(const SosBuilder& builder)
  {
    Sos sos = m_model->AddSos(builder.Get());
    CHECKERROR(m_model);
    return sos;
  }

  Sos AddSos(const VarArray& vars, const double* pWeights, int type)
  {
    Sos sos = m_model->AddSos(vars.Get(), pWeights, type);
    CHECKERROR(m_model);
    return sos;
  }

  GenConstr AddGenConstrIndicator(const GenConstrBuilder& builder, const char* szName = nullptr)
  {
    GenConstr indicator = m_model->AddGenConstrIndicator(builder.Get(), szName);
    CHECKERROR(m_model);
    return indicator;
  }

  GenConstr AddGenConstrIndicator(const Var& binVar,
    int binVal,
    const ConstrBuilder& builder,
    int type = COPT_INDICATOR_IF,
    const char* szName = nullptr)
  {
    GenConstr indicator = m_model->AddGenConstrIndicator(binVar.Get(), binVal, builder.Get(), type, szName);
    CHECKERROR(m_model);
    return indicator;
  }

  GenConstr AddGenConstrIndicator(const Var& binVar,
    int binVal,
    const Expr& expr,
    char sense,
    double rhs,
    int type = COPT_INDICATOR_IF,
    const char* szName = nullptr)
  {
    GenConstr indicator = m_model->AddGenConstrIndicator(binVar.Get(), binVal, expr.Get(), sense, rhs, type, szName);
    CHECKERROR(m_model);
    return indicator;
  }

  GenConstr AddGenConstrIndicators(const Var& binVar,
    int binVal,
    const MExpression& expr,
    char sense,
    double rhs,
    int type = COPT_INDICATOR_IF,
    const char* szName = nullptr)
  {
    GenConstr indicator = m_model->AddGenConstrIndicator(binVar.Get(), binVal, expr.Get(), sense, rhs, type, szName);
    CHECKERROR(m_model);
    return indicator;
  }

  GenConstrArray AddGenConstrIndicators(const GenConstrBuilderArray& builders, const char* szPrefix = nullptr)
  {
    GenConstrArray indicators = m_model->AddGenConstrIndicators(builders.Get(), szPrefix);
    CHECKERROR(m_model);
    return indicators;
  }

  template <int N>
  GenConstrArray AddGenConstrIndicators(const Var& binVar,
    int binVal,
    const MConstrBuilder<N>& builders,
    int type = COPT_INDICATOR_IF,
    const char* szPrefix = nullptr)
  {
    GenConstrArray ret = m_model->AddGenConstrIndicator(binVar.Get(), binVal, builders.Get(), type, szPrefix);
    CHECKERROR(m_model);
    return ret;
  }

  Cone AddCone(int dim, int type, char* pvtype, const char* szPrefix)
  {
    Cone cone = m_model->AddCone(dim, type, pvtype, szPrefix);
    CHECKERROR(m_model);
    return cone;
  }

  Cone AddCone(const ConeBuilder& builder)
  {
    Cone cone = m_model->AddCone(builder.Get());
    CHECKERROR(m_model);
    return cone;
  }

  Cone AddCone(const VarArray& vars, int type)
  {
    Cone cone = m_model->AddCone(vars.Get(), type);
    CHECKERROR(m_model);
    return cone;
  }

  Cone AddCone(const MVar<1>& vars, int type)
  {
    Cone cone = m_model->AddCone(vars.Get(), type);
    CHECKERROR(m_model);
    return cone;
  }

  ConeArray AddCones(const MVar<2>& vars, int type)
  {
    ConeArray cones = m_model->AddCones(vars.Get(), type);
    CHECKERROR(m_model);
    return cones;
  }

  ExpCone AddExpCone(int type, char* pvtype, const char* szPrefix)
  {
    ExpCone cone = m_model->AddExpCone(type, pvtype, szPrefix);
    CHECKERROR(m_model);
    return cone;
  }

  ExpCone AddExpCone(const ExpConeBuilder& builder)
  {
    ExpCone cone = m_model->AddExpCone(builder.Get());
    CHECKERROR(m_model);
    return cone;
  }

  ExpCone AddExpCone(const VarArray& vars, int type)
  {
    ExpCone cone = m_model->AddExpCone(vars.Get(), type);
    CHECKERROR(m_model);
    return cone;
  }

  ExpCone AddExpCone(const MVar<1>& vars, int type)
  {
    ExpCone cone = m_model->AddExpCone(vars.Get(), type);
    CHECKERROR(m_model);
    return cone;
  }

  ExpConeArray AddExpCones(const MVar<2>& vars, int type)
  {
    ExpConeArray cones = m_model->AddExpCones(vars.Get(), type);
    CHECKERROR(m_model);
    return cones;
  }

  AffineCone AddAffineCone(const AffineConeBuilder& builder, const char* szName = nullptr)
  {
    AffineCone cone = m_model->AddAffineCone(builder.Get(), szName);
    CHECKERROR(m_model);
    return cone;
  }

  AffineCone AddAffineCone(const MLinExpr<1>& exprs, int type, const char* szName = nullptr)
  {
    AffineCone cone = m_model->AddAffineCone(exprs.Get(), type, szName);
    CHECKERROR(m_model);
    return cone;
  }

  AffineConeArray AddAffineCones(const MLinExpr<2>& exprs, int type, const char* szPrefix = nullptr)
  {
    AffineConeArray cones = m_model->AddAffineCones(exprs.Get(), type, szPrefix);
    CHECKERROR(m_model);
    return cones;
  }

  AffineCone AddAffineCone(const MPsdExpr<1>& exprs, int type, const char* szName = nullptr)
  {
    AffineCone cone = m_model->AddAffineCone(exprs.Get(), type, szName);
    CHECKERROR(m_model);
    return cone;
  }

  AffineConeArray AddAffineCones(const MPsdExpr<2>& exprs, int type, const char* szPrefix = nullptr)
  {
    AffineConeArray cones = m_model->AddAffineCones(exprs.Get(), type, szPrefix);
    CHECKERROR(m_model);
    return cones;
  }

  QConstraint AddQConstr(const QuadExpr& expr, char sense, double rhs, const char* szName = nullptr)
  {
    QConstraint constr = m_model->AddQConstr(expr.Get(), sense, rhs, szName);
    CHECKERROR(m_model);
    return constr;
  }

  QConstraint AddQConstr(const QuadExpr& lhs, char sense, const QuadExpr& rhs, const char* szName = nullptr)
  {
    QConstraint constr = m_model->AddQConstr(lhs.Get(), sense, rhs.Get(), szName);
    CHECKERROR(m_model);
    return constr;
  }

  QConstraint AddQConstr(const QConstrBuilder& builder, const char* szName = nullptr)
  {
    QConstraint constr = m_model->AddQConstr(builder.Get(), szName);
    CHECKERROR(m_model);
    return constr;
  }

  template <int N>
  MQConstr<N> AddMQConstr(const MQuadExpr<N>& exprs, char sense, double rhs, const char* szPrefix = "QC")
  {
    MQConstr<N> constrs = m_model->AddMQConstr(exprs.Get(), sense, rhs, szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  template <int N> MQConstr<N> AddMQConstr(const MQConstrBuilder<N>& builder, const char* szPrefix = "QC")
  {
    MQConstr<N> constrs = m_model->AddMQConstr(builder.Get(), szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  PsdVar AddPsdVar(int dim, const char* szName = nullptr)
  {
    PsdVar var = m_model->AddPsdVar(dim, szName);
    CHECKERROR(m_model);
    return var;
  }

  PsdVarArray AddPsdVars(int count, int* pDim, const char* szPrefix = "PSDV")
  {
    PsdVarArray vars = m_model->AddPsdVars(count, pDim, szPrefix);
    CHECKERROR(m_model);
    return vars;
  }

  PsdConstraint AddPsdConstr(const PsdExpr& expr, char sense, double rhs, const char* szName = nullptr)
  {
    PsdConstraint constr = m_model->AddPsdConstr(expr.Get(), sense, rhs, szName);
    CHECKERROR(m_model);
    return constr;
  }

  PsdConstraint AddPsdConstr(const PsdExpr& expr, double lb, double ub, const char* szName = nullptr)
  {
    PsdConstraint constr = m_model->AddPsdConstr(expr.Get(), lb, ub, szName);
    CHECKERROR(m_model);
    return constr;
  }

  PsdConstraint AddPsdConstr(const PsdExpr& lhs, char sense, const PsdExpr& rhs, const char* szName = nullptr)
  {
    PsdConstraint constr = m_model->AddPsdConstr(lhs.Get(), sense, rhs.Get(), szName);
    CHECKERROR(m_model);
    return constr;
  }

  PsdConstraint AddPsdConstr(const PsdConstrBuilder& builder, const char* szName = nullptr)
  {
    PsdConstraint constr = m_model->AddPsdConstr(builder.Get(), szName);
    CHECKERROR(m_model);
    return constr;
  }

  template <int N>
  MPsdConstr<N> AddMPsdConstr(const MPsdExpr<N>& exprs, char sense, double rhs, const char* szPrefix = "PSDC")
  {
    MPsdConstr<N> constrs = m_model->AddMPsdConstr(exprs.Get(), sense, rhs, szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  template <int N> MPsdConstr<N> AddMPsdConstr(const MPsdConstrBuilder<N>& builder, const char* szPrefix = "PSDC")
  {
    MPsdConstr<N> constrs = m_model->AddMPsdConstr(builder.Get(), szPrefix);
    CHECKERROR(m_model);
    return constrs;
  }

  LmiConstraint AddLmiConstr(const LmiExpr& expr, const char* szName = nullptr)
  {
    LmiConstraint constr = m_model->AddLmiConstr(expr.Get(), szName);
    CHECKERROR(m_model);
    return constr;
  }

  void AddUserCut(const Expr& lhs, char sense, double rhs, const char* szName = nullptr)
  {
    m_model->AddUserCut(lhs.Get(), sense, rhs, szName);
    CHECKERROR(m_model);
  }

  void AddUserCut(const Expr& lhs, char sense, const Expr& rhs, const char* szName = nullptr)
  {
    m_model->AddUserCut(lhs.Get(), sense, rhs.Get(), szName);
    CHECKERROR(m_model);
  }

  void AddUserCut(const ConstrBuilder& builder, const char* szName = nullptr)
  {
    m_model->AddUserCut(builder.Get(), szName);
    CHECKERROR(m_model);
  }

  void AddUserCuts(const ConstrBuilderArray& builders, const char* szPrefix)
  {
    m_model->AddUserCuts(builders.Get(), szPrefix);
    CHECKERROR(m_model);
  }

  void AddLazyConstr(const Expr& lhs, char sense, double rhs, const char* szName = nullptr)
  {
    m_model->AddLazyConstr(lhs.Get(), sense, rhs, szName);
    CHECKERROR(m_model);
  }

  void AddLazyConstr(const Expr& lhs, char sense, const Expr& rhs, const char* szName = nullptr)
  {
    m_model->AddLazyConstr(lhs.Get(), sense, rhs.Get(), szName);
    CHECKERROR(m_model);
  }

  void AddLazyConstr(const ConstrBuilder& builder, const char* szName = nullptr)
  {
    m_model->AddLazyConstr(builder.Get(), szName);
    CHECKERROR(m_model);
  }

  void AddLazyConstrs(const ConstrBuilderArray& builders, const char* szPrefix)
  {
    m_model->AddLazyConstrs(builders.Get(), szPrefix);
    CHECKERROR(m_model);
  }

  SymMatrix AddSparseMat(int dim, int nElems, int* pRows, int* pCols, double* pVals)
  {
    SymMatrix mat = m_model->AddSparseMat(dim, nElems, pRows, pCols, pVals);
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix AddDenseMat(int dim, double* pVals, int len)
  {
    SymMatrix mat = m_model->AddDenseMat(dim, pVals, len);
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix AddDenseMat(int dim, double val)
  {
    SymMatrix mat = m_model->AddDenseMat(dim, val);
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix AddDiagMat(int dim, double* pVals, int len)
  {
    SymMatrix mat = m_model->AddDiagMat(dim, pVals, len);
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix AddDiagMat(int dim, double val)
  {
    SymMatrix mat = m_model->AddDiagMat(dim, val);
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix AddDiagMat(int dim, double* pVals, int len, int offset)
  {
    SymMatrix mat = m_model->AddDiagMat(dim, pVals, len, offset);
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix AddDiagMat(int dim, double val, int offset)
  {
    SymMatrix mat = m_model->AddDiagMat(dim, val, offset);
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix AddOnesMat(int dim)
  {
    SymMatrix mat = m_model->AddOnesMat(dim);
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix AddEyeMat(int dim)
  {
    SymMatrix mat = m_model->AddEyeMat(dim);
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix AddSymMat(const SymMatExpr& expr)
  {
    SymMatrix mat = m_model->AddSymMat(expr.Get());
    CHECKERROR(m_model);
    return mat;
  }

  SymMatrix GetSymMat(int idx)
  {
    SymMatrix mat = m_model->GetSymMat(idx);
    CHECKERROR(m_model);
    return mat;
  }

  void LoadMatrix(int nCol,
    int nRow,
    double* pCost,
    int* pMatBeg,
    int* pMatCnt,
    int* pMatIdx,
    double* pMatElem,
    double* pLHS,
    double* pRHS,
    double* pLB,
    double* pUB,
    char* pType)
  {
    m_model->LoadMatrix(nCol, nRow, pCost, pMatBeg, pMatCnt, pMatIdx, pMatElem, pLHS, pRHS, pLB, pUB, pType);
    CHECKERROR(m_model);
  }

  void GetCoeffMatrix(int* pMatBeg, int* pMatCnt, int* pMatIdx, double* pMatElem)
  {
    m_model->GetCoeffMatrix(pMatBeg, pMatCnt, pMatIdx, pMatElem);
    CHECKERROR(m_model);
  }

  void GetSolution(double* pValue)
  {
    m_model->GetSolution(pValue);
    CHECKERROR(m_model);
  }

  void GetLpSolution(double* pValue, double* pSlack, double* pRowDual, double* pRedCost)
  {
    m_model->GetLpSolution(pValue, pSlack, pRowDual, pRedCost);
    CHECKERROR(m_model);
  }

  void SetLpSolution(double* pValue, double* pSlack, double* pRowDual, double* pRedCost)
  {
    m_model->SetLpSolution(pValue, pSlack, pRowDual, pRedCost);
    CHECKERROR(m_model);
  }

  void GetPsdSolution(double* psdColValue, double* psdRowSlack, double* psdRowDual, double* psdColDual)
  {
    m_model->GetPsdSolution(psdColValue, psdRowSlack, psdRowDual, psdColDual);
    CHECKERROR(m_model);
  }

  void GetLmiSolution(double* lmiRowSlack, double* lmiRowDual)
  {
    m_model->GetLmiSolution(lmiRowSlack, lmiRowDual);
    CHECKERROR(m_model);
  }

  int GetColBasis(int* pBasis)
  {
    int status = m_model->GetColBasis(pBasis);
    CHECKERROR(m_model);
    return status;
  }

  int GetRowBasis(int* pBasis)
  {
    int status = m_model->GetRowBasis(pBasis);
    CHECKERROR(m_model);
    return status;
  }

  void SetBasis(int* pColBasis, int* pRowBasis)
  {
    m_model->SetBasis(pColBasis, pRowBasis);
    CHECKERROR(m_model);
  }

  void SetSlackBasis()
  {
    m_model->SetSlackBasis();
    CHECKERROR(m_model);
  }

  double GetPoolObjVal(int iSol)
  {
    double objVal = m_model->GetPoolObjVal(iSol);
    CHECKERROR(m_model);
    return objVal;
  }

  int GetPoolSolution(int iSol, const VarArray& vars, double* pColVals)
  {
    int len = m_model->GetPoolSolution(iSol, vars.Get(), pColVals);
    CHECKERROR(m_model);
    return len;
  }

  int GetVarLowerIIS(const VarArray& vars, int* pLowerIIS)
  {
    int numVar = m_model->GetVarLowerIIS(vars.Get(), pLowerIIS);
    CHECKERROR(m_model);
    return numVar;
  }

  int GetVarUpperIIS(const VarArray& vars, int* pUpperIIS)
  {
    int numVar = m_model->GetVarUpperIIS(vars.Get(), pUpperIIS);
    CHECKERROR(m_model);
    return numVar;
  }

  int GetConstrLowerIIS(const ConstrArray& constrs, int* pLowerIIS)
  {
    int numConstr = m_model->GetConstrLowerIIS(constrs.Get(), pLowerIIS);
    CHECKERROR(m_model);
    return numConstr;
  }

  int GetConstrUpperIIS(const ConstrArray& constrs, int* pUpperIIS)
  {
    int numConstr = m_model->GetConstrUpperIIS(constrs.Get(), pUpperIIS);
    CHECKERROR(m_model);
    return numConstr;
  }

  int GetSOSIIS(const SosArray& soss, int* pIIS)
  {
    int numSos = m_model->GetSOSIIS(soss.Get(), pIIS);
    CHECKERROR(m_model);
    return numSos;
  }

  int GetIndicatorIIS(const GenConstrArray& genconstrs, int* pIIS)
  {
    int numInd = m_model->GetIndicatorIIS(genconstrs.Get(), pIIS);
    CHECKERROR(m_model);
    return numInd;
  }

  double GetCoeff(const Constraint& constr, const Var& var)
  {
    double elem = m_model->GetCoeff(constr.Get(), var.Get());
    CHECKERROR(m_model);
    return elem;
  }

  void SetCoeff(const Constraint& constr, const Var& var, double newVal)
  {
    m_model->SetCoeff(constr.Get(), var.Get(), newVal);
    CHECKERROR(m_model);
  }

  void SetCoeffs(const ConstrArray& constrs, const VarArray& vars, double* vals, int len)
  {
    m_model->SetCoeffs(constrs.Get(), vars.Get(), vals, len);
    CHECKERROR(m_model);
  }

  SymMatrix GetPsdCoeff(const PsdConstraint& constr, const PsdVar& var)
  {
    SymMatrix mat = m_model->GetPsdCoeff(constr.Get(), var.Get());
    CHECKERROR(m_model);
    return mat;
  }

  void SetPsdCoeff(const PsdConstraint& constr, const PsdVar& var, const SymMatrix& mat)
  {
    m_model->SetPsdCoeff(constr.Get(), var.Get(), mat.Get());
    CHECKERROR(m_model);
  }

  SymMatrix GetLmiCoeff(const LmiConstraint& constr, const Var& var)
  {
    SymMatrix mat = m_model->GetLmiCoeff(constr.Get(), var.Get());
    CHECKERROR(m_model);
    return mat;
  }

  void SetLmiCoeff(const LmiConstraint& constr, const Var& var, const SymMatrix& mat)
  {
    m_model->SetLmiCoeff(constr.Get(), var.Get(), mat.Get());
    CHECKERROR(m_model);
  }

  SymMatrix GetLmiRhs(const LmiConstraint& constr)
  {
    SymMatrix mat = m_model->GetLmiRhs(constr.Get());
    CHECKERROR(m_model);
    return mat;
  }

  void SetLmiRhs(const LmiConstraint& constr, const SymMatrix& mat)
  {
    m_model->SetLmiRhs(constr.Get(), mat.Get());
    CHECKERROR(m_model);
  }

  Var GetVar(int idx) const
  {
    Var var = m_model->GetVar(idx);
    CHECKERROR(m_model);
    return var;
  }

  Var GetVarByName(const char* szName)
  {
    Var var = m_model->GetVarByName(szName);
    CHECKERROR(m_model);
    return var;
  }

  VarArray GetVars()
  {
    VarArray vars = m_model->GetVars();
    CHECKERROR(m_model);
    return vars;
  }

  void SetNames(const VarArray& vars, const char* const szNames[], int sz)
  {
    if (!szNames || sz <= 0)
    {
      return;
    }

    size_t len = 1;
    for (int i = 0; i < sz; i++)
    {
      len += strlen(szNames[i]) + 1;
    }

    std::vector<char> buffer(len, 0);

    size_t cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      snprintf(buffer.data() + cnt, len, "%s", szNames[i]);
      cnt += strlen(buffer.data() + cnt) + 1;
    }
    buffer[cnt] = '\0';

    m_model->SetNames(vars.Get(), buffer.data(), len);
    CHECKERROR(m_model);
  }

  Column GetCol(const Var& var)
  {
    Column col = m_model->GetCol(var.Get());
    CHECKERROR(m_model);
    return col;
  }

  Constraint GetConstr(int idx) const
  {
    Constraint constr = m_model->GetConstr(idx);
    CHECKERROR(m_model);
    return constr;
  }

  Constraint GetConstrByName(const char* szName)
  {
    Constraint constr = m_model->GetConstrByName(szName);
    CHECKERROR(m_model);
    return constr;
  }

  ConstrArray GetConstrs()
  {
    ConstrArray constrs = m_model->GetConstrs();
    CHECKERROR(m_model);
    return constrs;
  }

  void SetNames(const ConstrArray& cons, const char* const szNames[], int sz)
  {
    if (!szNames || sz <= 0)
    {
      return;
    }

    size_t len = 1;
    for (int i = 0; i < sz; i++)
    {
      len += strlen(szNames[i]) + 1;
    }

    std::vector<char> buffer(len, 0);

    size_t cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      snprintf(buffer.data() + cnt, len, "%s", szNames[i]);
      cnt += strlen(buffer.data() + cnt) + 1;
    }
    buffer[cnt] = '\0';

    m_model->SetNames(cons.Get(), buffer.data(), len);
    CHECKERROR(m_model);
  }

  ConstrBuilderArray GetConstrBuilders()
  {
    ConstrBuilderArray builders = m_model->GetConstrBuilders();
    CHECKERROR(m_model);
    return builders;
  }

  ConstrBuilder GetConstrBuilder(const Constraint& constr)
  {
    ConstrBuilder builder = m_model->GetConstrBuilder(constr.Get());
    CHECKERROR(m_model);
    return builder;
  }

  Expr GetRow(const Constraint& constr)
  {
    Expr expr = m_model->GetRow(constr.Get());
    CHECKERROR(m_model);
    return expr;
  }

  Sos GetSos(int idx)
  {
    Sos sos = m_model->GetSos(idx);
    CHECKERROR(m_model);
    return sos;
  }

  SosArray GetSoss()
  {
    SosArray soss = m_model->GetSoss();
    CHECKERROR(m_model);
    return soss;
  }

  SosBuilderArray GetSosBuilders()
  {
    SosBuilderArray builders = m_model->GetSosBuilders();
    CHECKERROR(m_model);
    return builders;
  }

  SosBuilderArray GetSosBuilders(SosArray& soss)
  {
    SosBuilderArray builders = m_model->GetSosBuilders(soss.Get());
    CHECKERROR(m_model);
    return builders;
  }

  GenConstr GetGenConstr(int idx) const
  {
    GenConstr constr = m_model->GetGenConstr(idx);
    CHECKERROR(m_model);
    return constr;
  }

  GenConstr GetGenConstrByName(const char* szName)
  {
    GenConstr constr = m_model->GetGenConstrByName(szName);
    CHECKERROR(m_model);
    return constr;
  }

  GenConstrArray GetGenConstrs()
  {
    GenConstrArray constrs = m_model->GetGenConstrs();
    CHECKERROR(m_model);
    return constrs;
  }

  void SetNames(const GenConstrArray& genConstrs, const char* const szNames[], int sz)
  {
    if (!szNames || sz <= 0)
    {
      return;
    }

    size_t len = 1;
    for (int i = 0; i < sz; i++)
    {
      len += strlen(szNames[i]) + 1;
    }

    std::vector<char> buffer(len, 0);

    size_t cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      snprintf(buffer.data() + cnt, len, "%s", szNames[i]);
      cnt += strlen(buffer.data() + cnt) + 1;
    }
    buffer[cnt] = '\0';

    m_model->SetNames(genConstrs.Get(), buffer.data(), len);
    CHECKERROR(m_model);
  }

  GenConstrBuilderArray GetGenConstrIndicators()
  {
    GenConstrBuilderArray builders = m_model->GetGenConstrIndicators();
    CHECKERROR(m_model);
    return builders;
  }

  GenConstrBuilder GetGenConstrIndicator(const GenConstr& indicator)
  {
    GenConstrBuilder ret = m_model->GetGenConstrIndicator(indicator.Get());
    CHECKERROR(m_model);
    return ret;
  }

  Cone GetCone(int idx)
  {
    Cone cone = m_model->GetCone(idx);
    CHECKERROR(m_model);
    return cone;
  }

  ConeArray GetCones()
  {
    ConeArray cones = m_model->GetCones();
    CHECKERROR(m_model);
    return cones;
  }

  ConeBuilderArray GetConeBuilders()
  {
    ConeBuilderArray builders = m_model->GetConeBuilders();
    CHECKERROR(m_model);
    return builders;
  }

  ConeBuilderArray GetConeBuilders(const ConeArray& cones)
  {
    ConeBuilderArray builders = m_model->GetConeBuilders(cones.Get());
    CHECKERROR(m_model);
    return builders;
  }

  ExpCone GetExpCone(int idx)
  {
    ExpCone cone = m_model->GetExpCone(idx);
    CHECKERROR(m_model);
    return cone;
  }

  ExpConeArray GetExpCones()
  {
    ExpConeArray cones = m_model->GetExpCones();
    CHECKERROR(m_model);
    return cones;
  }

  ExpConeBuilderArray GetExpConeBuilders()
  {
    ExpConeBuilderArray builders = m_model->GetExpConeBuilders();
    CHECKERROR(m_model);
    return builders;
  }

  ExpConeBuilderArray GetExpConeBuilders(const ExpConeArray& cones)
  {
    ExpConeBuilderArray builders = m_model->GetExpConeBuilders(cones.Get());
    CHECKERROR(m_model);
    return builders;
  }

  AffineCone GetAffineCone(int idx) const
  {
    AffineCone cone = m_model->GetAffineCone(idx);
    CHECKERROR(m_model);
    return cone;
  }

  AffineCone GetAffineConeByName(const char* szName)
  {
    AffineCone cone = m_model->GetAffineConeByName(szName);
    CHECKERROR(m_model);
    return cone;
  }

  AffineConeArray GetAffineCones()
  {
    AffineConeArray cones = m_model->GetAffineCones();
    CHECKERROR(m_model);
    return cones;
  }

  void SetNames(const AffineConeArray& cones, const char* const szNames[], int sz)
  {
    if (!szNames || sz <= 0)
    {
      return;
    }

    size_t len = 1;
    for (int i = 0; i < sz; i++)
    {
      len += strlen(szNames[i]) + 1;
    }

    std::vector<char> buffer(len, 0);

    size_t cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      snprintf(buffer.data() + cnt, len, "%s", szNames[i]);
      cnt += strlen(buffer.data() + cnt) + 1;
    }
    buffer[cnt] = '\0';

    m_model->SetNames(cones.Get(), buffer.data(), len);
    CHECKERROR(m_model);
  }

  AffineConeBuilder GetAffineConeBuilder(const AffineCone& cone)
  {
    AffineConeBuilder builder = m_model->GetAffineConeBuilder(cone.Get());
    CHECKERROR(m_model);
    return builder;
  }

  AffineConeBuilderArray GetAffineConeBuilders(const AffineConeArray& cones)
  {
    AffineConeBuilderArray builders = m_model->GetAffineConeBuilders(cones.Get());
    CHECKERROR(m_model);
    return builders;
  }

  AffineConeBuilderArray GetAffineConeBuilders()
  {
    AffineConeBuilderArray builders = m_model->GetAffineConeBuilders();
    CHECKERROR(m_model);
    return builders;
  }

  NlConstraint GetNlConstr(int idx) const
  {
    NlConstraint constr = m_model->GetNlConstr(idx);
    CHECKERROR(m_model);
    return constr;
  }

  NlConstraint GetNlConstrByName(const char* szName)
  {
    NlConstraint constr = m_model->GetNlConstrByName(szName);
    CHECKERROR(m_model);
    return constr;
  }

  NlConstrArray GetNlConstrs()
  {
    NlConstrArray constrs = m_model->GetNlConstrs();
    CHECKERROR(m_model);
    return constrs;
  }

  void SetNames(const NlConstrArray& cons, const char* const szNames[], int sz)
  {
    if (!szNames || sz <= 0)
    {
      return;
    }

    size_t len = 1;
    for (int i = 0; i < sz; i++)
    {
      len += strlen(szNames[i]) + 1;
    }

    std::vector<char> buffer(len, 0);

    size_t cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      snprintf(buffer.data() + cnt, len, "%s", szNames[i]);
      cnt += strlen(buffer.data() + cnt) + 1;
    }
    buffer[cnt] = '\0';

    m_model->SetNames(cons.Get(), buffer.data(), len);
    CHECKERROR(m_model);
  }

  NlConstrBuilderArray GetNlConstrBuilders()
  {
    NlConstrBuilderArray builders = m_model->GetNlConstrBuilders();
    CHECKERROR(m_model);
    return builders;
  }

  NlConstrBuilder GetNlConstrBuilder(const NlConstraint& constr)
  {
    NlConstrBuilder builder = m_model->GetNlConstrBuilder(constr.Get());
    CHECKERROR(m_model);
    return builder;
  }

  NlExpr GetNlRow(const NlConstraint& constr)
  {
    NlExpr expr = m_model->GetNlRow(constr.Get());
    CHECKERROR(m_model);
    return expr;
  }

  QConstraint GetQConstr(int idx) const
  {
    QConstraint constr = m_model->GetQConstr(idx);
    CHECKERROR(m_model);
    return constr;
  }

  QConstraint GetQConstrByName(const char* szName)
  {
    QConstraint constr = m_model->GetQConstrByName(szName);
    CHECKERROR(m_model);
    return constr;
  }

  QConstrArray GetQConstrs()
  {
    QConstrArray constrs = m_model->GetQConstrs();
    CHECKERROR(m_model);
    return constrs;
  }

  void SetNames(const QConstrArray& cons, const char* const szNames[], int sz)
  {
    if (!szNames || sz <= 0)
    {
      return;
    }

    size_t len = 1;
    for (int i = 0; i < sz; i++)
    {
      len += strlen(szNames[i]) + 1;
    }

    std::vector<char> buffer(len, 0);

    size_t cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      snprintf(buffer.data() + cnt, len, "%s", szNames[i]);
      cnt += strlen(buffer.data() + cnt) + 1;
    }
    buffer[cnt] = '\0';

    m_model->SetNames(cons.Get(), buffer.data(), len);
    CHECKERROR(m_model);
  }

  QConstrBuilderArray GetQConstrBuilders()
  {
    QConstrBuilderArray builders = m_model->GetQConstrBuilders();
    CHECKERROR(m_model);
    return builders;
  }

  QConstrBuilder GetQConstrBuilder(const QConstraint& constr)
  {
    QConstrBuilder builder = m_model->GetQConstrBuilder(constr.Get());
    CHECKERROR(m_model);
    return builder;
  }

  QuadExpr GetQuadRow(const QConstraint& constr)
  {
    QuadExpr expr = m_model->GetQuadRow(constr.Get());
    CHECKERROR(m_model);
    return expr;
  }

  PsdVar GetPsdVar(int idx) const
  {
    PsdVar var = m_model->GetPsdVar(idx);
    CHECKERROR(m_model);
    return var;
  }

  PsdVar GetPsdVarByName(const char* szName)
  {
    PsdVar var = m_model->GetPsdVarByName(szName);
    CHECKERROR(m_model);
    return var;
  }

  PsdVarArray GetPsdVars()
  {
    PsdVarArray vars = m_model->GetPsdVars();
    CHECKERROR(m_model);
    return vars;
  }

  void SetNames(const PsdVarArray& vars, const char* const szNames[], int sz)
  {
    if (!szNames || sz <= 0)
    {
      return;
    }

    size_t len = 1;
    for (int i = 0; i < sz; i++)
    {
      len += strlen(szNames[i]) + 1;
    }

    std::vector<char> buffer(len, 0);

    size_t cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      snprintf(buffer.data() + cnt, len, "%s", szNames[i]);
      cnt += strlen(buffer.data() + cnt) + 1;
    }
    buffer[cnt] = '\0';

    m_model->SetNames(vars.Get(), buffer.data(), len);
    CHECKERROR(m_model);
  }

  PsdConstraint GetPsdConstr(int idx) const
  {
    PsdConstraint constr = m_model->GetPsdConstr(idx);
    CHECKERROR(m_model);
    return constr;
  }

  PsdConstraint GetPsdConstrByName(const char* szName)
  {
    PsdConstraint constr = m_model->GetPsdConstrByName(szName);
    CHECKERROR(m_model);
    return constr;
  }

  PsdConstrArray GetPsdConstrs()
  {
    PsdConstrArray constrs = m_model->GetPsdConstrs();
    CHECKERROR(m_model);
    return constrs;
  }

  void SetNames(const PsdConstrArray& cons, const char* const szNames[], int sz)
  {
    if (!szNames || sz <= 0)
    {
      return;
    }

    size_t len = 1;
    for (int i = 0; i < sz; i++)
    {
      len += strlen(szNames[i]) + 1;
    }

    std::vector<char> buffer(len, 0);

    size_t cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      snprintf(buffer.data() + cnt, len, "%s", szNames[i]);
      cnt += strlen(buffer.data() + cnt) + 1;
    }
    buffer[cnt] = '\0';

    m_model->SetNames(cons.Get(), buffer.data(), len);
    CHECKERROR(m_model);
  }

  PsdConstrBuilderArray GetPsdConstrBuilders()
  {
    PsdConstrBuilderArray builders = m_model->GetPsdConstrBuilders();
    CHECKERROR(m_model);
    return builders;
  }

  PsdConstrBuilder GetPsdConstrBuilder(const PsdConstraint& constr)
  {
    PsdConstrBuilder builder = m_model->GetPsdConstrBuilder(constr.Get());
    CHECKERROR(m_model);
    return builder;
  }

  PsdExpr GetPsdRow(const PsdConstraint& constr)
  {
    PsdExpr expr = m_model->GetPsdRow(constr.Get());
    CHECKERROR(m_model);
    return expr;
  }

  LmiConstraint GetLmiConstr(int idx) const
  {
    LmiConstraint constr = m_model->GetLmiConstr(idx);
    CHECKERROR(m_model);
    return constr;
  }

  LmiConstraint GetLmiConstrByName(const char* szName)
  {
    LmiConstraint constr = m_model->GetLmiConstrByName(szName);
    CHECKERROR(m_model);
    return constr;
  }

  LmiConstrArray GetLmiConstrs()
  {
    LmiConstrArray constrs = m_model->GetLmiConstrs();
    CHECKERROR(m_model);
    return constrs;
  }

  void SetNames(const LmiConstrArray& cons, const char* const szNames[], int sz)
  {
    if (!szNames || sz <= 0)
    {
      return;
    }

    size_t len = 1;
    for (int i = 0; i < sz; i++)
    {
      len += strlen(szNames[i]) + 1;
    }

    std::vector<char> buffer(len, 0);

    size_t cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      snprintf(buffer.data() + cnt, len, "%s", szNames[i]);
      cnt += strlen(buffer.data() + cnt) + 1;
    }
    buffer[cnt] = '\0';

    m_model->SetNames(cons.Get(), buffer.data(), len);
    CHECKERROR(m_model);
  }

  LmiExpr GetLmiRow(const LmiConstraint& constr)
  {
    LmiExpr expr = m_model->GetLmiRow(constr.Get());
    CHECKERROR(m_model);
    return expr;
  }

  void SetObjSense(int sense)
  {
    m_model->SetObjSense(sense);
    CHECKERROR(m_model);
  }

  void SetObjConst(double constant)
  {
    m_model->SetObjConst(constant);
    CHECKERROR(m_model);
  }

  void SetObjective(const Var& var, int sense = 0)
  {
    m_model->SetObjective(Expr(var).Get(), sense);
    CHECKERROR(m_model);
  }

  void SetObjective(const Expr& expr, int sense = 0)
  {
    m_model->SetObjective(expr.Get(), sense);
    CHECKERROR(m_model);
  }

  void SetObjective(const MExpression& expr, int sense = 0)
  {
    m_model->SetObjective(expr.Get(), sense);
    CHECKERROR(m_model);
  }

  void SetObjective(const MVar<0>& var, int sense = 0)
  {
    SetObjective(var.Item(), sense);
  }

  void SetObjective(const MLinExpr<0>& expr, int sense = 0)
  {
    SetObjective(expr.Item(), sense);
  }
  void SetObjective(const MLinExpr<1>& expr, int sense = 0)
  {
    if (expr.GetSize() > 1)
    {
      throw CoptException(COPT_RETCODE_INVALID, "Argument 'expr' has multiple objects");
    }
    SetObjective(expr.Item(), sense);
  }

  void SetCost(int num, const int* list, const double* obj)
  {
    m_model->SetCost(num, list, obj);
    CHECKERROR(m_model);
  }

  Expr GetObjective() const
  {
    Expr expr = m_model->GetObjective();
    CHECKERROR(m_model);
    return expr;
  }

  void SetObjectiveN(int idx,
    const Var& var,
    int sense = 0,
    double priority = 0.0,
    double weight = 1.0,
    double abstol = 1e-6,
    double reltol = 0.0)
  {
    SetObjectiveN(idx, Expr(var), sense, priority, weight, abstol, reltol);
  }

  void SetObjectiveN(int idx,
    const Expr& expr,
    int sense = 0,
    double priority = 0.0,
    double weight = 1.0,
    double abstol = 1e-6,
    double reltol = 0.0)
  {
    m_model->SetObjectiveN(idx, expr.Get(), sense, priority, weight, abstol, reltol);
    CHECKERROR(m_model);
  }

  void SetObjectiveN(int idx,
    const MExpression& expr,
    int sense = 0,
    double priority = 0.0,
    double weight = 1.0,
    double abstol = 1e-6,
    double reltol = 0.0)
  {
    m_model->SetObjectiveN(idx, expr.Get(), sense, priority, weight, abstol, reltol);
    CHECKERROR(m_model);
  }

  void SetObjectiveN(int idx,
    const MVar<0>& var,
    int sense = 0,
    double priority = 0.0,
    double weight = 1.0,
    double abstol = 1e-6,
    double reltol = 0.0)
  {
    SetObjectiveN(idx, var.Item(), sense, priority, weight, abstol, reltol);
  }

  void SetObjectiveN(int idx,
    const MLinExpr<0>& expr,
    int sense = 0,
    double priority = 0.0,
    double weight = 1.0,
    double abstol = 1e-6,
    double reltol = 0.0)
  {
    SetObjectiveN(idx, expr.Item(), sense, priority, weight, abstol, reltol);
  }

  void SetObjectiveN(int idx,
    const MLinExpr<1>& expr,
    int sense = 0,
    double priority = 0.0,
    double weight = 1.0,
    double abstol = 1e-6,
    double reltol = 0.0)
  {
    if (expr.GetSize() > 1)
    {
      throw CoptException(COPT_RETCODE_INVALID, "Argument 'expr' has multiple objects");
    }
    SetObjectiveN(idx, expr.Item(), sense, priority, weight, abstol, reltol);
  }

  Expr GetObjectiveN(int idx) const
  {
    Expr expr = m_model->GetObjectiveN(idx);
    CHECKERROR(m_model);
    return expr;
  }

  void DelObjN(int idx)
  {
    m_model->DelObjN(idx);
    CHECKERROR(m_model);
  }

  void SetObjParamN(int idx, const char* szParam, double val)
  {
    m_model->SetObjParamN(idx, szParam, val);
    CHECKERROR(m_model);
  }

  void SetDblParamN(int idx, const char* szParam, double val)
  {
    m_model->SetDblParamN(idx, szParam, val);
    CHECKERROR(m_model);
  }

  void SetIntParamN(int idx, const char* szParam, int val)
  {
    m_model->SetIntParamN(idx, szParam, val);
    CHECKERROR(m_model);
  }

  double GetObjParamN(int idx, const char* szParam) const
  {
    double val = m_model->GetObjParamN(idx, szParam);
    CHECKERROR(m_model);
    return val;
  }

  double GetDblParamN(int idx, const char* szParam) const
  {
    double val = m_model->GetDblParamN(idx, szParam);
    CHECKERROR(m_model);
    return val;
  }

  int GetIntParamN(int idx, const char* szParam) const
  {
    int val = m_model->GetIntParamN(idx, szParam);
    CHECKERROR(m_model);
    return val;
  }

  double GetDblAttrN(int idx, const char* szAttr) const
  {
    double val = m_model->GetDblAttrN(idx, szAttr);
    CHECKERROR(m_model);
    return val;
  }

  int GetIntAttrN(int idx, const char* szAttr) const
  {
    int val = m_model->GetIntAttrN(idx, szAttr);
    CHECKERROR(m_model);
    return val;
  }

  double GetPoolObjValN(int idx, int iSol)
  {
    double objVal = m_model->GetPoolObjValN(idx, iSol);
    CHECKERROR(m_model);
    return objVal;
  }

  void ResetObjParamN(int idx)
  {
    m_model->ResetObjParamN(idx);
    CHECKERROR(m_model);
  }

  void ResetParamN(int idx)
  {
    m_model->ResetParamN(idx);
    CHECKERROR(m_model);
  }

  void SetNlObjective(const NlExpr& expr, int sense = 0)
  {
    m_model->SetNlObjective(expr.Get(), sense);
    CHECKERROR(m_model);
  }

  NlExpr GetNlObjective()
  {
    NlExpr expr = m_model->GetNlObjective();
    CHECKERROR(m_model);
    return expr;
  }

  void DelNlObj()
  {
    m_model->DelNlObj();
    CHECKERROR(m_model);
  }

  void SetQuadObjective(const QuadExpr& expr, int sense = 0)
  {
    m_model->SetQuadObjective(expr.Get(), sense);
    CHECKERROR(m_model);
  }

  void SetQuadObjective(const MQExpression& expr, int sense = 0)
  {
    m_model->SetQuadObjective(expr.Get(), sense);
    CHECKERROR(m_model);
  }

  void SetQuadObjective(const MQuadExpr<0>& expr, int sense = 0)
  {
    SetQuadObjective(expr.Item(), sense);
  }
  void SetQuadObjective(const MQuadExpr<1>& expr, int sense = 0)
  {
    if (expr.GetSize() > 1)
    {
      throw CoptException(COPT_RETCODE_INVALID, "Argument 'expr' has multiple objects");
    }
    SetQuadObjective(expr.Item(), sense);
  }

  void SetQuadCost(int nQElem, const int* pMatRow, const int* pMatCol, const double* pMatElem)
  {
    m_model->LoadQ(nQElem, pMatRow, pMatCol, pMatElem);
    CHECKERROR(m_model);
  }

  QuadExpr GetQuadObjective()
  {
    QuadExpr expr = m_model->GetQuadObjective();
    CHECKERROR(m_model);
    return expr;
  }

  void DelQuadObj()
  {
    m_model->DelQuadObj();
    CHECKERROR(m_model);
  }

  void SetPsdObjective(const PsdExpr& expr, int sense = 0)
  {
    m_model->SetPsdObjective(expr.Get(), sense);
    CHECKERROR(m_model);
  }

  void SetPsdObjective(const MPsdExpr<0>& expr, int sense = 0)
  {
    SetPsdObjective(expr.Item(), sense);
  }

  void SetPsdObjective(const MPsdExpr<1>& expr, int sense = 0)
  {
    if (expr.GetSize() > 1)
    {
      throw CoptException(COPT_RETCODE_INVALID, "Argument 'expr' has multiple objects");
    }
    SetPsdObjective(expr.Item(), sense);
  }

  PsdExpr GetPsdObjective()
  {
    PsdExpr expr = m_model->GetPsdObjective();
    CHECKERROR(m_model);
    return expr;
  }

  void DelPsdObj()
  {
    m_model->DelPsdObj();
    CHECKERROR(m_model);
  }

  void SetMipStart(int count, double* pVals)
  {
    m_model->SetMipStart(count, pVals);
    CHECKERROR(m_model);
  }

  void SetMipStart(const Var& var, double val)
  {
    m_model->SetMipStart(var.Get(), val);
    CHECKERROR(m_model);
  }

  void SetMipStart(const VarArray& vars, double* pVals)
  {
    m_model->SetMipStart(vars.Get(), pVals);
    CHECKERROR(m_model);
  }

  void LoadMipStart()
  {
    m_model->LoadMipStart();
    CHECKERROR(m_model);
  }

  void SetNlPrimalStart(int count, double* pVals)
  {
    m_model->SetNlPrimalStart(count, pVals);
    CHECKERROR(m_model);
  }

  void SetNlPrimalStart(const Var& var, double val)
  {
    m_model->SetNlPrimalStart(var.Get(), val);
    CHECKERROR(m_model);
  }

  void SetNlPrimalStart(const VarArray& vars, double* pVals)
  {
    m_model->SetNlPrimalStart(vars.Get(), pVals);
    CHECKERROR(m_model);
  }

  int Get(const char* szName, const VarArray& vars, double* pOut)
  {
    int ret = m_model->Get(szName, vars.Get(), pOut);
    CHECKERROR(m_model);
    return ret;
  }

  int Get(const char* szName, const ConstrArray& constrs, double* pOut)
  {
    int ret = m_model->Get(szName, constrs.Get(), pOut);
    CHECKERROR(m_model);
    return ret;
  }

  int Get(const char* szName, const NlConstrArray& constrs, double* pOut)
  {
    int ret = m_model->Get(szName, constrs.Get(), pOut);
    CHECKERROR(m_model);
    return ret;
  }

  int Get(const char* szName, const QConstrArray& constrs, double* pOut)
  {
    int ret = m_model->Get(szName, constrs.Get(), pOut);
    CHECKERROR(m_model);
    return ret;
  }

  int Get(const char* szName, const PsdConstrArray& constrs, double* pOut)
  {
    int ret = m_model->Get(szName, constrs.Get(), pOut);
    CHECKERROR(m_model);
    return ret;
  }

  void Set(const char* szName, const VarArray& vars, double* pVals, int len)
  {
    return m_model->Set(szName, vars.Get(), pVals, len);
    CHECKERROR(m_model);
  }

  void Set(const char* szName, const ConstrArray& constrs, double* pVals, int len)
  {
    return m_model->Set(szName, constrs.Get(), pVals, len);
    CHECKERROR(m_model);
  }

  void Set(const char* szName, const NlConstrArray& constrs, double* pVals, int len)
  {
    return m_model->Set(szName, constrs.Get(), pVals, len);
    CHECKERROR(m_model);
  }

  void Set(const char* szName, const PsdConstrArray& constrs, double* pVals, int len)
  {
    return m_model->Set(szName, constrs.Get(), pVals, len);
    CHECKERROR(m_model);
  }

  void Solve()
  {
    m_model->Solve();
    CHECKERROR(m_model);
  }
  void SolveLp()
  {
    m_model->SolveLp();
    CHECKERROR(m_model);
  }

  void ComputeIIS()
  {
    m_model->ComputeIIS();
    CHECKERROR(m_model);
  }

  void FeasRelax(const VarArray& vars,
    double* pColLowPen,
    double* pColUppPen,
    const ConstrArray& cons,
    double* pRowBndPen,
    double* pRowUppPen)
  {
    m_model->FeasRelax(vars.Get(), pColLowPen, pColUppPen, cons.Get(), pRowBndPen, pRowUppPen);
    CHECKERROR(m_model);
  }
  void FeasRelax(const MVar<1>& vars,
    double* pColLowPen,
    double* pColUppPen,
    const MConstr<1>& cons,
    double* pRowBndPen,
    double* pRowUppPen)
  {
    m_model->FeasRelax(vars.Get(), pColLowPen, pColUppPen, cons.Get(), pRowBndPen, pRowUppPen);
    CHECKERROR(m_model);
  }
  template <int N, int M>
  void FeasRelax(const MVar<N>& vars,
    const NdArray<double, N>& colLowPen,
    const NdArray<double, N>& colUppPen,
    const MConstr<M>& cons,
    const NdArray<double, M>& rowBndPen,
    const NdArray<double, M>& rowUppPen)
  {
    m_model->FeasRelax(vars.Flatten().Get(), colLowPen.Flatten().Get(), colUppPen.Flatten().Get(), cons.Flatten().Get(),
      rowBndPen.Flatten().Get(), rowUppPen.Flatten().Get());
    CHECKERROR(m_model);
  }

  void FeasRelax(int ifRelaxVars, int ifRelaxCons)
  {
    m_model->FeasRelax(ifRelaxVars, ifRelaxCons);
    CHECKERROR(m_model);
  }

  void Tune()
  {
    m_model->Tune();
    CHECKERROR(m_model);
  }
  void LoadTuneParam(int idx)
  {
    m_model->LoadTuneParam(idx);
    CHECKERROR(m_model);
  }

  void Interrupt()
  {
    m_model->Interrupt();
    CHECKERROR(m_model);
  }

  template <int N> void Remove(const MVar<N>& vars)
  {
    m_model->Remove(vars.Get());
  }
  template <int N> void Remove(const MConstr<N>& constrs)
  {
    m_model->Remove(constrs.Get());
  }
  template <int N> void Remove(const MQConstr<N>& constrs)
  {
    m_model->Remove(constrs.Get());
  }
  template <int N> void Remove(const MPsdConstr<N>& constrs)
  {
    m_model->Remove(constrs.Get());
  }

  void Remove(const VarArray& vars)
  {
    m_model->Remove(vars.Get());
  }
  void Remove(const ConstrArray& constrs)
  {
    m_model->Remove(constrs.Get());
  }
  void Remove(const NlConstrArray& constrs)
  {
    m_model->Remove(constrs.Get());
  }
  void Remove(const SosArray& soss)
  {
    m_model->Remove(soss.Get());
  }
  void Remove(const ConeArray& cones)
  {
    m_model->Remove(cones.Get());
  }
  void Remove(const ExpConeArray& cones)
  {
    m_model->Remove(cones.Get());
  }
  void Remove(const AffineConeArray& cones)
  {
    m_model->Remove(cones.Get());
  }
  void Remove(const GenConstrArray& genConstrs)
  {
    m_model->Remove(genConstrs.Get());
  }
  void Remove(const QConstrArray& constrs)
  {
    m_model->Remove(constrs.Get());
  }
  void Remove(const PsdVarArray& vars)
  {
    m_model->Remove(vars.Get());
  }
  void Remove(const PsdConstrArray& constrs)
  {
    m_model->Remove(constrs.Get());
  }
  void Remove(const LmiConstrArray& constrs)
  {
    m_model->Remove(constrs.Get());
  }

  void ResetParam()
  {
    m_model->ResetParam();
    CHECKERROR(m_model);
  }

  void ResetAll()
  {
    m_model->ResetAll();
    CHECKERROR(m_model);
  }

  void Reset()
  {
    m_model->Reset();
    CHECKERROR(m_model);
  }

  void Clear()
  {
    m_model->Clear();
    CHECKERROR(m_model);
  }

  Model Clone()
  {
    Model model = m_model->Clone();
    CHECKERROR(m_model);
    return model;
  }

  void SetCallback(ICallback* pcb, int cbctx)
  {
    m_model->SetCallback(pcb, cbctx);
    CHECKERROR(m_model);
  }

  void SetSolverLogFile(const char* szLogFile)
  {
    m_model->SetSolverLogFile(szLogFile);
    CHECKERROR(m_model);
  }

  void SetSolverLogCallback(ILogCallback* pcb)
  {
    m_model->SetSolverLogCallback(pcb);
  }

private:
  std::shared_ptr<Copt::IModel> m_model;
};
