
PKCS12 * PKCS12_init(int mode)

{
  PKCS7 *pPVar1;
  PKCS12 *a;
  ASN1_OBJECT *pAVar2;
  ASN1_STRING *pAVar3;
  
  a = PKCS12_new();
  if (a == (PKCS12 *)0x0) {
    ERR_put_error(0x23,0x6d,0x41,"p12_init.c",0x45);
  }
  else {
    ASN1_INTEGER_set(a->version,3);
    pPVar1 = a->authsafes;
    pAVar2 = OBJ_nid2obj(mode);
    pPVar1->type = pAVar2;
    if (mode == 0x15) {
      pPVar1 = a->authsafes;
      pAVar3 = ASN1_STRING_type_new(4);
      (pPVar1->d).data = pAVar3;
      if (pAVar3 != (ASN1_STRING *)0x0) {
        return a;
      }
      ERR_put_error(0x23,0x6d,0x41,"p12_init.c",0x4e);
    }
    else {
      ERR_put_error(0x23,0x6d,0x77,"p12_init.c",0x54);
    }
    PKCS12_free(a);
  }
  return (PKCS12 *)0x0;
}

