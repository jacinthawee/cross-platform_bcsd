
PKCS7 * PKCS12_pack_p7data(stack_st_PKCS12_SAFEBAG *sk)

{
  PKCS7 *pPVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_STRING *pAVar3;
  int reason;
  int line;
  
  pPVar1 = PKCS7_new();
  if (pPVar1 == (PKCS7 *)0x0) {
    line = 0x8b;
    reason = 0x41;
  }
  else {
    pAVar2 = OBJ_nid2obj(0x15);
    pPVar1->type = pAVar2;
    pAVar3 = ASN1_STRING_type_new(4);
    (pPVar1->d).data = pAVar3;
    if (pAVar3 == (ASN1_STRING *)0x0) {
      line = 0x90;
      reason = 0x41;
    }
    else {
      pAVar3 = ASN1_item_pack(sk,(ASN1_ITEM *)PKCS12_SAFEBAGS_it,&(pPVar1->d).data);
      if (pAVar3 != (ASN1_STRING *)0x0) {
        return pPVar1;
      }
      line = 0x95;
      reason = 100;
    }
  }
  ERR_put_error(0x23,0x72,reason,"p12_add.c",line);
  return (PKCS7 *)0x0;
}

