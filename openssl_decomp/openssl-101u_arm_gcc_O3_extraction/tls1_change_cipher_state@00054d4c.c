
void tls1_change_cipher_state(int *param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  ulong uVar3;
  undefined4 uVar4;
  COMP_CTX *pCVar5;
  EVP_CIPHER_CTX *pEVar6;
  EVP_PKEY *pkey;
  EVP_MD *type;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  EVP_CIPHER *cipher;
  COMP_CTX *pCVar12;
  EVP_CIPHER_CTX *pEVar13;
  void *pvVar14;
  void *__src;
  int iVar15;
  size_t __n;
  uint uVar16;
  char *pcVar17;
  EVP_CIPHER_CTX *local_11c;
  EVP_MD_CTX *local_118;
  int local_114;
  size_t *local_10c;
  uchar *local_108;
  uchar *local_104;
  uchar *local_f8;
  uchar auStack_ec [32];
  undefined auStack_cc [32];
  uchar auStack_ac [64];
  undefined auStack_6c [64];
  int local_2c;
  
  iVar10 = param_1[0x16];
  type = *(EVP_MD **)(iVar10 + 0x380);
  pCVar12 = (COMP_CTX *)(param_2 & 1);
  iVar7 = *(int *)(iVar10 + 900);
  cipher = *(EVP_CIPHER **)(iVar10 + 0x37c);
  iVar15 = *(int *)(iVar10 + 0x38c);
  local_2c = __stack_chk_guard;
  uVar16 = *(uint *)(*(int *)(iVar10 + 0x344) + 0x20);
  uVar11 = *(uint *)(*(int *)(iVar10 + 0x344) + 0x24);
  if (pCVar12 == (COMP_CTX *)0x0) {
    local_11c = (EVP_CIPHER_CTX *)param_1[0x23];
    if ((uVar11 & 4) == 0) {
      uVar11 = param_1[0x1f] & 0xfffffffd;
    }
    else {
      uVar11 = param_1[0x1f] | 2;
    }
    param_1[0x1f] = uVar11;
    if ((local_11c == (EVP_CIPHER_CTX *)0x0) || (*(int *)param_1[2] == 0xfeff)) {
      local_11c = EVP_CIPHER_CTX_new();
      param_1[0x23] = (int)local_11c;
      if (local_11c != (EVP_CIPHER_CTX *)0x0) {
        if (*(int *)param_1[2] != 0xfeff) {
          bVar1 = false;
          goto LAB_0005507e;
        }
        local_118 = EVP_MD_CTX_create();
        if (local_118 == (EVP_MD_CTX *)0x0) goto LAB_000551ac;
        param_1[0x24] = (int)local_118;
        bVar1 = false;
        goto LAB_00055090;
      }
    }
    else {
      bVar1 = true;
LAB_0005507e:
      local_118 = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x24,0);
      if (local_118 != (EVP_MD_CTX *)0x0) {
LAB_00055090:
        if ((COMP_CTX *)param_1[0x25] != (COMP_CTX *)0x0) {
          COMP_CTX_free((COMP_CTX *)param_1[0x25]);
          param_1[0x25] = 0;
        }
        if (iVar15 != 0) {
          pCVar5 = COMP_CTX_new(*(COMP_METHOD **)(iVar15 + 8));
          param_1[0x25] = (int)pCVar5;
          if (pCVar5 == (COMP_CTX *)0x0) {
            iVar10 = 0x1bd;
            goto LAB_000552c6;
          }
        }
        if (*param_1 != 0xfeff) {
          iVar10 = param_1[0x16];
          *(undefined *)(iVar10 + 0x54) = 0;
          *(undefined *)(iVar10 + 0x55) = 0;
          *(undefined *)(iVar10 + 0x56) = 0;
          *(undefined *)(iVar10 + 0x57) = 0;
          *(undefined *)(iVar10 + 0x58) = 0;
          *(undefined *)(iVar10 + 0x59) = 0;
          *(undefined *)(iVar10 + 0x5a) = 0;
          *(undefined *)(iVar10 + 0x5b) = 0;
        }
        iVar10 = param_1[0x16];
        local_108 = (uchar *)(iVar10 + 0x60);
        local_10c = (size_t *)(iVar10 + 0x5c);
        if (bVar1) goto LAB_00055104;
        goto LAB_00054e3c;
      }
    }
LAB_000551ac:
    pCVar12 = (COMP_CTX *)0x0;
    ERR_put_error(0x14,0xd1,0x41,"t1_enc.c",0x262);
    goto LAB_00055174;
  }
  pEVar13 = (EVP_CIPHER_CTX *)param_1[0x20];
  if ((uVar11 & 4) == 0) {
    uVar11 = param_1[0x1f] & 0xfffffffe;
  }
  else {
    uVar11 = param_1[0x1f] | 1;
  }
  param_1[0x1f] = uVar11;
  if (pEVar13 == (EVP_CIPHER_CTX *)0x0) {
    pEVar6 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"t1_enc.c",0x17b);
    param_1[0x20] = (int)pEVar6;
    if (pEVar6 == (EVP_CIPHER_CTX *)0x0) goto LAB_000551ac;
    EVP_CIPHER_CTX_init(pEVar6);
    local_11c = (EVP_CIPHER_CTX *)param_1[0x20];
    pEVar6 = pEVar13;
  }
  else {
    pEVar6 = (EVP_CIPHER_CTX *)0x1;
    local_11c = pEVar13;
  }
  local_118 = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x21,0);
  if (local_118 == (EVP_MD_CTX *)0x0) goto LAB_000551ac;
  if ((COMP_CTX *)param_1[0x22] != (COMP_CTX *)0x0) {
    COMP_CTX_free((COMP_CTX *)param_1[0x22]);
    param_1[0x22] = 0;
  }
  if (iVar15 == 0) {
    iVar10 = param_1[0x16];
  }
  else {
    pCVar12 = COMP_CTX_new(*(COMP_METHOD **)(iVar15 + 8));
    iVar10 = 399;
    param_1[0x22] = (int)pCVar12;
    if (pCVar12 == (COMP_CTX *)0x0) {
LAB_000552c6:
      ERR_put_error(0x14,0xd1,0x8e,"t1_enc.c",iVar10);
      goto LAB_00055174;
    }
    iVar10 = param_1[0x16];
    if (*(int *)(iVar10 + 0x120) == 0) {
      pvVar14 = CRYPTO_malloc(0x4540,"t1_enc.c",0x194);
      *(void **)(iVar10 + 0x120) = pvVar14;
      iVar10 = param_1[0x16];
      if (*(int *)(iVar10 + 0x120) == 0) goto LAB_000551ac;
    }
  }
  if (*param_1 != 0xfeff) {
    *(undefined *)(iVar10 + 8) = 0;
    *(undefined *)(iVar10 + 9) = 0;
    *(undefined *)(iVar10 + 10) = 0;
    *(undefined *)(iVar10 + 0xb) = 0;
    *(undefined *)(iVar10 + 0xc) = 0;
    *(undefined *)(iVar10 + 0xd) = 0;
    *(undefined *)(iVar10 + 0xe) = 0;
    *(undefined *)(iVar10 + 0xf) = 0;
    iVar10 = param_1[0x16];
  }
  local_108 = (uchar *)(iVar10 + 0x14);
  local_10c = (size_t *)(iVar10 + 0x10);
  if (pEVar6 != (EVP_CIPHER_CTX *)0x0) {
LAB_00055104:
    EVP_CIPHER_CTX_cleanup(local_11c);
    iVar10 = param_1[0x16];
  }
LAB_00054e3c:
  __n = *(size_t *)(iVar10 + 0x388);
  uVar16 = uVar16 & 2;
  pvVar14 = *(void **)(iVar10 + 0x378);
  *local_10c = __n;
  iVar10 = EVP_CIPHER_key_length(cipher);
  if (uVar16 != 0) {
    if (*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x20) << 0x1c < 0) {
      iVar15 = 5;
    }
    else if (*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x14) == 1) {
      iVar15 = 8;
    }
    else {
      iVar15 = 7;
    }
    if (iVar15 <= iVar10) {
      iVar10 = iVar15;
    }
  }
  uVar3 = EVP_CIPHER_flags(cipher);
  if ((uVar3 & 0xf0007) == 6) {
    local_114 = 4;
  }
  else {
    local_114 = EVP_CIPHER_iv_length(cipher);
  }
  bVar1 = param_2 == 0x12;
  bVar2 = param_2 == 0x21;
  if (bVar1 || bVar2) {
    iVar15 = __n * 2;
    iVar8 = iVar15 + iVar10 * 2;
    pcVar17 = "client write key";
    iVar9 = iVar8 + local_114 * 2;
    __src = pvVar14;
  }
  else {
    iVar15 = iVar10 + __n * 2;
    iVar8 = local_114 + iVar10 + iVar15;
    pcVar17 = "server write key";
    iVar9 = iVar8 + local_114;
    __src = (void *)((int)pvVar14 + __n);
  }
  local_f8 = (uchar *)((int)pvVar14 + iVar8);
  local_104 = (uchar *)((int)pvVar14 + iVar15);
  if (*(int *)(param_1[0x16] + 0x374) < iVar9) {
    iVar7 = 499;
LAB_00055162:
    pCVar12 = (COMP_CTX *)0x0;
    ERR_put_error(0x14,0xd1,0x44,"t1_enc.c",iVar7);
    goto LAB_00055174;
  }
  memcpy(local_108,__src,__n);
  uVar3 = EVP_CIPHER_flags(cipher);
  if ((uVar3 & 0x200000) == 0) {
    pkey = EVP_PKEY_new_mac_key(iVar7,(ENGINE *)0x0,local_108,*local_10c);
    if ((pkey == (EVP_PKEY *)0x0) ||
       (iVar7 = EVP_DigestSignInit(local_118,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey),
       iVar7 < 1)) {
      pCVar12 = (COMP_CTX *)0x0;
      EVP_PKEY_free(pkey);
      ERR_put_error(0x14,0xd1,0x44,"t1_enc.c",0x1ff);
      goto LAB_00055174;
    }
    EVP_PKEY_free(pkey);
  }
  if (uVar16 != 0) {
    uVar4 = ssl_get_algorithm2(param_1);
    iVar15 = param_1[0x16];
    iVar7 = EVP_CIPHER_key_length(cipher);
    iVar7 = tls1_PRF_constprop_2
                      (uVar4,pcVar17,0x10,iVar15 + 0xc0,0x20,iVar15 + 0xa0,0x20,0,0,local_104,iVar10
                       ,auStack_ac,auStack_6c,iVar7);
    if (iVar7 == 0) {
LAB_00055258:
      pCVar12 = (COMP_CTX *)0x0;
      goto LAB_00055174;
    }
    local_104 = auStack_ac;
    if (0 < local_114) {
      local_f8 = auStack_ec;
      uVar4 = ssl_get_algorithm2(param_1);
      iVar7 = tls1_PRF_constprop_2
                        (uVar4,"IV block",8,param_1[0x16] + 0xc0,0x20,param_1[0x16] + 0xa0,0x20,0,0,
                         &empty_18571,0,local_f8,auStack_cc,local_114 << 1);
      if (iVar7 == 0) goto LAB_00055258;
      if ((param_2 != 0x12 && param_2 != 0x21) && (!bVar1 && !bVar2)) {
        local_f8 = local_f8 + local_114;
      }
    }
  }
  *(undefined4 *)(param_1[0x30] + 4) = 0;
  uVar3 = EVP_CIPHER_flags(cipher);
  if ((uVar3 & 0xf0007) == 6) {
    iVar7 = EVP_CipherInit_ex(local_11c,cipher,(ENGINE *)0x0,local_104,(uchar *)0x0,param_2 & 2);
    if ((iVar7 == 0) || (iVar7 = EVP_CIPHER_CTX_ctrl(local_11c,0x12,local_114,local_f8), iVar7 == 0)
       ) {
      iVar7 = 0x23b;
      goto LAB_00055162;
    }
LAB_0005500a:
    uVar3 = EVP_CIPHER_flags(cipher);
    if (((-1 < (int)(uVar3 << 10)) || (*local_10c == 0)) ||
       (pCVar12 = (COMP_CTX *)EVP_CIPHER_CTX_ctrl(local_11c,0x17,*local_10c,local_108),
       pCVar12 != (COMP_CTX *)0x0)) {
      OPENSSL_cleanse(auStack_ac,0x40);
      pCVar12 = (COMP_CTX *)0x1;
      OPENSSL_cleanse(auStack_6c,0x40);
      OPENSSL_cleanse(auStack_ec,0x20);
      OPENSSL_cleanse(auStack_cc,0x20);
      goto LAB_00055174;
    }
    iVar7 = 0x248;
  }
  else {
    pCVar12 = (COMP_CTX *)
              EVP_CipherInit_ex(local_11c,cipher,(ENGINE *)0x0,local_104,local_f8,param_2 & 2);
    iVar7 = 0x240;
    if (pCVar12 != (COMP_CTX *)0x0) goto LAB_0005500a;
  }
  ERR_put_error(0x14,0xd1,0x44,"t1_enc.c",iVar7);
LAB_00055174:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pCVar12);
}

