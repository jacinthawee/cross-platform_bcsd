
void DES_ede3_ofb64_encrypt
               (uchar *in,uchar *out,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int *num)

{
  byte *pbVar1;
  byte bVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint *unaff_s1;
  DES_key_schedule *pDVar15;
  int unaff_s5;
  uint *puVar16;
  long unaff_s6;
  byte *pbVar17;
  byte *pbVar18;
  uint uStack_a4;
  uint uStack_a0;
  byte abStack_9c [4];
  byte bStack_98;
  byte bStack_97;
  byte bStack_96;
  byte bStack_95;
  int iStack_94;
  uint uStack_90;
  uint *puStack_8c;
  DES_key_schedule *pDStack_88;
  DES_key_schedule *pDStack_84;
  DES_cblock *pauStack_80;
  int iStack_7c;
  int iStack_78;
  byte *pbStack_74;
  byte *pbStack_70;
  undefined4 uStack_6c;
  byte *local_58;
  uint *puStack_54;
  DES_key_schedule *local_4c;
  uint *local_48;
  int *local_44;
  uint local_3c;
  uint local_38;
  byte local_34 [4];
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  int local_2c;
  
  pbVar17 = &_gp;
  local_44 = (int *)PTR___stack_chk_guard_006aabf0;
  local_58 = &_gp;
  local_4c = ks1;
  uVar10 = (uint)(*ivec)[3];
  uVar9 = (uint)(*ivec)[7];
  local_48 = (uint *)num;
  uVar6 = uVar10 << 0x18 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0];
  uStack_90 = *num;
  uVar14 = uVar6 >> 8;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pbVar7 = (byte *)(uVar9 << 0x18);
  local_3c = uVar6;
  uVar5 = (uint)pbVar7 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4];
  uVar13 = uVar6 >> 0x10;
  local_38 = uVar5;
  uVar12 = uVar5 >> 8;
  local_34[0] = (*ivec)[0];
  uVar11 = uVar5 >> 0x10;
  local_34[1] = (*ivec)[1];
  local_34[2] = (*ivec)[2];
  local_34[3] = (*ivec)[3];
  local_30 = (*ivec)[4];
  local_2f = (*ivec)[5];
  local_2e = (*ivec)[6];
  local_2d = (*ivec)[7];
  if (length != 0) {
    unaff_s5 = 0;
    unaff_s1 = &local_3c;
    unaff_s6 = length;
    pbVar18 = out;
    do {
      if (uStack_90 == 0) {
        unaff_s5 = unaff_s5 + 1;
        length = (long)ks2;
        (**(code **)(pbVar17 + -0x5764))(unaff_s1,local_4c,ks2,ks3);
        uVar14 = local_3c >> 8;
        uVar13 = local_3c >> 0x10;
        local_34[0] = (byte)local_3c;
        uVar10 = local_3c >> 0x18;
        local_30 = (byte)local_38;
        uVar12 = local_38 >> 8;
        local_34[1] = (byte)(local_3c >> 8);
        uVar11 = local_38 >> 0x10;
        local_34[2] = (byte)(local_3c >> 0x10);
        uVar9 = local_38 >> 0x18;
        local_34[3] = (byte)(local_3c >> 0x18);
        local_2f = (byte)(local_38 >> 8);
        local_2e = (byte)(local_38 >> 0x10);
        local_2d = (byte)(local_38 >> 0x18);
        uVar5 = local_38;
        uVar6 = local_3c;
        pbVar17 = local_58;
      }
      out = pbVar18 + 1;
      bVar2 = *in;
      unaff_s6 = unaff_s6 + -1;
      pbVar1 = local_34 + uStack_90;
      pbVar7 = (byte *)(uint)*pbVar1;
      in = in + 1;
      uStack_90 = uStack_90 + 1 & 7;
      *pbVar18 = bVar2 ^ *pbVar1;
      pbVar18 = out;
    } while (unaff_s6 != 0);
    if (unaff_s5 != 0) {
      (*ivec)[0] = (uchar)uVar6;
      (*ivec)[1] = (uchar)uVar14;
      (*ivec)[2] = (uchar)uVar13;
      (*ivec)[3] = (uchar)uVar10;
      (*ivec)[4] = (uchar)uVar5;
      (*ivec)[5] = (uchar)uVar12;
      (*ivec)[6] = (uchar)uVar11;
      (*ivec)[7] = (uchar)uVar9;
    }
  }
  iVar4 = *local_44;
  *local_48 = uStack_90;
  if (local_2c == iVar4) {
    return;
  }
  uStack_6c = 0x5e6f08;
  puVar16 = local_48;
  (**(code **)(pbVar17 + -0x5328))();
  pbVar17 = local_58;
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pbStack_74 = in;
  iStack_78 = unaff_s6;
  iStack_7c = unaff_s5;
  pauStack_80 = ivec;
  pDStack_88 = ks2;
  pbStack_70 = out;
  pDStack_84 = ks3;
  puStack_8c = unaff_s1;
  uVar5 = (uint)local_58[3];
  uVar6 = *puStack_54;
  uStack_a4 = uVar5 << 0x18 | (uint)local_58[1] << 8 | (uint)local_58[2] << 0x10 | (uint)*local_58;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_a0 = (uint)local_58[7] << 0x18 |
              (uint)local_58[5] << 8 | (uint)local_58[6] << 0x10 | (uint)local_58[4];
  abStack_9c[0] = *local_58;
  abStack_9c[2] = local_58[2];
  puVar8 = (uint *)(uStack_a0 >> 8);
  abStack_9c[1] = local_58[1];
  abStack_9c[3] = local_58[3];
  bStack_98 = local_58[4];
  bStack_97 = local_58[5];
  bStack_96 = local_58[6];
  bStack_95 = local_58[7];
  if ((DES_key_schedule *)length != (DES_key_schedule *)0x0) {
    iVar4 = 0;
    pDVar15 = (DES_key_schedule *)length;
    do {
      if (uVar6 == 0) {
        (*(code *)PTR_DES_encrypt1_006a95e8)(&uStack_a4,uVar9,1);
        iVar4 = iVar4 + 1;
        length = uStack_a4 >> 0x10;
        abStack_9c[0] = (byte)uStack_a4;
        puVar8 = (uint *)(uStack_a0 >> 8);
        bStack_98 = (byte)uStack_a0;
        abStack_9c[1] = (byte)(uStack_a4 >> 8);
        abStack_9c[2] = (byte)(uStack_a4 >> 0x10);
        bStack_97 = (byte)(uStack_a0 >> 8);
        abStack_9c[3] = (byte)(uStack_a4 >> 0x18);
        bStack_96 = (byte)(uStack_a0 >> 0x10);
        bStack_95 = (byte)(uStack_a0 >> 0x18);
      }
      bVar2 = *(byte *)puVar16;
      pDVar15 = (DES_key_schedule *)((int)pDVar15[-1].ks + 0x7f);
      pbVar18 = abStack_9c + uVar6;
      puVar16 = (uint *)((int)puVar16 + 1);
      uVar6 = uVar6 + 1 & 7;
      *pbVar7 = bVar2 ^ *pbVar18;
      pbVar7 = pbVar7 + 1;
    } while (pDVar15 != (DES_key_schedule *)0x0);
    if (iVar4 != 0) {
      length = uStack_a4 >> 0x10;
      *pbVar17 = (byte)uStack_a4;
      puVar8 = (uint *)(uStack_a0 >> 8);
      pbVar17[4] = (byte)uStack_a0;
      pbVar17[1] = (byte)(uStack_a4 >> 8);
      pbVar17[2] = (byte)(uStack_a4 >> 0x10);
      pbVar17[5] = (byte)(uStack_a0 >> 8);
      pbVar17[3] = (byte)(uStack_a4 >> 0x18);
      pbVar17[6] = (byte)(uStack_a0 >> 0x10);
      pbVar17[7] = (byte)(uStack_a0 >> 0x18);
    }
  }
  iVar4 = *(int *)puVar3;
  *puStack_54 = uVar6;
  if (iStack_94 != iVar4) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar4 = 0x19;
    uVar10 = 0;
    uVar9 = 0;
    uVar6 = 0;
    do {
      uVar11 = length & (uVar9 ^ uVar10);
      uVar9 = uVar5 & (uVar9 ^ uVar10);
      uVar12 = uVar10 ^ *puVar8 ^ uVar11;
      uVar13 = uVar11 << 0x10 ^ uVar12;
      uVar11 = uVar10 ^ puVar8[1] ^ uVar9;
      uVar9 = (uVar9 << 0x10 ^ uVar11) >> 4;
      uVar11 = uVar9 + uVar11 * 0x10000000;
      uVar6 = *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc) + 0x100) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 * 0x100 >> 0x1a) + 0x140) * 4) ^ uVar6;
      uVar9 = uVar6 >> 0x10 ^ uVar6;
      uVar11 = length & uVar9;
      uVar9 = uVar5 & uVar9;
      uVar12 = uVar6 ^ puVar8[2] ^ uVar11;
      uVar13 = uVar11 << 0x10 ^ uVar12;
      uVar11 = uVar6 ^ puVar8[3] ^ uVar9;
      uVar9 = (uVar9 << 0x10 ^ uVar11) >> 4;
      uVar11 = uVar9 + uVar11 * 0x10000000;
      uVar12 = uVar10 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar9 = uVar12 >> 0x10 ^ uVar12;
      uVar10 = length & uVar9;
      uVar9 = uVar5 & uVar9;
      uVar11 = uVar12 ^ puVar8[4] ^ uVar10;
      uVar13 = uVar10 << 0x10 ^ uVar11;
      uVar10 = uVar12 ^ puVar8[5] ^ uVar9;
      uVar9 = (uVar9 << 0x10 ^ uVar10) >> 4;
      uVar10 = uVar9 + uVar10 * 0x10000000;
      uVar11 = uVar6 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar10 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar10 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar11 >> 0x10 ^ uVar11;
      uVar9 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar10 = uVar11 ^ puVar8[6] ^ uVar9;
      uVar13 = uVar9 << 0x10 ^ uVar10;
      uVar9 = uVar11 ^ puVar8[7] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar9) >> 4;
      uVar9 = uVar6 + uVar9 * 0x10000000;
      uVar10 = uVar12 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar10 >> 0x10 ^ uVar10;
      uVar9 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar10 ^ puVar8[8] ^ uVar9;
      uVar13 = uVar9 << 0x10 ^ uVar12;
      uVar9 = uVar10 ^ puVar8[9] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar9) >> 4;
      uVar9 = uVar6 + uVar9 * 0x10000000;
      uVar9 = uVar11 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      iVar4 = iVar4 + -1;
      uVar6 = uVar9 >> 0x10 ^ uVar9;
      uVar11 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar9 ^ puVar8[10] ^ uVar11;
      uVar13 = uVar11 << 0x10 ^ uVar12;
      uVar11 = uVar9 ^ puVar8[0xb] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar11) >> 4;
      uVar11 = uVar6 + uVar11 * 0x10000000;
      uVar11 = uVar10 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar11 >> 0x10 ^ uVar11;
      uVar10 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar11 ^ puVar8[0xc] ^ uVar10;
      uVar13 = uVar10 << 0x10 ^ uVar12;
      uVar10 = uVar11 ^ puVar8[0xd] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar10) >> 4;
      uVar10 = uVar6 + uVar10 * 0x10000000;
      uVar10 = uVar9 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar10 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar10 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar10 >> 0x10 ^ uVar10;
      uVar9 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar10 ^ puVar8[0xe] ^ uVar9;
      uVar13 = uVar9 << 0x10 ^ uVar12;
      uVar9 = uVar10 ^ puVar8[0xf] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar9) >> 4;
      uVar9 = uVar6 + uVar9 * 0x10000000;
      uVar9 = uVar11 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar9 >> 0x10 ^ uVar9;
      uVar11 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar9 ^ puVar8[0x10] ^ uVar11;
      uVar13 = uVar11 << 0x10 ^ uVar12;
      uVar11 = uVar9 ^ puVar8[0x11] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar11) >> 4;
      uVar11 = uVar6 + uVar11 * 0x10000000;
      uVar11 = uVar10 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar11 >> 0x10 ^ uVar11;
      uVar10 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar11 ^ puVar8[0x12] ^ uVar10;
      uVar13 = uVar10 << 0x10 ^ uVar12;
      uVar10 = uVar11 ^ puVar8[0x13] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar10) >> 4;
      uVar10 = uVar6 + uVar10 * 0x10000000;
      uVar10 = uVar9 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar10 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar10 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar10 >> 0x10 ^ uVar10;
      uVar9 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar10 ^ puVar8[0x14] ^ uVar9;
      uVar13 = uVar9 << 0x10 ^ uVar12;
      uVar9 = uVar10 ^ puVar8[0x15] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar9) >> 4;
      uVar9 = uVar6 + uVar9 * 0x10000000;
      uVar9 = uVar11 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar9 >> 0x10 ^ uVar9;
      uVar11 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar9 ^ puVar8[0x16] ^ uVar11;
      uVar13 = uVar11 << 0x10 ^ uVar12;
      uVar11 = uVar9 ^ puVar8[0x17] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar11) >> 4;
      uVar11 = uVar6 + uVar11 * 0x10000000;
      uVar11 = uVar10 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar11 >> 0x10 ^ uVar11;
      uVar10 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar11 ^ puVar8[0x18] ^ uVar10;
      uVar13 = uVar10 << 0x10 ^ uVar12;
      uVar10 = uVar11 ^ puVar8[0x19] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar10) >> 4;
      uVar10 = uVar6 + uVar10 * 0x10000000;
      uVar10 = uVar9 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar10 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar10 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar10 >> 0x10 ^ uVar10;
      uVar9 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar10 ^ puVar8[0x1a] ^ uVar9;
      uVar13 = uVar9 << 0x10 ^ uVar12;
      uVar9 = uVar10 ^ puVar8[0x1b] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar9) >> 4;
      uVar9 = uVar6 + uVar9 * 0x10000000;
      uVar11 = uVar11 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar6 = uVar11 >> 0x10 ^ uVar11;
      uVar9 = length & uVar6;
      uVar6 = uVar5 & uVar6;
      uVar12 = uVar11 ^ puVar8[0x1c] ^ uVar9;
      uVar13 = uVar9 << 0x10 ^ uVar12;
      uVar9 = uVar11 ^ puVar8[0x1d] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar9) >> 4;
      uVar9 = uVar6 + uVar9 * 0x10000000;
      uVar10 = uVar10 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar13 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar13 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar12 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar9 = uVar10 >> 0x10;
      uVar12 = length & (uVar9 ^ uVar10);
      uVar6 = uVar5 & (uVar9 ^ uVar10);
      uVar13 = uVar10 ^ puVar8[0x1e] ^ uVar12;
      uVar14 = uVar12 << 0x10 ^ uVar13;
      uVar12 = uVar10 ^ puVar8[0x1f] ^ uVar6;
      uVar6 = (uVar6 << 0x10 ^ uVar12) >> 4;
      uVar12 = uVar6 + uVar12 * 0x10000000;
      uVar6 = uVar11 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar14 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar14 & 0xfc)) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar13 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar14 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar12 & 0xfc) + 0x100) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
    } while (iVar4 != 0);
    uVar6 = (uVar6 >> 3) + uVar6 * 0x20000000;
    uVar9 = (uVar10 >> 3) + uVar10 * 0x20000000;
    uVar5 = (uVar6 >> 1 ^ uVar9) & 0x55555555;
    uVar9 = uVar9 ^ uVar5;
    uVar6 = uVar5 << 1 ^ uVar6;
    uVar5 = (uVar9 >> 8 ^ uVar6) & 0xff00ff;
    uVar6 = uVar6 ^ uVar5;
    uVar9 = uVar5 << 8 ^ uVar9;
    uVar5 = (uVar6 >> 2 ^ uVar9) & 0x33333333;
    uVar9 = uVar9 ^ uVar5;
    uVar6 = uVar5 << 2 ^ uVar6;
    uVar5 = (uVar9 >> 0x10 ^ uVar6) & 0xffff;
    uVar6 = uVar6 ^ uVar5;
    uVar9 = uVar5 << 0x10 ^ uVar9;
    uVar5 = (uVar6 >> 4 ^ uVar9) & 0xf0f0f0f;
    *puStack_54 = uVar9 ^ uVar5;
    puStack_54[1] = uVar5 << 4 ^ uVar6;
    return;
  }
  return;
}

