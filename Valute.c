#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void minuscola (char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    float importo, risultato;
    char valuta_origine[20], valuta_destinazione[20];
    
    float tassi_di_cambio[4][4] = {
        {1.0, 0.85, 0.75, 110.5}, // EUR to EUR, USD, GBP, JPY
        {1.18, 1.0, 0.88, 130.0}, // USD to EUR, USD, GBP, JPY
        {1.33, 1.14, 1.0, 148.0}, // GBP to EUR, USD, GBP, JPY
        {0.009, 0.0077, 0.0068, 1.0} // JPY to EUR, USD, GBP, JPY
    };
    
    // Chiedi l'importo
    printf("Inserisci l'importo da convertire: ");
    scanf("%f", &importo);

    // Chiedi la valuta di origine
    int origine;
    while (1) {
        printf("Inserisci la valuta di origine (Euro, Dollaro USA, Sterlina, Yen): ");
        scanf("%s", valuta_origine);
        minuscola(valuta_origine); // Converte tutto in minuscolo per la comparazione

        if (strcmp(valuta_origine, "euro") == 0) {
            origine = 0;
            break;
        } else if (strcmp(valuta_origine, "dollaro") == 0) {
            origine = 1;
            break;
        } else if (strcmp(valuta_origine, "sterlina") == 0) {
            origine = 2;
            break;
        } else if (strcmp(valuta_origine, "yen") == 0) {
            origine = 3;
            break;
        } else {
            printf("Valuta di origine non valida. Riprova.\n");
        }
    }

    // Chiedi la valuta di destinazione
    int destinazione;
    while (1) {
        printf("Inserisci la valuta di destinazione (Euro, Dollaro USA, Sterlina, Yen): ");
        scanf("%s", valuta_destinazione);
        minuscola(valuta_destinazione); // Converte tutto in minuscolo per la comparazione

        if (strcmp(valuta_destinazione, "euro") == 0) {
            destinazione = 0;
            break;
        } else if (strcmp(valuta_destinazione, "dollaro") == 0) {
            destinazione = 1;
            break;
        } else if (strcmp(valuta_destinazione, "sterlina") == 0) {
            destinazione = 2;
            break;
        } else if (strcmp(valuta_destinazione, "yen") == 0) {
            destinazione = 3;
            break;
        } else {
            printf("Valuta di destinazione non valida. Riprova.\n");
        }
    }

    // Calcola il risultato della conversione
    risultato = importo * tassi_di_cambio[origine][destinazione];

    // Visualizza la conversione
    printf("Conversione in corso...\n");
    Sleep(2000);
    printf("L'importo convertito è: %.2f ", risultato);

    if (destinazione == 0) printf("Euro\n");
    else if (destinazione == 1) printf("Dollaro USA\n");
    else if (destinazione == 2) printf("Sterlina\n");
    else if (destinazione == 3) printf("Yen\n");

    return 0;
}
