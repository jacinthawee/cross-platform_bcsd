
char * BN_bn2dec(BIGNUM *a)

{
  int iVar1;
  char cVar2;
  int iVar3;
  ulong *ptr;
  char *ptr_00;
  BIGNUM *a_00;
  ulong uVar4;
  ulong *puVar5;
  char *buf;
  bool bVar6;
  
  iVar3 = BN_num_bits(a);
  iVar1 = (iVar3 * 3) / 10 + (iVar3 * 3) / 1000;
  iVar3 = (iVar1 + 2) / 9 + 1;
  ptr = (ulong *)CRYPTO_malloc(iVar3 * 4,"bn_print.c",0x7d);
  ptr_00 = (char *)CRYPTO_malloc(iVar1 + 5,"bn_print.c",0x7e);
  bVar6 = ptr_00 == (char *)0x0 || ptr == (ulong *)0x0;
  if (ptr_00 == (char *)0x0 || ptr == (ulong *)0x0) {
    ERR_put_error(3,0x68,0x41,"bn_print.c",0x80);
    if (ptr == (ulong *)0x0) {
      bVar6 = ptr_00 != (char *)0x0;
    }
    else {
      CRYPTO_free(ptr);
      bVar6 = ptr_00 != (char *)0x0;
    }
  }
  else {
    a_00 = BN_dup(a);
    if (a_00 == (BIGNUM *)0x0) {
      CRYPTO_free(ptr);
      goto LAB_080f8049;
    }
    if (a_00->top == 0) {
      *ptr_00 = '0';
      ptr_00[1] = '\0';
    }
    else {
      buf = ptr_00;
      puVar5 = ptr;
      if (a_00->neg != 0) {
        buf = ptr_00 + 1;
        *ptr_00 = '-';
        if (a_00->top == 0) {
          uVar4 = ptr[-1];
LAB_080f7fb4:
          puVar5 = puVar5 + -1;
          BIO_snprintf(buf,(iVar1 + 5) - ((int)buf - (int)ptr_00),"%u",uVar4);
          cVar2 = *buf;
          while (cVar2 != '\0') {
            buf = buf + 1;
            cVar2 = *buf;
          }
          while (ptr != puVar5) {
            puVar5 = puVar5 + -1;
            BIO_snprintf(buf,(iVar1 + 5) - ((int)buf - (int)ptr_00),"%09u",*puVar5);
            cVar2 = *buf;
            while (cVar2 != '\0') {
              buf = buf + 1;
              cVar2 = *buf;
            }
          }
          goto LAB_080f7ee7;
        }
      }
      if (0 < iVar3) {
        do {
          uVar4 = BN_div_word(a_00,1000000000);
          *puVar5 = uVar4;
          if (uVar4 == 0xffffffff) break;
          puVar5 = puVar5 + 1;
          if (a_00->top == 0) goto LAB_080f7fb4;
        } while ((int)puVar5 - (int)ptr >> 2 < iVar3);
      }
      bVar6 = true;
    }
LAB_080f7ee7:
    CRYPTO_free(ptr);
    BN_free(a_00);
  }
  if (!bVar6) {
    return ptr_00;
  }
LAB_080f8049:
  CRYPTO_free(ptr_00);
  return (char *)0x0;
}

