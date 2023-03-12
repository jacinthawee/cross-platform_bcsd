
int i2c_ASN1_BIT_STRING(ASN1_BIT_STRING *a,uchar **pp)

{
  void *pvVar1;
  uchar *puVar2;
  int extraout_r1;
  int iVar3;
  byte *pbVar4;
  size_t __n;
  uint uVar5;
  int iVar6;
  
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  __n = a->length;
  if ((int)__n < 1) {
    iVar6 = __n + 1;
    uVar5 = 0;
  }
  else if (a->flags << 0x1c < 0) {
    uVar5 = a->flags & 7;
    iVar6 = __n + 1;
  }
  else {
    pbVar4 = a->data + __n;
    do {
      pbVar4 = pbVar4 + -1;
      uVar5 = (uint)*pbVar4;
      if (uVar5 != 0) {
        iVar6 = __n + 1;
        goto LAB_000b02de;
      }
      __n = __n - 1;
    } while (__n != 0);
    uVar5 = (uint)a->data[-1];
    iVar6 = 1;
LAB_000b02de:
    if ((int)(uVar5 << 0x1f) < 0) {
      uVar5 = 0;
    }
    else if ((int)(uVar5 << 0x1e) < 0) {
      uVar5 = 1;
    }
    else if ((int)(uVar5 << 0x1d) < 0) {
      uVar5 = 2;
    }
    else if ((int)(uVar5 << 0x1c) < 0) {
      uVar5 = 3;
    }
    else if ((int)(uVar5 << 0x1b) < 0) {
      uVar5 = 4;
    }
    else if ((int)(uVar5 << 0x1a) < 0) {
      uVar5 = 5;
    }
    else if ((int)(uVar5 << 0x19) < 0) {
      uVar5 = 6;
    }
    else if ((uVar5 & 0x80) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 7;
    }
  }
  if (pp != (uchar **)0x0) {
    puVar2 = *pp;
    *puVar2 = (uchar)uVar5;
    pvVar1 = memcpy(puVar2 + 1,a->data,__n);
    iVar3 = extraout_r1;
    if (0 < (int)__n) {
      iVar3 = 0xff;
    }
    puVar2 = (uchar *)((int)pvVar1 + __n);
    if (0 < (int)__n) {
      puVar2[-1] = (byte)(iVar3 << uVar5) & puVar2[-1];
    }
    *pp = puVar2;
  }
  return iVar6;
}

