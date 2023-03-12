
void SEED_set_key(uchar *rawkey,SEED_KEY_SCHEDULE *ks)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar6 = *(uint *)rawkey;
  uVar5 = *(uint *)(rawkey + 8);
  uVar4 = *(uint *)(rawkey + 4);
  uVar9 = *(uint *)(rawkey + 0xc);
  uVar7 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8;
  uVar10 = uVar7 | uVar5 << 0x18;
  uVar12 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  uVar1 = uVar12 + 0x61c88647 + uVar10;
  uVar11 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
  uVar8 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8;
  uVar2 = uVar8 | uVar9 << 0x18;
  uVar3 = (uVar11 + 0x9e3779b9) - uVar2;
  ks->data[0] = *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  uVar12 = uVar12 >> 8;
  ks->data[1] = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar11 = uVar11 >> 8;
  uVar13 = uVar6 & 0xff000000 ^ uVar11;
  uVar4 = uVar12 ^ uVar4 & 0xff000000;
  uVar1 = uVar10 + 0xc3910c8d + uVar4;
  uVar6 = (uVar13 - uVar2) + 0x3c6ef373;
  ks->data[2] = *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[3] = *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 << 8;
  uVar14 = uVar9 & 0xff ^ uVar7;
  uVar8 = uVar8 << 8;
  uVar2 = uVar5 & 0xff ^ uVar8;
  uVar1 = uVar4 + 0x8722191a + uVar14;
  uVar6 = (uVar13 + 0x78dde6e6) - uVar2;
  ks->data[4] = *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[5] = *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar3 = uVar13 >> 8 ^ uVar12 << 0x18;
  uVar10 = uVar11 << 0x18 ^ uVar4 >> 8;
  uVar1 = uVar14 + 0xe443234 + uVar10;
  uVar5 = (uVar3 - uVar2) + 0xf1bbcdcc;
  uVar6 = *(uint *)(SS + (uVar5 & 0xff) * 4);
  ks->data[6] = *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[7] = uVar6 ^ *(uint *)(SS + (uVar5 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar5 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar5 >> 0x10 & 0xff) * 4 + 0x800);
  uVar11 = uVar7 >> 0x18 ^ uVar2 << 8;
  uVar9 = uVar8 >> 0x18 ^ uVar14 << 8;
  uVar1 = uVar10 + 0x1c886467 + uVar9;
  uVar6 = (uVar3 + 0xe3779b99) - uVar11;
  ks->data[8] = *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[9] = *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
                *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
                *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = (uVar13 >> 8) << 0x18 ^ uVar10 >> 8;
  uVar1 = uVar9 + 0x3910c8cd + uVar7;
  uVar12 = uVar3 >> 8 ^ (uVar4 >> 8) << 0x18;
  uVar6 = (uVar12 - uVar11) + 0xc6ef3733;
  ks->data[10] = *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
                 *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
                 *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0xb] =
       *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar8 = (uVar2 << 8) >> 0x18 ^ uVar9 << 8;
  uVar4 = (uVar14 << 8) >> 0x18 ^ uVar11 << 8;
  uVar1 = uVar7 + 0x72219199 + uVar8;
  uVar6 = (uVar12 + 0x8dde6e67) - uVar4;
  ks->data[0xc] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0xd] =
       *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar10 = uVar12 >> 8 ^ (uVar10 >> 8) << 0x18;
  uVar13 = (uVar3 >> 8) << 0x18 ^ uVar7 >> 8;
  uVar1 = uVar8 + 0xe4432331 + uVar13;
  uVar5 = (uVar10 - uVar4) + 0x1bbcdccf;
  uVar6 = *(uint *)(SS + (uVar5 & 0xff) * 4);
  ks->data[0xe] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0xf] =
       uVar6 ^ *(uint *)(SS + (uVar5 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar5 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar5 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = (uVar9 << 8) >> 0x18 ^ uVar4 << 8;
  uVar9 = (uVar11 << 8) >> 0x18 ^ uVar8 << 8;
  uVar1 = uVar13 + 0xc8864662 + uVar9;
  uVar6 = (uVar10 + 0x3779b99e) - uVar2;
  ks->data[0x10] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0x11] =
       *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar10 >> 8 ^ (uVar7 >> 8) << 0x18;
  uVar3 = (uVar12 >> 8) << 0x18 ^ uVar13 >> 8;
  uVar1 = uVar9 + 0x910c8cc4 + uVar3;
  uVar6 = (uVar7 - uVar2) + 0x6ef3733c;
  ks->data[0x12] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0x13] =
       *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar12 = (uVar8 << 8) >> 0x18 ^ uVar2 << 8;
  uVar4 = (uVar4 << 8) >> 0x18 ^ uVar9 << 8;
  uVar1 = uVar3 + 0x22191988 + uVar4;
  uVar5 = (uVar7 + 0xdde6e678) - uVar12;
  uVar6 = *(uint *)(SS + (uVar5 & 0xff) * 4);
  ks->data[0x14] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0x15] =
       uVar6 ^ *(uint *)(SS + (uVar5 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar5 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar5 >> 0x10 & 0xff) * 4 + 0x800);
  uVar10 = (uVar10 >> 8) << 0x18 ^ uVar3 >> 8;
  uVar11 = (uVar13 >> 8) << 0x18 ^ uVar7 >> 8;
  uVar1 = uVar4 + 0x4432330f + uVar10;
  uVar6 = (uVar11 - uVar12) + 0xbbcdccf1;
  ks->data[0x16] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0x17] =
       *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar9 = (uVar9 << 8) >> 0x18 ^ uVar12 << 8;
  uVar8 = (uVar2 << 8) >> 0x18 ^ uVar4 << 8;
  uVar1 = uVar10 + 0x8864661d + uVar8;
  uVar5 = (uVar11 + 0x779b99e3) - uVar9;
  uVar6 = *(uint *)(SS + (uVar5 & 0xff) * 4);
  ks->data[0x18] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0x19] =
       uVar6 ^ *(uint *)(SS + (uVar5 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar5 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar5 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = (uVar7 >> 8) << 0x18 ^ uVar10 >> 8;
  uVar1 = uVar8 + 0x10c8cc3a + uVar7;
  uVar2 = (uVar3 >> 8) << 0x18 ^ uVar11 >> 8;
  uVar5 = (uVar2 - uVar9) + 0xef3733c6;
  uVar6 = *(uint *)(SS + (uVar5 & 0xff) * 4);
  ks->data[0x1a] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0x1b] =
       uVar6 ^ *(uint *)(SS + (uVar5 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar5 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar5 >> 0x10 & 0xff) * 4 + 0x800);
  uVar8 = uVar8 << 8 ^ (uVar12 << 8) >> 0x18;
  uVar5 = (uVar4 << 8) >> 0x18 ^ uVar9 << 8;
  uVar1 = uVar7 + 0x21919873 + uVar8;
  uVar6 = (uVar2 + 0xde6e678d) - uVar5;
  ks->data[0x1c] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0x1d] =
       *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar6 = uVar8 + 0x432330e5 + ((uVar11 >> 8) << 0x18 ^ uVar7 >> 8);
  uVar1 = (((uVar10 >> 8) << 0x18 ^ uVar2 >> 8) - uVar5) + 0xbcdccf1b;
  ks->data[0x1e] =
       *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  ks->data[0x1f] =
       *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + (uVar1 >> 0x18) * 4 + 0xc00) ^
       *(uint *)(SS + (uVar1 >> 8 & 0xff) * 4 + 0x400) ^
       *(uint *)(SS + (uVar1 >> 0x10 & 0xff) * 4 + 0x800);
  return;
}

