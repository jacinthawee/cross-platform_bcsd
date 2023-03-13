
int X509_TRUST_set(int *t,int trust)

{
  int iVar1;
  int in_GS_OFFSET;
  int local_28 [6];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (trust - 1U < 8) {
LAB_08165851:
    *t = trust;
    iVar1 = 1;
  }
  else {
    local_28[0] = trust;
    if (trtable != (_STACK *)0x0) {
      iVar1 = sk_find(trtable,local_28);
      if ((iVar1 != -1) && (iVar1 != -9)) goto LAB_08165851;
    }
    ERR_put_error(0xb,0x8d,0x7b,"x509_trs.c",0xa3);
    iVar1 = 0;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

