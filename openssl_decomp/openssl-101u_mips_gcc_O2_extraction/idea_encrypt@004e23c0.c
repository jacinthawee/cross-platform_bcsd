
void idea_encrypt(ulong *in,IDEA_KEY_SCHEDULE *ks)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar6 = ks->data[0];
  uVar5 = in[1];
  uVar11 = *in >> 0x10;
  uVar2 = uVar11 * uVar6;
  if (uVar2 == 0) {
    uVar2 = ks->data[2];
    uVar7 = ks->data[3];
    uVar11 = (1 - uVar6) - uVar11;
    uVar12 = ks->data[1];
    uVar6 = (uVar5 & 0xffff) * uVar7;
  }
  else {
    uVar7 = ks->data[3];
    uVar12 = ks->data[1];
    uVar11 = (uVar2 & 0xffff) - (uVar2 >> 0x10);
    uVar2 = ks->data[2];
    uVar11 = uVar11 - (uVar11 >> 0x10);
    uVar6 = (uVar5 & 0xffff) * uVar7;
  }
  uVar12 = *in + uVar12;
  uVar2 = (uVar5 >> 0x10) + uVar2;
  if (uVar6 == 0) {
    uVar6 = (uVar11 ^ uVar2) & 0xffff;
    uVar5 = (1 - uVar7) - (uVar5 & 0xffff);
    uVar7 = ks->data[4];
    uVar3 = uVar6 * uVar7;
  }
  else {
    uVar7 = ks->data[4];
    uVar5 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar6 = (uVar11 ^ uVar2) & 0xffff;
    uVar5 = uVar5 - (uVar5 >> 0x10);
    uVar3 = uVar6 * uVar7;
  }
  if (uVar3 == 0) {
    uVar9 = ks->data[5];
    iVar10 = (1 - uVar7) - uVar6;
    uVar6 = (uVar5 ^ uVar12) + iVar10 & 0xffff;
    uVar7 = uVar6 * uVar9;
  }
  else {
    uVar9 = ks->data[5];
    uVar6 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    iVar10 = uVar6 - (uVar6 >> 0x10);
    uVar6 = (uVar5 ^ uVar12) + iVar10 & 0xffff;
    uVar7 = uVar6 * uVar9;
  }
  if (uVar7 == 0) {
    uVar6 = (1 - uVar9) - uVar6;
    uVar7 = ks->data[1][0];
    uVar11 = (uVar11 ^ uVar6) & 0xffff;
    uVar3 = uVar11 * uVar7;
  }
  else {
    uVar6 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    uVar6 = uVar6 - (uVar6 >> 0x10);
    uVar7 = ks->data[1][0];
    uVar11 = (uVar11 ^ uVar6) & 0xffff;
    uVar3 = uVar11 * uVar7;
  }
  uVar5 = uVar5 ^ iVar10 + uVar6;
  if (uVar3 == 0) {
    uVar3 = ks->data[1][3];
    uVar9 = ks->data[1][1];
    uVar13 = ks->data[1][2];
    uVar11 = (1 - uVar7) - uVar11;
    uVar7 = (uVar5 & 0xffff) * uVar3;
  }
  else {
    uVar9 = ks->data[1][1];
    uVar13 = ks->data[1][2];
    uVar11 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
    uVar3 = ks->data[1][3];
    uVar7 = (uVar5 & 0xffff) * uVar3;
  }
  uVar13 = (uVar12 ^ iVar10 + uVar6) + uVar13;
  uVar9 = (uVar6 ^ uVar2) + uVar9;
  if (uVar7 == 0) {
    uVar6 = ks->data[1][4];
    uVar7 = (uVar11 ^ uVar13) & 0xffff;
    uVar2 = (1 - uVar3) - (uVar5 & 0xffff);
    uVar5 = uVar7 * uVar6;
  }
  else {
    uVar2 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    uVar7 = (uVar11 ^ uVar13) & 0xffff;
    uVar2 = uVar2 - (uVar2 >> 0x10);
    uVar6 = ks->data[1][4];
    uVar5 = uVar7 * uVar6;
  }
  if (uVar5 == 0) {
    uVar12 = ks->data[1][5];
    iVar10 = (1 - uVar6) - uVar7;
    uVar5 = (uVar2 ^ uVar9) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar12;
  }
  else {
    uVar12 = ks->data[1][5];
    uVar5 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar10 = uVar5 - (uVar5 >> 0x10);
    uVar5 = (uVar2 ^ uVar9) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar12;
  }
  if (uVar6 == 0) {
    uVar5 = (1 - uVar12) - uVar5;
    uVar6 = ks->data[2][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  else {
    uVar5 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar5 = uVar5 - (uVar5 >> 0x10);
    uVar6 = ks->data[2][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  uVar2 = uVar2 ^ iVar10 + uVar5;
  if (uVar7 == 0) {
    uVar7 = ks->data[2][3];
    uVar12 = ks->data[2][1];
    uVar3 = ks->data[2][2];
    uVar11 = (1 - uVar6) - uVar11;
    uVar6 = (uVar2 & 0xffff) * uVar7;
  }
  else {
    uVar12 = ks->data[2][1];
    uVar3 = ks->data[2][2];
    uVar11 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
    uVar7 = ks->data[2][3];
    uVar6 = (uVar2 & 0xffff) * uVar7;
  }
  uVar3 = (uVar9 ^ iVar10 + uVar5) + uVar3;
  uVar12 = (uVar5 ^ uVar13) + uVar12;
  if (uVar6 == 0) {
    uVar5 = ks->data[2][4];
    uVar6 = (uVar11 ^ uVar3) & 0xffff;
    uVar2 = (1 - uVar7) - (uVar2 & 0xffff);
    uVar7 = uVar6 * uVar5;
  }
  else {
    uVar2 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar6 = (uVar11 ^ uVar3) & 0xffff;
    uVar2 = uVar2 - (uVar2 >> 0x10);
    uVar5 = ks->data[2][4];
    uVar7 = uVar6 * uVar5;
  }
  if (uVar7 == 0) {
    uVar9 = ks->data[2][5];
    iVar10 = (1 - uVar5) - uVar6;
    uVar5 = (uVar2 ^ uVar12) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar9;
  }
  else {
    uVar9 = ks->data[2][5];
    uVar5 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    iVar10 = uVar5 - (uVar5 >> 0x10);
    uVar5 = (uVar2 ^ uVar12) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar9;
  }
  if (uVar6 == 0) {
    uVar5 = (1 - uVar9) - uVar5;
    uVar6 = ks->data[3][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  else {
    uVar5 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar5 = uVar5 - (uVar5 >> 0x10);
    uVar6 = ks->data[3][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  uVar2 = uVar2 ^ iVar10 + uVar5;
  if (uVar7 == 0) {
    uVar7 = ks->data[3][3];
    uVar9 = ks->data[3][1];
    uVar13 = ks->data[3][2];
    uVar11 = (1 - uVar6) - uVar11;
    uVar6 = (uVar2 & 0xffff) * uVar7;
  }
  else {
    uVar9 = ks->data[3][1];
    uVar13 = ks->data[3][2];
    uVar11 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
    uVar7 = ks->data[3][3];
    uVar6 = (uVar2 & 0xffff) * uVar7;
  }
  uVar13 = (uVar12 ^ iVar10 + uVar5) + uVar13;
  uVar9 = (uVar5 ^ uVar3) + uVar9;
  if (uVar6 == 0) {
    uVar5 = ks->data[3][4];
    uVar6 = (uVar11 ^ uVar13) & 0xffff;
    uVar2 = (1 - uVar7) - (uVar2 & 0xffff);
    uVar7 = uVar6 * uVar5;
  }
  else {
    uVar2 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar6 = (uVar11 ^ uVar13) & 0xffff;
    uVar2 = uVar2 - (uVar2 >> 0x10);
    uVar5 = ks->data[3][4];
    uVar7 = uVar6 * uVar5;
  }
  if (uVar7 == 0) {
    uVar12 = ks->data[3][5];
    iVar10 = (1 - uVar5) - uVar6;
    uVar5 = (uVar2 ^ uVar9) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar12;
  }
  else {
    uVar12 = ks->data[3][5];
    uVar5 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    iVar10 = uVar5 - (uVar5 >> 0x10);
    uVar5 = (uVar2 ^ uVar9) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar12;
  }
  if (uVar6 == 0) {
    uVar5 = (1 - uVar12) - uVar5;
    uVar6 = ks->data[4][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  else {
    uVar5 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar5 = uVar5 - (uVar5 >> 0x10);
    uVar6 = ks->data[4][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  uVar2 = uVar2 ^ iVar10 + uVar5;
  if (uVar7 == 0) {
    uVar7 = ks->data[4][3];
    uVar12 = ks->data[4][1];
    uVar3 = ks->data[4][2];
    uVar11 = (1 - uVar6) - uVar11;
    uVar6 = (uVar2 & 0xffff) * uVar7;
  }
  else {
    uVar12 = ks->data[4][1];
    uVar3 = ks->data[4][2];
    uVar11 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
    uVar7 = ks->data[4][3];
    uVar6 = (uVar2 & 0xffff) * uVar7;
  }
  uVar3 = (uVar9 ^ iVar10 + uVar5) + uVar3;
  uVar12 = (uVar5 ^ uVar13) + uVar12;
  if (uVar6 == 0) {
    uVar5 = ks->data[4][4];
    uVar6 = (uVar11 ^ uVar3) & 0xffff;
    uVar2 = (1 - uVar7) - (uVar2 & 0xffff);
    uVar7 = uVar6 * uVar5;
  }
  else {
    uVar2 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar6 = (uVar11 ^ uVar3) & 0xffff;
    uVar2 = uVar2 - (uVar2 >> 0x10);
    uVar5 = ks->data[4][4];
    uVar7 = uVar6 * uVar5;
  }
  if (uVar7 == 0) {
    uVar9 = ks->data[4][5];
    iVar10 = (1 - uVar5) - uVar6;
    uVar5 = (uVar2 ^ uVar12) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar9;
  }
  else {
    uVar9 = ks->data[4][5];
    uVar5 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    iVar10 = uVar5 - (uVar5 >> 0x10);
    uVar5 = (uVar2 ^ uVar12) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar9;
  }
  if (uVar6 == 0) {
    uVar5 = (1 - uVar9) - uVar5;
    uVar6 = ks->data[5][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  else {
    uVar5 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar5 = uVar5 - (uVar5 >> 0x10);
    uVar6 = ks->data[5][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  uVar2 = uVar2 ^ iVar10 + uVar5;
  if (uVar7 == 0) {
    uVar7 = ks->data[5][3];
    uVar9 = ks->data[5][1];
    uVar13 = ks->data[5][2];
    uVar11 = (1 - uVar6) - uVar11;
    uVar6 = (uVar2 & 0xffff) * uVar7;
  }
  else {
    uVar9 = ks->data[5][1];
    uVar13 = ks->data[5][2];
    uVar11 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
    uVar7 = ks->data[5][3];
    uVar6 = (uVar2 & 0xffff) * uVar7;
  }
  uVar13 = (uVar12 ^ iVar10 + uVar5) + uVar13;
  uVar9 = (uVar5 ^ uVar3) + uVar9;
  if (uVar6 == 0) {
    uVar5 = ks->data[5][4];
    uVar6 = (uVar11 ^ uVar13) & 0xffff;
    uVar2 = (1 - uVar7) - (uVar2 & 0xffff);
    uVar7 = uVar6 * uVar5;
  }
  else {
    uVar2 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar6 = (uVar11 ^ uVar13) & 0xffff;
    uVar2 = uVar2 - (uVar2 >> 0x10);
    uVar5 = ks->data[5][4];
    uVar7 = uVar6 * uVar5;
  }
  if (uVar7 == 0) {
    uVar12 = ks->data[5][5];
    iVar10 = (1 - uVar5) - uVar6;
    uVar5 = (uVar2 ^ uVar9) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar12;
  }
  else {
    uVar12 = ks->data[5][5];
    uVar5 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    iVar10 = uVar5 - (uVar5 >> 0x10);
    uVar5 = (uVar2 ^ uVar9) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar12;
  }
  if (uVar6 == 0) {
    uVar5 = (1 - uVar12) - uVar5;
    uVar6 = ks->data[6][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  else {
    uVar5 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar5 = uVar5 - (uVar5 >> 0x10);
    uVar6 = ks->data[6][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  uVar2 = uVar2 ^ iVar10 + uVar5;
  if (uVar7 == 0) {
    uVar7 = ks->data[6][3];
    uVar3 = ks->data[6][2];
    uVar12 = (uVar2 & 0xffff) * uVar7;
    uVar11 = (1 - uVar6) - uVar11;
    uVar6 = ks->data[6][1];
  }
  else {
    uVar6 = ks->data[6][1];
    uVar3 = ks->data[6][2];
    uVar11 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
    uVar7 = ks->data[6][3];
    uVar12 = (uVar2 & 0xffff) * uVar7;
  }
  uVar6 = (uVar5 ^ uVar13) + uVar6;
  uVar3 = (uVar9 ^ iVar10 + uVar5) + uVar3;
  if (uVar12 == 0) {
    uVar5 = ks->data[6][4];
    uVar9 = (uVar11 ^ uVar3) & 0xffff;
    uVar2 = (1 - uVar7) - (uVar2 & 0xffff);
    uVar7 = uVar9 * uVar5;
  }
  else {
    uVar5 = ks->data[6][4];
    uVar9 = (uVar11 ^ uVar3) & 0xffff;
    uVar7 = uVar9 * uVar5;
    uVar2 = (uVar12 & 0xffff) - (uVar12 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  if (uVar7 == 0) {
    uVar12 = ks->data[6][5];
    iVar10 = (1 - uVar5) - uVar9;
    uVar5 = (uVar2 ^ uVar6) + iVar10 & 0xffff;
    uVar7 = uVar5 * uVar12;
  }
  else {
    uVar12 = ks->data[6][5];
    uVar5 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    iVar10 = uVar5 - (uVar5 >> 0x10);
    uVar5 = (uVar2 ^ uVar6) + iVar10 & 0xffff;
    uVar7 = uVar5 * uVar12;
  }
  if (uVar7 == 0) {
    uVar5 = (1 - uVar12) - uVar5;
    uVar7 = ks->data[7][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar12 = uVar11 * uVar7;
  }
  else {
    uVar5 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    uVar5 = uVar5 - (uVar5 >> 0x10);
    uVar7 = ks->data[7][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar12 = uVar11 * uVar7;
  }
  uVar2 = uVar2 ^ iVar10 + uVar5;
  if (uVar12 == 0) {
    uVar12 = ks->data[7][3];
    uVar13 = ks->data[7][1];
    uVar9 = (uVar2 & 0xffff) * uVar12;
    uVar4 = ks->data[7][2];
    uVar11 = (1 - uVar7) - uVar11;
  }
  else {
    uVar13 = ks->data[7][1];
    uVar4 = ks->data[7][2];
    uVar11 = (uVar12 & 0xffff) - (uVar12 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
    uVar12 = ks->data[7][3];
    uVar9 = (uVar2 & 0xffff) * uVar12;
  }
  uVar4 = (uVar6 ^ iVar10 + uVar5) + uVar4;
  uVar13 = (uVar5 ^ uVar3) + uVar13;
  if (uVar9 == 0) {
    uVar5 = ks->data[7][4];
    uVar6 = (uVar11 ^ uVar4) & 0xffff;
    uVar7 = uVar6 * uVar5;
    uVar2 = (1 - uVar12) - (uVar2 & 0xffff);
  }
  else {
    uVar5 = ks->data[7][4];
    uVar6 = (uVar11 ^ uVar4) & 0xffff;
    uVar7 = uVar6 * uVar5;
    uVar2 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  if (uVar7 == 0) {
    uVar12 = ks->data[7][5];
    iVar10 = (1 - uVar5) - uVar6;
    uVar5 = (uVar2 ^ uVar13) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar12;
  }
  else {
    uVar12 = ks->data[7][5];
    uVar5 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    iVar10 = uVar5 - (uVar5 >> 0x10);
    uVar5 = (uVar2 ^ uVar13) + iVar10 & 0xffff;
    uVar6 = uVar5 * uVar12;
  }
  if (uVar6 == 0) {
    uVar5 = (1 - uVar12) - uVar5;
    uVar6 = ks->data[8][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  else {
    uVar5 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar5 = uVar5 - (uVar5 >> 0x10);
    uVar6 = ks->data[8][0];
    uVar11 = (uVar11 ^ uVar5) & 0xffff;
    uVar7 = uVar11 * uVar6;
  }
  uVar2 = uVar2 ^ iVar10 + uVar5;
  if (uVar7 == 0) {
    uVar3 = ks->data[8][1];
    uVar12 = ks->data[8][3];
    iVar8 = (1 - uVar6) - uVar11;
    uVar6 = ks->data[8][2];
    uVar11 = (uVar2 & 0xffff) * uVar12;
  }
  else {
    uVar12 = ks->data[8][3];
    uVar3 = ks->data[8][1];
    uVar6 = ks->data[8][2];
    uVar11 = (uVar2 & 0xffff) * uVar12;
    uVar7 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    iVar8 = uVar7 - (uVar7 >> 0x10);
  }
  iVar1 = (uVar5 ^ uVar4) + uVar6;
  uVar3 = (uVar13 ^ iVar10 + uVar5) + uVar3;
  if (uVar11 != 0) {
    uVar11 = (uVar11 & 0xffff) - (uVar11 >> 0x10);
    *in = uVar3 & 0xffff | iVar8 << 0x10;
    in[1] = uVar11 - (uVar11 >> 0x10) & 0xffff | iVar1 * 0x10000;
    return;
  }
  *in = uVar3 & 0xffff | iVar8 << 0x10;
  in[1] = (1 - uVar12) - (uVar2 & 0xffff) & 0xffff | iVar1 * 0x10000;
  return;
}

