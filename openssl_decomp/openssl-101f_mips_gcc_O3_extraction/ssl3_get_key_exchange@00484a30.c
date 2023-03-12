
int ssl3_get_key_exchange(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  byte *pbVar4;
  ushort *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined *unaff_s2;
  int iVar9;
  ushort *puVar10;
  uint uVar11;
  byte *pbVar12;
  int *piVar13;
  uint uVar14;
  ushort *puVar15;
  ushort *local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  uint local_d0;
  int local_cc;
  undefined auStack_c8 [24];
  ushort auStack_b0 [66];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (**(code **)(param_1[2] + 0x30))(param_1,0x1140,0x1141,0xffffffff,param_1[0x42],&local_cc)
  ;
  if (local_cc == 0) goto LAB_00484ae8;
  iVar7 = param_1[0x16];
  if (*(int *)(iVar7 + 0x340) != 0xc) {
    if ((*(uint *)(*(int *)(iVar7 + 0x344) + 0xc) & 0x100) != 0) {
      iVar7 = param_1[0x30];
      uVar6 = (*(code *)PTR_ssl_sess_cert_new_006a9060)();
      iVar3 = param_1[0x39];
      *(undefined4 *)(iVar7 + 0x98) = uVar6;
      if (*(int *)(iVar3 + 0x14c) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
        iVar3 = param_1[0x39];
      }
      iVar7 = param_1[0x16];
      *(undefined4 *)(iVar3 + 0x14c) = 0;
    }
    iVar3 = 1;
    *(undefined4 *)(iVar7 + 0x354) = 1;
    goto LAB_00484ae8;
  }
  iVar9 = param_1[0x30];
  iVar7 = *(int *)(iVar9 + 0x98);
  puVar10 = (ushort *)param_1[0x10];
  if (iVar7 == 0) {
    uVar6 = (*(code *)PTR_ssl_sess_cert_new_006a9060)();
    *(undefined4 *)(iVar9 + 0x98) = uVar6;
  }
  else {
    if (*(int *)(iVar7 + 0x6c) != 0) {
      (*(code *)PTR_RSA_free_006a86f0)();
      iVar7 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar7 + 0x6c) = 0;
    }
    if (*(int *)(iVar7 + 0x70) != 0) {
      (*(code *)PTR_DH_free_006a8604)();
      iVar7 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar7 + 0x70) = 0;
    }
    if (*(int *)(iVar7 + 0x74) != 0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)();
      *(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x74) = 0;
    }
  }
  unaff_s2 = auStack_c8;
  uVar11 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  uVar14 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x10);
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(unaff_s2);
  if ((uVar11 & 0x100) != 0) {
    uVar11 = (uint)*puVar10;
    local_d0 = uVar11;
    if (0x80 < uVar11) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0x92,"s3_clnt.c",0x554);
      uVar6 = 0x28;
LAB_004856b8:
      local_d8 = 0;
      piVar13 = (int *)0x0;
      local_d4 = 0;
      local_dc = 0;
      local_e0 = (ushort *)0x0;
      goto LAB_00485120;
    }
    if (iVar3 < (int)(uVar11 + 2)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0x13c,"s3_clnt.c",0x55b);
      uVar6 = 0x32;
      goto LAB_004856b8;
    }
    (*(code *)PTR___memcpy_chk_006aab54)(auStack_b0,puVar10 + 1,uVar11,0x81);
    (*(code *)PTR_memset_006aab00)((int)auStack_b0 + uVar11,0,0x81 - uVar11);
    iVar7 = param_1[0x39];
    if (*(int *)(iVar7 + 0x14c) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
      iVar7 = param_1[0x39];
    }
    iVar3 = iVar3 - (uVar11 + 2);
    uVar6 = (*(code *)PTR_BUF_strdup_006a80dc)(auStack_b0);
    iVar9 = param_1[0x39];
    *(undefined4 *)(iVar7 + 0x14c) = uVar6;
    if (*(int *)(iVar9 + 0x14c) == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0x41,"s3_clnt.c",0x569);
      uVar6 = 0x28;
      goto LAB_004856b8;
    }
LAB_00484c80:
    piVar13 = (int *)0x0;
    if (iVar3 != 0) {
      uVar8 = 0x99;
      uVar6 = 0x725;
LAB_0048515c:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,uVar8,"s3_clnt.c",uVar6);
      uVar6 = 0x32;
      local_d8 = 0;
      local_d4 = 0;
      local_dc = 0;
      local_e0 = (ushort *)0x0;
      goto LAB_00485120;
    }
LAB_00484c8c:
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar13);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(unaff_s2);
    iVar3 = 1;
    goto LAB_00484ae8;
  }
  if ((uVar11 & 0x400) == 0) {
    if ((uVar11 & 1) == 0) {
      if ((uVar11 & 8) != 0) {
        local_e0 = (ushort *)(*(code *)PTR_DH_new_006a8618)();
        if (local_e0 == (ushort *)0x0) {
          uVar8 = 5;
          uVar6 = 0x5fd;
        }
        else {
          local_d0 = (uint)*puVar10;
          iVar7 = local_d0 + 2;
          if (iVar3 < iVar7) {
            uVar8 = 0x6e;
            uVar6 = 0x605;
            goto LAB_0048596c;
          }
          iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar10 + 1,local_d0,0);
          *(int *)(local_e0 + 4) = iVar9;
          if (iVar9 == 0) {
            uVar8 = 3;
            uVar6 = 0x60a;
          }
          else {
            puVar15 = (ushort *)((int)(puVar10 + 1) + local_d0);
            puVar5 = puVar15 + 1;
            local_d0 = (uint)*puVar15;
            iVar7 = local_d0 + 2 + iVar7;
            if (iVar3 < iVar7) {
              uVar8 = 0x6c;
              uVar6 = 0x614;
              goto LAB_0048596c;
            }
            iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar5,local_d0,0);
            *(int *)(local_e0 + 6) = iVar9;
            if (iVar9 == 0) {
              uVar8 = 3;
              uVar6 = 0x619;
            }
            else {
              puVar5 = (ushort *)((int)puVar5 + local_d0);
              puVar15 = puVar5 + 1;
              local_d0 = (uint)*puVar5;
              iVar7 = local_d0 + 2 + iVar7;
              if (iVar3 < iVar7) goto LAB_00485a20;
              iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar15,local_d0,0);
              *(int *)(local_e0 + 10) = iVar9;
              if (iVar9 != 0) {
                iVar3 = iVar3 - iVar7;
                puVar15 = (ushort *)((int)puVar15 + local_d0);
                if ((uVar14 & 1) == 0) {
                  if ((uVar14 & 2) == 0) {
                    piVar13 = (int *)0x0;
                  }
                  else {
                    piVar13 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                               (*(undefined4 *)
                                                 (*(int *)(param_1[0x30] + 0x98) + 0x24));
                  }
                }
                else {
                  piVar13 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                             (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc))
                  ;
                }
                *(ushort **)(*(int *)(param_1[0x30] + 0x98) + 0x70) = local_e0;
                goto LAB_00484f2c;
              }
              uVar8 = 3;
              uVar6 = 0x628;
            }
          }
        }
        piVar13 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,uVar8,"s3_clnt.c",uVar6);
        local_d8 = 0;
        local_dc = 0;
        goto LAB_00484d60;
      }
      if ((uVar11 & 6) != 0) {
        piVar13 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0xeb,"s3_clnt.c",0x641);
        uVar6 = 0x2f;
        local_d8 = 0;
        local_d4 = 0;
        local_dc = 0;
        local_e0 = (ushort *)0x0;
        goto LAB_00485120;
      }
      if ((uVar11 & 0x80) != 0) {
        local_dc = (*(code *)PTR_EC_KEY_new_006a82a8)();
        if (local_dc == 0) {
          uVar8 = 0x41;
          uVar6 = 0x64e;
        }
        else {
          if (((iVar3 < 3) || (*(char *)puVar10 != '\x03')) ||
             (iVar7 = tls1_ec_curve_id2nid(*(char *)(puVar10 + 1)), iVar7 == 0)) {
            piVar13 = (int *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0x13a,"s3_clnt.c",0x661);
            uVar6 = 0x50;
            local_d8 = 0;
            local_d4 = 0;
            local_e0 = (ushort *)0x0;
            goto LAB_00485120;
          }
          piVar13 = (int *)(*(code *)PTR_EC_GROUP_new_by_curve_name_006a8284)(iVar7);
          if (piVar13 == (int *)0x0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0x10,"s3_clnt.c",0x668);
            local_d8 = 0;
            local_e0 = (ushort *)0x0;
            goto LAB_00484d60;
          }
          iVar7 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(local_dc,piVar13);
          if (iVar7 != 0) {
            (*(code *)PTR_EC_GROUP_free_006a829c)(piVar13);
            uVar6 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(local_dc);
            if (((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) != 0) &&
               (iVar7 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(uVar6), 0xa3 < iVar7)) {
              piVar13 = (int *)0x0;
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0x136,"s3_clnt.c",0x678);
              uVar6 = 0x3c;
              local_d8 = 0;
              local_d4 = 0;
              local_e0 = (ushort *)0x0;
              goto LAB_00485120;
            }
            local_d8 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar6);
            if ((local_d8 == 0) || (local_d4 = (*(code *)PTR_BN_CTX_new_006a8a38)(), local_d4 == 0))
            {
              piVar13 = (int *)0x0;
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0x41,"s3_clnt.c",0x682);
              local_e0 = (ushort *)0x0;
              goto LAB_00484d60;
            }
            uVar11 = (uint)*(byte *)((int)puVar10 + 3);
            iVar7 = uVar11 + 4;
            local_e0 = puVar10 + 2;
            if ((iVar3 < iVar7) ||
               (iVar9 = (*(code *)PTR_EC_POINT_oct2point_006a9148)
                                  (uVar6,local_d8,local_e0,uVar11,local_d4), iVar9 == 0)) {
              piVar13 = (int *)0x0;
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0x132,"s3_clnt.c",0x68e);
              uVar6 = 0x32;
              local_e0 = (ushort *)0x0;
              goto LAB_00485120;
            }
            iVar3 = iVar3 - iVar7;
            puVar15 = (ushort *)((int)local_e0 + uVar11);
            if ((uVar14 & 1) == 0) {
              if ((uVar14 & 0x40) == 0) {
                piVar13 = (int *)0x0;
              }
              else {
                piVar13 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                           (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x48));
              }
            }
            else {
              piVar13 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                         (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc));
            }
            (*(code *)PTR_EC_KEY_set_public_key_006a91b0)(local_dc,local_d8);
            puVar1 = PTR_BN_CTX_free_006a8a40;
            *(int *)(*(int *)(param_1[0x30] + 0x98) + 0x74) = local_dc;
            (*(code *)puVar1)(local_d4);
            (*(code *)PTR_EC_POINT_free_006a9134)(local_d8);
LAB_00484f2c:
            if (piVar13 != (int *)0x0) {
              if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
                uVar11 = tls12_get_sigid(piVar13);
                if (uVar11 == 0xffffffff) {
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0x44,"s3_clnt.c",0x6bf);
                  local_d8 = 0;
                  local_dc = 0;
                  local_e0 = (ushort *)0x0;
                  goto LAB_00484d60;
                }
                if (uVar11 != *(byte *)((int)puVar15 + 1)) {
                  uVar8 = 0x172;
                  uVar6 = 0x6c5;
                  goto LAB_0048515c;
                }
                iVar9 = tls12_get_hash(*(byte *)puVar15);
                if (iVar9 == 0) {
                  uVar8 = 0x170;
                  uVar6 = 0x6cc;
                  goto LAB_0048515c;
                }
                puVar15 = puVar15 + 1;
                iVar3 = iVar3 + -2;
              }
              else {
                iVar9 = (*(code *)PTR_EVP_sha1_006a86c4)();
              }
              uVar11 = iVar3 - 2;
              local_d0 = (uint)*puVar15;
              iVar3 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(piVar13);
              if (((uVar11 != local_d0) || (iVar3 < (int)uVar11)) || ((int)uVar11 < 1)) {
                uVar8 = 0x108;
                uVar6 = 0x6e1;
                goto LAB_0048515c;
              }
              if ((*piVar13 == 6) && ((*param_1 >> 8 != 3 || (*param_1 < 0x303)))) {
                local_d4 = 0;
                iVar3 = 2;
                local_e0 = auStack_b0;
                do {
                  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(unaff_s2,8);
                  if (iVar3 == 2) {
                    uVar6 = *(undefined4 *)(param_1[0x39] + 0x8c);
                  }
                  else {
                    uVar6 = *(undefined4 *)(param_1[0x39] + 0x90);
                  }
                  iVar3 = iVar3 + -1;
                  (*(code *)PTR_EVP_DigestInit_ex_006a8670)(unaff_s2,uVar6,0);
                  (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,param_1[0x16] + 0xc0,0x20);
                  (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,param_1[0x16] + 0xa0,0x20);
                  (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,puVar10,iVar7);
                  (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(unaff_s2,local_e0,&local_d0);
                  local_e0 = (ushort *)((int)local_e0 + local_d0);
                  local_d4 = local_d4 + local_d0;
                } while (iVar3 != 0);
                local_d0 = (*(code *)PTR_RSA_verify_006a8b68)
                                     (0x72,auStack_b0,local_d4,puVar15 + 1,uVar11,piVar13[5]);
                if ((int)local_d0 < 0) {
                  uVar8 = 0x76;
                  uVar6 = 0x6fe;
                }
                else {
                  if (local_d0 != 0) goto LAB_00484c8c;
                  uVar8 = 0x7b;
                  uVar6 = 0x705;
                }
LAB_004850f8:
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,uVar8,"s3_clnt.c",uVar6);
                uVar6 = 0x33;
                local_d8 = 0;
                local_d4 = 0;
                local_dc = 0;
                local_e0 = (ushort *)0x0;
                goto LAB_00485120;
              }
              (*(code *)PTR_EVP_DigestInit_ex_006a8670)(unaff_s2,iVar9,0);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,param_1[0x16] + 0xc0,0x20);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,param_1[0x16] + 0xa0,0x20);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s2,puVar10,iVar7);
              iVar3 = (*(code *)PTR_EVP_VerifyFinal_006a907c)(unaff_s2,puVar15 + 1,uVar11,piVar13);
              if (iVar3 < 1) {
                uVar8 = 0x7b;
                uVar6 = 0x714;
                goto LAB_004850f8;
              }
              goto LAB_00484c8c;
            }
            goto LAB_00484d20;
          }
          uVar8 = 0x10;
          uVar6 = 0x66d;
        }
        piVar13 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,uVar8,"s3_clnt.c",uVar6);
        local_d8 = 0;
        local_e0 = (ushort *)0x0;
        goto LAB_00484d60;
      }
      if (uVar11 != 0) {
        piVar13 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,0xf4,"s3_clnt.c",0x6ae);
        uVar6 = 10;
        local_d8 = 0;
        local_d4 = 0;
        local_dc = 0;
        local_e0 = (ushort *)0x0;
        goto LAB_00485120;
      }
LAB_00484d20:
      if ((uVar14 & 4) != 0) goto LAB_00484c80;
      uVar8 = 0x44;
      uVar6 = 0x71e;
    }
    else {
      local_e0 = (ushort *)(*(code *)PTR_RSA_new_006a8964)();
      if (local_e0 != (ushort *)0x0) {
        local_d0 = (uint)*puVar10;
        iVar7 = local_d0 + 2;
        if (iVar3 < iVar7) {
          uVar8 = 0x79;
          uVar6 = 0x5cf;
LAB_004858f0:
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,uVar8,"s3_clnt.c",uVar6);
          ssl3_send_alert(param_1,2,0x32);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(0);
        }
        else {
          iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)
                            (puVar10 + 1,local_d0,*(undefined4 *)(local_e0 + 8));
          *(int *)(local_e0 + 8) = iVar9;
          if (iVar9 == 0) {
            uVar8 = 3;
            uVar6 = 0x5d4;
          }
          else {
            puVar5 = (ushort *)((int)(puVar10 + 1) + local_d0);
            puVar15 = puVar5 + 1;
            local_d0 = (uint)*puVar5;
            iVar7 = local_d0 + 2 + iVar7;
            if (iVar3 < iVar7) {
              uVar8 = 0x78;
              uVar6 = 0x5de;
              goto LAB_004858f0;
            }
            iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)
                              (puVar15,local_d0,*(undefined4 *)(local_e0 + 10));
            *(int *)(local_e0 + 10) = iVar9;
            if (iVar9 == 0) {
              uVar8 = 3;
              uVar6 = 0x5e3;
            }
            else {
              iVar3 = iVar3 - iVar7;
              puVar15 = (ushort *)((int)puVar15 + local_d0);
              if ((uVar14 & 1) != 0) {
                piVar13 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                           (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc));
                *(ushort **)(*(int *)(param_1[0x30] + 0x98) + 0x6c) = local_e0;
                goto LAB_00484f2c;
              }
              uVar8 = 0x44;
              uVar6 = 0x5ee;
            }
          }
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,uVar8,"s3_clnt.c",uVar6);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(0);
        }
        (*(code *)PTR_RSA_free_006a86f0)(local_e0);
        (*(code *)PTR_BN_CTX_free_006a8a40)(0);
        (*(code *)PTR_EC_POINT_free_006a9134)(0);
        goto LAB_00484dc4;
      }
      uVar8 = 0x41;
      uVar6 = 0x5c7;
    }
  }
  else {
    local_d0 = (uint)*puVar10;
    iVar7 = local_d0 + 2;
    if (iVar3 < iVar7) {
      uVar8 = 0x15e;
      uVar6 = 0x57a;
LAB_0048575c:
      piVar13 = (int *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,uVar8,"s3_clnt.c",uVar6);
      uVar6 = 0x32;
      local_d8 = 0;
      local_d4 = 0;
      local_dc = 0;
      local_e0 = (ushort *)0x0;
      goto LAB_00485120;
    }
    iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar10 + 1,local_d0,0);
    param_1[0x6a] = iVar9;
    if (iVar9 == 0) {
      uVar8 = 3;
      uVar6 = 0x57f;
    }
    else {
      puVar15 = (ushort *)((int)(puVar10 + 1) + local_d0);
      puVar5 = puVar15 + 1;
      local_d0 = (uint)*puVar15;
      iVar7 = local_d0 + 2 + iVar7;
      if (iVar3 < iVar7) {
        uVar8 = 0x15d;
        uVar6 = 0x589;
        goto LAB_0048575c;
      }
      iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar5,local_d0,0);
      param_1[0x6b] = iVar9;
      if (iVar9 == 0) {
        uVar8 = 3;
        uVar6 = 0x58e;
      }
      else {
        pbVar4 = (byte *)((int)puVar5 + local_d0);
        pbVar12 = pbVar4 + 1;
        local_d0 = (uint)*pbVar4;
        iVar7 = local_d0 + 1 + iVar7;
        if (iVar3 < iVar7) {
          uVar8 = 0x15f;
          uVar6 = 0x599;
          goto LAB_0048575c;
        }
        iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)(pbVar12,local_d0,0);
        param_1[0x6c] = iVar9;
        if (iVar9 == 0) {
          uVar8 = 3;
          uVar6 = 0x59e;
        }
        else {
          puVar15 = (ushort *)(pbVar12 + local_d0);
          local_d0 = (uint)*puVar15;
          iVar7 = local_d0 + 2 + iVar7;
          if (iVar3 < iVar7) {
            uVar8 = 0x15c;
            uVar6 = 0x5a8;
            goto LAB_0048575c;
          }
          iVar9 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar15 + 1,local_d0,0);
          param_1[0x6d] = iVar9;
          if (iVar9 != 0) {
            iVar3 = iVar3 - iVar7;
            puVar15 = (ushort *)((int)(puVar15 + 1) + local_d0);
            if ((uVar14 & 1) == 0) {
              if ((uVar14 & 2) == 0) goto LAB_00484d20;
              piVar13 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                         (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x24));
            }
            else {
              piVar13 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                         (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc));
            }
            goto LAB_00484f2c;
          }
          uVar8 = 3;
          uVar6 = 0x5ad;
        }
      }
    }
  }
  piVar13 = (int *)0x0;
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,uVar8,"s3_clnt.c",uVar6);
  local_d8 = 0;
  local_dc = 0;
  local_e0 = (ushort *)0x0;
LAB_00484d60:
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar13);
  local_d4 = 0;
  while( true ) {
    if (local_e0 != (ushort *)0x0) {
      (*(code *)PTR_DH_free_006a8604)();
    }
    (*(code *)PTR_BN_CTX_free_006a8a40)(local_d4);
    (*(code *)PTR_EC_POINT_free_006a9134)(local_d8);
    if (local_dc != 0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)();
    }
LAB_00484dc4:
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(unaff_s2);
    iVar3 = -1;
LAB_00484ae8:
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00485a20:
    uVar8 = 0x6d;
    uVar6 = 0x623;
LAB_0048596c:
    piVar13 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8d,uVar8,"s3_clnt.c",uVar6);
    uVar6 = 0x32;
    local_d8 = 0;
    local_d4 = 0;
    local_dc = 0;
LAB_00485120:
    ssl3_send_alert(param_1,2,uVar6);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar13);
  }
  return iVar3;
}

