
EVP_PKEY * EVP_PKEY_new_mac_key(int type,ENGINE *e,uchar *key,int keylen)

{
  code *pcVar1;
  int *ctx;
  int iVar2;
  EVP_PKEY *pkey;
  int line;
  
  ctx = (int *)EVP_PKEY_CTX_new_id(type,e);
  if (ctx == (int *)0x0) {
    return (EVP_PKEY *)0x0;
  }
  iVar2 = *ctx;
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x20) == 0)) {
    ERR_put_error(6,0x93,0x96,"pmeth_gn.c",0x7b);
  }
  else {
    pcVar1 = *(code **)(iVar2 + 0x1c);
    ctx[4] = 4;
    if ((pcVar1 == (code *)0x0) || (iVar2 = (*pcVar1)(ctx), 0 < iVar2)) {
      iVar2 = EVP_PKEY_CTX_ctrl((EVP_PKEY_CTX *)ctx,-1,4,6,keylen,key);
      if (0 < iVar2) {
        if ((*ctx == 0) || (*(int *)(*ctx + 0x20) == 0)) {
          line = 0x8d;
          iVar2 = 0x96;
        }
        else {
          if (ctx[4] == 4) {
            pkey = EVP_PKEY_new();
            iVar2 = (**(code **)(*ctx + 0x20))(ctx,pkey);
            if (0 < iVar2) goto LAB_08134e9a;
            EVP_PKEY_free(pkey);
            goto LAB_08134e98;
          }
          line = 0x91;
          iVar2 = 0x97;
        }
        pkey = (EVP_PKEY *)0x0;
        ERR_put_error(6,0x92,iVar2,"pmeth_gn.c",line);
        goto LAB_08134e9a;
      }
    }
    else {
      ctx[4] = 0;
    }
  }
LAB_08134e98:
  pkey = (EVP_PKEY *)0x0;
LAB_08134e9a:
  EVP_PKEY_CTX_free((EVP_PKEY_CTX *)ctx);
  return pkey;
}

