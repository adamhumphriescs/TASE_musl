//Altered for TASE.  We inserted a call that will trap so we can avoid the inline assembly,
//and in the future possibly do some environment modeling.

extern void * __pthread_self_tase();

static inline struct pthread *__pthread_self()
{
  /*
	struct pthread *self;
	__asm__ ("mov %%fs:0,%0" : "=r" (self) );
	return self;
  */
  return (struct pthread *) __pthread_self_tase();
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[REG_RIP]
