
/* WARNING: Could not reconcile some variable overlaps */

void DES_ede3_cbc_encrypt
               (uchar *input,uchar *output,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int enc)

{
  byte *pbVar1;
  uchar uVar2;
  uint uVar3;
  uchar uVar4;
  uint uVar5;
  uint uVar6;
  uchar *puVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  int in_GS_OFFSET;
  uchar local_7c;
  uchar local_6c;
  uchar local_5c;
  uint *local_4c;
  uchar *local_44;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_4c = (uint *)input;
  local_44 = output;
  if (enc != 0) {
    uVar11 = *(uint *)*ivec;
    uVar9 = *(uint *)(*ivec + 4);
    uVar5 = length - 8;
    if (-1 < (int)uVar5) {
      iVar8 = (uVar5 & 0xfffffff8) + 8;
      local_4c = (uint *)(input + iVar8);
      local_24 = uVar9;
      local_28 = uVar11;
      puVar7 = output;
      do {
        puVar10 = (uint *)((int)input + 4);
        uVar11 = *(uint *)input;
        input = (uchar *)((int)input + 8);
        local_24 = local_24 ^ *puVar10;
        local_28 = local_28 ^ uVar11;
        DES_encrypt3(&local_28,ks1,ks2,ks3);
        *puVar7 = (uchar)local_28;
        puVar7[4] = (uchar)local_24;
        puVar7[1] = (uchar)(local_28 >> 8);
        puVar7[2] = (uchar)(local_28 >> 0x10);
        puVar7[3] = (uchar)(local_28 >> 0x18);
        puVar7[5] = (uchar)(local_24 >> 8);
        puVar7[6] = (uchar)(local_24 >> 0x10);
        puVar7[7] = (uchar)(local_24 >> 0x18);
        puVar7 = puVar7 + 8;
      } while (local_4c != (uint *)input);
      output = output + iVar8;
      uVar5 = length + -0x10 + (uVar5 >> 3) * -8;
      uVar9 = local_24;
      uVar11 = local_28;
    }
    if (uVar5 == 0xfffffff8) {
      local_7c = (uchar)(uVar11 >> 8);
      local_5c = (uchar)(uVar11 >> 0x18);
      local_6c = (uchar)(uVar11 >> 0x10);
      uVar4 = (uchar)(uVar9 >> 8);
      uVar2 = (uchar)(uVar9 >> 0x18);
      local_4c._0_1_ = (uchar)(uVar9 >> 0x10);
    }
    else {
      iVar8 = (int)local_4c + uVar5 + 8;
      switch(uVar5) {
      default:
        local_4c = (uint *)0x0;
        local_28 = 0;
        goto LAB_080e4855;
      case 0xfffffff9:
        local_4c = (uint *)0x0;
        local_28 = 0;
        goto LAB_080e484f;
      case 0xfffffffa:
        local_4c = (uint *)0x0;
        local_28 = 0;
        goto LAB_080e4843;
      case 0xfffffffb:
        local_4c = (uint *)0x0;
        local_28 = 0;
        goto LAB_080e4837;
      case 0xfffffffc:
        local_4c = (uint *)0x0;
        goto LAB_080e482b;
      case 0xfffffffd:
        uVar5 = 0;
        goto LAB_080e481e;
      case 0xfffffffe:
        uVar5 = 0;
        break;
      case 0xffffffff:
        pbVar1 = (byte *)(iVar8 + -1);
        iVar8 = iVar8 + -1;
        uVar5 = (uint)*pbVar1 << 0x10;
      }
      pbVar1 = (byte *)(iVar8 + -1);
      iVar8 = iVar8 + -1;
      uVar5 = uVar5 | (uint)*pbVar1 << 8;
LAB_080e481e:
      pbVar1 = (byte *)(iVar8 + -1);
      iVar8 = iVar8 + -1;
      local_4c = (uint *)(*pbVar1 | uVar5);
LAB_080e482b:
      pbVar1 = (byte *)(iVar8 + -1);
      iVar8 = iVar8 + -1;
      local_28 = (uint)*pbVar1 << 0x18;
LAB_080e4837:
      pbVar1 = (byte *)(iVar8 + -1);
      iVar8 = iVar8 + -1;
      local_28 = (uint)*pbVar1 << 0x10 | local_28;
LAB_080e4843:
      pbVar1 = (byte *)(iVar8 + -1);
      iVar8 = iVar8 + -1;
      local_28 = local_28 | (uint)*pbVar1 << 8;
LAB_080e484f:
      local_28 = local_28 | *(byte *)(iVar8 + -1);
LAB_080e4855:
      local_28 = local_28 ^ uVar11;
      local_24 = (uint)local_4c ^ uVar9;
      DES_encrypt3(&local_28,ks1,ks2,ks3);
      *output = (uchar)local_28;
      local_7c = (uchar)(local_28 >> 8);
      output[1] = local_7c;
      local_5c = (uchar)(local_28 >> 0x18);
      output[3] = local_5c;
      local_6c = (uchar)(local_28 >> 0x10);
      output[2] = local_6c;
      output[4] = (uchar)local_24;
      uVar4 = (uchar)(local_24 >> 8);
      output[5] = uVar4;
      local_4c._0_1_ = (uchar)(local_24 >> 0x10);
      output[6] = (uchar)local_4c;
      uVar2 = (uchar)(local_24 >> 0x18);
      output[7] = uVar2;
      uVar11 = local_28;
      uVar9 = local_24;
    }
    (*ivec)[0] = (uchar)uVar11;
    (*ivec)[5] = uVar4;
    (*ivec)[7] = uVar2;
    (*ivec)[1] = local_7c;
    (*ivec)[2] = local_6c;
    (*ivec)[3] = local_5c;
    (*ivec)[4] = (uchar)uVar9;
    (*ivec)[6] = (uchar)local_4c;
    goto LAB_080e47ed;
  }
  uVar11 = *(uint *)*ivec;
  uVar9 = *(uint *)(*ivec + 4);
  uVar5 = length - 8;
  if (-1 < (int)uVar5) {
    iVar8 = (uVar5 & 0xfffffff8) + 8;
    local_44 = output + iVar8;
    uVar3 = uVar9;
    uVar6 = uVar11;
    puVar10 = (uint *)input;
    do {
      uVar11 = *puVar10;
      uVar9 = puVar10[1];
      puVar7 = output + 8;
      puVar10 = puVar10 + 2;
      local_28 = uVar11;
      local_24 = uVar9;
      DES_decrypt3(&local_28,ks1,ks2,ks3);
      uVar6 = uVar6 ^ local_28;
      uVar3 = uVar3 ^ local_24;
      *output = (uchar)uVar6;
      output[4] = (uchar)uVar3;
      output[1] = (uchar)(uVar6 >> 8);
      output[3] = (uchar)(uVar6 >> 0x18);
      output[2] = (uchar)(uVar6 >> 0x10);
      output[5] = (uchar)(uVar3 >> 8);
      output[6] = (uchar)(uVar3 >> 0x10);
      output[7] = (uchar)(uVar3 >> 0x18);
      uVar3 = uVar9;
      uVar6 = uVar11;
      output = puVar7;
    } while (local_44 != puVar7);
    input = input + iVar8;
    uVar5 = length + -0x10 + (uVar5 >> 3) * -8;
  }
  uVar3 = *(uint *)((int)input + 4);
  uVar6 = *(uint *)input;
  local_28 = uVar6;
  local_24 = uVar3;
  DES_decrypt3(&local_28,ks1,ks2,ks3);
  uVar11 = uVar11 ^ local_28;
  uVar9 = local_24 ^ uVar9;
  local_44 = local_44 + uVar5 + 8;
  puVar7 = local_44;
  switch(uVar5) {
  default:
    goto switchD_080e475a_caseD_7;
  case 0xfffffff9:
    goto LAB_080e47a7;
  case 0xfffffffa:
    goto switchD_080e475a_caseD_fffffffa;
  case 0xfffffffb:
    goto LAB_080e478d;
  case 0xfffffffc:
    goto switchD_080e475a_caseD_fffffffc;
  case 0xfffffffd:
    break;
  case 0xffffffff:
    puVar7 = local_44 + -1;
    *puVar7 = (uchar)(uVar9 >> 0x10);
  case 0xfffffffe:
    local_44 = puVar7 + -1;
    puVar7[-1] = (uchar)(uVar9 >> 8);
  }
  puVar7 = local_44 + -1;
  local_44[-1] = (uchar)uVar9;
switchD_080e475a_caseD_fffffffc:
  local_44 = puVar7 + -1;
  puVar7[-1] = (uchar)(uVar11 >> 0x18);
LAB_080e478d:
  puVar7 = local_44 + -1;
  local_44[-1] = (uchar)(uVar11 >> 0x10);
switchD_080e475a_caseD_fffffffa:
  local_44 = puVar7 + -1;
  puVar7[-1] = (uchar)(uVar11 >> 8);
LAB_080e47a7:
  local_44[-1] = (uchar)uVar11;
switchD_080e475a_caseD_7:
  (*ivec)[0] = (uchar)uVar6;
  (*ivec)[4] = (uchar)uVar3;
  (*ivec)[1] = (uchar)(uVar6 >> 8);
  (*ivec)[2] = (uchar)(uVar6 >> 0x10);
  (*ivec)[3] = (uchar)(uVar6 >> 0x18);
  (*ivec)[5] = (uchar)(uVar3 >> 8);
  (*ivec)[6] = (uchar)(uVar3 >> 0x10);
  (*ivec)[7] = (uchar)(uVar3 >> 0x18);
LAB_080e47ed:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

