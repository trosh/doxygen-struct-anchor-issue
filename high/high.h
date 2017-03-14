/**
 * \file high.h
 *
 * High-level stuff
 */

#include <low.h>

/** High-level object
 */
typedef struct hobj {
    /** Low-level object
     */
    object_p cont;
} hobj_s;

/** Pointer to high-level object
 *
 * Very useful!
 */
typedef hobj_s * hobj_p;
