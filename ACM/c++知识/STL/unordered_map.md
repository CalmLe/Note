# C++ unordered_map容器

><h2>底层原理</h2>
>**哈希表**
>
>
>
><h2>特性</h2>
>
>**key无序，key不可以重复，key不可以修改**
>
>
>
><h2>复杂度</h2>
>
>查询效率 : $O(1)$
>
>增删效率 : $O(1)$
>
>
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
>
>
>
>**五、push_back()**
>
>功能:
>
>向末尾添加一个数，时间复杂度为O(1);

