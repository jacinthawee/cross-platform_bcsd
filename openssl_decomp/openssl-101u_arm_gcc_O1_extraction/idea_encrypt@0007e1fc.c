
void idea_encrypt(ulong *in,IDEA_KEY_SCHEDULE *ks)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  uVar1 = ks->data[0];
  uVar8 = *in >> 0x10;
  uVar5 = uVar1 * uVar8;
  if (uVar5 == 0) {
    uVar8 = (1 - uVar1) - uVar8;
  }
  else {
    uVar8 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar9 = ks->data[3];
  uVar3 = in[1] & 0xffff;
  uVar6 = uVar9 * uVar3;
  uVar1 = *in + ks->data[1];
  uVar5 = ks->data[2] + (in[1] >> 0x10);
  if (uVar6 == 0) {
    uVar3 = (1 - uVar9) - uVar3;
  }
  else {
    uVar3 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar9 = ks->data[4];
  uVar10 = (uVar8 ^ uVar5) & 0xffff;
  uVar6 = uVar9 * uVar10;
  if (uVar6 == 0) {
    iVar7 = (1 - uVar9) - uVar10;
  }
  else {
    uVar6 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    iVar7 = uVar6 - (uVar6 >> 0x10);
  }
  uVar10 = ks->data[5];
  uVar9 = (uVar3 ^ uVar1) + iVar7 & 0xffff;
  uVar6 = uVar10 * uVar9;
  if (uVar6 == 0) {
    uVar9 = (1 - uVar10) - uVar9;
  }
  else {
    uVar9 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar10 = ks->data[1][0];
  uVar8 = (uVar8 ^ uVar9) & 0xffff;
  uVar6 = uVar10 * uVar8;
  if (uVar6 == 0) {
    uVar8 = (1 - uVar10) - uVar8;
  }
  else {
    uVar8 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar10 = ks->data[1][3];
  uVar6 = (uVar3 ^ iVar7 + uVar9) & 0xffff;
  uVar3 = uVar10 * uVar6;
  uVar5 = (uVar9 ^ uVar5) + ks->data[1][1];
  uVar1 = ks->data[1][2] + (iVar7 + uVar9 ^ uVar1);
  if (uVar3 == 0) {
    uVar6 = (1 - uVar10) - uVar6;
  }
  else {
    uVar6 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar6 = uVar6 - (uVar6 >> 0x10);
  }
  uVar9 = ks->data[1][4];
  uVar10 = (uVar8 ^ uVar1) & 0xffff;
  uVar3 = uVar9 * uVar10;
  if (uVar3 == 0) {
    iVar7 = (1 - uVar9) - uVar10;
  }
  else {
    uVar3 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    iVar7 = uVar3 - (uVar3 >> 0x10);
  }
  uVar10 = ks->data[1][5];
  uVar9 = (uVar6 ^ uVar5) + iVar7 & 0xffff;
  uVar3 = uVar10 * uVar9;
  if (uVar3 == 0) {
    uVar9 = (1 - uVar10) - uVar9;
  }
  else {
    uVar9 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar10 = ks->data[2][0];
  uVar8 = (uVar8 ^ uVar9) & 0xffff;
  uVar3 = uVar10 * uVar8;
  if (uVar3 == 0) {
    uVar8 = (1 - uVar10) - uVar8;
  }
  else {
    uVar8 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar10 = ks->data[2][3];
  uVar3 = (uVar6 ^ iVar7 + uVar9) & 0xffff;
  uVar6 = uVar10 * uVar3;
  uVar1 = (uVar9 ^ uVar1) + ks->data[2][1];
  uVar5 = ks->data[2][2] + (iVar7 + uVar9 ^ uVar5);
  if (uVar6 == 0) {
    uVar3 = (1 - uVar10) - uVar3;
  }
  else {
    uVar3 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar9 = ks->data[2][4];
  uVar10 = (uVar8 ^ uVar5) & 0xffff;
  uVar6 = uVar9 * uVar10;
  if (uVar6 == 0) {
    iVar7 = (1 - uVar9) - uVar10;
  }
  else {
    uVar6 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    iVar7 = uVar6 - (uVar6 >> 0x10);
  }
  uVar10 = ks->data[2][5];
  uVar9 = (uVar3 ^ uVar1) + iVar7 & 0xffff;
  uVar6 = uVar10 * uVar9;
  if (uVar6 == 0) {
    uVar9 = (1 - uVar10) - uVar9;
  }
  else {
    uVar9 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar10 = ks->data[3][0];
  uVar8 = (uVar8 ^ uVar9) & 0xffff;
  uVar6 = uVar10 * uVar8;
  if (uVar6 == 0) {
    uVar8 = (1 - uVar10) - uVar8;
  }
  else {
    uVar8 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar10 = ks->data[3][3];
  uVar6 = (uVar3 ^ iVar7 + uVar9) & 0xffff;
  uVar3 = uVar10 * uVar6;
  uVar5 = (uVar9 ^ uVar5) + ks->data[3][1];
  uVar1 = ks->data[3][2] + (iVar7 + uVar9 ^ uVar1);
  if (uVar3 == 0) {
    uVar6 = (1 - uVar10) - uVar6;
  }
  else {
    uVar6 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar6 = uVar6 - (uVar6 >> 0x10);
  }
  uVar9 = ks->data[3][4];
  uVar10 = (uVar8 ^ uVar1) & 0xffff;
  uVar3 = uVar9 * uVar10;
  if (uVar3 == 0) {
    iVar7 = (1 - uVar9) - uVar10;
  }
  else {
    uVar3 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    iVar7 = uVar3 - (uVar3 >> 0x10);
  }
  uVar10 = ks->data[3][5];
  uVar9 = (uVar6 ^ uVar5) + iVar7 & 0xffff;
  uVar3 = uVar10 * uVar9;
  if (uVar3 == 0) {
    uVar9 = (1 - uVar10) - uVar9;
  }
  else {
    uVar9 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar10 = ks->data[4][0];
  uVar8 = (uVar8 ^ uVar9) & 0xffff;
  uVar3 = uVar10 * uVar8;
  if (uVar3 == 0) {
    uVar8 = (1 - uVar10) - uVar8;
  }
  else {
    uVar8 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar10 = ks->data[4][3];
  uVar3 = (uVar6 ^ iVar7 + uVar9) & 0xffff;
  uVar6 = uVar10 * uVar3;
  uVar1 = (uVar9 ^ uVar1) + ks->data[4][1];
  uVar5 = ks->data[4][2] + (iVar7 + uVar9 ^ uVar5);
  if (uVar6 == 0) {
    uVar3 = (1 - uVar10) - uVar3;
  }
  else {
    uVar3 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar9 = ks->data[4][4];
  uVar10 = (uVar8 ^ uVar5) & 0xffff;
  uVar6 = uVar9 * uVar10;
  if (uVar6 == 0) {
    iVar7 = (1 - uVar9) - uVar10;
  }
  else {
    uVar6 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    iVar7 = uVar6 - (uVar6 >> 0x10);
  }
  uVar10 = ks->data[4][5];
  uVar9 = (uVar3 ^ uVar1) + iVar7 & 0xffff;
  uVar6 = uVar10 * uVar9;
  if (uVar6 == 0) {
    uVar9 = (1 - uVar10) - uVar9;
  }
  else {
    uVar9 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar10 = ks->data[5][0];
  uVar8 = (uVar8 ^ uVar9) & 0xffff;
  uVar6 = uVar10 * uVar8;
  if (uVar6 == 0) {
    uVar8 = (1 - uVar10) - uVar8;
  }
  else {
    uVar8 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar10 = ks->data[5][3];
  uVar6 = (uVar3 ^ iVar7 + uVar9) & 0xffff;
  uVar3 = uVar10 * uVar6;
  uVar5 = (uVar9 ^ uVar5) + ks->data[5][1];
  uVar1 = ks->data[5][2] + (iVar7 + uVar9 ^ uVar1);
  if (uVar3 == 0) {
    uVar6 = (1 - uVar10) - uVar6;
  }
  else {
    uVar6 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar6 = uVar6 - (uVar6 >> 0x10);
  }
  uVar9 = ks->data[5][4];
  uVar10 = (uVar8 ^ uVar1) & 0xffff;
  uVar3 = uVar9 * uVar10;
  if (uVar3 == 0) {
    iVar7 = (1 - uVar9) - uVar10;
  }
  else {
    uVar3 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    iVar7 = uVar3 - (uVar3 >> 0x10);
  }
  uVar10 = ks->data[5][5];
  uVar9 = (uVar6 ^ uVar5) + iVar7 & 0xffff;
  uVar3 = uVar10 * uVar9;
  if (uVar3 == 0) {
    uVar9 = (1 - uVar10) - uVar9;
  }
  else {
    uVar9 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar10 = ks->data[6][0];
  uVar8 = (uVar8 ^ uVar9) & 0xffff;
  uVar3 = uVar10 * uVar8;
  if (uVar3 == 0) {
    uVar8 = (1 - uVar10) - uVar8;
  }
  else {
    uVar8 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar10 = ks->data[6][3];
  uVar3 = (uVar6 ^ iVar7 + uVar9) & 0xffff;
  uVar6 = uVar10 * uVar3;
  uVar1 = (uVar9 ^ uVar1) + ks->data[6][1];
  uVar5 = ks->data[6][2] + (iVar7 + uVar9 ^ uVar5);
  if (uVar6 == 0) {
    uVar3 = (1 - uVar10) - uVar3;
  }
  else {
    uVar3 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar9 = ks->data[6][4];
  uVar10 = (uVar8 ^ uVar5) & 0xffff;
  uVar6 = uVar9 * uVar10;
  if (uVar6 == 0) {
    iVar7 = (1 - uVar9) - uVar10;
  }
  else {
    uVar6 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    iVar7 = uVar6 - (uVar6 >> 0x10);
  }
  uVar10 = ks->data[6][5];
  uVar9 = (uVar3 ^ uVar1) + iVar7 & 0xffff;
  uVar6 = uVar10 * uVar9;
  if (uVar6 == 0) {
    uVar9 = (1 - uVar10) - uVar9;
  }
  else {
    uVar9 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar10 = ks->data[7][0];
  uVar8 = (uVar8 ^ uVar9) & 0xffff;
  uVar6 = uVar10 * uVar8;
  if (uVar6 == 0) {
    uVar8 = (1 - uVar10) - uVar8;
  }
  else {
    uVar8 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar10 = ks->data[7][3];
  uVar6 = (uVar3 ^ iVar7 + uVar9) & 0xffff;
  uVar3 = uVar10 * uVar6;
  uVar5 = (uVar9 ^ uVar5) + ks->data[7][1];
  uVar1 = ks->data[7][2] + (iVar7 + uVar9 ^ uVar1);
  if (uVar3 == 0) {
    uVar6 = (1 - uVar10) - uVar6;
  }
  else {
    uVar6 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar6 = uVar6 - (uVar6 >> 0x10);
  }
  uVar9 = ks->data[7][4];
  uVar10 = (uVar8 ^ uVar1) & 0xffff;
  uVar3 = uVar9 * uVar10;
  if (uVar3 == 0) {
    iVar7 = (1 - uVar9) - uVar10;
  }
  else {
    uVar3 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    iVar7 = uVar3 - (uVar3 >> 0x10);
  }
  uVar10 = ks->data[7][5];
  uVar9 = (uVar6 ^ uVar5) + iVar7 & 0xffff;
  uVar3 = uVar10 * uVar9;
  if (uVar3 == 0) {
    uVar9 = (1 - uVar10) - uVar9;
  }
  else {
    uVar9 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar3 = ks->data[8][0];
  uVar10 = (uVar8 ^ uVar9) & 0xffff;
  uVar8 = uVar3 * uVar10;
  if (uVar8 == 0) {
    iVar11 = (1 - uVar3) - uVar10;
  }
  else {
    uVar8 = (uVar8 & 0xffff) - (uVar8 >> 0x10);
    iVar11 = uVar8 - (uVar8 >> 0x10);
  }
  uVar3 = ks->data[8][3];
  uVar6 = (uVar6 ^ iVar7 + uVar9) & 0xffff;
  uVar10 = ks->data[8][2];
  uVar8 = uVar3 * uVar6;
  if (uVar8 == 0) {
    uVar2 = (1 - (short)uVar3) - (short)uVar6;
  }
  else {
    iVar4 = (uVar8 & 0xffff) - (uVar8 >> 0x10);
    uVar2 = (short)iVar4 - (short)((uint)iVar4 >> 0x10);
  }
  *in = (uVar5 ^ iVar7 + uVar9) + ks->data[8][1] & 0xffff | iVar11 << 0x10;
  in[1] = (uint)uVar2 | ((uVar9 ^ uVar1) + uVar10) * 0x10000;
  return;
}

