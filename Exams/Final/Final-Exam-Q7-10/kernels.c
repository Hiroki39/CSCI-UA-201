/********************************************************
 * Kernels to be optimized for the CSO Final Exam
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/*
 * Please fill in the following team struct
 */
team_t team = {
    "",               /* Team name */
    "Hongyi Zheng",   /* First member full name */
    "hz2212@nyu.edu", /* First member email address */
    "",               /* Second member full name (leave blank if none) */
    ""                /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/*
 * naive_rotate - The naive baseline version of rotate
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel* src, pixel* dst) {
    int i, j;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            dst[RIDX(dim - 1 - j, i, dim)] = src[RIDX(i, j, dim)];
}

/*
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] =
    "optimized_rotate: Blocking the for loop + Unrolling the inner loop + "
    "Avoid using RIDX";
void rotate(int dim, pixel* src, pixel* dst) {
    // dst[dim * dim - dim + i - dim * j] == src[dim * i + j]
    int i, j;
    dst += (dim * dim - dim);
    for (i = 0; i < dim; i += 16) {
        for (j = 0; j < dim; j++) {
            dst[0] = src[0];
            dst[1] = src[dim];
            dst[2] = src[2 * dim];
            dst[3] = src[3 * dim];
            dst[4] = src[4 * dim];
            dst[5] = src[5 * dim];
            dst[6] = src[6 * dim];
            dst[7] = src[7 * dim];
            dst[8] = src[8 * dim];
            dst[9] = src[9 * dim];
            dst[10] = src[10 * dim];
            dst[11] = src[11 * dim];
            dst[12] = src[12 * dim];
            dst[13] = src[13 * dim];
            dst[14] = src[14 * dim];
            dst[15] = src[15 * dim];
            src++;       // j++ => src+=1
            dst -= dim;  // j++ => dim+=-dim
        }
        // i += 16 => src += 16 * dim, then neutralize the effects of for(j)
        src += 15 * dim;
        // i += 16 => dst += 16, then neutralize the effects of for(j)
        dst += dim * dim + 16;
    }
}

char unroll_rotate_descr[] =
    "unroll_rotate: Blocking the for loop + Unrolling the inner loop";
void unroll_rotate(int dim, pixel* src, pixel* dst) {
    int i, j, k;
    int tmp = dim - 1;
    for (i = 0; i < dim; i += 4) {
        for (j = 0; j < dim; j += 4) {
            for (k = i; k < i + 4; k++) {
                dst[RIDX(tmp - j, k, dim)] = src[RIDX(k, j, dim)];
                dst[RIDX(tmp - j - 1, k, dim)] = src[RIDX(k, j + 1, dim)];
                dst[RIDX(tmp - j - 2, k, dim)] = src[RIDX(k, j + 2, dim)];
                dst[RIDX(tmp - j - 3, k, dim)] = src[RIDX(k, j + 3, dim)];
            }
        }
    }
}

char blocked_rotate_descr[] = "blocked_rotate: Blocking the for loop only";
void blocked_rotate(int dim, pixel* src, pixel* dst) {
    int i, j, k, l;
    int tmp = dim - 1;
    for (i = 0; i < dim; i += 4) {
        for (j = 0; j < dim; j += 4) {
            for (k = i; k < i + 4; k++) {
                for (l = j; l < j + 4; l++) {
                    dst[RIDX(tmp - l, k, dim)] = src[RIDX(k, l, dim)];
                }
            }
        }
    }
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_rotate_functions() {
    add_rotate_function(&naive_rotate, naive_rotate_descr);
    add_rotate_function(&rotate, rotate_descr);
    add_rotate_function(&unroll_rotate, unroll_rotate_descr);
    add_rotate_function(&blocked_rotate, blocked_rotate_descr);
    /* ... Register additional test functions here */
}

/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/*
 * initialize_pixel_sum - Initializes all fields of sum to 0
 */
static void initialize_pixel_sum(pixel_sum* sum) {
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/*
 * accumulate_sum - Accumulates field values of p in corresponding
 * fields of sum
 */
static void accumulate_sum(pixel_sum* sum, pixel p) {
    sum->red += (int)p.red;
    sum->green += (int)p.green;
    sum->blue += (int)p.blue;
    sum->num++;
    return;
}

/*
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel
 */
static void assign_sum_to_pixel(pixel* current_pixel, pixel_sum sum) {
    current_pixel->red = (unsigned short)(sum.red / sum.num);
    current_pixel->green = (unsigned short)(sum.green / sum.num);
    current_pixel->blue = (unsigned short)(sum.blue / sum.num);
    return;
}

/*
 * avg - Returns averaged pixel value at (i,j)
 */
static pixel avg(int dim, int i, int j, pixel* src) {
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for (ii = max(i - 1, 0); ii <= min(i + 1, dim - 1); ii++)
        for (jj = max(j - 1, 0); jj <= min(j + 1, dim - 1); jj++)
            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel* src, pixel* dst) {
    int i, j;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++) dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth.
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] =
    "optimized_smooth: Break images into parts + Avoid using RIDX";
void smooth(int dim, pixel* src, pixel* dst) {
    int i, j;
    int tmp;

    // corners
    dst[0].red =
        (src[0].red + src[1].red + src[dim].red + src[dim + 1].red) >> 2;
    dst[0].green =
        (src[0].green + src[1].green + src[dim].green + src[dim + 1].green) >>
        2;
    dst[0].blue =
        (src[0].blue + src[1].blue + src[dim].blue + src[dim + 1].blue) >> 2;
    i = dim - 1;
    dst[i].red = (src[i].red + src[i - 1].red + src[i + dim].red +
                  src[i + dim - 1].red) >>
                 2;
    dst[i].green = (src[i].green + src[i - 1].green + src[i + dim].green +
                    src[i + dim - 1].green) >>
                   2;
    dst[i].blue = (src[i].blue + src[i - 1].blue + src[i + dim].blue +
                   src[i + dim - 1].blue) >>
                  2;
    i = i * dim;
    dst[i].red = (src[i].red + src[i + 1].red + src[i - dim].red +
                  src[i - dim + 1].red) >>
                 2;
    dst[i].green = (src[i].green + src[i + 1].green + src[i - dim].green +
                    src[i - dim + 1].green) >>
                   2;
    dst[i].blue = (src[i].blue + src[i + 1].blue + src[i - dim].blue +
                   src[i - dim + 1].blue) >>
                  2;
    i = i + dim - 1;
    dst[i].red = (src[i].red + src[i - 1].red + src[i - dim].red +
                  src[i - dim - 1].red) >>
                 2;
    dst[i].green = (src[i].green + src[i - 1].green + src[i - dim].green +
                    src[i - dim - 1].green) >>
                   2;
    dst[i].blue = (src[i].blue + src[i - 1].blue + src[i - dim].blue +
                   src[i - dim - 1].blue) >>
                  2;

    // sides
    for (i = 1; i < dim - 1; ++i) {
        dst[i].red =
            (src[i].red + src[i - 1].red + src[i + 1].red + src[i + dim].red +
             src[i + dim - 1].red + src[i + dim + 1].red) /
            6;
        dst[i].green = (src[i].green + src[i - 1].green + src[i + 1].green +
                        src[i + dim].green + src[i + dim - 1].green +
                        src[i + dim + 1].green) /
                       6;
        dst[i].blue = (src[i].blue + src[i - 1].blue + src[i + 1].blue +
                       src[i + dim].blue + src[i + dim - 1].blue +
                       src[i + dim + 1].blue) /
                      6;
    }
    for (i = dim * (dim - 1) + 1; i < dim * dim - 1; ++i) {
        dst[i].red =
            (src[i].red + src[i - 1].red + src[i + 1].red + src[i - dim].red +
             src[i - dim - 1].red + src[i - dim + 1].red) /
            6;
        dst[i].green = (src[i].green + src[i - 1].green + src[i + 1].green +
                        src[i - dim].green + src[i - dim - 1].green +
                        src[i - dim + 1].green) /
                       6;
        dst[i].blue = (src[i].blue + src[i - 1].blue + src[i + 1].blue +
                       src[i - dim].blue + src[i - dim - 1].blue +
                       src[i - dim + 1].blue) /
                      6;
    }
    for (j = dim; j < dim * (dim - 1); j += dim) {
        dst[j].red =
            (src[j].red + src[j + 1].red + src[j - dim].red +
             src[j - dim + 1].red + src[j + dim].red + src[j + dim + 1].red) /
            6;
        dst[j].green = (src[j].green + src[j + 1].green + src[j - dim].green +
                        src[j - dim + 1].green + src[j + dim].green +
                        src[j + dim + 1].green) /
                       6;
        dst[j].blue = (src[j].blue + src[j + 1].blue + src[j - dim].blue +
                       src[j - dim + 1].blue + src[j + dim].blue +
                       src[j + dim + 1].blue) /
                      6;
    }
    for (j = 2 * dim - 1; j < dim * dim - 1; j += dim) {
        dst[j].red =
            (src[j].red + src[j - 1].red + src[j - dim].red +
             src[j - dim - 1].red + src[j + dim].red + src[j + dim - 1].red) /
            6;
        dst[j].green = (src[j].green + src[j - 1].green + src[j - dim].green +
                        src[j - dim - 1].green + src[j + dim].green +
                        src[j + dim - 1].green) /
                       6;
        dst[j].blue = (src[j].blue + src[j - 1].blue + src[j - dim].blue +
                       src[j - dim - 1].blue + src[j + dim].blue +
                       src[j + dim - 1].blue) /
                      6;
    }

    // center
    for (i = 1; i < dim - 1; ++i) {
        for (j = 1; j < dim - 1; ++j) {
            tmp = i * dim + j;
            dst[tmp].red = (src[tmp].red + src[tmp - 1].red + src[tmp + 1].red +
                            src[tmp - dim].red + src[tmp - dim - 1].red +
                            src[tmp - dim + 1].red + src[tmp + dim].red +
                            src[tmp + dim - 1].red + src[tmp + dim + 1].red) /
                           9;
            dst[tmp].green =
                (src[tmp].green + src[tmp - 1].green + src[tmp + 1].green +
                 src[tmp - dim].green + src[tmp - dim - 1].green +
                 src[tmp - dim + 1].green + src[tmp + dim].green +
                 src[tmp + dim - 1].green + src[tmp + dim + 1].green) /
                9;
            dst[tmp].blue =
                (src[tmp].blue + src[tmp - 1].blue + src[tmp + 1].blue +
                 src[tmp - dim].blue + src[tmp - dim - 1].blue +
                 src[tmp - dim + 1].blue + src[tmp + dim].blue +
                 src[tmp + dim - 1].blue + src[tmp + dim + 1].blue) /
                9;
        }
    }
}

char break_smooth_descr[] =
    "break_smooth: Break images into parts (Using RIDX results in higher CPE,"
    "probabily because it allows merging 4 for loops for side into one)";
void break_smooth(int dim, pixel* src, pixel* dst) {
    int i, j;

    // corners
    dst[RIDX(0, 0, dim)].red =
        (src[RIDX(0, 0, dim)].red + src[RIDX(0, 1, dim)].red +
         src[RIDX(1, 0, dim)].red + src[RIDX(1, 1, dim)].red) >>
        2;
    dst[RIDX(0, 0, dim)].green =
        (src[RIDX(0, 0, dim)].green + src[RIDX(0, 1, dim)].green +
         src[RIDX(1, 0, dim)].green + src[RIDX(1, 1, dim)].green) >>
        2;
    dst[RIDX(0, 0, dim)].blue =
        (src[RIDX(0, 0, dim)].blue + src[RIDX(0, 1, dim)].blue +
         src[RIDX(1, 0, dim)].blue + src[RIDX(1, 1, dim)].blue) >>
        2;

    dst[RIDX(0, dim - 1, dim)].red =
        (src[RIDX(0, dim - 1, dim)].red + src[RIDX(0, dim - 2, dim)].red +
         src[RIDX(1, dim - 1, dim)].red + src[RIDX(1, dim - 2, dim)].red) >>
        2;
    dst[RIDX(0, dim - 1, dim)].green =
        (src[RIDX(0, dim - 1, dim)].green + src[RIDX(0, dim - 2, dim)].green +
         src[RIDX(1, dim - 1, dim)].green + src[RIDX(1, dim - 2, dim)].green) >>
        2;
    dst[RIDX(0, dim - 1, dim)].blue =
        (src[RIDX(0, dim - 1, dim)].blue + src[RIDX(0, dim - 2, dim)].blue +
         src[RIDX(1, dim - 1, dim)].blue + src[RIDX(1, dim - 2, dim)].blue) >>
        2;

    dst[RIDX(dim - 1, 0, dim)].red =
        (src[RIDX(dim - 1, 0, dim)].red + src[RIDX(dim - 2, 0, dim)].red +
         src[RIDX(dim - 1, 1, dim)].red + src[RIDX(dim - 2, 1, dim)].red) >>
        2;
    dst[RIDX(dim - 1, 0, dim)].green =
        (src[RIDX(dim - 1, 0, dim)].green + src[RIDX(dim - 2, 0, dim)].green +
         src[RIDX(dim - 1, 1, dim)].green + src[RIDX(dim - 2, 1, dim)].green) >>
        2;
    dst[RIDX(dim - 1, 0, dim)].blue =
        (src[RIDX(dim - 1, 0, dim)].blue + src[RIDX(dim - 2, 0, dim)].blue +
         src[RIDX(dim - 1, 1, dim)].blue + src[RIDX(dim - 2, 1, dim)].blue) >>
        2;

    dst[RIDX(dim - 1, dim - 1, dim)].red =
        (src[RIDX(dim - 1, dim - 1, dim)].red +
         src[RIDX(dim - 2, dim - 1, dim)].red +
         src[RIDX(dim - 1, dim - 2, dim)].red +
         src[RIDX(dim - 2, dim - 2, dim)].red) >>
        2;
    dst[RIDX(dim - 1, dim - 1, dim)].green =
        (src[RIDX(dim - 1, dim - 1, dim)].green +
         src[RIDX(dim - 2, dim - 1, dim)].green +
         src[RIDX(dim - 1, dim - 2, dim)].green +
         src[RIDX(dim - 2, dim - 2, dim)].green) >>
        2;
    dst[RIDX(dim - 1, dim - 1, dim)].blue =
        (src[RIDX(dim - 1, dim - 1, dim)].blue +
         src[RIDX(dim - 2, dim - 1, dim)].blue +
         src[RIDX(dim - 1, dim - 2, dim)].blue +
         src[RIDX(dim - 2, dim - 2, dim)].blue) >>
        2;

    // sides
    for (i = 1; i < dim - 1; ++i) {
        dst[RIDX(i, 0, dim)].red =
            (src[RIDX(i, 0, dim)].red + src[RIDX(i - 1, 0, dim)].red +
             src[RIDX(i + 1, 0, dim)].red + src[RIDX(i, 1, dim)].red +
             src[RIDX(i - 1, 1, dim)].red + src[RIDX(i + 1, 1, dim)].red) /
            6;
        dst[RIDX(i, 0, dim)].green =
            (src[RIDX(i, 0, dim)].green + src[RIDX(i - 1, 0, dim)].green +
             src[RIDX(i + 1, 0, dim)].green + src[RIDX(i, 1, dim)].green +
             src[RIDX(i - 1, 1, dim)].green + src[RIDX(i + 1, 1, dim)].green) /
            6;
        dst[RIDX(i, 0, dim)].blue =
            (src[RIDX(i, 0, dim)].blue + src[RIDX(i - 1, 0, dim)].blue +
             src[RIDX(i + 1, 0, dim)].blue + src[RIDX(i, 1, dim)].blue +
             src[RIDX(i - 1, 1, dim)].blue + src[RIDX(i + 1, 1, dim)].blue) /
            6;

        dst[RIDX(i, dim - 1, dim)].red = (src[RIDX(i, dim - 1, dim)].red +
                                          src[RIDX(i - 1, dim - 1, dim)].red +
                                          src[RIDX(i + 1, dim - 1, dim)].red +
                                          src[RIDX(i, dim - 2, dim)].red +
                                          src[RIDX(i - 1, dim - 2, dim)].red +
                                          src[RIDX(i + 1, dim - 2, dim)].red) /
                                         6;
        dst[RIDX(i, dim - 1, dim)].green =
            (src[RIDX(i, dim - 1, dim)].green +
             src[RIDX(i - 1, dim - 1, dim)].green +
             src[RIDX(i + 1, dim - 1, dim)].green +
             src[RIDX(i, dim - 2, dim)].green +
             src[RIDX(i - 1, dim - 2, dim)].green +
             src[RIDX(i + 1, dim - 2, dim)].green) /
            6;
        dst[RIDX(i, dim - 1, dim)].blue =
            (src[RIDX(i, dim - 1, dim)].blue +
             src[RIDX(i - 1, dim - 1, dim)].blue +
             src[RIDX(i + 1, dim - 1, dim)].blue +
             src[RIDX(i, dim - 2, dim)].blue +
             src[RIDX(i - 1, dim - 2, dim)].blue +
             src[RIDX(i + 1, dim - 2, dim)].blue) /
            6;

        dst[RIDX(0, i, dim)].red =
            (src[RIDX(0, i, dim)].red + src[RIDX(1, i, dim)].red +
             src[RIDX(0, i - 1, dim)].red + src[RIDX(1, i - 1, dim)].red +
             src[RIDX(0, i + 1, dim)].red + src[RIDX(1, i + 1, dim)].red) /
            6;
        dst[RIDX(0, i, dim)].green =
            (src[RIDX(0, i, dim)].green + src[RIDX(1, i, dim)].green +
             src[RIDX(0, i - 1, dim)].green + src[RIDX(1, i - 1, dim)].green +
             src[RIDX(0, i + 1, dim)].green + src[RIDX(1, i + 1, dim)].green) /
            6;
        dst[RIDX(0, i, dim)].blue =
            (src[RIDX(0, i, dim)].blue + src[RIDX(1, i, dim)].blue +
             src[RIDX(0, i - 1, dim)].blue + src[RIDX(1, i - 1, dim)].blue +
             src[RIDX(0, i + 1, dim)].blue + src[RIDX(1, i + 1, dim)].blue) /
            6;

        dst[RIDX(dim - 1, i, dim)].red =
            (src[RIDX(dim - 1, i, dim)].red + src[RIDX(dim - 2, i, dim)].red +
             src[RIDX(dim - 1, i - 1, dim)].red +
             src[RIDX(dim - 2, i - 1, dim)].red +
             src[RIDX(dim - 1, i + 1, dim)].red +
             src[RIDX(dim - 2, i + 1, dim)].red) /
            6;
        dst[RIDX(dim - 1, i, dim)].green =
            (src[RIDX(dim - 1, i, dim)].green +
             src[RIDX(dim - 2, i, dim)].green +
             src[RIDX(dim - 1, i - 1, dim)].green +
             src[RIDX(dim - 2, i - 1, dim)].green +
             src[RIDX(dim - 1, i + 1, dim)].green +
             src[RIDX(dim - 2, i + 1, dim)].green) /
            6;
        dst[RIDX(dim - 1, i, dim)].blue =
            (src[RIDX(dim - 1, i, dim)].blue + src[RIDX(dim - 2, i, dim)].blue +
             src[RIDX(dim - 1, i - 1, dim)].blue +
             src[RIDX(dim - 2, i - 1, dim)].blue +
             src[RIDX(dim - 1, i + 1, dim)].blue +
             src[RIDX(dim - 2, i + 1, dim)].blue) /
            6;
    }

    // center
    for (i = 1; i < dim - 1; ++i) {
        for (j = 1; j < dim - 1; ++j) {
            dst[RIDX(i, j, dim)].red =
                (src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
                 src[RIDX(i + 1, j, dim)].red + src[RIDX(i, j - 1, dim)].red +
                 src[RIDX(i - 1, j - 1, dim)].red +
                 src[RIDX(i + 1, j - 1, dim)].red +
                 src[RIDX(i, j + 1, dim)].red +
                 src[RIDX(i - 1, j + 1, dim)].red +
                 src[RIDX(i + 1, j + 1, dim)].red) /
                9;
            dst[RIDX(i, j, dim)].green =
                (src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
                 src[RIDX(i + 1, j, dim)].green +
                 src[RIDX(i, j - 1, dim)].green +
                 src[RIDX(i - 1, j - 1, dim)].green +
                 src[RIDX(i + 1, j - 1, dim)].green +
                 src[RIDX(i, j + 1, dim)].green +
                 src[RIDX(i - 1, j + 1, dim)].green +
                 src[RIDX(i + 1, j + 1, dim)].green) /
                9;
            dst[RIDX(i, j, dim)].blue =
                (src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
                 src[RIDX(i + 1, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue +
                 src[RIDX(i - 1, j - 1, dim)].blue +
                 src[RIDX(i + 1, j - 1, dim)].blue +
                 src[RIDX(i, j + 1, dim)].blue +
                 src[RIDX(i - 1, j + 1, dim)].blue +
                 src[RIDX(i + 1, j + 1, dim)].blue) /
                9;
        }
    }
}

char partial_break_smooth_descr[] =
    "partial_break_smooth: Break images into parts and uses RIDX, but use "
    "avg() only for corner and side pixels (balance between efficiency and "
    "simplicity)";
void partial_break_smooth(int dim, pixel* src, pixel* dst) {
    int i, j;

    // corners
    dst[RIDX(0, 0, dim)] = avg(dim, 0, 0, src);
    dst[RIDX(0, dim - 1, dim)] = avg(dim, 0, dim - 1, src);
    dst[RIDX(dim - 1, 0, dim)] = avg(dim, dim - 1, 0, src);
    dst[RIDX(dim - 1, dim - 1, dim)] = avg(dim, dim - 1, dim - 1, src);

    // sides
    for (i = 1; i < dim - 1; ++i) {
        dst[RIDX(i, 0, dim)] = avg(dim, i, 0, src);
        dst[RIDX(i, dim - 1, dim)] = avg(dim, i, dim - 1, src);
        dst[RIDX(0, i, dim)] = avg(dim, 0, i, src);
        dst[RIDX(dim - 1, i, dim)] = avg(dim, dim - 1, i, src);
    }

    // center
    for (i = 1; i < dim - 1; ++i) {
        for (j = 1; j < dim - 1; ++j) {
            dst[RIDX(i, j, dim)].red =
                (src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
                 src[RIDX(i + 1, j, dim)].red + src[RIDX(i, j - 1, dim)].red +
                 src[RIDX(i - 1, j - 1, dim)].red +
                 src[RIDX(i + 1, j - 1, dim)].red +
                 src[RIDX(i, j + 1, dim)].red +
                 src[RIDX(i - 1, j + 1, dim)].red +
                 src[RIDX(i + 1, j + 1, dim)].red) /
                9;
            dst[RIDX(i, j, dim)].green =
                (src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
                 src[RIDX(i + 1, j, dim)].green +
                 src[RIDX(i, j - 1, dim)].green +
                 src[RIDX(i - 1, j - 1, dim)].green +
                 src[RIDX(i + 1, j - 1, dim)].green +
                 src[RIDX(i, j + 1, dim)].green +
                 src[RIDX(i - 1, j + 1, dim)].green +
                 src[RIDX(i + 1, j + 1, dim)].green) /
                9;
            dst[RIDX(i, j, dim)].blue =
                (src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
                 src[RIDX(i + 1, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue +
                 src[RIDX(i - 1, j - 1, dim)].blue +
                 src[RIDX(i + 1, j - 1, dim)].blue +
                 src[RIDX(i, j + 1, dim)].blue +
                 src[RIDX(i - 1, j + 1, dim)].blue +
                 src[RIDX(i + 1, j + 1, dim)].blue) /
                9;
        }
    }
}

char blocked_smooth_descr[] =
    "blocked_smooth: Blocking the for loop + Unrolling two levels of inner "
    "loop";
void blocked_smooth(int dim, pixel* src, pixel* dst) {
    int i, j;
    for (i = 0; i < dim; i += 4) {
        for (j = 0; j < dim; j += 4) {
            dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
            dst[RIDX(i, j + 1, dim)] = avg(dim, i, j + 1, src);
            dst[RIDX(i, j + 2, dim)] = avg(dim, i, j + 2, src);
            dst[RIDX(i, j + 3, dim)] = avg(dim, i, j + 3, src);
            dst[RIDX(i + 1, j, dim)] = avg(dim, i + 1, j, src);
            dst[RIDX(i + 1, j + 1, dim)] = avg(dim, i + 1, j + 1, src);
            dst[RIDX(i + 1, j + 2, dim)] = avg(dim, i + 1, j + 2, src);
            dst[RIDX(i + 1, j + 3, dim)] = avg(dim, i + 1, j + 3, src);
            dst[RIDX(i + 2, j, dim)] = avg(dim, i + 2, j, src);
            dst[RIDX(i + 2, j + 1, dim)] = avg(dim, i + 2, j + 1, src);
            dst[RIDX(i + 2, j + 2, dim)] = avg(dim, i + 2, j + 2, src);
            dst[RIDX(i + 2, j + 3, dim)] = avg(dim, i + 2, j + 3, src);
            dst[RIDX(i + 3, j, dim)] = avg(dim, i + 3, j, src);
            dst[RIDX(i + 3, j + 1, dim)] = avg(dim, i + 3, j + 1, src);
            dst[RIDX(i + 3, j + 2, dim)] = avg(dim, i + 3, j + 2, src);
            dst[RIDX(i + 3, j + 3, dim)] = avg(dim, i + 3, j + 3, src);
        }
    }
}

/*********************************************************************
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    add_smooth_function(&break_smooth, break_smooth_descr);
    add_smooth_function(&partial_break_smooth, partial_break_smooth_descr);
    add_smooth_function(&blocked_smooth, blocked_smooth_descr);
    /* ... Register additional test functions here */
}
