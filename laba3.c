#include <stdio.h>
#include <stdint.h>
#include "mylib.h"
#pragma pack(push, 1)
typedef struct {
    uint32_t timestamp_ms;
    float lat_rad;
    float lon_rad;
    float alt_m;
} record_t;
#pragma pack(pop)
int main() {
    FILE *fin = fopen("flight_data10.bin", "rb");
    FILE *fout = fopen("wwwwwwwwww.txt", "w");
    if (!fin || !fout) {
        printf("File open error\n");
        return 1;
    }
    Node* list = NULL;
    record_t r;
    // Файл->список
    while (fread(&r, sizeof(record_t), 1, fin) == 1) {
        appendList(&list, r.timestamp_ms, r.lat_rad, r.lon_rad, r.alt_m);
    }
    if (!list) {
        printf("No data\n");
        return 1;
    }
    // Дерево с высотой
    TreeNode* root = NULL;
    Node* cur = list;
    while (cur) {
        root = insertTree(root, cur->alt);
        cur = cur->next;
    }

    float min_h = findMin(root);
    float max_h = findMax(root);
    // Статистика
    int count = 0;
    uint32_t start = list->time;
    uint32_t end = list->time;
    cur = list;
    while (cur) {
        count++;
        end = cur->time;
        cur = cur->next;
    }
    uint32_t duration = end - start;
    // Вывод
    printf("Number of points: %d\n", count);
    printf("Flight duration: %u ms\n", duration);
    printf("Max altitude: %.2f m\n", max_h);
    printf("Min altitude: %.2f m\n", min_h);

    fprintf(fout, "Number of points: %d\n", count);
    fprintf(fout, "Flight duration: %u ms\n", duration);
    fprintf(fout, "Max altitude: %.2f m\n", max_h);
    fprintf(fout, "Min altitude: %.2f m\n", min_h);
    fclose(fin);
    fclose(fout);
    freeList(list);
    freeTree(root);
    return 0;
}
