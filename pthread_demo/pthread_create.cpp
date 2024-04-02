#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void *callback(void * arg){
    int num = *(int *)arg;//需要先将void* 转化为int* 然后再解引用
    while(num--){
        sleep(1);
        printf("child_pthread : %d\n", num);
    }
    return NULL;
}

int main(){
    pthread_t pid;
    int num = 999;
    int ret = pthread_create(&pid, NULL, callback, (void *)&num);//创建一个子线程
    if (ret != 0){      //返回值非0，返回错误信息
        char *errstr = strerror(ret);
        printf("error: %s\n",errstr);
    }

    for(int i = 999; i > 0; i++) {
        sleep(10);       //防止子线程没时间抢占cpu运行
        printf("main_pthread : %d\n", i);
    }
    return 0;//相当于 exit(0) 进程结束
}
