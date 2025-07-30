#pragma once
#ifdef _WIN32
#define COPT_CALL __stdcall
#else
#define COPT_CALL
#endif
#include <memory>
#include <vector>
#include <stdint.h>

class ICallback;
class ILogCallback;

namespace Copt {
class IVar {
public:
  virtual ~IVar() = default;

  virtual int GetIdx() const = 0;
  virtual const char* GetName() const = 0;
  virtual void SetName(const char* szName) = 0;
  virtual char GetType() const = 0;
  virtual void SetType(char type) = 0;
  virtual int GetBasis() const = 0;
  virtual int GetLowerIIS() const = 0;
  virtual int GetUpperIIS() const = 0;

  virtual double Get(const char* szAttr) = 0;
  virtual void Set(const char* szAttr, double value) = 0;

  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IVarArray {
public:
  virtual ~IVarArray() = default;

  virtual void PushBack(const IVar* pVar) = 0;

  virtual int Size() const = 0;
  virtual IVar* GetVar(int idx) const = 0;
  virtual std::vector<IVar*> GetAll() = 0;
  virtual void Reserve(int n) = 0;
};

class IConstraint {
public:
  virtual ~IConstraint() = default;

  virtual int GetIdx() const = 0;
  virtual const char* GetName() const = 0;
  virtual void SetName(const char* szName) = 0;
  virtual int GetBasis() const = 0;
  virtual int GetLowerIIS() const = 0;
  virtual int GetUpperIIS() const = 0;

  virtual double Get(const char* szAttr) = 0;
  virtual void Set(const char* szAttr, double value) = 0;

  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IConstrArray {
public:
  virtual ~IConstrArray() = default;

  virtual void PushBack(const IConstraint* pConstr) = 0;

  virtual int Size() const = 0;
  virtual IConstraint* GetConstr(int idx) const = 0;
  virtual std::vector<IConstraint*> GetAll() = 0;
  virtual void Reserve(int n) = 0;
};

class IColumn {
public:
  virtual ~IColumn() = default;

  virtual int Size() const = 0;
  virtual IConstraint* GetConstr(int i) const = 0;
  virtual double GetCoeff(int i) const = 0;

  virtual void AddTerm(const IConstraint* pConstr, double coeff) = 0;
  virtual int AddTerms(const IConstrArray* pConstrs, double* pCoeff, int len) = 0;
  virtual void AddColumn(const IColumn* pCol, double mult) = 0;

  virtual void Remove(int idx) = 0;
  virtual void Remove(const IConstraint* pConstr) = 0;
  virtual void Reserve(int n) = 0;
  virtual void Clear() = 0;
  virtual IColumn* Clone() const = 0;
};

class IColumnArray {
public:
  virtual ~IColumnArray() = default;

  virtual void PushBack(const IColumn* pCol) = 0;

  virtual int Size() const = 0;
  virtual IColumn* GetColumn(int idx) const = 0;
  virtual void Reserve(int n) = 0;
  virtual void Clear() = 0;
};

class IExpr {
public:
  virtual ~IExpr() = default;

  virtual size_t Size() const = 0;
  virtual IVar* GetVar(int i) const = 0;
  virtual double GetCoeff(int i) const = 0;
  virtual double GetConstant() const = 0;

  virtual void SetCoeff(int i, double value) = 0;
  virtual void SetConstant(double constant) = 0;
  virtual void AddConstant(double constant) = 0;

  virtual void AddTerm(const IVar* pVar, double coeff) = 0;
  virtual int AddTerms(const IVarArray* pVars, double* pCoeff, int len) = 0;
  virtual void AddExpr(const IExpr* pExpr, double mult) = 0;

  virtual double Evaluate() = 0;
  virtual void Remove(int idx) = 0;
  virtual void Remove(const IVar* pVar) = 0;
  virtual void Reserve(int n) = 0;
  virtual void Clear() const = 0;
  virtual IExpr* Clone() const = 0;

  virtual void iDivide(double c) = 0;
  virtual void iMultiply(double c) = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IQuadExpr {
public:
  virtual ~IQuadExpr() = default;

  virtual size_t Size() const = 0;
  virtual IVar* GetVar1(int i) const = 0;
  virtual IVar* GetVar2(int i) const = 0;
  virtual double GetCoeff(int i) const = 0;
  virtual double GetConstant() const = 0;
  virtual IExpr* GetLinExpr() const = 0;

  virtual void SetCoeff(int i, double value) = 0;
  virtual void SetConstant(double constant) = 0;
  virtual void AddConstant(double constant) = 0;

  virtual void AddTerm(const IVar* pVar, double coeff) = 0;
  virtual void AddTerm(const IVar* pVar1, const IVar* pVar2, double coeff) = 0;
  virtual int AddTerms(const IVarArray* pVars, double* pCoeff, int len) = 0;
  virtual int AddTerms(const IVarArray* pVars1, const IVarArray* pVars2, double* pCoeff, int len) = 0;
  virtual void AddLinExpr(const IExpr* pExpr, double mult) = 0;
  virtual void AddQuadExpr(const IQuadExpr* pExpr, double mult) = 0;
  virtual void AddQuadExpr(const IExpr* pLeft, const IExpr* pRight) = 0;
  virtual void AddQuadExpr(const IExpr* pExpr, const IVar* pVar) = 0;

  virtual double Evaluate() = 0;
  virtual void Remove(int idx) = 0;
  virtual void Remove(const IVar* pVar) = 0;
  virtual void Reserve(int n) = 0;
  virtual void Clear() const = 0;
  virtual IQuadExpr* Clone() const = 0;

  virtual void iDivide(double c) = 0;
  virtual void iMultiply(double c) = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IConstrBuilder {
public:
  virtual ~IConstrBuilder() = default;

  virtual IExpr* GetExpr() const = 0;
  virtual char GetSense() const = 0;
  virtual double GetRange() const = 0;
  virtual void Set(const IExpr* expr, char sense, double rhs) const = 0;
  virtual void SetRange(const IExpr* expr, double range) const = 0;
};

class IConstrBuilderArray {
public:
  virtual ~IConstrBuilderArray() = default;

  virtual void PushBack(const IConstrBuilder* pcb) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual IConstrBuilder* GetBuilder(int idx) const = 0;
};

class ISos {
public:
  virtual ~ISos() = default;

  virtual int GetIdx() const = 0;
  virtual int GetIIS() const = 0;
  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class ISosArray {
public:
  virtual ~ISosArray() = default;

  virtual void PushBack(const ISos* pSos) = 0;

  virtual int Size() const = 0;
  virtual ISos* GetSos(int idx) const = 0;
};

class ISosBuilder {
public:
  virtual ~ISosBuilder() = default;

  virtual int GetType() const = 0;
  virtual int GetSize() const = 0;
  virtual IVar* GetVar(int idx) const = 0;
  virtual IVarArray* GetVars() const = 0;
  virtual double GetWeight(int idx) const = 0;
  virtual void GetWeights(double* pOut) const = 0;

  virtual void Set(const IVarArray* vars, double* pWeights, int type) = 0;
};

class ISosBuilderArray {
public:
  virtual ~ISosBuilderArray() = default;

  virtual void PushBack(const ISosBuilder* pcb) = 0;

  virtual int Size() const = 0;
  virtual ISosBuilder* GetBuilder(int idx) const = 0;
};

class IGenConstr {
public:
  virtual ~IGenConstr() = default;

  virtual int GetIdx() const = 0;
  virtual const char* GetName() const = 0;
  virtual void SetName(const char* szName) = 0;

  virtual int GetIIS() const = 0;
  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IGenConstrArray {
public:
  virtual ~IGenConstrArray() = default;

  virtual void PushBack(const IGenConstr* pConstr) = 0;

  virtual int Size() const = 0;
  virtual std::vector<IGenConstr*> GetAll() = 0;
  virtual IGenConstr* GetGenConstr(int idx) const = 0;
  virtual void Reserve(int n) = 0;
};

class IGenConstrBuilder {
public:
  virtual ~IGenConstrBuilder() = default;

  virtual IVar* GetBinVar() const = 0;
  virtual int GetBinVal() const = 0;
  virtual IExpr* GetExpr() const = 0;
  virtual char GetSense() const = 0;
  virtual int GetIndType() const = 0;

  virtual void Set(const IVar* binVar, int binVal, const IExpr* expr, char sense, int type) = 0;
};

class IGenConstrBuilderArray {
public:
  virtual ~IGenConstrBuilderArray() = default;

  virtual void PushBack(const IGenConstrBuilder* pcb) = 0;

  virtual int Size() const = 0;
  virtual IGenConstrBuilder* GetBuilder(int idx) const = 0;
};

class ICone {
public:
  virtual ~ICone() = default;

  virtual int GetIdx() const = 0;
  virtual void Remove() = 0;
};

class IConeArray {
public:
  virtual ~IConeArray() = default;

  virtual void PushBack(const ICone* pCone) = 0;

  virtual int Size() const = 0;
  virtual ICone* GetCone(int idx) const = 0;
};

class IConeBuilder {
public:
  virtual ~IConeBuilder() = default;

  virtual int GetType() const = 0;
  virtual int GetSize() const = 0;
  virtual IVar* GetVar(int idx) const = 0;
  virtual IVarArray* GetVars() const = 0;

  virtual void Set(const IVarArray* vars, int type) = 0;
};

class IConeBuilderArray {
public:
  virtual ~IConeBuilderArray() = default;

  virtual void PushBack(const IConeBuilder* pcb) = 0;

  virtual int Size() const = 0;
  virtual IConeBuilder* GetBuilder(int idx) const = 0;
};

class IExpCone {
public:
  virtual ~IExpCone() = default;

  virtual int GetIdx() const = 0;
  virtual void Remove() = 0;
};

class IExpConeArray {
public:
  virtual ~IExpConeArray() = default;

  virtual void PushBack(const IExpCone* pCone) = 0;

  virtual int Size() const = 0;
  virtual IExpCone* GetCone(int idx) const = 0;
};

class IExpConeBuilder {
public:
  virtual ~IExpConeBuilder() = default;

  virtual int GetType() const = 0;
  virtual int GetSize() const = 0;
  virtual IVar* GetVar(int idx) const = 0;
  virtual IVarArray* GetVars() const = 0;

  virtual void Set(const IVarArray* vars, int type) = 0;
};

class IExpConeBuilderArray {
public:
  virtual ~IExpConeBuilderArray() = default;

  virtual void PushBack(const IExpConeBuilder* pcb) = 0;

  virtual int Size() const = 0;
  virtual IExpConeBuilder* GetBuilder(int idx) const = 0;
};

class IAffineCone {
public:
  virtual ~IAffineCone() = default;

  virtual int GetIdx() const = 0;
  virtual const char* GetName() const = 0;
  virtual void SetName(const char* szName) = 0;

  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IAffineConeArray {
public:
  virtual ~IAffineConeArray() = default;

  virtual void PushBack(const IAffineCone* cone) = 0;

  virtual void Reserve(int n) = 0;
  virtual int Size() const = 0;
  virtual IAffineCone* GetCone(int idx) const = 0;
  virtual std::vector<IAffineCone*> GetAll() = 0;
};

class IPsdExpr;
template <int N> class IMLinExpr;
template <int N> class IMPsdExpr;
class IAffineConeBuilder {
public:
  virtual ~IAffineConeBuilder() = default;

  virtual int GetSize() const = 0;
  virtual int GetType() const = 0;
  virtual bool HasPsdTerm() const = 0;
  virtual IExpr* GetExpr(int i) const = 0;
  virtual IPsdExpr* GetPsdExpr(int i) const = 0;
  virtual IMLinExpr<1>* GetExprs() = 0;
  virtual IMPsdExpr<1>* GetPsdExprs() = 0;

  virtual void Set(const IMPsdExpr<1>* exprs, int type) = 0;
  virtual void Set(const std::vector<IPsdExpr*>& exprs, int type) = 0;
  virtual void Set(const IMLinExpr<1>* exprs, int type) = 0;
  virtual void Set(const std::vector<IExpr*>& exprs, int type) = 0;
};

class IAffineConeBuilderArray {
public:
  virtual ~IAffineConeBuilderArray() = default;

  virtual void PushBack(const IAffineConeBuilder* builder) = 0;

  virtual int Size() const = 0;
  virtual IAffineConeBuilder* GetBuilder(int i) const = 0;
};

class IQConstraint {
public:
  virtual ~IQConstraint() = default;

  virtual int GetIdx() const = 0;
  virtual const char* GetName() const = 0;
  virtual void SetName(const char* szName) = 0;

  virtual double GetRhs() const = 0;
  virtual char GetSense() const = 0;
  virtual void SetRhs(double rhs) = 0;
  virtual void SetSense(char sense) = 0;

  virtual double Get(const char* szAttr) = 0;
  virtual void Set(const char* szAttr, double value) = 0;

  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IQConstrArray {
public:
  virtual ~IQConstrArray() = default;

  virtual void PushBack(const IQConstraint* pConstr) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual IQConstraint* GetQConstr(int idx) const = 0;
};

class IQConstrBuilder {
public:
  virtual ~IQConstrBuilder() = default;

  virtual IQuadExpr* GetQuadExpr() const = 0;
  virtual char GetSense() const = 0;
  virtual void Set(const IQuadExpr* expr, char sense, double rhs) const = 0;
};

class IQConstrBuilderArray {
public:
  virtual ~IQConstrBuilderArray() = default;

  virtual void PushBack(const IQConstrBuilder* pcb) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual IQConstrBuilder* GetBuilder(int idx) const = 0;
};

class IView;
template <class T, int N> class INdArray;

class IPsdVar {
public:
  virtual ~IPsdVar() = default;

  virtual int GetIdx() const = 0;
  virtual int GetDim() const = 0;
  virtual int GetLen() const = 0;
  virtual int GetSize() const = 0;

  virtual const char* GetName() const = 0;
  virtual void SetName(const char* szName) = 0;

  virtual void Get(const char* szAttr, double* pOut, int sz) = 0;
  virtual INdArray<double, 2>* Get(const char* szAttr) = 0;

  virtual IMPsdExpr<1>* Diagonal(int offset) const = 0;
  virtual IMPsdExpr<2>* Item(const IView* view) const = 0;
  virtual IMPsdExpr<1>* Pick(const INdArray<int, 1>* indexes) const = 0;
  virtual IMPsdExpr<1>* Pick(const INdArray<int, 2>* idxrows) const = 0;
  virtual IPsdExpr* Sum() const = 0;
  virtual IMPsdExpr<2>* ToExpr() const = 0;

  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IPsdVarArray {
public:
  virtual ~IPsdVarArray() = default;

  virtual void PushBack(const IPsdVar* pVar) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual std::vector<IPsdVar*> GetAll() = 0;
  virtual IPsdVar* GetPsdVar(int idx) const = 0;
};

class ISymMatrix {
public:
  virtual ~ISymMatrix() = default;

  virtual int GetIdx() const = 0;
  virtual int GetDim() const = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class ISymMatrixArray {
public:
  virtual ~ISymMatrixArray() = default;

  virtual void PushBack(const ISymMatrix* pMat) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual ISymMatrix* GetMatrix(int idx) const = 0;
};

class ISymMatExpr {
public:
  virtual ~ISymMatExpr() = default;

  virtual int GetDim() const = 0;
  virtual size_t Size() const = 0;
  virtual ISymMatrix* GetSymMat(int i) const = 0;
  virtual double GetCoeff(int i) const = 0;
  virtual void SetCoeff(int i, double value) = 0;

  virtual bool AddTerm(const ISymMatrix* pMat, double coeff) = 0;
  virtual int AddTerms(const ISymMatrixArray* pMats, double* pCoeff, int len) = 0;
  virtual void AddSymMatExpr(const ISymMatExpr* pExpr, double mult) = 0;

  virtual void Remove(int idx) = 0;
  virtual void Remove(const ISymMatrix* pMat) = 0;
  virtual void Reserve(int n) = 0;
  virtual ISymMatExpr* Clone() const = 0;

  virtual void iMultiply(double c) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IMExpression;
class IPsdExpr {
public:
  virtual ~IPsdExpr() = default;

  virtual size_t Size() const = 0;
  virtual IPsdVar* GetPsdVar(int i) const = 0;
  virtual ISymMatExpr* GetCoeff(int i) const = 0;
  virtual double GetConstant() const = 0;
  virtual IExpr* GetLinExpr() const = 0;

  virtual void SetCoeff(int i, ISymMatrix* pMat) = 0;
  virtual void SetConstant(double constant) = 0;
  virtual void AddConstant(double constant) = 0;

  virtual void AddTerm(const IVar* pVar, double coeff) = 0;
  virtual void AddTerm(const IPsdVar* pVar, const ISymMatrix* pMat) = 0;
  virtual void AddTerm(const IPsdVar* pVar, const ISymMatExpr* pExpr) = 0;
  virtual int AddTerms(const IVarArray* pVars, double* pCoeff, int len) = 0;
  virtual int AddTerms(const IPsdVarArray* pVars, const ISymMatrixArray* pMats) = 0;
  virtual void AddLinExpr(const IExpr* pExpr, double mult) = 0;
  virtual void AddPsdExpr(const IPsdExpr* pExpr, double mult) = 0;
  virtual void AddMExpr(const IMExpression* pExpr, double mult) = 0;

  virtual double Evaluate() = 0;
  virtual void Remove(int idx) = 0;
  virtual void Remove(const IVar* pVar) = 0;
  virtual void Remove(const IPsdVar* pVar) = 0;
  virtual void Reserve(int n) = 0;
  virtual IPsdExpr* Clone() const = 0;

  virtual void iMultiply(double c) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IPsdConstraint {
public:
  virtual ~IPsdConstraint() = default;

  virtual int GetIdx() const = 0;
  virtual const char* GetName() const = 0;
  virtual void SetName(const char* szName) = 0;

  virtual double Get(const char* szAttr) = 0;
  virtual void Set(const char* szAttr, double value) = 0;

  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IPsdConstrArray {
public:
  virtual ~IPsdConstrArray() = default;

  virtual void PushBack(const IPsdConstraint* pConstr) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual IPsdConstraint* GetPsdConstr(int idx) const = 0;
};

class IPsdConstrBuilder {
public:
  virtual ~IPsdConstrBuilder() = default;

  virtual IPsdExpr* GetPsdExpr() const = 0;
  virtual char GetSense() const = 0;
  virtual double GetRange() const = 0;
  virtual void Set(const IPsdExpr* expr, char sense, double rhs) const = 0;
  virtual void SetRange(const IPsdExpr* expr, double range) const = 0;
};

class IPsdConstrBuilderArray {
public:
  virtual ~IPsdConstrBuilderArray() = default;

  virtual void PushBack(const IPsdConstrBuilder* pcb) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual IPsdConstrBuilder* GetBuilder(int idx) const = 0;
};

class ILmiExpr {
public:
  virtual ~ILmiExpr() = default;

  virtual size_t Size() const = 0;
  virtual IVar* GetVar(int i) const = 0;
  virtual ISymMatExpr* GetCoeff(int i) const = 0;
  virtual ISymMatExpr* GetConstant() const = 0;

  virtual void SetCoeff(int i, const ISymMatrix* pMat) = 0;
  virtual void SetConstant(const ISymMatrix* pMat) = 0;
  virtual void AddConstant(const ISymMatExpr* pExpr) = 0;

  virtual void AddTerm(const IVar* pVar, const ISymMatrix* pMat) = 0;
  virtual void AddTerm(const IVar* pVar, const ISymMatExpr* pExpr) = 0;
  virtual int AddTerms(const IVarArray* pVars, const ISymMatrixArray* pMats) = 0;
  virtual void AddLmiExpr(const ILmiExpr* pExpr, double mult) = 0;

  virtual void Remove(int idx) = 0;
  virtual void Remove(const IVar* pVar) = 0;
  virtual void Reserve(int n) = 0;
  virtual ILmiExpr* Clone() const = 0;

  virtual void iMultiply(double c) = 0;
};

class ILmiConstraint {
public:
  virtual ~ILmiConstraint() = default;

  virtual int GetIdx() const = 0;
  virtual int GetDim() const = 0;
  virtual int GetLen() const = 0;

  virtual const char* GetName() const = 0;
  virtual void SetName(const char* szName) = 0;

  virtual void Get(const char* szAttr, double* pOut, int len) = 0;
  virtual void SetRhs(const ISymMatrix* pMat) = 0;

  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class ILmiConstrArray {
public:
  virtual ~ILmiConstrArray() = default;

  virtual void PushBack(const ILmiConstraint* pConstr) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual ILmiConstraint* GetLmiConstr(int idx) const = 0;
};

class INlExpr {
public:
  virtual ~INlExpr() = default;

  virtual size_t Size() const = 0;

  virtual double GetConstant() const = 0;
  virtual IExpr* GetLinExpr() const = 0;
  virtual void SetConstant(double constant) = 0;
  virtual void AddConstant(double constant) = 0;

  virtual void AddTerm(const IVar* pVar, double coeff) = 0;
  virtual int AddTerms(const IVarArray* pVars, double* pCoeff, int len) = 0;
  virtual void AddLinExpr(const IExpr* pExpr, double mult) = 0;
  virtual void AddQuadExpr(const IQuadExpr* pExpr, double mult) = 0;
  virtual void AddNlExpr(const INlExpr* pExpr, double mult) = 0;

  virtual void Clear() = 0;
  virtual INlExpr* Clone() const = 0;
  virtual double Evaluate() = 0;
  virtual void Reserve(int n) = 0;

  virtual void iDivide(double c) = 0;
  virtual void iDivide(const IVar* pVar) = 0;
  virtual void iDivide(const IExpr* pExpr) = 0;
  virtual void iDivide(const IQuadExpr* pExpr) = 0;
  virtual void iDivide(const INlExpr* pExpr) = 0;

  virtual void iMultiply(double c) = 0;
  virtual void iMultiply(const IVar* pVar) = 0;
  virtual void iMultiply(const IExpr* pExpr) = 0;
  virtual void iMultiply(const IQuadExpr* pExpr) = 0;
  virtual void iMultiply(const INlExpr* pExpr) = 0;

  virtual void Negate() = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class INlConstraint {
public:
  virtual ~INlConstraint() = default;

  virtual int GetIdx() const = 0;

  virtual const char* GetName() const = 0;
  virtual void SetName(const char* szName) = 0;

  virtual double Get(const char* szInfo) = 0;
  virtual void Set(const char* szInfo, double value) = 0;

  virtual void Remove() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class INlConstrArray {
public:
  virtual ~INlConstrArray() = default;

  virtual void PushBack(const INlConstraint* pConstr) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual INlConstraint* GetNlConstr(int idx) const = 0;
};

class INlConstrBuilder {
public:
  virtual ~INlConstrBuilder() = default;

  virtual INlExpr* GetNlExpr() const = 0;
  virtual char GetSense() const = 0;
  virtual double GetRange() const = 0;
  virtual void Set(const INlExpr* expr, char sense, double rhs) const = 0;
  virtual void SetRange(const INlExpr* expr, double range) const = 0;

  virtual const char* Represent(size_t maxlen) = 0;
};

class INlConstrBuilderArray {
public:
  virtual ~INlConstrBuilderArray() = default;

  virtual void PushBack(const INlConstrBuilder* pcb) = 0;

  virtual int Size() const = 0;
  virtual void Reserve(int n) = 0;
  virtual INlConstrBuilder* GetBuilder(int idx) const = 0;
};

class IProbBuffer {
public:
  virtual ~IProbBuffer() = default;

  virtual char* GetData() = 0;
  virtual int Size() const = 0;
  virtual void Resize(int sz) = 0;
};

class IView {
public:
  virtual ~IView() = default;

  virtual IView* AddFull() const = 0;
  virtual IView* AddScalar(int64_t n) const = 0;
  virtual IView* AddSlice(int64_t start, int64_t stop, int64_t step, int flag) const = 0;
};

template <int N> class INDim {
public:
  virtual ~INDim() = default;

  virtual int GetND() const = 0;
  virtual size_t GetDim(int i) const = 0;
  virtual size_t GetSize() const = 0;
  virtual int64_t GetStride(int i) const = 0;
  virtual int64_t GetStart(int i) const = 0;

  virtual INDim<N>* Rebuild() const = 0;
  virtual INDim<N>* RebuildWith(size_t dim) const = 0;

  virtual const char* Represent(int type) = 0;

  // strong comparison, having the same dims, strides and starts
  virtual bool Equals(const INDim<N>* other) const = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <class T, int N> class INdArray {
public:
  virtual ~INdArray() = default;

  virtual int GetND() const = 0;
  virtual size_t GetDim(int i) const = 0;
  virtual size_t GetSize() const = 0;
  virtual INDim<N>* GetShape() const = 0;

  virtual INdArray<T, 1>* Reshape(const INDim<1>* shape) const = 0;
  virtual INdArray<T, 2>* Reshape(const INDim<2>* shape) const = 0;
  virtual INdArray<T, 3>* Reshape(const INDim<3>* shape) const = 0;

  virtual INdArray<T, 1>* Flatten() const = 0;
  virtual INdArray<T, N>* Repeat(size_t repeats, int axis) const = 0;
  virtual INdArray<T, N>* RepeatBlock(size_t repeats, int axis) const = 0;
  virtual INdArray<T, 0>* Sum() const = 0;
  virtual INdArray<T, N>* Transpose() const = 0;

  virtual T Item(size_t idx) const = 0;
  virtual INdArray<T, N>* Item(const IView* view) const = 0;
  virtual INdArray<T, 1>* Pick(const INdArray<int, 1>* indexes) const = 0;
  virtual INdArray<T, 1>* Pick(const INdArray<int, 2>* idxrows) const = 0;
  virtual void SetItem(size_t idx, T val) const = 0;
  virtual void Fill(T val) const = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMConstr {
public:
  virtual ~IMConstr() = default;

  virtual int GetND() const = 0;
  virtual size_t GetDim(int i) const = 0;
  virtual size_t GetSize() const = 0;
  virtual INDim<N>* GetShape() const = 0;

  virtual INdArray<int, N>* GetBasis() const = 0;
  virtual INdArray<int, N>* GetIdx() const = 0;
  virtual INdArray<int, N>* GetLowerIIS() const = 0;
  virtual INdArray<int, N>* GetUpperIIS() const = 0;
  virtual INdArray<double, N>* Get(const char* szInfo) const = 0;
  virtual void Set(const char* szInfo, double val) const = 0;
  virtual void Set(const char* szInfo, INdArray<double, N>* vals) const = 0;

  virtual IMConstr<1>* Reshape(const INDim<1>* shape) const = 0;
  virtual IMConstr<2>* Reshape(const INDim<2>* shape) const = 0;
  virtual IMConstr<3>* Reshape(const INDim<3>* shape) const = 0;

  virtual IMConstr<1>* Flatten() const = 0;
  virtual IMConstr<N>* Transpose() const = 0;

  virtual IConstraint* Item(size_t idx) const = 0;
  virtual IMConstr<N>* Item(const IView* view) const = 0;
  virtual IMConstr<1>* Pick(const INdArray<int, 1>* indexes) const = 0;
  virtual IMConstr<1>* Pick(const INdArray<int, 2>* idxrows) const = 0;
  virtual void SetItem(size_t idx, const IConstraint* con) const = 0;
  virtual IMConstr<N>* Clone() const = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IMExpression {
public:
  virtual ~IMExpression() = default;

  virtual double GetConstant() const = 0;
  virtual void AddConstant(double constant) = 0;
  virtual void SetConstant(double constant) = 0;

  virtual void AddTerm(const IVar* pVar, double coeff) = 0;
  virtual void AddExpr(const IExpr* pExpr, double mult) = 0;
  virtual void AddMExpr(const IMExpression* pExpr, double mult) = 0;

  virtual void iMultiply(double constant) = 0;

  virtual IMExpression* Clone() const = 0;
  virtual double Evaluate() = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMVar;

template <int N> class IMLinExpr {
public:
  virtual ~IMLinExpr() = default;

  virtual int GetND() const = 0;
  virtual size_t GetDim(int i) const = 0;
  virtual size_t GetSize() const = 0;
  virtual INDim<N>* GetShape() const = 0;

  virtual IMLinExpr<1>* Reshape(const INDim<1>* shape) const = 0;
  virtual IMLinExpr<2>* Reshape(const INDim<2>* shape) const = 0;
  virtual IMLinExpr<3>* Reshape(const INDim<3>* shape) const = 0;

  virtual IMLinExpr<1>* Flatten() const = 0;
  virtual IMLinExpr<N>* Repeat(size_t repeats, int axis) const = 0;
  virtual IMLinExpr<N>* RepeatBlock(size_t repeats, int axis) const = 0;
  virtual IMLinExpr<0>* Sum() const = 0;
  virtual IMLinExpr<N>* Transpose() const = 0;

  virtual IMExpression* Item(size_t idx) const = 0;
  virtual IMLinExpr<N>* Item(const IView* view) const = 0;
  virtual IMLinExpr<1>* Pick(const INdArray<int, 1>* indexes) const = 0;
  virtual IMLinExpr<1>* Pick(const INdArray<int, 2>* idxrows) const = 0;
  virtual void SetItem(size_t idx, const IMExpression* expr) const = 0;

  virtual void iMultiply(double constant) = 0;
  virtual void AddConstant(double constant) = 0;
  virtual void AddConstant(const INdArray<double, N>* constants) = 0;
  virtual void AddConstant(const INdArray<int64_t, N>* constants) = 0;
  virtual void AddConstant(const INdArray<int, N>* constants) = 0;
  virtual void SubConstant(const INdArray<double, N>* constants) = 0;
  virtual void SubConstant(const INdArray<int64_t, N>* constants) = 0;
  virtual void SubConstant(const INdArray<int, N>* constants) = 0;

  virtual void AddTerm(const IVar* var, double coeff) = 0;
  virtual void AddTerms(const IMVar<N>* vars, double mult) = 0;
  virtual void AddTerms(const IMVar<N>* vars, const INdArray<double, N>* coeffs) = 0;
  virtual void AddExpr(const IExpr* expr, double mult) = 0;
  virtual void AddMExpr(const IMExpression* expr, double mult) = 0;
  virtual void AddMLinExpr(const IMLinExpr<N>* exprs, double mult) = 0;

  virtual void Clear() const = 0;
  virtual IMLinExpr<N>* Clone() const = 0;
  virtual INdArray<double, N>* Evaluate() = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMVar {
public:
  virtual ~IMVar() = default;

  virtual int GetND() const = 0;
  virtual size_t GetDim(int i) const = 0;
  virtual size_t GetSize() const = 0;
  virtual INDim<N>* GetShape() const = 0;

  virtual INdArray<int, N>* GetBasis() const = 0;
  virtual INdArray<int, N>* GetIdx() const = 0;
  virtual INdArray<int, N>* GetLowerIIS() const = 0;
  virtual INdArray<int, N>* GetUpperIIS() const = 0;
  virtual INdArray<char, N>* GetType() const = 0;
  virtual INdArray<double, N>* Get(const char* szInfo) const = 0;
  virtual void Set(const char* szInfo, double val) const = 0;
  virtual void Set(const char* szInfo, INdArray<double, N>* vals) const = 0;

  virtual IMVar<1>* Reshape(const INDim<1>* shape) const = 0;
  virtual IMVar<2>* Reshape(const INDim<2>* shape) const = 0;
  virtual IMVar<3>* Reshape(const INDim<3>* shape) const = 0;

  virtual IMVar<1>* Flatten() const = 0;
  virtual IMVar<N>* Repeat(size_t repeats, int axis) const = 0;
  virtual IMVar<N>* RepeatBlock(size_t repeats, int axis) const = 0;
  virtual IMLinExpr<0>* Sum() const = 0;
  virtual IMVar<N>* Transpose() const = 0;

  virtual IVar* Item(size_t idx) const = 0;
  virtual IMVar<N>* Item(const IView* view) const = 0;
  virtual IMVar<1>* Pick(const INdArray<int, 1>* indexes) const = 0;
  virtual IMVar<1>* Pick(const INdArray<int, 2>* idxrows) const = 0;
  virtual void SetItem(size_t idx, const IVar* var) const = 0;

  virtual IMVar<N>* Clone() const = 0;
  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMConstrBuilder {
public:
  virtual ~IMConstrBuilder() = default;

  virtual IMConstrBuilder<1>* Flatten() const = 0;

  virtual int GetND() const = 0;
  virtual IMLinExpr<N>* GetExpr() const = 0;
  virtual char GetSense() const = 0;
  virtual double GetRange() const = 0;

  virtual void Set(const IMLinExpr<N>* expr, char sense, double rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const INdArray<double, N>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const INdArray<int64_t, N>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const INdArray<int, N>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const IMVar<0>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const IMVar<1>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const IMVar<2>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const IMVar<3>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const IMLinExpr<0>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const IMLinExpr<1>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const IMLinExpr<2>* rhs) = 0;
  virtual void Set(const IMLinExpr<N>* expr, char sense, const IMLinExpr<3>* rhs) = 0;

  virtual void SetRange(const IMLinExpr<N>* expr, double range) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMQConstr {
public:
  virtual ~IMQConstr() = default;

  virtual int GetND() const = 0;
  virtual size_t GetDim(int i) const = 0;
  virtual size_t GetSize() const = 0;
  virtual INDim<N>* GetShape() const = 0;

  virtual INdArray<int, N>* GetIdx() const = 0;
  virtual INdArray<double, N>* GetRhs() const = 0;
  virtual INdArray<char, N>* GetSense() const = 0;
  virtual INdArray<double, N>* Get(const char* szInfo) const = 0;
  virtual void Set(const char* szInfo, double val) const = 0;
  virtual void Set(const char* szInfo, INdArray<double, N>* vals) const = 0;

  virtual IMQConstr<1>* Reshape(const INDim<1>* shape) const = 0;
  virtual IMQConstr<2>* Reshape(const INDim<2>* shape) const = 0;
  virtual IMQConstr<3>* Reshape(const INDim<3>* shape) const = 0;

  virtual IMQConstr<1>* Flatten() const = 0;
  virtual IMQConstr<N>* Transpose() const = 0;

  virtual IQConstraint* Item(size_t idx) const = 0;
  virtual IMQConstr<N>* Item(const IView* view) const = 0;
  virtual IMQConstr<1>* Pick(const INdArray<int, 1>* indexes) const = 0;
  virtual IMQConstr<1>* Pick(const INdArray<int, 2>* idxrows) const = 0;
  virtual void SetItem(size_t idx, const IQConstraint* con) const = 0;
  virtual IMQConstr<N>* Clone() const = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IMQExpression {
public:
  virtual ~IMQExpression() = default;

  virtual double GetConstant() const = 0;
  virtual void AddConstant(double constant) = 0;

  virtual void AddTerm(const IVar* var, double coeff) = 0;
  virtual void AddTerm(const IVar* var1, const IVar* var2, double coeff) = 0;
  virtual void AddExpr(const IExpr* expr, double mult) = 0;
  virtual void AddMExpr(const IMExpression* expr, double mult) = 0;
  virtual void AddQuadExpr(const IQuadExpr* expr, double mult) = 0;
  virtual void AddQuadExpr(const IMExpression* expr, const IVar* var) = 0;
  virtual void AddQuadExpr(const IMExpression* left, const IExpr* right) = 0;
  virtual void AddQuadExpr(const IMExpression* left, const IMExpression* right) = 0;
  virtual void AddMQExpr(const IMQExpression* expr, double mult) = 0;

  virtual void iMultiply(double constant) = 0;

  virtual IMQExpression* Clone() const = 0;
  virtual double Evaluate() = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMQuadExpr {
public:
  virtual ~IMQuadExpr() = default;

  virtual int GetND() const = 0;
  virtual size_t GetDim(int i) const = 0;
  virtual size_t GetSize() const = 0;
  virtual INDim<N>* GetShape() const = 0;

  virtual IMQuadExpr<1>* Reshape(const INDim<1>* shape) const = 0;
  virtual IMQuadExpr<2>* Reshape(const INDim<2>* shape) const = 0;
  virtual IMQuadExpr<3>* Reshape(const INDim<3>* shape) const = 0;

  virtual IMQuadExpr<1>* Flatten() const = 0;
  virtual IMQuadExpr<N>* Repeat(size_t repeats, int axis) const = 0;
  virtual IMQuadExpr<N>* RepeatBlock(size_t repeats, int axis) const = 0;
  virtual IMQuadExpr<0>* Sum() const = 0;
  virtual IMQuadExpr<N>* Transpose() const = 0;

  virtual IMQExpression* Item(size_t idx) const = 0;
  virtual IMQuadExpr<N>* Item(const IView* view) const = 0;
  virtual IMQuadExpr<1>* Pick(const INdArray<int, 1>* indexes) const = 0;
  virtual IMQuadExpr<1>* Pick(const INdArray<int, 2>* idxrows) const = 0;
  virtual void SetItem(size_t idx, const IMQExpression* expr) const = 0;

  // Other than scalar, must have the same shape to add, substract, multiply to self
  virtual void iMultiply(double constant) = 0;
  virtual void AddConstant(double constant) = 0;
  virtual void AddConstant(const INdArray<double, N>* constants) = 0;
  virtual void AddConstant(const INdArray<int64_t, N>* constants) = 0;
  virtual void AddConstant(const INdArray<int, N>* constants) = 0;
  virtual void SubConstant(const INdArray<double, N>* constants) = 0;
  virtual void SubConstant(const INdArray<int64_t, N>* constants) = 0;
  virtual void SubConstant(const INdArray<int, N>* constants) = 0;

  virtual void AddTerm(const IVar* var, double coeff) = 0;
  virtual void AddTerm(const IVar* var1, const IVar* var2, double coeff) = 0;
  virtual void AddTerms(const IMVar<N>* vars, double mult) = 0;
  virtual void AddTerms(const IMVar<N>* vars, const INdArray<double, N>* coeffs) = 0;
  virtual void AddExpr(const IExpr* expr, double mult) = 0;
  virtual void AddQuadExpr(const IQuadExpr* expr, double mult) = 0;
  virtual void AddMExpr(const IMExpression* expr, double mult) = 0;
  virtual void AddMQExpr(const IMQExpression* expr, double mult) = 0;
  virtual void AddMLinExpr(const IMLinExpr<N>* exprs, double mult) = 0;
  virtual void AddMQuadExpr(const IMQuadExpr<N>* exprs, double mult) = 0;

  virtual void Clear() const = 0;
  virtual IMQuadExpr<N>* Clone() const = 0;
  virtual INdArray<double, N>* Evaluate() = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMQConstrBuilder {
public:
  virtual ~IMQConstrBuilder() = default;

  virtual IMQConstrBuilder<1>* Flatten() const = 0;

  virtual int GetND() const = 0;
  virtual IMQuadExpr<N>* GetQuadExpr() const = 0;
  virtual char GetSense() const = 0;

  virtual void Set(const IMQuadExpr<N>* expr, char sense, double rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const INdArray<double, N>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const INdArray<int64_t, N>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const INdArray<int, N>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMVar<0>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMVar<1>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMVar<2>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMVar<3>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMLinExpr<0>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMLinExpr<1>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMLinExpr<2>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMLinExpr<3>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMQuadExpr<0>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMQuadExpr<1>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMQuadExpr<2>* rhs) = 0;
  virtual void Set(const IMQuadExpr<N>* expr, char sense, const IMQuadExpr<3>* rhs) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMPsdExpr {
public:
  virtual ~IMPsdExpr() = default;

  virtual int GetND() const = 0;
  virtual size_t GetDim(int i) const = 0;
  virtual size_t GetSize() const = 0;
  virtual INDim<N>* GetShape() const = 0;

  virtual IMPsdExpr<1>* Reshape(const INDim<1>* shape) const = 0;
  virtual IMPsdExpr<2>* Reshape(const INDim<2>* shape) const = 0;
  virtual IMPsdExpr<3>* Reshape(const INDim<3>* shape) const = 0;

  virtual IMPsdExpr<1>* Flatten() const = 0;
  virtual IMPsdExpr<N>* Repeat(size_t repeats, int axis) const = 0;
  virtual IMPsdExpr<N>* RepeatBlock(size_t repeats, int axis) const = 0;
  virtual IMPsdExpr<0>* Sum() const = 0;
  virtual IMPsdExpr<N>* Transpose() const = 0;

  virtual IPsdExpr* Item(size_t idx) const = 0;
  virtual IMPsdExpr<N>* Item(const IView* view) const = 0;
  virtual IMPsdExpr<1>* Pick(const INdArray<int, 1>* indexes) const = 0;
  virtual IMPsdExpr<1>* Pick(const INdArray<int, 2>* idxrows) const = 0;
  virtual void SetItem(size_t idx, const IPsdExpr* expr) const = 0;
  virtual void SetItem(size_t idx, const IMExpression* expr) const = 0;

  // Other than scalar, must have the same shape to add, substract, multiply to self
  virtual void iMultiply(double constant) = 0;
  virtual void AddConstant(double constant) = 0;
  virtual void AddConstant(const INdArray<double, N>* constants) = 0;
  virtual void AddConstant(const INdArray<int64_t, N>* constants) = 0;
  virtual void AddConstant(const INdArray<int, N>* constants) = 0;
  virtual void SubConstant(const INdArray<double, N>* constants) = 0;
  virtual void SubConstant(const INdArray<int64_t, N>* constants) = 0;
  virtual void SubConstant(const INdArray<int, N>* constants) = 0;

  virtual void AddTerm(const IVar* var, double coeff) = 0;
  virtual void AddTerm(const IPsdVar* var, const ISymMatrix* mat) = 0;
  virtual void AddTerm(const IPsdVar* pVar, const ISymMatExpr* pExpr) = 0;
  virtual void AddTerms(const IMVar<N>* vars, double mult) = 0;
  virtual void AddTerms(const IMVar<N>* vars, const INdArray<double, N>* coeffs) = 0;

  virtual void AddLinExpr(const IExpr* expr, double mult) = 0;
  virtual void AddPsdExpr(const IPsdExpr* expr, double mult) = 0;
  virtual void AddMExpr(const IMExpression* expr, double mult) = 0;
  virtual void AddMLinExpr(const IMLinExpr<N>* exprs, double mult) = 0;
  virtual void AddMPsdExpr(const IMPsdExpr<N>* exprs, double mult) = 0;

  virtual void Clear() const = 0;
  virtual IMPsdExpr<N>* Clone() const = 0;
  virtual INdArray<double, N>* Evaluate() = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMPsdConstr {
public:
  virtual ~IMPsdConstr() = default;

  virtual int GetND() const = 0;
  virtual size_t GetDim(int i) const = 0;
  virtual size_t GetSize() const = 0;
  virtual INDim<N>* GetShape() const = 0;

  virtual INdArray<int, N>* GetIdx() const = 0;
  virtual INdArray<double, N>* Get(const char* szInfo) const = 0;
  virtual void Set(const char* szInfo, double val) const = 0;
  virtual void Set(const char* szInfo, INdArray<double, N>* vals) const = 0;

  virtual IMPsdConstr<1>* Reshape(const INDim<1>* shape) const = 0;
  virtual IMPsdConstr<2>* Reshape(const INDim<2>* shape) const = 0;
  virtual IMPsdConstr<3>* Reshape(const INDim<3>* shape) const = 0;

  virtual IMPsdConstr<1>* Flatten() const = 0;
  virtual IMPsdConstr<N>* Transpose() const = 0;

  virtual IPsdConstraint* Item(size_t idx) const = 0;
  virtual IMPsdConstr<N>* Item(const IView* view) const = 0;
  virtual IMPsdConstr<1>* Pick(const INdArray<int, 1>* indexes) const = 0;
  virtual IMPsdConstr<1>* Pick(const INdArray<int, 2>* idxrows) const = 0;
  virtual void SetItem(size_t idx, const IPsdConstraint* con) const = 0;
  virtual IMPsdConstr<N>* Clone() const = 0;

  virtual const char* Represent(size_t maxlen) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

template <int N> class IMPsdConstrBuilder {
public:
  virtual ~IMPsdConstrBuilder() = default;

  virtual IMPsdConstrBuilder<1>* Flatten() const = 0;

  virtual int GetND() const = 0;
  virtual IMPsdExpr<N>* GetPsdExpr() const = 0;
  virtual char GetSense() const = 0;
  virtual double GetRange() const = 0;

  virtual void Set(const IMPsdExpr<N>* expr, char sense, double rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const INdArray<double, N>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const INdArray<int64_t, N>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const INdArray<int, N>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMVar<0>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMVar<1>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMVar<2>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMVar<3>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMLinExpr<0>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMLinExpr<1>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMLinExpr<2>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMLinExpr<3>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMPsdExpr<0>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMPsdExpr<1>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMPsdExpr<2>* rhs) = 0;
  virtual void Set(const IMPsdExpr<N>* expr, char sense, const IMPsdExpr<3>* rhs) = 0;

  virtual void SetRange(const IMPsdExpr<N>* expr, double range) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class ICallbackProxy {
public:
  virtual ~ICallbackProxy() = default;

  virtual void Interrupt() = 0;

  virtual void AddUserCut(const IExpr* lhs, char sense, double rhs) = 0;
  virtual void AddUserCut(const IExpr* lhs, char sense, const IExpr* rhs) = 0;
  virtual void AddUserCut(const IConstrBuilder* builder) = 0;
  virtual void AddUserCuts(const IConstrBuilderArray* builders) = 0;
  virtual void AddUserCuts(const IMConstrBuilder<0>* builders) = 0;
  virtual void AddUserCuts(const IMConstrBuilder<1>* builders) = 0;
  virtual void AddUserCuts(const IMConstrBuilder<2>* builders) = 0;
  virtual void AddUserCuts(const IMConstrBuilder<3>* builders) = 0;

  virtual void AddLazyConstr(const IExpr* lhs, char sense, double rhs) = 0;
  virtual void AddLazyConstr(const IExpr* lhs, char sense, const IExpr* rhs) = 0;
  virtual void AddLazyConstr(const IConstrBuilder* builder) = 0;
  virtual void AddLazyConstrs(const IConstrBuilderArray* builders) = 0;
  virtual void AddLazyConstrs(const IMConstrBuilder<0>* builders) = 0;
  virtual void AddLazyConstrs(const IMConstrBuilder<1>* builders) = 0;
  virtual void AddLazyConstrs(const IMConstrBuilder<2>* builders) = 0;
  virtual void AddLazyConstrs(const IMConstrBuilder<3>* builders) = 0;

  virtual int GetIntInfo(const char* cbinfo) = 0;
  virtual double GetDblInfo(const char* cbinfo) = 0;

  virtual double GetIncumbent(const IVar* var) = 0;
  virtual int GetIncumbent(const IVarArray* vars, double* pOut) = 0;
  virtual int GetIncumbent(double* pOut, int len) = 0;
  virtual double GetRelaxSol(const IVar* var) = 0;
  virtual int GetRelaxSol(const IVarArray* vars, double* pOut) = 0;
  virtual int GetRelaxSol(double* pOut, int len) = 0;
  virtual double GetSolution(const IVar* var) = 0;
  virtual int GetSolution(const IVarArray* vars, double* pOut) = 0;
  virtual int GetSolution(double* pOut, int len) = 0;

  virtual void SetSolution(const IVar* var, double val) = 0;
  virtual void SetSolution(const IVarArray* vars, const double* vals, int len) = 0;
  virtual double LoadSolution() = 0;

  virtual int Where() const = 0;
  virtual int GetInfoType(const char* cbinfo) const = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IModel {
public:
  virtual ~IModel() = default;

  virtual void Read(const char* szFileName) = 0;
  virtual void ReadMps(const char* szFileName) = 0;
  virtual void ReadLp(const char* szFileName) = 0;
  virtual void ReadSdpa(const char* szFileName) = 0;
  virtual void ReadCbf(const char* szFileName) = 0;
  virtual void ReadBin(const char* szFileName) = 0;
  virtual void ReadSol(const char* szFileName) = 0;
  virtual void ReadJsonSol(const char* szFileName) = 0;
  virtual void ReadBasis(const char* szFileName) = 0;
  virtual void ReadMst(const char* szFileName) = 0;
  virtual void ReadParam(const char* szFileName) = 0;
  virtual void ReadTune(const char* szFileName) = 0;

  virtual void GetParamInfo(const char* szParam, int* pnCur, int* pnDef, int* pnMin, int* pnMax) = 0;
  virtual void GetParamInfo(const char* szParam, double* pdCur, double* pdDef, double* pdMin, double* pdMax) = 0;

  virtual int GetIntParam(const char* szParam) = 0;
  virtual double GetDblParam(const char* szParam) = 0;
  virtual void SetIntParam(const char* szParam, int nVal) = 0;
  virtual void SetDblParam(const char* szParam, double dVal) = 0;

  virtual void Write(const char* szFileName) = 0;
  virtual void WriteMps(const char* szFileName) = 0;
  virtual IProbBuffer* WriteMpsStr() = 0;
  virtual void WriteLp(const char* szFileName) = 0;
  virtual void WriteCbf(const char* szFileName) = 0;
  virtual void WriteBin(const char* szFileName) = 0;
  virtual void WriteNL(const char* szFileName) = 0;
  virtual void WriteIIS(const char* szFileName) = 0;
  virtual void WriteRelax(const char* szFileName) = 0;
  virtual void WriteSol(const char* szFileName) = 0;
  virtual void WriteJsonSol(const char* szFileName) = 0;
  virtual void WritePoolSol(int iSol, const char* szFileName) = 0;
  virtual void WriteBasis(const char* szFileName) = 0;
  virtual void WriteMst(const char* szFileName) = 0;
  virtual void WriteParam(const char* szFileName) = 0;
  virtual void WriteTuneParam(int idx, const char* szFileName) = 0;

  virtual int GetIntAttr(const char* szAttr) = 0;
  virtual double GetDblAttr(const char* szAttr) = 0;
  virtual int GetParamAttrType(const char* szName) = 0;

  virtual IVar* AddVar(double lb, double ub, double obj, char vtype, const char* szName) = 0;
  virtual IVar* AddVar(double lb, double ub, double obj, char vtype, const IColumn* col, const char* szName) = 0;
  virtual IVarArray* AddVars(int count, char vtype, const char* szPrefix) = 0;
  virtual IVarArray* AddVars(int count, char vtype, const char* szNames, size_t len) = 0;
  virtual IVarArray* AddVars(int count, double lb, double ub, double obj, char vtype, const char* szPrefix) = 0;
  virtual IVarArray*
  AddVars(int count, double lb, double ub, double obj, char vtype, const char* szNames, size_t len) = 0;
  virtual IVarArray* AddVars(int count, double* plb, double* pub, double* pobj, char* pvtype, const char* szPrefix) = 0;
  virtual IVarArray*
  AddVars(int count, double* plb, double* pub, double* pobj, char* pvtype, const char* szNames, size_t len) = 0;
  virtual IVarArray* AddVars(int count,
    double* plb,
    double* pub,
    double* pobj,
    char* pvtype,
    const IColumnArray* cols,
    const char* szPrefix) = 0;

  virtual IVar* AddCol(double obj,
    int colCnt,
    const int* colIdx,
    const double* colElem,
    char vtype,
    double lb,
    double ub,
    const char* szName) = 0;

  virtual IVarArray*
  AddCols(int count, double* pobj, char* pvtype, double* plb, double* pub, char const* const* names) = 0;

  virtual IVarArray* AddCols(int count,
    double* pobj,
    int* colBeg,
    int* colCnt,
    int* colIdx,
    double* colElem,
    char* pvtype,
    double* plb,
    double* pub,
    char const* const* names) = 0;

  virtual IMVar<0>* AddMVar(const INDim<0>* shp, char vtype, const char* szPrefix) = 0;
  virtual IMVar<1>* AddMVar(const INDim<1>* shp, char vtype, const char* szPrefix) = 0;
  virtual IMVar<2>* AddMVar(const INDim<2>* shp, char vtype, const char* szPrefix) = 0;
  virtual IMVar<3>* AddMVar(const INDim<3>* shp, char vtype, const char* szPrefix) = 0;
  virtual IMVar<0>*
  AddMVar(const INDim<0>* shp, double lb, double ub, double obj, char vtype, const char* szPrefix) = 0;
  virtual IMVar<1>*
  AddMVar(const INDim<1>* shp, double lb, double ub, double obj, char vtype, const char* szPrefix) = 0;
  virtual IMVar<2>*
  AddMVar(const INDim<2>* shp, double lb, double ub, double obj, char vtype, const char* szPrefix) = 0;
  virtual IMVar<3>*
  AddMVar(const INDim<3>* shp, double lb, double ub, double obj, char vtype, const char* szPrefix) = 0;
  virtual IMVar<0>*
  AddMVar(const INDim<0>* shp, double* plb, double* pub, double* pobj, char* pvtype, const char* szPrefix) = 0;
  virtual IMVar<1>*
  AddMVar(const INDim<1>* shp, double* plb, double* pub, double* pobj, char* pvtype, const char* szPrefix) = 0;
  virtual IMVar<2>*
  AddMVar(const INDim<2>* shp, double* plb, double* pub, double* pobj, char* pvtype, const char* szPrefix) = 0;
  virtual IMVar<3>*
  AddMVar(const INDim<3>* shp, double* plb, double* pub, double* pobj, char* pvtype, const char* szPrefix) = 0;

  virtual IConstraint* AddConstr(const IExpr* expr, char sense, double rhs, const char* szName) = 0;
  virtual IConstraint* AddConstr(const IExpr* lhs, char sense, const IExpr* rhs, const char* szName) = 0;
  virtual IConstraint* AddConstr(const IExpr* expr, double lb, double ub, const char* szName) = 0;
  virtual IConstraint* AddConstr(const IConstrBuilder* builder, const char* szName) = 0;

  virtual IConstrArray* AddConstrs(int count, char* pSense, double* pRhs, const char* szPrefix) = 0;
  virtual IConstrArray* AddConstrs(int count, double* pLower, double* pUpper, const char* szPrefix) = 0;
  virtual IConstrArray* AddConstrs(int count, double* pLower, double* pUpper, const char* szNames, size_t len) = 0;
  virtual IConstrArray* AddConstrs(const IConstrBuilderArray* builders, const char* szPrefix) = 0;
  virtual IConstrArray* AddConstrs(const IConstrBuilderArray* builders, const char* szNames, size_t len) = 0;

  virtual IConstraint*
  AddRow(int rowCnt, const int* rowIdx, const double* rowElem, char sense, double rhs, const char* szName) = 0;
  virtual IConstraint*
  AddRow(int rowCnt, const int* rowIdx, const double* rowElem, double lb, double ub, const char* szName) = 0;

  virtual IConstrArray* AddRows(int count, char* pSense, double* pRhs, char const* const* names) = 0;
  virtual IConstrArray* AddRows(int count, double* plb, double* pub, char const* const* names) = 0;
  virtual IConstrArray* AddRows(int count,
    int* rowBeg,
    int* rowCnt,
    int* rowIdx,
    double* rowElem,
    char* rowSense,
    double* rowBound,
    double* rowUpper,
    char const* const* names) = 0;

  virtual IConstraint* AddMConstr(const IMExpression* expr, char sense, double rhs, const char* szName) = 0;
  virtual IMConstr<0>* AddMConstr(const IMConstrBuilder<0>* builder, const char* szPrefix) = 0;
  virtual IMConstr<1>* AddMConstr(const IMConstrBuilder<1>* builder, const char* szPrefix) = 0;
  virtual IMConstr<2>* AddMConstr(const IMConstrBuilder<2>* builder, const char* szPrefix) = 0;
  virtual IMConstr<3>* AddMConstr(const IMConstrBuilder<3>* builder, const char* szPrefix) = 0;
  virtual IMConstr<0>* AddMConstr(const IMLinExpr<0>* exprs, char sense, double rhs, const char* szPrefix) = 0;
  virtual IMConstr<1>* AddMConstr(const IMLinExpr<1>* exprs, char sense, double rhs, const char* szPrefix) = 0;
  virtual IMConstr<2>* AddMConstr(const IMLinExpr<2>* exprs, char sense, double rhs, const char* szPrefix) = 0;
  virtual IMConstr<3>* AddMConstr(const IMLinExpr<3>* exprs, char sense, double rhs, const char* szPrefix) = 0;

  virtual INlConstraint* AddNlConstr(const INlExpr* expr, char sense, double rhs, const char* szName) = 0;
  virtual INlConstraint* AddNlConstr(const INlExpr* lhs, char sense, const INlExpr* rhs, const char* szName) = 0;
  virtual INlConstraint* AddNlConstr(const INlExpr* expr, double lb, double ub, const char* szName) = 0;
  virtual INlConstraint* AddNlConstr(const INlConstrBuilder* builder, const char* szName) = 0;

  virtual INlConstrArray* AddNlConstrs(const INlConstrBuilderArray* builders, const char* szPrefix) = 0;
  virtual INlConstrArray* AddNlConstrs(const INlConstrBuilderArray* builders, const char* szNames, size_t len) = 0;

  virtual ISos* AddSos(const ISosBuilder* builder) = 0;
  virtual ISos* AddSos(const IVarArray* pVars, const double* pWeights, int type) = 0;

  virtual IGenConstr* AddGenConstrIndicator(const IGenConstrBuilder* pBuilder, const char* szName) = 0;
  virtual IGenConstr* AddGenConstrIndicator(const IVar* binVar,
    int binVal,
    const IConstrBuilder* pConstr,
    int type,
    const char* szName) = 0;

  virtual IGenConstr* AddGenConstrIndicator(const IVar* binVar,
    int binVal,
    const IExpr* expr,
    char sense,
    double rhs,
    int type,
    const char* szName) = 0;
  virtual IGenConstr* AddGenConstrIndicator(const IVar* binVar,
    int binVal,
    const IMExpression* expr,
    char sense,
    double rhs,
    int type,
    const char* szName) = 0;
  virtual IGenConstrArray* AddGenConstrIndicators(const IGenConstrBuilderArray* builders, const char* szPrefix) = 0;
  virtual IGenConstrArray*
  AddGenConstrIndicators(const IGenConstrBuilderArray* builders, const char* szNames, size_t len) = 0;
  virtual IGenConstrArray* AddGenConstrIndicators(const IVar* binVar,
    int binVal,
    const IMConstrBuilder<0>* pBuilders,
    int type,
    const char* szPrefix) = 0;
  virtual IGenConstrArray* AddGenConstrIndicators(const IVar* binVar,
    int binVal,
    const IMConstrBuilder<1>* pBuilders,
    int type,
    const char* szPrefix) = 0;
  virtual IGenConstrArray* AddGenConstrIndicators(const IVar* binVar,
    int binVal,
    const IMConstrBuilder<2>* pBuilders,
    int type,
    const char* szPrefix) = 0;
  virtual IGenConstrArray* AddGenConstrIndicators(const IVar* binVar,
    int binVal,
    const IMConstrBuilder<3>* pBuilders,
    int type,
    const char* szPrefix) = 0;

  virtual ICone* AddCone(int dim, int type, char* pvtype, const char* szPrefix) = 0;
  virtual ICone* AddCone(const IConeBuilder* builder) = 0;
  virtual ICone* AddCone(const IVarArray* pVars, int type) = 0;
  virtual ICone* AddCone(const IMVar<1>* vars, int type) = 0;
  virtual IConeArray* AddCones(const IMVar<2>* vars, int type) = 0;

  virtual IExpCone* AddExpCone(int type, char* pvtype, const char* szPrefix) = 0;
  virtual IExpCone* AddExpCone(const IExpConeBuilder* builder) = 0;
  virtual IExpCone* AddExpCone(const IVarArray* pVars, int type) = 0;
  virtual IExpCone* AddExpCone(const IMVar<1>* vars, int type) = 0;
  virtual IExpConeArray* AddExpCones(const IMVar<2>* vars, int type) = 0;

  virtual IAffineCone* AddAffineCone(const IAffineConeBuilder* builder, const char* szName) = 0;
  virtual IAffineCone* AddAffineCone(const IMLinExpr<1>* exprs, int type, const char* szName) = 0;
  virtual IAffineCone* AddAffineCone(const std::vector<IExpr*>& exprs, int type, const char* szName) = 0;
  virtual IAffineConeArray* AddAffineCones(const IMLinExpr<2>* exprs, int type, const char* szPrefix) = 0;
  virtual IAffineConeArray* AddAffineCones(const IMLinExpr<2>* exprs, int type, const char* szNames, size_t len) = 0;
  virtual IAffineCone* AddAffineCone(const IMPsdExpr<1>* exprs, int type, const char* szName) = 0;
  virtual IAffineCone* AddAffineCone(const std::vector<IPsdExpr*>& exprs, int type, const char* szName) = 0;
  virtual IAffineConeArray* AddAffineCones(const IMPsdExpr<2>* exprs, int type, const char* szPrefix) = 0;
  virtual IAffineConeArray* AddAffineCones(const IMPsdExpr<2>* exprs, int type, const char* szNames, size_t len) = 0;

  virtual IQConstraint* AddQConstr(const IQuadExpr* expr, char sense, double rhs, const char* szName) = 0;
  virtual IQConstraint* AddQConstr(const IQuadExpr* lhs, char sense, const IQuadExpr* rhs, const char* szName) = 0;
  virtual IQConstraint* AddQConstr(const IQConstrBuilder* builder, const char* szName) = 0;
  virtual IQConstraint* AddMQConstr(const IMQExpression* expr, char sense, double rhs, const char* szName) = 0;
  virtual IMQConstr<0>* AddMQConstr(const IMQConstrBuilder<0>* builder, const char* szPrefix) = 0;
  virtual IMQConstr<1>* AddMQConstr(const IMQConstrBuilder<1>* builder, const char* szPrefix) = 0;
  virtual IMQConstr<2>* AddMQConstr(const IMQConstrBuilder<2>* builder, const char* szPrefix) = 0;
  virtual IMQConstr<3>* AddMQConstr(const IMQConstrBuilder<3>* builder, const char* szPrefix) = 0;
  virtual IMQConstr<0>* AddMQConstr(const IMQuadExpr<0>* exprs, char sense, double rhs, const char* szPrefix) = 0;
  virtual IMQConstr<1>* AddMQConstr(const IMQuadExpr<1>* exprs, char sense, double rhs, const char* szPrefix) = 0;
  virtual IMQConstr<2>* AddMQConstr(const IMQuadExpr<2>* exprs, char sense, double rhs, const char* szPrefix) = 0;
  virtual IMQConstr<3>* AddMQConstr(const IMQuadExpr<3>* exprs, char sense, double rhs, const char* szPrefix) = 0;

  virtual IPsdVar* AddPsdVar(int dim, const char* szName) = 0;
  virtual IPsdVarArray* AddPsdVars(int count, int* pDim, const char* szPrefix) = 0;
  virtual IPsdVarArray* AddPsdVars(int count, int* pDim, const char* szNames, size_t len) = 0;

  virtual IPsdConstraint* AddPsdConstr(const IPsdExpr* pExpr, char sense, double rhs, const char* szName) = 0;
  virtual IPsdConstraint* AddPsdConstr(const IPsdExpr* pLhs, char sense, const IPsdExpr* pRhs, const char* szName) = 0;
  virtual IPsdConstraint* AddPsdConstr(const IPsdExpr* pExpr, double lb, double ub, const char* szName) = 0;
  virtual IPsdConstraint* AddPsdConstr(const IPsdConstrBuilder* pBuilder, const char* szName) = 0;
  virtual IMPsdConstr<0>* AddMPsdConstr(const IMPsdConstrBuilder<0>* builder, const char* szPrefix) = 0;
  virtual IMPsdConstr<1>* AddMPsdConstr(const IMPsdConstrBuilder<1>* builder, const char* szPrefix) = 0;
  virtual IMPsdConstr<2>* AddMPsdConstr(const IMPsdConstrBuilder<2>* builder, const char* szPrefix) = 0;
  virtual IMPsdConstr<3>* AddMPsdConstr(const IMPsdConstrBuilder<3>* builder, const char* szPrefix) = 0;
  virtual IMPsdConstr<0>* AddMPsdConstr(const IMPsdExpr<0>* exprs, char sense, double rhs, const char* szPrefix) = 0;
  virtual IMPsdConstr<1>* AddMPsdConstr(const IMPsdExpr<1>* exprs, char sense, double rhs, const char* szPrefix) = 0;
  virtual IMPsdConstr<2>* AddMPsdConstr(const IMPsdExpr<2>* exprs, char sense, double rhs, const char* szPrefix) = 0;
  virtual IMPsdConstr<3>* AddMPsdConstr(const IMPsdExpr<3>* exprs, char sense, double rhs, const char* szPrefix) = 0;

  virtual ILmiConstraint* AddLmiConstr(const ILmiExpr* pExpr, const char* szName) = 0;

  virtual void AddUserCut(const IExpr* lhs, char sense, double rhs, const char* szName) = 0;
  virtual void AddUserCut(const IExpr* lhs, char sense, const IExpr* rhs, const char* szName) = 0;
  virtual void AddUserCut(const IConstrBuilder* builder, const char* szName) = 0;
  virtual void AddUserCuts(const IConstrBuilderArray* builders, const char* szPrefix) = 0;
  virtual void AddUserCuts(const IConstrBuilderArray* builders, const char* szNames, size_t len) = 0;
  virtual void AddUserCuts(const IMConstrBuilder<0>* builders, const char* szPrefix) = 0;
  virtual void AddUserCuts(const IMConstrBuilder<1>* builders, const char* szPrefix) = 0;
  virtual void AddUserCuts(const IMConstrBuilder<2>* builders, const char* szPrefix) = 0;
  virtual void AddUserCuts(const IMConstrBuilder<3>* builders, const char* szPrefix) = 0;

  virtual void AddLazyConstr(const IExpr* lhs, char sense, double rhs, const char* szName) = 0;
  virtual void AddLazyConstr(const IExpr* lhs, char sense, const IExpr* rhs, const char* szName) = 0;
  virtual void AddLazyConstr(const IConstrBuilder* builder, const char* szName) = 0;
  virtual void AddLazyConstrs(const IConstrBuilderArray* builders, const char* szPrefix) = 0;
  virtual void AddLazyConstrs(const IConstrBuilderArray* builders, const char* szNames, size_t len) = 0;
  virtual void AddLazyConstrs(const IMConstrBuilder<0>* builders, const char* szPrefix) = 0;
  virtual void AddLazyConstrs(const IMConstrBuilder<1>* builders, const char* szPrefix) = 0;
  virtual void AddLazyConstrs(const IMConstrBuilder<2>* builders, const char* szPrefix) = 0;
  virtual void AddLazyConstrs(const IMConstrBuilder<3>* builders, const char* szPrefix) = 0;

  virtual ISymMatrix* AddSparseMat(int dim, int nElems, int* pRows, int* pCols, double* pVals) = 0;
  virtual ISymMatrix* AddDenseMat(int dim, double* pVals, int len) = 0;
  virtual ISymMatrix* AddDenseMat(int dim, double val) = 0;
  virtual ISymMatrix* AddDiagMat(int dim, double* pVals, int len) = 0;
  virtual ISymMatrix* AddDiagMat(int dim, double val) = 0;
  virtual ISymMatrix* AddDiagMat(int dim, double* pVals, int len, int offset) = 0;
  virtual ISymMatrix* AddDiagMat(int dim, double val, int offset) = 0;
  virtual ISymMatrix* AddOnesMat(int dim) = 0;
  virtual ISymMatrix* AddEyeMat(int dim) = 0;
  virtual ISymMatrix* AddSymMat(const ISymMatExpr* expr) = 0;
  virtual ISymMatrix* GetSymMat(int idx) = 0;

  virtual void GetSolution(double* pValue) = 0;
  virtual void GetLpSolution(double* pValue, double* pSlack, double* pRowDual, double* pRedCost) = 0;
  virtual void SetLpSolution(double* pValue, double* pSlack, double* pRowDual, double* pRedCost) = 0;
  virtual int GetColBasis(int* pBasis) = 0;
  virtual int GetRowBasis(int* pBasis) = 0;
  virtual void SetBasis(int* pColBasis, int* pRowBasis) = 0;
  virtual void SetSlackBasis() = 0;

  virtual double GetPoolObjVal(int iSol) = 0;
  virtual int GetPoolSolution(int iSol, const IVarArray* pVars, double* pColVals) = 0;

  virtual int GetVarLowerIIS(const IVarArray* pVars, int* pLowerIIS) = 0;
  virtual int GetVarUpperIIS(const IVarArray* pVars, int* pUpperIIS) = 0;
  virtual int GetConstrLowerIIS(const IConstrArray* pConstrs, int* pLowerIIS) = 0;
  virtual int GetConstrUpperIIS(const IConstrArray* pConstrs, int* pUpperIIS) = 0;
  virtual int GetSOSIIS(const ISosArray* pSoss, int* pIIS) = 0;
  virtual int GetIndicatorIIS(const IGenConstrArray* pGenConstrs, int* pIIS) = 0;

  virtual double GetCoeff(const IConstraint* pConstr, const IVar* pVar) = 0;
  virtual void SetCoeff(const IConstraint* pConstr, const IVar* pVar, double newVal) = 0;
  virtual void SetCoeffs(const IConstrArray* pConstrs, const IVarArray* pVars, double* vals, int len) = 0;

  virtual ISymMatrix* GetPsdCoeff(const IPsdConstraint* pConstr, const IPsdVar* pVar) = 0;
  virtual void SetPsdCoeff(const IPsdConstraint* pConstr, const IPsdVar* pVar, const ISymMatrix* pMat) = 0;

  virtual ISymMatrix* GetLmiCoeff(const ILmiConstraint* pConstr, const IVar* pVar) = 0;
  virtual void SetLmiCoeff(const ILmiConstraint* pConstr, const IVar* pVar, const ISymMatrix* pMat) = 0;
  virtual ISymMatrix* GetLmiRhs(const ILmiConstraint* pConstr) = 0;
  virtual void SetLmiRhs(const ILmiConstraint* pConstr, const ISymMatrix* pMat) = 0;

  virtual void GetCoeffMatrix(int* pMatBeg, int* pMatCnt, int* pMatIdx, double* pMatElem) = 0;
  virtual void LoadMatrix(int nCol,
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
    char* pType) = 0;
  virtual void LoadQ(int nQElem, const int* pMatRow, const int* pMatCol, const double* pMatElem) = 0;
  virtual void LoadCone(int nCone, int* pConeType, int* pConeDims, int* pConeIdx) = 0;
  virtual void LoadExpCone(int nExpCone, int* pExpConeType, int* pExpConeIdx) = 0;
  virtual void LoadConeMatrix(int nCol,
    int nRow,
    int nFree,
    int nPositive,
    int nBox,
    int nCone,
    int nRotateCone,
    int nPrimalExp,
    int nDualExp,
    int nPrimalPow,
    int nDualPow,
    int nPSD,
    int nQObjElem,
    double* colObj,
    int* qObjRow,
    int* qObjCol,
    double* qObjElem,
    int* colMatBeg,
    int* colMatCnt,
    int* colMatIdx,
    double* colMatElem,
    double* rowRhs,
    double* boxLower,
    double* boxUpper,
    int* coneDim,
    int* rotateConeDim,
    int* primalPowDim,
    int* dualPowDim,
    double* primalPowAlpha,
    double* dualPowAlpha,
    int* psdDim,
    char* colType,
    int* outRowMap) = 0;

  virtual void GetPsdSolution(double* psdColValue, double* psdRowSlack, double* psdRowDual, double* psdColDual) = 0;
  virtual void GetLmiSolution(double* lmiRowSlack, double* lmiRowDual) = 0;

  virtual IVar* GetVar(int idx) const = 0;
  virtual IVar* GetVarByName(const char* szName) = 0;
  virtual IVarArray* GetVars() = 0;
  virtual void SetNames(const IVarArray* pVars, const char* szNames, size_t len) = 0;
  virtual IColumn* GetCol(const IVar* pVar) = 0;

  virtual IConstraint* GetConstr(int idx) const = 0;
  virtual IConstraint* GetConstrByName(const char* szName) = 0;
  virtual IConstrArray* GetConstrs() = 0;
  virtual void SetNames(const IConstrArray* pCons, const char* szNames, size_t len) = 0;
  virtual IConstrBuilderArray* GetConstrBuilders() = 0;
  virtual IConstrBuilder* GetConstrBuilder(const IConstraint* pConstr) = 0;
  virtual IExpr* GetRow(const IConstraint* pConstr) = 0;

  virtual ISos* GetSos(int idx) const = 0;
  virtual ISosArray* GetSoss() = 0;
  virtual ISosBuilderArray* GetSosBuilders() = 0;
  virtual ISosBuilderArray* GetSosBuilders(const ISosArray* pSoss) = 0;

  virtual IGenConstr* GetGenConstr(int idx) const = 0;
  virtual IGenConstr* GetGenConstrByName(const char* szName) = 0;
  virtual IGenConstrArray* GetGenConstrs() = 0;
  virtual void SetNames(const IGenConstrArray* genConstrs, const char* szNames, size_t len) = 0;
  virtual IGenConstrBuilderArray* GetGenConstrIndicators() = 0;
  virtual IGenConstrBuilder* GetGenConstrIndicator(const IGenConstr* pIndicator) = 0;

  virtual ICone* GetCone(int idx) const = 0;
  virtual IConeArray* GetCones() = 0;
  virtual IConeBuilderArray* GetConeBuilders() = 0;
  virtual IConeBuilderArray* GetConeBuilders(const IConeArray* pCones) = 0;

  virtual IExpCone* GetExpCone(int idx) const = 0;
  virtual IExpConeArray* GetExpCones() = 0;
  virtual IExpConeBuilderArray* GetExpConeBuilders() = 0;
  virtual IExpConeBuilderArray* GetExpConeBuilders(const IExpConeArray* pCones) = 0;

  virtual IAffineCone* GetAffineCone(int idx) const = 0;
  virtual IAffineCone* GetAffineConeByName(const char* szName) = 0;
  virtual IAffineConeArray* GetAffineCones() = 0;
  virtual void SetNames(const IAffineConeArray* cones, const char* szNames, size_t len) = 0;
  virtual IAffineConeBuilder* GetAffineConeBuilder(const IAffineCone* cone) = 0;
  virtual IAffineConeBuilderArray* GetAffineConeBuilders() = 0;
  virtual IAffineConeBuilderArray* GetAffineConeBuilders(const IAffineConeArray* pCones) = 0;

  virtual INlConstraint* GetNlConstr(int idx) const = 0;
  virtual INlConstraint* GetNlConstrByName(const char* szName) = 0;
  virtual INlConstrArray* GetNlConstrs() = 0;
  virtual void SetNames(const INlConstrArray* pCons, const char* szNames, size_t len) = 0;
  virtual INlConstrBuilderArray* GetNlConstrBuilders() = 0;
  virtual INlConstrBuilder* GetNlConstrBuilder(const INlConstraint* constr) = 0;
  virtual INlExpr* GetNlRow(const INlConstraint* pConstr) = 0;

  virtual IQConstraint* GetQConstr(int idx) const = 0;
  virtual IQConstraint* GetQConstrByName(const char* szName) = 0;
  virtual IQConstrArray* GetQConstrs() = 0;
  virtual void SetNames(const IQConstrArray* pCons, const char* szNames, size_t len) = 0;
  virtual IQConstrBuilderArray* GetQConstrBuilders() = 0;
  virtual IQConstrBuilder* GetQConstrBuilder(const IQConstraint* constr) = 0;
  virtual IQuadExpr* GetQuadRow(const IQConstraint* pConstr) = 0;

  virtual IPsdVar* GetPsdVar(int idx) const = 0;
  virtual IPsdVar* GetPsdVarByName(const char* szName) = 0;
  virtual IPsdVarArray* GetPsdVars() = 0;
  virtual void SetNames(const IPsdVarArray* pVars, const char* szNames, size_t len) = 0;
  virtual IPsdConstraint* GetPsdConstr(int idx) const = 0;
  virtual IPsdConstraint* GetPsdConstrByName(const char* szName) = 0;
  virtual IPsdConstrArray* GetPsdConstrs() = 0;
  virtual void SetNames(const IPsdConstrArray* pCons, const char* szNames, size_t len) = 0;
  virtual IPsdConstrBuilder* GetPsdConstrBuilder(const IPsdConstraint* pConstr) = 0;
  virtual IPsdConstrBuilderArray* GetPsdConstrBuilders() = 0;
  virtual IPsdExpr* GetPsdRow(const IPsdConstraint* pConstr) = 0;

  virtual ILmiConstraint* GetLmiConstr(int idx) const = 0;
  virtual ILmiConstraint* GetLmiConstrByName(const char* szName) = 0;
  virtual ILmiConstrArray* GetLmiConstrs() = 0;
  virtual void SetNames(const ILmiConstrArray* pCons, const char* szNames, size_t len) = 0;
  virtual ILmiExpr* GetLmiRow(const ILmiConstraint* pConstr) = 0;

  virtual void SetObjSense(int sense) = 0;
  virtual void SetObjConst(double constant) = 0;
  virtual void SetObjective(const IExpr* expr, int sense) = 0;
  virtual void SetObjective(const IMExpression* expr, int sense) = 0;
  virtual void SetCost(int num, const int* list, const double* obj) = 0;
  virtual IExpr* GetObjective() const = 0;

  virtual void SetObjectiveN(int idx,
    const IExpr* expr,
    int sense,
    double priority,
    double weight,
    double abstol,
    double reltol) = 0;
  virtual void SetObjectiveN(int idx,
    const IMExpression* expr,
    int sense,
    double priority,
    double weight,
    double abstol,
    double reltol) = 0;
  virtual IExpr* GetObjectiveN(int idx) const = 0;
  virtual void DelObjN(int idx) = 0;

  virtual void SetObjParamN(int idx, const char* szParam, double val) = 0;
  virtual void SetDblParamN(int idx, const char* szParam, double val) = 0;
  virtual void SetIntParamN(int idx, const char* szParam, int val) = 0;

  virtual double GetObjParamN(int idx, const char* szParam) const = 0;
  virtual double GetDblParamN(int idx, const char* szParam) const = 0;
  virtual int GetIntParamN(int idx, const char* szParam) const = 0;
  virtual double GetDblAttrN(int idx, const char* szAttr) const = 0;
  virtual int GetIntAttrN(int idx, const char* szAttr) const = 0;
  virtual double GetPoolObjValN(int idx, int iSol) const = 0;

  virtual void ResetObjParamN(int idx) = 0;
  virtual void ResetParamN(int idx) = 0;

  virtual void SetNlObjective(const INlExpr* expr, int sense) = 0;
  virtual INlExpr* GetNlObjective() const = 0;
  virtual void DelNlObj() = 0;

  virtual void SetQuadObjective(const IQuadExpr* expr, int sense) = 0;
  virtual void SetQuadObjective(const IMQExpression* expr, int sense) = 0;
  virtual IQuadExpr* GetQuadObjective() const = 0;
  virtual void DelQuadObj() = 0;

  virtual void SetPsdObjective(const IPsdExpr* expr, int sense) = 0;
  virtual IPsdExpr* GetPsdObjective() const = 0;
  virtual void DelPsdObj() = 0;

  virtual void SetMipStart(int count, double* pVals) = 0;
  virtual void SetMipStart(const IVar* pVar, double val) = 0;
  virtual void SetMipStart(const IVarArray* pVars, double* pVals) = 0;
  virtual void LoadMipStart() = 0;

  virtual void SetNlPrimalStart(int count, double* pVals) = 0;
  virtual void SetNlPrimalStart(const IVar* pVar, double val) = 0;
  virtual void SetNlPrimalStart(const IVarArray* pVars, double* pVals) = 0;

  virtual int Get(const char* szName, const IVarArray* pVars, double* pOut) = 0;
  virtual int Get(const char* szName, const IConstrArray* pConstrs, double* pOut) = 0;
  virtual int Get(const char* szName, const INlConstrArray* pConstrs, double* pOut) = 0;
  virtual int Get(const char* szName, const IQConstrArray* pConstrs, double* pOut) = 0;
  virtual int Get(const char* szName, const IPsdConstrArray* pConstrs, double* pOut) = 0;

  virtual void Set(const char* szName, const IVarArray* pVars, double* pVals, int len) = 0;
  virtual void Set(const char* szName, const IConstrArray* pConstrs, double* pVals, int len) = 0;
  virtual void Set(const char* szName, const INlConstrArray* pConstrs, double* pVals, int len) = 0;
  virtual void Set(const char* szName, const IPsdConstrArray* pConstrs, double* pVals, int len) = 0;

  virtual void Solve() = 0;
  virtual void SolveLp() = 0;

  virtual void ComputeIIS() = 0;

  virtual void FeasRelax(const IVarArray* pVars,
    double* pColLowPen,
    double* pColUppPen,
    const IConstrArray* pCons,
    double* pRowBndPen,
    double* pRowUppPen) = 0;
  virtual void FeasRelax(const IMVar<1>* pVars,
    double* pColLowPen,
    double* pColUppPen,
    const IMConstr<1>* pCons,
    double* pRowBndPen,
    double* pRowUppPen) = 0;
  virtual void FeasRelax(const IMVar<1>* pVars,
    const INdArray<double, 1>* pColLowPen,
    const INdArray<double, 1>* pColUppPen,
    const IMConstr<1>* pCons,
    const INdArray<double, 1>* pRowBndPen,
    const INdArray<double, 1>* pRowUppPen) = 0;
  virtual void FeasRelax(int ifRelaxVars, int ifRelaxCons) = 0;

  virtual void Tune() = 0;
  virtual void LoadTuneParam(int idx) = 0;

  virtual void Interrupt() = 0;

  virtual void Remove(IMVar<0>* pVars) = 0;
  virtual void Remove(IMVar<1>* pVars) = 0;
  virtual void Remove(IMVar<2>* pVars) = 0;
  virtual void Remove(IMVar<3>* pVars) = 0;
  virtual void Remove(IMConstr<0>* pConstrs) = 0;
  virtual void Remove(IMConstr<1>* pConstrs) = 0;
  virtual void Remove(IMConstr<2>* pConstrs) = 0;
  virtual void Remove(IMConstr<3>* pConstrs) = 0;
  virtual void Remove(IMQConstr<0>* pConstrs) = 0;
  virtual void Remove(IMQConstr<1>* pConstrs) = 0;
  virtual void Remove(IMQConstr<2>* pConstrs) = 0;
  virtual void Remove(IMQConstr<3>* pConstrs) = 0;
  virtual void Remove(IMPsdConstr<0>* pConstrs) = 0;
  virtual void Remove(IMPsdConstr<1>* pConstrs) = 0;
  virtual void Remove(IMPsdConstr<2>* pConstrs) = 0;
  virtual void Remove(IMPsdConstr<3>* pConstrs) = 0;

  virtual void Remove(IVarArray* pVars) = 0;
  virtual void Remove(IConstrArray* pConstrs) = 0;
  virtual void Remove(INlConstrArray* pConstrs) = 0;
  virtual void Remove(ISosArray* pSoss) = 0;
  virtual void Remove(IConeArray* pCones) = 0;
  virtual void Remove(IExpConeArray* pCones) = 0;
  virtual void Remove(IAffineConeArray* pCones) = 0;
  virtual void Remove(IGenConstrArray* pGenConstrs) = 0;
  virtual void Remove(IQConstrArray* pConstrs) = 0;
  virtual void Remove(IPsdVarArray* pVars) = 0;
  virtual void Remove(IPsdConstrArray* pConstrs) = 0;
  virtual void Remove(ILmiConstrArray* pConstrs) = 0;

  virtual void ResetParam() = 0;
  virtual void ResetAll() = 0;
  virtual void Reset() = 0;

  virtual void Clear() = 0;
  virtual IModel* Clone() = 0;

  virtual void SetCallback(ICallback* pcb, int cbctx) = 0;

  virtual void SetSolverLogFile(const char* szLogFile) = 0;
  virtual void SetSolverLogCallback(ILogCallback* pcb) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IEnvrConfig {
public:
  virtual ~IEnvrConfig() = default;

  virtual void Set(const char* szName, const char* szValue) = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class IEnvr {
public:
  virtual ~IEnvr() = default;

  virtual IModel* CreateModel(const char* szName) = 0;
  virtual void Close() = 0;

  virtual int GetLastError() const = 0;
  virtual const char* GetErrorMessage() const = 0;
};

class INlHelper {
public:
  virtual ~INlHelper() = default;

  virtual INlExpr* Sum(const std::vector<INlExpr*>& exprs) const = 0;
  virtual INlExpr* Sum(const INlExpr* op1, const INlExpr* op2, const INlExpr* op3) const = 0;
  virtual INlExpr* Sum(const INlExpr* op1, const INlExpr* op2, const INlExpr* op3, const INlExpr* op4) const = 0;

  virtual INlExpr* ATan2(double y, const INlExpr* x) const = 0;
  virtual INlExpr* ATan2(const INlExpr* y, double x) const = 0;
  virtual INlExpr* ATan2(const INlExpr* y, const INlExpr* x) const = 0;

  virtual INlExpr* Pow(const INlExpr* base, double expo) const = 0;
  virtual INlExpr* Pow(double base, const INlExpr* expo) const = 0;
  virtual INlExpr* Pow(const INlExpr* base, const INlExpr* expo) const = 0;

  virtual INlExpr* Sqrt(double c) const = 0;
  virtual INlExpr* Sqrt(const IVar* var) const = 0;
  virtual INlExpr* Sqrt(const IExpr* expr) const = 0;
  virtual INlExpr* Sqrt(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Sqrt(const INlExpr* expr) const = 0;

  virtual INlExpr* Exp(double c) const = 0;
  virtual INlExpr* Exp(const IVar* var) const = 0;
  virtual INlExpr* Exp(const IExpr* expr) const = 0;
  virtual INlExpr* Exp(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Exp(const INlExpr* expr) const = 0;

  virtual INlExpr* Log(double c) const = 0;
  virtual INlExpr* Log(const IVar* var) const = 0;
  virtual INlExpr* Log(const IExpr* expr) const = 0;
  virtual INlExpr* Log(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Log(const INlExpr* expr) const = 0;

  virtual INlExpr* Log10(double c) const = 0;
  virtual INlExpr* Log10(const IVar* var) const = 0;
  virtual INlExpr* Log10(const IExpr* expr) const = 0;
  virtual INlExpr* Log10(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Log10(const INlExpr* expr) const = 0;

  virtual INlExpr* Neg(double c) const = 0;
  virtual INlExpr* Neg(const IVar* var) const = 0;
  virtual INlExpr* Neg(const IExpr* expr) const = 0;
  virtual INlExpr* Neg(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Neg(const INlExpr* expr) const = 0;

  virtual INlExpr* Abs(double c) const = 0;
  virtual INlExpr* Abs(const IVar* var) const = 0;
  virtual INlExpr* Abs(const IExpr* expr) const = 0;
  virtual INlExpr* Abs(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Abs(const INlExpr* expr) const = 0;

  virtual INlExpr* Floor(double c) const = 0;
  virtual INlExpr* Floor(const IVar* var) const = 0;
  virtual INlExpr* Floor(const IExpr* expr) const = 0;
  virtual INlExpr* Floor(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Floor(const INlExpr* expr) const = 0;

  virtual INlExpr* Ceil(double c) const = 0;
  virtual INlExpr* Ceil(const IVar* var) const = 0;
  virtual INlExpr* Ceil(const IExpr* expr) const = 0;
  virtual INlExpr* Ceil(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Ceil(const INlExpr* expr) const = 0;

  virtual INlExpr* Cos(double c) const = 0;
  virtual INlExpr* Cos(const IVar* var) const = 0;
  virtual INlExpr* Cos(const IExpr* expr) const = 0;
  virtual INlExpr* Cos(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Cos(const INlExpr* expr) const = 0;

  virtual INlExpr* Sin(double c) const = 0;
  virtual INlExpr* Sin(const IVar* var) const = 0;
  virtual INlExpr* Sin(const IExpr* expr) const = 0;
  virtual INlExpr* Sin(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Sin(const INlExpr* expr) const = 0;

  virtual INlExpr* Tan(double c) const = 0;
  virtual INlExpr* Tan(const IVar* var) const = 0;
  virtual INlExpr* Tan(const IExpr* expr) const = 0;
  virtual INlExpr* Tan(const IQuadExpr* expr) const = 0;
  virtual INlExpr* Tan(const INlExpr* expr) const = 0;

  virtual INlExpr* CosH(double c) const = 0;
  virtual INlExpr* CosH(const IVar* var) const = 0;
  virtual INlExpr* CosH(const IExpr* expr) const = 0;
  virtual INlExpr* CosH(const IQuadExpr* expr) const = 0;
  virtual INlExpr* CosH(const INlExpr* expr) const = 0;

  virtual INlExpr* SinH(double c) const = 0;
  virtual INlExpr* SinH(const IVar* var) const = 0;
  virtual INlExpr* SinH(const IExpr* expr) const = 0;
  virtual INlExpr* SinH(const IQuadExpr* expr) const = 0;
  virtual INlExpr* SinH(const INlExpr* expr) const = 0;

  virtual INlExpr* TanH(double c) const = 0;
  virtual INlExpr* TanH(const IVar* var) const = 0;
  virtual INlExpr* TanH(const IExpr* expr) const = 0;
  virtual INlExpr* TanH(const IQuadExpr* expr) const = 0;
  virtual INlExpr* TanH(const INlExpr* expr) const = 0;

  virtual INlExpr* ACos(double c) const = 0;
  virtual INlExpr* ACos(const IVar* var) const = 0;
  virtual INlExpr* ACos(const IExpr* expr) const = 0;
  virtual INlExpr* ACos(const IQuadExpr* expr) const = 0;
  virtual INlExpr* ACos(const INlExpr* expr) const = 0;

  virtual INlExpr* ASin(double c) const = 0;
  virtual INlExpr* ASin(const IVar* var) const = 0;
  virtual INlExpr* ASin(const IExpr* expr) const = 0;
  virtual INlExpr* ASin(const IQuadExpr* expr) const = 0;
  virtual INlExpr* ASin(const INlExpr* expr) const = 0;

  virtual INlExpr* ATan(double c) const = 0;
  virtual INlExpr* ATan(const IVar* var) const = 0;
  virtual INlExpr* ATan(const IExpr* expr) const = 0;
  virtual INlExpr* ATan(const IQuadExpr* expr) const = 0;
  virtual INlExpr* ATan(const INlExpr* expr) const = 0;

  virtual INlExpr* ACosH(double c) const = 0;
  virtual INlExpr* ACosH(const IVar* var) const = 0;
  virtual INlExpr* ACosH(const IExpr* expr) const = 0;
  virtual INlExpr* ACosH(const IQuadExpr* expr) const = 0;
  virtual INlExpr* ACosH(const INlExpr* expr) const = 0;

  virtual INlExpr* ASinH(double c) const = 0;
  virtual INlExpr* ASinH(const IVar* var) const = 0;
  virtual INlExpr* ASinH(const IExpr* expr) const = 0;
  virtual INlExpr* ASinH(const IQuadExpr* expr) const = 0;
  virtual INlExpr* ASinH(const INlExpr* expr) const = 0;

  virtual INlExpr* ATanH(double c) const = 0;
  virtual INlExpr* ATanH(const IVar* var) const = 0;
  virtual INlExpr* ATanH(const IExpr* expr) const = 0;
  virtual INlExpr* ATanH(const IQuadExpr* expr) const = 0;
  virtual INlExpr* ATanH(const INlExpr* expr) const = 0;
};

class IMFactory {
public:
  virtual ~IMFactory() = default;

  /* create matrix modelling objects */
  virtual IMVar<0>* CreateMVar(const INDim<0>* shp, const IVar* var) const = 0;
  virtual IMVar<1>* CreateMVar(const INDim<1>* shp, const IVar* var) const = 0;
  virtual IMVar<2>* CreateMVar(const INDim<2>* shp, const IVar* var) const = 0;
  virtual IMVar<3>* CreateMVar(const INDim<3>* shp, const IVar* var) const = 0;
  virtual IMVar<0>* CreateMVar(const INDim<0>* shp, const IVarArray* vars) const = 0;
  virtual IMVar<1>* CreateMVar(const INDim<1>* shp, const IVarArray* vars) const = 0;
  virtual IMVar<2>* CreateMVar(const INDim<2>* shp, const IVarArray* vars) const = 0;
  virtual IMVar<3>* CreateMVar(const INDim<3>* shp, const IVarArray* vars) const = 0;

  virtual IMConstr<0>* CreateMConstr(const INDim<0>* shp, const IConstraint* con) const = 0;
  virtual IMConstr<1>* CreateMConstr(const INDim<1>* shp, const IConstraint* con) const = 0;
  virtual IMConstr<2>* CreateMConstr(const INDim<2>* shp, const IConstraint* con) const = 0;
  virtual IMConstr<3>* CreateMConstr(const INDim<3>* shp, const IConstraint* con) const = 0;
  virtual IMConstr<0>* CreateMConstr(const INDim<0>* shp, const IConstrArray* cons) const = 0;
  virtual IMConstr<1>* CreateMConstr(const INDim<1>* shp, const IConstrArray* cons) const = 0;
  virtual IMConstr<2>* CreateMConstr(const INDim<2>* shp, const IConstrArray* cons) const = 0;
  virtual IMConstr<3>* CreateMConstr(const INDim<3>* shp, const IConstrArray* cons) const = 0;

  virtual IMConstrBuilder<0>* CreateMConstrBuilder(const INDim<0>* shp) const = 0;
  virtual IMConstrBuilder<1>* CreateMConstrBuilder(const INDim<1>* shp) const = 0;
  virtual IMConstrBuilder<2>* CreateMConstrBuilder(const INDim<2>* shp) const = 0;
  virtual IMConstrBuilder<3>* CreateMConstrBuilder(const INDim<3>* shp) const = 0;

  virtual IMQConstr<0>* CreateMQConstr(const INDim<0>* shp, const IQConstraint* con) const = 0;
  virtual IMQConstr<1>* CreateMQConstr(const INDim<1>* shp, const IQConstraint* con) const = 0;
  virtual IMQConstr<2>* CreateMQConstr(const INDim<2>* shp, const IQConstraint* con) const = 0;
  virtual IMQConstr<3>* CreateMQConstr(const INDim<3>* shp, const IQConstraint* con) const = 0;
  virtual IMQConstr<0>* CreateMQConstr(const INDim<0>* shp, const IQConstrArray* cons) const = 0;
  virtual IMQConstr<1>* CreateMQConstr(const INDim<1>* shp, const IQConstrArray* cons) const = 0;
  virtual IMQConstr<2>* CreateMQConstr(const INDim<2>* shp, const IQConstrArray* cons) const = 0;
  virtual IMQConstr<3>* CreateMQConstr(const INDim<3>* shp, const IQConstrArray* cons) const = 0;

  virtual IMQConstrBuilder<0>* CreateMQConstrBuilder(const INDim<0>* shp) const = 0;
  virtual IMQConstrBuilder<1>* CreateMQConstrBuilder(const INDim<1>* shp) const = 0;
  virtual IMQConstrBuilder<2>* CreateMQConstrBuilder(const INDim<2>* shp) const = 0;
  virtual IMQConstrBuilder<3>* CreateMQConstrBuilder(const INDim<3>* shp) const = 0;

  virtual IMLinExpr<0>* CreateMLinExpr(const INDim<0>* shp, const IMExpression* expr) const = 0;
  virtual IMLinExpr<1>* CreateMLinExpr(const INDim<1>* shp, const IMExpression* expr) const = 0;
  virtual IMLinExpr<2>* CreateMLinExpr(const INDim<2>* shp, const IMExpression* expr) const = 0;
  virtual IMLinExpr<3>* CreateMLinExpr(const INDim<3>* shp, const IMExpression* expr) const = 0;
  virtual IMLinExpr<0>* CreateMLinExpr(const INDim<0>* shp, const IExpr* expr) const = 0;
  virtual IMLinExpr<1>* CreateMLinExpr(const INDim<1>* shp, const IExpr* expr) const = 0;
  virtual IMLinExpr<2>* CreateMLinExpr(const INDim<2>* shp, const IExpr* expr) const = 0;
  virtual IMLinExpr<3>* CreateMLinExpr(const INDim<3>* shp, const IExpr* expr) const = 0;
  virtual IMLinExpr<0>* CreateMLinExpr(const INDim<0>* shp, double constant) const = 0;
  virtual IMLinExpr<1>* CreateMLinExpr(const INDim<1>* shp, double constant) const = 0;
  virtual IMLinExpr<2>* CreateMLinExpr(const INDim<2>* shp, double constant) const = 0;
  virtual IMLinExpr<3>* CreateMLinExpr(const INDim<3>* shp, double constant) const = 0;

  virtual IMExpression* CreateMExpression(double constant) const = 0;
  virtual IMExpression* CreateMExpression(const IExpr* expr) const = 0;

  virtual IMQuadExpr<0>* CreateMQuadExpr(const INDim<0>* shp, const IMQExpression* expr) const = 0;
  virtual IMQuadExpr<1>* CreateMQuadExpr(const INDim<1>* shp, const IMQExpression* expr) const = 0;
  virtual IMQuadExpr<2>* CreateMQuadExpr(const INDim<2>* shp, const IMQExpression* expr) const = 0;
  virtual IMQuadExpr<3>* CreateMQuadExpr(const INDim<3>* shp, const IMQExpression* expr) const = 0;
  virtual IMQuadExpr<0>* CreateMQuadExpr(const INDim<0>* shp, const IQuadExpr* expr) const = 0;
  virtual IMQuadExpr<1>* CreateMQuadExpr(const INDim<1>* shp, const IQuadExpr* expr) const = 0;
  virtual IMQuadExpr<2>* CreateMQuadExpr(const INDim<2>* shp, const IQuadExpr* expr) const = 0;
  virtual IMQuadExpr<3>* CreateMQuadExpr(const INDim<3>* shp, const IQuadExpr* expr) const = 0;
  virtual IMQuadExpr<0>* CreateMQuadExpr(const INDim<0>* shp, double constant) const = 0;
  virtual IMQuadExpr<1>* CreateMQuadExpr(const INDim<1>* shp, double constant) const = 0;
  virtual IMQuadExpr<2>* CreateMQuadExpr(const INDim<2>* shp, double constant) const = 0;
  virtual IMQuadExpr<3>* CreateMQuadExpr(const INDim<3>* shp, double constant) const = 0;

  virtual IMQExpression* CreateMQExpression(double constant) const = 0;
  virtual IMQExpression* CreateMQExpression(const IQuadExpr* expr) const = 0;

  virtual IMPsdExpr<0>* CreateMPsdExpr(const INDim<0>* shp, const IMExpression* expr) const = 0;
  virtual IMPsdExpr<1>* CreateMPsdExpr(const INDim<1>* shp, const IMExpression* expr) const = 0;
  virtual IMPsdExpr<2>* CreateMPsdExpr(const INDim<2>* shp, const IMExpression* expr) const = 0;
  virtual IMPsdExpr<3>* CreateMPsdExpr(const INDim<3>* shp, const IMExpression* expr) const = 0;
  virtual IMPsdExpr<0>* CreateMPsdExpr(const INDim<0>* shp, const IPsdExpr* expr) const = 0;
  virtual IMPsdExpr<1>* CreateMPsdExpr(const INDim<1>* shp, const IPsdExpr* expr) const = 0;
  virtual IMPsdExpr<2>* CreateMPsdExpr(const INDim<2>* shp, const IPsdExpr* expr) const = 0;
  virtual IMPsdExpr<3>* CreateMPsdExpr(const INDim<3>* shp, const IPsdExpr* expr) const = 0;
  virtual IMPsdExpr<0>* CreateMPsdExpr(const INDim<0>* shp, double constant) const = 0;
  virtual IMPsdExpr<1>* CreateMPsdExpr(const INDim<1>* shp, double constant) const = 0;
  virtual IMPsdExpr<2>* CreateMPsdExpr(const INDim<2>* shp, double constant) const = 0;
  virtual IMPsdExpr<3>* CreateMPsdExpr(const INDim<3>* shp, double constant) const = 0;

  virtual IMPsdConstr<0>* CreateMPsdConstr(const INDim<0>* shp, const IPsdConstraint* con) const = 0;
  virtual IMPsdConstr<1>* CreateMPsdConstr(const INDim<1>* shp, const IPsdConstraint* con) const = 0;
  virtual IMPsdConstr<2>* CreateMPsdConstr(const INDim<2>* shp, const IPsdConstraint* con) const = 0;
  virtual IMPsdConstr<3>* CreateMPsdConstr(const INDim<3>* shp, const IPsdConstraint* con) const = 0;
  virtual IMPsdConstr<0>* CreateMPsdConstr(const INDim<0>* shp, const IPsdConstrArray* cons) const = 0;
  virtual IMPsdConstr<1>* CreateMPsdConstr(const INDim<1>* shp, const IPsdConstrArray* cons) const = 0;
  virtual IMPsdConstr<2>* CreateMPsdConstr(const INDim<2>* shp, const IPsdConstrArray* cons) const = 0;
  virtual IMPsdConstr<3>* CreateMPsdConstr(const INDim<3>* shp, const IPsdConstrArray* cons) const = 0;

  virtual IMPsdConstrBuilder<0>* CreateMPsdConstrBuilder(const INDim<0>* shp) const = 0;
  virtual IMPsdConstrBuilder<1>* CreateMPsdConstrBuilder(const INDim<1>* shp) const = 0;
  virtual IMPsdConstrBuilder<2>* CreateMPsdConstrBuilder(const INDim<2>* shp) const = 0;
  virtual IMPsdConstrBuilder<3>* CreateMPsdConstrBuilder(const INDim<3>* shp) const = 0;

  /* create NDim and NdArray of number */
  virtual INDim<0>* CreateNDim() const = 0;
  virtual INDim<1>* CreateNDim(size_t dim0) const = 0;
  virtual INDim<2>* CreateNDim(size_t dim0, size_t dim1) const = 0;
  virtual INDim<3>* CreateNDim(size_t dim0, size_t dim1, size_t dim2) const = 0;

  virtual INdArray<int, 0>* CreateNdArray(const INDim<0>* shape, int val) const = 0;
  virtual INdArray<int, 1>* CreateNdArray(const INDim<1>* shape, int val) const = 0;
  virtual INdArray<int, 2>* CreateNdArray(const INDim<2>* shape, int val) const = 0;
  virtual INdArray<int, 3>* CreateNdArray(const INDim<3>* shape, int val) const = 0;

  virtual INdArray<double, 0>* CreateNdArray(const INDim<0>* shape, double val) const = 0;
  virtual INdArray<double, 1>* CreateNdArray(const INDim<1>* shape, double val) const = 0;
  virtual INdArray<double, 2>* CreateNdArray(const INDim<2>* shape, double val) const = 0;
  virtual INdArray<double, 3>* CreateNdArray(const INDim<3>* shape, double val) const = 0;

  virtual INdArray<int64_t, 0>* CreateNdArray(const INDim<0>* shape, int64_t val) const = 0;
  virtual INdArray<int64_t, 1>* CreateNdArray(const INDim<1>* shape, int64_t val) const = 0;
  virtual INdArray<int64_t, 2>* CreateNdArray(const INDim<2>* shape, int64_t val) const = 0;
  virtual INdArray<int64_t, 3>* CreateNdArray(const INDim<3>* shape, int64_t val) const = 0;

  virtual INdArray<double, 0>* CreateNdArray(const INDim<0>* shape, const double* data, size_t sz) const = 0;
  virtual INdArray<double, 1>* CreateNdArray(const INDim<1>* shape, const double* data, size_t sz) const = 0;
  virtual INdArray<double, 2>* CreateNdArray(const INDim<2>* shape, const double* data, size_t sz) const = 0;
  virtual INdArray<double, 3>* CreateNdArray(const INDim<3>* shape, const double* data, size_t sz) const = 0;

  virtual INdArray<int64_t, 0>* CreateNdArray(const INDim<0>* shape, const int64_t* data, size_t sz) const = 0;
  virtual INdArray<int64_t, 1>* CreateNdArray(const INDim<1>* shape, const int64_t* data, size_t sz) const = 0;
  virtual INdArray<int64_t, 2>* CreateNdArray(const INDim<2>* shape, const int64_t* data, size_t sz) const = 0;
  virtual INdArray<int64_t, 3>* CreateNdArray(const INDim<3>* shape, const int64_t* data, size_t sz) const = 0;

  virtual INdArray<int, 0>* CreateNdArray(const INDim<0>* shape, const int* data, size_t sz) const = 0;
  virtual INdArray<int, 1>* CreateNdArray(const INDim<1>* shape, const int* data, size_t sz) const = 0;
  virtual INdArray<int, 2>* CreateNdArray(const INDim<2>* shape, const int* data, size_t sz) const = 0;
  virtual INdArray<int, 3>* CreateNdArray(const INDim<3>* shape, const int* data, size_t sz) const = 0;

  virtual INdArray<double, 0>* CreateNdArray(const INDim<0>* shape, double (*func)(size_t)) const = 0;
  virtual INdArray<double, 1>* CreateNdArray(const INDim<1>* shape, double (*func)(size_t)) const = 0;
  virtual INdArray<double, 2>* CreateNdArray(const INDim<2>* shape, double (*func)(size_t)) const = 0;
  virtual INdArray<double, 3>* CreateNdArray(const INDim<3>* shape, double (*func)(size_t)) const = 0;

  virtual INdArray<int, 0>* CreateNdArray(const INDim<0>* shape, int (*func)(size_t)) const = 0;
  virtual INdArray<int, 1>* CreateNdArray(const INDim<1>* shape, int (*func)(size_t)) const = 0;
  virtual INdArray<int, 2>* CreateNdArray(const INDim<2>* shape, int (*func)(size_t)) const = 0;
  virtual INdArray<int, 3>* CreateNdArray(const INDim<3>* shape, int (*func)(size_t)) const = 0;

  virtual IView* CreateView() const = 0;
};

class IMHelper {
public:
  virtual ~IMHelper() = default;

  /* matrix multiplication of NdArray and MObj */
  virtual IMLinExpr<0>* MatMultiply(const INdArray<double, 1>* A, const IVarArray* vars) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<double, 2>* A, const IVarArray* vars) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const INdArray<int64_t, 1>* A, const IVarArray* vars) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int64_t, 2>* A, const IVarArray* vars) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const INdArray<int, 1>* A, const IVarArray* vars) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int, 2>* A, const IVarArray* vars) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const INdArray<double, 1>* A, const IMVar<1>* vars) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<double, 1>* A, const IMVar<2>* vars) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<double, 2>* A, const IMVar<1>* vars) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const INdArray<double, 2>* A, const IMVar<2>* vars) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const INdArray<int64_t, 1>* A, const IMVar<1>* vars) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int64_t, 1>* A, const IMVar<2>* vars) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int64_t, 2>* A, const IMVar<1>* vars) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const INdArray<int64_t, 2>* A, const IMVar<2>* vars) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const INdArray<int, 1>* A, const IMVar<1>* vars) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int, 1>* A, const IMVar<2>* vars) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int, 2>* A, const IMVar<1>* vars) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const INdArray<int, 2>* A, const IMVar<2>* vars) const = 0;

  virtual IMLinExpr<0>* MatMultiply(const INdArray<double, 1>* A, const IMLinExpr<1>* exprs) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<double, 1>* A, const IMLinExpr<2>* exprs) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<double, 2>* A, const IMLinExpr<1>* exprs) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const INdArray<double, 2>* A, const IMLinExpr<2>* exprs) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const INdArray<int64_t, 1>* A, const IMLinExpr<1>* exprs) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int64_t, 1>* A, const IMLinExpr<2>* exprs) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int64_t, 2>* A, const IMLinExpr<1>* exprs) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const INdArray<int64_t, 2>* A, const IMLinExpr<2>* exprs) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const INdArray<int, 1>* A, const IMLinExpr<1>* exprs) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int, 1>* A, const IMLinExpr<2>* exprs) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const INdArray<int, 2>* A, const IMLinExpr<1>* exprs) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const INdArray<int, 2>* A, const IMLinExpr<2>* exprs) const = 0;

  virtual IMQuadExpr<0>* MatMultiply(const INdArray<double, 1>* A, const IMQuadExpr<1>* exprs) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const INdArray<double, 1>* A, const IMQuadExpr<2>* exprs) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const INdArray<double, 2>* A, const IMQuadExpr<1>* exprs) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const INdArray<double, 2>* A, const IMQuadExpr<2>* exprs) const = 0;
  virtual IMQuadExpr<0>* MatMultiply(const INdArray<int64_t, 1>* A, const IMQuadExpr<1>* exprs) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const INdArray<int64_t, 1>* A, const IMQuadExpr<2>* exprs) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const INdArray<int64_t, 2>* A, const IMQuadExpr<1>* exprs) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const INdArray<int64_t, 2>* A, const IMQuadExpr<2>* exprs) const = 0;
  virtual IMQuadExpr<0>* MatMultiply(const INdArray<int, 1>* A, const IMQuadExpr<1>* exprs) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const INdArray<int, 1>* A, const IMQuadExpr<2>* exprs) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const INdArray<int, 2>* A, const IMQuadExpr<1>* exprs) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const INdArray<int, 2>* A, const IMQuadExpr<2>* exprs) const = 0;

  virtual IMPsdExpr<0>* MatMultiply(const INdArray<double, 1>* A, const IMPsdExpr<1>* exprs) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const INdArray<double, 1>* A, const IMPsdExpr<2>* exprs) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const INdArray<double, 2>* A, const IMPsdExpr<1>* exprs) const = 0;
  virtual IMPsdExpr<2>* MatMultiply(const INdArray<double, 2>* A, const IMPsdExpr<2>* exprs) const = 0;
  virtual IMPsdExpr<0>* MatMultiply(const INdArray<int64_t, 1>* A, const IMPsdExpr<1>* exprs) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const INdArray<int64_t, 1>* A, const IMPsdExpr<2>* exprs) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const INdArray<int64_t, 2>* A, const IMPsdExpr<1>* exprs) const = 0;
  virtual IMPsdExpr<2>* MatMultiply(const INdArray<int64_t, 2>* A, const IMPsdExpr<2>* exprs) const = 0;
  virtual IMPsdExpr<0>* MatMultiply(const INdArray<int, 1>* A, const IMPsdExpr<1>* exprs) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const INdArray<int, 1>* A, const IMPsdExpr<2>* exprs) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const INdArray<int, 2>* A, const IMPsdExpr<1>* exprs) const = 0;
  virtual IMPsdExpr<2>* MatMultiply(const INdArray<int, 2>* A, const IMPsdExpr<2>* exprs) const = 0;

  virtual IMLinExpr<0>* MatMultiply(const IVarArray* vars, const INdArray<double, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IVarArray* vars, const INdArray<double, 2>* A) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const IVarArray* vars, const INdArray<int64_t, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IVarArray* vars, const INdArray<int64_t, 2>* A) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const IVarArray* vars, const INdArray<int, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IVarArray* vars, const INdArray<int, 2>* A) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const IMVar<1>* vars, const INdArray<double, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMVar<2>* vars, const INdArray<double, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMVar<1>* vars, const INdArray<double, 2>* A) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const IMVar<2>* vars, const INdArray<double, 2>* A) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const IMVar<1>* vars, const INdArray<int64_t, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMVar<2>* vars, const INdArray<int64_t, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMVar<1>* vars, const INdArray<int64_t, 2>* A) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const IMVar<2>* vars, const INdArray<int64_t, 2>* A) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const IMVar<1>* vars, const INdArray<int, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMVar<2>* vars, const INdArray<int, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMVar<1>* vars, const INdArray<int, 2>* A) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const IMVar<2>* vars, const INdArray<int, 2>* A) const = 0;

  virtual IMQuadExpr<0>* MatMultiply(const IMVar<1>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMVar<1>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMVar<2>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const IMVar<2>* left, const IMVar<2>* right) const = 0;

  virtual IMQuadExpr<0>* MatMultiply(const IMVar<1>* vars, const IMLinExpr<1>* exprs) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMVar<1>* vars, const IMLinExpr<2>* exprs) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMVar<2>* vars, const IMLinExpr<1>* exprs) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const IMVar<2>* vars, const IMLinExpr<2>* exprs) const = 0;

  virtual IMLinExpr<0>* MatMultiply(const IMLinExpr<1>* exprs, const INdArray<double, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMLinExpr<2>* exprs, const INdArray<double, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMLinExpr<1>* exprs, const INdArray<double, 2>* A) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const IMLinExpr<2>* exprs, const INdArray<double, 2>* A) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const IMLinExpr<1>* exprs, const INdArray<int64_t, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMLinExpr<2>* exprs, const INdArray<int64_t, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMLinExpr<1>* exprs, const INdArray<int64_t, 2>* A) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const IMLinExpr<2>* exprs, const INdArray<int64_t, 2>* A) const = 0;
  virtual IMLinExpr<0>* MatMultiply(const IMLinExpr<1>* exprs, const INdArray<int, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMLinExpr<2>* exprs, const INdArray<int, 1>* A) const = 0;
  virtual IMLinExpr<1>* MatMultiply(const IMLinExpr<1>* exprs, const INdArray<int, 2>* A) const = 0;
  virtual IMLinExpr<2>* MatMultiply(const IMLinExpr<2>* exprs, const INdArray<int, 2>* A) const = 0;

  virtual IMQuadExpr<0>* MatMultiply(const IMLinExpr<1>* exprs, const IMVar<1>* vars) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMLinExpr<1>* exprs, const IMVar<2>* vars) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMLinExpr<2>* exprs, const IMVar<1>* vars) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const IMLinExpr<2>* exprs, const IMVar<2>* vars) const = 0;

  virtual IMQuadExpr<0>* MatMultiply(const IMLinExpr<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMLinExpr<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMLinExpr<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const IMLinExpr<2>* left, const IMLinExpr<2>* right) const = 0;

  virtual IMQuadExpr<0>* MatMultiply(const IMQuadExpr<1>* exprs, const INdArray<double, 1>* A) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMQuadExpr<2>* exprs, const INdArray<double, 1>* A) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMQuadExpr<1>* exprs, const INdArray<double, 2>* A) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const IMQuadExpr<2>* exprs, const INdArray<double, 2>* A) const = 0;
  virtual IMQuadExpr<0>* MatMultiply(const IMQuadExpr<1>* exprs, const INdArray<int64_t, 1>* A) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMQuadExpr<2>* exprs, const INdArray<int64_t, 1>* A) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMQuadExpr<1>* exprs, const INdArray<int64_t, 2>* A) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const IMQuadExpr<2>* exprs, const INdArray<int64_t, 2>* A) const = 0;
  virtual IMQuadExpr<0>* MatMultiply(const IMQuadExpr<1>* exprs, const INdArray<int, 1>* A) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMQuadExpr<2>* exprs, const INdArray<int, 1>* A) const = 0;
  virtual IMQuadExpr<1>* MatMultiply(const IMQuadExpr<1>* exprs, const INdArray<int, 2>* A) const = 0;
  virtual IMQuadExpr<2>* MatMultiply(const IMQuadExpr<2>* exprs, const INdArray<int, 2>* A) const = 0;

  virtual IMPsdExpr<0>* MatMultiply(const IMPsdExpr<1>* exprs, const INdArray<double, 1>* A) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const IMPsdExpr<2>* exprs, const INdArray<double, 1>* A) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const IMPsdExpr<1>* exprs, const INdArray<double, 2>* A) const = 0;
  virtual IMPsdExpr<2>* MatMultiply(const IMPsdExpr<2>* exprs, const INdArray<double, 2>* A) const = 0;
  virtual IMPsdExpr<0>* MatMultiply(const IMPsdExpr<1>* exprs, const INdArray<int64_t, 1>* A) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const IMPsdExpr<2>* exprs, const INdArray<int64_t, 1>* A) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const IMPsdExpr<1>* exprs, const INdArray<int64_t, 2>* A) const = 0;
  virtual IMPsdExpr<2>* MatMultiply(const IMPsdExpr<2>* exprs, const INdArray<int64_t, 2>* A) const = 0;
  virtual IMPsdExpr<0>* MatMultiply(const IMPsdExpr<1>* exprs, const INdArray<int, 1>* A) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const IMPsdExpr<2>* exprs, const INdArray<int, 1>* A) const = 0;
  virtual IMPsdExpr<1>* MatMultiply(const IMPsdExpr<1>* exprs, const INdArray<int, 2>* A) const = 0;
  virtual IMPsdExpr<2>* MatMultiply(const IMPsdExpr<2>* exprs, const INdArray<int, 2>* A) const = 0;

  virtual INdArray<double, 0>* MatMultiply(const INdArray<double, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 1>* MatMultiply(const INdArray<double, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 1>* MatMultiply(const INdArray<double, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* MatMultiply(const INdArray<double, 2>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 0>* MatMultiply(const INdArray<int64_t, 1>* left,
    const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 1>* MatMultiply(const INdArray<int64_t, 1>* left,
    const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 1>* MatMultiply(const INdArray<int64_t, 2>* left,
    const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* MatMultiply(const INdArray<int64_t, 2>* left,
    const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 0>* MatMultiply(const INdArray<int, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 1>* MatMultiply(const INdArray<int, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 1>* MatMultiply(const INdArray<int, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* MatMultiply(const INdArray<int, 2>* left, const INdArray<double, 2>* right) const = 0;

  virtual INdArray<double, 0>* MatMultiply(const INdArray<double, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 1>* MatMultiply(const INdArray<double, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 1>* MatMultiply(const INdArray<double, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* MatMultiply(const INdArray<double, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 0>* MatMultiply(const INdArray<int64_t, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 1>* MatMultiply(const INdArray<int64_t, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 1>* MatMultiply(const INdArray<int64_t, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* MatMultiply(const INdArray<int64_t, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 0>* MatMultiply(const INdArray<int, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 1>* MatMultiply(const INdArray<int, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 1>* MatMultiply(const INdArray<int, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* MatMultiply(const INdArray<int, 2>* left, const INdArray<int, 2>* right) const = 0;

  // Diagonal overloads
  virtual IMVar<2>* Diagonal(const IMVar<3>* vars, int offset, int axis1, int axis2) const = 0;
  virtual IMVar<1>* Diagonal(const IMVar<2>* vars, int offset, int axis1, int axis2) const = 0;
  virtual IMConstr<2>* Diagonal(const IMConstr<3>* cons, int offset, int axis1, int axis2) const = 0;
  virtual IMConstr<1>* Diagonal(const IMConstr<2>* cons, int offset, int axis1, int axis2) const = 0;
  virtual IMQConstr<2>* Diagonal(const IMQConstr<3>* cons, int offset, int axis1, int axis2) const = 0;
  virtual IMQConstr<1>* Diagonal(const IMQConstr<2>* cons, int offset, int axis1, int axis2) const = 0;
  virtual IMPsdConstr<2>* Diagonal(const IMPsdConstr<3>* cons, int offset, int axis1, int axis2) const = 0;
  virtual IMPsdConstr<1>* Diagonal(const IMPsdConstr<2>* cons, int offset, int axis1, int axis2) const = 0;
  virtual IMLinExpr<2>* Diagonal(const IMLinExpr<3>* exprs, int offset, int axis1, int axis2) const = 0;
  virtual IMLinExpr<1>* Diagonal(const IMLinExpr<2>* exprs, int offset, int axis1, int axis2) const = 0;
  virtual IMQuadExpr<2>* Diagonal(const IMQuadExpr<3>* exprs, int offset, int axis1, int axis2) const = 0;
  virtual IMQuadExpr<1>* Diagonal(const IMQuadExpr<2>* exprs, int offset, int axis1, int axis2) const = 0;
  virtual IMPsdExpr<2>* Diagonal(const IMPsdExpr<3>* exprs, int offset, int axis1, int axis2) const = 0;
  virtual IMPsdExpr<1>* Diagonal(const IMPsdExpr<2>* exprs, int offset, int axis1, int axis2) const = 0;
  virtual INdArray<double, 2>* Diagonal(const INdArray<double, 3>* mat, int offset, int axis1, int axis2) const = 0;
  virtual INdArray<double, 1>* Diagonal(const INdArray<double, 2>* mat, int offset, int axis1, int axis2) const = 0;
  virtual INdArray<int64_t, 2>* Diagonal(const INdArray<int64_t, 3>* mat, int offset, int axis1, int axis2) const = 0;
  virtual INdArray<int64_t, 1>* Diagonal(const INdArray<int64_t, 2>* mat, int offset, int axis1, int axis2) const = 0;
  virtual INdArray<int, 2>* Diagonal(const INdArray<int, 3>* mat, int offset, int axis1, int axis2) const = 0;
  virtual INdArray<int, 1>* Diagonal(const INdArray<int, 2>* mat, int offset, int axis1, int axis2) const = 0;

  // Expand overloads
  virtual INDim<1>* Expand(const INDim<0>* shape, int axis) const = 0;
  virtual INDim<2>* Expand(const INDim<1>* shape, int axis) const = 0;
  virtual INDim<3>* Expand(const INDim<2>* shape, int axis) const = 0;
  virtual IMVar<3>* Expand(const IMVar<2>* vars, int axis) const = 0;
  virtual IMVar<2>* Expand(const IMVar<1>* vars, int axis) const = 0;
  virtual IMVar<1>* Expand(const IMVar<0>* vars, int axis) const = 0;
  virtual IMConstr<3>* Expand(const IMConstr<2>* cons, int axis) const = 0;
  virtual IMConstr<2>* Expand(const IMConstr<1>* cons, int axis) const = 0;
  virtual IMConstr<1>* Expand(const IMConstr<0>* cons, int axis) const = 0;
  virtual IMQConstr<3>* Expand(const IMQConstr<2>* cons, int axis) const = 0;
  virtual IMQConstr<2>* Expand(const IMQConstr<1>* cons, int axis) const = 0;
  virtual IMQConstr<1>* Expand(const IMQConstr<0>* cons, int axis) const = 0;
  virtual IMPsdConstr<3>* Expand(const IMPsdConstr<2>* cons, int axis) const = 0;
  virtual IMPsdConstr<2>* Expand(const IMPsdConstr<1>* cons, int axis) const = 0;
  virtual IMPsdConstr<1>* Expand(const IMPsdConstr<0>* cons, int axis) const = 0;
  virtual IMLinExpr<3>* Expand(const IMLinExpr<2>* exprs, int axis) const = 0;
  virtual IMLinExpr<2>* Expand(const IMLinExpr<1>* exprs, int axis) const = 0;
  virtual IMLinExpr<1>* Expand(const IMLinExpr<0>* exprs, int axis) const = 0;
  virtual IMQuadExpr<3>* Expand(const IMQuadExpr<2>* exprs, int axis) const = 0;
  virtual IMQuadExpr<2>* Expand(const IMQuadExpr<1>* exprs, int axis) const = 0;
  virtual IMQuadExpr<1>* Expand(const IMQuadExpr<0>* exprs, int axis) const = 0;
  virtual IMPsdExpr<3>* Expand(const IMPsdExpr<2>* exprs, int axis) const = 0;
  virtual IMPsdExpr<2>* Expand(const IMPsdExpr<1>* exprs, int axis) const = 0;
  virtual IMPsdExpr<1>* Expand(const IMPsdExpr<0>* exprs, int axis) const = 0;
  virtual INdArray<double, 3>* Expand(const INdArray<double, 2>* mat, int axis) const = 0;
  virtual INdArray<double, 2>* Expand(const INdArray<double, 1>* mat, int axis) const = 0;
  virtual INdArray<double, 1>* Expand(const INdArray<double, 0>* mat, int axis) const = 0;
  virtual INdArray<int64_t, 3>* Expand(const INdArray<int64_t, 2>* mat, int axis) const = 0;
  virtual INdArray<int64_t, 2>* Expand(const INdArray<int64_t, 1>* mat, int axis) const = 0;
  virtual INdArray<int64_t, 1>* Expand(const INdArray<int64_t, 0>* mat, int axis) const = 0;
  virtual INdArray<int, 3>* Expand(const INdArray<int, 2>* mat, int axis) const = 0;
  virtual INdArray<int, 2>* Expand(const INdArray<int, 1>* mat, int axis) const = 0;
  virtual INdArray<int, 1>* Expand(const INdArray<int, 0>* mat, int axis) const = 0;

  // Squeeze overloads
  virtual INDim<2>* Squeeze(const INDim<3>* shape, int axis) const = 0;
  virtual INDim<1>* Squeeze(const INDim<2>* shape, int axis) const = 0;
  virtual INDim<0>* Squeeze(const INDim<1>* shape, int axis) const = 0;
  virtual IMVar<2>* Squeeze(const IMVar<3>* vars, int axis) const = 0;
  virtual IMVar<1>* Squeeze(const IMVar<2>* vars, int axis) const = 0;
  virtual IMVar<0>* Squeeze(const IMVar<1>* vars, int axis) const = 0;
  virtual IMConstr<2>* Squeeze(const IMConstr<3>* cons, int axis) const = 0;
  virtual IMConstr<1>* Squeeze(const IMConstr<2>* cons, int axis) const = 0;
  virtual IMConstr<0>* Squeeze(const IMConstr<1>* cons, int axis) const = 0;
  virtual IMQConstr<2>* Squeeze(const IMQConstr<3>* cons, int axis) const = 0;
  virtual IMQConstr<1>* Squeeze(const IMQConstr<2>* cons, int axis) const = 0;
  virtual IMQConstr<0>* Squeeze(const IMQConstr<1>* cons, int axis) const = 0;
  virtual IMPsdConstr<2>* Squeeze(const IMPsdConstr<3>* cons, int axis) const = 0;
  virtual IMPsdConstr<1>* Squeeze(const IMPsdConstr<2>* cons, int axis) const = 0;
  virtual IMPsdConstr<0>* Squeeze(const IMPsdConstr<1>* cons, int axis) const = 0;
  virtual IMLinExpr<2>* Squeeze(const IMLinExpr<3>* exprs, int axis) const = 0;
  virtual IMLinExpr<1>* Squeeze(const IMLinExpr<2>* exprs, int axis) const = 0;
  virtual IMLinExpr<0>* Squeeze(const IMLinExpr<1>* exprs, int axis) const = 0;
  virtual IMQuadExpr<2>* Squeeze(const IMQuadExpr<3>* exprs, int axis) const = 0;
  virtual IMQuadExpr<1>* Squeeze(const IMQuadExpr<2>* exprs, int axis) const = 0;
  virtual IMQuadExpr<0>* Squeeze(const IMQuadExpr<1>* exprs, int axis) const = 0;
  virtual IMPsdExpr<2>* Squeeze(const IMPsdExpr<3>* exprs, int axis) const = 0;
  virtual IMPsdExpr<1>* Squeeze(const IMPsdExpr<2>* exprs, int axis) const = 0;
  virtual IMPsdExpr<0>* Squeeze(const IMPsdExpr<1>* exprs, int axis) const = 0;
  virtual INdArray<double, 2>* Squeeze(const INdArray<double, 3>* mat, int axis) const = 0;
  virtual INdArray<double, 1>* Squeeze(const INdArray<double, 2>* mat, int axis) const = 0;
  virtual INdArray<double, 0>* Squeeze(const INdArray<double, 1>* mat, int axis) const = 0;
  virtual INdArray<int64_t, 2>* Squeeze(const INdArray<int64_t, 3>* mat, int axis) const = 0;
  virtual INdArray<int64_t, 1>* Squeeze(const INdArray<int64_t, 2>* mat, int axis) const = 0;
  virtual INdArray<int64_t, 0>* Squeeze(const INdArray<int64_t, 1>* mat, int axis) const = 0;
  virtual INdArray<int, 2>* Squeeze(const INdArray<int, 3>* mat, int axis) const = 0;
  virtual INdArray<int, 1>* Squeeze(const INdArray<int, 2>* mat, int axis) const = 0;
  virtual INdArray<int, 0>* Squeeze(const INdArray<int, 1>* mat, int axis) const = 0;

  virtual INdArray<double, 1>* Repeat(double a, size_t repeats) const = 0;
  virtual INdArray<int64_t, 1>* Repeat(int64_t a, size_t repeats) const = 0;
  virtual INdArray<int, 1>* Repeat(int a, size_t repeats) const = 0;
  virtual IMVar<1>* Repeat(const IVar* var, size_t repeats) const = 0;
  virtual IMLinExpr<1>* Repeat(const IMExpression* expr, size_t repeats) const = 0;
  virtual IMQuadExpr<1>* Repeat(const IMQExpression* expr, size_t repeats) const = 0;
  virtual IMPsdExpr<1>* Repeat(const IPsdExpr* expr, size_t repeats) const = 0;

  // Stack overloads for dimensions of 3
  virtual INdArray<double, 3>* Stack(const INdArray<double, 3>* A1, const INdArray<double, 3>* A2, int axis) const = 0;
  virtual INdArray<double, 3>* Stack(const INdArray<double, 3>* A1, const INdArray<int64_t, 3>* A2, int axis) const = 0;
  virtual INdArray<double, 3>* Stack(const INdArray<double, 3>* A1, const INdArray<int, 3>* A2, int axis) const = 0;
  virtual INdArray<int64_t, 3>* Stack(const INdArray<int64_t, 3>* A1, const INdArray<int, 3>* A2, int axis) const = 0;
  virtual INdArray<int64_t, 3>*
  Stack(const INdArray<int64_t, 3>* A1, const INdArray<int64_t, 3>* A2, int axis) const = 0;
  virtual INdArray<double, 3>* Stack(const INdArray<int64_t, 3>* A1, const INdArray<double, 3>* A2, int axis) const = 0;
  virtual INdArray<double, 3>* Stack(const INdArray<int, 3>* A1, const INdArray<double, 3>* A2, int axis) const = 0;
  virtual INdArray<int64_t, 3>* Stack(const INdArray<int, 3>* A1, const INdArray<int64_t, 3>* A2, int axis) const = 0;
  virtual INdArray<int, 3>* Stack(const INdArray<int, 3>* A1, const INdArray<int, 3>* A2, int axis) const = 0;

  virtual IMConstr<3>* Stack(const IMConstr<3>* cons1, const IMConstr<3>* cons2, int axis) const = 0;
  virtual IMQConstr<3>* Stack(const IMQConstr<3>* cons1, const IMQConstr<3>* cons2, int axis) const = 0;
  virtual IMPsdConstr<3>* Stack(const IMPsdConstr<3>* cons1, const IMPsdConstr<3>* cons2, int axis) const = 0;
  virtual IMVar<3>* Stack(const IMVar<3>* vars1, const IMVar<3>* vars2, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const IMVar<3>* vars, const IMLinExpr<3>* exprs, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const IMVar<3>* vars, const INdArray<double, 3>* A, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const IMVar<3>* vars, const INdArray<int64_t, 3>* A, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const IMVar<3>* vars, const INdArray<int, 3>* A, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const INdArray<double, 3>* A, const IMVar<3>* vars, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const INdArray<int64_t, 3>* A, const IMVar<3>* vars, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const INdArray<int, 3>* A, const IMVar<3>* vars, int axis) const = 0;

  virtual IMLinExpr<3>* Stack(const IMLinExpr<3>* exprs, const IMVar<3>* vars, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const IMLinExpr<3>* exprs1, const IMLinExpr<3>* exprs2, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const IMLinExpr<3>* exprs, const INdArray<double, 3>* A, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const IMLinExpr<3>* exprs, const INdArray<int64_t, 3>* A, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const IMLinExpr<3>* exprs, const INdArray<int, 3>* A, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const INdArray<double, 3>* A, const IMLinExpr<3>* exprs, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const INdArray<int64_t, 3>* A, const IMLinExpr<3>* exprs, int axis) const = 0;
  virtual IMLinExpr<3>* Stack(const INdArray<int, 3>* A, const IMLinExpr<3>* exprs, int axis) const = 0;

  virtual IMQuadExpr<3>* Stack(const IMQuadExpr<3>* qexprs, const IMVar<3>* vars, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const IMQuadExpr<3>* qexprs, const IMLinExpr<3>* exprs, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const IMQuadExpr<3>* qexprs1, const IMQuadExpr<3>* qexprs2, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const IMQuadExpr<3>* qexprs, const INdArray<double, 3>* A, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const IMQuadExpr<3>* qexprs, const INdArray<int64_t, 3>* A, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const IMQuadExpr<3>* qexprs, const INdArray<int, 3>* A, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const IMVar<3>* vars, const IMQuadExpr<3>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const IMLinExpr<3>* exprs, const IMQuadExpr<3>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const INdArray<double, 3>* A, const IMQuadExpr<3>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const INdArray<int64_t, 3>* A, const IMQuadExpr<3>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<3>* Stack(const INdArray<int, 3>* A, const IMQuadExpr<3>* qexprs, int axis) const = 0;

  virtual IMPsdExpr<3>* Stack(const IMPsdExpr<3>* qexprs, const IMVar<3>* vars, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const IMPsdExpr<3>* qexprs, const IMLinExpr<3>* exprs, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const IMPsdExpr<3>* qexprs1, const IMPsdExpr<3>* qexprs2, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const IMPsdExpr<3>* qexprs, const INdArray<double, 3>* A, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const IMPsdExpr<3>* qexprs, const INdArray<int64_t, 3>* A, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const IMPsdExpr<3>* qexprs, const INdArray<int, 3>* A, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const IMVar<3>* vars, const IMPsdExpr<3>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const IMLinExpr<3>* exprs, const IMPsdExpr<3>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const INdArray<double, 3>* A, const IMPsdExpr<3>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const INdArray<int64_t, 3>* A, const IMPsdExpr<3>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<3>* Stack(const INdArray<int, 3>* A, const IMPsdExpr<3>* qexprs, int axis) const = 0;

  // Stack overloads for dimensions of 2
  virtual INdArray<double, 2>* Stack(const INdArray<double, 2>* A1, const INdArray<double, 2>* A2, int axis) const = 0;
  virtual INdArray<double, 2>* Stack(const INdArray<double, 2>* A1, const INdArray<int64_t, 2>* A2, int axis) const = 0;
  virtual INdArray<double, 2>* Stack(const INdArray<double, 2>* A1, const INdArray<int, 2>* A2, int axis) const = 0;
  virtual INdArray<int64_t, 2>* Stack(const INdArray<int64_t, 2>* A1, const INdArray<int, 2>* A2, int axis) const = 0;
  virtual INdArray<int64_t, 2>*
  Stack(const INdArray<int64_t, 2>* A1, const INdArray<int64_t, 2>* A2, int axis) const = 0;
  virtual INdArray<double, 2>* Stack(const INdArray<int64_t, 2>* A1, const INdArray<double, 2>* A2, int axis) const = 0;
  virtual INdArray<double, 2>* Stack(const INdArray<int, 2>* A1, const INdArray<double, 2>* A2, int axis) const = 0;
  virtual INdArray<int64_t, 2>* Stack(const INdArray<int, 2>* A1, const INdArray<int64_t, 2>* A2, int axis) const = 0;
  virtual INdArray<int, 2>* Stack(const INdArray<int, 2>* A1, const INdArray<int, 2>* A2, int axis) const = 0;

  virtual IMConstr<2>* Stack(const IMConstr<2>* cons1, const IMConstr<2>* cons2, int axis) const = 0;
  virtual IMQConstr<2>* Stack(const IMQConstr<2>* cons1, const IMQConstr<2>* cons2, int axis) const = 0;
  virtual IMPsdConstr<2>* Stack(const IMPsdConstr<2>* cons1, const IMPsdConstr<2>* cons2, int axis) const = 0;
  virtual IMVar<2>* Stack(const IMVar<2>* vars1, const IMVar<2>* vars2, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const IMVar<2>* vars, const IMLinExpr<2>* exprs, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const IMVar<2>* vars, const INdArray<double, 2>* A, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const IMVar<2>* vars, const INdArray<int64_t, 2>* A, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const IMVar<2>* vars, const INdArray<int, 2>* A, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const INdArray<double, 2>* A, const IMVar<2>* vars, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const INdArray<int64_t, 2>* A, const IMVar<2>* vars, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const INdArray<int, 2>* A, const IMVar<2>* vars, int axis) const = 0;

  virtual IMLinExpr<2>* Stack(const IMLinExpr<2>* exprs, const IMVar<2>* vars, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const IMLinExpr<2>* exprs1, const IMLinExpr<2>* exprs2, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const IMLinExpr<2>* exprs, const INdArray<double, 2>* A, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const IMLinExpr<2>* exprs, const INdArray<int64_t, 2>* A, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const IMLinExpr<2>* exprs, const INdArray<int, 2>* A, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const INdArray<double, 2>* A, const IMLinExpr<2>* exprs, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const INdArray<int64_t, 2>* A, const IMLinExpr<2>* exprs, int axis) const = 0;
  virtual IMLinExpr<2>* Stack(const INdArray<int, 2>* A, const IMLinExpr<2>* exprs, int axis) const = 0;

  virtual IMQuadExpr<2>* Stack(const IMQuadExpr<2>* qexprs, const IMVar<2>* vars, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const IMQuadExpr<2>* qexprs, const IMLinExpr<2>* exprs, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const IMQuadExpr<2>* qexprs1, const IMQuadExpr<2>* qexprs2, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const IMQuadExpr<2>* qexprs, const INdArray<double, 2>* A, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const IMQuadExpr<2>* qexprs, const INdArray<int64_t, 2>* A, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const IMQuadExpr<2>* qexprs, const INdArray<int, 2>* A, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const IMVar<2>* vars, const IMQuadExpr<2>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const IMLinExpr<2>* exprs, const IMQuadExpr<2>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const INdArray<double, 2>* A, const IMQuadExpr<2>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const INdArray<int64_t, 2>* A, const IMQuadExpr<2>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<2>* Stack(const INdArray<int, 2>* A, const IMQuadExpr<2>* qexprs, int axis) const = 0;

  virtual IMPsdExpr<2>* Stack(const IMPsdExpr<2>* qexprs, const IMVar<2>* vars, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const IMPsdExpr<2>* qexprs, const IMLinExpr<2>* exprs, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const IMPsdExpr<2>* qexprs1, const IMPsdExpr<2>* qexprs2, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const IMPsdExpr<2>* qexprs, const INdArray<double, 2>* A, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const IMPsdExpr<2>* qexprs, const INdArray<int64_t, 2>* A, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const IMPsdExpr<2>* qexprs, const INdArray<int, 2>* A, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const IMVar<2>* vars, const IMPsdExpr<2>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const IMLinExpr<2>* exprs, const IMPsdExpr<2>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const INdArray<double, 2>* A, const IMPsdExpr<2>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const INdArray<int64_t, 2>* A, const IMPsdExpr<2>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<2>* Stack(const INdArray<int, 2>* A, const IMPsdExpr<2>* qexprs, int axis) const = 0;

  // Stack overloads for dimensions of 1
  virtual INdArray<double, 1>* Stack(const INdArray<double, 1>* A1, const INdArray<double, 1>* A2, int axis) const = 0;
  virtual INdArray<double, 1>* Stack(const INdArray<double, 1>* A1, const INdArray<int64_t, 1>* A2, int axis) const = 0;
  virtual INdArray<double, 1>* Stack(const INdArray<double, 1>* A1, const INdArray<int, 1>* A2, int axis) const = 0;
  virtual INdArray<int64_t, 1>* Stack(const INdArray<int64_t, 1>* A1, const INdArray<int, 1>* A2, int axis) const = 0;
  virtual INdArray<int64_t, 1>*
  Stack(const INdArray<int64_t, 1>* A1, const INdArray<int64_t, 1>* A2, int axis) const = 0;
  virtual INdArray<double, 1>* Stack(const INdArray<int64_t, 1>* A1, const INdArray<double, 1>* A2, int axis) const = 0;
  virtual INdArray<double, 1>* Stack(const INdArray<int, 1>* A1, const INdArray<double, 1>* A2, int axis) const = 0;
  virtual INdArray<int64_t, 1>* Stack(const INdArray<int, 1>* A1, const INdArray<int64_t, 1>* A2, int axis) const = 0;
  virtual INdArray<int, 1>* Stack(const INdArray<int, 1>* A1, const INdArray<int, 1>* A2, int axis) const = 0;

  virtual IMConstr<1>* Stack(const IMConstr<1>* cons1, const IMConstr<1>* cons2, int axis) const = 0;
  virtual IMQConstr<1>* Stack(const IMQConstr<1>* cons1, const IMQConstr<1>* cons2, int axis) const = 0;
  virtual IMPsdConstr<1>* Stack(const IMPsdConstr<1>* cons1, const IMPsdConstr<1>* cons2, int axis) const = 0;
  virtual IMVar<1>* Stack(const IMVar<1>* vars1, const IMVar<1>* vars2, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const IMVar<1>* vars, const IMLinExpr<1>* exprs, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const IMVar<1>* vars, const INdArray<double, 1>* A, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const IMVar<1>* vars, const INdArray<int64_t, 1>* A, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const IMVar<1>* vars, const INdArray<int, 1>* A, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const INdArray<double, 1>* A, const IMVar<1>* vars, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const INdArray<int64_t, 1>* A, const IMVar<1>* vars, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const INdArray<int, 1>* A, const IMVar<1>* vars, int axis) const = 0;

  virtual IMLinExpr<1>* Stack(const IMLinExpr<1>* exprs, const IMVar<1>* vars, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const IMLinExpr<1>* exprs1, const IMLinExpr<1>* exprs2, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const IMLinExpr<1>* exprs, const INdArray<double, 1>* A, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const IMLinExpr<1>* exprs, const INdArray<int64_t, 1>* A, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const IMLinExpr<1>* exprs, const INdArray<int, 1>* A, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const INdArray<double, 1>* A, const IMLinExpr<1>* exprs, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const INdArray<int64_t, 1>* A, const IMLinExpr<1>* exprs, int axis) const = 0;
  virtual IMLinExpr<1>* Stack(const INdArray<int, 1>* A, const IMLinExpr<1>* exprs, int axis) const = 0;

  virtual IMQuadExpr<1>* Stack(const IMQuadExpr<1>* qexprs, const IMVar<1>* vars, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const IMQuadExpr<1>* qexprs, const IMLinExpr<1>* exprs, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const IMQuadExpr<1>* qexprs1, const IMQuadExpr<1>* qexprs2, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const IMQuadExpr<1>* qexprs, const INdArray<double, 1>* A, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const IMQuadExpr<1>* qexprs, const INdArray<int64_t, 1>* A, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const IMQuadExpr<1>* qexprs, const INdArray<int, 1>* A, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const IMVar<1>* vars, const IMQuadExpr<1>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const IMLinExpr<1>* exprs, const IMQuadExpr<1>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const INdArray<double, 1>* A, const IMQuadExpr<1>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const INdArray<int64_t, 1>* A, const IMQuadExpr<1>* qexprs, int axis) const = 0;
  virtual IMQuadExpr<1>* Stack(const INdArray<int, 1>* A, const IMQuadExpr<1>* qexprs, int axis) const = 0;

  virtual IMPsdExpr<1>* Stack(const IMPsdExpr<1>* qexprs, const IMVar<1>* vars, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const IMPsdExpr<1>* qexprs, const IMLinExpr<1>* exprs, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const IMPsdExpr<1>* qexprs1, const IMPsdExpr<1>* qexprs2, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const IMPsdExpr<1>* qexprs, const INdArray<double, 1>* A, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const IMPsdExpr<1>* qexprs, const INdArray<int64_t, 1>* A, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const IMPsdExpr<1>* qexprs, const INdArray<int, 1>* A, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const IMVar<1>* vars, const IMPsdExpr<1>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const IMLinExpr<1>* exprs, const IMPsdExpr<1>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const INdArray<double, 1>* A, const IMPsdExpr<1>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const INdArray<int64_t, 1>* A, const IMPsdExpr<1>* qexprs, int axis) const = 0;
  virtual IMPsdExpr<1>* Stack(const INdArray<int, 1>* A, const IMPsdExpr<1>* qexprs, int axis) const = 0;

  // Sum overloads
  virtual IMLinExpr<2>* Sum(const IMVar<3>* vars, int axis) const = 0;
  virtual IMLinExpr<1>* Sum(const IMVar<2>* vars, int axis) const = 0;
  virtual IMLinExpr<0>* Sum(const IMVar<1>* vars, int axis) const = 0;
  virtual IMLinExpr<2>* Sum(const IMLinExpr<3>* exprs, int axis) const = 0;
  virtual IMLinExpr<1>* Sum(const IMLinExpr<2>* exprs, int axis) const = 0;
  virtual IMLinExpr<0>* Sum(const IMLinExpr<1>* exprs, int axis) const = 0;
  virtual IMQuadExpr<2>* Sum(const IMQuadExpr<3>* exprs, int axis) const = 0;
  virtual IMQuadExpr<1>* Sum(const IMQuadExpr<2>* exprs, int axis) const = 0;
  virtual IMQuadExpr<0>* Sum(const IMQuadExpr<1>* exprs, int axis) const = 0;
  virtual IMPsdExpr<2>* Sum(const IMPsdExpr<3>* exprs, int axis) const = 0;
  virtual IMPsdExpr<1>* Sum(const IMPsdExpr<2>* exprs, int axis) const = 0;
  virtual IMPsdExpr<0>* Sum(const IMPsdExpr<1>* exprs, int axis) const = 0;
  virtual INdArray<double, 2>* Sum(const INdArray<double, 3>* mat, int axis) const = 0;
  virtual INdArray<double, 1>* Sum(const INdArray<double, 2>* mat, int axis) const = 0;
  virtual INdArray<double, 0>* Sum(const INdArray<double, 1>* mat, int axis) const = 0;
  virtual INdArray<int64_t, 2>* Sum(const INdArray<int64_t, 3>* mat, int axis) const = 0;
  virtual INdArray<int64_t, 1>* Sum(const INdArray<int64_t, 2>* mat, int axis) const = 0;
  virtual INdArray<int64_t, 0>* Sum(const INdArray<int64_t, 1>* mat, int axis) const = 0;
  virtual INdArray<int, 2>* Sum(const INdArray<int, 3>* mat, int axis) const = 0;
  virtual INdArray<int, 1>* Sum(const INdArray<int, 2>* mat, int axis) const = 0;
  virtual INdArray<int, 0>* Sum(const INdArray<int, 1>* mat, int axis) const = 0;
};

class IBroadCastHelper {
public:
  virtual ~IBroadCastHelper() = default;

  /* MQuadExpr: broadcasting methods of plus */
  virtual IMQuadExpr<0>* PlusCast(const IMVar<0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMVar<0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMVar<0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMVar<0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMVar<1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMVar<1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMVar<1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMVar<1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMVar<2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMVar<2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMVar<2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMVar<2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMVar<3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMVar<3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMVar<3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMVar<3>* left, const IMQuadExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* PlusCast(const IMLinExpr<0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMLinExpr<0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMLinExpr<0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMLinExpr<0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMLinExpr<1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMLinExpr<1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMLinExpr<1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMLinExpr<1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMLinExpr<2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMQuadExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* PlusCast(const IMQuadExpr<0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMQuadExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* PlusCast(const INdArray<double, 0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const INdArray<double, 0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<double, 0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<double, 0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const INdArray<double, 1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const INdArray<double, 1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<double, 1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<double, 1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<double, 2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMQuadExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* PlusCast(const INdArray<int, 0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const INdArray<int, 0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<int, 0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<int, 0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const INdArray<int, 1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const INdArray<int, 1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<int, 1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<int, 1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<int, 2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMQuadExpr<3>* right) const = 0;

  /* MQuadExpr: broadcasting methods of substract */
  virtual IMQuadExpr<0>* SubCast(const IMVar<0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMVar<0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMVar<0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMVar<0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMVar<1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMVar<1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMVar<1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMVar<1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMVar<2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMVar<2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMVar<2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMVar<2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMVar<3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMVar<3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMVar<3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMVar<3>* left, const IMQuadExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* SubCast(const IMLinExpr<0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMLinExpr<0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMLinExpr<0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMLinExpr<0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMLinExpr<1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMLinExpr<1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMLinExpr<1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMLinExpr<1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMLinExpr<2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMLinExpr<2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMLinExpr<2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMLinExpr<2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMLinExpr<3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMLinExpr<3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMLinExpr<3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMLinExpr<3>* left, const IMQuadExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* SubCast(const IMQuadExpr<0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMQuadExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* SubCast(const INdArray<double, 0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const INdArray<double, 0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<double, 0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<double, 0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const INdArray<double, 1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const INdArray<double, 1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<double, 1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<double, 1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<double, 2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<double, 2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<double, 2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<double, 2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<double, 3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<double, 3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<double, 3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<double, 3>* left, const IMQuadExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* SubCast(const INdArray<int, 0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const INdArray<int, 0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<int, 0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<int, 0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const INdArray<int, 1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const INdArray<int, 1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<int, 1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<int, 1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<int, 2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<int, 2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const INdArray<int, 2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<int, 2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<int, 3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<int, 3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<int, 3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const INdArray<int, 3>* left, const IMQuadExpr<3>* right) const = 0;

  /* MQuadExpr: broadcasting methods of dot product*/
  virtual IMQuadExpr<0>* DotCast(const INdArray<double, 0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const INdArray<double, 0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<double, 0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<double, 0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const INdArray<double, 1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const INdArray<double, 1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<double, 1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<double, 1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<double, 2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<double, 2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<double, 2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<double, 2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<double, 3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<double, 3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<double, 3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<double, 3>* left, const IMQuadExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* DotCast(const INdArray<int, 0>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const INdArray<int, 0>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<int, 0>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<int, 0>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const INdArray<int, 1>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const INdArray<int, 1>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<int, 1>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<int, 1>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<int, 2>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<int, 2>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const INdArray<int, 2>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<int, 2>* left, const IMQuadExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<int, 3>* left, const IMQuadExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<int, 3>* left, const IMQuadExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<int, 3>* left, const IMQuadExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const INdArray<int, 3>* left, const IMQuadExpr<3>* right) const = 0;

  /* MPsdExpr: broadcasting methods of plus */
  virtual IMPsdExpr<0>* PlusCast(const IMVar<0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMVar<0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMVar<0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMVar<0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMVar<1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMVar<1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMVar<1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMVar<1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMVar<2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMVar<2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMVar<2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMVar<2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMVar<3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMVar<3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMVar<3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMVar<3>* left, const IMPsdExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* PlusCast(const IMLinExpr<0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMLinExpr<0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMLinExpr<0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMLinExpr<0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMLinExpr<1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMLinExpr<1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMLinExpr<1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMLinExpr<1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMLinExpr<2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMPsdExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* PlusCast(const IMPsdExpr<0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMPsdExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* PlusCast(const INdArray<double, 0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const INdArray<double, 0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<double, 0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<double, 0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const INdArray<double, 1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const INdArray<double, 1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<double, 1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<double, 1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<double, 2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMPsdExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* PlusCast(const INdArray<int, 0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const INdArray<int, 0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<int, 0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<int, 0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const INdArray<int, 1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const INdArray<int, 1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<int, 1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<int, 1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<int, 2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMPsdExpr<3>* right) const = 0;

  /* MPsdExpr: broadcasting methods of substract */
  virtual IMPsdExpr<0>* SubCast(const IMVar<0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMVar<0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMVar<0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMVar<0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMVar<1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMVar<1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMVar<1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMVar<1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMVar<2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMVar<2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMVar<2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMVar<2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMVar<3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMVar<3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMVar<3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMVar<3>* left, const IMPsdExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* SubCast(const IMLinExpr<0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMLinExpr<0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMLinExpr<0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMLinExpr<0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMLinExpr<1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMLinExpr<1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMLinExpr<1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMLinExpr<1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMLinExpr<2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMLinExpr<2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMLinExpr<2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMLinExpr<2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMLinExpr<3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMLinExpr<3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMLinExpr<3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMLinExpr<3>* left, const IMPsdExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* SubCast(const IMPsdExpr<0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMPsdExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* SubCast(const INdArray<double, 0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const INdArray<double, 0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<double, 0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<double, 0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const INdArray<double, 1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const INdArray<double, 1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<double, 1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<double, 1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<double, 2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<double, 2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<double, 2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<double, 2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<double, 3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<double, 3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<double, 3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<double, 3>* left, const IMPsdExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* SubCast(const INdArray<int, 0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const INdArray<int, 0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<int, 0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<int, 0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const INdArray<int, 1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const INdArray<int, 1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<int, 1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<int, 1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<int, 2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<int, 2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const INdArray<int, 2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<int, 2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<int, 3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<int, 3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<int, 3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const INdArray<int, 3>* left, const IMPsdExpr<3>* right) const = 0;

  /* MPsdExpr: broadcasting methods of dot product*/
  virtual IMPsdExpr<0>* DotCast(const INdArray<double, 0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const INdArray<double, 0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<double, 0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<double, 0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const INdArray<double, 1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const INdArray<double, 1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<double, 1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<double, 1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<double, 2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<double, 2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<double, 2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<double, 2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<double, 3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<double, 3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<double, 3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<double, 3>* left, const IMPsdExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* DotCast(const INdArray<int, 0>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const INdArray<int, 0>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<int, 0>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<int, 0>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const INdArray<int, 1>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const INdArray<int, 1>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<int, 1>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<int, 1>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<int, 2>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<int, 2>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const INdArray<int, 2>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<int, 2>* left, const IMPsdExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<int, 3>* left, const IMPsdExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<int, 3>* left, const IMPsdExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<int, 3>* left, const IMPsdExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const INdArray<int, 3>* left, const IMPsdExpr<3>* right) const = 0;

  /* MLinExpr: broadcasting methods of plus */
  virtual IMLinExpr<0>* PlusCast(const IMVar<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMLinExpr<0>* PlusCast(const IMLinExpr<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* PlusCast(const IMPsdExpr<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* PlusCast(const IMQuadExpr<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMLinExpr<0>* PlusCast(const INdArray<double, 0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<double, 0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<double, 1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<double, 1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMLinExpr<0>* PlusCast(const INdArray<int, 0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<int, 0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<int, 1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<int, 1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMLinExpr<3>* right) const = 0;

  /* MLinExpr: broadcasting methods of substract */
  virtual IMLinExpr<0>* SubCast(const IMVar<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMLinExpr<0>* SubCast(const IMLinExpr<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMPsdExpr<0>* SubCast(const IMPsdExpr<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* SubCast(const IMQuadExpr<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMLinExpr<0>* SubCast(const INdArray<double, 0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<double, 0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<double, 1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<double, 1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMLinExpr<0>* SubCast(const INdArray<int, 0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<int, 0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<int, 1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<int, 1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 3>* left, const IMLinExpr<3>* right) const = 0;

  /* MLinExpr: broadcasting methods of dot product*/
  virtual IMQuadExpr<0>* DotCast(const IMVar<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMVar<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMVar<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMVar<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMQuadExpr<0>* DotCast(const IMLinExpr<0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMLinExpr<0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMLinExpr<1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMLinExpr<1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMLinExpr<0>* DotCast(const INdArray<double, 0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<double, 0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<double, 1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<double, 1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 3>* left, const IMLinExpr<3>* right) const = 0;

  virtual IMLinExpr<0>* DotCast(const INdArray<int, 0>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<int, 0>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 0>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 0>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<int, 1>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<int, 1>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 1>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 1>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 2>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 2>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 2>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 2>* left, const IMLinExpr<3>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 3>* left, const IMLinExpr<0>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 3>* left, const IMLinExpr<1>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 3>* left, const IMLinExpr<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 3>* left, const IMLinExpr<3>* right) const = 0;

  /* MVar: broadcasting methods of plus */
  virtual IMLinExpr<0>* PlusCast(const IMVar<0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const IMVar<3>* right) const = 0;

  virtual IMLinExpr<0>* PlusCast(const IMLinExpr<0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const IMVar<3>* right) const = 0;

  virtual IMPsdExpr<0>* PlusCast(const IMPsdExpr<0>* left, const IMVar<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<0>* left, const IMVar<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<0>* left, const IMVar<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<0>* left, const IMVar<3>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const IMVar<0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const IMVar<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<1>* left, const IMVar<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<1>* left, const IMVar<3>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const IMVar<0>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const IMVar<1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const IMVar<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<2>* left, const IMVar<3>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMVar<0>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMVar<1>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMVar<2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const IMVar<3>* right) const = 0;

  virtual IMQuadExpr<0>* PlusCast(const IMQuadExpr<0>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<0>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<0>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<0>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<1>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<1>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<2>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const IMVar<3>* right) const = 0;

  virtual IMLinExpr<0>* PlusCast(const INdArray<double, 0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<double, 0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<double, 1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<double, 1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<double, 2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<double, 3>* left, const IMVar<3>* right) const = 0;

  virtual IMLinExpr<0>* PlusCast(const INdArray<int, 0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<int, 0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<int, 1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const INdArray<int, 1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const INdArray<int, 2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const INdArray<int, 3>* left, const IMVar<3>* right) const = 0;

  /* MVar: broadcasting methods of substract */
  virtual IMLinExpr<0>* SubCast(const IMVar<0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const IMVar<3>* right) const = 0;

  virtual IMLinExpr<0>* SubCast(const IMLinExpr<0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const IMVar<3>* right) const = 0;

  virtual IMPsdExpr<0>* SubCast(const IMPsdExpr<0>* left, const IMVar<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<0>* left, const IMVar<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<0>* left, const IMVar<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<0>* left, const IMVar<3>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const IMVar<0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const IMVar<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<1>* left, const IMVar<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<1>* left, const IMVar<3>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const IMVar<0>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const IMVar<1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const IMVar<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<2>* left, const IMVar<3>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMVar<0>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMVar<1>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMVar<2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const IMVar<3>* right) const = 0;

  virtual IMQuadExpr<0>* SubCast(const IMQuadExpr<0>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<0>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<0>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<0>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<1>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<1>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<2>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const IMVar<3>* right) const = 0;

  virtual IMLinExpr<0>* SubCast(const INdArray<double, 0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<double, 0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<double, 1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<double, 1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<double, 2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<double, 3>* left, const IMVar<3>* right) const = 0;

  virtual IMLinExpr<0>* SubCast(const INdArray<int, 0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<int, 0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<int, 1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const INdArray<int, 1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const INdArray<int, 2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const INdArray<int, 3>* left, const IMVar<3>* right) const = 0;

  /* MVar: broadcasting methods of dot product*/
  virtual IMQuadExpr<0>* DotCast(const IMVar<0>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMVar<0>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<0>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<0>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMVar<1>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMVar<1>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<1>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<1>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<2>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<2>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMVar<2>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<2>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<3>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<3>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<3>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMVar<3>* left, const IMVar<3>* right) const = 0;

  virtual IMQuadExpr<0>* DotCast(const IMLinExpr<0>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMLinExpr<0>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<0>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<0>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMLinExpr<1>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMLinExpr<1>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<1>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<1>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<2>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<2>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMLinExpr<2>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<2>* left, const IMVar<3>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<3>* left, const IMVar<0>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<3>* left, const IMVar<1>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<3>* left, const IMVar<2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMLinExpr<3>* left, const IMVar<3>* right) const = 0;

  virtual IMLinExpr<0>* DotCast(const INdArray<double, 0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<double, 0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<double, 1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<double, 1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<double, 2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<double, 3>* left, const IMVar<3>* right) const = 0;

  virtual IMLinExpr<0>* DotCast(const INdArray<int, 0>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<int, 0>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 0>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 0>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<int, 1>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const INdArray<int, 1>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 1>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 1>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 2>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 2>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const INdArray<int, 2>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 2>* left, const IMVar<3>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 3>* left, const IMVar<0>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 3>* left, const IMVar<1>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 3>* left, const IMVar<2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const INdArray<int, 3>* left, const IMVar<3>* right) const = 0;

  /* NdArray<double>: broadcasting methods of plus */
  virtual IMLinExpr<0>* PlusCast(const IMVar<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const INdArray<double, 3>* right) const = 0;

  virtual IMLinExpr<0>* PlusCast(const IMLinExpr<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const INdArray<double, 3>* right) const = 0;

  virtual IMPsdExpr<0>* PlusCast(const IMPsdExpr<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const INdArray<double, 3>* right) const = 0;

  virtual IMQuadExpr<0>* PlusCast(const IMQuadExpr<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const INdArray<double, 3>* right) const = 0;

  /* NdArray<double>: broadcasting methods of substract */
  virtual IMLinExpr<0>* SubCast(const IMVar<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const INdArray<double, 3>* right) const = 0;

  virtual IMLinExpr<0>* SubCast(const IMLinExpr<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const INdArray<double, 3>* right) const = 0;

  virtual IMPsdExpr<0>* SubCast(const IMPsdExpr<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const INdArray<double, 3>* right) const = 0;

  virtual IMQuadExpr<0>* SubCast(const IMQuadExpr<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const INdArray<double, 3>* right) const = 0;

  /* NdArray<double>: broadcasting methods of dot product*/
  virtual IMLinExpr<0>* DotCast(const IMVar<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMVar<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMVar<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMVar<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<3>* left, const INdArray<double, 3>* right) const = 0;

  virtual IMLinExpr<0>* DotCast(const IMLinExpr<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMLinExpr<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMLinExpr<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMLinExpr<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<3>* left, const INdArray<double, 3>* right) const = 0;

  virtual IMPsdExpr<0>* DotCast(const IMPsdExpr<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const IMPsdExpr<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const IMPsdExpr<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const IMPsdExpr<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<3>* left, const INdArray<double, 3>* right) const = 0;

  virtual IMQuadExpr<0>* DotCast(const IMQuadExpr<0>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMQuadExpr<0>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<0>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<0>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMQuadExpr<1>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMQuadExpr<1>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<1>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<1>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<2>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<2>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<2>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<2>* left, const INdArray<double, 3>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<3>* left, const INdArray<double, 0>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<3>* left, const INdArray<double, 1>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<3>* left, const INdArray<double, 2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<3>* left, const INdArray<double, 3>* right) const = 0;

  /* NdArray<int>: broadcasting methods of plus */
  virtual IMLinExpr<0>* PlusCast(const IMVar<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMVar<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMVar<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMVar<3>* left, const INdArray<int, 3>* right) const = 0;

  virtual IMLinExpr<0>* PlusCast(const IMLinExpr<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* PlusCast(const IMLinExpr<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* PlusCast(const IMLinExpr<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* PlusCast(const IMLinExpr<3>* left, const INdArray<int, 3>* right) const = 0;

  virtual IMPsdExpr<0>* PlusCast(const IMPsdExpr<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<1>* PlusCast(const IMPsdExpr<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<2>* PlusCast(const IMPsdExpr<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* PlusCast(const IMPsdExpr<3>* left, const INdArray<int, 3>* right) const = 0;

  virtual IMQuadExpr<0>* PlusCast(const IMQuadExpr<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<1>* PlusCast(const IMQuadExpr<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<2>* PlusCast(const IMQuadExpr<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* PlusCast(const IMQuadExpr<3>* left, const INdArray<int, 3>* right) const = 0;

  /* NdArray<int>: broadcasting methods of substract */
  virtual IMLinExpr<0>* SubCast(const IMVar<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMVar<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMVar<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMVar<3>* left, const INdArray<int, 3>* right) const = 0;

  virtual IMLinExpr<0>* SubCast(const IMLinExpr<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* SubCast(const IMLinExpr<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* SubCast(const IMLinExpr<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* SubCast(const IMLinExpr<3>* left, const INdArray<int, 3>* right) const = 0;

  virtual IMPsdExpr<0>* SubCast(const IMPsdExpr<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<1>* SubCast(const IMPsdExpr<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<2>* SubCast(const IMPsdExpr<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* SubCast(const IMPsdExpr<3>* left, const INdArray<int, 3>* right) const = 0;

  virtual IMQuadExpr<0>* SubCast(const IMQuadExpr<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<1>* SubCast(const IMQuadExpr<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<2>* SubCast(const IMQuadExpr<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* SubCast(const IMQuadExpr<3>* left, const INdArray<int, 3>* right) const = 0;

  /* NdArray<int>: broadcasting methods of dot product*/
  virtual IMLinExpr<0>* DotCast(const IMVar<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMVar<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMVar<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMVar<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMVar<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMVar<3>* left, const INdArray<int, 3>* right) const = 0;

  virtual IMLinExpr<0>* DotCast(const IMLinExpr<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMLinExpr<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMLinExpr<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<1>* DotCast(const IMLinExpr<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<2>* DotCast(const IMLinExpr<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMLinExpr<3>* DotCast(const IMLinExpr<3>* left, const INdArray<int, 3>* right) const = 0;

  virtual IMPsdExpr<0>* DotCast(const IMPsdExpr<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const IMPsdExpr<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const IMPsdExpr<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<1>* DotCast(const IMPsdExpr<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<2>* DotCast(const IMPsdExpr<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMPsdExpr<3>* DotCast(const IMPsdExpr<3>* left, const INdArray<int, 3>* right) const = 0;

  virtual IMQuadExpr<0>* DotCast(const IMQuadExpr<0>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMQuadExpr<0>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<0>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<0>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMQuadExpr<1>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<1>* DotCast(const IMQuadExpr<1>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<1>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<1>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<2>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<2>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<2>* DotCast(const IMQuadExpr<2>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<2>* left, const INdArray<int, 3>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<3>* left, const INdArray<int, 0>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<3>* left, const INdArray<int, 1>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<3>* left, const INdArray<int, 2>* right) const = 0;
  virtual IMQuadExpr<3>* DotCast(const IMQuadExpr<3>* left, const INdArray<int, 3>* right) const = 0;

  // Rename to PlusCasting/SubCasting/DotCasting for less overloads
  /* NdArray<> + NdArray<double>: broadcasting methods of plus*/
  virtual INdArray<double, 0>* PlusCasting(const INdArray<double, 0>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<double, 0>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 0>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 0>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<double, 1>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<double, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 1>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 2>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 2>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 2>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left, const INdArray<double, 3>* right) const = 0;

  virtual INdArray<double, 0>* PlusCasting(const INdArray<int64_t, 0>* left,
    const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<int64_t, 0>* left,
    const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int64_t, 0>* left,
    const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int64_t, 0>* left,
    const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<int64_t, 1>* left,
    const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<int64_t, 1>* left,
    const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int64_t, 1>* left,
    const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int64_t, 1>* left,
    const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int64_t, 2>* left,
    const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int64_t, 2>* left,
    const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int64_t, 2>* left,
    const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int64_t, 2>* left,
    const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int64_t, 3>* left,
    const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int64_t, 3>* left,
    const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int64_t, 3>* left,
    const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int64_t, 3>* left,
    const INdArray<double, 3>* right) const = 0;

  virtual INdArray<double, 0>* PlusCasting(const INdArray<int, 0>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<int, 0>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int, 0>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int, 0>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<int, 1>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<int, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int, 1>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int, 2>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<int, 2>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int, 2>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<double, 3>* right) const = 0;

  /* NdArray<> - NdArray<double>: broadcasting methods of substract*/
  virtual INdArray<double, 0>* SubCasting(const INdArray<double, 0>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<double, 0>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 0>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 0>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<double, 1>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<double, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 1>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 2>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 2>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 2>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<double, 3>* right) const = 0;

  virtual INdArray<double, 0>* SubCasting(const INdArray<int64_t, 0>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<int64_t, 0>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int64_t, 0>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int64_t, 0>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<int64_t, 1>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<int64_t, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int64_t, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int64_t, 1>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int64_t, 2>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int64_t, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int64_t, 2>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int64_t, 2>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int64_t, 3>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int64_t, 3>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int64_t, 3>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int64_t, 3>* left, const INdArray<double, 3>* right) const = 0;

  virtual INdArray<double, 0>* SubCasting(const INdArray<int, 0>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<int, 0>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int, 0>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int, 0>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<int, 1>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<int, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int, 1>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int, 2>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<int, 2>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int, 2>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<double, 3>* right) const = 0;

  /* NdArray<> * NdArray<double>: broadcasting methods of dot product*/
  virtual INdArray<double, 0>* DotCasting(const INdArray<double, 0>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<double, 0>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 0>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 0>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<double, 1>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<double, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 1>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 2>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 2>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 2>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<double, 3>* right) const = 0;

  virtual INdArray<double, 0>* DotCasting(const INdArray<int64_t, 0>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<int64_t, 0>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int64_t, 0>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int64_t, 0>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<int64_t, 1>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<int64_t, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int64_t, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int64_t, 1>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int64_t, 2>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int64_t, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int64_t, 2>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int64_t, 2>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int64_t, 3>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int64_t, 3>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int64_t, 3>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int64_t, 3>* left, const INdArray<double, 3>* right) const = 0;

  virtual INdArray<double, 0>* DotCasting(const INdArray<int, 0>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<int, 0>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int, 0>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int, 0>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<int, 1>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<int, 1>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int, 1>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int, 1>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int, 2>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int, 2>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<int, 2>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int, 2>* left, const INdArray<double, 3>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<double, 0>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<double, 1>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<double, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<double, 3>* right) const = 0;

  /* NdArray<> + NdArray<int64_t>: broadcasting methods of plus*/
  virtual INdArray<double, 0>* PlusCasting(const INdArray<double, 0>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<double, 0>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 0>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 0>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<double, 1>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<double, 1>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 1>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 1>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 2>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 2>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 2>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 2>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left,
    const INdArray<int64_t, 3>* right) const = 0;

  virtual INdArray<int64_t, 0>* PlusCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* PlusCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 1>* PlusCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* PlusCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 3>* right) const = 0;

  virtual INdArray<int64_t, 0>* PlusCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* PlusCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 1>* PlusCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* PlusCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 3>* right) const = 0;

  /* NdArray<> - NdArray<int64_t>: broadcasting methods of substract*/
  virtual INdArray<double, 0>* SubCasting(const INdArray<double, 0>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<double, 0>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 0>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 0>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<double, 1>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<double, 1>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 1>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 1>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 2>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 2>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 2>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 2>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<int64_t, 3>* right) const = 0;

  virtual INdArray<int64_t, 0>* SubCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* SubCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 1>* SubCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* SubCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 3>* right) const = 0;

  virtual INdArray<int64_t, 0>* SubCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* SubCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 1>* SubCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* SubCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 3>* right) const = 0;

  /* NdArray<> * NdArray<int64_t>: broadcasting methods of dot product*/
  virtual INdArray<double, 0>* DotCasting(const INdArray<double, 0>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<double, 0>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 0>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 0>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<double, 1>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<double, 1>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 1>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 1>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 2>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 2>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 2>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 2>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<int64_t, 3>* right) const = 0;

  virtual INdArray<int64_t, 0>* DotCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* DotCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 0>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 1>* DotCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* DotCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 1>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 2>* left,
    const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 3>* left,
    const INdArray<int64_t, 3>* right) const = 0;

  virtual INdArray<int64_t, 0>* DotCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* DotCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int, 0>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 1>* DotCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* DotCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int, 1>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int, 2>* left, const INdArray<int64_t, 3>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 0>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 1>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<int64_t, 3>* right) const = 0;

  /* NdArray<> + NdArray<int>: broadcasting methods of plus*/
  virtual INdArray<double, 0>* PlusCasting(const INdArray<double, 0>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<double, 0>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 0>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 0>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<double, 1>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 1>* PlusCasting(const INdArray<double, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 1>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 2>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* PlusCasting(const INdArray<double, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 2>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* PlusCasting(const INdArray<double, 3>* left, const INdArray<int, 3>* right) const = 0;

  virtual INdArray<int64_t, 0>* PlusCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* PlusCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int64_t, 1>* PlusCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* PlusCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* PlusCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* PlusCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 3>* right) const = 0;

  virtual INdArray<int, 0>* PlusCasting(const INdArray<int, 0>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 1>* PlusCasting(const INdArray<int, 0>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* PlusCasting(const INdArray<int, 0>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* PlusCasting(const INdArray<int, 0>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int, 1>* PlusCasting(const INdArray<int, 1>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 1>* PlusCasting(const INdArray<int, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* PlusCasting(const INdArray<int, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* PlusCasting(const INdArray<int, 1>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int, 2>* PlusCasting(const INdArray<int, 2>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 2>* PlusCasting(const INdArray<int, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* PlusCasting(const INdArray<int, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* PlusCasting(const INdArray<int, 2>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* PlusCasting(const INdArray<int, 3>* left, const INdArray<int, 3>* right) const = 0;

  /* NdArray<> - NdArray<int>: broadcasting methods of substract*/
  virtual INdArray<double, 0>* SubCasting(const INdArray<double, 0>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<double, 0>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 0>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 0>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<double, 1>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 1>* SubCasting(const INdArray<double, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 1>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 2>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* SubCasting(const INdArray<double, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 2>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* SubCasting(const INdArray<double, 3>* left, const INdArray<int, 3>* right) const = 0;

  virtual INdArray<int64_t, 0>* SubCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* SubCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int64_t, 1>* SubCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* SubCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* SubCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* SubCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 3>* right) const = 0;

  virtual INdArray<int, 0>* SubCasting(const INdArray<int, 0>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 1>* SubCasting(const INdArray<int, 0>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* SubCasting(const INdArray<int, 0>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* SubCasting(const INdArray<int, 0>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int, 1>* SubCasting(const INdArray<int, 1>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 1>* SubCasting(const INdArray<int, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* SubCasting(const INdArray<int, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* SubCasting(const INdArray<int, 1>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int, 2>* SubCasting(const INdArray<int, 2>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 2>* SubCasting(const INdArray<int, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* SubCasting(const INdArray<int, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* SubCasting(const INdArray<int, 2>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* SubCasting(const INdArray<int, 3>* left, const INdArray<int, 3>* right) const = 0;

  /* NdArray<> * NdArray<int>: broadcasting methods of dot product*/
  virtual INdArray<double, 0>* DotCasting(const INdArray<double, 0>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<double, 0>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 0>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 0>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<double, 1>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 1>* DotCasting(const INdArray<double, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 1>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 2>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 2>* DotCasting(const INdArray<double, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 2>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<double, 3>* DotCasting(const INdArray<double, 3>* left, const INdArray<int, 3>* right) const = 0;

  virtual INdArray<int64_t, 0>* DotCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* DotCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 0>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int64_t, 1>* DotCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 1>* DotCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 1>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 2>* DotCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 2>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int64_t, 3>* DotCasting(const INdArray<int64_t, 3>* left, const INdArray<int, 3>* right) const = 0;

  virtual INdArray<int, 0>* DotCasting(const INdArray<int, 0>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 1>* DotCasting(const INdArray<int, 0>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* DotCasting(const INdArray<int, 0>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* DotCasting(const INdArray<int, 0>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int, 1>* DotCasting(const INdArray<int, 1>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 1>* DotCasting(const INdArray<int, 1>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* DotCasting(const INdArray<int, 1>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* DotCasting(const INdArray<int, 1>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int, 2>* DotCasting(const INdArray<int, 2>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 2>* DotCasting(const INdArray<int, 2>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 2>* DotCasting(const INdArray<int, 2>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* DotCasting(const INdArray<int, 2>* left, const INdArray<int, 3>* right) const = 0;
  virtual INdArray<int, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<int, 0>* right) const = 0;
  virtual INdArray<int, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<int, 1>* right) const = 0;
  virtual INdArray<int, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<int, 2>* right) const = 0;
  virtual INdArray<int, 3>* DotCasting(const INdArray<int, 3>* left, const INdArray<int, 3>* right) const = 0;
};

}  // namespace Copt
