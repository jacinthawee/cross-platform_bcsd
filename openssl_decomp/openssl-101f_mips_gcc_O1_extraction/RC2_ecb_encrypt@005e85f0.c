
void RC2_ecb_encrypt(uchar *in,uchar *out,RC2_KEY *key,int enc)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  undefined *puVar4;
  int iVar5;
  byte *pbVar6;
  uint *puVar7;
  undefined *puVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  uint *puVar13;
  undefined4 *puVar14;
  uint *unaff_s8;
  undefined4 uStack_174;
  uint uStack_170;
  byte abStack_16c [4];
  undefined uStack_168;
  undefined uStack_167;
  undefined uStack_166;
  undefined uStack_165;
  int iStack_164;
  uint uStack_160;
  uint *puStack_15c;
  byte *pbStack_158;
  uint *puStack_154;
  undefined *puStack_150;
  undefined *puStack_14c;
  uint *puStack_148;
  byte *pbStack_144;
  uint *puStack_140;
  code *pcStack_13c;
  undefined4 *puStack_128;
  uint *puStack_124;
  uint uStack_11c;
  uint uStack_118;
  int iStack_114;
  uint uStack_110;
  undefined *puStack_10c;
  uint *puStack_108;
  uint *puStack_104;
  undefined *puStack_100;
  byte *pbStack_fc;
  uint *puStack_f8;
  byte *pbStack_f4;
  uint *puStack_f0;
  undefined4 uStack_ec;
  uint *puStack_d8;
  uint *puStack_d4;
  int iStack_d0;
  uint *puStack_cc;
  uint uStack_c4;
  uint uStack_c0;
  byte abStack_bc [4];
  byte bStack_b8;
  byte bStack_b7;
  byte bStack_b6;
  byte bStack_b5;
  int iStack_b4;
  uint uStack_b0;
  undefined *puStack_ac;
  undefined *puStack_a8;
  uint *puStack_a4;
  undefined *puStack_9c;
  byte *pbStack_98;
  uint *puStack_94;
  uint *puStack_90;
  code *pcStack_8c;
  byte *pbStack_78;
  uint *puStack_74;
  uint uStack_6c;
  uint uStack_68;
  int iStack_64;
  uchar *puStack_60;
  undefined *puStack_5c;
  undefined *local_28;
  uint *puStack_24;
  int iStack_20;
  uint local_1c;
  uint local_18;
  byte *local_14;
  
  puStack_5c = PTR___stack_chk_guard_006aabf0;
  local_28 = &_gp;
  local_14 = *(byte **)PTR___stack_chk_guard_006aabf0;
  local_1c = (uint)in[3] << 0x18 | (uint)in[1] << 8 | (uint)in[2] << 0x10 | (uint)*in;
  local_18 = (uint)in[7] << 0x18 | (uint)in[5] << 8 | (uint)in[6] << 0x10 | (uint)in[4];
  if (enc == 0) {
    (*(code *)PTR_RC2_decrypt_006aa784)(&local_1c);
  }
  else {
    (*(code *)PTR_RC2_encrypt_006aa788)(&local_1c,key);
  }
  *out = (uchar)local_1c;
  out[4] = (uchar)local_18;
  out[1] = (uchar)(local_1c >> 8);
  puVar8 = (undefined *)(local_18 >> 8);
  out[2] = (uchar)(local_1c >> 0x10);
  puStack_f8 = (uint *)(local_18 >> 0x10);
  out[3] = (uchar)(local_1c >> 0x18);
  out[5] = (uchar)(local_18 >> 8);
  out[6] = (uchar)(local_18 >> 0x10);
  out[7] = (uchar)(local_18 >> 0x18);
  if (local_14 == *(byte **)puStack_5c) {
    return;
  }
  pbStack_fc = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_9c = PTR___stack_chk_guard_006aabf0;
  pbVar12 = &_gp;
  pbStack_78 = &_gp;
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_b0 = *puStack_24;
  puStack_108 = (uint *)enc;
  puStack_a8 = puVar8;
  pbStack_98 = pbStack_fc;
  puStack_94 = puStack_f8;
  puStack_60 = out;
  if (iStack_20 == 0) {
    unaff_s8 = &uStack_6c;
    for (; puStack_a8 != (undefined *)0x0; puStack_a8 = puStack_a8 + -1) {
      puStack_f8 = (uint *)enc;
      if (uStack_b0 == 0) {
        puStack_108 = (uint *)((uint)DAT_006afee1 << 8 | (uint)DAT_006afee2 << 0x10);
        uStack_6c = (uint)DAT_006afee3 << 0x18 | (uint)puStack_108 | (uint)_gp;
        uStack_68 = (uint)DAT_006afee7 << 0x18 |
                    (uint)DAT_006afee5 << 8 | (uint)DAT_006afee6 << 0x10 | (uint)DAT_006afee4;
        (**(code **)(pbVar12 + -0x5758))(unaff_s8);
        puVar8 = (undefined *)(uStack_6c >> 0x10);
        _gp = (byte)uStack_6c;
        puStack_f8 = (uint *)(uStack_68 >> 8);
        DAT_006afee4 = (byte)uStack_68;
        DAT_006afee1 = (byte)(uStack_6c >> 8);
        DAT_006afee2 = (byte)(uStack_6c >> 0x10);
        DAT_006afee5 = (byte)(uStack_68 >> 8);
        DAT_006afee3 = (byte)(uStack_6c >> 0x18);
        DAT_006afee6 = (byte)(uStack_68 >> 0x10);
        DAT_006afee7 = (byte)(uStack_68 >> 0x18);
        pbVar12 = pbStack_78;
      }
      bVar2 = *pbStack_98;
      bVar3 = (&_gp)[uStack_b0];
      pbStack_fc = (byte *)(uint)bVar3;
      (&_gp)[uStack_b0] = bVar2;
      pbStack_98 = pbStack_98 + 1;
      uStack_b0 = uStack_b0 + 1 & 7;
      *(byte *)puStack_94 = bVar2 ^ bVar3;
      puStack_94 = (uint *)((int)puStack_94 + 1);
    }
  }
  else if (puVar8 != (undefined *)0x0) {
    unaff_s8 = &uStack_6c;
    puVar13 = puStack_f8;
    do {
      if (uStack_b0 == 0) {
        puStack_108 = (uint *)((uint)DAT_006afee1 << 8 | (uint)DAT_006afee2 << 0x10);
        uStack_6c = (uint)DAT_006afee3 << 0x18 | (uint)puStack_108 | (uint)_gp;
        uStack_68 = (uint)DAT_006afee7 << 0x18 |
                    (uint)DAT_006afee5 << 8 | (uint)DAT_006afee6 << 0x10 | (uint)DAT_006afee4;
        (**(code **)(pbStack_78 + -0x5758))(unaff_s8,enc);
        puVar8 = (undefined *)(uStack_6c >> 0x10);
        _gp = (byte)uStack_6c;
        puStack_f8 = (uint *)(uStack_68 >> 8);
        DAT_006afee4 = (byte)uStack_68;
        DAT_006afee1 = (byte)(uStack_6c >> 8);
        DAT_006afee2 = (byte)(uStack_6c >> 0x10);
        DAT_006afee5 = (byte)(uStack_68 >> 8);
        DAT_006afee3 = (byte)(uStack_6c >> 0x18);
        DAT_006afee6 = (byte)(uStack_68 >> 0x10);
        DAT_006afee7 = (byte)(uStack_68 >> 0x18);
      }
      pbVar12 = &_gp + uStack_b0;
      bVar2 = *pbStack_98;
      puStack_94 = (uint *)((int)puVar13 + 1);
      bVar3 = *pbVar12;
      pbStack_fc = (byte *)(uint)bVar3;
      puStack_a8 = puStack_a8 + -1;
      pbStack_98 = pbStack_98 + 1;
      uStack_b0 = uStack_b0 + 1 & 7;
      bVar2 = bVar2 ^ bVar3;
      *(byte *)puVar13 = bVar2;
      *pbVar12 = bVar2;
      pbVar12 = pbStack_78;
      puVar13 = puStack_94;
    } while (puStack_a8 != (undefined *)0x0);
  }
  iVar5 = *(int *)puStack_9c;
  *puStack_24 = uStack_b0;
  if (iStack_64 == iVar5) {
    return;
  }
  pcStack_8c = RC2_ofb64_encrypt;
  (**(code **)(pbVar12 + -0x5328))();
  pbStack_f4 = pbStack_78;
  puStack_100 = PTR___stack_chk_guard_006aabf0;
  puVar13 = (uint *)&_gp;
  puStack_90 = unaff_s8;
  puStack_a4 = (uint *)enc;
  puStack_ac = &_gp;
  puStack_d8 = (uint *)&_gp;
  pbStack_158 = (byte *)(uint)pbStack_78[3];
  puStack_cc = puStack_74;
  uStack_110 = *puStack_74;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_c4 = (int)pbStack_158 << 0x18 |
              (uint)pbStack_78[1] << 8 | (uint)pbStack_78[2] << 0x10 | (uint)*pbStack_78;
  uStack_c0 = (uint)pbStack_78[7] << 0x18 |
              (uint)pbStack_78[5] << 8 | (uint)pbStack_78[6] << 0x10 | (uint)pbStack_78[4];
  abStack_bc[0] = *pbStack_78;
  abStack_bc[2] = pbStack_78[2];
  pbVar12 = (byte *)(uStack_c0 >> 8);
  abStack_bc[1] = pbStack_78[1];
  abStack_bc[3] = pbStack_78[3];
  bStack_b8 = pbStack_78[4];
  bStack_b7 = pbStack_78[5];
  bStack_b6 = pbStack_78[6];
  bStack_b5 = pbStack_78[7];
  if (puVar8 != (undefined *)0x0) {
    unaff_s8 = (uint *)0x0;
    enc = (int)&uStack_c4;
    local_28 = puVar8;
    puVar7 = puStack_f8;
    do {
      if (uStack_110 == 0) {
        unaff_s8 = (uint *)((int)unaff_s8 + 1);
        (**(code **)((int)puVar13 + -0x5758))(enc,puStack_108);
        puVar8 = (undefined *)(uStack_c4 >> 0x10);
        abStack_bc[0] = (byte)uStack_c4;
        pbVar12 = (byte *)(uStack_c0 >> 8);
        bStack_b8 = (byte)uStack_c0;
        abStack_bc[1] = (byte)(uStack_c4 >> 8);
        abStack_bc[2] = (byte)(uStack_c4 >> 0x10);
        bStack_b7 = (byte)(uStack_c0 >> 8);
        abStack_bc[3] = (byte)(uStack_c4 >> 0x18);
        bStack_b6 = (byte)(uStack_c0 >> 0x10);
        bStack_b5 = (byte)(uStack_c0 >> 0x18);
        puVar13 = puStack_d8;
      }
      puStack_f8 = (uint *)((int)puVar7 + 1);
      bVar2 = *pbStack_fc;
      local_28 = local_28 + -1;
      pbVar9 = abStack_bc + uStack_110;
      pbStack_fc = pbStack_fc + 1;
      uStack_110 = uStack_110 + 1 & 7;
      *(byte *)puVar7 = bVar2 ^ *pbVar9;
      puVar7 = puStack_f8;
    } while (local_28 != (undefined *)0x0);
    if (unaff_s8 != (uint *)0x0) {
      puVar8 = (undefined *)(uStack_c4 >> 0x10);
      *pbStack_f4 = (byte)uStack_c4;
      pbVar12 = (byte *)(uStack_c0 >> 8);
      pbStack_f4[4] = (byte)uStack_c0;
      pbStack_f4[1] = (byte)(uStack_c4 >> 8);
      pbStack_f4[2] = (byte)(uStack_c4 >> 0x10);
      pbStack_f4[5] = (byte)(uStack_c0 >> 8);
      pbStack_f4[3] = (byte)(uStack_c4 >> 0x18);
      pbStack_f4[6] = (byte)(uStack_c0 >> 0x10);
      pbStack_f4[7] = (byte)(uStack_c0 >> 0x18);
    }
  }
  iVar5 = *(int *)puStack_100;
  *puStack_cc = uStack_110;
  if (iStack_b4 == iVar5) {
    return;
  }
  uStack_ec = 0x5e8bd8;
  puVar7 = puStack_cc;
  (**(code **)((int)puVar13 + -0x5328))();
  puStack_15c = puStack_d8;
  puStack_150 = PTR___stack_chk_guard_006aabf0;
  puVar14 = (undefined4 *)&_gp;
  puStack_128 = (undefined4 *)&_gp;
  iStack_114 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_160 = *puStack_d4;
  pbVar9 = pbStack_158;
  puStack_14c = puVar8;
  puStack_148 = puVar7;
  pbStack_144 = pbVar12;
  puStack_10c = local_28;
  puStack_104 = (uint *)enc;
  puStack_f0 = unaff_s8;
  if (iStack_d0 == 0) {
    for (; puStack_140 = &uStack_11c, puStack_14c != (undefined *)0x0;
        puStack_14c = puStack_14c + -1) {
      pbVar12 = pbStack_158;
      if (uStack_160 == 0) {
        uStack_11c = *puStack_15c;
        uStack_118 = puStack_15c[1];
        (**(code **)((int)puVar14 + -0x68d8))(&uStack_11c);
        puVar8 = (undefined *)(uStack_11c >> 0x10);
        *(char *)((int)puStack_15c + 3) = (char)uStack_11c;
        pbVar12 = (byte *)(uStack_118 >> 0x18);
        *(char *)((int)puStack_15c + 7) = (char)uStack_118;
        *(char *)puStack_15c = (char)(uStack_11c >> 0x18);
        *(char *)((int)puStack_15c + 1) = (char)(uStack_11c >> 0x10);
        *(char *)(puStack_15c + 1) = (char)(uStack_118 >> 0x18);
        *(char *)((int)puStack_15c + 2) = (char)(uStack_11c >> 8);
        *(char *)((int)puStack_15c + 5) = (char)(uStack_118 >> 0x10);
        *(char *)((int)puStack_15c + 6) = (char)(uStack_118 >> 8);
        puVar14 = puStack_128;
      }
      bVar2 = *(byte *)puStack_148;
      bVar3 = *(byte *)((int)puStack_15c + uStack_160);
      puVar7 = (uint *)(uint)bVar3;
      *(byte *)((int)puStack_15c + uStack_160) = bVar2;
      puStack_148 = (uint *)((int)puStack_148 + 1);
      uStack_160 = uStack_160 + 1 & 7;
      *pbStack_144 = bVar2 ^ bVar3;
      pbStack_144 = pbStack_144 + 1;
    }
  }
  else {
    puStack_140 = unaff_s8;
    if (puVar8 != (undefined *)0x0) {
      puStack_140 = &uStack_11c;
      pbVar1 = pbVar12;
      do {
        if (uStack_160 == 0) {
          uStack_11c = *puStack_15c;
          uStack_118 = puStack_15c[1];
          (*(code *)puStack_128[-0x1a36])(puStack_140,pbStack_158);
          puVar8 = (undefined *)(uStack_11c >> 0x10);
          *(char *)((int)puStack_15c + 3) = (char)uStack_11c;
          pbVar12 = (byte *)(uStack_118 >> 0x18);
          *(char *)((int)puStack_15c + 7) = (char)uStack_118;
          *(char *)puStack_15c = (char)(uStack_11c >> 0x18);
          *(char *)((int)puStack_15c + 1) = (char)(uStack_11c >> 0x10);
          *(char *)(puStack_15c + 1) = (char)(uStack_118 >> 0x18);
          *(char *)((int)puStack_15c + 2) = (char)(uStack_11c >> 8);
          *(char *)((int)puStack_15c + 5) = (char)(uStack_118 >> 0x10);
          *(char *)((int)puStack_15c + 6) = (char)(uStack_118 >> 8);
        }
        pbVar6 = (byte *)((int)puStack_15c + uStack_160);
        bVar2 = *(byte *)puStack_148;
        pbStack_144 = pbVar1 + 1;
        bVar3 = *pbVar6;
        puVar7 = (uint *)(uint)bVar3;
        puStack_14c = puStack_14c + -1;
        puStack_148 = (uint *)((int)puStack_148 + 1);
        uStack_160 = uStack_160 + 1 & 7;
        bVar2 = bVar2 ^ bVar3;
        *pbVar1 = bVar2;
        *pbVar6 = bVar2;
        puVar14 = puStack_128;
        pbVar1 = pbStack_144;
      } while (puStack_14c != (undefined *)0x0);
    }
  }
  iVar5 = *(int *)puStack_150;
  *puStack_d4 = uStack_160;
  if (iStack_114 != iVar5) {
    pcStack_13c = idea_ofb64_encrypt;
    (*(code *)puVar14[-0x14ca])();
    puVar14 = puStack_128;
    puVar4 = PTR___stack_chk_guard_006aabf0;
    puStack_154 = puStack_d4;
    uStack_174 = *puStack_128;
    uStack_170 = puStack_128[1];
    uVar11 = *puStack_124;
    iStack_164 = *(int *)PTR___stack_chk_guard_006aabf0;
    abStack_16c[3] = (char)uStack_174;
    abStack_16c[0] = (byte)((uint)uStack_174 >> 0x18);
    uVar10 = uStack_170 >> 0x18;
    abStack_16c[1] = (char)((uint)uStack_174 >> 0x10);
    abStack_16c[2] = (char)((uint)uStack_174 >> 8);
    uStack_168 = (char)(uStack_170 >> 0x18);
    uStack_167 = (char)(uStack_170 >> 0x10);
    uStack_166 = (char)(uStack_170 >> 8);
    uStack_165 = (char)uStack_170;
    if (puVar8 != (undefined *)0x0) {
      iVar5 = 0;
      do {
        if (uVar11 == 0) {
          iVar5 = iVar5 + 1;
          (*(code *)PTR_idea_encrypt_006a9608)(&uStack_174,pbVar9);
          abStack_16c[3] = (char)uStack_174;
          uStack_165 = (char)uStack_170;
          abStack_16c[0] = (byte)((uint)uStack_174 >> 0x18);
          abStack_16c[1] = (char)((uint)uStack_174 >> 0x10);
          uStack_168 = (char)(uStack_170 >> 0x18);
          abStack_16c[2] = (char)((uint)uStack_174 >> 8);
          uStack_167 = (char)(uStack_170 >> 0x10);
          uStack_166 = (char)(uStack_170 >> 8);
        }
        bVar2 = *(byte *)puVar7;
        puVar8 = puVar8 + -1;
        pbVar1 = abStack_16c + uVar11;
        puVar7 = (uint *)((int)puVar7 + 1);
        uVar11 = uVar11 + 1 & 7;
        *pbVar12 = bVar2 ^ *pbVar1;
        pbVar12 = pbVar12 + 1;
      } while (puVar8 != (undefined *)0x0);
      if (iVar5 != 0) {
        *(char *)((int)puVar14 + 3) = (char)uStack_174;
        *(char *)((int)puVar14 + 7) = (char)uStack_170;
        *(char *)puVar14 = (char)((uint)uStack_174 >> 0x18);
        *(char *)((int)puVar14 + 1) = (char)((uint)uStack_174 >> 0x10);
        *(char *)(puVar14 + 1) = (char)(uStack_170 >> 0x18);
        *(char *)((int)puVar14 + 2) = (char)((uint)uStack_174 >> 8);
        *(char *)((int)puVar14 + 5) = (char)(uStack_170 >> 0x10);
        *(char *)((int)puVar14 + 6) = (char)(uStack_170 >> 8);
      }
    }
    iVar5 = *(int *)puVar4;
    *puStack_124 = uVar11;
    if (iStack_164 == iVar5) {
      return;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (uVar10 != 1) {
                    /* WARNING: Could not recover jumptable at 0x005e9004. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_Camellia_decrypt_006a9634)();
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x005e9010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_Camellia_encrypt_006a9638)();
    return;
  }
  return;
}

