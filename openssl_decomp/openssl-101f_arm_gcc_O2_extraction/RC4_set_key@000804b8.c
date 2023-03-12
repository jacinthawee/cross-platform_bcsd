
void RC4_set_key(RC4_KEY *key,int len,uchar *data)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  int iVar11;
  int unaff_r10;
  bool bVar12;
  
  puVar4 = (undefined *)((int)&key->x + 2);
  *(undefined *)&key->x = 0;
  iVar5 = 0;
  *(undefined *)((int)&key->x + 1) = 0;
  do {
    puVar4[iVar5] = (char)iVar5;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x100);
  uVar6 = 0;
  iVar5 = 0;
  puVar2 = puVar4;
  puVar9 = (undefined *)((int)&key->x + 3);
  do {
    bVar1 = puVar9[-1];
    iVar11 = iVar5 + 1;
    bVar12 = iVar11 == len;
    iVar7 = iVar5 + 2;
    puVar3 = puVar2 + 4;
    iVar10 = (uint)data[iVar5] + (uint)bVar1;
    if (bVar12) {
      iVar11 = 0;
    }
    if (bVar12) {
      iVar7 = 1;
    }
    uVar6 = uVar6 + iVar10 & 0xff;
    if (len != iVar7) {
      iVar10 = iVar7;
    }
    iVar8 = iVar7 + 1;
    if (len == iVar7) {
      iVar8 = 1;
      iVar10 = 0;
    }
    bVar12 = len != iVar8;
    iVar5 = iVar8 + 1;
    puVar9[-1] = puVar4[uVar6];
    if (bVar12) {
      unaff_r10 = iVar8;
    }
    puVar4[uVar6] = bVar1;
    bVar1 = puVar2[1];
    if (!bVar12) {
      unaff_r10 = 0;
    }
    if (!bVar12) {
      iVar5 = 1;
    }
    if (len == iVar5) {
      iVar5 = 0;
    }
    uVar6 = uVar6 + (uint)data[iVar11] + (uint)bVar1 & 0xff;
    puVar2[1] = puVar4[uVar6];
    puVar4[uVar6] = bVar1;
    bVar1 = puVar2[2];
    uVar6 = uVar6 + (uint)data[iVar10] + (uint)bVar1 & 0xff;
    puVar2[2] = puVar4[uVar6];
    puVar4[uVar6] = bVar1;
    bVar1 = puVar2[3];
    uVar6 = (uint)data[unaff_r10] + (uint)bVar1 + uVar6 & 0xff;
    puVar2[3] = puVar4[uVar6];
    puVar4[uVar6] = bVar1;
    puVar2 = puVar3;
    puVar9 = puVar9 + 4;
  } while (puVar3 != (undefined *)((int)key->data + 0xfa));
  return;
}

