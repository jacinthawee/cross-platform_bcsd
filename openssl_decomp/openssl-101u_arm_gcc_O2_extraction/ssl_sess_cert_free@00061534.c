
void ssl_sess_cert_free(_STACK **param_1)

{
  int iVar1;
  X509 *a;
  int iVar2;
  
  if (param_1 != (_STACK **)0x0) {
    iVar1 = CRYPTO_add_lock((int *)(param_1 + 0x1e),-1,0xf,"ssl_cert.c",0x19f);
    if (iVar1 < 1) {
      if (*param_1 != (_STACK *)0x0) {
        sk_pop_free(*param_1,X509_free);
      }
      iVar1 = 0;
      do {
        iVar2 = iVar1 + 0xc;
        a = *(X509 **)((int)param_1 + iVar1 + 0xc);
        if (a != (X509 *)0x0) {
          X509_free(a);
        }
        iVar1 = iVar2;
      } while (iVar2 != 0x60);
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
