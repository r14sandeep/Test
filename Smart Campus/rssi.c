
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

// TODO: This works currently only on Linux

#if defined(LINUX) || defined(__linux__)
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#endif

//#include "blue.h"


int dd, dev_id;
struct hci_conn_info_req *cr;
	int8_t rssi;

dev_id = hci_for_each_dev(HCI_UP, findConn, (long)&bdaddr);
dd = hci_open_dev(dev_id);

if ((cr = malloc(sizeof(struct hci_conn_info_req) + sizeof(struct hci_conn_info))) == NULL) {
		perror("malloc");
		hci_close_dev(dd);
		return BLUE_ERROR;
	}

bacpy(&cr->bdaddr, &bdaddr);
	cr->type = ACL_LINK;
	if (ioctl(dd, HCIGETCONNINFO, (unsigned long)cr) < 0) {
		perror("Could not get connection info");
		free(cr);
		hci_close_dev(dd);
		return BLUE_ERROR;
	}


if (hci_read_rssi(dd, htobs(cr->conn_info->handle), &rssi, 1000) < 0) {
		perror("Could not read RSSI");
		free(cr);
		hci_close_dev(dd);
		return BLUE_ERROR;
	}


free(cr);
	hci_close_dev(dd);
	
//	return rssi;

printf("rssi=%d\n",rssi);
