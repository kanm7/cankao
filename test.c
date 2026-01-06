#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char buf[10];
    // 从标准输入读取数据
    if (read(0, buf, 10) < 4) return 0;

    // 只有变异出 "AFL!" 这四个特定字符，才会触发 crash
    if (buf[0] == 'A') {
        if (buf[1] == 'F') {
            if (buf[2] == 'L') {
                if (buf[3] == '!') {
                    printf("Crash triggered!\n");
                    abort(); // 模拟程序崩溃
                }
            }
        }
    }
    return 0;
}