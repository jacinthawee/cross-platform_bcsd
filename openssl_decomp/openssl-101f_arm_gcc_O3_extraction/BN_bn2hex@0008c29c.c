
char * BN_bn2hex(BIGNUM *a)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  
  pcVar2 = (char *)CRYPTO_malloc(a->top * 8 + 2,"bn_print.c",0x4a);
  if (pcVar2 == (char *)0x0) {
    ERR_put_error(3,0x69,0x41,"bn_print.c",0x4d);
  }
  else {
    pcVar5 = pcVar2;
    if (a->neg != 0) {
      pcVar5 = pcVar2 + 1;
      *pcVar2 = '-';
    }
    iVar3 = a->top;
    if (iVar3 == 0) {
      *pcVar5 = '0';
      iVar3 = a->top;
      pcVar5 = pcVar5 + 1;
    }
    iVar3 = iVar3 + -1;
    if (-1 < iVar3) {
      iVar4 = iVar3 * 4;
      uVar9 = 0;
      do {
        uVar6 = *(uint *)((int)a->d + iVar4);
        uVar9 = uVar9 | uVar6 >> 0x18;
        pcVar7 = pcVar5;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[uVar6 >> 0x18 & 0xf];
          pcVar7 = pcVar5 + 2;
          *pcVar5 = "0123456789ABCDEF"[(int)(uVar6 >> 0x18) >> 4];
          pcVar5[1] = cVar1;
          uVar6 = *(uint *)((int)a->d + iVar4);
        }
        uVar8 = uVar6 >> 0x10 & 0xff;
        uVar9 = uVar8 | uVar9;
        pcVar5 = pcVar7;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[uVar6 >> 0x10 & 0xf];
          pcVar5 = pcVar7 + 2;
          *pcVar7 = "0123456789ABCDEF"[(int)uVar8 >> 4];
          pcVar7[1] = cVar1;
          uVar6 = *(uint *)((int)a->d + iVar4);
        }
        uVar8 = uVar6 >> 8 & 0xff;
        uVar9 = uVar8 | uVar9;
        pcVar7 = pcVar5;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[uVar6 >> 8 & 0xf];
          pcVar7 = pcVar5 + 2;
          *pcVar5 = "0123456789ABCDEF"[(int)uVar8 >> 4];
          pcVar5[1] = cVar1;
          uVar6 = *(uint *)((int)a->d + iVar4);
        }
        uVar9 = uVar6 & 0xff | uVar9;
        pcVar5 = pcVar7;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[uVar6 & 0xf];
          pcVar5 = pcVar7 + 2;
          *pcVar7 = "0123456789ABCDEF"[(int)(uVar6 & 0xff) >> 4];
          pcVar7[1] = cVar1;
        }
        iVar3 = iVar3 + -1;
        iVar4 = iVar4 + -4;
      } while (iVar3 != -1);
    }
    *pcVar5 = '\0';
  }
  return pcVar2;
}

