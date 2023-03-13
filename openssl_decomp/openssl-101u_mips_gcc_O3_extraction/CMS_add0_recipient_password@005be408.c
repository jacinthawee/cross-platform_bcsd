
CMS_RecipientInfo *
CMS_add0_recipient_password
          (CMS_ContentInfo *cms,int iter,int wrap_nid,int pbe_nid,uchar *pass,ssize_t passlen,
          EVP_CIPHER *kekciph)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  EVP_CIPHER *pEVar5;
  int iVar6;
  CMS_RecipientInfo *pCVar7;
  uint uVar8;
  uint *puVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 *puVar12;
  char *pcVar13;
  int iVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined4 *puVar17;
  char *pcVar18;
  uint uVar19;
  EVP_CIPHER *unaff_s5;
  int iVar20;
  int unaff_s6;
  undefined4 *unaff_s7;
  byte *pbVar21;
  code *pcVar22;
  undefined4 unaff_s8;
  undefined4 uStack_1b0;
  undefined auStack_1ac [4];
  undefined auStack_1a8 [140];
  undefined4 *puStack_11c;
  EVP_CIPHER *pEStack_118;
  EVP_CIPHER *pEStack_114;
  undefined *puStack_110;
  int iStack_10c;
  uchar *puStack_108;
  EVP_CIPHER *pEStack_104;
  int iStack_100;
  undefined4 *puStack_fc;
  undefined4 uStack_f8;
  code *pcStack_f4;
  _func_1092 **local_e0;
  undefined *local_d8;
  undefined4 *local_d0;
  int local_cc;
  EVP_CIPHER aEStack_c8 [3];
  int local_2c;
  
  puStack_110 = PTR___stack_chk_guard_006a9ae8;
  local_d8 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar14 = wrap_nid;
  iStack_100 = cms_get0_enveloped();
  if (iStack_100 == 0) {
LAB_005be754:
    pEVar5 = (EVP_CIPHER *)0x0;
    pEStack_114 = kekciph;
    iStack_100 = unaff_s6;
  }
  else {
    unaff_s6 = iStack_100;
    if (0 < wrap_nid) {
      if ((kekciph == (EVP_CIPHER *)0x0) &&
         (kekciph = *(EVP_CIPHER **)(*(int *)(iStack_100 + 0xc) + 0xc), kekciph == (EVP_CIPHER *)0x0
         )) {
        pcVar22 = *(code **)(local_d8 + -0x6eac);
        goto LAB_005be828;
      }
      if (wrap_nid == 0x37d) {
        pcVar22 = *(code **)(local_d8 + -0x6f18);
        pEVar5 = kekciph;
        goto LAB_005be490;
      }
      pcVar22 = *(code **)(local_d8 + -0x6eac);
      iVar14 = 0xb3;
      local_e0 = (_func_1092 **)&DAT_00000076;
LAB_005be7a4:
      cms = (CMS_ContentInfo *)0x2e;
      (*pcVar22)(0x2e,0xa5,iVar14,"cms_pwri.c");
      goto LAB_005be754;
    }
    pcVar22 = *(code **)(local_d8 + -0x6f18);
    pEVar5 = kekciph;
    if ((kekciph == (EVP_CIPHER *)0x0) &&
       (kekciph = *(EVP_CIPHER **)(*(int *)(iStack_100 + 0xc) + 0xc), pEVar5 = kekciph,
       kekciph == (EVP_CIPHER *)0x0)) {
      pcVar22 = *(code **)(local_d8 + -0x6eac);
LAB_005be828:
      iVar14 = 0x7e;
      local_e0 = (_func_1092 **)0x71;
      goto LAB_005be7a4;
    }
LAB_005be490:
    wrap_nid = (int)aEStack_c8;
    unaff_s5 = (EVP_CIPHER *)(*pcVar22)();
    if (unaff_s5 == (EVP_CIPHER *)0x0) {
LAB_005be838:
      iVar14 = 0x41;
      local_e0 = (_func_1092 **)0xcd;
      (**(code **)(local_d8 + -0x6eac))(0x2e,0xa5,0x41,"cms_pwri.c");
      cms = (CMS_ContentInfo *)wrap_nid;
      (**(code **)(local_d8 + -0x736c))();
      kekciph = pEVar5;
      if (unaff_s5 == (EVP_CIPHER *)0x0) goto LAB_005be754;
      pcVar22 = *(code **)(local_d8 + -0x6f3c);
      pEStack_114 = pEVar5;
LAB_005be7f8:
      cms = (CMS_ContentInfo *)unaff_s5;
      (*pcVar22)();
      pEVar5 = (EVP_CIPHER *)0x0;
    }
    else {
      (**(code **)(local_d8 + -0x737c))(wrap_nid);
      iVar14 = 0;
      local_e0 = (_func_1092 **)0x0;
      iVar3 = (**(code **)(local_d8 + -0x7348))(wrap_nid,pEVar5,0,0);
      if (iVar3 < 1) {
        pcVar22 = *(code **)(local_d8 + -0x6eac);
        iVar14 = 6;
        local_e0 = (_func_1092 **)0x82;
LAB_005be7d0:
        (*pcVar22)(0x2e,0xa5,iVar14,"cms_pwri.c");
LAB_005be7e4:
        (**(code **)(local_d8 + -0x736c))(wrap_nid);
LAB_005be7f4:
        pcVar22 = *(code **)(local_d8 + -0x6f3c);
        pEStack_114 = pEVar5;
        goto LAB_005be7f8;
      }
      iVar3 = (**(code **)(local_d8 + -0x6de8))(wrap_nid);
      if (0 < iVar3) {
        pEVar5 = (EVP_CIPHER *)&aEStack_c8[2].set_asn1_parameters;
        iVar3 = (**(code **)(local_d8 + -0x786c))(pEVar5,iVar3);
        if (0 < iVar3) {
          local_e0 = (_func_1092 **)pEVar5;
          iVar14 = (**(code **)(local_d8 + -0x7348))(wrap_nid,0,0,0);
          if (iVar14 < 1) {
            pcVar22 = *(code **)(local_d8 + -0x6eac);
            iVar14 = 6;
            local_e0 = (_func_1092 **)&DAT_0000008c;
          }
          else {
            iVar14 = (**(code **)(local_d8 + -0x6f14))();
            unaff_s5->block_size = iVar14;
            if (iVar14 == 0) {
              pcVar22 = *(code **)(local_d8 + -0x6eac);
              iVar14 = 0x41;
              local_e0 = (_func_1092 **)0x91;
            }
            else {
              iVar14 = (**(code **)(local_d8 + -0x5fe4))(wrap_nid,iVar14);
              if (0 < iVar14) goto LAB_005be55c;
              pcVar22 = *(code **)(local_d8 + -0x6eac);
              iVar14 = 0x66;
              local_e0 = (_func_1092 **)0x96;
            }
          }
          goto LAB_005be7d0;
        }
        goto LAB_005be7e4;
      }
LAB_005be55c:
      uVar4 = (**(code **)(local_d8 + -0x6cf4))(wrap_nid);
      uVar4 = (**(code **)(local_d8 + -0x5fe8))(uVar4);
      iVar14 = (**(code **)(local_d8 + -0x7ca0))(uVar4);
      pcVar22 = *(code **)(local_d8 + -0x736c);
      unaff_s5->nid = iVar14;
      (*pcVar22)(wrap_nid);
      pEVar5 = (EVP_CIPHER *)(**(code **)(local_d8 + -0x678c))(*(undefined4 *)(local_d8 + -0x5a24));
      if (pEVar5 == (EVP_CIPHER *)0x0) goto LAB_005be838;
      unaff_s7 = (undefined4 *)
                 (**(code **)(local_d8 + -0x678c))(*(undefined4 *)(local_d8 + -0x59e8));
      pEVar5->block_size = (int)unaff_s7;
      if (unaff_s7 == (undefined4 *)0x0) {
LAB_005be704:
        iVar14 = 0x41;
        local_e0 = (_func_1092 **)0xcd;
        (**(code **)(local_d8 + -0x6eac))(0x2e,0xa5,0x41,"cms_pwri.c");
        (**(code **)(local_d8 + -0x736c))(wrap_nid);
LAB_005be73c:
        cms = (CMS_ContentInfo *)pEVar5;
        (**(code **)(local_d8 + -0x6788))(pEVar5,*(undefined4 *)(local_d8 + -0x5a24));
        kekciph = pEVar5;
        if (unaff_s5 == (EVP_CIPHER *)0x0) goto LAB_005be754;
        goto LAB_005be7f4;
      }
      unaff_s8 = 3;
      pcVar22 = *(code **)(local_d8 + -0x6f3c);
      uVar4 = unaff_s7[2];
      pEVar5->nid = 3;
      (*pcVar22)(uVar4);
      local_d0 = (undefined4 *)(**(code **)(local_d8 + -0x6f18))();
      unaff_s7[2] = local_d0;
      if (local_d0 == (undefined4 *)0x0) goto LAB_005be704;
      uVar4 = (**(code **)(local_d8 + -0x7ca0))(0x37d);
      local_cc = unaff_s7[2];
      pcVar22 = *(code **)(local_d8 + -0x6f14);
      *local_d0 = uVar4;
      uVar4 = (*pcVar22)();
      iVar14 = unaff_s7[2];
      *(undefined4 *)(local_cc + 4) = uVar4;
      if ((*(int *)(iVar14 + 4) == 0) ||
         (iVar14 = (**(code **)(local_d8 + -0x5fec))
                             (unaff_s5,*(undefined4 *)(local_d8 + -0x59e4),*(int *)(iVar14 + 4) + 4)
         , iVar14 == 0)) goto LAB_005be704;
      pcVar22 = *(code **)(local_d8 + -0x6f3c);
      **(undefined4 **)(unaff_s7[2] + 4) = 0x10;
      (*pcVar22)(unaff_s5);
      iVar14 = 0;
      local_e0 = (_func_1092 **)0xffffffff;
      iVar3 = (**(code **)(local_d8 + -0x59e0))(iter,0,0,0xffffffff);
      unaff_s7[1] = iVar3;
      if (iVar3 == 0) {
        unaff_s5 = (EVP_CIPHER *)0x0;
        (**(code **)(local_d8 + -0x736c))(wrap_nid);
        goto LAB_005be73c;
      }
      if (pEVar5->nid == 3) {
        iter = pEVar5->block_size;
        *(uchar **)(iter + 0x10) = pass;
        if ((pass != (uchar *)0x0) && (passlen < 0)) {
          passlen = (**(code **)(local_d8 + -0x53bc))(pass);
        }
        *(ssize_t *)(iter + 0x14) = passlen;
      }
      else {
        iVar14 = 0xb1;
        local_e0 = (_func_1092 **)0x47;
        (**(code **)(local_d8 + -0x6eac))(0x2e,0xa8,0xb1,"cms_pwri.c");
      }
      pcVar22 = *(code **)(local_d8 + -0x7e38);
      cms = *(CMS_ContentInfo **)(iStack_100 + 8);
      *unaff_s7 = 0;
      iVar3 = (*pcVar22)(cms,pEVar5);
      pEStack_114 = pEVar5;
      if (iVar3 == 0) {
        unaff_s5 = (EVP_CIPHER *)0x0;
        goto LAB_005be704;
      }
    }
  }
  if (local_2c == *(int *)puStack_110) {
    return (CMS_RecipientInfo *)pEVar5;
  }
  pcStack_f4 = cms_RecipientInfo_pwri_crypt;
  iVar3 = local_2c;
  (**(code **)(local_d8 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_108 = pass;
  iVar20 = *(int *)(iVar3 + 4);
  puStack_11c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iVar3 = *(int *)(*(int *)((int)cms + 4) + 0xc);
  uStack_1b0 = 0;
  pEStack_118 = (EVP_CIPHER *)wrap_nid;
  iStack_10c = iter;
  pEStack_104 = unaff_s5;
  puStack_fc = unaff_s7;
  uStack_f8 = unaff_s8;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_1a8);
  if (*(int *)(iVar20 + 0x10) == 0) {
    uVar15 = 0xb2;
    uVar4 = 0x152;
  }
  else {
    puVar17 = *(undefined4 **)(iVar20 + 8);
    if ((puVar17 == (undefined4 *)0x0) ||
       (iVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar17), iVar6 != 0x37d)) {
      uVar15 = 0xb3;
      uVar4 = 0x159;
    }
    else {
      if (*(int *)puVar17[1] == 0x10) {
        puVar17 = (undefined4 *)((int *)puVar17[1])[1];
        uStack_1b0 = puVar17[2];
        puVar17 = (undefined4 *)(*(code *)PTR_d2i_X509_ALGOR_006a8dc4)(0,&uStack_1b0,*puVar17);
        if (puVar17 != (undefined4 *)0x0) {
          uVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar17);
          uVar4 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar4);
          pcVar13 = (char *)(*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar4);
          if (pcVar13 == (char *)0x0) {
            uVar15 = 0x94;
            uVar4 = 0x16b;
            goto LAB_005bed40;
          }
          iVar6 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(auStack_1a8,pcVar13,0,0,0,iVar14);
          if (iVar6 == 0) goto LAB_005beaf4;
          (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a7564)(auStack_1a8,0);
          iVar6 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a8c8c)(auStack_1a8,puVar17[1]);
          if (iVar6 < 0) {
            uVar15 = 0x66;
            uVar4 = 0x175;
LAB_005bed40:
            pcVar13 = (char *)0xa7;
            pcVar18 = (char *)0x0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa7,uVar15,"cms_pwri.c",uVar4);
LAB_005beaf8:
            (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1a8);
            if (pcVar18 == (char *)0x0) {
              pCVar7 = (CMS_RecipientInfo *)0x0;
            }
            else {
              pCVar7 = (CMS_RecipientInfo *)0x0;
              (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar18);
            }
          }
          else {
            iVar6 = (*(code *)PTR_EVP_PBE_CipherInit_006a9228)
                              (**(undefined4 **)(iVar20 + 4),*(undefined4 *)(iVar20 + 0x10),
                               *(undefined4 *)(iVar20 + 0x14),(*(undefined4 **)(iVar20 + 4))[1],
                               auStack_1a8,iVar14);
            if (iVar6 < 0) {
              uVar15 = 6;
              uVar4 = 0x180;
              goto LAB_005bed40;
            }
            if (iVar14 == 0) {
              pcVar18 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)
                                          (**(undefined4 **)(iVar20 + 0xc),"cms_pwri.c",0x195);
              if (pcVar18 == (char *)0x0) {
                pcVar13 = (char *)0xa7;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa7,0x41,"cms_pwri.c",0x198);
                goto LAB_005beaf8;
              }
              pcVar13 = **(char ***)(iVar20 + 0xc);
              pcVar10 = (*(char ***)(iVar20 + 0xc))[2];
              uVar8 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(auStack_1a8);
              if ((char *)(uVar8 * 2) <= pcVar13) {
                if (uVar8 == 0) {
                  trap(7);
                }
                if (((uint)pcVar13 % uVar8 == 0) &&
                   (pbVar21 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)
                                                (pcVar13,"cms_pwri.c",0xec), pbVar21 != (byte *)0x0)
                   ) {
                  pcVar11 = pcVar13 + uVar8 * -2;
                  (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                            (auStack_1a8,pbVar21 + (int)pcVar11,auStack_1ac,pcVar11 + (int)pcVar10,
                             (char *)(uVar8 * 2));
                  (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                            (auStack_1a8,pbVar21,auStack_1ac,pbVar21 + (int)(pcVar11 + uVar8),uVar8)
                  ;
                  (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                            (auStack_1a8,pbVar21,auStack_1ac,pcVar10,pcVar11 + uVar8);
                  (*(code *)PTR_EVP_DecryptInit_ex_006a7a68)(auStack_1a8,0,0,0,0);
                  (*(code *)PTR_EVP_DecryptUpdate_006a7a70)
                            (auStack_1a8,pbVar21,auStack_1ac,pbVar21,pcVar13);
                  if (((byte)((pbVar21[1] ^ pbVar21[4]) & (pbVar21[2] ^ pbVar21[5]) &
                             (pbVar21[3] ^ pbVar21[6])) == 0xff) &&
                     (uVar8 = (uint)*pbVar21, (char *)(uVar8 - 4) <= pcVar13)) {
                    (*(code *)PTR_memcpy_006a9aec)(pcVar18,pbVar21 + 4,uVar8);
                    (*(code *)PTR_OPENSSL_cleanse_006a7074)(pbVar21);
                    (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar21);
                    *(char **)(iVar3 + 0x10) = pcVar18;
                    *(uint *)(iVar3 + 0x14) = uVar8;
                    goto LAB_005becf4;
                  }
                  (*(code *)PTR_OPENSSL_cleanse_006a7074)(pbVar21,pcVar13);
                  (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar21);
                }
              }
              pcVar13 = (char *)0xa7;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa7,0xb4,"cms_pwri.c",0x19e);
              goto LAB_005beaf8;
            }
            uVar19 = *(uint *)(iVar3 + 0x14);
            uVar8 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(auStack_1a8);
            pcVar13 = (char *)(uVar8 << 1);
            if (uVar8 == 0) {
              trap(7);
            }
            pcVar18 = (char *)(((uVar19 + 3 + uVar8) / uVar8) * uVar8);
            if ((pcVar18 < pcVar13) || (pcVar13 = "encrypt", 0xff < uVar19)) {
LAB_005beaf4:
              pcVar18 = (char *)0x0;
              goto LAB_005beaf8;
            }
            pcVar13 = "cms_pwri.c";
            pcVar18 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pcVar18,"cms_pwri.c",0x18b);
            if (pcVar18 == (char *)0x0) goto LAB_005beaf4;
            uVar19 = *(uint *)(iVar3 + 0x14);
            pbVar21 = *(byte **)(iVar3 + 0x10);
            uVar8 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(auStack_1a8);
            if (uVar8 == 0) {
              trap(7);
            }
            uVar16 = ((uVar19 + 3 + uVar8) / uVar8) * uVar8;
            if ((uVar16 < uVar8 << 1) || (0xff < uVar19)) goto LAB_005beaf8;
            *pcVar18 = (char)uVar19;
            puVar2 = PTR_memcpy_006a9aec;
            pcVar18[1] = ~*pbVar21;
            pcVar18[2] = ~pbVar21[1];
            pcVar18[3] = ~pbVar21[2];
            (*(code *)puVar2)(pcVar18 + 4,pbVar21,uVar19);
            if (uVar19 + 4 < uVar16) {
              pcVar13 = (char *)((uVar16 - uVar19) + -4);
              iVar14 = (*(code *)PTR_RAND_bytes_006a7574)(pcVar18 + uVar19 + 4);
              if (iVar14 < 1) goto LAB_005beaf8;
            }
            (*(code *)PTR_EVP_EncryptUpdate_006a7aa0)
                      (auStack_1a8,pcVar18,auStack_1ac,pcVar18,uVar16);
            pcVar13 = pcVar18;
            (*(code *)PTR_EVP_EncryptUpdate_006a7aa0)
                      (auStack_1a8,pcVar18,auStack_1ac,pcVar18,uVar16);
            puVar9 = *(uint **)(iVar20 + 0xc);
            puVar9[2] = (uint)pcVar18;
            *puVar9 = uVar16;
LAB_005becf4:
            pCVar7 = (CMS_RecipientInfo *)0x1;
            (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1a8);
          }
          (*(code *)PTR_X509_ALGOR_free_006a7ea4)(puVar17);
          goto LAB_005bea08;
        }
      }
      uVar15 = 0xb0;
      uVar4 = 0x164;
    }
  }
  pcVar13 = (char *)0xa7;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa7,uVar15,"cms_pwri.c",uVar4);
  pCVar7 = (CMS_RecipientInfo *)0x0;
LAB_005bea08:
  if (puStack_11c != *(undefined4 **)puVar1) {
    puVar17 = puStack_11c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    puVar12 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x10,"pqueue.c",0x47);
    if (puVar12 != (undefined4 *)0x0) {
      uVar4 = puVar17[1];
      *puVar12 = *puVar17;
      puVar12[1] = uVar4;
      puVar12[2] = pcVar13;
      puVar12[3] = 0;
    }
    return (CMS_RecipientInfo *)puVar12;
  }
  return pCVar7;
}

