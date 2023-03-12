
void RC2_set_key(RC2_KEY *key,int len,uchar *data,int bits)

{
  undefined *puVar1;
  byte bVar2;
  byte bVar3;
  undefined uVar4;
  uchar uVar5;
  uint uVar6;
  int iVar7;
  RC2_KEY *pRVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  byte *pbVar13;
  byte *pbVar14;
  undefined *puVar15;
  byte *pbVar16;
  uint *puVar17;
  char cVar18;
  int iVar19;
  int iVar20;
  uchar *puVar21;
  uint *puVar22;
  int iVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  
  *(undefined *)key->data = 0;
  if (0x80 < len) {
    len = 0x80;
  }
  if (bits < 1) {
    uVar24 = 0xff;
    iVar23 = 0;
    iVar19 = -1;
    iVar20 = 0x80;
  }
  else if (bits < 0x401) {
    iVar20 = bits + 7 >> 3;
    iVar23 = 0x80 - iVar20;
    iVar19 = 0x7f - iVar20;
    uVar24 = 0xff >> (-bits & 7U);
  }
  else {
    uVar24 = 0xff;
    iVar23 = 0;
    iVar20 = 0x80;
    iVar19 = -1;
  }
  if (len < 1) {
    cVar18 = *(char *)((int)key->data + (len - 1U));
  }
  else {
    if (((uint)len < 10 || key < (RC2_KEY *)(data + 4) && data < key->data + 1) ||
       ((((uint)key | (uint)data) & 3) != 0)) {
      puVar21 = data + len;
      pRVar8 = key;
      do {
        uVar5 = *data;
        data = data + 1;
        *(uchar *)pRVar8->data = uVar5;
        pRVar8 = (RC2_KEY *)((int)pRVar8->data + 1);
      } while (data != puVar21);
    }
    else {
      uVar25 = 0;
      uVar6 = len - 4U & 0xfffffffc;
      uVar9 = uVar6 + 4;
      puVar17 = (uint *)data;
      puVar22 = key->data;
      do {
        uVar26 = *puVar17;
        uVar25 = uVar25 + 1;
        puVar17 = puVar17 + 1;
        *puVar22 = uVar26;
        puVar22 = puVar22 + 1;
      } while (uVar25 < (len - 4U >> 2) + 1);
      if (uVar9 != len) {
        iVar7 = uVar6 + 5;
        *(uchar *)((int)key->data + uVar9) = data[uVar9];
        if (iVar7 < len) {
          iVar10 = uVar6 + 6;
          *(uchar *)((int)key->data + iVar7) = data[iVar7];
          if (iVar10 < len) {
            *(uchar *)((int)key->data + iVar10) = data[iVar10];
          }
        }
      }
    }
    cVar18 = *(char *)((int)key->data + (len - 1U));
    if (len == 0x80) goto LAB_004e3f78;
  }
  pcVar11 = (char *)((int)key->data + len);
  pRVar8 = key;
  do {
    puVar17 = pRVar8->data;
    pcVar12 = pcVar11 + 1;
    pRVar8 = (RC2_KEY *)((int)pRVar8->data + 1);
    cVar18 = key_table[(byte)(*(char *)puVar17 + cVar18)];
    *pcVar11 = cVar18;
    pcVar11 = pcVar12;
  } while ((uint *)pcVar12 != key->data + 0x20);
LAB_004e3f78:
  pbVar13 = (byte *)((int)key->data + iVar23);
  bVar2 = key_table[*pbVar13 & uVar24];
  *pbVar13 = bVar2;
  if (iVar23 != 0) {
    pbVar16 = (byte *)((int)key->data + iVar19 + iVar20);
    pbVar13 = (byte *)((int)key->data + iVar19);
    do {
      bVar3 = *pbVar16;
      pbVar14 = pbVar13 + -1;
      pbVar16 = pbVar16 + -1;
      bVar2 = key_table[bVar3 ^ bVar2];
      *pbVar13 = bVar2;
      pbVar13 = pbVar14;
    } while (pbVar14 != (byte *)((int)key[-1].data + 0xff));
  }
  puVar15 = (undefined *)((int)key->data + 0x7f);
  puVar17 = key->data + 0x3f;
  do {
    uVar4 = *puVar15;
    puVar22 = puVar17 + -1;
    puVar1 = puVar15 + -1;
    puVar15 = puVar15 + -2;
    *puVar17 = (uint)CONCAT11(uVar4,*puVar1);
    puVar17 = puVar22;
  } while (puVar22 != key[-1].data + 0x3f);
  return;
}

