// SPDX-License-Identifier: GPL-2.0-or-later
/* Author: Alexander Shiyan <shc_work@mail.ru> */

#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <linux/of_platform.h>

#include "common.h"
#include "hardware.h"

#define MX21_AVIC_ADDR	0x10040000

static void __init imx21_init_early(void)
{
	mxc_set_cpu_type(MXC_CPU_MX21);
}

static void __init imx21_init_irq(void)
{
	void __iomem *avic = ioremap(MX21_AVIC_ADDR, SZ_4K);

	WARN_ON(!avic);

	mxc_init_irq(avic);
}

static const char * const imx21_dt_board_compat[] __initconst = {
	"fsl,imx21",
	NULL
};

DT_MACHINE_START(IMX21_DT, "Freescale i.MX21 (Device Tree Support)")
	.init_early	= imx21_init_early,
	.init_irq	= imx21_init_irq,
	.dt_compat	= imx21_dt_board_compat,
MACHINE_END
