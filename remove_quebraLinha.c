#include <string.h>
void removaQuebraLinha(char *texto)
{
    int ln = strlen(texto) - 1;
    if (*texto && texto[ln] == '\n')
    {
        texto[ln] = '\0';
    }
}
