
undefined4 TS_ACCURACY_set_micros(int param_1,ASN1_STRING *param_2)

{
  ASN1_STRING *pAVar1;
  ASN1_INTEGER *a;
  
  a = *(ASN1_INTEGER **)(param_1 + 8);
  if (a == param_2) {
    return 1;
  }
  if (param_2 == (ASN1_STRING *)0x0) {
    pAVar1 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar1 = ASN1_INTEGER_dup(param_2);
    if (pAVar1 == (ASN1_STRING *)0x0) {
      ERR_put_error(0x2f,0x73,0x41,"ts_rsp_utils.c",0x122);
      return 0;
    }
    a = *(ASN1_INTEGER **)(param_1 + 8);
  }
  ASN1_INTEGER_free(a);
  *(ASN1_STRING **)(param_1 + 8) = pAVar1;
  return 1;
}

