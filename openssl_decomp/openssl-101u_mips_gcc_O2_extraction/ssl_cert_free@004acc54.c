
void ssl_cert_free(void *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 != (void *)0x0) {
    iVar2 = CRYPTO_add_lock((int *)((int)param_1 + 0x90),-1,0xd,"ssl_cert.c",0x147);
    if (iVar2 < 1) {
      if (*(int *)((int)param_1 + 0x18) != 0) {
        (*(code *)PTR_RSA_free_006a7600)();
      }
      if (*(int *)((int)param_1 + 0x20) != 0) {
        (*(code *)PTR_DH_free_006a7508)();
      }
      piVar3 = (int *)((int)param_1 + 0x30);
      if (*(int *)((int)param_1 + 0x28) != 0) {
        (*(code *)PTR_EC_KEY_free_006a71d4)();
      }
      do {
        if (*piVar3 != 0) {
          (*(code *)PTR_X509_free_006a6e90)();
        }
        piVar1 = piVar3 + 1;
        piVar3 = piVar3 + 3;
        if (*piVar1 != 0) {
          (*(code *)PTR_EVP_PKEY_free_006a6e78)();
        }
      } while ((int *)((int)param_1 + 0x90) != piVar3);
      CRYPTO_free(param_1);
      return;
    }
  }
  return;
}

