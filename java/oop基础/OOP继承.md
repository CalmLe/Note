<h2>OOP继承</h2>

>**<b>继承</b>:**就是子类**继承父类的特征和行为**,可以拥有**自己的特性和行为**。（但是不继承构造方法啊）
>
>**问题：**为什么要有继承呢？
>
>**我的理解：**继承出现的目的是为了将一些**具有共同特征的类提取出来组成一个新的类**，这个类也就是我们说的父类，而继承父类的类叫做子类。

![image-20211219182626716](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211219182626716.png)

>**注意！！！！继承不能继承构造方法！！！！！**必须在子类里面写构造方法！！！！
>
>```java
>public class Dog extends Animal {
>    public Dog() {
>    }
>
>    public Dog(String name, String breed) {
>        super(name, breed);
>    }   
>}     //用alt + insert ->Constructor 写或者直接手写
>```
>
>



>**方法的重写:**
>
>**好处**：让子类具有自己的特性
>
>**重写的方法**:1.直接写
>
>​                    2.alt + insert  -> Override Methods
>
>```java
>public class Cat extends Animal{
>@Override
>void eat() { 
>   super.eat();            //父类的方法                                          
>}
>
>@Override
>void sleep() {
>   System.out.println("猫睡觉");             //方法的重写！！！！！！让子类具有自己的特性
>}
>
>@Override
>void sick() {
>   System.out.println("猫生病");            //方法的重写！！！！！！让子类具有自己的特性
>}
>
>}
>
>```
>

> <h3>注意重载跟重写是不一样的。</h3>
>
> 重写是继承中的概念，发生在**子类跟父类**之间，子类重写父类的**方法，方法名、参数列表、返回值相同**，让子类可以拥有跟父类不一样的特性，but子类的**访问权限不能低于父类**
>
> 重载是发生在**同一个类**中，有**同名方法**，but同名方法的参**数列表的不同**（参数类型或者参数的个数不一样，或两者都不一样），**跟方法的返回值类型无关**。

