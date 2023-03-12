
void OPENSSL_cpuid_setup(void)

{
  char *__nptr;
  int iVar1;
  sigset_t sStack_1b0;
  sigaction sStack_130;
  sigaction local_a4;
  
  if (trigger_6831 == 0) {
    trigger_6831 = 1;
    __nptr = getenv("OPENSSL_armcap");
    if (__nptr == (char *)0x0) {
      sigfillset((sigset_t *)all_masked);
      sigdelset((sigset_t *)all_masked,4);
      sigdelset((sigset_t *)all_masked,5);
      sigdelset((sigset_t *)all_masked,8);
      sigdelset((sigset_t *)all_masked,7);
      sigdelset((sigset_t *)all_masked,0xb);
      OPENSSL_armcap_P = __nptr;
      memset(&local_a4,0,0x8c);
      local_a4.__sigaction_handler.sa_handler = ill_handler + 1;
      memcpy(&local_a4.sa_mask,all_masked,0x80);
      sigprocmask(2,&local_a4.sa_mask,&sStack_1b0);
      sigaction(4,&local_a4,&sStack_130);
      iVar1 = __sigsetjmp(&ill_jmp,1);
      if (iVar1 == 0) {
        func_0x0006e1a0();
        OPENSSL_armcap_P = (char *)((uint)OPENSSL_armcap_P | 1);
      }
      iVar1 = __sigsetjmp(&ill_jmp,1);
      if (iVar1 == 0) {
        _armv7_tick();
        OPENSSL_armcap_P = (char *)((uint)OPENSSL_armcap_P | 2);
      }
      sigaction(4,&sStack_130,(sigaction *)0x0);
      sigprocmask(2,&sStack_1b0,(sigset_t *)0x0);
    }
    else {
      OPENSSL_armcap_P = (char *)strtoul(__nptr,(char **)0x0,0);
    }
  }
  return;
}

