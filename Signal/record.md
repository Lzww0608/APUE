信号是软件中断，用于通知进程发生了异步事件。

信号的分类：
1. 可靠信号和不可靠信号
2. 实时信号和非实时信号

可靠信号和不可靠信号：
1. 可靠信号：信号不会丢失，会存储在信号处理函数中，直到处理完毕。
2. 不可靠信号：信号可能会丢失，不会存储在信号处理函数中，处理完毕后信号会自动消失。

实时信号和非实时信号：
1. 实时信号：信号会按照发送的顺序依次处理。
2. 非实时信号：信号会按照发送的顺序依次处理。

信号的处理：
1. 忽略信号： `SIGKILL` 和 `SIGSTOP` 不能被忽略。它们向内核提供了使进程终止和停止的可靠方法。
2. 捕捉信号： 通知内核在某种信号发生时，调用一个用户函数。
3. 执行系统默认动作： 系统默认动作是终止进程。


