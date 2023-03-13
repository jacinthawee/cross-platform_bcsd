
int EVP_PKEY_paramgen(EVP_PKEY_CTX *ctx,EVP_PKEY **ppkey)

{
  int iVar1;
  EVP_PKEY *pEVar2;
  int reason;
  code *pcVar3;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (*(int *)ctx == 0)) ||
     (pcVar3 = *(code **)(*(int *)ctx + 0x18), pcVar3 == (code *)0x0)) {
    ERR_put_error(6,0x94,0x96,"pmeth_gn.c",0x5a);
    return -2;
  }
  if (*(int *)(ctx + 0x10) == 2) {
    if (ppkey == (EVP_PKEY **)0x0) {
      return -1;
    }
    pEVar2 = *ppkey;
    if (pEVar2 == (EVP_PKEY *)0x0) {
      pEVar2 = EVP_PKEY_new();
      *ppkey = pEVar2;
      if (pEVar2 == (EVP_PKEY *)0x0) {
        reason = 0x41;
        iVar1 = 0x6a;
        goto LAB_0054681c;
      }
      pcVar3 = *(code **)(*(int *)ctx + 0x18);
    }
    iVar1 = (*pcVar3)(ctx,pEVar2);
    if (iVar1 < 1) {
      EVP_PKEY_free(*ppkey);
      *ppkey = (EVP_PKEY *)0x0;
      return iVar1;
    }
  }
  else {
    reason = 0x97;
    iVar1 = 0x5f;
LAB_0054681c:
    ERR_put_error(6,0x94,reason,"pmeth_gn.c",iVar1);
    iVar1 = -1;
  }
  return iVar1;
}

