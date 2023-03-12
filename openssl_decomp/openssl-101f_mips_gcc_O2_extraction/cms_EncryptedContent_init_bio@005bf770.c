
int cms_EncryptedContent_init_bio(int param_1)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  undefined *puVar14;
  undefined4 *puVar15;
  undefined4 local_40;
  undefined auStack_3c [16];
  undefined4 *local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  iVar13 = *(int *)(param_1 + 0xc);
  puVar15 = *(undefined4 **)(param_1 + 4);
  uVar5 = (*(code *)PTR_BIO_f_cipher_006a8648)();
  iVar6 = (*(code *)PTR_BIO_new_006a7fa4)(uVar5);
  if (iVar6 == 0) {
    iVar9 = 0x41;
    pcVar10 = "cms_enc.c";
    iVar7 = 0x78;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e);
    iVar6 = 0;
    goto LAB_005bf990;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(iVar6,0x81,0,&local_40);
  if (iVar13 == 0) {
    uVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar15);
    uVar5 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar5);
    iVar7 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar5);
    if (iVar7 == 0) {
      iVar9 = 0x94;
      goto LAB_005bfa6c;
    }
    iVar7 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(local_40,iVar7,0,0,0,iVar13 != 0);
    if (iVar7 < 1) goto LAB_005bfa58;
    iVar7 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a9dac)(local_40,puVar15[1]);
    if (iVar7 < 1) {
      iVar9 = 0x66;
      goto LAB_005bfa6c;
    }
    puVar14 = (undefined *)0x0;
    iVar8 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a90b8)(local_40);
LAB_005bf9f0:
    iVar9 = 0x92;
    pcVar11 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar8,"cms_enc.c");
    pcVar10 = "7 datafinal";
    if (pcVar11 == (char *)0x0) {
      pcVar10 = "cms_enc.c";
      iVar9 = 0x41;
      iVar7 = 0x78;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e);
      goto LAB_005bfa84;
    }
    iVar7 = (*(code *)PTR_EVP_CIPHER_CTX_rand_key_006aa25c)(local_40,pcVar11);
    pcVar12 = pcVar11;
    if (iVar7 < 1) {
      if (*(int *)(param_1 + 0x10) != 0) goto LAB_005bfa94;
LAB_005bfaf8:
      bVar1 = false;
      goto LAB_005bf964;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      *(char **)(param_1 + 0x10) = pcVar11;
      *(int *)(param_1 + 0x14) = iVar8;
      if (iVar13 == 0) {
        pcVar12 = (char *)0x0;
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
        goto LAB_005bf8c8;
      }
      bVar2 = true;
      pcVar12 = (char *)0x0;
LAB_005bf8ec:
      iVar9 = 0;
      iVar7 = 0;
      iVar13 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(local_40);
      if (iVar13 < 1) {
        iVar9 = 0x65;
LAB_005bfb1c:
        pcVar11 = "cms_enc.c";
        iVar7 = 0x78;
        bVar1 = false;
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e);
      }
      else {
        if (puVar14 != (undefined *)0x0) {
          iVar7 = (*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
          puVar15[1] = iVar7;
          if (iVar7 == 0) {
            iVar9 = 0x41;
          }
          else {
            iVar13 = (*(code *)PTR_EVP_CIPHER_param_to_asn1_006a9f18)(local_40);
            if (0 < iVar13) goto LAB_005bf944;
            iVar9 = 0x66;
          }
          goto LAB_005bfb1c;
        }
LAB_005bf944:
        bVar1 = true;
      }
      if ((*(int *)(param_1 + 0x10) != 0) && (!bVar2)) goto LAB_005bfa98;
      goto LAB_005bf95c;
    }
LAB_005bf8c8:
    if ((*(int *)(param_1 + 0x14) == iVar8) ||
       (iVar7 = (*(code *)PTR_EVP_CIPHER_CTX_set_key_length_006a9ba8)(local_40), 0 < iVar7)) {
      pcVar11 = *(char **)(param_1 + 0x10);
      bVar2 = false;
      goto LAB_005bf8ec;
    }
    if ((iVar13 == 0) && (*(int *)(param_1 + 0x18) == 0)) {
      bVar2 = false;
      (*(code *)PTR_OPENSSL_cleanse_006a8174)
                (*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(param_1 + 0x10));
      *(char **)(param_1 + 0x10) = pcVar12;
      puVar3 = PTR_ERR_clear_error_006a7fe0;
      pcVar12 = (char *)0x0;
      *(int *)(param_1 + 0x14) = iVar8;
      (*(code *)puVar3)();
      pcVar11 = *(char **)(param_1 + 0x10);
      goto LAB_005bf8ec;
    }
    iVar9 = 0x76;
    pcVar10 = "cms_enc.c";
    iVar7 = 0x78;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e);
    if (*(int *)(param_1 + 0x10) != 0) goto LAB_005bfa94;
    if (pcVar12 != (char *)0x0) goto LAB_005bfaf8;
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    pcVar10 = (char *)0x0;
    iVar9 = 0;
    iVar7 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(local_40,uVar5,0,0,0,iVar13 != 0);
    if (0 < iVar7) {
      uVar5 = (*(code *)PTR_EVP_CIPHER_CTX_cipher_006a9218)(local_40);
      uVar5 = (*(code *)PTR_EVP_CIPHER_type_006a9d90)(uVar5);
      uVar5 = (*(code *)PTR_OBJ_nid2obj_006a8240)(uVar5);
      puVar14 = PTR_EVP_CIPHER_CTX_iv_length_006a9164;
      *puVar15 = uVar5;
      iVar7 = (*(code *)puVar14)(local_40);
      if (iVar7 < 1) {
        puVar14 = (undefined *)0x0;
        iVar8 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a90b8)(local_40);
        iVar7 = *(int *)(param_1 + 0x10);
      }
      else {
        puVar14 = auStack_3c;
        iVar8 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(puVar14);
        if (iVar8 < 1) {
          iVar8 = 0;
          goto LAB_005bfa84;
        }
        iVar8 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a90b8)(local_40);
        iVar7 = *(int *)(param_1 + 0x10);
      }
      if (iVar7 == 0) goto LAB_005bf9f0;
      pcVar12 = (char *)0x0;
      goto LAB_005bf8c8;
    }
LAB_005bfa58:
    iVar9 = 0x65;
LAB_005bfa6c:
    pcVar10 = "cms_enc.c";
    iVar7 = 0x78;
    iVar8 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e);
LAB_005bfa84:
    if (*(int *)(param_1 + 0x10) != 0) {
      pcVar12 = (char *)0x0;
LAB_005bfa94:
      pcVar11 = pcVar10;
      bVar1 = false;
LAB_005bfa98:
      iVar7 = *(int *)(param_1 + 0x14);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)();
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
LAB_005bf95c:
      pcVar10 = pcVar11;
      if (pcVar12 != (char *)0x0) {
LAB_005bf964:
        iVar7 = iVar8;
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(pcVar12);
        (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar12);
      }
      if (bVar1) goto LAB_005bf990;
    }
  }
  (*(code *)PTR_BIO_free_006a7f70)(iVar6);
  iVar6 = 0;
LAB_005bf990:
  if (local_2c == *(undefined4 **)puVar4) {
    return iVar6;
  }
  puVar15 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar15[3] = iVar7;
  if (iVar9 != 0) {
    iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(pcVar10,"cms_enc.c",0xf6);
    puVar15[4] = iVar6;
    if (iVar6 == 0) {
      return 0;
    }
    (*(code *)PTR_memcpy_006aabf4)(iVar6,iVar9,pcVar10);
  }
  puVar15[5] = pcVar10;
  if (iVar7 != 0) {
    uVar5 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x15);
    *puVar15 = uVar5;
    return 1;
  }
  return 1;
}

