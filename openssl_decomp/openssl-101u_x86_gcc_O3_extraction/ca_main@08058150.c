
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

int ca_main(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  uchar *bytes;
  _STACK *p_Var3;
  char *pcVar4;
  BIO *pBVar5;
  BIO_METHOD *pBVar6;
  BIO *pBVar7;
  CONF_METHOD *pCVar8;
  byte *pbVar9;
  char *pcVar10;
  uint uVar11;
  size_t sVar12;
  _func_1084 *p_Var13;
  __int32_t **pp_Var14;
  OPENSSL_STRING *ppcVar15;
  char **ppcVar16;
  ASN1_UTCTIME *s;
  EVP_MD *pEVar17;
  EVP_MD *pEVar18;
  BIGNUM **ppBVar19;
  long lVar20;
  void *pvVar21;
  byte *pbVar22;
  EVP_PKEY *pEVar23;
  X509_NAME *name;
  BIGNUM *pBVar24;
  ASN1_TIME *pAVar25;
  X509_REVOKED *x;
  ASN1_INTEGER *pAVar26;
  X509 *pXVar27;
  EVP_MD *pEVar28;
  uint *puVar29;
  uint *puVar30;
  int iVar31;
  uint uVar32;
  EVP_MD *pEVar33;
  undefined1 *puVar34;
  OPENSSL_STRING *value;
  X509_CRL *x_00;
  CONF_METHOD *pCVar35;
  BIGNUM *pBVar36;
  int iVar37;
  int in_GS_OFFSET;
  undefined uVar38;
  bool bVar39;
  undefined uVar40;
  bool bVar41;
  byte bVar42;
  FILE *pFVar43;
  undefined auStack_44c [8];
  X509_NAME *local_444;
  _STACK *local_440;
  BIGNUM *local_43c;
  EVP_MD *local_438;
  BIGNUM *local_434;
  EVP_MD *local_430;
  BIGNUM *local_42c;
  EVP_MD *local_428;
  EVP_MD *local_424;
  char *local_420;
  undefined4 local_41c;
  int local_418;
  X509 *local_414;
  stack_st_CONF_VALUE *local_410;
  int local_40c;
  void *local_408;
  BIGNUM *local_404;
  EVP_MD *local_400;
  EVP_MD *local_3fc;
  uint local_3f8;
  uint local_3f4;
  int local_3f0;
  void *local_3ec;
  undefined4 local_3e8;
  EVP_MD *local_3e4;
  void *local_3e0;
  EVP_MD *local_3dc;
  int local_3d8;
  EVP_MD *local_3d4;
  X509 *local_3d0;
  uint local_3cc;
  EVP_MD *local_3c8;
  EVP_MD *local_3c4;
  char *local_3c0;
  EVP_MD *local_3bc;
  char *local_3b8;
  undefined4 local_3b4;
  EVP_MD *local_3b0;
  EVP_MD *local_3ac;
  BIGNUM *local_3a8;
  _STACK *local_3a4;
  BIGNUM *local_3a0;
  char *local_39c;
  BIO *local_398;
  BIO *local_394;
  BIO *local_390;
  BIO *local_38c;
  void *local_388;
  char *local_384;
  EVP_PKEY *local_380;
  X509 *local_37c;
  EVP_MD *local_378;
  uint local_374;
  BIGNUM *local_370;
  byte *local_368;
  uint local_364;
  uint local_360;
  EVP_MD *local_35c;
  BIGNUM *local_358;
  EVP_MD *local_354;
  BIGNUM *local_350;
  EVP_MD *local_34c;
  EVP_MD *local_348;
  undefined local_344 [4];
  int local_340;
  undefined local_33c [28];
  OPENSSL_STRING local_320 [3];
  _func_1084 *local_314;
  OPENSSL_STRING local_308 [122];
  uint local_120 [64];
  ulong *local_20;
  
  bVar42 = 0;
  local_368 = (byte *)0x0;
  local_20 = *(ulong **)(in_GS_OFFSET + 0x14);
  local_364 = 0;
  local_360 = 0;
  local_35c = (EVP_MD *)0xffffffff;
  local_358 = (BIGNUM *)0x0;
  local_354 = (EVP_MD *)0x0;
  local_350 = (BIGNUM *)0x0;
  local_34c = (EVP_MD *)0x0;
  local_348 = (EVP_MD *)0x0;
  local_344 = (undefined  [4])0x0;
  signal(0xd,(__sighandler_t)0x1);
  conf = (BIGNUM *)0x0;
  local_368 = (byte *)0x0;
  section = (EVP_MD *)0x0;
  preserve = 0;
  msie_hack = 0;
  if (bio_err == (BIO *)0x0) {
    pBVar6 = BIO_s_file();
    bio_err = BIO_new(pBVar6);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  local_388 = (void *)0x0;
  pEVar33 = (EVP_MD *)(param_1 + -1);
  local_3a8 = (BIGNUM *)(param_2 + 4);
  bVar39 = pEVar33 == (EVP_MD *)0x0;
  if (0 < (int)pEVar33) {
    local_3a4 = (_STACK *)0x0;
    local_3f0 = 0;
    local_418 = 0;
    local_3d8 = 0;
    local_3bc = (EVP_MD *)0x0;
    local_3b8 = (char *)0x0;
    local_3ec = (void *)0x0;
    local_3e8 = 0;
    local_3c8 = (EVP_MD *)0x0;
    local_3b4 = 0;
    local_3a0 = (BIGNUM *)0x1001;
    local_384 = (char *)0x0;
    local_3e4 = (EVP_MD *)0x0;
    local_3b0 = (EVP_MD *)0x0;
    local_3c0 = (char *)0x0;
    local_400 = (EVP_MD *)0x0;
    local_37c = (X509 *)0x0;
    local_404 = (BIGNUM *)0x0;
    local_3dc = (EVP_MD *)0x0;
    local_3e0 = (void *)0x0;
    local_414 = (X509 *)0x3;
    local_3fc = (EVP_MD *)0x0;
    local_380 = (EVP_PKEY *)0x0;
    local_3c4 = (EVP_MD *)0x0;
    local_3d4 = (EVP_MD *)0x0;
    local_378 = (EVP_MD *)0x0;
    local_3f8 = 0;
    local_410 = (stack_st_CONF_VALUE *)0x0;
    local_40c = 0;
    local_3f4 = 0;
    local_374 = 0;
    local_3d0 = (X509 *)0x0;
    local_3cc = 1;
    local_3ac = (EVP_MD *)0x0;
    local_408 = (void *)0x0;
    pBVar36 = local_3a8;
    local_370 = local_3a8;
LAB_080583e9:
    local_3a8 = pBVar36;
    iVar31 = 9;
    pCVar8 = (CONF_METHOD *)local_370->d;
    pCVar35 = pCVar8;
    pcVar4 = "-verbose";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    pBVar36 = local_3a8;
    pBVar24 = local_370;
    if (bVar39) {
      local_374 = 1;
      goto joined_r0x08058415;
    }
    iVar31 = 8;
    pCVar35 = pCVar8;
    pcVar4 = "-config";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_378 = (EVP_MD *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 6;
    pCVar35 = pCVar8;
    pcVar4 = "-name";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      section = (EVP_MD *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 6;
    pCVar35 = pCVar8;
    pcVar4 = "-subj";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_384 = (char *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 6;
    pCVar35 = pCVar8;
    pcVar4 = "-utf8";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      local_3a0 = (BIGNUM *)0x1000;
      goto joined_r0x08058415;
    }
    iVar31 = 0xf;
    pCVar35 = pCVar8;
    pcVar4 = "-create_serial";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      local_3ac = (EVP_MD *)0x1;
      goto joined_r0x08058415;
    }
    iVar31 = 0x10;
    pCVar35 = pCVar8;
    pcVar4 = "-multivalue-rdn";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      local_3b4 = 1;
      goto joined_r0x08058415;
    }
    iVar31 = 0xb;
    pCVar35 = pCVar8;
    pcVar4 = "-startdate";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_3b8 = (char *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 9;
    pCVar35 = pCVar8;
    pcVar4 = "-enddate";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_3bc = (EVP_MD *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 6;
    pCVar35 = pCVar8;
    pcVar4 = "-days";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      pBVar24 = (BIGNUM *)&local_370->top;
      local_354 = (EVP_MD *)strtol((char *)local_370->top,(char **)0x0,10);
      pBVar36 = local_3a8;
      goto joined_r0x08058415;
    }
    local_38c = (BIO *)(0x2d - (uint)*(byte *)&pCVar8->name);
    bVar39 = local_38c == (BIO *)0x0;
    if ((((bVar39) && (bVar39 = *(char *)((int)&pCVar8->name + 1) == 'm', bVar39)) &&
        (bVar39 = *(char *)((int)&pCVar8->name + 2) == 'd', bVar39)) &&
       (bVar39 = *(char *)((int)&pCVar8->name + 3) == '\0', bVar39)) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_3d4 = (EVP_MD *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 8;
    pCVar35 = pCVar8;
    pcVar4 = "-policy";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_3c4 = (EVP_MD *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 9;
    pCVar35 = pCVar8;
    pcVar4 = "-keyfile";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_380 = (EVP_PKEY *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 9;
    pCVar35 = pCVar8;
    pcVar4 = "-keyform";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      pBVar24 = (BIGNUM *)&local_370->top;
      local_414 = (X509 *)str2fmt((void *)local_370->top);
      pBVar36 = local_3a8;
      goto joined_r0x08058415;
    }
    iVar31 = 8;
    pCVar35 = pCVar8;
    pcVar4 = "-passin";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_408 = (void *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 5;
    pCVar35 = pCVar8;
    pcVar4 = "-key";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_368 = (byte *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 6;
    pCVar35 = pCVar8;
    pcVar4 = "-cert";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
      local_3fc = (EVP_MD *)local_370->top;
      pBVar24 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058415;
    }
    iVar31 = 10;
    pCVar35 = pCVar8;
    pcVar4 = "-selfsign";
    do {
      if (iVar31 == 0) break;
      iVar31 = iVar31 + -1;
      bVar39 = *(char *)&pCVar35->name == *pcVar4;
      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      local_3f0 = 1;
      goto joined_r0x08058415;
    }
    bVar39 = local_38c == (BIO *)0x0;
    if (((bVar39) && (bVar39 = *(char *)((int)&pCVar8->name + 1) == 'i', bVar39)) &&
       ((bVar39 = *(char *)((int)&pCVar8->name + 2) == 'n', bVar39 &&
        (bVar39 = *(char *)((int)&pCVar8->name + 3) == '\0', bVar39)))) {
      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
      if (pEVar33 != (EVP_MD *)0x0) {
        local_3d0 = (X509 *)0x1;
        local_3e0 = (void *)local_370->top;
        pBVar24 = (BIGNUM *)&local_370->top;
        goto joined_r0x08058415;
      }
    }
    else {
      iVar31 = 5;
      pCVar35 = pCVar8;
      pcVar4 = "-out";
      do {
        if (iVar31 == 0) break;
        iVar31 = iVar31 + -1;
        bVar39 = *(char *)&pCVar35->name == *pcVar4;
        pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
        pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
      } while (bVar39);
      if (bVar39) {
        pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
        if (pEVar33 != (EVP_MD *)0x0) {
          local_400 = (EVP_MD *)local_370->top;
          pBVar24 = (BIGNUM *)&local_370->top;
          goto joined_r0x08058415;
        }
      }
      else {
        iVar31 = 8;
        pCVar35 = pCVar8;
        pcVar4 = "-outdir";
        do {
          if (iVar31 == 0) break;
          iVar31 = iVar31 + -1;
          bVar39 = *(char *)&pCVar35->name == *pcVar4;
          pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
          pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
        } while (bVar39);
        if (bVar39) {
          pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
          if (pEVar33 != (EVP_MD *)0x0) {
            local_3c0 = (char *)local_370->top;
            pBVar24 = (BIGNUM *)&local_370->top;
            goto joined_r0x08058415;
          }
        }
        else {
          iVar31 = 8;
          pCVar35 = pCVar8;
          pcVar4 = "-sigopt";
          do {
            if (iVar31 == 0) break;
            iVar31 = iVar31 + -1;
            bVar39 = *(char *)&pCVar35->name == *pcVar4;
            pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
            pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
          } while (bVar39);
          if (!bVar39) {
            iVar31 = 8;
            pCVar35 = pCVar8;
            pcVar4 = "-notext";
            do {
              if (iVar31 == 0) break;
              iVar31 = iVar31 + -1;
              bVar39 = *(char *)&pCVar35->name == *pcVar4;
              pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
              pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
            } while (bVar39);
            if (bVar39) {
              local_418 = 1;
            }
            else {
              iVar31 = 7;
              pCVar35 = pCVar8;
              pcVar4 = "-batch";
              do {
                if (iVar31 == 0) break;
                iVar31 = iVar31 + -1;
                bVar39 = *(char *)&pCVar35->name == *pcVar4;
                pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
              } while (bVar39);
              if (bVar39) {
                local_3d8 = 1;
              }
              else {
                iVar31 = 0xc;
                pCVar35 = pCVar8;
                pcVar4 = "-preserveDN";
                do {
                  if (iVar31 == 0) break;
                  iVar31 = iVar31 + -1;
                  bVar39 = *(char *)&pCVar35->name == *pcVar4;
                  pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                  pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                } while (bVar39);
                if (bVar39) {
                  preserve = 1;
                }
                else {
                  iVar31 = 0xb;
                  pCVar35 = pCVar8;
                  pcVar4 = "-noemailDN";
                  do {
                    if (iVar31 == 0) break;
                    iVar31 = iVar31 + -1;
                    bVar39 = *(char *)&pCVar35->name == *pcVar4;
                    pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                    pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                  } while (bVar39);
                  if (bVar39) {
                    local_3cc = 0;
                  }
                  else {
                    iVar31 = 8;
                    pCVar35 = pCVar8;
                    pcVar4 = "-gencrl";
                    do {
                      if (iVar31 == 0) break;
                      iVar31 = iVar31 + -1;
                      bVar39 = *(char *)&pCVar35->name == *pcVar4;
                      pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                    } while (bVar39);
                    if (!bVar39) {
                      iVar31 = 0xb;
                      pCVar35 = pCVar8;
                      pcVar4 = "-msie_hack";
                      do {
                        if (iVar31 == 0) break;
                        iVar31 = iVar31 + -1;
                        bVar39 = *(char *)&pCVar35->name == *pcVar4;
                        pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                        pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                      } while (bVar39);
                      if (bVar39) {
                        msie_hack = 1;
                        goto joined_r0x08058415;
                      }
                      iVar31 = 9;
                      pCVar35 = pCVar8;
                      pcVar4 = "-crldays";
                      do {
                        if (iVar31 == 0) break;
                        iVar31 = iVar31 + -1;
                        bVar39 = *(char *)&pCVar35->name == *pcVar4;
                        pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                        pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                      } while (bVar39);
                      if (bVar39) {
                        pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                        if (pEVar33 != (EVP_MD *)0x0) {
                          pBVar24 = (BIGNUM *)&local_370->top;
                          local_364 = strtol((char *)local_370->top,(char **)0x0,10);
                          pBVar36 = local_3a8;
                          goto joined_r0x08058415;
                        }
                      }
                      else {
                        iVar31 = 10;
                        pCVar35 = pCVar8;
                        pcVar4 = "-crlhours";
                        do {
                          if (iVar31 == 0) break;
                          iVar31 = iVar31 + -1;
                          bVar39 = *(char *)&pCVar35->name == *pcVar4;
                          pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                          pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                        } while (bVar39);
                        if (!bVar39) {
                          iVar31 = 8;
                          pCVar35 = pCVar8;
                          pcVar4 = "-crlsec";
                          do {
                            if (iVar31 == 0) break;
                            iVar31 = iVar31 + -1;
                            bVar39 = *(char *)&pCVar35->name == *pcVar4;
                            pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                            pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                          } while (bVar39);
                          if (bVar39) {
                            pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                            if (pEVar33 != (EVP_MD *)0x0) {
                              pBVar24 = (BIGNUM *)&local_370->top;
                              local_3f8 = strtol((char *)local_370->top,(char **)0x0,10);
                              pBVar36 = local_3a8;
                              goto joined_r0x08058415;
                            }
                            goto LAB_08058b55;
                          }
                          iVar31 = 9;
                          pCVar35 = pCVar8;
                          pcVar4 = "-infiles";
                          do {
                            if (iVar31 == 0) break;
                            iVar31 = iVar31 + -1;
                            bVar39 = *(char *)&pCVar35->name == *pcVar4;
                            pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                            pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                          } while (bVar39);
                          if (!bVar39) {
                            iVar31 = 9;
                            pCVar35 = pCVar8;
                            pcVar4 = "-ss_cert";
                            do {
                              if (iVar31 == 0) break;
                              iVar31 = iVar31 + -1;
                              bVar39 = *(char *)&pCVar35->name == *pcVar4;
                              pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                              pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                            } while (bVar39);
                            if (bVar39) {
                              pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                              if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
                              local_3d0 = (X509 *)0x1;
                              local_404 = (BIGNUM *)local_370->top;
                              pBVar24 = (BIGNUM *)&local_370->top;
                            }
                            else {
                              iVar31 = 7;
                              pCVar35 = pCVar8;
                              pcVar4 = "-spkac";
                              do {
                                if (iVar31 == 0) break;
                                iVar31 = iVar31 + -1;
                                bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                              } while (bVar39);
                              if (bVar39) {
                                pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                                if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
                                local_3d0 = (X509 *)0x1;
                                local_3dc = (EVP_MD *)local_370->top;
                                pBVar24 = (BIGNUM *)&local_370->top;
                              }
                              else {
                                iVar31 = 8;
                                pCVar35 = pCVar8;
                                pcVar4 = "-revoke";
                                do {
                                  if (iVar31 == 0) break;
                                  iVar31 = iVar31 + -1;
                                  bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                  pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                  pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                } while (bVar39);
                                if (bVar39) {
                                  pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                                  if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
                                  local_40c = 1;
                                  local_3e0 = (void *)local_370->top;
                                  pBVar24 = (BIGNUM *)&local_370->top;
                                }
                                else {
                                  iVar31 = 0xc;
                                  pCVar35 = pCVar8;
                                  pcVar4 = "-extensions";
                                  do {
                                    if (iVar31 == 0) break;
                                    iVar31 = iVar31 + -1;
                                    bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                    pCVar35 = (CONF_METHOD *)((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                    pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                  } while (bVar39);
                                  if (bVar39) {
                                    pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                                    if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
                                    local_3b0 = (EVP_MD *)local_370->top;
                                    pBVar24 = (BIGNUM *)&local_370->top;
                                  }
                                  else {
                                    iVar31 = 9;
                                    pCVar35 = pCVar8;
                                    pcVar4 = "-extfile";
                                    do {
                                      if (iVar31 == 0) break;
                                      iVar31 = iVar31 + -1;
                                      bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                      pCVar35 = (CONF_METHOD *)
                                                ((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                    } while (bVar39);
                                    if (bVar39) {
                                      pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                                      if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
                                      local_3e4 = (EVP_MD *)local_370->top;
                                      pBVar24 = (BIGNUM *)&local_370->top;
                                    }
                                    else {
                                      iVar31 = 8;
                                      pCVar35 = pCVar8;
                                      pcVar4 = "-status";
                                      do {
                                        if (iVar31 == 0) break;
                                        iVar31 = iVar31 + -1;
                                        bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                        pCVar35 = (CONF_METHOD *)
                                                  ((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                        pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                      } while (bVar39);
                                      if (bVar39) {
                                        pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                                        if (pEVar33 == (EVP_MD *)0x0) goto LAB_08058b55;
                                        local_37c = (X509 *)local_370->top;
                                        pBVar24 = (BIGNUM *)&local_370->top;
                                      }
                                      else {
                                        iVar31 = 10;
                                        pCVar35 = pCVar8;
                                        pcVar4 = "-updatedb";
                                        do {
                                          if (iVar31 == 0) break;
                                          iVar31 = iVar31 + -1;
                                          bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                          pCVar35 = (CONF_METHOD *)
                                                    ((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                          pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                        } while (bVar39);
                                        if (!bVar39) {
                                          iVar31 = 9;
                                          pCVar35 = pCVar8;
                                          pcVar4 = "-crlexts";
                                          do {
                                            if (iVar31 == 0) break;
                                            iVar31 = iVar31 + -1;
                                            bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                            pCVar35 = (CONF_METHOD *)
                                                      ((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                            pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                          } while (bVar39);
                                          if (bVar39) {
                                            pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                                            if (pEVar33 != (EVP_MD *)0x0) {
                                              local_3c8 = (EVP_MD *)local_370->top;
                                              pBVar24 = (BIGNUM *)&local_370->top;
                                              goto joined_r0x08058415;
                                            }
                                          }
                                          else {
                                            iVar31 = 0xc;
                                            pCVar35 = pCVar8;
                                            pcVar4 = "-crl_reason";
                                            do {
                                              if (iVar31 == 0) break;
                                              iVar31 = iVar31 + -1;
                                              bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                              pCVar35 = (CONF_METHOD *)
                                                        ((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                              pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                            } while (bVar39);
                                            if (bVar39) {
                                              pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                                              if (pEVar33 != (EVP_MD *)0x0) {
                                                local_3e8 = 1;
                                                local_3ec = (void *)local_370->top;
                                                pBVar24 = (BIGNUM *)&local_370->top;
                                                goto joined_r0x08058415;
                                              }
                                            }
                                            else {
                                              iVar31 = 10;
                                              pCVar35 = pCVar8;
                                              pcVar4 = "-crl_hold";
                                              do {
                                                if (iVar31 == 0) break;
                                                iVar31 = iVar31 + -1;
                                                bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                                pCVar35 = (CONF_METHOD *)
                                                          ((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                                pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                              } while (bVar39);
                                              if (bVar39) {
                                                pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                                                if (pEVar33 != (EVP_MD *)0x0) {
                                                  local_3e8 = 2;
                                                  local_3ec = (void *)local_370->top;
                                                  pBVar24 = (BIGNUM *)&local_370->top;
                                                  goto joined_r0x08058415;
                                                }
                                              }
                                              else {
                                                iVar31 = 0x10;
                                                pCVar35 = pCVar8;
                                                pcVar4 = "-crl_compromise";
                                                do {
                                                  if (iVar31 == 0) break;
                                                  iVar31 = iVar31 + -1;
                                                  bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                                  pCVar35 = (CONF_METHOD *)
                                                            ((int)pCVar35 + (uint)bVar42 * -2 + 1);
                                                  pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                                } while (bVar39);
                                                if (bVar39) {
                                                  pEVar33 = (EVP_MD *)
                                                            ((int)&pEVar33[-1].md_ctrl + 3);
                                                  if (pEVar33 != (EVP_MD *)0x0) {
                                                    local_3e8 = 3;
                                                    local_3ec = (void *)local_370->top;
                                                    pBVar24 = (BIGNUM *)&local_370->top;
                                                    goto joined_r0x08058415;
                                                  }
                                                }
                                                else {
                                                  iVar31 = 0x13;
                                                  pCVar35 = pCVar8;
                                                  pcVar4 = "-crl_CA_compromise";
                                                  do {
                                                    if (iVar31 == 0) break;
                                                    iVar31 = iVar31 + -1;
                                                    bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                                    pCVar35 = (CONF_METHOD *)
                                                              ((int)pCVar35 + (uint)bVar42 * -2 + 1)
                                                    ;
                                                    pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                                  } while (bVar39);
                                                  if (bVar39) {
                                                    pEVar33 = (EVP_MD *)
                                                              ((int)&pEVar33[-1].md_ctrl + 3);
                                                    if (pEVar33 != (EVP_MD *)0x0) {
                                                      local_3e8 = 4;
                                                      local_3ec = (void *)local_370->top;
                                                      pBVar24 = (BIGNUM *)&local_370->top;
                                                      goto joined_r0x08058415;
                                                    }
                                                  }
                                                  else {
                                                    iVar31 = 8;
                                                    pCVar35 = pCVar8;
                                                    pcVar4 = "-engine";
                                                    do {
                                                      if (iVar31 == 0) break;
                                                      iVar31 = iVar31 + -1;
                                                      bVar39 = *(char *)&pCVar35->name == *pcVar4;
                                                      pCVar35 = (CONF_METHOD *)
                                                                ((int)pCVar35 +
                                                                (uint)bVar42 * -2 + 1);
                                                      pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
                                                    } while (bVar39);
                                                    if ((bVar39) &&
                                                       (pEVar33 = (EVP_MD *)
                                                                  ((int)&pEVar33[-1].md_ctrl + 3),
                                                       pEVar33 != (EVP_MD *)0x0)) {
                                                      local_388 = (void *)local_370->top;
                                                      pBVar24 = (BIGNUM *)&local_370->top;
                                                      goto joined_r0x08058415;
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                          goto LAB_08058b55;
                                        }
                                        local_410 = (stack_st_CONF_VALUE *)0x1;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            goto joined_r0x08058415;
                          }
                          pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                          local_3d0 = (X509 *)0x1;
                          local_3a8 = (BIGNUM *)&local_370->top;
                          goto LAB_08058423;
                        }
                        pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
                        if (pEVar33 != (EVP_MD *)0x0) {
                          pBVar24 = (BIGNUM *)&local_370->top;
                          local_360 = strtol((char *)local_370->top,(char **)0x0,10);
                          pBVar36 = local_3a8;
                          goto joined_r0x08058415;
                        }
                      }
                      goto LAB_08058b55;
                    }
                    local_3f4 = 1;
                  }
                }
              }
            }
joined_r0x08058415:
            pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
            bVar39 = pEVar33 == (EVP_MD *)0x0;
            local_3a8 = (BIGNUM *)&pBVar24->top;
            local_370 = local_3a8;
            if (bVar39) goto LAB_08058423;
            goto LAB_080583e9;
          }
          pEVar33 = (EVP_MD *)((int)&pEVar33[-1].md_ctrl + 3);
          if (pEVar33 != (EVP_MD *)0x0) {
            if ((local_3a4 == (_STACK *)0x0) &&
               (local_3a4 = sk_new_null(), local_3a4 == (_STACK *)0x0)) {
              pCVar8 = (CONF_METHOD *)local_370->d;
            }
            else {
              pBVar24 = (BIGNUM *)&local_370->top;
              iVar31 = sk_push(local_3a4,(void *)local_370->top);
              pBVar36 = local_3a8;
              if (iVar31 != 0) goto joined_r0x08058415;
              pCVar8 = (CONF_METHOD *)local_370->top;
            }
          }
        }
      }
    }
LAB_08058b55:
    puVar34 = ca_usage;
    BIO_printf(bio_err,"unknown option %s\n",pCVar8);
    iVar31 = ca_usage._0_4_;
    while (iVar31 != 0) {
      puVar34 = (undefined1 *)((int)puVar34 + 4);
      BIO_printf(bio_err,"%s",iVar31);
      iVar31 = *(int *)puVar34;
    }
    goto LAB_080584bd;
  }
  local_3f0 = 0;
  local_418 = 0;
  local_3d8 = 0;
  local_3bc = (EVP_MD *)0x0;
  local_3b8 = (char *)0x0;
  local_3ec = (void *)0x0;
  local_3e8 = 0;
  local_3c8 = (EVP_MD *)0x0;
  local_3b4 = 0;
  local_3a0 = (BIGNUM *)0x1001;
  local_384 = (char *)0x0;
  local_3e4 = (EVP_MD *)0x0;
  local_3b0 = (EVP_MD *)0x0;
  local_3c0 = (char *)0x0;
  local_400 = (EVP_MD *)0x0;
  local_37c = (X509 *)0x0;
  local_404 = (BIGNUM *)0x0;
  local_3dc = (EVP_MD *)0x0;
  local_3e0 = (void *)0x0;
  local_414 = (X509 *)0x3;
  local_3fc = (EVP_MD *)0x0;
  local_380 = (EVP_PKEY *)0x0;
  local_3c4 = (EVP_MD *)0x0;
  local_3d4 = (EVP_MD *)0x0;
  local_378 = (EVP_MD *)0x0;
  local_3f8 = 0;
  local_410 = (stack_st_CONF_VALUE *)0x0;
  local_40c = 0;
  local_3f4 = 0;
  local_374 = 0;
  local_3cc = 1;
  local_3ac = (EVP_MD *)0x0;
  local_408 = (void *)0x0;
  local_3a4 = (_STACK *)0x0;
  local_3d0 = (X509 *)0x0;
LAB_08058423:
  ERR_load_crypto_strings();
  if (((local_378 == (EVP_MD *)0x0) &&
      (local_378 = (EVP_MD *)getenv("OPENSSL_CONF"), local_378 == (EVP_MD *)0x0)) &&
     (local_378 = (EVP_MD *)getenv("SSLEAY_CONF"), local_378 == (EVP_MD *)0x0)) {
    local_370 = (BIGNUM *)X509_get_default_cert_area();
    sVar12 = strlen((char *)local_370);
    sVar12 = sVar12 + 0xd;
    pBVar36 = (BIGNUM *)CRYPTO_malloc(sVar12,"ca.c",0x232);
    if (pBVar36 == (BIGNUM *)0x0) {
      x_00 = (X509_CRL *)0x0;
      iVar31 = 1;
      BIO_printf(bio_err,"Out of memory\n");
      local_39c = (char *)0x0;
      local_370 = (BIGNUM *)0x0;
      local_378 = (EVP_MD *)0x0;
      local_394 = (BIO *)0x0;
      local_38c = (BIO *)0x0;
      local_390 = (BIO *)0x0;
      local_398 = (BIO *)0x0;
      local_37c = (X509 *)0x0;
      local_380 = (EVP_PKEY *)0x0;
      local_388 = (void *)0x0;
      goto LAB_0805852a;
    }
    BUF_strlcpy((char *)pBVar36,(char *)local_370,sVar12);
    BUF_strlcat((char *)pBVar36,"/",sVar12);
    BUF_strlcat((char *)pBVar36,"openssl.cnf",sVar12);
    BIO_printf(bio_err,"Using configuration from %s\n",pBVar36);
    conf = (BIGNUM *)NCONF_new((CONF_METHOD *)0x0);
    local_370 = (BIGNUM *)&local_35c;
    iVar31 = NCONF_load((CONF *)conf,(char *)pBVar36,(long *)local_370);
    pBVar24 = pBVar36;
    if (iVar31 < 1) goto LAB_08058485;
    CRYPTO_free(pBVar36);
LAB_08058882:
    iVar31 = load_config(bio_err,conf);
    if (iVar31 == 0) goto LAB_080584bd;
    local_41c = setup_engine(bio_err,local_388,0);
    if ((section == (EVP_MD *)0x0) &&
       (section = (EVP_MD *)NCONF_get_string((CONF *)conf,"ca","default_ca"),
       section == (EVP_MD *)0x0)) {
      BIO_printf(bio_err,"variable lookup failed for %s::%s\n","ca","default_ca");
      goto LAB_080584bd;
    }
    if (conf != (BIGNUM *)0x0) {
      pcVar4 = NCONF_get_string((CONF *)conf,(char *)0x0,"oid_file");
      if ((pcVar4 == (char *)0x0) || (pBVar5 = BIO_new_file(pcVar4,"r"), pBVar5 == (BIO *)0x0)) {
        ERR_clear_error();
      }
      else {
        OBJ_create_objects(pBVar5);
        BIO_free(pBVar5);
      }
      iVar31 = add_oid_section(bio_err,conf);
      if (iVar31 == 0) {
        ERR_print_errors(bio_err);
        goto LAB_080584bd;
      }
    }
    local_39c = NCONF_get_string((CONF *)conf,"ca","RANDFILE");
    if (local_39c == (char *)0x0) {
      ERR_clear_error();
    }
    app_RAND_load_file(local_39c,bio_err,0);
    pcVar4 = NCONF_get_string((CONF *)conf,(char *)section,"string_mask");
    if (pcVar4 != (char *)0x0) {
      iVar31 = ASN1_STRING_set_default_mask_asc(pcVar4);
      if (iVar31 != 0) goto LAB_080589b9;
      BIO_printf(bio_err,"Invalid global string mask setting %s\n",pcVar4);
      goto LAB_080584c7;
    }
    ERR_clear_error();
LAB_080589b9:
    if (local_3a0 == (BIGNUM *)0x1000) {
LAB_08058a00:
      local_3a0 = (BIGNUM *)0x1000;
    }
    else {
      pcVar4 = NCONF_get_string((CONF *)conf,(char *)section,"utf8");
      if (pcVar4 == (char *)0x0) {
        ERR_clear_error();
      }
      else if ((((*pcVar4 == 'y') && (pcVar4[1] == 'e')) && (pcVar4[2] == 's')) &&
              (pcVar4[3] == '\0')) goto LAB_08058a00;
    }
    local_340 = 1;
    pcVar4 = NCONF_get_string((CONF *)conf,(char *)section,"unique_subject");
    if (pcVar4 == (char *)0x0) {
      ERR_clear_error();
    }
    else {
      local_340 = parse_yesno(pcVar4,1);
    }
    pBVar6 = BIO_s_file();
    pBVar5 = BIO_new(pBVar6);
    local_398 = pBVar5;
    pBVar6 = BIO_s_file();
    pBVar7 = BIO_new(pBVar6);
    local_390 = pBVar7;
    pBVar6 = BIO_s_file();
    local_38c = BIO_new(pBVar6);
    pBVar6 = BIO_s_file();
    local_394 = BIO_new(pBVar6);
    if (((pBVar5 == (BIO *)0x0) || (pBVar7 == (BIO *)0x0)) ||
       ((local_38c == (BIO *)0x0 || (local_394 == (BIO *)0x0)))) {
      ERR_print_errors(bio_err);
      local_378 = (EVP_MD *)0x0;
    }
    else {
      if (local_37c == (X509 *)0x0) {
        if ((local_380 == (EVP_PKEY *)0x0) &&
           (local_380 = (EVP_PKEY *)NCONF_get_string((CONF *)conf,(char *)section,"private_key"),
           local_380 == (EVP_PKEY *)0x0)) {
          pcVar4 = "private_key";
          goto LAB_0805b66c;
        }
        local_388 = (void *)0x0;
        if (local_368 == (byte *)0x0) {
          iVar31 = app_passwd(bio_err,local_408,0,&local_368,0);
          if (iVar31 == 0) {
            x_00 = (X509_CRL *)0x0;
            pBVar36 = (BIGNUM *)0x0;
            iVar31 = 1;
            BIO_printf(bio_err,"Error getting password\n");
            local_370 = (BIGNUM *)0x0;
            local_378 = (EVP_MD *)0x0;
            local_37c = (X509 *)0x0;
            local_380 = (EVP_PKEY *)0x0;
            local_388 = (void *)0x1;
            goto LAB_0805852a;
          }
          local_388 = (void *)0x1;
        }
        pcVar4 = "CA private key";
        local_380 = (EVP_PKEY *)
                    load_key(bio_err,local_380,local_414,0,local_368,local_41c,"CA private key");
        pbVar9 = local_368;
        if (local_368 != (byte *)0x0) {
          sVar12 = strlen((char *)local_368);
          OPENSSL_cleanse(pbVar9,sVar12);
        }
        if (local_380 == (EVP_PKEY *)0x0) {
LAB_0805b6ff:
          local_370 = (BIGNUM *)0x0;
          x_00 = (X509_CRL *)0x0;
          local_378 = (EVP_MD *)0x0;
          local_37c = (X509 *)0x0;
          pBVar36 = (BIGNUM *)0x0;
          iVar31 = 1;
          goto LAB_0805852a;
        }
        if ((((local_3f0 == 0) || (local_3dc != (EVP_MD *)0x0)) || (local_404 != (BIGNUM *)0x0)) ||
           (local_37c = (X509 *)0x0, local_3f4 != 0)) {
          if (local_3fc == (EVP_MD *)0x0) {
            pcVar4 = "certificate";
            local_3fc = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"certificate");
            if (local_3fc == (EVP_MD *)0x0) {
              BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,"certificate");
              goto LAB_0805b6ff;
            }
          }
          local_37c = (X509 *)load_cert(bio_err,local_3fc,3,0,local_41c,"CA certificate");
          if (local_37c == (X509 *)0x0) goto LAB_08059234;
          iVar31 = X509_check_private_key(local_37c,local_380);
          if (iVar31 != 0) {
            local_414 = local_37c;
            if (local_3f0 != 0) goto LAB_08059068;
            goto LAB_08059072;
          }
          pcVar10 = "CA certificate and CA private key do not match\n";
LAB_0805972f:
          BIO_printf(bio_err,pcVar10,pcVar4);
LAB_08059234:
          local_370 = (BIGNUM *)0x0;
          x_00 = (X509_CRL *)0x0;
          local_378 = (EVP_MD *)0x0;
LAB_0805924a:
          pBVar36 = (BIGNUM *)0x0;
        }
        else {
LAB_08059068:
          local_414 = (X509 *)0x0;
LAB_08059072:
          pbVar9 = (byte *)NCONF_get_string((CONF *)conf,"ca","preserve");
          if (pbVar9 == (byte *)0x0) {
            ERR_clear_error();
          }
          else if ((*pbVar9 & 0xdf) == 0x59) {
            preserve = 1;
          }
          pbVar9 = (byte *)NCONF_get_string((CONF *)conf,"ca","msie_hack");
          if (pbVar9 == (byte *)0x0) {
            ERR_clear_error();
          }
          else if ((*pbVar9 & 0xdf) == 0x59) {
            msie_hack = 1;
          }
          pcVar4 = NCONF_get_string((CONF *)conf,(char *)section,"name_opt");
          if ((EVP_MD *)pcVar4 == (EVP_MD *)0x0) {
            ERR_clear_error();
            local_408 = (void *)0x1;
          }
          else {
            iVar31 = set_name_ex(&local_350,pcVar4);
            local_408 = (void *)0x0;
            if (iVar31 == 0) {
              pcVar10 = "Invalid name options: \"%s\"\n";
              goto LAB_0805972f;
            }
          }
          pcVar4 = NCONF_get_string((CONF *)conf,(char *)section,"cert_opt");
          if ((EVP_MD *)pcVar4 == (EVP_MD *)0x0) {
            ERR_clear_error();
          }
          else {
            iVar31 = set_cert_ex(&local_34c,pcVar4);
            local_408 = (void *)0x0;
            if (iVar31 == 0) {
              pcVar10 = "Invalid certificate options: \"%s\"\n";
              goto LAB_0805972f;
            }
          }
          pcVar4 = NCONF_get_string((CONF *)conf,(char *)section,"copy_extensions");
          if ((EVP_MD *)pcVar4 == (EVP_MD *)0x0) {
            ERR_clear_error();
          }
          else {
            iVar31 = set_ext_copy(&local_348,pcVar4);
            if (iVar31 == 0) {
              pcVar10 = "Invalid extension copy option: \"%s\"\n";
              goto LAB_0805972f;
            }
          }
          if ((local_3c0 == (char *)0x0) && (local_3d0 != (X509 *)0x0)) {
            pcVar4 = "new_certs_dir";
            pcVar10 = NCONF_get_string((CONF *)conf,(char *)section,"new_certs_dir");
            local_3c0 = pcVar10;
            if (pcVar10 == (char *)0x0) {
              pcVar10 = 
              "there needs to be defined a directory for new certificate to be placed in\n";
              goto LAB_0805972f;
            }
            iVar31 = access(pcVar10,7);
            if (iVar31 == 0) {
              iVar31 = app_isdir(local_3c0);
              pcVar4 = local_3c0;
              if (0 < iVar31) goto LAB_0805973f;
              BIO_printf(bio_err,"%s need to be a directory\n",local_3c0);
              perror(pcVar4);
            }
            else {
              BIO_printf(bio_err,"I am unable to access the %s directory\n",pcVar10);
              perror(pcVar10);
            }
            goto LAB_08059234;
          }
LAB_0805973f:
          pcVar4 = "database";
          local_3fc = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"database");
          if (local_3fc == (EVP_MD *)0x0) {
            pcVar10 = "variable lookup failed for %s::%s\n";
            pcVar4 = (char *)section;
            goto LAB_0805972f;
          }
          local_378 = (EVP_MD *)load_index(local_3fc,local_344 + 4);
          if (local_378 == (EVP_MD *)0x0) {
LAB_08059895:
            local_370 = (BIGNUM *)0x0;
LAB_0805989f:
            x_00 = (X509_CRL *)0x0;
            goto LAB_0805924a;
          }
          for (iVar37 = 0; iVar31 = sk_num(*(_STACK **)((int)local_378->pkey_type + 4)),
              pBVar5 = local_390, iVar37 < iVar31; iVar37 = iVar37 + 1) {
            ppcVar16 = (char **)sk_value(*(_STACK **)((int)local_378->pkey_type + 4),iVar37);
            if (**ppcVar16 == 'R') {
              iVar31 = make_revoked(0,ppcVar16[2]);
              if (iVar31 == 0) {
                pcVar10 = " in entry %d\n";
                pcVar4 = (char *)(iVar37 + 1);
                goto LAB_08059887;
              }
            }
            else if (*ppcVar16[2] != '\0') {
              pcVar10 = "entry %d: not revoked yet, but has a revocation date\n";
              pcVar4 = (char *)(iVar37 + 1);
              goto LAB_08059887;
            }
            iVar31 = ASN1_TIME_set_string((ASN1_TIME *)0x0,ppcVar16[1]);
            if (iVar31 == 0) {
              pcVar10 = "entry %d: invalid expiry date\n";
              pcVar4 = (char *)(iVar37 + 1);
              goto LAB_08059887;
            }
            pbVar22 = (byte *)ppcVar16[3];
            uVar11 = strlen((char *)pbVar22);
            pbVar9 = pbVar22;
            if (*pbVar22 == 0x2d) {
              pbVar9 = pbVar22 + 1;
              uVar11 = uVar11 - 1;
            }
            if (((int)uVar11 < 2) || ((uVar11 & 1) != 0)) {
              pcVar10 = "entry %d: bad serial number length (%d)\n";
              pcVar4 = (char *)(iVar37 + 1);
              goto LAB_08059887;
            }
            while( true ) {
              bVar2 = *pbVar9;
              if (bVar2 == 0) break;
              if ((5 < (byte)((bVar2 & 0xdf) + 0xbf)) && (9 < (byte)(bVar2 - 0x30))) {
                x_00 = (X509_CRL *)0x0;
                pBVar36 = (BIGNUM *)0x0;
                iVar31 = 1;
                BIO_printf(bio_err,
                           "entry %d: bad serial number characters, char pos %ld, char is \'%c\'\n",
                           iVar37 + 1,(int)pbVar9 - (int)pbVar22,(int)(char)bVar2);
                local_370 = (BIGNUM *)0x0;
                goto LAB_0805852a;
              }
              pbVar9 = pbVar9 + 1;
            }
          }
          if (local_374 != 0) {
            BIO_ctrl(local_390,0x6a,0x10,stdout);
            pEVar18 = local_378;
            TXT_DB_write(pBVar5,(TXT_DB *)local_378->pkey_type);
            pcVar4 = (char *)sk_num(*(_STACK **)((int)pEVar18->pkey_type + 4));
            BIO_printf(bio_err,"%d entries loaded from the database\n",pcVar4);
            BIO_printf(bio_err,"generating index\n");
          }
          iVar31 = index_index(local_378);
          if (iVar31 == 0) goto LAB_08059895;
          if (local_410 != (stack_st_CONF_VALUE *)0x0) {
            if (local_374 != 0) {
              pcVar4 = (char *)local_3fc;
              BIO_printf(bio_err,"Updating %s ...\n",local_3fc);
            }
            s = ASN1_UTCTIME_new();
            if (s != (ASN1_UTCTIME *)0x0) {
              pEVar17 = (EVP_MD *)X509_gmtime_adj(s,0);
              pcVar4 = (char *)0x9da;
              local_410 = (stack_st_CONF_VALUE *)pEVar17->type;
              local_424 = pEVar17;
              pEVar18 = (EVP_MD *)
                        CRYPTO_malloc((int)((int)&(local_410->stack).num + 1),"ca.c",0x9da);
              local_428 = pEVar18;
              if (pEVar18 != (EVP_MD *)0x0) {
                uVar38 = auStack_44c < &DAT_00000004;
                uVar40 = &stack0x00000000 == (undefined *)0x450;
                memcpy(pEVar18,(uchar *)pEVar17->md_size,pEVar17->type);
                iVar31 = 2;
                local_410 = (stack_st_CONF_VALUE *)0x0;
                local_420 = (char *)0x0;
                *(undefined *)((int)pEVar18->required_pkey_type + pEVar17->type + -0x2c) = 0;
                pbVar9 = &DAT_081ede7c;
                do {
                  if (iVar31 == 0) break;
                  iVar31 = iVar31 + -1;
                  uVar38 = *(byte *)&pEVar18->type < *pbVar9;
                  uVar40 = *(byte *)&pEVar18->type == *pbVar9;
                  pEVar18 = (EVP_MD *)((int)pEVar18 + (uint)bVar42 * -2 + 1);
                  pbVar9 = pbVar9 + (uint)bVar42 * -2 + 1;
                } while ((bool)uVar40);
                local_42c = (BIGNUM *)(int)(char)((!(bool)uVar38 && !(bool)uVar40) - uVar38);
                local_434 = local_3a8;
                local_430 = pEVar33;
                while (iVar31 = sk_num(*(_STACK **)((int)local_378->pkey_type + 4)),
                      pEVar33 = local_430, (int)local_420 < iVar31) {
                  ppBVar19 = (BIGNUM **)
                             sk_value(*(_STACK **)((int)local_378->pkey_type + 4),(int)local_420);
                  local_3a8 = *ppBVar19;
                  bVar39 = *(byte *)&local_3a8->d < 0x56;
                  bVar41 = *(char *)&local_3a8->d == 'V';
                  if (bVar41) {
                    iVar31 = 2;
                    pBVar36 = ppBVar19[1];
                    pbVar9 = &DAT_081ede7c;
                    do {
                      if (iVar31 == 0) break;
                      iVar31 = iVar31 + -1;
                      bVar39 = *(byte *)&pBVar36->d < *pbVar9;
                      bVar41 = *(byte *)&pBVar36->d == *pbVar9;
                      pBVar36 = (BIGNUM *)((int)pBVar36 + (uint)bVar42 * -2 + 1);
                      pbVar9 = pbVar9 + (uint)bVar42 * -2 + 1;
                    } while (bVar41);
                    if ((char)((!bVar39 && !bVar41) - bVar39) < '\x01') {
                      if ((int)local_42c < 1) goto LAB_0805b90c;
                    }
                    else {
                      if (0 < (int)local_42c) {
LAB_0805b90c:
                        iVar31 = strcmp((char *)ppBVar19[1],(char *)local_428);
                        if (0 < iVar31) goto LAB_08059aae;
                      }
                      *(undefined *)&local_3a8->d = 0x45;
                      *(undefined *)((int)&(*ppBVar19)->d + 1) = 0;
                      local_410 = (stack_st_CONF_VALUE *)((int)&(local_410->stack).num + 1);
                      BIO_printf(bio_err,"%s=Expired\n",ppBVar19[3]);
                    }
                  }
LAB_08059aae:
                  local_420 = local_420 + 1;
                }
                local_3a8 = local_434;
                ASN1_UTCTIME_free((ASN1_UTCTIME *)local_424);
                CRYPTO_free(local_428);
                if (local_410 == (stack_st_CONF_VALUE *)0x0) {
                  if (local_374 != 0) {
                    BIO_printf(bio_err,"No entries found to mark expired\n");
                  }
                }
                else {
                  iVar31 = save_index(local_3fc,&DAT_081eaee6,local_378);
                  if ((iVar31 == 0) ||
                     (iVar31 = rotate_index(local_3fc,&DAT_081eaee6,"old"), iVar31 == 0))
                  goto LAB_08059895;
                  if (local_374 != 0) {
                    BIO_printf(bio_err,"Done. %d entries marked as expired\n",local_410);
                  }
                }
                goto LAB_08059b24;
              }
              ASN1_UTCTIME_free((ASN1_UTCTIME *)local_424);
              CRYPTO_free((void *)0x0);
            }
            pcVar10 = "Malloc failure\n";
LAB_08059887:
            BIO_printf(bio_err,pcVar10,pcVar4);
            goto LAB_08059895;
          }
LAB_08059b24:
          pEVar18 = local_3e4;
          if (local_3e4 != (EVP_MD *)0x0) {
            extconf = NCONF_new((CONF_METHOD *)0x0);
            iVar31 = NCONF_load(extconf,(char *)pEVar18,(long *)local_370);
            if (iVar31 < 1) {
              if ((int)local_35c < 1) {
                pcVar10 = "ERROR: loading the config file \'%s\'\n";
                pcVar4 = (char *)local_3e4;
              }
              else {
                pcVar10 = "ERROR: on line %ld of config file \'%s\'\n";
                pcVar4 = (char *)local_35c;
              }
              goto LAB_08059887;
            }
            if (local_374 != 0) {
              BIO_printf(bio_err,"Successfully loaded extensions file %s\n",local_3e4);
            }
            if (local_3b0 == (EVP_MD *)0x0) {
              pEVar18 = (EVP_MD *)NCONF_get_string(extconf,"default","extensions");
              local_3b0 = (EVP_MD *)0x822e832;
              if (pEVar18 != (EVP_MD *)0x0) {
                local_3b0 = pEVar18;
              }
            }
          }
          if (((uint)local_3d0 | local_3f4) != 0) {
            if (local_400 == (EVP_MD *)0x0) {
              BIO_ctrl(local_38c,0x6a,0x10,stdout);
            }
            else {
              lVar20 = BIO_ctrl(local_38c,0x6c,5,local_400);
              if (lVar20 < 1) {
                perror((char *)local_400);
                goto LAB_08059895;
              }
            }
          }
          bVar39 = local_3d4 == (EVP_MD *)0x0;
          if (bVar39) {
            local_3d4 = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"default_md");
            bVar39 = local_3d4 == (EVP_MD *)0x0;
            if (bVar39) {
              pcVar10 = "variable lookup failed for %s::%s\n";
              pcVar4 = (char *)section;
              goto LAB_08059887;
            }
          }
          iVar31 = 8;
          pEVar18 = local_3d4;
          pcVar4 = "default";
          do {
            if (iVar31 == 0) break;
            iVar31 = iVar31 + -1;
            bVar39 = *(char *)&pEVar18->type == *pcVar4;
            pEVar18 = (EVP_MD *)((int)pEVar18 + (uint)bVar42 * -2 + 1);
            pcVar4 = pcVar4 + (uint)bVar42 * -2 + 1;
          } while (bVar39);
          if (bVar39) {
            iVar31 = EVP_PKEY_get_default_digest_nid(local_380,(int *)local_33c);
            if (iVar31 < 1) {
              BIO_puts(bio_err,"no default digest\n");
              goto LAB_08059895;
            }
            local_3d4 = (EVP_MD *)OBJ_nid2sn(local_33c._0_4_);
          }
          local_3e4 = EVP_get_digestbyname((char *)local_3d4);
          if (local_3e4 == (EVP_MD *)0x0) {
            pcVar10 = "%s is an unsupported message digest type\n";
            pcVar4 = (char *)local_3d4;
            goto LAB_08059887;
          }
          if (local_3d0 == (X509 *)0x0) {
            local_370 = (BIGNUM *)0x0;
            goto LAB_0805a83f;
          }
          if ((local_3cc == 1) &&
             (pbVar9 = (byte *)NCONF_get_string((CONF *)conf,(char *)section,"email_in_dn"),
             pbVar9 != (byte *)0x0)) {
            iVar31 = 0x6e - (uint)*pbVar9;
            if ((iVar31 == 0) && (iVar31 = 0x6f - (uint)pbVar9[1], iVar31 == 0)) {
              iVar31 = -(uint)pbVar9[2];
            }
            local_3cc = (uint)(iVar31 != 0);
          }
          if (local_374 == 0) {
            if ((local_3c4 == (EVP_MD *)0x0) &&
               (local_3c4 = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"policy"),
               local_3c4 == (EVP_MD *)0x0)) {
LAB_0805b2f6:
              pcVar10 = "variable lookup failed for %s::%s\n";
              pcVar4 = (char *)section;
              goto LAB_08059887;
            }
          }
          else {
            pcVar4 = OBJ_nid2ln((int)local_3e4->type);
            BIO_printf(bio_err,"message digest is %s\n",pcVar4);
            if ((local_3c4 == (EVP_MD *)0x0) &&
               (local_3c4 = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"policy"),
               local_3c4 == (EVP_MD *)0x0)) goto LAB_0805b2f6;
            BIO_printf(bio_err,"policy is %s\n",local_3c4);
          }
          pcVar4 = "serial";
          local_420 = NCONF_get_string((CONF *)conf,(char *)section,"serial");
          if (local_420 == (char *)0x0) {
            pcVar10 = "variable lookup failed for %s::%s\n";
            pcVar4 = (char *)section;
            goto LAB_08059887;
          }
          if (extconf == (CONF *)0x0) {
            if (local_3b0 == (EVP_MD *)0x0) {
              pcVar4 = "x509_extensions";
              local_3b0 = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"x509_extensions")
              ;
              if (local_3b0 == (EVP_MD *)0x0) {
                ERR_clear_error();
                goto LAB_08059cd8;
              }
            }
            X509V3_set_ctx((X509V3_CTX *)local_33c,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,
                           (X509_CRL *)0x0,1);
            X509V3_set_nconf((X509V3_CTX *)local_33c,(CONF *)conf);
            iVar31 = X509V3_EXT_add_nconf
                               ((CONF *)conf,(X509V3_CTX *)local_33c,(char *)local_3b0,(X509 *)0x0);
            if (iVar31 == 0) {
              pcVar10 = "Error Loading extension section %s\n";
              pcVar4 = (char *)local_3b0;
              goto LAB_08059887;
            }
          }
LAB_08059cd8:
          if (local_3b8 == (char *)0x0) {
            pcVar4 = "default_startdate";
            local_3b8 = NCONF_get_string((CONF *)conf,(char *)section,"default_startdate");
            if (local_3b8 != (char *)0x0) goto LAB_08059ce6;
            ERR_clear_error();
            local_3b8 = "today";
          }
          else {
LAB_08059ce6:
            iVar31 = ASN1_TIME_set_string((ASN1_TIME *)0x0,local_3b8);
            if (iVar31 == 0) {
              pcVar10 = "start date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n";
              goto LAB_08059887;
            }
          }
          if (local_3bc == (EVP_MD *)0x0) {
            pcVar4 = "default_enddate";
            local_3bc = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"default_enddate");
            if (local_3bc != (EVP_MD *)0x0) goto LAB_08059d0f;
            ERR_clear_error();
          }
          else {
LAB_08059d0f:
            iVar31 = ASN1_TIME_set_string((ASN1_TIME *)0x0,(char *)local_3bc);
            if (iVar31 == 0) {
              pcVar10 = "end date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n";
              goto LAB_08059887;
            }
          }
          if (local_354 == (EVP_MD *)0x0) {
            pcVar4 = "default_days";
            iVar31 = NCONF_get_number_e((CONF *)conf,(char *)section,"default_days",
                                        (long *)&local_354);
            if (iVar31 == 0) {
              local_354 = (EVP_MD *)0x0;
              pEVar18 = local_3bc;
            }
            else {
              pEVar18 = local_354;
              if (local_3bc != (EVP_MD *)0x0) goto LAB_08059d38;
            }
            if (pEVar18 == (EVP_MD *)0x0) {
              pcVar10 = "cannot lookup how many days to certify for\n";
              goto LAB_08059887;
            }
          }
LAB_08059d38:
          pcVar4 = (char *)0x0;
          local_358 = (BIGNUM *)load_serial(local_420,local_3ac,0);
          if (local_358 == (BIGNUM *)0x0) {
            pcVar10 = "error while loading serial number\n";
            goto LAB_08059887;
          }
          if (local_374 != 0) {
            if (local_358->top == 0) {
              BIO_printf(bio_err,"next serial number is 00\n");
            }
            else {
              pEVar18 = (EVP_MD *)BN_bn2hex(local_358);
              if (pEVar18 == (EVP_MD *)0x0) goto LAB_08059895;
              pcVar4 = (char *)pEVar18;
              BIO_printf(bio_err,"next serial number is %s\n",pEVar18);
              CRYPTO_free(pEVar18);
            }
          }
          local_410 = NCONF_get_section((CONF *)conf,(char *)local_3c4);
          if (local_410 == (stack_st_CONF_VALUE *)0x0) {
            pcVar10 = "unable to find \'section\' for %s\n";
            pcVar4 = (char *)local_3c4;
            goto LAB_08059887;
          }
          local_370 = (BIGNUM *)sk_new_null();
          if (local_370 == (BIGNUM *)0x0) {
LAB_0805b095:
            pcVar10 = "Memory allocation failure\n";
LAB_0805aef6:
            x_00 = (X509_CRL *)0x0;
            pBVar36 = (BIGNUM *)0x0;
            iVar31 = 1;
            BIO_printf(bio_err,pcVar10,pcVar4);
            goto LAB_0805852a;
          }
          if (local_3dc == (EVP_MD *)0x0) {
            local_424 = (EVP_MD *)0x2;
            local_3dc = (EVP_MD *)0x2;
            pEVar18 = (EVP_MD *)0x0;
            local_3c4 = (EVP_MD *)0x1;
            local_3ac = (EVP_MD *)0x1;
            pEVar17 = (EVP_MD *)0x0;
            local_3d4 = (EVP_MD *)0x0;
            goto LAB_0805a168;
          }
          local_428 = local_348;
          local_42c = local_350;
          local_430 = local_34c;
          local_434 = conf;
          local_438 = local_354;
          local_43c = local_358;
          pcVar4 = local_33c;
          local_3c4 = (EVP_MD *)
                      CONF_load((lhash_st_CONF_VALUE *)0x0,(char *)local_3dc,(long *)pcVar4);
          if (local_3c4 == (EVP_MD *)0x0) {
            x_00 = (X509_CRL *)0x0;
            pBVar36 = (BIGNUM *)0x0;
            iVar31 = 1;
            BIO_printf(bio_err,"error on line %ld of %s\n",local_33c._0_4_,local_3dc);
            ERR_print_errors(bio_err);
            goto LAB_0805852a;
          }
          local_440 = (_STACK *)CONF_get_section((lhash_st_CONF_VALUE *)local_3c4,"default");
          iVar31 = sk_num(local_440);
          if (iVar31 == 0) {
            BIO_printf(bio_err,"no name/value pairs found in %s\n",local_3dc);
            CONF_free((lhash_st_CONF_VALUE *)local_3c4);
LAB_0805afe1:
            CONF_free((lhash_st_CONF_VALUE *)local_3c4);
            goto LAB_0805989f;
          }
          local_3d0 = (X509 *)X509_REQ_new();
          if (local_3d0 == (X509 *)0x0) {
            ERR_print_errors(bio_err);
            goto LAB_0805afe1;
          }
          local_424 = (EVP_MD *)0x0;
          local_3ac = (EVP_MD *)0x0;
          local_444 = (X509_NAME *)local_3d0->cert_info->validity;
          local_3d4 = pEVar33;
          while (p_Var3 = local_440, iVar31 = sk_num(local_440), pEVar33 = local_3d4,
                (int)local_424 < iVar31) {
            pvVar21 = sk_value(p_Var3,(int)local_424);
            pbVar9 = *(byte **)((int)pvVar21 + 4);
            bVar2 = *pbVar9;
            pbVar22 = pbVar9;
            while (bVar2 != 0) {
              if (((bVar2 & 0xfd) == 0x2c) || (bVar2 == 0x3a)) {
                if (*(byte *)((int)pbVar22 + 1) != 0) {
                  pbVar9 = (byte *)((int)pbVar22 + 1);
                }
                break;
              }
              pbVar22 = (byte *)((int)pbVar22 + 1);
              bVar2 = *pbVar22;
            }
            bytes = *(uchar **)((int)pvVar21 + 8);
            iVar31 = OBJ_txt2nid((char *)pbVar9);
            bVar39 = iVar31 == 0;
            if (bVar39) {
              iVar31 = 6;
              pbVar22 = (byte *)0x8227a66;
              do {
                if (iVar31 == 0) break;
                iVar31 = iVar31 + -1;
                bVar39 = *pbVar9 == *pbVar22;
                pbVar9 = pbVar9 + (uint)bVar42 * -2 + 1;
                pbVar22 = pbVar22 + (uint)bVar42 * -2 + 1;
              } while (bVar39);
              if ((bVar39) &&
                 (local_3ac = (EVP_MD *)NETSCAPE_SPKI_b64_decode(*(char **)((int)pvVar21 + 8),-1),
                 pEVar33 = local_3d4, local_3ac == (EVP_MD *)0x0)) {
                iVar31 = -1;
                BIO_printf(bio_err,"unable to load Netscape SPKAC structure\n");
                ERR_print_errors(bio_err);
                goto LAB_0805a07f;
              }
            }
            else {
              pcVar4 = (char *)0x0;
              iVar31 = X509_NAME_add_entry_by_NID(local_444,iVar31,(int)local_3a0,bytes,-1,-1,0);
              if (iVar31 == 0) {
                iVar31 = -1;
                pEVar33 = local_3d4;
                goto LAB_0805a07f;
              }
            }
            local_424 = (EVP_MD *)((int)&local_424->type + 1);
          }
          if (local_3ac == (EVP_MD *)0x0) {
            iVar31 = -1;
            pcVar4 = (char *)local_3dc;
            BIO_printf(bio_err,"Netscape SPKAC structure not found in %s\n",local_3dc);
          }
          else {
            BIO_printf(bio_err,"Check that the SPKAC request matches the signature\n");
            pEVar23 = NETSCAPE_SPKI_get_pubkey((NETSCAPE_SPKI *)local_3ac);
            if (pEVar23 == (EVP_PKEY *)0x0) {
              iVar31 = -1;
              BIO_printf(bio_err,"error unpacking SPKAC public key\n");
            }
            else {
              iVar31 = NETSCAPE_SPKI_verify((NETSCAPE_SPKI *)local_3ac,pEVar23);
              if (iVar31 < 1) {
                iVar31 = -1;
                BIO_printf(bio_err,"signature verification failed on SPKAC public key\n");
              }
              else {
                BIO_printf(bio_err,"Signature ok\n");
                pXVar27 = local_3d0;
                X509_REQ_set_pubkey((X509_REQ *)local_3d0,pEVar23);
                EVP_PKEY_free(pEVar23);
                iVar31 = do_body(local_3e4,local_3a4,local_410,local_378,local_43c,local_384,
                                 local_3a0,local_3b4,local_3cc,local_3b8,local_3bc,local_438,1,
                                 local_374,pXVar27,local_3b0,local_434,local_430,local_42c,local_408
                                 ,local_428,0);
              }
            }
          }
LAB_0805a07f:
          X509_REQ_free((X509_REQ *)local_3d0);
          CONF_free((lhash_st_CONF_VALUE *)local_3c4);
          if (local_3ac != (EVP_MD *)0x0) {
            NETSCAPE_SPKI_free((NETSCAPE_SPKI *)local_3ac);
          }
          if (iVar31 < 0) goto LAB_0805989f;
          if (iVar31 == 0) {
            local_424 = (EVP_MD *)0x2;
            local_3dc = (EVP_MD *)0x3;
            pEVar18 = (EVP_MD *)0x0;
            local_3c4 = (EVP_MD *)0x1;
            local_3ac = (EVP_MD *)0x2;
            pEVar17 = (EVP_MD *)0x1;
            local_3d4 = (EVP_MD *)0x0;
          }
          else {
            BIO_printf(bio_err,"\n");
            iVar31 = BN_add_word(local_358,1);
            if (iVar31 == 0) goto LAB_0805989f;
            iVar31 = sk_push((_STACK *)local_370,(void *)local_344);
            if (iVar31 == 0) goto LAB_0805b095;
            pEVar18 = (EVP_MD *)0x1;
            local_424 = (EVP_MD *)0x3;
            local_3dc = (EVP_MD *)0x3;
            local_3c4 = (EVP_MD *)0x2;
            local_3ac = (EVP_MD *)0x2;
            local_3d4 = (EVP_MD *)(uint)(local_400 != (EVP_MD *)0x0);
            pEVar17 = (EVP_MD *)0x1;
            if (local_400 != (EVP_MD *)0x0) {
              local_3d8 = 1;
            }
          }
LAB_0805a168:
          pBVar36 = local_404;
          pEVar28 = local_3ac;
          if (local_404 == (BIGNUM *)0x0) goto LAB_0805a2ff;
          local_400 = local_348;
          local_404 = local_350;
          local_428 = local_34c;
          local_42c = conf;
          local_430 = local_354;
          local_434 = local_358;
          local_3d0 = (X509 *)load_cert(bio_err,pBVar36,3,0,local_41c,pBVar36);
          if (local_3d0 == (X509 *)0x0) goto LAB_0805989f;
          if (local_374 != 0) {
            X509_print(bio_err,local_3d0);
          }
          BIO_printf(bio_err,"Check that the request matches the signature\n");
          pEVar23 = X509_get_pubkey(local_3d0);
          if (pEVar23 == (EVP_PKEY *)0x0) {
            iVar31 = -1;
            BIO_printf(bio_err,"error unpacking public key\n");
          }
          else {
            local_438 = (EVP_MD *)X509_verify(local_3d0,pEVar23);
            EVP_PKEY_free(pEVar23);
            if ((int)local_438 < 0) {
              iVar31 = 0;
              BIO_printf(bio_err,"Signature verification problems....\n");
            }
            else if (local_438 == (EVP_MD *)0x0) {
              iVar31 = 0;
              BIO_printf(bio_err,"Signature did not match the certificate\n");
            }
            else {
              BIO_printf(bio_err,"Signature ok\n");
              pcVar4 = (char *)EVP_md5();
              pEVar28 = (EVP_MD *)X509_to_X509_REQ(local_3d0,(EVP_PKEY *)0x0,(EVP_MD *)pcVar4);
              pEVar17 = local_400;
              if (pEVar28 == (EVP_MD *)0x0) {
                iVar31 = -1;
              }
              else {
                local_400 = pEVar28;
                iVar31 = do_body(local_3e4,local_3a4,local_410,local_378,local_434,local_384,
                                 local_3a0,local_3b4,local_3cc,local_3b8,local_3bc,local_430,
                                 local_3d8,local_374,pEVar28,local_3b0,local_42c,local_428,local_404
                                 ,local_408,pEVar17,0);
                X509_REQ_free((X509_REQ *)local_400);
              }
            }
          }
          X509_free(local_3d0);
          if (iVar31 < 0) goto LAB_0805989f;
          pEVar28 = local_3dc;
          pEVar17 = local_3ac;
          if (iVar31 != 0) {
            BIO_printf(bio_err,"\n");
            iVar31 = BN_add_word(local_358,1);
            if (iVar31 == 0) goto LAB_0805989f;
            iVar31 = sk_push((_STACK *)local_370,(void *)local_344);
            pEVar18 = local_3c4;
            if (iVar31 == 0) goto LAB_0805b095;
            local_3c4 = local_424;
            pEVar28 = local_3dc;
            pEVar17 = local_3ac;
          }
LAB_0805a2ff:
          local_3ac = pEVar17;
          pEVar17 = local_3ac;
          if (local_3e0 != (void *)0x0) {
            iVar31 = certify(local_414,local_3e4,local_3a4,local_410,local_378,local_358,local_384,
                             local_3a0,local_3b4,local_3cc,local_3b8,local_3bc,local_354,local_3d8,
                             local_3b0,conf,local_374,local_34c,local_350,local_408,local_348,
                             local_3f0);
            if (iVar31 < 0) goto LAB_0805989f;
            pEVar17 = pEVar28;
            if (iVar31 != 0) {
              BIO_printf(bio_err,"\n");
              iVar31 = BN_add_word(local_358,1);
              if (iVar31 == 0) goto LAB_0805989f;
              iVar31 = sk_push((_STACK *)local_370,(void *)local_344);
              pEVar18 = local_3c4;
              if (iVar31 == 0) goto LAB_0805b095;
            }
          }
          pEVar28 = pEVar17;
          if (0 < (int)pEVar33) {
            pEVar28 = (EVP_MD *)
                      ((int)pEVar17->required_pkey_type + (int)(pEVar33->required_pkey_type + -0x16)
                      );
            local_3ac = (EVP_MD *)((int)local_3a8 + (int)pEVar17 * -4);
            local_3a8 = (BIGNUM *)local_344;
            do {
              pEVar17 = (EVP_MD *)((int)&pEVar17->type + 1);
              iVar31 = certify(local_414,local_3e4,local_3a4,local_410,local_378,local_358,local_384
                               ,local_3a0,local_3b4,local_3cc,local_3b8,local_3bc,local_354,
                               local_3d8,local_3b0,conf,local_374,local_34c,local_350,local_408,
                               local_348,local_3f0);
              if (iVar31 < 0) goto LAB_0805989f;
              if (iVar31 != 0) {
                pEVar18 = (EVP_MD *)((int)&pEVar18->type + 1);
                BIO_printf(bio_err,"\n");
                iVar31 = BN_add_word(local_358,1);
                if (iVar31 == 0) goto LAB_0805989f;
                iVar31 = sk_push((_STACK *)local_370,(void *)local_344);
                if (iVar31 == 0) goto LAB_0805b095;
              }
            } while (pEVar28 != pEVar17);
          }
          iVar31 = sk_num((_STACK *)local_370);
          if (0 < iVar31) {
            if (local_3d8 != 0) {
LAB_0805a5bd:
              iVar31 = sk_num((_STACK *)local_370);
              BIO_printf(bio_err,"Write out database with %d new entries\n",iVar31);
              iVar31 = save_serial(local_420,&DAT_081eaee6,local_358,0);
              if ((iVar31 == 0) ||
                 (pcVar4 = (char *)local_378, iVar31 = save_index(local_3fc,&DAT_081eaee6,local_378)
                 , iVar31 == 0)) goto LAB_0805989f;
              goto LAB_0805a626;
            }
            BIO_printf(bio_err,"\n%d out of %d certificate requests certified, commit? [y/n]",
                       pEVar18,pEVar28);
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            local_320[0]._0_1_ = 0;
            pFVar43 = stdin;
            pcVar4 = fgets((char *)local_320,10,stdin);
            if (pcVar4 == (char *)0x0) {
              pcVar4 = "CERTIFICATION CANCELED: I/O error\n";
            }
            else {
              if (((byte)local_320[0] & 0xdf) == 0x59) goto LAB_0805a5bd;
              pcVar4 = "CERTIFICATION CANCELED\n";
            }
            x_00 = (X509_CRL *)0x0;
            BIO_printf(bio_err,pcVar4,pFVar43,pEVar28);
LAB_0805ae79:
            pBVar36 = (BIGNUM *)0x0;
            iVar31 = 0;
            goto LAB_0805852a;
          }
LAB_0805a626:
          if (local_374 != 0) {
            BIO_printf(bio_err,"writing new certificates\n");
          }
          pBVar5 = local_394;
          local_384 = (char *)0x0;
          while (iVar31 = sk_num((_STACK *)local_370), (int)local_384 < iVar31) {
            local_344 = (undefined  [4])sk_value((_STACK *)local_370,(int)local_384);
            pAVar26 = (*(X509_CINF **)local_344)->serialNumber;
            iVar31 = pAVar26->length;
            pbVar9 = pAVar26->data;
            sVar12 = strlen(local_3c0);
            if (iVar31 == 0) {
              if (0xf7 < sVar12) goto LAB_0805bace;
              __memcpy_chk(local_120,local_3c0,sVar12 + 1,0x100);
              BUF_strlcat((char *)local_120,"/",0x100);
              puVar30 = local_120;
              do {
                puVar29 = puVar30;
                uVar32 = *puVar29 + 0xfefefeff & ~*puVar29;
                uVar11 = uVar32 & 0x80808080;
                puVar30 = puVar29 + 1;
              } while (uVar11 == 0);
              bVar39 = (uVar32 & 0x8080) == 0;
              if (bVar39) {
                uVar11 = uVar11 >> 0x10;
              }
              if (bVar39) {
                puVar30 = (uint *)((int)puVar29 + 6);
              }
              iVar37 = (int)puVar30 +
                       ((-3 - (uint)CARRY1((byte)uVar11,(byte)uVar11)) - (int)local_120);
              pBVar36 = (BIGNUM *)((undefined *)((int)register0x00000010 + -0x123) + iVar37 + 3);
LAB_0805ba40:
              *(undefined *)((int)local_120 + iVar37) = 0x30;
              pBVar24 = (BIGNUM *)((int)&pBVar36->d + 2);
              *(undefined *)((int)&pBVar36->d + 1) = 0x30;
            }
            else {
              if ((uint)((0x7d - iVar31) * 2) <= sVar12) {
LAB_0805bace:
                pcVar10 = "certificate file name too long\n";
                goto LAB_0805aef6;
              }
              __memcpy_chk(local_120,local_3c0,sVar12 + 1,0x100);
              BUF_strlcat((char *)local_120,"/",0x100);
              puVar30 = local_120;
              do {
                puVar29 = puVar30;
                uVar32 = *puVar29 + 0xfefefeff & ~*puVar29;
                uVar11 = uVar32 & 0x80808080;
                puVar30 = puVar29 + 1;
              } while (uVar11 == 0);
              bVar39 = (uVar32 & 0x8080) == 0;
              if (bVar39) {
                uVar11 = uVar11 >> 0x10;
              }
              if (bVar39) {
                puVar30 = (uint *)((int)puVar29 + 6);
              }
              iVar37 = (int)puVar30 +
                       ((-3 - (uint)CARRY1((byte)uVar11,(byte)uVar11)) - (int)local_120);
              pBVar24 = (BIGNUM *)((undefined *)((int)register0x00000010 + -0x123) + iVar37 + 3);
              pBVar36 = pBVar24;
              if (iVar31 < 1) goto LAB_0805ba40;
              if (pBVar24 < (BIGNUM *)&local_20) {
                local_3a8 = (BIGNUM *)&local_20;
                pbVar22 = pbVar9;
                do {
                  local_3a0 = pBVar24;
                  BIO_snprintf((char *)pBVar24,(int)local_3a8 - (int)pBVar24,"%02X",(uint)*pbVar22);
                  pBVar24 = (BIGNUM *)((int)&local_3a0->d + 2);
                  if (pbVar22 + 1 == pbVar9 + iVar31) break;
                  pbVar22 = pbVar22 + 1;
                } while (pBVar24 < local_3a8);
              }
            }
            *(undefined *)&pBVar24->d = 0x2e;
            *(undefined *)((int)&pBVar24->d + 1) = 0x70;
            *(undefined *)((int)&pBVar24->d + 2) = 0x65;
            *(undefined *)((int)&pBVar24->d + 3) = 0x6d;
            *(undefined *)&pBVar24->top = 0;
            if (local_374 != 0) {
              BIO_printf(bio_err,"writing %s\n",local_120);
            }
            pcVar4 = (char *)0x5;
            lVar20 = BIO_ctrl(pBVar5,0x6c,5,local_120);
            pXVar27 = (X509 *)local_344;
            if (lVar20 < 1) {
              x_00 = (X509_CRL *)0x0;
              pBVar36 = (BIGNUM *)0x0;
              iVar31 = 1;
              perror((char *)local_120);
              goto LAB_0805852a;
            }
            if (local_418 == 0) {
              X509_print(pBVar5,(X509 *)local_344);
              PEM_write_bio_X509(pBVar5,pXVar27);
              pXVar27 = (X509 *)local_344;
              if (local_3d4 == (EVP_MD *)0x0) {
                X509_print(local_38c,(X509 *)local_344);
                goto LAB_0805a817;
              }
LAB_0805badb:
              i2d_X509_bio(local_38c,(X509 *)local_344);
            }
            else {
              PEM_write_bio_X509(pBVar5,(X509 *)local_344);
              pXVar27 = (X509 *)local_344;
              if (local_3d4 != (EVP_MD *)0x0) goto LAB_0805badb;
LAB_0805a817:
              PEM_write_bio_X509(local_38c,pXVar27);
            }
            local_384 = local_384 + 1;
          }
          iVar31 = sk_num((_STACK *)local_370);
          if (iVar31 != 0) {
            iVar31 = rotate_serial(local_420,&DAT_081eaee6,"old");
            if ((iVar31 == 0) || (iVar31 = rotate_index(local_3fc,&DAT_081eaee6,"old"), iVar31 == 0)
               ) goto LAB_0805989f;
            BIO_printf(bio_err,"Data Base Updated\n");
          }
LAB_0805a83f:
          if (local_3f4 == 0) {
            x_00 = (X509_CRL *)0x0;
LAB_0805ac91:
            if (local_40c == 0) goto LAB_0805ae79;
            if (local_3e0 == (void *)0x0) {
              pBVar36 = (BIGNUM *)0x0;
              iVar31 = 1;
              BIO_printf(bio_err,"no input files\n");
              goto LAB_0805852a;
            }
            pXVar27 = (X509 *)load_cert(bio_err,local_3e0,3,0,local_41c,local_3e0);
            pEVar33 = local_378;
            if ((pXVar27 != (X509 *)0x0) && (iVar31 = do_revoke(local_3ec), 0 < iVar31)) {
              iVar31 = 1;
              X509_free(pXVar27);
              pBVar36 = (BIGNUM *)0x0;
              iVar37 = save_index(local_3fc,&DAT_081eaee6,pEVar33);
              if ((iVar37 != 0) &&
                 (iVar37 = rotate_index(local_3fc,&DAT_081eaee6,"old"), iVar37 != 0)) {
                iVar31 = 0;
                BIO_printf(bio_err,"Data Base Updated\n");
              }
              goto LAB_0805852a;
            }
            goto LAB_0805924a;
          }
          if ((local_3c8 == (EVP_MD *)0x0) &&
             (local_3c8 = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"crl_extensions"),
             local_3c8 == (EVP_MD *)0x0)) {
            ERR_clear_error();
          }
          else {
            X509V3_set_ctx((X509V3_CTX *)local_33c,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,
                           (X509_CRL *)0x0,1);
            X509V3_set_nconf((X509V3_CTX *)local_33c,(CONF *)conf);
            iVar31 = X509V3_EXT_add_nconf
                               ((CONF *)conf,(X509V3_CTX *)local_33c,(char *)local_3c8,(X509 *)0x0);
            if (iVar31 == 0) {
              pcVar10 = "Error Loading CRL extension section %s\n";
              pcVar4 = (char *)local_3c8;
              goto LAB_0805aef6;
            }
          }
          local_384 = NCONF_get_string((CONF *)conf,(char *)section,"crlnumber");
          if (local_384 == (char *)0x0) {
            pBVar36 = (BIGNUM *)0x0;
LAB_0805a8e6:
            if ((local_360 | local_364 | local_3f8) == 0) {
              iVar31 = NCONF_get_number_e((CONF *)conf,(char *)section,"default_crl_days",
                                          (long *)&local_364);
              if (iVar31 == 0) {
                local_364 = 0;
              }
              iVar31 = NCONF_get_number_e((CONF *)conf,(char *)section,"default_crl_hours",
                                          (long *)&local_360);
              if (iVar31 == 0) {
                local_360 = 0;
              }
              ERR_clear_error();
            }
            if ((local_364 == 0) && ((local_3f8 | local_360) == 0)) {
              pcVar4 = "cannot lookup how long until the next CRL is issued\n";
              goto LAB_0805aea6;
            }
            if (local_374 != 0) {
              BIO_printf(bio_err,"making CRL\n");
            }
            x_00 = X509_CRL_new();
            iVar31 = 1;
            if (x_00 == (X509_CRL *)0x0) goto LAB_0805852a;
            name = X509_get_subject_name(local_37c);
            iVar37 = X509_CRL_set_issuer_name(x_00,name);
            if ((iVar37 == 0) || (pBVar24 = (BIGNUM *)ASN1_TIME_new(), pBVar24 == (BIGNUM *)0x0))
            goto LAB_0805852a;
            local_3a0 = pBVar24;
            X509_gmtime_adj((ASN1_TIME *)pBVar24,0);
            X509_CRL_set_lastUpdate(x_00,(ASN1_TIME *)local_3a0);
            pAVar25 = X509_time_adj_ex((ASN1_TIME *)local_3a0,local_364,
                                       local_360 * 0xe10 + local_3f8,(time_t *)0x0);
            pBVar24 = local_3a0;
            if (pAVar25 == (ASN1_TIME *)0x0) {
              BIO_puts(bio_err,"error setting CRL nextUpdate\n");
              goto LAB_0805852a;
            }
            X509_CRL_set_nextUpdate(x_00,(ASN1_TIME *)local_3a0);
            ASN1_TIME_free((ASN1_TIME *)pBVar24);
            local_3a8 = (BIGNUM *)0x0;
            local_3ac = (EVP_MD *)0x0;
            local_3a0 = pBVar36;
            while (iVar31 = sk_num(*(_STACK **)((int)local_378->pkey_type + 4)), pBVar36 = local_3a0
                  , (int)local_3ac < iVar31) {
              ppcVar16 = (char **)sk_value(*(_STACK **)((int)local_378->pkey_type + 4),
                                           (int)local_3ac);
              if (**ppcVar16 == 'R') {
                x = X509_REVOKED_new();
                pBVar36 = local_3a0;
                if ((x == (X509_REVOKED *)0x0) ||
                   (iVar31 = make_revoked(x,ppcVar16[2]), pBVar36 = local_3a0, iVar31 == 0))
                goto LAB_0805924c;
                pBVar36 = (BIGNUM *)0x1;
                if (iVar31 != 2) {
                  pBVar36 = local_3a8;
                }
                local_3a8 = pBVar36;
                iVar31 = BN_hex2bn(&local_358,ppcVar16[3]);
                pBVar36 = local_3a0;
                if (iVar31 == 0) goto LAB_0805924c;
                pAVar26 = BN_to_ASN1_INTEGER(local_358,(ASN1_INTEGER *)0x0);
                BN_free(local_358);
                local_358 = (BIGNUM *)0x0;
                pBVar36 = local_3a0;
                if (pAVar26 == (ASN1_INTEGER *)0x0) goto LAB_0805924c;
                X509_REVOKED_set_serialNumber(x,pAVar26);
                ASN1_INTEGER_free(pAVar26);
                X509_CRL_add0_revoked(x_00,x);
              }
              local_3ac = (EVP_MD *)((int)&local_3ac->type + 1);
            }
            X509_CRL_sort(x_00);
            if (local_374 != 0) {
              BIO_printf(bio_err,"signing CRL\n");
            }
            bVar39 = local_3c8 != (EVP_MD *)0x0;
            local_374 = local_374 & 0xffffff00 | (uint)bVar39;
            uVar11 = (uint)local_3a0 & 0xffffff00;
            local_3a0 = (BIGNUM *)(uVar11 | (local_384 != (char *)0x0 || bVar39));
            if (local_384 == (char *)0x0 && !bVar39) {
              local_3a0 = (BIGNUM *)(uVar11 | local_3a8 != (BIGNUM *)0x0);
LAB_0805abda:
              if ((char)local_3a0 != '\0') {
                iVar31 = 1;
                iVar37 = X509_CRL_set_version(x_00,1);
                if (iVar37 == 0) goto LAB_0805852a;
              }
              if (local_384 != (char *)0x0) {
                iVar31 = 1;
                iVar37 = save_serial(local_384,&DAT_081eaee6,pBVar36,0);
                if (iVar37 == 0) goto LAB_0805852a;
              }
              if (pBVar36 != (BIGNUM *)0x0) {
                BN_free(pBVar36);
              }
              pBVar36 = (BIGNUM *)0x0;
              iVar31 = 1;
              iVar37 = do_X509_CRL_sign(bio_err,x_00,local_380,local_3e4,local_3a4);
              if ((iVar37 == 0) ||
                 ((PEM_write_bio_X509_CRL(local_38c,x_00), local_384 != (char *)0x0 &&
                  (iVar37 = rotate_serial(local_384,&DAT_081eaee6,"old"), iVar37 == 0))))
              goto LAB_0805852a;
              goto LAB_0805ac91;
            }
            X509V3_set_ctx((X509V3_CTX *)local_33c,local_37c,(X509 *)0x0,(X509_REQ *)0x0,x_00,0);
            X509V3_set_nconf((X509V3_CTX *)local_33c,(CONF *)conf);
            if ((local_3c8 == (EVP_MD *)0x0) ||
               (iVar31 = X509V3_EXT_CRL_add_nconf
                                   ((CONF *)conf,(X509V3_CTX *)local_33c,(char *)local_3c8,x_00),
               iVar31 != 0)) {
              if (local_384 == (char *)0x0) {
                local_3a0 = (BIGNUM *)
                            ((uint)local_3a0 & 0xffffff00 |
                            (uint)(local_3a8 != (BIGNUM *)0x0 | (byte)local_374));
                goto LAB_0805abda;
              }
              pAVar26 = BN_to_ASN1_INTEGER(pBVar36,(ASN1_INTEGER *)0x0);
              if (pAVar26 != (ASN1_INTEGER *)0x0) {
                X509_CRL_add1_ext_i2d(x_00,0x58,pAVar26,0,0);
                ASN1_INTEGER_free(pAVar26);
                iVar31 = BN_add_word(pBVar36,1);
                if (iVar31 != 0) goto LAB_0805abda;
              }
            }
          }
          else {
            pBVar36 = (BIGNUM *)load_serial(local_384,0,0);
            if (pBVar36 != (BIGNUM *)0x0) goto LAB_0805a8e6;
            pcVar4 = "error while loading CRL number\n";
LAB_0805aea6:
            x_00 = (X509_CRL *)0x0;
            BIO_printf(bio_err,pcVar4);
          }
        }
LAB_0805924c:
        iVar31 = 1;
        goto LAB_0805852a;
      }
      pcVar4 = NCONF_get_string((CONF *)conf,(char *)section,"database");
      if (pcVar4 == (char *)0x0) {
        pcVar4 = "database";
LAB_0805b66c:
        BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,pcVar4);
        local_378 = (EVP_MD *)0x0;
      }
      else {
        local_378 = (EVP_MD *)load_index(pcVar4,local_344 + 4);
        if ((local_378 != (EVP_MD *)0x0) && (iVar31 = index_index(local_378), iVar31 != 0)) {
          value = local_320;
          uVar11 = 0;
          do {
            *(undefined4 *)((int)value + uVar11) = 0;
            uVar11 = uVar11 + 4;
          } while (uVar11 < 0x18);
          sVar12 = strlen((char *)local_37c);
          p_Var13 = (_func_1084 *)CRYPTO_malloc(sVar12 + 2,"ca.c",0x98f);
          pXVar27 = local_37c;
          local_314 = p_Var13;
          if (p_Var13 == (_func_1084 *)0x0) {
            iVar31 = -1;
            BIO_printf(bio_err,"Malloc failure\n");
          }
          else {
            sVar12 = strlen((char *)local_37c);
            if ((sVar12 & 1) == 0) {
              memcpy(p_Var13,pXVar27,sVar12);
              sVar12 = strlen((char *)pXVar27);
              local_314[sVar12] = (_func_1084)0x0;
            }
            else {
              *p_Var13 = (_func_1084)0x30;
              sVar12 = strlen((char *)pXVar27);
              memcpy(local_314 + 1,pXVar27,sVar12);
              sVar12 = strlen((char *)pXVar27);
              local_314[sVar12 + 1] = (_func_1084)0x0;
            }
            p_Var13 = local_314;
            if (*local_314 != (_func_1084)0x0) {
              local_370 = (BIGNUM *)((uint)local_370 & 0xffffff00 | (uint)(byte)*local_314);
              iVar31 = 0;
              pp_Var14 = __ctype_toupper_loc();
              do {
                iVar31 = iVar31 + 1;
                *p_Var13 = (_func_1084)(byte)(*pp_Var14)[(byte)local_370];
                p_Var13 = local_314 + iVar31;
                local_370._0_1_ = (byte)*p_Var13;
              } while ((byte)local_370 != 0);
            }
            ppcVar15 = TXT_DB_get_by_index((TXT_DB *)local_378->pkey_type,3,value);
            if (ppcVar15 == (OPENSSL_STRING *)0x0) {
              iVar31 = -1;
              BIO_printf(bio_err,"Serial %s not present in db.\n",local_314);
            }
            else {
              cVar1 = **ppcVar15;
              if (cVar1 == 'V') {
                iVar31 = 1;
                BIO_printf(bio_err,"%s=Valid (%c)\n",local_314,0x56);
              }
              else if (cVar1 == 'R') {
                iVar31 = 1;
                BIO_printf(bio_err,"%s=Revoked (%c)\n",local_314,0x52);
              }
              else if (cVar1 == 'E') {
                iVar31 = 1;
                BIO_printf(bio_err,"%s=Expired (%c)\n",local_314,0x45);
              }
              else if (cVar1 == 'S') {
                iVar31 = 1;
                BIO_printf(bio_err,"%s=Suspended (%c)\n",local_314,0x53);
              }
              else {
                iVar31 = -1;
                BIO_printf(bio_err,"%s=Unknown (%c).\n",local_314,(int)cVar1);
              }
            }
          }
          do {
            if (*value != (OPENSSL_STRING)0x0) {
              CRYPTO_free(*value);
            }
            value = value + 1;
          } while (value != local_308);
          if (iVar31 != 1) {
            BIO_printf(bio_err,"Error verifying serial %s!\n",local_37c);
          }
        }
      }
    }
  }
  else {
    pBVar24 = (BIGNUM *)local_378;
    BIO_printf(bio_err,"Using configuration from %s\n",local_378);
    conf = (BIGNUM *)NCONF_new((CONF_METHOD *)0x0);
    local_370 = (BIGNUM *)&local_35c;
    pBVar36 = (BIGNUM *)0x0;
    iVar31 = NCONF_load((CONF *)conf,(char *)pBVar24,(long *)local_370);
    pBVar24 = (BIGNUM *)local_378;
    if (0 < iVar31) goto LAB_08058882;
LAB_08058485:
    local_378 = (EVP_MD *)pBVar24;
    if ((int)local_35c < 1) {
      BIO_printf(bio_err,"error loading the config file \'%s\'\n",local_378);
    }
    else {
      BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_35c,local_378);
    }
    if (pBVar36 != (BIGNUM *)0x0) {
      CRYPTO_free(pBVar36);
    }
LAB_080584bd:
    local_39c = (char *)0x0;
LAB_080584c7:
    local_378 = (EVP_MD *)0x0;
    local_394 = (BIO *)0x0;
    local_38c = (BIO *)0x0;
    local_390 = (BIO *)0x0;
    local_398 = (BIO *)0x0;
  }
  local_370 = (BIGNUM *)0x0;
  x_00 = (X509_CRL *)0x0;
  local_37c = (X509 *)0x0;
  pBVar36 = (BIGNUM *)0x0;
  local_380 = (EVP_PKEY *)0x0;
  iVar31 = 1;
  local_388 = (void *)0x0;
LAB_0805852a:
  BIO_free_all(local_394);
  BIO_free_all(local_38c);
  BIO_free_all(local_390);
  BIO_free_all(local_398);
  if (local_370 != (BIGNUM *)0x0) {
    sk_pop_free((_STACK *)local_370,X509_free);
  }
  if (iVar31 != 0) {
    ERR_print_errors(bio_err);
  }
  app_RAND_write_file(local_39c,bio_err);
  if ((local_388 != (void *)0x0) && (local_368 != (byte *)0x0)) {
    CRYPTO_free(local_368);
  }
  BN_free(local_358);
  BN_free(pBVar36);
  free_index(local_378);
  if (local_3a4 != (_STACK *)0x0) {
    sk_free(local_3a4);
  }
  EVP_PKEY_free(local_380);
  if (local_37c != (X509 *)0x0) {
    X509_free(local_37c);
  }
  X509_CRL_free(x_00);
  NCONF_free((CONF *)conf);
  NCONF_free(extconf);
  OBJ_cleanup();
  if (local_20 != *(ulong **)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar31;
}

