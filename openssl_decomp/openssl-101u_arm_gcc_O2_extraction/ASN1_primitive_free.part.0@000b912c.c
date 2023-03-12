
void ASN1_primitive_free_part_0(char ***param_1,char *param_2)

{
  ASN1_OBJECT *a;
  char *pcVar1;
  ASN1_OBJECT *pAVar2;
  
  if (param_2 == (char *)0x0) {
    pAVar2 = (ASN1_OBJECT *)*param_1;
    a = (ASN1_OBJECT *)pAVar2->ln;
    param_1 = &pAVar2->ln;
    pcVar1 = pAVar2->sn;
    if (a == (ASN1_OBJECT *)0x0) {
      return;
    }
LAB_000b9142:
    switch(pcVar1) {
    case (char *)0x1:
      if (param_2 == (char *)0x0) {
        *param_1 = (char **)0xffffffff;
        return;
      }
LAB_000b9180:
      *param_1 = &(*(ASN1_OBJECT **)(param_2 + 0x14))->sn;
      return;
    case (char *)0x5:
      break;
    case (char *)0x6:
      ASN1_OBJECT_free(a);
      break;
    case (char *)0xfffffffc:
      ASN1_primitive_free_part_0(param_1,0);
      CRYPTO_free((ASN1_OBJECT *)*param_1);
      break;
    default:
      goto switchD_000b9148_caseD_fffffffd;
    }
  }
  else {
    if (*param_2 != '\x05') {
      pcVar1 = *(char **)(param_2 + 4);
      if (pcVar1 == (char *)0x1) goto LAB_000b9180;
      a = (ASN1_OBJECT *)*param_1;
      if (a == (ASN1_OBJECT *)0x0) {
        return;
      }
      goto LAB_000b9142;
    }
    a = (ASN1_OBJECT *)*param_1;
    if (a == (ASN1_OBJECT *)0x0) {
      return;
    }
switchD_000b9148_caseD_fffffffd:
    ASN1_STRING_free((ASN1_STRING *)a);
    *param_1 = (char **)0x0;
  }
  *param_1 = (char **)0x0;
  return;
}

