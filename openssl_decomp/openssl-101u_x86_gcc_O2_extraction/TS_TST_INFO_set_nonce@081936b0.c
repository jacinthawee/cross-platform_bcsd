
undefined4 TS_TST_INFO_set_nonce(int param_1,ASN1_STRING *param_2)

{
  ASN1_STRING *pAVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(ASN1_STRING **)(param_1 + 0x1c) != param_2) {
    pAVar1 = ASN1_INTEGER_dup(param_2);
    if (pAVar1 == (ASN1_STRING *)0x0) {
      uVar2 = 0;
      ERR_put_error(0x2f,0x8b,0x41,"ts_rsp_utils.c",0x137);
    }
    else {
      ASN1_INTEGER_free(*(ASN1_INTEGER **)(param_1 + 0x1c));
      *(ASN1_STRING **)(param_1 + 0x1c) = pAVar1;
    }
  }
  return uVar2;
}

