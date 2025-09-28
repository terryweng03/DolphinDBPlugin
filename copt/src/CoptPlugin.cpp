//
// Created by shanshucopt on 2025/7/22.
//

#include "CoptPlugin.h"

#include <ScalarImp.h>

#include "ddbplugin/Plugin.h"

using ddb::DF_DICTIONARY;
using ddb::DF_MATRIX;
using ddb::DF_SCALAR;
using ddb::DF_VECTOR;
using ddb::DictionarySP;
using ddb::Double;
using ddb::DT_ANY;
using ddb::DT_CHAR;
using ddb::DT_DOUBLE;
using ddb::DT_INT;
using ddb::DT_STRING;
using ddb::FunctionDefSP;
using ddb::IllegalArgumentException;
using ddb::Int;
using ddb::RuntimeException;
using ddb::SmartPointer;
using ddb::Util;
using ddb::VectorSP;
using ddb::Void;
using ddb::String;

using namespace std;

// descriptions
const string COPT_PREFIX = "[Plugin::Copt]";
const string COPT_MODEL_DESC = "copt model";
const string COPT_LINEAR_EXPRESSION_DESC = "copt linear expression";
const string COPT_QUAD_EXPRESSION_DESC = "copt quadratic expression";

// maps
ddb::ResourceMap<Model> COPT_MODEL_AMP(COPT_PREFIX, COPT_MODEL_DESC);
ddb::ResourceMap<Expr> COPT_LINEAR_EXPRESSION_AMP(COPT_PREFIX, COPT_LINEAR_EXPRESSION_DESC);
ddb::ResourceMap<QuadExpr> COPT_QUAD_EXPRESSION_AMP(COPT_PREFIX, COPT_QUAD_EXPRESSION_DESC);

// close functions
void modelOnClose(Heap *heap, vector<ConstantSP> &args) {
	std::ignore = heap;
    COPT_MODEL_AMP.safeRemoveWithoutException(args[0]);
}
void linearExpressionOnClose(Heap *heap, vector<ConstantSP> &args) {
	std::ignore = heap;
    COPT_LINEAR_EXPRESSION_AMP.safeRemoveWithoutException(args[0]);
}
void quadExpressionOnClose(Heap *heap, vector<ConstantSP> &args) {
	std::ignore = heap;
    COPT_QUAD_EXPRESSION_AMP.safeRemoveWithoutException(args[0]);
}


/// Helper Declarations
VectorSP getNumVector(const ConstantSP &arg, const string &funcName, const string &usage,
                      const string &argName, int size = 0);
VectorSP getCharVector(const ConstantSP &arg, const string &funcName, const string &usage,
                       const string &argName, int size = 0);
VectorSP getStringVector(const ConstantSP &arg, const string &funcName, const string &usage,
                         const string &argName, int size = 0);
VectorSP getQuadMatrix(const ConstantSP &arg, const string &funcName, const string &usage,
                       const string &argName, int size = 0);
int getIntScalar(const ConstantSP &arg, const string &funcName, const string &usage, const string &argName);
char getCharScalar(const ConstantSP &arg, const string &funcName, const string &usage, const string &argName);
double getDoubleScalar(const ConstantSP &arg, const string &funcName, const string &usage, const string &argName);
string getStringScalar(const ConstantSP &arg, const string &funcName, const string &usage, const string &argName);


ConstantSP coptModel(Heap *heap) {
    string usage = COPT_PREFIX + " model(): ";

    // create COPT model
    SmartPointer<Model> model;
    try {
        Envr env;
        Model coptModel = env.CreateModel("COPT model");
        model = new Model(coptModel);
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what()   );
    }
    FunctionDefSP onClose(Util::createSystemProcedure("modelOnClose", modelOnClose, 1, 1));
    ConstantSP resource = Util::createResource(reinterpret_cast<long long>(model.get()), COPT_MODEL_DESC, onClose,
                                               heap->currentSession());
    COPT_MODEL_AMP.safeAdd(resource, model);
    return resource;
}

ConstantSP coptModelRead(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " modelRead(model, filePath): ";
    
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    string filePath = getStringScalar(args[1], __FUNCTION__, usage, "filePath");

    // read input file
    try {
       model->Read(filePath.c_str());
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Void();
}

ConstantSP coptModelWrite(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " modelWrite(model, filePath): ";
    
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    string filePath = getStringScalar(args[1], __FUNCTION__, usage, "filePath");

    // write into given file
    try {
       model->Write(filePath.c_str());
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Void();
}

ConstantSP coptModelGetIntAttr(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " modelGetIntAttr(model, intAttrName): ";
    
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    string intAttrName = getStringScalar(args[1], __FUNCTION__, usage, "intAttrName");

    // get value of integer attribute
    int attrValue;
    try {
       attrValue = model->GetIntAttr(intAttrName.c_str());
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Int(attrValue);
}

ConstantSP coptModelGetDblAttr(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " modelGetIntAttr(model, dblAttrName): ";
    
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    string dblAttrName = getStringScalar(args[1], __FUNCTION__, usage, "dblAttrName");

    // get value of double attribute
    double attrValue;
    try {
       attrValue = model->GetDblAttr(dblAttrName.c_str());
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Double(attrValue);
}

ConstantSP coptModelGetIntParam(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " modelGetIntParam(model, intParamName): ";
    
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    string intParamName = getStringScalar(args[1], __FUNCTION__, usage, "intParamName");

    // get value of integer parameter
    int paramValue;
    try {
        paramValue = model->GetIntParam(intParamName.c_str());
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Int(paramValue);
}

ConstantSP coptModelGetDblParam(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " modelGetDblParam(model, dblParamName): ";
    
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    string dblParamName = getStringScalar(args[1], __FUNCTION__, usage, "dblParamName");

    // get value of double parameter
    double paramValue;
    try {
       paramValue = model->GetDblParam(dblParamName.c_str());
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Double(paramValue);
}

ConstantSP coptModelSetIntParam(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " modelSetIntParam(model, intParamName, intParamValue): ";
    
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    string intParamName = getStringScalar(args[1], __FUNCTION__, usage, "intParamName");
    int intParamValue = getIntScalar(args[2], __FUNCTION__, usage, "intParamValue");

    // set value of integer parameter
    try {
       model->SetIntParam(intParamName.c_str(), intParamValue);
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Void();
}

ConstantSP coptModelSetDblParam(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " modelSetDblParam(model, dblParamName, dblParamValue): ";
    
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    string dblParamName = getStringScalar(args[1], __FUNCTION__, usage, "dblParamName");
    double dblParamValue = getDoubleScalar(args[2], __FUNCTION__, usage, "dblParamValue");

    // set value of double parameter
    try {
        model->SetDblParam(dblParamName.c_str(), dblParamValue);
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Void();
}

ConstantSP coptAddVars(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " addVars(model, numVars, lb, ub, obj, type, varNamePrefix): ";

    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    auto numVars = getIntScalar(args[1], __FUNCTION__, usage, "numVars");
    VectorSP lb;
    if (!args[2]->isNull()) {
        lb = getNumVector(args[2], __FUNCTION__, usage, "lb", numVars);
    }
    VectorSP ub;
    if (!args[3]->isNull()) {
        ub = getNumVector(args[3], __FUNCTION__, usage, "ub", numVars);
    }
    VectorSP obj;
    if (!args[4]->isNull()) {
        obj = getNumVector(args[4], __FUNCTION__, usage, "obj", numVars);
    }
    VectorSP type;
    if (!args[5]->isNull()) {
        type = getCharVector(args[5], __FUNCTION__, usage, "type", numVars);
    }
    auto hasVarNamePrefix = false;
    if (args.size() == 7 and !args[6]->isNull()) {
        hasVarNamePrefix = true;
    } 
    string varNamePrefix;
    if (hasVarNamePrefix) {
        varNamePrefix = getStringScalar(args[6], __FUNCTION__, usage, "varNamePrefix");
    }

    /// ddb vec to std vec
    vector<double> lbVec;
    vector<double> ubVec;
    vector<double> objVec;
    vector<char> typeVec;
    if (!lb.isNull()) {
        lbVec.reserve(numVars);
        for (auto i = 0; i < numVars; ++i) {
            lbVec.emplace_back(lb->getDouble(i));
        }
    }
    if (!ub.isNull()) {
        ubVec.reserve(numVars);
        for (auto i = 0; i < numVars; ++i) {
            ubVec.emplace_back(ub->getDouble(i));
        }
    }
    if (!obj.isNull()) {
        objVec.reserve(numVars);
        for (auto i = 0; i < numVars; ++i) {
            objVec.emplace_back(obj->getDouble(i));
        }
    }
    if (!type.isNull()) {
        typeVec.reserve(numVars);
        for (auto i = 0; i < numVars; ++i) {
            typeVec.emplace_back(type->getChar(i));
        }
    }

    // add vars
    VarArray vars;  
    try {
        if (hasVarNamePrefix) { 
            vars = model->AddVars(numVars, lbVec.data(), ubVec.data(), objVec.data(), typeVec.data(), varNamePrefix.c_str());
        } else {
            vars = model->AddVars(numVars, lbVec.data(), ubVec.data(), objVec.data(), typeVec.data());
        }
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    }

    // get the names of new vars
    VectorSP varNames = Util::createVector(DT_STRING, 0); 
    for (auto i = 0; i < vars.Size(); ++i) {
            Var var = vars.GetVar(i);
            varNames->append(new String(var.GetName())); 
        }

    return varNames;
}

ConstantSP coptVarsGetAttr(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " varsGetAttr(model, varNames, attrName): ";

    auto model = COPT_MODEL_AMP.safeGet(args[0]);

    bool singleVar = true;
    if (args[1]->getForm() == DF_VECTOR)
        singleVar = false;

    auto varAttrName = getStringScalar(args[2], __FUNCTION__, usage, "varAttrName");

    // get attribute values of given vars
    if (singleVar) {
        auto varName = getStringScalar(args[1], __FUNCTION__, usage, "varName");
        double attrValue;
        try {
            auto var = model->GetVarByName(varName.c_str());
            attrValue = var.Get(varAttrName.c_str());
            return new Double(attrValue);
        } catch (CoptException &e) {
            throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
        }
    } else {
        auto varNames = getStringVector(args[1], __FUNCTION__, usage, "varNames", args[1]->size());
        VectorSP attrValue = Util::createVector(DT_DOUBLE, 0);
        try {
           for (auto i = 0; i < varNames->size(); ++i) {
                auto var = model->GetVarByName(varNames->getString(i).c_str());
                attrValue->append(new Double(var.Get(varAttrName.c_str())));
            }
            return attrValue;
        } catch (CoptException &e) {
            throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
        }
    }
}

ConstantSP coptVarsSetAttr(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " varsSetAttr(model, varNames, attrName, attrValues): ";

    auto model = COPT_MODEL_AMP.safeGet(args[0]);

    VectorSP varNames;
    if (args[1]->getForm() == DF_VECTOR) {
        varNames = getStringVector(args[1], __FUNCTION__, usage, "varNames",  args[1]->size());
    } else {
        auto varName = getStringScalar(args[1], __FUNCTION__, usage, "varName");
        varNames = Util::createVector(DT_STRING, 0);
        varNames->append(new String(varName));
    }

    auto attrName = getStringScalar(args[2], __FUNCTION__, usage, "attrName");

    VectorSP attrValues;
    if (args[3]->getForm() == DF_VECTOR) {
        attrValues = getNumVector(args[3], __FUNCTION__, usage, "attrValues",  args[3]->size());
    } else {
        auto attrValue = getDoubleScalar(args[3], __FUNCTION__, usage, "attrValue");
        attrValues = Util::createVector(DT_DOUBLE, 0);
        attrValues->append(new Double(attrValue));
    }

    if (varNames->size() != attrValues->size())
        throw IllegalArgumentException(__FUNCTION__, usage + "size of varNames should equals to should the size of attrValues.");

    // set attribute values of given vars
    try {
        for (auto i = 0; i < varNames->size(); ++i) {
            auto var = model->GetVarByName(varNames->getString(i).c_str());
            var.Set(attrName.c_str(), attrValues->getDouble(i));
        }
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Void();
}

ConstantSP coptLinExpr(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " linExpr(model, coefficient, varNames, constant): ";

    auto numVars = args[1]->size();
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    auto coefficient = getNumVector(args[1], __FUNCTION__, usage, "coefficient", numVars);
    auto varNames = getStringVector(args[2], __FUNCTION__, usage, "varNames", numVars);
    double constantTerm;
    if (args.size() == 4 and !args[3]->isNull()) {
        constantTerm = getDoubleScalar(args[3], __FUNCTION__, usage, "constant");
    } else {
        constantTerm = 0;
    }

    /// create linear expression
    Expr expr;
    try {
        auto size = varNames->size();
        for (auto i = 0; i < size; ++i) {
            auto c = coefficient->getDouble(i);
            auto var = model->GetVarByName(varNames->getString(i).c_str());
            if (c != 0) {
                expr += c * var;
            }
        }
        expr += constantTerm;
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    }

    SmartPointer<Expr> linearExpr = new Expr(expr);
    FunctionDefSP onClose(Util::createSystemProcedure("linExpressionOnClose", linearExpressionOnClose, 1, 1));
    ConstantSP resource = Util::createResource(reinterpret_cast<long long>(linearExpr.get()), COPT_LINEAR_EXPRESSION_DESC,
                                               onClose, heap->currentSession());
    COPT_LINEAR_EXPRESSION_AMP.safeAdd(resource, linearExpr);

    return resource;
}

ConstantSP coptQuadExpr(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " quadExpr(model, quadMatrix, varNames, [linExpr], constant): ";

    auto numVars = args[2]->size();
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    auto quadMatrix = getQuadMatrix(args[1], __FUNCTION__, usage, "quadMatrix", numVars);
    auto varNames = getStringVector(args[2], __FUNCTION__, usage, "varNames", numVars);
    SmartPointer<Expr> linExpr;
    if ((args.size() == 4 or args.size() == 5) and !args[3]->isNull()) {
        linExpr = COPT_LINEAR_EXPRESSION_AMP.safeGet(args[3]);
    }
    double constantTerm;
    if (args.size() == 5 and !args[4]->isNull() ) {
        constantTerm = getDoubleScalar(args[4], __FUNCTION__, usage, "constant");
    } else {
        constantTerm = 0;
    }

    /// create quadratic expression
    // TODO: the constant of quadratic expression should set to be the constant of the linear expression as default?
    QuadExpr expr;
    try {
        if (linExpr.isNull()) {
            expr = QuadExpr(constantTerm);
        } else {
            linExpr->SetConstant(constantTerm);
            expr = QuadExpr(*linExpr);
        }
        auto size = varNames->size();
        for (auto i = 0; i < size; ++i) {
            VectorSP col = quadMatrix->getColumn(i);
            auto iVar = model->GetVarByName(varNames->getString(i).c_str());
            for (auto j = 0; j < size; j++) {
                auto coefficient = col->getDouble(j);
                if (coefficient != 0) {
                    auto jVar = model->GetVarByName(varNames->getString(j).c_str());
                    expr += coefficient * iVar * jVar;
                }
            }
        }
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    }

    SmartPointer<QuadExpr> quadExpr = new QuadExpr(expr);
    FunctionDefSP onClose(Util::createSystemProcedure("quadExpressionOnClose", quadExpressionOnClose, 1, 1));
    ConstantSP resource = Util::createResource(reinterpret_cast<long long>(quadExpr.get()), COPT_QUAD_EXPRESSION_DESC,
                                               onClose, heap->currentSession());
    COPT_QUAD_EXPRESSION_AMP.safeAdd(resource, quadExpr);

    return resource;
}

ConstantSP coptAddConstr(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " addConstr(model, lhsExpr, sense, rhsVal, constrName): ";

    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    auto expr = args[1];
    bool isQuad = false;
    if (expr->getString() == COPT_QUAD_EXPRESSION_DESC) {
        isQuad = true;
    }
    auto sense = getCharScalar(args[2], __FUNCTION__, usage, "sense");
    if (sense == '<') {
        sense = 'L';
    } 
    if (sense == '>') {
        sense = 'G';
    } 
    if (sense == '=') {
        sense = 'E';
    }
    auto rhsVal = getDoubleScalar(args[3], __FUNCTION__, usage, "rhsVal");
    auto hasConstrName = false;
    if (args.size() == 5 and !args[4]->isNull()) {
        hasConstrName = true;
    } 
    string constrName;
    if (hasConstrName) {
        constrName = getStringScalar(args[4], __FUNCTION__, usage, "constrName");
    }

    /// add constraint
    try {
        if (isQuad) {
            if (hasConstrName) {
                model->AddQConstr(*COPT_QUAD_EXPRESSION_AMP.safeGet(expr), sense, rhsVal, constrName.c_str());
            } else {
                model->AddQConstr(*COPT_QUAD_EXPRESSION_AMP.safeGet(expr), sense, rhsVal);
            }
        } else {
            if (hasConstrName) {
                model->AddConstr(*COPT_LINEAR_EXPRESSION_AMP.safeGet(expr), sense, rhsVal, constrName.c_str());
            } else {
                model->AddConstr(*COPT_LINEAR_EXPRESSION_AMP.safeGet(expr), sense, rhsVal);
            }
        }

    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    }

    return new String(constrName);
}

ConstantSP coptSetLogFile(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " setLogFile(model, logFilePath): ";
    
    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    string logFilePath = getStringScalar(args[1], __FUNCTION__, usage, "logFilePath");

    // SET log file
    try {
       model->SetSolverLogFile(logFilePath.c_str());
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    } 

    return new Void();
}

ConstantSP coptSetObjective(Heap *heap, vector<ConstantSP> &args) {
    string usage = COPT_PREFIX + " setObjective(model, expr, sense): ";

    auto model = COPT_MODEL_AMP.safeGet(args[0]);
    auto expr = args[1];
    if (args[2].isNull() or args[2]->getForm() != DF_SCALAR or args[2]->getType() != DT_INT) {
        throw IllegalArgumentException(__FUNCTION__, usage + " sense should be an int.");
    }
    int sense = args[2]->getInt();
    if (sense != COPT_MAXIMIZE && sense != COPT_MINIMIZE) {
        throw IllegalArgumentException(__FUNCTION__, usage + " sense should be 1 or -1.");
    }

    bool isQuad = false;
    if (expr->getString() == COPT_QUAD_EXPRESSION_DESC) {
        isQuad = true;
    }

    // set objective value
    try {
        if (isQuad) {
            model->SetQuadObjective(*COPT_QUAD_EXPRESSION_AMP.safeGet(expr), sense);
        } else {
            model->SetObjective(*COPT_LINEAR_EXPRESSION_AMP.safeGet(expr), sense);
        }
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    }

    return new Void();
}

ConstantSP coptSolve(Heap *heap, vector<ConstantSP> &args) {
    auto model = COPT_MODEL_AMP.safeGet(args[0]);

    // solve the optimization problem
    int status;
    try {
        model->Solve();
        if (model->GetIntAttr(COPT_INTATTR_ISMIP)) {
            status = model->GetIntAttr(COPT_INTATTR_MIPSTATUS);
        } else {
            status = model->GetIntAttr(COPT_INTATTR_LPSTATUS);
        }
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    }

    return new Int(status);
}

ConstantSP coptGetResult(Heap *heap, vector<ConstantSP> &args) {
    auto model = COPT_MODEL_AMP.safeGet(args[0]);

    // get results
    DictionarySP result = Util::createDictionary(DT_STRING, nullptr, DT_ANY, nullptr, true);
    try {
        auto vars = model->GetVars();
        for (int i = 0; i < vars.Size(); i++) {
            result->set(vars[i].GetName(), new Double(vars[i].Get("Value")));
        }
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    }

    return result;
}

ConstantSP coptGetObjValue(Heap *heap, vector<ConstantSP> &args) {
    auto model = COPT_MODEL_AMP.safeGet(args[0]);

    double objValue;
    try {
        if (model->GetIntAttr(COPT_INTATTR_ISMIP)) {
            objValue = model->GetDblAttr(COPT_CBINFO_BESTOBJ);
        } else {
            objValue = model->GetDblAttr(COPT_DBLATTR_LPOBJVAL);
        }
    } catch (CoptException &e) {
        throw RuntimeException(COPT_PREFIX + " Error code = " + std::to_string(e.GetCode()) + "\n" + e.what());
    }

    return new Double(objValue);
}


/// Helper Implementations
VectorSP getNumVector(const ConstantSP &arg, const string &funcName, const string &usage,
                      const string &argName, int size) {
    if (arg.isNull() or arg == NULL or arg->getForm() != DF_VECTOR or (arg->getType() != DT_INT and arg->getType() != DT_DOUBLE)) {
        throw IllegalArgumentException(funcName, usage + argName + " should be a vector of int or double.");
    }
    if (arg->size() != size) {
        throw IllegalArgumentException(funcName, usage + "size of " + argName + " is not equal to " + to_string(size));
    }
    if (arg->hasNull()) {
        throw IllegalArgumentException(funcName, usage + argName + " can't contain null value.");
    }
    return arg;
}

VectorSP getCharVector(const ConstantSP &arg, const string &funcName, const string &usage,
                       const string &argName, int size) {
    if (arg.isNull() or arg == NULL or arg->getForm() != DF_VECTOR or arg->getType() != DT_CHAR) {
        throw IllegalArgumentException(funcName, usage + argName + " should be a vector of char.");
    }
    if (arg->size() != size) {
        throw IllegalArgumentException(funcName, usage + "size of " + argName + " is not equal to " + to_string(size));
    }
    if (arg->hasNull()) {
        throw IllegalArgumentException(funcName, usage + argName + " can't contain null value.");
    }
    return arg;
}

VectorSP getStringVector(const ConstantSP &arg, const string &funcName, const string &usage,
                         const string &argName, int size) {
    if (arg.isNull() or arg == NULL or arg->getForm() != DF_VECTOR or arg->getType() != DT_STRING) {
        throw IllegalArgumentException(funcName, usage + argName + " should be a vector of string.");
    }
    if (arg->size() != size) {
        throw IllegalArgumentException(funcName, usage + "size of " + argName + " is not equal to " + to_string(size));
    }
    if (arg->hasNull()) {
        throw IllegalArgumentException(funcName, usage + argName + " can't contain null value.");
    }
    return arg;
}

VectorSP getQuadMatrix(const ConstantSP &arg, const string &funcName, const string &usage,
                       const string &argName, int size) {
    // check form
    auto form = arg->getForm();
    if (arg.isNull() or arg == NULL or form != DF_MATRIX) {
        throw IllegalArgumentException(funcName, usage + argName + " should be a matrix.");
    }
    // check size
    auto argSize = arg->columns();
    if (argSize != size) {
        throw IllegalArgumentException(funcName, usage + "size of " + argName + " is not equal to " + to_string(size));
    }
    // check columns
    for (auto i = 0; i < size; ++i) {
        getNumVector(arg->getColumn(i), funcName, usage, "member of " + argName, argSize);
    }

    if (arg->hasNull()) {
        throw IllegalArgumentException(funcName, usage + argName + " can't contain null value.");
    }
    return arg;
}

int getIntScalar(const ConstantSP &arg, const string &funcName, const string &usage, const string &argName) {
    if (arg->isNull() or arg == NULL or arg->getForm() != DF_SCALAR or arg->getType() != DT_INT) {
        throw IllegalArgumentException(funcName, usage + argName + " should be a int.");
    }
    return arg->getInt();
}

char getCharScalar(const ConstantSP &arg, const string &funcName, const string &usage, const string &argName) {
    if (arg.isNull() or arg == NULL or arg->getForm() != DF_SCALAR or arg->getType() != DT_CHAR) {
        throw IllegalArgumentException(funcName, usage + argName + " should be a char.");
    }
    return arg->getChar();
}

double getDoubleScalar(const ConstantSP &arg, const string &funcName, const string &usage,
                       const string &argName) {
    if (arg.isNull() or arg == NULL or arg->getForm() != DF_SCALAR or (arg->getType() != DT_DOUBLE and arg->getType() != DT_INT)) {
        throw IllegalArgumentException(funcName, usage + argName + " should be a double.");
    }
    return arg->getDouble();
}

string getStringScalar(const ConstantSP &arg, const string &funcName, const string &usage, const string &argName) {
    if (arg.isNull() or arg == NULL or arg->getForm() != DF_SCALAR or arg->getType() != DT_STRING) {
        throw IllegalArgumentException(funcName, usage + argName + " should be a string.");
    }
    return arg->getString();
}

