
char * BN_bn2dec(BIGNUM *a)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  ulong *ptr;
  char *ptr_00;
  BIGNUM *a_00;
  ulong uVar4;
  ulong *puVar5;
  ulong *puVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  
  iVar3 = BN_num_bits(a);
  iVar3 = (iVar3 * 3) / 10 + (iVar3 * 3) / 1000;
  iVar8 = (iVar3 + 2) / 9 + 1;
  ptr = (ulong *)CRYPTO_malloc(iVar8 * 4,"bn_print.c",0x7d);
  ptr_00 = (char *)CRYPTO_malloc(iVar3 + 5,"bn_print.c",0x7e);
  bVar2 = ptr_00 == (char *)0x0 || ptr == (ulong *)0x0;
  pcVar9 = (char *)(uint)bVar2;
  if (ptr_00 == (char *)0x0 || ptr == (ulong *)0x0) {
    ERR_put_error(3,0x68,0x41,"bn_print.c",0x80);
    pcVar9 = ptr_00;
    if (ptr == (ulong *)0x0) {
      if (ptr_00 != (char *)0x0) {
        pcVar9 = (char *)0x1;
      }
    }
    else {
      if (ptr_00 != (char *)0x0) {
        pcVar9 = (char *)0x1;
      }
      CRYPTO_free(ptr);
    }
    goto LAB_0008a784;
  }
  a_00 = BN_dup(a);
  if (a_00 == (BIGNUM *)0x0) {
LAB_0008a7f2:
    pcVar9 = (char *)0x1;
  }
  else {
    if (a_00->top != 0) {
      pcVar7 = ptr_00;
      if (a_00->neg != 0) {
        *ptr_00 = '-';
        pcVar7 = ptr_00 + 1;
        if (a_00->top == 0) {
          uVar4 = ptr[-1];
          puVar6 = ptr;
LAB_0008a820:
          puVar6 = puVar6 + -1;
          BIO_snprintf(pcVar7,(size_t)(ptr_00 + ((iVar3 + 5) - (int)pcVar7)),"%u",uVar4);
          cVar1 = *pcVar7;
          while (cVar1 != '\0') {
            pcVar7 = pcVar7 + 1;
            cVar1 = *pcVar7;
          }
          while (ptr != puVar6) {
            puVar6 = puVar6 + -1;
            BIO_snprintf(pcVar7,(size_t)(ptr_00 + ((iVar3 + 5) - (int)pcVar7)),"%09u",*puVar6);
            cVar1 = *pcVar7;
            while (cVar1 != '\0') {
              pcVar7 = pcVar7 + 1;
              cVar1 = *pcVar7;
            }
          }
          goto LAB_0008a7aa;
        }
      }
      puVar5 = ptr;
      if (0 < iVar8) {
        do {
          uVar4 = BN_div_word(a_00,1000000000);
          puVar6 = puVar5 + 1;
          *puVar5 = uVar4;
          if (uVar4 == 0xffffffff) break;
          if (a_00->top == 0) goto LAB_0008a820;
          puVar5 = puVar6;
        } while ((int)puVar6 - (int)ptr >> 2 < iVar8);
      }
      goto LAB_0008a7f2;
    }
    ptr_00[1] = bVar2;
    *ptr_00 = '0';
  }
LAB_0008a7aa:
  CRYPTO_free(ptr);
  if (a_00 != (BIGNUM *)0x0) {
    BN_free(a_00);
  }
LAB_0008a784:
  pcVar7 = ptr_00;
  if (pcVar9 != (char *)0x0) {
    pcVar7 = (char *)0x0;
    CRYPTO_free(ptr_00);
  }
  return pcVar7;
}

