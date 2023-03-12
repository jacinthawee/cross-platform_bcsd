
int SSL_CTX_use_RSAPrivateKey_file(SSL_CTX *ctx,char *file,int type)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  RSA *rsa;
  RSA *pRVar4;
  undefined4 uVar5;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb3,7,&DAT_00649450,0x21c);
    return 0;
  }
  iVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x6c,3,file);
  if (iVar3 < 1) {
    uVar5 = 2;
    uVar1 = 0x221;
LAB_004b60d8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb3,uVar5,&DAT_00649450,uVar1);
    rsa = (RSA *)0x0;
  }
  else {
    if (type == 2) {
      rsa = (RSA *)(*(code *)PTR_d2i_RSAPrivateKey_bio_006a83d4)(iVar2,0);
      uVar1 = 0xd;
    }
    else {
      if (type != 1) {
        uVar5 = 0x7c;
        uVar1 = 0x22d;
        goto LAB_004b60d8;
      }
      rsa = (RSA *)(*(code *)PTR_PEM_read_bio_RSAPrivateKey_006a83d0)
                             (iVar2,0,ctx->default_passwd_callback,
                              ctx->default_passwd_callback_userdata);
      uVar1 = 9;
    }
    if (rsa == (RSA *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb3,uVar1,&DAT_00649450,0x231);
    }
    else {
      pRVar4 = (RSA *)SSL_CTX_use_RSAPrivateKey(ctx,rsa);
      (*(code *)PTR_RSA_free_006a7600)(rsa);
      rsa = pRVar4;
    }
  }
  (*(code *)PTR_BIO_free_006a6e70)(iVar2);
  return (int)rsa;
}

