>   很直观的sliding window题目，我们维护一个sum来记录从sliding window的first到last所剩余的油量，同时维护一个count变量的记录这个sliding window
的大小。

>   至于更新，sum+gas[i]-[cost]>0则意味着可以到达下一个节点i+1。
>   first指针的更新，当sum<0时，意味着last指针无法到达下一个节点，此时要更新first指针，同时要更新sum和count，直到找到一个first值使得sum>=0
