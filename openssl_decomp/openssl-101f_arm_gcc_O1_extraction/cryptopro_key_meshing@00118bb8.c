
void cryptopro_key_meshing(uint *param_1,undefined4 *param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  undefined4 local_58;
  undefined4 uStack_54;
  byte local_50 [11];
  byte local_45;
  byte local_44;
  byte local_43;
  byte local_42;
  byte local_41;
  byte local_40;
  byte local_3f;
  byte local_3e;
  byte local_3d;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  int local_2c;
  
  uVar2 = param_1[5];
  uVar11 = *param_1;
  uVar3 = param_1[6];
  uVar10 = param_1[1];
  uVar9 = param_1[2];
  uVar16 = param_1[3];
  uVar4 = param_1[7];
  uVar17 = param_1[4];
  local_2c = __TMC_END__;
  pbVar1 = local_50;
  pbVar6 = &CryptoProKeyMeshingKey;
  do {
    pbVar7 = pbVar6 + 8;
    uVar13 = (uint)pbVar6[2] << 0x10 | (uint)pbVar6[1] << 8 | (uint)*pbVar6 |
             (uint)pbVar6[3] << 0x18;
    uVar5 = uVar13 + uVar11;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = ((uint)pbVar6[6] << 0x10 | (uint)pbVar6[5] << 8 | (uint)pbVar6[4] |
            (uint)pbVar6[7] << 0x18) ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar10;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar13 + uVar9;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar16;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar13 + uVar17;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar2 + uVar8;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar3 + uVar13;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar4 + uVar8;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar4 + uVar13;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar3 + uVar8;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar2 + uVar13;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar17;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar13 + uVar16;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar9;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar13 + uVar10;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar11;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar4 + uVar13;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar3 + uVar8;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar2 + uVar13;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar17;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar13 + uVar16;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar9;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar13 + uVar10;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar11;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar4 + uVar13;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar3 + uVar8;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar2 + uVar13;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar17;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar13 + uVar16;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar9;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar13 + uVar10;
    uVar5 = param_1[(uVar5 & 0xff) + 0x308] | param_1[(uVar5 >> 0x18) + 8] |
            param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    uVar8 = uVar8 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    uVar5 = uVar8 + uVar11;
    uVar14 = param_1[(uVar5 >> 0x18) + 8];
    uVar15 = param_1[(uVar5 & 0xff) + 0x308];
    uVar12 = param_1[(uVar5 * 0x100 >> 0x18) + 0x108];
    uVar5 = param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
    *pbVar1 = (byte)uVar8;
    uVar5 = uVar15 | uVar14 | uVar12 | uVar5;
    pbVar1[3] = (byte)(uVar8 >> 0x18);
    uVar13 = uVar13 ^ (uVar5 >> 0x15 | uVar5 << 0xb);
    pbVar1[2] = (byte)(uVar8 >> 0x10);
    pbVar1[4] = (byte)uVar13;
    pbVar1[1] = (byte)(uVar8 >> 8);
    pbVar1[5] = (byte)(uVar13 >> 8);
    pbVar1[6] = (byte)(uVar13 >> 0x10);
    pbVar1[7] = (byte)(uVar13 >> 0x18);
    pbVar1 = pbVar1 + 8;
    pbVar6 = pbVar7;
  } while (pbVar7 != PTR_s_gost94_keyx_c_00119608);
  *param_1 = (uint)local_50[2] << 0x10 | (uint)local_50[3] << 0x18 | (uint)local_50[0] |
             (uint)local_50[1] << 8;
  param_1[1] = (uint)local_50[6] << 0x10 | (uint)local_50[7] << 0x18 | (uint)local_50[4] |
               (uint)local_50[5] << 8;
  param_1[2] = (uint)local_50[10] << 0x10 | (uint)local_45 << 0x18 | (uint)local_50[8] |
               (uint)local_50[9] << 8;
  param_1[3] = (uint)local_42 << 0x10 | (uint)local_41 << 0x18 | (uint)local_44 |
               (uint)local_43 << 8;
  param_1[4] = (uint)local_3e << 0x10 | (uint)local_3d << 0x18 | (uint)local_40 |
               (uint)local_3f << 8;
  param_1[5] = (uint)local_3a << 0x10 | (uint)local_39 << 0x18 | (uint)local_3c |
               (uint)local_3b << 8;
  param_1[6] = (uint)local_36 << 0x10 | (uint)local_35 << 0x18 | (uint)local_38 |
               (uint)local_37 << 8;
  param_1[7] = (uint)local_32 << 0x10 | (uint)local_33 << 8 | (uint)local_34 |
               (uint)local_31 << 0x18;
  gostcrypt(param_1,param_2,&local_58);
  *param_2 = local_58;
  bVar18 = local_2c == __TMC_END__;
  param_2[1] = uStack_54;
  if (bVar18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

