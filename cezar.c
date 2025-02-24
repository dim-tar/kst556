#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100

 /*
                da          da
 1)da raboti s malki, golemi bukvi, cifri, a raztoqniq i specialni simvoli da NE se kodirat
 
 2)da se poddyrja vyvejdane na raztoqniq
 
 3)da se zapisva v file polucheniq shifer
 
 4)check if file exists and if it doesn't create one
 */
char* cezar_cipher(char* str, int key)
{
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char)*(length + 1));
    for(int i = 0; i < length; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            cipher[i] = (str[i] - 'a' + key) % 26 + 'a';
        }
        //Glavni bukvi
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            cipher[i] = (str[i] - 'A' + key) % 26 + 'A';
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            cipher[i] = (str[i] - '0' + key) % 10 + '0';
        }
        else if(str[i] == ' '){
            cipher[i] = ' ';
        }

    }
    cipher [length] = '\0';
    return cipher;
}


int main()
{
    char str[MAXN];
    scanf ("%[^\n]", str);
    int key;
    scanf("%d", &key);
    char* cipher = cezar_cipher(str,key);
    printf("%s", cipher);
    FILE *file = fopen("text.txt", "w");
    if(file== NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fprintf(file, "%s\n", cipher);
    fclose(file);
    printf("\n");
    return EXIT_SUCCESS;
}