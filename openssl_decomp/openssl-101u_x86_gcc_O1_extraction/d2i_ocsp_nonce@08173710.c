
ASN1_STRING * d2i_ocsp_nonce(ASN1_STRING **param_1,void **param_2,int param_3)

{
  int iVar1;
  ASN1_STRING *str;
  
  if (param_1 == (ASN1_STRING **)0x0) {
    str = ASN1_OCTET_STRING_new();
    iVar1 = ASN1_OCTET_STRING_set(str,*param_2,param_3);
    if (iVar1 != 0) {
      *param_2 = (void *)((int)*param_2 + param_3);
      return str;
    }
    if (str == (ASN1_OCTET_STRING *)0x0) goto LAB_08173790;
  }
  else {
    str = *param_1;
    if (str == (ASN1_STRING *)0x0) {
      str = ASN1_OCTET_STRING_new();
      iVar1 = ASN1_OCTET_STRING_set(str,*param_2,param_3);
      if (iVar1 != 0) goto LAB_08173744;
      if (str == (ASN1_OCTET_STRING *)0x0) goto LAB_08173790;
    }
    else {
      iVar1 = ASN1_OCTET_STRING_set(str,*param_2,param_3);
      if (iVar1 != 0) {
LAB_08173744:
        *param_2 = (void *)((int)*param_2 + param_3);
        *param_1 = str;
        return str;
      }
    }
    if (*param_1 == str) goto LAB_08173790;
  }
  ASN1_STRING_free(str);
LAB_08173790:
  ERR_put_error(0x27,0x66,0x41,"v3_ocsp.c",0xfd);
  return (ASN1_STRING *)0x0;
}

