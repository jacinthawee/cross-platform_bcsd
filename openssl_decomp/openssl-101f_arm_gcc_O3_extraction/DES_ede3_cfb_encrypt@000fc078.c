
void DES_ede3_cfb_encrypt
               (uchar *in,uchar *out,int numbits,long length,DES_key_schedule *ks1,
               DES_key_schedule *ks2,DES_key_schedule *ks3,DES_cblock *ivec,int enc)

{
  bool bVar1;
  byte *pbVar2;
  uchar uVar3;
  uchar uVar5;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  uint uVar16;
  uint uVar17;
  uchar *puVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uchar *local_84;
  uchar *local_7c;
  uint local_48;
  uint local_44;
  byte local_40 [4];
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  byte local_38;
  uchar local_37;
  uchar local_36;
  uchar local_35;
  uchar local_34;
  uchar local_33;
  uchar local_32;
  uchar local_31;
  int local_2c;
  uchar uVar4;
  byte bVar6;
  uchar uVar7;
  uchar uVar8;
  uchar uVar9;
  uchar uVar10;
  
  local_2c = __TMC_END__;
  if (numbits < 0x41) {
    uVar14 = numbits + 7;
    uVar17 = uVar14 >> 3;
    uVar19 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
    uVar20 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
             (uint)(*ivec)[7] << 0x18;
    local_7c = out;
    if (enc == 0) {
      if (uVar17 <= (uint)length) {
        uVar14 = uVar14 & numbits >> 0x20;
        if (uVar17 > (uint)length) {
          uVar14 = numbits;
        }
        pbVar15 = local_40 + ((int)uVar14 >> 3);
        uVar11 = numbits % 8;
        uVar21 = 8 - uVar11;
        uVar14 = uVar19;
        uVar12 = uVar20;
        uVar16 = length - uVar17;
        local_84 = in;
        do {
          local_48 = uVar14;
          local_44 = uVar12;
          DES_encrypt3(&local_48,ks1,ks2,ks3);
          local_84 = local_84 + uVar17;
          switch(uVar17 - 1) {
          case 0:
            uVar22 = 0;
            uVar13 = uVar22;
            goto LAB_000fc25c;
          case 1:
            uVar22 = 0;
            uVar20 = uVar22;
            goto LAB_000fc252;
          case 2:
            uVar22 = 0;
            uVar20 = uVar22;
            goto LAB_000fc248;
          case 3:
            uVar22 = 0;
            goto LAB_000fc240;
          case 4:
            uVar22 = 0;
            goto LAB_000fc238;
          case 5:
            uVar22 = 0;
            goto LAB_000fc22e;
          case 6:
            uVar22 = 0;
            break;
          case 7:
            pbVar2 = local_84 + -1;
            local_84 = local_84 + -1;
            uVar22 = (uint)*pbVar2 << 0x18;
            break;
          default:
            uVar22 = 0;
            uVar13 = uVar22;
            goto LAB_000fc264;
          }
          pbVar2 = local_84 + -1;
          local_84 = local_84 + -1;
          uVar22 = uVar22 | (uint)*pbVar2 << 0x10;
LAB_000fc22e:
          pbVar2 = local_84 + -1;
          local_84 = local_84 + -1;
          uVar22 = uVar22 | (uint)*pbVar2 << 8;
LAB_000fc238:
          pbVar2 = local_84 + -1;
          local_84 = local_84 + -1;
          uVar22 = uVar22 | *pbVar2;
LAB_000fc240:
          pbVar2 = local_84 + -1;
          local_84 = local_84 + -1;
          uVar20 = (uint)*pbVar2 << 0x18;
LAB_000fc248:
          pbVar2 = local_84 + -1;
          local_84 = local_84 + -1;
          uVar20 = uVar20 | (uint)*pbVar2 << 0x10;
LAB_000fc252:
          pbVar2 = local_84 + -1;
          local_84 = local_84 + -1;
          uVar13 = uVar20 | (uint)*pbVar2 << 8;
LAB_000fc25c:
          pbVar2 = local_84 + -1;
          local_84 = local_84 + -1;
          uVar13 = uVar13 | *pbVar2;
LAB_000fc264:
          local_84 = local_84 + uVar17;
          uVar19 = uVar12;
          uVar20 = uVar13;
          if ((numbits != 0x20) && (uVar19 = uVar13, uVar20 = uVar22, numbits != 0x40)) {
            local_40[0] = (byte)uVar14;
            local_40[3] = (byte)(uVar14 >> 0x18);
            local_3c = (byte)uVar12;
            local_40[1] = (byte)(uVar14 >> 8);
            local_40[2] = (byte)(uVar14 >> 0x10);
            local_3b = (byte)(uVar12 >> 8);
            local_3a = (byte)(uVar12 >> 0x10);
            local_37 = (uchar)(uVar13 >> 8);
            local_36 = (uchar)(uVar13 >> 0x10);
            local_35 = (uchar)(uVar13 >> 0x18);
            local_38 = (byte)uVar13;
            local_34 = (uchar)uVar22;
            local_39 = (byte)(uVar12 >> 0x18);
            local_33 = (uchar)(uVar22 >> 8);
            local_32 = (uchar)(uVar22 >> 0x10);
            local_31 = (uchar)(uVar22 >> 0x18);
            if ((numbits & 7U) == 0) {
              memmove(local_40,pbVar15,8);
              uVar26 = (uint)local_40[0];
              uVar24 = (uint)local_40[1];
              uVar23 = (uint)local_40[2];
              uVar19 = (uint)local_40[3];
              uVar20 = (uint)local_3c;
              uVar14 = (uint)local_3b;
              uVar12 = (uint)local_3a;
              uVar25 = (uint)local_39;
            }
            else {
              memmove(local_40,pbVar15,9);
              uVar26 = ((uint)local_40[0] << (uVar11 & 0xff) |
                       (int)(uint)local_40[1] >> (uVar21 & 0xff)) & 0xff;
              local_40[0] = (byte)uVar26;
              uVar24 = ((int)(uint)local_40[2] >> (uVar21 & 0xff) |
                       (uint)local_40[1] << (uVar11 & 0xff)) & 0xff;
              uVar23 = ((int)(uint)local_40[3] >> (uVar21 & 0xff) |
                       (uint)local_40[2] << (uVar11 & 0xff)) & 0xff;
              local_40[1] = (byte)uVar24;
              uVar19 = ((int)(uint)local_3c >> (uVar21 & 0xff) |
                       (uint)local_40[3] << (uVar11 & 0xff)) & 0xff;
              local_40[2] = (byte)uVar23;
              uVar20 = ((int)(uint)local_3b >> (uVar21 & 0xff) | (uint)local_3c << (uVar11 & 0xff))
                       & 0xff;
              local_40[3] = (byte)uVar19;
              uVar14 = ((int)(uint)local_3a >> (uVar21 & 0xff) | (uint)local_3b << (uVar11 & 0xff))
                       & 0xff;
              local_3c = (byte)uVar20;
              uVar12 = ((int)(uint)local_39 >> (uVar21 & 0xff) | (uint)local_3a << (uVar11 & 0xff))
                       & 0xff;
              local_3b = (byte)uVar14;
              uVar25 = ((int)(uint)local_38 >> (uVar21 & 0xff) | (uint)local_39 << (uVar11 & 0xff))
                       & 0xff;
              local_3a = (byte)uVar12;
              local_39 = (byte)uVar25;
            }
            uVar19 = uVar23 << 0x10 | uVar24 << 8 | uVar26 | uVar19 << 0x18;
            uVar20 = uVar20 | uVar12 << 0x10 | uVar14 << 8 | uVar25 << 0x18;
          }
          uVar13 = uVar13 ^ local_48;
          local_7c = local_7c + uVar17;
          uVar22 = uVar22 ^ local_44;
          puVar18 = local_7c;
          switch(uVar17) {
          case 1:
            goto LAB_000fc444;
          case 2:
            goto switchD_000fc406_caseD_2;
          case 3:
            goto LAB_000fc434;
          case 4:
            goto switchD_000fc406_caseD_4;
          case 5:
            break;
          case 8:
            local_7c = local_7c + -1;
            *local_7c = (uchar)(uVar22 >> 0x18);
          case 7:
            local_7c = local_7c + -1;
            *local_7c = (uchar)(uVar22 >> 0x10);
          case 6:
            local_7c[-1] = (uchar)(uVar22 >> 8);
            local_7c = local_7c + -1;
            break;
          default:
            goto switchD_000fc406_caseD_8;
          }
          puVar18 = local_7c + -1;
          local_7c[-1] = (uchar)uVar22;
switchD_000fc406_caseD_4:
          puVar18[-1] = (uchar)(uVar13 >> 0x18);
          local_7c = puVar18 + -1;
LAB_000fc434:
          puVar18 = local_7c + -1;
          local_7c[-1] = (uchar)(uVar13 >> 0x10);
switchD_000fc406_caseD_2:
          puVar18[-1] = (uchar)(uVar13 >> 8);
          local_7c = puVar18 + -1;
LAB_000fc444:
          puVar18 = local_7c + -1;
          local_7c[-1] = (uchar)uVar13;
switchD_000fc406_caseD_8:
          local_7c = puVar18 + uVar17;
          bVar1 = uVar17 <= uVar16;
          uVar14 = uVar19;
          uVar12 = uVar20;
          uVar16 = uVar16 - uVar17;
        } while (bVar1);
      }
    }
    else if (uVar17 <= (uint)length) {
      uVar14 = uVar14 & numbits >> 0x20;
      if (uVar17 > (uint)length) {
        uVar14 = numbits;
      }
      pbVar15 = local_40 + ((int)uVar14 >> 3);
      uVar21 = numbits % 8;
      uVar11 = 8 - uVar21;
      uVar14 = length - uVar17;
      uVar12 = uVar19;
      uVar16 = uVar20;
      do {
        puVar18 = in + uVar17;
        local_48 = uVar12;
        local_44 = uVar16;
        DES_encrypt3(&local_48,ks1,ks2,ks3);
        switch(uVar17 - 1) {
        case 0:
          uVar13 = 0;
          uVar20 = uVar13;
          goto LAB_000fc4ca;
        case 1:
          uVar13 = 0;
          uVar20 = uVar13;
          goto LAB_000fc4c0;
        case 2:
          uVar13 = 0;
          uVar20 = uVar13;
          goto LAB_000fc4b6;
        case 3:
          uVar13 = 0;
          goto LAB_000fc4ae;
        case 4:
          uVar13 = 0;
          goto LAB_000fc4a6;
        case 5:
          uVar13 = 0;
          goto LAB_000fc49c;
        case 6:
          uVar13 = 0;
          break;
        case 7:
          pbVar2 = puVar18 + -1;
          puVar18 = puVar18 + -1;
          uVar13 = (uint)*pbVar2 << 0x18;
          break;
        default:
          uVar13 = 0;
          uVar20 = uVar13;
          goto LAB_000fc4d2;
        }
        pbVar2 = puVar18 + -1;
        puVar18 = puVar18 + -1;
        uVar13 = uVar13 | (uint)*pbVar2 << 0x10;
LAB_000fc49c:
        pbVar2 = puVar18 + -1;
        puVar18 = puVar18 + -1;
        uVar13 = uVar13 | (uint)*pbVar2 << 8;
LAB_000fc4a6:
        pbVar2 = puVar18 + -1;
        puVar18 = puVar18 + -1;
        uVar13 = uVar13 | *pbVar2;
LAB_000fc4ae:
        pbVar2 = puVar18 + -1;
        puVar18 = puVar18 + -1;
        uVar20 = (uint)*pbVar2 << 0x18;
LAB_000fc4b6:
        pbVar2 = puVar18 + -1;
        puVar18 = puVar18 + -1;
        uVar20 = uVar20 | (uint)*pbVar2 << 0x10;
LAB_000fc4c0:
        pbVar2 = puVar18 + -1;
        puVar18 = puVar18 + -1;
        uVar20 = uVar20 | (uint)*pbVar2 << 8;
LAB_000fc4ca:
        pbVar2 = puVar18 + -1;
        puVar18 = puVar18 + -1;
        uVar20 = uVar20 | *pbVar2;
LAB_000fc4d2:
        in = puVar18 + uVar17;
        uVar20 = uVar20 ^ local_48;
        local_7c = local_7c + uVar17;
        uVar13 = uVar13 ^ local_44;
        uVar5 = (uchar)uVar13;
        bVar6 = (byte)uVar20;
        uVar7 = (uchar)(uVar13 >> 8);
        uVar3 = (uchar)(uVar13 >> 0x10);
        uVar4 = (uchar)(uVar13 >> 0x18);
        uVar8 = (uchar)(uVar20 >> 8);
        uVar9 = (uchar)(uVar20 >> 0x10);
        uVar10 = (uchar)(uVar20 >> 0x18);
        puVar18 = local_7c;
        switch(uVar17 - 1) {
        case 0:
          goto LAB_000fc532;
        case 1:
          goto switchD_000fc4ea_caseD_1;
        case 2:
          goto LAB_000fc520;
        case 3:
          goto switchD_000fc4ea_caseD_3;
        case 4:
          break;
        case 7:
          local_7c = local_7c + -1;
          *local_7c = uVar4;
        case 6:
          local_7c = local_7c + -1;
          *local_7c = uVar3;
        case 5:
          local_7c[-1] = uVar7;
          local_7c = local_7c + -1;
          break;
        default:
          goto switchD_000fc4ea_caseD_8;
        }
        puVar18 = local_7c + -1;
        local_7c[-1] = uVar5;
switchD_000fc4ea_caseD_3:
        puVar18[-1] = uVar10;
        local_7c = puVar18 + -1;
LAB_000fc520:
        puVar18 = local_7c + -1;
        local_7c[-1] = uVar9;
switchD_000fc4ea_caseD_1:
        puVar18[-1] = uVar8;
        local_7c = puVar18 + -1;
LAB_000fc532:
        puVar18 = local_7c + -1;
        local_7c[-1] = bVar6;
switchD_000fc4ea_caseD_8:
        local_7c = puVar18 + uVar17;
        uVar19 = uVar16;
        if ((numbits != 0x20) && (uVar19 = uVar20, uVar20 = uVar13, numbits != 0x40)) {
          local_40[0] = (byte)uVar12;
          local_40[3] = (byte)(uVar12 >> 0x18);
          local_3c = (byte)uVar16;
          local_40[1] = (byte)(uVar12 >> 8);
          local_40[2] = (byte)(uVar12 >> 0x10);
          local_3b = (byte)(uVar16 >> 8);
          local_3a = (byte)(uVar16 >> 0x10);
          local_39 = (byte)(uVar16 >> 0x18);
          local_38 = bVar6;
          local_37 = uVar8;
          local_36 = uVar9;
          local_35 = uVar10;
          local_34 = uVar5;
          local_33 = uVar7;
          local_32 = uVar3;
          local_31 = uVar4;
          if ((numbits & 7U) == 0) {
            memmove(local_40,pbVar15,8);
            uVar22 = (uint)local_40[0];
            uVar13 = (uint)local_40[1];
            uVar24 = (uint)local_40[2];
            uVar19 = (uint)local_40[3];
            uVar20 = (uint)local_3c;
            uVar12 = (uint)local_3b;
            uVar16 = (uint)local_3a;
            uVar26 = (uint)local_39;
          }
          else {
            memmove(local_40,pbVar15,9);
            uVar13 = ((int)(uint)local_40[2] >> (uVar11 & 0xff) |
                     (uint)local_40[1] << (uVar21 & 0xff)) & 0xff;
            uVar24 = ((int)(uint)local_40[3] >> (uVar11 & 0xff) |
                     (uint)local_40[2] << (uVar21 & 0xff)) & 0xff;
            uVar19 = ((int)(uint)local_3c >> (uVar11 & 0xff) | (uint)local_40[3] << (uVar21 & 0xff))
                     & 0xff;
            uVar20 = ((int)(uint)local_3b >> (uVar11 & 0xff) | (uint)local_3c << (uVar21 & 0xff)) &
                     0xff;
            uVar12 = ((int)(uint)local_3a >> (uVar11 & 0xff) | (uint)local_3b << (uVar21 & 0xff)) &
                     0xff;
            uVar22 = ((int)(uint)local_40[1] >> (uVar11 & 0xff) |
                     (uint)local_40[0] << (uVar21 & 0xff)) & 0xff;
            uVar16 = ((int)(uint)local_39 >> (uVar11 & 0xff) | (uint)local_3a << (uVar21 & 0xff)) &
                     0xff;
            uVar26 = ((int)(uint)local_38 >> (uVar11 & 0xff) | (uint)local_39 << (uVar21 & 0xff)) &
                     0xff;
            local_40[0] = (byte)uVar22;
            local_40[1] = (byte)uVar13;
            local_40[2] = (byte)uVar24;
            local_40[3] = (byte)uVar19;
            local_3c = (byte)uVar20;
            local_3b = (byte)uVar12;
            local_3a = (byte)uVar16;
            local_39 = (byte)uVar26;
          }
          uVar19 = uVar24 << 0x10 | uVar13 << 8 | uVar22 | uVar19 << 0x18;
          uVar20 = uVar20 | uVar16 << 0x10 | uVar12 << 8 | uVar26 << 0x18;
        }
        bVar1 = uVar17 <= uVar14;
        uVar14 = uVar14 - uVar17;
        uVar12 = uVar19;
        uVar16 = uVar20;
      } while (bVar1);
    }
    (*ivec)[0] = (uchar)uVar19;
    (*ivec)[4] = (uchar)uVar20;
    (*ivec)[1] = (uchar)(uVar19 >> 8);
    (*ivec)[2] = (uchar)(uVar19 >> 0x10);
    (*ivec)[3] = (uchar)(uVar19 >> 0x18);
    (*ivec)[5] = (uchar)(uVar20 >> 8);
    (*ivec)[6] = (uchar)(uVar20 >> 0x10);
    (*ivec)[7] = (uchar)(uVar20 >> 0x18);
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

