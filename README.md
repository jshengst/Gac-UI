通过xmake构建GacUI。

### 仓库结构

#### Root：

- [GacUI Release](https://github.com/vczh-libraries/Release)：GacUI发布仓库

#### Root\Source：

- [GacUI](https://github.com/vczh-libraries/GacUI)：GUI
- [Vlpp](https://github.com/vczh-libraries/Vlpp)：提供数据处理功能
- [VlppOS](https://github.com/vczh-libraries/VlppOS)：提供访问操作系统功能
- [VlppParser](https://github.com/vczh-libraries/VlppParser)：GLR 解析器生成器
- [VlppParser2](https://github.com/vczh-libraries/VlppParser2)：GLR 解析器生成器
- [VlppReflection](https://github.com/vczh-libraries/VlppReflection)：C++类的反射功能
- [VlppRegex](https://github.com/vczh-libraries/VlppRegex)：提供快速的正则表达式实现
- [Workflow](https://github.com/vczh-libraries/Workflow)：与 C++ 类互操作的脚本语言实现和运行时功能

### 构建

编译GacUI release：

``` cmd
xmake f --use_release_code=true
xmake build HelloGacUI
```

编译GacUI source：

``` cmd
xmake f --use_release_code=false
xmake build HelloGacUI
```

### 说明

本项目出于学习目的，搜集了由 [@vczh](https://github.com/vczh) 创建的 GacUI 项目的未合并源码。请注意，这些未合并代码的使用许可可能与发布在 [GacUI Release](https://github.com/vczh-libraries/Release) 仓库中的代码有所不同，最终解释权归 [@vczh](https://github.com/vczh)所有。

本仓库与 GacUI 项目无关，且不拥有任何权利。
