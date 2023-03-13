
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
  int *piVar9;
  undefined4 *puVar10;
  byte bVar11;
  int iVar12;
  
  bVar11 = 0;
  piVar1 = (int *)CRYPTO_malloc(0x94,"ssl_cert.c",0xc9);
  if (piVar1 == (int *)0x0) {
    ERR_put_error(0x14,0xdd,0x41,"ssl_cert.c",0xcb);
    return (int *)0x0;
  }
  *piVar1 = 0;
  piVar7 = param_1 + 0xc;
  puVar10 = (undefined4 *)((uint)(piVar1 + 1) & 0xfffffffc);
  for (uVar6 = (uint)((int)piVar1 + (0x94 - (int)(undefined4 *)((uint)(piVar1 + 1) & 0xfffffffc)))
               >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar10 = 0;
    puVar10 = puVar10 + (uint)bVar11 * -2 + 1;
  }
  piVar1[0x24] = 1;
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
  if ((DH *)param_1[8] == (DH *)0x0) goto LAB_080c23ee;
  pDVar2 = DHparams_dup((DH *)param_1[8]);
  piVar1[8] = (int)pDVar2;
  if (pDVar2 == (DH *)0x0) {
    ERR_put_error(0x14,0xdd,5,"ssl_cert.c",0xea);
    goto LAB_080c24cf;
  }
  iVar12 = param_1[8];
  if (*(BIGNUM **)(iVar12 + 0x18) == (BIGNUM *)0x0) {
LAB_080c23c5:
    if (*(BIGNUM **)(iVar12 + 0x14) != (BIGNUM *)0x0) {
      pBVar3 = BN_dup(*(BIGNUM **)(iVar12 + 0x14));
      if (pBVar3 == (BIGNUM *)0x0) {
        iVar12 = 0xf8;
        goto LAB_080c2579;
      }
      *(BIGNUM **)(piVar1[8] + 0x14) = pBVar3;
    }
LAB_080c23ee:
    piVar1[9] = param_1[9];
    if ((EC_KEY *)param_1[10] != (EC_KEY *)0x0) {
      pEVar4 = EC_KEY_dup((EC_KEY *)param_1[10]);
      piVar1[10] = (int)pEVar4;
      if (pEVar4 == (EC_KEY *)0x0) {
        ERR_put_error(0x14,0xdd,0x10,"ssl_cert.c",0x105);
        goto LAB_080c24cf;
      }
    }
    piVar9 = piVar1 + 0xd;
    piVar1[0xb] = param_1[0xb];
    do {
      iVar12 = *piVar7;
      if (iVar12 != 0) {
        piVar9[-1] = iVar12;
        CRYPTO_add_lock((int *)(iVar12 + 0x10),1,3,"ssl_cert.c",0x10f);
      }
      iVar12 = piVar7[1];
      if (iVar12 != 0) {
        *piVar9 = iVar12;
        CRYPTO_add_lock((int *)(iVar12 + 8),1,10,"ssl_cert.c",0x115);
      }
      piVar7 = piVar7 + 3;
      piVar9 = piVar9 + 3;
    } while (piVar7 != param_1 + 0x24);
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
    goto LAB_080c23c5;
  }
  iVar12 = 0xf0;
LAB_080c2579:
  ERR_put_error(0x14,0xdd,3,"ssl_cert.c",iVar12);
LAB_080c24cf:
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

