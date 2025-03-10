#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
#define Alpha_lenght 26

char* reverse_cezar_cipher(char* cipher, int key)
{
    int length = strlen(cipher);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            plaintext[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }
        //Glavni bukvi
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            plaintext[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(cipher[i] >= '0' && cipher[i] <= '9')
        {
            plaintext[i] = (cipher[i] - '0' - key + 10) % 10 + '0';
        }
        else {
            plaintext[i] = cipher[i]; 
        }
        

    }
    plaintext[length] = '\0';
    return plaintext;
}

int main()
{
    char cipher[MAXN];
    fgets(cipher, MAXN, stdin);
    for (int key = 0; key < Alpha_lenght;key++)
    {
        char*plaintext = reverse_cezar_cipher(cipher, key);
        printf("key %d -> %s\n", key, plaintext);
        free(plaintext);
    }
    return EXIT_SUCCESS;
}
