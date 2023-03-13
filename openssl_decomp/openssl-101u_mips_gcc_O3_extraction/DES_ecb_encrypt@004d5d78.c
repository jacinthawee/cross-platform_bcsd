
void DES_ecb_encrypt(const_DES_cblock *input,DES_cblock *output,DES_key_schedule *ks,int enc)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_1c;
  uint local_18;
  uint *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  local_18 = (uint)(*input)[7] << 0x18 |
             (uint)(*input)[5] << 8 | (uint)(*input)[6] << 0x10 | (uint)(*input)[4];
  local_1c = (uint)(*input)[3] << 0x18 |
             (uint)(*input)[1] << 8 | (uint)(*input)[2] << 0x10 | (uint)(*input)[0];
  DES_encrypt1(&local_1c,ks,enc);
  (*output)[0] = (uchar)local_1c;
  (*output)[4] = (uchar)local_18;
  (*output)[1] = (uchar)(local_1c >> 8);
  (*output)[2] = (uchar)(local_1c >> 0x10);
  puVar4 = (uint *)(local_18 >> 0x10);
  (*output)[3] = (uchar)(local_1c >> 0x18);
  (*output)[5] = (uchar)(local_18 >> 8);
  (*output)[6] = (uchar)(local_18 >> 0x10);
  (*output)[7] = (uchar)(local_18 >> 0x18);
  if (local_14 == *(uint **)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar7 = (*local_14 >> 0x1d) + *local_14 * 8;
  uVar2 = uVar7 ^ *puVar4;
  uVar3 = (uVar7 ^ puVar4[1]) >> 4;
  uVar6 = uVar3 + (uVar7 ^ puVar4[1]) * 0x10000000;
  uVar2 = (local_14[1] >> 0x1d) + local_14[1] * 8 ^
          *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar6 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar6 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar6 = uVar2 ^ puVar4[2];
  uVar3 = (uVar2 ^ puVar4[3]) >> 4;
  uVar5 = uVar3 + (uVar2 ^ puVar4[3]) * 0x10000000;
  uVar6 = uVar7 ^ *(uint *)(DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar6 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar7 = uVar6 ^ puVar4[4];
  uVar3 = (uVar6 ^ puVar4[5]) >> 4;
  uVar5 = uVar3 + (uVar6 ^ puVar4[5]) * 0x10000000;
  uVar7 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar7 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar7 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar5 = uVar7 ^ puVar4[6];
  uVar3 = (uVar7 ^ puVar4[7]) >> 4;
  uVar2 = uVar3 + (uVar7 ^ puVar4[7]) * 0x10000000;
  uVar6 = uVar6 ^ *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar2 = uVar6 ^ puVar4[8];
  uVar3 = (uVar6 ^ puVar4[9]) >> 4;
  uVar5 = uVar3 + (uVar6 ^ puVar4[9]) * 0x10000000;
  uVar2 = uVar7 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar7 = uVar2 ^ puVar4[10];
  uVar3 = (uVar2 ^ puVar4[0xb]) >> 4;
  uVar5 = uVar3 + (uVar2 ^ puVar4[0xb]) * 0x10000000;
  uVar7 = uVar6 ^ *(uint *)(DES_SPtrans + ((uVar7 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar7 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar5 = uVar7 ^ puVar4[0xc];
  uVar3 = (uVar7 ^ puVar4[0xd]) >> 4;
  uVar6 = uVar3 + (uVar7 ^ puVar4[0xd]) * 0x10000000;
  uVar6 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar6 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar6 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar2 = uVar6 ^ puVar4[0xe];
  uVar3 = (uVar6 ^ puVar4[0xf]) >> 4;
  uVar5 = uVar3 + (uVar6 ^ puVar4[0xf]) * 0x10000000;
  uVar2 = uVar7 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar7 = uVar2 ^ puVar4[0x10];
  uVar3 = (uVar2 ^ puVar4[0x11]) >> 4;
  uVar5 = uVar3 + (uVar2 ^ puVar4[0x11]) * 0x10000000;
  uVar5 = uVar6 ^ *(uint *)(DES_SPtrans + ((uVar7 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar7 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar7 = uVar5 ^ puVar4[0x12];
  uVar3 = (uVar5 ^ puVar4[0x13]) >> 4;
  uVar6 = uVar3 + (uVar5 ^ puVar4[0x13]) * 0x10000000;
  uVar6 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar7 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar7 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar6 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar6 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar2 = uVar6 ^ puVar4[0x14];
  uVar3 = (uVar6 ^ puVar4[0x15]) >> 4;
  uVar7 = uVar3 + (uVar6 ^ puVar4[0x15]) * 0x10000000;
  uVar2 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar7 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar7 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar7 = uVar2 ^ puVar4[0x16];
  uVar3 = (uVar2 ^ puVar4[0x17]) >> 4;
  uVar5 = uVar3 + (uVar2 ^ puVar4[0x17]) * 0x10000000;
  uVar7 = uVar6 ^ *(uint *)(DES_SPtrans + ((uVar7 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar7 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar5 = uVar7 ^ puVar4[0x18];
  uVar3 = (uVar7 ^ puVar4[0x19]) >> 4;
  uVar6 = uVar3 + (uVar7 ^ puVar4[0x19]) * 0x10000000;
  uVar6 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar6 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar6 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar2 = uVar6 ^ puVar4[0x1a];
  uVar3 = (uVar6 ^ puVar4[0x1b]) >> 4;
  uVar5 = uVar3 + (uVar6 ^ puVar4[0x1b]) * 0x10000000;
  uVar7 = uVar7 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar2 = uVar7 ^ puVar4[0x1c];
  uVar3 = (uVar7 ^ puVar4[0x1d]) >> 4;
  uVar5 = uVar3 + (uVar7 ^ puVar4[0x1d]) * 0x10000000;
  uVar2 = uVar6 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  uVar5 = uVar2 ^ puVar4[0x1e];
  uVar3 = (uVar2 ^ puVar4[0x1f]) >> 4;
  uVar6 = uVar3 + (uVar2 ^ puVar4[0x1f]) * 0x10000000;
  uVar3 = uVar7 ^ *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar6 >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(DES_SPtrans + (uVar6 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(DES_SPtrans + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  *local_14 = (uVar2 >> 3) + uVar2 * 0x20000000;
  local_14[1] = (uVar3 >> 3) + uVar3 * 0x20000000;
  return;
}

