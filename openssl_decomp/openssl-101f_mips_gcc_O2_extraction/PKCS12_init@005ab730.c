
PKCS12 * PKCS12_init(int mode)

{
  PKCS12 *a;
  ASN1_OBJECT *pAVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  PKCS7 *pPVar5;
  
  a = PKCS12_new();
  if (a == (PKCS12 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6d,0x41,"p12_init.c",0x45);
  }
  else {
    (*(code *)PTR_ASN1_INTEGER_set_006a8264)(a->version,3);
    pPVar5 = a->authsafes;
    pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(mode);
    pPVar5->type = pAVar1;
    if (mode == 0x15) {
      pPVar5 = a->authsafes;
      pcVar3 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
      (pPVar5->d).ptr = pcVar3;
      if (pcVar3 != (char *)0x0) {
        return a;
      }
      uVar4 = 0x41;
      uVar2 = 0x4e;
    }
    else {
      uVar4 = 0x77;
      uVar2 = 0x54;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6d,uVar4,"p12_init.c",uVar2);
    PKCS12_free(a);
  }
  return (PKCS12 *)0x0;
}

