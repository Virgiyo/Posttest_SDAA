#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char namaPelanggan[50];
    int jumlahToken;
    float hargaToken;
    struct Node *next;
} Node;

void pushTopUp(Node **head); 
void popTopUp(Node **head); 
void enqueueTopUp(Node **head, Node **tail); 
void dequeueTopUp(Node **head, Node **tail); 
void tampilkanTopUp(Node *head);
void freeList(Node **head);      

int main() {
    Node *headNode = NULL;
    Node *tailNode = NULL; 
    int menuOption;

    do {
        printf("\n--- Menu Top-Up Token Game ---\n");
        printf("1. Push Top up (Stack)\n");
        printf("2. Pop Top up (Stack)\n");
        printf("3. Enqueue Top up (Queue)\n");
        printf("4. Dequeue Top up (Queue)\n");
        printf("5. Tampilkan Data Top-Up\n");
        printf("6. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &menuOption);

        switch (menuOption) {
            case 1:
                pushTopUp(&headNode);
                break;
            case 2:
                popTopUp(&headNode);
                break;
            case 3:
                enqueueTopUp(&headNode, &tailNode);
                break;
            case 4:
                dequeueTopUp(&headNode, &tailNode);
                break;
            case 5:
                tampilkanTopUp(headNode);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (menuOption != 6);

    freeList(&headNode);
    return 0;
}

void pushTopUp(Node **head) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory tidak cukup!\n");
        return;
    }

    printf("Masukkan nama pelanggan: ");
    scanf("%s", newNode->namaPelanggan);
    printf("Masukkan jumlah token: ");
    scanf("%d", &newNode->jumlahToken);
    printf("Masukkan harga token: ");
    scanf("%f", &newNode->hargaToken);

    newNode->next = *head; 
    *head = newNode;
    printf("Data top-up berhasil ditambahkan (Stack - Push)!\n");
}

void popTopUp(Node **head) {
    if (*head == NULL) {
        printf("Stack kosong, tidak ada data untuk dihapus.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Data top-up berhasil dihapus (Stack - Pop)!\n");
}

void enqueueTopUp(Node **head, Node **tail) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory tidak cukup!\n");
        return;
    }

    printf("Masukkan nama pelanggan: ");
    scanf("%s", newNode->namaPelanggan);
    printf("Masukkan jumlah token: ");
    scanf("%d", &newNode->jumlahToken);
    printf("Masukkan harga token: ");
    scanf("%f", &newNode->hargaToken);
    newNode->next = NULL;

    if (*tail == NULL) {  
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("Data top-up berhasil ditambahkan (Queue - Enqueue)!\n");
}

void dequeueTopUp(Node **head, Node **tail) {
    if (*head == NULL) {
        printf("Queue kosong, tidak ada data untuk dihapus.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);

    if (*head == NULL) {
        *tail = NULL; 
    }

    printf("Data top-up berhasil dihapus (Queue - Dequeue)!\n");
}

void tampilkanTopUp(Node *head) {
    if (head == NULL) {
        printf("Tidak ada data top-up.\n");
        return;
    }

    Node *currentNode = head;
    int dataCount = 1;
    while (currentNode != NULL) {
        printf("\nData Top-Up ke-%d\n", dataCount++);
        printf("Nama Pelanggan: %s\n", currentNode->namaPelanggan);
        printf("Jumlah Token: %d\n", currentNode->jumlahToken);
        printf("Harga Token: %.2f\n", currentNode->hargaToken);
        currentNode = currentNode->next;
    }
}

void freeList(Node **head) {
    Node *currentNode = *head;
    Node *nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    *head = NULL;
}
