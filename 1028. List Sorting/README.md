- 用cin输入太慢了，最后一个测试例超时，要用scanf
- ios::sync_with_stdio(false)这个同步关闭会提升cin速度，但是副作用是不能混用cin和scanf，否则输出会和理想不一致（太坑了）