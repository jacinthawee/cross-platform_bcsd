
/* WARNING: Could not reconcile some variable overlaps */

undefined4
ssl3_send_server_key_exchange(int *param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  undefined *puVar1;
  undefined extraout_var;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  undefined *puVar14;
  code *pcVar15;
  undefined *puVar16;
  undefined *local_b0;
  int *local_ac;
  int local_a8;
  int *local_a4;
  int local_a0;
  undefined4 local_9c;
  int local_94;
  int local_90;
  int local_8c;
  undefined auStack_88 [24];
  int local_70 [4];
  int local_60 [4];
  undefined auStack_50 [36];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_90 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_88);
  if (param_1[0xd] != 0x2150) goto LAB_0047a7e0;
  iVar13 = param_1[0x16];
  iVar10 = param_1[0x26];
  iVar11 = param_1[0xf];
  local_70[3] = 0;
  iVar6 = *(int *)(iVar13 + 0x344);
  local_70[2] = 0;
  local_70[1] = 0;
  local_70[0] = 0;
  uVar9 = *(uint *)(iVar6 + 0xc);
  if ((uVar9 & 1) == 0) {
    if ((uVar9 & 8) != 0) {
      iVar8 = *(int *)(iVar10 + 0x20);
      if (iVar8 == 0) {
        if (*(code **)(iVar10 + 0x24) != (code *)0x0) {
          uVar4 = 0x200;
          if ((*(uint *)(iVar6 + 0x20) & 8) == 0) {
            uVar4 = 0x400;
          }
          iVar8 = (**(code **)(iVar10 + 0x24))(param_1,*(uint *)(iVar6 + 0x20) & 2,uVar4);
          if (iVar8 != 0) {
            iVar13 = param_1[0x16];
            goto LAB_0047abf4;
          }
        }
        uVar7 = 0xab;
        uVar4 = 0x6b4;
        goto LAB_0047b1d0;
      }
LAB_0047abf4:
      if (*(int *)(iVar13 + 0x348) != 0) {
        uVar7 = 0x44;
        param_4 = "s3_srvr.c";
        uVar4 = 0x6ba;
        pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
        goto LAB_0047b0d0;
      }
      iVar6 = (*(code *)PTR_DHparams_dup_006a7f8c)(iVar8);
      puVar12 = PTR_DH_generate_key_006a7f90;
      if (iVar6 == 0) {
        uVar7 = 5;
        param_4 = "s3_srvr.c";
        uVar4 = 0x6bf;
        pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
        goto LAB_0047b0d0;
      }
      *(int *)(param_1[0x16] + 0x348) = iVar6;
      iVar13 = (*(code *)puVar12)(iVar6);
      if (iVar13 == 0) {
        uVar7 = 5;
        param_4 = "s3_srvr.c";
        uVar4 = 0x6c5;
        pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
        goto LAB_0047b0d0;
      }
      iVar10 = *(int *)(iVar6 + 8);
      local_70[1] = *(int *)(iVar6 + 0xc);
      local_70[2] = *(int *)(iVar6 + 0x14);
      goto LAB_0047a4fc;
    }
    if ((uVar9 & 0x80) == 0) {
      iVar10 = 0;
      if ((uVar9 & 0x100) == 0) {
        param_4 = "-check_ss_sig";
        if ((uVar9 & 0x400) == 0) {
          uVar7 = 0xfa;
          uVar4 = 0x761;
          goto LAB_0047b1d0;
        }
        pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
        if (param_1[0x6a] == 0) goto LAB_0047b334;
        if (param_1[0x6b] == 0) goto LAB_0047b334;
        if (param_1[0x6c] == 0) goto LAB_0047b334;
        param_4 = "s3_srvr.c";
        iVar10 = param_1[0x6a];
        iVar6 = param_1[0x6b];
        iVar13 = param_1[0x6c];
        iVar8 = param_1[0x6d];
        if (param_1[0x6d] == 0) goto LAB_0047b338;
        goto LAB_0047a508;
      }
      iVar6 = (*(code *)PTR_strlen_006a9a24)(*(undefined4 *)(param_1[0x39] + 0x14c));
      iVar6 = iVar6 + 2;
      local_9c = 0;
      local_a0 = 0;
      local_a4 = (int *)0x0;
      local_8c = 0;
      goto LAB_0047a5a0;
    }
    iVar8 = *(int *)(iVar10 + 0x28);
    if (iVar8 == 0) {
      if (*(code **)(iVar10 + 0x2c) != (code *)0x0) {
        uVar4 = 0x200;
        if ((*(uint *)(iVar6 + 0x20) & 8) == 0) {
          uVar4 = 0x400;
        }
        iVar8 = (**(code **)(iVar10 + 0x2c))(param_1,*(uint *)(iVar6 + 0x20) & 2,uVar4);
        if (iVar8 != 0) {
          iVar13 = param_1[0x16];
          goto LAB_0047a868;
        }
      }
      uVar7 = 0x137;
      uVar4 = 0x6dc;
      goto LAB_0047b1d0;
    }
LAB_0047a868:
    if (*(int *)(iVar13 + 0x34c) != 0) {
      uVar7 = 0x44;
      param_4 = "s3_srvr.c";
      uVar4 = 0x6e2;
      pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
      goto LAB_0047b0d0;
    }
    iVar6 = (*(code *)PTR_EC_KEY_dup_006a7f74)(iVar8);
    puVar12 = PTR_EC_KEY_get0_public_key_006a7ae4;
    if (iVar6 == 0) {
      uVar7 = 0x2b;
      param_4 = "s3_srvr.c";
      uVar4 = 0x6ec;
      pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
      goto LAB_0047b0d0;
    }
    *(int *)(param_1[0x16] + 0x34c) = iVar6;
    iVar13 = (*(code *)puVar12)(iVar6);
    if ((((iVar13 == 0) ||
         (iVar13 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar6), iVar13 == 0)) ||
        (param_1[0x40] << 0xc < 0)) &&
       (iVar13 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(iVar6), iVar13 == 0)) {
      uVar7 = 0x2b;
      param_4 = "s3_srvr.c";
      uVar4 = 0x6f6;
      pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
      goto LAB_0047b0d0;
    }
    iVar13 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar6);
    if (((iVar13 == 0) ||
        (iVar10 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar6), iVar10 == 0)) ||
       (iVar10 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar6), iVar10 == 0)) {
      uVar7 = 0x2b;
      param_4 = "s3_srvr.c";
      uVar4 = 0x6fe;
      pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
      goto LAB_0047b0d0;
    }
    if (((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) != 0) &&
       (iVar10 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(iVar13), 0xa3 < iVar10)) {
      uVar7 = 0x136;
      param_4 = "s3_srvr.c";
      uVar4 = 0x705;
      pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
      goto LAB_0047b0d0;
    }
    uVar4 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(iVar13);
    local_9c = tls1_ec_nid2curve_id(uVar4);
    if (local_9c == 0) {
      uVar7 = 0x13b;
      param_4 = "s3_srvr.c";
      uVar4 = 0x712;
      pcVar15 = (code *)PTR_ERR_put_error_006a7f34;
      goto LAB_0047b0d0;
    }
    uVar4 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar6);
    uVar4 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)(iVar13,uVar4,4,0,0,0);
    local_a4 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4,"s3_srvr.c",0x720);
    iVar8 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if ((local_a4 == (int *)0x0) || (iVar8 == 0)) {
      param_4 = "s3_srvr.c";
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9b,0x41,"s3_srvr.c",0x724);
      goto LAB_0047afd8;
    }
    uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar6);
    param_4 = (char *)local_a4;
    local_a0 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)(iVar13,uVar7,4,local_a4,uVar4,iVar8);
    if (local_a0 != 0) {
      iVar6 = local_a0 + 4;
      iVar10 = 0;
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
      iVar13 = param_1[0x16];
      local_70[0] = 0;
      local_70[1] = 0;
      local_70[2] = 0;
      local_70[3] = 0;
      local_8c = 0;
      goto LAB_0047a5a0;
    }
    param_4 = "s3_srvr.c";
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9b,0x2b,"s3_srvr.c",0x72e);
  }
  else {
    iVar8 = *(int *)(iVar10 + 0x18);
    if (iVar8 == 0) {
      uVar4 = 0x200;
      if (*(code **)(iVar10 + 0x1c) == (code *)0x0) {
        uVar7 = 0xac;
        uVar4 = 0x6a0;
      }
      else {
        if ((*(uint *)(iVar6 + 0x20) & 8) == 0) {
          uVar4 = 0x400;
        }
        iVar8 = (**(code **)(iVar10 + 0x1c))(param_1,*(uint *)(iVar6 + 0x20) & 2,uVar4);
        if (iVar8 != 0) {
          (*(code *)PTR_RSA_up_ref_006a7f98)(iVar8);
          iVar13 = param_1[0x16];
          *(int *)(iVar10 + 0x18) = iVar8;
          goto LAB_0047a4e4;
        }
        uVar7 = 0x11a;
        uVar4 = 0x697;
      }
LAB_0047b1d0:
      param_4 = "s3_srvr.c";
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9b,uVar7,"s3_srvr.c",uVar4);
      uVar4 = 0x28;
      local_a4 = (int *)0x0;
LAB_0047afc0:
      iVar8 = 0;
      ssl3_send_alert(param_1,2,uVar4);
    }
    else {
LAB_0047a4e4:
      iVar10 = *(int *)(iVar8 + 0x10);
      local_70[1] = *(int *)(iVar8 + 0x14);
      *(undefined4 *)(iVar13 + 0x370) = 1;
LAB_0047a4fc:
      local_8c = 0;
      iVar6 = local_70[1];
      iVar13 = local_70[2];
      iVar8 = local_70[3];
      if (iVar10 == 0) {
        iVar13 = param_1[0x16];
        iVar6 = 0;
        local_9c = 0;
        local_a0 = 0;
        local_a4 = (int *)0x0;
        local_70[0] = iVar10;
      }
      else {
LAB_0047a508:
        local_70[3] = iVar8;
        local_70[2] = iVar13;
        local_70[1] = iVar6;
        local_70[0] = iVar10;
        iVar10 = local_70[0];
        local_8c = 0;
        iVar6 = 0;
        iVar8 = 0;
        iVar13 = local_70[0];
        if ((uVar9 & 0x400) == 0) {
          do {
            iVar2 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar13);
            iVar13 = iVar2 + 7;
            if (iVar2 + 7 < 0) {
              iVar13 = iVar2 + 0xe;
            }
            iVar2 = local_8c + 1;
            *(int *)((int)local_60 + iVar8) = iVar13 >> 3;
            iVar6 = iVar6 + local_60[local_8c] + 2;
            local_8c = iVar2;
            if (3 < iVar2) break;
            iVar8 = iVar2 * 4;
            iVar13 = local_70[iVar2];
          } while (local_70[iVar2] != 0);
        }
        else {
          do {
            iVar2 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar13);
            iVar13 = iVar2 + 7;
            if (iVar2 + 7 < 0) {
              iVar13 = iVar2 + 0xe;
            }
            *(int *)((int)local_60 + iVar8) = iVar13 >> 3;
            if (local_8c == 2) {
              local_8c = 3;
              iVar6 = iVar6 + local_60[2] + 1;
            }
            else {
              iVar13 = local_8c + 1;
              iVar6 = iVar6 + local_60[local_8c] + 2;
              local_8c = iVar13;
              if (3 < iVar13) break;
            }
            iVar8 = local_8c * 4;
            iVar13 = local_70[local_8c];
          } while (local_70[local_8c] != 0);
        }
        iVar13 = param_1[0x16];
        local_9c = 0;
        local_a0 = 0;
        local_a4 = (int *)0x0;
      }
LAB_0047a5a0:
      iVar13 = *(int *)(iVar13 + 0x344);
      if ((*(uint *)(iVar13 + 0x10) & 0x404) == 0) {
        iVar8 = 0;
        if ((*(uint *)(iVar13 + 0xc) & 0x100) == 0) {
          local_ac = (int *)(*(code *)PTR_ssl_get_sign_pkey_006a7f94)(param_1,iVar13,&local_90);
          if (local_ac == (int *)0x0) {
            uVar4 = 0x32;
            goto LAB_0047afc0;
          }
          iVar8 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(local_ac);
        }
        else {
          local_ac = (int *)0x0;
        }
        iVar13 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar11,iVar8 + iVar6 + 4);
        if (iVar13 == 0) goto LAB_0047b18c;
        puVar12 = *(undefined **)(param_1[0xf] + 4);
LAB_0047a5fc:
        local_a8 = iVar6 + 4;
        local_b0 = puVar12 + 4;
        local_8c = 0;
        uVar3 = uVar9 & 0x400;
        puVar16 = local_b0;
        if (iVar10 != 0) {
          if (uVar3 != 0) {
            iVar13 = 0;
            do {
              puVar14 = puVar16 + 2;
              *puVar16 = (char)((uint)*(undefined4 *)((int)local_60 + iVar13) >> 8);
              puVar16[1] = (char)local_60[local_8c];
              while( true ) {
                (*(code *)PTR_BN_bn2bin_006a7200)(local_70[local_8c],puVar14);
                iVar13 = local_8c + 1;
                puVar16 = puVar14 + local_60[local_8c];
                local_8c = iVar13;
                if ((3 < iVar13) || (local_70[iVar13] == 0)) goto LAB_0047a6a0;
                iVar13 = iVar13 * 4;
                if (iVar13 != 2) break;
                puVar14 = puVar16 + 1;
                *puVar16 = (char)local_60[2];
              }
            } while( true );
          }
          do {
            puVar14 = PTR_BN_bn2bin_006a7200;
            *puVar16 = (char)((uint)*(undefined4 *)((int)local_60 + uVar3) >> 8);
            puVar16[1] = (char)local_60[local_8c];
            (*(code *)puVar14)(local_70[local_8c],puVar16 + 2);
            iVar13 = local_8c + 1;
            puVar16 = puVar16 + 2 + local_60[local_8c];
            local_8c = iVar13;
            if (3 < iVar13) break;
            uVar3 = iVar13 * 4;
          } while (local_70[iVar13] != 0);
        }
LAB_0047a6a0:
        puVar14 = PTR_memcpy_006a9aec;
        if ((uVar9 & 0x80) != 0) {
          puVar16[2] = (undefined)local_9c;
          puVar16[3] = (char)local_a0;
          puVar16[1] = 0;
          *puVar16 = 3;
          param_4 = (char *)(*(code *)puVar14)(puVar16 + 4,local_a4,local_a0);
          puVar16 = (undefined *)((int)param_4 + local_a0);
          (*(code *)PTR_CRYPTO_free_006a6e88)(local_a4);
          local_a4 = (int *)0x0;
        }
        if ((uVar9 & 0x100) != 0) {
          (*(code *)PTR_strlen_006a9a24)(*(undefined4 *)(param_1[0x39] + 0x14c));
          *puVar16 = extraout_var;
          uVar5 = (*(code *)PTR_strlen_006a9a24)(*(undefined4 *)(param_1[0x39] + 0x14c));
          puVar16[1] = uVar5;
          uVar7 = *(undefined4 *)(param_1[0x39] + 0x14c);
          uVar4 = (*(code *)PTR_strlen_006a9a24)(uVar7);
          (*(code *)PTR_strncpy_006a99e0)(puVar16 + 2,uVar7,uVar4);
          iVar13 = (*(code *)PTR_strlen_006a9a24)(*(undefined4 *)(param_1[0x39] + 0x14c));
          puVar16 = puVar16 + 2 + iVar13;
        }
        if (local_ac != (int *)0x0) {
          if (*local_ac == 6) {
            if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
              if (local_90 != 0) {
LAB_0047abc4:
                iVar13 = tls12_get_sigandhash(puVar16,local_ac,local_90);
                if (iVar13 != 0) {
                  puVar16 = puVar16 + 2;
                  goto LAB_0047a6f0;
                }
                uVar7 = 0x44;
                uVar4 = 0x7e3;
                goto LAB_0047afa8;
              }
LAB_0047b08c:
              param_4 = "s3_srvr.c";
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9b,0xfb,"s3_srvr.c",0x7ff);
              uVar4 = 0x28;
              goto LAB_0047afc0;
            }
            local_a8 = 0;
            iVar13 = 2;
            puVar14 = auStack_50;
            do {
              (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(auStack_88,8);
              if (iVar13 == 2) {
                uVar4 = *(undefined4 *)(param_1[0x39] + 0x8c);
              }
              else {
                uVar4 = *(undefined4 *)(param_1[0x39] + 0x90);
              }
              iVar10 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_88,uVar4,0);
              if ((((iVar10 < 1) ||
                   (iVar10 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                       (auStack_88,param_1[0x16] + 0xc0,0x20), iVar10 < 1)) ||
                  (iVar10 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                      (auStack_88,param_1[0x16] + 0xa0,0x20), iVar10 < 1)) ||
                 ((iVar10 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_88,local_b0,iVar6),
                  iVar10 < 1 ||
                  (iVar10 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_88,puVar14,&local_8c)
                  , iVar10 < 1)))) {
                uVar7 = 6;
                uVar4 = 0x7ca;
                goto LAB_0047afa8;
              }
              iVar13 = iVar13 + -1;
              puVar14 = puVar14 + local_8c;
              local_a8 = local_a8 + local_8c;
            } while (iVar13 != 0);
            param_4 = puVar16 + 2;
            iVar13 = (*(code *)PTR_RSA_sign_006a7a78)
                               (0x72,auStack_50,local_a8,param_4,&local_94,local_ac[5]);
            if (iVar13 < 1) {
              uVar7 = 4;
              uVar4 = 0x7d3;
              goto LAB_0047b1a0;
            }
            *puVar16 = (char)((uint)local_94 >> 8);
            puVar16[1] = (char)local_94;
            iVar6 = local_94 + 2 + iVar6;
            local_a8 = iVar6 + 4;
          }
          else {
            if (local_90 == 0) goto LAB_0047b08c;
            if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) goto LAB_0047abc4;
LAB_0047a6f0:
            iVar13 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_88,local_90,0);
            if ((((iVar13 < 1) ||
                 (iVar13 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                     (auStack_88,param_1[0x16] + 0xc0,0x20), iVar13 < 1)) ||
                (iVar13 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                    (auStack_88,param_1[0x16] + 0xa0,0x20), iVar13 < 1)) ||
               ((iVar13 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_88,local_b0,iVar6),
                iVar13 < 1 ||
                (iVar13 = (*(code *)PTR_EVP_SignFinal_006a7f70)
                                    (auStack_88,puVar16 + 2,&local_8c,local_ac), iVar13 < 1)))) {
              uVar7 = 6;
              uVar4 = 0x7f3;
LAB_0047afa8:
              param_4 = "s3_srvr.c";
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9b,uVar7,"s3_srvr.c",uVar4);
              uVar4 = 0x50;
              goto LAB_0047afc0;
            }
            *puVar16 = (char)((uint)local_8c >> 8);
            puVar16[1] = (char)local_8c;
            iVar6 = iVar6 + local_8c + 2;
            param_4 = (char *)local_ac;
            if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
              local_a8 = iVar6 + 6;
              iVar6 = iVar6 + 2;
            }
            else {
              local_a8 = iVar6 + 4;
            }
          }
        }
        puVar12[3] = (char)iVar6;
        puVar12[1] = (char)((uint)iVar6 >> 0x10);
        *puVar12 = 0xc;
        puVar12[2] = (char)((uint)iVar6 >> 8);
        param_1[0x12] = 0;
        param_1[0x11] = local_a8;
LAB_0047a7e0:
        puVar12 = PTR_EVP_MD_CTX_cleanup_006a6e34;
        param_1[0xd] = 0x2151;
        (*(code *)puVar12)(auStack_88);
        uVar4 = ssl3_do_write(param_1,0x16);
        goto LAB_0047a80c;
      }
      iVar13 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar11,iVar6 + 4);
      if (iVar13 != 0) {
        local_ac = (int *)0x0;
        puVar12 = *(undefined **)(param_1[0xf] + 4);
        goto LAB_0047a5fc;
      }
LAB_0047b18c:
      uVar7 = 7;
      uVar4 = 0x77c;
LAB_0047b1a0:
      param_4 = "s3_srvr.c";
      iVar8 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9b,uVar7,"s3_srvr.c",uVar4);
    }
LAB_0047afd8:
    if (local_a4 == (int *)0x0) goto LAB_0047aff8;
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(local_a4);
LAB_0047aff8:
  while( true ) {
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_88);
    uVar4 = 0xffffffff;
    param_1[0xd] = 5;
LAB_0047a80c:
    if (local_2c == *(int *)puVar1) break;
    pcVar15 = (code *)PTR___stack_chk_fail_006a9ab0;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0047b334:
    param_4 = (char *)((int)param_4 + 0x6304);
LAB_0047b338:
    uVar7 = 0x166;
    uVar4 = 0x755;
LAB_0047b0d0:
    iVar8 = 0;
    (*pcVar15)(0x14,0x9b,uVar7,param_4,uVar4);
  }
  return uVar4;
}

