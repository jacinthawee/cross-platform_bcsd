
void CAST_cfb64_encrypt(uchar *in,uchar *out,long length,CAST_KEY *schedule,uchar *ivec,int *num,
                       int enc)

{
  byte bVar1;
  byte bVar2;
  uint **ppuVar3;
  undefined *puVar4;
  int iVar5;
  uint **ppuVar6;
  uint **ppuVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  CAST_KEY *pCVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  uint *puVar15;
  uint *unaff_s8;
  uint uStack_8c;
  uint uStack_88;
  byte abStack_84 [4];
  undefined uStack_80;
  undefined uStack_7f;
  undefined uStack_7e;
  undefined uStack_7d;
  int iStack_7c;
  uint uStack_78;
  uchar *puStack_74;
  CAST_KEY *pCStack_70;
  int *piStack_6c;
  undefined *puStack_68;
  int iStack_64;
  byte *pbStack_60;
  byte *pbStack_5c;
  uint *puStack_58;
  code *pcStack_54;
  uint *local_40;
  uint *puStack_3c;
  uint local_34;
  uint local_30;
  int local_2c;
  
  puStack_68 = PTR___stack_chk_guard_006aabf0;
  puVar15 = (uint *)&_gp;
  local_40 = (uint *)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_78 = *num;
  pCVar11 = schedule;
  iStack_64 = length;
  pbStack_60 = in;
  pbStack_5c = out;
  if (enc == 0) {
    unaff_s8 = &local_34;
    pbVar14 = out;
    if (length != 0) {
      do {
        out = (uchar *)schedule;
        if (uStack_78 == 0) {
          local_34 = *(uint *)ivec;
          local_30 = *(uint *)(ivec + 4);
          (**(code **)((int)puVar15 + -0x5504))(unaff_s8);
          length = local_34 >> 0x10;
          ivec[3] = (uchar)local_34;
          out = (uchar *)(local_30 >> 0x18);
          ivec[7] = (uchar)local_30;
          *ivec = (uchar)(local_34 >> 0x18);
          ivec[1] = (uchar)(local_34 >> 0x10);
          ivec[4] = (uchar)(local_30 >> 0x18);
          ivec[2] = (uchar)(local_34 >> 8);
          ivec[5] = (uchar)(local_30 >> 0x10);
          ivec[6] = (uchar)(local_30 >> 8);
          puVar15 = local_40;
        }
        bVar1 = *pbStack_60;
        bVar2 = ivec[uStack_78];
        in = (uchar *)(uint)bVar2;
        iStack_64 = iStack_64 + -1;
        ivec[uStack_78] = bVar1;
        pbStack_60 = pbStack_60 + 1;
        uStack_78 = uStack_78 + 1 & 7;
        *pbVar14 = bVar1 ^ bVar2;
        pbStack_5c = pbVar14 + 1;
        pbVar14 = pbVar14 + 1;
      } while (iStack_64 != 0);
    }
  }
  else if (length != 0) {
    unaff_s8 = &local_34;
    pbVar14 = out;
    do {
      if (uStack_78 == 0) {
        local_34 = *(uint *)ivec;
        local_30 = *(uint *)(ivec + 4);
        (*(code *)local_40[-0x1541])(unaff_s8,schedule);
        length = local_34 >> 0x10;
        ivec[3] = (uchar)local_34;
        out = (uchar *)(local_30 >> 0x18);
        ivec[7] = (uchar)local_30;
        *ivec = (uchar)(local_34 >> 0x18);
        ivec[1] = (uchar)(local_34 >> 0x10);
        ivec[4] = (uchar)(local_30 >> 0x18);
        ivec[2] = (uchar)(local_34 >> 8);
        ivec[5] = (uchar)(local_30 >> 0x10);
        ivec[6] = (uchar)(local_30 >> 8);
      }
      pbVar9 = ivec + uStack_78;
      bVar1 = *pbStack_60;
      pbStack_5c = pbVar14 + 1;
      bVar2 = *pbVar9;
      in = (uchar *)(uint)bVar2;
      iStack_64 = iStack_64 + -1;
      pbStack_60 = pbStack_60 + 1;
      uStack_78 = uStack_78 + 1 & 7;
      bVar1 = bVar1 ^ bVar2;
      *pbVar14 = bVar1;
      *pbVar9 = bVar1;
      puVar15 = local_40;
      pbVar14 = pbStack_5c;
    } while (iStack_64 != 0);
  }
  iVar5 = *(int *)puStack_68;
  *num = uStack_78;
  if (local_2c == iVar5) {
    return;
  }
  pcStack_54 = CAST_ofb64_encrypt;
  (*(code *)puVar15[-0x14ca])();
  puVar15 = local_40;
  puVar4 = PTR___stack_chk_guard_006aabf0;
  pCStack_70 = schedule;
  puStack_58 = unaff_s8;
  piStack_6c = num;
  puStack_74 = ivec;
  uStack_8c = *local_40;
  uStack_88 = local_40[1];
  uVar12 = *puStack_3c;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  abStack_84[3] = (char)uStack_8c;
  abStack_84[0] = (byte)(uStack_8c >> 0x18);
  abStack_84[1] = (char)(uStack_8c >> 0x10);
  uVar10 = uStack_88 >> 0x10;
  abStack_84[2] = (char)(uStack_8c >> 8);
  uStack_80 = (char)(uStack_88 >> 0x18);
  uStack_7f = (char)(uStack_88 >> 0x10);
  uStack_7e = (char)(uStack_88 >> 8);
  uStack_7d = (char)uStack_88;
  if (length != 0) {
    iVar5 = 0;
    uVar13 = length;
    do {
      if (uVar12 == 0) {
        iVar5 = iVar5 + 1;
        (*(code *)PTR_CAST_encrypt_006aa9dc)(&uStack_8c,pCVar11);
        length = uStack_8c >> 0x10;
        abStack_84[3] = (char)uStack_8c;
        uVar10 = uStack_88 >> 0x18;
        uStack_7d = (char)uStack_88;
        abStack_84[0] = (byte)(uStack_8c >> 0x18);
        abStack_84[1] = (char)(uStack_8c >> 0x10);
        uStack_80 = (char)(uStack_88 >> 0x18);
        abStack_84[2] = (char)(uStack_8c >> 8);
        uStack_7f = (char)(uStack_88 >> 0x10);
        uStack_7e = (char)(uStack_88 >> 8);
      }
      bVar1 = *in;
      uVar13 = uVar13 - 1;
      pbVar14 = abStack_84 + uVar12;
      in = in + 1;
      uVar12 = uVar12 + 1 & 7;
      *(byte *)(uint *)out = bVar1 ^ *pbVar14;
      out = (uchar *)((int)(uint *)out + 1);
    } while (uVar13 != 0);
    if (iVar5 != 0) {
      length = uStack_8c >> 0x10;
      *(char *)((int)puVar15 + 3) = (char)uStack_8c;
      uVar10 = uStack_88 >> 0x18;
      *(char *)((int)puVar15 + 7) = (char)uStack_88;
      *(char *)puVar15 = (char)(uStack_8c >> 0x18);
      *(char *)((int)puVar15 + 1) = (char)(uStack_8c >> 0x10);
      *(char *)(puVar15 + 1) = (char)(uStack_88 >> 0x18);
      *(char *)((int)puVar15 + 2) = (char)(uStack_8c >> 8);
      *(char *)((int)puVar15 + 5) = (char)(uStack_88 >> 0x10);
      *(char *)((int)puVar15 + 6) = (char)(uStack_88 >> 8);
    }
  }
  iVar5 = *(int *)puVar4;
  *puStack_3c = uVar12;
  if (iStack_7c == iVar5) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_BN_CTX_start_006a9644)(length);
  ppuVar6 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(length);
  ppuVar7 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(length);
  if (ppuVar7 == (uint **)0x0) {
    (*(code *)PTR_BN_CTX_end_006a9654)(length);
    return;
  }
  iVar5 = (*(code *)PTR_BN_copy_006a9570)(ppuVar6,puStack_3c);
  if (iVar5 == 0) {
LAB_00623404:
    (*(code *)PTR_BN_CTX_end_006a9654)(length);
    return;
  }
  iVar5 = (*(code *)PTR_BN_copy_006a9570)(ppuVar7,uVar10);
  if (iVar5 != 0) {
    if (ppuVar7[1] != (uint *)0x0) {
      if (((int)ppuVar6[1] < 1) || (iVar5 = 0, (**ppuVar6 & 1) == 0)) {
        if (((int)ppuVar7[1] < 1) || ((**ppuVar7 & 1) == 0)) goto LAB_006233cc;
        iVar5 = 0;
      }
      while (iVar8 = (*(code *)PTR_BN_is_bit_set_006a9650)(ppuVar7,iVar5), iVar8 == 0) {
        iVar5 = iVar5 + 1;
      }
      iVar5 = (*(code *)PTR_BN_rshift_006a96f8)(ppuVar7,ppuVar7,iVar5);
      if (iVar5 != 0) {
        puVar15 = ppuVar6[1];
        if (ppuVar7[3] != (uint *)0x0) {
          ppuVar7[3] = (uint *)0x0;
        }
        while (ppuVar3 = ppuVar6, puVar15 != (uint *)0x0) {
          iVar5 = 0;
          while (iVar8 = (*(code *)PTR_BN_is_bit_set_006a9650)(ppuVar3,iVar5), iVar8 == 0) {
            iVar5 = iVar5 + 1;
          }
          iVar5 = (*(code *)PTR_BN_rshift_006a96f8)(ppuVar3,ppuVar3,iVar5);
          if (iVar5 == 0) goto LAB_00623404;
          iVar5 = (*(code *)PTR_BN_nnmod_006a9664)(ppuVar7,ppuVar7,ppuVar3,length);
          if (iVar5 == 0) break;
          puVar15 = ppuVar7[1];
          ppuVar3[3] = (uint *)0x0;
          ppuVar6 = ppuVar7;
          ppuVar7 = ppuVar3;
        }
      }
    }
  }
LAB_006233cc:
  (*(code *)PTR_BN_CTX_end_006a9654)(length);
  return;
}

