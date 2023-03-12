
/* WARNING: Could not reconcile some variable overlaps */

void DES_ede3_cfb_encrypt
               (uchar *in,uchar *out,int numbits,long length,DES_key_schedule *ks1,
               DES_key_schedule *ks2,DES_key_schedule *ks3,DES_cblock *ivec,int enc)

{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  byte bVar11;
  uchar *puVar12;
  uchar uVar13;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int in_GS_OFFSET;
  uint local_7c;
  uchar *local_78;
  uchar local_74;
  uint local_70;
  uchar *local_5c;
  uint local_58;
  uchar *local_54;
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
  uchar uVar7;
  uchar uVar14;
  uchar uVar15;
  uchar uVar16;
  uchar uVar17;
  
  local_78 = out;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (numbits < 0x41) {
    local_7c = *(uint *)*ivec;
    uVar21 = *(uint *)(*ivec + 4);
    uVar8 = numbits + 7;
    uVar19 = uVar8 >> 3;
    if (enc == 0) {
      if (uVar19 <= (uint)length) {
        local_54 = in;
        if (-1 < numbits) {
          uVar8 = numbits;
        }
        puVar9 = (uint *)(((int)uVar8 >> 3) + (int)&local_30);
        bVar3 = (byte)(numbits % 8);
        bVar11 = 8 - bVar3;
        uVar20 = uVar21;
        local_58 = length - uVar19;
        do {
          local_38 = local_7c;
          local_34 = uVar20;
          DES_encrypt3(&local_38,ks1,ks2,ks3);
          local_54 = local_54 + uVar19;
          switch(uVar19) {
          default:
            local_70 = 0;
            uVar18 = 0;
            goto LAB_081b069e;
          case 1:
            local_70 = 0;
            uVar18 = 0;
            goto LAB_081b0695;
          case 2:
            local_70 = 0;
            uVar18 = 0;
            goto LAB_081b0689;
          case 3:
            local_70 = 0;
            uVar18 = 0;
            goto LAB_081b067d;
          case 4:
            local_70 = 0;
            goto LAB_081b0673;
          case 5:
            local_70 = 0;
            goto LAB_081b0666;
          case 6:
            local_70 = 0;
            goto LAB_081b0656;
          case 7:
            local_70 = 0;
            break;
          case 8:
            pbVar1 = local_54 + -1;
            local_54 = local_54 + -1;
            local_70 = (uint)*pbVar1 << 0x18;
          }
          pbVar1 = local_54 + -1;
          local_54 = local_54 + -1;
          local_70 = (uint)*pbVar1 << 0x10 | local_70;
LAB_081b0656:
          pbVar1 = local_54 + -1;
          local_54 = local_54 + -1;
          local_70 = (uint)*pbVar1 << 8 | local_70;
LAB_081b0666:
          pbVar1 = local_54 + -1;
          local_54 = local_54 + -1;
          local_70 = *pbVar1 | local_70;
LAB_081b0673:
          uVar18 = (uint)local_54[-1] << 0x18;
          local_54 = local_54 + -1;
LAB_081b067d:
          pbVar1 = local_54 + -1;
          local_54 = local_54 + -1;
          uVar18 = (uint)*pbVar1 << 0x10 | uVar18;
LAB_081b0689:
          pbVar1 = local_54 + -1;
          local_54 = local_54 + -1;
          uVar18 = (uint)*pbVar1 << 8 | uVar18;
LAB_081b0695:
          pbVar1 = local_54 + -1;
          local_54 = local_54 + -1;
          uVar18 = *pbVar1 | uVar18;
LAB_081b069e:
          local_54 = local_54 + uVar19;
          uVar21 = uVar18;
          uVar10 = uVar20;
          if ((numbits != 0x20) && (uVar21 = local_70, uVar10 = uVar18, numbits != 0x40)) {
            local_30 = local_7c;
            local_28 = (byte)uVar18;
            local_27 = (uchar)(uVar18 >> 8);
            local_26 = (uchar)(uVar18 >> 0x10);
            local_25 = (uchar)(uVar18 >> 0x18);
            local_24 = (uchar)local_70;
            local_23 = (uchar)(local_70 >> 8);
            local_22 = (uchar)(local_70 >> 0x10);
            local_21 = (uchar)(local_70 >> 0x18);
            if ((numbits & 7U) == 0) {
              local_2c = *(uint *)((int)&local_2c + ((int)uVar8 >> 3));
              local_30 = *puVar9;
            }
            else {
              local_2c = uVar20;
              memmove(&local_30,puVar9,9);
              bVar6 = (byte)(local_30 >> 0x10);
              local_30._0_2_ =
                   CONCAT11(local_30._1_1_ << (bVar3 & 0x1f) |
                            (byte)((int)(uint)bVar6 >> (bVar11 & 0x1f)),
                            (char)local_30 << (bVar3 & 0x1f) |
                            (byte)((int)(uint)local_30._1_1_ >> (bVar11 & 0x1f)));
              bVar4 = (byte)(local_30 >> 0x18);
              local_30._0_3_ =
                   CONCAT12(bVar6 << (bVar3 & 0x1f) | (byte)((int)(uint)bVar4 >> (bVar11 & 0x1f)),
                            (undefined2)local_30);
              local_30 = CONCAT13(bVar4 << (bVar3 & 0x1f) |
                                  (byte)((int)(local_2c & 0xff) >> (bVar11 & 0x1f)),
                                  (undefined3)local_30);
              bVar6 = (byte)(local_2c >> 0x10);
              local_2c._0_2_ =
                   CONCAT11(local_2c._1_1_ << (bVar3 & 0x1f) |
                            (byte)((int)(uint)bVar6 >> (bVar11 & 0x1f)),
                            (char)local_2c << (bVar3 & 0x1f) |
                            (byte)((int)(uint)local_2c._1_1_ >> (bVar11 & 0x1f)));
              bVar4 = (byte)(local_2c >> 0x18);
              local_2c._0_3_ =
                   CONCAT12(bVar6 << (bVar3 & 0x1f) | (byte)((int)(uint)bVar4 >> (bVar11 & 0x1f)),
                            (undefined2)local_2c);
              local_2c = CONCAT13((byte)((int)(uint)local_28 >> (bVar11 & 0x1f)) |
                                  bVar4 << (bVar3 & 0x1f),(undefined3)local_2c);
            }
            local_7c = local_30;
            uVar21 = local_2c;
            uVar10 = local_7c;
          }
          local_7c = uVar10;
          local_70 = local_70 ^ local_34;
          uVar18 = local_38 ^ uVar18;
          local_78 = local_78 + uVar19;
          puVar12 = local_78;
          switch(uVar19) {
          default:
            goto switchD_081b085c_caseD_0;
          case 1:
            goto LAB_081b08be;
          case 2:
            goto switchD_081b085c_caseD_2;
          case 3:
            goto LAB_081b08a4;
          case 4:
            goto switchD_081b085c_caseD_4;
          case 5:
            break;
          case 8:
            local_78 = local_78 + -1;
            *local_78 = (uchar)(local_70 >> 0x18);
          case 7:
            local_78 = local_78 + -1;
            *local_78 = (uchar)(local_70 >> 0x10);
          case 6:
            local_78[-1] = (uchar)(local_70 >> 8);
            local_78 = local_78 + -1;
          }
          puVar12 = local_78 + -1;
          local_78[-1] = (uchar)local_70;
switchD_081b085c_caseD_4:
          local_78 = puVar12 + -1;
          puVar12[-1] = (uchar)(uVar18 >> 0x18);
LAB_081b08a4:
          puVar12 = local_78 + -1;
          local_78[-1] = (uchar)(uVar18 >> 0x10);
switchD_081b085c_caseD_2:
          local_78 = puVar12 + -1;
          puVar12[-1] = (uchar)(uVar18 >> 8);
LAB_081b08be:
          local_74 = (uchar)uVar18;
          puVar12 = local_78 + -1;
          local_78[-1] = local_74;
switchD_081b085c_caseD_0:
          local_78 = puVar12 + uVar19;
          bVar2 = uVar19 <= local_58;
          uVar20 = uVar21;
          local_58 = local_58 - uVar19;
        } while (bVar2);
      }
    }
    else if (uVar19 <= (uint)length) {
      local_5c = in;
      if (-1 < numbits) {
        uVar8 = numbits;
      }
      puVar9 = (uint *)(((int)uVar8 >> 3) + (int)&local_30);
      bVar3 = (byte)(numbits % 8);
      bVar11 = 8 - bVar3;
      uVar20 = uVar21;
      local_70 = length - uVar19;
      do {
        local_38 = local_7c;
        local_34 = uVar20;
        DES_encrypt3(&local_38,ks1,ks2,ks3);
        local_5c = local_5c + uVar19;
        switch(uVar19) {
        default:
          uVar18 = 0;
          uVar10 = 0;
          puVar12 = local_5c;
          goto LAB_081b09e6;
        case 1:
          uVar18 = 0;
          uVar10 = 0;
          goto LAB_081b09dd;
        case 2:
          uVar18 = 0;
          uVar10 = 0;
          goto LAB_081b09d1;
        case 3:
          uVar18 = 0;
          uVar10 = 0;
          goto LAB_081b09c5;
        case 4:
          uVar18 = 0;
          goto LAB_081b09bb;
        case 5:
          uVar18 = 0;
          puVar12 = local_5c;
          goto LAB_081b09b2;
        case 6:
          uVar18 = 0;
          goto LAB_081b09a6;
        case 7:
          uVar18 = 0;
          break;
        case 8:
          pbVar1 = local_5c + -1;
          local_5c = local_5c + -1;
          uVar18 = (uint)*pbVar1 << 0x18;
        }
        pbVar1 = local_5c + -1;
        local_5c = local_5c + -1;
        uVar18 = (uint)*pbVar1 << 0x10 | uVar18;
LAB_081b09a6:
        uVar18 = uVar18 | (uint)local_5c[-1] << 8;
        puVar12 = local_5c + -1;
LAB_081b09b2:
        local_5c = puVar12 + -1;
        uVar18 = uVar18 | puVar12[-1];
LAB_081b09bb:
        pbVar1 = local_5c + -1;
        local_5c = local_5c + -1;
        uVar10 = (uint)*pbVar1 << 0x18;
LAB_081b09c5:
        pbVar1 = local_5c + -1;
        local_5c = local_5c + -1;
        uVar10 = uVar10 | (uint)*pbVar1 << 0x10;
LAB_081b09d1:
        pbVar1 = local_5c + -1;
        local_5c = local_5c + -1;
        uVar10 = (uint)*pbVar1 << 8 | uVar10;
LAB_081b09dd:
        puVar12 = local_5c + -1;
        uVar10 = uVar10 | local_5c[-1];
LAB_081b09e6:
        uVar18 = uVar18 ^ local_34;
        local_5c = puVar12 + uVar19;
        uVar10 = uVar10 ^ local_38;
        local_78 = local_78 + uVar19;
        bVar6 = (byte)uVar10;
        uVar13 = (uchar)(uVar10 >> 8);
        uVar7 = (uchar)(uVar10 >> 0x18);
        uVar14 = (uchar)(uVar10 >> 0x10);
        local_74 = (uchar)uVar18;
        uVar15 = (uchar)(uVar18 >> 8);
        uVar16 = (uchar)(uVar18 >> 0x10);
        uVar17 = (uchar)(uVar18 >> 0x18);
        switch(uVar19) {
        default:
          goto switchD_081b0a07_caseD_0;
        case 1:
          puVar12 = local_78;
          goto LAB_081b038d;
        case 2:
          goto switchD_081b0a07_caseD_2;
        case 3:
          puVar12 = local_78;
          goto LAB_081b0373;
        case 4:
          goto switchD_081b0a07_caseD_4;
        case 5:
          puVar12 = local_78;
          break;
        case 8:
          local_78 = local_78 + -1;
          *local_78 = uVar17;
        case 7:
          local_78 = local_78 + -1;
          *local_78 = uVar16;
        case 6:
          local_78[-1] = uVar15;
          puVar12 = local_78 + -1;
        }
        local_78 = puVar12 + -1;
        puVar12[-1] = local_74;
switchD_081b0a07_caseD_4:
        local_78[-1] = uVar7;
        puVar12 = local_78 + -1;
LAB_081b0373:
        local_78 = puVar12 + -1;
        puVar12[-1] = uVar14;
switchD_081b0a07_caseD_2:
        local_78[-1] = uVar13;
        puVar12 = local_78 + -1;
LAB_081b038d:
        local_78 = puVar12 + -1;
        puVar12[-1] = bVar6;
switchD_081b0a07_caseD_0:
        local_78 = local_78 + uVar19;
        uVar21 = uVar10;
        uVar5 = uVar20;
        if ((numbits != 0x20) && (uVar21 = uVar18, uVar5 = uVar10, numbits != 0x40)) {
          local_30 = local_7c;
          local_28 = bVar6;
          local_27 = uVar13;
          local_26 = uVar14;
          local_25 = uVar7;
          local_24 = local_74;
          local_23 = uVar15;
          local_22 = uVar16;
          local_21 = uVar17;
          if ((numbits & 7U) == 0) {
            local_2c = *(uint *)((int)&local_2c + ((int)uVar8 >> 3));
            local_30 = *puVar9;
          }
          else {
            local_2c = uVar20;
            memmove(&local_30,puVar9,9);
            bVar6 = (byte)(local_30 >> 0x10);
            local_30._0_2_ =
                 CONCAT11(local_30._1_1_ << (bVar3 & 0x1f) |
                          (byte)((int)(uint)bVar6 >> (bVar11 & 0x1f)),
                          (char)local_30 << (bVar3 & 0x1f) |
                          (byte)((int)(uint)local_30._1_1_ >> (bVar11 & 0x1f)));
            bVar4 = (byte)(local_30 >> 0x18);
            local_30._0_3_ =
                 CONCAT12(bVar6 << (bVar3 & 0x1f) | (byte)((int)(uint)bVar4 >> (bVar11 & 0x1f)),
                          (undefined2)local_30);
            local_30 = CONCAT13(bVar4 << (bVar3 & 0x1f) |
                                (byte)((int)(local_2c & 0xff) >> (bVar11 & 0x1f)),
                                (undefined3)local_30);
            bVar6 = (byte)(local_2c >> 0x10);
            local_2c._0_2_ =
                 CONCAT11(local_2c._1_1_ << (bVar3 & 0x1f) |
                          (byte)((int)(uint)bVar6 >> (bVar11 & 0x1f)),
                          (char)local_2c << (bVar3 & 0x1f) |
                          (byte)((int)(uint)local_2c._1_1_ >> (bVar11 & 0x1f)));
            bVar4 = (byte)(local_2c >> 0x18);
            local_2c._0_3_ =
                 CONCAT12(bVar6 << (bVar3 & 0x1f) | (byte)((int)(uint)bVar4 >> (bVar11 & 0x1f)),
                          (undefined2)local_2c);
            local_2c = CONCAT13((byte)((int)(uint)local_28 >> (bVar11 & 0x1f)) |
                                bVar4 << (bVar3 & 0x1f),(undefined3)local_2c);
          }
          local_7c = local_30;
          uVar21 = local_2c;
          uVar5 = local_7c;
        }
        local_7c = uVar5;
        bVar2 = uVar19 <= local_70;
        uVar20 = uVar21;
        local_70 = local_70 - uVar19;
      } while (bVar2);
    }
    (*ivec)[0] = (uchar)local_7c;
    (*ivec)[1] = (uchar)(local_7c >> 8);
    (*ivec)[2] = (uchar)(local_7c >> 0x10);
    (*ivec)[3] = (uchar)(local_7c >> 0x18);
    (*ivec)[4] = (uchar)uVar21;
    (*ivec)[5] = (uchar)(uVar21 >> 8);
    (*ivec)[6] = (uchar)(uVar21 >> 0x10);
    (*ivec)[7] = (uchar)(uVar21 >> 0x18);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

