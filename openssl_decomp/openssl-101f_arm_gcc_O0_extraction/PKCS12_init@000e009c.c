
PKCS12 * PKCS12_init(int mode)

{
  PKCS12 *a;
  ASN1_OBJECT *pAVar1;
  ASN1_STRING *pAVar2;
  PKCS7 *pPVar3;
  
  a = PKCS12_new();
  if (a == (PKCS12 *)0x0) {
    ERR_put_error(0x23,0x6d,0x41,"p12_init.c",0x45);
  }
  else {
    ASN1_INTEGER_set(a->version,3);
    pPVar3 = a->authsafes;
    pAVar1 = OBJ_nid2obj(mode);
    pPVar3->type = pAVar1;
    if (mode == 0x15) {
      pPVar3 = a->authsafes;
      pAVar2 = ASN1_STRING_type_new(4);
      (pPVar3->d).data = pAVar2;
      if (pAVar2 != (ASN1_STRING *)0x0) {
        return a;
      }
      ERR_put_error(0x23,0x6d,0x41,"p12_init.c",0x4e);
    }
    else {
      ERR_put_error(0x23,0x6d,0x77,"p12_init.c",0x54);
    }
    PKCS12_free(a);
    a = (PKCS12 *)0x0;
  }
  return a;
}

