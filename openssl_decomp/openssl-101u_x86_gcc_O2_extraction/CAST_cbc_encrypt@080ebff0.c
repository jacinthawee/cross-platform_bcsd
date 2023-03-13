
void CAST_cbc_encrypt(uchar *in,uchar *out,long length,CAST_KEY *ks,uchar *iv,int enc)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uchar uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uchar uVar8;
  uint uVar9;
  uint uVar10;
  uchar *puVar11;
  int iVar12;
  int in_GS_OFFSET;
  uchar local_6c;
  uchar local_5c;
  uchar local_48;
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
    uVar5 = *(uint *)iv;
    uVar6 = *(uint *)(iv + 4);
    uVar9 = length - 8;
    uVar7 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
    uVar5 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
    if (-1 < (int)uVar9) {
      iVar12 = (uVar9 & 0xfffffff8) + 8;
      puVar2 = (uint *)(in + iVar12);
      local_24 = uVar5;
      local_28 = uVar7;
      puVar11 = out;
      do {
        uVar5 = *(uint *)in;
        uVar6 = *(uint *)((int)in + 4);
        in = (uchar *)((int)in + 8);
        local_28 = local_28 ^
                   (uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18)
        ;
        local_24 = local_24 ^
                   (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18)
        ;
        CAST_encrypt(&local_28,ks);
        puVar11[3] = (uchar)local_28;
        *puVar11 = (uchar)(local_28 >> 0x18);
        puVar11[1] = (uchar)(local_28 >> 0x10);
        puVar11[2] = (uchar)(local_28 >> 8);
        puVar11[4] = (uchar)(local_24 >> 0x18);
        puVar11[5] = (uchar)(local_24 >> 0x10);
        puVar11[6] = (uchar)(local_24 >> 8);
        puVar11[7] = (uchar)local_24;
        puVar11 = puVar11 + 8;
      } while (puVar2 != (uint *)in);
      local_3c = out + iVar12;
      uVar9 = length + -0x10 + (uVar9 >> 3) * -8;
      uVar5 = local_24;
      uVar7 = local_28;
      in = (uchar *)puVar2;
    }
    if (uVar9 == 0xfffffff8) {
      uVar8 = (uchar)(uVar7 >> 0x18);
      local_6c = (uchar)(uVar7 >> 0x10);
      local_5c = (uchar)(uVar7 >> 8);
      uVar4 = (uchar)(uVar5 >> 0x18);
      local_48 = (uchar)(uVar5 >> 0x10);
      local_44 = (uchar)(uVar5 >> 8);
    }
    else {
      iVar12 = (int)in + uVar9 + 8;
      switch(uVar9) {
      default:
        local_24 = 0;
        local_28 = 0;
        goto LAB_080ec326;
      case 0xfffffff9:
        local_24 = 0;
        local_28 = 0;
        goto LAB_080ec31d;
      case 0xfffffffa:
        local_24 = 0;
        local_28 = 0;
        goto LAB_080ec311;
      case 0xfffffffb:
        local_24 = 0;
        local_28 = 0;
        goto LAB_080ec305;
      case 0xfffffffc:
        local_24 = 0;
        goto LAB_080ec2fe;
      case 0xfffffffd:
        local_24 = 0;
        goto LAB_080ec2f0;
      case 0xfffffffe:
        local_24 = 0;
        break;
      case 0xffffffff:
        pbVar1 = (byte *)(iVar12 + -1);
        iVar12 = iVar12 + -1;
        local_24 = (uint)*pbVar1 << 8;
      }
      pbVar1 = (byte *)(iVar12 + -1);
      iVar12 = iVar12 + -1;
      local_24 = (uint)*pbVar1 << 0x10 | local_24;
LAB_080ec2f0:
      local_24 = (uint)*(byte *)(iVar12 + -1) << 0x18 | local_24;
      iVar12 = iVar12 + -1;
LAB_080ec2fe:
      local_28 = (uint)*(byte *)(iVar12 + -1);
      iVar12 = iVar12 + -1;
LAB_080ec305:
      local_28 = (uint)*(byte *)(iVar12 + -1) << 8 | local_28;
      iVar12 = iVar12 + -1;
LAB_080ec311:
      pbVar1 = (byte *)(iVar12 + -1);
      iVar12 = iVar12 + -1;
      local_28 = local_28 | (uint)*pbVar1 << 0x10;
LAB_080ec31d:
      local_28 = local_28 | (uint)*(byte *)(iVar12 + -1) << 0x18;
LAB_080ec326:
      local_28 = uVar7 ^ local_28;
      local_24 = local_24 ^ uVar5;
      CAST_encrypt(&local_28,ks);
      local_3c[3] = (uchar)local_28;
      uVar8 = (uchar)(local_28 >> 0x18);
      *local_3c = uVar8;
      local_6c = (uchar)(local_28 >> 0x10);
      local_3c[1] = local_6c;
      local_5c = (uchar)(local_28 >> 8);
      local_3c[2] = local_5c;
      uVar4 = (uchar)(local_24 >> 0x18);
      local_3c[4] = uVar4;
      local_48 = (uchar)(local_24 >> 0x10);
      local_3c[5] = local_48;
      local_44 = (uchar)(local_24 >> 8);
      local_3c[6] = local_44;
      local_3c[7] = (uchar)local_24;
      uVar5 = local_24;
      uVar7 = local_28;
    }
    *iv = uVar8;
    iv[5] = local_48;
    iv[4] = uVar4;
    iv[7] = (uchar)uVar5;
    iv[1] = local_6c;
    iv[6] = local_44;
    iv[2] = local_5c;
    iv[3] = (uchar)uVar7;
    goto LAB_080ec2bf;
  }
  uVar9 = *(uint *)iv;
  uVar5 = *(uint *)(iv + 4);
  uVar6 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
  uVar9 = length - 8;
  uVar5 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  if (-1 < (int)uVar9) {
    iVar12 = (uVar9 & 0xfffffff8) + 8;
    local_40 = (uint *)(in + iVar12);
    uVar7 = uVar6;
    uVar10 = uVar5;
    puVar11 = out;
    do {
      uVar5 = *(uint *)in;
      uVar3 = *(uint *)((int)in + 4);
      in = (uchar *)((int)in + 8);
      uVar6 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      uVar5 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      local_28 = uVar6;
      local_24 = uVar5;
      CAST_decrypt(&local_28,ks);
      uVar7 = uVar7 ^ local_28;
      uVar10 = uVar10 ^ local_24;
      puVar11[3] = (uchar)uVar7;
      *puVar11 = (uchar)(uVar7 >> 0x18);
      puVar11[1] = (uchar)(uVar7 >> 0x10);
      puVar11[4] = (uchar)(uVar10 >> 0x18);
      puVar11[2] = (uchar)(uVar7 >> 8);
      puVar11[5] = (uchar)(uVar10 >> 0x10);
      puVar11[6] = (uchar)(uVar10 >> 8);
      puVar11[7] = (uchar)uVar10;
      uVar7 = uVar6;
      uVar10 = uVar5;
      puVar11 = puVar11 + 8;
    } while ((uint *)in != local_40);
    local_3c = out + iVar12;
    uVar9 = length + -0x10 + (uVar9 >> 3) * -8;
  }
  uVar7 = *local_40;
  uVar10 = local_40[1];
  local_28 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
  local_24 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18;
  CAST_decrypt(&local_28,ks);
  uVar6 = uVar6 ^ local_28;
  uVar5 = uVar5 ^ local_24;
  local_3c = local_3c + uVar9 + 8;
  switch(uVar9) {
  default:
    goto switchD_080ec22f_caseD_7;
  case 0xfffffff9:
    goto LAB_080ec274;
  case 0xfffffffa:
    goto switchD_080ec22f_caseD_fffffffa;
  case 0xfffffffb:
    puVar11 = local_3c;
    goto LAB_080ec25e;
  case 0xfffffffc:
    goto switchD_080ec22f_caseD_fffffffc;
  case 0xfffffffd:
    puVar11 = local_3c;
    break;
  case 0xffffffff:
    local_3c = local_3c + -1;
    *local_3c = (uchar)(uVar5 >> 8);
  case 0xfffffffe:
    local_3c[-1] = (uchar)(uVar5 >> 0x10);
    puVar11 = local_3c + -1;
  }
  local_3c = puVar11 + -1;
  puVar11[-1] = (uchar)(uVar5 >> 0x18);
switchD_080ec22f_caseD_fffffffc:
  local_3c[-1] = (uchar)uVar6;
  puVar11 = local_3c + -1;
LAB_080ec25e:
  local_3c = puVar11 + -1;
  puVar11[-1] = (uchar)(uVar6 >> 8);
switchD_080ec22f_caseD_fffffffa:
  local_3c[-1] = (uchar)(uVar6 >> 0x10);
  local_3c = local_3c + -1;
LAB_080ec274:
  local_3c[-1] = (uchar)(uVar6 >> 0x18);
switchD_080ec22f_caseD_7:
  *iv = (uchar)uVar7;
  iv[1] = (uchar)((uVar7 & 0xff00) >> 8);
  iv[2] = (uchar)((uVar7 & 0xff0000) >> 0x10);
  iv[3] = (uchar)(uVar7 >> 0x18);
  iv[4] = (uchar)uVar10;
  iv[5] = (uchar)((uVar10 & 0xff00) >> 8);
  iv[6] = (uchar)((uVar10 & 0xff0000) >> 0x10);
  iv[7] = (uchar)(uVar10 >> 0x18);
LAB_080ec2bf:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

