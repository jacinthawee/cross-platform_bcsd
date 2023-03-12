
/* WARNING: Could not reconcile some variable overlaps */

void DES_ncbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,int enc)

{
  uint *puVar1;
  byte *pbVar2;
  uint *puVar3;
  int iVar4;
  uchar uVar5;
  uchar uVar6;
  uint uVar7;
  uint uVar8;
  uchar uVar9;
  uchar uVar10;
  uchar uVar11;
  uint uVar12;
  uchar *puVar13;
  uint uVar14;
  int iVar15;
  int in_GS_OFFSET;
  uint local_4c;
  uchar local_44;
  uint *local_40;
  uchar *local_3c;
  
  iVar4 = *(int *)(in_GS_OFFSET + 0x14);
  local_40 = (uint *)input;
  local_3c = output;
  if (enc != 0) {
    uVar8 = *(uint *)*ivec;
    uVar7 = *(uint *)(*ivec + 4);
    uVar12 = length - 8;
    if (-1 < (int)uVar12) {
      iVar15 = (uVar12 & 0xfffffff8) + 8;
      puVar3 = (uint *)(input + iVar15);
      puVar13 = output;
      do {
        puVar1 = (uint *)((int)input + 4);
        uVar14 = *(uint *)input;
        input = (uchar *)((int)input + 8);
        uVar7 = uVar7 ^ *puVar1;
        uVar8 = uVar8 ^ uVar14;
        DES_encrypt1_constprop_2();
        *puVar13 = (uchar)uVar8;
        puVar13[1] = (uchar)(uVar8 >> 8);
        puVar13[2] = (uchar)(uVar8 >> 0x10);
        puVar13[3] = (uchar)(uVar8 >> 0x18);
        puVar13[4] = (uchar)uVar7;
        puVar13[5] = (uchar)(uVar7 >> 8);
        puVar13[6] = (uchar)(uVar7 >> 0x10);
        puVar13[7] = (uchar)(uVar7 >> 0x18);
        puVar13 = puVar13 + 8;
      } while (puVar3 != (uint *)input);
      local_3c = output + iVar15;
      uVar12 = length + -0x10 + (uVar12 >> 3) * -8;
      input = (uchar *)puVar3;
    }
    uVar5 = (uchar)(uVar7 >> 0x18);
    if (uVar12 == 0xfffffff8) {
      uVar6 = (uchar)uVar7;
      uVar9 = (uchar)(uVar8 >> 8);
      local_4c._0_1_ = (uchar)(uVar8 >> 0x18);
      uVar10 = (uchar)(uVar8 >> 0x10);
      local_44 = (uchar)(uVar7 >> 8);
      uVar11 = (uchar)(uVar7 >> 0x10);
    }
    else {
      iVar15 = (int)input + uVar12 + 8;
      switch(uVar12) {
      default:
        uVar14 = 0;
        uVar12 = 0;
        goto LAB_080e67f1;
      case 0xfffffff9:
        uVar14 = 0;
        uVar12 = 0;
        goto LAB_080e67eb;
      case 0xfffffffa:
        uVar14 = 0;
        uVar12 = 0;
        goto LAB_080e67df;
      case 0xfffffffb:
        uVar14 = 0;
        uVar12 = 0;
        goto LAB_080e67d3;
      case 0xfffffffc:
        uVar14 = 0;
        goto LAB_080e67c7;
      case 0xfffffffd:
        uVar14 = 0;
        goto LAB_080e67bc;
      case 0xfffffffe:
        uVar14 = 0;
        break;
      case 0xffffffff:
        pbVar2 = (byte *)(iVar15 + -1);
        iVar15 = iVar15 + -1;
        uVar14 = (uint)*pbVar2 << 0x10;
      }
      pbVar2 = (byte *)(iVar15 + -1);
      iVar15 = iVar15 + -1;
      uVar14 = (uint)*pbVar2 << 8 | uVar14;
LAB_080e67bc:
      uVar14 = *(byte *)(iVar15 + -1) | uVar14;
      iVar15 = iVar15 + -1;
LAB_080e67c7:
      pbVar2 = (byte *)(iVar15 + -1);
      iVar15 = iVar15 + -1;
      uVar12 = (uint)*pbVar2 << 0x18;
LAB_080e67d3:
      pbVar2 = (byte *)(iVar15 + -1);
      iVar15 = iVar15 + -1;
      uVar12 = (uint)*pbVar2 << 0x10 | uVar12;
LAB_080e67df:
      pbVar2 = (byte *)(iVar15 + -1);
      iVar15 = iVar15 + -1;
      uVar12 = uVar12 | (uint)*pbVar2 << 8;
LAB_080e67eb:
      uVar12 = uVar12 | *(byte *)(iVar15 + -1);
LAB_080e67f1:
      uVar8 = uVar8 ^ uVar12;
      uVar14 = uVar14 ^ uVar7;
      DES_encrypt1_constprop_2();
      *local_3c = (uchar)uVar8;
      uVar9 = (uchar)(uVar8 >> 8);
      local_3c[1] = uVar9;
      local_4c._0_1_ = (uchar)(uVar8 >> 0x18);
      local_3c[3] = (uchar)local_4c;
      uVar10 = (uchar)(uVar8 >> 0x10);
      local_3c[2] = uVar10;
      uVar6 = (uchar)uVar14;
      local_3c[4] = uVar6;
      local_44 = (uchar)(uVar14 >> 8);
      local_3c[5] = local_44;
      local_3c[7] = uVar5;
      uVar11 = (uchar)(uVar14 >> 0x10);
      local_3c[6] = uVar11;
    }
    (*ivec)[0] = (uchar)uVar8;
    (*ivec)[6] = uVar11;
    (*ivec)[1] = uVar9;
    (*ivec)[5] = local_44;
    (*ivec)[7] = uVar5;
    (*ivec)[2] = uVar10;
    (*ivec)[3] = (uchar)local_4c;
    (*ivec)[4] = uVar6;
    goto LAB_080e678b;
  }
  local_4c = *(uint *)*ivec;
  uVar8 = *(uint *)(*ivec + 4);
  uVar12 = length - 8;
  if (-1 < (int)uVar12) {
    iVar15 = (uVar12 & 0xfffffff8) + 8;
    local_40 = (uint *)(input + iVar15);
    puVar13 = output;
    uVar7 = local_4c;
    uVar14 = uVar8;
    do {
      local_4c = *(uint *)input;
      uVar8 = *(uint *)((int)input + 4);
      input = (uchar *)((int)input + 8);
      DES_encrypt1_constprop_3(schedule);
      uVar7 = uVar7 ^ local_4c;
      uVar14 = uVar14 ^ uVar8;
      *puVar13 = (uchar)uVar7;
      puVar13[1] = (uchar)(uVar7 >> 8);
      puVar13[4] = (uchar)uVar14;
      puVar13[2] = (uchar)(uVar7 >> 0x10);
      puVar13[3] = (uchar)(uVar7 >> 0x18);
      puVar13[6] = (uchar)(uVar14 >> 0x10);
      puVar13[5] = (uchar)(uVar14 >> 8);
      puVar13[7] = (uchar)(uVar14 >> 0x18);
      puVar13 = puVar13 + 8;
      uVar7 = local_4c;
      uVar14 = uVar8;
    } while (local_40 != (uint *)input);
    local_3c = output + iVar15;
    uVar12 = length + -0x10 + (uVar12 >> 3) * -8;
  }
  uVar7 = *local_40;
  uVar14 = local_40[1];
  DES_encrypt1_constprop_3(schedule);
  local_4c = local_4c ^ uVar7;
  uVar8 = uVar8 ^ uVar14;
  local_3c = local_3c + uVar12 + 8;
  switch(uVar12) {
  default:
    goto switchD_080e6700_caseD_7;
  case 0xfffffff9:
    goto LAB_080e6743;
  case 0xfffffffa:
    goto switchD_080e6700_caseD_fffffffa;
  case 0xfffffffb:
    puVar13 = local_3c;
    goto LAB_080e672d;
  case 0xfffffffc:
    goto switchD_080e6700_caseD_fffffffc;
  case 0xfffffffd:
    puVar13 = local_3c;
    break;
  case 0xffffffff:
    local_3c = local_3c + -1;
    *local_3c = (uchar)(uVar8 >> 0x10);
  case 0xfffffffe:
    local_3c[-1] = (uchar)(uVar8 >> 8);
    puVar13 = local_3c + -1;
  }
  local_3c = puVar13 + -1;
  puVar13[-1] = (uchar)uVar8;
switchD_080e6700_caseD_fffffffc:
  local_3c[-1] = (uchar)(local_4c >> 0x18);
  puVar13 = local_3c + -1;
LAB_080e672d:
  local_3c = puVar13 + -1;
  puVar13[-1] = (uchar)(local_4c >> 0x10);
switchD_080e6700_caseD_fffffffa:
  local_3c[-1] = (uchar)(local_4c >> 8);
  local_3c = local_3c + -1;
LAB_080e6743:
  local_3c[-1] = (uchar)local_4c;
switchD_080e6700_caseD_7:
  (*ivec)[4] = (uchar)uVar14;
  (*ivec)[0] = (uchar)uVar7;
  (*ivec)[1] = (uchar)(uVar7 >> 8);
  (*ivec)[2] = (uchar)(uVar7 >> 0x10);
  (*ivec)[3] = (uchar)(uVar7 >> 0x18);
  (*ivec)[5] = (uchar)(uVar14 >> 8);
  (*ivec)[7] = (uchar)(uVar14 >> 0x18);
  (*ivec)[6] = (uchar)(uVar14 >> 0x10);
LAB_080e678b:
  if (iVar4 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

