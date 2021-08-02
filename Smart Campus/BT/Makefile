PROJECT := rs

#OBJS := BT.scan.o scan.o
OBJS :=scan.o db1.o

DEPS := 

all: $(PROJECT)

CFLAGS := -Wall -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/mysql -g #-Werror

LDFLAGS := -lglib-2.0 -lgio-2.0 -lbluetooth -lmysqlclient -g

$(PROJECT): $(OBJS)
	$(CC) $(OBJS)  $(LDFLAGS) -o $@

%.o: %.c Makefile $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

install: all
	install -m 755 $(PROJECT) $(LUALIB_INSTALLDIR)

