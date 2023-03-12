
PKCS7 * PKCS12_pack_p7data(stack_st_PKCS12_SAFEBAG *sk)

{
  undefined *puVar1;
  PKCS7 *a;
  ASN1_OBJECT *pAVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  a = PKCS7_new();
  if (a == (PKCS7 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x72,0x41,"p12_add.c",0x92);
  }
  else {
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
    puVar1 = PTR_ASN1_STRING_type_new_006a8680;
    a->type = pAVar2;
    pcVar3 = (char *)(*(code *)puVar1)(4);
    (a->d).ptr = pcVar3;
    if (pcVar3 == (char *)0x0) {
      uVar6 = 0x41;
      uVar5 = 0x97;
    }
    else {
      iVar4 = (*(code *)PTR_ASN1_item_pack_006a8df4)(sk,PTR_PKCS12_SAFEBAGS_it_006a91d4,&a->d);
      if (iVar4 != 0) {
        return a;
      }
      uVar6 = 100;
      uVar5 = 0x9c;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x72,uVar6,"p12_add.c",uVar5);
    PKCS7_free(a);
  }
  return (PKCS7 *)0x0;
}

