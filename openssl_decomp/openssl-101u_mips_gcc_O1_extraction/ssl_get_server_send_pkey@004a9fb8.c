
int ssl_get_server_send_pkey(int param_1,undefined4 param_2,int *param_3)

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
  int iVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  ASN1_OBJECT *pAVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint unaff_s0;
  int iVar22;
  int iVar23;
  uint unaff_s1;
  uint uVar24;
  uint uVar25;
  uint unaff_s3;
  uint unaff_s4;
  uint uVar26;
  uint unaff_s6;
  int iVar27;
  uint unaff_s8;
  bool bVar28;
  int iStack_ac;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  uint uStack_98;
  uint uStack_94;
  int iStack_90;
  uint uStack_8c;
  uint uStack_88;
  undefined *puStack_84;
  uint uStack_80;
  int iStack_7c;
  uint uStack_78;
  code *pcStack_74;
  undefined4 local_60;
  undefined *local_58;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int *local_3c;
  int local_34;
  int local_30;
  int local_2c;
  
  puStack_84 = PTR___stack_chk_guard_006a9ae8;
  iVar13 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  local_58 = &_gp;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_7c = *(int *)(param_1 + 0x98);
  if (iStack_7c != 0) {
    iVar22 = 0x400;
    if ((*(uint *)(iVar13 + 0x20) & 8) != 0) {
      iVar22 = 0x200;
    }
    if (*(int *)(iStack_7c + 0x18) == 0) {
      uVar16 = (uint)(*(int *)(iStack_7c + 0x1c) != 0);
      local_44 = uVar16;
      if (*(int *)(iStack_7c + 0x20) == 0) goto LAB_004aa55c;
LAB_004aa058:
      if (*(int *)(iStack_7c + 0x24) == 0) {
        iVar13 = (**(code **)(local_58 + -0x6a98))();
        uVar26 = iVar22 < iVar13 << 3 ^ 1;
      }
      else {
        uVar26 = 1;
      }
      unaff_s6 = 1;
      if (*(int *)(iStack_7c + 0x28) != 0) goto LAB_004aa078;
LAB_004aa570:
      local_4c = (uint)(*(int *)(iStack_7c + 0x2c) != 0);
    }
    else {
      if (*(int *)(iStack_7c + 0x1c) == 0) {
        iVar13 = (*(code *)PTR_RSA_size_006a7640)();
        local_44 = iVar22 < iVar13 << 3 ^ 1;
      }
      else {
        local_44 = 1;
      }
      uVar16 = 1;
      if (*(int *)(iStack_7c + 0x20) != 0) goto LAB_004aa058;
LAB_004aa55c:
      uVar26 = (uint)(*(int *)(iStack_7c + 0x24) != 0);
      unaff_s6 = uVar26;
      if (*(int *)(iStack_7c + 0x28) == 0) goto LAB_004aa570;
LAB_004aa078:
      local_4c = 1;
    }
    if ((*(int *)(iStack_7c + 0x30) == 0) || (*(int *)(iStack_7c + 0x34) == 0)) {
      unaff_s3 = 0;
      bVar1 = false;
      if (*(int *)(iStack_7c + 0x3c) != 0) goto LAB_004aa0b8;
LAB_004aa520:
      local_48 = 0;
      if (*(int *)(iStack_7c + 0x48) == 0) goto LAB_004aa52c;
LAB_004aa0d0:
      local_50 = (uint)(*(int *)(iStack_7c + 0x4c) != 0);
    }
    else {
      unaff_s3 = 1;
      iVar13 = (**(code **)(local_58 + -0x78e8))();
      bVar1 = iVar13 << 3 <= iVar22;
      if (*(int *)(iStack_7c + 0x3c) == 0) goto LAB_004aa520;
LAB_004aa0b8:
      local_48 = (uint)(*(int *)(iStack_7c + 0x40) != 0);
      if (*(int *)(iStack_7c + 0x48) != 0) goto LAB_004aa0d0;
LAB_004aa52c:
      local_50 = 0;
    }
    param_3 = (int *)0x0;
    if ((*(int *)(iStack_7c + 0x54) == 0) || (*(int *)(iStack_7c + 0x58) == 0)) {
      uVar21 = 0;
    }
    else {
      iVar13 = (**(code **)(local_58 + -0x78e8))();
      param_3 = (int *)0x1;
      uVar21 = iVar22 < iVar13 << 3 ^ 1;
    }
    if ((*(int *)(iStack_7c + 0x60) == 0) || (*(int *)(iStack_7c + 100) == 0)) {
      uVar20 = *(uint *)(iStack_7c + 0x6c);
      bVar5 = false;
      bVar28 = false;
      if (uVar20 != 0) goto LAB_004aa158;
LAB_004aa4dc:
      bVar6 = false;
      if (*(int *)(iStack_7c + 0x84) == 0) goto LAB_004aa4e8;
LAB_004aa168:
      uVar19 = 0x100;
      if (*(int *)(iStack_7c + 0x88) != 0) {
        uVar19 = 0x300;
      }
      uVar18 = 0x200;
      if (*(int *)(iStack_7c + 0x88) == 0) {
        uVar18 = 0;
      }
      if (*(int *)(iStack_7c + 0x78) != 0) goto LAB_004aa18c;
LAB_004aa4f8:
      uVar19 = uVar18;
      if (unaff_s3 != 0) goto LAB_004aa1b0;
LAB_004aa1a0:
      if ((uVar16 != 0) && (local_48 != 0)) goto LAB_004aa1b0;
    }
    else {
      local_40 = uVar21;
      local_3c = param_3;
      iVar13 = (**(code **)(local_58 + -0x78e8))();
      bVar5 = true;
      uVar20 = *(uint *)(iStack_7c + 0x6c);
      bVar28 = iVar13 << 3 <= iVar22;
      param_3 = local_3c;
      uVar21 = local_40;
      if (uVar20 == 0) goto LAB_004aa4dc;
LAB_004aa158:
      bVar6 = *(int *)(iStack_7c + 0x70) != 0;
      if (*(int *)(iStack_7c + 0x84) != 0) goto LAB_004aa168;
LAB_004aa4e8:
      uVar19 = 0x100;
      uVar18 = 0;
      if (*(int *)(iStack_7c + 0x78) == 0) goto LAB_004aa4f8;
LAB_004aa18c:
      if (*(int *)(iStack_7c + 0x7c) == 0) {
        uVar19 = uVar18;
      }
      if (*(int *)(iStack_7c + 0x7c) != 0) {
        uVar18 = 0x200;
      }
      if (unaff_s3 == 0) goto LAB_004aa1a0;
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
      if (unaff_s3 == 0) goto LAB_004aa20c;
LAB_004aa320:
      uVar19 = uVar19 | 1;
      uVar16 = 5;
      uVar21 = 7;
      uVar26 = 3;
      unaff_s4 = 1;
      if (local_50 == 0) goto LAB_004aa338;
LAB_004aa22c:
      uVar24 = uVar19 | 6;
      uVar19 = uVar19 | 2;
      unaff_s4 = uVar26;
      uVar16 = uVar21;
    }
    else {
      unaff_s8 = 0;
      if ((local_44 != 0) && (unaff_s8 = 1, local_48 == 0)) {
        unaff_s8 = unaff_s3;
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
      if (unaff_s3 != 0) goto LAB_004aa320;
LAB_004aa20c:
      if (local_48 != 0) goto LAB_004aa320;
      uVar16 = 4;
      uVar21 = 6;
      uVar26 = 2;
      unaff_s4 = 0;
      if (local_50 != 0) goto LAB_004aa22c;
LAB_004aa338:
      uVar24 = uVar19 | 4;
    }
    if (bVar6) {
      param_3 = (int *)0x0;
      local_50 = uVar20;
      local_48 = uVar18;
      local_44 = uVar19;
      (**(code **)(local_58 + -0x76c4))(uVar20,0xffffffff);
      if ((*(uint *)(local_50 + 0x28) & 2) == 0) {
        unaff_s6 = 1;
        unaff_s3 = 1;
      }
      else {
        unaff_s6 = *(uint *)(local_50 + 0x2c) & 8;
        unaff_s3 = *(uint *)(local_50 + 0x2c) & 0x80;
      }
      iVar13 = (**(code **)(local_58 + -0x7ed8))(local_50);
      if (iVar13 == 0) {
        local_3c = (int *)0x0;
        uVar26 = local_48;
        local_48 = local_50;
      }
      else {
        local_40 = local_44;
        local_44 = local_48;
        local_48 = local_50;
        local_50 = iVar13;
        local_3c = (int *)(**(code **)(local_58 + -0x7dfc))(iVar13);
        iVar13 = local_50;
        uVar26 = local_44;
        local_44 = local_40;
      }
      local_50 = local_48;
      local_48 = uVar26;
      (**(code **)(local_58 + -0x7f68))(iVar13);
      uVar26 = local_48;
      uVar18 = local_48;
      uVar21 = local_44;
      if ((*(ASN1_OBJECT ***)(local_50 + 4) != (ASN1_OBJECT **)0x0) &&
         (pAVar17 = **(ASN1_OBJECT ***)(local_50 + 4), pAVar17 != (ASN1_OBJECT *)0x0)) {
        local_48 = local_44;
        local_50 = uVar26;
        iVar13 = OBJ_obj2nid(pAVar17);
        param_3 = &local_34;
        OBJ_find_sigid_algs(iVar13,&local_30,param_3);
        uVar18 = local_50;
        uVar21 = local_48;
      }
      if (unaff_s6 != 0) {
        if ((local_34 == 6) || (local_34 == 0x13)) {
          uVar18 = uVar18 | 0x20;
          uVar24 = uVar21 | 0x14;
          if ((int)local_3c < 0xa4) {
            unaff_s8 = unaff_s8 | 0x20;
            uVar16 = unaff_s4 | 0x14;
            goto LAB_004aa480;
          }
        }
        if (local_34 == 0x198) {
          uVar18 = uVar18 | 0x40;
          uVar24 = uVar24 | 0x10;
          if ((int)local_3c < 0xa4) {
            unaff_s8 = unaff_s8 | 0x40;
            uVar16 = uVar16 | 0x10;
          }
        }
      }
LAB_004aa480:
      if (unaff_s3 != 0) {
        uVar24 = uVar24 | 0x40;
        uVar16 = uVar16 | 0x40;
      }
    }
    if (local_4c != 0) {
      uVar18 = uVar18 | 0x80;
      unaff_s8 = unaff_s8 | 0x80;
    }
    iVar13 = *(int *)(param_1 + 0x58);
    unaff_s1 = uVar24 | 0x80;
    *(uint *)(iStack_7c + 8) = uVar18 | 0x100;
    unaff_s0 = uVar16 | 0x80;
    *(uint *)(iStack_7c + 0xc) = unaff_s1;
    *(uint *)(iStack_7c + 0x10) = unaff_s8 | 0x100;
    *(uint *)(iStack_7c + 0x14) = unaff_s0;
    *(undefined4 *)(iStack_7c + 4) = 1;
    iVar13 = *(int *)(iVar13 + 0x344);
  }
  uVar16 = *(uint *)(iVar13 + 0xc);
  if ((uVar16 & 0x60) == 0) {
    uVar26 = *(uint *)(iVar13 + 0x10);
    if ((uVar26 & 0x40) != 0) goto LAB_004aa2a0;
    if ((uVar16 & 2) != 0) {
      iVar13 = 0x24;
      goto LAB_004aa2a4;
    }
    if ((uVar16 & 4) != 0) {
      iVar13 = 0x30;
      goto LAB_004aa2a4;
    }
    if ((uVar26 & 2) != 0) {
      iVar13 = 0x18;
      goto LAB_004aa2a4;
    }
    if ((uVar26 & 1) != 0) {
      iVar13 = (uint)(*(int *)(iStack_7c + 0x30) == 0) * 0xc;
      goto LAB_004aa2a4;
    }
    if ((uVar26 & 0x20) == 0) {
      if ((uVar26 & 0x100) == 0) {
        iVar13 = 0x54;
        if ((uVar26 & 0x200) == 0) {
          param_3 = (int *)0x44;
          local_60 = 0x944;
          (**(code **)(local_58 + -0x6eac))(0x14,0x13d,0x44,"ssl_lib.c");
          iVar13 = 0;
          goto LAB_004aa2ac;
        }
      }
      else {
        iVar13 = 0x48;
      }
      goto LAB_004aa2a4;
    }
    iVar13 = 0;
  }
  else {
LAB_004aa2a0:
    iVar13 = 0x3c;
LAB_004aa2a4:
    iVar13 = iStack_7c + 0x30 + iVar13;
  }
LAB_004aa2ac:
  if (local_2c == *(int *)puStack_84) {
    return iVar13;
  }
  pcStack_74 = ssl_get_server_send_cert;
  iVar13 = local_2c;
  (**(code **)(local_58 + -0x5330))();
  puVar12 = PTR___stack_chk_guard_006a9ae8;
  iVar22 = *(int *)(*(int *)(iVar13 + 0x58) + 0x344);
  iStack_a4 = 0;
  iStack_a0 = 0;
  iStack_9c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar27 = *(int *)(iVar13 + 0x98);
  uStack_98 = unaff_s0;
  uStack_94 = unaff_s1;
  iStack_90 = param_1;
  uStack_8c = unaff_s3;
  uStack_88 = unaff_s4;
  uStack_80 = unaff_s6;
  uStack_78 = unaff_s8;
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
      uVar16 = 0;
      bVar2 = false;
      if (*(int *)(iVar27 + 0x3c) != 0) goto LAB_004aa778;
LAB_004aabec:
      bVar7 = false;
      if (*(int *)(iVar27 + 0x48) == 0) goto LAB_004aabf8;
LAB_004aa790:
      bVar8 = *(int *)(iVar27 + 0x4c) != 0;
    }
    else {
      uVar16 = 1;
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
      if (uVar16 != 0) goto LAB_004aa870;
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
      if (uVar16 == 0) goto LAB_004aa860;
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
      if (uVar16 == 0) goto LAB_004aa8cc;
LAB_004aa9ec:
      uVar26 = uVar26 | 1;
      uVar19 = 5;
      uVar24 = 7;
      uVar18 = 3;
      uVar16 = 1;
      if (!bVar8) goto LAB_004aaa04;
LAB_004aa8ec:
      uVar25 = uVar26 | 6;
      uVar26 = uVar26 | 2;
      uVar16 = uVar18;
      uVar19 = uVar24;
    }
    else {
      uVar20 = 0;
      if ((bVar1) && (uVar20 = 1, !bVar7)) {
        uVar20 = uVar16;
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
      if (uVar16 != 0) goto LAB_004aa9ec;
LAB_004aa8cc:
      if (bVar7) goto LAB_004aa9ec;
      uVar19 = 4;
      uVar24 = 6;
      uVar18 = 2;
      uVar16 = 0;
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
        iStack_ac = 0;
      }
      else {
        iStack_ac = (*(code *)PTR_EVP_PKEY_bits_006a6fe4)(iVar23);
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar23);
      if ((*(ASN1_OBJECT ***)(iVar22 + 4) != (ASN1_OBJECT **)0x0) &&
         (pAVar17 = **(ASN1_OBJECT ***)(iVar22 + 4), pAVar17 != (ASN1_OBJECT *)0x0)) {
        iVar22 = OBJ_obj2nid(pAVar17);
        param_3 = &iStack_a4;
        OBJ_find_sigid_algs(iVar22,&iStack_a0,param_3);
      }
      if (uVar24 != 0) {
        if ((iStack_a4 == 6) || (iStack_a4 == 0x13)) {
          uVar21 = uVar21 | 0x20;
          uVar25 = uVar26 | 0x14;
          if (iStack_ac < 0xa4) {
            uVar20 = uVar20 | 0x20;
            uVar19 = uVar16 | 0x14;
            goto LAB_004aab4c;
          }
        }
        if (iStack_a4 == 0x198) {
          uVar21 = uVar21 | 0x40;
          uVar25 = uVar25 | 0x10;
          if (iStack_ac < 0xa4) {
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
    iVar13 = *(int *)(iVar13 + 0x58);
    *(uint *)(iVar27 + 8) = uVar21 | 0x100;
    *(uint *)(iVar27 + 0xc) = uVar25 | 0x80;
    *(uint *)(iVar27 + 0x10) = uVar20 | 0x100;
    *(uint *)(iVar27 + 0x14) = uVar19 | 0x80;
    *(undefined4 *)(iVar27 + 4) = 1;
    iVar22 = *(int *)(iVar13 + 0x344);
  }
  uVar16 = *(uint *)(iVar22 + 0xc);
  uVar26 = uVar16 & 0x60;
  if (uVar26 == 0) {
    uVar21 = *(uint *)(iVar22 + 0x10);
    uVar26 = uVar16 & 2;
    if ((uVar21 & 0x40) != 0) goto LAB_004aa960;
    if (uVar26 != 0) {
      iVar13 = 0x24;
      goto LAB_004aa964;
    }
    if ((uVar16 & 4) != 0) {
      iVar13 = 0x30;
      goto LAB_004aa964;
    }
    if ((uVar21 & 2) != 0) {
      iVar13 = 0x18;
      goto LAB_004aa964;
    }
    if ((uVar21 & 1) != 0) {
      iVar13 = (uint)(*(int *)(iVar27 + 0x30) == 0) * 0xc;
      goto LAB_004aa964;
    }
    if ((uVar21 & 0x20) == 0) {
      if ((uVar21 & 0x100) == 0) {
        iVar13 = 0x54;
        if ((uVar21 & 0x200) == 0) {
          param_3 = (int *)0x44;
          uVar26 = 0x13d;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13d,0x44,"ssl_lib.c",0x944);
          goto LAB_004aad20;
        }
      }
      else {
        iVar13 = 0x48;
      }
      goto LAB_004aa964;
    }
LAB_004aad20:
    iVar13 = 0;
  }
  else {
LAB_004aa960:
    iVar13 = 0x3c;
LAB_004aa964:
    piVar15 = (int *)(iVar27 + 0x30 + iVar13);
    iVar13 = 0;
    if (piVar15 != (int *)0x0) {
      iVar13 = *piVar15;
    }
  }
  if (iStack_9c == *(int *)puVar12) {
    return iVar13;
  }
  iVar13 = iStack_9c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar16 = *(uint *)(uVar26 + 0x10);
  iVar13 = *(int *)(iVar13 + 0x98);
  if (((uVar16 & 2) == 0) || (iVar22 = *(int *)(iVar13 + 0x4c), iVar22 == 0)) {
    if ((uVar16 & 1) == 0) {
      if ((uVar16 & 0x40) != 0) {
        iVar22 = *(int *)(iVar13 + 0x70);
        iVar27 = 5;
        if (iVar22 != 0) goto LAB_004aad70;
      }
LAB_004aaddc:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb7,0x44,"ssl_lib.c",0x96a);
      return 0;
    }
    iVar22 = *(int *)(iVar13 + 0x40);
    iVar27 = 1;
    if (iVar22 == 0) {
      iVar22 = *(int *)(iVar13 + 0x34);
      iVar27 = 0;
      if (iVar22 == 0) goto LAB_004aaddc;
    }
  }
  else {
    iVar27 = 2;
  }
LAB_004aad70:
  if (param_3 != (int *)0x0) {
    iVar13 = iVar13 + iVar27 * 0xc;
    *param_3 = *(int *)(iVar13 + 0x38);
    iVar22 = *(int *)(iVar13 + 0x34);
  }
  return iVar22;
}

