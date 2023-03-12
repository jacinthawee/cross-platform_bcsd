
void DES_ofb64_encrypt(uchar *in,uchar *out,long length,DES_key_schedule *schedule,DES_cblock *ivec,
                      int *num)

{
  byte *pbVar1;
  byte bVar2;
  undefined *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  long lVar13;
  int iVar14;
  uint local_3c;
  uint local_38;
  byte local_34 [4];
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  uVar4 = (uint)(*ivec)[3];
  uVar12 = *num;
  local_3c = uVar4 << 0x18 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0];
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_38 = (uint)(*ivec)[7] << 0x18 |
             (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4];
  local_34[0] = (*ivec)[0];
  local_34[2] = (*ivec)[2];
  puVar5 = (uint *)(local_38 >> 8);
  local_34[1] = (*ivec)[1];
  local_34[3] = (*ivec)[3];
  local_30 = (*ivec)[4];
  local_2f = (*ivec)[5];
  local_2e = (*ivec)[6];
  local_2d = (*ivec)[7];
  if (length != 0) {
    iVar14 = 0;
    lVar13 = length;
    do {
      if (uVar12 == 0) {
        (*(code *)PTR_DES_encrypt1_006a95e8)(&local_3c,schedule,1);
        iVar14 = iVar14 + 1;
        length = local_3c >> 0x10;
        local_34[0] = (byte)local_3c;
        puVar5 = (uint *)(local_38 >> 8);
        local_30 = (byte)local_38;
        local_34[1] = (byte)(local_3c >> 8);
        local_34[2] = (byte)(local_3c >> 0x10);
        local_2f = (byte)(local_38 >> 8);
        local_34[3] = (byte)(local_3c >> 0x18);
        local_2e = (byte)(local_38 >> 0x10);
        local_2d = (byte)(local_38 >> 0x18);
      }
      bVar2 = *in;
      lVar13 = lVar13 + -1;
      pbVar1 = local_34 + uVar12;
      in = in + 1;
      uVar12 = uVar12 + 1 & 7;
      *out = bVar2 ^ *pbVar1;
      out = out + 1;
    } while (lVar13 != 0);
    if (iVar14 != 0) {
      length = local_3c >> 0x10;
      (*ivec)[0] = (uchar)local_3c;
      puVar5 = (uint *)(local_38 >> 8);
      (*ivec)[4] = (uchar)local_38;
      (*ivec)[1] = (uchar)(local_3c >> 8);
      (*ivec)[2] = (uchar)(local_3c >> 0x10);
      (*ivec)[5] = (uchar)(local_38 >> 8);
      (*ivec)[3] = (uchar)(local_3c >> 0x18);
      (*ivec)[6] = (uchar)(local_38 >> 0x10);
      (*ivec)[7] = (uchar)(local_38 >> 0x18);
    }
  }
  iVar14 = *(int *)puVar3;
  *num = uVar12;
  if (local_2c == iVar14) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar14 = 0x19;
  uVar8 = 0;
  uVar7 = 0;
  uVar12 = 0;
  do {
    uVar9 = length & (uVar7 ^ uVar8);
    uVar7 = uVar4 & (uVar7 ^ uVar8);
    uVar10 = uVar8 ^ *puVar5 ^ uVar9;
    uVar11 = uVar9 << 0x10 ^ uVar10;
    uVar9 = uVar8 ^ puVar5[1] ^ uVar7;
    uVar7 = (uVar7 << 0x10 ^ uVar9) >> 4;
    uVar9 = uVar7 + uVar9 * 0x10000000;
    uVar12 = *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4) ^ uVar12;
    uVar7 = uVar12 >> 0x10 ^ uVar12;
    uVar9 = length & uVar7;
    uVar7 = uVar4 & uVar7;
    uVar10 = uVar12 ^ puVar5[2] ^ uVar9;
    uVar11 = uVar9 << 0x10 ^ uVar10;
    uVar9 = uVar12 ^ puVar5[3] ^ uVar7;
    uVar7 = (uVar7 << 0x10 ^ uVar9) >> 4;
    uVar9 = uVar7 + uVar9 * 0x10000000;
    uVar10 = uVar8 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar7 = uVar10 >> 0x10 ^ uVar10;
    uVar8 = length & uVar7;
    uVar7 = uVar4 & uVar7;
    uVar9 = uVar10 ^ puVar5[4] ^ uVar8;
    uVar11 = uVar8 << 0x10 ^ uVar9;
    uVar8 = uVar10 ^ puVar5[5] ^ uVar7;
    uVar7 = (uVar7 << 0x10 ^ uVar8) >> 4;
    uVar8 = uVar7 + uVar8 * 0x10000000;
    uVar9 = uVar12 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar9 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar8 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar9 >> 0x10 ^ uVar9;
    uVar7 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar8 = uVar9 ^ puVar5[6] ^ uVar7;
    uVar11 = uVar7 << 0x10 ^ uVar8;
    uVar7 = uVar9 ^ puVar5[7] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar7) >> 4;
    uVar7 = uVar12 + uVar7 * 0x10000000;
    uVar8 = uVar10 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar8 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar8 >> 0x10 ^ uVar8;
    uVar7 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar8 ^ puVar5[8] ^ uVar7;
    uVar11 = uVar7 << 0x10 ^ uVar10;
    uVar7 = uVar8 ^ puVar5[9] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar7) >> 4;
    uVar7 = uVar12 + uVar7 * 0x10000000;
    uVar7 = uVar9 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    iVar14 = iVar14 + -1;
    uVar12 = uVar7 >> 0x10 ^ uVar7;
    uVar9 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar7 ^ puVar5[10] ^ uVar9;
    uVar11 = uVar9 << 0x10 ^ uVar10;
    uVar9 = uVar7 ^ puVar5[0xb] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar9) >> 4;
    uVar9 = uVar12 + uVar9 * 0x10000000;
    uVar9 = uVar8 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar9 >> 0x10 ^ uVar9;
    uVar8 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar9 ^ puVar5[0xc] ^ uVar8;
    uVar11 = uVar8 << 0x10 ^ uVar10;
    uVar8 = uVar9 ^ puVar5[0xd] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar8) >> 4;
    uVar8 = uVar12 + uVar8 * 0x10000000;
    uVar8 = uVar7 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar8 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar8 >> 0x10 ^ uVar8;
    uVar7 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar8 ^ puVar5[0xe] ^ uVar7;
    uVar11 = uVar7 << 0x10 ^ uVar10;
    uVar7 = uVar8 ^ puVar5[0xf] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar7) >> 4;
    uVar7 = uVar12 + uVar7 * 0x10000000;
    uVar7 = uVar9 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar7 >> 0x10 ^ uVar7;
    uVar9 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar7 ^ puVar5[0x10] ^ uVar9;
    uVar11 = uVar9 << 0x10 ^ uVar10;
    uVar9 = uVar7 ^ puVar5[0x11] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar9) >> 4;
    uVar9 = uVar12 + uVar9 * 0x10000000;
    uVar9 = uVar8 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar9 >> 0x10 ^ uVar9;
    uVar8 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar9 ^ puVar5[0x12] ^ uVar8;
    uVar11 = uVar8 << 0x10 ^ uVar10;
    uVar8 = uVar9 ^ puVar5[0x13] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar8) >> 4;
    uVar8 = uVar12 + uVar8 * 0x10000000;
    uVar8 = uVar7 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar8 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar8 >> 0x10 ^ uVar8;
    uVar7 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar8 ^ puVar5[0x14] ^ uVar7;
    uVar11 = uVar7 << 0x10 ^ uVar10;
    uVar7 = uVar8 ^ puVar5[0x15] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar7) >> 4;
    uVar7 = uVar12 + uVar7 * 0x10000000;
    uVar7 = uVar9 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar7 >> 0x10 ^ uVar7;
    uVar9 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar7 ^ puVar5[0x16] ^ uVar9;
    uVar11 = uVar9 << 0x10 ^ uVar10;
    uVar9 = uVar7 ^ puVar5[0x17] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar9) >> 4;
    uVar9 = uVar12 + uVar9 * 0x10000000;
    uVar9 = uVar8 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar9 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar9 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar9 >> 0x10 ^ uVar9;
    uVar8 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar9 ^ puVar5[0x18] ^ uVar8;
    uVar11 = uVar8 << 0x10 ^ uVar10;
    uVar8 = uVar9 ^ puVar5[0x19] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar8) >> 4;
    uVar8 = uVar12 + uVar8 * 0x10000000;
    uVar8 = uVar7 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar8 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar8 >> 0x10 ^ uVar8;
    uVar7 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar8 ^ puVar5[0x1a] ^ uVar7;
    uVar11 = uVar7 << 0x10 ^ uVar10;
    uVar7 = uVar8 ^ puVar5[0x1b] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar7) >> 4;
    uVar7 = uVar12 + uVar7 * 0x10000000;
    uVar9 = uVar9 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar12 = uVar9 >> 0x10 ^ uVar9;
    uVar7 = length & uVar12;
    uVar12 = uVar4 & uVar12;
    uVar10 = uVar9 ^ puVar5[0x1c] ^ uVar7;
    uVar11 = uVar7 << 0x10 ^ uVar10;
    uVar7 = uVar9 ^ puVar5[0x1d] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar7) >> 4;
    uVar7 = uVar12 + uVar7 * 0x10000000;
    uVar8 = uVar8 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar11 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar11 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar10 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar7 = uVar8 >> 0x10;
    uVar10 = length & (uVar7 ^ uVar8);
    uVar12 = uVar4 & (uVar7 ^ uVar8);
    uVar11 = uVar8 ^ puVar5[0x1e] ^ uVar10;
    uVar6 = uVar10 << 0x10 ^ uVar11;
    uVar10 = uVar8 ^ puVar5[0x1f] ^ uVar12;
    uVar12 = (uVar12 << 0x10 ^ uVar10) >> 4;
    uVar10 = uVar12 + uVar10 * 0x10000000;
    uVar12 = uVar9 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 >> 0x1a) + 0x180) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar6 & 0xfc)) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar11 << 0x10) >> 0x1a) + 0x80) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar10 >> 0x1a) + 0x1c0) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar10 & 0xfc) + 0x100) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
             *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar12 * 0x100 >> 0x1a) + 0x140) * 4);
  } while (iVar14 != 0);
  uVar12 = (uVar12 >> 3) + uVar12 * 0x20000000;
  uVar7 = (uVar8 >> 3) + uVar8 * 0x20000000;
  uVar4 = (uVar12 >> 1 ^ uVar7) & 0x55555555;
  uVar7 = uVar7 ^ uVar4;
  uVar12 = uVar4 << 1 ^ uVar12;
  uVar4 = (uVar7 >> 8 ^ uVar12) & 0xff00ff;
  uVar12 = uVar12 ^ uVar4;
  uVar7 = uVar4 << 8 ^ uVar7;
  uVar4 = (uVar12 >> 2 ^ uVar7) & 0x33333333;
  uVar7 = uVar7 ^ uVar4;
  uVar12 = uVar4 << 2 ^ uVar12;
  uVar4 = (uVar7 >> 0x10 ^ uVar12) & 0xffff;
  uVar12 = uVar12 ^ uVar4;
  uVar7 = uVar4 << 0x10 ^ uVar7;
  uVar4 = (uVar12 >> 4 ^ uVar7) & 0xf0f0f0f;
  *num = uVar7 ^ uVar4;
  ((uint *)num)[1] = uVar4 << 4 ^ uVar12;
  return;
}

