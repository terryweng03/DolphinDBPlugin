# DolphinDB copt 行情插件最佳实践指南
杉数求解器（Cardinal Optimizer），简称 COPT，是杉数科技自主研发的针对大规模优化问题的高效数学规划求解器套件。   杉数求解器目前支持求解线性规划、二阶锥规划、二次规划、 二次约束规划、指数锥规划、半定规划、非线性规划、 混合整数线性规划、混合整数二阶锥规划、混合整数二次规划以及混合整数二次约束规划问题，为企业应对高性能求解的需求提供了更多选择。用户可于杉数科技官网进行 copt 的[试用申请](https://shanshu.ai/copt)。

DolphinDB 提供了 copt 插件，支持通过插件函数调用 copt 进行建模以及求解。本文全部代码需要运行在 2.00.16 以及 3.00.3 或者更高版本的 DolphinDB server 以及插件上，目前仅支持 Linux 系统。

# 1. 基本使用说明
节点启动后，可以使用 GUI, VS Code, Web UI 等 [DolphinDB 客户端](https://docs.dolphindb.cn/zh/db_distr_comp/clients.html) 连接相应节点并执行示例代码。

## 1.1 安装插件
(1) 安装插件前，需要登录有创建权限的账号。执行如下代码登录默认的管理员账号：
```DolphinDB
login("admin", "123456")
```
(2) 在 DolphinDB 客户端中使用 listRemotePlugins 命令查看插件仓库中的插件信息。
```DolphinDB
listRemotePlugins();            \\ 所有插件的版本信息
listRemotePlugins("copt");      \\ copt 插件的版本信息 
```
(3) 执行 installPlugin 函数，则可以下载到与当前 server 版本适配的 copt 插件文件，插件文件包括插件描述文件及插件的二进制文件：
```DolphinDB
loadPlugin("copt")
```

## 1.2 加载插件
在脚本中调用插件相关的接口前，需要先加载插件。
```DolphinDB
loadPlugin("copt")
```

# 2. 快速上手
copt 插件提供函数调用 copt 进行建模以及求解，具体函数介绍可以参照插件文档。
## 2.1 创建一个二次规划模型并求解

### 2.1.1 DolphinDB 代码
```DolphinDB
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
	copt::addConstr(model, lhsExpr, 'L', rhs[i])
}

lhsExpr = copt::linExpr(model, 1 1 1 1 1 1 1 1 1 1, stock_vars)
copt::addConstr(model, lhsExpr, 'E', 1)

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

## 2.2 代码解析
```DolphinDB
model = copt::model()
```
copt::model() 创建一个 COPT 模型对象，该对象会作为其他插件函数的参数。

```DolphinDB
lb = 0 0 0 0 0 0 0 0 0 0
ub = 1 1 1 1 1 1 1 1 1 1

stock_vars = copt::addVars(model, 10, lb, ub, , , 'stock')
```
向 COPT 模型对象 model 加入一组连续变量 $stock_i$ 满足 $ 0 \leq stock_i \leq 1 \ where\ i = 0,1,...,9$，该组变量为连续变量且目标函数中的系数为0。

```DolphinDB
A = [1 1 1 0 0 0 0 0 0 0,
     0 0 0 1 1 1 0 0 0 0,
     0 0 0 0 0 0 1 1 1 1,
     -1 -1 -1 0 0 0 0 0 0 0,
     0 0 0 -1 -1 -1 0 0 0 0,
     0 0 0 0 0 0 -1 -1 -1 -1]
rhs = 0.38 0.48 0.38 -0.22 -0.32 -0.22

for (i in 0:6) {
	lhsExpr = copt::linExpr(model, A[i], stock_vars)
	copt::addConstr(model, lhsExpr, 'L', rhs[i])
}
```
向 COPT 模型对象 model 加入一组线性不等式约束  
$$ 
\begin{align*} 
stock_0 + stock_1 + stock_2 \leq 0.38  \\
stock_3 + stock_4 + stock_5 \leq 0.48  \\
stock_6 + stock_7 + stock_8 + stock_9 \leq 0.38  \\
-stock_0 - stock_1 - stock_2 \leq -0.22 \\
-stock_3 - stock_4 - stock_5 \leq -0.32 \\
-stock_6 - stock_7 - stock_8 - stock_9 \leq -0.22 \\
\end{align*}

$$
```DolphinDB
lhsExpr = copt::linExpr(model, 1 1 1 1 1 1 1 1 1 1, stock_vars)
copt::addConstr(model, lhsExpr, 'E', 1)
```
向 COPT 模型对象 model 加入一条线性等式约束
$$ 
\begin{align*} 
stock_0 + stock_1 + stock_2 + stock_3 + stock_4 + stock_5 + stock_6 + stock_7 + stock_8 + stock_9 = 1
\end{align*}
$$

```DolphinDB
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
```
向 COPT 模型对象 model 设置二次目标函数
$$ 
\begin{align*} 
Maximize\  & -{stock_{0}}^2 - {stock_{1}}^2 - {stock_{2}}^2 - {stock_{3}}^2 - {stock_{4}}^2 - {stock_{5}}^2 - {stock_{6}}^2 \\
& -{stock_{7}}^2 - {stock_{8}}^2 - {stock_{9}}^2 + 0.1stock_0 + 0.02stock_1 + 0.01stock_2 + 0.05stock_3 \\
& + 0.17stock_4 + 0.01stock_5 + 0.07stock_6 + 0.08stock_7 + 0.09stock_8 + 0.1stock_9
\end{align*}
$$

```DolphinDB
objValue = copt::getObjValue(model)
print(objValue)
```
获取模型目标函数值并打印，该示例的目标函数值为 -0.025441666666667

```DolphinDB
results = copt::getResult(model)
print(results)
```
获取模型中的变量取值并打印，该示例的变量取值字典为
```DolphinDB
stock_0->0.123333333331732
stock_1->0.083333333331732
stock_2->0.078333333331732
stock_3->0.098333333334935
stock_4->0.158333333334934
stock_5->0.078333333334936
stock_6->0.0875
stock_7->0.0925
stock_8->0.0975
stock_9->0.1025
```