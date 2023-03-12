
int CMS_EncryptedData_set1_key(CMS_ContentInfo *cms,EVP_CIPHER *ciph,uchar *key,size_t keylen)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  
  if ((key == (uchar *)0x0) || (keylen == 0)) {
    uVar5 = 0x82;
    uVar3 = 0x107;
  }
  else if (ciph == (EVP_CIPHER *)0x0) {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
    puVar1 = PTR_CRYPTO_malloc_006a8108;
    if (iVar2 == 0x1a) {
      iVar6 = *(int *)(*(int *)(cms + 4) + 4);
      *(undefined4 *)(iVar6 + 0xc) = 0;
      iVar2 = (*(code *)puVar1)(keylen,"cms_enc.c",0xf6);
      *(int *)(iVar6 + 0x10) = iVar2;
      if (iVar2 != 0) {
        (*(code *)PTR_memcpy_006aabf4)(iVar2,key,keylen);
        *(size_t *)(iVar6 + 0x14) = keylen;
        return 1;
      }
      return 0;
    }
    uVar5 = 0x7a;
    uVar3 = 0x119;
  }
  else {
    iVar2 = (*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_EncryptedData_it_006aa4f4);
    *(int *)(cms + 4) = iVar2;
    if (iVar2 != 0) {
      uVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x1a);
      puVar4 = *(undefined4 **)(cms + 4);
      *(undefined4 *)cms = uVar3;
      *puVar4 = 0;
      puVar1 = PTR_CRYPTO_malloc_006a8108;
      puVar4 = (undefined4 *)puVar4[1];
      puVar4[3] = ciph;
      iVar2 = (*(code *)puVar1)(keylen,"cms_enc.c",0xf6);
      puVar4[4] = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
      (*(code *)PTR_memcpy_006aabf4)(iVar2,key,keylen);
      puVar1 = PTR_OBJ_nid2obj_006a8240;
      puVar4[5] = keylen;
      uVar3 = (*(code *)puVar1)(0x15);
      *puVar4 = uVar3;
      return 1;
    }
    uVar5 = 0x41;
    uVar3 = 0x110;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7b,uVar5,"cms_enc.c",uVar3);
  return 0;
}

