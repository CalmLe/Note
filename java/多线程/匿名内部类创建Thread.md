<h2>匿名内部类创建Thread</h2>

```java
public class Main {

    public static void main(String[] args) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                int nikeShotAmount = 10;
                while (nikeShotAmount > 0) {
                    System.out.println(Thread.currentThread().getName()+"线程抢到"+(nikeShotAmount--)+"双鞋");
                }
            }
        }).start();
        while (true) {
            System.out.println("Main Thread");
        }
    }
}
```
>lambda表达式
>
>```java
>public class Main {
>
>    public static void main(String[] args) {
>        new Thread(() -> {
>            int nikeShotAmount = 10;
>            while (nikeShotAmount > 0) {
>                System.out.println(Thread.currentThread().getName()+"线程抢到"+(nikeShotAmount--)+"双鞋");
>            }
>        }).start();
>        while (true) {
>            System.out.println("Main Thread");
>        }
>    }
>}
>```
>
>