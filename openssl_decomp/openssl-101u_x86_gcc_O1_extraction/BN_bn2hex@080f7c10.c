
char * BN_bn2hex(BIGNUM *a)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  int local_2c;
  uint local_28;
  char *local_20;
  
  if ((a->neg == 0) || (a->top != 0)) {
    local_20 = (char *)CRYPTO_malloc(a->top * 8 + 2,"bn_print.c",0x4f);
  }
  else {
    local_20 = (char *)CRYPTO_malloc(3,"bn_print.c",0x4d);
  }
  if (local_20 == (char *)0x0) {
    ERR_put_error(3,0x69,0x41,"bn_print.c",0x52);
  }
  else {
    pcVar2 = local_20;
    if (a->neg != 0) {
      pcVar2 = local_20 + 1;
      *local_20 = '-';
    }
    local_2c = a->top;
    if (local_2c == 0) {
      *pcVar2 = '0';
      pcVar2 = pcVar2 + 1;
      local_2c = a->top;
    }
    local_2c = local_2c + -1;
    if (-1 < local_2c) {
      iVar7 = local_2c * 4;
      uVar4 = 0;
      do {
        uVar5 = *(uint *)((int)a->d + iVar7);
        uVar6 = uVar5 >> 0x18;
        bVar8 = (uVar4 | uVar6) != 0;
        pcVar3 = pcVar2;
        if (bVar8) {
          pcVar3 = pcVar2 + 2;
          *pcVar2 = "0123456789ABCDEF"[(int)uVar6 >> 4];
          pcVar2[1] = "0123456789ABCDEF"[uVar6 & 0xf];
          uVar5 = *(uint *)((int)a->d + iVar7);
        }
        uVar4 = uVar5 >> 0x10 & 0xff;
        bVar8 = (bVar8 | uVar4) != 0;
        pcVar2 = pcVar3;
        if (bVar8) {
          pcVar2 = pcVar3 + 2;
          *pcVar3 = "0123456789ABCDEF"[(int)uVar4 >> 4];
          pcVar3[1] = "0123456789ABCDEF"[uVar5 >> 0x10 & 0xf];
          uVar5 = *(uint *)((int)a->d + iVar7);
        }
        local_28 = (uint)bVar8;
        uVar4 = uVar5 >> 8 & 0xff;
        bVar8 = (local_28 | uVar4) != 0;
        pcVar3 = pcVar2;
        if (bVar8) {
          pcVar3 = pcVar2 + 2;
          *pcVar2 = "0123456789ABCDEF"[(int)uVar4 >> 4];
          pcVar2[1] = "0123456789ABCDEF"[uVar5 >> 8 & 0xf];
          uVar5 = *(uint *)((int)a->d + iVar7);
        }
        bVar8 = ((uint)bVar8 | uVar5 & 0xff) != 0;
        pcVar2 = pcVar3;
        if (bVar8) {
          pcVar2 = pcVar3 + 2;
          cVar1 = "0123456789ABCDEF"[uVar5 & 0xf];
          *pcVar3 = "0123456789ABCDEF"[(int)(uVar5 & 0xff) >> 4];
          pcVar3[1] = cVar1;
        }
        uVar4 = (uint)bVar8;
        local_2c = local_2c + -1;
        iVar7 = iVar7 + -4;
      } while (local_2c != -1);
    }
    *pcVar2 = '\0';
  }
  return local_20;
}

