
/* WARNING: Removing unreachable block (ram,0x080d24f8) */
/* WARNING: Removing unreachable block (ram,0x080d2506) */
/* WARNING: Removing unreachable block (ram,0x080d251a) */
/* WARNING: Removing unreachable block (ram,0x080d2545) */
/* WARNING: Removing unreachable block (ram,0x080d2589) */
/* WARNING: Removing unreachable block (ram,0x080d2559) */

void __regparm1 CRYPTO_lock(int mode,int type,char *file,int line)

{
  code *pcVar1;
  CRYPTO_dynlock_value *pCVar2;
  bool bVar3;
  char **ppcVar4;
  char *pcVar5;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if ((int)file < 0) {
    if (dynlock_lock_callback != (code *)0x0) {
      pCVar2 = CRYPTO_get_dynlock_value((int)file);
      if (pCVar2 != (CRYPTO_dynlock_value *)0x0) {
        (*dynlock_lock_callback)(type,pCVar2,line);
        CRYPTO_destroy_dynlockid((int)file);
        return;
      }
      pcVar5 = "pointer != NULL";
      ppcVar4 = (char **)&DAT_00000253;
      OpenSSLDie("cryptlib.c",0x253,"pointer != NULL");
      if (add_lock_callback == (code *)0x0) {
        if (locking_callback == (code *)0x0) {
          *ppcVar4 = pcVar5 + (int)*ppcVar4;
        }
        else {
          (*locking_callback)(9,0,uStack_1c,uStack_18);
          pcVar1 = locking_callback;
          bVar3 = locking_callback != (code *)0x0;
          *ppcVar4 = pcVar5 + (int)*ppcVar4;
          if (bVar3) {
            (*pcVar1)(10,0,uStack_1c,uStack_18);
          }
        }
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x080d24ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*add_lock_callback)();
      return;
    }
  }
  else if (locking_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x080d241b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*locking_callback)();
    return;
  }
  return;
}

