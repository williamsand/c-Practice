#***********diffierence between  := and = ********************
#----------test "="-----------
x = foo
y = $(x)bar
x = xyz

#------------test ":=" -----------
a := foo
b := $(a)bar
a := xyz

#-----------test "?="----------
ifdef VER
	test = "[ifdef VER]  I say OK"
else
endif

ifeq (${num},1) 
	test ?= "[no VER]  I say NO"
endif

#------------test pass -----------
ifdef VER
	right = YES
else
	right = 
endif

ifeq (${right},abc)
	right = OK
	enterif=yes
else
	right = NO
endif

#--------------------------------
#ifeq (${err},1)
#	str = hello
#else
#	str = hi
#endif

#---------------------------------------
AVPROGS-yes   += ffmpeg
AVPROGS-yes   += ffplay
AVPROGS-yes   += ffprobe
AVPROGS-yes   += ffserver
PROGSSUF=a
EXESUF=b
AVPROGS    := $(AVPROGS-yes:%=%$(PROGSSUF)$(EXESUF))
#------------------------------------

#---------------------------------------
vpath %.c  . 
PROG += ffmpeg
PROG += ffplay
PROG += ffprobe
PROG += ffserver

define DOSUBDIR
SUBDIR += $(1)/
endef

$(foreach D,$(PROG),$(eval $(call DOSUBDIR,lib$(D))))
#------------------------------------
$(eval include ../2_test_make/Makefile)

all::
	@echo "first enter all --------"
test:
	@echo $1
	@echo "[in test  =] :  $y"
	@echo "[in test :=] :  $b"
	@echo "[in test ?=] :  ${test}"
	@echo "[in ] :  ${AVPROGS}"
	@echo "[in s1]" $(1)
	@echo "[in test foreach]" $(SUBDIR)

pass:
	@echo $(err)
	$(if ${err},@echo "get abc",$(error no thoins))
	@echo "[in test pass] :  ${right}"
	@if [ "$(enterif)"=="yes" ]; then \
	    echo "enter ok---------------";\
		right=OK; \
	fi	
	@echo "[in test pass] :  ${right}"
	@echo ${str}
	@echo ${fix}

clean::
	@echo "---------enter test_make clean------"
