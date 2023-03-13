
undefined4 nsseq_cb(int param_1,undefined4 *param_2)

{
  ASN1_OBJECT **ppAVar1;
  ASN1_OBJECT *pAVar2;
  
  if (param_1 != 1) {
    return 1;
  }
  ppAVar1 = (ASN1_OBJECT **)*param_2;
  pAVar2 = OBJ_nid2obj(0x4f);
  *ppAVar1 = pAVar2;
  return 1;
}

