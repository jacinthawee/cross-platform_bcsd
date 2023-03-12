
void DES_ncbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,int enc)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined *puVar4;
  int iVar5;
  uchar uVar8;
  uint uVar6;
  uchar uVar9;
  uint uVar7;
  uchar uVar15;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar16;
  uint uVar17;
  uchar *puVar18;
  DES_key_schedule *ks1;
  uchar uVar19;
  uchar uVar20;
  DES_key_schedule *pDVar21;
  uint uVar22;
  DES_key_schedule **ppDVar23;
  undefined *puVar24;
  DES_key_schedule *pDVar25;
  DES_key_schedule *pDVar26;
  DES_key_schedule *pDVar27;
  byte *pbVar28;
  DES_key_schedule *pDVar29;
  DES_key_schedule **unaff_s3;
  DES_key_schedule *pDVar30;
  DES_key_schedule **unaff_s4;
  DES_key_schedule **ppDVar31;
  DES_key_schedule **unaff_s5;
  DES_key_schedule *pDVar32;
  DES_key_schedule *pDVar33;
  uchar *puVar34;
  DES_key_schedule *unaff_s6;
  DES_key_schedule **unaff_s7;
  _union_771 *p_Var35;
  int iVar36;
  undefined *puVar37;
  byte *pbVar38;
  code *pcVar39;
  undefined auStack_d8 [16];
  undefined *puStack_c8;
  _union_771 *p_Stack_c0;
  byte *pbStack_bc;
  DES_key_schedule *pDStack_b8;
  _union_771 *p_Stack_b4;
  byte *pbStack_b0;
  _union_771 *p_Stack_ac;
  int *piStack_a8;
  uint uStack_a4;
  DES_key_schedule *pDStack_9c;
  DES_key_schedule *pDStack_98;
  int iStack_94;
  byte *pbStack_90;
  DES_cblock *pauStack_8c;
  DES_key_schedule *pDStack_88;
  DES_key_schedule **ppDStack_84;
  DES_key_schedule **ppDStack_80;
  DES_key_schedule **ppDStack_7c;
  DES_key_schedule *pDStack_78;
  DES_key_schedule **ppDStack_74;
  byte *pbStack_70;
  code *pcStack_6c;
  uint uStack_60;
  DES_key_schedule *local_58;
  DES_key_schedule *pDStack_54;
  DES_key_schedule *pDStack_50;
  DES_key_schedule **local_4c;
  byte *local_48;
  uchar *local_44;
  int *local_40;
  DES_key_schedule **local_3c;
  DES_key_schedule *local_34;
  DES_key_schedule **local_30;
  int local_2c;
  
  local_40 = (int *)PTR___stack_chk_guard_006aabf0;
  local_58 = (DES_key_schedule *)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_88 = schedule;
  local_48 = input;
  local_44 = output;
  if (enc == 0) {
    unaff_s5 = (DES_key_schedule **)(length + -8);
    ks1 = (DES_key_schedule *)((uint)(*ivec)[3] << 0x18);
    p_Stack_ac = (_union_771 *)((uint)(*ivec)[7] << 0x18);
    pDVar25 = (DES_key_schedule *)
              ((uint)ks1 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0]);
    unaff_s7 = (DES_key_schedule **)
               ((uint)p_Stack_ac |
               (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4]);
    unaff_s6 = pDVar25;
    local_3c = unaff_s5;
    if (-1 < (int)unaff_s5) {
      unaff_s3 = &local_34;
      ppDVar23 = unaff_s7;
      ppDVar31 = (DES_key_schedule **)output;
      pDVar29 = pDVar25;
      do {
        output = input + 8;
        unaff_s4 = ppDVar31 + 2;
        unaff_s5 = unaff_s5 + -2;
        pDVar25 = (DES_key_schedule *)
                  ((uint)input[1] << 8 | (uint)input[2] << 0x10 | (uint)*input |
                  (uint)input[3] << 0x18);
        unaff_s7 = (DES_key_schedule **)
                   ((uint)input[7] << 0x18 |
                   (uint)input[5] << 8 | (uint)input[6] << 0x10 | (uint)input[4]);
        local_4c = ppDVar23;
        local_34 = pDVar25;
        local_30 = unaff_s7;
        DES_encrypt1_constprop_3(unaff_s3,schedule);
        uVar10 = (uint)pDVar29 ^ (uint)local_34;
        uVar6 = (uint)local_4c ^ (uint)local_30;
        *(byte *)ppDVar31 = (byte)uVar10;
        ks1 = (DES_key_schedule *)(uVar10 >> 0x10);
        p_Stack_ac = (_union_771 *)(uVar6 >> 8);
        *(byte *)(ppDVar31 + 1) = (byte)uVar6;
        *(byte *)((int)ppDVar31 + 1) = (byte)(uVar10 >> 8);
        *(byte *)((int)ppDVar31 + 2) = (byte)(uVar10 >> 0x10);
        *(byte *)((int)ppDVar31 + 5) = (byte)(uVar6 >> 8);
        *(byte *)((int)ppDVar31 + 3) = (byte)(uVar10 >> 0x18);
        *(byte *)((int)ppDVar31 + 6) = (byte)(uVar6 >> 0x10);
        *(byte *)((int)ppDVar31 + 7) = (byte)(uVar6 >> 0x18);
        ppDVar23 = unaff_s7;
        ppDVar31 = unaff_s4;
        pDVar29 = pDVar25;
        input = output;
      } while (-1 < (int)unaff_s5);
      iVar5 = (((uint)local_3c >> 3) + 1) * 8;
      unaff_s5 = (DES_key_schedule **)
                 ((int)(DES_key_schedule *)(length + -0x10) - ((uint)local_3c & 0xfffffff8));
      local_48 = local_48 + iVar5;
      local_44 = local_44 + iVar5;
      unaff_s6 = (DES_key_schedule *)(length + -0x10);
    }
    pDVar29 = pDVar25;
    if (unaff_s5 != (DES_key_schedule **)0xfffffff8) {
      ks1 = (DES_key_schedule *)
            ((uint)local_48[1] << 8 | (uint)local_48[2] << 0x10 | (uint)*local_48);
      unaff_s3 = (DES_key_schedule **)
                 ((uint)local_48[5] << 8 | (uint)local_48[6] << 0x10 | (uint)local_48[4] |
                 (uint)local_48[7] << 0x18);
      pDVar29 = (DES_key_schedule *)((uint)ks1 | (uint)local_48[3] << 0x18);
      local_34 = pDVar29;
      local_30 = unaff_s3;
      DES_encrypt1_constprop_3(&local_34);
      unaff_s4 = (DES_key_schedule **)(local_44 + (int)(unaff_s5 + 2));
      uVar10 = (uint)pDVar25 ^ (uint)local_34;
      uVar6 = (uint)unaff_s7 ^ (uint)local_30;
      p_Stack_ac = schedule->ks;
      pDStack_88 = pDVar29;
      unaff_s7 = unaff_s3;
      if (&DAT_00000007 < unaff_s5 + 2) goto LAB_004dfd8c;
      ppDVar23 = unaff_s4;
      switch(unaff_s5) {
      case (DES_key_schedule **)0xfffffff9:
        goto LAB_004dfd80;
      case (DES_key_schedule **)0xfffffffa:
        goto switchD_004dfd48_caseD_fffffffa;
      case (DES_key_schedule **)0xfffffffb:
        goto LAB_004dfd68;
      case (DES_key_schedule **)0xfffffffd:
        ppDVar23 = (DES_key_schedule **)((int)unaff_s4 + -1);
        *(byte *)((int)unaff_s4 + -1) = (byte)uVar6;
        break;
      case (DES_key_schedule **)0xffffffff:
        unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
        *(byte *)unaff_s4 = (byte)(uVar6 >> 0x10);
      case (DES_key_schedule **)0xfffffffe:
        *(byte *)((int)unaff_s4 + -1) = (byte)(uVar6 >> 8);
        ppDVar23 = (DES_key_schedule **)((int)unaff_s4 + -2);
        *(byte *)((int)unaff_s4 + -2) = (byte)uVar6;
      }
      unaff_s4 = (DES_key_schedule **)((int)ppDVar23 + -1);
      *(byte *)((int)ppDVar23 + -1) = (byte)(uVar10 >> 0x18);
LAB_004dfd68:
      ppDVar23 = (DES_key_schedule **)((int)unaff_s4 + -1);
      *(byte *)((int)unaff_s4 + -1) = (byte)(uVar10 >> 0x10);
switchD_004dfd48_caseD_fffffffa:
      unaff_s4 = (DES_key_schedule **)((int)ppDVar23 + -1);
      *(byte *)((int)ppDVar23 + -1) = (byte)(uVar10 >> 8);
LAB_004dfd80:
      *(byte *)((int)unaff_s4 + -1) = (byte)uVar10;
      unaff_s4 = ppDVar23;
    }
LAB_004dfd8c:
    (*ivec)[0] = (uchar)pDVar29;
    pbStack_b0 = (byte *)((uint)pDVar29 >> 0x10);
    (*ivec)[4] = (uchar)unaff_s7;
    input = (uchar *)((uint)pDVar29 >> 0x18);
    (*ivec)[1] = (uchar)((uint)pDVar29 >> 8);
    (*ivec)[2] = (uchar)((uint)pDVar29 >> 0x10);
    (*ivec)[3] = (uchar)((uint)pDVar29 >> 0x18);
    (*ivec)[5] = (uchar)((uint)unaff_s7 >> 8);
    (*ivec)[7] = (uchar)((uint)unaff_s7 >> 0x18);
    (*ivec)[6] = (uchar)((uint)unaff_s7 >> 0x10);
    ppDVar23 = unaff_s7;
  }
  else {
    unaff_s4 = (DES_key_schedule **)(length + -8);
    pDVar25 = (DES_key_schedule *)
              ((uint)(*ivec)[3] << 0x18 |
              (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0]);
    ppDVar23 = (DES_key_schedule **)
               ((uint)(*ivec)[7] << 0x18 |
               (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4]);
    local_3c = unaff_s4;
    if (-1 < (int)unaff_s4) {
      unaff_s3 = &local_34;
      local_30 = ppDVar23;
      local_34 = pDVar25;
      pbVar28 = input;
      pbVar38 = output;
      do {
        input = pbVar28 + 8;
        output = pbVar38 + 8;
        unaff_s4 = unaff_s4 + -2;
        local_30 = (DES_key_schedule **)
                   (((uint)pbVar28[7] << 0x18 |
                    (uint)pbVar28[5] << 8 | (uint)pbVar28[6] << 0x10 | (uint)pbVar28[4]) ^
                   (uint)local_30);
        local_34 = (DES_key_schedule *)
                   (((uint)pbVar28[3] << 0x18 |
                    (uint)pbVar28[1] << 8 | (uint)pbVar28[2] << 0x10 | (uint)*pbVar28) ^
                   (uint)local_34);
        DES_encrypt1_constprop_2(unaff_s3,schedule);
        *pbVar38 = (byte)local_34;
        pbVar38[4] = (byte)local_30;
        pbVar38[1] = (byte)((uint)local_34 >> 8);
        pbVar38[2] = (byte)((uint)local_34 >> 0x10);
        pbVar38[3] = (byte)((uint)local_34 >> 0x18);
        pbVar38[5] = (byte)((uint)local_30 >> 8);
        pbVar38[6] = (byte)((uint)local_30 >> 0x10);
        pbVar38[7] = (byte)((uint)local_30 >> 0x18);
        pbVar28 = input;
        pbVar38 = output;
      } while (-1 < (int)unaff_s4);
      unaff_s6 = (DES_key_schedule *)(length + -0x10);
      unaff_s5 = (DES_key_schedule **)((uint)local_3c & 0xfffffff8);
      iVar5 = (((uint)local_3c >> 3) + 1) * 8;
      unaff_s4 = (DES_key_schedule **)((int)unaff_s6 - (int)unaff_s5);
      local_48 = local_48 + iVar5;
      local_44 = local_44 + iVar5;
      ppDVar23 = local_30;
      pDVar25 = local_34;
    }
    if (unaff_s4 == (DES_key_schedule **)0xfffffff8) {
      pbStack_b0 = (byte *)((uint)pDVar25 & 0xff);
      uVar19 = (uchar)((uint)pDVar25 >> 8);
      uVar9 = (uchar)((uint)pDVar25 >> 0x18);
      uVar8 = (uchar)((uint)ppDVar23 >> 0x18);
      uVar15 = (uchar)ppDVar23;
    }
    else {
      unaff_s3 = (DES_key_schedule **)(local_48 + (int)(unaff_s4 + 2));
      switch(unaff_s4) {
      default:
        uVar6 = 0;
        uVar10 = 0;
        goto LAB_004dfea4;
      case (DES_key_schedule **)0xfffffff9:
        uVar6 = 0;
        uVar10 = 0;
        goto LAB_004dfe9c;
      case (DES_key_schedule **)0xfffffffa:
        uVar6 = 0;
        uVar10 = 0;
        goto LAB_004dfe8c;
      case (DES_key_schedule **)0xfffffffb:
        uVar6 = 0;
        uVar10 = 0;
        goto LAB_004dfe7c;
      case (DES_key_schedule **)0xfffffffc:
        uVar6 = 0;
        goto LAB_004dfe70;
      case (DES_key_schedule **)0xfffffffd:
        uVar6 = 0;
        goto LAB_004dfe64;
      case (DES_key_schedule **)0xfffffffe:
        uVar6 = 0;
        break;
      case (DES_key_schedule **)0xffffffff:
        pbVar28 = (byte *)((int)unaff_s3 + -1);
        unaff_s3 = (DES_key_schedule **)((int)unaff_s3 + -1);
        uVar6 = (uint)*pbVar28 << 0x10;
      }
      pbVar28 = (byte *)((int)unaff_s3 + -1);
      unaff_s3 = (DES_key_schedule **)((int)unaff_s3 + -1);
      uVar6 = (uint)*pbVar28 << 8 | uVar6;
LAB_004dfe64:
      pbVar28 = (byte *)((int)unaff_s3 + -1);
      unaff_s3 = (DES_key_schedule **)((int)unaff_s3 + -1);
      uVar6 = *pbVar28 | uVar6;
LAB_004dfe70:
      pbVar28 = (byte *)((int)unaff_s3 + -1);
      unaff_s3 = (DES_key_schedule **)((int)unaff_s3 + -1);
      uVar10 = (uint)*pbVar28 << 0x18;
LAB_004dfe7c:
      pbVar28 = (byte *)((int)unaff_s3 + -1);
      unaff_s3 = (DES_key_schedule **)((int)unaff_s3 + -1);
      uVar10 = (uint)*pbVar28 << 0x10 | uVar10;
LAB_004dfe8c:
      pbVar28 = (byte *)((int)unaff_s3 + -1);
      unaff_s3 = (DES_key_schedule **)((int)unaff_s3 + -1);
      uVar10 = (uint)*pbVar28 << 8 | uVar10;
LAB_004dfe9c:
      uVar10 = *(byte *)((int)unaff_s3 + -1) | uVar10;
LAB_004dfea4:
      local_34 = (DES_key_schedule *)(uVar10 ^ (uint)pDVar25);
      local_30 = (DES_key_schedule **)(uVar6 ^ (uint)ppDVar23);
      DES_encrypt1_constprop_2(&local_34,schedule);
      uVar19 = (uchar)((uint)local_34 >> 8);
      local_44[1] = uVar19;
      local_44[2] = (uchar)((uint)local_34 >> 0x10);
      uVar9 = (uchar)((uint)local_34 >> 0x18);
      local_44[3] = uVar9;
      pbStack_b0 = (byte *)((uint)local_34 & 0xff);
      local_44[5] = (uchar)((uint)local_30 >> 8);
      uVar15 = (uchar)local_30;
      local_44[6] = (uchar)((uint)local_30 >> 0x10);
      *local_44 = (uchar)pbStack_b0;
      local_44[4] = uVar15;
      uVar8 = (uchar)((uint)local_30 >> 0x18);
      local_44[7] = uVar8;
      ppDVar23 = local_30;
      pDVar25 = local_34;
    }
    ks1 = (DES_key_schedule *)((uint)((int)pDVar25 << 8) >> 0x18);
    p_Stack_ac = (_union_771 *)((uint)((int)ppDVar23 << 8) >> 0x18);
    (*ivec)[0] = (uchar)pbStack_b0;
    (*ivec)[1] = uVar19;
    (*ivec)[2] = (uchar)((uint)pDVar25 >> 0x10);
    (*ivec)[3] = uVar9;
    (*ivec)[4] = uVar15;
    (*ivec)[5] = (uchar)((uint)ppDVar23 >> 8);
    (*ivec)[6] = (uchar)((uint)ppDVar23 >> 0x10);
    (*ivec)[7] = uVar8;
    ppDVar23 = (DES_key_schedule **)((int)ppDVar23 << 0x10);
  }
  uStack_60 = (uint)ppDVar23 >> 0x18;
  if (local_2c == *local_40) {
    return;
  }
  pcStack_6c = DES_ede3_cbc_encrypt;
  (*(code *)local_58[-0xa7].ks[0xb].deslong[0])();
  pDVar25 = local_58;
  pauStack_8c = ivec;
  piStack_a8 = (int *)PTR___stack_chk_guard_006aabf0;
  puStack_c8 = &_gp;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  pDVar29 = pDVar25;
  pDVar30 = pDStack_54;
  pbStack_90 = input;
  ppDStack_84 = unaff_s3;
  ppDStack_80 = unaff_s4;
  ppDStack_7c = unaff_s5;
  pDStack_78 = unaff_s6;
  ppDStack_74 = unaff_s7;
  pbStack_70 = output;
  if (local_4c == (DES_key_schedule **)0x0) {
    uVar6 = uStack_60 - 8;
    pDVar27 = (DES_key_schedule *)
              ((uint)pDStack_50->ks[0].cblock[1] << 8 | (uint)pDStack_50->ks[0].cblock[2] << 0x10);
    pDVar26 = (DES_key_schedule *)
              ((uint)pDStack_50->ks[0].cblock[3] << 0x18 |
              (uint)pDVar27 | (uint)pDStack_50->ks[0].cblock[0]);
    pDVar32 = (DES_key_schedule *)
              ((uint)pDStack_50->ks[0].cblock[7] << 0x18 |
              (uint)pDStack_50->ks[0].cblock[5] << 8 | (uint)pDStack_50->ks[0].cblock[6] << 0x10 |
              (uint)pDStack_50->ks[0].cblock[4]);
    uStack_a4 = uVar6;
    if (-1 < (int)uVar6) {
      pbStack_bc = pbStack_b0;
      p_Stack_c0 = p_Stack_ac;
      pDVar21 = pDVar26;
      pDVar33 = pDVar32;
      do {
        p_Stack_c0 = p_Stack_c0 + 1;
        pDVar32 = (DES_key_schedule *)
                  ((uint)pbStack_bc[7] << 0x18 |
                  (uint)pbStack_bc[5] << 8 | (uint)pbStack_bc[6] << 0x10 | (uint)pbStack_bc[4]);
        pDVar26 = (DES_key_schedule *)
                  ((uint)pbStack_bc[1] << 8 | (uint)pbStack_bc[2] << 0x10 | (uint)*pbStack_bc |
                  (uint)pbStack_bc[3] << 0x18);
        pbStack_bc = pbStack_bc + 8;
        pDStack_b8 = pDVar21;
        p_Stack_b4 = p_Stack_c0;
        pDStack_9c = pDVar26;
        pDStack_98 = pDVar32;
        DES_decrypt3((uint *)&pDStack_9c,ks1,pDVar25,pDStack_54);
        uVar6 = uVar6 - 8;
        uVar7 = (uint)pDStack_b8 ^ (uint)pDStack_9c;
        uVar10 = (uint)pDStack_98 ^ (uint)pDVar33;
        p_Stack_c0[-1].cblock[0] = (uchar)uVar7;
        *(char *)((int)p_Stack_c0 + -4) = (char)uVar10;
        *(char *)((int)p_Stack_c0 + -7) = (char)(uVar7 >> 8);
        pDVar27 = (DES_key_schedule *)(uVar10 >> 0x10);
        *(char *)((int)p_Stack_c0 + -6) = (char)(uVar7 >> 0x10);
        *(char *)((int)p_Stack_c0 + -3) = (char)(uVar10 >> 8);
        *(char *)((int)p_Stack_c0 + -5) = (char)(uVar7 >> 0x18);
        *(char *)((int)p_Stack_c0 + -2) = (char)(uVar10 >> 0x10);
        *(char *)((int)p_Stack_c0 + -1) = (char)(uVar10 >> 0x18);
        pDVar21 = pDVar26;
        pDVar33 = pDVar32;
      } while (-1 < (int)uVar6);
      iVar5 = (uStack_a4 >> 3) + 1;
      uVar6 = (uStack_60 - 0x10) - (uStack_a4 & 0xfffffff8);
      pbStack_b0 = pbStack_b0 + iVar5 * 8;
      p_Stack_ac = p_Stack_ac + iVar5;
      unaff_s4 = &pDStack_9c;
    }
    if (uVar6 != 0xfffffff8) {
      pDVar30 = (DES_key_schedule *)
                ((uint)pbStack_b0[1] << 8 | (uint)pbStack_b0[2] << 0x10 | (uint)*pbStack_b0 |
                (uint)pbStack_b0[3] << 0x18);
      pDVar29 = (DES_key_schedule *)
                ((uint)pbStack_b0[5] << 8 | (uint)pbStack_b0[6] << 0x10 | (uint)pbStack_b0[4] |
                (uint)pbStack_b0[7] << 0x18);
      pDStack_9c = pDVar30;
      pDStack_98 = pDVar29;
      DES_decrypt3((uint *)&pDStack_9c,ks1,pDVar25,pDStack_54);
      puVar18 = p_Stack_ac->cblock + uVar6 + 8;
      uVar10 = (uint)pDVar26 ^ (uint)pDStack_9c;
      uVar7 = (uint)pDStack_98 ^ (uint)pDVar32;
      pDVar27 = pDVar25;
      pDVar26 = pDVar30;
      pDVar32 = pDVar29;
      if (7 < uVar6 + 8) goto LAB_004e0454;
      puVar34 = puVar18;
      switch(uVar6) {
      case 0xfffffff9:
        goto LAB_004e0448;
      case 0xfffffffa:
        goto switchD_004e0410_caseD_fffffffa;
      case 0xfffffffb:
        goto LAB_004e0430;
      case 0xfffffffd:
        puVar34 = puVar18 + -1;
        puVar18[-1] = (uchar)uVar7;
        break;
      case 0xffffffff:
        puVar18 = puVar18 + -1;
        *puVar18 = (uchar)(uVar7 >> 0x10);
      case 0xfffffffe:
        puVar18[-1] = (uchar)(uVar7 >> 8);
        puVar34 = puVar18 + -2;
        puVar18[-2] = (uchar)uVar7;
      }
      puVar18 = puVar34 + -1;
      puVar34[-1] = (uchar)(uVar10 >> 0x18);
LAB_004e0430:
      puVar34 = puVar18 + -1;
      puVar18[-1] = (uchar)(uVar10 >> 0x10);
switchD_004e0410_caseD_fffffffa:
      puVar18 = puVar34 + -1;
      puVar34[-1] = (uchar)(uVar10 >> 8);
LAB_004e0448:
      puVar18[-1] = (uchar)uVar10;
    }
LAB_004e0454:
    pDStack_50->ks[0].cblock[0] = (uchar)pDVar26;
    pDStack_50->ks[0].cblock[4] = (uchar)pDVar32;
    puVar18 = (uchar *)((uint)pDVar32 >> 8);
    pDStack_50->ks[0].cblock[1] = (uchar)((uint)pDVar26 >> 8);
    pDStack_50->ks[0].cblock[2] = (uchar)((uint)pDVar26 >> 0x10);
    pcVar16 = (char *)((uint)pDVar32 >> 0x18);
    pDStack_50->ks[0].cblock[3] = (uchar)((uint)pDVar26 >> 0x18);
    pDStack_50->ks[0].cblock[5] = (uchar)((uint)pDVar32 >> 8);
    pDStack_50->ks[0].cblock[6] = (uchar)((uint)pDVar32 >> 0x10);
    pDStack_50->ks[0].cblock[7] = (uchar)((uint)pDVar32 >> 0x18);
    goto LAB_004e048c;
  }
  uVar6 = uStack_60 - 8;
  pDVar27 = (DES_key_schedule *)
            ((uint)pDStack_50->ks[0].cblock[3] << 0x18 |
            (uint)pDStack_50->ks[0].cblock[1] << 8 | (uint)pDStack_50->ks[0].cblock[2] << 0x10 |
            (uint)pDStack_50->ks[0].cblock[0]);
  pDVar26 = (DES_key_schedule *)
            ((uint)pDStack_50->ks[0].cblock[7] << 0x18 |
            (uint)pDStack_50->ks[0].cblock[5] << 8 | (uint)pDStack_50->ks[0].cblock[6] << 0x10 |
            (uint)pDStack_50->ks[0].cblock[4]);
  uStack_a4 = uVar6;
  if (-1 < (int)uVar6) {
    pDStack_98 = pDVar26;
    pDStack_9c = pDVar27;
    pbVar28 = pbStack_b0;
    p_Var35 = p_Stack_ac;
    do {
      uVar6 = uVar6 - 8;
      pDStack_98 = (DES_key_schedule *)
                   (((uint)pbVar28[7] << 0x18 |
                    (uint)pbVar28[5] << 8 | (uint)pbVar28[6] << 0x10 | (uint)pbVar28[4]) ^
                   (uint)pDStack_98);
      pDStack_9c = (DES_key_schedule *)
                   ((uint)pDStack_9c ^
                   ((uint)pbVar28[3] << 0x18 |
                   (uint)pbVar28[1] << 8 | (uint)pbVar28[2] << 0x10 | (uint)*pbVar28));
      DES_encrypt3((uint *)&pDStack_9c,ks1,pDVar25,pDStack_54);
      p_Var35->cblock[0] = (uchar)pDStack_9c;
      p_Var35->cblock[4] = (uchar)pDStack_98;
      p_Var35->cblock[1] = (uchar)((uint)pDStack_9c >> 8);
      p_Var35->cblock[2] = (uchar)((uint)pDStack_9c >> 0x10);
      p_Var35->cblock[3] = (uchar)((uint)pDStack_9c >> 0x18);
      p_Var35->cblock[5] = (uchar)((uint)pDStack_98 >> 8);
      p_Var35->cblock[6] = (uchar)((uint)pDStack_98 >> 0x10);
      p_Var35->cblock[7] = (uchar)((uint)pDStack_98 >> 0x18);
      pbVar28 = pbVar28 + 8;
      p_Var35 = p_Var35 + 1;
    } while (-1 < (int)uVar6);
    iVar5 = (uStack_a4 >> 3) + 1;
    uVar6 = (uStack_60 - 0x10) - (uStack_a4 & 0xfffffff8);
    pbStack_b0 = pbStack_b0 + iVar5 * 8;
    p_Stack_ac = p_Stack_ac + iVar5;
    pDVar26 = pDStack_98;
    pDVar27 = pDStack_9c;
    unaff_s4 = &pDStack_9c;
  }
  if (uVar6 == 0xfffffff8) {
    uVar19 = (uchar)((uint)pDVar27 >> 8);
    uVar15 = (uchar)((uint)pDVar27 >> 0x10);
    uVar9 = (uchar)((uint)pDVar27 >> 0x18);
    uVar20 = (uchar)((uint)pDVar26 >> 0x18);
    pcVar16 = (char *)((uint)pDVar27 & 0xff);
    uVar8 = (uchar)pDVar26;
  }
  else {
    unaff_s4 = (DES_key_schedule **)(pbStack_b0 + uVar6 + 8);
    switch(uVar6) {
    default:
      uVar10 = 0;
      uVar6 = 0;
      goto LAB_004e056c;
    case 0xfffffff9:
      uVar10 = 0;
      uVar6 = 0;
      goto LAB_004e0564;
    case 0xfffffffa:
      uVar10 = 0;
      uVar6 = 0;
      goto LAB_004e0554;
    case 0xfffffffb:
      uVar10 = 0;
      uVar6 = 0;
      goto LAB_004e0544;
    case 0xfffffffc:
      uVar10 = 0;
      goto LAB_004e0538;
    case 0xfffffffd:
      uVar10 = 0;
      goto LAB_004e052c;
    case 0xfffffffe:
      uVar10 = 0;
      break;
    case 0xffffffff:
      pbVar28 = (byte *)((int)unaff_s4 + -1);
      unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
      uVar10 = (uint)*pbVar28 << 0x10;
    }
    pbVar28 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar10 = (uint)*pbVar28 << 8 | uVar10;
LAB_004e052c:
    pbVar28 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar10 = *pbVar28 | uVar10;
LAB_004e0538:
    pbVar28 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar6 = (uint)*pbVar28 << 0x18;
LAB_004e0544:
    pbVar28 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar6 = (uint)*pbVar28 << 0x10 | uVar6;
LAB_004e0554:
    pbVar28 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar6 = (uint)*pbVar28 << 8 | uVar6;
LAB_004e0564:
    uVar6 = *(byte *)((int)unaff_s4 + -1) | uVar6;
LAB_004e056c:
    pDStack_9c = (DES_key_schedule *)(uVar6 ^ (uint)pDVar27);
    pDStack_98 = (DES_key_schedule *)(uVar10 ^ (uint)pDVar26);
    DES_encrypt3((uint *)&pDStack_9c,ks1,pDVar25,pDStack_54);
    uVar19 = (uchar)((uint)pDStack_9c >> 8);
    uVar15 = (uchar)((uint)pDStack_9c >> 0x10);
    p_Stack_ac->cblock[1] = uVar19;
    p_Stack_ac->cblock[2] = uVar15;
    uVar9 = (uchar)((uint)pDStack_9c >> 0x18);
    p_Stack_ac->cblock[3] = uVar9;
    pcVar16 = (char *)((uint)pDStack_9c & 0xff);
    p_Stack_ac->cblock[5] = (uchar)((uint)pDStack_98 >> 8);
    uVar8 = (uchar)pDStack_98;
    p_Stack_ac->cblock[6] = (uchar)((uint)pDStack_98 >> 0x10);
    p_Stack_ac->cblock[0] = (uchar)pcVar16;
    p_Stack_ac->cblock[4] = uVar8;
    uVar20 = (uchar)((uint)pDStack_98 >> 0x18);
    p_Stack_ac->cblock[7] = uVar20;
    pDVar26 = pDStack_98;
  }
  pDVar27 = (DES_key_schedule *)((uint)((int)pDVar26 << 0x10) >> 0x18);
  puVar18 = (uchar *)((uint)((int)pDVar26 << 8) >> 0x18);
  pDStack_50->ks[0].cblock[0] = (uchar)pcVar16;
  pDStack_50->ks[0].cblock[1] = uVar19;
  pDStack_50->ks[0].cblock[2] = uVar15;
  pDStack_50->ks[0].cblock[3] = uVar9;
  pDStack_50->ks[0].cblock[4] = uVar8;
  pDStack_50->ks[0].cblock[5] = (uchar)((uint)pDVar26 >> 8);
  pDStack_50->ks[0].cblock[6] = (uchar)((uint)pDVar26 >> 0x10);
  pDStack_50->ks[0].cblock[7] = uVar20;
LAB_004e048c:
  if (iStack_94 == *piStack_a8) {
    return;
  }
  pcVar39 = (code *)0x4e0684;
  (**(code **)(puStack_c8 + -0x5328))();
  puVar37 = auStack_d8;
DES_fcrypt:
  pDVar25 = pDVar27;
  puVar4 = PTR___stack_chk_guard_006aabf0;
  *(DES_key_schedule **)(puVar37 + -0x14) = ks1;
  *(DES_key_schedule **)(puVar37 + -0x18) = pDStack_50;
  *(code **)(puVar37 + -4) = pcVar39;
  *(DES_key_schedule ***)(puVar37 + -8) = unaff_s4;
  *(DES_key_schedule **)(puVar37 + -0xc) = pDVar30;
  *(DES_key_schedule **)(puVar37 + -0x10) = pDVar29;
  *(undefined **)(puVar37 + -0xc0) = &_gp;
  uVar19 = *puVar18;
  *(undefined4 *)(puVar37 + -0x1c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0;
  pDVar30 = (DES_key_schedule *)&DAT_00000030;
  if ((char)uVar19 == 0) {
    uVar19 = 'A';
  }
  else {
    pDVar30 = (DES_key_schedule *)((uint)(byte)(&con_salt)[(char)uVar19] << 2);
  }
  pDVar25->ks[0].cblock[0] = uVar19;
  uVar19 = puVar18[1];
  unaff_s4 = (DES_key_schedule **)0x300;
  if ((char)uVar19 == 0) {
    uVar19 = 'A';
  }
  else {
    unaff_s4 = (DES_key_schedule **)((uint)(byte)(&con_salt)[(char)uVar19] << 6);
  }
  pDVar25->ks[0].cblock[1] = uVar19;
  if (*pcVar16 == '\0') {
    iVar5 = 0;
  }
  else {
    cVar1 = pcVar16[1];
    puVar37[-0x30] = *pcVar16 << 1;
    if (cVar1 == '\0') {
      iVar5 = 1;
    }
    else {
      cVar2 = pcVar16[2];
      puVar37[-0x2f] = cVar1 << 1;
      if (cVar2 == '\0') {
        iVar5 = 2;
      }
      else {
        cVar1 = pcVar16[3];
        puVar37[-0x2e] = cVar2 << 1;
        if (cVar1 == '\0') {
          iVar5 = 3;
        }
        else {
          cVar2 = pcVar16[4];
          puVar37[-0x2d] = cVar1 << 1;
          if (cVar2 == '\0') {
            iVar5 = 4;
          }
          else {
            cVar1 = pcVar16[5];
            puVar37[-0x2c] = cVar2 << 1;
            if (cVar1 == '\0') {
              iVar5 = 5;
            }
            else {
              cVar2 = pcVar16[6];
              puVar37[-0x2b] = cVar1 << 1;
              if (cVar2 == '\0') {
                iVar5 = 6;
              }
              else {
                cVar1 = pcVar16[7];
                puVar37[-0x2a] = cVar2 << 1;
                if (cVar1 != '\0') {
                  puVar37[-0x29] = cVar1 << 1;
                  goto LAB_004e0794;
                }
                iVar5 = 7;
              }
            }
          }
        }
      }
    }
  }
  (*(code *)PTR_memset_006aab00)(puVar37 + iVar5 + -0x30,0,8 - iVar5);
LAB_004e0794:
  pDVar29 = (DES_key_schedule *)(puVar37 + -0xb0);
  DES_set_key_unchecked((const_DES_cblock *)(puVar37 + -0x30),pDVar29);
  (**(code **)(*(int *)(puVar37 + -0xc0) + -0x68f4))(puVar37 + -0xb8,pDVar29,pDVar30,unaff_s4);
  uVar10 = *(uint *)(puVar37 + -0xb8);
  puVar18 = (uchar *)((int)pDVar25->ks + 2);
  uVar11 = *(undefined4 *)(puVar37 + -0xb4);
  iVar36 = *(int *)(puVar37 + -0xc0);
  puVar37[-0x20] = 0;
  puVar37[-0x24] = (char)uVar11;
  puVar37[-0x26] = (char)(uVar10 >> 0x10);
  puVar37[-0x27] = (char)(uVar10 >> 8);
  puVar37[-0x23] = (char)((uint)uVar11 >> 8);
  uVar7 = uVar10 & 0xff;
  puVar37[-0x21] = (char)((uint)uVar11 >> 0x18);
  puVar37[-0x25] = (char)(uVar10 >> 0x18);
  uVar6 = 0x40;
  puVar37[-0x22] = (char)((uint)uVar11 >> 0x10);
  puVar37[-0x28] = (char)uVar7;
  iVar5 = 0;
  uVar10 = (uint)((uVar10 & 0x80) != 0);
LAB_004e0910:
  uVar10 = uVar10 << 1;
  iVar12 = iVar5;
  if ((uVar6 & uVar7) != 0) {
    uVar6 = uVar6 >> 1;
    goto LAB_004e0a84;
  }
  uVar6 = uVar6 >> 1;
  if (uVar6 != 0) goto LAB_004e0a8c;
LAB_004e092c:
  iVar13 = iVar12 + 1;
  uVar7 = uVar10 << 1;
  puVar24 = puVar37 + iVar12 + -0x17;
  if ((puVar24[-0x10] & 0x80) != 0) {
    uVar17 = 0x40;
    goto LAB_004e0a38;
  }
  uVar7 = uVar10 << 2;
  uVar6 = 0x20;
  if ((puVar24[-0x10] & 0x40) == 0) goto LAB_004e0964;
LAB_004e0a64:
  uVar7 = uVar7 | 1;
  if (uVar6 != 0) goto LAB_004e0a6c;
LAB_004e096c:
  iVar5 = iVar13 + 1;
  uVar10 = uVar7 << 1;
  puVar24 = puVar37 + iVar13 + -0x17;
  if ((puVar24[-0x10] & 0x80) != 0) {
    uVar17 = 0x40;
    goto LAB_004e0a04;
  }
  uVar10 = uVar7 << 2;
  uVar22 = 0x20;
  if ((puVar24[-0x10] & 0x40) == 0) goto LAB_004e09a8;
LAB_004e0a28:
  uVar10 = uVar10 | 1;
LAB_004e09a8:
  if (uVar22 != 0) goto LAB_004e08e0;
  iVar5 = iVar5 + 1;
  uVar22 = 0x80;
  *puVar18 = cov_2char[uVar10];
  do {
    puVar18 = puVar18 + 1;
    if (puVar18 == (uchar *)((int)pDVar25->ks + 0xd)) {
      pcVar16 = *(char **)(puVar37 + -0x1c);
      pcVar14 = *(char **)puVar4;
      *(undefined *)((int)pDVar25->ks + 0xd) = 0;
      if (pcVar16 == pcVar14) {
        return;
      }
      pcVar39 = DES_crypt;
      (**(code **)(iVar36 + -0x5328))();
      pDVar27 = (DES_key_schedule *)buff_6268;
      pDStack_50 = pDVar25;
      ks1 = (DES_key_schedule *)puVar4;
      puVar37 = puVar37 + -0xd0;
      goto DES_fcrypt;
    }
    uVar6 = (uVar22 << 0x17) >> 0x18;
    uVar7 = (uint)(byte)puVar37[iVar5 + -0x28];
    uVar10 = (uint)((uVar22 & uVar7) != 0);
    if (uVar6 != 0) goto LAB_004e0910;
    iVar12 = iVar5 + 1;
    uVar10 = uVar10 << 1;
    puVar24 = puVar37 + iVar5 + -0x17;
    bVar3 = puVar24[-0x10];
    if ((bVar3 & 0x80) == 0) {
      uVar17 = 0x20;
      uVar6 = 0x40;
    }
    else {
      uVar6 = 0x40;
LAB_004e0a84:
      uVar10 = uVar10 | 1;
      if (uVar6 == 0) goto LAB_004e092c;
LAB_004e0a8c:
      puVar24 = puVar37 + iVar12 + -0x18;
      uVar17 = (uVar6 << 0x17) >> 0x18;
      bVar3 = puVar24[-0x10];
    }
    uVar7 = uVar10 << 1;
    iVar13 = iVar12;
    if ((uVar6 & bVar3) == 0) {
      if (uVar17 == 0) goto LAB_004e087c;
LAB_004e0a44:
      uVar7 = uVar7 << 1;
      uVar6 = uVar17 >> 1;
      if ((uVar17 & (byte)puVar24[-0x10]) != 0) goto LAB_004e0a64;
LAB_004e0964:
      if (uVar6 == 0) goto LAB_004e096c;
LAB_004e0a6c:
      bVar3 = puVar24[-0x10];
      uVar17 = uVar6 >> 1;
    }
    else {
LAB_004e0a38:
      uVar7 = uVar7 | 1;
      if (uVar17 != 0) goto LAB_004e0a44;
LAB_004e087c:
      uVar7 = uVar7 << 1;
      puVar24 = puVar37 + iVar13 + -0x17;
      bVar3 = puVar24[-0x10];
      if ((bVar3 & 0x80) != 0) {
        uVar6 = 0x40;
        iVar13 = iVar13 + 1;
        goto LAB_004e0a64;
      }
      uVar17 = 0x20;
      uVar6 = 0x40;
      iVar13 = iVar13 + 1;
    }
    uVar10 = uVar7 << 1;
    iVar5 = iVar13;
    if ((uVar6 & bVar3) != 0) {
LAB_004e0a04:
      uVar10 = uVar10 | 1;
    }
    if (uVar17 != 0) {
      uVar10 = uVar10 << 1;
      uVar22 = uVar17 >> 1;
      if ((uVar17 & (byte)puVar24[-0x10]) == 0) goto LAB_004e09a8;
      goto LAB_004e0a28;
    }
    uVar10 = uVar10 << 1;
    if ((puVar37[iVar5 + -0x27] & 0x80) != 0) break;
    uVar22 = 0x40;
    iVar5 = iVar5 + 1;
LAB_004e08e0:
    *puVar18 = cov_2char[uVar10];
  } while( true );
  uVar10 = uVar10 | 1;
  uVar22 = 0x40;
  iVar5 = iVar5 + 1;
  goto LAB_004e09a8;
}

