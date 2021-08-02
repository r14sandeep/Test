PROJECT := rs

OBJS := bt_initialise.o bt_scan.o main.o read_rssi.o rssi_ndevice_info.o
DEPS := 

all: $(PROJECT)

CFLAGS := -Wall -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -g #-Werror

LDFLAGS := -lglib-2.0 -lgio-2.0 -lbluetooth -g

$(PROJECT): $(OBJS)
	$(CC) $(OBJS)  $(LDFLAGS) -o $@

%.o: %.c Makefile $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

install: all
	install -m 755 $(PROJECT) $(LUALIB_INSTALLDIR)

