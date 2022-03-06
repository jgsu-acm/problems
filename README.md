# problems

`jgsuoj` 上所有题目的题面、大部分题目的数据生成器和标程以及管理器。

## 管理器 manager.py 的用法

```txt
Usage: manager.py [OPTIONS] COMMAND [ARGS]...

Options:
  -l, --level [ERROR|WARNING|INFO|DEBUG]
                                  日志级别
  --help                          Show this message and exit.

Commands:
  c  创建题目
  g  生成测试数据
```

### 子模块

#### 创建题目

<details>

```txt
Usage: manager.py c [OPTIONS] PIDS...

  创建 PIDS 题目

  PIDS 与 SOURCEIDS 支持以下语法：
      * P1001-P1010 代表 P1001,P1002,...,P1010
      * P1001+5 代表 P1001,P1002,...,P1005

Options:
  -s, --source [luogu]   从何处获取题目
  -i, --spids SOURCEIDS  获取哪些题面，数量及顺序要与欲创建的题目相同
  -sa, --submitans       提交答案题
  -ng, --nogen           不生成生成器模板
  -ns, --nostd           不生成标程模板
  -py, --python          使用 python 生成器
```

</details>

#### 生成测试数据

<details>

```txt
Usage: manager.py g [OPTIONS] PIDS...

  生成 PIDS 测试数据

  PIDS 支持以下语法：
      * P1001-P1010 代表 P1001,P1002,...,P1010
      * P1001+5 代表 P1001,P1002,...,P1005
```

</details>
