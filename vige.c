#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if (argc != 2) // reject argc(!=2)
    {
        printf("type only a single alphanumeric encryption key as command-line argument\n");
        return 1;
    }
    char* key = argv[1];  // store key
    int kleng = strlen(key);  // store key length
    for(int a = 0; a < kleng; a++) // check every char of argv[1] is alpha, turn it to uppercase and store it in key
    {
        if(isalpha(key[a]) == false)  //  reject any non a/n key
        {
            printf("your key needs to be alphanumeric\n");
            return 1;
        }
        else
        {
            key[a] = toupper(key[a]);  //  convert key to 65-90 ASCII char's
        }
    }
    printf("insert text: \n");
    char* text = get_string();  //  get plain text
    
    int tleng = strlen(text);  //  get length of plain text
    
    int ptxt = 0;  //  initialize an int to be used in the next lines (for plain char, cyphered char and key char) to store, add and print 
    int ctxt = 0;
    int kint = 0;
    int c = 0;  //  initialize an int to be used as a separate counter for the key
    for(int b = 0; b < tleng; b++)
    {
        if(isalpha(text[b]))  //  treat a/n char's of plain text
        {
            if(isupper(text[b]))  //  upper and lowercase chars need to be elaborated differently
            {
                ptxt = (int) text[b] - 65;  //  set int ptxt as a 0-25 equivalent of char text[b]
                kint = (int) key[c % kleng] - 65;  //  set kint as a 0-25 equivalent of char key[c % kleng] to esure rotation among key characters
                ctxt = (ptxt + kint) % 26 + 65;  //  set ctxt as sum of the two, make sure it's still a 0-25 value and convert it it a 65-90 ASCII-valid number
            }
            if(islower(text[b]))  //  upper and lowercase chars need to be elaborated differently
            {
                ptxt = (int) text[b] - 97;  //  set int ptxt as a 0-25 equivalent of char text[b]
                kint = (int) key[c % kleng] - 65;  //  set kint as a 0-25 equivalent of char key[c % kleng] to esure rotation among key characters
                ctxt = (ptxt + kint) % 26 + 97;  //  set ctxt as sum of the two, make sure it's still a 0-25 value and convert it it a 65-90 ASCII-valid number
            }
            c++;  //  if the character was a/n, the counter for the key will be set +1
            printf("%c", (char) ctxt);  //  print the resulting cyphered character
            
        }
        else  //  if character was not a/n (as a ' ', a number or a symbol)
        {
            printf("%c", text[b]);  //  then print it as it is
        }
    }
    printf("\n");
}


