#include "linkedListOfMusic.h"

int main() {
    // 读取CSV文件
    Music *musicList = readMusicCSV("music.csv");

    // 打印读取到的音乐列表
    printf("读取到的音乐列表:\n");
    printMusicList(musicList);

    // 按年份排序
    printf("\n按年份排序后的音乐列表:\n");
    sortMusicByYear(&musicList);
    printMusicList(musicList);

    // 释放内存
    freeMusicList(musicList);

    return 0;
}
