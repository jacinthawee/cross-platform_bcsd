
void ssl3_change_cipher_state(int param_1,uint param_2)

{
  EVP_CIPHER *cipher;
  size_t __n;
  size_t cnt;
  int iVar1;
  COMP_CTX *pCVar2;
  EVP_CIPHER_CTX *pEVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  COMP_METHOD *meth;
  uchar *md;
  EVP_MD *pEVar8;
  void *pvVar9;
  void *__src;
  EVP_CIPHER_CTX *pEVar10;
  void *pvVar11;
  uint uVar12;
  EVP_CIPHER_CTX *local_a8;
  uchar *local_a4;
  void *local_a0;
  void *local_9c;
  EVP_MD_CTX EStack_94;
  uchar auStack_7c [16];
  uchar auStack_6c [64];
  int local_2c;
  
  iVar7 = *(int *)(param_1 + 0x58);
  local_2c = __stack_chk_guard;
  pEVar8 = *(EVP_MD **)(iVar7 + 0x380);
  cipher = *(EVP_CIPHER **)(iVar7 + 0x37c);
  uVar12 = *(uint *)(*(int *)(iVar7 + 0x344) + 0x20);
  if (pEVar8 == (EVP_MD *)0x0) {
    OpenSSLDie("s3_enc.c",0xeb,"m");
    iVar7 = *(int *)(param_1 + 0x58);
  }
  meth = *(COMP_METHOD **)(iVar7 + 0x38c);
  if (meth != (COMP_METHOD *)0x0) {
    meth = (COMP_METHOD *)meth->init;
  }
  pEVar10 = (EVP_CIPHER_CTX *)(param_2 & 1);
  if (pEVar10 == (EVP_CIPHER_CTX *)0x0) {
    local_a8 = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    if (local_a8 == (EVP_CIPHER_CTX *)0x0) {
      pEVar3 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s3_enc.c",0x11e);
      *(EVP_CIPHER_CTX **)(param_1 + 0x8c) = pEVar3;
      if (pEVar3 == (EVP_CIPHER_CTX *)0x0) goto LAB_0004cfdc;
      EVP_CIPHER_CTX_init(pEVar3);
      local_a8 = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
      pEVar3 = pEVar10;
    }
    else {
      pEVar3 = (EVP_CIPHER_CTX *)0x1;
    }
    iVar7 = ssl_replace_hash(param_1 + 0x90,pEVar8);
    if (iVar7 == 0) {
      iVar7 = 0x127;
LAB_0004d028:
      ERR_put_error(0x14,0x81,0x44,"s3_enc.c",iVar7);
      goto LAB_0004cdfe;
    }
    if (*(COMP_CTX **)(param_1 + 0x94) != (COMP_CTX *)0x0) {
      COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x94));
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    if (meth != (COMP_METHOD *)0x0) {
      pCVar2 = COMP_CTX_new(meth);
      *(COMP_CTX **)(param_1 + 0x94) = pCVar2;
      if (pCVar2 != (COMP_CTX *)0x0) goto LAB_0004ce56;
      iVar7 = 0x134;
LAB_0004d042:
      ERR_put_error(0x14,0x81,0x8e,"s3_enc.c",iVar7);
      goto LAB_0004cdfe;
    }
LAB_0004ce56:
    iVar7 = *(int *)(param_1 + 0x58);
    *(undefined *)(iVar7 + 0x54) = 0;
    *(undefined *)(iVar7 + 0x55) = 0;
    *(undefined *)(iVar7 + 0x56) = 0;
    *(undefined *)(iVar7 + 0x57) = 0;
    *(undefined *)(iVar7 + 0x58) = 0;
    *(undefined *)(iVar7 + 0x59) = 0;
    *(undefined *)(iVar7 + 0x5a) = 0;
    *(undefined *)(iVar7 + 0x5b) = 0;
    iVar7 = *(int *)(param_1 + 0x58);
    pvVar11 = (void *)(iVar7 + 0x60);
  }
  else {
    pEVar10 = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    if (pEVar10 == (EVP_CIPHER_CTX *)0x0) {
      pEVar3 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s3_enc.c",0xf7);
      *(EVP_CIPHER_CTX **)(param_1 + 0x80) = pEVar3;
      if (pEVar3 != (EVP_CIPHER_CTX *)0x0) {
        EVP_CIPHER_CTX_init(pEVar3);
        local_a8 = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
        pEVar3 = pEVar10;
        goto LAB_0004ccac;
      }
LAB_0004cfdc:
      pEVar10 = (EVP_CIPHER_CTX *)0x0;
      ERR_put_error(0x14,0x81,0x41,"s3_enc.c",0x184);
      goto LAB_0004cdfe;
    }
    pEVar3 = (EVP_CIPHER_CTX *)0x1;
    local_a8 = pEVar10;
LAB_0004ccac:
    pEVar10 = (EVP_CIPHER_CTX *)ssl_replace_hash(param_1 + 0x84,pEVar8);
    iVar7 = 0x101;
    if (pEVar10 == (EVP_CIPHER_CTX *)0x0) goto LAB_0004d028;
    if (*(COMP_CTX **)(param_1 + 0x88) != (COMP_CTX *)0x0) {
      COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x88));
      *(undefined4 *)(param_1 + 0x88) = 0;
    }
    if (meth == (COMP_METHOD *)0x0) {
      iVar7 = *(int *)(param_1 + 0x58);
    }
    else {
      pEVar10 = (EVP_CIPHER_CTX *)COMP_CTX_new(meth);
      iVar7 = 0x10e;
      *(EVP_CIPHER_CTX **)(param_1 + 0x88) = pEVar10;
      if (pEVar10 == (EVP_CIPHER_CTX *)0x0) goto LAB_0004d042;
      iVar7 = *(int *)(param_1 + 0x58);
      if (*(int *)(iVar7 + 0x120) == 0) {
        pvVar11 = CRYPTO_malloc(0x4000,"s3_enc.c",0x113);
        *(void **)(iVar7 + 0x120) = pvVar11;
        iVar7 = *(int *)(param_1 + 0x58);
        if (*(int *)(iVar7 + 0x120) == 0) goto LAB_0004cfdc;
      }
    }
    *(undefined *)(iVar7 + 8) = 0;
    *(undefined *)(iVar7 + 9) = 0;
    *(undefined *)(iVar7 + 10) = 0;
    *(undefined *)(iVar7 + 0xb) = 0;
    *(undefined *)(iVar7 + 0xc) = 0;
    *(undefined *)(iVar7 + 0xd) = 0;
    *(undefined *)(iVar7 + 0xe) = 0;
    *(undefined *)(iVar7 + 0xf) = 0;
    iVar7 = *(int *)(param_1 + 0x58);
    pvVar11 = (void *)(iVar7 + 0x14);
  }
  if (pEVar3 != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_cleanup(local_a8);
    iVar7 = *(int *)(param_1 + 0x58);
  }
  pvVar9 = *(void **)(iVar7 + 0x378);
  __n = EVP_MD_size(pEVar8);
  if ((int)__n < 0) {
    pEVar10 = (EVP_CIPHER_CTX *)0x0;
    goto LAB_0004cdfe;
  }
  uVar12 = uVar12 & 2;
  cnt = EVP_CIPHER_key_length(cipher);
  if (uVar12 != 0) {
    iVar7 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
    if (*(int *)(iVar7 + 0x20) << 0x1c < 0) {
      sVar5 = 5;
    }
    else if (*(int *)(iVar7 + 0x14) == 1) {
      sVar5 = 8;
    }
    else {
      sVar5 = 7;
    }
    if ((int)sVar5 <= (int)cnt) {
      cnt = sVar5;
    }
  }
  iVar7 = EVP_CIPHER_iv_length(cipher);
  if (param_2 == 0x12 || param_2 == 0x21) {
    iVar6 = *(int *)(param_1 + 0x58);
    iVar1 = __n * 2;
    iVar4 = iVar1 + cnt * 2;
    local_a0 = (void *)(iVar6 + 0xc0);
    local_9c = (void *)(iVar6 + 0xa0);
    __src = pvVar9;
    if (*(int *)(iVar6 + 0x374) < iVar4 + iVar7 * 2) {
LAB_0004cebe:
      pEVar10 = (EVP_CIPHER_CTX *)0x0;
      ERR_put_error(0x14,0x81,0x44,"s3_enc.c",0x160);
      goto LAB_0004cdfe;
    }
  }
  else {
    iVar6 = *(int *)(param_1 + 0x58);
    iVar1 = cnt + __n * 2;
    iVar4 = cnt + iVar7 + iVar1;
    local_a0 = (void *)(iVar6 + 0xa0);
    local_9c = (void *)(iVar6 + 0xc0);
    __src = (void *)((int)pvVar9 + __n);
    if (*(int *)(iVar6 + 0x374) < iVar4 + iVar7) goto LAB_0004cebe;
  }
  local_a4 = (uchar *)((int)pvVar9 + iVar4);
  EVP_MD_CTX_init(&EStack_94);
  memcpy(pvVar11,__src,__n);
  md = (uchar *)((int)pvVar9 + iVar1);
  if (uVar12 != 0) {
    md = auStack_6c;
    pEVar8 = EVP_md5();
    EVP_DigestInit_ex(&EStack_94,pEVar8,(ENGINE *)0x0);
    EVP_DigestUpdate(&EStack_94,(uchar *)((int)pvVar9 + iVar1),cnt);
    EVP_DigestUpdate(&EStack_94,local_a0,0x20);
    EVP_DigestUpdate(&EStack_94,local_9c,0x20);
    EVP_DigestFinal_ex(&EStack_94,md,(uint *)0x0);
    if (0 < iVar7) {
      pEVar8 = EVP_md5();
      local_a4 = auStack_7c;
      EVP_DigestInit_ex(&EStack_94,pEVar8,(ENGINE *)0x0);
      EVP_DigestUpdate(&EStack_94,local_a0,0x20);
      EVP_DigestUpdate(&EStack_94,local_9c,0x20);
      EVP_DigestFinal_ex(&EStack_94,local_a4,(uint *)0x0);
    }
  }
  pEVar10 = (EVP_CIPHER_CTX *)0x1;
  *(undefined4 *)(*(int *)(param_1 + 0xc0) + 4) = 0;
  EVP_CipherInit_ex(local_a8,cipher,(ENGINE *)0x0,md,local_a4,param_2 & 2);
  OPENSSL_cleanse(auStack_6c,0x40);
  OPENSSL_cleanse(auStack_7c,0x10);
  EVP_MD_CTX_cleanup(&EStack_94);
LAB_0004cdfe:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pEVar10);
}

