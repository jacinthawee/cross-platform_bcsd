
void BF_cbc_encrypt(uchar *in,uchar *out,long length,BF_KEY *schedule,uchar *ivec,int enc)

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
  byte *pbVar18;
  uint uVar19;
  byte *pbVar20;
  uchar uVar21;
  uchar uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uchar uVar26;
  uchar *local_44;
  byte *local_40;
  uint local_30;
  uint local_2c;
  
  local_44 = out;
  local_40 = in;
  if (enc != 0) {
    local_2c = (uint)ivec[5] << 0x10 | (uint)ivec[4] << 0x18 | (uint)ivec[7] | (uint)ivec[6] << 8;
    local_30 = (uint)ivec[1] << 0x10 | (uint)*ivec << 0x18 | (uint)ivec[3] | (uint)ivec[2] << 8;
    uVar13 = length - 8;
    if (-1 < (int)uVar13) {
      uVar14 = uVar13 >> 3;
      pbVar20 = in;
      puVar11 = out;
      do {
        pbVar18 = pbVar20 + 8;
        local_30 = local_30 ^
                   ((uint)pbVar20[1] << 0x10 | (uint)*pbVar20 << 0x18 | (uint)pbVar20[3] |
                   (uint)pbVar20[2] << 8);
        local_2c = local_2c ^
                   ((uint)pbVar20[5] << 0x10 | (uint)pbVar20[4] << 0x18 | (uint)pbVar20[7] |
                   (uint)pbVar20[6] << 8);
        BF_encrypt(&local_30,schedule);
        *puVar11 = (uchar)(local_30 >> 0x18);
        puVar11[1] = (uchar)(local_30 >> 0x10);
        puVar11[2] = (uchar)(local_30 >> 8);
        puVar11[4] = (uchar)(local_2c >> 0x18);
        puVar11[3] = (uchar)local_30;
        puVar11[7] = (uchar)local_2c;
        puVar11[5] = (uchar)(local_2c >> 0x10);
        puVar11[6] = (uchar)(local_2c >> 8);
        pbVar20 = pbVar18;
        puVar11 = puVar11 + 8;
      } while (pbVar18 != in + (uVar13 & 0xfffffff8) + 8);
      uVar13 = length + -0x10 + uVar14 * -8;
      iVar10 = (uVar14 + 1) * 8;
      local_40 = in + iVar10;
      local_44 = out + iVar10;
    }
    if (uVar13 == 0xfffffff8) {
      uVar26 = (uchar)(local_30 >> 0x18);
      uVar22 = (uchar)(local_30 >> 0x10);
      uVar21 = (uchar)(local_30 >> 8);
      uVar17 = (uchar)(local_2c >> 0x18);
      uVar9 = (uchar)(local_2c >> 0x10);
      uVar12 = (uchar)(local_2c >> 8);
      uVar15 = (uchar)local_30;
      uVar16 = (uchar)local_2c;
      goto LAB_00081ee8;
    }
    puVar11 = local_40 + uVar13 + 8;
    switch(uVar13) {
    default:
      uVar13 = 0;
      uVar14 = uVar13;
      goto LAB_00081f3e;
    case 0xfffffff9:
      uVar14 = 0;
      uVar13 = uVar14;
      goto LAB_00081f36;
    case 0xfffffffa:
      uVar14 = 0;
      uVar13 = uVar14;
      goto LAB_00081f2c;
    case 0xfffffffb:
      uVar13 = 0;
      uVar14 = uVar13;
      goto LAB_00081f22;
    case 0xfffffffc:
      uVar13 = 0;
      goto LAB_00081f1c;
    case 0xfffffffd:
      uVar13 = 0;
      goto LAB_00081f12;
    case 0xfffffffe:
      uVar13 = 0;
      break;
    case 0xffffffff:
      pbVar20 = puVar11 + -1;
      puVar11 = puVar11 + -1;
      uVar13 = (uint)*pbVar20 << 8;
    }
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar13 = uVar13 | (uint)*pbVar20 << 0x10;
LAB_00081f12:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar13 = uVar13 | (uint)*pbVar20 << 0x18;
LAB_00081f1c:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar14 = (uint)*pbVar20;
LAB_00081f22:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar14 = uVar14 | (uint)*pbVar20 << 8;
LAB_00081f2c:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar14 = uVar14 | (uint)*pbVar20 << 0x10;
LAB_00081f36:
    uVar14 = uVar14 | (uint)puVar11[-1] << 0x18;
LAB_00081f3e:
    local_30 = local_30 ^ uVar14;
    local_2c = local_2c ^ uVar13;
    BF_encrypt(&local_30,schedule);
    uVar22 = (uchar)(local_30 >> 0x10);
    local_44[1] = uVar22;
    uVar15 = (uchar)local_30;
    uVar26 = (uchar)(local_30 >> 0x18);
    *local_44 = uVar26;
    uVar21 = (uchar)(local_30 >> 8);
    local_44[2] = uVar21;
    local_44[3] = uVar15;
    uVar16 = (uchar)local_2c;
    uVar17 = (uchar)(local_2c >> 0x18);
    local_44[4] = uVar17;
    uVar9 = (uchar)(local_2c >> 0x10);
    local_44[5] = uVar9;
    uVar12 = (uchar)(local_2c >> 8);
    local_44[6] = uVar12;
    local_44[7] = uVar16;
LAB_00081ee8:
    *ivec = uVar26;
    ivec[1] = uVar22;
    ivec[2] = uVar21;
    ivec[3] = uVar15;
    ivec[4] = uVar17;
    ivec[5] = uVar9;
    ivec[6] = uVar12;
    ivec[7] = uVar16;
    return;
  }
  uVar14 = length - 8;
  uVar23 = (uint)ivec[1] << 0x10 | (uint)*ivec << 0x18 | (uint)ivec[3] | (uint)ivec[2] << 8;
  uVar13 = (uint)ivec[5] << 0x10 | (uint)ivec[4] << 0x18 | (uint)ivec[7] | (uint)ivec[6] << 8;
  if (-1 < (int)uVar14) {
    uVar19 = uVar14 >> 3;
    pbVar20 = in;
    puVar11 = out;
    uVar24 = uVar23;
    uVar25 = uVar13;
    do {
      pbVar18 = pbVar20 + 8;
      uVar23 = (uint)pbVar20[1] << 0x10 | (uint)*pbVar20 << 0x18 | (uint)pbVar20[3] |
               (uint)pbVar20[2] << 8;
      uVar13 = (uint)pbVar20[5] << 0x10 | (uint)pbVar20[4] << 0x18 | (uint)pbVar20[7] |
               (uint)pbVar20[6] << 8;
      local_30 = uVar23;
      local_2c = uVar13;
      BF_decrypt(&local_30,schedule);
      uVar24 = uVar24 ^ local_30;
      puVar11[3] = (uchar)uVar24;
      uVar25 = uVar25 ^ local_2c;
      puVar11[7] = (uchar)uVar25;
      puVar11[1] = (uchar)(uVar24 >> 0x10);
      puVar11[4] = (uchar)(uVar25 >> 0x18);
      puVar11[6] = (uchar)(uVar25 >> 8);
      *puVar11 = (uchar)(uVar24 >> 0x18);
      puVar11[2] = (uchar)(uVar24 >> 8);
      puVar11[5] = (uchar)(uVar25 >> 0x10);
      pbVar20 = pbVar18;
      puVar11 = puVar11 + 8;
      uVar24 = uVar23;
      uVar25 = uVar13;
    } while (pbVar18 != in + (uVar14 & 0xfffffff8) + 8);
    uVar14 = length + -0x10 + uVar19 * -8;
    iVar10 = (uVar19 + 1) * 8;
    local_40 = in + iVar10;
    local_44 = out + iVar10;
  }
  bVar1 = local_40[1];
  bVar2 = local_40[5];
  bVar3 = *local_40;
  bVar4 = local_40[4];
  bVar5 = local_40[3];
  bVar6 = local_40[2];
  bVar7 = local_40[7];
  bVar8 = local_40[6];
  local_30 = (uint)bVar1 << 0x10 | (uint)bVar3 << 0x18 | (uint)bVar5 | (uint)bVar6 << 8;
  local_2c = (uint)bVar2 << 0x10 | (uint)bVar4 << 0x18 | (uint)bVar7 | (uint)bVar8 << 8;
  BF_decrypt(&local_30,schedule);
  uVar23 = uVar23 ^ local_30;
  uVar13 = uVar13 ^ local_2c;
  local_44 = local_44 + uVar14 + 8;
  puVar11 = local_44;
  switch(uVar14) {
  default:
    goto switchD_00081e5a_caseD_7;
  case 0xfffffff9:
    goto LAB_00081e96;
  case 0xfffffffa:
    goto switchD_00081e5a_caseD_fffffffa;
  case 0xfffffffb:
    puVar11 = local_44;
    goto LAB_00081e82;
  case 0xfffffffc:
    goto switchD_00081e5a_caseD_fffffffc;
  case 0xfffffffd:
    break;
  case 0xffffffff:
    puVar11 = local_44 + -1;
    *puVar11 = (uchar)(uVar13 >> 8);
  case 0xfffffffe:
    local_44 = puVar11 + -1;
    puVar11[-1] = (uchar)(uVar13 >> 0x10);
  }
  puVar11 = local_44 + -1;
  local_44[-1] = (uchar)(uVar13 >> 0x18);
switchD_00081e5a_caseD_fffffffc:
  puVar11[-1] = (uchar)uVar23;
  puVar11 = puVar11 + -1;
LAB_00081e82:
  local_44 = puVar11 + -1;
  puVar11[-1] = (uchar)(uVar23 >> 8);
switchD_00081e5a_caseD_fffffffa:
  local_44[-1] = (uchar)(uVar23 >> 0x10);
  local_44 = local_44 + -1;
LAB_00081e96:
  local_44[-1] = (uchar)(uVar23 >> 0x18);
switchD_00081e5a_caseD_7:
  ivec[3] = bVar5;
  ivec[7] = bVar7;
  *ivec = bVar3;
  ivec[1] = bVar1;
  ivec[2] = bVar6;
  ivec[4] = bVar4;
  ivec[5] = bVar2;
  ivec[6] = bVar8;
  return;
}
