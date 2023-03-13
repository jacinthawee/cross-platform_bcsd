
void RC2_cbc_encrypt(uchar *in,uchar *out,long length,RC2_KEY *ks,uchar *iv,int enc)

{
  uint *puVar1;
  byte *pbVar2;
  uint *puVar3;
  uchar uVar4;
  uchar uVar5;
  uint uVar6;
  uchar *puVar7;
  uchar uVar8;
  uchar uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int in_GS_OFFSET;
  uchar local_6c;
  uchar local_5c;
  uchar local_44;
  uint *local_40;
  uchar *local_3c;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_40 = (uint *)in;
  local_3c = out;
  if (enc != 0) {
    uVar14 = *(uint *)iv;
    uVar13 = *(uint *)(iv + 4);
    uVar10 = length - 8;
    if (-1 < (int)uVar10) {
      iVar12 = (uVar10 & 0xfffffff8) + 8;
      puVar3 = (uint *)(in + iVar12);
      local_24 = uVar13;
      local_28 = uVar14;
      puVar7 = out;
      do {
        uVar14 = *(uint *)in;
        puVar1 = (uint *)((int)in + 4);
        in = (uchar *)((int)in + 8);
        local_28 = local_28 ^ uVar14;
        local_24 = local_24 ^ *puVar1;
        RC2_encrypt(&local_28,ks);
        *puVar7 = (uchar)local_28;
        puVar7[1] = (uchar)(local_28 >> 8);
        puVar7[2] = (uchar)(local_28 >> 0x10);
        puVar7[3] = (uchar)(local_28 >> 0x18);
        puVar7[4] = (uchar)local_24;
        puVar7[5] = (uchar)(local_24 >> 8);
        puVar7[6] = (uchar)(local_24 >> 0x10);
        puVar7[7] = (uchar)(local_24 >> 0x18);
        puVar7 = puVar7 + 8;
      } while (puVar3 != (uint *)in);
      local_3c = out + iVar12;
      uVar10 = length + -0x10 + (uVar10 >> 3) * -8;
      uVar13 = local_24;
      uVar14 = local_28;
      in = (uchar *)puVar3;
    }
    if (uVar10 == 0xfffffff8) {
      uVar4 = (uchar)uVar13;
      uVar8 = (uchar)(uVar14 >> 8);
      local_5c = (uchar)(uVar14 >> 0x18);
      local_6c = (uchar)(uVar14 >> 0x10);
      local_44 = (uchar)(uVar13 >> 8);
      uVar5 = (uchar)(uVar13 >> 0x18);
      uVar9 = (uchar)(uVar13 >> 0x10);
    }
    else {
      iVar12 = (int)in + uVar10 + 8;
      switch(uVar10) {
      default:
        local_24 = 0;
        local_28 = 0;
        goto LAB_080e7c36;
      case 0xfffffff9:
        local_24 = 0;
        local_28 = 0;
        goto LAB_080e7c30;
      case 0xfffffffa:
        local_24 = 0;
        local_28 = 0;
        goto LAB_080e7c24;
      case 0xfffffffb:
        local_24 = 0;
        local_28 = 0;
        goto LAB_080e7c18;
      case 0xfffffffc:
        local_24 = 0;
        goto LAB_080e7c0c;
      case 0xfffffffd:
        local_24 = 0;
        goto LAB_080e7c01;
      case 0xfffffffe:
        local_24 = 0;
        break;
      case 0xffffffff:
        pbVar2 = (byte *)(iVar12 + -1);
        iVar12 = iVar12 + -1;
        local_24 = (uint)*pbVar2 << 0x10;
      }
      pbVar2 = (byte *)(iVar12 + -1);
      iVar12 = iVar12 + -1;
      local_24 = (uint)*pbVar2 << 8 | local_24;
LAB_080e7c01:
      local_24 = *(byte *)(iVar12 + -1) | local_24;
      iVar12 = iVar12 + -1;
LAB_080e7c0c:
      pbVar2 = (byte *)(iVar12 + -1);
      iVar12 = iVar12 + -1;
      local_28 = (uint)*pbVar2 << 0x18;
LAB_080e7c18:
      pbVar2 = (byte *)(iVar12 + -1);
      iVar12 = iVar12 + -1;
      local_28 = (uint)*pbVar2 << 0x10 | local_28;
LAB_080e7c24:
      pbVar2 = (byte *)(iVar12 + -1);
      iVar12 = iVar12 + -1;
      local_28 = local_28 | (uint)*pbVar2 << 8;
LAB_080e7c30:
      local_28 = local_28 | *(byte *)(iVar12 + -1);
LAB_080e7c36:
      local_28 = uVar14 ^ local_28;
      local_24 = local_24 ^ uVar13;
      RC2_encrypt(&local_28,ks);
      *local_3c = (uchar)local_28;
      uVar8 = (uchar)(local_28 >> 8);
      local_3c[1] = uVar8;
      local_5c = (uchar)(local_28 >> 0x18);
      local_3c[3] = local_5c;
      local_6c = (uchar)(local_28 >> 0x10);
      local_3c[2] = local_6c;
      uVar4 = (uchar)local_24;
      local_3c[4] = uVar4;
      local_44 = (uchar)(local_24 >> 8);
      local_3c[5] = local_44;
      uVar5 = (uchar)(local_24 >> 0x18);
      local_3c[7] = uVar5;
      uVar9 = (uchar)(local_24 >> 0x10);
      local_3c[6] = uVar9;
      uVar14 = local_28;
    }
    *iv = (uchar)uVar14;
    iv[6] = uVar9;
    iv[1] = uVar8;
    iv[7] = uVar5;
    iv[2] = local_6c;
    iv[3] = local_5c;
    iv[4] = uVar4;
    iv[5] = local_44;
    goto LAB_080e7bd0;
  }
  uVar14 = *(uint *)iv;
  uVar13 = *(uint *)(iv + 4);
  uVar10 = length - 8;
  if (-1 < (int)uVar10) {
    iVar12 = (uVar10 & 0xfffffff8) + 8;
    local_40 = (uint *)(in + iVar12);
    uVar6 = uVar13;
    uVar11 = uVar14;
    puVar7 = out;
    do {
      uVar14 = *(uint *)in;
      uVar13 = *(uint *)((int)in + 4);
      in = (uchar *)((int)in + 8);
      local_28 = uVar14;
      local_24 = uVar13;
      RC2_decrypt(&local_28,ks);
      uVar11 = uVar11 ^ local_28;
      uVar6 = uVar6 ^ local_24;
      *puVar7 = (uchar)uVar11;
      puVar7[4] = (uchar)uVar6;
      puVar7[1] = (uchar)(uVar11 >> 8);
      puVar7[3] = (uchar)(uVar11 >> 0x18);
      puVar7[2] = (uchar)(uVar11 >> 0x10);
      puVar7[5] = (uchar)(uVar6 >> 8);
      puVar7[6] = (uchar)(uVar6 >> 0x10);
      puVar7[7] = (uchar)(uVar6 >> 0x18);
      uVar6 = uVar13;
      uVar11 = uVar14;
      puVar7 = puVar7 + 8;
    } while (local_40 != (uint *)in);
    local_3c = out + iVar12;
    uVar10 = length + -0x10 + (uVar10 >> 3) * -8;
  }
  uVar6 = local_40[1];
  uVar11 = *local_40;
  local_28 = uVar11;
  local_24 = uVar6;
  RC2_decrypt(&local_28,ks);
  uVar14 = uVar14 ^ local_28;
  uVar13 = uVar13 ^ local_24;
  local_3c = local_3c + uVar10 + 8;
  switch(uVar10) {
  default:
    goto switchD_080e7b3b_caseD_7;
  case 0xfffffff9:
    goto LAB_080e7b88;
  case 0xfffffffa:
    goto switchD_080e7b3b_caseD_fffffffa;
  case 0xfffffffb:
    puVar7 = local_3c;
    goto LAB_080e7b6e;
  case 0xfffffffc:
    goto switchD_080e7b3b_caseD_fffffffc;
  case 0xfffffffd:
    puVar7 = local_3c;
    break;
  case 0xffffffff:
    local_3c = local_3c + -1;
    *local_3c = (uchar)(uVar13 >> 0x10);
  case 0xfffffffe:
    local_3c[-1] = (uchar)(uVar13 >> 8);
    puVar7 = local_3c + -1;
  }
  local_3c = puVar7 + -1;
  puVar7[-1] = (uchar)uVar13;
switchD_080e7b3b_caseD_fffffffc:
  local_3c[-1] = (uchar)(uVar14 >> 0x18);
  puVar7 = local_3c + -1;
LAB_080e7b6e:
  local_3c = puVar7 + -1;
  puVar7[-1] = (uchar)(uVar14 >> 0x10);
switchD_080e7b3b_caseD_fffffffa:
  local_3c[-1] = (uchar)(uVar14 >> 8);
  local_3c = local_3c + -1;
LAB_080e7b88:
  local_3c[-1] = (uchar)uVar14;
switchD_080e7b3b_caseD_7:
  *iv = (uchar)uVar11;
  iv[1] = (uchar)(uVar11 >> 8);
  iv[2] = (uchar)(uVar11 >> 0x10);
  iv[3] = (uchar)(uVar11 >> 0x18);
  iv[4] = (uchar)uVar6;
  iv[5] = (uchar)(uVar6 >> 8);
  iv[6] = (uchar)(uVar6 >> 0x10);
  iv[7] = (uchar)(uVar6 >> 0x18);
LAB_080e7bd0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

