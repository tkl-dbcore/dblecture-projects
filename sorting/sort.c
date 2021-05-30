
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>

struct string_array {
    long count;
    char **elems;
};

struct string_array *
read_input_file(const char *input_file){
    FILE *fp = fopen(input_file, "r");
    if (fp == NULL) {
        perror("failed to open input file");
        exit(EXIT_FAILURE);
    }

    struct string_array *array = malloc(sizeof(struct string_array));
    if (array == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    array->count = 0;
    array->elems = NULL;

    /* NOTE: each record is 100 bytes long in Gray Sort */
    char linebuf[1024];
    while(fgets(linebuf, 1024, fp) != NULL) {
        array->count ++;
        array->elems = realloc(array->elems, sizeof(char *) * array->count);
        if (array->elems == NULL) {
            perror("realloc failed");
            exit(EXIT_FAILURE);
        }

        array->elems[array->count - 1] = strdup(linebuf);
    }
    fclose(fp);

    return array;
}

void
delete_array(struct string_array *array) {
    for(long i = 0; i < array->count; i++) {
        free(array->elems[i]);
    }
    free(array->elems);
    free(array);
}

void
write_output_file(const char *output_file, struct string_array *array) {
    FILE *fp = fopen(output_file, "w");
    if (fp == NULL) {
        perror("failed to open output file");
        exit(EXIT_FAILURE);
    }

    for (long i = 0; i < array->count; i++) {
        /* NOTE: each element includes trailing newline (CR LF) */
        fprintf(fp, "%s", array->elems[i]);
    }

    fclose(fp);
}

void
swap(char **a, char **b) {
    char *x;
    x = *b;
    *b = *a;
    *a = x;
}

void
sort(struct string_array *array) {
    /* Bubble Sort algorithm */
    for (long i = 0; i < array->count - 1; i++) {
        bool is_swapped = false;
        for (long j = 1; j < array->count - i; j++) {
            int cmp = strcmp(array->elems[j - 1], array->elems[j]);
            if (cmp > 0) {
                swap(&array->elems[j - 1], &array->elems[j]);
                is_swapped = true;
            }
        }
        if (!is_swapped) {
            /* already sorted. */
            break;
        }
    }
}

int
main(int argc, char **argv) {
    /* get input file name & output file name */
    if (argc != 3) {
        puts("[Usage] ./sort INPUT_FILE OUTPUT_FILE");
        exit(EXIT_FAILURE);
    }
    const char *input_file = argv[1];
    const char *output_file = argv[2];

    /* read input file */
    struct string_array *array = read_input_file(input_file);

    /* sort the array */
    struct timeval t0, t1;
    gettimeofday(&t0, NULL);
    sort(array);
    gettimeofday(&t1, NULL);

    double time = (t1.tv_sec + (double) t1.tv_usec / 1e6) - (t0.tv_sec + (double) t0.tv_usec / 1e6);
    printf("Sorting time: %0.3f seconds\n", time);

    /* write output file */
    write_output_file(output_file, array);

    delete_array(array);

    return 0;
}


