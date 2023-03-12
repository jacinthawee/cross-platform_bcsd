
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_88);
  if (*(int *)(param_1 + 0x34) != 0x2150) goto LAB_0049c428;
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
            goto LAB_0049c4a8;
          }
        }
        uVar7 = 0xab;
        uVar14 = 0x45a;
        goto LAB_0049cc60;
      }
LAB_0049c4a8:
      if (*(int *)(iVar12 + 0x348) != 0) {
        (*(code *)PTR_DH_free_006a8604)(0);
        uVar7 = 0x44;
        uVar14 = 0x461;
        goto LAB_0049cb4c;
      }
      iVar5 = (*(code *)PTR_DHparams_dup_006a90f8)(iVar8);
      if (iVar5 == 0) goto LAB_0049ce2c;
      iVar12 = *(int *)(iVar8 + 0x14);
      *(int *)(*(int *)(param_1 + 0x58) + 0x348) = iVar5;
      if (((iVar12 == 0) || (*(int *)(iVar8 + 0x18) == 0)) || (*(int *)(param_1 + 0x100) << 0xb < 0)
         ) {
        iVar12 = (*(code *)PTR_DH_generate_key_006a90fc)(iVar5);
        if (iVar12 == 0) {
          uVar7 = 5;
          uVar14 = 0x473;
          goto LAB_0049cb4c;
        }
        iVar12 = *(int *)(iVar5 + 0x14);
      }
      else {
        uVar7 = (*(code *)PTR_BN_dup_006a9100)();
        puVar15 = PTR_BN_dup_006a9100;
        uVar6 = *(undefined4 *)(iVar8 + 0x18);
        *(undefined4 *)(iVar5 + 0x14) = uVar7;
        iVar11 = (*(code *)puVar15)(uVar6);
        iVar12 = *(int *)(iVar5 + 0x14);
        *(int *)(iVar5 + 0x18) = iVar11;
        if ((iVar12 == 0) || (iVar11 == 0)) {
          uVar7 = 5;
          uVar14 = 0x47e;
          goto LAB_0049cb4c;
        }
      }
      iVar11 = *(int *)(iVar5 + 8);
      local_70[1] = *(undefined4 *)(iVar5 + 0xc);
      local_70[2] = iVar12;
      goto LAB_0049c17c;
    }
    if ((uVar9 & 0x80) == 0) {
      iVar11 = 0;
      if ((uVar9 & 0x100) == 0) {
        uVar7 = 0xfa;
        uVar14 = 0x511;
        goto LAB_0049cc60;
      }
      iVar5 = (*(code *)PTR_strlen_006aab30)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c));
      iVar5 = iVar5 + 2;
      local_94 = 0;
      local_98 = 0;
      local_a4 = 0;
      local_8c = 0;
      goto LAB_0049c204;
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
          goto LAB_0049c5b8;
        }
      }
      uVar7 = 0x137;
      uVar14 = 0x497;
      goto LAB_0049cc60;
    }
LAB_0049c5b8:
    if (*(int *)(iVar12 + 0x34c) != 0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)(*(int *)(iVar12 + 0x34c));
      uVar7 = 0x44;
      uVar14 = 0x49e;
      goto LAB_0049cb4c;
    }
    iVar5 = (*(code *)PTR_EC_KEY_dup_006a9108)(iVar8);
    puVar15 = PTR_EC_KEY_get0_public_key_006a8bd0;
    if (iVar5 == 0) {
      uVar7 = 0x2b;
      uVar14 = 0x4aa;
      goto LAB_0049cb4c;
    }
    *(int *)(*(int *)(param_1 + 0x58) + 0x34c) = iVar5;
    iVar12 = (*(code *)puVar15)(iVar5);
    if ((((iVar12 == 0) ||
         (iVar12 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar5), iVar12 == 0)) ||
        (*(int *)(param_1 + 0x100) << 0xc < 0)) &&
       (iVar12 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(iVar5), iVar12 == 0)) {
      uVar7 = 0x2b;
      uVar14 = 0x4b5;
      goto LAB_0049cb4c;
    }
    iVar12 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(iVar5);
    if (((iVar12 == 0) ||
        (iVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar5), iVar11 == 0)) ||
       (iVar11 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar5), iVar11 == 0)) {
      uVar7 = 0x2b;
      uVar14 = 0x4be;
      goto LAB_0049cb4c;
    }
    if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 2) != 0) &&
       (iVar11 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(iVar12), 0xa3 < iVar11)) {
      uVar7 = 0x136;
      uVar14 = 0x4c5;
      goto LAB_0049cb4c;
    }
    uVar7 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(iVar12);
    local_94 = tls1_ec_nid2curve_id(uVar7);
    if (local_94 == 0) {
      uVar7 = 0x13b;
      uVar14 = 0x4d1;
      goto LAB_0049cb4c;
    }
    uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar5);
    uVar7 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(iVar12,uVar7,4,0,0,0);
    local_a4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar7,"d1_srvr.c",0x4df);
    iVar8 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if ((local_a4 == 0) || (iVar8 == 0)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x10b,0x41,"d1_srvr.c",0x4e3);
      goto LAB_0049ca40;
    }
    uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar5);
    local_98 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(iVar12,uVar6,4,local_a4,uVar7,iVar8);
    if (local_98 != 0) {
      iVar5 = local_98 + 4;
      iVar11 = 0;
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar8);
      iVar12 = *(int *)(param_1 + 0x58);
      local_70[0] = 0;
      local_70[1] = 0;
      local_70[2] = 0;
      local_70[3] = 0;
      local_8c = 0;
      goto LAB_0049c204;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x10b,0x2b,"d1_srvr.c",0x4ef);
  }
  else {
    iVar8 = *(int *)(iVar11 + 0x18);
    if (iVar8 != 0) {
LAB_0049c164:
      iVar11 = *(int *)(iVar8 + 0x10);
      local_70[1] = *(undefined4 *)(iVar8 + 0x14);
      *(undefined4 *)(iVar12 + 0x370) = 1;
LAB_0049c17c:
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
          iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar12);
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
LAB_0049c204:
      iVar12 = *(int *)(iVar12 + 0x344);
      if (((*(uint *)(iVar12 + 0x10) & 4) == 0) && ((*(uint *)(iVar12 + 0xc) & 0x100) == 0)) {
        piVar13 = (int *)ssl_get_sign_pkey(param_1,iVar12,0);
        if (piVar13 == (int *)0x0) {
          uVar14 = 0x32;
          goto LAB_0049cb0c;
        }
        iVar12 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(piVar13);
      }
      else {
        iVar12 = 0;
        piVar13 = (int *)0x0;
      }
      iVar8 = iVar5 + 0xc;
      iVar12 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(uVar14,iVar12 + iVar8);
      if (iVar12 == 0) {
        uVar7 = 7;
        uVar14 = 0x52d;
        goto LAB_0049ca28;
      }
      local_8c = 0;
      iVar12 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
      puVar3 = (undefined *)(iVar12 + 0xc);
      puVar15 = puVar3;
      if (iVar11 != 0) {
        iVar11 = 0;
        do {
          puVar10 = PTR_BN_bn2bin_006a8300;
          *puVar15 = (char)((uint)*(undefined4 *)((int)local_60 + iVar11) >> 8);
          puVar15[1] = (char)local_60[local_8c];
          (*(code *)puVar10)(local_70[local_8c],puVar15 + 2);
          iVar2 = local_8c + 1;
          iVar11 = iVar2 * 4;
          puVar15 = puVar15 + 2 + local_60[local_8c];
          local_8c = iVar2;
        } while (local_70[iVar2] != 0);
      }
      puVar10 = PTR_memcpy_006aabf4;
      if ((uVar9 & 0x80) != 0) {
        puVar15[2] = (undefined)local_94;
        puVar15[3] = (char)local_98;
        puVar15[1] = 0;
        *puVar15 = 3;
        iVar11 = (*(code *)puVar10)(puVar15 + 4,local_a4,local_98);
        puVar15 = (undefined *)(iVar11 + local_98);
        (*(code *)PTR_CRYPTO_free_006a7f88)(local_a4);
      }
      if ((uVar9 & 0x100) != 0) {
        (*(code *)PTR_strlen_006aab30)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c));
        *puVar15 = extraout_var;
        uVar4 = (*(code *)PTR_strlen_006aab30)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c));
        puVar15[1] = uVar4;
        uVar7 = *(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c);
        uVar14 = (*(code *)PTR_strlen_006aab30)(uVar7);
        (*(code *)PTR_strncpy_006aaaec)(puVar15 + 2,uVar7,uVar14);
        iVar11 = (*(code *)PTR_strlen_006aab30)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x14c));
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
            (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_88,uVar14,0);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xc0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xa0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_88,puVar3,iVar5);
            (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_88,puVar10,&local_8c);
            puVar10 = puVar10 + local_8c;
            iVar11 = iVar11 + local_8c;
          } while (iVar8 != 0);
          iVar11 = (*(code *)PTR_RSA_sign_006a8b64)
                             (0x72,auStack_50,iVar11,puVar15 + 2,&local_90,piVar13[5]);
          if (iVar11 < 1) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x10b,4,"d1_srvr.c",0x577);
            goto LAB_0049ca40;
          }
          *puVar15 = (char)((uint)local_90 >> 8);
          puVar15[1] = (char)local_90;
        }
        else {
          if (iVar11 == 0x74) {
            uVar14 = (*(code *)PTR_EVP_dss1_006a9338)();
            (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_88,uVar14,0);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xc0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xa0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_88,puVar3,iVar5);
            iVar11 = (*(code *)PTR_EVP_SignFinal_006a9094)(auStack_88,puVar15 + 2,&local_8c,piVar13)
            ;
            if (iVar11 == 0) {
              uVar7 = 10;
              uVar14 = 0x58a;
LAB_0049ca28:
              iVar8 = 0;
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x10b,uVar7,"d1_srvr.c",uVar14);
              goto LAB_0049ca40;
            }
          }
          else {
            if (iVar11 != 0x198) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x10b,0xfb,"d1_srvr.c",0x5a8);
              uVar14 = 0x28;
              goto LAB_0049cb0c;
            }
            uVar14 = (*(code *)PTR_EVP_ecdsa_006a933c)();
            (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_88,uVar14,0);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xc0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)
                      (auStack_88,*(int *)(param_1 + 0x58) + 0xa0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_88,puVar3,iVar5);
            iVar11 = (*(code *)PTR_EVP_SignFinal_006a9094)(auStack_88,puVar15 + 2,&local_8c,piVar13)
            ;
            if (iVar11 == 0) {
              uVar7 = 0x2a;
              uVar14 = 0x59d;
              goto LAB_0049ca28;
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
LAB_0049c428:
      puVar15 = PTR_EVP_MD_CTX_cleanup_006a7f34;
      *(undefined4 *)(param_1 + 0x34) = 0x2151;
      (*(code *)puVar15)(auStack_88);
      uVar14 = dtls1_do_write(param_1,0x16);
      goto LAB_0049c454;
    }
    uVar7 = 0x200;
    if (*(code **)(iVar11 + 0x1c) == (code *)0x0) {
      uVar7 = 0xac;
      uVar14 = 0x446;
    }
    else {
      if ((*(uint *)(iVar5 + 0x20) & 8) == 0) {
        uVar7 = 0x400;
      }
      iVar8 = (**(code **)(iVar11 + 0x1c))(param_1,*(uint *)(iVar5 + 0x20) & 2,uVar7);
      if (iVar8 != 0) {
        (*(code *)PTR_RSA_up_ref_006a9120)(iVar8);
        iVar12 = *(int *)(param_1 + 0x58);
        *(int *)(iVar11 + 0x18) = iVar8;
        goto LAB_0049c164;
      }
      uVar7 = 0x11a;
      uVar14 = 0x43d;
    }
LAB_0049cc60:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x10b,uVar7,"d1_srvr.c",uVar14);
    uVar14 = 0x28;
    local_a4 = 0;
LAB_0049cb0c:
    iVar8 = 0;
    ssl3_send_alert(param_1,2,uVar14);
LAB_0049ca40:
    if (local_a4 == 0) goto LAB_0049ca60;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(local_a4);
LAB_0049ca60:
  while( true ) {
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar8);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_88);
    uVar14 = 0xffffffff;
LAB_0049c454:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0049ce2c:
    uVar7 = 5;
    uVar14 = 0x467;
LAB_0049cb4c:
    iVar8 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x10b,uVar7,"d1_srvr.c",uVar14);
  }
  return uVar14;
}

