CC := gcc
CFLAGS := -g -Wall

DEFINES := -DUNIT_TEST=test_MsgGen
SRC_DIR := ..
INCLUDES := -I . -I ${SRC_DIR}/ 
OBJDUMP_FLAGS := -dS
OBJDUMP := objdump
# blank lines after commas
INDENT_FLAGS := --k-and-r-style \
				--blank-lines-after-declarations \
				--blank-lines-after-commas \
				--braces-after-if-line \
				--brace-indent0 \
				--break-function-decl-args \
				--cuddle-do-while \
				--declaration-comment-column0 \
				--no-tabs

INDENT := indent

SOURCES_TEST_MSGGEN := test_MsgGen.c test_main.c
SOURCES_TEST_MSGGEN_PREP := test_MsgGen.c
OBJS := test_MsgGen.o
SOURCES_TEST_MSGGEN_ASM := $(SOURCES_TEST_MSGGEN_PREP)
SOURCES_TEST_MSGGEN_INTERLEAVED := $(SOURCES_TEST_MSGGEN_PREP)
OUT_TEST_MSGGEN := test_MsgGen
OUT_TEST_MSGGEN_PREP := tmp_MsgGen.c
OUT_TEST_MSGGEN_ASM := tmp_MsgGen.S
OUT_TEST_MSGGEN_INTERLEAVED := tmp_MsgGen.asm

DIR_LIB_TESTMSGGEN := lib
OBJS_TEST_LIBTESTMSGGEN := test_LibTestMsgGen.o
OUT_LIB_TESTMSGGEN := $(DIR_LIB_TESTMSGGEN)/libTestMsgGen.a
OUT_TEST_LIBTESTMSGGEN := test_LibTestMsgGen

default: $(OBJS) test_main.c
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o $(OUT_TEST_MSGGEN) test_main.c $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

prep: $(SOURCES_TEST_MSGGEN_PREP)
	$(CC) -P -E $(CFLAGS) $(DEFINES) $(INCLUDES) -o $(OUT_TEST_MSGGEN_PREP) $(SOURCES_TEST_MSGGEN_PREP)
	$(INDENT) $(INDENT_FLAGS) $(OUT_TEST_MSGGEN_PREP)

asm: $(SOURCES_TEST_MSGGEN_ASM)
	$(CC) -P -S $(CFLAGS) $(DEFINES) $(INCLUDES) -o $(OUT_TEST_MSGGEN_ASM) $(SOURCES_TEST_MSGGEN_ASM)

interleaved: $(OBJS)
	$(OBJDUMP) $(OBJDUMP_FLAGS) $< > $(OUT_TEST_MSGGEN_INTERLEAVED) 

.PHONY: clean
clean:
	rm -f $(OBJS) *.c~ *.a *.i *.i~ $(OUT_TEST_MSGGEN) $(OUT_TEST_MSGGEN_PREP) $(OUT_TEST_MSGGEN_ASM) $(OUT_TEST_MSGGEN_INTERLEAVED)

%.h.i : %.h
	$(CC) -P -E $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<
	$(INDENT) $(INDENT_FLAGS) $@

%.c.i : %.c
	$(CC) -P -E $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<
	$(INDENT) $(INDENT_FLAGS) $@

%.a : %.o
	$(AR) $(ARFLAGS) $@ $<

libdir:
	@mkdir -p lib

lib/%.c : %.c
	cp $< $@

lib/%.h : %.h.i
	cp $< $@

libprep: libTestMsgGen.h.i libTestMsgGen.c.i

libhdr: libdir lib/libTestMsgGen.h

lib: libdir libhdr $(OUT_LIB_TESTMSGGEN)

.PHONY: libclean
libclean:
	@rm -f $(OUT_TEST_LIBTESTMSGGEN) $(OBJS_TEST_LIBTESTMSGGEN) *.c~ *.a *.i *.i~ 
	@rm -rf lib/

libtest: lib $(OBJS_TEST_LIBTESTMSGGEN) test_main.c
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -I $(DIR_LIB_TESTMSGGEN) -L$(DIR_LIB_TESTMSGGEN) -o $(OUT_TEST_LIBTESTMSGGEN) test_main.c $(OBJS_TEST_LIBTESTMSGGEN) -lTestMsgGen

