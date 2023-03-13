
void idea_encrypt(ulong *in,IDEA_KEY_SCHEDULE *ks)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint local_18;
  
  uVar1 = ks->data[0];
  local_18 = *in >> 0x10;
  uVar6 = local_18 * uVar1;
  if (uVar6 == 0) {
    local_18 = (1 - uVar1) - local_18;
  }
  else {
    local_18 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    local_18 = local_18 - (local_18 >> 0x10);
  }
  uVar3 = (in[1] >> 0x10) + ks->data[2];
  uVar1 = ks->data[3];
  uVar6 = in[1] & 0xffff;
  uVar9 = *in + ks->data[1];
  uVar4 = uVar6 * uVar1;
  if (uVar4 == 0) {
    uVar6 = (1 - uVar1) - uVar6;
  }
  else {
    uVar6 = (uVar4 & 0xffff) - (uVar4 >> 0x10);
    uVar6 = uVar6 - (uVar6 >> 0x10);
  }
  uVar1 = ks->data[4];
  uVar4 = (local_18 ^ uVar3) & 0xffff;
  uVar7 = uVar4 * uVar1;
  if (uVar7 == 0) {
    iVar2 = (1 - uVar1) - uVar4;
  }
  else {
    uVar1 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    iVar2 = uVar1 - (uVar1 >> 0x10);
  }
  uVar1 = ks->data[5];
  uVar7 = (uVar6 ^ uVar9) + iVar2 & 0xffff;
  uVar4 = uVar7 * uVar1;
  if (uVar4 == 0) {
    uVar7 = (1 - uVar1) - uVar7;
  }
  else {
    uVar7 = (uVar4 & 0xffff) - (uVar4 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar1 = ks->data[1][0];
  local_18 = (local_18 ^ uVar7) & 0xffff;
  uVar4 = local_18 * uVar1;
  if (uVar4 == 0) {
    local_18 = (1 - uVar1) - local_18;
  }
  else {
    local_18 = (uVar4 & 0xffff) - (uVar4 >> 0x10);
    local_18 = local_18 - (local_18 >> 0x10);
  }
  uVar4 = (iVar2 + uVar7 ^ uVar9) + ks->data[1][2];
  uVar1 = ks->data[1][3];
  uVar9 = (uVar6 ^ iVar2 + uVar7) & 0xffff;
  uVar3 = (uVar7 ^ uVar3) + ks->data[1][1];
  uVar6 = uVar9 * uVar1;
  if (uVar6 == 0) {
    uVar9 = (1 - uVar1) - uVar9;
  }
  else {
    uVar9 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar1 = ks->data[1][4];
  uVar6 = (local_18 ^ uVar4) & 0xffff;
  uVar7 = uVar6 * uVar1;
  if (uVar7 == 0) {
    iVar2 = (1 - uVar1) - uVar6;
  }
  else {
    uVar1 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    iVar2 = uVar1 - (uVar1 >> 0x10);
  }
  uVar1 = ks->data[1][5];
  uVar7 = (uVar9 ^ uVar3) + iVar2 & 0xffff;
  uVar6 = uVar7 * uVar1;
  if (uVar6 == 0) {
    uVar7 = (1 - uVar1) - uVar7;
  }
  else {
    uVar7 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar1 = ks->data[2][0];
  local_18 = (local_18 ^ uVar7) & 0xffff;
  uVar6 = local_18 * uVar1;
  if (uVar6 == 0) {
    local_18 = (1 - uVar1) - local_18;
  }
  else {
    local_18 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    local_18 = local_18 - (local_18 >> 0x10);
  }
  uVar5 = (iVar2 + uVar7 ^ uVar3) + ks->data[2][2];
  uVar9 = (uVar9 ^ iVar2 + uVar7) & 0xffff;
  uVar6 = (uVar7 ^ uVar4) + ks->data[2][1];
  uVar1 = ks->data[2][3];
  uVar3 = uVar9 * uVar1;
  if (uVar3 == 0) {
    uVar9 = (1 - uVar1) - uVar9;
  }
  else {
    uVar9 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar1 = ks->data[2][4];
  uVar3 = (local_18 ^ uVar5) & 0xffff;
  uVar4 = uVar3 * uVar1;
  if (uVar4 == 0) {
    iVar2 = (1 - uVar1) - uVar3;
  }
  else {
    uVar1 = (uVar4 & 0xffff) - (uVar4 >> 0x10);
    iVar2 = uVar1 - (uVar1 >> 0x10);
  }
  uVar1 = ks->data[2][5];
  uVar4 = (uVar9 ^ uVar6) + iVar2 & 0xffff;
  uVar3 = uVar4 * uVar1;
  if (uVar3 == 0) {
    uVar4 = (1 - uVar1) - uVar4;
  }
  else {
    uVar4 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar1 = ks->data[3][0];
  local_18 = (local_18 ^ uVar4) & 0xffff;
  uVar3 = local_18 * uVar1;
  if (uVar3 == 0) {
    local_18 = (1 - uVar1) - local_18;
  }
  else {
    local_18 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    local_18 = local_18 - (local_18 >> 0x10);
  }
  uVar7 = (iVar2 + uVar4 ^ uVar6) + ks->data[3][2];
  uVar9 = (uVar9 ^ iVar2 + uVar4) & 0xffff;
  uVar3 = (uVar4 ^ uVar5) + ks->data[3][1];
  uVar1 = ks->data[3][3];
  uVar6 = uVar9 * uVar1;
  if (uVar6 == 0) {
    uVar9 = (1 - uVar1) - uVar9;
  }
  else {
    uVar9 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar1 = ks->data[3][4];
  uVar6 = (local_18 ^ uVar7) & 0xffff;
  uVar4 = uVar6 * uVar1;
  if (uVar4 == 0) {
    iVar2 = (1 - uVar1) - uVar6;
  }
  else {
    uVar1 = (uVar4 & 0xffff) - (uVar4 >> 0x10);
    iVar2 = uVar1 - (uVar1 >> 0x10);
  }
  uVar1 = ks->data[3][5];
  uVar4 = (uVar9 ^ uVar3) + iVar2 & 0xffff;
  uVar6 = uVar4 * uVar1;
  if (uVar6 == 0) {
    uVar4 = (1 - uVar1) - uVar4;
  }
  else {
    uVar4 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar1 = ks->data[4][0];
  local_18 = (local_18 ^ uVar4) & 0xffff;
  uVar6 = local_18 * uVar1;
  if (uVar6 == 0) {
    local_18 = (1 - uVar1) - local_18;
  }
  else {
    local_18 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    local_18 = local_18 - (local_18 >> 0x10);
  }
  uVar1 = ks->data[4][3];
  uVar9 = (uVar9 ^ iVar2 + uVar4) & 0xffff;
  uVar5 = (iVar2 + uVar4 ^ uVar3) + ks->data[4][2];
  uVar6 = (uVar4 ^ uVar7) + ks->data[4][1];
  uVar3 = uVar9 * uVar1;
  if (uVar3 == 0) {
    uVar9 = (1 - uVar1) - uVar9;
  }
  else {
    uVar9 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar1 = ks->data[4][4];
  uVar3 = (local_18 ^ uVar5) & 0xffff;
  uVar4 = uVar3 * uVar1;
  if (uVar4 == 0) {
    iVar2 = (1 - uVar1) - uVar3;
  }
  else {
    uVar1 = (uVar4 & 0xffff) - (uVar4 >> 0x10);
    iVar2 = uVar1 - (uVar1 >> 0x10);
  }
  uVar1 = ks->data[4][5];
  uVar4 = (uVar9 ^ uVar6) + iVar2 & 0xffff;
  uVar3 = uVar4 * uVar1;
  if (uVar3 == 0) {
    uVar4 = (1 - uVar1) - uVar4;
  }
  else {
    uVar4 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar1 = ks->data[5][0];
  local_18 = (local_18 ^ uVar4) & 0xffff;
  uVar3 = local_18 * uVar1;
  if (uVar3 == 0) {
    local_18 = (1 - uVar1) - local_18;
  }
  else {
    local_18 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    local_18 = local_18 - (local_18 >> 0x10);
  }
  uVar7 = (iVar2 + uVar4 ^ uVar6) + ks->data[5][2];
  uVar1 = ks->data[5][3];
  uVar3 = (uVar4 ^ uVar5) + ks->data[5][1];
  uVar4 = (uVar9 ^ iVar2 + uVar4) & 0xffff;
  uVar6 = uVar4 * uVar1;
  if (uVar6 == 0) {
    uVar4 = (1 - uVar1) - uVar4;
  }
  else {
    uVar4 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar1 = ks->data[5][4];
  uVar6 = (local_18 ^ uVar7) & 0xffff;
  uVar9 = uVar6 * uVar1;
  if (uVar9 == 0) {
    iVar2 = (1 - uVar1) - uVar6;
  }
  else {
    uVar1 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar2 = uVar1 - (uVar1 >> 0x10);
  }
  uVar1 = ks->data[5][5];
  uVar9 = (uVar4 ^ uVar3) + iVar2 & 0xffff;
  uVar6 = uVar9 * uVar1;
  if (uVar6 == 0) {
    uVar9 = (1 - uVar1) - uVar9;
  }
  else {
    uVar9 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar1 = ks->data[6][0];
  local_18 = (local_18 ^ uVar9) & 0xffff;
  uVar6 = local_18 * uVar1;
  if (uVar6 == 0) {
    local_18 = (1 - uVar1) - local_18;
  }
  else {
    local_18 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    local_18 = local_18 - (local_18 >> 0x10);
  }
  uVar5 = (iVar2 + uVar9 ^ uVar3) + ks->data[6][2];
  uVar4 = (uVar4 ^ iVar2 + uVar9) & 0xffff;
  uVar6 = (uVar9 ^ uVar7) + ks->data[6][1];
  uVar1 = ks->data[6][3];
  uVar3 = uVar4 * uVar1;
  if (uVar3 == 0) {
    uVar4 = (1 - uVar1) - uVar4;
  }
  else {
    uVar4 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar1 = ks->data[6][4];
  uVar3 = (local_18 ^ uVar5) & 0xffff;
  uVar9 = uVar3 * uVar1;
  if (uVar9 == 0) {
    iVar2 = (1 - uVar1) - uVar3;
  }
  else {
    uVar1 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar2 = uVar1 - (uVar1 >> 0x10);
  }
  uVar1 = ks->data[6][5];
  uVar9 = (uVar4 ^ uVar6) + iVar2 & 0xffff;
  uVar3 = uVar9 * uVar1;
  if (uVar3 == 0) {
    uVar9 = (1 - uVar1) - uVar9;
  }
  else {
    uVar9 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar1 = ks->data[7][0];
  local_18 = (local_18 ^ uVar9) & 0xffff;
  uVar3 = local_18 * uVar1;
  if (uVar3 == 0) {
    local_18 = (1 - uVar1) - local_18;
  }
  else {
    local_18 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    local_18 = local_18 - (local_18 >> 0x10);
  }
  uVar1 = ks->data[7][3];
  uVar4 = (uVar4 ^ iVar2 + uVar9) & 0xffff;
  uVar7 = (iVar2 + uVar9 ^ uVar6) + ks->data[7][2];
  uVar3 = (uVar9 ^ uVar5) + ks->data[7][1];
  uVar6 = uVar4 * uVar1;
  if (uVar6 == 0) {
    uVar4 = (1 - uVar1) - uVar4;
  }
  else {
    uVar4 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar1 = ks->data[7][4];
  uVar6 = (local_18 ^ uVar7) & 0xffff;
  uVar9 = uVar6 * uVar1;
  if (uVar9 == 0) {
    iVar2 = (1 - uVar1) - uVar6;
  }
  else {
    uVar1 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar2 = uVar1 - (uVar1 >> 0x10);
  }
  uVar1 = ks->data[7][5];
  uVar9 = (uVar4 ^ uVar3) + iVar2 & 0xffff;
  uVar6 = uVar9 * uVar1;
  if (uVar6 == 0) {
    uVar9 = (1 - uVar1) - uVar9;
  }
  else {
    uVar9 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar1 = ks->data[8][0];
  uVar6 = (local_18 ^ uVar9) & 0xffff;
  uVar5 = uVar6 * uVar1;
  if (uVar5 == 0) {
    iVar8 = (1 - uVar1) - uVar6;
  }
  else {
    uVar1 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar8 = uVar1 - (uVar1 >> 0x10);
  }
  uVar1 = ks->data[8][3];
  uVar5 = (uVar4 ^ iVar2 + uVar9) & 0xffff;
  uVar6 = ks->data[8][2];
  uVar4 = uVar5 * uVar1;
  if (uVar4 == 0) {
    uVar5 = (1 - uVar1) - uVar5;
  }
  else {
    uVar5 = (uVar4 & 0xffff) - (uVar4 >> 0x10);
    uVar5 = uVar5 - (uVar5 >> 0x10);
  }
  *in = (iVar2 + uVar9 ^ uVar3) + ks->data[8][1] & 0xffff | iVar8 << 0x10;
  in[1] = ((uVar9 ^ uVar7) + uVar6) * 0x10000 | uVar5 & 0xffff;
  return;
}

