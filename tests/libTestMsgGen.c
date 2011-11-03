/*
 * Example MsgGen static library.
 */

/* Platforms must provide their own types */
#include <stdint.h>

/* Message library */
#include "MsgGen_declare.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

#include "MsgGen_lib.h" /* declare encode functions extern */
#include "MsgGen_encode.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

#include "MsgGen_lib.h" /* declare decode functions extern */
#include "MsgGen_decode.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

#include "MsgGen_lib.h" /* declare print functions extern */
#include "MsgGen_print.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

