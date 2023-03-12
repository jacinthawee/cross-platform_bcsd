
ASN1_STRING * s2i_ASN1_IA5STRING(undefined4 param_1,undefined4 param_2,ASN1_STRING *param_3)

{
  ASN1_STRING *str;
  size_t len;
  int iVar1;
  
  if (param_3 == (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,100,0x6b,"v3_ia5.c",99);
  }
  else {
    str = ASN1_STRING_type_new(0x16);
    if (str != (ASN1_STRING *)0x0) {
      len = strlen((char *)param_3);
      iVar1 = ASN1_STRING_set(str,param_3,len);
      if (iVar1 != 0) {
        return str;
      }
      ASN1_STRING_free(str);
    }
    ERR_put_error(0x22,100,0x41,"v3_ia5.c",0x71);
    param_3 = (ASN1_STRING *)0x0;
  }
  return param_3;
}
