
stack_st_CONF_VALUE *
i2v_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,ASN1_BIT_STRING *bits,stack_st_CONF_VALUE *extlist)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)((int)method->usr_data + 4) != 0) {
    piVar3 = (int *)method->usr_data;
    do {
      while (iVar2 = ASN1_BIT_STRING_get_bit(bits,*piVar3), iVar2 != 0) {
        X509V3_add_value((char *)piVar3[1],(char *)0x0,&extlist);
        piVar1 = piVar3 + 4;
        piVar3 = piVar3 + 3;
        if (*piVar1 == 0) {
          return extlist;
        }
      }
      piVar1 = piVar3 + 4;
      piVar3 = piVar3 + 3;
    } while (*piVar1 != 0);
  }
  return extlist;
}

