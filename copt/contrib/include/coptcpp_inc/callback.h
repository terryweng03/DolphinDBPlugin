#pragma once
class ICallbackProxy;

class ICallback {
public:
  virtual ~ICallback() {}

  virtual void callback() = 0;

  virtual Copt::ICallbackProxy* getProxy() const = 0;
};