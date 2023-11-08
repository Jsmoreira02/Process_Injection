CC = x86_64-w64-mingw32-gcc

CFLAGS = -static-libgcc

SOURCES = explorer_injection.c Process_injection.c Win_malware.c

TARGETS = $(SOURCES:.c=)

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

clean-%:
	rm -f $*

