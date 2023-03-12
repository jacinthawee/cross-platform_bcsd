
char * BN_bn2dec(BIGNUM *a)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  ulong *ptr;
  char *ptr_00;
  BIGNUM *a_00;
  ulong uVar4;
  char *pcVar5;
  ulong *puVar6;
  ulong *puVar7;
  char *pcVar8;
  char *pcVar9;
  
  iVar3 = BN_num_bits(a);
  iVar3 = (iVar3 * 3) / 10 + (iVar3 * 3) / 1000;
  ptr = (ulong *)CRYPTO_malloc(((iVar3 + 2) / 9 + 1) * 4,"bn_print.c",0x76);
  ptr_00 = (char *)CRYPTO_malloc(iVar3 + 5,"bn_print.c",0x77);
  bVar2 = ptr_00 == (char *)0x0 || ptr == (ulong *)0x0;
  pcVar8 = (char *)(uint)bVar2;
  if (ptr_00 == (char *)0x0 || ptr == (ulong *)0x0) {
    ERR_put_error(3,0x68,0x41,"bn_print.c",0x7a);
    pcVar8 = ptr_00;
    if (ptr == (ulong *)0x0) {
      if (ptr_00 != (char *)0x0) {
        pcVar8 = (char *)0x1;
      }
    }
    else {
      if (ptr_00 != (char *)0x0) {
        pcVar8 = (char *)0x1;
      }
      CRYPTO_free(ptr);
    }
    goto LAB_0008c474;
  }
  a_00 = BN_dup(a);
  if (a_00 == (BIGNUM *)0x0) {
    pcVar8 = (char *)0x1;
  }
  else if (a_00->top == 0) {
    ptr_00[1] = bVar2;
    *ptr_00 = '0';
  }
  else {
    puVar6 = ptr;
    pcVar9 = pcVar8;
    pcVar5 = ptr_00;
    if (a_00->neg == 0) {
LAB_0008c4d6:
      do {
        uVar4 = BN_div_word(a_00,1000000000);
        *puVar6 = uVar4;
        puVar7 = puVar6 + 1;
        puVar6 = puVar6 + 1;
      } while (a_00->top != 0);
    }
    else {
      *ptr_00 = '-';
      pcVar5 = ptr_00 + 1;
      pcVar9 = ptr_00 + -(int)pcVar5;
      if (a_00->top != 0) goto LAB_0008c4d6;
      uVar4 = ptr[-1];
      puVar7 = ptr;
    }
    BIO_snprintf(pcVar5,(size_t)(pcVar9 + iVar3 + 5),"%u",uVar4);
    puVar7 = puVar7 + -1;
    cVar1 = *pcVar5;
    while (cVar1 != '\0') {
      pcVar5 = pcVar5 + 1;
      cVar1 = *pcVar5;
    }
    while (ptr != puVar7) {
      puVar7 = puVar7 + -1;
      BIO_snprintf(pcVar5,(size_t)(ptr_00 + ((iVar3 + 5) - (int)pcVar5)),"%09u",*puVar7);
      cVar1 = *pcVar5;
      while (cVar1 != '\0') {
        pcVar5 = pcVar5 + 1;
        cVar1 = *pcVar5;
      }
    }
  }
  CRYPTO_free(ptr);
  if (a_00 != (BIGNUM *)0x0) {
    BN_free(a_00);
  }
LAB_0008c474:
  pcVar5 = ptr_00;
  if (pcVar8 != (char *)0x0) {
    pcVar5 = (char *)0x0;
    CRYPTO_free(ptr_00);
  }
  return pcVar5;
}

