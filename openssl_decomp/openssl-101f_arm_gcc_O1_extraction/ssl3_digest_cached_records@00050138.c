
undefined4 ssl3_digest_cached_records(int param_1)

{
  EVP_MD_CTX **ppEVar1;
  size_t cnt;
  EVP_MD_CTX *pEVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  uint local_2c;
  EVP_MD *local_28;
  void *local_24 [2];
  
  iVar8 = *(int *)(param_1 + 0x58);
  pvVar6 = *(void **)(iVar8 + 0x17c);
  if (pvVar6 != (void *)0x0) {
    iVar8 = 0;
    do {
      ppEVar1 = (EVP_MD_CTX **)((int)pvVar6 + iVar8);
      iVar8 = iVar8 + 4;
      if (*ppEVar1 != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(*ppEVar1);
        pvVar6 = *(void **)(*(int *)(param_1 + 0x58) + 0x17c);
      }
    } while (iVar8 != 0x18);
    CRYPTO_free(pvVar6);
    iVar8 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar8 + 0x17c) = 0;
  }
  pvVar6 = CRYPTO_malloc(0x18,"s3_enc.c",0x256);
  iVar7 = *(int *)(param_1 + 0x58);
  *(void **)(iVar8 + 0x17c) = pvVar6;
  memset(*(void **)(iVar7 + 0x17c),0,0x18);
  cnt = BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x58) + 0x178),3,0,local_24);
  if ((int)cnt < 1) {
    ERR_put_error(0x14,0x125,0x14c,"s3_enc.c",0x25b);
    uVar5 = 0;
  }
  else {
    iVar8 = 0;
    iVar7 = 0;
    while (iVar3 = ssl_get_handshake_digest(iVar7,&local_2c,&local_28), iVar3 != 0) {
      uVar4 = ssl_get_algorithm2(param_1);
      if (((uVar4 & local_2c) == 0) || (local_28 == (EVP_MD *)0x0)) {
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar8) = 0;
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + 0x58) + 0x17c);
        pEVar2 = EVP_MD_CTX_create();
        *(EVP_MD_CTX **)(iVar3 + iVar8) = pEVar2;
        EVP_DigestInit_ex(*(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar8),
                          local_28,(ENGINE *)0x0);
        EVP_DigestUpdate(*(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar8),
                         local_24[0],cnt);
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 4;
    }
    if ((**(uint **)(param_1 + 0x58) & 0x20) == 0) {
      BIO_free((BIO *)(*(uint **)(param_1 + 0x58))[0x5e]);
      uVar5 = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x178) = 0;
    }
    else {
      uVar5 = 1;
    }
  }
  return uVar5;
}

