
char * BN_bn2hex(BIGNUM *a)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  pcVar3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(a->top * 8 + 2,"bn_print.c",0x4a);
  if (pcVar3 == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x69,0x41,"bn_print.c",0x4d);
  }
  else {
    pcVar6 = pcVar3;
    if (a->neg != 0) {
      *pcVar3 = '-';
      pcVar6 = pcVar3 + 1;
    }
    iVar9 = a->top;
    pcVar7 = pcVar6;
    if (iVar9 == 0) {
      pcVar7 = pcVar6 + 1;
      *pcVar6 = '0';
      iVar9 = a->top;
    }
    iVar9 = iVar9 + -1;
    iVar8 = iVar9 * 4;
    if (-1 < iVar9) {
      bVar2 = false;
      do {
        uVar4 = *(uint *)((int)a->d + iVar8);
        uVar5 = uVar4 >> 0x18;
        if ((bVar2) || (uVar5 != 0)) {
          cVar1 = "0123456789ABCDEF"[uVar5 & 0xf];
          *pcVar7 = "0123456789ABCDEF"[(int)uVar5 >> 4];
          pcVar7[1] = cVar1;
          uVar5 = (uint)*(ushort *)((int)a->d + iVar8);
          uVar10 = uVar5 & 0xff;
          pcVar7 = pcVar7 + 2;
LAB_004fa620:
          cVar1 = "0123456789ABCDEF"[uVar5 & 0xf];
          *pcVar7 = "0123456789ABCDEF"[(int)uVar10 >> 4];
          pcVar7[1] = cVar1;
          uVar5 = *(uint *)((int)a->d + iVar8) >> 8;
          uVar10 = uVar5 & 0xff;
          pcVar7 = pcVar7 + 2;
LAB_004fa658:
          cVar1 = "0123456789ABCDEF"[(int)uVar10 >> 4];
          pcVar7[1] = "0123456789ABCDEF"[uVar5 & 0xf];
          *pcVar7 = cVar1;
          uVar4 = *(uint *)((int)a->d + iVar8);
          uVar5 = uVar4 & 0xff;
          pcVar6 = pcVar7 + 2;
LAB_004fa68c:
          pcVar7 = pcVar6 + 2;
          bVar2 = true;
          cVar1 = "0123456789ABCDEF"[uVar4 & 0xf];
          *pcVar6 = "0123456789ABCDEF"[(int)uVar5 >> 4];
          pcVar6[1] = cVar1;
        }
        else {
          uVar5 = uVar4 >> 0x10;
          uVar10 = uVar5 & 0xff;
          if (uVar10 != 0) goto LAB_004fa620;
          uVar5 = uVar4 >> 8;
          uVar10 = uVar5 & 0xff;
          if (uVar10 != 0) goto LAB_004fa658;
          uVar5 = uVar4 & 0xff;
          pcVar6 = pcVar7;
          if (uVar5 != 0) goto LAB_004fa68c;
        }
        iVar9 = iVar9 + -1;
        iVar8 = iVar8 + -4;
      } while (iVar9 != -1);
    }
    *pcVar7 = '\0';
  }
  return pcVar3;
}

