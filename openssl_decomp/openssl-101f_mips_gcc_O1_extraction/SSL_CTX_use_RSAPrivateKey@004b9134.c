
int SSL_CTX_use_RSAPrivateKey(SSL_CTX *ctx,RSA *rsa)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (rsa == (RSA *)0x0) {
    uVar4 = 0x43;
    uVar3 = 0x210;
  }
  else {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb1,0x41,&DAT_00649ed0,0x215);
      return 0;
    }
    iVar1 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
    if (iVar1 != 0) {
      (*(code *)PTR_RSA_up_ref_006a9120)(rsa);
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar1,6,rsa);
      iVar2 = ssl_set_pkey(ctx->cert,iVar1);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar1);
      return iVar2;
    }
    uVar4 = 6;
    uVar3 = 0x21a;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb1,uVar4,&DAT_00649ed0,uVar3);
  return 0;
}

