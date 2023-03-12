
void private_RC4_set_key(RC4_KEY *key,int len,uchar *data)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  
  pbVar9 = (byte *)((int)&key->x + 2);
  *(undefined *)&key->x = 0;
  iVar2 = 0;
  *(undefined *)((int)&key->x + 1) = 0;
  pbVar5 = pbVar9;
  do {
    *pbVar5 = (byte)iVar2;
    iVar2 = iVar2 + 1;
    pbVar5 = pbVar5 + 1;
  } while (iVar2 != 0x100);
  uVar6 = 0;
  iVar2 = 0;
  pbVar5 = pbVar9;
  do {
    bVar1 = *pbVar5;
    uVar7 = iVar2 + 1;
    uVar3 = iVar2 + 2;
    if ((uVar7 ^ len) == 0) {
      uVar3 = 1;
    }
    pbVar8 = pbVar5 + 4;
    if ((uVar7 ^ len) == 0) {
      uVar7 = 0;
    }
    uVar10 = len ^ uVar3;
    uVar6 = (uint)data[iVar2] + (uint)bVar1 + uVar6 & 0xff;
    iVar4 = uVar3 + 1;
    if (uVar10 == 0) {
      uVar3 = 0;
    }
    if (uVar10 == 0) {
      iVar4 = 1;
    }
    *pbVar5 = pbVar9[uVar6];
    pbVar9[uVar6] = bVar1;
    iVar2 = iVar4 + 1;
    bVar1 = pbVar5[1];
    if (len == iVar4) {
      iVar4 = 0;
      iVar2 = 1;
    }
    uVar6 = (uint)data[uVar7] + (uint)bVar1 + uVar6 & 0xff;
    if (len == iVar2) {
      iVar2 = 0;
    }
    pbVar5[1] = pbVar9[uVar6];
    pbVar9[uVar6] = bVar1;
    bVar1 = pbVar5[2];
    uVar6 = (uint)data[uVar3] + (uint)bVar1 + uVar6 & 0xff;
    pbVar5[2] = pbVar9[uVar6];
    pbVar9[uVar6] = bVar1;
    bVar1 = pbVar5[3];
    uVar6 = (uint)data[iVar4] + (uint)bVar1 + uVar6 & 0xff;
    pbVar5[3] = pbVar9[uVar6];
    pbVar9[uVar6] = bVar1;
    pbVar5 = pbVar8;
  } while ((byte *)((int)key->data + 0xfa) != pbVar8);
  return;
}

