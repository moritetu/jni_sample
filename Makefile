# Assume that make will run on mac
JAVA_HOME    := $(shell /usr/libexec/java_home)
CC           = gcc
CFLAGS       = -O2 -Wall $(addprefix -I$(JAVA_HOME)/,include include/darwin)
SOURCES      = hello.c
OBJS         = $(SOURCES:%.c=%.o)
PROGRAM      = libjnisample.jnilib
CLASSES      = src/main/java/sample/JNISample.java

.SUFFIXES: .java .class

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): JNISample.h $(OBJS)
	$(CC) $(CFLAGS) -shared $(OBJS) -o $@

JNISample.h: classes
	javah -o JNISample.h -classpath classes sample.JNISample

.PHONY: classes
classes: $(CLASSES:.java=.class)

.java.class:
	mkdir -p classes
	javac -d classes $<


.PHONY: run
run:
	java -classpath classes -Djava.library.path=. sample.JNISample $(ARGS)

.PHONY: clean
clean:
	$(RM) -rf *.o *.jnilib classes JNISample.h
