
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ERR_STATE * ERR_get_state(void)

{
  ERR_STATE *pEVar1;
  ERR_STATE *dest;
  void *ptr;
  ERR_STATE *pEVar2;
  int iVar3;
  void *pvVar4;
  CRYPTO_THREADID CStack_1b0;
  CRYPTO_THREADID aCStack_1a8 [50];
  
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  CRYPTO_THREADID_current(&CStack_1b0);
  CRYPTO_THREADID_cpy(aCStack_1a8,&CStack_1b0);
  pEVar1 = (ERR_STATE *)(**(code **)(err_fns + 0x1c))(aCStack_1a8);
  if ((pEVar1 == (ERR_STATE *)0x0) &&
     (dest = (ERR_STATE *)CRYPTO_malloc(400,"err.c",0x403),
     pEVar1 = (ERR_STATE *)PTR_fallback_8214_000a4e80, dest != (ERR_STATE *)0x0)) {
    CRYPTO_THREADID_cpy((CRYPTO_THREADID *)dest,&CStack_1b0);
    dest->top = 0;
    dest->bottom = 0;
    memset(dest->err_data,0,0x40);
    memset(dest->err_data_flags,0,0x40);
    ptr = (void *)(**(code **)(err_fns + 0x20))(dest);
    pEVar1 = (ERR_STATE *)(**(code **)(err_fns + 0x1c))(dest);
    if (pEVar1 == dest) {
      if (ptr != (void *)0x0) {
        iVar3 = 0x10;
        pvVar4 = ptr;
        do {
          if ((*(void **)((int)pvVar4 + 0x88) != (void *)0x0) &&
             (*(int *)((int)pvVar4 + 200) << 0x1f < 0)) {
            CRYPTO_free(*(void **)((int)pvVar4 + 0x88));
            *(undefined4 *)((int)pvVar4 + 0x88) = 0;
          }
          iVar3 = iVar3 + -1;
          *(undefined4 *)((int)pvVar4 + 200) = 0;
          pvVar4 = (void *)((int)pvVar4 + 4);
        } while (iVar3 != 0);
        CRYPTO_free(ptr);
      }
    }
    else {
      iVar3 = 0x10;
      pEVar2 = dest;
      do {
        if ((pEVar2->err_data[0] != (char *)0x0) && (pEVar2->err_data_flags[0] << 0x1f < 0)) {
          CRYPTO_free(pEVar2->err_data[0]);
          pEVar2->err_data[0] = (char *)0x0;
        }
        iVar3 = iVar3 + -1;
        pEVar2->err_data_flags[0] = 0;
        pEVar1 = (ERR_STATE *)PTR_fallback_8214_000a4e80;
        pEVar2 = (ERR_STATE *)&(pEVar2->tid).val;
      } while (iVar3 != 0);
      CRYPTO_free(dest);
    }
  }
  return pEVar1;
}

