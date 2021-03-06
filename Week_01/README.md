学习笔记

## PriorityQueue 源码学习

- Java 中的 PriorityQueue 底层实现为数组。
- 它的有序性由 heap sort 保证。在 offer, poll 这两个方法中均有利用 heap sort 来保证剩余元素的有序性。因此，offer 和 poll 的时间复杂度和 heap sort 为同一数量级。
- 在新增元素时，会基于已有元素个数是否达到队列容量，进行扩容。扩容时使用的是数组的复制操作。

## 学习方法总结

- 在学习算法时，应该总结出整个知识点的体系，系统化地理解数据结构、算法复杂度、常见代码片段以及应用场景。
- 同时，练习算法题也应该用科学高效的方法进行。不能死磕，浪费时间。应该在有效的时间内，获取更多优秀思想，理解并消化。进一步地，坚持不懈地多加练习，达到融会贯通的效果。

