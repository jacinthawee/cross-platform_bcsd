
CMS_ContentInfo * CMS_EnvelopedData_create(EVP_CIPHER *cipher)

{
  undefined *puVar1;
  undefined4 *a;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  a = (undefined4 *)CMS_ContentInfo_new();
  if (a == (undefined4 *)0x0) goto LAB_005bb8e0;
  if (a[1] == 0) {
    puVar3 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_EnvelopedData_it_006a93b8);
    a[1] = puVar3;
    puVar1 = PTR_OBJ_nid2obj_006a7140;
    if (puVar3 != (undefined4 *)0x0) {
      puVar6 = (undefined4 *)puVar3[3];
      *puVar3 = 0;
      uVar4 = (*(code *)puVar1)(0x15);
      puVar1 = PTR_ASN1_OBJECT_free_006a7004;
      uVar5 = *a;
      *puVar6 = uVar4;
      (*(code *)puVar1)(uVar5);
      uVar4 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x17);
      iVar2 = a[1];
      *a = uVar4;
      goto LAB_005bb828;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7e,0x41,"cms_env.c",0x5a);
  }
  else {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*a);
    if (iVar2 == 0x17) {
      iVar2 = a[1];
LAB_005bb828:
      if ((iVar2 != 0) &&
         (iVar2 = cms_EncryptedContent_init(*(undefined4 *)(iVar2 + 0xc),cipher,0,0), iVar2 != 0)) {
        return (CMS_ContentInfo *)a;
      }
    }
    else {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    }
  }
  CMS_ContentInfo_free((CMS_ContentInfo *)a);
LAB_005bb8e0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7c,0x41,"cms_env.c",0x86);
  return (CMS_ContentInfo *)0x0;
}

