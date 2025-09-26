#include <stdio.h>
#include <string.h>

#define max_length 1000
#define window_size 20
#define hydro_threshold 0.5f
#define max_below 5

float hydro_value(char amino_acid) {
    if (amino_acid == 'A') return 0.616f;
    if (amino_acid == 'C') return 0.680f;
    if (amino_acid == 'D') return 0.028f;
    if (amino_acid == 'E') return 0.043f;
    if (amino_acid == 'F') return 1.000f;
    if (amino_acid == 'G') return 0.501f;
    if (amino_acid == 'H') return 0.165f;
    if (amino_acid == 'I') return 0.943f;
    if (amino_acid == 'K') return 0.283f;
    if (amino_acid == 'L') return 0.943f;
    if (amino_acid == 'M') return 0.738f;
    if (amino_acid == 'N') return 0.236f;
    if (amino_acid == 'P') return 0.711f;
    if (amino_acid == 'Q') return 0.251f;
    if (amino_acid == 'R') return 0.000f;
    if (amino_acid == 'S') return 0.359f;
    if (amino_acid == 'T') return 0.450f;
    if (amino_acid == 'V') return 0.825f;
    if (amino_acid == 'W') return 0.878f;
    if (amino_acid == 'Y') return 0.880f;
    return -1.0f;
}

int main() {
    char protein_sequence[max_length];
    int sequence_length, position, window_index;
    int segment_found;

    printf("Give me a protein sequence:\n");
    scanf("%s", protein_sequence);
    sequence_length = strlen(protein_sequence);

    position = 0;
    segment_found = 0;

    while (position <= sequence_length - window_size) {
        int below_threshold_count = 0;
        for (window_index = position; window_index < position + window_size; window_index++) {
            if (hydro_value(protein_sequence[window_index]) < hydro_threshold)
                below_threshold_count++;
        }

        if (below_threshold_count <= max_below) {
            segment_found = 1;
            printf("Found segment: ");
            for (window_index = position; window_index < position + window_size; window_index++)
                printf("%c", protein_sequence[window_index]);
            printf(" (positions %d-%d)\n", position + 1, position + window_size);
            position += window_size;
        } else {
            position++;
        }
    }

    if (!segment_found)
        printf("No transmembrane segments found.\n");

    return 0;
}

