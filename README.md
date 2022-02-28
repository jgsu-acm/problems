# oj-problems

`jgsuoj` 上所有题目的题面、大部分题目的数据生成器和标程以及管理器。

## 管理器 manager.py 的用法

```bash
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

```bash
Usage: manager.py c [OPTIONS] PIDS...

  创建题目

Options:
  -s, --source [luogu]   从何处获取题目
  -i, --spids SOURCEIDS  获取哪些题面，支持区间，题目数量及顺序要与要创建的题目相同
  -sa, --submitans       提交答案题
  -ng, --nogen           不生成生成器模板
  -ns, --nostd           不生成标程模板
  -py, --python          使用 python 生成器
```

</details>

#### 生成数据

<details>
  
```bash
Usage: manager.py g [OPTIONS] [PIDS]...

  生成测试数据
```

</details>
