
void ssl_sess_cert_free(_STACK **param_1)

{
  int iVar1;
  X509 **ppXVar2;
  
  if (param_1 != (_STACK **)0x0) {
    iVar1 = CRYPTO_add_lock((int *)(param_1 + 0x1e),-1,0xf,"ssl_cert.c",0x1ca);
    if (iVar1 < 1) {
      if (*param_1 != (_STACK *)0x0) {
        sk_pop_free(*param_1,X509_free);
      }
      ppXVar2 = (X509 **)(param_1 + 3);
      do {
        if (*ppXVar2 != (X509 *)0x0) {
          X509_free(*ppXVar2);
        }
        ppXVar2 = ppXVar2 + 3;
      } while (ppXVar2 != (X509 **)(param_1 + 0x1b));
      if ((RSA *)param_1[0x1b] != (RSA *)0x0) {
        RSA_free((RSA *)param_1[0x1b]);
      }
      if ((DH *)param_1[0x1c] != (DH *)0x0) {
        DH_free((DH *)param_1[0x1c]);
      }
      if (param_1[0x1d] != (_STACK *)0x0) {
        EC_KEY_free((EC_KEY *)param_1[0x1d]);
      }
      CRYPTO_free(param_1);
      return;
    }
  }
  return;
}

