
void DES_ede3_cbc_encrypt
               (uchar *input,uchar *output,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int enc)

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
  uchar uVar10;
  uchar uVar11;
  uchar uVar12;
  int iVar13;
  uchar *puVar14;
  uchar uVar15;
  byte *pbVar16;
  uint uVar17;
  byte *pbVar18;
  uchar uVar19;
  uchar uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uchar uVar26;
  uchar *local_48;
  byte *local_44;
  uint local_30;
  uint local_2c;
  
  local_48 = output;
  local_44 = input;
  if (enc != 0) {
    uVar24 = length - 8;
    local_30 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
               (uint)(*ivec)[3] << 0x18;
    local_2c = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
               (uint)(*ivec)[7] << 0x18;
    if (-1 < (int)uVar24) {
      uVar25 = uVar24 >> 3;
      pbVar18 = input;
      puVar14 = output;
      do {
        pbVar16 = pbVar18 + 8;
        local_30 = ((uint)pbVar18[2] << 0x10 | (uint)pbVar18[1] << 8 | (uint)*pbVar18 |
                   (uint)pbVar18[3] << 0x18) ^ local_30;
        local_2c = local_2c ^
                   ((uint)pbVar18[6] << 0x10 | (uint)pbVar18[5] << 8 | (uint)pbVar18[4] |
                   (uint)pbVar18[7] << 0x18);
        DES_encrypt3(&local_30,ks1,ks2,ks3);
        puVar14[1] = (uchar)(local_30 >> 8);
        puVar14[2] = (uchar)(local_30 >> 0x10);
        puVar14[3] = (uchar)(local_30 >> 0x18);
        puVar14[5] = (uchar)(local_2c >> 8);
        *puVar14 = (uchar)local_30;
        puVar14[4] = (uchar)local_2c;
        puVar14[6] = (uchar)(local_2c >> 0x10);
        puVar14[7] = (uchar)(local_2c >> 0x18);
        pbVar18 = pbVar16;
        puVar14 = puVar14 + 8;
      } while (pbVar16 != input + (uVar24 & 0xfffffff8) + 8);
      uVar24 = length + -0x10 + uVar25 * -8;
      iVar13 = (uVar25 + 1) * 8;
      local_44 = input + iVar13;
      local_48 = output + iVar13;
    }
    if (uVar24 == 0xfffffff8) {
      uVar9 = (uchar)local_2c;
      uVar10 = (uchar)(local_2c >> 8);
      uVar11 = (uchar)(local_2c >> 0x10);
      uVar26 = (uchar)local_30;
      uVar19 = (uchar)(local_30 >> 8);
      uVar15 = (uchar)(local_30 >> 0x10);
      uVar12 = (uchar)(local_30 >> 0x18);
      uVar20 = (uchar)(local_2c >> 0x18);
      goto LAB_0007b0cc;
    }
    puVar14 = local_44 + uVar24 + 8;
    switch(uVar24) {
    default:
      uVar24 = 0;
      uVar25 = uVar24;
      goto LAB_0007b120;
    case 0xfffffff9:
      uVar25 = 0;
      uVar24 = uVar25;
      goto LAB_0007b11a;
    case 0xfffffffa:
      uVar25 = 0;
      uVar24 = uVar25;
      goto LAB_0007b110;
    case 0xfffffffb:
      uVar25 = 0;
      uVar24 = uVar25;
      goto LAB_0007b106;
    case 0xfffffffc:
      uVar24 = 0;
      goto LAB_0007b0fe;
    case 0xfffffffd:
      uVar24 = 0;
      goto LAB_0007b0f6;
    case 0xfffffffe:
      uVar24 = 0;
      break;
    case 0xffffffff:
      pbVar18 = puVar14 + -1;
      puVar14 = puVar14 + -1;
      uVar24 = (uint)*pbVar18 << 0x10;
    }
    pbVar18 = puVar14 + -1;
    puVar14 = puVar14 + -1;
    uVar24 = uVar24 | (uint)*pbVar18 << 8;
LAB_0007b0f6:
    pbVar18 = puVar14 + -1;
    puVar14 = puVar14 + -1;
    uVar24 = *pbVar18 | uVar24;
LAB_0007b0fe:
    pbVar18 = puVar14 + -1;
    puVar14 = puVar14 + -1;
    uVar25 = (uint)*pbVar18 << 0x18;
LAB_0007b106:
    pbVar18 = puVar14 + -1;
    puVar14 = puVar14 + -1;
    uVar25 = uVar25 | (uint)*pbVar18 << 0x10;
LAB_0007b110:
    pbVar18 = puVar14 + -1;
    puVar14 = puVar14 + -1;
    uVar25 = uVar25 | (uint)*pbVar18 << 8;
LAB_0007b11a:
    uVar25 = puVar14[-1] | uVar25;
LAB_0007b120:
    local_30 = uVar25 ^ local_30;
    local_2c = local_2c ^ uVar24;
    DES_encrypt3(&local_30,ks1,ks2,ks3);
    uVar26 = (uchar)local_30;
    uVar9 = (uchar)local_2c;
    uVar19 = (uchar)(local_30 >> 8);
    local_48[1] = uVar19;
    *local_48 = uVar26;
    uVar15 = (uchar)(local_30 >> 0x10);
    local_48[2] = uVar15;
    uVar12 = (uchar)(local_30 >> 0x18);
    local_48[3] = uVar12;
    local_48[4] = uVar9;
    uVar10 = (uchar)(local_2c >> 8);
    local_48[5] = uVar10;
    uVar11 = (uchar)(local_2c >> 0x10);
    local_48[6] = uVar11;
    uVar20 = (uchar)(local_2c >> 0x18);
    local_48[7] = uVar20;
LAB_0007b0cc:
    (*ivec)[0] = uVar26;
    (*ivec)[1] = uVar19;
    (*ivec)[2] = uVar15;
    (*ivec)[3] = uVar12;
    (*ivec)[4] = uVar9;
    (*ivec)[5] = uVar10;
    (*ivec)[6] = uVar11;
    (*ivec)[7] = uVar20;
    return;
  }
  uVar25 = length - 8;
  uVar21 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
           (uint)(*ivec)[3] << 0x18;
  uVar24 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
           (uint)(*ivec)[7] << 0x18;
  if (-1 < (int)uVar25) {
    uVar17 = uVar25 >> 3;
    pbVar18 = input;
    puVar14 = output;
    uVar22 = uVar21;
    uVar23 = uVar24;
    do {
      pbVar16 = pbVar18 + 8;
      uVar21 = (uint)pbVar18[2] << 0x10 | (uint)pbVar18[1] << 8 | (uint)*pbVar18 |
               (uint)pbVar18[3] << 0x18;
      uVar24 = (uint)pbVar18[6] << 0x10 | (uint)pbVar18[5] << 8 | (uint)pbVar18[4] |
               (uint)pbVar18[7] << 0x18;
      local_30 = uVar21;
      local_2c = uVar24;
      DES_decrypt3(&local_30,ks1,ks2,ks3);
      uVar22 = uVar22 ^ local_30;
      uVar23 = uVar23 ^ local_2c;
      *puVar14 = (uchar)uVar22;
      puVar14[4] = (uchar)uVar23;
      puVar14[1] = (uchar)(uVar22 >> 8);
      puVar14[2] = (uchar)(uVar22 >> 0x10);
      puVar14[3] = (uchar)(uVar22 >> 0x18);
      puVar14[5] = (uchar)(uVar23 >> 8);
      puVar14[6] = (uchar)(uVar23 >> 0x10);
      puVar14[7] = (uchar)(uVar23 >> 0x18);
      pbVar18 = pbVar16;
      puVar14 = puVar14 + 8;
      uVar22 = uVar21;
      uVar23 = uVar24;
    } while (pbVar16 != input + (uVar25 & 0xfffffff8) + 8);
    uVar25 = length + -0x10 + uVar17 * -8;
    iVar13 = (uVar17 + 1) * 8;
    local_44 = input + iVar13;
    local_48 = output + iVar13;
  }
  bVar3 = local_44[2];
  bVar1 = local_44[6];
  bVar4 = local_44[5];
  bVar2 = local_44[1];
  bVar5 = *local_44;
  bVar6 = local_44[3];
  bVar7 = local_44[4];
  bVar8 = local_44[7];
  local_30 = (uint)bVar3 << 0x10 | (uint)bVar2 << 8 | (uint)bVar5 | (uint)bVar6 << 0x18;
  local_2c = (uint)bVar1 << 0x10 | (uint)bVar4 << 8 | (uint)bVar7 | (uint)bVar8 << 0x18;
  DES_decrypt3(&local_30,ks1,ks2,ks3);
  uVar21 = uVar21 ^ local_30;
  uVar24 = uVar24 ^ local_2c;
  local_48 = local_48 + uVar25 + 8;
  puVar14 = local_48;
  switch(uVar25) {
  default:
    goto switchD_0007b044_caseD_7;
  case 0xfffffff9:
    goto LAB_0007b07c;
  case 0xfffffffa:
    goto switchD_0007b044_caseD_fffffffa;
  case 0xfffffffb:
    goto LAB_0007b06c;
  case 0xfffffffc:
    goto switchD_0007b044_caseD_fffffffc;
  case 0xfffffffd:
    break;
  case 0xffffffff:
    puVar14 = local_48 + -1;
    *puVar14 = (uchar)(uVar24 >> 0x10);
  case 0xfffffffe:
    local_48 = puVar14 + -1;
    puVar14[-1] = (uchar)(uVar24 >> 8);
  }
  puVar14 = local_48 + -1;
  local_48[-1] = (uchar)uVar24;
switchD_0007b044_caseD_fffffffc:
  local_48 = puVar14 + -1;
  puVar14[-1] = (uchar)(uVar21 >> 0x18);
LAB_0007b06c:
  puVar14 = local_48 + -1;
  local_48[-1] = (uchar)(uVar21 >> 0x10);
switchD_0007b044_caseD_fffffffa:
  local_48 = puVar14 + -1;
  puVar14[-1] = (uchar)(uVar21 >> 8);
LAB_0007b07c:
  local_48[-1] = (uchar)uVar21;
switchD_0007b044_caseD_7:
  (*ivec)[0] = bVar5;
  (*ivec)[4] = bVar7;
  (*ivec)[1] = bVar2;
  (*ivec)[2] = bVar3;
  (*ivec)[3] = bVar6;
  (*ivec)[5] = bVar4;
  (*ivec)[6] = bVar1;
  (*ivec)[7] = bVar8;
  return;
}

