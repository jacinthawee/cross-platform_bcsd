
void RC2_set_key(RC2_KEY *key,int len,uchar *data,int bits)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  RC2_KEY *pRVar5;
  int iVar6;
  char *pcVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  if (0x7f < len) {
    len = 0x80;
  }
  iVar14 = 0;
  *(undefined *)key->data = 0;
  if ((bits < 1) || (0x400 < bits)) {
    iVar4 = -1;
    uVar11 = 0xff;
    iVar13 = 0x80;
  }
  else {
    iVar13 = bits + 7 >> 3;
    uVar11 = 0xff >> (-bits & 7U);
    iVar14 = 0x80 - iVar13;
    iVar4 = 0x7f - iVar13;
  }
  if (len < 1) {
    cVar8 = *(char *)((int)key->data + (len - 1U));
  }
  else {
    uVar9 = (uint)(((uint)data & 3) == 0);
    if ((uint)len < 9) {
      uVar9 = 0;
    }
    uVar9 = ((RC2_KEY *)(data + 4) <= key || key->data + 1 <= data) & uVar9;
    if (uVar9 == 0) {
      do {
        *(uchar *)((int)key->data + uVar9) = data[uVar9];
        uVar12 = uVar9 + 1;
        if (uVar12 == len) break;
        *(uchar *)((int)key->data + uVar12) = data[uVar12];
        uVar9 = uVar9 + 2;
      } while (uVar9 != len);
    }
    else {
      iVar10 = 0;
      uVar9 = 0;
      uVar12 = len & 0xfffffffc;
      do {
        uVar9 = uVar9 + 1;
        *(undefined4 *)((int)key->data + iVar10) = *(undefined4 *)(data + iVar10);
        iVar10 = iVar10 + 4;
      } while (uVar9 < (uint)len >> 2);
      if (uVar12 != len) {
        iVar10 = uVar12 + 1;
        *(uchar *)((int)key->data + (len & 0xfffffffcU)) = data[len & 0xfffffffc];
        if (iVar10 < len) {
          iVar6 = uVar12 + 2;
          *(uchar *)((int)key->data + iVar10) = data[iVar10];
          if (iVar6 < len) {
            *(uchar *)((int)key->data + iVar6) = data[iVar6];
          }
        }
      }
    }
    cVar8 = *(char *)((int)key->data + (len - 1U));
    if (len == 0x80) goto LAB_0007f88e;
  }
  pcVar7 = (char *)((int)key[-1].data + 0xff);
  do {
    pcVar7 = pcVar7 + 1;
    cVar8 = (&key_table)[(byte)(cVar8 + *pcVar7)];
    pcVar7[len] = cVar8;
  } while (pcVar7 != (char *)((int)key + (0x7f - len)));
LAB_0007f88e:
  bVar1 = (&key_table)[*(byte *)((int)key->data + iVar14) & uVar11];
  *(byte *)((int)key->data + iVar14) = bVar1;
  while (iVar10 = iVar4, iVar14 != 0) {
    bVar1 = (&key_table)[bVar1 ^ *(byte *)((int)key->data + iVar10 + iVar13)];
    *(byte *)((int)key->data + iVar10) = bVar1;
    iVar4 = iVar10 + -1;
    iVar14 = iVar10;
  }
  puVar2 = key->data + 0x3f;
  pRVar5 = key;
  do {
    puVar3 = puVar2 + -1;
    *puVar2 = (uint)*(ushort *)((int)pRVar5->data + 0x7e);
    puVar2 = puVar3;
    pRVar5 = (RC2_KEY *)((int)pRVar5[-1].data + 0xfe);
  } while (puVar3 != key[-1].data + 0x3f);
  return;
}

