
/* WARNING: Could not reconcile some variable overlaps */

undefined4 ssl3_send_server_key_exchange(int *param_1)

{
  undefined *puVar1;
  undefined extraout_var;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  undefined *puVar14;
  undefined *puVar15;
  int *local_b0;
  int local_ac;
  int local_a4;
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_90 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_88);
  if (param_1[0xd] != 0x2150) goto LAB_0047f3a4;
  iVar13 = param_1[0x16];
  iVar12 = param_1[0x26];
  iVar10 = param_1[0xf];
  local_70[3] = 0;
  iVar6 = *(int *)(iVar13 + 0x344);
  local_70[2] = 0;
  local_70[1] = 0;
  local_70[0] = 0;
  uVar9 = *(uint *)(iVar6 + 0xc);
  if ((uVar9 & 1) == 0) {
    if ((uVar9 & 8) != 0) {
      iVar8 = *(int *)(iVar12 + 0x20);
      if (iVar8 == 0) {
        if (*(code **)(iVar12 + 0x24) != (code *)0x0) {
          uVar4 = 0x200;
          if ((*(uint *)(iVar6 + 0x20) & 8) == 0) {
            uVar4 = 0x400;
          }
          iVar8 = (**(code **)(iVar12 + 0x24))(param_1,*(uint *)(iVar6 + 0x20) & 2,uVar4);
          if (iVar8 != 0) {
            iVar13 = param_1[0x16];
            goto LAB_0047f424;
          }
        }
        uVar7 = 0xab;
        uVar4 = 0x65f;
        goto LAB_0047fd6c;
      }
LAB_0047f424:
      if (*(int *)(iVar13 + 0x348) != 0) {
        uVar7 = 0x44;
        uVar4 = 0x665;
        goto LAB_0047fc2c;
      }
      iVar6 = (*(code *)PTR_DHparams_dup_006a90f8)(iVar8);
      if (iVar6 == 0) {
        uVar7 = 5;
        uVar4 = 0x66b;
        goto LAB_0047fc2c;
      }
      iVar13 = *(int *)(iVar8 + 0x14);
      *(int *)(param_1[0x16] + 0x348) = iVar6;
      if (((iVar13 == 0) || (*(int *)(iVar8 + 0x18) == 0)) || (param_1[0x40] << 0xb < 0)) {
        iVar13 = (*(code *)PTR_DH_generate_key_006a90fc)(iVar6);
        if (iVar13 == 0) {
          uVar7 = 5;
          uVar4 = 0x677;
          goto LAB_0047fc2c;
        }
        iVar13 = *(int *)(iVar6 + 0x14);
      }
      else {
        uVar4 = (*(code *)PTR_BN_dup_006a9100)();
        puVar15 = PTR_BN_dup_006a9100;
        uVar7 = *(undefined4 *)(iVar8 + 0x18);
        *(undefined4 *)(iVar6 + 0x14) = uVar4;
        iVar12 = (*(code *)puVar15)(uVar7);
        iVar13 = *(int *)(iVar6 + 0x14);
        *(int *)(iVar6 + 0x18) = iVar12;
        if ((iVar13 == 0) || (iVar12 == 0)) {
          uVar7 = 5;
          uVar4 = 0x682;
          goto LAB_0047fc2c;
        }
      }
      iVar12 = *(int *)(iVar6 + 8);
      local_70[1] = *(int *)(iVar6 + 0xc);
      local_70[2] = iVar13;
      goto LAB_0047f0cc;
    }
    if ((uVar9 & 0x80) == 0) {
      iVar12 = 0;
      if ((uVar9 & 0x100) == 0) {
        if ((uVar9 & 0x400) == 0) {
          uVar7 = 0xfa;
          uVar4 = 0x726;
          goto LAB_0047fd6c;
        }
        if (((param_1[0x6a] == 0) || (param_1[0x6b] == 0)) ||
           ((param_1[0x6c] == 0 ||
            (iVar12 = param_1[0x6a], iVar6 = param_1[0x6b], iVar13 = param_1[0x6c],
            iVar8 = param_1[0x6d], param_1[0x6d] == 0)))) {
          uVar7 = 0x166;
          uVar4 = 0x71a;
          goto LAB_0047fc2c;
        }
        goto LAB_0047f0d8;
      }
      iVar6 = (*(code *)PTR_strlen_006aab30)(*(undefined4 *)(param_1[0x39] + 0x14c));
      iVar6 = iVar6 + 2;
      local_9c = 0;
      local_a0 = 0;
      local_a4 = 0;
      local_8c = 0;
      goto LAB_0047f170;
    }
    iVar8 = *(int *)(iVar12 + 0x28);
    if (iVar8 == 0) {
      if (*(code **)(iVar12 + 0x2c) != (code *)0x0) {
        uVar4 = 0x200;
        if ((*(uint *)(iVar6 + 0x20) & 8) == 0) {
          uVar4 = 0x400;
        }
        iVar8 = (**(code **)(iVar12 + 0x2c))(param_1,*(uint *)(iVar6 + 0x20) & 2,uVar4);
        if (iVar8 != 0) {
          iVar13 = param_1[0x16];
          goto LAB_0047f63c;
        }
      }
      uVar7 = 0x137;
      uVar4 = 0x69b;
      goto LAB_0047fd6c;
    }
LAB_0047f63c:
    if (*(int *)(iVar13 + 0x34c) != 0) {
      uVar7 = 0x44;
      uVar4 = 0x6a1;
      goto LAB_0047fc2c;
    }
    iVar6 = (*(code *)PTR_EC_KEY_dup_006a9108)(iVar8);
    puVar15 = PTR_EC_KEY_get0_public_key_006a8bd0;
    if (iVar6 == 0) goto LAB_0047ff0c;
    *(int *)(param_1[0x16] + 0x34c) = iVar6;
    iVar13 = (*(code *)puVar15)(iVar6);
    if ((((iVar13 == 0) ||
         (iVar13 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar6), iVar13 == 0)) ||
        (param_1[0x40] << 0xc < 0)) &&
       (iVar13 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(iVar6), iVar13 == 0)) {
      uVar7 = 0x2b;
      uVar4 = 0x6b8;
      goto LAB_0047fc2c;
    }
    iVar13 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(iVar6);
    if (((iVar13 == 0) ||
        (iVar12 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar6), iVar12 == 0)) ||
       (iVar12 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar6), iVar12 == 0)) {
      uVar7 = 0x2b;
      uVar4 = 0x6c1;
      goto LAB_0047fc2c;
    }
    if (((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) != 0) &&
       (iVar12 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(iVar13), 0xa3 < iVar12)) {
      uVar7 = 0x136;
      uVar4 = 0x6c8;
      goto LAB_0047fc2c;
    }
    uVar4 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(iVar13);
    local_9c = tls1_ec_nid2curve_id(uVar4);
    if (local_9c == 0) {
      uVar7 = 0x13b;
      uVar4 = 0x6d4;
      goto LAB_0047fc2c;
    }
    uVar4 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar6);
    uVar4 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(iVar13,uVar4,4,0,0,0);
    local_a4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar4,"s3_srvr.c",0x6e2);
    iVar8 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if ((local_a4 == 0) || (iVar8 == 0)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9b,0x41,"s3_srvr.c",0x6e6);
      goto LAB_0047fbd4;
    }
    uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar6);
    local_a0 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(iVar13,uVar7,4,local_a4,uVar4,iVar8);
    if (local_a0 != 0) {
      iVar6 = local_a0 + 4;
      iVar12 = 0;
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar8);
      iVar13 = param_1[0x16];
      local_70[0] = 0;
      local_70[1] = 0;
      local_70[2] = 0;
      local_70[3] = 0;
      local_8c = 0;
      goto LAB_0047f170;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9b,0x2b,"s3_srvr.c",0x6f2);
  }
  else {
    iVar8 = *(int *)(iVar12 + 0x18);
    if (iVar8 == 0) {
      uVar4 = 0x200;
      if (*(code **)(iVar12 + 0x1c) == (code *)0x0) {
        uVar7 = 0xac;
        uVar4 = 0x64b;
      }
      else {
        if ((*(uint *)(iVar6 + 0x20) & 8) == 0) {
          uVar4 = 0x400;
        }
        iVar8 = (**(code **)(iVar12 + 0x1c))(param_1,*(uint *)(iVar6 + 0x20) & 2,uVar4);
        if (iVar8 != 0) {
          (*(code *)PTR_RSA_up_ref_006a9120)(iVar8);
          iVar13 = param_1[0x16];
          *(int *)(iVar12 + 0x18) = iVar8;
          goto LAB_0047f0b4;
        }
        uVar7 = 0x11a;
        uVar4 = 0x642;
      }
LAB_0047fd6c:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9b,uVar7,"s3_srvr.c",uVar4);
      uVar4 = 0x28;
      local_a4 = 0;
LAB_0047fbbc:
      iVar8 = 0;
      ssl3_send_alert(param_1,2,uVar4);
    }
    else {
LAB_0047f0b4:
      iVar12 = *(int *)(iVar8 + 0x10);
      local_70[1] = *(int *)(iVar8 + 0x14);
      *(undefined4 *)(iVar13 + 0x370) = 1;
LAB_0047f0cc:
      local_8c = 0;
      iVar6 = local_70[1];
      iVar13 = local_70[2];
      iVar8 = local_70[3];
      if (iVar12 == 0) {
        iVar13 = param_1[0x16];
        iVar6 = 0;
        local_9c = 0;
        local_a0 = 0;
        local_a4 = 0;
        local_70[0] = iVar12;
      }
      else {
LAB_0047f0d8:
        local_70[3] = iVar8;
        local_70[2] = iVar13;
        local_70[1] = iVar6;
        local_70[0] = iVar12;
        iVar12 = local_70[0];
        local_8c = 0;
        iVar6 = 0;
        if ((uVar9 & 0x400) == 0) {
          iVar13 = local_70[0];
          iVar8 = 0;
          do {
            iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar13);
            iVar13 = iVar2 + 7;
            if (iVar2 + 7 < 0) {
              iVar13 = iVar2 + 0xe;
            }
            iVar2 = local_8c + 1;
            *(int *)((int)local_60 + iVar8) = iVar13 >> 3;
            iVar13 = local_70[iVar2];
            iVar6 = iVar6 + local_60[local_8c] + 2;
            local_8c = iVar2;
            if (iVar13 == 0) {
              iVar13 = param_1[0x16];
              goto LAB_0047f164;
            }
            iVar8 = iVar2 * 4;
          } while (iVar2 < 4);
        }
        else {
          iVar8 = 0;
          iVar13 = local_70[0];
          do {
            while( true ) {
              iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar13);
              iVar13 = iVar2 + 7;
              if (iVar2 + 7 < 0) {
                iVar13 = iVar2 + 0xe;
              }
              *(int *)((int)local_60 + iVar8) = iVar13 >> 3;
              if (local_8c != 2) break;
              local_8c = 3;
              iVar6 = iVar6 + local_60[2] + 1;
              if (local_70[3] == 0) goto LAB_0047f160;
              iVar8 = 0xc;
              iVar13 = local_70[3];
            }
            iVar13 = local_8c + 1;
            iVar8 = iVar13 * 4;
            iVar6 = iVar6 + local_60[local_8c] + 2;
            local_8c = iVar13;
          } while ((local_70[iVar13] != 0) && (iVar13 = local_70[iVar13], iVar13 < 4));
        }
LAB_0047f160:
        iVar13 = param_1[0x16];
LAB_0047f164:
        local_9c = 0;
        local_a0 = 0;
        local_a4 = 0;
      }
LAB_0047f170:
      iVar13 = *(int *)(iVar13 + 0x344);
      if (((*(uint *)(iVar13 + 0x10) & 4) == 0) && ((*(uint *)(iVar13 + 0xc) & 0x100) == 0)) {
        local_b0 = (int *)(*(code *)PTR_ssl_get_sign_pkey_006a911c)(param_1,iVar13,&local_90);
        if (local_b0 == (int *)0x0) {
          uVar4 = 0x32;
          goto LAB_0047fbbc;
        }
        iVar13 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(local_b0);
      }
      else {
        iVar13 = 0;
        local_b0 = (int *)0x0;
      }
      local_ac = iVar6 + 4;
      iVar13 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar10,iVar13 + local_ac);
      if (iVar13 != 0) {
        local_8c = 0;
        puVar11 = *(undefined **)(param_1[0xf] + 4);
        puVar3 = puVar11 + 4;
        puVar15 = puVar3;
        if (iVar12 != 0) {
          if ((uVar9 & 0x400) != 0) {
            do {
              puVar14 = puVar15 + 2;
              *puVar15 = (char)((uint)local_60[local_8c] >> 8);
              puVar15[1] = (char)local_60[local_8c];
              while( true ) {
                (*(code *)PTR_BN_bn2bin_006a8300)(local_70[local_8c],puVar14);
                iVar13 = local_8c + 1;
                puVar15 = puVar14 + local_60[local_8c];
                local_8c = iVar13;
                if ((local_70[iVar13] == 0) || (3 < iVar13)) goto LAB_0047f278;
                if (iVar13 != 2) break;
                puVar14 = puVar15 + 1;
                *puVar15 = (char)local_60[2];
              }
            } while( true );
          }
          iVar13 = 0;
          do {
            puVar14 = PTR_BN_bn2bin_006a8300;
            *puVar15 = (char)((uint)*(undefined4 *)((int)local_60 + iVar13) >> 8);
            puVar15[1] = (char)local_60[local_8c];
            (*(code *)puVar14)(local_70[local_8c],puVar15 + 2);
            iVar10 = local_8c + 1;
            iVar13 = iVar10 * 4;
            puVar15 = puVar15 + 2 + local_60[local_8c];
            local_8c = iVar10;
            if (local_70[iVar10] == 0) break;
          } while (iVar10 < 4);
        }
LAB_0047f278:
        puVar14 = PTR_memcpy_006aabf4;
        if ((uVar9 & 0x80) != 0) {
          puVar15[2] = (undefined)local_9c;
          puVar15[3] = (char)local_a0;
          puVar15[1] = 0;
          *puVar15 = 3;
          iVar13 = (*(code *)puVar14)(puVar15 + 4,local_a4,local_a0);
          puVar15 = (undefined *)(iVar13 + local_a0);
          (*(code *)PTR_CRYPTO_free_006a7f88)(local_a4);
          local_a4 = 0;
        }
        if ((uVar9 & 0x100) != 0) {
          (*(code *)PTR_strlen_006aab30)(*(undefined4 *)(param_1[0x39] + 0x14c));
          *puVar15 = extraout_var;
          uVar5 = (*(code *)PTR_strlen_006aab30)(*(undefined4 *)(param_1[0x39] + 0x14c));
          puVar15[1] = uVar5;
          uVar7 = *(undefined4 *)(param_1[0x39] + 0x14c);
          uVar4 = (*(code *)PTR_strlen_006aab30)(uVar7);
          (*(code *)PTR_strncpy_006aaaec)(puVar15 + 2,uVar7,uVar4);
          iVar13 = (*(code *)PTR_strlen_006aab30)(*(undefined4 *)(param_1[0x39] + 0x14c));
          puVar15 = puVar15 + 2 + iVar13;
        }
        if (local_b0 != (int *)0x0) {
          if (*local_b0 == 6) {
            if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
              if (local_90 != 0) goto LAB_0047f604;
              goto LAB_0047fb90;
            }
            local_ac = 0;
            iVar13 = 2;
            puVar14 = auStack_50;
            do {
              (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_88,8);
              if (iVar13 == 2) {
                uVar4 = *(undefined4 *)(param_1[0x39] + 0x8c);
              }
              else {
                uVar4 = *(undefined4 *)(param_1[0x39] + 0x90);
              }
              iVar13 = iVar13 + -1;
              (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_88,uVar4,0);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_88,param_1[0x16] + 0xc0,0x20);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_88,param_1[0x16] + 0xa0,0x20);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_88,puVar3,iVar6);
              (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_88,puVar14,&local_8c);
              puVar14 = puVar14 + local_8c;
              local_ac = local_ac + local_8c;
            } while (iVar13 != 0);
            iVar13 = (*(code *)PTR_RSA_sign_006a8b64)
                               (0x72,auStack_50,local_ac,puVar15 + 2,&local_94,local_b0[5]);
            if (iVar13 < 1) {
              uVar7 = 4;
              uVar4 = 0x79c;
              goto LAB_0047fd28;
            }
            *puVar15 = (char)((uint)local_94 >> 8);
            puVar15[1] = (char)local_94;
            iVar6 = local_94 + 2 + iVar6;
            local_ac = iVar6 + 4;
          }
          else {
            if (local_90 == 0) {
LAB_0047fb90:
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9b,0xfb,"s3_srvr.c",0x7ca);
              uVar4 = 0x28;
              goto LAB_0047fbbc;
            }
            if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
LAB_0047f604:
              iVar13 = tls12_get_sigandhash(puVar15,local_b0,local_90);
              if (iVar13 == 0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9b,0x44,"s3_srvr.c",0x7ae);
                uVar4 = 0x50;
                goto LAB_0047fbbc;
              }
              puVar15 = puVar15 + 2;
            }
            (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_88,local_90,0);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_88,param_1[0x16] + 0xc0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_88,param_1[0x16] + 0xa0,0x20);
            (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_88,puVar3,iVar6);
            iVar13 = (*(code *)PTR_EVP_SignFinal_006a9094)
                               (auStack_88,puVar15 + 2,&local_8c,local_b0);
            if (iVar13 == 0) {
              uVar7 = 6;
              uVar4 = 0x7be;
              goto LAB_0047fd28;
            }
            *puVar15 = (char)((uint)local_8c >> 8);
            puVar15[1] = (char)local_8c;
            iVar6 = iVar6 + local_8c + 2;
            if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
              local_ac = iVar6 + 6;
              iVar6 = iVar6 + 2;
            }
            else {
              local_ac = iVar6 + 4;
            }
          }
        }
        puVar11[3] = (char)iVar6;
        puVar11[1] = (char)((uint)iVar6 >> 0x10);
        *puVar11 = 0xc;
        puVar11[2] = (char)((uint)iVar6 >> 8);
        param_1[0x12] = 0;
        param_1[0x11] = local_ac;
LAB_0047f3a4:
        puVar15 = PTR_EVP_MD_CTX_cleanup_006a7f34;
        param_1[0xd] = 0x2151;
        (*(code *)puVar15)(auStack_88);
        uVar4 = ssl3_do_write(param_1,0x16);
        goto LAB_0047f3d0;
      }
      uVar7 = 7;
      uVar4 = 0x747;
LAB_0047fd28:
      iVar8 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9b,uVar7,"s3_srvr.c",uVar4);
    }
LAB_0047fbd4:
    if (local_a4 == 0) goto LAB_0047fbf4;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(local_a4);
LAB_0047fbf4:
  while( true ) {
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar8);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_88);
    uVar4 = 0xffffffff;
LAB_0047f3d0:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0047ff0c:
    uVar7 = 0x2b;
    uVar4 = 0x6ad;
LAB_0047fc2c:
    iVar8 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9b,uVar7,"s3_srvr.c",uVar4);
  }
  return uVar4;
}

