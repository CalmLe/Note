<h1>this与super</h1>

>**this 关键字**：指向**对象本身**的一个指针
>
>this的用法：
>
>用法①：直接用表示该对象的成员变量。
>
>用法②：形参与成员变量同名时 ，常用this用来区分this.成员变量（常常用来与同名变量区分）
>
>```java
>public Country(String name) {
>    this.name = name;
>}
>```
>



> **super 关键字**:指向对象父类的一个指针
>
> super的用法：
>
> 用法①：直接引用父类的方法或者成员变量
>
> ```java
> public class Dog extends Animal{
> @Override   
> void eat() {
> super.eat();      //引用父类的方法
> }
> 
> @Override
> void sleep() {
> super.sleep();    //引用父类的方法
> }
> 
> @Override
> void sick() {
> super.sick();     //引用父类的方法
> }
> }
> ```
>
> 用法②：**子类中的成员变量或方法与父类中的成员变量或方法同名**
>
> ```java
> class Country {
> String name;
> void value() {
> name = "China";
> }
> }
> class City extends Country {
> String name;
> void value() {
> name = "Shanghai";
> super.value();      //调用父类的方法
> System.out.println(name);
> System.out.println(super.name);//父类的成员变量
> }
> 
> public static void main(String[] args) {
> City c=new City();
> c.value();
> }
> }
> 答案：
> Shanghai
> China
> 若去掉super.value则答案为null然后china
> ```
> **this与super都可以引用构造函数**（注意super（）与this（）都必须放在构造函数的第一条语句）
>
> super（参数）：调用父类中某一构造函数。
>
> this（参数）：调用本类中另一种构造函数。（也就是重载构造函数的调用）
>
> ```java
> public class Animal {
> String name;
> int age;
> public Animal() {
> System.out.println("无参父类构造器");
> }
> 
> public Animal(String name) {
> System.out.println("一个参数父类构造器");
> }
> 
> public Animal(String name, int age) {
> System.out.println("两个参数父类构造器");
> }
> 
> }
> ```
>
> ```java
> public class Dog extends Animal{
> String name;
> int age;
> 
> public Dog() {
>   super();
>   System.out.println("无参子类构造器");
> }
> 
> public Dog(String name) {
>   super(name);
>   System.out.println("一个参数子类构造器");
> }
> 
> public Dog(String name, int age) {
>   this(name);
>   System.out.println("两个参数子类构造器");
> }
> }
> ```
>
> ```java
> public class DogApplication {
>  public static void main(String[] args) {
>       Dog zhangdaye = new Dog();
>       Dog lidaye = new Dog("泰迪");
>       Dog zhoudaye = new Dog("泰迪",10);
>  }
> }
> ```
>
> 输出
>
> 无参父类构造器
> 无参子类构造器
> 一个参数父类构造器
> 一个参数子类构造器
> 一个参数父类构造器
> 一个参数子类构造器
> 两个参数子类构造器

<h3>关于this跟super的注意事项</h3>

1. super() 和 this() 均需放在构造方法内第一行。

2. this（） 和 super（） 不能同时出现在一个构造函数里面，尽管可以用this调用一个构造器，但却不能调用两个。

3. this() 和 super() 都指的是对象，所以，均不可以在 static 环境中使用。包括：static 变量,static 方法，static 语句块。
