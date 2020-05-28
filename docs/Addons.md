## 插件系统(草稿)

fibjs_vender 通过一系列宏/纯 C 函数/C++ 11 兼容的类帮助开发者编译扩展.

## 规则

所有的 FIBJS 扩展必须按下列格式导出一个初始化方法:

```cpp
void Initialize(t_internal_init_callback init_cb, t_init_context_value_ref init_ctx, t_addon_retValue& retAddonVal);
FIBJS_ADDON(Initialize)
```
**说明**:
- 其中 `Initialize` 的类型说明详见 `jssdk/include/jsaddons.h`

你可以使用任何支持的 C++ 11 标准的编译器编译该模块得到 `[FIBJS_MODULE_NAME].addon`, 将其放在 fibjs 可解析的路径中.

比如, 在项目中存在 `node_modules/foo/index.addon`, 则在 fibjs (>= 0.31.0) 中这样调用:

```javascript
var fooModule = require('foo')
```

就可以加载该扩展

## 开始编写你的扩展

参考[这里的例子](https://github.com/fibjs/addon_sample) 开始编写你的扩展:

### 添加一个模块

扩展的要求很简单, 引用 `jssdk/include/jsaddons.h` 文件即可:

```cpp
#include <jssdk/include/jsaddons.h>

void Initialize(jsaddons::t_init_context_value_ref ctx, jsaddons::t_addon_retValue& addonVal) {
  // 来自 jsaddons.h 的全局静态变量, 是扩展和 fibjs 主程序之间的首要的, 也是目前唯一的沟通渠道
  js::Api* fibjs_api = js::fibjs_api;

  // 获取运行中的 fibjs 的 JSRuntime, 通过它, 你可以访问和操作 JS 对象
  js::Runtime* jsruntime = fibjs_api->getCurrentJSRuntime();

  // exlib 是 fibjs 的基础库, 其中包含了字符处理和事件调度等对于 fibjs 重要的数据结构和操作
  // 不过, 你并不是必须使用它, 这里我们创建了一个 JS 字符对象, 随即将其转换成了 exlib 提供的 string 结构
  exlib::string str = jsruntime->NewString("foo").toString();

  // 创建一个 JS 对象, 我们要将这个 JS 对象作为扩展最终的返回值.
  js::Object addonModule = jsruntime->NewObject();

  // ...在这里, 你可以对 addonModule 做进一步的处理, 将你希望暴露的数据或方法挂载在这个对象上

  // 将 addonModule 转化为 JS Value, 传给 addonValue, 这一步是必须的!
  addonVal = addonModule.toValue();
}

FIBJS_MODULE(Initialize)
```

## 说明

和 NodeJs 不同, FibJS 采取**反向注入**的方式来将扩展与 FibJS 程序协同工作. 除此外, FibJS 的扩展还具有以下特点:

- FibJS 的扩展本质是二进制动态链接库, 对于不同的平台, 用户应分发不同的二进制扩展
- FibJS 的扩展总是将一个名为 addonEntry C 风格函数入口作为扩展的入口
- FibJS 的扩展目前只在 FibJS 的 JS Thread 运行后才可以加载, 扩展无法干涉此前的操作

尤其注意:

- 扩展可能破坏 FibJS 的安全性和完备性! 使用扩展意味着你信任该扩展的发行方, 或者扩展由你自行下载并编译使用.

## TODOs

- [x] 扩展可独立编译
- [ ] 扩展能通过 jssdk API 得到完备的 JS 能力
  - JS Primitive
    - [x] undefined
    - [ ] number
      - [ ] NaN
    - [x] boolean
    - [x] string
    - [x] object/null
    - [x] function
    - [ ] symbol
  - JS BuiltIn Object
    - [ ] Object
    - [ ] Function
    - [ ] Date
    - ...
  - [ ] 运行 JS 脚本并获得其执行结果
  - [ ] 在 C++ 中开辟 JS Thread, 提供 JS 执行栈
- [x] jssdk::Isolate
- [ ] jssdk::FiberRuntime
  - [ ] 扩展能通过 jssdk API 来发起异步操作, 而无需关心异步调度(就像在 fibjs 里的那样)
    - [ ] exlib::Service
    - [ ] AsyncEvent
- [ ] jssdk::Module
  - [ ] idlc.js for addon
- ...