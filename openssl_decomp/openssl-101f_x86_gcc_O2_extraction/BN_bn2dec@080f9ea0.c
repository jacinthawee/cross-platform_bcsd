
char * BN_bn2dec(BIGNUM *a)

{
  char cVar1;
  int iVar2;
  ulong *ptr;
  char *ptr_00;
  BIGNUM *a_00;
  ulong uVar3;
  ulong *puVar4;
  ulong *puVar5;
  char *buf;
  int local_20;
  
  iVar2 = BN_num_bits(a);
  iVar2 = (iVar2 * 3) / 10 + (iVar2 * 3) / 1000;
  ptr = (ulong *)CRYPTO_malloc(((iVar2 + 2) / 9) * 4 + 4,"bn_print.c",0x76);
  ptr_00 = (char *)CRYPTO_malloc(iVar2 + 5,"bn_print.c",0x77);
  if ((ptr_00 == (char *)0x0) || (ptr == (ulong *)0x0)) {
    ERR_put_error(3,0x68,0x41,"bn_print.c",0x7a);
    if (ptr != (ulong *)0x0) {
      CRYPTO_free(ptr);
    }
    if (ptr_00 == (char *)0x0) {
      return (char *)0x0;
    }
LAB_080fa0c4:
    CRYPTO_free(ptr_00);
    return (char *)0x0;
  }
  a_00 = BN_dup(a);
  if (a_00 == (BIGNUM *)0x0) {
    CRYPTO_free(ptr);
    goto LAB_080fa0c4;
  }
  if (a_00->top == 0) {
    *ptr_00 = '0';
    ptr_00[1] = '\0';
    goto LAB_080f9f54;
  }
  puVar4 = ptr;
  if (a_00->neg == 0) {
    local_20 = 0;
    buf = ptr_00;
LAB_080f9fe0:
    do {
      uVar3 = BN_div_word(a_00,1000000000);
      *puVar4 = uVar3;
      puVar5 = puVar4 + 1;
      puVar4 = puVar4 + 1;
    } while (a_00->top != 0);
  }
  else {
    *ptr_00 = '-';
    buf = ptr_00 + 1;
    local_20 = 1;
    if (a_00->top != 0) goto LAB_080f9fe0;
    uVar3 = ptr[-1];
    puVar5 = ptr;
  }
  puVar5 = puVar5 + -1;
  BIO_snprintf(buf,(iVar2 + 5) - local_20,"%u",uVar3);
  cVar1 = *buf;
  while (cVar1 != '\0') {
    buf = buf + 1;
    cVar1 = *buf;
  }
  while (ptr != puVar5) {
    puVar5 = puVar5 + -1;
    BIO_snprintf(buf,(iVar2 + 5) - ((int)buf - (int)ptr_00),"%09u",*puVar5);
    cVar1 = *buf;
    while (cVar1 != '\0') {
      buf = buf + 1;
      cVar1 = *buf;
    }
  }
LAB_080f9f54:
  CRYPTO_free(ptr);
  BN_free(a_00);
  return ptr_00;
}

