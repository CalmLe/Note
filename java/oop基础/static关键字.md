<h1>static关键字</h1>

> static 是一个**非访问修饰符**，能修饰**方法**，**成员变量**，**代码块**，使其变成静态的。（控制不了访问权限）

>用法：
>
>**用法①：静态成员变量**    （类名.成员变量）
>
>下面是Math类的源代码的一部分；
>
>```java
>public final class Math {
>
>/**
>  * Don't let anyone instantiate this class.
>  */
> private Math() {}
>
>public static final double E = 2.7182818284590452354;
>
>static final double PI = 3.14159265358979323846;
>}
>
>```
>
>！！！调用的时候就可以直接Math.E 或者 Math.PI，但由于有构造函数private Math（）的存在，所以Math类不可以被实例化，所以只能类名.成员变量。

>关于静态变量与非静态变量：静态变量被所有对象共同享用，只有一个副本（**所以很多static修饰的成员变量都用fianl修饰**）；而非静态变量是对象所拥有的，在创建对象的时候就被初始化了，有多个副本
>
>注意：在C/C++中static是可以作用域局部变量的，但是在Java中切记：**static是不允许用来修饰局部变量**。不要问为什么，这是Java语法的规定。

>**用法②：静态成员方法**     （类名.成员方法）
>
>下面是Math类的源代码的一部分；
>
>```java
>public final class Math {
>
>  /**
>   * Don't let anyone instantiate this class.
>   */
>  private Math() {}
>
>  public static int max(int a, int b) {
>      return (a >= b) ? a : b;
>  }
>
>}
>
>```
>！！！调用的时候就可以直接Math.max(a,b)，但由于有构造函数private Math（）的存在，所以Math类不可以被实例化，所以只能类名.成员方法。
>
>关于静态成员变量跟静态成员方法其实可以通过创建对象，再通过**对象.成员变量**或者**对象.方法**。
>
>因为静态的成员变量跟静态的方法是所有对象共享的！不依赖于对象的存在。，就可以通过类名进行直接的访问。 因此，如果说想在不创建对象的情况下调用某个方法，就可以将这个方法设置为static。

><h4>注意!</h4>
>static方法就是没有this的方法。在static方法内部不能调用非静态方法以及非静态变量，反过来在非静态方法里面使用静态变量跟静态方法都是可以的。而且可以在没有创建任何对象的前提下，仅仅通过类本身来调用static方法。这实际上正是static方法的主要用途
>
>```java
>常见错误；静态方法中使用非静态的变量，更不能用this了！！！！
>public class Student {
>        public int id;
>        public static void outputId () {
>                System.out.println("id = " + id);      
>        }
>}
>public class Main(void) {
>        public static void main(String[] arg) {
>                Student.outputId();
>        }
>}
>```
