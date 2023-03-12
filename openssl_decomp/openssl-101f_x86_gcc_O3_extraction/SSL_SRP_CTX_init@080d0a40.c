
undefined4 SSL_SRP_CTX_init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  BIGNUM *pBVar3;
  char *pcVar4;
  
  if ((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0xe4), iVar1 == 0)) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(iVar1 + 0x164);
  *(undefined4 *)(param_1 + 0x198) = *(undefined4 *)(iVar1 + 0x168);
  *(undefined4 *)(param_1 + 0x19c) = *(undefined4 *)(iVar1 + 0x16c);
  uVar2 = *(undefined4 *)(iVar1 + 0x170);
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = uVar2;
  uVar2 = *(undefined4 *)(iVar1 + 0x198);
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = uVar2;
  uVar2 = *(undefined4 *)(iVar1 + 0x19c);
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = uVar2;
  if (*(BIGNUM **)(iVar1 + 0x178) != (BIGNUM *)0x0) {
    pBVar3 = BN_dup(*(BIGNUM **)(iVar1 + 0x178));
    *(BIGNUM **)(param_1 + 0x1a8) = pBVar3;
    if (pBVar3 != (BIGNUM *)0x0) goto LAB_080d0b25;
LAB_080d0c50:
    ERR_put_error(0x14,0x139,3,"tls_srp.c",0xad);
LAB_080d0c6e:
    CRYPTO_free(*(void **)(param_1 + 0x1a4));
    BN_free(*(BIGNUM **)(param_1 + 0x1a8));
    BN_free(*(BIGNUM **)(param_1 + 0x1ac));
    BN_free(*(BIGNUM **)(param_1 + 0x1b0));
    BN_free(*(BIGNUM **)(param_1 + 0x1b4));
    BN_free(*(BIGNUM **)(param_1 + 0x1b8));
    BN_free(*(BIGNUM **)(param_1 + 0x1bc));
    BN_free(*(BIGNUM **)(param_1 + 0x1c0));
    BN_free(*(BIGNUM **)(param_1 + 0x1c4));
    return 0;
  }
LAB_080d0b25:
  if (*(BIGNUM **)(iVar1 + 0x17c) != (BIGNUM *)0x0) {
    pBVar3 = BN_dup(*(BIGNUM **)(iVar1 + 0x17c));
    *(BIGNUM **)(param_1 + 0x1ac) = pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) goto LAB_080d0c50;
  }
  if (*(BIGNUM **)(iVar1 + 0x180) != (BIGNUM *)0x0) {
    pBVar3 = BN_dup(*(BIGNUM **)(iVar1 + 0x180));
    *(BIGNUM **)(param_1 + 0x1b0) = pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) goto LAB_080d0c50;
  }
  if (*(BIGNUM **)(iVar1 + 0x184) != (BIGNUM *)0x0) {
    pBVar3 = BN_dup(*(BIGNUM **)(iVar1 + 0x184));
    *(BIGNUM **)(param_1 + 0x1b4) = pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) goto LAB_080d0c50;
  }
  if (*(BIGNUM **)(iVar1 + 0x188) != (BIGNUM *)0x0) {
    pBVar3 = BN_dup(*(BIGNUM **)(iVar1 + 0x188));
    *(BIGNUM **)(param_1 + 0x1b8) = pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) goto LAB_080d0c50;
  }
  if (*(BIGNUM **)(iVar1 + 0x18c) != (BIGNUM *)0x0) {
    pBVar3 = BN_dup(*(BIGNUM **)(iVar1 + 0x18c));
    *(BIGNUM **)(param_1 + 0x1bc) = pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) goto LAB_080d0c50;
  }
  if (*(BIGNUM **)(iVar1 + 0x194) != (BIGNUM *)0x0) {
    pBVar3 = BN_dup(*(BIGNUM **)(iVar1 + 0x194));
    *(BIGNUM **)(param_1 + 0x1c4) = pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) goto LAB_080d0c50;
  }
  if (*(BIGNUM **)(iVar1 + 400) != (BIGNUM *)0x0) {
    pBVar3 = BN_dup(*(BIGNUM **)(iVar1 + 400));
    *(BIGNUM **)(param_1 + 0x1c0) = pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) goto LAB_080d0c50;
  }
  if (*(char **)(iVar1 + 0x174) != (char *)0x0) {
    pcVar4 = BUF_strdup(*(char **)(iVar1 + 0x174));
    *(char **)(param_1 + 0x1a4) = pcVar4;
    if (pcVar4 == (char *)0x0) {
      ERR_put_error(0x14,0x139,0x44,"tls_srp.c",0xb3);
      goto LAB_080d0c6e;
    }
  }
  *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(iVar1 + 0x1a0);
  return 1;
}

