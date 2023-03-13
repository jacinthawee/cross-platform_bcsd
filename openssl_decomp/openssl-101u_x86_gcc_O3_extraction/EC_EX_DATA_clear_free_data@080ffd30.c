
void EC_EX_DATA_clear_free_data(void **param_1,void *param_2,void *param_3,code *param_4)

{
  void *pvVar1;
  void **ppvVar2;
  void **ppvVar3;
  
  if (param_1 != (void **)0x0) {
    ppvVar3 = (void **)*param_1;
    while (ppvVar2 = ppvVar3, ppvVar2 != (void **)0x0) {
      if (((ppvVar2[2] == param_2) && (ppvVar2[3] == param_3)) && ((code *)ppvVar2[4] == param_4)) {
        pvVar1 = *ppvVar2;
        (*param_4)(ppvVar2[1]);
        CRYPTO_free(*param_1);
        *param_1 = pvVar1;
        return;
      }
      param_1 = ppvVar2;
      ppvVar3 = (void **)*ppvVar2;
    }
  }
  return;
}

