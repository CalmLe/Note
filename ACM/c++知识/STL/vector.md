# C++ vector<>容器

><h2>底层原理
>Vector是**顺序容器，是一个动态数组**，支持随机存取、插入、删除、查找等操作，在内存中是一块连续的空间。在原有空间不够情况下**自动分配空间**。vector随机存取效率高，但是在vector插入元素，需要移动的数目多，效率低下。(插入操作效率低下！)
>
><h2>使用方法</h2>
>
>**一、begin函数**
>
>函数原型:
>
>iterator begin();
>
>const_iterator begin();
>
>功能：
>
>返回一个当前vector容器中**起始元素的迭代器**。
>
> 
>
>**二、end函数**
>
>函数原型：
>
>iterator end();
>
>const_iterator end();
>
>功能：
>
>返回一个当前vector容器中**末尾元素再下一个元素**的迭代器。
>
> 
>
>**三、front函数**
>
>函数原型：
>
>reference front();
>
>const_reference front();
>
>功能：
>
>返回当前vector容器中**起始元素的引用**。
>
> 
>
>**四、back函数**
>
>函数原型：
>
>reference back();
>
>const_reference back();
>
>功能：
>
>返回当前vector容器中**末尾元素的引用**。
>
>- **可以通过使用 \* vector.begin() 或 \*( vector.end() - 1) 来获得 vector 中第一个或最后一个的值；**
>- **也可以直接使用 vector.front() 、vector.back() 来得到 vector 首尾的值。**
>- vector大小  [  **begin(), end()**  );