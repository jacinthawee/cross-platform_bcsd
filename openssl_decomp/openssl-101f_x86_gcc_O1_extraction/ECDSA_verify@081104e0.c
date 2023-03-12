
int ECDSA_verify(int type,uchar *dgst,int dgstlen,uchar *sig,int siglen,EC_KEY *eckey)

{
  ECDSA_SIG *pEVar1;
  ECDSA_SIG *pEVar2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  uchar *local_30 [3];
  ECDSA_SIG *local_24;
  int local_20;
  
  local_30[0] = sig;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = ECDSA_SIG_new();
  if (local_24 == (ECDSA_SIG *)0x0) {
    iVar4 = -1;
  }
  else {
    iVar4 = -1;
    pEVar2 = d2i_ECDSA_SIG(&local_24,local_30,siglen);
    pEVar1 = local_24;
    if (pEVar2 != (ECDSA_SIG *)0x0) {
      iVar4 = 0;
      iVar3 = ecdsa_check(eckey);
      if (iVar3 != 0) {
        iVar4 = (**(code **)(*(int *)(iVar3 + 0xc) + 0xc))(dgst,dgstlen,pEVar1,eckey);
      }
    }
    ECDSA_SIG_free(local_24);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

