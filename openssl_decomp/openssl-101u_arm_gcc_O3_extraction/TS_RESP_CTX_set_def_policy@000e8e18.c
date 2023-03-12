
undefined4 TS_RESP_CTX_set_def_policy(int param_1,ASN1_OBJECT *param_2)

{
  ASN1_OBJECT *pAVar1;
  
  if (*(ASN1_OBJECT **)(param_1 + 0x10) != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(*(ASN1_OBJECT **)(param_1 + 0x10));
  }
  pAVar1 = OBJ_dup(param_2);
  *(ASN1_OBJECT **)(param_1 + 0x10) = pAVar1;
  if (pAVar1 != (ASN1_OBJECT *)0x0) {
    return 1;
  }
  ERR_put_error(0x2f,0x82,0x41,"ts_rsp_sign.c",0xeb);
  return 0;
}

