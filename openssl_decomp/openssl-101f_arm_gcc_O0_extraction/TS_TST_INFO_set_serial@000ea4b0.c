
ASN1_STRING * TS_TST_INFO_set_serial(int param_1,ASN1_STRING *param_2)

{
  ASN1_STRING *pAVar1;
  
  if (*(ASN1_STRING **)(param_1 + 0xc) == param_2) {
    pAVar1 = (ASN1_STRING *)0x1;
  }
  else {
    pAVar1 = ASN1_INTEGER_dup(param_2);
    if (pAVar1 == (ASN1_STRING *)0x0) {
      ERR_put_error(0x2f,0x8d,0x41,"ts_rsp_utils.c",0xad);
    }
    else {
      ASN1_INTEGER_free(*(ASN1_INTEGER **)(param_1 + 0xc));
      *(ASN1_STRING **)(param_1 + 0xc) = pAVar1;
      pAVar1 = (ASN1_STRING *)0x1;
    }
  }
  return pAVar1;
}

