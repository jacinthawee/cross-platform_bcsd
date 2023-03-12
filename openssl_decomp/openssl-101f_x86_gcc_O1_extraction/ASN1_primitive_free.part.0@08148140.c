
void __regparm3 ASN1_primitive_free_part_0(int *param_1,char *param_2)

{
  ASN1_STRING *pAVar1;
  ASN1_OBJECT *a;
  int iVar2;
  
  if (param_2 == (char *)0x0) {
    pAVar1 = (ASN1_STRING *)*param_1;
    a = (ASN1_OBJECT *)pAVar1->type;
    iVar2 = pAVar1->length;
    param_1 = &pAVar1->type;
    if (a == (ASN1_OBJECT *)0x0) {
      return;
    }
    if (iVar2 == 1) {
      pAVar1->type = -1;
      return;
    }
    if (1 < iVar2) {
      if (iVar2 == 5) goto LAB_08148182;
      if (iVar2 == 6) goto LAB_081481df;
      goto LAB_08148196;
    }
  }
  else {
    if (*param_2 == '\x05') {
      a = (ASN1_OBJECT *)*param_1;
      if (a == (ASN1_OBJECT *)0x0) {
        return;
      }
      goto LAB_08148196;
    }
    iVar2 = *(int *)(param_2 + 4);
    if (iVar2 == 1) {
      *param_1 = (int)*(void **)(param_2 + 0x14);
      return;
    }
    a = (ASN1_OBJECT *)*param_1;
    if (a == (ASN1_OBJECT *)0x0) {
      return;
    }
    if (iVar2 == 5) goto LAB_08148182;
    if (iVar2 == 6) {
LAB_081481df:
      ASN1_OBJECT_free(a);
      *param_1 = 0;
      return;
    }
  }
  if (iVar2 == -4) {
    ASN1_primitive_free_part_0();
    CRYPTO_free((void *)*param_1);
LAB_08148182:
    *param_1 = 0;
    return;
  }
LAB_08148196:
  ASN1_STRING_free((ASN1_STRING *)a);
  *param_1 = 0;
  *param_1 = 0;
  return;
}

