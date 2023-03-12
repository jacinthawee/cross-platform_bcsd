
uint tls1_change_cipher_state(int *param_1,uint param_2)

{
  EVP_CIPHER *cipher;
  EVP_MD *type;
  size_t __n;
  bool bVar1;
  COMP_CTX *pCVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  EVP_PKEY *pkey;
  void *pvVar9;
  EVP_CIPHER_CTX *a;
  uint uVar10;
  uint uVar11;
  void *__src;
  int in_GS_OFFSET;
  int local_11c;
  undefined *local_118;
  size_t *local_114;
  EVP_CIPHER_CTX *local_110;
  uchar *local_10c;
  uchar *local_108;
  uchar *local_104;
  EVP_MD_CTX *local_f4;
  uchar local_e0 [32];
  undefined local_c0 [32];
  uchar local_a0 [64];
  undefined local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar8 = param_1[0x16];
  iVar4 = *(int *)(iVar8 + 0x344);
  iVar5 = *(int *)(iVar8 + 0x38c);
  uVar10 = *(uint *)(iVar4 + 0x20) & 2;
  uVar11 = param_2 & 1;
  cipher = *(EVP_CIPHER **)(iVar8 + 0x37c);
  type = *(EVP_MD **)(iVar8 + 0x380);
  iVar8 = *(int *)(iVar8 + 900);
  if (uVar11 == 0) {
    if ((*(byte *)(iVar4 + 0x24) & 4) == 0) {
      uVar3 = param_1[0x1f] & 0xfffffffd;
    }
    else {
      uVar3 = param_1[0x1f] | 2;
    }
    param_1[0x1f] = uVar3;
    local_110 = (EVP_CIPHER_CTX *)param_1[0x23];
    if ((local_110 == (EVP_CIPHER_CTX *)0x0) || (bVar1 = true, *(int *)param_1[2] == 0xfeff)) {
      local_110 = EVP_CIPHER_CTX_new();
      param_1[0x23] = (int)local_110;
      if (local_110 == (EVP_CIPHER_CTX *)0x0) {
LAB_080b1f71:
        iVar4 = 0x242;
        iVar8 = 0x41;
        goto LAB_080b1d8a;
      }
      if (*(int *)param_1[2] != 0xfeff) {
        bVar1 = false;
        goto LAB_080b1aa1;
      }
      local_f4 = EVP_MD_CTX_create();
      if (local_f4 == (EVP_MD_CTX *)0x0) goto LAB_080b1f71;
      param_1[0x24] = (int)local_f4;
      bVar1 = false;
    }
    else {
LAB_080b1aa1:
      local_f4 = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x24,0);
    }
    if ((COMP_CTX *)param_1[0x25] != (COMP_CTX *)0x0) {
      COMP_CTX_free((COMP_CTX *)param_1[0x25]);
      param_1[0x25] = 0;
    }
    if (iVar5 != 0) {
      pCVar2 = COMP_CTX_new(*(COMP_METHOD **)(iVar5 + 8));
      param_1[0x25] = (int)pCVar2;
      if (pCVar2 == (COMP_CTX *)0x0) {
        ERR_put_error(0x14,0xd1,0x8e,"t1_enc.c",0x1ba);
        goto LAB_080b1cff;
      }
    }
    if (*param_1 != 0xfeff) {
      iVar4 = param_1[0x16];
      *(undefined4 *)(iVar4 + 0x54) = 0;
      *(undefined4 *)(iVar4 + 0x58) = 0;
    }
    iVar4 = param_1[0x16];
    local_108 = (uchar *)(iVar4 + 0x60);
    local_114 = (size_t *)(iVar4 + 0x5c);
    if (bVar1) {
LAB_080b1a4d:
      EVP_CIPHER_CTX_cleanup(local_110);
      iVar4 = param_1[0x16];
    }
LAB_080b1b2b:
    __n = *(size_t *)(iVar4 + 0x388);
    pvVar9 = *(void **)(iVar4 + 0x378);
    *local_114 = __n;
    iVar4 = EVP_CIPHER_key_length(cipher);
    if (uVar10 != 0) {
      iVar5 = 5;
      if ((*(byte *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 8) == 0) {
        iVar5 = (*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x14) == 1) + 7;
      }
      if (iVar5 < iVar4) {
        iVar4 = iVar5;
      }
    }
    uVar6 = EVP_CIPHER_flags(cipher);
    local_11c = 4;
    if ((uVar6 & 0xf0007) != 6) {
      local_11c = EVP_CIPHER_iv_length(cipher);
    }
    if ((param_2 == 0x12) || (param_2 == 0x21)) {
      iVar5 = __n * 2;
      bVar1 = true;
      iVar7 = iVar5 + iVar4 * 2;
      __src = pvVar9;
      if (*(int *)(param_1[0x16] + 0x374) < iVar7 + local_11c * 2) goto LAB_080b1d7b;
    }
    else {
      iVar5 = iVar4 + __n * 2;
      bVar1 = false;
      iVar7 = iVar5 + local_11c + iVar4;
      __src = (void *)((int)pvVar9 + __n);
      if (*(int *)(param_1[0x16] + 0x374) < iVar7 + local_11c) {
LAB_080b1d7b:
        iVar4 = 0x1ec;
        iVar8 = 0x44;
        goto LAB_080b1d8a;
      }
    }
    local_104 = (uchar *)((int)pvVar9 + iVar7);
    local_10c = (uchar *)((int)pvVar9 + iVar5);
    memcpy(local_108,__src,__n);
    uVar6 = EVP_CIPHER_flags(cipher);
    if ((uVar6 & 0x200000) == 0) {
      pkey = EVP_PKEY_new_mac_key(iVar8,(ENGINE *)0x0,local_108,*local_114);
      EVP_DigestSignInit(local_f4,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
      EVP_PKEY_free(pkey);
    }
    if (uVar10 != 0) {
      iVar5 = EVP_CIPHER_key_length(cipher);
      iVar8 = param_1[0x16];
      ssl_get_algorithm2(param_1);
      iVar8 = tls1_PRF_constprop_1
                        (iVar8 + 0xc0,0x20,iVar8 + 0xa0,0x20,0,0,local_10c,iVar4,local_a0,local_60,
                         iVar5);
      if (iVar8 == 0) goto LAB_080b1d99;
      local_10c = local_a0;
      if (0 < local_11c) {
        iVar8 = param_1[0x16];
        ssl_get_algorithm2(param_1);
        local_104 = local_e0;
        iVar8 = tls1_PRF_constprop_1
                          (iVar8 + 0xc0,0x20,iVar8 + 0xa0,0x20,0,0,&empty_15890,0,local_104,local_c0
                           ,local_11c * 2);
        if (iVar8 == 0) goto LAB_080b1d99;
        if (!bVar1) {
          local_104 = local_104 + local_11c;
        }
      }
    }
    local_118 = local_60;
    *(undefined4 *)(param_1[0x30] + 4) = 0;
    uVar6 = EVP_CIPHER_flags(cipher);
    if ((uVar6 & 0xf0007) == 6) {
      EVP_CipherInit_ex(local_110,cipher,(ENGINE *)0x0,local_10c,(uchar *)0x0,param_2 & 2);
      EVP_CIPHER_CTX_ctrl(local_110,0x12,local_11c,local_104);
    }
    else {
      EVP_CipherInit_ex(local_110,cipher,(ENGINE *)0x0,local_10c,local_104,param_2 & 2);
    }
    uVar6 = EVP_CIPHER_flags(cipher);
    if (((uVar6 & 0x200000) != 0) && (*local_114 != 0)) {
      EVP_CIPHER_CTX_ctrl(local_110,0x17,*local_114,local_108);
    }
    OPENSSL_cleanse(local_a0,0x40);
    OPENSSL_cleanse(local_118,0x40);
    OPENSSL_cleanse(local_e0,0x20);
    uVar11 = 1;
    OPENSSL_cleanse(local_c0,0x20);
  }
  else {
    if ((*(byte *)(iVar4 + 0x24) & 4) == 0) {
      uVar11 = param_1[0x1f] & 0xfffffffe;
    }
    else {
      uVar11 = param_1[0x1f] | 1;
    }
    param_1[0x1f] = uVar11;
    local_110 = (EVP_CIPHER_CTX *)param_1[0x20];
    bVar1 = true;
    if (local_110 == (EVP_CIPHER_CTX *)0x0) {
      a = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"t1_enc.c",0x179);
      param_1[0x20] = (int)a;
      if (a == (EVP_CIPHER_CTX *)0x0) goto LAB_080b1f71;
      bVar1 = false;
      EVP_CIPHER_CTX_init(a);
      local_110 = (EVP_CIPHER_CTX *)param_1[0x20];
    }
    local_f4 = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x21,0);
    if ((COMP_CTX *)param_1[0x22] != (COMP_CTX *)0x0) {
      COMP_CTX_free((COMP_CTX *)param_1[0x22]);
      param_1[0x22] = 0;
    }
    if (iVar5 == 0) {
      iVar4 = param_1[0x16];
LAB_080b1a1e:
      if (*param_1 != 0xfeff) {
        *(undefined4 *)(iVar4 + 8) = 0;
        *(undefined4 *)(iVar4 + 0xc) = 0;
        iVar4 = param_1[0x16];
      }
      local_108 = (uchar *)(iVar4 + 0x14);
      local_114 = (size_t *)(iVar4 + 0x10);
      if (bVar1) goto LAB_080b1a4d;
      goto LAB_080b1b2b;
    }
    pCVar2 = COMP_CTX_new(*(COMP_METHOD **)(iVar5 + 8));
    param_1[0x22] = (int)pCVar2;
    if (pCVar2 != (COMP_CTX *)0x0) {
      iVar4 = param_1[0x16];
      if (*(int *)(iVar4 + 0x120) == 0) {
        pvVar9 = CRYPTO_malloc(0x4540,"t1_enc.c",400);
        *(void **)(iVar4 + 0x120) = pvVar9;
        iVar4 = param_1[0x16];
        if (*(int *)(iVar4 + 0x120) == 0) goto LAB_080b1f71;
      }
      goto LAB_080b1a1e;
    }
    iVar4 = 0x18b;
    iVar8 = 0x8e;
LAB_080b1d8a:
    ERR_put_error(0x14,0xd1,iVar8,"t1_enc.c",iVar4);
LAB_080b1d99:
    uVar11 = 0;
  }
LAB_080b1cff:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}

