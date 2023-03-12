
EVP_PKEY * EVP_PKEY_new_mac_key(int type,ENGINE *e,uchar *key,int keylen)

{
  EVP_PKEY_CTX *ctx;
  EVP_PKEY *pkey;
  int iVar1;
  code *pcVar2;
  int iVar3;
  EVP_PKEY *pEVar4;
  
  iVar3 = keylen;
  ctx = EVP_PKEY_CTX_new_id(type,e);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    return (EVP_PKEY *)0x0;
  }
  iVar1 = *(int *)&ctx->field_0x0;
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x20) == 0)) {
    ERR_put_error(6,0x93,0x96,"pmeth_gn.c",0x7a);
  }
  else {
    pcVar2 = *(code **)(iVar1 + 0x1c);
    *(undefined **)(ctx + 0x10) = &DAT_00000004;
    if (pcVar2 != (code *)0x0) {
      iVar1 = (*pcVar2)();
      if (iVar1 < 1) {
        iVar3 = 0;
      }
      if (iVar1 < 1) {
        *(int *)(ctx + 0x10) = iVar3;
        goto LAB_000b1fba;
      }
    }
    iVar3 = EVP_PKEY_CTX_ctrl(ctx,-1,4,6,keylen,key);
    if (0 < iVar3) {
      if ((*(int *)&ctx->field_0x0 == 0) || (*(int *)(*(int *)&ctx->field_0x0 + 0x20) == 0)) {
        pEVar4 = (EVP_PKEY *)0x0;
        ERR_put_error(6,0x92,0x96,"pmeth_gn.c",0x8d);
      }
      else if (*(undefined **)(ctx + 0x10) == &DAT_00000004) {
        pkey = EVP_PKEY_new();
        iVar3 = (**(code **)(*(int *)&ctx->field_0x0 + 0x20))(ctx,pkey);
        pEVar4 = pkey;
        if (iVar3 < 1) {
          pEVar4 = (EVP_PKEY *)0x0;
          EVP_PKEY_free(pkey);
        }
      }
      else {
        pEVar4 = (EVP_PKEY *)0x0;
        ERR_put_error(6,0x92,0x97,"pmeth_gn.c",0x92);
      }
      goto LAB_000b1fbc;
    }
  }
LAB_000b1fba:
  pEVar4 = (EVP_PKEY *)0x0;
LAB_000b1fbc:
  EVP_PKEY_CTX_free(ctx);
  return pEVar4;
}

