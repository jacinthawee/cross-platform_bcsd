
undefined4 TS_REQ_set_nonce(int param_1,ASN1_STRING *param_2)

{
  ASN1_STRING *pAVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(ASN1_STRING **)(param_1 + 0xc) != param_2) {
    pAVar1 = ASN1_INTEGER_dup(param_2);
    if (pAVar1 == (ASN1_STRING *)0x0) {
      uVar2 = 0;
      ERR_put_error(0x2f,0x78,0x41,"ts_req_utils.c",0x9d);
    }
    else {
      ASN1_INTEGER_free(*(ASN1_INTEGER **)(param_1 + 0xc));
      *(ASN1_STRING **)(param_1 + 0xc) = pAVar1;
    }
  }
  return uVar2;
}

