
undefined4 ssl3_digest_cached_records(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  size_t cnt;
  EVP_MD_CTX *pEVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int in_GS_OFFSET;
  uint local_2c;
  EVP_MD *local_28;
  void *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = *(int *)(param_1 + 0x58);
  pvVar2 = *(void **)(iVar6 + 0x17c);
  if (pvVar2 != (void *)0x0) {
    iVar6 = 0;
    do {
      if (*(EVP_MD_CTX **)((int)pvVar2 + iVar6) != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)pvVar2 + iVar6));
        pvVar2 = *(void **)(*(int *)(param_1 + 0x58) + 0x17c);
      }
      iVar6 = iVar6 + 4;
    } while (iVar6 != 0x18);
    CRYPTO_free(pvVar2);
    iVar6 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar6 + 0x17c) = 0;
  }
  pvVar2 = CRYPTO_malloc(0x18,"s3_enc.c",0x256);
  *(void **)(iVar6 + 0x17c) = pvVar2;
  uVar5 = 0;
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x58) + 0x17c);
  *puVar1 = 0;
  puVar1[5] = 0;
  do {
    *(undefined4 *)(((uint)(puVar1 + 1) & 0xfffffffc) + uVar5) = 0;
    uVar5 = uVar5 + 4;
  } while (uVar5 < ((int)puVar1 + (0x18 - ((uint)(puVar1 + 1) & 0xfffffffc)) & 0xfffffffc));
  cnt = BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x58) + 0x178),3,0,&local_24);
  if ((int)cnt < 1) {
    uVar7 = 0;
    ERR_put_error(0x14,0x125,0x14c,"s3_enc.c",0x25b);
  }
  else {
    iVar6 = 0;
    while( true ) {
      iVar4 = ssl_get_handshake_digest(iVar6,&local_2c,&local_28);
      if (iVar4 == 0) break;
      uVar5 = ssl_get_algorithm2(param_1);
      iVar4 = *(int *)(*(int *)(param_1 + 0x58) + 0x17c);
      if (((local_2c & uVar5) == 0) || (local_28 == (EVP_MD *)0x0)) {
        *(undefined4 *)(iVar4 + iVar6 * 4) = 0;
      }
      else {
        pEVar3 = EVP_MD_CTX_create();
        *(EVP_MD_CTX **)(iVar4 + iVar6 * 4) = pEVar3;
        EVP_DigestInit_ex(*(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar6 * 4),
                          local_28,(ENGINE *)0x0);
        EVP_DigestUpdate(*(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar6 * 4),
                         local_24,cnt);
      }
      iVar6 = iVar6 + 1;
    }
    uVar7 = 1;
    if ((**(byte **)(param_1 + 0x58) & 0x20) == 0) {
      BIO_free(*(BIO **)(*(byte **)(param_1 + 0x58) + 0x178));
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x178) = 0;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

