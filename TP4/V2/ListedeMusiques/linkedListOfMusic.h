#ifndef LINKEDLISTOFMUSIC_H
#define LINKEDLISTOFMUSIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Music {
    char name[100];
    char artist[100];
    char album[100];
    char genre[50];
    int discNumber;
    int trackNumber;
    int year;
    struct Music *next;
} Music;

// 创建新的音乐节点
Music *createMusic(char *name, char *artist, char *album, char *genre, int discNumber, int trackNumber, int year);

// 打印音乐列表
void printMusicList(Music *head);

// 读取CSV文件并创建音乐链表
Music *readMusicCSV(const char *filename);

// 按年份对音乐列表进行排序
void sortMusicByYear(Music **head);

// 释放音乐链表
void freeMusicList(Music *head);

#endif
