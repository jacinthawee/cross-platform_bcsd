
int SSL_CTX_use_RSAPrivateKey(SSL_CTX *ctx,RSA *rsa)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (rsa == (RSA *)0x0) {
    uVar4 = 0x43;
    uVar3 = 0x1fc;
  }
  else {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb1,0x41,&DAT_00649450,0x200);
      return 0;
    }
    iVar1 = (*(code *)PTR_EVP_PKEY_new_006a7620)();
    if (iVar1 != 0) {
      (*(code *)PTR_RSA_up_ref_006a7f98)(rsa);
      iVar2 = (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar1,6,rsa);
      if (iVar2 < 1) {
        (*(code *)PTR_RSA_free_006a7600)(rsa);
        iVar2 = 0;
      }
      else {
        iVar2 = ssl_set_pkey(ctx->cert,iVar1);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar1);
      }
      return iVar2;
    }
    uVar4 = 6;
    uVar3 = 0x204;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb1,uVar4,&DAT_00649450,uVar3);
  return 0;
}

