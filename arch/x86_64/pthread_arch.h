static inline struct pthread *__pthread_self()
{
  //return *(struct pthread * volatile *)0;
	struct pthread *self;
	__asm__ ("mov %%fs:0,%0" : "=r" (self) );
	return self;
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[REG_RIP]
