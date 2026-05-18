#include <stdio.h>
#include <stdlib.h>

// Struktur node pembungkus yang menyimpan pointer ke int
typedef struct Node {
    int* ptr_ke_data;       // Mencatat ALAMAT memori dari variabel int asli
    struct Node* next_node; // Mencatat alamat node berikutnya
} Node;

// Fungsi untuk membuat node baru dan menghubungkannya ke list
Node* hubungkanVariabel(Node* head_saat_ini, int* alamat_variabel_asli) {
    Node* node_baru = (Node*) malloc(sizeof(Node));
    
    // Node baru hanya mencatat alamat dari int tersebut, bukan menyalin nilainya
    node_baru->ptr_ke_data = alamat_variabel_asli;
    node_baru->next_node = head_saat_ini;
    
    return node_baru;
}

int main() {
    // 1. Tiga variabel int mandiri yang sudah ada di memori Stack
    int nilai_A = 2;
    int nilai_B = 3;
    int nilai_C = 4;

    // 2. Membuat Linked List kosong
    Node* head_utama = NULL;
    
    // Kita hubungkan satu per satu menggunakan operator address-of (&)
    head_utama = hubungkanVariabel(head_utama, &nilai_C); 
    head_utama = hubungkanVariabel(head_utama, &nilai_B); 
    head_utama = hubungkanVariabel(head_utama, &nilai_A); 

    // 3. Menampilkan isi Linked List untuk pembuktian
    printf("--- ISI LINKED LIST BANSER ---\n");
    Node* penjelajah = head_utama;
    while (penjelajah != NULL) {
        // Menggunakan tanda bintang (*) untuk mengambil nilai data dari alamatnya
        printf("Nilai: %d | Diambil dari Alamat RAM: %p\n", 
               *(penjelajah->ptr_ke_data), 
               (void*)penjelajah->ptr_ke_data);
               
        penjelajah = penjelajah->next_node;
    }

    // 4. Mencetak alamat asli variabel di Stack untuk dicocokkan
    printf("\n--- ALAMAT ASLI VARIABEL DI RAM ---\n");
    printf("Alamat asli nilai_A: %p\n", (void*)&nilai_A);
    printf("Alamat asli nilai_B: %p\n", (void*)&nilai_B);
    printf("Alamat asli nilai_C: %p\n", (void*)&nilai_C);

    // 5. Membersihkan memori node pembungkus di Heap
    while (head_utama != NULL) {
        Node* temp = head_utama;
        head_utama = head_utama->next_node;
        free(temp);
    }

    return 0;
}