
int * ssl_cert_dup(int *param_1)

{
  int *piVar1;
  DH *pDVar2;
  BIGNUM *pBVar3;
  EC_KEY *pEVar4;
  EVP_MD *pEVar5;
  uint uVar6;
  int *piVar7;
  X509 **ppXVar8;
  undefined4 *puVar9;
  int *piVar10;
  byte bVar11;
  int iVar12;
  
  bVar11 = 0;
  piVar1 = (int *)CRYPTO_malloc(0x94,"ssl_cert.c",0xc9);
  if (piVar1 == (int *)0x0) {
    ERR_put_error(0x14,0xdd,0x41,"ssl_cert.c",0xcc);
    return (int *)0x0;
  }
  *piVar1 = 0;
  piVar1[0x24] = 0;
  piVar7 = param_1 + 0xc;
  puVar9 = (undefined4 *)((uint)(piVar1 + 1) & 0xfffffffc);
  for (uVar6 = (uint)((int)piVar1 + (0x94 - (int)(undefined4 *)((uint)(piVar1 + 1) & 0xfffffffc)))
               >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar9 = 0;
    puVar9 = puVar9 + (uint)bVar11 * -2 + 1;
  }
  *piVar1 = (int)piVar1 + (*param_1 - (int)piVar7 & 0xfffffffcU) + 0x30;
  piVar1[1] = param_1[1];
  piVar1[2] = param_1[2];
  piVar1[3] = param_1[3];
  piVar1[4] = param_1[4];
  piVar1[5] = param_1[5];
  if ((RSA *)param_1[6] != (RSA *)0x0) {
    RSA_up_ref((RSA *)param_1[6]);
    piVar1[6] = param_1[6];
  }
  piVar1[7] = param_1[7];
  if ((DH *)param_1[8] == (DH *)0x0) goto LAB_080c4b26;
  pDVar2 = DHparams_dup((DH *)param_1[8]);
  piVar1[8] = (int)pDVar2;
  if (pDVar2 == (DH *)0x0) {
    ERR_put_error(0x14,0xdd,5,"ssl_cert.c",0xeb);
    goto LAB_080c4c49;
  }
  iVar12 = param_1[8];
  if (*(BIGNUM **)(iVar12 + 0x18) == (BIGNUM *)0x0) {
LAB_080c4b05:
    if (*(BIGNUM **)(iVar12 + 0x14) != (BIGNUM *)0x0) {
      pBVar3 = BN_dup(*(BIGNUM **)(iVar12 + 0x14));
      if (pBVar3 == (BIGNUM *)0x0) {
        iVar12 = 0xfd;
        goto LAB_080c4cf1;
      }
      *(BIGNUM **)(piVar1[8] + 0x14) = pBVar3;
    }
LAB_080c4b26:
    piVar1[9] = param_1[9];
    if ((EC_KEY *)param_1[10] != (EC_KEY *)0x0) {
      pEVar4 = EC_KEY_dup((EC_KEY *)param_1[10]);
      piVar1[10] = (int)pEVar4;
      if (pEVar4 == (EC_KEY *)0x0) {
        ERR_put_error(0x14,0xdd,0x10,"ssl_cert.c",0x10c);
        goto LAB_080c4c49;
      }
    }
    piVar10 = piVar1 + 0xd;
    uVar6 = 0;
    piVar1[0xb] = param_1[0xb];
    do {
      while( true ) {
        iVar12 = *piVar7;
        if (iVar12 != 0) {
          piVar10[-1] = iVar12;
          CRYPTO_add_lock((int *)(iVar12 + 0x10),1,3,"ssl_cert.c",0x119);
        }
        iVar12 = piVar7[1];
        if (iVar12 != 0) break;
LAB_080c4b60:
        uVar6 = uVar6 + 1;
        piVar7 = piVar7 + 3;
        piVar10 = piVar10 + 3;
        if (uVar6 == 8) goto LAB_080c4bf7;
      }
      *piVar10 = iVar12;
      CRYPTO_add_lock((int *)(iVar12 + 8),1,10,"ssl_cert.c",0x120);
      if (uVar6 < 6) goto LAB_080c4b60;
      uVar6 = uVar6 + 1;
      piVar7 = piVar7 + 3;
      piVar10 = piVar10 + 3;
      ERR_put_error(0x14,0xdd,0x112,"ssl_cert.c",0x13c);
    } while (uVar6 != 8);
LAB_080c4bf7:
    piVar1[0x24] = 1;
    pEVar5 = EVP_sha1();
    piVar1[0x14] = (int)pEVar5;
    pEVar5 = EVP_sha1();
    piVar1[0x11] = (int)pEVar5;
    pEVar5 = EVP_sha1();
    piVar1[0xe] = (int)pEVar5;
    pEVar5 = EVP_sha1();
    piVar1[0x1d] = (int)pEVar5;
    return piVar1;
  }
  pBVar3 = BN_dup(*(BIGNUM **)(iVar12 + 0x18));
  if (pBVar3 != (BIGNUM *)0x0) {
    *(BIGNUM **)(piVar1[8] + 0x18) = pBVar3;
    iVar12 = param_1[8];
    goto LAB_080c4b05;
  }
  iVar12 = 0xf3;
LAB_080c4cf1:
  ERR_put_error(0x14,0xdd,3,"ssl_cert.c",iVar12);
LAB_080c4c49:
  if ((RSA *)piVar1[6] != (RSA *)0x0) {
    RSA_free((RSA *)piVar1[6]);
  }
  if ((DH *)piVar1[8] != (DH *)0x0) {
    DH_free((DH *)piVar1[8]);
  }
  if ((EC_KEY *)piVar1[10] != (EC_KEY *)0x0) {
    EC_KEY_free((EC_KEY *)piVar1[10]);
  }
  ppXVar8 = (X509 **)(piVar1 + 0xc);
  do {
    if (*ppXVar8 != (X509 *)0x0) {
      X509_free(*ppXVar8);
    }
    if (ppXVar8[1] != (X509 *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)ppXVar8[1]);
    }
    ppXVar8 = ppXVar8 + 3;
  } while (ppXVar8 != (X509 **)(piVar1 + 0x24));
  return (int *)0x0;
}

