
void CRYPTO_THREADID_current(CRYPTO_THREADID *id)

{
  ulong uVar1;
  int *piVar2;
  
  if (threadid_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x080cfc75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*threadid_callback)();
    return;
  }
  if (id_callback == (code *)0x0) {
    piVar2 = __errno_location();
    id->ptr = piVar2;
    id->val = (ulong)piVar2;
  }
  else {
    uVar1 = (*id_callback)();
    id->ptr = (void *)0x0;
    id->val = uVar1;
  }
  return;
}

