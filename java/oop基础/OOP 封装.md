<h2>OOP 封装</h2>

> <b>对OOP封装的理解：</b>
>
> 把public类型的成员变量改成private，不允许其他外部内访问，防止对成员变量的任意修改



> <b>举例</b>
>
> getBalance和 setBalances
>
> ```java
> private int balance;
>    public int getBalance() { 
>  return balance;
> }
> //如果不用get，set可能会导致余额被胡乱修改
>    public void setBalance(int money) {
>     if(money > 0) {
>         this.balance += money;  //存入余额
>     }else {
>         //  存钱失败
>  }
> }
> ```



><b>问题</b>：我们发现如果很多都需要封装，那么一个个写get，set就很麻烦。
>
><b>解决办法1</b>:alt + insert  -> Getter and Setter 就直接生成 get，set 。
>
><b>新问题的产生</b>:这样很多个get，set会让代码看起来非常的繁琐，那我们该怎么办呢？
>
><b>解决办法</b>2:通过注解（<b>@Getter@Setter</b>）不过再次之前我们必须安装<b>lombok</b>插件 Setting -> Plugins -> lombok, 然后使用搜索引擎搜索Maven Repository  下载jar文件再导入项目内即可（这里还可以用maven的方法，不过现在还没有学习）