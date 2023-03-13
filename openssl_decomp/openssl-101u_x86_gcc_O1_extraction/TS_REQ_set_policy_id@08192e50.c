
undefined4 TS_REQ_set_policy_id(int param_1,ASN1_OBJECT *param_2)

{
  ASN1_OBJECT *pAVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(ASN1_OBJECT **)(param_1 + 8) != param_2) {
    pAVar1 = OBJ_dup(param_2);
    if (pAVar1 == (ASN1_OBJECT *)0x0) {
      uVar2 = 0;
      ERR_put_error(0x2f,0x79,0x41,"ts_req_utils.c",0x88);
    }
    else {
      ASN1_OBJECT_free(*(ASN1_OBJECT **)(param_1 + 8));
      *(ASN1_OBJECT **)(param_1 + 8) = pAVar1;
    }
  }
  return uVar2;
}

