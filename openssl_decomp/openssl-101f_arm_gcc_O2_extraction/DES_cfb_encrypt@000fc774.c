
void DES_cfb_encrypt(uchar *in,uchar *out,int numbits,long length,DES_key_schedule *schedule,
                    DES_cblock *ivec,int enc)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  uchar uVar5;
  uchar uVar6;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uchar *puVar14;
  uint uVar15;
  uchar *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  byte *local_70;
  uchar *local_6c;
  uint local_68;
  uint local_48;
  uint local_44;
  byte local_40 [9];
  uchar local_37;
  uchar local_36;
  uchar local_35;
  uchar local_34;
  uchar local_33;
  uchar local_32;
  uchar local_31;
  int local_2c;
  uchar uVar7;
  uchar uVar8;
  uchar uVar9;
  uchar uVar10;
  
  local_2c = __TMC_END__;
  if (numbits - 1U < 0x40) {
    uVar17 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
    uVar15 = numbits + 7 >> 3;
    iVar2 = numbits >> 3;
    uVar19 = (uint)(*ivec)[4] | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 |
             (uint)(*ivec)[7] << 0x18;
    uVar20 = numbits & 7;
    uVar18 = uVar17;
    uVar12 = uVar19;
    local_70 = in;
    local_6c = out;
    if (enc == 0) {
      if (uVar15 <= (uint)length) {
        local_68 = length - uVar15;
        do {
          local_48 = uVar18;
          local_44 = uVar12;
          DES_encrypt1(&local_48,schedule,1);
          local_70 = local_70 + uVar15;
          switch(uVar15 - 2) {
          case 0:
            uVar13 = 0;
            uVar11 = uVar13;
            goto LAB_000fc92c;
          case 1:
            uVar13 = 0;
            uVar17 = uVar13;
            goto LAB_000fc922;
          case 2:
            uVar13 = 0;
            goto LAB_000fc91a;
          case 3:
            uVar13 = 0;
            goto LAB_000fc912;
          case 4:
            uVar13 = 0;
            goto LAB_000fc908;
          case 5:
            uVar13 = 0;
            break;
          case 6:
            pbVar3 = local_70 + -1;
            local_70 = local_70 + -1;
            uVar13 = (uint)*pbVar3 << 0x18;
            break;
          default:
            uVar13 = 0;
            uVar11 = uVar13;
            goto LAB_000fc936;
          }
          pbVar3 = local_70 + -1;
          local_70 = local_70 + -1;
          uVar13 = uVar13 | (uint)*pbVar3 << 0x10;
LAB_000fc908:
          pbVar3 = local_70 + -1;
          local_70 = local_70 + -1;
          uVar13 = uVar13 | (uint)*pbVar3 << 8;
LAB_000fc912:
          pbVar3 = local_70 + -1;
          local_70 = local_70 + -1;
          uVar13 = uVar13 | *pbVar3;
LAB_000fc91a:
          pbVar3 = local_70 + -1;
          local_70 = local_70 + -1;
          uVar17 = (uint)*pbVar3 << 0x18;
LAB_000fc922:
          pbVar3 = local_70 + -1;
          local_70 = local_70 + -1;
          uVar11 = uVar17 | (uint)*pbVar3 << 0x10;
LAB_000fc92c:
          pbVar3 = local_70 + -1;
          local_70 = local_70 + -1;
          uVar11 = uVar11 | (uint)*pbVar3 << 8;
LAB_000fc936:
          bVar4 = local_70[-1];
          local_70 = local_70 + -1 + uVar15;
          uVar22 = uVar11 | bVar4;
          uVar17 = uVar12;
          uVar19 = uVar22;
          if ((numbits != 0x20) && (uVar17 = uVar22, uVar19 = uVar13, numbits != 0x40)) {
            local_40[0] = (byte)uVar18;
            local_40[4] = (byte)uVar12;
            local_40[1] = (byte)(uVar18 >> 8);
            local_40[2] = (byte)(uVar18 >> 0x10);
            local_40[5] = (byte)(uVar12 >> 8);
            local_40[6] = (byte)(uVar12 >> 0x10);
            local_37 = (uchar)(uVar11 >> 8);
            local_36 = (uchar)(uVar11 >> 0x10);
            local_35 = (uchar)(uVar11 >> 0x18);
            local_40[8] = bVar4;
            local_34 = (uchar)uVar13;
            local_40[3] = (byte)(uVar18 >> 0x18);
            local_40[7] = (byte)(uVar12 >> 0x18);
            local_33 = (uchar)(uVar13 >> 8);
            local_32 = (uchar)(uVar13 >> 0x10);
            local_31 = (uchar)(uVar13 >> 0x18);
            if (uVar20 == 0) {
              memmove(local_40,local_40 + iVar2,8);
              uVar21 = (uint)local_40[0];
              uVar17 = (uint)local_40[1];
              uVar24 = (uint)local_40[2];
              uVar23 = (uint)local_40[3];
              uVar11 = (uint)local_40[4];
              uVar18 = (uint)local_40[5];
              uVar12 = (uint)local_40[6];
              uVar19 = (uint)local_40[7];
            }
            else {
              uVar19 = 8 - uVar20;
              uVar21 = ((int)(uint)local_40[iVar2 + 1] >> (uVar19 & 0xff) |
                       (uint)local_40[iVar2] << uVar20) & 0xff;
              local_40[0] = (byte)uVar21;
              uVar17 = ((int)(uint)local_40[iVar2 + 2] >> (uVar19 & 0xff) |
                       (uint)local_40[iVar2 + 1] << uVar20) & 0xff;
              local_40[1] = (byte)uVar17;
              uVar24 = ((int)(uint)local_40[iVar2 + 3] >> (uVar19 & 0xff) |
                       (uint)local_40[iVar2 + 2] << uVar20) & 0xff;
              local_40[2] = (byte)uVar24;
              uVar23 = ((int)(uint)local_40[iVar2 + 4] >> (uVar19 & 0xff) |
                       (uint)local_40[iVar2 + 3] << uVar20) & 0xff;
              local_40[3] = (byte)uVar23;
              uVar11 = ((int)(uint)local_40[iVar2 + 5] >> (uVar19 & 0xff) |
                       (uint)local_40[iVar2 + 4] << uVar20) & 0xff;
              local_40[4] = (byte)uVar11;
              uVar18 = ((int)(uint)local_40[iVar2 + 6] >> (uVar19 & 0xff) |
                       (uint)local_40[iVar2 + 5] << uVar20) & 0xff;
              local_40[5] = (byte)uVar18;
              uVar12 = ((int)(uint)local_40[iVar2 + 7] >> (uVar19 & 0xff) |
                       (uint)local_40[iVar2 + 6] << uVar20) & 0xff;
              local_40[6] = (byte)uVar12;
              uVar19 = ((int)(uint)local_40[iVar2 + 8] >> (uVar19 & 0xff) |
                       (uint)local_40[iVar2 + 7] << uVar20) & 0xff;
              local_40[7] = (byte)uVar19;
            }
            uVar17 = uVar24 << 0x10 | uVar17 << 8 | uVar21 | uVar23 << 0x18;
            uVar19 = uVar12 << 0x10 | uVar18 << 8 | uVar11 | uVar19 << 0x18;
          }
          uVar22 = uVar22 ^ local_48;
          local_6c = local_6c + uVar15;
          uVar13 = uVar13 ^ local_44;
          puVar16 = local_6c;
          switch(uVar15) {
          case 2:
            goto LAB_000fcb3e;
          case 3:
            goto switchD_000fcb06_caseD_3;
          case 4:
            goto LAB_000fcb2e;
          case 5:
            goto switchD_000fcb06_caseD_5;
          case 6:
            break;
          case 8:
            local_6c = local_6c + -1;
            *local_6c = (uchar)(uVar13 >> 0x18);
          case 7:
            local_6c[-1] = (uchar)(uVar13 >> 0x10);
            local_6c = local_6c + -1;
            break;
          default:
            goto switchD_000fcb06_caseD_7;
          }
          puVar16 = local_6c + -1;
          local_6c[-1] = (uchar)(uVar13 >> 8);
switchD_000fcb06_caseD_5:
          local_6c = puVar16 + -1;
          puVar16[-1] = (uchar)uVar13;
LAB_000fcb2e:
          puVar16 = local_6c + -1;
          local_6c[-1] = (uchar)(uVar22 >> 0x18);
switchD_000fcb06_caseD_3:
          puVar16[-1] = (uchar)(uVar22 >> 0x10);
          local_6c = puVar16 + -1;
LAB_000fcb3e:
          puVar16 = local_6c + -1;
          local_6c[-1] = (uchar)(uVar22 >> 8);
switchD_000fcb06_caseD_7:
          puVar16[-1] = (uchar)uVar22;
          local_6c = puVar16 + (uVar15 - 1);
          bVar1 = uVar15 <= local_68;
          uVar18 = uVar17;
          uVar12 = uVar19;
          local_68 = local_68 - uVar15;
        } while (bVar1);
      }
    }
    else {
      while (uVar19 = uVar12, uVar17 = uVar18, uVar15 <= (uint)length) {
        local_48 = uVar17;
        local_44 = uVar19;
        DES_encrypt1(&local_48,schedule,1);
        length = length - uVar15;
        puVar16 = local_70 + uVar15;
        switch(uVar15 - 2) {
        case 0:
          uVar11 = 0;
          uVar18 = uVar11;
          goto LAB_000fcbba;
        case 1:
          uVar11 = 0;
          uVar18 = uVar11;
          goto LAB_000fcbb0;
        case 2:
          uVar11 = 0;
          goto LAB_000fcba8;
        case 3:
          uVar11 = 0;
          goto LAB_000fcba0;
        case 4:
          uVar11 = 0;
          goto LAB_000fcb96;
        case 5:
          uVar11 = 0;
          break;
        case 6:
          pbVar3 = puVar16 + -1;
          puVar16 = puVar16 + -1;
          uVar11 = (uint)*pbVar3 << 0x18;
          break;
        default:
          uVar11 = 0;
          uVar18 = uVar11;
          goto LAB_000fcbc4;
        }
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar11 = uVar11 | (uint)*pbVar3 << 0x10;
LAB_000fcb96:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar11 = uVar11 | (uint)*pbVar3 << 8;
LAB_000fcba0:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar11 = uVar11 | *pbVar3;
LAB_000fcba8:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar18 = (uint)*pbVar3 << 0x18;
LAB_000fcbb0:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar18 = uVar18 | (uint)*pbVar3 << 0x10;
LAB_000fcbba:
        pbVar3 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        uVar18 = uVar18 | (uint)*pbVar3 << 8;
LAB_000fcbc4:
        local_70 = puVar16 + (uVar15 - 1);
        uVar13 = (puVar16[-1] | uVar18) ^ local_48;
        puVar16 = local_6c + uVar15;
        uVar11 = uVar11 ^ local_44;
        uVar6 = (uchar)(uVar11 >> 8);
        uVar7 = (uchar)(uVar11 >> 0x10);
        uVar5 = (uchar)(uVar11 >> 0x18);
        uVar8 = (uchar)(uVar13 >> 8);
        uVar9 = (uchar)(uVar13 >> 0x10);
        uVar10 = (uchar)(uVar13 >> 0x18);
        switch(uVar15 - 2) {
        case 0:
          puVar14 = puVar16;
          goto LAB_000fcc42;
        case 1:
          goto switchD_000fcbe6_caseD_1;
        case 2:
          puVar14 = puVar16;
          goto LAB_000fcc32;
        case 3:
          goto switchD_000fcbe6_caseD_3;
        case 4:
          puVar14 = puVar16;
          break;
        case 6:
          puVar16 = puVar16 + -1;
          *puVar16 = uVar5;
        case 5:
          puVar16[-1] = uVar7;
          puVar14 = puVar16 + -1;
          break;
        default:
          goto switchD_000fcbe6_caseD_7;
        }
        puVar16 = puVar14 + -1;
        puVar14[-1] = uVar6;
switchD_000fcbe6_caseD_3:
        puVar16[-1] = (uchar)uVar11;
        puVar14 = puVar16 + -1;
LAB_000fcc32:
        puVar16 = puVar14 + -1;
        puVar14[-1] = uVar10;
switchD_000fcbe6_caseD_1:
        puVar16[-1] = uVar9;
        puVar14 = puVar16 + -1;
LAB_000fcc42:
        puVar16 = puVar14 + -1;
        puVar14[-1] = uVar8;
switchD_000fcbe6_caseD_7:
        local_6c = puVar16 + (uVar15 - 1);
        puVar16[-1] = (byte)uVar13;
        uVar18 = uVar19;
        uVar12 = uVar13;
        if ((numbits != 0x20) && (uVar18 = uVar13, uVar12 = uVar11, numbits != 0x40)) {
          local_40[0] = (byte)uVar17;
          local_40[4] = (byte)uVar19;
          local_40[8] = (byte)uVar13;
          local_34 = (uchar)uVar11;
          local_40[1] = (byte)(uVar17 >> 8);
          local_40[3] = (byte)(uVar17 >> 0x18);
          local_40[6] = (byte)(uVar19 >> 0x10);
          local_40[2] = (byte)(uVar17 >> 0x10);
          local_40[5] = (byte)(uVar19 >> 8);
          local_36 = uVar9;
          local_40[7] = (byte)(uVar19 >> 0x18);
          local_37 = uVar8;
          local_35 = uVar10;
          local_33 = uVar6;
          local_32 = uVar7;
          local_31 = uVar5;
          if (uVar20 == 0) {
            memmove(local_40,local_40 + iVar2,8);
            uVar24 = (uint)local_40[0];
            uVar22 = (uint)local_40[1];
            uVar13 = (uint)local_40[2];
            uVar18 = (uint)local_40[3];
            uVar11 = (uint)local_40[4];
            uVar17 = (uint)local_40[5];
            uVar12 = (uint)local_40[6];
            uVar19 = (uint)local_40[7];
          }
          else {
            uVar19 = 8 - uVar20;
            uVar24 = ((int)(uint)local_40[iVar2 + 1] >> (uVar19 & 0xff) |
                     (uint)local_40[iVar2] << uVar20) & 0xff;
            local_40[0] = (byte)uVar24;
            uVar22 = ((int)(uint)local_40[iVar2 + 2] >> (uVar19 & 0xff) |
                     (uint)local_40[iVar2 + 1] << uVar20) & 0xff;
            local_40[1] = (byte)uVar22;
            uVar13 = ((int)(uint)local_40[iVar2 + 3] >> (uVar19 & 0xff) |
                     (uint)local_40[iVar2 + 2] << uVar20) & 0xff;
            local_40[2] = (byte)uVar13;
            uVar18 = ((uint)local_40[iVar2 + 3] << uVar20 |
                     (int)(uint)local_40[iVar2 + 4] >> (uVar19 & 0xff)) & 0xff;
            local_40[3] = (byte)uVar18;
            uVar11 = ((int)(uint)local_40[iVar2 + 5] >> (uVar19 & 0xff) |
                     (uint)local_40[iVar2 + 4] << uVar20) & 0xff;
            local_40[4] = (byte)uVar11;
            uVar17 = ((int)(uint)local_40[iVar2 + 6] >> (uVar19 & 0xff) |
                     (uint)local_40[iVar2 + 5] << uVar20) & 0xff;
            local_40[5] = (byte)uVar17;
            uVar12 = ((int)(uint)local_40[iVar2 + 7] >> (uVar19 & 0xff) |
                     (uint)local_40[iVar2 + 6] << uVar20) & 0xff;
            local_40[6] = (byte)uVar12;
            uVar19 = ((int)(uint)local_40[iVar2 + 8] >> (uVar19 & 0xff) |
                     (uint)local_40[iVar2 + 7] << uVar20) & 0xff;
            local_40[7] = (byte)uVar19;
          }
          uVar18 = uVar13 << 0x10 | uVar22 << 8 | uVar24 | uVar18 << 0x18;
          uVar12 = uVar11 | uVar12 << 0x10 | uVar17 << 8 | uVar19 << 0x18;
        }
      }
    }
    (*ivec)[0] = (uchar)uVar17;
    (*ivec)[4] = (uchar)uVar19;
    (*ivec)[1] = (uchar)(uVar17 >> 8);
    (*ivec)[2] = (uchar)(uVar17 >> 0x10);
    (*ivec)[3] = (uchar)(uVar17 >> 0x18);
    (*ivec)[5] = (uchar)(uVar19 >> 8);
    (*ivec)[6] = (uchar)(uVar19 >> 0x10);
    (*ivec)[7] = (uchar)(uVar19 >> 0x18);
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

