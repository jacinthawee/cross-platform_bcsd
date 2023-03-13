
PKCS12_SAFEBAG * PKCS12_MAKE_KEYBAG(PKCS8_PRIV_KEY_INFO *p8)

{
  PKCS12_SAFEBAG *pPVar1;
  ASN1_OBJECT *pAVar2;
  
  pPVar1 = PKCS12_SAFEBAG_new();
  if (pPVar1 == (PKCS12_SAFEBAG *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x70,0x41,"p12_add.c",99);
    pPVar1 = (PKCS12_SAFEBAG *)0x0;
  }
  else {
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0x96);
    pPVar1->type = pAVar2;
    (pPVar1->value).bag = (pkcs12_bag_st *)p8;
  }
  return pPVar1;
}

