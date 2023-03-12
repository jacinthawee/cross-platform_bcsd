
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong CRYPTO_thread_id(void)

{
  ulong uVar1;
  
  if (id_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004bcac4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*id_callback)();
    return uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x004bcad4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR_getpid_006a9a68)();
  return uVar1;
}

