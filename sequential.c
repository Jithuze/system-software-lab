
#include <stdio.h>
#include <stdlib.h>

struct File {
    char name[20];
    int size;
    int startBlock;
};

void allocateFile(struct File files[], int n) {
    int currentBlock = 0;

    for (int i = 0; i < n; ++i) {
        files[i].startBlock = currentBlock;
        currentBlock += files[i].size;
    }
}

void displayFiles(struct File files[], int n) {
    printf("File\tSize\tStart Block\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\t%d\t%d\n", files[i].name, files[i].size, files[i].startBlock);
    }
}

int main() {
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);

    struct File files[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter file name: ");
        scanf("%s", files[i].name);
        printf("Enter file size: ");
        scanf("%d", &files[i].size);
    }

    allocateFile(files, n);

    printf("\nFile Allocation Table:\n");
    displayFiles(files, n);

    return 0;
}
