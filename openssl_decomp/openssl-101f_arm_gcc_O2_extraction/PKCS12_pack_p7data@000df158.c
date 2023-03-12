
PKCS7 * PKCS12_pack_p7data(stack_st_PKCS12_SAFEBAG *sk)

{
  PKCS7 *pPVar1;
  ASN1_OBJECT *pAVar2;
  PKCS7 *pPVar3;
  
  pPVar1 = PKCS7_new();
  if (pPVar1 == (PKCS7 *)0x0) {
    ERR_put_error(0x23,0x72,0x41,"p12_add.c",0x8b);
  }
  else {
    pAVar2 = OBJ_nid2obj(0x15);
    pPVar1->type = pAVar2;
    pPVar3 = (PKCS7 *)ASN1_STRING_type_new(4);
    (pPVar1->d).data = (ASN1_OCTET_STRING *)pPVar3;
    if (pPVar3 == (PKCS7 *)0x0) {
      ERR_put_error(0x23,0x72,0x41,"p12_add.c",0x90);
      pPVar1 = pPVar3;
    }
    else {
      pPVar3 = (PKCS7 *)ASN1_item_pack(sk,(ASN1_ITEM *)PKCS12_SAFEBAGS_it,&(pPVar1->d).data);
      if (pPVar3 == (PKCS7 *)0x0) {
        ERR_put_error(0x23,0x72,100,"p12_add.c",0x95);
        pPVar1 = pPVar3;
      }
    }
  }
  return pPVar1;
}

