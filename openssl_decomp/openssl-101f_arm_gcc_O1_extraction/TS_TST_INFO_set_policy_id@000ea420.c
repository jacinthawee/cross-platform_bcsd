
ASN1_OBJECT * TS_TST_INFO_set_policy_id(int param_1,ASN1_OBJECT *param_2)

{
  ASN1_OBJECT *pAVar1;
  
  if (*(ASN1_OBJECT **)(param_1 + 4) == param_2) {
    pAVar1 = (ASN1_OBJECT *)0x1;
  }
  else {
    pAVar1 = OBJ_dup(param_2);
    if (pAVar1 == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0x2f,0x8c,0x41,"ts_rsp_utils.c",0x81);
    }
    else {
      ASN1_OBJECT_free(*(ASN1_OBJECT **)(param_1 + 4));
      *(ASN1_OBJECT **)(param_1 + 4) = pAVar1;
      pAVar1 = (ASN1_OBJECT *)0x1;
    }
  }
  return pAVar1;
}

