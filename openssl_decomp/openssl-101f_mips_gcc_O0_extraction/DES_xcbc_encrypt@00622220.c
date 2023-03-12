
void DES_xcbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,const_DES_cblock *inw,const_DES_cblock *outw,int enc)

{
  byte *pbVar1;
  uint **ppuVar2;
  uint *puVar3;
  byte bVar7;
  uint **ppuVar4;
  uint **ppuVar5;
  int iVar6;
  int iVar8;
  byte bVar10;
  byte *pbVar9;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte bVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint *unaff_s6;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  undefined *puVar22;
  uint *puVar23;
  uint uStack_1ec;
  uint uStack_1e8;
  byte abStack_1e4 [4];
  undefined uStack_1e0;
  undefined uStack_1df;
  undefined uStack_1de;
  undefined uStack_1dd;
  int iStack_1dc;
  uint uStack_1d8;
  uint *puStack_1d4;
  byte *pbStack_1d0;
  uint *puStack_1cc;
  undefined *puStack_1c8;
  uint uStack_1c4;
  byte *pbStack_1c0;
  byte *pbStack_1bc;
  uint *puStack_1b8;
  code *pcStack_1b4;
  uint *puStack_1a0;
  uint *puStack_19c;
  uint uStack_194;
  uint uStack_190;
  int iStack_18c;
  undefined *puStack_188;
  undefined *puStack_184;
  byte *pbStack_180;
  uint *puStack_17c;
  undefined *puStack_178;
  byte *pbStack_174;
  byte *pbStack_170;
  uint *puStack_16c;
  uint *puStack_168;
  undefined4 uStack_164;
  uint *puStack_150;
  uint *puStack_14c;
  int iStack_148;
  uint uStack_144;
  uint uStack_140;
  byte *pbStack_13c;
  uint uStack_134;
  uint *puStack_130;
  undefined4 uStack_12c;
  undefined *puStack_118;
  uint *puStack_10c;
  uint uStack_104;
  uint uStack_100;
  byte abStack_fc [4];
  undefined uStack_f8;
  undefined uStack_f7;
  undefined uStack_f6;
  undefined uStack_f5;
  int iStack_f4;
  uint uStack_f0;
  uint *puStack_ec;
  byte *pbStack_e8;
  uint *puStack_e4;
  undefined *puStack_e0;
  uint *puStack_dc;
  byte *pbStack_d8;
  byte *pbStack_d4;
  uint *puStack_d0;
  code *pcStack_cc;
  uint *puStack_b8;
  uint *puStack_b4;
  uint uStack_ac;
  uint uStack_a8;
  int iStack_a4;
  uint uStack_a0;
  DES_cblock *pauStack_9c;
  uint uStack_98;
  uint uStack_94;
  uint uStack_90;
  DES_key_schedule *pDStack_8c;
  uint *puStack_88;
  uint *puStack_84;
  uint *puStack_80;
  undefined4 uStack_7c;
  uint *local_68;
  uint *puStack_64;
  int iStack_60;
  uint *local_5c;
  uint *local_58;
  uchar *local_54;
  uint *local_50;
  byte *local_4c;
  int local_48;
  byte *local_44;
  uint *local_40;
  int *local_3c;
  uint local_34;
  uint local_30;
  int local_2c;
  
  local_68 = (uint *)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_3c = (int *)PTR___stack_chk_guard_006aabf0;
  uStack_a0 = (uint)(*inw)[3] << 0x18 |
              (uint)(*inw)[1] << 8 | (uint)(*inw)[2] << 0x10 | (uint)(*inw)[0];
  uStack_98 = (uint)(*inw)[7] << 0x18 |
              (uint)(*inw)[5] << 8 | (uint)(*inw)[6] << 0x10 | (uint)(*inw)[4];
  uStack_90 = (uint)(*outw)[3] << 0x18 |
              (uint)(*outw)[1] << 8 | (uint)(*outw)[2] << 0x10 | (uint)(*outw)[0];
  uStack_94 = (uint)(*outw)[7] << 0x18 |
              (uint)(*outw)[5] << 8 | (uint)(*outw)[6] << 0x10 | (uint)(*outw)[4];
  local_44 = input;
  local_40 = (uint *)output;
  if (enc != 0) {
    puVar3 = (uint *)(length + -8);
    uVar16 = (uint)(*ivec)[3] << 0x18 |
             (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0];
    uVar15 = (uint)(*ivec)[7] << 0x18 |
             (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4];
    puStack_88 = puVar3;
    local_58 = puVar3;
    if (-1 < (int)puVar3) {
      local_5c = &local_34;
      puVar21 = puVar3;
      puVar19 = (uint *)output;
      puVar20 = (uint *)input;
      do {
        input = (uchar *)(puVar20 + 2);
        output = (uchar *)(puVar19 + 2);
        puVar21 = puVar21 + -2;
        local_34 = uStack_a0 ^
                   ((uint)*(byte *)((int)puVar20 + 3) << 0x18 |
                   (uint)*(byte *)((int)puVar20 + 1) << 8 |
                   (uint)*(byte *)((int)puVar20 + 2) << 0x10 | (uint)*(byte *)puVar20) ^ uVar16;
        local_30 = uStack_98 ^
                   ((uint)*(byte *)((int)puVar20 + 7) << 0x18 |
                   (uint)*(byte *)((int)puVar20 + 5) << 8 |
                   (uint)*(byte *)((int)puVar20 + 6) << 0x10 | (uint)*(byte *)(puVar20 + 1)) ^
                   uVar15;
        (*(code *)local_68[-0x1a3e])(local_5c,schedule,1);
        uVar16 = uStack_90 ^ local_34;
        *(byte *)puVar19 = (byte)uVar16;
        uVar15 = uStack_94 ^ local_30;
        puVar3 = (uint *)(uVar15 >> 8);
        *(byte *)((int)puVar19 + 1) = (byte)(uVar16 >> 8);
        *(byte *)((int)puVar19 + 2) = (byte)(uVar16 >> 0x10);
        *(byte *)(puVar19 + 1) = (byte)uVar15;
        *(byte *)((int)puVar19 + 5) = (byte)(uVar15 >> 8);
        *(byte *)((int)puVar19 + 3) = (byte)(uVar16 >> 0x18);
        *(byte *)((int)puVar19 + 6) = (byte)(uVar15 >> 0x10);
        *(byte *)((int)puVar19 + 7) = (byte)(uVar15 >> 0x18);
        puVar19 = (uint *)output;
        puVar20 = (uint *)input;
      } while (-1 < (int)puVar21);
      iVar8 = (((uint)local_58 >> 3) + 1) * 8;
      puStack_88 = (uint *)((length + -0x10) - ((uint)local_58 & 0xfffffff8));
      local_44 = local_44 + iVar8;
      local_40 = (uint *)((int)local_40 + iVar8);
    }
    if (puStack_88 == (uint *)0xfffffff8) {
      bVar14 = (byte)(uVar16 >> 0x18);
      bVar10 = (byte)(uVar15 >> 8);
      bVar7 = (byte)(uVar15 >> 0x10);
      uStack_90 = uVar16 & 0xff;
      uStack_94 = uVar15 & 0xff;
    }
    else {
      output = local_44 + (int)(puStack_88 + 2);
      switch(puStack_88) {
      default:
        local_30 = 0;
        local_34 = 0;
        goto LAB_0062288c;
      case (uint *)0xfffffff9:
        local_30 = 0;
        local_34 = 0;
        goto LAB_00622884;
      case (uint *)0xfffffffa:
        local_30 = 0;
        local_34 = 0;
        goto LAB_00622874;
      case (uint *)0xfffffffb:
        local_30 = 0;
        local_34 = 0;
        goto LAB_00622864;
      case (uint *)0xfffffffc:
        local_30 = 0;
        goto LAB_00622858;
      case (uint *)0xfffffffd:
        local_30 = 0;
        goto LAB_0062284c;
      case (uint *)0xfffffffe:
        local_30 = 0;
        break;
      case (uint *)0xffffffff:
        pbVar12 = (byte *)((int)output + -1);
        output = (uchar *)((int)output + -1);
        local_30 = (uint)*pbVar12 << 0x10;
      }
      pbVar12 = (byte *)((int)output + -1);
      output = (uchar *)((int)output + -1);
      local_30 = (uint)*pbVar12 << 8 | local_30;
LAB_0062284c:
      pbVar12 = (byte *)((int)output + -1);
      output = (uchar *)((int)output + -1);
      local_30 = *pbVar12 | local_30;
LAB_00622858:
      pbVar12 = (byte *)((int)output + -1);
      output = (uchar *)((int)output + -1);
      local_34 = (uint)*pbVar12 << 0x18;
LAB_00622864:
      pbVar12 = (byte *)((int)output + -1);
      output = (uchar *)((int)output + -1);
      local_34 = (uint)*pbVar12 << 0x10 | local_34;
LAB_00622874:
      pbVar12 = (byte *)((int)output + -1);
      output = (uchar *)((int)output + -1);
      local_34 = (uint)*pbVar12 << 8 | local_34;
LAB_00622884:
      local_34 = *(byte *)((int)output + -1) | local_34;
LAB_0062288c:
      local_34 = uStack_a0 ^ uVar16 ^ local_34;
      local_30 = uStack_98 ^ uVar15 ^ local_30;
      (*(code *)local_68[-0x1a3e])(&local_34,schedule,1);
      uVar16 = uStack_90 ^ local_34;
      uVar15 = uStack_94 ^ local_30;
      *(byte *)((int)local_40 + 1) = (byte)(uVar16 >> 8);
      bVar10 = (byte)(uVar15 >> 8);
      *(byte *)((int)local_40 + 2) = (byte)(uVar16 >> 0x10);
      bVar7 = (byte)(uVar15 >> 0x10);
      bVar14 = (byte)(uVar16 >> 0x18);
      *(byte *)((int)local_40 + 3) = bVar14;
      uStack_90 = uVar16 & 0xff;
      *(byte *)((int)local_40 + 5) = bVar10;
      uStack_94 = uVar15 & 0xff;
      *(byte *)((int)local_40 + 6) = bVar7;
      *(byte *)local_40 = (byte)uStack_90;
      *(byte *)(local_40 + 1) = (byte)uStack_94;
      *(byte *)((int)local_40 + 7) = (byte)(uVar15 >> 0x18);
      puVar3 = local_40;
    }
    pbStack_170 = (byte *)((uVar16 << 0x10) >> 0x18);
    pbStack_e8 = (byte *)(uVar15 >> 0x18);
    (*ivec)[0] = (uchar)uStack_90;
    (*ivec)[1] = (uchar)(uVar16 >> 8);
    (*ivec)[2] = (uchar)(uVar16 >> 0x10);
    (*ivec)[3] = bVar14;
    (*ivec)[4] = (uchar)uStack_94;
    (*ivec)[5] = bVar10;
    (*ivec)[6] = bVar7;
    (*ivec)[7] = (uchar)(uVar15 >> 0x18);
    puVar21 = (uint *)(uVar16 << 8);
    goto LAB_006227ac;
  }
  iVar8 = length + -8;
  puVar3 = (uint *)((uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10);
  pbStack_e8 = (byte *)((uint)(*ivec)[3] << 0x18);
  puVar21 = (uint *)((uint)pbStack_e8 | (uint)puVar3 | (uint)(*ivec)[0]);
  puVar19 = (uint *)((uint)(*ivec)[7] << 0x18 |
                    (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4]);
  if (iVar8 < 1) {
    puStack_88 = unaff_s6;
    puVar20 = puVar19;
    puVar23 = &local_34;
    if (iVar8 != -8) goto LAB_00622698;
    goto switchD_00622764_caseD_0;
  }
  local_5c = &local_34;
  local_58 = (uint *)iVar8;
  puVar3 = puVar19;
  do {
    local_58 = (uint *)((int)local_58 + -8);
    local_54 = output + 8;
    local_4c = input + 8;
    local_50 = (uint *)((uint)input[1] << 8 | (uint)input[2] << 0x10 | (uint)*input |
                       (uint)input[3] << 0x18);
    puVar19 = (uint *)((uint)input[7] << 0x18 |
                      (uint)input[5] << 8 | (uint)input[6] << 0x10 | (uint)input[4]);
    local_34 = uStack_90 ^ (uint)local_50;
    local_30 = uStack_94 ^ (uint)puVar19;
    local_48 = (int)local_58;
    (*(code *)local_68[-0x1a3e])(local_5c,schedule,0);
    uVar16 = uStack_a0 ^ local_34 ^ (uint)puVar21;
    uVar15 = uStack_98 ^ local_30 ^ (uint)puVar3;
    local_54[-8] = (uchar)uVar16;
    local_54[-7] = (uchar)(uVar16 >> 8);
    local_54[-4] = (uchar)uVar15;
    local_54[-6] = (uchar)(uVar16 >> 0x10);
    local_54[-3] = (uchar)(uVar15 >> 8);
    local_54[-2] = (uchar)(uVar15 >> 0x10);
    local_54[-5] = (uchar)(uVar16 >> 0x18);
    local_54[-1] = (uchar)(uVar15 >> 0x18);
    input = local_4c;
    output = local_54;
    puVar3 = puVar19;
    puVar21 = local_50;
  } while (0 < (int)local_58);
  iVar6 = ((length - 9U >> 3) + 1) * 8;
  iVar8 = (length + -0x10) - (length - 9U & 0xfffffff8);
  local_44 = local_44 + iVar6;
  local_40 = (uint *)((int)local_40 + iVar6);
  puVar23 = local_5c;
LAB_00622698:
  local_5c = puVar23;
  puVar3 = (uint *)0x0;
  pbStack_e8 = (byte *)((uint)local_44[5] << 8 | (uint)local_44[6] << 0x10);
  puVar20 = (uint *)((uint)pbStack_e8 | (uint)local_44[4] | (uint)local_44[7] << 0x18);
  puVar23 = (uint *)((uint)local_44[1] << 8 | (uint)local_44[2] << 0x10 | (uint)*local_44 |
                    (uint)local_44[3] << 0x18);
  uStack_90 = uStack_90 ^ (uint)puVar23;
  uStack_94 = uStack_94 ^ (uint)puVar20;
  local_58 = puVar21;
  local_54 = (uchar *)iVar8;
  local_34 = uStack_90;
  local_30 = uStack_94;
  (*(code *)local_68[-0x1a3e])(local_5c,schedule);
  uStack_a0 = uStack_a0 ^ local_34;
  pbVar11 = (byte *)((int)local_40 + (int)local_54 + 8);
  uStack_98 = uStack_98 ^ local_30;
  uVar15 = uStack_a0 ^ (uint)local_58;
  uVar16 = uStack_98 ^ (uint)puVar19;
  pbVar12 = pbVar11;
  puStack_88 = puVar19;
  puVar21 = puVar23;
  switch((int)local_54 + 8) {
  default:
    goto switchD_00622764_caseD_0;
  case 1:
    pbVar11[-1] = (byte)uVar15;
    goto switchD_00622764_caseD_0;
  case 2:
    goto switchD_00622764_caseD_2;
  case 3:
    goto LAB_00622968;
  case 4:
    break;
  case 5:
    pbVar12 = pbVar11 + -1;
    pbVar11[-1] = (byte)uVar16;
    break;
  case 6:
    goto switchD_00622764_caseD_6;
  case 7:
    goto switchD_00622764_caseD_7;
  case 8:
    pbVar11 = pbVar11 + -1;
    *pbVar11 = (byte)(uVar16 >> 0x18);
switchD_00622764_caseD_7:
    pbVar11 = pbVar11 + -1;
    *pbVar11 = (byte)(uVar16 >> 0x10);
switchD_00622764_caseD_6:
    pbVar11[-1] = (byte)(uVar16 >> 8);
    pbVar12 = pbVar11 + -2;
    pbVar11[-2] = (byte)uVar16;
  }
  pbVar11 = pbVar12 + -1;
  pbVar12[-1] = (byte)(uVar15 >> 0x18);
LAB_00622968:
  pbVar12 = pbVar11 + -1;
  pbVar11[-1] = (byte)(uVar15 >> 0x10);
switchD_00622764_caseD_2:
  pbVar12[-1] = (byte)(uVar15 >> 8);
  pbVar12[-2] = (byte)uVar15;
switchD_00622764_caseD_0:
  input = (uchar *)puVar21;
  output = (uchar *)puVar20;
  (*ivec)[0] = (uchar)input;
  (*ivec)[4] = (uchar)output;
  pbStack_170 = (byte *)((uint)output >> 8);
  (*ivec)[1] = (uchar)((uint)input >> 8);
  (*ivec)[2] = (uchar)((uint)input >> 0x10);
  (*ivec)[3] = (uchar)((uint)input >> 0x18);
  (*ivec)[5] = (uchar)((uint)output >> 8);
  (*ivec)[6] = (uchar)((uint)output >> 0x10);
  (*ivec)[7] = (uchar)((uint)output >> 0x18);
  puVar21 = (uint *)input;
LAB_006227ac:
  pbStack_174 = (byte *)((uint)puVar21 >> 0x18);
  if (local_2c == *local_3c) {
    return;
  }
  uStack_7c = 0x6229f4;
  (*(code *)local_68[-0x14ca])();
  puStack_130 = local_68;
  puStack_e0 = PTR___stack_chk_guard_006aabf0;
  puVar21 = (uint *)&_gp;
  pauStack_9c = ivec;
  puStack_b8 = (uint *)&_gp;
  iStack_a4 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_f0 = *puStack_64;
  pbStack_180 = pbStack_e8;
  puStack_dc = puVar3;
  pbStack_d8 = pbStack_174;
  pbStack_d4 = pbStack_170;
  pDStack_8c = schedule;
  puStack_84 = (uint *)output;
  puStack_80 = (uint *)input;
  if (iStack_60 == 0) {
    for (; puStack_168 = &uStack_ac, puStack_dc != (uint *)0x0;
        puStack_dc = (uint *)((int)puStack_dc + -1)) {
      pbStack_170 = pbStack_e8;
      if (uStack_f0 == 0) {
        uStack_ac = *puStack_130;
        uStack_a8 = puStack_130[1];
        (**(code **)((int)puVar21 + -0x68d4))(&uStack_ac);
        puVar3 = (uint *)(uStack_ac >> 0x10);
        *(byte *)((int)puStack_130 + 3) = (byte)uStack_ac;
        pbStack_170 = (byte *)(uStack_a8 >> 0x18);
        *(byte *)((int)puStack_130 + 7) = (byte)uStack_a8;
        *(byte *)puStack_130 = (byte)(uStack_ac >> 0x18);
        *(byte *)((int)puStack_130 + 1) = (byte)(uStack_ac >> 0x10);
        *(byte *)(puStack_130 + 1) = (byte)(uStack_a8 >> 0x18);
        *(byte *)((int)puStack_130 + 2) = (byte)(uStack_ac >> 8);
        *(byte *)((int)puStack_130 + 5) = (byte)(uStack_a8 >> 0x10);
        *(byte *)((int)puStack_130 + 6) = (byte)(uStack_a8 >> 8);
        puVar21 = puStack_b8;
      }
      bVar10 = *pbStack_d8;
      bVar7 = *(byte *)((int)puStack_130 + uStack_f0);
      pbStack_174 = (byte *)(uint)bVar7;
      *(byte *)((int)puStack_130 + uStack_f0) = bVar10;
      pbStack_d8 = pbStack_d8 + 1;
      uStack_f0 = uStack_f0 + 1 & 7;
      *pbStack_d4 = bVar10 ^ bVar7;
      pbStack_d4 = pbStack_d4 + 1;
    }
  }
  else {
    puStack_168 = (uint *)input;
    if (puVar3 != (uint *)0x0) {
      puStack_168 = &uStack_ac;
      pbVar12 = pbStack_170;
      do {
        if (uStack_f0 == 0) {
          uStack_ac = *puStack_130;
          uStack_a8 = puStack_130[1];
          (*(code *)puStack_b8[-0x1a35])(puStack_168,pbStack_e8);
          puVar3 = (uint *)(uStack_ac >> 0x10);
          *(byte *)((int)puStack_130 + 3) = (byte)uStack_ac;
          pbStack_170 = (byte *)(uStack_a8 >> 0x18);
          *(byte *)((int)puStack_130 + 7) = (byte)uStack_a8;
          *(byte *)puStack_130 = (byte)(uStack_ac >> 0x18);
          *(byte *)((int)puStack_130 + 1) = (byte)(uStack_ac >> 0x10);
          *(byte *)(puStack_130 + 1) = (byte)(uStack_a8 >> 0x18);
          *(byte *)((int)puStack_130 + 2) = (byte)(uStack_ac >> 8);
          *(byte *)((int)puStack_130 + 5) = (byte)(uStack_a8 >> 0x10);
          *(byte *)((int)puStack_130 + 6) = (byte)(uStack_a8 >> 8);
        }
        pbVar11 = (byte *)((int)puStack_130 + uStack_f0);
        bVar10 = *pbStack_d8;
        pbStack_d4 = pbVar12 + 1;
        bVar7 = *pbVar11;
        pbStack_174 = (byte *)(uint)bVar7;
        puStack_dc = (uint *)((int)puStack_dc + -1);
        pbStack_d8 = pbStack_d8 + 1;
        uStack_f0 = uStack_f0 + 1 & 7;
        bVar10 = bVar10 ^ bVar7;
        *pbVar12 = bVar10;
        *pbVar11 = bVar10;
        puVar21 = puStack_b8;
        pbVar12 = pbStack_d4;
      } while (puStack_dc != (uint *)0x0);
    }
  }
  iVar8 = *(int *)puStack_e0;
  *puStack_64 = uStack_f0;
  if (iStack_a4 == iVar8) {
    return;
  }
  pcStack_cc = BF_ofb64_encrypt;
  (*(code *)puVar21[-0x14ca])();
  puStack_16c = puStack_b8;
  puStack_178 = PTR___stack_chk_guard_006aabf0;
  puVar22 = &_gp;
  puStack_d0 = puStack_168;
  puStack_e4 = puStack_64;
  puStack_ec = puStack_130;
  puStack_118 = &_gp;
  uStack_104 = *puStack_b8;
  puStack_10c = puStack_b4;
  uStack_100 = puStack_b8[1];
  uStack_134 = *puStack_b4;
  iStack_f4 = *(int *)PTR___stack_chk_guard_006aabf0;
  abStack_fc[3] = (char)uStack_104;
  abStack_fc[0] = (byte)(uStack_104 >> 0x18);
  pbStack_1d0 = (byte *)(uStack_100 >> 0x18);
  abStack_fc[1] = (char)(uStack_104 >> 0x10);
  puStack_188 = (undefined *)(uStack_100 >> 0x10);
  abStack_fc[2] = (char)(uStack_104 >> 8);
  uStack_f8 = (char)(uStack_100 >> 0x18);
  uStack_f7 = (char)(uStack_100 >> 0x10);
  uStack_f6 = (char)(uStack_100 >> 8);
  uStack_f5 = (char)uStack_100;
  if (puVar3 != (uint *)0x0) {
    puStack_168 = (uint *)0x0;
    puStack_64 = &uStack_104;
    puStack_130 = puVar3;
    pbVar12 = pbStack_170;
    do {
      if (uStack_134 == 0) {
        puStack_168 = (uint *)((int)puStack_168 + 1);
        (**(code **)(puVar22 + -0x68d4))(puStack_64,pbStack_180);
        puVar3 = (uint *)(uStack_104 >> 0x10);
        abStack_fc[3] = (char)uStack_104;
        puStack_188 = (undefined *)(uStack_100 >> 0x18);
        uStack_f5 = (char)uStack_100;
        abStack_fc[0] = (byte)(uStack_104 >> 0x18);
        abStack_fc[1] = (char)(uStack_104 >> 0x10);
        uStack_f8 = (char)(uStack_100 >> 0x18);
        abStack_fc[2] = (char)(uStack_104 >> 8);
        uStack_f7 = (char)(uStack_100 >> 0x10);
        uStack_f6 = (char)(uStack_100 >> 8);
        puVar22 = puStack_118;
      }
      pbStack_170 = pbVar12 + 1;
      bVar10 = *pbStack_174;
      puStack_130 = (uint *)((int)puStack_130 + -1);
      pbVar11 = abStack_fc + uStack_134;
      pbStack_174 = pbStack_174 + 1;
      uStack_134 = uStack_134 + 1 & 7;
      *pbVar12 = bVar10 ^ *pbVar11;
      pbVar12 = pbStack_170;
    } while (puStack_130 != (uint *)0x0);
    if (puStack_168 != (uint *)0x0) {
      puVar3 = (uint *)(uStack_104 >> 0x10);
      *(char *)((int)puStack_16c + 3) = (char)uStack_104;
      puStack_188 = (undefined *)(uStack_100 >> 0x18);
      *(char *)((int)puStack_16c + 7) = (char)uStack_100;
      *(char *)puStack_16c = (char)(uStack_104 >> 0x18);
      *(char *)((int)puStack_16c + 1) = (char)(uStack_104 >> 0x10);
      *(char *)(puStack_16c + 1) = (char)(uStack_100 >> 0x18);
      *(char *)((int)puStack_16c + 2) = (char)(uStack_104 >> 8);
      *(char *)((int)puStack_16c + 5) = (char)(uStack_100 >> 0x10);
      *(char *)((int)puStack_16c + 6) = (char)(uStack_100 >> 8);
    }
  }
  iVar8 = *(int *)puStack_178;
  *puStack_10c = uStack_134;
  if (iStack_f4 == iVar8) {
    return;
  }
  uStack_12c = 0x622e08;
  puVar21 = puStack_10c;
  (**(code **)(puVar22 + -0x5328))();
  puStack_184 = PTR___stack_chk_guard_006aabf0;
  puStack_150 = (uint *)&_gp;
  uStack_144 = *puVar21;
  uStack_140 = puVar21[1];
  pbStack_13c = *(byte **)PTR___stack_chk_guard_006aabf0;
  if (pbStack_1d0 == (byte *)0x0) {
    (*(code *)PTR_CAST_decrypt_006aa9d8)(&uStack_144);
  }
  else {
    (*(code *)PTR_CAST_encrypt_006aa9dc)(&uStack_144,puVar3);
  }
  puStack_188[3] = (char)uStack_144;
  puStack_188[7] = (char)uStack_140;
  *puStack_188 = (char)(uStack_144 >> 0x18);
  uVar15 = uStack_140 >> 0x18;
  puStack_188[1] = (char)(uStack_144 >> 0x10);
  pbVar12 = (byte *)(uStack_140 >> 0x10);
  puStack_188[2] = (char)(uStack_144 >> 8);
  puStack_188[4] = (char)(uStack_140 >> 0x18);
  puStack_188[5] = (char)(uStack_140 >> 0x10);
  puStack_188[6] = (char)(uStack_140 >> 8);
  if (pbStack_13c == *(byte **)puStack_184) {
    return;
  }
  uStack_164 = 0x622eec;
  pbVar11 = pbStack_13c;
  (*(code *)puStack_150[-0x14ca])();
  puStack_1d4 = puStack_150;
  puStack_1c8 = PTR___stack_chk_guard_006aabf0;
  puVar3 = (uint *)&_gp;
  puStack_1a0 = (uint *)&_gp;
  iStack_18c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_1d8 = *puStack_14c;
  pbVar13 = pbStack_1d0;
  uStack_1c4 = uVar15;
  pbStack_1c0 = pbVar11;
  pbStack_1bc = pbVar12;
  puStack_17c = puStack_64;
  if (iStack_148 == 0) {
    for (; puStack_1b8 = &uStack_194, uStack_1c4 != 0; uStack_1c4 = uStack_1c4 - 1) {
      pbVar12 = pbStack_1d0;
      if (uStack_1d8 == 0) {
        uStack_194 = *puStack_1d4;
        uStack_190 = puStack_1d4[1];
        (**(code **)((int)puVar3 + -0x5504))(&uStack_194);
        uVar15 = uStack_194 >> 0x10;
        *(char *)((int)puStack_1d4 + 3) = (char)uStack_194;
        pbVar12 = (byte *)(uStack_190 >> 0x18);
        *(char *)((int)puStack_1d4 + 7) = (char)uStack_190;
        *(char *)puStack_1d4 = (char)(uStack_194 >> 0x18);
        *(char *)((int)puStack_1d4 + 1) = (char)(uStack_194 >> 0x10);
        *(char *)(puStack_1d4 + 1) = (char)(uStack_190 >> 0x18);
        *(char *)((int)puStack_1d4 + 2) = (char)(uStack_194 >> 8);
        *(char *)((int)puStack_1d4 + 5) = (char)(uStack_190 >> 0x10);
        *(char *)((int)puStack_1d4 + 6) = (char)(uStack_190 >> 8);
        puVar3 = puStack_1a0;
      }
      bVar10 = *pbStack_1c0;
      bVar7 = *(byte *)((int)puStack_1d4 + uStack_1d8);
      pbVar11 = (byte *)(uint)bVar7;
      *(byte *)((int)puStack_1d4 + uStack_1d8) = bVar10;
      pbStack_1c0 = pbStack_1c0 + 1;
      uStack_1d8 = uStack_1d8 + 1 & 7;
      *pbStack_1bc = bVar10 ^ bVar7;
      pbStack_1bc = pbStack_1bc + 1;
    }
  }
  else {
    puStack_1b8 = puStack_168;
    if (uVar15 != 0) {
      puStack_1b8 = &uStack_194;
      pbVar1 = pbVar12;
      do {
        if (uStack_1d8 == 0) {
          uStack_194 = *puStack_1d4;
          uStack_190 = puStack_1d4[1];
          (*(code *)puStack_1a0[-0x1541])(puStack_1b8,pbStack_1d0);
          uVar15 = uStack_194 >> 0x10;
          *(char *)((int)puStack_1d4 + 3) = (char)uStack_194;
          pbVar12 = (byte *)(uStack_190 >> 0x18);
          *(char *)((int)puStack_1d4 + 7) = (char)uStack_190;
          *(char *)puStack_1d4 = (char)(uStack_194 >> 0x18);
          *(char *)((int)puStack_1d4 + 1) = (char)(uStack_194 >> 0x10);
          *(char *)(puStack_1d4 + 1) = (char)(uStack_190 >> 0x18);
          *(char *)((int)puStack_1d4 + 2) = (char)(uStack_194 >> 8);
          *(char *)((int)puStack_1d4 + 5) = (char)(uStack_190 >> 0x10);
          *(char *)((int)puStack_1d4 + 6) = (char)(uStack_190 >> 8);
        }
        pbVar9 = (byte *)((int)puStack_1d4 + uStack_1d8);
        bVar10 = *pbStack_1c0;
        pbStack_1bc = pbVar1 + 1;
        bVar7 = *pbVar9;
        pbVar11 = (byte *)(uint)bVar7;
        uStack_1c4 = uStack_1c4 - 1;
        pbStack_1c0 = pbStack_1c0 + 1;
        uStack_1d8 = uStack_1d8 + 1 & 7;
        bVar10 = bVar10 ^ bVar7;
        *pbVar1 = bVar10;
        *pbVar9 = bVar10;
        puVar3 = puStack_1a0;
        pbVar1 = pbStack_1bc;
      } while (uStack_1c4 != 0);
    }
  }
  iVar8 = *(int *)puStack_1c8;
  *puStack_14c = uStack_1d8;
  if (iStack_18c == iVar8) {
    return;
  }
  pcStack_1b4 = CAST_ofb64_encrypt;
  (*(code *)puVar3[-0x14ca])();
  puVar3 = puStack_1a0;
  puVar22 = PTR___stack_chk_guard_006aabf0;
  puStack_1cc = puStack_14c;
  uStack_1ec = *puStack_1a0;
  uStack_1e8 = puStack_1a0[1];
  uVar17 = *puStack_19c;
  iStack_1dc = *(int *)PTR___stack_chk_guard_006aabf0;
  abStack_1e4[3] = (char)uStack_1ec;
  abStack_1e4[0] = (byte)(uStack_1ec >> 0x18);
  abStack_1e4[1] = (char)(uStack_1ec >> 0x10);
  uVar16 = uStack_1e8 >> 0x10;
  abStack_1e4[2] = (char)(uStack_1ec >> 8);
  uStack_1e0 = (char)(uStack_1e8 >> 0x18);
  uStack_1df = (char)(uStack_1e8 >> 0x10);
  uStack_1de = (char)(uStack_1e8 >> 8);
  uStack_1dd = (char)uStack_1e8;
  if (uVar15 != 0) {
    iVar8 = 0;
    uVar18 = uVar15;
    do {
      if (uVar17 == 0) {
        iVar8 = iVar8 + 1;
        (*(code *)PTR_CAST_encrypt_006aa9dc)(&uStack_1ec,pbVar13);
        uVar15 = uStack_1ec >> 0x10;
        abStack_1e4[3] = (char)uStack_1ec;
        uVar16 = uStack_1e8 >> 0x18;
        uStack_1dd = (char)uStack_1e8;
        abStack_1e4[0] = (byte)(uStack_1ec >> 0x18);
        abStack_1e4[1] = (char)(uStack_1ec >> 0x10);
        uStack_1e0 = (char)(uStack_1e8 >> 0x18);
        abStack_1e4[2] = (char)(uStack_1ec >> 8);
        uStack_1df = (char)(uStack_1e8 >> 0x10);
        uStack_1de = (char)(uStack_1e8 >> 8);
      }
      bVar10 = *pbVar11;
      uVar18 = uVar18 - 1;
      pbVar1 = abStack_1e4 + uVar17;
      pbVar11 = pbVar11 + 1;
      uVar17 = uVar17 + 1 & 7;
      *pbVar12 = bVar10 ^ *pbVar1;
      pbVar12 = pbVar12 + 1;
    } while (uVar18 != 0);
    if (iVar8 != 0) {
      uVar15 = uStack_1ec >> 0x10;
      *(char *)((int)puVar3 + 3) = (char)uStack_1ec;
      uVar16 = uStack_1e8 >> 0x18;
      *(char *)((int)puVar3 + 7) = (char)uStack_1e8;
      *(char *)puVar3 = (char)(uStack_1ec >> 0x18);
      *(char *)((int)puVar3 + 1) = (char)(uStack_1ec >> 0x10);
      *(char *)(puVar3 + 1) = (char)(uStack_1e8 >> 0x18);
      *(char *)((int)puVar3 + 2) = (char)(uStack_1ec >> 8);
      *(char *)((int)puVar3 + 5) = (char)(uStack_1e8 >> 0x10);
      *(char *)((int)puVar3 + 6) = (char)(uStack_1e8 >> 8);
    }
  }
  iVar8 = *(int *)puVar22;
  *puStack_19c = uVar17;
  if (iStack_1dc == iVar8) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar15);
  ppuVar4 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
  ppuVar5 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
  if (ppuVar5 == (uint **)0x0) {
    (*(code *)PTR_BN_CTX_end_006a9654)(uVar15);
    return;
  }
  iVar8 = (*(code *)PTR_BN_copy_006a9570)(ppuVar4,puStack_19c);
  if (iVar8 == 0) {
LAB_00623404:
    (*(code *)PTR_BN_CTX_end_006a9654)(uVar15);
    return;
  }
  iVar8 = (*(code *)PTR_BN_copy_006a9570)(ppuVar5,uVar16);
  if (iVar8 != 0) {
    if (ppuVar5[1] != (uint *)0x0) {
      if (((int)ppuVar4[1] < 1) || (iVar8 = 0, (**ppuVar4 & 1) == 0)) {
        if (((int)ppuVar5[1] < 1) || ((**ppuVar5 & 1) == 0)) goto LAB_006233cc;
        iVar8 = 0;
      }
      while (iVar6 = (*(code *)PTR_BN_is_bit_set_006a9650)(ppuVar5,iVar8), iVar6 == 0) {
        iVar8 = iVar8 + 1;
      }
      iVar8 = (*(code *)PTR_BN_rshift_006a96f8)(ppuVar5,ppuVar5,iVar8);
      if (iVar8 != 0) {
        puVar3 = ppuVar4[1];
        if (ppuVar5[3] != (uint *)0x0) {
          ppuVar5[3] = (uint *)0x0;
        }
        while (ppuVar2 = ppuVar4, puVar3 != (uint *)0x0) {
          iVar8 = 0;
          while (iVar6 = (*(code *)PTR_BN_is_bit_set_006a9650)(ppuVar2,iVar8), iVar6 == 0) {
            iVar8 = iVar8 + 1;
          }
          iVar8 = (*(code *)PTR_BN_rshift_006a96f8)(ppuVar2,ppuVar2,iVar8);
          if (iVar8 == 0) goto LAB_00623404;
          iVar8 = (*(code *)PTR_BN_nnmod_006a9664)(ppuVar5,ppuVar5,ppuVar2,uVar15);
          if (iVar8 == 0) break;
          puVar3 = ppuVar5[1];
          ppuVar2[3] = (uint *)0x0;
          ppuVar4 = ppuVar5;
          ppuVar5 = ppuVar2;
        }
      }
    }
  }
LAB_006233cc:
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar15);
  return;
}

