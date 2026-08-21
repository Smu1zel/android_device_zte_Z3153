/*
 * Copyright (C) 2022-2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <net/if.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>

static int ifc_ctl_sock = -1;

int ifc_init(void) {
    if (ifc_ctl_sock < 0) {
        ifc_ctl_sock = socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
        if (ifc_ctl_sock < 0) {
            return -1;
        }
    }
    return 0;
}

void ifc_close(void) {
    if (ifc_ctl_sock >= 0) {
        close(ifc_ctl_sock);
        ifc_ctl_sock = -1;
    }
}

static int ifc_set_flags(const char *name, unsigned set, unsigned clr) {
    struct ifreq ifr;
    if (ifc_init() < 0) return -1;

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, name, IFNAMSIZ);
    ifr.ifr_name[IFNAMSIZ - 1] = 0;

    if (ioctl(ifc_ctl_sock, SIOCGIFFLAGS, &ifr) < 0) return -1;
    ifr.ifr_flags = (ifr.ifr_flags & ~clr) | set;
    return ioctl(ifc_ctl_sock, SIOCSIFFLAGS, &ifr);
}

int ifc_up(const char *name) {
    return ifc_set_flags(name, IFF_UP, 0);
}

int ifc_down(const char *name) {
    return ifc_set_flags(name, 0, IFF_UP);
}

int ifc_enable(const char *name) {
    return ifc_up(name);
}

int ifc_disable(const char *name) {
    return ifc_down(name);
}

int ifc_reset_connections(const char *name, int reset_mask) {
    (void)name;
    (void)reset_mask;
    return 0;
}
