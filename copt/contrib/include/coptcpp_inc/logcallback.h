#pragma once

class ILogCallback {
public:
  virtual ~ILogCallback() {}
  virtual void Display(const char* msg) = 0;
};