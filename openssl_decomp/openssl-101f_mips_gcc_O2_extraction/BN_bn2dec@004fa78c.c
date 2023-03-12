
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
  ulong *puVar8;
  ulong *puVar9;
  int iVar10;
  
  iVar3 = BN_num_bits(a);
  iVar3 = (iVar3 * 3) / 10 + (iVar3 * 3) / 1000;
  puVar4 = (ulong *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                              (((iVar3 + 2) / 9 + 1) * 4,"bn_print.c",0x76);
  pcVar5 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3 + 5,"bn_print.c",0x77);
  if (pcVar5 == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x68,0x41,"bn_print.c",0x7a);
    if (puVar4 == (ulong *)0x0) {
      return (char *)0x0;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar4);
    return (char *)0x0;
  }
  if (puVar4 == (ulong *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x68,0x41,"bn_print.c",0x7a);
joined_r0x004fa9f8:
    if (pcVar5 == (char *)0x0) {
      return (char *)0x0;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar5);
    return (char *)0x0;
  }
  a_00 = BN_dup(a);
  if (a_00 == (BIGNUM *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar4);
    goto joined_r0x004fa9f8;
  }
  if (a_00->top == 0) {
    pcVar5[1] = '\0';
    *pcVar5 = '0';
    goto LAB_004fa8a8;
  }
  puVar8 = puVar4;
  if (a_00->neg == 0) {
    iVar10 = 0;
    pcVar7 = pcVar5;
LAB_004fa914:
    do {
      uVar6 = BN_div_word(a_00,1000000000);
      *puVar8 = uVar6;
      puVar9 = puVar8 + 1;
      puVar8 = puVar8 + 1;
    } while (a_00->top != 0);
  }
  else {
    *pcVar5 = '-';
    pcVar7 = pcVar5 + 1;
    if (a_00->top != 0) {
      iVar10 = 1;
      goto LAB_004fa914;
    }
    uVar6 = puVar4[-1];
    iVar10 = 1;
    puVar9 = puVar4;
  }
  (*(code *)PTR_BIO_snprintf_006a8060)(pcVar7,(iVar3 + 5) - iVar10,&DAT_00662b88,uVar6);
  cVar2 = *pcVar7;
  while (cVar2 != '\0') {
    pcVar7 = pcVar7 + 1;
    cVar2 = *pcVar7;
  }
  if (puVar4 != puVar9 + -1) {
    puVar9 = puVar9 + -2;
    do {
      (*(code *)PTR_BIO_snprintf_006a8060)
                (pcVar7,(iVar3 + 5) - ((int)pcVar7 - (int)pcVar5),&DAT_00662b8c,*puVar9);
      cVar2 = *pcVar7;
      while (cVar2 != '\0') {
        pcVar7 = pcVar7 + 1;
        cVar2 = *pcVar7;
      }
      bVar1 = puVar4 != puVar9;
      puVar9 = puVar9 + -1;
    } while (bVar1);
  }
LAB_004fa8a8:
  (*(code *)PTR_CRYPTO_free_006a7f88)(puVar4);
  BN_free(a_00);
  return pcVar5;
}

