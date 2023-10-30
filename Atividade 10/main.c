#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_table_init();

   
    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    hash_table_put("chave3", "valor3");

    
    printf("Valor da chave1: %s\n", hash_table_get("chave1"));
    printf("Valor da chave2: %s\n", hash_table_get("chave2"));

    
    printf("chave1 existe na tabela: %d\n", hash_table_contains("chave1"));
    printf("chave4 existe na tabela: %d\n", hash_table_contains("chave4"));

    
    hash_table_remove("chave2");
    printf("Valor da chave2 após remoção: %s\n", hash_table_get("chave2"));

    
    hash_table_cleanup();

    return 0;
}