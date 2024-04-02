#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h> //sleep()头文件

void * callback(void * arg) {
    while (1){
    printf("callback thread id : %ld\n", pthread_self());
        sleep(3);
    }
    pthread_exit(NULL);   // 相当于 return NULL; 
} 

void * callback_(void * arg)
{
    while (1){
        printf("callback_ thread id : %ld\n", pthread_self());
        sleep(5);
    }
    return NULL;
}
int main() {  
    pthread_t tid, tid_;
    int ret = pthread_create(&tid, NULL, callback, NULL);// 创建一个子线程
    int ret_ = pthread_create(&tid_, NULL, callback_, NULL);// 创建一个子线程
    if(ret != 0) {
        char * errstr = strerror(ret);
        printf("error : %s\n", errstr);
    }
     if(ret_ != 0) {
        char * errstr = strerror(ret_);
        printf("error : %s\n", errstr);
    }
    // 主线程
    for(int i = 0; i < 3; i++) {
        printf("%d\n", i);
    }

    printf("tid : %ld, tid_ : %ld, main thread id : %ld\n", tid, tid_, pthread_self());

    // 让主线程退出,当主线程退出时，不会影响其他正常运行的线程。
    pthread_exit(NULL);

    printf("main thread exit\n");
	
	//当所有子线程都退出后，主进程结束，系统回收所有资源
    sleep(5);
    return 0;   // exit(0);
}
