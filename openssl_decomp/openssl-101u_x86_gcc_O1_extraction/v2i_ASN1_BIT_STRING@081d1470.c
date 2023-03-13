
ASN1_BIT_STRING *
v2i_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,stack_st_CONF_VALUE *nval)

{
  char *__s2;
  ASN1_STRING *a;
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  char *__s1;
  int iVar4;
  
  a = ASN1_STRING_type_new(3);
  if (a == (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,0x65,0x41,"v3_bitst.c",0x74);
  }
  else {
    iVar4 = 0;
    while( true ) {
      iVar1 = sk_num(&nval->stack);
      if (iVar1 <= iVar4) {
        return a;
      }
      puVar2 = (undefined4 *)sk_value(&nval->stack,iVar4);
      __s1 = *(char **)((int)method->usr_data + 4);
      if (__s1 == (char *)0x0) break;
      __s2 = (char *)puVar2[1];
      piVar3 = (int *)method->usr_data;
      while( true ) {
        iVar1 = strcmp((char *)piVar3[2],__s2);
        if (iVar1 == 0) break;
        iVar1 = strcmp(__s1,__s2);
        if (iVar1 == 0) break;
        __s1 = (char *)piVar3[4];
        piVar3 = piVar3 + 3;
        if (__s1 == (char *)0x0) goto LAB_081d1530;
      }
      iVar1 = ASN1_BIT_STRING_set_bit(a,*piVar3,1);
      if (iVar1 == 0) {
        ERR_put_error(0x22,0x65,0x41,"v3_bitst.c",0x7e);
        goto LAB_081d156d;
      }
      if (piVar3[1] == 0) break;
      iVar4 = iVar4 + 1;
    }
LAB_081d1530:
    ERR_put_error(0x22,0x65,0x6f,"v3_bitst.c",0x87);
    ERR_add_error_data(6,"section:",*puVar2,",name:",puVar2[1],",value:",puVar2[2]);
LAB_081d156d:
    ASN1_STRING_free(a);
  }
  return (ASN1_BIT_STRING *)0x0;
}

