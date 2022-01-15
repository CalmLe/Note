<h2>企业开发标准之----本地测试
</h2>
 ><h5>企业中的开发
 ></h5>
 >企业中的开发是模块化的，main里面不能存放太多逻辑与功能性的东西,写一些简单的东西，复杂的东西都在模块里面，否则不符合面向对象程序设计，复用性太差了。
 >
 >注意：main函数是程序的入口，千万不要拿来测试！！！，注意模块化！！！，抽离！！！！




> 说明：我们个人通常是这样进行本地测试的，在main函数里面通过控制台打印，看结果是否符合自己的预期；然而在企业中一般都是模块化测试，也就是单元测试，这就需要导入Junit架包，去（maven repository)上下载，其实还可以用maven的方式去下载但是现在我还没有学




>导入架包如果没有解决依耐性问题就会出现现在这种情况

![image-20220108130628800](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220108130628800.png)

>解决办法:如下图（编译依赖）

![image-20220108130834078](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220108130834078.png)



> 本地单元测试：
>
> ```java
> import org.junit.Assert;      //代替了控制台输出的繁琐方法！！！这才是单元测试
> import org.junit.Test; 
> 
> import java.util.concurrent.ThreadLocalRandom;
> 
> public class CalcuTest {
>     @Test
>     public void sumTest() {
>         int a = ThreadLocalRandom.current().nextInt(1, 100);
>         int b = ThreadLocalRandom.current().nextInt(1, 100);
>         int sum = Calcu.sum(a, b);
>         Assert.assertEquals(a + b, sum);   //而不是你通过肉眼去算，太low了
>     }
>     @Test
>     public void factoryTest() {
>         int a = ThreadLocalRandom.current().nextInt(1, 100);
>         int b = ThreadLocalRandom.current().nextInt(1, 100);
>         int factory = Calcu.factory(a, b);
>         Assert.assertEquals(a * b, factory);  //而不是你通过肉眼去算，太low了
>     }
> }
> ```
> 

![image-20220108131320782](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220108131320782.png)



