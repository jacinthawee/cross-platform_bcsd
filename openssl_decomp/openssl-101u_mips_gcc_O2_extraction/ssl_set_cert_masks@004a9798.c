
char ** ssl_set_cert_masks(ASN1_OBJECT *param_1,ASN1_OBJECT *param_2,int *param_3)

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
  char **ppcVar14;
  int iVar15;
  int *piVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint unaff_s0;
  int iVar21;
  ASN1_OBJECT *pAVar22;
  int iVar23;
  uint uVar24;
  uint unaff_s1;
  uint uVar25;
  uint unaff_s2;
  ASN1_OBJECT *unaff_s3;
  uint uVar26;
  uint unaff_s5;
  uint unaff_s6;
  int iVar27;
  code *pcVar28;
  uchar *unaff_s8;
  uint uVar29;
  bool bVar30;
  int iStack_164;
  int iStack_15c;
  int iStack_158;
  int iStack_154;
  ASN1_OBJECT *pAStack_150;
  undefined *puStack_14c;
  int iStack_148;
  uchar *puStack_144;
  ASN1_OBJECT *pAStack_140;
  undefined *puStack_13c;
  uint uStack_138;
  int iStack_134;
  uchar *puStack_130;
  code *pcStack_12c;
  undefined4 uStack_118;
  undefined *puStack_110;
  uint uStack_108;
  uint uStack_104;
  uint uStack_100;
  uint uStack_fc;
  uint uStack_f8;
  int *piStack_f4;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  ASN1_OBJECT *pAStack_e0;
  undefined *puStack_dc;
  uint uStack_d8;
  uchar *puStack_d4;
  ASN1_OBJECT *pAStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  ASN1_OBJECT *pAStack_c4;
  uchar *puStack_c0;
  code *pcStack_bc;
  undefined4 uStack_a8;
  undefined *puStack_a0;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  uint uStack_84;
  uint uStack_80;
  uint uStack_7c;
  ASN1_OBJECT *pAStack_78;
  undefined *puStack_74;
  uint uStack_70;
  code *pcStack_6c;
  undefined *local_58;
  uint local_50;
  ASN1_OBJECT *local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int *local_3c;
  int local_34;
  char *local_30;
  char **local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_58 = &_gp;
  local_34 = 0;
  local_30 = (char *)0x0;
  local_2c = *(char ***)PTR___stack_chk_guard_006a9ae8;
  pAStack_150 = param_1;
  if (param_1 != (ASN1_OBJECT *)0x0) {
    iVar21 = 0x400;
    if ((param_2[1].nid & 8U) != 0) {
      iVar21 = 0x200;
    }
    if (param_1[1].sn == (char *)0x0) {
      uVar29 = (uint)(param_1[1].ln != (char **)0x0);
      local_44 = uVar29;
      if (param_1[1].nid == 0) goto LAB_004a9c88;
LAB_004a9828:
      if (param_1[1].length == 0) {
        iVar13 = (**(code **)(local_58 + -0x6a98))();
        uVar26 = iVar21 < iVar13 << 3 ^ 1;
      }
      else {
        uVar26 = 1;
      }
      unaff_s5 = 1;
      if (param_1[1].data != (uchar *)0x0) goto LAB_004a9848;
LAB_004a9c9c:
      local_50 = (uint)(param_1[1].flags != 0);
    }
    else {
      if (param_1[1].ln == (char **)0x0) {
        iVar13 = (*(code *)PTR_RSA_size_006a7640)();
        local_44 = iVar21 < iVar13 << 3 ^ 1;
      }
      else {
        local_44 = 1;
      }
      uVar29 = 1;
      if (param_1[1].nid != 0) goto LAB_004a9828;
LAB_004a9c88:
      uVar26 = (uint)(param_1[1].length != 0);
      unaff_s5 = uVar26;
      if (param_1[1].data == (uchar *)0x0) goto LAB_004a9c9c;
LAB_004a9848:
      local_50 = 1;
    }
    if ((param_1[2].sn == (char *)0x0) || (param_1[2].ln == (char **)0x0)) {
      unaff_s2 = 0;
      bVar1 = false;
      if (param_1[2].length != 0) goto LAB_004a9888;
LAB_004a9c50:
      local_48 = 0;
      if (param_1[3].sn == (char *)0x0) goto LAB_004a9c5c;
LAB_004a98a0:
      local_4c = (ASN1_OBJECT *)(uint)(param_1[3].ln != (char **)0x0);
    }
    else {
      unaff_s2 = 1;
      iVar13 = (**(code **)(local_58 + -0x78e8))();
      bVar1 = iVar13 << 3 <= iVar21;
      if (param_1[2].length == 0) goto LAB_004a9c50;
LAB_004a9888:
      local_48 = (uint)(param_1[2].data != (uchar *)0x0);
      if (param_1[3].sn != (char *)0x0) goto LAB_004a98a0;
LAB_004a9c5c:
      local_4c = (ASN1_OBJECT *)0x0;
    }
    param_3 = (int *)0x0;
    if ((param_1[3].length == 0) || (param_1[3].data == (uchar *)0x0)) {
      uVar20 = 0;
    }
    else {
      iVar13 = (**(code **)(local_58 + -0x78e8))();
      param_3 = (int *)0x1;
      uVar20 = iVar21 < iVar13 << 3 ^ 1;
    }
    if ((param_1[4].sn == (char *)0x0) || (param_1[4].ln == (char **)0x0)) {
      uVar19 = param_1[4].length;
      bVar5 = false;
      bVar30 = false;
      if (uVar19 != 0) goto LAB_004a9928;
LAB_004a9c0c:
      bVar6 = false;
      if (param_1[5].length == 0) goto LAB_004a9c18;
LAB_004a9938:
      uVar18 = 0x100;
      if (param_1[5].data != (uchar *)0x0) {
        uVar18 = 0x300;
      }
      uVar17 = 0x200;
      if (param_1[5].data == (uchar *)0x0) {
        uVar17 = 0;
      }
      unaff_s6 = uVar17;
      if (param_1[5].sn != (char *)0x0) goto LAB_004a995c;
LAB_004a9c28:
      unaff_s6 = uVar17;
      if (unaff_s2 != 0) goto LAB_004a9980;
LAB_004a9970:
      if ((uVar29 != 0) && (local_48 != 0)) goto LAB_004a9980;
    }
    else {
      local_40 = uVar20;
      local_3c = param_3;
      iVar13 = (**(code **)(local_58 + -0x78e8))();
      bVar5 = true;
      uVar19 = param_1[4].length;
      bVar30 = iVar13 << 3 <= iVar21;
      param_3 = local_3c;
      uVar20 = local_40;
      if (uVar19 == 0) goto LAB_004a9c0c;
LAB_004a9928:
      bVar6 = param_1[4].data != (uchar *)0x0;
      if (param_1[5].length != 0) goto LAB_004a9938;
LAB_004a9c18:
      uVar18 = 0x100;
      uVar17 = 0;
      unaff_s6 = uVar17;
      if (param_1[5].sn == (char *)0x0) goto LAB_004a9c28;
LAB_004a995c:
      uVar17 = uVar18;
      if (param_1[5].ln == (char **)0x0) {
        uVar17 = unaff_s6;
      }
      if (param_1[5].ln != (char **)0x0) {
        unaff_s6 = 0x200;
      }
      if (unaff_s2 == 0) goto LAB_004a9970;
LAB_004a9980:
      unaff_s6 = unaff_s6 | 1;
    }
    if (bVar1) {
      if (unaff_s5 != 0) {
        unaff_s6 = unaff_s6 | 8;
      }
      uVar29 = 1;
      if (uVar26 != 0) {
        uVar29 = 9;
      }
      if (uVar20 != 0) {
        uVar29 = uVar29 | 2;
      }
      if (param_3 != (int *)0x0) {
        unaff_s6 = unaff_s6 | 2;
      }
      if (bVar30) {
        uVar29 = uVar29 | 4;
      }
      if (bVar5) {
        unaff_s6 = unaff_s6 | 4;
      }
      if (unaff_s2 == 0) goto LAB_004a99d8;
LAB_004a9ab4:
      uVar17 = uVar17 | 1;
      pAStack_150 = (ASN1_OBJECT *)&DAT_00000005;
      pAVar22 = (ASN1_OBJECT *)&DAT_00000007;
      param_2 = (ASN1_OBJECT *)0x3;
      unaff_s3 = (ASN1_OBJECT *)0x1;
      if (local_4c == (ASN1_OBJECT *)0x0) goto LAB_004a9acc;
LAB_004a99f8:
      uVar26 = uVar17 | 6;
      uVar17 = uVar17 | 2;
      unaff_s3 = param_2;
    }
    else {
      uVar29 = 0;
      if ((local_44 != 0) && (uVar29 = 1, local_48 == 0)) {
        uVar29 = unaff_s2;
      }
      if (uVar26 != 0) {
        uVar29 = uVar29 | 8;
      }
      if (unaff_s5 != 0) {
        unaff_s6 = unaff_s6 | 8;
      }
      if (uVar20 != 0) {
        uVar29 = uVar29 | 2;
      }
      if (param_3 != (int *)0x0) {
        unaff_s6 = unaff_s6 | 2;
      }
      if (bVar30) {
        uVar29 = uVar29 | 4;
      }
      if (bVar5) {
        unaff_s6 = unaff_s6 | 4;
      }
      if (unaff_s2 != 0) goto LAB_004a9ab4;
LAB_004a99d8:
      if (local_48 != 0) goto LAB_004a9ab4;
      pAStack_150 = (ASN1_OBJECT *)&SUB_00000004;
      pAVar22 = (ASN1_OBJECT *)&DAT_00000006;
      param_2 = (ASN1_OBJECT *)&SUB_00000002;
      unaff_s3 = (ASN1_OBJECT *)0x0;
      if (local_4c != (ASN1_OBJECT *)0x0) goto LAB_004a99f8;
LAB_004a9acc:
      uVar26 = uVar17 | 4;
      pAVar22 = pAStack_150;
    }
    if (bVar6) {
      param_3 = (int *)0x0;
      local_4c = (ASN1_OBJECT *)uVar19;
      local_48 = uVar17;
      (**(code **)(local_58 + -0x76c4))(uVar19,0xffffffff);
      if ((*(uint *)((int)local_4c + 0x28) & 2) == 0) {
        unaff_s5 = 1;
        unaff_s2 = 1;
      }
      else {
        unaff_s5 = *(uint *)((int)local_4c + 0x2c) & 8;
        unaff_s2 = *(uint *)((int)local_4c + 0x2c) & 0x80;
      }
      pAStack_150 = (ASN1_OBJECT *)(**(code **)(local_58 + -0x7ed8))(local_4c);
      if (pAStack_150 == (ASN1_OBJECT *)0x0) {
        local_40 = 0;
        uVar20 = (uint)local_4c;
      }
      else {
        local_44 = (uint)local_4c;
        local_4c = pAStack_150;
        local_40 = (**(code **)(local_58 + -0x7dfc))(pAStack_150);
        pAStack_150 = local_4c;
        uVar20 = local_44;
      }
      param_2 = pAStack_150;
      local_4c = (ASN1_OBJECT *)local_48;
      local_48 = uVar20;
      (**(code **)(local_58 + -0x7f68))();
      if ((*(ASN1_OBJECT ***)(local_48 + 4) != (ASN1_OBJECT **)0x0) &&
         (pAStack_150 = **(ASN1_OBJECT ***)(local_48 + 4), pAStack_150 != (ASN1_OBJECT *)0x0)) {
        pAStack_150 = (ASN1_OBJECT *)OBJ_obj2nid(pAStack_150);
        param_3 = &local_34;
        param_2 = (ASN1_OBJECT *)&local_30;
        OBJ_find_sigid_algs((int)pAStack_150,(int *)param_2,param_3);
      }
      if (unaff_s5 != 0) {
        if ((local_34 == 6) || (local_34 == 0x13)) {
          unaff_s6 = unaff_s6 | 0x20;
          pAStack_150 = (ASN1_OBJECT *)(uint)((int)local_40 < 0xa4);
          uVar26 = (uint)local_4c | 0x14;
          if (pAStack_150 != (ASN1_OBJECT *)0x0) {
            uVar29 = uVar29 | 0x20;
            pAVar22 = (ASN1_OBJECT *)((uint)unaff_s3 | 0x14);
            goto LAB_004a9be8;
          }
        }
        pAStack_150 = (ASN1_OBJECT *)0x198;
        if (local_34 == 0x198) {
          unaff_s6 = unaff_s6 | 0x40;
          uVar26 = uVar26 | 0x10;
          if ((int)local_40 < 0xa4) {
            uVar29 = uVar29 | 0x40;
            pAVar22 = (ASN1_OBJECT *)((uint)pAVar22 | 0x10);
          }
        }
      }
LAB_004a9be8:
      if (unaff_s2 != 0) {
        uVar26 = uVar26 | 0x40;
        pAVar22 = (ASN1_OBJECT *)((uint)pAVar22 | 0x40);
      }
    }
    if (local_50 != 0) {
      unaff_s6 = unaff_s6 | 0x80;
      uVar29 = uVar29 | 0x80;
    }
    unaff_s1 = uVar26 | 0x80;
    unaff_s8 = (uchar *)(uVar29 | 0x100);
    param_1->nid = unaff_s6 | 0x100;
    unaff_s0 = (uint)pAVar22 | 0x80;
    param_1->length = unaff_s1;
    param_1->data = unaff_s8;
    param_1->flags = unaff_s0;
    param_1->ln = (char **)0x1;
  }
  ppcVar14 = *(char ***)puStack_74;
  if (local_2c == ppcVar14) {
    return ppcVar14;
  }
  pcStack_6c = ssl_check_srvr_ecc_cert_and_alg;
  (**(code **)(local_58 + -0x5330))();
  puStack_14c = PTR___stack_chk_guard_006a9ae8;
  iVar21 = *(int *)(param_2[3].data + 0x344);
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_144 = *(uchar **)(iVar21 + 0xc);
  uStack_d8 = *(uint *)(iVar21 + 0x10);
  puStack_a0 = &_gp;
  iStack_94 = 0;
  iStack_90 = 0;
  pcVar28 = (code *)PTR_X509_check_purpose_006a771c;
  uStack_84 = unaff_s0;
  uStack_80 = unaff_s1;
  uStack_7c = unaff_s2;
  pAStack_78 = unaff_s3;
  uStack_70 = unaff_s5;
  if ((*(uint *)(iVar21 + 0x20) & 2) == 0) {
LAB_004a9dec:
    param_3 = (int *)0x0;
    (*pcVar28)(pAStack_150,0xffffffff);
    if (((ASN1_OBJECT **)pAStack_150->ln != (ASN1_OBJECT **)0x0) &&
       (pAVar22 = (ASN1_OBJECT *)*pAStack_150->ln, pAVar22 != (ASN1_OBJECT *)0x0)) {
      iVar21 = OBJ_obj2nid(pAVar22);
      param_3 = &iStack_90;
      OBJ_find_sigid_algs(iVar21,&iStack_94,param_3);
    }
    if (((uint)puStack_144 & 0x60) != 0) {
      if ((((uint)pAStack_150[1].data & 2) == 0) || ((pAStack_150[1].flags & 8U) != 0)) {
        if (((uint)puStack_144 & 0x40) != 0) {
          if (((int)param_2->sn >> 8 == 3) && (0x302 < (int)param_2->sn)) goto LAB_004a9ef0;
          if (iStack_90 != 0x198) {
            pcVar28 = *(code **)(puStack_a0 + -0x6eac);
            param_3 = (int *)0x143;
            uStack_a8 = 0x8fb;
            goto LAB_004a9e9c;
          }
        }
        puStack_144 = (uchar *)((uint)puStack_144 & 0x20);
        if ((puStack_144 == (uchar *)0x0) ||
           (((((int)param_2->sn >> 8 == 3 && (0x302 < (int)param_2->sn)) || (iStack_90 == 6)) ||
            (iStack_90 == 0x13)))) goto LAB_004a9ef0;
        pcVar28 = *(code **)(puStack_a0 + -0x6eac);
        param_3 = (int *)0x142;
        uStack_a8 = 0x904;
      }
      else {
        pcVar28 = *(code **)(puStack_a0 + -0x6eac);
        param_3 = (int *)&DAT_0000013d;
        uStack_a8 = 0x8f4;
      }
LAB_004a9e9c:
      (*pcVar28)(0x14,0x117,param_3,"ssl_lib.c");
      goto LAB_004a9eb0;
    }
LAB_004a9ef0:
    uStack_d8 = uStack_d8 & 0x40;
    iVar21 = 1;
    if ((uStack_d8 != 0) && (iVar21 = 1, ((uint)pAStack_150[1].data & 2) != 0)) {
      if ((pAStack_150[1].flags & 0x80U) == 0) {
        pcVar28 = *(code **)(puStack_a0 + -0x6eac);
        param_3 = (int *)0x13e;
        uStack_a8 = 0x90d;
        goto LAB_004a9e9c;
      }
      iVar21 = 1;
    }
  }
  else {
    uVar29 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
    unaff_s5 = uVar29;
    if (uVar29 != 0) {
      iVar21 = (**(code **)(puStack_a0 + -0x7dfc))(uVar29);
      unaff_s5 = (uint)(iVar21 < 0xa4);
      (**(code **)(puStack_a0 + -0x7f68))(uVar29);
      if (unaff_s5 != 0) {
        pcVar28 = *(code **)(puStack_a0 + -0x76c4);
        goto LAB_004a9dec;
      }
    }
LAB_004a9eb0:
    iVar21 = 0;
  }
  if (iStack_8c == *(int *)puStack_14c) {
    return (char **)iVar21;
  }
  pcStack_bc = ssl_get_server_send_pkey;
  iStack_148 = iStack_8c;
  (**(code **)(puStack_a0 + -0x5330))();
  puStack_13c = PTR___stack_chk_guard_006a9ae8;
  iVar21 = *(int *)(*(int *)(iStack_148 + 0x58) + 0x344);
  puStack_dc = puStack_14c;
  puStack_110 = &_gp;
  iStack_ec = 0;
  iStack_e8 = 0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_134 = *(int *)(iStack_148 + 0x98);
  pAStack_e0 = pAStack_150;
  puStack_d4 = puStack_144;
  pAStack_d0 = param_2;
  uStack_cc = unaff_s5;
  uStack_c8 = unaff_s6;
  pAStack_c4 = param_1;
  puStack_c0 = unaff_s8;
  if (iStack_134 != 0) {
    iVar13 = 0x400;
    if ((*(uint *)(iVar21 + 0x20) & 8) != 0) {
      iVar13 = 0x200;
    }
    if (*(int *)(iStack_134 + 0x18) == 0) {
      uVar29 = (uint)(*(int *)(iStack_134 + 0x1c) != 0);
      uStack_fc = uVar29;
      if (*(int *)(iStack_134 + 0x20) == 0) goto LAB_004aa55c;
LAB_004aa058:
      if (*(int *)(iStack_134 + 0x24) == 0) {
        iVar21 = (**(code **)(puStack_110 + -0x6a98))();
        uVar26 = iVar13 < iVar21 << 3 ^ 1;
      }
      else {
        uVar26 = 1;
      }
      unaff_s6 = 1;
      if (*(int *)(iStack_134 + 0x28) != 0) goto LAB_004aa078;
LAB_004aa570:
      uStack_104 = (uint)(*(int *)(iStack_134 + 0x2c) != 0);
    }
    else {
      if (*(int *)(iStack_134 + 0x1c) == 0) {
        iVar21 = (*(code *)PTR_RSA_size_006a7640)();
        uStack_fc = iVar13 < iVar21 << 3 ^ 1;
      }
      else {
        uStack_fc = 1;
      }
      uVar29 = 1;
      if (*(int *)(iStack_134 + 0x20) != 0) goto LAB_004aa058;
LAB_004aa55c:
      uVar26 = (uint)(*(int *)(iStack_134 + 0x24) != 0);
      unaff_s6 = uVar26;
      if (*(int *)(iStack_134 + 0x28) == 0) goto LAB_004aa570;
LAB_004aa078:
      uStack_104 = 1;
    }
    if ((*(int *)(iStack_134 + 0x30) == 0) || (*(int *)(iStack_134 + 0x34) == 0)) {
      puStack_144 = (uchar *)0x0;
      bVar1 = false;
      if (*(int *)(iStack_134 + 0x3c) != 0) goto LAB_004aa0b8;
LAB_004aa520:
      uStack_100 = 0;
      if (*(int *)(iStack_134 + 0x48) == 0) goto LAB_004aa52c;
LAB_004aa0d0:
      uStack_108 = (uint)(*(int *)(iStack_134 + 0x4c) != 0);
    }
    else {
      puStack_144 = (uchar *)0x1;
      iVar21 = (**(code **)(puStack_110 + -0x78e8))();
      bVar1 = iVar21 << 3 <= iVar13;
      if (*(int *)(iStack_134 + 0x3c) == 0) goto LAB_004aa520;
LAB_004aa0b8:
      uStack_100 = (uint)(*(int *)(iStack_134 + 0x40) != 0);
      if (*(int *)(iStack_134 + 0x48) != 0) goto LAB_004aa0d0;
LAB_004aa52c:
      uStack_108 = 0;
    }
    param_3 = (int *)0x0;
    if ((*(int *)(iStack_134 + 0x54) == 0) || (*(int *)(iStack_134 + 0x58) == 0)) {
      uVar20 = 0;
    }
    else {
      iVar21 = (**(code **)(puStack_110 + -0x78e8))();
      param_3 = (int *)0x1;
      uVar20 = iVar13 < iVar21 << 3 ^ 1;
    }
    if ((*(int *)(iStack_134 + 0x60) == 0) || (*(int *)(iStack_134 + 100) == 0)) {
      uVar19 = *(uint *)(iStack_134 + 0x6c);
      bVar5 = false;
      bVar30 = false;
      if (uVar19 != 0) goto LAB_004aa158;
LAB_004aa4dc:
      bVar6 = false;
      if (*(int *)(iStack_134 + 0x84) == 0) goto LAB_004aa4e8;
LAB_004aa168:
      uVar18 = 0x100;
      if (*(int *)(iStack_134 + 0x88) != 0) {
        uVar18 = 0x300;
      }
      uVar17 = 0x200;
      if (*(int *)(iStack_134 + 0x88) == 0) {
        uVar17 = 0;
      }
      if (*(int *)(iStack_134 + 0x78) != 0) goto LAB_004aa18c;
LAB_004aa4f8:
      uVar18 = uVar17;
      if (puStack_144 != (uchar *)0x0) goto LAB_004aa1b0;
LAB_004aa1a0:
      if ((uVar29 != 0) && (uStack_100 != 0)) goto LAB_004aa1b0;
    }
    else {
      uStack_f8 = uVar20;
      piStack_f4 = param_3;
      iVar21 = (**(code **)(puStack_110 + -0x78e8))();
      bVar5 = true;
      uVar19 = *(uint *)(iStack_134 + 0x6c);
      bVar30 = iVar21 << 3 <= iVar13;
      param_3 = piStack_f4;
      uVar20 = uStack_f8;
      if (uVar19 == 0) goto LAB_004aa4dc;
LAB_004aa158:
      bVar6 = *(int *)(iStack_134 + 0x70) != 0;
      if (*(int *)(iStack_134 + 0x84) != 0) goto LAB_004aa168;
LAB_004aa4e8:
      uVar18 = 0x100;
      uVar17 = 0;
      if (*(int *)(iStack_134 + 0x78) == 0) goto LAB_004aa4f8;
LAB_004aa18c:
      if (*(int *)(iStack_134 + 0x7c) == 0) {
        uVar18 = uVar17;
      }
      if (*(int *)(iStack_134 + 0x7c) != 0) {
        uVar17 = 0x200;
      }
      if (puStack_144 == (uchar *)0x0) goto LAB_004aa1a0;
LAB_004aa1b0:
      uVar17 = uVar17 | 1;
    }
    if (bVar1) {
      if (unaff_s6 != 0) {
        uVar17 = uVar17 | 8;
      }
      unaff_s8 = (uchar *)0x1;
      if (uVar26 != 0) {
        unaff_s8 = &DAT_00000009;
      }
      if (uVar20 != 0) {
        unaff_s8 = (uchar *)((uint)unaff_s8 | 2);
      }
      if (param_3 != (int *)0x0) {
        uVar17 = uVar17 | 2;
      }
      if (bVar30) {
        unaff_s8 = (uchar *)((uint)unaff_s8 | 4);
      }
      if (bVar5) {
        uVar17 = uVar17 | 4;
      }
      if (puStack_144 == (uchar *)0x0) goto LAB_004aa20c;
LAB_004aa320:
      uVar18 = uVar18 | 1;
      uVar29 = 5;
      uVar26 = 7;
      pAVar22 = (ASN1_OBJECT *)0x3;
      param_2 = (ASN1_OBJECT *)0x1;
      if (uStack_108 == 0) goto LAB_004aa338;
LAB_004aa22c:
      uVar20 = uVar18 | 6;
      uVar18 = uVar18 | 2;
      param_2 = pAVar22;
      uVar29 = uVar26;
    }
    else {
      unaff_s8 = (uchar *)0x0;
      if ((uStack_fc != 0) && (unaff_s8 = (uchar *)0x1, uStack_100 == 0)) {
        unaff_s8 = puStack_144;
      }
      if (uVar26 != 0) {
        unaff_s8 = (uchar *)((uint)unaff_s8 | 8);
      }
      if (unaff_s6 != 0) {
        uVar17 = uVar17 | 8;
      }
      if (uVar20 != 0) {
        unaff_s8 = (uchar *)((uint)unaff_s8 | 2);
      }
      if (param_3 != (int *)0x0) {
        uVar17 = uVar17 | 2;
      }
      if (bVar30) {
        unaff_s8 = (uchar *)((uint)unaff_s8 | 4);
      }
      if (bVar5) {
        uVar17 = uVar17 | 4;
      }
      if (puStack_144 != (uchar *)0x0) goto LAB_004aa320;
LAB_004aa20c:
      if (uStack_100 != 0) goto LAB_004aa320;
      uVar29 = 4;
      uVar26 = 6;
      pAVar22 = (ASN1_OBJECT *)&SUB_00000002;
      param_2 = (ASN1_OBJECT *)0x0;
      if (uStack_108 != 0) goto LAB_004aa22c;
LAB_004aa338:
      uVar20 = uVar18 | 4;
    }
    if (bVar6) {
      param_3 = (int *)0x0;
      uStack_108 = uVar19;
      uStack_100 = uVar17;
      uStack_fc = uVar18;
      (**(code **)(puStack_110 + -0x76c4))(uVar19,0xffffffff);
      if ((*(uint *)(uStack_108 + 0x28) & 2) == 0) {
        unaff_s6 = 1;
        puStack_144 = (uchar *)0x1;
      }
      else {
        unaff_s6 = *(uint *)(uStack_108 + 0x2c) & 8;
        puStack_144 = (uchar *)(*(uint *)(uStack_108 + 0x2c) & 0x80);
      }
      iVar21 = (**(code **)(puStack_110 + -0x7ed8))(uStack_108);
      if (iVar21 == 0) {
        piStack_f4 = (int *)0x0;
        uVar26 = uStack_100;
        uStack_100 = uStack_108;
      }
      else {
        uStack_f8 = uStack_fc;
        uStack_fc = uStack_100;
        uStack_100 = uStack_108;
        uStack_108 = iVar21;
        piStack_f4 = (int *)(**(code **)(puStack_110 + -0x7dfc))(iVar21);
        iVar21 = uStack_108;
        uVar26 = uStack_fc;
        uStack_fc = uStack_f8;
      }
      uStack_108 = uStack_100;
      uStack_100 = uVar26;
      (**(code **)(puStack_110 + -0x7f68))(iVar21);
      uVar26 = uStack_100;
      uVar17 = uStack_100;
      uVar19 = uStack_fc;
      if ((*(ASN1_OBJECT ***)(uStack_108 + 4) != (ASN1_OBJECT **)0x0) &&
         (pAVar22 = **(ASN1_OBJECT ***)(uStack_108 + 4), pAVar22 != (ASN1_OBJECT *)0x0)) {
        uStack_100 = uStack_fc;
        uStack_108 = uVar26;
        iVar21 = OBJ_obj2nid(pAVar22);
        param_3 = &iStack_ec;
        OBJ_find_sigid_algs(iVar21,&iStack_e8,param_3);
        uVar17 = uStack_108;
        uVar19 = uStack_100;
      }
      if (unaff_s6 != 0) {
        if ((iStack_ec == 6) || (iStack_ec == 0x13)) {
          uVar17 = uVar17 | 0x20;
          uVar20 = uVar19 | 0x14;
          if ((int)piStack_f4 < 0xa4) {
            unaff_s8 = (uchar *)((uint)unaff_s8 | 0x20);
            uVar29 = (uint)param_2 | 0x14;
            goto LAB_004aa480;
          }
        }
        if (iStack_ec == 0x198) {
          uVar17 = uVar17 | 0x40;
          uVar20 = uVar20 | 0x10;
          if ((int)piStack_f4 < 0xa4) {
            unaff_s8 = (uchar *)((uint)unaff_s8 | 0x40);
            uVar29 = uVar29 | 0x10;
          }
        }
      }
LAB_004aa480:
      if (puStack_144 != (uchar *)0x0) {
        uVar20 = uVar20 | 0x40;
        uVar29 = uVar29 | 0x40;
      }
    }
    if (uStack_104 != 0) {
      uVar17 = uVar17 | 0x80;
      unaff_s8 = (uchar *)((uint)unaff_s8 | 0x80);
    }
    iVar21 = *(int *)(iStack_148 + 0x58);
    puStack_14c = (undefined *)(uVar20 | 0x80);
    *(uint *)(iStack_134 + 8) = uVar17 | 0x100;
    pAStack_150 = (ASN1_OBJECT *)(uVar29 | 0x80);
    *(undefined **)(iStack_134 + 0xc) = puStack_14c;
    *(uint *)(iStack_134 + 0x10) = (uint)unaff_s8 | 0x100;
    *(ASN1_OBJECT **)(iStack_134 + 0x14) = pAStack_150;
    *(undefined4 *)(iStack_134 + 4) = 1;
    iVar21 = *(int *)(iVar21 + 0x344);
  }
  uVar29 = *(uint *)(iVar21 + 0xc);
  if ((uVar29 & 0x60) == 0) {
    uVar26 = *(uint *)(iVar21 + 0x10);
    if ((uVar26 & 0x40) != 0) goto LAB_004aa2a0;
    if ((uVar29 & 2) != 0) {
      iVar21 = 0x24;
      goto LAB_004aa2a4;
    }
    if ((uVar29 & 4) != 0) {
      iVar21 = 0x30;
      goto LAB_004aa2a4;
    }
    if ((uVar26 & 2) != 0) {
      iVar21 = 0x18;
      goto LAB_004aa2a4;
    }
    if ((uVar26 & 1) != 0) {
      iVar21 = (uint)(*(int *)(iStack_134 + 0x30) == 0) * 0xc;
      goto LAB_004aa2a4;
    }
    if ((uVar26 & 0x20) == 0) {
      if ((uVar26 & 0x100) == 0) {
        iVar21 = 0x54;
        if ((uVar26 & 0x200) == 0) {
          param_3 = (int *)0x44;
          uStack_118 = 0x944;
          (**(code **)(puStack_110 + -0x6eac))(0x14,0x13d,0x44,"ssl_lib.c");
          iVar21 = 0;
          goto LAB_004aa2ac;
        }
      }
      else {
        iVar21 = 0x48;
      }
      goto LAB_004aa2a4;
    }
    iVar21 = 0;
  }
  else {
LAB_004aa2a0:
    iVar21 = 0x3c;
LAB_004aa2a4:
    iVar21 = iStack_134 + 0x30 + iVar21;
  }
LAB_004aa2ac:
  if (iStack_e4 == *(int *)puStack_13c) {
    return (char **)iVar21;
  }
  pcStack_12c = ssl_get_server_send_cert;
  iVar21 = iStack_e4;
  (**(code **)(puStack_110 + -0x5330))();
  puVar12 = PTR___stack_chk_guard_006a9ae8;
  iVar13 = *(int *)(*(int *)(iVar21 + 0x58) + 0x344);
  iStack_15c = 0;
  iStack_158 = 0;
  iStack_154 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar27 = *(int *)(iVar21 + 0x98);
  pAStack_140 = param_2;
  uStack_138 = unaff_s6;
  puStack_130 = unaff_s8;
  if (iVar27 != 0) {
    iVar23 = 0x400;
    if ((*(uint *)(iVar13 + 0x20) & 8) != 0) {
      iVar23 = 0x200;
    }
    if (*(int *)(iVar27 + 0x18) == 0) {
      bVar30 = *(int *)(iVar27 + 0x1c) != 0;
      bVar1 = bVar30;
      if (*(int *)(iVar27 + 0x20) == 0) goto LAB_004aac28;
LAB_004aa718:
      if (*(int *)(iVar27 + 0x24) == 0) {
        iVar13 = (*(code *)PTR_DH_size_006a8348)();
        bVar5 = iVar13 << 3 <= iVar23;
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
        iVar13 = (*(code *)PTR_RSA_size_006a7640)();
        bVar1 = iVar13 << 3 <= iVar23;
      }
      else {
        bVar1 = true;
      }
      bVar30 = true;
      if (*(int *)(iVar27 + 0x20) != 0) goto LAB_004aa718;
LAB_004aac28:
      bVar5 = *(int *)(iVar27 + 0x24) != 0;
      bVar6 = bVar5;
      if (*(int *)(iVar27 + 0x28) == 0) goto LAB_004aac3c;
LAB_004aa738:
      bVar10 = true;
    }
    if ((*(int *)(iVar27 + 0x30) == 0) || (*(int *)(iVar27 + 0x34) == 0)) {
      uVar29 = 0;
      bVar2 = false;
      if (*(int *)(iVar27 + 0x3c) != 0) goto LAB_004aa778;
LAB_004aabec:
      bVar7 = false;
      if (*(int *)(iVar27 + 0x48) == 0) goto LAB_004aabf8;
LAB_004aa790:
      bVar8 = *(int *)(iVar27 + 0x4c) != 0;
    }
    else {
      uVar29 = 1;
      iVar13 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      bVar2 = iVar13 << 3 <= iVar23;
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
      iVar13 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      param_3 = (int *)0x1;
      bVar3 = iVar13 << 3 <= iVar23;
    }
    if ((*(int *)(iVar27 + 0x60) == 0) || (*(int *)(iVar27 + 100) == 0)) {
      iVar13 = *(int *)(iVar27 + 0x6c);
      bVar11 = false;
      bVar4 = false;
      if (iVar13 != 0) goto LAB_004aa818;
LAB_004aaba8:
      bVar9 = false;
      if (*(int *)(iVar27 + 0x84) == 0) goto LAB_004aabb4;
LAB_004aa828:
      uVar26 = 0x100;
      if (*(int *)(iVar27 + 0x88) != 0) {
        uVar26 = 0x300;
      }
      uVar20 = 0x200;
      if (*(int *)(iVar27 + 0x88) == 0) {
        uVar20 = 0;
      }
      if (*(int *)(iVar27 + 0x78) != 0) goto LAB_004aa84c;
LAB_004aabc4:
      uVar26 = uVar20;
      if (uVar29 != 0) goto LAB_004aa870;
LAB_004aa860:
      if ((bVar30) && (bVar7)) goto LAB_004aa870;
    }
    else {
      iVar15 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      bVar11 = true;
      iVar13 = *(int *)(iVar27 + 0x6c);
      bVar4 = iVar15 << 3 <= iVar23;
      if (iVar13 == 0) goto LAB_004aaba8;
LAB_004aa818:
      bVar9 = *(int *)(iVar27 + 0x70) != 0;
      if (*(int *)(iVar27 + 0x84) != 0) goto LAB_004aa828;
LAB_004aabb4:
      uVar26 = 0x100;
      uVar20 = 0;
      if (*(int *)(iVar27 + 0x78) == 0) goto LAB_004aabc4;
LAB_004aa84c:
      if (*(int *)(iVar27 + 0x7c) == 0) {
        uVar26 = uVar20;
      }
      if (*(int *)(iVar27 + 0x7c) != 0) {
        uVar20 = 0x200;
      }
      if (uVar29 == 0) goto LAB_004aa860;
LAB_004aa870:
      uVar20 = uVar20 | 1;
    }
    if (bVar2) {
      if (bVar6) {
        uVar20 = uVar20 | 8;
      }
      uVar19 = 1;
      if (bVar5) {
        uVar19 = 9;
      }
      if (bVar3) {
        uVar19 = uVar19 | 2;
      }
      if (param_3 != (int *)0x0) {
        uVar20 = uVar20 | 2;
      }
      if (bVar4) {
        uVar19 = uVar19 | 4;
      }
      if (bVar11) {
        uVar20 = uVar20 | 4;
      }
      if (uVar29 == 0) goto LAB_004aa8cc;
LAB_004aa9ec:
      uVar26 = uVar26 | 1;
      uVar18 = 5;
      uVar24 = 7;
      uVar17 = 3;
      uVar29 = 1;
      if (!bVar8) goto LAB_004aaa04;
LAB_004aa8ec:
      uVar25 = uVar26 | 6;
      uVar26 = uVar26 | 2;
      uVar29 = uVar17;
      uVar18 = uVar24;
    }
    else {
      uVar19 = 0;
      if ((bVar1) && (uVar19 = 1, !bVar7)) {
        uVar19 = uVar29;
      }
      if (bVar5) {
        uVar19 = uVar19 | 8;
      }
      if (bVar6) {
        uVar20 = uVar20 | 8;
      }
      if (bVar3) {
        uVar19 = uVar19 | 2;
      }
      if (param_3 != (int *)0x0) {
        uVar20 = uVar20 | 2;
      }
      if (bVar4) {
        uVar19 = uVar19 | 4;
      }
      if (bVar11) {
        uVar20 = uVar20 | 4;
      }
      if (uVar29 != 0) goto LAB_004aa9ec;
LAB_004aa8cc:
      if (bVar7) goto LAB_004aa9ec;
      uVar18 = 4;
      uVar24 = 6;
      uVar17 = 2;
      uVar29 = 0;
      if (bVar8) goto LAB_004aa8ec;
LAB_004aaa04:
      uVar25 = uVar26 | 4;
    }
    if (bVar9) {
      param_3 = (int *)0x0;
      (*(code *)PTR_X509_check_purpose_006a771c)(iVar13,0xffffffff);
      if ((*(uint *)(iVar13 + 0x28) & 2) == 0) {
        uVar24 = 1;
        uVar17 = 1;
      }
      else {
        uVar24 = *(uint *)(iVar13 + 0x2c) & 8;
        uVar17 = *(uint *)(iVar13 + 0x2c) & 0x80;
      }
      iVar23 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar13);
      if (iVar23 == 0) {
        iStack_164 = 0;
      }
      else {
        iStack_164 = (*(code *)PTR_EVP_PKEY_bits_006a6fe4)(iVar23);
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar23);
      if ((*(ASN1_OBJECT ***)(iVar13 + 4) != (ASN1_OBJECT **)0x0) &&
         (pAVar22 = **(ASN1_OBJECT ***)(iVar13 + 4), pAVar22 != (ASN1_OBJECT *)0x0)) {
        iVar13 = OBJ_obj2nid(pAVar22);
        param_3 = &iStack_15c;
        OBJ_find_sigid_algs(iVar13,&iStack_158,param_3);
      }
      if (uVar24 != 0) {
        if ((iStack_15c == 6) || (iStack_15c == 0x13)) {
          uVar20 = uVar20 | 0x20;
          uVar25 = uVar26 | 0x14;
          if (iStack_164 < 0xa4) {
            uVar19 = uVar19 | 0x20;
            uVar18 = uVar29 | 0x14;
            goto LAB_004aab4c;
          }
        }
        if (iStack_15c == 0x198) {
          uVar20 = uVar20 | 0x40;
          uVar25 = uVar25 | 0x10;
          if (iStack_164 < 0xa4) {
            uVar19 = uVar19 | 0x40;
            uVar18 = uVar18 | 0x10;
          }
        }
      }
LAB_004aab4c:
      if (uVar17 != 0) {
        uVar25 = uVar25 | 0x40;
        uVar18 = uVar18 | 0x40;
      }
    }
    if (bVar10) {
      uVar20 = uVar20 | 0x80;
      uVar19 = uVar19 | 0x80;
    }
    iVar21 = *(int *)(iVar21 + 0x58);
    *(uint *)(iVar27 + 8) = uVar20 | 0x100;
    *(uint *)(iVar27 + 0xc) = uVar25 | 0x80;
    *(uint *)(iVar27 + 0x10) = uVar19 | 0x100;
    *(uint *)(iVar27 + 0x14) = uVar18 | 0x80;
    *(undefined4 *)(iVar27 + 4) = 1;
    iVar13 = *(int *)(iVar21 + 0x344);
  }
  uVar29 = *(uint *)(iVar13 + 0xc);
  uVar26 = uVar29 & 0x60;
  if (uVar26 == 0) {
    uVar20 = *(uint *)(iVar13 + 0x10);
    uVar26 = uVar29 & 2;
    if ((uVar20 & 0x40) != 0) goto LAB_004aa960;
    if (uVar26 != 0) {
      iVar21 = 0x24;
      goto LAB_004aa964;
    }
    if ((uVar29 & 4) != 0) {
      iVar21 = 0x30;
      goto LAB_004aa964;
    }
    if ((uVar20 & 2) != 0) {
      iVar21 = 0x18;
      goto LAB_004aa964;
    }
    if ((uVar20 & 1) != 0) {
      iVar21 = (uint)(*(int *)(iVar27 + 0x30) == 0) * 0xc;
      goto LAB_004aa964;
    }
    if ((uVar20 & 0x20) == 0) {
      if ((uVar20 & 0x100) == 0) {
        iVar21 = 0x54;
        if ((uVar20 & 0x200) == 0) {
          param_3 = (int *)0x44;
          uVar26 = 0x13d;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13d,0x44,"ssl_lib.c",0x944);
          goto LAB_004aad20;
        }
      }
      else {
        iVar21 = 0x48;
      }
      goto LAB_004aa964;
    }
LAB_004aad20:
    iVar21 = 0;
  }
  else {
LAB_004aa960:
    iVar21 = 0x3c;
LAB_004aa964:
    piVar16 = (int *)(iVar27 + 0x30 + iVar21);
    iVar21 = 0;
    if (piVar16 != (int *)0x0) {
      iVar21 = *piVar16;
    }
  }
  if (iStack_154 == *(int *)puVar12) {
    return (char **)iVar21;
  }
  iVar21 = iStack_154;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar29 = *(uint *)(uVar26 + 0x10);
  iVar21 = *(int *)(iVar21 + 0x98);
  if (((uVar29 & 2) == 0) || (iVar13 = *(int *)(iVar21 + 0x4c), iVar13 == 0)) {
    if ((uVar29 & 1) == 0) {
      if ((uVar29 & 0x40) != 0) {
        iVar13 = *(int *)(iVar21 + 0x70);
        iVar27 = 5;
        if (iVar13 != 0) goto LAB_004aad70;
      }
LAB_004aaddc:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb7,0x44,"ssl_lib.c",0x96a);
      return (char **)0;
    }
    iVar13 = *(int *)(iVar21 + 0x40);
    iVar27 = 1;
    if (iVar13 == 0) {
      iVar13 = *(int *)(iVar21 + 0x34);
      iVar27 = 0;
      if (iVar13 == 0) goto LAB_004aaddc;
    }
  }
  else {
    iVar27 = 2;
  }
LAB_004aad70:
  if (param_3 != (int *)0x0) {
    iVar21 = iVar21 + iVar27 * 0xc;
    *param_3 = *(int *)(iVar21 + 0x38);
    iVar13 = *(int *)(iVar21 + 0x34);
  }
  return (char **)iVar13;
}

