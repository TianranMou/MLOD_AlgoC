#include "linkedListOfMusic.h"

// 创建新的音乐节点
Music *createMusic(char *name, char *artist, char *album, char *genre, int discNumber, int trackNumber, int year) {
    Music *newMusic = (Music *)malloc(sizeof(Music));
    if (newMusic == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newMusic->name, name);
    strcpy(newMusic->artist, artist);
    strcpy(newMusic->album, album);
    strcpy(newMusic->genre, genre);
    newMusic->discNumber = discNumber;
    newMusic->trackNumber = trackNumber;
    newMusic->year = year;
    newMusic->next = NULL;
    return newMusic;
}

// 打印音乐列表
void printMusicList(Music *head) {
    Music *current = head;
    printf("Name, Artist, Album, Genre, Disc Number, Track Number, Year\n");
    while (current != NULL) {
        printf("%s, %s, %s, %s, %d, %d, %d\n",
               current->name, current->artist, current->album, current->genre,
               current->discNumber, current->trackNumber, current->year);
        current = current->next;
    }
}

// 读取CSV文件并创建音乐链表
Music *readMusicCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    char line[1024];
    fgets(line, sizeof(line), file); // 跳过标题行

    Music *head = NULL;
    Music *tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *artist = strtok(NULL, ",");
        char *album = strtok(NULL, ",");
        char *genre = strtok(NULL, ",");
        int discNumber = atoi(strtok(NULL, ","));
        int trackNumber = atoi(strtok(NULL, ","));
        int year = atoi(strtok(NULL, ","));

        Music *newMusic = createMusic(name, artist, album, genre, discNumber, trackNumber, year);
        if (head == NULL) {
            head = newMusic;
            tail = head;
        } else {
            tail->next = newMusic;
            tail = newMusic;
        }
    }

    fclose(file);
    return head;
}

void sortMusicByYear(Music **head) {
    if (*head == NULL) {
        return;
    }

    Music *sorted = NULL;
    Music *current = *head;

    while (current != NULL) {
        Music *next = current->next;

        if (sorted == NULL || current->year < sorted->year) {
            // 插入到排序链表的开头
            current->next = sorted;
            sorted = current;
        } else {
            // 找到合适的插入位置
            Music *temp = sorted;
            while (temp->next != NULL && temp->next->year < current->year) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sorted;
}

void freeMusicList(Music *head) {
    Music *current = head;
    Music *next;

    while (current != NULL) {
        next = current->next;  // 保存下一个节点
        free(current);         // 释放当前节点
        current = next;        // 移动到下一个节点
    }
}
