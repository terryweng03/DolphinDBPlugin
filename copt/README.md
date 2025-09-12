# DolphinDB copt 插件使用说明
杉数求解器 copt 是杉数自主研发的针对大规模优化问题的高效数学规划求解器套件。\
杉数求解器目前支持求解线性规划、二阶锥规划、二次规划、 二次约束规划、指数锥规划、半定规划、非线性规划、 混合整数线性规划、混合整数二阶锥规划、混合整数凸二次规划以及混合整数凸二次约束规划问题，为企业应对高性能求解的需求提供了更多选择。\
用户可于杉数科技官网进行 copt 的[试用申请](https://shanshu.ai/copt)。
## 在插件市场安装插件

### 版本要求
DolphinDB Server: 2.00.16及更高版本，或3.00.3及更高版本

注：目前仅支持 x86 的 Linux 版本。

### 安装步骤

(1) 在 DolphinDB 客户端中使用 `listRemotePlugins` 命令查看插件仓库中的插件信息。
```DolphinDB
login("admin", "123456")
listRemotePlugins(, "http://plugins.dolphindb.cn/plugins/")
```

(2) 使用 `installPlugin` 命令完成插件安装。
```DolphinDB
installPlugin("copt")
```

(3) 使用 `loadPlugin` 命令加载插件。
```DolphinDB
loadPlugin("copt")
```

## 函数接口

### model

**语法**

`model()`

**详情**

建立一个 COPT 模型对象。

**示例**

```dolphindb
model = copt::model()
```

**返回值**

返回创建的 COPT 模型对象。

### modelRead

`modelRead(model, filePath)`

**详情**

从文件中读取问题，解，基，MIP start 或者 COPT 参数，请参考 COPT 文档的 [文件格式](https://guide.coap.online/copt/zh-doc/fileformats.html)。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- filePath：类型为 STRING，文件路径。

**示例**

```dolphindb
copt::modelRead(model, "lp_ex1.mps") // 从 lp_ex1.mps 读取问题
```

### modelWrite

`modelWrite(model, filePath)`

**详情**

将问题，解，基，MIP start 或者更改后的 COPT 参数输出到文件中，请参考 COPT 文档的 [文件格式](https://guide.coap.online/copt/zh-doc/fileformats.html)。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- filePath：类型为 STRING，文件路径。

**返回值**

该函数无返回值。

**示例**

```dolphindb
copt::modelWrite(model, "lp_ex1.sol") // 将求解结果写入 lp_ex1.sol 文件中
```

### modelGetIntAttr

`modelGetIntAttr(model, intAttrName)`

**详情**

获取 COPT模型 整型属性的值，请参考 COPT 文档的 [属性](https://guide.coap.online/copt/zh-doc/attribute.html)。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- intAttrName：类型为 STRING，整数属性名称。

**返回值**

返回值为 INT 类型，为该整数属性的值。

**示例**

```dolphindb
copt::modelGetIntAttr(model, "Cols") // 获取模型的变量个数
```

### modelGetDblAttr

`modelGetDblAttr(model, dblAttrName)`

**详情**

获取 COPT模型 双精度型属性的值，请参考 COPT 文档的 [属性](https://guide.coap.online/copt/zh-doc/attribute.html)。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- dblAttrName：类型为 STRING，双精度型属性名称。

**返回值**

返回值为 DOUBLE 类型，为该双精度型属性的值。

**示例**

```dolphindb
copt::modelGetDblAttr(model, 'BestObj') // 获取整数规划求解结束时最好的目标函数值
```

### modelGetIntParam

`modelGetIntParam(model, intParamName)`

**详情**

获取 COPT模型 整型参数的值，请参考 COPT 文档的 [参数](https://guide.coap.online/copt/zh-doc/parameter.html)。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- intParamName：类型为 STRING，整数参数名称。

**返回值**

返回值为 INT 类型，为该整数参数的值。

**示例**

```dolphindb
copt::modelGetIntParam(model, 'logging') // 获取代表是否显示求解日志的参数
```

### modelGetDblParam

`modelGetDblParam(model, dblParamName)`

**详情**

获取 COPT模型 双精度型参数的值，请参考 COPT 文档的 [参数](https://guide.coap.online/copt/zh-doc/parameter.html)。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- dblParamName：类型为 STRING，双精度型参数名称。

**返回值**

返回值为 DOUBLE 类型，为该双精度型参数的值。

**示例**

```dolphindb
copt::modelGetDblParam(model, 'TimeLimit') // 获取优化求解的时间限制（秒）
```

### modelSetIntParam

`modelSetIntParam(model, intParamName, intParamValue)`

**详情**

设置 COPT模型 整型参数的值，请参考 COPT 文档的 [参数](https://guide.coap.online/copt/zh-doc/parameter.html)。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- intParamName：类型为 STRING，整数参数名称。
- intParamValue：类型为 INT，整数参数的值。

**返回值**

该函数无返回值。

**示例**

```dolphindb
copt::modelSetIntParam(model, 'logging', 0) // 设置为不显示求解日志
```

### modelSetDblParam

`modelSetDblParam(model, dblParamName, dblParamValue)`

**详情**

设置 COPT模型  双精度型参数的值，请参考 COPT 文档的 [参数](https://guide.coap.online/copt/zh-doc/parameter.html)。

**返回值**

该函数无返回值。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- dblParamName：类型为 STRING，双精度型参数名称。
- dblParamValue：类型为 DOUBLE，双精度型参数的值。

**示例**

```dolphindb
copt::modelSetDblParam(model, 'TimeLimit', 1800.0) // 将求解时间限制设置为 1800 秒
```

### addVars

**语法**

`addVars(model, lb, ub, obj, type, varNamePrefix)`

**详情**

为模型添加新的决策变量。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- numVars: 类型为 INT，为该组变量的数量。
- lb：DOUBLE 类型数组，数组中的每个元素表示对应变量的下界（lower bound）。参数 lb 可以为 NULL，此时所有变量的下界为 0。
- ub：DOUBLE 类型数组，数组中的每个元素表示对应变量的上界（upper bound）。参数 ub 可以为 NULL，此时所有变量的上界为 正无穷 或者 1（对于二进制变量）。
- obj：DOUBLE 类型数组，数组中的每个元素表示对应变量在目标函数中的系数。参数 obj 可以为 NULL，此时所有变量的系数均为 0.0。
- type：CHAR 类型数组，每个字符表示对应变量的类型。参数 type 可以为 NULL，此时所有变量的类型均为默认值 'C'：
  - 'C': 表示连续变量（Continuous）
  - 'B': 表示二元变量（Binary）
  - 'I': 表示整数变量（Integer）
- varNamePrefix：类型为 STRING，为该组变量的名称前缀。参数 varNamePrefix 可以为 NULL 或者缺省，此时所有变量的前缀由 COPT 生成。

**返回值**

返回 STRING 类型数组，数组中的每个字符串为对应的变量名。

**示例**

```dolphindb
varNames = copt::addVars(model, 10, , , , , ) // 设置一组数量为10的连续变量 (lb = 0, ub = inf, obj = 0)
varNames = copt::addVars(model, 4, , , , , "vars1") // varNames = ["vars1_10","vars1_11","vars1_12","vars1_13"]
```

### varsGetAttr

`varsGetAttr(model, varNames, attrName)`

**详情**

获取变量的信息值。 支持"Value"，"RedCost"，"LB"，"UB"，"Obj" 等信息，请参考 COPT 文档的 [信息](https://guide.coap.online/copt/zh-doc/information.html)。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- varNames：STRING 类型数组 或者 STRING 类型，对应 *model* 模型中的变量。
- attrName：类型为 STRING，获取的信息名称。

**返回值**

当 varNames 为 STRING 类型数组，返回 DOUBLE 类型数组，数组中的每个双精度浮点数为对应变量的信息值。  
当 varNames 为 STRING 类型，返回 DOUBLE 类型，为对应变量的信息值。

**示例**

```dolphindb
UBVec = copt::varsGetAttr(model, varNames, "UB") // 获取 varNames 的上界
```

### varsSetAttr

`varsSetAttr(model, varNames, attrName, attrValues)`

**详情**

设置变量的信息值。支持"LB"，"UB" 和 "Obj"等信息，请参考 COPT 文档的 [信息](https://guide.coap.online/copt/zh-doc/information.html)。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- varNames：STRING 类型数组 或者 STRING 类型，对应 *model* 模型中的变量。
- attrName：类型为 STRING，获取的信息名称。
- attrValues: DOUBLE 类型数组 或者 DOUBLE 类型，对应变量的信息值。

注：varNames 长度需要和 attrValues 长度一致。

**返回值**

该函数无返回值。

**示例**

```dolphindb
copt::varsSetAttr(model, varNames, "UB", UBVec) // 设置 varNames 的上界
```

### linExpr

**语法**

`linExpr(model, coefficient, varNames, constant)`

**详情**

创建线性表达式对象。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- coefficient：DOUBLE 类型数组，数组中的每个元素表示变量的系数。
- varNames：STRING 类型数组，对应 *model* 模型中的变量。
- constant: 类型为 DOUBLE，为线性表达式的常数项。参数 constant 可以为 NULL 或者缺省，此时常数项为 0。

**返回值**

返回创建的线性表达式对象。

**示例**

```dolphindb
lhsExpr = copt::linExpr(model, 1 2, x, 2)  // 创建线性表达式：x[0] + 2 * x[1] + 2
```

### quadExpr

**语法**

`quadExpr(model, quadMatrix, varNames, [linExpr], constant)`

**详情**

创建二次表达式对象。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- quadMatrix：DOUBLE 类型矩阵
  - 通过累加系数 (`quadMatrix[r][c]`) * 该行表示的变量 (`varName[r]`) * 该列表示的变量 (`varName[c]`)，得到二次表达式。
  - 注意虽然 DolphinDB 的矩阵是列存，理论上应该 transpose 转置，但因为 `quadMatrix[r][c]` 和 `quadMatrix[c][r]` 的作用是完全等价的（因为 `c * obj_r * obj_c = c * obj_c * obj_r`），所以实际使用中无需转置，当成行优先的矩阵直接使用即可。
- varNames：STRING 类型数组，对应 model 中的变量。
- linExpr：可选参数，通过 `linExpr` 接口创建的线性表达式对象，用来初始化二次表达式对象。
- constant: 类型为 DOUBLE，为线性表达式的常数项。参数 constant 可以为 NULL 或者缺省，此时常数项为 0。

**返回值**

返回创建的二次表达式对象。

**示例**
```dolphindb
linExpr = copt::linExpr(model, q, x)
quadExpr = copt::quadExpr(model, matrix(P), x, linExpr, 1) // 创建二次表达式 x^T H x + qx + 1
```

### addConstr

**语法**

`addConstr(model, lhsExpr, sense, rhsVal, constrName)`

**详情**

为模型添加单个线性或二次约束。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- lhsExpr：通过 `linExpr` 或 `quadExpr` 接口创建的表达式对象。
- sense：类型为 CHAR，表示约束类型：
  - 'L' or '<': COPT_LESS_EQUAL
  - 'G' or '>': COP_GREATER_EQUAL
  - 'E' or '=': COPT_EQUAL
- rhsVal：DOUBLE 类型标量。
- constrName：类型为 STRING，为约束名称。参数 constrName 可以为 NULL 或者缺省，此时约束名称由 COPT 生成。

**返回值**

返回值为 STRING 类型，为该约束的名称。

**示例**

```dolphindb
lhsExpr = copt::linExpr(model, 1 3, x) 
constr1 = copt::addConstr(model, lhsExpr, '=', 1) // 添加约束 x[0] + 3 * x[1] = 1
```

### setLogFile

**语法**

`setLogFile(model, logFilePath)`

**详情**

为 COPT 设置日志文件。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- logFilePath：类型为 STRING。为日志文件路径。

**返回值**

该函数无返回值。

**示例**

```dolphindb
copt::setLogFile(model, "MIP_case.log") // 将 MIP_case.log 设置为日志文件
```

### setObjective

**语法**

`setObjective(model, expr, sense)`

**详情**

定义模型的优化目标。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。
- expr：通过 `linExpr` 或 `quadExpr` 接口创建的表达式对象。
- sense：类型为 INT，指定优化方向：
  - -1: COPT_MAXIMIZE
  - 1: COPT_MINIMIZE

**返回值**

该函数无返回值。

**示例**

```dolphindb
copt::setObjective(model, quadExpr, -1) // 将模型的优化目标设置为 MAXIMIZE quadExpr
```

### solve

**语法**

`solve(model)`

**详情**

根据设置的目标函数和约束来寻找最优解，获取模型求解后的状态。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。

**返回值**

返回模型求解后的状态，类型为 INT，含义参考 COPT 文档的 [解状态](https://guide.coap.online/copt/zh-doc/constant.html#copttab-statuscodes)。

**示例**

```dolphindb
copt::solve(model)
```

### getResult

**语法**

`getResult(model)`

**详情**

获取优化后变量取值。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。

**返回值**

返回优化后的变量求解结果字典，其中包含了模型中所有变量的名称和对应的值。

**示例**

```dolphindb
copt::getResult(model)
```

### getObjValue

**语法**

`getObjValue(model)`

**详情**

获取优化后的目标值。

**参数**

- model：通过 `model` 接口创建的 COPT 模型对象。

**返回值**

获取优化模型求解后的目标函数值，类型为 DOUBLE。

**示例**

```dolphindb
copt::getObjValue(model)
```

## 使用示例
``` bash
/// 初始化模型
model = copt::model()

/// 增加变量
lb = 0 0 0 0 0 0 0 0 0 0
ub = 1 1 1 1 1 1 1 1 1 1

stock_vars = copt::addVars(model, 10, lb, ub, , , 'stock')

/// 增加线性约束
A = [1 1 1 0 0 0 0 0 0 0,
     0 0 0 1 1 1 0 0 0 0,
     0 0 0 0 0 0 1 1 1 1,
     -1 -1 -1 0 0 0 0 0 0 0,
     0 0 0 -1 -1 -1 0 0 0 0,
     0 0 0 0 0 0 -1 -1 -1 -1]
rhs = 0.38 0.48 0.38 -0.22 -0.32 -0.22

for (i in 0:6) {
	lhsExpr = copt::linExpr(model, A[i], stock_vars)
	copt::addConstr(model, lhsExpr, '<', rhs[i])
}

lhsExpr = copt::linExpr(model, 1 1 1 1 1 1 1 1 1 1, stock_vars)
copt::addConstr(model, lhsExpr, '=', 1)

/// 设定优化目标为二次表达式
coefficients = 0.1 0.02 0.01 0.05 0.17 0.01 0.07 0.08 0.09 0.10
linExpr = copt::linExpr(model, coefficients, stock_vars)

H = [-1 0 0 0 0 0 0 0 0 0,
     0 -1 0 0 0 0 0 0 0 0,
     0 0 -1 0 0 0 0 0 0 0,
     0 0 0 -1 0 0 0 0 0 0,
     0 0 0 0 -1 0 0 0 0 0,
     0 0 0 0 0 -1 0 0 0 0,
     0 0 0 0 0 0 -1 0 0 0,
     0 0 0 0 0 0 0 -1 0 0,
     0 0 0 0 0 0 0 0 -1 0,
     0 0 0 0 0 0 0 0 0 -1]
quadExpr = copt::quadExpr(model, matrix(H), stock_vars, linExpr)

copt::setObjective(model, quadExpr, -1)

/// 优化
status = copt::solve(model)

// 目标函数值
objValue = copt::getObjValue(model)
print(objValue)

// 变量取值
results = copt::getResult(model)
print(results)
```

