
void RC2_cbc_encrypt(uchar *in,uchar *out,long length,RC2_KEY *ks,uchar *iv,int enc)

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
  
  local_48 = out;
  local_40 = in;
  if (enc != 0) {
    local_2c = (uint)iv[6] << 0x10 | (uint)iv[5] << 8 | (uint)iv[4] | (uint)iv[7] << 0x18;
    local_30 = (uint)iv[2] << 0x10 | (uint)iv[1] << 8 | (uint)*iv | (uint)iv[3] << 0x18;
    uVar13 = length - 8;
    if (-1 < (int)uVar13) {
      uVar14 = uVar13 >> 3;
      puVar11 = out;
      pbVar20 = in;
      do {
        puVar18 = puVar11 + 8;
        local_30 = local_30 ^
                   ((uint)pbVar20[2] << 0x10 | (uint)pbVar20[1] << 8 | (uint)*pbVar20 |
                   (uint)pbVar20[3] << 0x18);
        local_2c = local_2c ^
                   ((uint)pbVar20[6] << 0x10 | (uint)pbVar20[5] << 8 | (uint)pbVar20[4] |
                   (uint)pbVar20[7] << 0x18);
        RC2_encrypt(&local_30,ks);
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
      } while (puVar18 != out + (uVar13 & 0xfffffff8) + 8);
      uVar13 = length + -0x10 + uVar14 * -8;
      iVar10 = (uVar14 + 1) * 8;
      local_40 = in + iVar10;
      local_48 = out + iVar10;
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
      goto LAB_0007fe58;
    }
    puVar11 = local_40 + uVar13 + 8;
    switch(uVar13) {
    default:
      uVar13 = 0;
      uVar14 = uVar13;
      goto LAB_0007feac;
    case 0xfffffff9:
      uVar14 = 0;
      uVar13 = uVar14;
      goto LAB_0007fea6;
    case 0xfffffffa:
      uVar14 = 0;
      uVar13 = uVar14;
      goto LAB_0007fe9c;
    case 0xfffffffb:
      uVar14 = 0;
      uVar13 = uVar14;
      goto LAB_0007fe92;
    case 0xfffffffc:
      uVar13 = 0;
      goto LAB_0007fe8a;
    case 0xfffffffd:
      uVar13 = 0;
      goto LAB_0007fe82;
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
LAB_0007fe82:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar13 = *pbVar20 | uVar13;
LAB_0007fe8a:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar14 = (uint)*pbVar20 << 0x18;
LAB_0007fe92:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar14 = uVar14 | (uint)*pbVar20 << 0x10;
LAB_0007fe9c:
    pbVar20 = puVar11 + -1;
    puVar11 = puVar11 + -1;
    uVar14 = uVar14 | (uint)*pbVar20 << 8;
LAB_0007fea6:
    uVar14 = puVar11[-1] | uVar14;
LAB_0007feac:
    local_30 = local_30 ^ uVar14;
    local_2c = local_2c ^ uVar13;
    RC2_encrypt(&local_30,ks);
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
LAB_0007fe58:
    *iv = uVar27;
    iv[1] = uVar23;
    iv[2] = uVar22;
    iv[3] = uVar15;
    iv[4] = uVar17;
    iv[5] = uVar9;
    iv[6] = uVar12;
    iv[7] = uVar16;
    return;
  }
  uVar14 = length - 8;
  uVar24 = (uint)iv[2] << 0x10 | (uint)iv[1] << 8 | (uint)*iv | (uint)iv[3] << 0x18;
  uVar13 = (uint)iv[6] << 0x10 | (uint)iv[5] << 8 | (uint)iv[4] | (uint)iv[7] << 0x18;
  if (-1 < (int)uVar14) {
    uVar19 = uVar14 >> 3;
    pbVar20 = in;
    puVar11 = out;
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
      RC2_decrypt(&local_30,ks);
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
    } while (pbVar21 != in + (uVar14 & 0xfffffff8) + 8);
    uVar14 = length + -0x10 + uVar19 * -8;
    iVar10 = (uVar19 + 1) * 8;
    local_40 = in + iVar10;
    local_48 = out + iVar10;
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
  RC2_decrypt(&local_30,ks);
  uVar24 = uVar24 ^ local_30;
  uVar13 = uVar13 ^ local_2c;
  local_48 = local_48 + uVar14 + 8;
  switch(uVar14) {
  default:
    goto switchD_0007fdcc_caseD_7;
  case 0xfffffff9:
    goto LAB_0007fe0a;
  case 0xfffffffa:
    goto switchD_0007fdcc_caseD_fffffffa;
  case 0xfffffffb:
    puVar11 = local_48;
    goto LAB_0007fdf6;
  case 0xfffffffc:
    goto switchD_0007fdcc_caseD_fffffffc;
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
switchD_0007fdcc_caseD_fffffffc:
  local_48[-1] = (uchar)(uVar24 >> 0x18);
  puVar11 = local_48 + -1;
LAB_0007fdf6:
  local_48 = puVar11 + -1;
  puVar11[-1] = (uchar)(uVar24 >> 0x10);
switchD_0007fdcc_caseD_fffffffa:
  local_48[-1] = (uchar)(uVar24 >> 8);
  local_48 = local_48 + -1;
LAB_0007fe0a:
  local_48[-1] = (uchar)uVar24;
switchD_0007fdcc_caseD_7:
  *iv = bVar5;
  iv[4] = bVar7;
  iv[1] = bVar3;
  iv[2] = bVar1;
  iv[3] = bVar6;
  iv[5] = bVar4;
  iv[6] = bVar2;
  iv[7] = bVar8;
  return;
}

