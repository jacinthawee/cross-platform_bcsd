
uint pkey_rsa_verify(int param_1,uchar *param_2,uint param_3,uchar *param_4,size_t param_5)

{
  EVP_PKEY *pkey;
  RSA *rsa;
  int iVar1;
  int iVar2;
  uint uVar3;
  uchar *puVar4;
  int in_GS_OFFSET;
  size_t local_24;
  int local_20;
  
  iVar2 = *(int *)(param_1 + 0x14);
  pkey = *(EVP_PKEY **)(param_1 + 8);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  rsa = (pkey->pkey).rsa;
  if (*(EVP_MD **)(iVar2 + 0x14) == (EVP_MD *)0x0) {
    puVar4 = *(uchar **)(iVar2 + 0x20);
    if (puVar4 == (uchar *)0x0) {
      iVar1 = EVP_PKEY_size(pkey);
      puVar4 = (uchar *)CRYPTO_malloc(iVar1,"rsa_pmeth.c",0x8c);
      *(uchar **)(iVar2 + 0x20) = puVar4;
      if (puVar4 == (uchar *)0x0) goto LAB_081c1d00;
    }
    local_24 = RSA_public_decrypt(param_3,param_2,puVar4,rsa,*(int *)(iVar2 + 0x10));
    if (local_24 != 0) {
LAB_081c1c72:
      if (param_5 == local_24) {
        iVar2 = memcmp(param_4,*(void **)(iVar2 + 0x20),param_5);
        uVar3 = (uint)(iVar2 == 0);
        goto LAB_081c1bf8;
      }
    }
  }
  else {
    iVar1 = *(int *)(iVar2 + 0x10);
    if (iVar1 == 1) {
      iVar2 = EVP_MD_type(*(EVP_MD **)(iVar2 + 0x14));
      uVar3 = RSA_verify(iVar2,param_4,param_5,param_2,param_3,rsa);
      goto LAB_081c1bf8;
    }
    if (iVar1 == 5) {
      iVar1 = pkey_rsa_verifyrecover(param_1,0,&local_24,param_2,param_3);
      if (0 < iVar1) goto LAB_081c1c72;
    }
    else {
      if (iVar1 != 6) {
LAB_081c1d00:
        uVar3 = 0xffffffff;
        goto LAB_081c1bf8;
      }
      puVar4 = *(uchar **)(iVar2 + 0x20);
      if (puVar4 == (uchar *)0x0) {
        iVar1 = EVP_PKEY_size(pkey);
        puVar4 = (uchar *)CRYPTO_malloc(iVar1,"rsa_pmeth.c",0x8c);
        *(uchar **)(iVar2 + 0x20) = puVar4;
        if (puVar4 == (uchar *)0x0) goto LAB_081c1d00;
      }
      iVar1 = RSA_public_decrypt(param_3,param_2,puVar4,rsa,3);
      if (0 < iVar1) {
        iVar2 = RSA_verify_PKCS1_PSS_mgf1
                          (rsa,param_4,*(EVP_MD **)(iVar2 + 0x14),*(EVP_MD **)(iVar2 + 0x18),
                           *(uchar **)(iVar2 + 0x20),*(int *)(iVar2 + 0x1c));
        uVar3 = (uint)(0 < iVar2);
        goto LAB_081c1bf8;
      }
    }
  }
  uVar3 = 0;
LAB_081c1bf8:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

