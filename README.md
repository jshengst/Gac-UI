# 使用xmake构建GacUI

## 仓库结构

### Root\Release

- [GacUI Release](https://github.com/vczh-libraries/Release)：GacUI 发布仓库

### Root\Source

- [GacUI](https://github.com/vczh-libraries/GacUI)：GUI
- [GacJS](https://github.com/vczh-libraries/GacJS)：GacUI 的浏览器运行依赖
- [Tools](https://github.com/vczh-libraries/Tools)：GacUI 配套的构建工具
- [Vlpp](https://github.com/vczh-libraries/Vlpp)：数据结构和相关数据处理功能的基础库
- [VlppOS](https://github.com/vczh-libraries/VlppOS)：提供访问操作系统功能
- [VlppParser](https://github.com/vczh-libraries/VlppParser)：GLR 解析器生成器
- [VlppParser2](https://github.com/vczh-libraries/VlppParser2)：GLR 解析器生成器2（即将废弃）
- [VlppReflection](https://github.com/vczh-libraries/VlppReflection)：C++反射功能库
- [VlppRegex](https://github.com/vczh-libraries/VlppRegex)：正则表达式库
- [Workflow](https://github.com/vczh-libraries/Workflow)：与 C++ 类互操作的 WorkFlow 脚本语言实现和运行时库

### 构建

编译GacUI Demo：

``` cmd
xmake build HelloGacUI
```

### 说明

本项目出于学习目的，搜集了由 [@vczh](https://github.com/vczh) 创建的 GacUI 项目的未合并源码。

注意，**使用前请阅读[GacUI License](https://github.com/vczh-libraries/License/blob/master/README.md)**。这些未合并代码的使用许可与发布在 [GacUI Release](https://github.com/vczh-libraries/Release) 仓库中的代码有显著不同。

[@vczh](https://github.com/vczh) 拥有 [GacUI 项目](https://github.com/vczh-libraries)的最终解释权。本仓库与 GacUI 项目无关，且不拥有任何权利。
