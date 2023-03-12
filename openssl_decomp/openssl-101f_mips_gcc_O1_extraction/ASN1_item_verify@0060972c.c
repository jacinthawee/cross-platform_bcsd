
int ASN1_item_verify(ASN1_ITEM *it,X509_ALGOR *algor1,ASN1_BIT_STRING *signature,void *data,
                    EVP_PKEY *pkey)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  ASN1_ITEM *pAVar5;
  undefined4 uVar6;
  code *pcVar7;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined auStack_3c [24];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_48 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (pkey == (EVP_PKEY *)0x0) {
    pAVar5 = (ASN1_ITEM *)0xc5;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,0x43,"a_verify.c",0x91);
    iVar3 = -1;
    goto LAB_00609824;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_3c);
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(algor1->algorithm);
  iVar3 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(uVar2,&local_44,&local_40);
  if (iVar3 == 0) {
    uVar6 = 199;
    uVar2 = 0x9a;
LAB_0060986c:
    pAVar5 = (ASN1_ITEM *)0xc5;
    iVar3 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,uVar6,"a_verify.c",uVar2);
  }
  else {
    if (local_44 != 0) {
      uVar2 = (*(code *)PTR_OBJ_nid2sn_006a819c)();
      iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar2);
      if (iVar3 == 0) {
        uVar6 = 0xa1;
        uVar2 = 0xb4;
      }
      else {
        iVar4 = (*(code *)PTR_EVP_PKEY_type_006aa8f0)(local_40);
        if (iVar4 == *(int *)pkey->ameth) {
          iVar3 = (*(code *)PTR_EVP_DigestVerifyInit_006a85f0)(auStack_3c,0,iVar3,0,pkey);
          if (iVar3 != 0) goto LAB_006098f4;
          uVar2 = 0xc1;
          goto LAB_00609944;
        }
        uVar6 = 200;
        uVar2 = 0xbb;
      }
      goto LAB_0060986c;
    }
    if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
       (pcVar7 = *(code **)(pkey->ameth + 100), pcVar7 == (code *)0x0)) {
      uVar6 = 199;
      uVar2 = 0xa1;
      goto LAB_0060986c;
    }
    pAVar5 = it;
    iVar3 = (*pcVar7)(auStack_3c,it,data,algor1,signature,pkey);
    if (iVar3 == 2) {
LAB_006098f4:
      uVar2 = (*(code *)PTR_ASN1_item_i2d_006a979c)(data,&local_48,it);
      if (local_48 == 0) {
        uVar6 = 0x41;
        uVar2 = 0xcc;
        goto LAB_0060986c;
      }
      iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_3c,local_48,uVar2);
      if (iVar3 == 0) {
        uVar2 = 0xd2;
      }
      else {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_48,uVar2);
        (*(code *)PTR_CRYPTO_free_006a7f88)(local_48);
        pAVar5 = (ASN1_ITEM *)signature->data;
        iVar3 = (*(code *)PTR_EVP_DigestVerifyFinal_006a85c8)(auStack_3c,pAVar5,signature->length);
        if (0 < iVar3) {
          iVar3 = 1;
          goto LAB_00609810;
        }
        uVar2 = 0xdd;
      }
LAB_00609944:
      pAVar5 = (ASN1_ITEM *)0xc5;
      iVar3 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,6,"a_verify.c",uVar2);
    }
  }
LAB_00609810:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_3c);
LAB_00609824:
  if (local_24 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *(int *)pAVar5 = *(int *)pAVar5 + 1;
  return 1;
}

