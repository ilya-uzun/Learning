JAVA_FILES:=$(wildcard *.java)
#
# the rest is independent of the directory
#
JAVA_CLASSES:=$(patsubst %.java,%.class,$(JAVA_FILES))

.PHONY: classes
LIST:=

classes: $(JAVA_CLASSES)
		if [ ! -z "$(LIST)" ] ; then \
                kotlinc $(LIST) ; \
        fi

$(JAVA_CLASSES) : %.class : %.java
        $(eval LIST+=$$<)