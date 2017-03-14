/**
 * \file low.h
 *
 * \author john
 *
 * This does low-level stuff
 */

/** An object structure !
 *
 * it contains a val :-/
 */
struct object {
    /** Value integer, amazing
     */
    int val;
};

/** How practical to typedef structs!
 */
typedef struct object object_s;

/** An object pointer ...
 *
 * how ominous.
 */
typedef object_s * object_p;
