
/* WARNING: Could not reconcile some variable overlaps */

void DES_cfb_encrypt(uchar *in,uchar *out,int numbits,long length,DES_key_schedule *schedule,
                    DES_cblock *ivec,int enc)

{
  byte *pbVar1;
  bool bVar2;
  uint3 uVar3;
  uint3 uVar4;
  uchar uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  sbyte sVar11;
  uchar *puVar12;
  uchar *puVar13;
  uchar uVar14;
  byte bVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  int in_GS_OFFSET;
  uchar *local_64;
  uchar *local_60;
  uint local_58;
  byte local_54;
  uint local_4c;
  byte local_48;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_28;
  uchar local_27;
  uchar local_26;
  uchar local_25;
  uchar local_24;
  uchar local_23;
  uchar local_22;
  uchar local_21;
  int local_20;
  uchar uVar15;
  uchar uVar16;
  uchar uVar17;
  uchar uVar18;
  
  local_64 = in;
  local_60 = out;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (numbits - 1U < 0x40) {
    local_4c = length;
    iVar6 = numbits >> 3;
    uVar7 = numbits & 7;
    uVar10 = *(uint *)(*ivec + 4);
    uVar21 = numbits + 7 >> 3;
    local_58 = *(uint *)*ivec;
    sVar11 = (sbyte)uVar7;
    if (enc != 0) {
      local_48 = 8 - sVar11;
      uVar23 = local_58;
LAB_081af8d0:
      local_58 = uVar23;
      uVar22 = uVar10;
      if (uVar21 <= local_4c) {
LAB_081af8da:
        local_4c = local_4c - uVar21;
        local_38 = local_58;
        local_34 = uVar22;
        DES_encrypt1(&local_38,schedule,1);
        puVar12 = local_64 + uVar21;
        switch(uVar21) {
        default:
          uVar20 = 0;
          uVar10 = 0;
          goto LAB_081afd75;
        case 2:
          uVar20 = 0;
          uVar10 = 0;
          goto LAB_081afd69;
        case 3:
          uVar20 = 0;
          uVar10 = 0;
          goto LAB_081afd5d;
        case 4:
          uVar20 = 0;
          goto LAB_081afd53;
        case 5:
          uVar20 = 0;
          puVar13 = puVar12;
          goto LAB_081afd4a;
        case 6:
          uVar20 = 0;
          goto LAB_081afd3e;
        case 7:
          uVar20 = 0;
          break;
        case 8:
          pbVar1 = puVar12 + -1;
          puVar12 = puVar12 + -1;
          uVar20 = (uint)*pbVar1 << 0x18;
        }
        pbVar1 = puVar12 + -1;
        puVar12 = puVar12 + -1;
        uVar20 = (uint)*pbVar1 << 0x10 | uVar20;
LAB_081afd3e:
        uVar20 = uVar20 | (uint)puVar12[-1] << 8;
        puVar13 = puVar12 + -1;
LAB_081afd4a:
        puVar12 = puVar13 + -1;
        uVar20 = uVar20 | puVar13[-1];
LAB_081afd53:
        pbVar1 = puVar12 + -1;
        puVar12 = puVar12 + -1;
        uVar10 = (uint)*pbVar1 << 0x18;
LAB_081afd5d:
        pbVar1 = puVar12 + -1;
        puVar12 = puVar12 + -1;
        uVar10 = uVar10 | (uint)*pbVar1 << 0x10;
LAB_081afd69:
        pbVar1 = puVar12 + -1;
        puVar12 = puVar12 + -1;
        uVar10 = (uint)*pbVar1 << 8 | uVar10;
LAB_081afd75:
        uVar20 = uVar20 ^ local_34;
        local_64 = puVar12 + (uVar21 - 1);
        uVar9 = (uVar10 | puVar12[-1]) ^ local_38;
        local_60 = local_60 + uVar21;
        bVar19 = (byte)uVar9;
        uVar14 = (uchar)(uVar9 >> 8);
        uVar5 = (uchar)(uVar9 >> 0x18);
        uVar15 = (uchar)(uVar9 >> 0x10);
        local_54 = (byte)uVar20;
        uVar16 = (uchar)(uVar20 >> 8);
        uVar17 = (uchar)(uVar20 >> 0x10);
        uVar18 = (uchar)(uVar20 >> 0x18);
        uVar10 = uVar9;
        uVar23 = uVar22;
        switch(uVar21) {
        default:
          local_60[-1] = bVar19;
          local_60 = local_60 + (uVar21 - 1);
          if (numbits != 0x20) goto LAB_081afe19;
          goto LAB_081af8d0;
        case 2:
          goto switchD_081afda0_caseD_2;
        case 3:
          puVar12 = local_60;
          goto LAB_081afdef;
        case 4:
          goto switchD_081afda0_caseD_4;
        case 5:
          puVar12 = local_60;
          goto LAB_081afdd9;
        case 6:
          goto switchD_081afda0_caseD_6;
        case 7:
          goto switchD_081afda0_caseD_7;
        case 8:
          goto switchD_081afda0_caseD_8;
        }
      }
      goto LAB_081af997;
    }
    if (uVar21 <= (uint)length) {
      local_54 = 8 - sVar11;
      uVar23 = uVar10;
      uVar22 = local_58;
      local_4c = length - uVar21;
      do {
        local_38 = uVar22;
        local_34 = uVar23;
        DES_encrypt1(&local_38,schedule,1);
        puVar12 = local_64 + uVar21;
        switch(uVar21) {
        default:
          uVar20 = 0;
          uVar9 = 0;
          goto LAB_081afaa7;
        case 2:
          uVar20 = 0;
          uVar9 = 0;
          puVar13 = puVar12;
          goto LAB_081afa9b;
        case 3:
          uVar20 = 0;
          uVar9 = 0;
          goto LAB_081afa8f;
        case 4:
          uVar20 = 0;
          goto LAB_081afa83;
        case 5:
          uVar20 = 0;
          puVar13 = puVar12;
          goto LAB_081afa7a;
        case 6:
          uVar20 = 0;
          goto LAB_081afa6e;
        case 7:
          uVar20 = 0;
          break;
        case 8:
          pbVar1 = puVar12 + -1;
          puVar12 = puVar12 + -1;
          uVar20 = (uint)*pbVar1 << 0x18;
        }
        pbVar1 = puVar12 + -1;
        puVar12 = puVar12 + -1;
        uVar20 = (uint)*pbVar1 << 0x10 | uVar20;
LAB_081afa6e:
        uVar20 = uVar20 | (uint)puVar12[-1] << 8;
        puVar13 = puVar12 + -1;
LAB_081afa7a:
        puVar12 = puVar13 + -1;
        uVar20 = uVar20 | puVar13[-1];
LAB_081afa83:
        uVar9 = (uint)puVar12[-1] << 0x18;
        puVar12 = puVar12 + -1;
LAB_081afa8f:
        uVar9 = (uint)puVar12[-1] << 0x10 | uVar9;
        puVar13 = puVar12 + -1;
LAB_081afa9b:
        puVar12 = puVar13 + -1;
        uVar9 = uVar9 | (uint)puVar13[-1] << 8;
LAB_081afaa7:
        local_64 = puVar12 + (uVar21 - 1);
        uVar8 = uVar9 | puVar12[-1];
        uVar10 = uVar8;
        local_58 = uVar23;
        if ((numbits != 0x20) && (uVar10 = uVar20, local_58 = uVar8, numbits != 0x40)) {
          local_28 = puVar12[-1];
          local_24 = (uchar)uVar20;
          uVar3 = (uint3)(uVar22 >> 8) & 0xff0000;
          local_30._1_3_ = uVar3 | (uint3)uVar22 >> 8;
          uVar4 = (uint3)(uVar23 >> 8) & 0xff0000;
          local_2c._1_3_ = uVar4 | (uint3)uVar23 >> 8;
          local_27 = (uchar)(uVar9 >> 8);
          local_26 = (uchar)(uVar9 >> 0x10);
          local_25 = (uchar)(uVar9 >> 0x18);
          local_23 = (uchar)(uVar20 >> 8);
          local_22 = (uchar)(uVar20 >> 0x10);
          local_21 = (uchar)(uVar20 >> 0x18);
          if (uVar7 == 0) {
            local_58 = *(uint *)((int)&local_30 + iVar6);
            uVar10 = *(uint *)(&local_28 + iVar6 + -4);
            local_30 = local_58;
            local_2c = uVar10;
          }
          else {
            bVar19 = *(char *)((int)&local_30 + iVar6) << sVar11 |
                     (byte)((int)(uint)*(byte *)((int)&local_30 + iVar6 + 1) >> (local_54 & 0x1f));
            local_30 = CONCAT31(local_30._1_3_,bVar19);
            local_30._0_2_ =
                 CONCAT11(*(char *)((int)&local_30 + iVar6 + 1) << sVar11 |
                          (byte)((int)(uint)*(byte *)((int)&local_30 + iVar6 + 2) >>
                                (local_54 & 0x1f)),bVar19);
            local_30._3_1_ = (undefined)(uVar3 >> 0x10);
            local_30._0_3_ =
                 CONCAT12(*(char *)((int)&local_30 + iVar6 + 2) << sVar11 |
                          (byte)((int)(uint)*(byte *)((int)&local_30 + iVar6 + 3) >>
                                (local_54 & 0x1f)),(undefined2)local_30);
            local_30 = CONCAT13(*(char *)((int)&local_30 + iVar6 + 3) << sVar11 |
                                (byte)((int)(uint)(&local_28)[iVar6 + -4] >> (local_54 & 0x1f)),
                                (undefined3)local_30);
            bVar19 = (&local_28)[iVar6 + -4] << sVar11 |
                     (byte)((int)(uint)(&local_28)[iVar6 + -3] >> (local_54 & 0x1f));
            local_2c = CONCAT31(local_2c._1_3_,bVar19);
            local_2c._0_2_ =
                 CONCAT11((&local_28)[iVar6 + -3] << sVar11 |
                          (byte)((int)(uint)(&local_28)[iVar6 + -2] >> (local_54 & 0x1f)),bVar19);
            local_2c._3_1_ = (undefined)(uVar4 >> 0x10);
            local_2c._0_3_ =
                 CONCAT12((&local_28)[iVar6 + -2] << sVar11 |
                          (byte)((int)(uint)(&local_28)[iVar6 + -1] >> (local_54 & 0x1f)),
                          (undefined2)local_2c);
            local_2c = CONCAT13((byte)((int)(uint)(&local_28)[iVar6] >> (local_54 & 0x1f)) |
                                (&local_28)[iVar6 + -1] << sVar11,(undefined3)local_2c);
            uVar10 = local_2c;
            local_58 = local_30;
          }
        }
        uVar8 = uVar8 ^ local_38;
        uVar20 = uVar20 ^ local_34;
        local_60 = local_60 + uVar21;
        switch(uVar21) {
        default:
          goto LAB_081af970;
        case 2:
          goto switchD_081afc93_caseD_2;
        case 3:
          puVar12 = local_60;
          goto LAB_081af956;
        case 4:
          goto switchD_081afc93_caseD_4;
        case 5:
          puVar12 = local_60;
          break;
        case 8:
          local_60 = local_60 + -1;
          *local_60 = (uchar)(uVar20 >> 0x18);
        case 7:
          local_60 = local_60 + -1;
          *local_60 = (uchar)(uVar20 >> 0x10);
        case 6:
          local_60[-1] = (uchar)(uVar20 >> 8);
          puVar12 = local_60 + -1;
        }
        local_60 = puVar12 + -1;
        puVar12[-1] = (uchar)uVar20;
switchD_081afc93_caseD_4:
        local_60[-1] = (uchar)(uVar8 >> 0x18);
        puVar12 = local_60 + -1;
LAB_081af956:
        local_60 = puVar12 + -1;
        puVar12[-1] = (uchar)(uVar8 >> 0x10);
switchD_081afc93_caseD_2:
        local_60[-1] = (uchar)(uVar8 >> 8);
        local_60 = local_60 + -1;
LAB_081af970:
        local_60[-1] = (uchar)uVar8;
        local_60 = local_60 + (uVar21 - 1);
        bVar2 = uVar21 <= local_4c;
        uVar23 = uVar10;
        uVar22 = local_58;
        local_4c = local_4c - uVar21;
      } while (bVar2);
    }
LAB_081af997:
    (*ivec)[0] = (uchar)local_58;
    (*ivec)[1] = (uchar)(local_58 >> 8);
    (*ivec)[2] = (uchar)(local_58 >> 0x10);
    (*ivec)[3] = (uchar)(local_58 >> 0x18);
    (*ivec)[4] = (uchar)uVar10;
    (*ivec)[5] = (uchar)(uVar10 >> 8);
    (*ivec)[6] = (uchar)(uVar10 >> 0x10);
    (*ivec)[7] = (uchar)(uVar10 >> 0x18);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
switchD_081afda0_caseD_8:
  local_60 = local_60 + -1;
  *local_60 = uVar18;
switchD_081afda0_caseD_7:
  local_60 = local_60 + -1;
  *local_60 = uVar17;
switchD_081afda0_caseD_6:
  local_60[-1] = uVar16;
  puVar12 = local_60 + -1;
LAB_081afdd9:
  local_60 = puVar12 + -1;
  puVar12[-1] = local_54;
switchD_081afda0_caseD_4:
  local_60[-1] = uVar5;
  puVar12 = local_60 + -1;
LAB_081afdef:
  local_60 = puVar12 + -1;
  puVar12[-1] = uVar15;
switchD_081afda0_caseD_2:
  local_60[-1] = uVar14;
  local_60[-2] = bVar19;
  local_60 = local_60 + (uVar21 - 2);
  if (numbits == 0x20) goto LAB_081af8d0;
LAB_081afe19:
  uVar10 = uVar20;
  uVar23 = uVar9;
  if (numbits == 0x40) goto LAB_081af8d0;
  local_28 = bVar19;
  uVar3 = (uint3)(local_58 >> 8) & 0xff0000;
  local_30._1_3_ = uVar3 | (uint3)local_58 >> 8;
  local_24 = local_54;
  uVar4 = (uint3)(uVar22 >> 8) & 0xff0000;
  local_2c._1_3_ = uVar4 | (uint3)uVar22 >> 8;
  local_27 = uVar14;
  local_25 = uVar5;
  local_26 = uVar15;
  local_23 = uVar16;
  local_21 = uVar18;
  local_22 = uVar17;
  if (uVar7 == 0) {
    local_2c = *(uint *)(&local_28 + iVar6 + -4);
    local_30 = *(uint *)((int)&local_30 + iVar6);
  }
  else {
    bVar19 = *(char *)((int)&local_30 + iVar6) << sVar11 |
             (byte)((int)(uint)*(byte *)((int)&local_30 + iVar6 + 1) >> (local_48 & 0x1f));
    local_30 = CONCAT31(local_30._1_3_,bVar19);
    local_30._0_2_ =
         CONCAT11((byte)((int)(uint)*(byte *)((int)&local_30 + iVar6 + 2) >> (local_48 & 0x1f)) |
                  *(char *)((int)&local_30 + iVar6 + 1) << sVar11,bVar19);
    local_30._3_1_ = (undefined)(uVar3 >> 0x10);
    local_30._0_3_ =
         CONCAT12(*(char *)((int)&local_30 + iVar6 + 2) << sVar11 |
                  (byte)((int)(uint)*(byte *)((int)&local_30 + iVar6 + 3) >> (local_48 & 0x1f)),
                  (undefined2)local_30);
    local_30 = CONCAT13((byte)((int)(uint)(&local_28)[iVar6 + -4] >> (local_48 & 0x1f)) |
                        *(char *)((int)&local_30 + iVar6 + 3) << sVar11,(undefined3)local_30);
    bVar19 = (&local_28)[iVar6 + -4] << sVar11 |
             (byte)((int)(uint)(&local_28)[iVar6 + -3] >> (local_48 & 0x1f));
    local_2c = CONCAT31(local_2c._1_3_,bVar19);
    local_2c._0_2_ =
         CONCAT11((byte)((int)(uint)(&local_28)[iVar6 + -2] >> (local_48 & 0x1f)) |
                  (&local_28)[iVar6 + -3] << sVar11,bVar19);
    local_2c._3_1_ = (undefined)(uVar4 >> 0x10);
    local_2c._0_3_ =
         CONCAT12((&local_28)[iVar6 + -2] << sVar11 |
                  (byte)((int)(uint)(&local_28)[iVar6 + -1] >> (local_48 & 0x1f)),
                  (undefined2)local_2c);
    local_2c = CONCAT13((byte)((int)(uint)(&local_28)[iVar6] >> (local_48 & 0x1f)) |
                        (&local_28)[iVar6 + -1] << sVar11,(undefined3)local_2c);
  }
  local_58 = local_30;
  uVar22 = local_2c;
  uVar10 = local_2c;
  if (local_4c < uVar21) goto LAB_081af997;
  goto LAB_081af8da;
}

