#ifndef CONFIG_UID16

#define OVERRIDE_32_getuid16
#define OVERRIDE_32_getgid16
#define OVERRIDE_32_geteuid16
#define OVERRIDE_32_getegid16
#define OVERRIDE_32_setuid16
#define OVERRIDE_32_setgid16
#define OVERRIDE_32_setfsuid16
#define OVERRIDE_32_setfsgid16
#define OVERRIDE_32_setreuid16
#define OVERRIDE_32_setregid16
#define OVERRIDE_32_fchown16
#define OVERRIDE_32_setresuid16
#define OVERRIDE_32_setresgid16

#define OVERRIDE_TABLE_32_getuid16
#define OVERRIDE_TABLE_32_getgid16
#define OVERRIDE_TABLE_32_geteuid16
#define OVERRIDE_TABLE_32_getegid16
#define OVERRIDE_TABLE_32_setuid16
#define OVERRIDE_TABLE_32_setgid16
#define OVERRIDE_TABLE_32_setreuid16
#define OVERRIDE_TABLE_32_setregid16
#define OVERRIDE_TABLE_32_fchown16
#define OVERRIDE_TABLE_32_setfsuid16
#define OVERRIDE_TABLE_32_setfsgid16
#define OVERRIDE_TABLE_32_setresuid16
#define OVERRIDE_TABLE_32_setresgid16

#endif

#ifndef CREATE_SYSCALL_TABLE

/* mmap_pgoff is kernel internal. mmap2 is exposed in unistd.h. */
#define OVERRIDE_32_mmap_pgoff
#define OVERRIDE_32_mmap2
SC_LTTNG_TRACEPOINT_EVENT(mmap2,
	TP_PROTO(sc_exit(unsigned long ret,)
		unsigned long addr, unsigned long len,
		unsigned long prot, unsigned long flags,
		unsigned long fd, unsigned long pgoff),
	TP_ARGS(sc_exit(ret,) addr, len, prot, flags, fd, pgoff),
	TP_FIELDS(sc_exit(ctf_integer_hex(unsigned long, ret, ret))
		sc_in(ctf_integer_hex(unsigned long, addr, addr))
		sc_in(ctf_integer(size_t, len, len))
		sc_in(ctf_integer(int, prot, prot))
		sc_in(ctf_integer(int, flags, flags))
		sc_in(ctf_integer(int, fd, fd))
		sc_in(ctf_integer(off_t, pgoff, pgoff))
	)
)

#else /* #ifndef CREATE_SYSCALL_TABLE */

#define OVERRIDE_TABLE_32_mmap
TRACE_SYSCALL_TABLE(mmap, mmap, 90, 6)

/* mmap_pgoff is kernel internal. mmap2 is exposed in unistd.h. */
#define OVERRIDE_TABLE_32_mmap_pgoff
#define OVERRIDE_TABLE_32_mmap2
TRACE_SYSCALL_TABLE(mmap2, mmap2, 192, 6)

#endif /* #else #ifndef CREATE_SYSCALL_TABLE */
