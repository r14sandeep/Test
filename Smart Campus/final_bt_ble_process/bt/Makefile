PROJECT := rs

OBJS := main_thread.o bt_initialise.o ble_scan.o scan.o BT_scan.o
DEPS := 

all: $(PROJECT)

CFLAGS := -Wall -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -g #-Werror

LDFLAGS := -lglib-2.0 -lgio-2.0 -lbluetooth -lpthread -g

$(PROJECT): $(OBJS)
	$(CC) $(OBJS)  $(LDFLAGS) -o $@

%.o: %.c Makefile $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

install: all
	install -m 755 $(PROJECT) $(LUALIB_INSTALLDIR)

