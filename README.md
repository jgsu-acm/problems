# oj-problems

## manager.py

```bash
usage: manager.py [-h] {c,g} ...

optional arguments:
  -h, --help  show this help message and exit

command:
  {c,g}
    c         创建题目
    g         生成测试数据
```
    
### 子模块

#### 创建题目

<details>

```bash
usage: manager.py c [-h] [--get [SOURCE ...] | --objective] [--python] [--nogen] [--nostd] problem [problem ...]

positional arguments:
  problem

optional arguments:
  -h, --help            show this help message and exit
  --get [SOURCE ...], -g [SOURCE ...]
                        从洛谷获取题目
  --objective, -o       客观题
  --python, -p          使用 python 生成器
  --nogen, -ng          不生成生成器模板
  --nostd, -ns          不生成标程模板
```
  
</details>

#### 生成数据

<details>
  
```bash
usage: manager.py g [-h] problem [problem ...]

positional arguments:
  problem

optional arguments:
  -h, --help  show this help message and exit
```

</details>
