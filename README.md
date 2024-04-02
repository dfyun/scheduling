# scheduling
for deterministic scheduing
本仓库所做的内容均是基于Linux系统，以确定性调度为导向开发的。 进程是 CPU 分配资源的最小单位，线程是操作系统调度执行的最小单位。 
查看指定进程的 LWP 号：ps –Lf pid
线程之间共享和非共享资源
![alt text](image.png)
 Linux 线程的一个新实现,NPTL(Net POSIX Thread Library)

◼ int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                void (start_routine) (void *), void *arg); // 创建子线程
◼ pthread_t pthread_self(void); //获取当前线程id
◼ int pthread_equal(pthread_t t1, pthread_t t2); //比较两线程id是否相等
◼ void pthread_exit(void *retval);//退出当前线程
◼ int pthread_join(pthread_t thread, void **retval);//连接已终止的子线程回收资源
◼ int pthread_detach(pthread_t thread); //分离线程，进程结束时系统回收其资源
◼ int pthread_cancel(pthread_t thread); //当线程执行到取消点时终止线程