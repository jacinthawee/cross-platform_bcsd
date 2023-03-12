
PKCS12_SAFEBAG * PKCS12_item_pack_safebag(void *obj,ASN1_ITEM *it,int nid1,int nid2)

{
  undefined *puVar1;
  PKCS12_BAGS *pPVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  PKCS12_SAFEBAG *pPVar5;
  undefined4 uVar6;
  
  pPVar2 = PKCS12_BAGS_new();
  if (pPVar2 == (PKCS12_BAGS *)0x0) {
    uVar6 = 0x47;
  }
  else {
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(nid1);
    pPVar2->type = pAVar3;
    iVar4 = (*(code *)PTR_ASN1_item_pack_006a9f14)(obj,it,&pPVar2->value);
    if (iVar4 == 0) {
      uVar6 = 0x4c;
    }
    else {
      pPVar5 = PKCS12_SAFEBAG_new();
      puVar1 = PTR_OBJ_nid2obj_006a8240;
      if (pPVar5 != (PKCS12_SAFEBAG *)0x0) {
        (pPVar5->value).bag = pPVar2;
        pAVar3 = (ASN1_OBJECT *)(*(code *)puVar1)(nid2);
        pPVar5->type = pAVar3;
        return pPVar5;
      }
      uVar6 = 0x50;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x75,0x41,"p12_add.c",uVar6);
  return (PKCS12_SAFEBAG *)0x0;
}

