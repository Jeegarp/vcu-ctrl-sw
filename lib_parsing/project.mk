LIB_PARSING_SRC:=\
	lib_parsing/common_syntax.c\
	lib_parsing/AvcParser.c\
	lib_parsing/HevcParser.c\
	lib_parsing/SliceHdrParsing.c\
	lib_parsing/DPB.c\
	lib_parsing/I_PictMngr.c\
	lib_parsing/Avc_PictMngr.c\
	lib_parsing/Hevc_PictMngr.c\
	lib_parsing/Concealment.c\

ifneq ($(ENABLE_JPEG),0)
endif

ifneq ($(ENABLE_UNITTESTS),0)
UNITTEST+=$(shell find lib_parsing/unittests -name "*.cpp")
UNITTEST+=$(LIB_PARSING_SRC)
endif
