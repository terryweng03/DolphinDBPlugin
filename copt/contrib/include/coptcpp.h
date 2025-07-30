#ifdef _WIN32
#define COPT_CALL __stdcall
#else
#define COPT_CALL
#endif

#define COPTCPP_API extern "C"

#include "logcallback.h"
#include "coptcpp.idl.h"

COPTCPP_API
Copt::IVarArray* COPT_CALL CreateVarArray();

COPTCPP_API
Copt::IConstrArray* COPT_CALL CreateConstrArray();

COPTCPP_API
Copt::IColumn* COPT_CALL CreateColumn();

COPTCPP_API
Copt::IColumnArray* COPT_CALL CreateColumnArray();

COPTCPP_API
Copt::IExpr* COPT_CALL CreateExpr(double constant);

COPTCPP_API
Copt::IExpr* COPT_CALL CreateLinExpr(Copt::IVar* var, double coeff);

COPTCPP_API
Copt::IQuadExpr* COPT_CALL CreateQuadExpr1(double constant);

COPTCPP_API
Copt::IQuadExpr* COPT_CALL CreateQuadExpr2(Copt::IVar* var, double coeff);

COPTCPP_API
Copt::IQuadExpr* COPT_CALL CreateQuadExpr3(Copt::IExpr* expr);

COPTCPP_API
Copt::IQuadExpr* COPT_CALL CreateQuadExpr4(Copt::IExpr* expr, Copt::IVar* var);

COPTCPP_API
Copt::IQuadExpr* COPT_CALL CreateQuadExpr5(Copt::IExpr* left, Copt::IExpr* right);

COPTCPP_API
Copt::IPsdExpr* COPT_CALL CreatePsdExpr1(double constant);

COPTCPP_API
Copt::IPsdExpr* COPT_CALL CreatePsdExpr2(Copt::IVar* var, double coeff);

COPTCPP_API
Copt::IPsdExpr* COPT_CALL CreatePsdExpr3(Copt::IExpr* expr);

COPTCPP_API
Copt::IPsdExpr* COPT_CALL CreatePsdExpr4(Copt::IPsdVar* var, Copt::ISymMatrix* mat);

COPTCPP_API
Copt::IPsdExpr* COPT_CALL CreatePsdExpr5(Copt::IPsdVar* var, Copt::ISymMatExpr* expr);

COPTCPP_API
Copt::IPsdExpr* COPT_CALL CreatePsdExpr6(Copt::IMExpression* expr);

COPTCPP_API
Copt::ILmiExpr* COPT_CALL CreateLmiExpr1();

COPTCPP_API
Copt::ILmiExpr* COPT_CALL CreateLmiExpr2(Copt::ISymMatrix* mat);

COPTCPP_API
Copt::ILmiExpr* COPT_CALL CreateLmiExpr3(Copt::ISymMatExpr* expr);

COPTCPP_API
Copt::ILmiExpr* COPT_CALL CreateLmiExpr4(Copt::IVar* var, Copt::ISymMatrix* mat);

COPTCPP_API
Copt::ILmiExpr* COPT_CALL CreateLmiExpr5(Copt::IVar* var, Copt::ISymMatExpr* expr);

COPTCPP_API
Copt::INlExpr* COPT_CALL CreateNlExpr1(double constant);

COPTCPP_API
Copt::INlExpr* COPT_CALL CreateNlExpr2(Copt::IVar* var, double coeff);

COPTCPP_API
Copt::INlExpr* COPT_CALL CreateNlExpr3(Copt::IExpr* expr);

COPTCPP_API
Copt::INlExpr* COPT_CALL CreateNlExpr4(Copt::IQuadExpr* expr);

COPTCPP_API
Copt::IConstrBuilder* COPT_CALL CreateConstrBuilder();

COPTCPP_API
Copt::IConstrBuilderArray* COPT_CALL CreateConstrBuilderArray();

COPTCPP_API
Copt::INlConstrArray* COPT_CALL CreateNlConstrArray();

COPTCPP_API
Copt::INlConstrBuilder* COPT_CALL CreateNlConstrBuilder();

COPTCPP_API
Copt::INlConstrBuilderArray* COPT_CALL CreateNlConstrBuilderArray();

COPTCPP_API
Copt::ISosArray* COPT_CALL CreateSosArray();

COPTCPP_API
Copt::ISosBuilder* COPT_CALL CreateSosBuilder();

COPTCPP_API
Copt::ISosBuilderArray* COPT_CALL CreateSosBuilderArray();

COPTCPP_API
Copt::IGenConstrArray* COPT_CALL CreateGenConstrArray();

COPTCPP_API
Copt::IGenConstrBuilder* COPT_CALL CreateGenConstrBuilder();

COPTCPP_API
Copt::IGenConstrBuilderArray* COPT_CALL CreateGenConstrBuilderArray();

COPTCPP_API
Copt::IConeArray* COPT_CALL CreateConeArray();

COPTCPP_API
Copt::IConeBuilder* COPT_CALL CreateConeBuilder();

COPTCPP_API
Copt::IConeBuilderArray* COPT_CALL CreateConeBuilderArray();

COPTCPP_API
Copt::IExpConeArray* COPT_CALL CreateExpConeArray();

COPTCPP_API
Copt::IExpConeBuilder* COPT_CALL CreateExpConeBuilder();

COPTCPP_API
Copt::IExpConeBuilderArray* COPT_CALL CreateExpConeBuilderArray();

COPTCPP_API
Copt::IAffineConeArray* COPT_CALL CreateAffineConeArray();

COPTCPP_API
Copt::IAffineConeBuilder* COPT_CALL CreateAffineConeBuilder();

COPTCPP_API
Copt::IAffineConeBuilderArray* COPT_CALL CreateAffineConeBuilderArray();

COPTCPP_API
Copt::IQConstrArray* COPT_CALL CreateQConstrArray();

COPTCPP_API
Copt::IQConstrBuilder* COPT_CALL CreateQConstrBuilder();

COPTCPP_API
Copt::IQConstrBuilderArray* COPT_CALL CreateQConstrBuilderArray();

COPTCPP_API
Copt::IPsdVarArray* COPT_CALL CreatePsdVarArray();

COPTCPP_API
Copt::IPsdConstrArray* COPT_CALL CreatePsdConstrArray();

COPTCPP_API
Copt::IPsdConstrBuilder* COPT_CALL CreatePsdConstrBuilder();

COPTCPP_API
Copt::IPsdConstrBuilderArray* COPT_CALL CreatePsdConstrBuilderArray();

COPTCPP_API
Copt::ILmiConstrArray* COPT_CALL CreateLmiConstrArray();

COPTCPP_API
Copt::ISymMatrixArray* COPT_CALL CreateSymMatrixArray();

COPTCPP_API
Copt::ISymMatExpr* COPT_CALL CreateSymMatExpr1();

COPTCPP_API
Copt::ISymMatExpr* COPT_CALL CreateSymMatExpr2(Copt::ISymMatrix* mat, double coeff);

COPTCPP_API
Copt::IModel* COPT_CALL CreateModel(Copt::IEnvr* env, const char* szName);

COPTCPP_API
Copt::IEnvr* COPT_CALL CreateEnvr(ILogCallback* pcb);

COPTCPP_API
Copt::IEnvr* COPT_CALL CreateEnvrWithPath(const char* szLicDir, ILogCallback* pcb);

COPTCPP_API
Copt::IEnvr* COPT_CALL CreateEnvrWithConfig(Copt::IEnvrConfig* config, ILogCallback* pcb);

COPTCPP_API
Copt::IEnvrConfig* COPT_CALL CreateEnvrConfig();

COPTCPP_API
Copt::IProbBuffer* COPT_CALL CreateProbBuffer(int sz);

COPTCPP_API
Copt::ICallbackProxy* COPT_CALL CreateCallbackProxy();

/* export functions to create mobj and ndarray */
COPTCPP_API
Copt::IMFactory* COPT_CALL CreateMFactory();

COPTCPP_API
Copt::IMHelper* COPT_CALL CreateMHelper();

COPTCPP_API
Copt::INlHelper* COPT_CALL CreateNlHelper();

COPTCPP_API
Copt::IBroadCastHelper* COPT_CALL CreateBroadCastHelper();

/* export functions to create int ndarray with dimension number (1-3) */
COPTCPP_API
Copt::INdArray<int, 1>* COPT_CALL CreateNdArrayInt1WithData(int* data, int N);

COPTCPP_API
Copt::INdArray<int, 2>* COPT_CALL CreateNdArrayInt2WithData(int* data, int N, int M);

COPTCPP_API
Copt::INdArray<int, 3>* COPT_CALL CreateNdArrayInt3WithData(int* data, int N, int M, int K);

COPTCPP_API
Copt::INdArray<int, 1>* COPT_CALL CreateNdArrayInt1WithExData(int* data, int N);

COPTCPP_API
Copt::INdArray<int, 2>* COPT_CALL CreateNdArrayInt2WithExData(int* data, int N, int M);

COPTCPP_API
Copt::INdArray<int, 3>* COPT_CALL CreateNdArrayInt3WithExData(int* data, int N, int M, int K);

/* export functions to create double ndarray with dimension number (1-3) */
COPTCPP_API
Copt::INdArray<double, 1>* COPT_CALL CreateNdArrayDbl1WithData(double* data, int N);

COPTCPP_API
Copt::INdArray<double, 2>* COPT_CALL CreateNdArrayDbl2WithData(double* data, int N, int M);

COPTCPP_API
Copt::INdArray<double, 3>* COPT_CALL CreateNdArrayDbl3WithData(double* data, int N, int M, int K);

COPTCPP_API
Copt::INdArray<double, 1>* COPT_CALL CreateNdArrayDbl1WithExData(double* data, int N);

COPTCPP_API
Copt::INdArray<double, 2>* COPT_CALL CreateNdArrayDbl2WithExData(double* data, int N, int M);

COPTCPP_API
Copt::INdArray<double, 3>* COPT_CALL CreateNdArrayDbl3WithExData(double* data, int N, int M, int K);

/* export functions to create int64 ndarray with dimension number (1-3) */
COPTCPP_API
Copt::INdArray<int64_t, 1>* COPT_CALL CreateNdArrayInt64t1WithData(int64_t* data, int N);

COPTCPP_API
Copt::INdArray<int64_t, 2>* COPT_CALL CreateNdArrayInt64t2WithData(int64_t* data, int N, int M);

COPTCPP_API
Copt::INdArray<int64_t, 3>* COPT_CALL CreateNdArrayInt64t3WithData(int64_t* data, int N, int M, int K);

COPTCPP_API
Copt::INdArray<int64_t, 1>* COPT_CALL CreateNdArrayInt64t1WithExData(int64_t* data, int N);

COPTCPP_API
Copt::INdArray<int64_t, 2>* COPT_CALL CreateNdArrayInt64t2WithExData(int64_t* data, int N, int M);

COPTCPP_API
Copt::INdArray<int64_t, 3>* COPT_CALL CreateNdArrayInt64t3WithExData(int64_t* data, int N, int M, int K);

COPTCPP_API
Copt::IMLinExpr<1>* COPT_CALL MVar1MatMultCsc(const Copt::IMVar<1>* vars,
  int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMLinExpr<1>* COPT_CALL CscMatMultMVar1(int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMVar<1>* vars);

COPTCPP_API
Copt::IMLinExpr<2>* COPT_CALL MVar2MatMultCsc(const Copt::IMVar<2>* vars,
  int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMLinExpr<2>* COPT_CALL CscMatMultMVar2(int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMVar<2>* vars);

COPTCPP_API
Copt::IMLinExpr<1>* COPT_CALL MVar1MatMultCsr(const Copt::IMVar<1>* vars,
  int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMLinExpr<1>* COPT_CALL CsrMatMultMVar1(int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMVar<1>* vars);

COPTCPP_API
Copt::IMLinExpr<2>* COPT_CALL MVar2MatMultCsr(const Copt::IMVar<2>* vars,
  int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMLinExpr<2>* COPT_CALL CsrMatMultMVar2(int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMVar<2>* vars);


COPTCPP_API
Copt::IMLinExpr<1>* COPT_CALL MLinExpr1MatMultCsc(const Copt::IMLinExpr<1>* exprs,
  int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMLinExpr<1>* COPT_CALL CscMatMultMLinExpr1(int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMLinExpr<1>* exprs);

COPTCPP_API
Copt::IMLinExpr<2>* COPT_CALL MLinExpr2MatMultCsc(const Copt::IMLinExpr<2>* exprs,
  int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMLinExpr<2>* COPT_CALL CscMatMultMLinExpr2(int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMLinExpr<2>* exprs);

COPTCPP_API
Copt::IMLinExpr<1>* COPT_CALL MLinExpr1MatMultCsr(const Copt::IMLinExpr<1>* exprs,
  int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMLinExpr<1>* COPT_CALL CsrMatMultMLinExpr1(int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMLinExpr<1>* exprs);

COPTCPP_API
Copt::IMLinExpr<2>* COPT_CALL MLinExpr2MatMultCsr(const Copt::IMLinExpr<2>* exprs,
  int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMLinExpr<2>* COPT_CALL CsrMatMultMLinExpr2(int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMLinExpr<2>* exprs);


COPTCPP_API
Copt::IMQuadExpr<1>* COPT_CALL MQuadExpr1MatMultCsc(const Copt::IMQuadExpr<1>* exprs,
  int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMQuadExpr<1>* COPT_CALL CscMatMultMQuadExpr1(int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMQuadExpr<1>* exprs);

COPTCPP_API
Copt::IMQuadExpr<2>* COPT_CALL MQuadExpr2MatMultCsc(const Copt::IMQuadExpr<2>* exprs,
  int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMQuadExpr<2>* COPT_CALL CscMatMultMQuadExpr2(int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMQuadExpr<2>* exprs);

COPTCPP_API
Copt::IMQuadExpr<1>* COPT_CALL MQuadExpr1MatMultCsr(const Copt::IMQuadExpr<1>* exprs,
  int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMQuadExpr<1>* COPT_CALL CsrMatMultMQuadExpr1(int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMQuadExpr<1>* exprs);

COPTCPP_API
Copt::IMQuadExpr<2>* COPT_CALL MQuadExpr2MatMultCsr(const Copt::IMQuadExpr<2>* exprs,
  int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz);

COPTCPP_API
Copt::IMQuadExpr<2>* COPT_CALL CsrMatMultMQuadExpr2(int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMQuadExpr<2>* exprs);

COPTCPP_API
Copt::IMQuadExpr<0>* COPT_CALL MVar1MatMultCscMVar1(const Copt::IMVar<1>* mxl,
  int nrow,
  int* indptr,
  int ncolone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMVar<1>* mxr);

COPTCPP_API
Copt::IMQuadExpr<0>* COPT_CALL MVar1MatMultCsrMVar1(const Copt::IMVar<1>* mxl,
  int ncol,
  int* indptr,
  int nrowone,
  int* indices,
  int cnz,
  double* data,
  int nnz,
  const Copt::IMVar<1>* mxr);

COPTCPP_API
int COPT_CALL GetCoptVersion(int type);
