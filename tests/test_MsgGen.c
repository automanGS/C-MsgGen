/*
 * Tests MsgGen macros
 */

#include "minunit.h"
#include <stdint.h>
#include <string.h> /* memset, memcmp */
#include <float.h>

char* test_MsgGen(void);

/* Message declarations */
#include "MsgGen_declare.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

/* Message serialization */
#include "MsgGen_encode.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

/* Message deserialization */
#include "MsgGen_decode.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

/* Message printing */
#include "MsgGen_print.h"
    #include "test_MsgGen.def"
#include "MsgGen_end.h"

void init_MSG_GEN_TEST_SIMPLE_T(MSG_GEN_TEST_SIMPLE_T* m)
{
    m->m_int16 = INT16_MIN;
}

void init_MSG_GEN_TEST_PRIMITIVES_T(MSG_GEN_TEST_PRIMITIVES_T* m)
{
    m->m_int8 = INT8_MIN;
    m->m_uint8 = UINT8_MAX;
    m->m_int16 = INT16_MIN;
    m->m_uint16 = UINT16_MAX;
    m->m_int32 = INT32_MIN;
    m->m_uint32 = UINT32_MAX;
    m->m_char = 'a';
    m->m_float = -FLT_MAX;
}

void init_MSG_GEN_TEST_NESTED_T(MSG_GEN_TEST_NESTED_T* m)
{
    init_MSG_GEN_TEST_PRIMITIVES_T(&m->nested);
}

void init_MSG_GEN_TEST_ARRAYS_T(MSG_GEN_TEST_ARRAYS_T* m)
{
    m->ma_int8[0] = INT8_MIN;
    m->ma_int8[1] = 0;
    m->ma_int8[2] = INT8_MAX;

    m->ma_uint8[0] = 0;
    m->ma_uint8[1] = UINT8_MAX;
    m->ma_uint8[2] = -1;

    m->ma_int16[0] = INT16_MIN;
    m->ma_int16[1] = 0;
    m->ma_int16[2] = INT16_MAX;

    m->ma_uint16[0] = 0;
    m->ma_uint16[1] = UINT16_MAX;
    m->ma_uint16[2] = -1;

    m->ma_int32[0] = INT32_MIN;
    m->ma_int32[1] = 0;
    m->ma_int32[2] = INT32_MAX;

    m->ma_uint32[0] = 0;
    m->ma_uint32[1] = UINT32_MAX;
    m->ma_uint32[2] = -1;

    m->ma_char[0] = 'a';
    m->ma_char[1] = 'b';
    m->ma_char[2] = 'c';

    m->ma_float[0] = -FLT_MAX;
    m->ma_float[1] = FLT_MIN;
    m->ma_float[2] = FLT_MAX;
}

void init_MSG_GEN_TEST_NESTED_ARRAY_T(MSG_GEN_TEST_NESTED_ARRAY_T* m)
{
    m->na[0].m_int16 = INT16_MIN;
    m->na[1].m_int16 = 0;
    m->na[2].m_int16 = INT16_MAX;
}

void init_MSG_GEN_TEST_EMPTY_ARRAY_T(MSG_GEN_TEST_EMPTY_ARRAY_T* m)
{
//    m->ma_char[0] = INT8_MIN;
}

void init_MSG_GEN_TEST_TYPE_T(MSG_GEN_TEST_TYPE_T* m)
{
    m->m_id = (ID_T) 666;
}

void init_MSG_GEN_TEST_NESTED_TYPE_T(MSG_GEN_TEST_NESTED_TYPE_T* m)
{
    m->m_nested_id = (NESTED_ID_T) 667;
}

void init_MSG_GEN_TEST_NESTED_MSG_TYPE_T(MSG_GEN_TEST_NESTED_MSG_TYPE_T* m)
{
    init_MSG_GEN_TEST_SIMPLE_T(&m->m_nested_msg_type);
}

/* Defines tests for each of the msg types
 * Calls init_##TYPE to initialize
 * Calls Encode and Decode functions
 * Checks that the decoded type matches the original
 */
#define MESSAGE(TYPE, NAME, MEMBERS) static char* testCodec_##TYPE(void) \
{ \
    TYPE orig; \
 \
    uint8_t encoded[sizeof(TYPE)]; \
    TYPE decoded; \
 \
    memset(&orig, 0xCD, sizeof(orig)); \
    memset(encoded, 0xCD, sizeof(encoded)); \
    memset(&decoded, 0xCD, sizeof(decoded)); \
 \
    init_##TYPE(&orig); /* initialize it */ \
 \
    MsgGenPrint(TYPE, &orig); \
    MsgGenEncode(TYPE, &orig, encoded); \
    MsgGenDecode(TYPE, encoded, &decoded); \
    MsgGenPrint(TYPE, &decoded); \
 \
    mu_assert("test_"#TYPE, \
              memcmp(&orig, &decoded, sizeof(TYPE)) == 0); \
 \
    return 0; \
};

#define MEMBER(TYPE, NAME, MEMBERS) 
#define MEMBER_ARRAY(TYPE, NAME, LENGTH) 
#define TYPE(BASE_TYPE, TYPE_NAME)

#include "test_MsgGen.def" /* generate tests */
#include "MsgGen_end.h" /* clear x-macros */

/***************************
 *  MsgGen_wrap tests
 ***************************/

typedef struct TEST_WRAP_EXAMPLE {
    uint16_t wrapData;
} TEST_WRAP_HDR_T, TEST_WRAP_FTR_T, TEST_WRAP_HDR2_T, TEST_WRAP_FTR2_T;

/* Tests generation of header wrapper */
static char* testWrapHeader(void)
{
    /* Message wrap header */
    #define MSG_GEN_WRAP_HEADER_TYPE TEST_WRAP_HDR_T
    #include "MsgGen_wrap.h"
        #include "test_MsgGen.def"
    #include "MsgGen_end.h"
    #undef MSG_GEN_WRAP_HEADER_TYPE
    
    return 0;
};

/* Tests generation of simple wrapper */
static char* testWrapNone(void)
{
    /* Message wrap none */
    #include "MsgGen_wrap.h"
        #include "test_MsgGen.def"
    #include "MsgGen_end.h"

    return 0;
}

char* test_MsgGen(void)
{
    mu_run_test(testCodec_MSG_GEN_TEST_SIMPLE_T);
    mu_run_test(testCodec_MSG_GEN_TEST_PRIMITIVES_T);
    mu_run_test(testCodec_MSG_GEN_TEST_ARRAYS_T);
    mu_run_test(testCodec_MSG_GEN_TEST_NESTED_T);
    mu_run_test(testCodec_MSG_GEN_TEST_NESTED_ARRAY_T);
    mu_run_test(testCodec_MSG_GEN_TEST_EMPTY_ARRAY_T);
    mu_run_test(testCodec_MSG_GEN_TEST_TYPE_T);
    mu_run_test(testCodec_MSG_GEN_TEST_NESTED_TYPE_T);
    mu_run_test(testCodec_MSG_GEN_TEST_NESTED_MSG_TYPE_T);
    mu_run_test(testWrapHeader);
    mu_run_test(testWrapNone);

    return 0;
}

