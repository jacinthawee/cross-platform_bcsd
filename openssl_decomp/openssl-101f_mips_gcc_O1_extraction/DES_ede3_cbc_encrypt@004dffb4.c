
void DES_ede3_cbc_encrypt
               (uchar *input,uchar *output,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int enc)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  uchar uVar9;
  uint uVar8;
  uchar uVar14;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar15;
  uint uVar16;
  uchar *puVar17;
  uchar uVar18;
  uchar uVar20;
  uint uVar19;
  DES_key_schedule *pDVar21;
  uchar uVar23;
  uint uVar22;
  undefined *puVar24;
  DES_key_schedule *pDVar25;
  DES_key_schedule *pDVar26;
  DES_key_schedule *pDVar27;
  DES_key_schedule *pDVar28;
  DES_key_schedule **unaff_s4;
  DES_key_schedule *pDVar29;
  DES_key_schedule *pDVar30;
  uchar *puVar31;
  int iVar32;
  undefined *puVar33;
  code *pcVar34;
  undefined auStack_70 [16];
  undefined *local_60;
  uchar *local_58;
  byte *local_54;
  DES_key_schedule *local_50;
  uchar *local_4c;
  byte *local_48;
  uchar *local_44;
  int *local_40;
  uint local_3c;
  DES_key_schedule *local_34;
  DES_key_schedule *local_30;
  int local_2c;
  
  local_40 = (int *)PTR___stack_chk_guard_006aabf0;
  local_60 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pDVar27 = ks2;
  pDVar28 = ks3;
  local_48 = input;
  local_44 = output;
  if (enc == 0) {
    uVar6 = length - 8;
    pDVar26 = (DES_key_schedule *)((uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10);
    pDVar25 = (DES_key_schedule *)((uint)(*ivec)[3] << 0x18 | (uint)pDVar26 | (uint)(*ivec)[0]);
    pDVar29 = (DES_key_schedule *)
              ((uint)(*ivec)[7] << 0x18 |
              (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4]);
    local_3c = uVar6;
    if (-1 < (int)uVar6) {
      unaff_s4 = &local_34;
      pDVar21 = pDVar25;
      pDVar30 = pDVar29;
      do {
        local_58 = output + 8;
        local_54 = input + 8;
        pDVar29 = (DES_key_schedule *)
                  ((uint)input[7] << 0x18 |
                  (uint)input[5] << 8 | (uint)input[6] << 0x10 | (uint)input[4]);
        pDVar25 = (DES_key_schedule *)
                  ((uint)input[1] << 8 | (uint)input[2] << 0x10 | (uint)*input |
                  (uint)input[3] << 0x18);
        local_50 = pDVar21;
        local_4c = local_58;
        local_34 = pDVar25;
        local_30 = pDVar29;
        DES_decrypt3((uint *)unaff_s4,ks1,ks2,ks3);
        uVar6 = uVar6 - 8;
        uVar8 = (uint)local_50 ^ (uint)local_34;
        uVar19 = (uint)local_30 ^ (uint)pDVar30;
        local_58[-8] = (uchar)uVar8;
        local_58[-4] = (uchar)uVar19;
        local_58[-7] = (uchar)(uVar8 >> 8);
        pDVar26 = (DES_key_schedule *)(uVar19 >> 0x10);
        local_58[-6] = (uchar)(uVar8 >> 0x10);
        local_58[-3] = (uchar)(uVar19 >> 8);
        local_58[-5] = (uchar)(uVar8 >> 0x18);
        local_58[-2] = (uchar)(uVar19 >> 0x10);
        local_58[-1] = (uchar)(uVar19 >> 0x18);
        input = local_54;
        output = local_58;
        pDVar21 = pDVar25;
        pDVar30 = pDVar29;
      } while (-1 < (int)uVar6);
      iVar7 = ((local_3c >> 3) + 1) * 8;
      uVar6 = (length + -0x10) - (local_3c & 0xfffffff8);
      local_48 = local_48 + iVar7;
      local_44 = local_44 + iVar7;
    }
    if (uVar6 != 0xfffffff8) {
      pDVar28 = (DES_key_schedule *)
                ((uint)local_48[1] << 8 | (uint)local_48[2] << 0x10 | (uint)*local_48 |
                (uint)local_48[3] << 0x18);
      pDVar27 = (DES_key_schedule *)
                ((uint)local_48[5] << 8 | (uint)local_48[6] << 0x10 | (uint)local_48[4] |
                (uint)local_48[7] << 0x18);
      local_34 = pDVar28;
      local_30 = pDVar27;
      DES_decrypt3((uint *)&local_34,ks1,ks2,ks3);
      puVar17 = local_44 + uVar6 + 8;
      uVar19 = (uint)pDVar25 ^ (uint)local_34;
      uVar8 = (uint)local_30 ^ (uint)pDVar29;
      pDVar26 = ks2;
      pDVar25 = pDVar28;
      pDVar29 = pDVar27;
      if (7 < uVar6 + 8) goto LAB_004e0454;
      puVar31 = puVar17;
      switch(uVar6) {
      case 0xfffffff9:
        goto LAB_004e0448;
      case 0xfffffffa:
        goto switchD_004e0410_caseD_fffffffa;
      case 0xfffffffb:
        goto LAB_004e0430;
      case 0xfffffffd:
        puVar31 = puVar17 + -1;
        puVar17[-1] = (uchar)uVar8;
        break;
      case 0xffffffff:
        puVar17 = puVar17 + -1;
        *puVar17 = (uchar)(uVar8 >> 0x10);
      case 0xfffffffe:
        puVar17[-1] = (uchar)(uVar8 >> 8);
        puVar31 = puVar17 + -2;
        puVar17[-2] = (uchar)uVar8;
      }
      puVar17 = puVar31 + -1;
      puVar31[-1] = (uchar)(uVar19 >> 0x18);
LAB_004e0430:
      puVar31 = puVar17 + -1;
      puVar17[-1] = (uchar)(uVar19 >> 0x10);
switchD_004e0410_caseD_fffffffa:
      puVar17 = puVar31 + -1;
      puVar31[-1] = (uchar)(uVar19 >> 8);
LAB_004e0448:
      puVar17[-1] = (uchar)uVar19;
    }
LAB_004e0454:
    (*ivec)[0] = (uchar)pDVar25;
    (*ivec)[4] = (uchar)pDVar29;
    puVar17 = (uchar *)((uint)pDVar29 >> 8);
    (*ivec)[1] = (uchar)((uint)pDVar25 >> 8);
    (*ivec)[2] = (uchar)((uint)pDVar25 >> 0x10);
    pcVar15 = (char *)((uint)pDVar29 >> 0x18);
    (*ivec)[3] = (uchar)((uint)pDVar25 >> 0x18);
    (*ivec)[5] = (uchar)((uint)pDVar29 >> 8);
    (*ivec)[6] = (uchar)((uint)pDVar29 >> 0x10);
    (*ivec)[7] = (uchar)((uint)pDVar29 >> 0x18);
    goto LAB_004e048c;
  }
  uVar6 = length - 8;
  pDVar26 = (DES_key_schedule *)
            ((uint)(*ivec)[3] << 0x18 |
            (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0]);
  pDVar25 = (DES_key_schedule *)
            ((uint)(*ivec)[7] << 0x18 |
            (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4]);
  local_3c = uVar6;
  if (-1 < (int)uVar6) {
    unaff_s4 = &local_34;
    local_30 = pDVar25;
    local_34 = pDVar26;
    do {
      uVar6 = uVar6 - 8;
      local_30 = (DES_key_schedule *)
                 (((uint)input[7] << 0x18 |
                  (uint)input[5] << 8 | (uint)input[6] << 0x10 | (uint)input[4]) ^ (uint)local_30);
      local_34 = (DES_key_schedule *)
                 ((uint)local_34 ^
                 ((uint)input[3] << 0x18 |
                 (uint)input[1] << 8 | (uint)input[2] << 0x10 | (uint)*input));
      DES_encrypt3((uint *)unaff_s4,ks1,ks2,ks3);
      *output = (uchar)local_34;
      output[4] = (uchar)local_30;
      output[1] = (uchar)((uint)local_34 >> 8);
      output[2] = (uchar)((uint)local_34 >> 0x10);
      output[3] = (uchar)((uint)local_34 >> 0x18);
      output[5] = (uchar)((uint)local_30 >> 8);
      output[6] = (uchar)((uint)local_30 >> 0x10);
      output[7] = (uchar)((uint)local_30 >> 0x18);
      input = input + 8;
      output = output + 8;
    } while (-1 < (int)uVar6);
    iVar7 = ((local_3c >> 3) + 1) * 8;
    uVar6 = (length + -0x10) - (local_3c & 0xfffffff8);
    local_48 = local_48 + iVar7;
    local_44 = local_44 + iVar7;
    pDVar25 = local_30;
    pDVar26 = local_34;
  }
  if (uVar6 == 0xfffffff8) {
    uVar23 = (uchar)((uint)pDVar26 >> 8);
    uVar18 = (uchar)((uint)pDVar26 >> 0x10);
    uVar9 = (uchar)((uint)pDVar26 >> 0x18);
    uVar20 = (uchar)((uint)pDVar25 >> 0x18);
    pcVar15 = (char *)((uint)pDVar26 & 0xff);
    uVar14 = (uchar)pDVar25;
  }
  else {
    unaff_s4 = (DES_key_schedule **)(local_48 + uVar6 + 8);
    switch(uVar6) {
    default:
      uVar19 = 0;
      uVar6 = 0;
      goto LAB_004e056c;
    case 0xfffffff9:
      uVar19 = 0;
      uVar6 = 0;
      goto LAB_004e0564;
    case 0xfffffffa:
      uVar19 = 0;
      uVar6 = 0;
      goto LAB_004e0554;
    case 0xfffffffb:
      uVar19 = 0;
      uVar6 = 0;
      goto LAB_004e0544;
    case 0xfffffffc:
      uVar19 = 0;
      goto LAB_004e0538;
    case 0xfffffffd:
      uVar19 = 0;
      goto LAB_004e052c;
    case 0xfffffffe:
      uVar19 = 0;
      break;
    case 0xffffffff:
      pbVar1 = (byte *)((int)unaff_s4 + -1);
      unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
      uVar19 = (uint)*pbVar1 << 0x10;
    }
    pbVar1 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar19 = (uint)*pbVar1 << 8 | uVar19;
LAB_004e052c:
    pbVar1 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar19 = *pbVar1 | uVar19;
LAB_004e0538:
    pbVar1 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar6 = (uint)*pbVar1 << 0x18;
LAB_004e0544:
    pbVar1 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar6 = (uint)*pbVar1 << 0x10 | uVar6;
LAB_004e0554:
    pbVar1 = (byte *)((int)unaff_s4 + -1);
    unaff_s4 = (DES_key_schedule **)((int)unaff_s4 + -1);
    uVar6 = (uint)*pbVar1 << 8 | uVar6;
LAB_004e0564:
    uVar6 = *(byte *)((int)unaff_s4 + -1) | uVar6;
LAB_004e056c:
    local_34 = (DES_key_schedule *)(uVar6 ^ (uint)pDVar26);
    local_30 = (DES_key_schedule *)(uVar19 ^ (uint)pDVar25);
    DES_encrypt3((uint *)&local_34,ks1,ks2,ks3);
    uVar23 = (uchar)((uint)local_34 >> 8);
    uVar18 = (uchar)((uint)local_34 >> 0x10);
    local_44[1] = uVar23;
    local_44[2] = uVar18;
    uVar9 = (uchar)((uint)local_34 >> 0x18);
    local_44[3] = uVar9;
    pcVar15 = (char *)((uint)local_34 & 0xff);
    local_44[5] = (uchar)((uint)local_30 >> 8);
    uVar14 = (uchar)local_30;
    local_44[6] = (uchar)((uint)local_30 >> 0x10);
    *local_44 = (uchar)pcVar15;
    local_44[4] = uVar14;
    uVar20 = (uchar)((uint)local_30 >> 0x18);
    local_44[7] = uVar20;
    pDVar25 = local_30;
  }
  pDVar26 = (DES_key_schedule *)((uint)((int)pDVar25 << 0x10) >> 0x18);
  puVar17 = (uchar *)((uint)((int)pDVar25 << 8) >> 0x18);
  (*ivec)[0] = (uchar)pcVar15;
  (*ivec)[1] = uVar23;
  (*ivec)[2] = uVar18;
  (*ivec)[3] = uVar9;
  (*ivec)[4] = uVar14;
  (*ivec)[5] = (uchar)((uint)pDVar25 >> 8);
  (*ivec)[6] = (uchar)((uint)pDVar25 >> 0x10);
  (*ivec)[7] = uVar20;
LAB_004e048c:
  if (local_2c == *local_40) {
    return;
  }
  pcVar34 = (code *)0x4e0684;
  (**(code **)(local_60 + -0x5328))();
  puVar33 = auStack_70;
DES_fcrypt:
  pDVar25 = pDVar26;
  puVar5 = PTR___stack_chk_guard_006aabf0;
  *(DES_key_schedule **)(puVar33 + -0x14) = ks1;
  *(DES_cblock **)(puVar33 + -0x18) = ivec;
  *(code **)(puVar33 + -4) = pcVar34;
  *(DES_key_schedule ***)(puVar33 + -8) = unaff_s4;
  *(DES_key_schedule **)(puVar33 + -0xc) = pDVar28;
  *(DES_key_schedule **)(puVar33 + -0x10) = pDVar27;
  *(undefined **)(puVar33 + -0xc0) = &_gp;
  uVar23 = *puVar17;
  *(undefined4 *)(puVar33 + -0x1c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0;
  pDVar28 = (DES_key_schedule *)&DAT_00000030;
  if ((char)uVar23 == 0) {
    uVar23 = 'A';
  }
  else {
    pDVar28 = (DES_key_schedule *)((uint)(byte)(&con_salt)[(char)uVar23] << 2);
  }
  pDVar25->ks[0].cblock[0] = uVar23;
  uVar23 = puVar17[1];
  unaff_s4 = (DES_key_schedule **)0x300;
  if ((char)uVar23 == 0) {
    uVar23 = 'A';
  }
  else {
    unaff_s4 = (DES_key_schedule **)((uint)(byte)(&con_salt)[(char)uVar23] << 6);
  }
  pDVar25->ks[0].cblock[1] = uVar23;
  if (*pcVar15 == '\0') {
    iVar7 = 0;
  }
  else {
    cVar2 = pcVar15[1];
    puVar33[-0x30] = *pcVar15 << 1;
    if (cVar2 == '\0') {
      iVar7 = 1;
    }
    else {
      cVar3 = pcVar15[2];
      puVar33[-0x2f] = cVar2 << 1;
      if (cVar3 == '\0') {
        iVar7 = 2;
      }
      else {
        cVar2 = pcVar15[3];
        puVar33[-0x2e] = cVar3 << 1;
        if (cVar2 == '\0') {
          iVar7 = 3;
        }
        else {
          cVar3 = pcVar15[4];
          puVar33[-0x2d] = cVar2 << 1;
          if (cVar3 == '\0') {
            iVar7 = 4;
          }
          else {
            cVar2 = pcVar15[5];
            puVar33[-0x2c] = cVar3 << 1;
            if (cVar2 == '\0') {
              iVar7 = 5;
            }
            else {
              cVar3 = pcVar15[6];
              puVar33[-0x2b] = cVar2 << 1;
              if (cVar3 == '\0') {
                iVar7 = 6;
              }
              else {
                cVar2 = pcVar15[7];
                puVar33[-0x2a] = cVar3 << 1;
                if (cVar2 != '\0') {
                  puVar33[-0x29] = cVar2 << 1;
                  goto LAB_004e0794;
                }
                iVar7 = 7;
              }
            }
          }
        }
      }
    }
  }
  (*(code *)PTR_memset_006aab00)(puVar33 + iVar7 + -0x30,0,8 - iVar7);
LAB_004e0794:
  pDVar27 = (DES_key_schedule *)(puVar33 + -0xb0);
  DES_set_key_unchecked((const_DES_cblock *)(puVar33 + -0x30),pDVar27);
  (**(code **)(*(int *)(puVar33 + -0xc0) + -0x68f4))(puVar33 + -0xb8,pDVar27,pDVar28,unaff_s4);
  uVar19 = *(uint *)(puVar33 + -0xb8);
  puVar17 = (uchar *)((int)pDVar25->ks + 2);
  uVar10 = *(undefined4 *)(puVar33 + -0xb4);
  iVar32 = *(int *)(puVar33 + -0xc0);
  puVar33[-0x20] = 0;
  puVar33[-0x24] = (char)uVar10;
  puVar33[-0x26] = (char)(uVar19 >> 0x10);
  puVar33[-0x27] = (char)(uVar19 >> 8);
  puVar33[-0x23] = (char)((uint)uVar10 >> 8);
  uVar8 = uVar19 & 0xff;
  puVar33[-0x21] = (char)((uint)uVar10 >> 0x18);
  puVar33[-0x25] = (char)(uVar19 >> 0x18);
  uVar6 = 0x40;
  puVar33[-0x22] = (char)((uint)uVar10 >> 0x10);
  puVar33[-0x28] = (char)uVar8;
  iVar7 = 0;
  uVar19 = (uint)((uVar19 & 0x80) != 0);
LAB_004e0910:
  uVar19 = uVar19 << 1;
  iVar11 = iVar7;
  if ((uVar6 & uVar8) != 0) {
    uVar6 = uVar6 >> 1;
    goto LAB_004e0a84;
  }
  uVar6 = uVar6 >> 1;
  if (uVar6 != 0) goto LAB_004e0a8c;
LAB_004e092c:
  iVar12 = iVar11 + 1;
  uVar8 = uVar19 << 1;
  puVar24 = puVar33 + iVar11 + -0x17;
  if ((puVar24[-0x10] & 0x80) != 0) {
    uVar16 = 0x40;
    goto LAB_004e0a38;
  }
  uVar8 = uVar19 << 2;
  uVar6 = 0x20;
  if ((puVar24[-0x10] & 0x40) == 0) goto LAB_004e0964;
LAB_004e0a64:
  uVar8 = uVar8 | 1;
  if (uVar6 != 0) goto LAB_004e0a6c;
LAB_004e096c:
  iVar7 = iVar12 + 1;
  uVar19 = uVar8 << 1;
  puVar24 = puVar33 + iVar12 + -0x17;
  if ((puVar24[-0x10] & 0x80) != 0) {
    uVar16 = 0x40;
    goto LAB_004e0a04;
  }
  uVar19 = uVar8 << 2;
  uVar22 = 0x20;
  if ((puVar24[-0x10] & 0x40) == 0) goto LAB_004e09a8;
LAB_004e0a28:
  uVar19 = uVar19 | 1;
LAB_004e09a8:
  if (uVar22 != 0) goto LAB_004e08e0;
  iVar7 = iVar7 + 1;
  uVar22 = 0x80;
  *puVar17 = cov_2char[uVar19];
  do {
    puVar17 = puVar17 + 1;
    if (puVar17 == (uchar *)((int)pDVar25->ks + 0xd)) {
      pcVar15 = *(char **)(puVar33 + -0x1c);
      pcVar13 = *(char **)puVar5;
      *(undefined *)((int)pDVar25->ks + 0xd) = 0;
      if (pcVar15 == pcVar13) {
        return;
      }
      pcVar34 = DES_crypt;
      (**(code **)(iVar32 + -0x5328))();
      pDVar26 = (DES_key_schedule *)buff_6268;
      ivec = (DES_cblock *)pDVar25;
      ks1 = (DES_key_schedule *)puVar5;
      puVar33 = puVar33 + -0xd0;
      goto DES_fcrypt;
    }
    uVar6 = (uVar22 << 0x17) >> 0x18;
    uVar8 = (uint)(byte)puVar33[iVar7 + -0x28];
    uVar19 = (uint)((uVar22 & uVar8) != 0);
    if (uVar6 != 0) goto LAB_004e0910;
    iVar11 = iVar7 + 1;
    uVar19 = uVar19 << 1;
    puVar24 = puVar33 + iVar7 + -0x17;
    bVar4 = puVar24[-0x10];
    if ((bVar4 & 0x80) == 0) {
      uVar16 = 0x20;
      uVar6 = 0x40;
    }
    else {
      uVar6 = 0x40;
LAB_004e0a84:
      uVar19 = uVar19 | 1;
      if (uVar6 == 0) goto LAB_004e092c;
LAB_004e0a8c:
      puVar24 = puVar33 + iVar11 + -0x18;
      uVar16 = (uVar6 << 0x17) >> 0x18;
      bVar4 = puVar24[-0x10];
    }
    uVar8 = uVar19 << 1;
    iVar12 = iVar11;
    if ((uVar6 & bVar4) == 0) {
      if (uVar16 == 0) goto LAB_004e087c;
LAB_004e0a44:
      uVar8 = uVar8 << 1;
      uVar6 = uVar16 >> 1;
      if ((uVar16 & (byte)puVar24[-0x10]) != 0) goto LAB_004e0a64;
LAB_004e0964:
      if (uVar6 == 0) goto LAB_004e096c;
LAB_004e0a6c:
      bVar4 = puVar24[-0x10];
      uVar16 = uVar6 >> 1;
    }
    else {
LAB_004e0a38:
      uVar8 = uVar8 | 1;
      if (uVar16 != 0) goto LAB_004e0a44;
LAB_004e087c:
      uVar8 = uVar8 << 1;
      puVar24 = puVar33 + iVar12 + -0x17;
      bVar4 = puVar24[-0x10];
      if ((bVar4 & 0x80) != 0) {
        uVar6 = 0x40;
        iVar12 = iVar12 + 1;
        goto LAB_004e0a64;
      }
      uVar16 = 0x20;
      uVar6 = 0x40;
      iVar12 = iVar12 + 1;
    }
    uVar19 = uVar8 << 1;
    iVar7 = iVar12;
    if ((uVar6 & bVar4) != 0) {
LAB_004e0a04:
      uVar19 = uVar19 | 1;
    }
    if (uVar16 != 0) {
      uVar19 = uVar19 << 1;
      uVar22 = uVar16 >> 1;
      if ((uVar16 & (byte)puVar24[-0x10]) == 0) goto LAB_004e09a8;
      goto LAB_004e0a28;
    }
    uVar19 = uVar19 << 1;
    if ((puVar33[iVar7 + -0x27] & 0x80) != 0) break;
    uVar22 = 0x40;
    iVar7 = iVar7 + 1;
LAB_004e08e0:
    *puVar17 = cov_2char[uVar19];
  } while( true );
  uVar19 = uVar19 | 1;
  uVar22 = 0x40;
  iVar7 = iVar7 + 1;
  goto LAB_004e09a8;
}

