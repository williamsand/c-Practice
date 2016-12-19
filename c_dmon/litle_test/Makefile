SRC = color_out.c  two_point.c
C_SOURCES = $(wildcard *.c)
OBJ_ALL=$(C_SOURCES:%.c=%.o)
OBJ = $(SRC:%.c=%.o)
TESTS=$(C_SOURCES:.c=)     #exe
SUBDIR = sub

ifeq ($(abc),ab)
	abc=2
else
	abc=no
	test_pass=no_eq
endif

#all:${OBJ_ALL}
all: ${TESTS}
	@echo "abc = ${abc}"
	@echo "test_pass = ${test_pass}"
	@echo ${OBJ}
	@echo ${C_SOURCES}
	@echo ${OBJ_ALL}
	@echo ${TESTS}
	@for n in $(C_SOURCES); do \
		echo $$n;  \
	done
	@make -C ${SUBDIR} what
	@make test -C ${SUBDIR} 
	@make test what -C ${SUBDIR} 
	@make -C ${SUBDIR} 
	@make update -C ${SUBDIR} 
	@make all -C ${SUBDIR} 

#str: str.o
#	gcc -o $@ $^ 	
#	${CC} $^ -o $@

#%.o : %.c
#	@echo "-----------enter here-------"
#	gcc -o $@ $^

.PHONY: clean
clean:
	rm -f *.o
	rm -r ${TESTS}
