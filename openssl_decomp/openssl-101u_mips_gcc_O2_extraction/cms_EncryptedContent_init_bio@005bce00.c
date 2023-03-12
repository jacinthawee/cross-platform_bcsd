
int cms_EncryptedContent_init_bio(int param_1)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int unaff_s1;
  int unaff_s2;
  int iVar9;
  int unaff_s4;
  undefined4 *puVar10;
  undefined *puVar11;
  undefined4 local_40;
  undefined auStack_3c [16];
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar9 = *(int *)(param_1 + 0xc);
  puVar10 = *(undefined4 **)(param_1 + 4);
  uVar5 = (*(code *)PTR_BIO_f_cipher_006a7558)();
  iVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (iVar6 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x78,0x41,"cms_enc.c",0x58);
    iVar6 = 0;
    goto LAB_005bd014;
  }
  (*(code *)PTR_BIO_ctrl_006a6e18)(iVar6,0x81,0,&local_40);
  bVar1 = iVar9 != 0;
  unaff_s1 = iVar6;
  if (iVar9 == 0) {
    uVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar10);
    uVar5 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar5);
    iVar7 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar5);
    if (iVar7 == 0) {
      uVar8 = 0x94;
      uVar5 = 0x69;
      goto LAB_005bd240;
    }
    iVar7 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(local_40,iVar7,0,0,0,bVar1);
    if (iVar7 < 1) goto LAB_005bd22c;
    iVar7 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a8c8c)(local_40,puVar10[1]);
    if (iVar7 < 1) {
      uVar8 = 0x66;
      uVar5 = 0x80;
      goto LAB_005bd240;
    }
    puVar11 = (undefined *)0x0;
    unaff_s4 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a8a00)(local_40);
LAB_005bd074:
    unaff_s2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s4,"cms_enc.c",0x86);
    if (unaff_s2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x78,0x41,"cms_enc.c",0x88);
      goto LAB_005bd258;
    }
    iVar7 = (*(code *)PTR_EVP_CIPHER_CTX_rand_key_006a9140)(local_40,unaff_s2);
    if (iVar7 < 1) {
      iVar9 = *(int *)(param_1 + 0x10);
      bVar1 = false;
      if (iVar9 == 0) goto LAB_005bd144;
      goto LAB_005bd208;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      *(int *)(param_1 + 0x10) = unaff_s2;
      *(int *)(param_1 + 0x14) = unaff_s4;
      if (iVar9 == 0) {
        unaff_s2 = 0;
        (*(code *)PTR_ERR_clear_error_006a6ee0)();
        goto LAB_005bcf58;
      }
      bVar2 = true;
      iVar9 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(local_40,0,0,unaff_s2,puVar11,bVar1);
      unaff_s2 = 0;
      if (iVar9 < 1) goto LAB_005bd32c;
LAB_005bcfa4:
      iVar9 = (*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
      puVar10[1] = iVar9;
      if (iVar9 == 0) {
        uVar8 = 0x41;
        uVar5 = 0xb9;
      }
      else {
        iVar9 = (*(code *)PTR_EVP_CIPHER_param_to_asn1_006a8dfc)(local_40,iVar9);
        if (0 < iVar9) {
          if (*(int *)puVar10[1] == -1) {
            bVar1 = true;
            (*(code *)PTR_ASN1_TYPE_free_006a7498)();
            puVar10[1] = 0;
          }
          else {
            bVar1 = true;
          }
          goto LAB_005bcfec;
        }
        uVar8 = 0x66;
        uVar5 = 0xbe;
      }
      bVar1 = false;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x78,uVar8,"cms_enc.c",uVar5);
LAB_005bcfec:
      iVar9 = *(int *)(param_1 + 0x10);
      if (iVar9 == 0) goto LAB_005bd138;
      if ((bVar2) && (bVar1)) {
        if (unaff_s2 != 0) goto LAB_005bd488;
        goto LAB_005bd014;
      }
      goto LAB_005bd208;
    }
LAB_005bcf58:
    if ((*(int *)(param_1 + 0x14) != unaff_s4) &&
       (iVar7 = (*(code *)PTR_EVP_CIPHER_CTX_set_key_length_006a8a8c)(local_40), iVar7 < 1)) {
      if ((iVar9 == 0) && (*(int *)(param_1 + 0x18) == 0)) {
        (*(code *)PTR_OPENSSL_cleanse_006a7074)
                  (*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
        (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x10));
        *(int *)(param_1 + 0x10) = unaff_s2;
        puVar3 = PTR_ERR_clear_error_006a6ee0;
        *(int *)(param_1 + 0x14) = unaff_s4;
        (*(code *)puVar3)();
        iVar9 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)
                          (local_40,0,0,*(undefined4 *)(param_1 + 0x10),puVar11,bVar1);
        if (iVar9 < 1) {
          bVar2 = false;
          unaff_s2 = 0;
          goto LAB_005bd32c;
        }
        iVar9 = *(int *)(param_1 + 0x10);
        if (iVar9 == 0) goto LAB_005bd014;
        bVar1 = true;
        unaff_s2 = 0;
      }
      else {
        bVar1 = false;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x78,0x76,"cms_enc.c",0xa3);
        iVar9 = *(int *)(param_1 + 0x10);
        if (iVar9 == 0) goto LAB_005bd138;
      }
      goto LAB_005bd208;
    }
    iVar7 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)
                      (local_40,0,0,*(undefined4 *)(param_1 + 0x10),puVar11,bVar1);
    if (iVar7 < 1) {
      bVar2 = false;
LAB_005bd32c:
      bVar1 = false;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x78,0x65,"cms_enc.c",0xb3);
      goto LAB_005bcfec;
    }
    bVar2 = false;
    if (iVar9 != 0) goto LAB_005bcfa4;
    iVar9 = *(int *)(param_1 + 0x10);
    bVar1 = true;
    if (iVar9 != 0) goto LAB_005bd208;
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar7 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(local_40,uVar5,0,0,0,bVar1);
    if (0 < iVar7) {
      uVar5 = (*(code *)PTR_EVP_CIPHER_CTX_cipher_006a80ec)(local_40);
      uVar5 = (*(code *)PTR_EVP_CIPHER_type_006a8df8)(uVar5);
      uVar5 = (*(code *)PTR_OBJ_nid2obj_006a7140)(uVar5);
      puVar11 = PTR_EVP_CIPHER_CTX_iv_length_006a7ff8;
      *puVar10 = uVar5;
      iVar7 = (*(code *)puVar11)(local_40);
      if (iVar7 < 1) {
        puVar11 = (undefined *)0x0;
        unaff_s4 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a8a00)(local_40);
        iVar7 = *(int *)(param_1 + 0x10);
      }
      else {
        puVar11 = auStack_3c;
        iVar7 = (*(code *)PTR_RAND_bytes_006a7574)(puVar11,iVar7);
        if (iVar7 < 1) {
          unaff_s4 = 0;
          goto LAB_005bd258;
        }
        unaff_s4 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a8a00)(local_40);
        iVar7 = *(int *)(param_1 + 0x10);
      }
      if (iVar7 == 0) goto LAB_005bd074;
      unaff_s2 = 0;
      goto LAB_005bcf58;
    }
LAB_005bd22c:
    uVar8 = 0x65;
    uVar5 = 0x70;
LAB_005bd240:
    unaff_s4 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x78,uVar8,"cms_enc.c",uVar5);
LAB_005bd258:
    iVar9 = *(int *)(param_1 + 0x10);
    if (iVar9 == 0) goto LAB_005bd170;
    bVar1 = false;
    unaff_s2 = 0;
LAB_005bd208:
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar9,*(undefined4 *)(param_1 + 0x14));
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
LAB_005bd138:
  if (unaff_s2 == 0) goto LAB_005bd164;
LAB_005bd144:
  while( true ) {
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(unaff_s2,unaff_s4);
    (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s2);
LAB_005bd164:
    unaff_s1 = iVar6;
    if (!bVar1) {
LAB_005bd170:
      (*(code *)PTR_BIO_free_006a6e70)(unaff_s1);
      iVar6 = 0;
    }
LAB_005bd014:
    if (local_2c == *(int *)puVar4) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005bd488:
    bVar1 = true;
    iVar6 = unaff_s1;
  }
  return iVar6;
}

