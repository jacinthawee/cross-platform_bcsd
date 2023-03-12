
uint pkey_rsa_verify(int param_1,uchar *param_2,uint param_3,uchar *param_4,uint param_5)

{
  uint uVar1;
  EVP_PKEY *pkey;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  RSA *rsa;
  uint local_24;
  
  iVar3 = *(int *)(param_1 + 0x14);
  pkey = *(EVP_PKEY **)(param_1 + 8);
  rsa = (pkey->pkey).rsa;
  if (*(EVP_MD **)(iVar3 + 0x14) == (EVP_MD *)0x0) {
    puVar2 = *(uchar **)(iVar3 + 0x20);
    if (puVar2 == (uchar *)0x0) {
      iVar4 = EVP_PKEY_size(pkey);
      puVar2 = (uchar *)CRYPTO_malloc(iVar4,"rsa_pmeth.c",0x8c);
      *(uchar **)(iVar3 + 0x20) = puVar2;
      if (puVar2 == (uchar *)0x0) {
        return 0xffffffff;
      }
    }
    local_24 = RSA_public_decrypt(param_3,param_2,puVar2,rsa,*(int *)(iVar3 + 0x10));
    if (local_24 == 0) {
      return 0;
    }
  }
  else {
    iVar4 = *(int *)(iVar3 + 0x10);
    if (iVar4 == 1) {
      iVar3 = EVP_MD_type(*(EVP_MD **)(iVar3 + 0x14));
      uVar1 = RSA_verify(iVar3,param_4,param_5,param_2,param_3,rsa);
      return uVar1;
    }
    if (iVar4 != 5) {
      if (iVar4 != 6) {
        return 0xffffffff;
      }
      puVar2 = *(uchar **)(iVar3 + 0x20);
      if (puVar2 == (uchar *)0x0) {
        iVar4 = EVP_PKEY_size(pkey);
        puVar2 = (uchar *)CRYPTO_malloc(iVar4,"rsa_pmeth.c",0x8c);
        *(uchar **)(iVar3 + 0x20) = puVar2;
        if (puVar2 == (uchar *)0x0) {
          return 0xffffffff;
        }
      }
      iVar4 = RSA_public_decrypt(param_3,param_2,puVar2,rsa,3);
      if (0 < iVar4) {
        iVar3 = RSA_verify_PKCS1_PSS_mgf1
                          (rsa,param_4,*(EVP_MD **)(iVar3 + 0x14),*(EVP_MD **)(iVar3 + 0x18),
                           *(uchar **)(iVar3 + 0x20),*(int *)(iVar3 + 0x1c));
        if (0 < iVar3) {
          return 1;
        }
        return 0;
      }
      return 0;
    }
    iVar4 = pkey_rsa_verifyrecover(param_1,0,&local_24,param_2,param_3);
    if (iVar4 < 1) {
      return 0;
    }
  }
  if (param_5 == local_24) {
    iVar3 = memcmp(param_4,*(void **)(iVar3 + 0x20),param_5);
    uVar1 = count_leading_zeroes(iVar3);
    return uVar1 >> 5;
  }
  return 0;
}

