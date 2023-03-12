
void CRYPTO_lock(int mode,int type,char *file,int line)

{
  bool bVar1;
  code *pcVar2;
  CRYPTO_dynlock_value *pCVar3;
  char *pcVar4;
  int iVar5;
  char *i;
  int iVar6;
  undefined4 uStack_20;
  
  if (-1 < type) {
    if (locking_callback == (code *)0x0) {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x004bcc74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*locking_callback)();
    return;
  }
  if (dynlock_lock_callback == (code *)0x0) {
    return;
  }
  iVar6 = line;
  pCVar3 = CRYPTO_get_dynlock_value(type);
  if (pCVar3 != (CRYPTO_dynlock_value *)0x0) {
    (*dynlock_lock_callback)(mode,pCVar3,file,line);
    CRYPTO_destroy_dynlockid(type);
    return;
  }
  i = "pointer != NULL";
  iVar5 = 0x24d;
  pcVar4 = s_cryptlib_c_0064cbb4;
  OpenSSLDie(s_cryptlib_c_0064cbb4,0x24d,"pointer != NULL");
  if (add_lock_callback == (code *)0x0) {
    if ((int)i < 0) {
      if (dynlock_lock_callback != (code *)0x0) {
        pCVar3 = CRYPTO_get_dynlock_value((int)i);
        if (pCVar3 != (CRYPTO_dynlock_value *)0x0) {
          (*dynlock_lock_callback)(9,pCVar3,iVar6,uStack_20);
          CRYPTO_destroy_dynlockid((int)i);
          bVar1 = dynlock_lock_callback == (code *)0x0;
          *(int *)pcVar4 = iVar5 + *(int *)pcVar4;
          if (bVar1) {
            return;
          }
          pCVar3 = CRYPTO_get_dynlock_value((int)i);
          if (pCVar3 != (CRYPTO_dynlock_value *)0x0) {
            (*dynlock_lock_callback)(10,pCVar3,iVar6,uStack_20);
            CRYPTO_destroy_dynlockid((int)i);
            return;
          }
        }
        OpenSSLDie(s_cryptlib_c_0064cbb4,0x24d,"pointer != NULL");
        return;
      }
    }
    else if (locking_callback != (code *)0x0) {
      (*locking_callback)(9,i,iVar6,uStack_20);
      pcVar2 = locking_callback;
      bVar1 = locking_callback == (code *)0x0;
      *(int *)pcVar4 = iVar5 + *(int *)pcVar4;
      if (bVar1) {
        return;
      }
      (*pcVar2)(10,i,iVar6,uStack_20);
      return;
    }
    *(int *)pcVar4 = iVar5 + *(int *)pcVar4;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004bcd88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*add_lock_callback)();
  return;
}

