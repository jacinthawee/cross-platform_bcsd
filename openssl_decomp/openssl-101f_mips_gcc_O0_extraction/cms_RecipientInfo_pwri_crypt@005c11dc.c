
undefined * cms_RecipientInfo_pwri_crypt(int param_1,int param_2,char *param_3)

{
  uint **ppuVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  char **ppcVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined *puVar12;
  char *pcVar13;
  undefined4 *unaff_s3;
  uint uVar14;
  uint uVar15;
  char *unaff_s6;
  byte *pbVar16;
  undefined4 local_c0;
  char acStack_bc [4];
  undefined auStack_b8 [140];
  char *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar12 = auStack_b8;
  uVar15 = *(uint *)(param_2 + 4);
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar13 = *(char **)(*(int *)(param_1 + 4) + 0xc);
  local_c0 = 0;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(puVar12);
  if (*(int *)(uVar15 + 0x10) == 0) {
    uVar11 = 0xb2;
    uVar4 = 0x157;
    goto LAB_005c1288;
  }
  unaff_s3 = *(undefined4 **)(uVar15 + 8);
  if ((unaff_s3 == (undefined4 *)0x0) ||
     (iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*unaff_s3), iVar3 != 0x37d)) {
    uVar11 = 0xb3;
    uVar4 = 0x15f;
    goto LAB_005c1288;
  }
  if (*(int *)unaff_s3[1] == 0x10) {
    puVar6 = (undefined4 *)((int *)unaff_s3[1])[1];
    local_c0 = puVar6[2];
    unaff_s3 = (undefined4 *)(*(code *)PTR_d2i_X509_ALGOR_006a9ee4)(0,&local_c0,*puVar6);
    if (unaff_s3 != (undefined4 *)0x0) {
      uVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*unaff_s3);
      uVar4 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar4);
      iVar3 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar4);
      if (iVar3 == 0) {
        uVar11 = 0x94;
        uVar4 = 0x175;
      }
      else {
        iVar3 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(puVar12,iVar3,0,0,0,param_3);
        if (iVar3 == 0) {
LAB_005c138c:
          param_3 = (char *)0x0;
          goto LAB_005c1390;
        }
        (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a8650)(puVar12,0);
        iVar3 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a9dac)(puVar12,unaff_s3[1]);
        if (iVar3 < 0) {
          uVar11 = 0x66;
          uVar4 = 0x180;
        }
        else {
          iVar3 = (*(code *)PTR_EVP_PBE_CipherInit_006aa340)
                            (**(undefined4 **)(uVar15 + 4),*(undefined4 *)(uVar15 + 0x10),
                             *(undefined4 *)(uVar15 + 0x14),(*(undefined4 **)(uVar15 + 4))[1],
                             puVar12,param_3);
          if (-1 < iVar3) {
            unaff_s6 = "r";
            if (param_3 == (char *)0x0) {
              param_3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                          (**(undefined4 **)(uVar15 + 0xc),"cms_pwri.c",0x1a4);
              if (param_3 == (char *)0x0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa7,0x41,"cms_pwri.c",0x1a9);
              }
              else {
                ppuVar1 = (uint **)(uVar15 + 0xc);
                uVar15 = **ppuVar1;
                uVar7 = (*ppuVar1)[2];
                uVar14 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(puVar12);
                if (uVar14 * 2 <= uVar15) {
                  if (uVar14 == 0) {
                    trap(7);
                  }
                  if (uVar15 % uVar14 == 0) {
                    pbVar16 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                                (uVar15,"cms_pwri.c",0xf0);
                    iVar3 = uVar15 + uVar14 * -2;
                    (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                              (puVar12,pbVar16 + iVar3,acStack_bc,uVar7 + iVar3,uVar14 * 2);
                    (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                              (puVar12,pbVar16,acStack_bc,pbVar16 + uVar14 + iVar3,uVar14);
                    (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                              (puVar12,pbVar16,acStack_bc,uVar7,uVar14 + iVar3);
                    (*(code *)PTR_EVP_DecryptInit_ex_006a8b54)(puVar12,0,0,0,0);
                    (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                              (puVar12,pbVar16,acStack_bc,pbVar16,uVar15);
                    if (((byte)((pbVar16[1] ^ pbVar16[4]) & (pbVar16[2] ^ pbVar16[5]) &
                               (pbVar16[3] ^ pbVar16[6])) == 0xff) &&
                       (uVar7 = (uint)*pbVar16, uVar7 - 4 <= uVar15)) {
                      (*(code *)PTR_memcpy_006aabf4)(param_3,pbVar16 + 4,uVar7);
                      (*(code *)PTR_OPENSSL_cleanse_006a8174)(pbVar16,uVar15);
                      (*(code *)PTR_CRYPTO_free_006a7f88)(pbVar16);
                      *(char **)(pcVar13 + 0x10) = param_3;
                      *(uint *)(pcVar13 + 0x14) = uVar7;
                      goto LAB_005c1570;
                    }
                    (*(code *)PTR_OPENSSL_cleanse_006a8174)(pbVar16,uVar15);
                    (*(code *)PTR_CRYPTO_free_006a7f88)(pbVar16);
                  }
                }
                (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa7,0xb4,"cms_pwri.c",0x1b1);
              }
              goto LAB_005c1390;
            }
            uVar14 = *(uint *)(pcVar13 + 0x14);
            uVar7 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(puVar12);
            if (uVar7 == 0) {
              trap(7);
            }
            uVar9 = ((uVar14 + 3 + uVar7) / uVar7) * uVar7;
            if (((uVar7 << 1 <= uVar9) && (uVar14 < 0x100)) &&
               (param_3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar9,"cms_pwri.c",0x198),
               param_3 != (char *)0x0)) {
              unaff_s6 = *(char **)(pcVar13 + 0x14);
              pbVar16 = *(byte **)(pcVar13 + 0x10);
              uVar7 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(puVar12);
              if (uVar7 == 0) {
                trap(7);
              }
              pcVar13 = (char *)(((uint)(unaff_s6 + uVar7 + 3) / uVar7) * uVar7);
              if (((char *)(uVar7 << 1) <= pcVar13) && (unaff_s6 < (char *)0x100)) {
                *param_3 = (char)unaff_s6;
                puVar5 = PTR_memcpy_006aabf4;
                param_3[1] = ~*pbVar16;
                param_3[2] = ~pbVar16[1];
                param_3[3] = ~pbVar16[2];
                (*(code *)puVar5)(param_3 + 4,pbVar16,unaff_s6);
                pcVar10 = unaff_s6 + 4;
                if (pcVar10 < pcVar13) goto LAB_005c186c;
                goto LAB_005c1520;
              }
              goto LAB_005c1390;
            }
            goto LAB_005c138c;
          }
          uVar11 = 6;
          uVar4 = 0x18c;
        }
      }
      param_3 = (char *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa7,uVar11,"cms_pwri.c",uVar4);
LAB_005c1390:
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(puVar12);
      if (param_3 == (char *)0x0) {
        puVar5 = (undefined *)0x0;
        goto LAB_005c13b8;
      }
      puVar5 = (undefined *)0x0;
      (*(code *)PTR_CRYPTO_free_006a7f88)(param_3);
      goto LAB_005c13b8;
    }
  }
  uVar11 = 0xb0;
  uVar4 = 0x16c;
LAB_005c1288:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa7,uVar11,"cms_pwri.c",uVar4);
  puVar5 = (undefined *)0x0;
  while (local_2c != *(char **)puVar2) {
    pcVar10 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005c186c:
    (*(code *)PTR_RAND_pseudo_bytes_006a8664)(param_3 + (int)pcVar10,pcVar13 + (-4 - (int)unaff_s6))
    ;
LAB_005c1520:
    unaff_s6 = acStack_bc;
    (*(code *)PTR_EVP_EncryptUpdate_006a8b8c)(puVar12,param_3,unaff_s6,param_3,pcVar13);
    (*(code *)PTR_EVP_EncryptUpdate_006a8b8c)(puVar12,param_3,unaff_s6,param_3,pcVar13);
    ppcVar8 = *(char ***)(uVar15 + 0xc);
    ppcVar8[2] = param_3;
    *ppcVar8 = pcVar13;
LAB_005c1570:
    puVar5 = (undefined *)0x1;
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(puVar12);
LAB_005c13b8:
    (*(code *)PTR_X509_ALGOR_free_006a8f94)(unaff_s3);
    puVar12 = puVar5;
  }
  return puVar5;
}

