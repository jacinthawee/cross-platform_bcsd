
void DES_xcbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,const_DES_cblock *inw,const_DES_cblock *outw,int enc)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uchar uVar7;
  uchar uVar8;
  uint uVar9;
  uint uVar10;
  uchar uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  uchar *puVar17;
  int in_GS_OFFSET;
  uchar local_60;
  uchar local_5c;
  uchar local_58;
  uint *local_4c;
  uchar *local_3c;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_3c = output;
  uVar3 = *(uint *)*inw;
  uVar4 = *(uint *)(*inw + 4);
  uVar5 = *(uint *)*outw;
  uVar6 = *(uint *)(*outw + 4);
  if (enc != 0) {
    uVar10 = *(uint *)*ivec;
    uVar9 = *(uint *)(*ivec + 4);
    uVar12 = length - 8;
    if (-1 < (int)uVar12) {
      iVar13 = (uVar12 & 0xfffffff8) + 8;
      puVar15 = (uint *)(input + iVar13);
      puVar17 = output;
      do {
        uVar14 = *(uint *)input;
        puVar16 = (uint *)((int)input + 4);
        input = (uchar *)((int)input + 8);
        local_24 = *puVar16 ^ uVar4 ^ uVar9;
        local_28 = uVar10 ^ uVar14 ^ uVar3;
        DES_encrypt1(&local_28,schedule,1);
        uVar10 = uVar5 ^ local_28;
        *puVar17 = (uchar)uVar10;
        puVar17[1] = (uchar)(uVar10 >> 8);
        puVar17[2] = (uchar)(uVar10 >> 0x10);
        puVar17[3] = (uchar)(uVar10 >> 0x18);
        uVar9 = uVar6 ^ local_24;
        puVar17[4] = (uchar)uVar9;
        puVar17[5] = (uchar)(uVar9 >> 8);
        puVar17[6] = (uchar)(uVar9 >> 0x10);
        puVar17[7] = (uchar)(uVar9 >> 0x18);
        puVar17 = puVar17 + 8;
      } while (puVar15 != (uint *)input);
      local_3c = output + iVar13;
      uVar12 = length + -0x10 + (uVar12 >> 3) * -8;
      input = (uchar *)puVar15;
    }
    if (uVar12 == 0xfffffff8) {
      local_60 = (uchar)(uVar10 >> 8);
      uVar7 = (uchar)(uVar10 >> 0x18);
      local_5c = (uchar)(uVar10 >> 0x10);
      local_58 = (uchar)(uVar9 >> 0x10);
      uVar11 = (uchar)(uVar9 >> 8);
      uVar8 = (uchar)(uVar9 >> 0x18);
    }
    else {
      iVar13 = (int)input + uVar12 + 8;
      switch(uVar12) {
      default:
        local_24 = 0;
        local_28 = 0;
        goto LAB_081de5da;
      case 0xfffffff9:
        local_24 = 0;
        local_28 = 0;
        goto LAB_081de5d4;
      case 0xfffffffa:
        local_24 = 0;
        local_28 = 0;
        goto LAB_081de5c8;
      case 0xfffffffb:
        local_24 = 0;
        local_28 = 0;
        goto LAB_081de5bc;
      case 0xfffffffc:
        local_24 = 0;
        goto LAB_081de5b0;
      case 0xfffffffd:
        local_24 = 0;
        goto LAB_081de5a5;
      case 0xfffffffe:
        local_24 = 0;
        break;
      case 0xffffffff:
        pbVar1 = (byte *)(iVar13 + -1);
        iVar13 = iVar13 + -1;
        local_24 = (uint)*pbVar1 << 0x10;
      }
      pbVar1 = (byte *)(iVar13 + -1);
      iVar13 = iVar13 + -1;
      local_24 = local_24 | (uint)*pbVar1 << 8;
LAB_081de5a5:
      pbVar1 = (byte *)(iVar13 + -1);
      iVar13 = iVar13 + -1;
      local_24 = *pbVar1 | local_24;
LAB_081de5b0:
      pbVar1 = (byte *)(iVar13 + -1);
      iVar13 = iVar13 + -1;
      local_28 = (uint)*pbVar1 << 0x18;
LAB_081de5bc:
      pbVar1 = (byte *)(iVar13 + -1);
      iVar13 = iVar13 + -1;
      local_28 = (uint)*pbVar1 << 0x10 | local_28;
LAB_081de5c8:
      pbVar1 = (byte *)(iVar13 + -1);
      iVar13 = iVar13 + -1;
      local_28 = local_28 | (uint)*pbVar1 << 8;
LAB_081de5d4:
      local_28 = local_28 | *(byte *)(iVar13 + -1);
LAB_081de5da:
      local_28 = local_28 ^ uVar10 ^ uVar3;
      local_24 = uVar9 ^ uVar4 ^ local_24;
      DES_encrypt1(&local_28,schedule,1);
      uVar10 = uVar5 ^ local_28;
      *local_3c = (uchar)uVar10;
      local_60 = (uchar)(uVar10 >> 8);
      local_3c[1] = local_60;
      uVar7 = (uchar)(uVar10 >> 0x18);
      local_5c = (uchar)(uVar10 >> 0x10);
      local_3c[2] = local_5c;
      local_3c[3] = uVar7;
      uVar9 = uVar6 ^ local_24;
      local_3c[4] = (uchar)uVar9;
      uVar11 = (uchar)(uVar9 >> 8);
      local_3c[5] = uVar11;
      uVar8 = (uchar)(uVar9 >> 0x18);
      local_58 = (uchar)(uVar9 >> 0x10);
      local_3c[6] = local_58;
      local_3c[7] = uVar8;
    }
    (*ivec)[0] = (uchar)uVar10;
    (*ivec)[7] = uVar8;
    (*ivec)[1] = local_60;
    (*ivec)[2] = local_5c;
    (*ivec)[3] = uVar7;
    (*ivec)[4] = (uchar)uVar9;
    (*ivec)[5] = uVar11;
    (*ivec)[6] = local_58;
    goto LAB_081de574;
  }
  uVar12 = *(uint *)*ivec;
  uVar10 = *(uint *)(*ivec + 4);
  iVar13 = length + -8;
  if (iVar13 < 1) {
    uVar14 = uVar12;
    uVar9 = uVar10;
    if (iVar13 != -8) goto LAB_081de470;
  }
  else {
    iVar2 = (length - 9U & 0xfffffff8) + 8;
    uVar14 = uVar12;
    puVar15 = (uint *)input;
    puVar17 = output;
    do {
      uVar12 = *puVar15;
      puVar16 = puVar15 + 2;
      local_28 = uVar5 ^ uVar12;
      uVar9 = puVar15[1];
      local_24 = uVar6 ^ uVar9;
      DES_encrypt1(&local_28,schedule,0);
      uVar14 = uVar14 ^ uVar3 ^ local_28;
      *puVar17 = (uchar)uVar14;
      uVar10 = uVar10 ^ uVar4 ^ local_24;
      puVar17[4] = (uchar)uVar10;
      puVar17[1] = (uchar)(uVar14 >> 8);
      puVar17[2] = (uchar)(uVar14 >> 0x10);
      puVar17[3] = (uchar)(uVar14 >> 0x18);
      puVar17[5] = (uchar)(uVar10 >> 8);
      puVar17[6] = (uchar)(uVar10 >> 0x10);
      puVar17[7] = (uchar)(uVar10 >> 0x18);
      uVar10 = uVar9;
      uVar14 = uVar12;
      puVar15 = puVar16;
      puVar17 = puVar17 + 8;
    } while ((uint *)(input + iVar2) != puVar16);
    local_3c = output + iVar2;
    iVar13 = length + -0x10 + (length - 9U >> 3) * -8;
    input = input + iVar2;
LAB_081de470:
    local_4c = &local_28;
    uVar14 = *(uint *)input;
    local_28 = uVar5 ^ uVar14;
    uVar10 = *(uint *)((int)input + 4);
    local_24 = uVar6 ^ uVar10;
    DES_encrypt1(local_4c,schedule,0);
    uVar9 = uVar9 ^ uVar4 ^ local_24;
    uVar12 = uVar12 ^ uVar3 ^ local_28;
    local_3c = local_3c + iVar13 + 8;
    switch(iVar13 + 8) {
    default:
      goto switchD_081de4d4_caseD_0;
    case 1:
      goto LAB_081de535;
    case 2:
      goto switchD_081de4d4_caseD_2;
    case 3:
      puVar17 = local_3c;
      goto LAB_081de517;
    case 4:
      goto switchD_081de4d4_caseD_4;
    case 5:
      puVar17 = local_3c;
      break;
    case 8:
      local_3c = local_3c + -1;
      *local_3c = (uchar)(uVar9 >> 0x18);
    case 7:
      local_3c = local_3c + -1;
      *local_3c = (uchar)(uVar9 >> 0x10);
    case 6:
      local_3c[-1] = (uchar)(uVar9 >> 8);
      puVar17 = local_3c + -1;
    }
    local_3c = puVar17 + -1;
    puVar17[-1] = (uchar)uVar9;
switchD_081de4d4_caseD_4:
    local_3c[-1] = (uchar)(uVar12 >> 0x18);
    puVar17 = local_3c + -1;
LAB_081de517:
    local_3c = puVar17 + -1;
    puVar17[-1] = (uchar)(uVar12 >> 0x10);
switchD_081de4d4_caseD_2:
    local_3c[-1] = (uchar)(uVar12 >> 8);
    local_3c = local_3c + -1;
LAB_081de535:
    local_60 = (uchar)uVar12;
    local_3c[-1] = local_60;
  }
switchD_081de4d4_caseD_0:
  (*ivec)[1] = (uchar)(uVar14 >> 8);
  (*ivec)[0] = (uchar)uVar14;
  (*ivec)[4] = (uchar)uVar10;
  (*ivec)[2] = (uchar)(uVar14 >> 0x10);
  (*ivec)[3] = (uchar)(uVar14 >> 0x18);
  (*ivec)[5] = (uchar)(uVar10 >> 8);
  (*ivec)[6] = (uchar)(uVar10 >> 0x10);
  (*ivec)[7] = (uchar)(uVar10 >> 0x18);
LAB_081de574:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

