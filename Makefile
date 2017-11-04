#	basic makefile for the c++ application

SOURCE=smat.cpp
MYPROGRAM=smat
CC=g++
PREFIX=/usr
BINDIR=$(PREFIX)/bin


all: 
	@echo "Run 'make smat' to compile in current location."
	@echo "Run 'make clean' to remove compiled binary."
	@echo "Run 'sudo make install/uninstall' for proper installation and uninstallation"

$(MYPROGRAM): $(SOURCE)
	$(CC) $(SOURCE) -o $(MYPROGRAM)

install:
	$(CC) $(SOURCE) -o $(MYPROGRAM)
	install -Dm755 $(MYPROGRAM) $(BINDIR)/$(MYPROGRAM)

uninstall:
	rm -f $(BINDIR)/$(MYPROGRAM)


clean:
	rm -f $(MYPROGRAM)
