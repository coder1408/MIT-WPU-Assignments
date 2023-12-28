#include <stdio.h>
#include <stdlib.h>

void printRegister(int register_size, int page_register[10]) {
    printf("Register: ");
    for (int j = 0; j < register_size; j++) {
        if (page_register[j] != -1) {
            printf("%d ", page_register[j]);
        } else {
            printf("- ");
        }
    }
}

void FIFO(int register_size, int ref_str_size, int page_register[10], int ref_str[20], int page[20]) {
    int page_faults = 0, page_hits = 0;
    int index = 0;
    printf("\n");
    for (int i = 0; i < ref_str_size; i++) {
        int flag_ref = 0, flag_replace = 0;
        for (int j = 0; j < register_size; j++) {
            if (ref_str[i] == page_register[j]) {
                flag_ref = 1;
                page[i] = 0;
                page_hits++;
                break;
            }
        }
        if (flag_ref == 0) {
            for (int j = 0; j < register_size; j++) {
                if (page_register[j] == -1) {
                    page_register[j] = ref_str[i];
                    flag_replace = 1;
                    break;
                }
            }
            if (flag_replace == 0) {
                page_register[index] = ref_str[i];
                index = (index + 1) % register_size;
            }
            page[i] = 1;
            page_faults++;
        }
        printf("%d\t", ref_str[i]);
        printRegister(register_size, page_register);
        printf("\n");
    }
    printf("Number of page hits: %d\n", page_hits);
    printf("Number of page faults: %d\n", page_faults);
}

void LRU(int register_size, int ref_str_size, int page_register[10], int ref_str[20], int page[20]) {
    int recent[20];
    int page_faults = 0, page_hits = 0;
    printf("\n");
    for (int i = 0; i < ref_str_size; i++) {
        int flag_ref = 0, flag_replace = 0;
        for (int j = 0; j < register_size; j++) {
            if (ref_str[i] == page_register[j]) {
                flag_ref = 1;
                recent[ref_str[i]] = i;
                page[i] = 0;
                page_hits++;
                break;
            }
        }
        if (flag_ref == 0) {
            for (int j = 0; j < register_size; j++) {
                if (page_register[j] == -1) {
                    page_register[j] = ref_str[i];
                    flag_replace = 1;
                    recent[ref_str[i]] = i;
                    break;
                }
            }
            if (flag_replace == 0) {
                int min = recent[ref_str[page_register[0]]];
                int min_reg = 0;
                for (int k = 1; k < register_size; k++) {
                    if (recent[page_register[k]] < min) {
                        min = recent[ref_str[page_register[k]]];
                        min_reg = k;
                    }
                }
                page_register[min_reg] = ref_str[i];
                recent[ref_str[i]] = i;
            }
            page[i] = 1;
            page_faults++;
        }
        printf("%d\t", ref_str[i]);
        printRegister(register_size, page_register);
        printf("\n");
    }
    printf("Number of page hits: %d\n", page_hits);
    printf("Number of page faults: %d\n", page_faults);
}

int main() {
    int register_size, ref_str_size, choice;
    int page_register[10], ref_str[20], page[20];

    printf("Enter size of register: ");
    scanf("%d", &register_size);
    printf("Enter size of reference string: ");
    scanf("%d", &ref_str_size);

    printf("Enter elements of string: ");
    for (int i = 0; i < ref_str_size; i++) {
        scanf("%d", &ref_str[i]);
    }

    for (int i = 0; i < register_size; i++) {
        page_register[i] = -1;
    }

    printf("Choose Page Replacement Algorithm:\n1. FIFO \n2. LRU \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            FIFO(register_size, ref_str_size, page_register, ref_str, page);
            break;
        }
        case 2: {
            LRU(register_size, ref_str_size, page_register, ref_str, page);
            break;
        }
        default:
            printf("Invalid Choice");
    }

    return 0;
}