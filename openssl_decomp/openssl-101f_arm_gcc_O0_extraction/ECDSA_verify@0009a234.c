
int ECDSA_verify(int type,uchar *dgst,int dgstlen,uchar *sig,int siglen,EC_KEY *eckey)

{
  ECDSA_SIG *pEVar1;
  ECDSA_SIG *pEVar2;
  int iVar3;
  uchar *local_24 [2];
  ECDSA_SIG *local_1c [2];
  
  local_24[0] = sig;
  local_1c[0] = ECDSA_SIG_new();
  if (local_1c[0] == (ECDSA_SIG *)0x0) {
    iVar3 = -1;
  }
  else {
    pEVar2 = d2i_ECDSA_SIG(local_1c,local_24,siglen);
    pEVar1 = local_1c[0];
    if (pEVar2 == (ECDSA_SIG *)0x0) {
      iVar3 = -1;
    }
    else {
      iVar3 = ecdsa_check(eckey);
      if (iVar3 != 0) {
        iVar3 = (**(code **)(*(int *)(iVar3 + 0xc) + 0xc))(dgst,dgstlen,pEVar1,eckey);
      }
    }
    ECDSA_SIG_free(local_1c[0]);
  }
  return iVar3;
}

