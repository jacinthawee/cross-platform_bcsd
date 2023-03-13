
uint tls1_change_cipher_state(int *param_1,uint param_2)

{
  EVP_CIPHER *cipher;
  EVP_MD *type;
  size_t __n;
  bool bVar1;
  COMP_CTX *pCVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  int iVar8;
  int iVar9;
  void *pvVar10;
  EVP_PKEY *pkey;
  EVP_CIPHER_CTX *a;
  uint uVar11;
  void *__src;
  int in_GS_OFFSET;
  int local_11c;
  EVP_CIPHER_CTX *local_114;
  size_t *local_110;
  uchar *local_10c;
  uchar *local_108;
  EVP_MD_CTX *local_fc;
  uchar *local_f8;
  uchar local_e0 [32];
  undefined local_c0 [32];
  uchar local_a0 [64];
  undefined local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = param_1[0x16];
  uVar11 = param_2 & 1;
  iVar6 = *(int *)(iVar5 + 0x344);
  iVar9 = *(int *)(iVar5 + 900);
  cipher = *(EVP_CIPHER **)(iVar5 + 0x37c);
  uVar4 = *(uint *)(iVar6 + 0x20);
  iVar8 = *(int *)(iVar5 + 0x38c);
  type = *(EVP_MD **)(iVar5 + 0x380);
  if (uVar11 == 0) {
    if ((*(byte *)(iVar6 + 0x24) & 4) == 0) {
      uVar3 = param_1[0x1f] & 0xfffffffd;
    }
    else {
      uVar3 = param_1[0x1f] | 2;
    }
    param_1[0x1f] = uVar3;
    local_114 = (EVP_CIPHER_CTX *)param_1[0x23];
    if ((local_114 == (EVP_CIPHER_CTX *)0x0) || (bVar1 = true, *(int *)param_1[2] == 0xfeff)) {
      local_114 = EVP_CIPHER_CTX_new();
      param_1[0x23] = (int)local_114;
      if (local_114 != (EVP_CIPHER_CTX *)0x0) {
        if (*(int *)param_1[2] != 0xfeff) {
          bVar1 = false;
          goto LAB_080ae619;
        }
        local_fc = EVP_MD_CTX_create();
        if (local_fc == (EVP_MD_CTX *)0x0) goto LAB_080aea48;
        param_1[0x24] = (int)local_fc;
        bVar1 = false;
        goto LAB_080ae639;
      }
    }
    else {
LAB_080ae619:
      local_fc = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x24,0);
      if (local_fc != (EVP_MD_CTX *)0x0) {
LAB_080ae639:
        if ((COMP_CTX *)param_1[0x25] != (COMP_CTX *)0x0) {
          COMP_CTX_free((COMP_CTX *)param_1[0x25]);
          param_1[0x25] = 0;
        }
        if (iVar8 != 0) {
          pCVar2 = COMP_CTX_new(*(COMP_METHOD **)(iVar8 + 8));
          param_1[0x25] = (int)pCVar2;
          if (pCVar2 == (COMP_CTX *)0x0) {
            ERR_put_error(0x14,0xd1,0x8e,"t1_enc.c",0x1bd);
            goto LAB_080ae9eb;
          }
        }
        if (*param_1 != 0xfeff) {
          iVar5 = param_1[0x16];
          *(undefined4 *)(iVar5 + 0x54) = 0;
          *(undefined4 *)(iVar5 + 0x58) = 0;
        }
        iVar5 = param_1[0x16];
        local_10c = (uchar *)(iVar5 + 0x60);
        local_110 = (size_t *)(iVar5 + 0x5c);
        if (bVar1) goto LAB_080ae5c2;
        goto LAB_080ae6ab;
      }
    }
LAB_080aea48:
    iVar6 = 0x262;
    iVar5 = 0x41;
LAB_080ae9da:
    ERR_put_error(0x14,0xd1,iVar5,"t1_enc.c",iVar6);
LAB_080ae9e9:
    uVar11 = 0;
    goto LAB_080ae9eb;
  }
  if ((*(byte *)(iVar6 + 0x24) & 4) == 0) {
    uVar11 = param_1[0x1f] & 0xfffffffe;
  }
  else {
    uVar11 = param_1[0x1f] | 1;
  }
  param_1[0x1f] = uVar11;
  local_114 = (EVP_CIPHER_CTX *)param_1[0x20];
  bVar1 = true;
  if (local_114 == (EVP_CIPHER_CTX *)0x0) {
    a = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"t1_enc.c",0x17b);
    param_1[0x20] = (int)a;
    if (a == (EVP_CIPHER_CTX *)0x0) goto LAB_080aea48;
    bVar1 = false;
    EVP_CIPHER_CTX_init(a);
    local_114 = (EVP_CIPHER_CTX *)param_1[0x20];
  }
  local_fc = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x21,0);
  if (local_fc == (EVP_MD_CTX *)0x0) goto LAB_080aea48;
  if ((COMP_CTX *)param_1[0x22] != (COMP_CTX *)0x0) {
    COMP_CTX_free((COMP_CTX *)param_1[0x22]);
    param_1[0x22] = 0;
  }
  if (iVar8 != 0) {
    pCVar2 = COMP_CTX_new(*(COMP_METHOD **)(iVar8 + 8));
    param_1[0x22] = (int)pCVar2;
    if (pCVar2 != (COMP_CTX *)0x0) {
      iVar5 = param_1[0x16];
      if (*(int *)(iVar5 + 0x120) == 0) {
        pvVar10 = CRYPTO_malloc(0x4540,"t1_enc.c",0x194);
        *(void **)(iVar5 + 0x120) = pvVar10;
        iVar5 = param_1[0x16];
        if (*(int *)(iVar5 + 0x120) == 0) goto LAB_080aea48;
      }
      goto LAB_080ae593;
    }
    iVar6 = 399;
    iVar5 = 0x8e;
    goto LAB_080ae9da;
  }
  iVar5 = param_1[0x16];
LAB_080ae593:
  if (*param_1 != 0xfeff) {
    *(undefined4 *)(iVar5 + 8) = 0;
    *(undefined4 *)(iVar5 + 0xc) = 0;
    iVar5 = param_1[0x16];
  }
  local_10c = (uchar *)(iVar5 + 0x14);
  local_110 = (size_t *)(iVar5 + 0x10);
  if (bVar1) {
LAB_080ae5c2:
    EVP_CIPHER_CTX_cleanup(local_114);
    iVar5 = param_1[0x16];
  }
LAB_080ae6ab:
  pvVar10 = *(void **)(iVar5 + 0x378);
  __n = *(size_t *)(iVar5 + 0x388);
  uVar4 = uVar4 & 2;
  *local_110 = __n;
  iVar5 = EVP_CIPHER_key_length(cipher);
  if (uVar4 != 0) {
    iVar6 = 5;
    if ((*(byte *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 8) == 0) {
      iVar6 = (*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x14) == 1) + 7;
    }
    if (iVar6 < iVar5) {
      iVar5 = iVar6;
    }
  }
  uVar7 = EVP_CIPHER_flags(cipher);
  local_11c = 4;
  if ((uVar7 & 0xf0007) != 6) {
    local_11c = EVP_CIPHER_iv_length(cipher);
  }
  if ((param_2 == 0x12) || (param_2 == 0x21)) {
    iVar6 = __n * 2;
    bVar1 = true;
    iVar8 = iVar6 + iVar5 * 2;
    __src = pvVar10;
    if (*(int *)(param_1[0x16] + 0x374) < iVar8 + local_11c * 2) goto LAB_080ae9cb;
  }
  else {
    iVar6 = iVar5 + __n * 2;
    bVar1 = false;
    iVar8 = iVar6 + local_11c + iVar5;
    __src = (void *)((int)pvVar10 + __n);
    if (*(int *)(param_1[0x16] + 0x374) < iVar8 + local_11c) {
LAB_080ae9cb:
      iVar6 = 499;
      iVar5 = 0x44;
      goto LAB_080ae9da;
    }
  }
  local_f8 = (uchar *)((int)pvVar10 + iVar8);
  local_108 = (uchar *)((int)pvVar10 + iVar6);
  memcpy(local_10c,__src,__n);
  uVar7 = EVP_CIPHER_flags(cipher);
  if ((uVar7 & 0x200000) == 0) {
    pkey = EVP_PKEY_new_mac_key(iVar9,(ENGINE *)0x0,local_10c,*local_110);
    if ((pkey == (EVP_PKEY *)0x0) ||
       (iVar6 = EVP_DigestSignInit(local_fc,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey), iVar6 < 1
       )) {
      EVP_PKEY_free(pkey);
      iVar6 = 0x1ff;
      iVar5 = 0x44;
      goto LAB_080ae9da;
    }
    EVP_PKEY_free(pkey);
  }
  if (uVar4 != 0) {
    iVar9 = EVP_CIPHER_key_length(cipher);
    iVar6 = param_1[0x16];
    ssl_get_algorithm2(param_1);
    iVar5 = tls1_PRF_constprop_1
                      (iVar6 + 0xc0,0x20,iVar6 + 0xa0,0x20,0,0,local_108,iVar5,local_a0,local_60,
                       iVar9);
    if (iVar5 != 0) {
      local_108 = local_a0;
      if (0 < local_11c) {
        iVar5 = param_1[0x16];
        ssl_get_algorithm2(param_1);
        local_f8 = local_e0;
        iVar5 = tls1_PRF_constprop_1
                          (iVar5 + 0xc0,0x20,iVar5 + 0xa0,0x20,0,0,&empty_15920,0,local_f8,local_c0,
                           local_11c * 2);
        if (iVar5 == 0) goto LAB_080ae9e9;
        if (!bVar1) {
          local_f8 = local_f8 + local_11c;
        }
      }
      goto LAB_080ae8a0;
    }
    goto LAB_080ae9e9;
  }
LAB_080ae8a0:
  *(undefined4 *)(param_1[0x30] + 4) = 0;
  uVar7 = EVP_CIPHER_flags(cipher);
  if ((uVar7 & 0xf0007) == 6) {
    iVar5 = EVP_CipherInit_ex(local_114,cipher,(ENGINE *)0x0,local_108,(uchar *)0x0,param_2 & 2);
    if ((iVar5 == 0) || (iVar5 = EVP_CIPHER_CTX_ctrl(local_114,0x12,local_11c,local_f8), iVar5 == 0)
       ) {
      iVar6 = 0x23b;
      iVar5 = 0x44;
      goto LAB_080ae9da;
    }
LAB_080ae8fc:
    uVar7 = EVP_CIPHER_flags(cipher);
    if (((uVar7 & 0x200000) == 0) ||
       ((*local_110 == 0 ||
        (uVar11 = EVP_CIPHER_CTX_ctrl(local_114,0x17,*local_110,local_10c), uVar11 != 0)))) {
      uVar11 = 1;
      OPENSSL_cleanse(local_a0,0x40);
      OPENSSL_cleanse(local_60,0x40);
      OPENSSL_cleanse(local_e0,0x20);
      OPENSSL_cleanse(local_c0,0x20);
      goto LAB_080ae9eb;
    }
    iVar5 = 0x248;
  }
  else {
    uVar11 = EVP_CipherInit_ex(local_114,cipher,(ENGINE *)0x0,local_108,local_f8,param_2 & 2);
    if (uVar11 != 0) goto LAB_080ae8fc;
    iVar5 = 0x240;
  }
  ERR_put_error(0x14,0xd1,0x44,"t1_enc.c",iVar5);
LAB_080ae9eb:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}

