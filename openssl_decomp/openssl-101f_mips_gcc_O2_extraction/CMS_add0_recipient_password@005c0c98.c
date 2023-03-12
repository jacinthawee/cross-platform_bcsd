
CMS_RecipientInfo *
CMS_add0_recipient_password
          (CMS_ContentInfo *cms,int iter,int wrap_nid,int pbe_nid,uchar *pass,ssize_t passlen,
          EVP_CIPHER *kekciph)

{
  uint **ppuVar1;
  undefined *puVar2;
  undefined *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  EVP_CIPHER *pEVar7;
  CMS_RecipientInfo *pCVar8;
  undefined4 *puVar9;
  uint uVar10;
  char **ppcVar11;
  EVP_CIPHER *pEVar12;
  uint uVar13;
  char *pcVar14;
  char *pcVar15;
  undefined4 uVar16;
  CMS_RecipientInfo *pCVar17;
  char *pcVar18;
  uint uVar19;
  EVP_CIPHER *unaff_s5;
  uint uVar20;
  char *unaff_s6;
  undefined4 *unaff_s7;
  byte *pbVar21;
  code *pcVar22;
  undefined4 unaff_s8;
  undefined4 uStack_1b0;
  char acStack_1ac [4];
  CMS_RecipientInfo aCStack_1a8 [140];
  char *pcStack_11c;
  EVP_CIPHER *pEStack_118;
  EVP_CIPHER *pEStack_114;
  undefined *puStack_110;
  undefined4 *puStack_10c;
  uchar *puStack_108;
  EVP_CIPHER *pEStack_104;
  char *pcStack_100;
  undefined4 *puStack_fc;
  undefined4 uStack_f8;
  code *pcStack_f4;
  _func_1092 **local_e0;
  undefined *local_d8;
  undefined4 *local_d0;
  int local_cc;
  EVP_CIPHER aEStack_c8 [3];
  int local_2c;
  
  puStack_110 = PTR___stack_chk_guard_006aabf0;
  local_d8 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar15 = (char *)wrap_nid;
  pcVar4 = (char *)cms_get0_enveloped();
  if (pcVar4 == (char *)0x0) {
    unaff_s5 = (EVP_CIPHER *)0x0;
LAB_005c1084:
    pEVar12 = aEStack_c8;
    (**(code **)(local_d8 + -0x7380))();
    pcVar4 = unaff_s6;
joined_r0x005c1090:
    if (unaff_s5 == (EVP_CIPHER *)0x0) {
      wrap_nid = (int)aEStack_c8;
      pEVar7 = (EVP_CIPHER *)0x0;
      pEStack_114 = kekciph;
    }
    else {
LAB_005c0fe0:
      wrap_nid = (int)aEStack_c8;
      pEVar12 = unaff_s5;
      (**(code **)(local_d8 + -0x6f4c))();
      pEVar7 = (EVP_CIPHER *)0x0;
      pEStack_114 = kekciph;
    }
  }
  else {
    if (wrap_nid < 1) {
      pcVar22 = *(code **)(local_d8 + -0x6f28);
      if ((kekciph == (EVP_CIPHER *)0x0) &&
         (kekciph = *(EVP_CIPHER **)(*(int *)(pcVar4 + 0xc) + 0xc), kekciph == (EVP_CIPHER *)0x0)) {
        pcVar22 = *(code **)(local_d8 + -0x6eb0);
        goto LAB_005c10bc;
      }
LAB_005c0d20:
      wrap_nid = (int)aEStack_c8;
      unaff_s5 = (EVP_CIPHER *)(*pcVar22)();
      (**(code **)(local_d8 + -0x7390))(wrap_nid);
      pcVar15 = (char *)0x0;
      local_e0 = (_func_1092 **)0x0;
      iVar5 = (**(code **)(local_d8 + -0x735c))(wrap_nid,kekciph,0,0);
      unaff_s6 = pcVar4;
      if (iVar5 < 1) {
        pcVar22 = *(code **)(local_d8 + -0x6eb0);
        pcVar15 = &DAT_00000006;
        local_e0 = (_func_1092 **)&DAT_00000080;
LAB_005c1070:
        (*pcVar22)(0x2e,0xa5,pcVar15,"cms_pwri.c");
        goto LAB_005c1084;
      }
      iVar5 = (**(code **)(local_d8 + -0x6d7c))(wrap_nid);
      if (0 < iVar5) {
        kekciph = (EVP_CIPHER *)&aEStack_c8[2].set_asn1_parameters;
        iVar5 = (**(code **)(local_d8 + -0x787c))(kekciph,iVar5);
        if (iVar5 < 1) goto LAB_005c1084;
        local_e0 = (_func_1092 **)kekciph;
        iVar5 = (**(code **)(local_d8 + -0x735c))(wrap_nid,0,0,0);
        if (iVar5 < 1) {
          pcVar22 = *(code **)(local_d8 + -0x6eb0);
          pcVar15 = &DAT_00000006;
          local_e0 = (_func_1092 **)0x8d;
        }
        else {
          iVar5 = (**(code **)(local_d8 + -0x6f24))();
          unaff_s5->block_size = iVar5;
          if (iVar5 == 0) {
            pcVar22 = *(code **)(local_d8 + -0x6eb0);
            pcVar15 = &DAT_00000041;
            local_e0 = (_func_1092 **)&DAT_00000094;
          }
          else {
            iVar5 = (**(code **)(local_d8 + -0x5fc8))(wrap_nid,iVar5);
            if (0 < iVar5) goto LAB_005c0de8;
            pcVar22 = *(code **)(local_d8 + -0x6eb0);
            pcVar15 = (char *)0x66;
            local_e0 = (_func_1092 **)0x9a;
          }
        }
        goto LAB_005c1070;
      }
LAB_005c0de8:
      uVar6 = (**(code **)(local_d8 + -0x6cc8))(wrap_nid);
      uVar6 = (**(code **)(local_d8 + -0x6150))(uVar6);
      iVar5 = (**(code **)(local_d8 + -0x7ca0))(uVar6);
      pcVar22 = *(code **)(local_d8 + -0x7380);
      unaff_s5->nid = iVar5;
      (*pcVar22)(wrap_nid);
      pEVar7 = (EVP_CIPHER *)(**(code **)(local_d8 + -0x6768))(*(undefined4 *)(local_d8 + -0x5a18));
      kekciph = pEVar7;
      if (pEVar7 != (EVP_CIPHER *)0x0) {
        unaff_s7 = (undefined4 *)
                   (**(code **)(local_d8 + -0x6768))(*(undefined4 *)(local_d8 + -0x59dc));
        pEVar7->block_size = (int)unaff_s7;
        if (unaff_s7 == (undefined4 *)0x0) {
LAB_005c0f90:
          pcVar15 = &DAT_00000041;
          local_e0 = (_func_1092 **)0xd1;
          (**(code **)(local_d8 + -0x6eb0))(0x2e,0xa5,0x41,"cms_pwri.c");
          (**(code **)(local_d8 + -0x7380))(wrap_nid);
        }
        else {
          unaff_s8 = 3;
          pcVar22 = *(code **)(local_d8 + -0x6f4c);
          uVar6 = unaff_s7[2];
          pEVar7->nid = 3;
          (*pcVar22)(uVar6);
          local_d0 = (undefined4 *)(**(code **)(local_d8 + -0x6f28))();
          unaff_s7[2] = local_d0;
          if (local_d0 == (undefined4 *)0x0) goto LAB_005c0f90;
          uVar6 = (**(code **)(local_d8 + -0x7ca0))(0x37d);
          local_cc = unaff_s7[2];
          pcVar22 = *(code **)(local_d8 + -0x6f24);
          *local_d0 = uVar6;
          uVar6 = (*pcVar22)();
          iVar5 = unaff_s7[2];
          *(undefined4 *)(local_cc + 4) = uVar6;
          if ((*(int *)(iVar5 + 4) == 0) ||
             (iVar5 = (**(code **)(local_d8 + -0x5fcc))
                                (unaff_s5,*(undefined4 *)(local_d8 + -23000),*(int *)(iVar5 + 4) + 4
                                ), iVar5 == 0)) goto LAB_005c0f90;
          pcVar22 = *(code **)(local_d8 + -0x6f4c);
          **(undefined4 **)(unaff_s7[2] + 4) = 0x10;
          (*pcVar22)(unaff_s5);
          pcVar15 = (char *)0x0;
          local_e0 = (_func_1092 **)0xffffffff;
          iVar5 = (**(code **)(local_d8 + -0x59d4))(iter,0,0,0xffffffff);
          unaff_s7[1] = iVar5;
          if (iVar5 != 0) {
            if (pEVar7->nid == 3) {
              iter = pEVar7->block_size;
              *(uchar **)(iter + 0x10) = pass;
              if ((pass != (uchar *)0x0) && (passlen < 0)) {
                passlen = (**(code **)(local_d8 + -0x53b0))(pass);
              }
              *(ssize_t *)(iter + 0x14) = passlen;
            }
            else {
              pcVar15 = (char *)0xb1;
              local_e0 = (_func_1092 **)0x47;
              (**(code **)(local_d8 + -0x6eb0))(0x2e,0xa8,0xb1,"cms_pwri.c");
            }
            pcVar22 = *(code **)(local_d8 + -0x7e38);
            pEVar12 = *(EVP_CIPHER **)(pcVar4 + 8);
            *unaff_s7 = 0;
            iVar5 = (*pcVar22)(pEVar12,pEVar7);
            pEStack_114 = pEVar7;
            if (iVar5 == 0) {
              unaff_s5 = (EVP_CIPHER *)0x0;
              goto LAB_005c0f90;
            }
            goto LAB_005c1020;
          }
          unaff_s5 = (EVP_CIPHER *)0x0;
          (**(code **)(local_d8 + -0x7380))(wrap_nid);
        }
        pEVar12 = pEVar7;
        (**(code **)(local_d8 + -0x6764))(pEVar7,*(undefined4 *)(local_d8 + -0x5a18));
        goto joined_r0x005c1090;
      }
      pcVar15 = &DAT_00000041;
      local_e0 = (_func_1092 **)0xd1;
      (**(code **)(local_d8 + -0x6eb0))(0x2e,0xa5,0x41,"cms_pwri.c");
      (**(code **)(local_d8 + -0x7380))(wrap_nid);
      goto LAB_005c0fe0;
    }
    if ((kekciph == (EVP_CIPHER *)0x0) &&
       (kekciph = *(EVP_CIPHER **)(*(int *)(pcVar4 + 0xc) + 0xc), kekciph == (EVP_CIPHER *)0x0)) {
      pcVar22 = *(code **)(local_d8 + -0x6eb0);
LAB_005c10bc:
      pcVar15 = (char *)0x7e;
      local_e0 = (_func_1092 **)&DAT_00000070;
    }
    else {
      if (wrap_nid == 0x37d) {
        pcVar22 = *(code **)(local_d8 + -0x6f28);
        goto LAB_005c0d20;
      }
      pcVar22 = *(code **)(local_d8 + -0x6eb0);
      pcVar15 = (char *)0xb3;
      local_e0 = (_func_1092 **)&DAT_00000076;
    }
    pEVar12 = (EVP_CIPHER *)0x2e;
    (*pcVar22)(0x2e,0xa5,pcVar15,"cms_pwri.c");
    pEVar7 = (EVP_CIPHER *)0x0;
    pEStack_114 = kekciph;
  }
LAB_005c1020:
  if (local_2c == *(int *)puStack_110) {
    return (CMS_RecipientInfo *)pEVar7;
  }
  pcStack_f4 = cms_RecipientInfo_pwri_crypt;
  iVar5 = local_2c;
  (**(code **)(local_d8 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puStack_108 = pass;
  pCVar17 = aCStack_1a8;
  uVar20 = *(uint *)(iVar5 + 4);
  pcStack_11c = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar18 = *(char **)(pEVar12->block_size + 0xc);
  uStack_1b0 = 0;
  pEStack_118 = (EVP_CIPHER *)wrap_nid;
  puStack_10c = (undefined4 *)iter;
  pEStack_104 = unaff_s5;
  pcStack_100 = pcVar4;
  puStack_fc = unaff_s7;
  uStack_f8 = unaff_s8;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(pCVar17);
  if (*(int *)(uVar20 + 0x10) == 0) {
    uVar16 = 0xb2;
    uVar6 = 0x157;
    goto LAB_005c1288;
  }
  iter = *(undefined4 *)(uVar20 + 8);
  if (((undefined4 *)iter == (undefined4 *)0x0) ||
     (iVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)iter), iVar5 != 0x37d)) {
    uVar16 = 0xb3;
    uVar6 = 0x15f;
    goto LAB_005c1288;
  }
  if (**(int **)(iter + 4) == 0x10) {
    puVar9 = (undefined4 *)(*(int **)(iter + 4))[1];
    uStack_1b0 = puVar9[2];
    iter = (*(code *)PTR_d2i_X509_ALGOR_006a9ee4)(0,&uStack_1b0,*puVar9);
    if ((undefined4 *)iter != (undefined4 *)0x0) {
      uVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)iter);
      uVar6 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar6);
      iVar5 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar6);
      if (iVar5 == 0) {
        uVar16 = 0x94;
        uVar6 = 0x175;
      }
      else {
        iVar5 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(pCVar17,iVar5,0,0,0,pcVar15);
        if (iVar5 == 0) {
LAB_005c138c:
          pcVar15 = (char *)0x0;
          goto LAB_005c1390;
        }
        (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a8650)(pCVar17,0);
        iVar5 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a9dac)(pCVar17,*(undefined4 *)(iter + 4));
        if (iVar5 < 0) {
          uVar16 = 0x66;
          uVar6 = 0x180;
        }
        else {
          iVar5 = (*(code *)PTR_EVP_PBE_CipherInit_006aa340)
                            (**(undefined4 **)(uVar20 + 4),*(undefined4 *)(uVar20 + 0x10),
                             *(undefined4 *)(uVar20 + 0x14),(*(undefined4 **)(uVar20 + 4))[1],
                             pCVar17,pcVar15);
          if (-1 < iVar5) {
            pcVar4 = "7 datafinal";
            if (pcVar15 == (char *)0x0) {
              pcVar15 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                          (**(undefined4 **)(uVar20 + 0xc),"cms_pwri.c",0x1a4);
              if (pcVar15 == (char *)0x0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa7,0x41,"cms_pwri.c",0x1a9);
              }
              else {
                ppuVar1 = (uint **)(uVar20 + 0xc);
                uVar20 = **ppuVar1;
                uVar10 = (*ppuVar1)[2];
                uVar19 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(pCVar17);
                if (uVar19 * 2 <= uVar20) {
                  if (uVar19 == 0) {
                    trap(7);
                  }
                  if (uVar20 % uVar19 == 0) {
                    pbVar21 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                                (uVar20,"cms_pwri.c",0xf0);
                    iVar5 = uVar20 + uVar19 * -2;
                    (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                              (pCVar17,pbVar21 + iVar5,acStack_1ac,uVar10 + iVar5,uVar19 * 2);
                    (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                              (pCVar17,pbVar21,acStack_1ac,pbVar21 + uVar19 + iVar5,uVar19);
                    (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                              (pCVar17,pbVar21,acStack_1ac,uVar10,uVar19 + iVar5);
                    (*(code *)PTR_EVP_DecryptInit_ex_006a8b54)(pCVar17,0,0,0,0);
                    (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)
                              (pCVar17,pbVar21,acStack_1ac,pbVar21,uVar20);
                    if (((byte)((pbVar21[1] ^ pbVar21[4]) & (pbVar21[2] ^ pbVar21[5]) &
                               (pbVar21[3] ^ pbVar21[6])) == 0xff) &&
                       (uVar10 = (uint)*pbVar21, uVar10 - 4 <= uVar20)) {
                      (*(code *)PTR_memcpy_006aabf4)(pcVar15,pbVar21 + 4,uVar10);
                      (*(code *)PTR_OPENSSL_cleanse_006a8174)(pbVar21,uVar20);
                      (*(code *)PTR_CRYPTO_free_006a7f88)(pbVar21);
                      *(char **)(pcVar18 + 0x10) = pcVar15;
                      *(uint *)(pcVar18 + 0x14) = uVar10;
                      goto LAB_005c1570;
                    }
                    (*(code *)PTR_OPENSSL_cleanse_006a8174)(pbVar21,uVar20);
                    (*(code *)PTR_CRYPTO_free_006a7f88)(pbVar21);
                  }
                }
                (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa7,0xb4,"cms_pwri.c",0x1b1);
              }
              goto LAB_005c1390;
            }
            uVar19 = *(uint *)(pcVar18 + 0x14);
            uVar10 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(pCVar17);
            if (uVar10 == 0) {
              trap(7);
            }
            uVar13 = ((uVar19 + 3 + uVar10) / uVar10) * uVar10;
            if (((uVar10 << 1 <= uVar13) && (uVar19 < 0x100)) &&
               (pcVar15 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar13,"cms_pwri.c",0x198),
               pcVar15 != (char *)0x0)) {
              pcVar4 = *(char **)(pcVar18 + 0x14);
              pbVar21 = *(byte **)(pcVar18 + 0x10);
              uVar10 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(pCVar17);
              if (uVar10 == 0) {
                trap(7);
              }
              pcVar18 = (char *)(((uint)(pcVar4 + uVar10 + 3) / uVar10) * uVar10);
              if (((char *)(uVar10 << 1) <= pcVar18) && (pcVar4 < (char *)0x100)) {
                *pcVar15 = (char)pcVar4;
                puVar3 = PTR_memcpy_006aabf4;
                pcVar15[1] = ~*pbVar21;
                pcVar15[2] = ~pbVar21[1];
                pcVar15[3] = ~pbVar21[2];
                (*(code *)puVar3)(pcVar15 + 4,pbVar21,pcVar4);
                pcVar14 = pcVar4 + 4;
                if (pcVar14 < pcVar18) goto LAB_005c186c;
                goto LAB_005c1520;
              }
              goto LAB_005c1390;
            }
            goto LAB_005c138c;
          }
          uVar16 = 6;
          uVar6 = 0x18c;
        }
      }
      pcVar15 = (char *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa7,uVar16,"cms_pwri.c",uVar6);
LAB_005c1390:
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(pCVar17);
      if (pcVar15 != (char *)0x0) {
        pCVar8 = (CMS_RecipientInfo *)0x0;
        (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar15);
        goto LAB_005c13b8;
      }
      pCVar8 = (CMS_RecipientInfo *)0x0;
      goto LAB_005c13b8;
    }
  }
  uVar16 = 0xb0;
  uVar6 = 0x16c;
LAB_005c1288:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa7,uVar16,"cms_pwri.c",uVar6);
  pCVar8 = (CMS_RecipientInfo *)0x0;
  while (pcStack_11c != *(char **)puVar2) {
    pcVar14 = pcStack_11c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005c186c:
    (*(code *)PTR_RAND_pseudo_bytes_006a8664)(pcVar15 + (int)pcVar14,pcVar18 + (-4 - (int)pcVar4));
LAB_005c1520:
    pcVar4 = acStack_1ac;
    (*(code *)PTR_EVP_EncryptUpdate_006a8b8c)(pCVar17,pcVar15,pcVar4,pcVar15,pcVar18);
    (*(code *)PTR_EVP_EncryptUpdate_006a8b8c)(pCVar17,pcVar15,pcVar4,pcVar15,pcVar18);
    ppcVar11 = *(char ***)(uVar20 + 0xc);
    ppcVar11[2] = pcVar15;
    *ppcVar11 = pcVar18;
LAB_005c1570:
    pCVar8 = (CMS_RecipientInfo *)0x1;
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(pCVar17);
LAB_005c13b8:
    (*(code *)PTR_X509_ALGOR_free_006a8f94)(iter);
    pCVar17 = pCVar8;
  }
  return pCVar8;
}

