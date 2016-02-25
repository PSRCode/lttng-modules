#ifndef CREATE_SYSCALL_TABLE

#define OVERRIDE_32_mmap2
SC_LTTNG_TRACEPOINT_EVENT(mmap2,
	TP_PROTO(sc_exit(long ret,)
		unsigned long addr, unsigned long len,
		unsigned long prot, unsigned long flags,
		unsigned long fd, unsigned long pgoff),
	TP_ARGS(sc_exit(ret,) addr, len, prot, flags, fd, pgoff),
	TP_FIELDS(sc_exit(ctf_integer(long, ret, ret))
		sc_in(ctf_integer_hex(unsigned long, addr, addr))
		sc_in(ctf_integer(size_t, len, len))
		sc_in(ctf_integer(int, prot, prot))
		sc_in(ctf_integer(int, flags, flags))
		sc_in(ctf_integer(int, fd, fd))
		sc_in(ctf_integer(off_t, pgoff, pgoff))
	)
)

#else	/* CREATE_SYSCALL_TABLE */

#define OVERRIDE_TABLE_32_mmap
TRACE_SYSCALL_TABLE(mmap, mmap, 90, 6)
#define OVERRIDE_TABLE_32_mmap2
TRACE_SYSCALL_TABLE(mmap2, mmap2, 192, 6)

#endif /* CREATE_SYSCALL_TABLE */

