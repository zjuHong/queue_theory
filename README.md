# 排队论学习
包括：
泊松分布随机生成。
卡方检验。
仿真等。

关于异常监测的一些想法：先判断是否为泊松分布，如果满足泊松分布，就滑动窗口计算实时lambda，获得概率分布。计算当前的概率如果低于一定的阈值就认为是异常。

判断一维数据属于何种分布：
1、KL散度
https://blog.csdn.net/cj151525/article/details/97611446?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase
