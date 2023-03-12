
void cleanup3_LHASH_DOALL(void *param_1)

{
  int *piVar1;
  ASN1_OBJECT *a;
  
  a = *(ASN1_OBJECT **)((int)param_1 + 4);
  piVar1 = &a->nid;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    ASN1_OBJECT_free(a);
  }
  CRYPTO_free(param_1);
  return;
}

