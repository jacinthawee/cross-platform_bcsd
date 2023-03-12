
void DES_set_key_unchecked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  _union_771 *p_Var1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  piVar2 = DAT_00076010;
  uVar7 = (uint)(*key)[6] << 0x10 | (uint)(*key)[5] << 8 | (uint)(*key)[4] | (uint)(*key)[7] << 0x18
  ;
  uVar6 = (uint)(*key)[2] << 0x10 | (uint)(*key)[1] << 8 | (uint)(*key)[0] | (uint)(*key)[3] << 0x18
  ;
  uVar5 = (uVar6 ^ uVar7 >> 4) & 0xf0f0f0f;
  uVar6 = uVar6 ^ uVar5;
  uVar7 = uVar7 ^ uVar5 << 4;
  uVar5 = (uVar6 ^ uVar6 << 0x12) & 0xcccc0000;
  uVar3 = (uVar7 ^ uVar7 << 0x12) & 0xcccc0000;
  uVar5 = uVar6 ^ uVar5 ^ uVar5 >> 0x12;
  uVar3 = uVar7 ^ uVar3 ^ uVar3 >> 0x12;
  uVar7 = (uVar5 ^ uVar3 >> 1) & 0x55555555;
  uVar5 = uVar5 ^ uVar7;
  uVar3 = uVar3 ^ uVar7 << 1;
  uVar7 = (uVar3 ^ uVar5 >> 8) & 0xff00ff;
  uVar3 = uVar3 ^ uVar7;
  uVar5 = uVar5 ^ uVar7 << 8;
  uVar7 = (uVar5 ^ uVar3 >> 1) & 0x55555555;
  uVar5 = uVar5 ^ uVar7;
  uVar3 = uVar3 ^ uVar7 << 1;
  uVar7 = uVar5 & 0xfffffff;
  uVar5 = uVar3 & 0xff00 | (uVar5 & 0xf0000000) >> 4 | (uVar3 & 0xff) << 0x10 | (uVar3 << 8) >> 0x18
  ;
  piVar4 = DAT_00076010;
  p_Var1 = schedule->ks;
  do {
    piVar4 = piVar4 + 1;
    uVar3 = uVar5 << 0x1a | uVar5 >> 2;
    if (*piVar4 == 0) {
      uVar3 = uVar5 << 0x1b | uVar5 >> 1;
    }
    uVar5 = uVar3 & 0xfffffff;
    uVar6 = uVar7 << 0x1a | uVar7 >> 2;
    if (*piVar4 == 0) {
      uVar6 = uVar7 << 0x1b | uVar7 >> 1;
    }
    uVar7 = uVar6 & 0xfffffff;
    uVar6 = piVar2[(uVar7 >> 7 & 0x3c | (uVar7 << 0x18) >> 0x1e) + 0x51] |
            piVar2[(uVar7 >> 0xe & 0x30 | (uVar7 << 0xf) >> 0x1c) + 0x91] |
            piVar2[(uVar6 & 0x3f) + 0x11] |
            piVar2[(uVar7 >> 0x15 & 6 | (uVar7 << 0xb) >> 0x1f | uVar7 >> 0x16 & 0x38) + 0xd1];
    uVar3 = piVar2[((uVar5 << 0xb) >> 0x1a) + 0x191] | piVar2[(uVar3 & 0x3f) + 0x111] |
            piVar2[(uVar5 >> 8 & 0x3c | (uVar5 << 0x17) >> 0x1e) + 0x151] |
            piVar2[(uVar5 >> 0x16 & 0x30 | (uVar5 << 7) >> 0x1c) + 0x1d1];
    ((DES_key_schedule *)(p_Var1 + 1 + -1))->ks[0].deslong[0] =
         (uVar3 << 0x10) >> 0x1e | (uVar6 & 0xffff | uVar3 << 0x10) << 2;
    bVar8 = piVar4 != DAT_00076014;
    *(uint *)((int)p_Var1 + 4) = uVar3 >> 0x1a | (uVar3 & 0xffff0000 | uVar6 >> 0x10) << 6;
    p_Var1 = p_Var1 + 1;
  } while (bVar8);
  return;
}

