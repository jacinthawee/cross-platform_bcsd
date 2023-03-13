
char * BN_bn2dec(BIGNUM *a)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  ulong *puVar4;
  char *pcVar5;
  BIGNUM *a_00;
  ulong uVar6;
  char *pcVar7;
  int iVar8;
  ulong *puVar9;
  ulong *puVar10;
  
  iVar3 = BN_num_bits(a);
  iVar3 = (iVar3 * 3) / 10 + (iVar3 * 3) / 1000;
  iVar8 = (iVar3 + 2) / 9 + 1;
  puVar4 = (ulong *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar8 * 4,"bn_print.c",0x7d);
  pcVar5 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3 + 5,"bn_print.c",0x7e);
  if (pcVar5 == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x68,0x41,"bn_print.c",0x80);
    if (puVar4 == (ulong *)0x0) {
      return (char *)0x0;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
    return (char *)0x0;
  }
  if (puVar4 == (ulong *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x68,0x41,"bn_print.c",0x80);
    if (pcVar5 == (char *)0x0) {
      return (char *)0x0;
    }
    goto LAB_004f8004;
  }
  a_00 = BN_dup(a);
  if (a_00 == (BIGNUM *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
    if (pcVar5 == (char *)0x0) {
      return (char *)0x0;
    }
    goto LAB_004f8004;
  }
  if (a_00->top == 0) {
    pcVar5[1] = '\0';
    bVar1 = true;
    *pcVar5 = '0';
  }
  else {
    pcVar7 = pcVar5;
    if (a_00->neg != 0) {
      *pcVar5 = '-';
      pcVar7 = pcVar5 + 1;
      if (a_00->top == 0) {
        uVar6 = puVar4[-1];
        puVar10 = puVar4;
LAB_004f8054:
        (*(code *)PTR_BIO_snprintf_006a6f60)
                  (pcVar7,(iVar3 + 5) - ((int)pcVar7 - (int)pcVar5),&DAT_006621e8,uVar6);
        cVar2 = *pcVar7;
        while (cVar2 != '\0') {
          pcVar7 = pcVar7 + 1;
          cVar2 = *pcVar7;
        }
        if (puVar4 != puVar10 + -1) {
          puVar10 = puVar10 + -2;
          do {
            (*(code *)PTR_BIO_snprintf_006a6f60)
                      (pcVar7,(iVar3 + 5) - ((int)pcVar7 - (int)pcVar5),&DAT_006621ec,*puVar10);
            cVar2 = *pcVar7;
            while (cVar2 != '\0') {
              pcVar7 = pcVar7 + 1;
              cVar2 = *pcVar7;
            }
            bVar1 = puVar4 != puVar10;
            puVar10 = puVar10 + -1;
          } while (bVar1);
        }
        bVar1 = true;
        goto LAB_004f7f08;
      }
    }
    puVar9 = puVar4;
    if (0 < iVar8) {
      do {
        puVar10 = puVar9 + 1;
        uVar6 = BN_div_word(a_00,1000000000);
        *puVar9 = uVar6;
        if (uVar6 == 0xffffffff) break;
        if (a_00->top == 0) goto LAB_004f8054;
        puVar9 = puVar10;
      } while ((int)puVar10 - (int)puVar4 >> 2 < iVar8);
    }
    bVar1 = false;
  }
LAB_004f7f08:
  (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
  BN_free(a_00);
  if (bVar1) {
    return pcVar5;
  }
LAB_004f8004:
  (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar5);
  return (char *)0x0;
}

