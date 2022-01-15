<h2>join</h2>

>线程的插队
>
>```java
>public class Main {
>
>    public static void main(String[] args) {
>        MyThread myThread = new MyThread();
>        Thread thread = new Thread(myThread);
>        thread.start();
>        //线程插队
>        for (int i = 0; i < 8; i++) {
>            System.out.println(Thread.currentThread().getName());
>            if (i == 5) {
>                try{
>                    thread.join();
>                }catch (InterruptedException e) {
>                    e.printStackTrace();
>                }
>            }
>        }
>    }
>}
>```
>
>```java
>public class MyThread implements Runnable{
>    @Override
>    public void run() {
>        for (int i = 0; i < 3; i++) {
>            System.out.println(Thread.currentThread().getName());
>        }
>    }
>}
>```