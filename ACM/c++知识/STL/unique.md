# C++ unique()去重

><h2>底层原理</h2>
>> 代码模拟
>> ```c++
>> template <class ForwardIterator>
>>   ForwardIterator unique (ForwardIterator first, ForwardIterator last)
>> {
>>   if (first==last) return last;
>> 
>>   ForwardIterator result = first;
>>   while (++first != last)
>>   {
>>     if (!(*result == *first))  // or: if (!pred(*result,*first)) for version (2)
>>       *(++result)=*first;
>>   }
>>   return ++result;
>> }
>
>>   
>>
>>   ```c++
>>   vector<int>::iterator unique(vector<int>&a) {
>>   //i用来遍历所有数, j用来指示存到了第几个元素了
>>   	int j = 0;
>>       for (int i = 0; i < a.size(); i++) {
>>         	if(!i || a[i - 1] != a[i]) a[j++] = a[i];
>>       }
>>   //a.begin()是迭代器(iterator)类型不能单独返回j否则是error
>>   return a.begin() + j;
>>   }
>>   ```
>
>
>
><h2>总述</h2>
>
>> unique函数的函数原型如下：
>
>> 1.只有两个参数，且参数类型都是迭代器：
>> ```c++
>> iterator unique(iterator it_1,iterator it_2);
>> ```
>> 2.有三个参数，且前两个参数类型为迭代器，最后一个参数类型可以看作是bool类型：
>
>> ```c++
>> iterator unique(iterator it_1,iterator it_2,bool MyFunc);
>> ```
>
><h2>使用方法</h2>
>
>1. 这里的第三个参数表示的是**自定义元素是否相等**。也就是说通过自定义两个元素相等的规则，来对容器中元素进行去重。这里的第三个参数与STL中sort函数的第三个参数功能类似
>2. unique函数通常和erase函数一起使用，来达到删除重复元素的目的。(注：此处的删除是真正的删除，即从容器中去除重复的元素，**容器的长度也发生了变换**；而单纯的使用unique函数的话，**容器的长度并没有发生变化**，只是元素的位置发生了变化)
>
>
>
><h2>注意事项</h2>
>
>1.有很多文章说的是，unique去重的过程是将重复的元素移到容器的后面去，实际上这种说法并不正确，**应该是把不重复的元素移到前面来**。
>
>2.一定不要忘记的是，unique函数在使用前**需要对容器中的元素进行排序**(当然不是必须的，但我们绝大数情况下需要这么做)，由于本例中的元素已经是排好序的，所以此处我没排序，但实际使用中不要忘记。
>
>