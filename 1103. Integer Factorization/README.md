回溯

一开始测试点5一直过不了，网上找了找发现是pow()很耗时间
查看C++11中pow的描述:
```
     double pow (double base     , double exponent);
      float pow (float base      , float exponent);
long double pow (long double base, long double exponent);
     double pow (Type1 base      , Type2 exponent);        // additional overloads
```
这题的回溯过程中只涉及到pow(int, int)，因此自己重新写了一个针对int的pow()函数，就过了
