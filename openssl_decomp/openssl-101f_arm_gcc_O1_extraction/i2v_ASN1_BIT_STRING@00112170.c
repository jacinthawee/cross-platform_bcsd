
stack_st_CONF_VALUE *
i2v_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,ASN1_BIT_STRING *bits,stack_st_CONF_VALUE *extlist)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  stack_st_CONF_VALUE *local_14 [2];
  
  piVar3 = (int *)method->usr_data;
  iVar2 = piVar3[1];
  local_14[0] = extlist;
  do {
    piVar4 = piVar3;
    if (iVar2 == 0) {
      return local_14[0];
    }
    while( true ) {
      piVar3 = piVar4 + 3;
      iVar2 = ASN1_BIT_STRING_get_bit(bits,*piVar4);
      if (iVar2 != 0) break;
      piVar1 = piVar4 + 4;
      piVar4 = piVar3;
      if (*piVar1 == 0) {
        return local_14[0];
      }
    }
    X509V3_add_value((char *)piVar4[1],(char *)0x0,local_14);
    iVar2 = piVar4[4];
  } while( true );
}

