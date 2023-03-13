
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CAST_ecb_encrypt(uchar *in,uchar *out,CAST_KEY *key,int enc)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint **ppuVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  uint **ppuVar8;
  uint **ppuVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint uVar14;
  uint uVar15;
  byte *pbVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  uint *unaff_s8;
  uint uStack_c4;
  uint uStack_c0;
  byte abStack_bc [4];
  undefined uStack_b8;
  undefined uStack_b7;
  undefined uStack_b6;
  undefined uStack_b5;
  int iStack_b4;
  uint uStack_b0;
  undefined *puStack_ac;
  byte *pbStack_a8;
  undefined *puStack_a0;
  uint uStack_9c;
  byte *pbStack_98;
  byte *pbStack_94;
  uint *puStack_90;
  code *pcStack_8c;
  uint *puStack_78;
  uint *puStack_74;
  uint uStack_6c;
  uint uStack_68;
  int iStack_64;
  uchar *puStack_60;
  undefined *puStack_5c;
  uint *puStack_24;
  int iStack_20;
  undefined4 local_1c;
  uint local_18;
  byte *local_14;
  
  puStack_5c = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(undefined4 *)in;
  local_18 = *(uint *)(in + 4);
  local_14 = *(byte **)PTR___stack_chk_guard_006a9ae8;
  if (enc == 0) {
    (*(code *)PTR_CAST_decrypt_006a98c8)(&local_1c);
  }
  else {
    (*(code *)PTR_CAST_encrypt_006a98cc)(&local_1c,key);
  }
  out[3] = (uchar)local_1c;
  out[7] = (uchar)local_18;
  *out = (uchar)((uint)local_1c >> 0x18);
  uVar15 = local_18 >> 0x18;
  out[1] = (uchar)((uint)local_1c >> 0x10);
  pbVar13 = (byte *)(local_18 >> 0x10);
  out[2] = (uchar)((uint)local_1c >> 8);
  out[4] = (uchar)(local_18 >> 0x18);
  out[5] = (uchar)(local_18 >> 0x10);
  out[6] = (uchar)(local_18 >> 8);
  if (local_14 == *(byte **)puStack_5c) {
    return;
  }
  pbVar12 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_a0 = PTR___stack_chk_guard_006a9ae8;
  puVar19 = (uint *)&_gp;
  puStack_78 = (uint *)&_gp;
  iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_b0 = *puStack_24;
  pbVar16 = (byte *)enc;
  uStack_9c = uVar15;
  pbStack_98 = pbVar12;
  pbStack_94 = pbVar13;
  puStack_60 = out;
  if (iStack_20 == 0) {
    unaff_s8 = &uStack_6c;
    for (; uStack_9c != 0; uStack_9c = uStack_9c - 1) {
      pbVar13 = (byte *)enc;
      if (uStack_b0 == 0) {
        uStack_6c = __gp;
        uStack_68 = _DAT_006aede4;
        (**(code **)((int)puVar19 + -0x5514))(unaff_s8);
        uVar15 = uStack_6c >> 0x10;
        pbVar13 = (byte *)(uStack_68 >> 0x18);
        __gp = uStack_6c & 0xff000000 | (uStack_6c >> 0x10 & 0xff) << 0x10 | uStack_6c & 0xffff;
        _DAT_006aede4 =
             uStack_68 & 0xff000000 | (uStack_68 >> 0x10 & 0xff) << 0x10 | uStack_68 & 0xffff;
        puVar19 = puStack_78;
      }
      bVar2 = *pbStack_98;
      bVar3 = (&_gp)[uStack_b0];
      pbVar12 = (byte *)(uint)bVar3;
      (&_gp)[uStack_b0] = bVar2;
      pbStack_98 = pbStack_98 + 1;
      uStack_b0 = uStack_b0 + 1 & 7;
      *pbStack_94 = bVar2 ^ bVar3;
      pbStack_94 = pbStack_94 + 1;
    }
  }
  else if (uVar15 != 0) {
    unaff_s8 = &uStack_6c;
    pbVar1 = pbVar13;
    uVar14 = uStack_6c;
    uVar17 = uStack_68;
    uVar18 = __gp;
    uVar6 = _DAT_006aede4;
    do {
      uStack_68 = uVar6;
      uStack_6c = uVar18;
      __gp = uStack_6c;
      _DAT_006aede4 = uStack_68;
      if (uStack_b0 == 0) {
        (*(code *)puStack_78[-0x1545])(unaff_s8,enc);
        uVar15 = uStack_6c >> 0x10;
        pbVar13 = (byte *)(uStack_68 >> 0x18);
        __gp = uStack_6c & 0xff000000 | (uStack_6c >> 0x10 & 0xff) << 0x10 | uStack_6c & 0xffff;
        _DAT_006aede4 =
             uStack_68 & 0xff000000 | (uStack_68 >> 0x10 & 0xff) << 0x10 | uStack_68 & 0xffff;
        uVar17 = uStack_68;
        uVar14 = uStack_6c;
      }
      uStack_6c = uVar14;
      uStack_68 = uVar17;
      pbVar11 = &_gp + uStack_b0;
      bVar2 = *pbStack_98;
      pbStack_94 = pbVar1 + 1;
      bVar3 = *pbVar11;
      pbVar12 = (byte *)(uint)bVar3;
      uStack_9c = uStack_9c - 1;
      pbStack_98 = pbStack_98 + 1;
      uStack_b0 = uStack_b0 + 1 & 7;
      bVar2 = bVar2 ^ bVar3;
      *pbVar1 = bVar2;
      *pbVar11 = bVar2;
      puVar19 = puStack_78;
      pbVar1 = pbStack_94;
      uVar14 = uStack_6c;
      uVar17 = uStack_68;
      uVar18 = __gp;
      uVar6 = _DAT_006aede4;
    } while (uStack_9c != 0);
  }
  iVar7 = *(int *)puStack_a0;
  *puStack_24 = uStack_b0;
  if (iStack_64 == iVar7) {
    return;
  }
  pcStack_8c = CAST_ofb64_encrypt;
  (*(code *)puVar19[-0x14cc])();
  puVar19 = puStack_78;
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  pbStack_a8 = (byte *)enc;
  puStack_90 = unaff_s8;
  puStack_ac = &_gp;
  uStack_c4 = *puStack_78;
  uStack_c0 = puStack_78[1];
  uVar17 = *puStack_74;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  abStack_bc[3] = (char)uStack_c4;
  abStack_bc[0] = (byte)(uStack_c4 >> 0x18);
  abStack_bc[1] = (char)(uStack_c4 >> 0x10);
  uVar14 = uStack_c0 >> 0x10;
  abStack_bc[2] = (char)(uStack_c4 >> 8);
  uStack_b8 = (char)(uStack_c0 >> 0x18);
  uStack_b7 = (char)(uStack_c0 >> 0x10);
  uStack_b6 = (char)(uStack_c0 >> 8);
  uStack_b5 = (char)uStack_c0;
  if (uVar15 != 0) {
    iVar7 = 0;
    uVar18 = uVar15;
    do {
      if (uVar17 == 0) {
        iVar7 = iVar7 + 1;
        (*(code *)PTR_CAST_encrypt_006a98cc)(&uStack_c4,pbVar16);
        uVar15 = uStack_c4 >> 0x10;
        abStack_bc[3] = (char)uStack_c4;
        uVar14 = uStack_c0 >> 0x18;
        uStack_b5 = (char)uStack_c0;
        abStack_bc[0] = (byte)(uStack_c4 >> 0x18);
        abStack_bc[1] = (char)(uStack_c4 >> 0x10);
        uStack_b8 = (char)(uStack_c0 >> 0x18);
        abStack_bc[2] = (char)(uStack_c4 >> 8);
        uStack_b7 = (char)(uStack_c0 >> 0x10);
        uStack_b6 = (char)(uStack_c0 >> 8);
      }
      bVar2 = *pbVar12;
      uVar18 = uVar18 - 1;
      pbVar1 = abStack_bc + uVar17;
      pbVar12 = pbVar12 + 1;
      uVar17 = uVar17 + 1 & 7;
      *pbVar13 = bVar2 ^ *pbVar1;
      pbVar13 = pbVar13 + 1;
    } while (uVar18 != 0);
    if (iVar7 != 0) {
      uVar15 = uStack_c4 >> 0x10;
      *(char *)((int)puVar19 + 3) = (char)uStack_c4;
      uVar14 = uStack_c0 >> 0x18;
      *(char *)((int)puVar19 + 7) = (char)uStack_c0;
      *(char *)puVar19 = (char)(uStack_c4 >> 0x18);
      *(char *)((int)puVar19 + 1) = (char)(uStack_c4 >> 0x10);
      *(char *)(puVar19 + 1) = (char)(uStack_c0 >> 0x18);
      *(char *)((int)puVar19 + 2) = (char)(uStack_c4 >> 8);
      *(char *)((int)puVar19 + 5) = (char)(uStack_c0 >> 0x10);
      *(char *)((int)puVar19 + 6) = (char)(uStack_c0 >> 8);
    }
  }
  iVar7 = *(int *)puVar5;
  *puStack_74 = uVar17;
  if (iStack_b4 == iVar7) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_BN_CTX_start_006a8528)(uVar15);
  ppuVar8 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(uVar15);
  ppuVar9 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(uVar15);
  if (ppuVar9 == (uint **)0x0) {
    (*(code *)PTR_BN_CTX_end_006a8530)(uVar15);
    return;
  }
  iVar7 = (*(code *)PTR_BN_copy_006a8450)(ppuVar8,puStack_74);
  if (iVar7 == 0) {
LAB_00622a04:
    (*(code *)PTR_BN_CTX_end_006a8530)(uVar15);
    return;
  }
  iVar7 = (*(code *)PTR_BN_copy_006a8450)(ppuVar9,uVar14);
  if (iVar7 != 0) {
    if (ppuVar9[1] != (uint *)0x0) {
      if (((int)ppuVar8[1] < 1) || (iVar7 = 0, (**ppuVar8 & 1) == 0)) {
        if (((int)ppuVar9[1] < 1) || ((**ppuVar9 & 1) == 0)) goto LAB_006229cc;
        iVar7 = 0;
      }
      while (iVar10 = (*(code *)PTR_BN_is_bit_set_006a8538)(ppuVar9,iVar7), iVar10 == 0) {
        iVar7 = iVar7 + 1;
      }
      iVar7 = (*(code *)PTR_BN_rshift_006a85d4)(ppuVar9,ppuVar9,iVar7);
      if (iVar7 != 0) {
        puVar19 = ppuVar8[1];
        if (ppuVar9[3] != (uint *)0x0) {
          ppuVar9[3] = (uint *)0x0;
        }
        while (ppuVar4 = ppuVar8, puVar19 != (uint *)0x0) {
          iVar7 = 0;
          while (iVar10 = (*(code *)PTR_BN_is_bit_set_006a8538)(ppuVar4,iVar7), iVar10 == 0) {
            iVar7 = iVar7 + 1;
          }
          iVar7 = (*(code *)PTR_BN_rshift_006a85d4)(ppuVar4,ppuVar4,iVar7);
          if (iVar7 == 0) goto LAB_00622a04;
          iVar7 = (*(code *)PTR_BN_nnmod_006a8548)(ppuVar9,ppuVar9,ppuVar4,uVar15);
          if (iVar7 == 0) break;
          puVar19 = ppuVar9[1];
          ppuVar4[3] = (uint *)0x0;
          ppuVar8 = ppuVar9;
          ppuVar9 = ppuVar4;
        }
      }
    }
  }
LAB_006229cc:
  (*(code *)PTR_BN_CTX_end_006a8530)(uVar15);
  return;
}

