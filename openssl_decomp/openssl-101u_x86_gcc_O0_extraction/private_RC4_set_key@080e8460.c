
void private_RC4_set_key(RC4_KEY *key,int len,uchar *data)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  
  iVar3 = 0;
  pbVar1 = (byte *)((int)&key->x + 2);
  *(undefined *)&key->x = 0;
  *(undefined *)((int)&key->x + 1) = 0;
  do {
    pbVar1[iVar3] = (byte)iVar3;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x100);
  uVar4 = 0;
  iVar3 = 0;
  pbVar7 = pbVar1;
  do {
    bVar2 = *pbVar7;
    iVar6 = iVar3 + 1;
    iVar9 = iVar3 + 2;
    uVar4 = uVar4 + (uint)bVar2 + (uint)data[iVar3] & 0xff;
    if (iVar6 == len) {
      iVar9 = 1;
    }
    *pbVar7 = pbVar1[uVar4];
    pbVar1[uVar4] = bVar2;
    if (iVar6 == len) {
      iVar6 = 0;
    }
    bVar2 = pbVar7[1];
    iVar5 = iVar9 + 1;
    uVar4 = (uint)bVar2 + (uint)data[iVar6] + uVar4 & 0xff;
    if (len == iVar9) {
      iVar5 = 1;
    }
    pbVar7[1] = pbVar1[uVar4];
    pbVar1[uVar4] = bVar2;
    bVar2 = pbVar7[2];
    if (len == iVar9) {
      iVar9 = 0;
    }
    iVar3 = iVar5 + 1;
    uVar4 = uVar4 + (uint)bVar2 + (uint)data[iVar9] & 0xff;
    if (len == iVar5) {
      iVar3 = 1;
    }
    pbVar7[2] = pbVar1[uVar4];
    pbVar1[uVar4] = bVar2;
    bVar2 = pbVar7[3];
    if (len == iVar5) {
      iVar5 = 0;
    }
    uVar4 = (uint)bVar2 + (uint)data[iVar5] + uVar4 & 0xff;
    if (len == iVar3) {
      iVar3 = 0;
    }
    pbVar8 = pbVar7 + 4;
    pbVar7[3] = pbVar1[uVar4];
    pbVar1[uVar4] = bVar2;
    pbVar7 = pbVar8;
  } while ((byte *)((int)key->data + 0xfa) != pbVar8);
  return;
}

