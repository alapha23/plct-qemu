/*
 * Spike machine interface
 *
 * Copyright (c) 2017 SiFive, Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2 or later, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HW_RISCV_SPIKE_H
#define HW_RISCV_SPIKE_H

#include "hw/riscv/riscv_hart.h"
#include "hw/sysbus.h"

typedef struct {
    /*< private >*/
    SysBusDevice parent_obj;

    /*< public >*/
    RISCVHartArrayState soc;
    void *fdt;
    int fdt_size;
} NucleiState;

enum {
    NUCLEI_MROM,
    NUCLEI_CLINT,
    NUCLEI_DRAM,
    NUCLEI_RTC,
    NUCLEI_SPI,
    NUCLEI_GPIO,
    NUCLEI_DMA,
    NUCLEI_USBFS
};

// TODO: Add riscv64 support
#if defined(TARGET_RISCV32)
#define NUCLEI_gd32vf103_CPU TYPE_RISCV_CPU_NUCLEI_rvstar
#elif defined(TARGET_RISCV64)
#endif

#endif
