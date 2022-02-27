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
usage: manager.py c [-h] [--get [SOURCE ...] | --objective] [--python] [--nogen] [--nostd] creator [creator ...]

positional arguments:
  creator               要创建的题目，支持区间

optional arguments:
  -h, --help            show this help message and exit
  --get [SOURCE ...], -g [SOURCE ...]
                        从洛谷获取题面，支持区间，题目数量及且顺序要与要创建的题目相同
  --objective, -o       客观题
  --python, -p          使用 python 生成器
  --nogen, -ng          不生成生成器模板
  --nostd, -ns          不生成标程模板
```
  
</details>

#### 生成数据

<details>
  
```bash
usage: manager.py g [-h] creator [creator ...]

positional arguments:
  creator     要生成数据的题目，支持区间

optional arguments:
  -h, --help  show this help message and exit
```

</details>
