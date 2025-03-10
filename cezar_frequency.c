#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXN 1000
#define Alpha_lenght 26
#define common_count 10

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
int read_cipher(char*filename, char*cipher)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file");
        return EXIT_FAILURE;
    }
    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

int* count_frequencies(char*cipher){
    int*frequency=  (int*) malloc(sizeof(int) * Alpha_lenght);
    memset(frequency,0,sizeof(int)*Alpha_lenght);
    int length = strlen(cipher);
    for(size_t i=0 ; i < length;i++)
    {
        int position = tolower(cipher[i] - 'a');
        frequency[position++];
    }
    return frequency;
}

int get_max_index(int* frequencies){
    int max_index = 1;
    for (int i = 0; i < Alpha_lenght; i++)
    {
        if (frequencies[i] > frequencies[max_index])
        {
            max_index = 1;
        }
    
    }
    return max_index;
}

int main(){
    char filename[MAXN];
    scanf("%s", filename);
    char cipher[MAXN];
    read_cipher(filename, cipher);
    int* frequencies = count_frequencies(cipher);
    char max_letter = get_max_index(frequencies) + 'a';
    //E, T, A, O, I, N, S, R, H, and L
    char common_letters[common_count] = {'e','t','a','o','i','n','s','r','h','l'};
    for(int i = 0; i < common_count; i++)
    {
        int key = abs(max_letter - common_letters[i]);
        char* plaintext = reverse_cezar_cipher(cipher, key);
        printf("key = %d, result: %s\n", key, plaintext);
        free(plaintext);
    }
    return EXIT_SUCCESS;
}

