
PKCS7 * PKCS12_pack_p7data(stack_st_PKCS12_SAFEBAG *sk)

{
  undefined *puVar1;
  PKCS7 *pPVar2;
  ASN1_OBJECT *pAVar3;
  char *pcVar4;
  int iVar5;
  
  pPVar2 = PKCS7_new();
  if (pPVar2 == (PKCS7 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x72,0x41,"p12_add.c",0x8b);
  }
  else {
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(0x15);
    puVar1 = PTR_ASN1_STRING_type_new_006a97a4;
    pPVar2->type = pAVar3;
    pcVar4 = (char *)(*(code *)puVar1)(4);
    (pPVar2->d).ptr = pcVar4;
    if (pcVar4 == (char *)0x0) {
      pPVar2 = (PKCS7 *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x72,0x41,"p12_add.c",0x90);
    }
    else {
      iVar5 = (*(code *)PTR_ASN1_item_pack_006a9f14)(sk,PTR_PKCS12_SAFEBAGS_it_006aa2ec,&pPVar2->d);
      if (iVar5 == 0) {
        pPVar2 = (PKCS7 *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x72,100,"p12_add.c",0x95);
      }
    }
  }
  return pPVar2;
}

