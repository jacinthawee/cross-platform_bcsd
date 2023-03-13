
undefined4 * cms_RecipientInfo_pwri_crypt(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint *puVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  char *pcVar15;
  uint uVar16;
  int iVar17;
  byte *pbVar18;
  undefined4 local_c0;
  undefined auStack_bc [4];
  undefined auStack_b8 [140];
  undefined4 *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar17 = *(int *)(param_2 + 4);
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iVar12 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  local_c0 = 0;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_b8);
  if (*(int *)(iVar17 + 0x10) == 0) {
    uVar11 = 0xb2;
    uVar4 = 0x152;
  }
  else {
    puVar14 = *(undefined4 **)(iVar17 + 8);
    if ((puVar14 == (undefined4 *)0x0) ||
       (iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar14), iVar3 != 0x37d)) {
      uVar11 = 0xb3;
      uVar4 = 0x159;
    }
    else {
      if (*(int *)puVar14[1] == 0x10) {
        puVar14 = (undefined4 *)((int *)puVar14[1])[1];
        local_c0 = puVar14[2];
        puVar14 = (undefined4 *)(*(code *)PTR_d2i_X509_ALGOR_006a8dc4)(0,&local_c0,*puVar14);
        if (puVar14 != (undefined4 *)0x0) {
          uVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar14);
          uVar4 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar4);
          pcVar10 = (char *)(*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar4);
          if (pcVar10 == (char *)0x0) {
            uVar11 = 0x94;
            uVar4 = 0x16b;
            goto LAB_005bed40;
          }
          iVar3 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(auStack_b8,pcVar10,0,0,0,param_3);
          if (iVar3 == 0) goto LAB_005beaf4;
          (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a7564)(auStack_b8,0);
          iVar3 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a8c8c)(auStack_b8,puVar14[1]);
          if (iVar3 < 0) {
            uVar11 = 0x66;
            uVar4 = 0x175;
LAB_005bed40:
            pcVar10 = (char *)0xa7;
            pcVar15 = (char *)0x0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa7,uVar11,"cms_pwri.c",uVar4);
LAB_005beaf8:
            (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_b8);
            if (pcVar15 == (char *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar5 = (undefined4 *)0x0;
              (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar15);
            }
          }
          else {
            iVar3 = (*(code *)PTR_EVP_PBE_CipherInit_006a9228)
                              (**(undefined4 **)(iVar17 + 4),*(undefined4 *)(iVar17 + 0x10),
                               *(undefined4 *)(iVar17 + 0x14),(*(undefined4 **)(iVar17 + 4))[1],
                               auStack_b8,param_3);
            if (iVar3 < 0) {
              uVar11 = 6;
              uVar4 = 0x180;
              goto LAB_005bed40;
            }
            if (param_3 == 0) {
              pcVar15 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)
                                          (**(undefined4 **)(iVar17 + 0xc),"cms_pwri.c",0x195);
              if (pcVar15 == (char *)0x0) {
                pcVar10 = (char *)0xa7;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa7,0x41,"cms_pwri.c",0x198);
                goto LAB_005beaf8;
              }
              pcVar10 = **(char ***)(iVar17 + 0xc);
              pcVar8 = (*(char ***)(iVar17 + 0xc))[2];
              uVar6 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(auStack_b8);
              if ((char *)(uVar6 * 2) <= pcVar10) {
                if (uVar6 == 0) {
                  trap(7);
                }
                if (((uint)pcVar10 % uVar6 == 0) &&
                   (pbVar18 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)
                                                (pcVar10,"cms_pwri.c",0xec), pbVar18 != (byte *)0x0)
                   ) {
                  pcVar9 = pcVar10 + uVar6 * -2;
                  (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                            (auStack_b8,pbVar18 + (int)pcVar9,auStack_bc,pcVar9 + (int)pcVar8,
                             (char *)(uVar6 * 2));
                  (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                            (auStack_b8,pbVar18,auStack_bc,pbVar18 + (int)(pcVar9 + uVar6),uVar6);
                  (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                            (auStack_b8,pbVar18,auStack_bc,pcVar8,pcVar9 + uVar6);
                  (*(code *)PTR_EVP_DecryptInit_ex_006a7a68)(auStack_b8,0,0,0,0);
                  (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                            (auStack_b8,pbVar18,auStack_bc,pbVar18,pcVar10);
                  if (((byte)((pbVar18[1] ^ pbVar18[4]) & (pbVar18[2] ^ pbVar18[5]) &
                             (pbVar18[3] ^ pbVar18[6])) == 0xff) &&
                     (uVar6 = (uint)*pbVar18, (char *)(uVar6 - 4) <= pcVar10)) {
                    (*(code *)PTR_memcpy_006a9aec)(pcVar15,pbVar18 + 4,uVar6);
                    (*(code *)PTR_OPENSSL_cleanse_006a7074)(pbVar18);
                    (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar18);
                    *(char **)(iVar12 + 0x10) = pcVar15;
                    *(uint *)(iVar12 + 0x14) = uVar6;
                    goto LAB_005becf4;
                  }
                  (*(code *)PTR_OPENSSL_cleanse_006a7074)(pbVar18,pcVar10);
                  (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar18);
                }
              }
              pcVar10 = (char *)0xa7;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa7,0xb4,"cms_pwri.c",0x19e);
              goto LAB_005beaf8;
            }
            uVar16 = *(uint *)(iVar12 + 0x14);
            uVar6 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(auStack_b8);
            pcVar10 = (char *)(uVar6 << 1);
            if (uVar6 == 0) {
              trap(7);
            }
            pcVar15 = (char *)(((uVar16 + 3 + uVar6) / uVar6) * uVar6);
            if ((pcVar15 < pcVar10) || (pcVar10 = "encrypt", 0xff < uVar16)) {
LAB_005beaf4:
              pcVar15 = (char *)0x0;
              goto LAB_005beaf8;
            }
            pcVar10 = "cms_pwri.c";
            pcVar15 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pcVar15,"cms_pwri.c",0x18b);
            if (pcVar15 == (char *)0x0) goto LAB_005beaf4;
            uVar16 = *(uint *)(iVar12 + 0x14);
            pbVar18 = *(byte **)(iVar12 + 0x10);
            uVar6 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(auStack_b8);
            if (uVar6 == 0) {
              trap(7);
            }
            uVar13 = ((uVar16 + 3 + uVar6) / uVar6) * uVar6;
            if ((uVar13 < uVar6 << 1) || (0xff < uVar16)) goto LAB_005beaf8;
            *pcVar15 = (char)uVar16;
            puVar2 = PTR_memcpy_006a9aec;
            pcVar15[1] = ~*pbVar18;
            pcVar15[2] = ~pbVar18[1];
            pcVar15[3] = ~pbVar18[2];
            (*(code *)puVar2)(pcVar15 + 4,pbVar18,uVar16);
            if (uVar16 + 4 < uVar13) {
              pcVar10 = (char *)((uVar13 - uVar16) + -4);
              iVar12 = (*(code *)PTR_RAND_bytes_006a7574)(pcVar15 + uVar16 + 4);
              if (iVar12 < 1) goto LAB_005beaf8;
            }
            (*(code *)PTR_EVP_EncryptUpdate_006a7aa0)(auStack_b8,pcVar15,auStack_bc,pcVar15,uVar13);
            pcVar10 = pcVar15;
            (*(code *)PTR_EVP_EncryptUpdate_006a7aa0)(auStack_b8,pcVar15,auStack_bc,pcVar15,uVar13);
            puVar7 = *(uint **)(iVar17 + 0xc);
            puVar7[2] = (uint)pcVar15;
            *puVar7 = uVar13;
LAB_005becf4:
            puVar5 = (undefined4 *)0x1;
            (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_b8);
          }
          (*(code *)PTR_X509_ALGOR_free_006a7ea4)(puVar14);
          goto LAB_005bea08;
        }
      }
      uVar11 = 0xb0;
      uVar4 = 0x164;
    }
  }
  pcVar10 = (char *)0xa7;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa7,uVar11,"cms_pwri.c",uVar4);
  puVar5 = (undefined4 *)0x0;
LAB_005bea08:
  if (local_2c != *(undefined4 **)puVar1) {
    puVar14 = local_2c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    puVar5 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x10,"pqueue.c",0x47);
    if (puVar5 != (undefined4 *)0x0) {
      uVar4 = puVar14[1];
      *puVar5 = *puVar14;
      puVar5[1] = uVar4;
      puVar5[2] = pcVar10;
      puVar5[3] = 0;
    }
    return puVar5;
  }
  return puVar5;
}

