
int CMS_add1_crl(CMS_ContentInfo *cms,X509_CRL *crl)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
  if (iVar2 == 0x16) {
    piVar4 = (int *)(*(int *)(cms + 4) + 0x10);
  }
  else {
    if (iVar2 != 0x17) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x84,0x98,"cms_lib.c",0x201);
      return 0;
    }
    piVar4 = (int *)(*(int *)(*(int *)(cms + 4) + 4) + 4);
  }
  if (piVar4 != (int *)0x0) {
    if (*piVar4 == 0) {
      iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
      *piVar4 = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
    }
    puVar3 = (undefined4 *)
             (*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_RevocationInfoChoice_it_006aa3fc);
    if (puVar3 != (undefined4 *)0x0) {
      iVar2 = (*(code *)PTR_sk_push_006a80a8)(*piVar4,puVar3);
      puVar1 = PTR_CRYPTO_add_lock_006a9080;
      if (iVar2 != 0) {
        puVar3[1] = crl;
        *puVar3 = 0;
        (*(code *)puVar1)(&crl->references,1,6,"cms_lib.c",0x22d);
        return 1;
      }
      (*(code *)PTR_ASN1_item_free_006a977c)(puVar3,PTR_CMS_RevocationInfoChoice_it_006aa3fc);
    }
  }
  return 0;
}

