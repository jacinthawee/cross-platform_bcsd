
PKCS12_SAFEBAG * PKCS12_item_pack_safebag(void *obj,ASN1_ITEM *it,int nid1,int nid2)

{
  undefined *puVar1;
  PKCS12_BAGS *a;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  PKCS12_SAFEBAG *pPVar4;
  undefined4 uVar5;
  
  a = PKCS12_BAGS_new();
  if (a == (PKCS12_BAGS *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x75,0x41,"p12_add.c",0x48);
  }
  else {
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(nid1);
    a->type = pAVar2;
    iVar3 = (*(code *)PTR_ASN1_item_pack_006a8df4)(obj,it,&a->value);
    if (iVar3 == 0) {
      uVar5 = 0x4d;
    }
    else {
      pPVar4 = PKCS12_SAFEBAG_new();
      puVar1 = PTR_OBJ_nid2obj_006a7140;
      if (pPVar4 != (PKCS12_SAFEBAG *)0x0) {
        (pPVar4->value).bag = a;
        pAVar2 = (ASN1_OBJECT *)(*(code *)puVar1)(nid2);
        pPVar4->type = pAVar2;
        return pPVar4;
      }
      uVar5 = 0x51;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x75,0x41,"p12_add.c",uVar5);
    PKCS12_BAGS_free(a);
  }
  return (PKCS12_SAFEBAG *)0x0;
}

