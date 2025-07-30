#pragma once
#include "coptcpp.idl.h"

class MFactory {
public:
  static MFactory& Get()
  {
    static MFactory factory;
    return factory;
  }

  template <int N> Copt::IMVar<N>* CreateMVar(const Copt::INDim<N>* shp, const Copt::IVar* var) const
  {
    return m_factory->CreateMVar(shp, var);
  }

  template <int N> Copt::IMVar<N>* CreateMVar(const Copt::INDim<N>* shp, const Copt::IVarArray* vars) const
  {
    return m_factory->CreateMVar(shp, vars);
  }

  template <int N> Copt::IMConstr<N>* CreateMConstr(const Copt::INDim<N>* shp, const Copt::IConstraint* con) const
  {
    return m_factory->CreateMConstr(shp, con);
  }

  template <int N> Copt::IMConstr<N>* CreateMConstr(const Copt::INDim<N>* shp, const Copt::IConstrArray* cons) const
  {
    return m_factory->CreateMConstr(shp, cons);
  }

  template <int N> Copt::IMConstrBuilder<N>* CreateMConstrBuilder(const Copt::INDim<N>* shp) const
  {
    return m_factory->CreateMConstrBuilder(shp);
  }

  template <int N> Copt::IMQConstr<N>* CreateMQConstr(const Copt::INDim<N>* shp, const Copt::IQConstraint* con) const
  {
    return m_factory->CreateMQConstr(shp, con);
  }

  template <int N> Copt::IMQConstr<N>* CreateMQConstr(const Copt::INDim<N>* shp, const Copt::IQConstrArray* cons) const
  {
    return m_factory->CreateMQConstr(shp, cons);
  }

  template <int N> Copt::IMQConstrBuilder<N>* CreateMQConstrBuilder(const Copt::INDim<N>* shp) const
  {
    return m_factory->CreateMQConstrBuilder(shp);
  }

  template <int N>
  Copt::IMPsdConstr<N>* CreateMPsdConstr(const Copt::INDim<N>* shp, const Copt::IPsdConstraint* con) const
  {
    return m_factory->CreateMPsdConstr(shp, con);
  }

  template <int N>
  Copt::IMPsdConstr<N>* CreateMPsdConstr(const Copt::INDim<N>* shp, const Copt::IPsdConstrArray* cons) const
  {
    return m_factory->CreateMPsdConstr(shp, cons);
  }

  template <int N> Copt::IMPsdConstrBuilder<N>* CreateMPsdConstrBuilder(const Copt::INDim<N>* shp) const
  {
    return m_factory->CreateMPsdConstrBuilder(shp);
  }

  template <int N> Copt::IMLinExpr<N>* CreateMLinExpr(const Copt::INDim<N>* shp, const Copt::IExpr* expr) const
  {
    return m_factory->CreateMLinExpr(shp, expr);
  }

  template <int N> Copt::IMLinExpr<N>* CreateMLinExpr(const Copt::INDim<N>* shp, const Copt::IMExpression* expr) const
  {
    return m_factory->CreateMLinExpr(shp, expr);
  }

  template <int N> Copt::IMLinExpr<N>* CreateMLinExpr(const Copt::INDim<N>* shp, double constant) const
  {
    return m_factory->CreateMLinExpr(shp, constant);
  }

  template <int N> Copt::IMQuadExpr<N>* CreateMQuadExpr(const Copt::INDim<N>* shp, const Copt::IQuadExpr* expr) const
  {
    return m_factory->CreateMQuadExpr(shp, expr);
  }

  template <int N>
  Copt::IMQuadExpr<N>* CreateMQuadExpr(const Copt::INDim<N>* shp, const Copt::IMQExpression* expr) const
  {
    return m_factory->CreateMQuadExpr(shp, expr);
  }

  template <int N> Copt::IMQuadExpr<N>* CreateMQuadExpr(const Copt::INDim<N>* shp, double constant) const
  {
    return m_factory->CreateMQuadExpr(shp, constant);
  }

  template <int N> Copt::IMPsdExpr<N>* CreateMPsdExpr(const Copt::INDim<N>* shp, const Copt::IPsdExpr* expr) const
  {
    return m_factory->CreateMPsdExpr(shp, expr);
  }

  template <int N> Copt::IMPsdExpr<N>* CreateMPsdExpr(const Copt::INDim<N>* shp, const Copt::IMExpression* expr) const
  {
    return m_factory->CreateMPsdExpr(shp, expr);
  }

  template <int N> Copt::IMPsdExpr<N>* CreateMPsdExpr(const Copt::INDim<N>* shp, double constant) const
  {
    return m_factory->CreateMPsdExpr(shp, constant);
  }

  Copt::IMExpression* CreateMExpression(double constant)
  {
    return m_factory->CreateMExpression(constant);
  }

  Copt::IMExpression* CreateMExpression(const Copt::IExpr* expr)
  {
    return m_factory->CreateMExpression(expr);
  }

  Copt::IMQExpression* CreateMQExpression(double constant)
  {
    return m_factory->CreateMQExpression(constant);
  }

  Copt::IMQExpression* CreateMQExpression(const Copt::IQuadExpr* expr)
  {
    return m_factory->CreateMQExpression(expr);
  }

  template <class T, int N> Copt::INdArray<T, N>* CreateNdArray(const Copt::INDim<N>* shape, T val)
  {
    return m_factory->CreateNdArray(shape, val);
  }

  template <class T, int N> Copt::INdArray<T, N>* CreateNdArray(const Copt::INDim<N>* shape, T (*func)(size_t))
  {
    return m_factory->CreateNdArray(shape, func);
  }

  template <class T, int N> Copt::INdArray<T, N>* CreateNdArray(const Copt::INDim<N>* shape, const T* data, size_t sz)
  {
    return m_factory->CreateNdArray(shape, data, sz);
  }

  template <int N, typename... TDs> Copt::INDim<N>* CreateNDim(TDs... dims)
  {
    return m_factory->CreateNDim(dims...);
  }

  Copt::INDim<0>* CreateNDim()
  {
    return m_factory->CreateNDim();
  }

  Copt::IView* CreateView()
  {
    return m_factory->CreateView();
  }

private:
  MFactory() : m_factory(CreateMFactory()) {}
  MFactory(const MFactory&);
  MFactory& operator=(const MFactory&);

  std::shared_ptr<Copt::IMFactory> m_factory;
};
