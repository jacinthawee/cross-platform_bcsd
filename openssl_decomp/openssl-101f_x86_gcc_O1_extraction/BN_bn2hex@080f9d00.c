
char * BN_bn2hex(BIGNUM *a)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  int local_2c;
  uint local_28;
  
  pcVar2 = (char *)CRYPTO_malloc(a->top * 8 + 2,"bn_print.c",0x4a);
  if (pcVar2 == (char *)0x0) {
    ERR_put_error(3,0x69,0x41,"bn_print.c",0x4d);
  }
  else {
    pcVar3 = pcVar2;
    if (a->neg != 0) {
      pcVar3 = pcVar2 + 1;
      *pcVar2 = '-';
    }
    local_2c = a->top;
    if (local_2c == 0) {
      *pcVar3 = '0';
      pcVar3 = pcVar3 + 1;
      local_2c = a->top;
    }
    local_2c = local_2c + -1;
    if (-1 < local_2c) {
      iVar8 = local_2c * 4;
      uVar5 = 0;
      do {
        uVar6 = *(uint *)((int)a->d + iVar8);
        uVar7 = uVar6 >> 0x18;
        bVar9 = (uVar5 | uVar7) != 0;
        pcVar4 = pcVar3;
        if (bVar9) {
          pcVar4 = pcVar3 + 2;
          *pcVar3 = "0123456789ABCDEF"[(int)uVar7 >> 4];
          pcVar3[1] = "0123456789ABCDEF"[uVar7 & 0xf];
          uVar6 = *(uint *)((int)a->d + iVar8);
        }
        uVar5 = uVar6 >> 0x10 & 0xff;
        bVar9 = (bVar9 | uVar5) != 0;
        pcVar3 = pcVar4;
        if (bVar9) {
          pcVar3 = pcVar4 + 2;
          *pcVar4 = "0123456789ABCDEF"[(int)uVar5 >> 4];
          pcVar4[1] = "0123456789ABCDEF"[uVar6 >> 0x10 & 0xf];
          uVar6 = *(uint *)((int)a->d + iVar8);
        }
        local_28 = (uint)bVar9;
        uVar5 = uVar6 >> 8 & 0xff;
        bVar9 = (local_28 | uVar5) != 0;
        pcVar4 = pcVar3;
        if (bVar9) {
          pcVar4 = pcVar3 + 2;
          *pcVar3 = "0123456789ABCDEF"[(int)uVar5 >> 4];
          pcVar3[1] = "0123456789ABCDEF"[uVar6 >> 8 & 0xf];
          uVar6 = *(uint *)((int)a->d + iVar8);
        }
        bVar9 = ((uint)bVar9 | uVar6 & 0xff) != 0;
        pcVar3 = pcVar4;
        if (bVar9) {
          pcVar3 = pcVar4 + 2;
          cVar1 = "0123456789ABCDEF"[uVar6 & 0xf];
          *pcVar4 = "0123456789ABCDEF"[(int)(uVar6 & 0xff) >> 4];
          pcVar4[1] = cVar1;
        }
        uVar5 = (uint)bVar9;
        local_2c = local_2c + -1;
        iVar8 = iVar8 + -4;
      } while (local_2c != -1);
    }
    *pcVar3 = '\0';
  }
  return pcVar2;
}

