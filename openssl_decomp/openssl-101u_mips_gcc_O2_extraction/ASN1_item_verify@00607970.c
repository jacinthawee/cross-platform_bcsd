
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_48 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (pkey == (EVP_PKEY *)0x0) {
    uVar6 = 0x43;
    uVar2 = 0x92;
  }
  else {
    if ((signature->type != 3) || ((signature->flags & 7U) == 0)) {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_3c);
      uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(algor1->algorithm);
      iVar3 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(uVar2,&local_44,&local_40);
      if (iVar3 == 0) {
        uVar6 = 199;
        uVar2 = 0x9f;
LAB_00607b58:
        pAVar5 = (ASN1_ITEM *)0xc5;
        iVar3 = -1;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar6,"a_verify.c",uVar2);
      }
      else {
        if (local_44 != 0) {
          uVar2 = (*(code *)PTR_OBJ_nid2sn_006a709c)();
          iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar2);
          if (iVar3 == 0) {
            uVar6 = 0xa1;
            uVar2 = 0xb6;
          }
          else {
            iVar4 = (*(code *)PTR_EVP_PKEY_type_006a97e0)(local_40);
            if (iVar4 == *(int *)pkey->ameth) {
              iVar3 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)(auStack_3c,0,iVar3,0,pkey);
              if (iVar3 != 0) goto LAB_00607b88;
              uVar2 = 0xc1;
              goto LAB_00607bd8;
            }
            uVar6 = 200;
            uVar2 = 0xbc;
          }
          goto LAB_00607b58;
        }
        if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
           (pcVar7 = *(code **)(pkey->ameth + 100), pcVar7 == (code *)0x0)) {
          uVar6 = 199;
          uVar2 = 0xa5;
          goto LAB_00607b58;
        }
        pAVar5 = it;
        iVar3 = (*pcVar7)(auStack_3c,it,data,algor1,signature,pkey);
        if (iVar3 == 2) {
LAB_00607b88:
          uVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)(data,&local_48,it);
          if (local_48 == 0) {
            uVar6 = 0x41;
            uVar2 = 0xcb;
            goto LAB_00607b58;
          }
          iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_3c,local_48,uVar2);
          if (iVar3 == 0) {
            uVar2 = 0xd0;
          }
          else {
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_48,uVar2);
            (*(code *)PTR_CRYPTO_free_006a6e88)(local_48);
            pAVar5 = (ASN1_ITEM *)signature->data;
            iVar3 = (*(code *)PTR_EVP_DigestVerifyFinal_006a74cc)
                              (auStack_3c,pAVar5,signature->length);
            if (0 < iVar3) {
              iVar3 = 1;
              goto LAB_00607a64;
            }
            uVar2 = 0xda;
          }
LAB_00607bd8:
          pAVar5 = (ASN1_ITEM *)0xc5;
          iVar3 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,6,"a_verify.c",uVar2);
        }
      }
LAB_00607a64:
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_3c);
      goto LAB_00607a78;
    }
    uVar6 = 0xdc;
    uVar2 = 0x97;
  }
  pAVar5 = (ASN1_ITEM *)0xc5;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar6,"a_verify.c",uVar2);
  iVar3 = -1;
LAB_00607a78:
  if (local_24 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    *(int *)pAVar5 = *(int *)pAVar5 + 1;
    return 1;
  }
  return iVar3;
}

