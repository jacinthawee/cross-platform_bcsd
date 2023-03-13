
void ssl_cert_free(void *param_1)

{
  int iVar1;
  X509 **ppXVar2;
  
  if (param_1 != (void *)0x0) {
    iVar1 = CRYPTO_add_lock((int *)(X509 **)((int)param_1 + 0x90),-1,0xd,"ssl_cert.c",0x147);
    if (iVar1 < 1) {
      if (*(RSA **)((int)param_1 + 0x18) != (RSA *)0x0) {
        RSA_free(*(RSA **)((int)param_1 + 0x18));
      }
      if (*(DH **)((int)param_1 + 0x20) != (DH *)0x0) {
        DH_free(*(DH **)((int)param_1 + 0x20));
      }
      if (*(EC_KEY **)((int)param_1 + 0x28) != (EC_KEY *)0x0) {
        EC_KEY_free(*(EC_KEY **)((int)param_1 + 0x28));
      }
      ppXVar2 = (X509 **)((int)param_1 + 0x30);
      do {
        if (*ppXVar2 != (X509 *)0x0) {
          X509_free(*ppXVar2);
        }
        if (ppXVar2[1] != (X509 *)0x0) {
          EVP_PKEY_free((EVP_PKEY *)ppXVar2[1]);
        }
        ppXVar2 = ppXVar2 + 3;
      } while (ppXVar2 != (X509 **)((int)param_1 + 0x90));
      CRYPTO_free(param_1);
      return;
    }
  }
  return;
}

