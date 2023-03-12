
void CRYPTO_THREADID_current(CRYPTO_THREADID *id)

{
  ulong uVar1;
  void *pvVar2;
  
  if (threadid_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004bfb4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*threadid_callback)();
    return;
  }
  if (id_callback == (code *)0x0) {
    pvVar2 = (void *)(*(code *)PTR___errno_location_006aaaf4)();
    id->ptr = pvVar2;
    id->val = (ulong)pvVar2;
  }
  else {
    uVar1 = (*id_callback)();
    *(undefined *)&id->ptr = 0;
    *(undefined *)((int)&id->ptr + 1) = 0;
    *(undefined *)((int)&id->ptr + 2) = 0;
    *(undefined *)((int)&id->ptr + 3) = 0;
    id->val = uVar1;
  }
  return;
}

