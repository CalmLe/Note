# mysql

## 0.数据库的简单认识 ##

### 一.什么是数据库 ###

数据库是存放数据的，是用来保存数据的仓库， qq， 密码等等都是属于数据



### 二.数据库的诞生 ###

举个学生管理系统的例子；

瞬时--------》放在内存里，程序结束后第二次运行的时候，上次的数据就没有了

之后为了解决这个问题就保存在文件里，实现了瞬时->持久性数据 stu.txt



### 三.萌芽阶段 ###

文件保存数据然后再加密的方式是最蠢的方式，CURD数据都费劲，这种方式是不行的，太愚蠢了，没必要，除非**有一种情况就是配置文件，配置文件有单独的语法**



### 四.CURD ###

- 新增数据

- 删除数据

- 修改数据

- 查找数据

    文件保存数据的方式显然不满足上述要求(**CRUD**)并且特别复杂,就有了数据库的产生
    
    
### 五.常见模型 ###    

- 层次模型：
- 网状模型: 解决了数据不完整的问题，但是没有解决导航问题
- 关系型：各管各的，和谁都有关系但都互不影响，通过一个公共字段，能找到爹，每一个都是独立的，但有共性的