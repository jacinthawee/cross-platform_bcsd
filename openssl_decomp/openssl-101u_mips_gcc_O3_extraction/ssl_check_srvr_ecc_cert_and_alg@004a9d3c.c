
int ssl_check_srvr_ecc_cert_and_alg(uint param_1,int *param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  ASN1_OBJECT *pAVar16;
  int *piVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint unaff_s5;
  uint unaff_s6;
  int iVar27;
  uint unaff_s8;
  bool bVar28;
  int iStack_fc;
  int iStack_f4;
  int iStack_f0;
  int iStack_ec;
  uint uStack_e8;
  undefined *puStack_e4;
  int iStack_e0;
  uint uStack_dc;
  int *piStack_d8;
  undefined *puStack_d4;
  uint uStack_d0;
  int iStack_cc;
  uint uStack_c8;
  code *pcStack_c4;
  undefined4 uStack_b0;
  undefined *puStack_a8;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  uint uStack_90;
  int *piStack_8c;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  uint uStack_78;
  undefined *puStack_74;
  uint uStack_70;
  uint uStack_6c;
  int *piStack_68;
  uint uStack_64;
  int local_2c;
  int local_28;
  int local_24;
  
  puStack_e4 = PTR___stack_chk_guard_006a9ae8;
  iVar15 = *(int *)(param_2[0x16] + 0x344);
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_dc = *(uint *)(iVar15 + 0xc);
  uStack_70 = *(uint *)(iVar15 + 0x10);
  local_2c = 0;
  local_28 = 0;
  if ((*(uint *)(iVar15 + 0x20) & 2) == 0) {
LAB_004a9dec:
    param_3 = (int *)0x0;
    (*(code *)PTR_X509_check_purpose_006a771c)(param_1,0xffffffff);
    if ((*(ASN1_OBJECT ***)(param_1 + 4) != (ASN1_OBJECT **)0x0) &&
       (pAVar16 = **(ASN1_OBJECT ***)(param_1 + 4), pAVar16 != (ASN1_OBJECT *)0x0)) {
      iVar15 = OBJ_obj2nid(pAVar16);
      param_3 = &local_28;
      OBJ_find_sigid_algs(iVar15,&local_2c,param_3);
    }
    if ((uStack_dc & 0x60) != 0) {
      if (((*(uint *)(param_1 + 0x28) & 2) == 0) || ((*(uint *)(param_1 + 0x2c) & 8) != 0)) {
        if ((uStack_dc & 0x40) != 0) {
          if ((*param_2 >> 8 == 3) && (0x302 < *param_2)) goto LAB_004a9ef0;
          if (local_28 != 0x198) {
            param_3 = (int *)0x143;
            goto LAB_004a9e9c;
          }
        }
        uStack_dc = uStack_dc & 0x20;
        if ((uStack_dc == 0) ||
           ((((*param_2 >> 8 == 3 && (0x302 < *param_2)) || (local_28 == 6)) || (local_28 == 0x13)))
           ) goto LAB_004a9ef0;
        param_3 = (int *)0x142;
      }
      else {
        param_3 = (int *)&DAT_0000013d;
      }
LAB_004a9e9c:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x117,param_3,"ssl_lib.c");
      goto LAB_004a9eb0;
    }
LAB_004a9ef0:
    uStack_70 = uStack_70 & 0x40;
    iVar15 = 1;
    if ((uStack_70 != 0) && (iVar15 = 1, (*(uint *)(param_1 + 0x28) & 2) != 0)) {
      if ((*(uint *)(param_1 + 0x2c) & 0x80) == 0) {
        param_3 = (int *)0x13e;
        goto LAB_004a9e9c;
      }
      iVar15 = 1;
    }
  }
  else {
    uVar13 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
    unaff_s5 = uVar13;
    if (uVar13 != 0) {
      iVar15 = (*(code *)PTR_EVP_PKEY_bits_006a6fe4)(uVar13);
      unaff_s5 = (uint)(iVar15 < 0xa4);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(uVar13);
      if (unaff_s5 != 0) goto LAB_004a9dec;
    }
LAB_004a9eb0:
    iVar15 = 0;
  }
  if (local_24 == *(int *)puStack_e4) {
    return iVar15;
  }
  iStack_e0 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_d4 = PTR___stack_chk_guard_006a9ae8;
  iVar15 = *(int *)(*(int *)(iStack_e0 + 0x58) + 0x344);
  puStack_74 = puStack_e4;
  puStack_a8 = &_gp;
  iStack_84 = 0;
  iStack_80 = 0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_cc = *(int *)(iStack_e0 + 0x98);
  uStack_78 = param_1;
  uStack_6c = uStack_dc;
  piStack_68 = param_2;
  uStack_64 = unaff_s5;
  if (iStack_cc != 0) {
    iVar22 = 0x400;
    if ((*(uint *)(iVar15 + 0x20) & 8) != 0) {
      iVar22 = 0x200;
    }
    if (*(int *)(iStack_cc + 0x18) == 0) {
      uVar13 = (uint)(*(int *)(iStack_cc + 0x1c) != 0);
      uStack_94 = uVar13;
      if (*(int *)(iStack_cc + 0x20) == 0) goto LAB_004aa55c;
LAB_004aa058:
      if (*(int *)(iStack_cc + 0x24) == 0) {
        iVar15 = (**(code **)(puStack_a8 + -0x6a98))();
        uVar26 = iVar22 < iVar15 << 3 ^ 1;
      }
      else {
        uVar26 = 1;
      }
      unaff_s6 = 1;
      if (*(int *)(iStack_cc + 0x28) != 0) goto LAB_004aa078;
LAB_004aa570:
      uStack_9c = (uint)(*(int *)(iStack_cc + 0x2c) != 0);
    }
    else {
      if (*(int *)(iStack_cc + 0x1c) == 0) {
        iVar15 = (*(code *)PTR_RSA_size_006a7640)();
        uStack_94 = iVar22 < iVar15 << 3 ^ 1;
      }
      else {
        uStack_94 = 1;
      }
      uVar13 = 1;
      if (*(int *)(iStack_cc + 0x20) != 0) goto LAB_004aa058;
LAB_004aa55c:
      uVar26 = (uint)(*(int *)(iStack_cc + 0x24) != 0);
      unaff_s6 = uVar26;
      if (*(int *)(iStack_cc + 0x28) == 0) goto LAB_004aa570;
LAB_004aa078:
      uStack_9c = 1;
    }
    if ((*(int *)(iStack_cc + 0x30) == 0) || (*(int *)(iStack_cc + 0x34) == 0)) {
      uStack_dc = 0;
      bVar1 = false;
      if (*(int *)(iStack_cc + 0x3c) != 0) goto LAB_004aa0b8;
LAB_004aa520:
      uStack_98 = 0;
      if (*(int *)(iStack_cc + 0x48) == 0) goto LAB_004aa52c;
LAB_004aa0d0:
      uStack_a0 = (uint)(*(int *)(iStack_cc + 0x4c) != 0);
    }
    else {
      uStack_dc = 1;
      iVar15 = (**(code **)(puStack_a8 + -0x78e8))();
      bVar1 = iVar15 << 3 <= iVar22;
      if (*(int *)(iStack_cc + 0x3c) == 0) goto LAB_004aa520;
LAB_004aa0b8:
      uStack_98 = (uint)(*(int *)(iStack_cc + 0x40) != 0);
      if (*(int *)(iStack_cc + 0x48) != 0) goto LAB_004aa0d0;
LAB_004aa52c:
      uStack_a0 = 0;
    }
    param_3 = (int *)0x0;
    if ((*(int *)(iStack_cc + 0x54) == 0) || (*(int *)(iStack_cc + 0x58) == 0)) {
      uVar21 = 0;
    }
    else {
      iVar15 = (**(code **)(puStack_a8 + -0x78e8))();
      param_3 = (int *)0x1;
      uVar21 = iVar22 < iVar15 << 3 ^ 1;
    }
    if ((*(int *)(iStack_cc + 0x60) == 0) || (*(int *)(iStack_cc + 100) == 0)) {
      uVar20 = *(uint *)(iStack_cc + 0x6c);
      bVar5 = false;
      bVar28 = false;
      if (uVar20 != 0) goto LAB_004aa158;
LAB_004aa4dc:
      bVar6 = false;
      if (*(int *)(iStack_cc + 0x84) == 0) goto LAB_004aa4e8;
LAB_004aa168:
      uVar19 = 0x100;
      if (*(int *)(iStack_cc + 0x88) != 0) {
        uVar19 = 0x300;
      }
      uVar18 = 0x200;
      if (*(int *)(iStack_cc + 0x88) == 0) {
        uVar18 = 0;
      }
      if (*(int *)(iStack_cc + 0x78) != 0) goto LAB_004aa18c;
LAB_004aa4f8:
      uVar19 = uVar18;
      if (uStack_dc != 0) goto LAB_004aa1b0;
LAB_004aa1a0:
      if ((uVar13 != 0) && (uStack_98 != 0)) goto LAB_004aa1b0;
    }
    else {
      uStack_90 = uVar21;
      piStack_8c = param_3;
      iVar15 = (**(code **)(puStack_a8 + -0x78e8))();
      bVar5 = true;
      uVar20 = *(uint *)(iStack_cc + 0x6c);
      bVar28 = iVar15 << 3 <= iVar22;
      param_3 = piStack_8c;
      uVar21 = uStack_90;
      if (uVar20 == 0) goto LAB_004aa4dc;
LAB_004aa158:
      bVar6 = *(int *)(iStack_cc + 0x70) != 0;
      if (*(int *)(iStack_cc + 0x84) != 0) goto LAB_004aa168;
LAB_004aa4e8:
      uVar19 = 0x100;
      uVar18 = 0;
      if (*(int *)(iStack_cc + 0x78) == 0) goto LAB_004aa4f8;
LAB_004aa18c:
      if (*(int *)(iStack_cc + 0x7c) == 0) {
        uVar19 = uVar18;
      }
      if (*(int *)(iStack_cc + 0x7c) != 0) {
        uVar18 = 0x200;
      }
      if (uStack_dc == 0) goto LAB_004aa1a0;
LAB_004aa1b0:
      uVar18 = uVar18 | 1;
    }
    if (bVar1) {
      if (unaff_s6 != 0) {
        uVar18 = uVar18 | 8;
      }
      unaff_s8 = 1;
      if (uVar26 != 0) {
        unaff_s8 = 9;
      }
      if (uVar21 != 0) {
        unaff_s8 = unaff_s8 | 2;
      }
      if (param_3 != (int *)0x0) {
        uVar18 = uVar18 | 2;
      }
      if (bVar28) {
        unaff_s8 = unaff_s8 | 4;
      }
      if (bVar5) {
        uVar18 = uVar18 | 4;
      }
      if (uStack_dc == 0) goto LAB_004aa20c;
LAB_004aa320:
      uVar19 = uVar19 | 1;
      param_1 = 5;
      uVar13 = 7;
      piVar17 = (int *)0x3;
      param_2 = (int *)0x1;
      if (uStack_a0 == 0) goto LAB_004aa338;
LAB_004aa22c:
      uVar26 = uVar19 | 6;
      uVar19 = uVar19 | 2;
      param_2 = piVar17;
      param_1 = uVar13;
    }
    else {
      unaff_s8 = 0;
      if ((uStack_94 != 0) && (unaff_s8 = 1, uStack_98 == 0)) {
        unaff_s8 = uStack_dc;
      }
      if (uVar26 != 0) {
        unaff_s8 = unaff_s8 | 8;
      }
      if (unaff_s6 != 0) {
        uVar18 = uVar18 | 8;
      }
      if (uVar21 != 0) {
        unaff_s8 = unaff_s8 | 2;
      }
      if (param_3 != (int *)0x0) {
        uVar18 = uVar18 | 2;
      }
      if (bVar28) {
        unaff_s8 = unaff_s8 | 4;
      }
      if (bVar5) {
        uVar18 = uVar18 | 4;
      }
      if (uStack_dc != 0) goto LAB_004aa320;
LAB_004aa20c:
      if (uStack_98 != 0) goto LAB_004aa320;
      param_1 = 4;
      uVar13 = 6;
      piVar17 = (int *)&SUB_00000002;
      param_2 = (int *)0x0;
      if (uStack_a0 != 0) goto LAB_004aa22c;
LAB_004aa338:
      uVar26 = uVar19 | 4;
    }
    if (bVar6) {
      param_3 = (int *)0x0;
      uStack_a0 = uVar20;
      uStack_98 = uVar18;
      uStack_94 = uVar19;
      (**(code **)(puStack_a8 + -0x76c4))(uVar20,0xffffffff);
      if ((*(uint *)(uStack_a0 + 0x28) & 2) == 0) {
        unaff_s6 = 1;
        uStack_dc = 1;
      }
      else {
        unaff_s6 = *(uint *)(uStack_a0 + 0x2c) & 8;
        uStack_dc = *(uint *)(uStack_a0 + 0x2c) & 0x80;
      }
      iVar15 = (**(code **)(puStack_a8 + -0x7ed8))(uStack_a0);
      if (iVar15 == 0) {
        piStack_8c = (int *)0x0;
        uVar13 = uStack_98;
        uStack_98 = uStack_a0;
      }
      else {
        uStack_90 = uStack_94;
        uStack_94 = uStack_98;
        uStack_98 = uStack_a0;
        uStack_a0 = iVar15;
        piStack_8c = (int *)(**(code **)(puStack_a8 + -0x7dfc))(iVar15);
        iVar15 = uStack_a0;
        uVar13 = uStack_94;
        uStack_94 = uStack_90;
      }
      uStack_a0 = uStack_98;
      uStack_98 = uVar13;
      (**(code **)(puStack_a8 + -0x7f68))(iVar15);
      uVar13 = uStack_98;
      uVar18 = uStack_98;
      uVar21 = uStack_94;
      if ((*(ASN1_OBJECT ***)(uStack_a0 + 4) != (ASN1_OBJECT **)0x0) &&
         (pAVar16 = **(ASN1_OBJECT ***)(uStack_a0 + 4), pAVar16 != (ASN1_OBJECT *)0x0)) {
        uStack_98 = uStack_94;
        uStack_a0 = uVar13;
        iVar15 = OBJ_obj2nid(pAVar16);
        param_3 = &iStack_84;
        OBJ_find_sigid_algs(iVar15,&iStack_80,param_3);
        uVar18 = uStack_a0;
        uVar21 = uStack_98;
      }
      if (unaff_s6 != 0) {
        if ((iStack_84 == 6) || (iStack_84 == 0x13)) {
          uVar18 = uVar18 | 0x20;
          uVar26 = uVar21 | 0x14;
          if ((int)piStack_8c < 0xa4) {
            unaff_s8 = unaff_s8 | 0x20;
            param_1 = (uint)param_2 | 0x14;
            goto LAB_004aa480;
          }
        }
        if (iStack_84 == 0x198) {
          uVar18 = uVar18 | 0x40;
          uVar26 = uVar26 | 0x10;
          if ((int)piStack_8c < 0xa4) {
            unaff_s8 = unaff_s8 | 0x40;
            param_1 = param_1 | 0x10;
          }
        }
      }
LAB_004aa480:
      if (uStack_dc != 0) {
        uVar26 = uVar26 | 0x40;
        param_1 = param_1 | 0x40;
      }
    }
    if (uStack_9c != 0) {
      uVar18 = uVar18 | 0x80;
      unaff_s8 = unaff_s8 | 0x80;
    }
    iVar15 = *(int *)(iStack_e0 + 0x58);
    puStack_e4 = (undefined *)(uVar26 | 0x80);
    *(uint *)(iStack_cc + 8) = uVar18 | 0x100;
    param_1 = param_1 | 0x80;
    *(undefined **)(iStack_cc + 0xc) = puStack_e4;
    *(uint *)(iStack_cc + 0x10) = unaff_s8 | 0x100;
    *(uint *)(iStack_cc + 0x14) = param_1;
    *(undefined4 *)(iStack_cc + 4) = 1;
    iVar15 = *(int *)(iVar15 + 0x344);
  }
  uVar13 = *(uint *)(iVar15 + 0xc);
  if ((uVar13 & 0x60) == 0) {
    uVar26 = *(uint *)(iVar15 + 0x10);
    if ((uVar26 & 0x40) != 0) goto LAB_004aa2a0;
    if ((uVar13 & 2) != 0) {
      iVar15 = 0x24;
      goto LAB_004aa2a4;
    }
    if ((uVar13 & 4) != 0) {
      iVar15 = 0x30;
      goto LAB_004aa2a4;
    }
    if ((uVar26 & 2) != 0) {
      iVar15 = 0x18;
      goto LAB_004aa2a4;
    }
    if ((uVar26 & 1) != 0) {
      iVar15 = (uint)(*(int *)(iStack_cc + 0x30) == 0) * 0xc;
      goto LAB_004aa2a4;
    }
    if ((uVar26 & 0x20) == 0) {
      if ((uVar26 & 0x100) == 0) {
        iVar15 = 0x54;
        if ((uVar26 & 0x200) == 0) {
          param_3 = (int *)0x44;
          uStack_b0 = 0x944;
          (**(code **)(puStack_a8 + -0x6eac))(0x14,0x13d,0x44,"ssl_lib.c");
          iVar15 = 0;
          goto LAB_004aa2ac;
        }
      }
      else {
        iVar15 = 0x48;
      }
      goto LAB_004aa2a4;
    }
    iVar15 = 0;
  }
  else {
LAB_004aa2a0:
    iVar15 = 0x3c;
LAB_004aa2a4:
    iVar15 = iStack_cc + 0x30 + iVar15;
  }
LAB_004aa2ac:
  if (iStack_7c == *(int *)puStack_d4) {
    return iVar15;
  }
  pcStack_c4 = ssl_get_server_send_cert;
  iVar15 = iStack_7c;
  (**(code **)(puStack_a8 + -0x5330))();
  puVar12 = PTR___stack_chk_guard_006a9ae8;
  iVar22 = *(int *)(*(int *)(iVar15 + 0x58) + 0x344);
  iStack_f4 = 0;
  iStack_f0 = 0;
  iStack_ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar27 = *(int *)(iVar15 + 0x98);
  uStack_e8 = param_1;
  piStack_d8 = param_2;
  uStack_d0 = unaff_s6;
  uStack_c8 = unaff_s8;
  if (iVar27 != 0) {
    iVar23 = 0x400;
    if ((*(uint *)(iVar22 + 0x20) & 8) != 0) {
      iVar23 = 0x200;
    }
    if (*(int *)(iVar27 + 0x18) == 0) {
      bVar28 = *(int *)(iVar27 + 0x1c) != 0;
      bVar1 = bVar28;
      if (*(int *)(iVar27 + 0x20) == 0) goto LAB_004aac28;
LAB_004aa718:
      if (*(int *)(iVar27 + 0x24) == 0) {
        iVar22 = (*(code *)PTR_DH_size_006a8348)();
        bVar5 = iVar22 << 3 <= iVar23;
      }
      else {
        bVar5 = true;
      }
      bVar6 = true;
      if (*(int *)(iVar27 + 0x28) != 0) goto LAB_004aa738;
LAB_004aac3c:
      bVar10 = *(int *)(iVar27 + 0x2c) != 0;
    }
    else {
      if (*(int *)(iVar27 + 0x1c) == 0) {
        iVar22 = (*(code *)PTR_RSA_size_006a7640)();
        bVar1 = iVar22 << 3 <= iVar23;
      }
      else {
        bVar1 = true;
      }
      bVar28 = true;
      if (*(int *)(iVar27 + 0x20) != 0) goto LAB_004aa718;
LAB_004aac28:
      bVar5 = *(int *)(iVar27 + 0x24) != 0;
      bVar6 = bVar5;
      if (*(int *)(iVar27 + 0x28) == 0) goto LAB_004aac3c;
LAB_004aa738:
      bVar10 = true;
    }
    if ((*(int *)(iVar27 + 0x30) == 0) || (*(int *)(iVar27 + 0x34) == 0)) {
      uVar13 = 0;
      bVar2 = false;
      if (*(int *)(iVar27 + 0x3c) != 0) goto LAB_004aa778;
LAB_004aabec:
      bVar7 = false;
      if (*(int *)(iVar27 + 0x48) == 0) goto LAB_004aabf8;
LAB_004aa790:
      bVar8 = *(int *)(iVar27 + 0x4c) != 0;
    }
    else {
      uVar13 = 1;
      iVar22 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      bVar2 = iVar22 << 3 <= iVar23;
      if (*(int *)(iVar27 + 0x3c) == 0) goto LAB_004aabec;
LAB_004aa778:
      bVar7 = *(int *)(iVar27 + 0x40) != 0;
      if (*(int *)(iVar27 + 0x48) != 0) goto LAB_004aa790;
LAB_004aabf8:
      bVar8 = false;
    }
    param_3 = (int *)0x0;
    if ((*(int *)(iVar27 + 0x54) == 0) || (*(int *)(iVar27 + 0x58) == 0)) {
      bVar3 = false;
    }
    else {
      iVar22 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      param_3 = (int *)0x1;
      bVar3 = iVar22 << 3 <= iVar23;
    }
    if ((*(int *)(iVar27 + 0x60) == 0) || (*(int *)(iVar27 + 100) == 0)) {
      iVar22 = *(int *)(iVar27 + 0x6c);
      bVar11 = false;
      bVar4 = false;
      if (iVar22 != 0) goto LAB_004aa818;
LAB_004aaba8:
      bVar9 = false;
      if (*(int *)(iVar27 + 0x84) == 0) goto LAB_004aabb4;
LAB_004aa828:
      uVar26 = 0x100;
      if (*(int *)(iVar27 + 0x88) != 0) {
        uVar26 = 0x300;
      }
      uVar21 = 0x200;
      if (*(int *)(iVar27 + 0x88) == 0) {
        uVar21 = 0;
      }
      if (*(int *)(iVar27 + 0x78) != 0) goto LAB_004aa84c;
LAB_004aabc4:
      uVar26 = uVar21;
      if (uVar13 != 0) goto LAB_004aa870;
LAB_004aa860:
      if ((bVar28) && (bVar7)) goto LAB_004aa870;
    }
    else {
      iVar14 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      bVar11 = true;
      iVar22 = *(int *)(iVar27 + 0x6c);
      bVar4 = iVar14 << 3 <= iVar23;
      if (iVar22 == 0) goto LAB_004aaba8;
LAB_004aa818:
      bVar9 = *(int *)(iVar27 + 0x70) != 0;
      if (*(int *)(iVar27 + 0x84) != 0) goto LAB_004aa828;
LAB_004aabb4:
      uVar26 = 0x100;
      uVar21 = 0;
      if (*(int *)(iVar27 + 0x78) == 0) goto LAB_004aabc4;
LAB_004aa84c:
      if (*(int *)(iVar27 + 0x7c) == 0) {
        uVar26 = uVar21;
      }
      if (*(int *)(iVar27 + 0x7c) != 0) {
        uVar21 = 0x200;
      }
      if (uVar13 == 0) goto LAB_004aa860;
LAB_004aa870:
      uVar21 = uVar21 | 1;
    }
    if (bVar2) {
      if (bVar6) {
        uVar21 = uVar21 | 8;
      }
      uVar20 = 1;
      if (bVar5) {
        uVar20 = 9;
      }
      if (bVar3) {
        uVar20 = uVar20 | 2;
      }
      if (param_3 != (int *)0x0) {
        uVar21 = uVar21 | 2;
      }
      if (bVar4) {
        uVar20 = uVar20 | 4;
      }
      if (bVar11) {
        uVar21 = uVar21 | 4;
      }
      if (uVar13 == 0) goto LAB_004aa8cc;
LAB_004aa9ec:
      uVar26 = uVar26 | 1;
      uVar19 = 5;
      uVar24 = 7;
      uVar18 = 3;
      uVar13 = 1;
      if (!bVar8) goto LAB_004aaa04;
LAB_004aa8ec:
      uVar25 = uVar26 | 6;
      uVar26 = uVar26 | 2;
      uVar13 = uVar18;
      uVar19 = uVar24;
    }
    else {
      uVar20 = 0;
      if ((bVar1) && (uVar20 = 1, !bVar7)) {
        uVar20 = uVar13;
      }
      if (bVar5) {
        uVar20 = uVar20 | 8;
      }
      if (bVar6) {
        uVar21 = uVar21 | 8;
      }
      if (bVar3) {
        uVar20 = uVar20 | 2;
      }
      if (param_3 != (int *)0x0) {
        uVar21 = uVar21 | 2;
      }
      if (bVar4) {
        uVar20 = uVar20 | 4;
      }
      if (bVar11) {
        uVar21 = uVar21 | 4;
      }
      if (uVar13 != 0) goto LAB_004aa9ec;
LAB_004aa8cc:
      if (bVar7) goto LAB_004aa9ec;
      uVar19 = 4;
      uVar24 = 6;
      uVar18 = 2;
      uVar13 = 0;
      if (bVar8) goto LAB_004aa8ec;
LAB_004aaa04:
      uVar25 = uVar26 | 4;
    }
    if (bVar9) {
      param_3 = (int *)0x0;
      (*(code *)PTR_X509_check_purpose_006a771c)(iVar22,0xffffffff);
      if ((*(uint *)(iVar22 + 0x28) & 2) == 0) {
        uVar24 = 1;
        uVar18 = 1;
      }
      else {
        uVar24 = *(uint *)(iVar22 + 0x2c) & 8;
        uVar18 = *(uint *)(iVar22 + 0x2c) & 0x80;
      }
      iVar23 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar22);
      if (iVar23 == 0) {
        iStack_fc = 0;
      }
      else {
        iStack_fc = (*(code *)PTR_EVP_PKEY_bits_006a6fe4)(iVar23);
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar23);
      if ((*(ASN1_OBJECT ***)(iVar22 + 4) != (ASN1_OBJECT **)0x0) &&
         (pAVar16 = **(ASN1_OBJECT ***)(iVar22 + 4), pAVar16 != (ASN1_OBJECT *)0x0)) {
        iVar22 = OBJ_obj2nid(pAVar16);
        param_3 = &iStack_f4;
        OBJ_find_sigid_algs(iVar22,&iStack_f0,param_3);
      }
      if (uVar24 != 0) {
        if ((iStack_f4 == 6) || (iStack_f4 == 0x13)) {
          uVar21 = uVar21 | 0x20;
          uVar25 = uVar26 | 0x14;
          if (iStack_fc < 0xa4) {
            uVar20 = uVar20 | 0x20;
            uVar19 = uVar13 | 0x14;
            goto LAB_004aab4c;
          }
        }
        if (iStack_f4 == 0x198) {
          uVar21 = uVar21 | 0x40;
          uVar25 = uVar25 | 0x10;
          if (iStack_fc < 0xa4) {
            uVar20 = uVar20 | 0x40;
            uVar19 = uVar19 | 0x10;
          }
        }
      }
LAB_004aab4c:
      if (uVar18 != 0) {
        uVar25 = uVar25 | 0x40;
        uVar19 = uVar19 | 0x40;
      }
    }
    if (bVar10) {
      uVar21 = uVar21 | 0x80;
      uVar20 = uVar20 | 0x80;
    }
    iVar15 = *(int *)(iVar15 + 0x58);
    *(uint *)(iVar27 + 8) = uVar21 | 0x100;
    *(uint *)(iVar27 + 0xc) = uVar25 | 0x80;
    *(uint *)(iVar27 + 0x10) = uVar20 | 0x100;
    *(uint *)(iVar27 + 0x14) = uVar19 | 0x80;
    *(undefined4 *)(iVar27 + 4) = 1;
    iVar22 = *(int *)(iVar15 + 0x344);
  }
  uVar13 = *(uint *)(iVar22 + 0xc);
  uVar26 = uVar13 & 0x60;
  if (uVar26 == 0) {
    uVar21 = *(uint *)(iVar22 + 0x10);
    uVar26 = uVar13 & 2;
    if ((uVar21 & 0x40) != 0) goto LAB_004aa960;
    if (uVar26 != 0) {
      iVar15 = 0x24;
      goto LAB_004aa964;
    }
    if ((uVar13 & 4) != 0) {
      iVar15 = 0x30;
      goto LAB_004aa964;
    }
    if ((uVar21 & 2) != 0) {
      iVar15 = 0x18;
      goto LAB_004aa964;
    }
    if ((uVar21 & 1) != 0) {
      iVar15 = (uint)(*(int *)(iVar27 + 0x30) == 0) * 0xc;
      goto LAB_004aa964;
    }
    if ((uVar21 & 0x20) == 0) {
      if ((uVar21 & 0x100) == 0) {
        iVar15 = 0x54;
        if ((uVar21 & 0x200) == 0) {
          param_3 = (int *)0x44;
          uVar26 = 0x13d;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13d,0x44,"ssl_lib.c",0x944);
          goto LAB_004aad20;
        }
      }
      else {
        iVar15 = 0x48;
      }
      goto LAB_004aa964;
    }
LAB_004aad20:
    iVar15 = 0;
  }
  else {
LAB_004aa960:
    iVar15 = 0x3c;
LAB_004aa964:
    piVar17 = (int *)(iVar27 + 0x30 + iVar15);
    iVar15 = 0;
    if (piVar17 != (int *)0x0) {
      iVar15 = *piVar17;
    }
  }
  if (iStack_ec == *(int *)puVar12) {
    return iVar15;
  }
  iVar15 = iStack_ec;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar13 = *(uint *)(uVar26 + 0x10);
  iVar15 = *(int *)(iVar15 + 0x98);
  if (((uVar13 & 2) == 0) || (iVar22 = *(int *)(iVar15 + 0x4c), iVar22 == 0)) {
    if ((uVar13 & 1) == 0) {
      if ((uVar13 & 0x40) != 0) {
        iVar22 = *(int *)(iVar15 + 0x70);
        iVar27 = 5;
        if (iVar22 != 0) goto LAB_004aad70;
      }
LAB_004aaddc:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb7,0x44,"ssl_lib.c",0x96a);
      return 0;
    }
    iVar22 = *(int *)(iVar15 + 0x40);
    iVar27 = 1;
    if (iVar22 == 0) {
      iVar22 = *(int *)(iVar15 + 0x34);
      iVar27 = 0;
      if (iVar22 == 0) goto LAB_004aaddc;
    }
  }
  else {
    iVar27 = 2;
  }
LAB_004aad70:
  if (param_3 != (int *)0x0) {
    iVar15 = iVar15 + iVar27 * 0xc;
    *param_3 = *(int *)(iVar15 + 0x38);
    iVar22 = *(int *)(iVar15 + 0x34);
  }
  return iVar22;
}
