
uint ssl3_change_cipher_state(int param_1,uint param_2)

{
  int iVar1;
  EVP_CIPHER *cipher;
  int iVar2;
  bool bVar3;
  COMP_CTX *pCVar4;
  size_t __n;
  uint uVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  EVP_CIPHER_CTX *pEVar9;
  EVP_MD *pEVar10;
  void *pvVar11;
  uchar *key;
  uint uVar12;
  COMP_METHOD *meth;
  void *__src;
  int in_GS_OFFSET;
  size_t local_b0;
  EVP_CIPHER_CTX *local_ac;
  void *local_a8;
  uchar *local_a0;
  void *local_98;
  void *local_94;
  EVP_MD_CTX local_88;
  uchar local_70 [16];
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar7 = *(int *)(param_1 + 0x58);
  pEVar10 = *(EVP_MD **)(iVar7 + 0x380);
  uVar5 = *(uint *)(*(int *)(iVar7 + 0x344) + 0x20);
  cipher = *(EVP_CIPHER **)(iVar7 + 0x37c);
  if (pEVar10 == (EVP_MD *)0x0) {
    OpenSSLDie("s3_enc.c",0xec,"m");
    iVar7 = *(int *)(param_1 + 0x58);
  }
  if (*(int *)(iVar7 + 0x38c) == 0) {
    meth = (COMP_METHOD *)0x0;
  }
  else {
    meth = *(COMP_METHOD **)(*(int *)(iVar7 + 0x38c) + 8);
  }
  uVar12 = param_2 & 1;
  if (uVar12 == 0) {
    local_ac = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    bVar3 = true;
    if (local_ac == (EVP_CIPHER_CTX *)0x0) {
      pEVar9 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s3_enc.c",0x11d);
      *(EVP_CIPHER_CTX **)(param_1 + 0x8c) = pEVar9;
      if (pEVar9 == (EVP_CIPHER_CTX *)0x0) goto LAB_080a5731;
      bVar3 = false;
      EVP_CIPHER_CTX_init(pEVar9);
      local_ac = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    }
    ssl_replace_hash(param_1 + 0x90,pEVar10);
    if (*(COMP_CTX **)(param_1 + 0x94) != (COMP_CTX *)0x0) {
      COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x94));
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    if (meth != (COMP_METHOD *)0x0) {
      pCVar4 = COMP_CTX_new(meth);
      *(COMP_CTX **)(param_1 + 0x94) = pCVar4;
      if (pCVar4 == (COMP_CTX *)0x0) {
        ERR_put_error(0x14,0x81,0x8e,"s3_enc.c",0x130);
        goto LAB_080a54fe;
      }
    }
    iVar7 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar7 + 0x54) = 0;
    *(undefined4 *)(iVar7 + 0x58) = 0;
    iVar7 = *(int *)(param_1 + 0x58);
    local_a8 = (void *)(iVar7 + 0x60);
    if (bVar3) {
LAB_080a52d6:
      EVP_CIPHER_CTX_cleanup(local_ac);
      iVar7 = *(int *)(param_1 + 0x58);
    }
LAB_080a538f:
    pvVar11 = *(void **)(iVar7 + 0x378);
    __n = EVP_MD_size(pEVar10);
    uVar12 = 0;
    if ((int)__n < 0) goto LAB_080a54fe;
    uVar5 = uVar5 & 2;
    sVar6 = EVP_CIPHER_key_length(cipher);
    local_b0 = sVar6;
    if (uVar5 != 0) {
      iVar7 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
      local_b0 = 5;
      if ((*(byte *)(iVar7 + 0x20) & 8) == 0) {
        local_b0 = (*(int *)(iVar7 + 0x14) == 1) + 7;
      }
      if ((int)sVar6 <= (int)local_b0) {
        local_b0 = sVar6;
      }
    }
    iVar7 = EVP_CIPHER_iv_length(cipher);
    if ((param_2 == 0x12) || (param_2 == 0x21)) {
      iVar1 = __n * 2;
      iVar8 = iVar1 + local_b0 * 2;
      iVar2 = *(int *)(param_1 + 0x58);
      local_98 = (void *)(iVar2 + 0xc0);
      local_94 = (void *)(iVar2 + 0xa0);
      __src = pvVar11;
      if (*(int *)(iVar2 + 0x374) < iVar8 + iVar7 * 2) goto LAB_080a5562;
    }
    else {
      iVar1 = local_b0 + __n * 2;
      iVar8 = iVar1 + local_b0 + iVar7;
      iVar2 = *(int *)(param_1 + 0x58);
      local_98 = (void *)(iVar2 + 0xa0);
      local_94 = (void *)(iVar2 + 0xc0);
      __src = (void *)((int)pvVar11 + __n);
      if (*(int *)(iVar2 + 0x374) < iVar8 + iVar7) {
LAB_080a5562:
        iVar8 = 0x15a;
        iVar7 = 0x44;
        goto LAB_080a5571;
      }
    }
    local_a0 = (uchar *)((int)pvVar11 + iVar8);
    EVP_MD_CTX_init(&local_88);
    memcpy(local_a8,__src,__n);
    key = (uchar *)((int)pvVar11 + iVar1);
    if (uVar5 != 0) {
      pEVar10 = EVP_md5();
      EVP_DigestInit_ex(&local_88,pEVar10,(ENGINE *)0x0);
      EVP_DigestUpdate(&local_88,(uchar *)((int)pvVar11 + iVar1),local_b0);
      EVP_DigestUpdate(&local_88,local_98,0x20);
      EVP_DigestUpdate(&local_88,local_94,0x20);
      EVP_DigestFinal_ex(&local_88,local_60,(uint *)0x0);
      key = local_60;
      if (0 < iVar7) {
        pEVar10 = EVP_md5();
        EVP_DigestInit_ex(&local_88,pEVar10,(ENGINE *)0x0);
        EVP_DigestUpdate(&local_88,local_98,0x20);
        EVP_DigestUpdate(&local_88,local_94,0x20);
        EVP_DigestFinal_ex(&local_88,local_70,(uint *)0x0);
        local_a0 = local_70;
      }
    }
    *(undefined4 *)(*(int *)(param_1 + 0xc0) + 4) = 0;
    EVP_CipherInit_ex(local_ac,cipher,(ENGINE *)0x0,key,local_a0,param_2 & 2);
    OPENSSL_cleanse(local_60,0x40);
    OPENSSL_cleanse(local_70,0x10);
    EVP_MD_CTX_cleanup(&local_88);
    uVar12 = 1;
  }
  else {
    local_ac = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    bVar3 = true;
    if (local_ac != (EVP_CIPHER_CTX *)0x0) {
LAB_080a5250:
      ssl_replace_hash(param_1 + 0x84,pEVar10);
      if (*(COMP_CTX **)(param_1 + 0x88) != (COMP_CTX *)0x0) {
        COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x88));
        *(undefined4 *)(param_1 + 0x88) = 0;
      }
      if (meth == (COMP_METHOD *)0x0) {
        iVar7 = *(int *)(param_1 + 0x58);
      }
      else {
        pCVar4 = COMP_CTX_new(meth);
        *(COMP_CTX **)(param_1 + 0x88) = pCVar4;
        if (pCVar4 == (COMP_CTX *)0x0) {
          iVar8 = 0x10c;
          iVar7 = 0x8e;
          goto LAB_080a5571;
        }
        iVar7 = *(int *)(param_1 + 0x58);
        if (*(int *)(iVar7 + 0x120) == 0) {
          pvVar11 = CRYPTO_malloc(0x4000,"s3_enc.c",0x111);
          *(void **)(iVar7 + 0x120) = pvVar11;
          iVar7 = *(int *)(param_1 + 0x58);
          if (*(int *)(iVar7 + 0x120) == 0) goto LAB_080a5731;
        }
      }
      *(undefined4 *)(iVar7 + 8) = 0;
      *(undefined4 *)(iVar7 + 0xc) = 0;
      iVar7 = *(int *)(param_1 + 0x58);
      local_a8 = (void *)(iVar7 + 0x14);
      if (bVar3) goto LAB_080a52d6;
      goto LAB_080a538f;
    }
    pEVar9 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s3_enc.c",0xf8);
    *(EVP_CIPHER_CTX **)(param_1 + 0x80) = pEVar9;
    if (pEVar9 != (EVP_CIPHER_CTX *)0x0) {
      bVar3 = false;
      EVP_CIPHER_CTX_init(pEVar9);
      local_ac = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
      goto LAB_080a5250;
    }
LAB_080a5731:
    iVar8 = 0x17f;
    iVar7 = 0x41;
LAB_080a5571:
    ERR_put_error(0x14,0x81,iVar7,"s3_enc.c",iVar8);
    uVar12 = 0;
  }
LAB_080a54fe:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}

