
void DES_ncbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,int enc)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uchar uVar9;
  int iVar10;
  uchar *puVar11;
  uchar uVar12;
  uint uVar13;
  uint uVar14;
  uchar uVar15;
  uchar uVar16;
  uchar uVar17;
  uchar *puVar18;
  uint uVar19;
  byte *pbVar20;
  byte *pbVar21;
  uchar uVar22;
  uchar uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uchar uVar27;
  uchar *local_48;
  byte *local_40;
  uint local_30;
  uint local_2c;
  
  local_48 = output;
  local_40 = input;
  if (enc != 0) {
    local_2c = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
               (uint)(*ivec)[7] << 0x18;
    local_30 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
               (uint)(*ivec)[3] << 0x18;
    uVar13 = length - 8;
    if (-1 < (int)uVar13) {
      uVar14 = uVar13 >> 3;
      puVar11 = output;
      pbVar20 = input;
      do {
        puVar18 = puVar11 + 8;
        local_30 = local_30 ^
                   ((uint)pbVar20[2] << 0x10 | (uint)pbVar20[1] << 8 | (uint)*pbVar20 |
                   (uint)pbVar20[3] << 0x18);
        local_2c = local_2c ^
                   ((uint)pbVar20[6] << 0x10 | (uint)pbVar20[5] << 8 | (uint)pbVar20[4] |
                   (uint)pbVar20[7] << 0x18);
        DES_encrypt1_constprop_2(&local_30,schedule);
        *puVar11 = (uchar)local_30;
        puVar11[1] = (uchar)(local_30 >> 8);
        puVar11[2] = (uchar)(local_30 >> 0x10);
        puVar11[4] = (uchar)local_2c;
        puVar11[3] = (uchar)(local_30 >> 0x18);
        puVar11[5] = (uchar)(local_2c >> 8);
        puVar11[6] = (uchar)(local_2c >> 0x10);
        puVar11[7] = (uchar)(local_2c >> 0x18);
        puVar11 = puVar18;
        pbVar20 = pbVar20 + 8;
      } while (puVar18 != output + (uVar13 & 0xfffffff8) + 8);
      uVar13 = length + -0x10 + uVar14 * -8;
      iVar10 = (uVar14 + 1) * 8;
      local_40 = input + iVar10;
      local_48 = output + iVar10;
    }
    if (uVar13 == 0xfffffff8) {
      uVar27 = (uchar)local_30;
      uVar23 = (uchar)(local_30 >> 8);
      uVar22 = (uchar)(local_30 >> 0x10);
      uVar17 = (uchar)local_2c;
      uVar9 = (uchar)(local_2c >> 8);
      uVar12 = (uchar)(local_2c >> 0x10);
      uVar15 = (uchar)(local_30 >> 0x18);
      uVar16 = (uchar)(local_2c >> 0x18);
      goto LAB_0007ac6c;
    }
    puVar11 = local_40 + uVar13 + 8;
    switch(uVar13) {
    default:
      uVar13 = 0;
      uVar14 = uVar13;
      goto LAB_0007acc0;
    case 0xfffffff9:
      uVar14 = 0;
      uVar13 = uVar14;
      goto LAB_0007acba;
    case 0xfffffffa:
      uVar14 = 0;
      uVar13 = uVar14;
      goto LAB_0007acb0;
    case 0xfffffffb:
      uVar14 = 0;
      uVar13 = uVar14;
      goto LAB_0007aca6;
    case 0xfffffffc:
      uVar13 = 0;
      goto LAB_0007ac9e;
    case 0xfffffffd:
      uVar13 = 0;
      goto LAB_0007ac96;
    case 0xfffffffe:
      uVar13 = 0;
      break;
    case 0xffffffff:
      pbVar20 = puVar11 + -1;
      puVar11 = puVar11 + -1;
      uVar13 = (uint)*pbVar20 << 0x10;
    }
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar13 = uVar13 | (uint)*pbVar20 << 8;
LAB_0007ac96:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar13 = *pbVar20 | uVar13;
LAB_0007ac9e:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar14 = (uint)*pbVar20 << 0x18;
LAB_0007aca6:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar14 = uVar14 | (uint)*pbVar20 << 0x10;
LAB_0007acb0:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar14 = uVar14 | (uint)*pbVar20 << 8;
LAB_0007acba:
    uVar14 = puVar11[-1] | uVar14;
LAB_0007acc0:
    local_30 = local_30 ^ uVar14;
    local_2c = local_2c ^ uVar13;
    DES_encrypt1_constprop_2(&local_30,schedule);
    uVar27 = (uchar)local_30;
    uVar23 = (uchar)(local_30 >> 8);
    local_48[1] = uVar23;
    *local_48 = uVar27;
    uVar22 = (uchar)(local_30 >> 0x10);
    local_48[2] = uVar22;
    uVar17 = (uchar)local_2c;
    uVar15 = (uchar)(local_30 >> 0x18);
    local_48[3] = uVar15;
    local_48[4] = uVar17;
    uVar9 = (uchar)(local_2c >> 8);
    local_48[5] = uVar9;
    uVar12 = (uchar)(local_2c >> 0x10);
    local_48[6] = uVar12;
    uVar16 = (uchar)(local_2c >> 0x18);
    local_48[7] = uVar16;
LAB_0007ac6c:
    (*ivec)[0] = uVar27;
    (*ivec)[1] = uVar23;
    (*ivec)[2] = uVar22;
    (*ivec)[3] = uVar15;
    (*ivec)[4] = uVar17;
    (*ivec)[5] = uVar9;
    (*ivec)[6] = uVar12;
    (*ivec)[7] = uVar16;
    return;
  }
  uVar14 = length - 8;
  uVar24 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
           (uint)(*ivec)[3] << 0x18;
  uVar13 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
           (uint)(*ivec)[7] << 0x18;
  if (-1 < (int)uVar14) {
    uVar19 = uVar14 >> 3;
    pbVar20 = input;
    puVar11 = output;
    uVar25 = uVar24;
    uVar26 = uVar13;
    do {
      pbVar21 = pbVar20 + 8;
      uVar24 = (uint)pbVar20[2] << 0x10 | (uint)pbVar20[1] << 8 | (uint)*pbVar20 |
               (uint)pbVar20[3] << 0x18;
      uVar13 = (uint)pbVar20[6] << 0x10 | (uint)pbVar20[5] << 8 | (uint)pbVar20[4] |
               (uint)pbVar20[7] << 0x18;
      local_30 = uVar24;
      local_2c = uVar13;
      DES_encrypt1_constprop_3(&local_30,schedule);
      uVar25 = uVar25 ^ local_30;
      *puVar11 = (uchar)uVar25;
      uVar26 = uVar26 ^ local_2c;
      puVar11[4] = (uchar)uVar26;
      puVar11[2] = (uchar)(uVar25 >> 0x10);
      puVar11[5] = (uchar)(uVar26 >> 8);
      puVar11[7] = (uchar)(uVar26 >> 0x18);
      puVar11[1] = (uchar)(uVar25 >> 8);
      puVar11[3] = (uchar)(uVar25 >> 0x18);
      puVar11[6] = (uchar)(uVar26 >> 0x10);
      pbVar20 = pbVar21;
      puVar11 = puVar11 + 8;
      uVar25 = uVar24;
      uVar26 = uVar13;
    } while (pbVar21 != input + (uVar14 & 0xfffffff8) + 8);
    uVar14 = length + -0x10 + uVar19 * -8;
    iVar10 = (uVar19 + 1) * 8;
    local_40 = input + iVar10;
    local_48 = output + iVar10;
  }
  bVar1 = local_40[2];
  bVar2 = local_40[6];
  bVar3 = local_40[1];
  bVar4 = local_40[5];
  bVar5 = *local_40;
  bVar6 = local_40[3];
  bVar7 = local_40[4];
  bVar8 = local_40[7];
  local_30 = (uint)bVar1 << 0x10 | (uint)bVar3 << 8 | (uint)bVar5 | (uint)bVar6 << 0x18;
  local_2c = (uint)bVar2 << 0x10 | (uint)bVar4 << 8 | (uint)bVar7 | (uint)bVar8 << 0x18;
  DES_encrypt1_constprop_3(&local_30,schedule);
  uVar24 = uVar24 ^ local_30;
  uVar13 = uVar13 ^ local_2c;
  local_48 = local_48 + uVar14 + 8;
  switch(uVar14) {
  default:
    goto switchD_0007abe0_caseD_7;
  case 0xfffffff9:
    goto LAB_0007ac1e;
  case 0xfffffffa:
    goto switchD_0007abe0_caseD_fffffffa;
  case 0xfffffffb:
    puVar11 = local_48;
    goto LAB_0007ac0a;
  case 0xfffffffc:
    goto switchD_0007abe0_caseD_fffffffc;
  case 0xfffffffd:
    puVar11 = local_48;
    break;
  case 0xffffffff:
    local_48 = local_48 + -1;
    *local_48 = (uchar)(uVar13 >> 0x10);
  case 0xfffffffe:
    local_48[-1] = (uchar)(uVar13 >> 8);
    puVar11 = local_48 + -1;
  }
  local_48 = puVar11 + -1;
  puVar11[-1] = (uchar)uVar13;
switchD_0007abe0_caseD_fffffffc:
  local_48[-1] = (uchar)(uVar24 >> 0x18);
  puVar11 = local_48 + -1;
LAB_0007ac0a:
  local_48 = puVar11 + -1;
  puVar11[-1] = (uchar)(uVar24 >> 0x10);
switchD_0007abe0_caseD_fffffffa:
  local_48[-1] = (uchar)(uVar24 >> 8);
  local_48 = local_48 + -1;
LAB_0007ac1e:
  local_48[-1] = (uchar)uVar24;
switchD_0007abe0_caseD_7:
  (*ivec)[0] = bVar5;
  (*ivec)[4] = bVar7;
  (*ivec)[1] = bVar3;
  (*ivec)[2] = bVar1;
  (*ivec)[3] = bVar6;
  (*ivec)[5] = bVar4;
  (*ivec)[6] = bVar2;
  (*ivec)[7] = bVar8;
  return;
}

