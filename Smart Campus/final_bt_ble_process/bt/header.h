#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <errno.h>
#include <glib.h>
#include<sys/timeb.h>
#include<time.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <signal.h>
#include <gio/gio.h>

#define BLUEZ_BUS_NAME "org.bluez"
#define BLUEZ_INTF_ADAPTER "org.bluez.Adapter"

static GDBusConnection *dbus_conn = NULL;
static GMainLoop *main_loop;

struct handler_data {
  const char *bt_address;
  short rssi;
};
int read_rssi(char *);
void ble_scan(int);
