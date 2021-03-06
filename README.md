# wordCounter
一个用c++编写的一个源程序特征统计程序
如需运行文件请下载后打开根目录`.sln`文件
## 项目功能要求
### 基本功能
- wc.exe -c `file.c`    // 返回文件 file.c 的字符数
- wc.exe -w `file.c`    // 返回文件 file.c 的单词的数目
- wc.exe -l `file.c`    // 返回文件 file.c 的行数
### 扩展功能
- -s 递归处理目录下符合条件的文件
- -a 返回更发杂的数据（代码行/空行/注释行）
- 支持各种文件的通配符（*,?）
### 高级功能
- -x 参数。这个参数单独使用。如果命令行有这个参数，则程序会显示图形界面，用户可以通过界面选取单个文件，程序就会显示文件的字符数、行数等全部统计信息。
需求举例：
　　`wc.exe -s -a *.c`
- 基本的Windows GUI 程序操作
- 支持通过图形界面选取文件
- 支持通过图形界面展现文件的信息


## 项目PSP表格
PSP2.1 | Personal Software Process Stages | 预估耗时（分钟） | 实际耗时（分钟）
-|-|-|-
Planning | 计划 | 30 | 
Estimate | 估计这个任务需要多少时间 | 30 | 
Development | 开发 | 1440 | 
Analysis | 需求分析 (包括学习新技术) | 120 | 
Design Spec | 生成设计文档 | 60 |
Design Review | 设计复审 (和同事审核设计文档) | 30 |
Coding Standard | 代码规范 (为目前的开发制定合适的规范) | 30 |
Design | 具体设计 | 60 | 
Coding | 具体编码 | 1000 | 
Code Review | 代码复审 | 60 |
Test | 测试（自我测试，修改代码，提交修改） | 30 |
Reporting | 报告 | 60 |
Test Report | 测试报告 | 40 |
Size Measurement | 计算工作量 | 30 |
Postmortem & Process Improvement Plan | 事后总结, 并提出过程改进计划 | 60 |
总计 |  | 3080 | 


