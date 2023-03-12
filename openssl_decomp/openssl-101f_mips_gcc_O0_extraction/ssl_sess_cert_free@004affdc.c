
void ssl_sess_cert_free(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != (int *)0x0) &&
     (iVar1 = CRYPTO_add_lock(param_1 + 0x1e,-1,0xf,"ssl_cert.c",0x1ca), iVar1 < 1)) {
    if (*param_1 != 0) {
      (*(code *)PTR_sk_pop_free_006a8158)(*param_1,PTR_X509_free_006a7f90);
    }
    piVar2 = param_1 + 3;
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 3;
      if (iVar1 != 0) {
        (*(code *)PTR_X509_free_006a7f90)();
      }
    } while (piVar2 != param_1 + 0x1b);
    if (param_1[0x1b] != 0) {
      (*(code *)PTR_RSA_free_006a86f0)();
    }
    if (param_1[0x1c] != 0) {
      (*(code *)PTR_DH_free_006a8604)();
    }
    if (param_1[0x1d] != 0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)();
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

