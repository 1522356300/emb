
# 上电流程
- arch/arm64/kernel/head.S
	```c
	_head:
		b	primary_entry    // branch to kernel start, magic , 第一行即跳转
	```
	- primary_entry
		```c
		SYM_CODE_START(primary_entry)
			bl	preserve_boot_args  
			bl	el2_setup			// Drop to EL1, w0=cpu_boot_mode
			adrp	x23, __PHYS_OFFSET
			and	x23, x23, MIN_KIMG_ALIGN - 1	// KASLR offset, defaults to 0
			bl	set_cpu_boot_mode_flag
			bl	__create_page_tables	//创建页表，避免脏页
			bl	__cpu_setup				// initialise processor
			b	__primary_switch		//executed with the MMU enabled
		SYM_CODE_END(primary_entry)
		```
	- secondary_entry
		- Secondary entry point that jumps straight into the kernel. Only to be used where CPUs are brought online dynamically by the kernel.
