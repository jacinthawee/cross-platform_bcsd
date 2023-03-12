
void RC2_set_key(RC2_KEY *key,int len,uchar *data,int bits)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  int local_24;
  int local_20;
  uint local_18;
  int local_14;
  
  if (0x80 < len) {
    len = 0x80;
  }
  *(undefined *)key->data = 0;
  if (bits < 1) {
    local_14 = 0;
    local_18 = 0xff;
    local_24 = -1;
    local_20 = 0x80;
  }
  else if (bits < 0x401) {
    local_20 = bits + 7 >> 3;
    local_14 = 0x80 - local_20;
    local_24 = 0x7f - local_20;
    local_18 = 0xff >> (-(char)bits & 7U);
  }
  else {
    local_14 = 0;
    local_18 = 0xff;
    local_20 = 0x80;
    local_24 = -1;
  }
  if (len < 1) {
    cVar3 = *(char *)((int)key->data + (len - 1U));
  }
  else {
    if (((uint)len < 10 || key < (RC2_KEY *)(data + 4) && data < key->data + 1) ||
       ((((uint)key | (uint)data) & 3) != 0)) {
      uVar7 = 0;
      do {
        *(uchar *)((int)key->data + uVar7) = data[uVar7];
        uVar7 = uVar7 + 1;
      } while (len != uVar7);
    }
    else {
      uVar7 = len - 4;
      uVar8 = 0;
      uVar4 = (uVar7 >> 2) + 1;
      uVar2 = uVar7 & 0xfffffffc;
      do {
        key->data[uVar8] = *(uint *)(data + uVar8 * 4);
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar4);
      if (((uVar2 + 4 != len) &&
          (*(uchar *)((int)key->data + (uVar7 & 0xfffffffc) + 4) = data[uVar4 * 4],
          (int)(uVar2 + 5) < len)) &&
         (*(uchar *)((int)key->data + uVar2 + 5) = data[uVar2 + 5], (int)(uVar2 + 6) < len)) {
        *(uchar *)((int)key->data + uVar2 + 6) = data[uVar2 + 6];
      }
    }
    cVar3 = *(char *)((int)key->data + (len - 1U));
    if (len == 0x80) goto LAB_080e99c2;
  }
  pcVar9 = (char *)((int)key->data + len);
  do {
    pcVar10 = pcVar9 + 1;
    cVar3 = key_table[(byte)(cVar3 + pcVar9[-len])];
    *pcVar9 = cVar3;
    pcVar9 = pcVar10;
  } while ((uint *)pcVar10 != key->data + 0x20);
LAB_080e99c2:
  pbVar5 = (byte *)((int)key->data + local_14);
  bVar1 = key_table[*pbVar5 & local_18];
  *pbVar5 = bVar1;
  if (local_14 != 0) {
    do {
      bVar1 = key_table[bVar1 ^ *(byte *)((int)key->data + local_24 + local_20)];
      *(byte *)((int)key->data + local_24) = bVar1;
      local_24 = local_24 + -1;
    } while (local_24 != -1);
  }
  iVar6 = 0x7f;
  do {
    *(uint *)((int)key->data + iVar6 * 2 + -2) =
         (uint)CONCAT11(*(undefined *)((int)key->data + iVar6),
                        *(undefined *)((int)key->data + iVar6 + -1));
    iVar6 = iVar6 + -2;
  } while (iVar6 != -1);
  return;
}

