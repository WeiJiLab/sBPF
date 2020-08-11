# NMCS
`netd` like network services for linux kernel

## 环境配置
采用vscode + devcontainer的方式开发
1. vscode打开会默认在右下角提示，reopen container，会自动启动相关容器
2. 安装相关依赖
```
apt install cmake git build-essential linux-headers-$(uanme -r) linux-source
apt install -y libgtest-dev
```
3. 编译
```
1. 在MNCS目录下执行cmake . -B build
2. 进入NetD目录执行make,会在NetD目录下的build目录中生成NetD的可执行文件
3. ./NetD执行
```
4. 测试
另开终端执行：curl 127.0.0.1:8080/getRoute
会查询到相关的路由信息

## 其他
sBPF 跟NetD没关系，是我们自己写的ebpf执行引擎。