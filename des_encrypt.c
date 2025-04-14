#include <stdio.h>
#include <string.h>
#include <openssl/des.h>
#include <stdlib.h>
#define key_size 8
#define maxn 1000

int main()
{
    unsigned char key[key_size] = "banichka";
    unsigned char input[maxn];
    fgets(input,maxn,stdin);

    input[strcspn(input, "\n")] = '\0';
    unsigned int input_lenght = strlen(input);

    int padding_lenght = ((input_lenght + 7)/8) * 8;
    unsigned char padded_input[padding_lenght];
    unsigned char output[padding_lenght];

    memcpy(padded_input,input, input_lenght);
    //PKCS55 padding
    memset (padded_input + input_lenght, 
            padding_lenght - input_lenght,
            padding_lenght - input_lenght
    );

    DES_key_schedule key_schedule;
    DES_set_key((DES_cblock*) key, &key_schedule);
    for(int i = 0; i < padding_lenght; i +=8)
    {
        DES_ecb_encrypt((DES_cblock*) (padded_input + 1),
        (DES_cblock*) (output + 1),
        &key_schedule,
        DES_ENCRYPT
    );
    }
    for(int i = 0; i < padding_lenght; i++)
    {
        printf("%02x", output[i]);
    }
    return EXIT_SUCCESS;
}