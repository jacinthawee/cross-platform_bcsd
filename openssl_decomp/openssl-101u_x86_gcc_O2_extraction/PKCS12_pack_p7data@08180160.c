
PKCS7 * PKCS12_pack_p7data(stack_st_PKCS12_SAFEBAG *sk)

{
  PKCS7 *a;
  ASN1_OBJECT *pAVar1;
  ASN1_STRING *pAVar2;
  
  a = PKCS7_new();
  if (a == (PKCS7 *)0x0) {
    ERR_put_error(0x23,0x72,0x41,"p12_add.c",0x92);
  }
  else {
    pAVar1 = OBJ_nid2obj(0x15);
    a->type = pAVar1;
    pAVar2 = ASN1_STRING_type_new(4);
    (a->d).data = pAVar2;
    if (pAVar2 == (ASN1_STRING *)0x0) {
      ERR_put_error(0x23,0x72,0x41,"p12_add.c",0x97);
    }
    else {
      pAVar2 = ASN1_item_pack(sk,(ASN1_ITEM *)PKCS12_SAFEBAGS_it,&(a->d).data);
      if (pAVar2 != (ASN1_STRING *)0x0) {
        return a;
      }
      ERR_put_error(0x23,0x72,100,"p12_add.c",0x9c);
    }
    PKCS7_free(a);
  }
  return (PKCS7 *)0x0;
}

