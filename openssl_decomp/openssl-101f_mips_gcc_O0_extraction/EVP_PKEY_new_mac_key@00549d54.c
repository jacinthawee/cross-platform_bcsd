
EVP_PKEY * EVP_PKEY_new_mac_key(int type,ENGINE *e,uchar *key,int keylen)

{
  int *ctx;
  int iVar1;
  EVP_PKEY *pkey;
  int reason;
  EVP_PKEY *pEVar2;
  code *pcVar3;
  
  ctx = (int *)EVP_PKEY_CTX_new_id(type,e);
  if (ctx == (int *)0x0) {
    return (EVP_PKEY *)0x0;
  }
  iVar1 = *ctx;
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x20) == 0)) {
    ERR_put_error(6,0x93,0x96,"pmeth_gn.c",0x7a);
  }
  else {
    pcVar3 = *(code **)(iVar1 + 0x1c);
    ctx[4] = 4;
    if ((pcVar3 == (code *)0x0) || (iVar1 = (*pcVar3)(ctx), 0 < iVar1)) {
      iVar1 = EVP_PKEY_CTX_ctrl((EVP_PKEY_CTX *)ctx,-1,4,6,keylen,key);
      if (0 < iVar1) {
        if ((*ctx == 0) || (*(int *)(*ctx + 0x20) == 0)) {
          reason = 0x96;
          iVar1 = 0x8d;
        }
        else {
          if (ctx[4] == 4) {
            pkey = EVP_PKEY_new();
            iVar1 = (**(code **)(*ctx + 0x20))(ctx,pkey);
            pEVar2 = pkey;
            if (iVar1 < 1) {
              pEVar2 = (EVP_PKEY *)0x0;
              EVP_PKEY_free(pkey);
            }
            goto LAB_00549e80;
          }
          reason = 0x97;
          iVar1 = 0x92;
        }
        ERR_put_error(6,0x92,reason,"pmeth_gn.c",iVar1);
      }
    }
    else {
      ctx[4] = 0;
    }
  }
  pEVar2 = (EVP_PKEY *)0x0;
LAB_00549e80:
  EVP_PKEY_CTX_free((EVP_PKEY_CTX *)ctx);
  return pEVar2;
}

