#include <stdio.h>
#include <stdlib.h>

// 1. Desain Gerbong
typedef struct NODE {
    int info;            // Tempat simpan data
    struct NODE *next;   // Tempat simpan alamat gerbong selanjutnya
} node;

// 2. Bikin Nama Panggilan untuk "Pointer ke Node"
typedef node *address;

// 3. Bikin Wadah/Manajer List
typedef struct {
    address first;       // Pintu masuk utama (Head)
} List;

void InsertFirst(List *L, int nilai) {
    address P; 
    
    // STEP 1: Alokasi (Beli gerbong baru dari pabrik memori)
    P = (address)malloc(sizeof(node));
    
    if (P != NULL) { // Cek apakah memori penuh atau tidak
        
        // STEP 2: Isi data ke gerbong baru
        P->info = nilai;
        
        // STEP 3: Sambungkan pengait gerbong baru ke gerbong yang sudah ada
        // (P megang apa yang lagi dipegang tangan si L)
        P->next = L->first;
        
        // STEP 4: Pindahkan tangan L untuk megang gerbong baru tadi
        L->first = P;
    }
}

void Display(List L) {
    address P;       // Senter bantu
    P = L.first;     // Mulai dari yang paling kiri (depan)

    if (P == NULL) {
        printf("List kosong, Ky!\n");
    } else {
        while (P != NULL) {      // Selama belum mentok ke NULL
            printf("%d -> ", P->info);
            P = P->next;         // Geser ke gerbong selanjutnya
        }
        printf("NULL\n");        // Tanda ujung rel
    }
}

int main() {
    List L;              // Siapkan manajer bernama L
    L.first = NULL;      // Tandai kalau list masih kosong (NULL)

    InsertFirst(&L, 1);
    InsertFirst(&L, 2);
    InsertFirst(&L, 3);
    InsertFirst(&L, 4);
    InsertFirst(&L, 5);

    Display(L);
    return 0;
}
