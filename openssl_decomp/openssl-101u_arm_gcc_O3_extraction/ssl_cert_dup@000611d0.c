
int * ssl_cert_dup(int *param_1)

{
  EVP_PKEY **ppEVar1;
  int *__s;
  RSA *r;
  DH *pDVar2;
  BIGNUM *pBVar3;
  EC_KEY *pEVar4;
  EVP_MD *pEVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  
  __s = (int *)CRYPTO_malloc(0x94,"ssl_cert.c",0xc9);
  if (__s == (int *)0x0) {
    ERR_put_error(0x14,0xdd,0x41,"ssl_cert.c",0xcb);
    return (int *)0x0;
  }
  memset(__s,0,0x94);
  iVar8 = *param_1;
  iVar10 = param_1[1];
  iVar9 = param_1[2];
  iVar6 = param_1[3];
  iVar7 = param_1[4];
  r = (RSA *)param_1[6];
  __s[5] = param_1[5];
  __s[2] = iVar9;
  *__s = (int)__s + (iVar8 - (int)(param_1 + 0xc) & 0xfffffffcU) + 0x30;
  __s[1] = iVar10;
  __s[3] = iVar6;
  __s[4] = iVar7;
  __s[0x24] = 1;
  if (r != (RSA *)0x0) {
    RSA_up_ref(r);
    __s[6] = param_1[6];
  }
  pDVar2 = (DH *)param_1[8];
  __s[7] = param_1[7];
  if (pDVar2 == (DH *)0x0) goto LAB_00061286;
  pDVar2 = DHparams_dup(pDVar2);
  __s[8] = (int)pDVar2;
  if (pDVar2 == (DH *)0x0) {
    ERR_put_error(0x14,0xdd,5,"ssl_cert.c",0xea);
    goto LAB_00061336;
  }
  iVar6 = param_1[8];
  if (*(BIGNUM **)(iVar6 + 0x18) == (BIGNUM *)0x0) {
LAB_00061274:
    if (*(BIGNUM **)(iVar6 + 0x14) != (BIGNUM *)0x0) {
      pBVar3 = BN_dup(*(BIGNUM **)(iVar6 + 0x14));
      if (pBVar3 == (BIGNUM *)0x0) {
        iVar6 = 0xf8;
        goto LAB_00061326;
      }
      *(BIGNUM **)(__s[8] + 0x14) = pBVar3;
    }
LAB_00061286:
    pEVar4 = (EC_KEY *)param_1[10];
    __s[9] = param_1[9];
    if (pEVar4 != (EC_KEY *)0x0) {
      pEVar4 = EC_KEY_dup(pEVar4);
      __s[10] = (int)pEVar4;
      if (pEVar4 == (EC_KEY *)0x0) {
        ERR_put_error(0x14,0xdd,0x10,"ssl_cert.c",0x105);
        goto LAB_00061336;
      }
    }
    iVar6 = 0;
    __s[0xb] = param_1[0xb];
    piVar11 = __s;
    do {
      iVar7 = param_1[0xc];
      iVar6 = iVar6 + 1;
      if (iVar7 != 0) {
        piVar11[0xc] = iVar7;
        CRYPTO_add_lock((int *)(iVar7 + 0x10),1,3,"ssl_cert.c",0x10f);
      }
      iVar7 = param_1[0xd];
      param_1 = param_1 + 3;
      if (iVar7 != 0) {
        piVar11[0xd] = iVar7;
        CRYPTO_add_lock((int *)(iVar7 + 8),1,10,"ssl_cert.c",0x115);
      }
      piVar11 = piVar11 + 3;
    } while (iVar6 != 8);
    pEVar5 = EVP_sha1();
    __s[0x14] = (int)pEVar5;
    pEVar5 = EVP_sha1();
    __s[0x11] = (int)pEVar5;
    pEVar5 = EVP_sha1();
    __s[0xe] = (int)pEVar5;
    pEVar5 = EVP_sha1();
    __s[0x1d] = (int)pEVar5;
    return __s;
  }
  pBVar3 = BN_dup(*(BIGNUM **)(iVar6 + 0x18));
  iVar6 = 0xf0;
  if (pBVar3 != (BIGNUM *)0x0) {
    iVar6 = param_1[8];
    *(BIGNUM **)(__s[8] + 0x18) = pBVar3;
    goto LAB_00061274;
  }
LAB_00061326:
  ERR_put_error(0x14,0xdd,3,"ssl_cert.c",iVar6);
LAB_00061336:
  if ((RSA *)__s[6] != (RSA *)0x0) {
    RSA_free((RSA *)__s[6]);
  }
  if ((DH *)__s[8] != (DH *)0x0) {
    DH_free((DH *)__s[8]);
  }
  if ((EC_KEY *)__s[10] != (EC_KEY *)0x0) {
    EC_KEY_free((EC_KEY *)__s[10]);
  }
  iVar6 = 8;
  do {
    if ((X509 *)__s[0xc] != (X509 *)0x0) {
      X509_free((X509 *)__s[0xc]);
    }
    ppEVar1 = (EVP_PKEY **)(__s + 0xd);
    __s = __s + 3;
    if (*ppEVar1 != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*ppEVar1);
    }
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return (int *)0x0;
}

