
ASN1_STRING * TS_TST_INFO_set_time(int param_1,ASN1_STRING *param_2)

{
  ASN1_STRING *pAVar1;
  
  if (*(ASN1_STRING **)(param_1 + 0x10) == param_2) {
    pAVar1 = (ASN1_STRING *)0x1;
  }
  else {
    pAVar1 = ASN1_STRING_dup(param_2);
    if (pAVar1 == (ASN1_STRING *)0x0) {
      ERR_put_error(0x2f,0x8e,0x41,"ts_rsp_utils.c",0xc3);
    }
    else {
      ASN1_GENERALIZEDTIME_free(*(ASN1_GENERALIZEDTIME **)(param_1 + 0x10));
      *(ASN1_STRING **)(param_1 + 0x10) = pAVar1;
      pAVar1 = (ASN1_STRING *)0x1;
    }
  }
  return pAVar1;
}

