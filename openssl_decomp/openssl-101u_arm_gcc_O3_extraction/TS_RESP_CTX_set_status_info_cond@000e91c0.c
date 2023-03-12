
undefined4 TS_RESP_CTX_set_status_info_cond(int param_1,undefined4 param_2,undefined4 param_3)

{
  ASN1_INTEGER **ppAVar1;
  long lVar2;
  undefined4 uVar3;
  
  ppAVar1 = (ASN1_INTEGER **)TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
  lVar2 = ASN1_INTEGER_get(*ppAVar1);
  if (lVar2 != 0) {
    return 1;
  }
  uVar3 = TS_RESP_CTX_set_status_info(param_1,param_2,param_3);
  return uVar3;
}

