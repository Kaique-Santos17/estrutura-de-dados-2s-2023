#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100


typedef struct {
    char* chave;
    char* dado;
} HashEntry;


HashEntry* hash_table[TABLE_SIZE];


unsigned int hash(const char* chave) {
    unsigned int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash = (hash * 31) + chave[i];
    }
    return hash % TABLE_SIZE;
}

void hash_table_init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    if (hash_table[index] != NULL && strcmp(hash_table[index]->chave, chave) == 0) {
        return hash_table[index]->dado;
    }
    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    if (hash_table[index] != NULL) {
        
        free(hash_table[index]->dado);
        hash_table[index]->dado = strdup(dado);
    } else {
       
        HashEntry* entry = malloc(sizeof(HashEntry));
        entry->chave = strdup(chave);
        entry->dado = strdup(dado);
        hash_table[index] = entry;
    }
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    return (hash_table[index] != NULL && strcmp(hash_table[index]->chave, chave) == 0);
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    if (hash_table[index] != NULL) {
        free(hash_table[index]->chave);
        free(hash_table[index]->dado);
        free(hash_table[index]);
        hash_table[index] = NULL;
    }
}

void hash_table_cleanup() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            free(hash_table[i]->chave);
            free(hash_table[i]->dado);
            free(hash_table[i]);
        }
    }
}