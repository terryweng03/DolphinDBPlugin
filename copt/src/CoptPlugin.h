//
// Created by shanshucopt on 2025/7/22.
//

#ifndef COPTPLUGIN_H
#define COPTPLUGIN_H

#include <CoreConcept.h>
#include "coptcpp_pch.h"
#include "ddbplugin/CommonInterface.h"

using ddb::ConstantSP;
using ddb::Heap;
using std::vector;

extern "C" {
    ConstantSP coptModel(Heap *heap);
    ConstantSP coptModelRead(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptModelWrite(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptModelGetIntAttr(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptModelGetDblAttr(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptModelGetIntParam(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptModelGetDblParam(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptModelSetIntParam(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptModelSetDblParam(Heap *heap, vector<ConstantSP> &args);

    ConstantSP coptAddVars(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptVarsGetAttr(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptVarsSetAttr(Heap *heap, vector<ConstantSP> &args);
    
    ConstantSP coptLinExpr(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptQuadExpr(Heap *heap, vector<ConstantSP> &args);

    ConstantSP coptAddConstr(Heap *heap, vector<ConstantSP> &args);

    ConstantSP coptSetLogFile(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptSetObjective(Heap *heap, vector<ConstantSP> &args);
    
    ConstantSP coptSolve(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptGetResult(Heap *heap, vector<ConstantSP> &args);
    ConstantSP coptGetObjValue(Heap *heap, vector<ConstantSP> &args);
}

#endif //COPTPLUGIN_H
