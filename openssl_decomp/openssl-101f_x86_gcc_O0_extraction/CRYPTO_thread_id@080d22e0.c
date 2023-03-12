
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong CRYPTO_thread_id(void)

{
  ulong uVar1;
  
  if (id_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x080d22e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*id_callback)();
    return uVar1;
  }
  uVar1 = getpid();
  return uVar1;
}

