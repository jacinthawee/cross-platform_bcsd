
undefined4 TS_TST_INFO_set_time(int param_1,ASN1_STRING *param_2)

{
  ASN1_STRING *pAVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(ASN1_STRING **)(param_1 + 0x10) != param_2) {
    pAVar1 = ASN1_STRING_dup(param_2);
    if (pAVar1 == (ASN1_STRING *)0x0) {
      uVar2 = 0;
      ERR_put_error(0x2f,0x8e,0x41,"ts_rsp_utils.c",0xbf);
    }
    else {
      ASN1_GENERALIZEDTIME_free(*(ASN1_GENERALIZEDTIME **)(param_1 + 0x10));
      *(ASN1_STRING **)(param_1 + 0x10) = pAVar1;
    }
  }
  return uVar2;
}

