
/* WARNING: Could not reconcile some variable overlaps */

undefined4 dtls1_send_server_key_exchange(int param_1)

{
  undefined *puVar1;
  undefined extraout_var;
  int iVar2;
  undefined *puVar3;
  undefined uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined4 uVar14;
  undefined *puVar15;
  int local_a4;
  int local_98;
  undefined4 local_94;
  int local_90;
  int local_8c;
  undefined auStack_88 [24];
  int local_70 [4];
  int local_60 [4];
  undefined auStack_50 [36];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_88);
  if (*(int *)(param_1 + 0x34) != 0x2150) goto LAB_00498938;
  iVar12 = *(int *)(param_1 + 0x58);
  iVar11 = *(int *)(param_1 + 0x98);
  uVar14 = *(undefined4 *)(param_1 + 0x3c);
  local_70[3] = 0;
  iVar5 = *(int *)(iVar12 + 0x344);
  local_70[2] = 0;
  local_70[1] = 0;
  local_70[0] = 0;
  uVar9 = *(uint *)(iVar5 + 0xc);
  if ((uVar9 & 1) == 0) {
    if ((uVar9 & 8) != 0) {
      iVar8 = *(int *)(iVar11 + 0x20);
      if (iVar8 == 0) {
        if (*(code **)(iVar11 + 0x24) != (code *)0x0) {
          uVar7 = 0x200;
          if ((*(uint *)(iVar5 + 0x20) & 8) == 0) {
            uVar7 = 0x400;
          }
          iVar8 = (**(code **)(iVar11 + 0x24))(param_1,*(uint *)(iVar5 + 0x20) & 2,uVar7);
          if (iVar8 != 0) {
            iVar12 = *(int *)(param_1 + 0x58);
            goto LAB_004989b8;
          }
        }
        uVar7 = 0xab;
        uVar14 = 0x493;
        goto LAB_00499174;
      }
LAB_004989b8:
      if (*(int *)(iVar12 + 0x348) != 0) {
        (*(code *)PTR_DH_free_006a7508)(0);
        uVar7 = 0x44;
        uVar14 = 0x49a;
        goto LAB_00499060;
      }
      iVar5 = (*(code *)PTR_DHparams_dup_006a7f8c)(iVar8);
      if (iVar5 == 0) goto LAB_00499340;
      iVar12 = *(int *)(iVar8 + 0x14);
      *(int *)(*(int *)(param_1 + 0x58) + 0x348) = iVar5;
      if (((iVar12 == 0) || (*(int *)(iVar8 + 0x18) == 0)) || (*(int *)(param_1 + 0x100) << 0xb < 0)
         ) {
        iVar12 = (*(code *)PTR_DH_generate_key_006a7f90)(iVar5);
        if (iVar12 == 0) {
          uVar7 = 5;
          uVar14 = 0x4a9;
          goto LAB_00499060;
        }
        iVar12 = *(int *)(iVar5 + 0x14);
      }
      else {
        uVar7 = (*(code *)PTR_BN_dup_006a8218)();
        puVar15 = PTR_BN_dup_006a8218;
        uVar6 = *(undefined4 *)(iVar8 + 0x18);
        *(undefined4 *)(iVar5 + 0x14) = uVar7;
        iVar11 = (*(code *)puVar15)(uVar6);
        iVar12 = *(int *)(iVar5 + 0x14);
        *(int *)(iVar5 + 0x18) = iVar11;
        if ((iVar12 == 0) || (iVar11 == 0)) {
          uVar7 = 5;
          uVar14 = 0x4b1;
          goto LAB_00499060;
        }
      }
      iVar11 = *(int *)(iVar5 + 8);
      local_70[1] = *(undefined4 *)(iVar5 + 0xc);
      local_70[2] = iVar12;
      goto LAB_0049868c;
    }
    if ((uVar9 & 0x80) == 0) {
      iVar11 = 0;
      if ((uVar9 & 0x100) == 0) {
        uVar7 = 0xfa;
        uVar14 = 0x540;
        goto LAB_00499174;
      }
      iVar5 = (*(code *)PTR_strlen_006a9a24)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c));
      iVar5 = iVar5 + 2;
      local_94 = 0;
      local_98 = 0;
      local_a4 = 0;
      local_8c = 0;
      goto LAB_00498714;
    }
    iVar8 = *(int *)(iVar11 + 0x28);
    if (iVar8 == 0) {
      if (*(code **)(iVar11 + 0x2c) != (code *)0x0) {
        uVar7 = 0x200;
        if ((*(uint *)(iVar5 + 0x20) & 8) == 0) {
          uVar7 = 0x400;
        }
        iVar8 = (**(code **)(iVar11 + 0x2c))(param_1,*(uint *)(iVar5 + 0x20) & 2,uVar7);
        if (iVar8 != 0) {
          iVar12 = *(int *)(param_1 + 0x58);
          goto LAB_00498ac8;
        }
      }
      uVar7 = 0x137;
      uVar14 = 0x4c9;
      goto LAB_00499174;
    }
LAB_00498ac8:
    if (*(int *)(iVar12 + 0x34c) != 0) {
      (*(code *)PTR_EC_KEY_free_006a71d4)(*(int *)(iVar12 + 0x34c));
      uVar7 = 0x44;
      uVar14 = 0x4d0;
      goto LAB_00499060;
    }
    iVar5 = (*(code *)PTR_EC_KEY_dup_006a7f74)(iVar8);
    puVar15 = PTR_EC_KEY_get0_public_key_006a7ae4;
    if (iVar5 == 0) {
      uVar7 = 0x2b;
      uVar14 = 0x4da;
      goto LAB_00499060;
    }
    *(int *)(*(int *)(param_1 + 0x58) + 0x34c) = iVar5;
    iVar12 = (*(code *)puVar15)(iVar5);
    if ((((iVar12 == 0) ||
         (iVar12 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar5), iVar12 == 0)) ||
        (*(int *)(param_1 + 0x100) << 0xc < 0)) &&
       (iVar12 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(iVar5), iVar12 == 0)) {
      uVar7 = 0x2b;
      uVar14 = 0x4e4;
      goto LAB_00499060;
    }
    iVar12 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar5);
    if (((iVar12 == 0) ||
        (iVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar5), iVar11 == 0)) ||
       (iVar11 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar5), iVar11 == 0)) {
      uVar7 = 0x2b;
      uVar14 = 0x4ec;
      goto LAB_00499060;
    }
    if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 2) != 0) &&
       (iVar11 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(iVar12), 0xa3 < iVar11)) {
      uVar7 = 0x136;
      uVar14 = 0x4f3;
      goto LAB_00499060;
    }
    uVar7 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(iVar12);
    local_94 = tls1_ec_nid2curve_id(uVar7);
    if (local_94 == 0) {
      uVar7 = 0x13b;
      uVar14 = 0x500;
      goto LAB_00499060;
    }
    uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar5);
    uVar7 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)(iVar12,uVar7,4,0,0,0);
    local_a4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar7,"d1_srvr.c",0x50e);
    iVar8 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if ((local_a4 == 0) || (iVar8 == 0)) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10b,0x41,"d1_srvr.c",0x512);
      goto LAB_00498f54;
    }
    uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar5);
    local_98 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)(iVar12,uVar6,4,local_a4,uVar7,iVar8);
    if (local_98 != 0) {
      iVar5 = local_98 + 4;
      iVar11 = 0;
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
      iVar12 = *(int *)(param_1 + 0x58);
      local_70[0] = 0;
      local_70[1] = 0;
      local_70[2] = 0;
      local_70[3] = 0;
      local_8c = 0;
      goto LAB_00498714;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10b,0x2b,"d1_srvr.c",0x51c);
  }
  else {
    iVar8 = *(int *)(iVar11 + 0x18);
    if (iVar8 != 0) {
LAB_00498674:
      iVar11 = *(int *)(iVar8 + 0x10);
      local_70[1] = *(undefined4 *)(iVar8 + 0x14);
      *(undefined4 *)(iVar12 + 0x370) = 1;
LAB_0049868c:
      local_8c = 0;
      local_70[0] = iVar11;
      if (iVar11 == 0) {
        iVar12 = *(int *)(param_1 + 0x58);
        iVar5 = 0;
        local_94 = 0;
        local_98 = 0;
        local_a4 = 0;
      }
      else {
        iVar5 = 0;
        iVar12 = iVar11;
        iVar8 = 0;
        do {
          iVar2 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar12);
          iVar12 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            iVar12 = iVar2 + 0xe;
          }
          iVar2 = local_8c + 1;
          *(int *)((int)local_60 + iVar8) = iVar12 >> 3;
          iVar12 = local_70[iVar2];
          iVar5 = iVar5 + local_60[local_8c] + 2;
          iVar8 = iVar2 * 4;
          local_8c = iVar2;
        } while (iVar12 != 0);
        iVar12 = *(int *)(param_1 + 0x58);
        local_94 = 0;
        local_98 = 0;
        local_a4 = 0;
      }
LAB_00498714:
      iVar12 = *(int *)(iVar12 + 0x344);
      if (((*(uint *)(iVar12 + 0x10) & 4) == 0) && ((*(uint *)(iVar12 + 0xc) & 0x100) == 0)) {
        piVar13 = (int *)ssl_get_sign_pkey(param_1,iVar12,0);
        if (piVar13 == (int *)0x0) {
          uVar14 = 0x32;
          goto LAB_00499020;
        }
        iVar12 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(piVar13);
      }
      else {
        iVar12 = 0;
        piVar13 = (int *)0x0;
      }
      iVar8 = iVar5 + 0xc;
      iVar12 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(uVar14,iVar12 + iVar8);
      if (iVar12 == 0) {
        uVar7 = 7;
        uVar14 = 0x556;
        goto LAB_00498f3c;
      }
      local_8c = 0;
      iVar12 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
      puVar3 = (undefined *)(iVar12 + 0xc);
      puVar15 = puVar3;
      if (iVar11 != 0) {
        iVar11 = 0;
        do {
          puVar10 = PTR_BN_bn2bin_006a7200;
          *puVar15 = (char)((uint)*(undefined4 *)((int)local_60 + iVar11) >> 8);
          puVar15[1] = (char)local_60[local_8c];
          (*(code *)puVar10)(local_70[local_8c],puVar15 + 2);
          iVar2 = local_8c + 1;
          iVar11 = iVar2 * 4;
          puVar15 = puVar15 + 2 + local_60[local_8c];
          local_8c = iVar2;
        } while (local_70[iVar2] != 0);
      }
      puVar10 = PTR_memcpy_006a9aec;
      if ((uVar9 & 0x80) != 0) {
        puVar15[2] = (undefined)local_94;
        puVar15[3] = (char)local_98;
        puVar15[1] = 0;
        *puVar15 = 3;
        iVar11 = (*(code *)puVar10)(puVar15 + 4,local_a4,local_98);
        puVar15 = (undefined *)(iVar11 + local_98);
        (*(code *)PTR_CRYPTO_free_006a6e88)(local_a4);
        local_a4 = 0;
      }
      if ((uVar9 & 0x100) != 0) {
        (*(code *)PTR_strlen_006a9a24)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c));
        *puVar15 = extraout_var;
        uVar4 = (*(code *)PTR_strlen_006a9a24)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c));
        puVar15[1] = uVar4;
        uVar7 = *(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c);
        uVar14 = (*(code *)PTR_strlen_006a9a24)(uVar7);
        (*(code *)PTR_strncpy_006a99e0)(puVar15 + 2,uVar7,uVar14);
        iVar11 = (*(code *)PTR_strlen_006a9a24)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c));
        puVar15 = puVar15 + 2 + iVar11;
      }
      if (piVar13 != (int *)0x0) {
        iVar11 = *piVar13;
        if (iVar11 == 6) {
          iVar8 = 2;
          iVar11 = 0;
          puVar10 = auStack_50;
          do {
            if (iVar8 == 2) {
              uVar14 = *(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x8c);
            }
            else {
              uVar14 = *(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x90);
            }
            iVar8 = iVar8 + -1;
            (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_88,uVar14,0);
            (*(code *)PTR_EVP_DigestUpdate_006a7580)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xc0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a7580)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xa0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_88,puVar3,iVar5);
            (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_88,puVar10,&local_8c);
            puVar10 = puVar10 + local_8c;
            iVar11 = iVar11 + local_8c;
          } while (iVar8 != 0);
          iVar11 = (*(code *)PTR_RSA_sign_006a7a78)
                             (0x72,auStack_50,iVar11,puVar15 + 2,&local_90,piVar13[5]);
          if (iVar11 < 1) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10b,4,"d1_srvr.c",0x59e);
            goto LAB_00498f54;
          }
          *puVar15 = (char)((uint)local_90 >> 8);
          puVar15[1] = (char)local_90;
        }
        else {
          if (iVar11 == 0x74) {
            uVar14 = (*(code *)PTR_EVP_dss1_006a8210)();
            (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_88,uVar14,0);
            (*(code *)PTR_EVP_DigestUpdate_006a7580)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xc0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a7580)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xa0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_88,puVar3,iVar5);
            iVar11 = (*(code *)PTR_EVP_SignFinal_006a7f70)(auStack_88,puVar15 + 2,&local_8c,piVar13)
            ;
            if (iVar11 == 0) {
              uVar7 = 10;
              uVar14 = 0x5b0;
LAB_00498f3c:
              iVar8 = 0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10b,uVar7,"d1_srvr.c",uVar14);
              goto LAB_00498f54;
            }
          }
          else {
            if (iVar11 != 0x198) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10b,0xfb,"d1_srvr.c",0x5ce);
              uVar14 = 0x28;
              goto LAB_00499020;
            }
            uVar14 = (*(code *)PTR_EVP_ecdsa_006a8214)();
            (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_88,uVar14,0);
            (*(code *)PTR_EVP_DigestUpdate_006a7580)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xc0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a7580)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xa0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_88,puVar3,iVar5);
            iVar11 = (*(code *)PTR_EVP_SignFinal_006a7f70)(auStack_88,puVar15 + 2,&local_8c,piVar13)
            ;
            if (iVar11 == 0) {
              uVar7 = 0x2a;
              uVar14 = 0x5c3;
              goto LAB_00498f3c;
            }
          }
          *puVar15 = (char)((uint)local_8c >> 8);
          puVar15[1] = (char)local_8c;
          local_90 = local_8c;
        }
        iVar5 = iVar5 + local_90 + 2;
        iVar8 = iVar5 + 0xc;
      }
      dtls1_set_message_header(param_1,iVar12,0xc,iVar5,0,iVar5);
      *(int *)(param_1 + 0x44) = iVar8;
      *(undefined4 *)(param_1 + 0x48) = 0;
      dtls1_buffer_message(param_1,0);
LAB_00498938:
      puVar15 = PTR_EVP_MD_CTX_cleanup_006a6e34;
      *(undefined4 *)(param_1 + 0x34) = 0x2151;
      (*(code *)puVar15)(auStack_88);
      uVar14 = dtls1_do_write(param_1,0x16);
      goto LAB_00498964;
    }
    uVar7 = 0x200;
    if (*(code **)(iVar11 + 0x1c) == (code *)0x0) {
      uVar7 = 0xac;
      uVar14 = 0x47f;
    }
    else {
      if ((*(uint *)(iVar5 + 0x20) & 8) == 0) {
        uVar7 = 0x400;
      }
      iVar8 = (**(code **)(iVar11 + 0x1c))(param_1,*(uint *)(iVar5 + 0x20) & 2,uVar7);
      if (iVar8 != 0) {
        (*(code *)PTR_RSA_up_ref_006a7f98)(iVar8);
        iVar12 = *(int *)(param_1 + 0x58);
        *(int *)(iVar11 + 0x18) = iVar8;
        goto LAB_00498674;
      }
      uVar7 = 0x11a;
      uVar14 = 0x476;
    }
LAB_00499174:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10b,uVar7,"d1_srvr.c",uVar14);
    uVar14 = 0x28;
    local_a4 = 0;
LAB_00499020:
    iVar8 = 0;
    ssl3_send_alert(param_1,2,uVar14);
LAB_00498f54:
    if (local_a4 == 0) goto LAB_00498f74;
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(local_a4);
LAB_00498f74:
  while( true ) {
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_88);
    uVar14 = 0xffffffff;
LAB_00498964:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00499340:
    uVar7 = 5;
    uVar14 = 0x49f;
LAB_00499060:
    iVar8 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10b,uVar7,"d1_srvr.c",uVar14);
  }
  return uVar14;
}

