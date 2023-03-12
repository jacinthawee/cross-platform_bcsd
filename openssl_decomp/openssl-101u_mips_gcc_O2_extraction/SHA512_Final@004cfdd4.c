
int SHA512_Final(uchar *md,SHA512_CTX *c)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  _union_314 *p_Var7;
  
  p_Var7 = &c->u;
  uVar2 = c->num + 1;
  p_Var7->p[c->num] = 0x80;
  if (uVar2 < 0x71) {
    iVar4 = 0x70 - uVar2;
  }
  else {
    (*(code *)PTR_memset_006a99f4)((int)p_Var7 + uVar2,0,0x80 - uVar2);
    sha512_block_data_order(c,p_Var7,1);
    iVar4 = 0x70;
    uVar2 = 0;
  }
  (*(code *)PTR_memset_006a99f4)((int)p_Var7 + uVar2,0,iVar4);
  uVar1 = *(undefined4 *)&c->Nl;
  uVar3 = *(undefined4 *)((int)&c->Nl + 4);
  uVar5 = *(undefined4 *)&c->Nh;
  uVar6 = *(undefined4 *)((int)&c->Nh + 4);
  (c->u).p[0x7b] = (uchar)uVar1;
  (c->u).p[0x7f] = (uchar)uVar3;
  (c->u).p[0x7a] = (uchar)((uint)uVar1 >> 8);
  (c->u).p[0x7e] = (uchar)((uint)uVar3 >> 8);
  (c->u).p[0x7d] = (uchar)((uint)uVar3 >> 0x10);
  (c->u).p[0x7c] = (uchar)((uint)uVar3 >> 0x18);
  (c->u).p[0x79] = (uchar)((uint)uVar1 >> 0x10);
  (c->u).p[0x78] = (uchar)((uint)uVar1 >> 0x18);
  (c->u).p[0x77] = (uchar)uVar6;
  (c->u).p[0x76] = (uchar)((uint)uVar6 >> 8);
  (c->u).p[0x75] = (uchar)((uint)uVar6 >> 0x10);
  (c->u).p[0x74] = (uchar)((uint)uVar6 >> 0x18);
  (c->u).p[0x73] = (uchar)uVar5;
  (c->u).p[0x72] = (uchar)((uint)uVar5 >> 8);
  (c->u).p[0x71] = (uchar)((uint)uVar5 >> 0x10);
  (c->u).p[0x70] = (uchar)((uint)uVar5 >> 0x18);
  sha512_block_data_order(c,p_Var7,1);
  if (md == (uchar *)0x0) {
    return 0;
  }
  if (c->md_len == 0x30) {
    uVar3 = *(undefined4 *)c->h;
    uVar1 = *(undefined4 *)((int)c->h + 4);
    md[3] = (uchar)uVar3;
    md[7] = (uchar)uVar1;
    *md = (uchar)((uint)uVar3 >> 0x18);
    md[1] = (uchar)((uint)uVar3 >> 0x10);
    md[4] = (uchar)((uint)uVar1 >> 0x18);
    md[2] = (uchar)((uint)uVar3 >> 8);
    md[5] = (uchar)((uint)uVar1 >> 0x10);
    md[6] = (uchar)((uint)uVar1 >> 8);
    uVar3 = *(undefined4 *)(c->h + 1);
    uVar1 = *(undefined4 *)((int)c->h + 0xc);
    md[0xb] = (uchar)uVar3;
    md[0xf] = (uchar)uVar1;
    md[8] = (uchar)((uint)uVar3 >> 0x18);
    md[9] = (uchar)((uint)uVar3 >> 0x10);
    md[0xc] = (uchar)((uint)uVar1 >> 0x18);
    md[10] = (uchar)((uint)uVar3 >> 8);
    md[0xd] = (uchar)((uint)uVar1 >> 0x10);
    md[0xe] = (uchar)((uint)uVar1 >> 8);
    uVar3 = *(undefined4 *)(c->h + 2);
    uVar1 = *(undefined4 *)((int)c->h + 0x14);
    md[0x13] = (uchar)uVar3;
    md[0x17] = (uchar)uVar1;
    md[0x10] = (uchar)((uint)uVar3 >> 0x18);
    md[0x11] = (uchar)((uint)uVar3 >> 0x10);
    md[0x14] = (uchar)((uint)uVar1 >> 0x18);
    md[0x12] = (uchar)((uint)uVar3 >> 8);
    md[0x15] = (uchar)((uint)uVar1 >> 0x10);
    md[0x16] = (uchar)((uint)uVar1 >> 8);
    uVar3 = *(undefined4 *)(c->h + 3);
    uVar1 = *(undefined4 *)((int)c->h + 0x1c);
    md[0x18] = (uchar)((uint)uVar3 >> 0x18);
    md[0x19] = (uchar)((uint)uVar3 >> 0x10);
    md[0x1c] = (uchar)((uint)uVar1 >> 0x18);
    md[0x1a] = (uchar)((uint)uVar3 >> 8);
    md[0x1d] = (uchar)((uint)uVar1 >> 0x10);
    md[0x1e] = (uchar)((uint)uVar1 >> 8);
    md[0x1b] = (uchar)uVar3;
    md[0x1f] = (uchar)uVar1;
    uVar3 = *(undefined4 *)(c->h + 4);
    uVar1 = *(undefined4 *)((int)c->h + 0x24);
    md[0x23] = (uchar)uVar3;
    md[0x27] = (uchar)uVar1;
    md[0x20] = (uchar)((uint)uVar3 >> 0x18);
    md[0x21] = (uchar)((uint)uVar3 >> 0x10);
    md[0x24] = (uchar)((uint)uVar1 >> 0x18);
    md[0x22] = (uchar)((uint)uVar3 >> 8);
    md[0x25] = (uchar)((uint)uVar1 >> 0x10);
    md[0x26] = (uchar)((uint)uVar1 >> 8);
    uVar3 = *(undefined4 *)(c->h + 5);
    uVar1 = *(undefined4 *)((int)c->h + 0x2c);
    md[0x2b] = (uchar)uVar3;
    md[0x2f] = (uchar)uVar1;
    md[0x28] = (uchar)((uint)uVar3 >> 0x18);
    md[0x29] = (uchar)((uint)uVar3 >> 0x10);
    md[0x2c] = (uchar)((uint)uVar1 >> 0x18);
    md[0x2a] = (uchar)((uint)uVar3 >> 8);
    md[0x2d] = (uchar)((uint)uVar1 >> 0x10);
    md[0x2e] = (uchar)((uint)uVar1 >> 8);
  }
  else {
    if (c->md_len != 0x40) {
      return 0;
    }
    uVar3 = *(undefined4 *)c->h;
    uVar1 = *(undefined4 *)((int)c->h + 4);
    md[3] = (uchar)uVar3;
    md[7] = (uchar)uVar1;
    *md = (uchar)((uint)uVar3 >> 0x18);
    md[1] = (uchar)((uint)uVar3 >> 0x10);
    md[4] = (uchar)((uint)uVar1 >> 0x18);
    md[2] = (uchar)((uint)uVar3 >> 8);
    md[5] = (uchar)((uint)uVar1 >> 0x10);
    md[6] = (uchar)((uint)uVar1 >> 8);
    uVar3 = *(undefined4 *)(c->h + 1);
    uVar1 = *(undefined4 *)((int)c->h + 0xc);
    md[0xb] = (uchar)uVar3;
    md[0xf] = (uchar)uVar1;
    md[8] = (uchar)((uint)uVar3 >> 0x18);
    md[9] = (uchar)((uint)uVar3 >> 0x10);
    md[0xc] = (uchar)((uint)uVar1 >> 0x18);
    md[10] = (uchar)((uint)uVar3 >> 8);
    md[0xd] = (uchar)((uint)uVar1 >> 0x10);
    md[0xe] = (uchar)((uint)uVar1 >> 8);
    uVar3 = *(undefined4 *)(c->h + 2);
    uVar1 = *(undefined4 *)((int)c->h + 0x14);
    md[0x13] = (uchar)uVar3;
    md[0x17] = (uchar)uVar1;
    md[0x10] = (uchar)((uint)uVar3 >> 0x18);
    md[0x11] = (uchar)((uint)uVar3 >> 0x10);
    md[0x14] = (uchar)((uint)uVar1 >> 0x18);
    md[0x12] = (uchar)((uint)uVar3 >> 8);
    md[0x15] = (uchar)((uint)uVar1 >> 0x10);
    md[0x16] = (uchar)((uint)uVar1 >> 8);
    uVar3 = *(undefined4 *)(c->h + 3);
    uVar1 = *(undefined4 *)((int)c->h + 0x1c);
    md[0x18] = (uchar)((uint)uVar3 >> 0x18);
    md[0x19] = (uchar)((uint)uVar3 >> 0x10);
    md[0x1a] = (uchar)((uint)uVar3 >> 8);
    md[0x1c] = (uchar)((uint)uVar1 >> 0x18);
    md[0x1d] = (uchar)((uint)uVar1 >> 0x10);
    md[0x1e] = (uchar)((uint)uVar1 >> 8);
    md[0x1b] = (uchar)uVar3;
    md[0x1f] = (uchar)uVar1;
    uVar3 = *(undefined4 *)(c->h + 4);
    uVar1 = *(undefined4 *)((int)c->h + 0x24);
    md[0x23] = (uchar)uVar3;
    md[0x27] = (uchar)uVar1;
    md[0x20] = (uchar)((uint)uVar3 >> 0x18);
    md[0x21] = (uchar)((uint)uVar3 >> 0x10);
    md[0x24] = (uchar)((uint)uVar1 >> 0x18);
    md[0x22] = (uchar)((uint)uVar3 >> 8);
    md[0x25] = (uchar)((uint)uVar1 >> 0x10);
    md[0x26] = (uchar)((uint)uVar1 >> 8);
    uVar3 = *(undefined4 *)(c->h + 5);
    uVar1 = *(undefined4 *)((int)c->h + 0x2c);
    md[0x2b] = (uchar)uVar3;
    md[0x2f] = (uchar)uVar1;
    md[0x28] = (uchar)((uint)uVar3 >> 0x18);
    md[0x29] = (uchar)((uint)uVar3 >> 0x10);
    md[0x2c] = (uchar)((uint)uVar1 >> 0x18);
    md[0x2a] = (uchar)((uint)uVar3 >> 8);
    md[0x2d] = (uchar)((uint)uVar1 >> 0x10);
    md[0x2e] = (uchar)((uint)uVar1 >> 8);
    uVar3 = *(undefined4 *)(c->h + 6);
    uVar1 = *(undefined4 *)((int)c->h + 0x34);
    md[0x30] = (uchar)((uint)uVar3 >> 0x18);
    md[0x31] = (uchar)((uint)uVar3 >> 0x10);
    md[0x32] = (uchar)((uint)uVar3 >> 8);
    md[0x33] = (uchar)uVar3;
    md[0x34] = (uchar)((uint)uVar1 >> 0x18);
    md[0x35] = (uchar)((uint)uVar1 >> 0x10);
    md[0x36] = (uchar)((uint)uVar1 >> 8);
    md[0x37] = (uchar)uVar1;
    uVar3 = *(undefined4 *)(c->h + 7);
    uVar1 = *(undefined4 *)((int)c->h + 0x3c);
    md[0x3b] = (uchar)uVar3;
    md[0x3f] = (uchar)uVar1;
    md[0x38] = (uchar)((uint)uVar3 >> 0x18);
    md[0x3c] = (uchar)((uint)uVar1 >> 0x18);
    md[0x39] = (uchar)((uint)uVar3 >> 0x10);
    md[0x3d] = (uchar)((uint)uVar1 >> 0x10);
    md[0x3e] = (uchar)((uint)uVar1 >> 8);
    md[0x3a] = (uchar)((uint)uVar3 >> 8);
  }
  return 1;
}

