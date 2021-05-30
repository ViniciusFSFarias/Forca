#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PAISES 4
#define MAX_STRING 32

int main( ) {
    srand( time( NULL ) );
    char pais[ PAISES ][ MAX_STRING ] = { "brasil", "alemanha", "belgica", "espanha" };
    int sorteado = rand( ) % PAISES;
    size_t length = strlen( pais[ sorteado ] );
    char secreto[ length ];
    memset( secreto, '?', length );
    *( secreto + length ) = '\0';
    int i = 0, corretas = 0, tentativas = 0;
    printf( "%s\n", secreto );
    char alfabeto[ 26 ];
    memset( alfabeto, 0, 26 );
    while ( corretas < length ) {
        printf( "digite uma letra: " );
        char c;
        scanf( " %c", &c );
        c = 'A' <= c && c <= 'Z' ? c - 'A' + 'a' : c;
        if ( 'a' <= c && c <= 'z' ) {
            if ( !alfabeto[ c - 'a' ] ) {
                alfabeto[ c - 'a' ] = c;
                for ( i = 0; i < length; i++ ) {
                    if ( c == pais[ sorteado ][ i ] ) {
                        secreto[ i ] = c;
                        corretas++;
                    }
                }
                printf( "%s\n", secreto );
                tentativas++;
            }
            else {
                printf( "letra repetida\n" );
            }
        }
        else {
            printf( "caractere invalido\n" );
        }
    }
    printf( "tentativas = %d\n", tentativas );
    return 0;
}
