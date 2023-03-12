
void ssl_cert_free(void *param_1)

{
  EVP_PKEY **ppEVar1;
  int iVar2;
  void *pvVar3;
  
  if (param_1 != (void *)0x0) {
    iVar2 = CRYPTO_add_lock((int *)((int)param_1 + 0x90),-1,0xd,"ssl_cert.c",0x147);
    if (iVar2 < 1) {
      if (*(RSA **)((int)param_1 + 0x18) != (RSA *)0x0) {
        RSA_free(*(RSA **)((int)param_1 + 0x18));
      }
      if (*(DH **)((int)param_1 + 0x20) != (DH *)0x0) {
        DH_free(*(DH **)((int)param_1 + 0x20));
      }
      if (*(EC_KEY **)((int)param_1 + 0x28) != (EC_KEY *)0x0) {
        EC_KEY_free(*(EC_KEY **)((int)param_1 + 0x28));
      }
      iVar2 = 0;
      pvVar3 = param_1;
      do {
        iVar2 = iVar2 + 1;
        if (*(X509 **)((int)pvVar3 + 0x30) != (X509 *)0x0) {
          X509_free(*(X509 **)((int)pvVar3 + 0x30));
        }
        ppEVar1 = (EVP_PKEY **)((int)pvVar3 + 0x34);
        pvVar3 = (void *)((int)pvVar3 + 0xc);
        if (*ppEVar1 != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(*ppEVar1);
        }
      } while (iVar2 != 8);
      CRYPTO_free(param_1);
      return;
    }
  }
  return;
}

