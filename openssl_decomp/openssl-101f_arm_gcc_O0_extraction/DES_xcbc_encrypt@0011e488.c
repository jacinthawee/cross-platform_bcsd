
void DES_xcbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,const_DES_cblock *inw,const_DES_cblock *outw,int enc)

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
  int iVar11;
  uchar *puVar12;
  uchar uVar13;
  uint uVar14;
  int iVar15;
  uchar uVar16;
  uint uVar17;
  uchar uVar18;
  byte *pbVar19;
  byte *pbVar20;
  uchar *puVar21;
  uchar uVar22;
  uint uVar23;
  uchar uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uchar uVar30;
  uint uVar31;
  uchar *local_50;
  byte *local_44;
  uint local_30;
  uint local_2c;
  
  uVar26 = (uint)(*inw)[2] << 0x10 | (uint)(*inw)[1] << 8 | (uint)(*inw)[0] |
           (uint)(*inw)[3] << 0x18;
  uVar31 = (uint)(*inw)[6] << 0x10 | (uint)(*inw)[5] << 8 | (uint)(*inw)[4] |
           (uint)(*inw)[7] << 0x18;
  uVar23 = (uint)(*outw)[2] << 0x10 | (uint)(*outw)[1] << 8 | (uint)(*outw)[0] |
           (uint)(*outw)[3] << 0x18;
  uVar14 = (uint)(*outw)[4] | (uint)(*outw)[6] << 0x10 | (uint)(*outw)[5] << 8 |
           (uint)(*outw)[7] << 0x18;
  local_50 = output;
  local_44 = input;
  if (enc != 0) {
    uVar27 = length - 8;
    local_30 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
               (uint)(*ivec)[3] << 0x18;
    local_2c = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
               (uint)(*ivec)[7] << 0x18;
    if (-1 < (int)uVar27) {
      uVar28 = uVar27 >> 3;
      pbVar19 = input;
      puVar12 = output;
      do {
        pbVar20 = pbVar19 + 8;
        local_30 = local_30 ^
                   ((uint)pbVar19[2] << 0x10 | (uint)pbVar19[1] << 8 | (uint)*pbVar19 |
                   (uint)pbVar19[3] << 0x18) ^ uVar26;
        local_2c = ((uint)pbVar19[6] << 0x10 | (uint)pbVar19[5] << 8 | (uint)pbVar19[4] |
                   (uint)pbVar19[7] << 0x18) ^ uVar31 ^ local_2c;
        DES_encrypt1(&local_30,schedule,1);
        local_30 = local_30 ^ uVar23;
        *puVar12 = (uchar)local_30;
        puVar12[1] = (uchar)(local_30 >> 8);
        puVar12[2] = (uchar)(local_30 >> 0x10);
        puVar12[3] = (uchar)(local_30 >> 0x18);
        local_2c = uVar14 ^ local_2c;
        puVar12[4] = (uchar)local_2c;
        puVar12[5] = (uchar)(local_2c >> 8);
        puVar12[6] = (uchar)(local_2c >> 0x10);
        puVar12[7] = (uchar)(local_2c >> 0x18);
        pbVar19 = pbVar20;
        puVar12 = puVar12 + 8;
      } while (pbVar20 != input + (uVar27 & 0xfffffff8) + 8);
      uVar27 = length + -0x10 + uVar28 * -8;
      iVar11 = (uVar28 + 1) * 8;
      local_44 = input + iVar11;
      local_50 = output + iVar11;
    }
    if (uVar27 == 0xfffffff8) {
      uVar30 = (uchar)local_30;
      uVar24 = (uchar)(local_30 >> 8);
      uVar22 = (uchar)(local_30 >> 0x10);
      uVar18 = (uchar)local_2c;
      uVar9 = (uchar)(local_2c >> 8);
      uVar10 = (uchar)(local_2c >> 0x10);
      uVar13 = (uchar)(local_30 >> 0x18);
      uVar16 = (uchar)(local_2c >> 0x18);
      goto LAB_0011e8b6;
    }
    puVar12 = local_44 + uVar27 + 8;
    switch(uVar27) {
    default:
      uVar27 = 0;
      uVar28 = uVar27;
      goto LAB_0011e90a;
    case 0xfffffff9:
      uVar28 = 0;
      uVar27 = uVar28;
      goto LAB_0011e904;
    case 0xfffffffa:
      uVar28 = 0;
      uVar27 = uVar28;
      goto LAB_0011e8fa;
    case 0xfffffffb:
      uVar28 = 0;
      uVar27 = uVar28;
      goto LAB_0011e8f0;
    case 0xfffffffc:
      uVar27 = 0;
      goto LAB_0011e8e8;
    case 0xfffffffd:
      uVar27 = 0;
      goto LAB_0011e8e0;
    case 0xfffffffe:
      uVar27 = 0;
      break;
    case 0xffffffff:
      pbVar19 = puVar12 + -1;
      puVar12 = puVar12 + -1;
      uVar27 = (uint)*pbVar19 << 0x10;
    }
    pbVar19 = puVar12 + -1;
    puVar12 = puVar12 + -1;
    uVar27 = uVar27 | (uint)*pbVar19 << 8;
LAB_0011e8e0:
    pbVar19 = puVar12 + -1;
    puVar12 = puVar12 + -1;
    uVar27 = *pbVar19 | uVar27;
LAB_0011e8e8:
    pbVar19 = puVar12 + -1;
    puVar12 = puVar12 + -1;
    uVar28 = (uint)*pbVar19 << 0x18;
LAB_0011e8f0:
    pbVar19 = puVar12 + -1;
    puVar12 = puVar12 + -1;
    uVar28 = uVar28 | (uint)*pbVar19 << 0x10;
LAB_0011e8fa:
    pbVar19 = puVar12 + -1;
    puVar12 = puVar12 + -1;
    uVar28 = uVar28 | (uint)*pbVar19 << 8;
LAB_0011e904:
    uVar28 = puVar12[-1] | uVar28;
LAB_0011e90a:
    local_2c = uVar27 ^ local_2c ^ uVar31;
    local_30 = uVar28 ^ uVar26 ^ local_30;
    DES_encrypt1(&local_30,schedule,1);
    local_30 = local_30 ^ uVar23;
    uVar24 = (uchar)(local_30 >> 8);
    local_50[1] = uVar24;
    uVar22 = (uchar)(local_30 >> 0x10);
    local_50[2] = uVar22;
    uVar30 = (uchar)local_30;
    uVar13 = (uchar)(local_30 >> 0x18);
    local_50[3] = uVar13;
    *local_50 = uVar30;
    local_2c = local_2c ^ uVar14;
    uVar18 = (uchar)local_2c;
    uVar9 = (uchar)(local_2c >> 8);
    local_50[5] = uVar9;
    local_50[4] = uVar18;
    uVar10 = (uchar)(local_2c >> 0x10);
    local_50[6] = uVar10;
    uVar16 = (uchar)(local_2c >> 0x18);
    local_50[7] = uVar16;
LAB_0011e8b6:
    (*ivec)[0] = uVar30;
    (*ivec)[1] = uVar24;
    (*ivec)[2] = uVar22;
    (*ivec)[3] = uVar13;
    (*ivec)[4] = uVar18;
    (*ivec)[5] = uVar9;
    (*ivec)[6] = uVar10;
    (*ivec)[7] = uVar16;
    return;
  }
  iVar11 = length + -8;
  uVar28 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
           (uint)(*ivec)[3] << 0x18;
  uVar27 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
           (uint)(*ivec)[7] << 0x18;
  if (0 < iVar11) {
    uVar17 = length - 9U >> 3;
    puVar12 = output;
    pbVar19 = input;
    uVar25 = uVar28;
    uVar29 = uVar27;
    do {
      puVar21 = puVar12 + 8;
      uVar28 = (uint)pbVar19[2] << 0x10 | (uint)pbVar19[1] << 8 | (uint)*pbVar19 |
               (uint)pbVar19[3] << 0x18;
      local_30 = uVar23 ^ uVar28;
      uVar27 = (uint)pbVar19[6] << 0x10 | (uint)pbVar19[5] << 8 | (uint)pbVar19[4] |
               (uint)pbVar19[7] << 0x18;
      local_2c = uVar14 ^ uVar27;
      DES_encrypt1(&local_30,schedule,0);
      uVar25 = local_30 ^ uVar26 ^ uVar25;
      *puVar12 = (uchar)uVar25;
      uVar29 = local_2c ^ uVar31 ^ uVar29;
      puVar12[4] = (uchar)uVar29;
      puVar12[1] = (uchar)(uVar25 >> 8);
      puVar12[5] = (uchar)(uVar29 >> 8);
      puVar12[2] = (uchar)(uVar25 >> 0x10);
      puVar12[3] = (uchar)(uVar25 >> 0x18);
      puVar12[6] = (uchar)(uVar29 >> 0x10);
      puVar12[7] = (uchar)(uVar29 >> 0x18);
      puVar12 = puVar21;
      pbVar19 = pbVar19 + 8;
      uVar25 = uVar28;
      uVar29 = uVar27;
    } while (puVar21 != output + (length - 9U & 0xfffffff8) + 8);
    iVar15 = (uVar17 + 1) * 8;
    local_44 = input + iVar15;
    iVar11 = length + -0x10 + uVar17 * -8;
    local_50 = output + iVar15;
  }
  bVar1 = local_44[2];
  bVar2 = local_44[1];
  bVar3 = *local_44;
  bVar4 = local_44[3];
  local_30 = uVar23 ^ ((uint)bVar1 << 0x10 | (uint)bVar2 << 8 | (uint)bVar3 | (uint)bVar4 << 0x18);
  bVar5 = local_44[6];
  bVar6 = local_44[5];
  bVar7 = local_44[7];
  bVar8 = local_44[4];
  local_2c = ((uint)bVar5 << 0x10 | (uint)bVar6 << 8 | (uint)bVar8 | (uint)bVar7 << 0x18) ^ uVar14;
  DES_encrypt1(&local_30,schedule,0);
  uVar28 = uVar28 ^ local_30 ^ uVar26;
  uVar27 = local_2c ^ uVar31 ^ uVar27;
  local_50 = local_50 + iVar11 + 8;
  puVar12 = local_50;
  switch(iVar11) {
  case 0:
    local_50 = local_50 + -1;
    *local_50 = (uchar)(uVar27 >> 0x18);
  case -1:
    puVar12 = local_50 + -1;
    *puVar12 = (uchar)(uVar27 >> 0x10);
  case -2:
    local_50 = puVar12 + -1;
    puVar12[-1] = (uchar)(uVar27 >> 8);
    break;
  default:
    goto switchD_0011e82c_caseD_8;
  case -7:
    goto LAB_0011e86a;
  case -6:
    goto switchD_0011e82c_caseD_fffffffa;
  case -5:
    puVar12 = local_50;
    goto LAB_0011e85a;
  case -4:
    goto switchD_0011e82c_caseD_fffffffc;
  case -3:
  }
  puVar12 = local_50 + -1;
  local_50[-1] = (uchar)uVar27;
switchD_0011e82c_caseD_fffffffc:
  puVar12[-1] = (uchar)(uVar28 >> 0x18);
  puVar12 = puVar12 + -1;
LAB_0011e85a:
  local_50 = puVar12 + -1;
  puVar12[-1] = (uchar)(uVar28 >> 0x10);
switchD_0011e82c_caseD_fffffffa:
  local_50[-1] = (uchar)(uVar28 >> 8);
  local_50 = local_50 + -1;
LAB_0011e86a:
  local_50[-1] = (uchar)uVar28;
switchD_0011e82c_caseD_8:
  (*ivec)[0] = bVar3;
  (*ivec)[1] = bVar2;
  (*ivec)[2] = bVar1;
  (*ivec)[4] = bVar8;
  (*ivec)[3] = bVar4;
  (*ivec)[5] = bVar6;
  (*ivec)[6] = bVar5;
  (*ivec)[7] = bVar7;
  return;
}

