/*
 * Example MsgGen static library.
 */

/* Platforms must provide their own stdint types, we make no assumption
 * about including them here.
 */

/* Message library */
#include "MsgGen_declare.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

#include "MsgGen_encode_decl.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

#include "MsgGen_decode_decl.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

#include "MsgGen_print_decl.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

