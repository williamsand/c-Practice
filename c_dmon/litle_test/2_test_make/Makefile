.PHONY: all t_eval clean
define EVAL
hello::hello.c
	gcc hello.c -o hello
endef

#$(eval $(call EVAL))

#in fact ,like this way,alaways use : make -C xxx .instead of  include in another makefile
#use this alaways like  : OBJs-xxx .for example ffmpeg
#hello:      #in this way ,will accour this warnning :overriding recipe for target 'hello'
all:: t_eval
	@echo "enter 2_test_make -------"
hello::
	gcc ../2_test_make/hello.c -o $@

clean::
	rm -f *.o
	rm hello

