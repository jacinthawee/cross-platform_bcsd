
void tls1_change_cipher_state(int *param_1,uint param_2)

{
  bool bVar1;
  EVP_MD_CTX *ctx;
  ulong uVar2;
  COMP_CTX *pCVar3;
  undefined4 uVar4;
  EVP_CIPHER_CTX *pEVar5;
  EVP_PKEY *pkey;
  uint uVar6;
  int iVar7;
  uint uVar8;
  EVP_MD *type;
  int iVar9;
  EVP_CIPHER *cipher;
  COMP_CTX *pCVar10;
  void *pvVar11;
  void *__src;
  int iVar12;
  size_t __n;
  EVP_CIPHER_CTX *pEVar13;
  int iVar14;
  uchar *key;
  char *pcVar15;
  undefined *local_118;
  EVP_CIPHER_CTX *local_114;
  int local_110;
  size_t *local_10c;
  uchar *local_108;
  uchar *local_100;
  uchar auStack_ec [32];
  undefined auStack_cc [32];
  uchar auStack_ac [64];
  undefined auStack_6c [64];
  int local_2c;
  
  iVar7 = param_1[0x16];
  type = *(EVP_MD **)(iVar7 + 0x380);
  iVar9 = *(int *)(iVar7 + 900);
  uVar6 = *(uint *)(*(int *)(iVar7 + 0x344) + 0x20) & 2;
  cipher = *(EVP_CIPHER **)(iVar7 + 0x37c);
  pCVar10 = (COMP_CTX *)(param_2 & 1);
  iVar12 = *(int *)(iVar7 + 0x38c);
  local_2c = __TMC_END__;
  uVar8 = *(uint *)(*(int *)(iVar7 + 0x344) + 0x24);
  if (pCVar10 == (COMP_CTX *)0x0) {
    local_114 = (EVP_CIPHER_CTX *)param_1[0x23];
    if ((uVar8 & 4) == 0) {
      uVar8 = param_1[0x1f] & 0xfffffffd;
    }
    else {
      uVar8 = param_1[0x1f] | 2;
    }
    param_1[0x1f] = uVar8;
    if ((local_114 == (EVP_CIPHER_CTX *)0x0) || (*(int *)param_1[2] == 0xfeff)) {
      local_114 = EVP_CIPHER_CTX_new();
      param_1[0x23] = (int)local_114;
      if (local_114 == (EVP_CIPHER_CTX *)0x0) {
LAB_00057b64:
        pCVar10 = (COMP_CTX *)0x0;
        ERR_put_error(0x14,0xd1,0x41,"t1_enc.c",0x242);
        goto LAB_000578a6;
      }
      if (*(int *)param_1[2] != 0xfeff) {
        bVar1 = false;
        goto LAB_000578ea;
      }
      ctx = EVP_MD_CTX_create();
      if (ctx == (EVP_MD_CTX *)0x0) goto LAB_00057b64;
      param_1[0x24] = (int)ctx;
      bVar1 = false;
    }
    else {
      bVar1 = true;
LAB_000578ea:
      ctx = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x24,0);
    }
    if ((COMP_CTX *)param_1[0x25] != (COMP_CTX *)0x0) {
      COMP_CTX_free((COMP_CTX *)param_1[0x25]);
      param_1[0x25] = 0;
    }
    if (iVar12 != 0) {
      pCVar3 = COMP_CTX_new(*(COMP_METHOD **)(iVar12 + 8));
      param_1[0x25] = (int)pCVar3;
      if (pCVar3 == (COMP_CTX *)0x0) {
        iVar7 = 0x1ba;
        goto LAB_00057ba0;
      }
    }
    if (*param_1 != 0xfeff) {
      iVar7 = param_1[0x16];
      *(undefined *)(iVar7 + 0x54) = 0;
      *(undefined *)(iVar7 + 0x55) = 0;
      *(undefined *)(iVar7 + 0x56) = 0;
      *(undefined *)(iVar7 + 0x57) = 0;
      *(undefined *)(iVar7 + 0x58) = 0;
      *(undefined *)(iVar7 + 0x59) = 0;
      *(undefined *)(iVar7 + 0x5a) = 0;
      *(undefined *)(iVar7 + 0x5b) = 0;
    }
    iVar7 = param_1[0x16];
    local_108 = (uchar *)(iVar7 + 0x60);
    local_10c = (size_t *)(iVar7 + 0x5c);
    if (bVar1) goto LAB_00057964;
  }
  else {
    pEVar13 = (EVP_CIPHER_CTX *)param_1[0x20];
    if ((uVar8 & 4) == 0) {
      uVar8 = param_1[0x1f] & 0xfffffffe;
    }
    else {
      uVar8 = param_1[0x1f] | 1;
    }
    param_1[0x1f] = uVar8;
    if (pEVar13 == (EVP_CIPHER_CTX *)0x0) {
      pEVar5 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"t1_enc.c",0x179);
      param_1[0x20] = (int)pEVar5;
      if (pEVar5 == (EVP_CIPHER_CTX *)0x0) goto LAB_00057b64;
      EVP_CIPHER_CTX_init(pEVar5);
      local_114 = (EVP_CIPHER_CTX *)param_1[0x20];
      pEVar5 = pEVar13;
    }
    else {
      pEVar5 = (EVP_CIPHER_CTX *)0x1;
      local_114 = pEVar13;
    }
    ctx = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x21,0);
    if ((COMP_CTX *)param_1[0x22] != (COMP_CTX *)0x0) {
      COMP_CTX_free((COMP_CTX *)param_1[0x22]);
      param_1[0x22] = 0;
    }
    if (iVar12 == 0) {
      iVar7 = param_1[0x16];
    }
    else {
      pCVar10 = COMP_CTX_new(*(COMP_METHOD **)(iVar12 + 8));
      iVar7 = 0x18b;
      param_1[0x22] = (int)pCVar10;
      if (pCVar10 == (COMP_CTX *)0x0) {
LAB_00057ba0:
        ERR_put_error(0x14,0xd1,0x8e,"t1_enc.c",iVar7);
        goto LAB_000578a6;
      }
      iVar7 = param_1[0x16];
      if (*(int *)(iVar7 + 0x120) == 0) {
        pvVar11 = CRYPTO_malloc(0x4540,"t1_enc.c",400);
        *(void **)(iVar7 + 0x120) = pvVar11;
        iVar7 = param_1[0x16];
        if (*(int *)(iVar7 + 0x120) == 0) goto LAB_00057b64;
      }
    }
    if (*param_1 != 0xfeff) {
      *(undefined *)(iVar7 + 8) = 0;
      *(undefined *)(iVar7 + 9) = 0;
      *(undefined *)(iVar7 + 10) = 0;
      *(undefined *)(iVar7 + 0xb) = 0;
      *(undefined *)(iVar7 + 0xc) = 0;
      *(undefined *)(iVar7 + 0xd) = 0;
      *(undefined *)(iVar7 + 0xe) = 0;
      *(undefined *)(iVar7 + 0xf) = 0;
      iVar7 = param_1[0x16];
    }
    local_108 = (uchar *)(iVar7 + 0x14);
    local_10c = (size_t *)(iVar7 + 0x10);
    if (pEVar5 != (EVP_CIPHER_CTX *)0x0) {
LAB_00057964:
      EVP_CIPHER_CTX_cleanup(local_114);
      iVar7 = param_1[0x16];
    }
  }
  __n = *(size_t *)(iVar7 + 0x388);
  pvVar11 = *(void **)(iVar7 + 0x378);
  *local_10c = __n;
  iVar7 = EVP_CIPHER_key_length(cipher);
  if (uVar6 != 0) {
    if (*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x20) << 0x1c < 0) {
      iVar12 = 5;
    }
    else if (*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x14) == 1) {
      iVar12 = 8;
    }
    else {
      iVar12 = 7;
    }
    if (iVar12 <= iVar7) {
      iVar7 = iVar12;
    }
  }
  uVar2 = EVP_CIPHER_flags(cipher);
  if ((uVar2 & 0xf0007) == 6) {
    local_110 = 4;
  }
  else {
    local_110 = EVP_CIPHER_iv_length(cipher);
  }
  bVar1 = param_2 == 0x12 || param_2 == 0x21;
  if (bVar1) {
    bVar1 = true;
    iVar14 = __n * 2;
    iVar12 = iVar14 + iVar7 * 2;
    pcVar15 = "client write key";
    __src = pvVar11;
    if (*(int *)(param_1[0x16] + 0x374) < iVar12 + local_110 * 2) goto LAB_0005799c;
  }
  else {
    iVar14 = iVar7 + __n * 2;
    iVar12 = local_110 + iVar7 + iVar14;
    __src = (void *)((int)pvVar11 + __n);
    pcVar15 = "server write key";
    if (*(int *)(param_1[0x16] + 0x374) < iVar12 + local_110) {
LAB_0005799c:
      pCVar10 = (COMP_CTX *)0x0;
      ERR_put_error(0x14,0xd1,0x44,"t1_enc.c",0x1ec);
      goto LAB_000578a6;
    }
  }
  local_100 = (uchar *)((int)pvVar11 + iVar12);
  key = (uchar *)(iVar14 + (int)pvVar11);
  memcpy(local_108,__src,__n);
  uVar2 = EVP_CIPHER_flags(cipher);
  if ((uVar2 & 0x200000) == 0) {
    pkey = EVP_PKEY_new_mac_key(iVar9,(ENGINE *)0x0,local_108,*local_10c);
    EVP_DigestSignInit(ctx,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
    EVP_PKEY_free(pkey);
  }
  if (uVar6 != 0) {
    uVar4 = ssl_get_algorithm2(param_1);
    iVar12 = param_1[0x16];
    iVar9 = EVP_CIPHER_key_length(cipher);
    iVar7 = tls1_PRF_constprop_2
                      (uVar4,pcVar15,0x10,iVar12 + 0xc0,0x20,iVar12 + 0xa0,0x20,0,0,key,iVar7,
                       auStack_ac,auStack_6c,iVar9);
    if (iVar7 == 0) {
LAB_00057a7e:
      pCVar10 = (COMP_CTX *)0x0;
      goto LAB_000578a6;
    }
    key = auStack_ac;
    if (0 < local_110) {
      uVar4 = ssl_get_algorithm2(param_1);
      local_100 = auStack_ec;
      iVar7 = tls1_PRF_constprop_2
                        (uVar4,"IV block",8,param_1[0x16] + 0xc0,0x20,param_1[0x16] + 0xa0,0x20,0,0,
                         &empty_18541,0,local_100,auStack_cc,local_110 << 1);
      if (iVar7 == 0) goto LAB_00057a7e;
      if (!bVar1) {
        local_100 = local_100 + local_110;
      }
    }
  }
  local_118 = auStack_cc;
  *(undefined4 *)(param_1[0x30] + 4) = 0;
  uVar2 = EVP_CIPHER_flags(cipher);
  if ((uVar2 & 0xf0007) == 6) {
    EVP_CipherInit_ex(local_114,cipher,(ENGINE *)0x0,key,(uchar *)0x0,param_2 & 2);
    EVP_CIPHER_CTX_ctrl(local_114,0x12,local_110,local_100);
  }
  else {
    EVP_CipherInit_ex(local_114,cipher,(ENGINE *)0x0,key,local_100,param_2 & 2);
  }
  uVar2 = EVP_CIPHER_flags(cipher);
  if (((int)(uVar2 << 10) < 0) && (*local_10c != 0)) {
    EVP_CIPHER_CTX_ctrl(local_114,0x17,*local_10c,local_108);
  }
  OPENSSL_cleanse(auStack_ac,0x40);
  pCVar10 = (COMP_CTX *)0x1;
  OPENSSL_cleanse(auStack_6c,0x40);
  OPENSSL_cleanse(auStack_ec,0x20);
  OPENSSL_cleanse(local_118,0x20);
LAB_000578a6:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pCVar10);
}

