#pragma once
#include "coptcpp.idl.h"
#include "envrconfig.h"
#include "model.h"

class Envr {
public:
  Envr() : m_env(CreateEnvr(nullptr))
  {
    CHECKERROR(m_env);
  }
  Envr(const char* szLicDir) : m_env(CreateEnvrWithPath(szLicDir, nullptr))
  {
    CHECKERROR(m_env);
  }
  Envr(const EnvrConfig& config) : m_env(CreateEnvrWithConfig(config.Get(), nullptr))
  {
    CHECKERROR(m_env);
  }
  Envr(Copt::IEnvr* env) : m_env(env) {}

  Model CreateModel(const char* szName)
  {
    Model model = m_env->CreateModel(szName);
    CHECKERROR(m_env);
    return model;
  }

  void Close()
  {
    m_env->Close();
  }

private:
  std::shared_ptr<Copt::IEnvr> m_env;
};
