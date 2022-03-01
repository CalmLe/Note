# C++ pair

> <h3>底层原理</h3>
>
> 
>
> <h3>总述</h3>
>
> ​     pair是将**2个数据组合成一组数据**，当需要这样的需求时就可以使用pair，如stl中的map就是将key和value放在一起来保存。另一个应用是，当一个函数需要返回2个数据的时候，可以选择pair。 **pair的实现是一个结构体，主要的两个成员变量是first second 因为是使用struct不是class，所以可以直接使用pair的成员变量**。
> 
>
> <h3>用法</h3>
>
> ​    **pair将一对值(T1和T2)组合成一个值**，
>
> ​    这一对值可以具有不同的数据类型（T1和T2），
>
> ​    两个值可以分别**用pair的两个公有函数first和second访问**。
>
> ```c++
> //可以用typedef 避免繁琐的书写
> typedef pair<int, int> PII
> //pair的使用
> vetor<PII>vec;
> 
> for (auto it : vec) {
>     it.first;
>     it.second;
> }
> ```
>
>  还可以利用**make_pair**创建新的pair对象
>
> ```c++
> //可以用typedef 避免繁琐的书写
> typedef pair<int, int> PII
> PII it = make_pair(1, 2);

