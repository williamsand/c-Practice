SRC_PATH = .
SUBDIR += codec
SUBDIR += utili

TARGET = mycodec
CFLAGS += -I ./common
OBJS = main.o

all:${TARGET} 


define DOSUBDIR
include $(SRC_PATH)/$(1)/Makefile
endef

$(foreach D,$(SUBDIR),$(eval $(call DOSUBDIR,$(D))))

${TARGET}: ${OBJS}
	gcc $^ -o $@
	rm -f ${OBJS}

.PHONY: all clean 
clean:
	rm -f ${OBJS}
