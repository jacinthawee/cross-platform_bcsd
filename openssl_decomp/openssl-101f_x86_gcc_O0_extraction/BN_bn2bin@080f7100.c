
int BN_bn2bin(BIGNUM *a,uchar *to)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulong *puVar4;
  int local_14;
  
  local_14 = 0;
  if (a->top != 0) {
    puVar4 = a->d;
    iVar1 = a->top + -1;
    uVar2 = puVar4[iVar1];
    if ((uVar2 & 0xffff0000) == 0) {
      if ((char)(uVar2 >> 8) == '\0') {
        uVar2 = (uint)(byte)bits_6052[uVar2];
      }
      else {
        uVar2 = (byte)bits_6052[uVar2 >> 8] + 8;
      }
    }
    else if ((uVar2 & 0xff000000) == 0) {
      uVar2 = (byte)bits_6052[uVar2 >> 0x10] + 0x10;
    }
    else {
      uVar2 = (byte)bits_6052[uVar2 >> 0x18] + 0x18;
    }
    iVar1 = uVar2 + iVar1 * 0x20;
    local_14 = iVar1 + 7;
    if (local_14 < 0) {
      local_14 = iVar1 + 0xe;
    }
    local_14 = local_14 >> 3;
    iVar1 = local_14 + -1;
    if (local_14 != 0) {
      while( true ) {
        iVar3 = iVar1 + 3;
        if (-1 < iVar1) {
          iVar3 = iVar1;
        }
        *to = (uchar)(puVar4[iVar3 >> 2] >> ((byte)(iVar1 % 4 << 3) & 0x1f));
        if (iVar1 + -1 == -1) break;
        puVar4 = a->d;
        iVar1 = iVar1 + -1;
        to = to + 1;
      }
    }
  }
  return local_14;
}

