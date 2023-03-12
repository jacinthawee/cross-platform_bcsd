
void cleanup3_LHASH_DOALL(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((int)param_1 + 4) + 8) + -1;
  *(int *)(*(int *)((int)param_1 + 4) + 8) = iVar1;
  if (iVar1 == 0) {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)();
  }
  CRYPTO_free(param_1);
  return;
}

