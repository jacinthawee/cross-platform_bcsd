
undefined4 __regparm3
pkcs7_decrypt_rinfo(uchar **param_1_00,size_t *param_2,void *param_3,EVP_PKEY *param_1)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  uchar *out;
  undefined4 uVar2;
  int in_GS_OFFSET;
  int line;
  size_t local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = EVP_PKEY_CTX_new(param_1,(ENGINE *)0x0);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    uVar2 = 0xffffffff;
    goto LAB_0817dcb3;
  }
  iVar1 = EVP_PKEY_decrypt_init(ctx);
  if (iVar1 < 1) {
LAB_0817dca0:
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x200,4,0,param_3);
    if (iVar1 < 1) {
      line = 0xdb;
      iVar1 = 0x98;
LAB_0817dce2:
      uVar2 = 0xffffffff;
      ERR_put_error(0x21,0x85,iVar1,"pk7_doit.c",line);
    }
    else {
      iVar1 = EVP_PKEY_decrypt(ctx,(uchar *)0x0,&local_24,
                               (uchar *)(*(size_t **)((int)param_3 + 0xc))[2],
                               **(size_t **)((int)param_3 + 0xc));
      if (iVar1 < 1) goto LAB_0817dca0;
      out = (uchar *)CRYPTO_malloc(local_24,"pk7_doit.c",0xe3);
      if (out == (uchar *)0x0) {
        line = 0xe7;
        iVar1 = 0x41;
        goto LAB_0817dce2;
      }
      iVar1 = EVP_PKEY_decrypt(ctx,out,&local_24,(uchar *)(*(size_t **)((int)param_3 + 0xc))[2],
                               **(size_t **)((int)param_3 + 0xc));
      if (iVar1 < 1) {
        ERR_put_error(0x21,0x85,6,"pk7_doit.c",0xef);
        EVP_PKEY_CTX_free(ctx);
        CRYPTO_free(out);
        uVar2 = 0;
        goto LAB_0817dcb3;
      }
      if (*param_1_00 != (uchar *)0x0) {
        OPENSSL_cleanse(*param_1_00,*param_2);
        CRYPTO_free(*param_1_00);
      }
      uVar2 = 1;
      *param_1_00 = out;
      *param_2 = local_24;
    }
  }
  EVP_PKEY_CTX_free(ctx);
LAB_0817dcb3:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

