
int SSL_use_RSAPrivateKey(SSL *ssl,RSA *rsa)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (rsa == (RSA *)0x0) {
    uVar4 = 0x43;
    uVar3 = 0x96;
  }
  else {
    iVar1 = ssl_cert_inst(&ssl->cert);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xcc,0x41,&DAT_00649450,0x9a);
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
        iVar2 = ssl_set_pkey(ssl->cert,iVar1);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar1);
      }
      return iVar2;
    }
    uVar4 = 6;
    uVar3 = 0x9e;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xcc,uVar4,&DAT_00649450,uVar3);
  return 0;
}

