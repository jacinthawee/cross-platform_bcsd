
char * BN_bn2hex(BIGNUM *a)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  
  if (a->neg == 0) {
    iVar5 = a->top;
  }
  else {
    iVar5 = a->top;
    if (iVar5 == 0) {
      pcVar2 = (char *)CRYPTO_malloc(3,"bn_print.c",0x4d);
      goto LAB_0008a5b0;
    }
  }
  pcVar2 = (char *)CRYPTO_malloc(iVar5 * 8 + 2,"bn_print.c",0x4f);
LAB_0008a5b0:
  if (pcVar2 == (char *)0x0) {
    ERR_put_error(3,0x69,0x41,"bn_print.c",0x52);
  }
  else {
    pcVar4 = pcVar2;
    if (a->neg != 0) {
      pcVar4 = pcVar2 + 1;
      *pcVar2 = '-';
    }
    iVar5 = a->top;
    if (iVar5 == 0) {
      *pcVar4 = '0';
      iVar5 = a->top;
      pcVar4 = pcVar4 + 1;
    }
    iVar5 = iVar5 + -1;
    if (-1 < iVar5) {
      iVar3 = iVar5 * 4;
      uVar9 = 0;
      do {
        uVar6 = *(uint *)((int)a->d + iVar3);
        uVar9 = uVar9 | uVar6 >> 0x18;
        pcVar7 = pcVar4;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[uVar6 >> 0x18 & 0xf];
          pcVar7 = pcVar4 + 2;
          *pcVar4 = "0123456789ABCDEF"[(int)(uVar6 >> 0x18) >> 4];
          pcVar4[1] = cVar1;
          uVar6 = *(uint *)((int)a->d + iVar3);
        }
        uVar8 = uVar6 >> 0x10 & 0xff;
        uVar9 = uVar8 | uVar9;
        pcVar4 = pcVar7;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[uVar6 >> 0x10 & 0xf];
          pcVar4 = pcVar7 + 2;
          *pcVar7 = "0123456789ABCDEF"[(int)uVar8 >> 4];
          pcVar7[1] = cVar1;
          uVar6 = *(uint *)((int)a->d + iVar3);
        }
        uVar8 = uVar6 >> 8 & 0xff;
        uVar9 = uVar8 | uVar9;
        pcVar7 = pcVar4;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[uVar6 >> 8 & 0xf];
          pcVar7 = pcVar4 + 2;
          *pcVar4 = "0123456789ABCDEF"[(int)uVar8 >> 4];
          pcVar4[1] = cVar1;
          uVar6 = *(uint *)((int)a->d + iVar3);
        }
        uVar9 = uVar6 & 0xff | uVar9;
        pcVar4 = pcVar7;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[uVar6 & 0xf];
          pcVar4 = pcVar7 + 2;
          *pcVar7 = "0123456789ABCDEF"[(int)(uVar6 & 0xff) >> 4];
          pcVar7[1] = cVar1;
        }
        iVar5 = iVar5 + -1;
        iVar3 = iVar3 + -4;
      } while (iVar5 != -1);
    }
    *pcVar4 = '\0';
  }
  return pcVar2;
}

