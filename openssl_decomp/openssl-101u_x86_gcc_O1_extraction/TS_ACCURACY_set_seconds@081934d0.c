
undefined4 TS_ACCURACY_set_seconds(ASN1_INTEGER **param_1,ASN1_STRING *param_2)

{
  ASN1_STRING *pAVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*param_1 != param_2) {
    pAVar1 = ASN1_INTEGER_dup(param_2);
    if (pAVar1 == (ASN1_STRING *)0x0) {
      uVar2 = 0;
      ERR_put_error(0x2f,0x75,0x41,"ts_rsp_utils.c",0xe9);
    }
    else {
      ASN1_INTEGER_free(*param_1);
      *param_1 = pAVar1;
    }
  }
  return uVar2;
}

