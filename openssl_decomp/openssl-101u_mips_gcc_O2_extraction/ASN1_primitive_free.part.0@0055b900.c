
void ASN1_primitive_free_part_0(int *param_1,char *param_2)

{
  ASN1_STRING *pAVar1;
  int iVar2;
  ASN1_OBJECT *a;
  
  if (param_2 == (char *)0x0) {
    pAVar1 = (ASN1_STRING *)*param_1;
    param_1 = &pAVar1->type;
    a = (ASN1_OBJECT *)pAVar1->type;
    iVar2 = pAVar1->length;
    if (a == (ASN1_OBJECT *)0x0) {
      return;
    }
    if (iVar2 == 1) {
      pAVar1->type = -1;
      return;
    }
    if (1 < iVar2) {
      if (iVar2 == 5) goto LAB_0055b980;
      if (iVar2 == 6) goto LAB_0055ba08;
      goto LAB_0055b9a0;
    }
  }
  else {
    if (*param_2 == '\x05') {
      a = (ASN1_OBJECT *)*param_1;
      if (a == (ASN1_OBJECT *)0x0) {
        return;
      }
      goto LAB_0055b9a0;
    }
    iVar2 = *(int *)(param_2 + 4);
    if (iVar2 == 1) {
      *param_1 = (int)*(ASN1_STRING **)(param_2 + 0x14);
      return;
    }
    a = (ASN1_OBJECT *)*param_1;
    if (a == (ASN1_OBJECT *)0x0) {
      return;
    }
    if (iVar2 == 5) goto LAB_0055b980;
    if (iVar2 == 6) {
LAB_0055ba08:
      ASN1_OBJECT_free(a);
      *param_1 = 0;
      return;
    }
  }
  if (iVar2 == -4) {
    ASN1_primitive_free_part_0(param_1,0);
    (*(code *)PTR_CRYPTO_free_006a6e88)((ASN1_STRING *)*param_1);
LAB_0055b980:
    *param_1 = 0;
    return;
  }
LAB_0055b9a0:
  ASN1_STRING_free((ASN1_STRING *)a);
  *param_1 = 0;
  return;
}

