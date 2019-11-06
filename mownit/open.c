#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *katalog;
    katalog = (char *)malloc(100*sizeof(char));
    char *plik =(char *) malloc(100* sizeof(char));
    scanf(katalog);
    scanf(plik);
    strcat("find",katalog," -name " ,plik,"zad1");
    
    system("find" + katalog +" -name " + plik > "zad1");

    FILE *f = fopen("zad1", "r");    // otwiera plik do odczytu (musi istniec)
    if (f == NULL)
    {
        perror("Nie udalo sie otworzyc pliku notatki.txt");
        return 1;
    }
    puts("Plik otwarty pomyslnie!");
    fclose(f);
    return 0;

    
}