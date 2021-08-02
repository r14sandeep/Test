PROJECT := rs

OBJS := bt_initialise.o bt_scan.o main_process.o read_rssi.o rssi_ndevice_info.o local_time.o scan_rssi.o db1.o
DEPS := 

all: $(PROJECT)

CFLAGS := -Wall -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/mysql -g #-Werror

LDFLAGS := -lglib-2.0 -lgio-2.0 -lbluetooth -lpthread -lmysqlclient -g

$(PROJECT): $(OBJS)
	$(CC) $(OBJS)  $(LDFLAGS) -o $@

%.o: %.c Makefile $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

install: all
	install -m 755 $(PROJECT) $(LUALIB_INSTALLDIR)
clean:
	rm *.o
