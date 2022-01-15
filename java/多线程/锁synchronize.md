>下面来看这段代码
>
>```java
>public class Main {
>
>public static void main(String[] args) {
>NikeThread nikeThread = new NikeThread();
>Thread thread1 = new Thread(nikeThread,"李绍乐");
>Thread thread2 = new Thread(nikeThread,"毛静");
>Thread thread3 = new Thread(nikeThread,"向凌云");
>thread1.start();
>thread2.start();
>thread3.start();
>}
>}
>```
>
>```java
>public class NikeThread implements Runnable {
>private int nikeShotAmount = 10;
>
>@Override
>public void run() {
>       while (nikeShotAmount > 0) {
>           try {
>               Thread.sleep(500);
>           } catch (InterruptedException e) {
>               e.printStackTrace();
>           }
>           System.out.println(Thread.currentThread().getName() + "抢到了第" + (nikeShotAmount--) + "双鞋");
>       }
>}
>}
>```
>
>这段程序的结果就是：
>
>李绍乐抢到了第8双鞋
>毛静抢到了第10双鞋
>向凌云抢到了第9双鞋
>向凌云抢到了第5双鞋
>毛静抢到了第6双鞋
>李绍乐抢到了第7双鞋
>毛静抢到了第4双鞋
>向凌云抢到了第4双鞋
>李绍乐抢到了第4双鞋
>毛静抢到了第2双鞋
>李绍乐抢到了第3双鞋
>向凌云抢到了第1双鞋
>李绍乐抢到了第0双鞋
>毛静抢到了第0双鞋
>
>Process finished with exit code 0
>
>发现问题了吗？
>
>鞋子按理来说不会出现毛静抢到了第4双，向凌云，李绍乐还在抢第四双 ，而且还有人抢到了第0双，明明条件就是nikeShotAmount > 0 
>
>这时候就对出了锁的概念，也就是**Synchronize**



>Synchronize代码块
>
>```java
>public class NikeThread implements Runnable {
>    private int nikeShotAmount = 10;
>    Object lock = new Object();
>
>    @Override
>    public void run() {
>        synchronized (lock) {
>            while (nikeShotAmount > 0) {
>                try {
>                    Thread.sleep(500);
>                } catch (InterruptedException e) {
>                    e.printStackTrace();
>                }
>                System.out.println(Thread.currentThread().getName() + "抢到了第" + (nikeShotAmount--) + "双鞋");
>            }
>        }
>    }
>}
>```
>
>运行结果
>
>李绍乐抢到了第10双鞋
>李绍乐抢到了第9双鞋
>李绍乐抢到了第8双鞋
>李绍乐抢到了第7双鞋
>李绍乐抢到了第6双鞋
>李绍乐抢到了第5双鞋
>李绍乐抢到了第4双鞋
>李绍乐抢到了第3双鞋
>李绍乐抢到了第2双鞋
>李绍乐抢到了第1双鞋
>
>Process finished with exit code 0
>
>还是发下了问题，为什么只是一个人抢鞋呢？用synchronize出现了啥问题？
>




>Synchronize同步方法
>
>```java
>public class NikeThread implements Runnable {
>    private int nikeShotAmount = 10;
>    Object lock = new Object();
>
>    @Override
>    public void run() {
>        SynchronizeMethod();
>    }
>    public synchronized void SynchronizeMethod() {
>        while (nikeShotAmount > 0) {
>            try {
>                Thread.sleep(500);
>            } catch (InterruptedException e) {
>                e.printStackTrace();
>            }
>            System.out.println(Thread.currentThread().getName() + "抢到了第" + (nikeShotAmount--) + "双鞋");
>        }
>    }
>}
>```
>结果还是会出现同样的问题!
>相比较于同步代码块，更推荐用同步方法，因为同步方法模块化，便于维护
>

