
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

int ca_main(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  uchar *bytes;
  _STACK *p_Var3;
  CONF_METHOD *pCVar4;
  char *pcVar5;
  BIO *pBVar6;
  BIO_METHOD *pBVar7;
  BIO *pBVar8;
  byte *pbVar9;
  uint uVar10;
  size_t sVar11;
  _func_1084 *p_Var12;
  __int32_t **pp_Var13;
  OPENSSL_STRING *ppcVar14;
  char **ppcVar15;
  ASN1_UTCTIME *s;
  EVP_MD *pEVar16;
  EVP_MD *pEVar17;
  BIGNUM **ppBVar18;
  long lVar19;
  void *pvVar20;
  byte *pbVar21;
  EVP_PKEY *pEVar22;
  EVP_MD *pEVar23;
  uint *puVar24;
  uint *puVar25;
  X509_NAME *name;
  BIGNUM *pBVar26;
  ASN1_TIME *pAVar27;
  X509_REVOKED *x;
  ASN1_INTEGER *pAVar28;
  X509 *pXVar29;
  int iVar30;
  uint uVar31;
  EVP_MD *pEVar32;
  undefined1 *puVar33;
  OPENSSL_STRING *value;
  X509_CRL *x_00;
  CONF_METHOD *pCVar34;
  char *pcVar35;
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
  char *local_3fc;
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
  BIO *local_39c;
  char *local_398;
  BIO *local_394;
  BIO *local_390;
  BIO *local_38c;
  void *local_388;
  EVP_PKEY *local_384;
  X509 *local_380;
  char *local_37c;
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
    pBVar7 = BIO_s_file();
    bio_err = BIO_new(pBVar7);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  local_388 = (void *)0x0;
  pEVar32 = (EVP_MD *)(param_1 + -1);
  local_3a8 = (BIGNUM *)(param_2 + 4);
  bVar39 = pEVar32 == (EVP_MD *)0x0;
  if (0 < (int)pEVar32) {
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
    local_37c = (char *)0x0;
    local_3e4 = (EVP_MD *)0x0;
    local_3b0 = (EVP_MD *)0x0;
    local_3c0 = (char *)0x0;
    local_400 = (EVP_MD *)0x0;
    local_380 = (X509 *)0x0;
    local_404 = (BIGNUM *)0x0;
    local_3dc = (EVP_MD *)0x0;
    local_3e0 = (void *)0x0;
    local_414 = (X509 *)0x3;
    local_3fc = (char *)0x0;
    local_384 = (EVP_PKEY *)0x0;
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
LAB_08058209:
    local_3a8 = pBVar36;
    iVar30 = 9;
    pCVar4 = (CONF_METHOD *)local_370->d;
    pCVar34 = pCVar4;
    pcVar5 = "-verbose";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    pBVar36 = local_3a8;
    pBVar26 = local_370;
    if (bVar39) {
      local_374 = 1;
      goto joined_r0x08058235;
    }
    iVar30 = 8;
    pCVar34 = pCVar4;
    pcVar5 = "-config";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_378 = (EVP_MD *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 6;
    pCVar34 = pCVar4;
    pcVar5 = "-name";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      section = (EVP_MD *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 6;
    pCVar34 = pCVar4;
    pcVar5 = "-subj";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_37c = (char *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 6;
    pCVar34 = pCVar4;
    pcVar5 = "-utf8";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      local_3a0 = (BIGNUM *)0x1000;
      goto joined_r0x08058235;
    }
    iVar30 = 0xf;
    pCVar34 = pCVar4;
    pcVar5 = "-create_serial";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      local_3ac = (EVP_MD *)0x1;
      goto joined_r0x08058235;
    }
    iVar30 = 0x10;
    pCVar34 = pCVar4;
    pcVar5 = "-multivalue-rdn";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      local_3b4 = 1;
      goto joined_r0x08058235;
    }
    iVar30 = 0xb;
    pCVar34 = pCVar4;
    pcVar5 = "-startdate";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_3b8 = (char *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 9;
    pCVar34 = pCVar4;
    pcVar5 = "-enddate";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_3bc = (EVP_MD *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 6;
    pCVar34 = pCVar4;
    pcVar5 = "-days";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      pBVar26 = (BIGNUM *)&local_370->top;
      local_354 = (EVP_MD *)strtol((char *)local_370->top,(char **)0x0,10);
      pBVar36 = local_3a8;
      goto joined_r0x08058235;
    }
    local_38c = (BIO *)(0x2d - (uint)*(byte *)&pCVar4->name);
    bVar39 = local_38c == (BIO *)0x0;
    if ((((bVar39) && (bVar39 = *(char *)((int)&pCVar4->name + 1) == 'm', bVar39)) &&
        (bVar39 = *(char *)((int)&pCVar4->name + 2) == 'd', bVar39)) &&
       (bVar39 = *(char *)((int)&pCVar4->name + 3) == '\0', bVar39)) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_3d4 = (EVP_MD *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 8;
    pCVar34 = pCVar4;
    pcVar5 = "-policy";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_3c4 = (EVP_MD *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 9;
    pCVar34 = pCVar4;
    pcVar5 = "-keyfile";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_384 = (EVP_PKEY *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 9;
    pCVar34 = pCVar4;
    pcVar5 = "-keyform";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      pBVar26 = (BIGNUM *)&local_370->top;
      local_414 = (X509 *)str2fmt((void *)local_370->top);
      pBVar36 = local_3a8;
      goto joined_r0x08058235;
    }
    iVar30 = 8;
    pCVar34 = pCVar4;
    pcVar5 = "-passin";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_408 = (void *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 5;
    pCVar34 = pCVar4;
    pcVar5 = "-key";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_368 = (byte *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 6;
    pCVar34 = pCVar4;
    pcVar5 = "-cert";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
      local_3fc = (char *)local_370->top;
      pBVar26 = (BIGNUM *)&local_370->top;
      goto joined_r0x08058235;
    }
    iVar30 = 10;
    pCVar34 = pCVar4;
    pcVar5 = "-selfsign";
    do {
      if (iVar30 == 0) break;
      iVar30 = iVar30 + -1;
      bVar39 = *(char *)&pCVar34->name == *pcVar5;
      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
    } while (bVar39);
    if (bVar39) {
      local_3f0 = 1;
      goto joined_r0x08058235;
    }
    bVar39 = local_38c == (BIO *)0x0;
    if (((bVar39) && (bVar39 = *(char *)((int)&pCVar4->name + 1) == 'i', bVar39)) &&
       ((bVar39 = *(char *)((int)&pCVar4->name + 2) == 'n', bVar39 &&
        (bVar39 = *(char *)((int)&pCVar4->name + 3) == '\0', bVar39)))) {
      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
      if (pEVar32 != (EVP_MD *)0x0) {
        local_3d0 = (X509 *)0x1;
        local_3e0 = (void *)local_370->top;
        pBVar26 = (BIGNUM *)&local_370->top;
        goto joined_r0x08058235;
      }
    }
    else {
      iVar30 = 5;
      pCVar34 = pCVar4;
      pcVar5 = "-out";
      do {
        if (iVar30 == 0) break;
        iVar30 = iVar30 + -1;
        bVar39 = *(char *)&pCVar34->name == *pcVar5;
        pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
        pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
      } while (bVar39);
      if (bVar39) {
        pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
        if (pEVar32 != (EVP_MD *)0x0) {
          local_400 = (EVP_MD *)local_370->top;
          pBVar26 = (BIGNUM *)&local_370->top;
          goto joined_r0x08058235;
        }
      }
      else {
        iVar30 = 8;
        pCVar34 = pCVar4;
        pcVar5 = "-outdir";
        do {
          if (iVar30 == 0) break;
          iVar30 = iVar30 + -1;
          bVar39 = *(char *)&pCVar34->name == *pcVar5;
          pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
          pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
        } while (bVar39);
        if (bVar39) {
          pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
          if (pEVar32 != (EVP_MD *)0x0) {
            local_3c0 = (char *)local_370->top;
            pBVar26 = (BIGNUM *)&local_370->top;
            goto joined_r0x08058235;
          }
        }
        else {
          iVar30 = 8;
          pCVar34 = pCVar4;
          pcVar5 = "-sigopt";
          do {
            if (iVar30 == 0) break;
            iVar30 = iVar30 + -1;
            bVar39 = *(char *)&pCVar34->name == *pcVar5;
            pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
            pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
          } while (bVar39);
          if (!bVar39) {
            iVar30 = 8;
            pCVar34 = pCVar4;
            pcVar5 = "-notext";
            do {
              if (iVar30 == 0) break;
              iVar30 = iVar30 + -1;
              bVar39 = *(char *)&pCVar34->name == *pcVar5;
              pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
              pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
            } while (bVar39);
            if (bVar39) {
              local_418 = 1;
            }
            else {
              iVar30 = 7;
              pCVar34 = pCVar4;
              pcVar5 = "-batch";
              do {
                if (iVar30 == 0) break;
                iVar30 = iVar30 + -1;
                bVar39 = *(char *)&pCVar34->name == *pcVar5;
                pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
              } while (bVar39);
              if (bVar39) {
                local_3d8 = 1;
              }
              else {
                iVar30 = 0xc;
                pCVar34 = pCVar4;
                pcVar5 = "-preserveDN";
                do {
                  if (iVar30 == 0) break;
                  iVar30 = iVar30 + -1;
                  bVar39 = *(char *)&pCVar34->name == *pcVar5;
                  pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                  pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                } while (bVar39);
                if (bVar39) {
                  preserve = 1;
                }
                else {
                  iVar30 = 0xb;
                  pCVar34 = pCVar4;
                  pcVar5 = "-noemailDN";
                  do {
                    if (iVar30 == 0) break;
                    iVar30 = iVar30 + -1;
                    bVar39 = *(char *)&pCVar34->name == *pcVar5;
                    pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                    pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                  } while (bVar39);
                  if (bVar39) {
                    local_3cc = 0;
                  }
                  else {
                    iVar30 = 8;
                    pCVar34 = pCVar4;
                    pcVar5 = "-gencrl";
                    do {
                      if (iVar30 == 0) break;
                      iVar30 = iVar30 + -1;
                      bVar39 = *(char *)&pCVar34->name == *pcVar5;
                      pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                    } while (bVar39);
                    if (!bVar39) {
                      iVar30 = 0xb;
                      pCVar34 = pCVar4;
                      pcVar5 = "-msie_hack";
                      do {
                        if (iVar30 == 0) break;
                        iVar30 = iVar30 + -1;
                        bVar39 = *(char *)&pCVar34->name == *pcVar5;
                        pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                        pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                      } while (bVar39);
                      if (bVar39) {
                        msie_hack = 1;
                        goto joined_r0x08058235;
                      }
                      iVar30 = 9;
                      pCVar34 = pCVar4;
                      pcVar5 = "-crldays";
                      do {
                        if (iVar30 == 0) break;
                        iVar30 = iVar30 + -1;
                        bVar39 = *(char *)&pCVar34->name == *pcVar5;
                        pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                        pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                      } while (bVar39);
                      if (bVar39) {
                        pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                        if (pEVar32 != (EVP_MD *)0x0) {
                          pBVar26 = (BIGNUM *)&local_370->top;
                          local_364 = strtol((char *)local_370->top,(char **)0x0,10);
                          pBVar36 = local_3a8;
                          goto joined_r0x08058235;
                        }
                      }
                      else {
                        iVar30 = 10;
                        pCVar34 = pCVar4;
                        pcVar5 = "-crlhours";
                        do {
                          if (iVar30 == 0) break;
                          iVar30 = iVar30 + -1;
                          bVar39 = *(char *)&pCVar34->name == *pcVar5;
                          pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                          pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                        } while (bVar39);
                        if (!bVar39) {
                          iVar30 = 8;
                          pCVar34 = pCVar4;
                          pcVar5 = "-crlsec";
                          do {
                            if (iVar30 == 0) break;
                            iVar30 = iVar30 + -1;
                            bVar39 = *(char *)&pCVar34->name == *pcVar5;
                            pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                            pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                          } while (bVar39);
                          if (bVar39) {
                            pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                            if (pEVar32 != (EVP_MD *)0x0) {
                              pBVar26 = (BIGNUM *)&local_370->top;
                              local_3f8 = strtol((char *)local_370->top,(char **)0x0,10);
                              pBVar36 = local_3a8;
                              goto joined_r0x08058235;
                            }
                            goto LAB_080585c4;
                          }
                          iVar30 = 9;
                          pCVar34 = pCVar4;
                          pcVar5 = "-infiles";
                          do {
                            if (iVar30 == 0) break;
                            iVar30 = iVar30 + -1;
                            bVar39 = *(char *)&pCVar34->name == *pcVar5;
                            pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                            pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                          } while (bVar39);
                          if (!bVar39) {
                            iVar30 = 9;
                            pCVar34 = pCVar4;
                            pcVar5 = "-ss_cert";
                            do {
                              if (iVar30 == 0) break;
                              iVar30 = iVar30 + -1;
                              bVar39 = *(char *)&pCVar34->name == *pcVar5;
                              pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                              pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                            } while (bVar39);
                            if (bVar39) {
                              pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                              if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
                              local_3d0 = (X509 *)0x1;
                              local_404 = (BIGNUM *)local_370->top;
                              pBVar26 = (BIGNUM *)&local_370->top;
                            }
                            else {
                              iVar30 = 7;
                              pCVar34 = pCVar4;
                              pcVar5 = "-spkac";
                              do {
                                if (iVar30 == 0) break;
                                iVar30 = iVar30 + -1;
                                bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                              } while (bVar39);
                              if (bVar39) {
                                pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                                if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
                                local_3d0 = (X509 *)0x1;
                                local_3dc = (EVP_MD *)local_370->top;
                                pBVar26 = (BIGNUM *)&local_370->top;
                              }
                              else {
                                iVar30 = 8;
                                pCVar34 = pCVar4;
                                pcVar5 = "-revoke";
                                do {
                                  if (iVar30 == 0) break;
                                  iVar30 = iVar30 + -1;
                                  bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                  pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                  pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                } while (bVar39);
                                if (bVar39) {
                                  pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                                  if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
                                  local_40c = 1;
                                  local_3e0 = (void *)local_370->top;
                                  pBVar26 = (BIGNUM *)&local_370->top;
                                }
                                else {
                                  iVar30 = 0xc;
                                  pCVar34 = pCVar4;
                                  pcVar5 = "-extensions";
                                  do {
                                    if (iVar30 == 0) break;
                                    iVar30 = iVar30 + -1;
                                    bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                    pCVar34 = (CONF_METHOD *)((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                    pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                  } while (bVar39);
                                  if (bVar39) {
                                    pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                                    if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
                                    local_3b0 = (EVP_MD *)local_370->top;
                                    pBVar26 = (BIGNUM *)&local_370->top;
                                  }
                                  else {
                                    iVar30 = 9;
                                    pCVar34 = pCVar4;
                                    pcVar5 = "-extfile";
                                    do {
                                      if (iVar30 == 0) break;
                                      iVar30 = iVar30 + -1;
                                      bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                      pCVar34 = (CONF_METHOD *)
                                                ((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                    } while (bVar39);
                                    if (bVar39) {
                                      pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                                      if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
                                      local_3e4 = (EVP_MD *)local_370->top;
                                      pBVar26 = (BIGNUM *)&local_370->top;
                                    }
                                    else {
                                      iVar30 = 8;
                                      pCVar34 = pCVar4;
                                      pcVar5 = "-status";
                                      do {
                                        if (iVar30 == 0) break;
                                        iVar30 = iVar30 + -1;
                                        bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                        pCVar34 = (CONF_METHOD *)
                                                  ((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                        pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                      } while (bVar39);
                                      if (bVar39) {
                                        pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                                        if (pEVar32 == (EVP_MD *)0x0) goto LAB_080585c4;
                                        local_380 = (X509 *)local_370->top;
                                        pBVar26 = (BIGNUM *)&local_370->top;
                                      }
                                      else {
                                        iVar30 = 10;
                                        pCVar34 = pCVar4;
                                        pcVar5 = "-updatedb";
                                        do {
                                          if (iVar30 == 0) break;
                                          iVar30 = iVar30 + -1;
                                          bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                          pCVar34 = (CONF_METHOD *)
                                                    ((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                          pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                        } while (bVar39);
                                        if (!bVar39) {
                                          iVar30 = 9;
                                          pCVar34 = pCVar4;
                                          pcVar5 = "-crlexts";
                                          do {
                                            if (iVar30 == 0) break;
                                            iVar30 = iVar30 + -1;
                                            bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                            pCVar34 = (CONF_METHOD *)
                                                      ((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                            pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                          } while (bVar39);
                                          if (bVar39) {
                                            pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                                            if (pEVar32 != (EVP_MD *)0x0) {
                                              local_3c8 = (EVP_MD *)local_370->top;
                                              pBVar26 = (BIGNUM *)&local_370->top;
                                              goto joined_r0x08058235;
                                            }
                                          }
                                          else {
                                            iVar30 = 0xc;
                                            pCVar34 = pCVar4;
                                            pcVar5 = "-crl_reason";
                                            do {
                                              if (iVar30 == 0) break;
                                              iVar30 = iVar30 + -1;
                                              bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                              pCVar34 = (CONF_METHOD *)
                                                        ((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                              pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                            } while (bVar39);
                                            if (bVar39) {
                                              pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                                              if (pEVar32 != (EVP_MD *)0x0) {
                                                local_3e8 = 1;
                                                local_3ec = (void *)local_370->top;
                                                pBVar26 = (BIGNUM *)&local_370->top;
                                                goto joined_r0x08058235;
                                              }
                                            }
                                            else {
                                              iVar30 = 10;
                                              pCVar34 = pCVar4;
                                              pcVar5 = "-crl_hold";
                                              do {
                                                if (iVar30 == 0) break;
                                                iVar30 = iVar30 + -1;
                                                bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                                pCVar34 = (CONF_METHOD *)
                                                          ((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                                pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                              } while (bVar39);
                                              if (bVar39) {
                                                pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                                                if (pEVar32 != (EVP_MD *)0x0) {
                                                  local_3e8 = 2;
                                                  local_3ec = (void *)local_370->top;
                                                  pBVar26 = (BIGNUM *)&local_370->top;
                                                  goto joined_r0x08058235;
                                                }
                                              }
                                              else {
                                                iVar30 = 0x10;
                                                pCVar34 = pCVar4;
                                                pcVar5 = "-crl_compromise";
                                                do {
                                                  if (iVar30 == 0) break;
                                                  iVar30 = iVar30 + -1;
                                                  bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                                  pCVar34 = (CONF_METHOD *)
                                                            ((int)pCVar34 + (uint)bVar42 * -2 + 1);
                                                  pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                                } while (bVar39);
                                                if (bVar39) {
                                                  pEVar32 = (EVP_MD *)
                                                            ((int)&pEVar32[-1].md_ctrl + 3);
                                                  if (pEVar32 != (EVP_MD *)0x0) {
                                                    local_3e8 = 3;
                                                    local_3ec = (void *)local_370->top;
                                                    pBVar26 = (BIGNUM *)&local_370->top;
                                                    goto joined_r0x08058235;
                                                  }
                                                }
                                                else {
                                                  iVar30 = 0x13;
                                                  pCVar34 = pCVar4;
                                                  pcVar5 = "-crl_CA_compromise";
                                                  do {
                                                    if (iVar30 == 0) break;
                                                    iVar30 = iVar30 + -1;
                                                    bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                                    pCVar34 = (CONF_METHOD *)
                                                              ((int)pCVar34 + (uint)bVar42 * -2 + 1)
                                                    ;
                                                    pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                                  } while (bVar39);
                                                  if (bVar39) {
                                                    pEVar32 = (EVP_MD *)
                                                              ((int)&pEVar32[-1].md_ctrl + 3);
                                                    if (pEVar32 != (EVP_MD *)0x0) {
                                                      local_3e8 = 4;
                                                      local_3ec = (void *)local_370->top;
                                                      pBVar26 = (BIGNUM *)&local_370->top;
                                                      goto joined_r0x08058235;
                                                    }
                                                  }
                                                  else {
                                                    iVar30 = 8;
                                                    pCVar34 = pCVar4;
                                                    pcVar5 = "-engine";
                                                    do {
                                                      if (iVar30 == 0) break;
                                                      iVar30 = iVar30 + -1;
                                                      bVar39 = *(char *)&pCVar34->name == *pcVar5;
                                                      pCVar34 = (CONF_METHOD *)
                                                                ((int)pCVar34 +
                                                                (uint)bVar42 * -2 + 1);
                                                      pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
                                                    } while (bVar39);
                                                    if ((bVar39) &&
                                                       (pEVar32 = (EVP_MD *)
                                                                  ((int)&pEVar32[-1].md_ctrl + 3),
                                                       pEVar32 != (EVP_MD *)0x0)) {
                                                      local_388 = (void *)local_370->top;
                                                      pBVar26 = (BIGNUM *)&local_370->top;
                                                      goto joined_r0x08058235;
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                          goto LAB_080585c4;
                                        }
                                        local_410 = (stack_st_CONF_VALUE *)0x1;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            goto joined_r0x08058235;
                          }
                          pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                          local_3d0 = (X509 *)0x1;
                          local_3a8 = (BIGNUM *)&local_370->top;
                          goto LAB_08058243;
                        }
                        pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
                        if (pEVar32 != (EVP_MD *)0x0) {
                          pBVar26 = (BIGNUM *)&local_370->top;
                          local_360 = strtol((char *)local_370->top,(char **)0x0,10);
                          pBVar36 = local_3a8;
                          goto joined_r0x08058235;
                        }
                      }
                      goto LAB_080585c4;
                    }
                    local_3f4 = 1;
                  }
                }
              }
            }
joined_r0x08058235:
            pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
            bVar39 = pEVar32 == (EVP_MD *)0x0;
            local_3a8 = (BIGNUM *)&pBVar26->top;
            local_370 = local_3a8;
            if (bVar39) goto LAB_08058243;
            goto LAB_08058209;
          }
          pEVar32 = (EVP_MD *)((int)&pEVar32[-1].md_ctrl + 3);
          if (pEVar32 != (EVP_MD *)0x0) {
            if ((local_3a4 == (_STACK *)0x0) &&
               (local_3a4 = sk_new_null(), local_3a4 == (_STACK *)0x0)) {
              pCVar4 = (CONF_METHOD *)local_370->d;
            }
            else {
              pBVar26 = (BIGNUM *)&local_370->top;
              iVar30 = sk_push(local_3a4,(void *)local_370->top);
              pBVar36 = local_3a8;
              if (iVar30 != 0) goto joined_r0x08058235;
              pCVar4 = (CONF_METHOD *)local_370->top;
            }
          }
        }
      }
    }
LAB_080585c4:
    puVar33 = ca_usage;
    BIO_printf(bio_err,"unknown option %s\n",pCVar4);
    iVar30 = ca_usage._0_4_;
    while (iVar30 != 0) {
      puVar33 = (undefined1 *)((int)puVar33 + 4);
      BIO_printf(bio_err,"%s",iVar30);
      iVar30 = *(int *)puVar33;
    }
    goto LAB_080582dd;
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
  local_37c = (char *)0x0;
  local_3e4 = (EVP_MD *)0x0;
  local_3b0 = (EVP_MD *)0x0;
  local_3c0 = (char *)0x0;
  local_400 = (EVP_MD *)0x0;
  local_380 = (X509 *)0x0;
  local_404 = (BIGNUM *)0x0;
  local_3dc = (EVP_MD *)0x0;
  local_3e0 = (void *)0x0;
  local_414 = (X509 *)0x3;
  local_3fc = (char *)0x0;
  local_384 = (EVP_PKEY *)0x0;
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
LAB_08058243:
  ERR_load_crypto_strings();
  if (((local_378 == (EVP_MD *)0x0) &&
      (local_378 = (EVP_MD *)getenv("OPENSSL_CONF"), local_378 == (EVP_MD *)0x0)) &&
     (local_378 = (EVP_MD *)getenv("SSLEAY_CONF"), local_378 == (EVP_MD *)0x0)) {
    local_370 = (BIGNUM *)X509_get_default_cert_area();
    sVar11 = strlen((char *)local_370);
    sVar11 = sVar11 + 0xd;
    pcVar35 = (char *)CRYPTO_malloc(sVar11,"ca.c",0x254);
    BUF_strlcpy(pcVar35,(char *)local_370,sVar11);
    BUF_strlcat(pcVar35,"/",sVar11);
    BUF_strlcat(pcVar35,"openssl.cnf",sVar11);
    BIO_printf(bio_err,"Using configuration from %s\n",pcVar35);
    conf = (BIGNUM *)NCONF_new((CONF_METHOD *)0x0);
    local_370 = (BIGNUM *)&local_35c;
    iVar30 = NCONF_load((CONF *)conf,pcVar35,(long *)local_370);
    pcVar5 = pcVar35;
    if (iVar30 < 1) goto LAB_080582a5;
    if (pcVar35 != (char *)0x0) {
      CRYPTO_free(pcVar35);
    }
LAB_08058719:
    iVar30 = load_config(bio_err,conf);
    if (iVar30 == 0) goto LAB_080582dd;
    local_41c = setup_engine(bio_err,local_388,0);
    if ((section == (EVP_MD *)0x0) &&
       (section = (EVP_MD *)NCONF_get_string((CONF *)conf,"ca","default_ca"),
       section == (EVP_MD *)0x0)) {
      BIO_printf(bio_err,"variable lookup failed for %s::%s\n","ca","default_ca");
      goto LAB_080582dd;
    }
    if (conf != (BIGNUM *)0x0) {
      pcVar5 = NCONF_get_string((CONF *)conf,(char *)0x0,"oid_file");
      if ((pcVar5 == (char *)0x0) || (pBVar6 = BIO_new_file(pcVar5,"r"), pBVar6 == (BIO *)0x0)) {
        ERR_clear_error();
      }
      else {
        OBJ_create_objects(pBVar6);
        BIO_free(pBVar6);
      }
      iVar30 = add_oid_section(bio_err,conf);
      if (iVar30 == 0) {
        ERR_print_errors(bio_err);
        goto LAB_080582dd;
      }
    }
    local_398 = NCONF_get_string((CONF *)conf,"ca","RANDFILE");
    if (local_398 == (char *)0x0) {
      ERR_clear_error();
    }
    app_RAND_load_file(local_398,bio_err,0);
    pcVar5 = NCONF_get_string((CONF *)conf,(char *)section,"string_mask");
    if (pcVar5 != (char *)0x0) {
      iVar30 = ASN1_STRING_set_default_mask_asc(pcVar5);
      if (iVar30 != 0) goto LAB_08058850;
      BIO_printf(bio_err,"Invalid global string mask setting %s\n",pcVar5);
      goto LAB_080582e7;
    }
    ERR_clear_error();
LAB_08058850:
    if (local_3a0 == (BIGNUM *)0x1000) {
LAB_08058897:
      local_3a0 = (BIGNUM *)0x1000;
    }
    else {
      pcVar5 = NCONF_get_string((CONF *)conf,(char *)section,"utf8");
      if (pcVar5 == (char *)0x0) {
        ERR_clear_error();
      }
      else if ((((*pcVar5 == 'y') && (pcVar5[1] == 'e')) && (pcVar5[2] == 's')) &&
              (pcVar5[3] == '\0')) goto LAB_08058897;
    }
    local_340 = 1;
    pcVar5 = NCONF_get_string((CONF *)conf,(char *)section,"unique_subject");
    if (pcVar5 == (char *)0x0) {
      ERR_clear_error();
    }
    else {
      local_340 = parse_yesno(pcVar5,1);
    }
    pBVar7 = BIO_s_file();
    pBVar6 = BIO_new(pBVar7);
    local_39c = pBVar6;
    pBVar7 = BIO_s_file();
    pBVar8 = BIO_new(pBVar7);
    local_390 = pBVar8;
    pBVar7 = BIO_s_file();
    local_38c = BIO_new(pBVar7);
    pBVar7 = BIO_s_file();
    local_394 = BIO_new(pBVar7);
    if (((pBVar6 == (BIO *)0x0) || (pBVar8 == (BIO *)0x0)) ||
       ((local_38c == (BIO *)0x0 || (local_394 == (BIO *)0x0)))) {
      ERR_print_errors(bio_err);
      local_378 = (EVP_MD *)0x0;
    }
    else {
      if (local_380 == (X509 *)0x0) {
        if ((local_384 == (EVP_PKEY *)0x0) &&
           (local_384 = (EVP_PKEY *)NCONF_get_string((CONF *)conf,(char *)section,"private_key"),
           local_384 == (EVP_PKEY *)0x0)) {
          pcVar5 = "private_key";
          goto LAB_0805b7c5;
        }
        local_388 = (void *)0x0;
        if (local_368 == (byte *)0x0) {
          iVar30 = app_passwd(bio_err,local_408,0,&local_368,0);
          if (iVar30 == 0) {
            x_00 = (X509_CRL *)0x0;
            pBVar36 = (BIGNUM *)0x0;
            iVar30 = 1;
            BIO_printf(bio_err,"Error getting password\n");
            local_370 = (BIGNUM *)0x0;
            local_378 = (EVP_MD *)0x0;
            local_380 = (X509 *)0x0;
            local_384 = (EVP_PKEY *)0x0;
            local_388 = (void *)0x1;
            goto LAB_0805834a;
          }
          local_388 = (void *)0x1;
        }
        pcVar5 = "CA private key";
        local_384 = (EVP_PKEY *)
                    load_key(bio_err,local_384,local_414,0,local_368,local_41c,"CA private key");
        pbVar9 = local_368;
        if (local_368 != (byte *)0x0) {
          sVar11 = strlen((char *)local_368);
          OPENSSL_cleanse(pbVar9,sVar11);
        }
        if (local_384 == (EVP_PKEY *)0x0) {
LAB_0805931f:
          local_370 = (BIGNUM *)0x0;
          x_00 = (X509_CRL *)0x0;
          local_378 = (EVP_MD *)0x0;
          local_380 = (X509 *)0x0;
          pBVar36 = (BIGNUM *)0x0;
          iVar30 = 1;
          goto LAB_0805834a;
        }
        if ((((local_3f0 == 0) || (local_3dc != (EVP_MD *)0x0)) || (local_404 != (BIGNUM *)0x0)) ||
           (local_380 = (X509 *)0x0, local_3f4 != 0)) {
          if (local_3fc == (char *)0x0) {
            pcVar5 = "certificate";
            local_3fc = NCONF_get_string((CONF *)conf,(char *)section,"certificate");
            if (local_3fc == (char *)0x0) {
              BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,"certificate");
              goto LAB_0805931f;
            }
          }
          local_380 = (X509 *)load_cert(bio_err,local_3fc,3,0,local_41c,"CA certificate");
          if (local_380 == (X509 *)0x0) goto LAB_08059032;
          iVar30 = X509_check_private_key(local_380,local_384);
          if (iVar30 != 0) {
            local_414 = local_380;
            if (local_3f0 != 0) goto LAB_08058e66;
            goto LAB_08058e70;
          }
          pcVar35 = "CA certificate and CA private key do not match\n";
LAB_0805b56e:
          BIO_printf(bio_err,pcVar35,pcVar5);
LAB_08059032:
          local_370 = (BIGNUM *)0x0;
          x_00 = (X509_CRL *)0x0;
          local_378 = (EVP_MD *)0x0;
LAB_08059048:
          pBVar36 = (BIGNUM *)0x0;
        }
        else {
LAB_08058e66:
          local_414 = (X509 *)0x0;
LAB_08058e70:
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
          pcVar5 = NCONF_get_string((CONF *)conf,(char *)section,"name_opt");
          if ((EVP_MD *)pcVar5 == (EVP_MD *)0x0) {
            ERR_clear_error();
            local_408 = (void *)0x1;
          }
          else {
            iVar30 = set_name_ex(&local_350,pcVar5);
            local_408 = (void *)0x0;
            if (iVar30 == 0) {
              pcVar35 = "Invalid name options: \"%s\"\n";
              goto LAB_0805b56e;
            }
          }
          pcVar5 = NCONF_get_string((CONF *)conf,(char *)section,"cert_opt");
          if ((EVP_MD *)pcVar5 == (EVP_MD *)0x0) {
            ERR_clear_error();
          }
          else {
            iVar30 = set_cert_ex(&local_34c,pcVar5);
            local_408 = (void *)0x0;
            if (iVar30 == 0) {
              pcVar35 = "Invalid certificate options: \"%s\"\n";
              goto LAB_0805b56e;
            }
          }
          pcVar5 = NCONF_get_string((CONF *)conf,(char *)section,"copy_extensions");
          if ((EVP_MD *)pcVar5 == (EVP_MD *)0x0) {
            ERR_clear_error();
          }
          else {
            iVar30 = set_ext_copy(&local_348,pcVar5);
            if (iVar30 == 0) {
              pcVar35 = "Invalid extension copy option: \"%s\"\n";
              goto LAB_0805b56e;
            }
          }
          if ((local_3c0 == (char *)0x0) && (local_3d0 != (X509 *)0x0)) {
            pcVar5 = "new_certs_dir";
            pcVar35 = NCONF_get_string((CONF *)conf,(char *)section,"new_certs_dir");
            local_3c0 = pcVar35;
            if (pcVar35 == (char *)0x0) {
              pcVar35 = 
              "there needs to be defined a directory for new certificate to be placed in\n";
              goto LAB_0805b56e;
            }
            iVar30 = access(pcVar35,7);
            if (iVar30 == 0) {
              iVar30 = app_isdir(local_3c0);
              pcVar5 = local_3c0;
              if (0 < iVar30) goto LAB_08059364;
              BIO_printf(bio_err,"%s need to be a directory\n",local_3c0);
              perror(pcVar5);
            }
            else {
              BIO_printf(bio_err,"I am unable to access the %s directory\n",pcVar35);
              perror(pcVar35);
            }
            goto LAB_08059032;
          }
LAB_08059364:
          local_3fc = NCONF_get_string((CONF *)conf,(char *)section,"database");
          if (local_3fc == (char *)0x0) {
            pcVar35 = "variable lookup failed for %s::%s\n";
            pcVar5 = (char *)section;
            goto LAB_0805b56e;
          }
          local_378 = (EVP_MD *)load_index(local_3fc,local_344 + 4);
          if (local_378 == (EVP_MD *)0x0) {
LAB_080594bd:
            local_370 = (BIGNUM *)0x0;
LAB_080594c7:
            x_00 = (X509_CRL *)0x0;
            goto LAB_08059048;
          }
          for (iVar37 = 0; iVar30 = sk_num(*(_STACK **)((int)local_378->pkey_type + 4)),
              pBVar6 = local_390, iVar37 < iVar30; iVar37 = iVar37 + 1) {
            ppcVar15 = (char **)sk_value(*(_STACK **)((int)local_378->pkey_type + 4),iVar37);
            if (**ppcVar15 == 'R') {
              iVar30 = make_revoked(0,ppcVar15[2]);
              if (iVar30 == 0) {
                pcVar35 = " in entry %d\n";
                pcVar5 = (char *)(iVar37 + 1);
                goto LAB_080594af;
              }
            }
            else if (*ppcVar15[2] != '\0') {
              pcVar35 = "entry %d: not revoked yet, but has a revocation date\n";
              pcVar5 = (char *)(iVar37 + 1);
              goto LAB_080594af;
            }
            iVar30 = ASN1_TIME_set_string((ASN1_TIME *)0x0,ppcVar15[1]);
            if (iVar30 == 0) {
              pcVar35 = "entry %d: invalid expiry date\n";
              pcVar5 = (char *)(iVar37 + 1);
              goto LAB_080594af;
            }
            pbVar21 = (byte *)ppcVar15[3];
            uVar10 = strlen((char *)pbVar21);
            pbVar9 = pbVar21;
            if (*pbVar21 == 0x2d) {
              pbVar9 = pbVar21 + 1;
              uVar10 = uVar10 - 1;
            }
            if (((int)uVar10 < 2) || ((uVar10 & 1) != 0)) {
              pcVar35 = "entry %d: bad serial number length (%d)\n";
              pcVar5 = (char *)(iVar37 + 1);
              goto LAB_080594af;
            }
            while( true ) {
              bVar2 = *pbVar9;
              if (bVar2 == 0) break;
              if ((5 < (byte)((bVar2 & 0xdf) + 0xbf)) && (9 < (byte)(bVar2 - 0x30))) {
                x_00 = (X509_CRL *)0x0;
                pBVar36 = (BIGNUM *)0x0;
                iVar30 = 1;
                BIO_printf(bio_err,
                           "entry %d: bad serial number characters, char pos %ld, char is \'%c\'\n",
                           iVar37 + 1,(int)pbVar9 - (int)pbVar21,(int)(char)bVar2);
                local_370 = (BIGNUM *)0x0;
                goto LAB_0805834a;
              }
              pbVar9 = pbVar9 + 1;
            }
          }
          if (local_374 != 0) {
            BIO_ctrl(local_390,0x6a,0x10,stdout);
            pEVar17 = local_378;
            TXT_DB_write(pBVar6,(TXT_DB *)local_378->pkey_type);
            iVar30 = sk_num(*(_STACK **)((int)pEVar17->pkey_type + 4));
            BIO_printf(bio_err,"%d entries loaded from the database\n",iVar30);
            BIO_printf(bio_err,"generating index\n");
          }
          iVar30 = index_index(local_378);
          if (iVar30 == 0) goto LAB_080594bd;
          if (local_410 != (stack_st_CONF_VALUE *)0x0) {
            if (local_374 != 0) {
              BIO_printf(bio_err,"Updating %s ...\n",local_3fc);
            }
            s = ASN1_UTCTIME_new();
            pEVar16 = (EVP_MD *)X509_gmtime_adj(s,0);
            pcVar5 = (char *)0xa44;
            local_410 = (stack_st_CONF_VALUE *)pEVar16->type;
            local_424 = pEVar16;
            pEVar17 = (EVP_MD *)CRYPTO_malloc((int)((int)&(local_410->stack).num + 1),"ca.c",0xa44);
            local_428 = pEVar17;
            if (pEVar17 != (EVP_MD *)0x0) {
              uVar38 = auStack_44c < &DAT_00000004;
              uVar40 = &stack0x00000000 == (undefined *)0x450;
              memcpy(pEVar17,(uchar *)pEVar16->md_size,pEVar16->type);
              iVar30 = 2;
              local_410 = (stack_st_CONF_VALUE *)0x0;
              local_420 = (char *)0x0;
              *(undefined *)((int)pEVar17->required_pkey_type + pEVar16->type + -0x2c) = 0;
              pbVar9 = &DAT_081edada;
              do {
                if (iVar30 == 0) break;
                iVar30 = iVar30 + -1;
                uVar38 = *(byte *)&pEVar17->type < *pbVar9;
                uVar40 = *(byte *)&pEVar17->type == *pbVar9;
                pEVar17 = (EVP_MD *)((int)pEVar17 + (uint)bVar42 * -2 + 1);
                pbVar9 = pbVar9 + (uint)bVar42 * -2 + 1;
              } while ((bool)uVar40);
              local_42c = (BIGNUM *)(int)(char)((!(bool)uVar38 && !(bool)uVar40) - uVar38);
              local_434 = local_3a8;
              local_430 = pEVar32;
              while (iVar30 = sk_num(*(_STACK **)((int)local_378->pkey_type + 4)),
                    pEVar32 = local_430, (int)local_420 < iVar30) {
                ppBVar18 = (BIGNUM **)
                           sk_value(*(_STACK **)((int)local_378->pkey_type + 4),(int)local_420);
                local_3a8 = *ppBVar18;
                bVar39 = *(byte *)&local_3a8->d < 0x56;
                bVar41 = *(char *)&local_3a8->d == 'V';
                if (bVar41) {
                  iVar30 = 2;
                  pBVar36 = ppBVar18[1];
                  pbVar9 = &DAT_081edada;
                  do {
                    if (iVar30 == 0) break;
                    iVar30 = iVar30 + -1;
                    bVar39 = *(byte *)&pBVar36->d < *pbVar9;
                    bVar41 = *(byte *)&pBVar36->d == *pbVar9;
                    pBVar36 = (BIGNUM *)((int)pBVar36 + (uint)bVar42 * -2 + 1);
                    pbVar9 = pbVar9 + (uint)bVar42 * -2 + 1;
                  } while (bVar41);
                  if ((char)((!bVar39 && !bVar41) - bVar39) < '\x01') {
                    if ((int)local_42c < 1) goto LAB_0805b53f;
                  }
                  else {
                    if (0 < (int)local_42c) {
LAB_0805b53f:
                      iVar30 = strcmp((char *)ppBVar18[1],(char *)local_428);
                      if (0 < iVar30) goto LAB_08059693;
                    }
                    *(undefined *)&local_3a8->d = 0x45;
                    *(undefined *)((int)&(*ppBVar18)->d + 1) = 0;
                    local_410 = (stack_st_CONF_VALUE *)((int)&(local_410->stack).num + 1);
                    BIO_printf(bio_err,"%s=Expired\n",ppBVar18[3]);
                  }
                }
LAB_08059693:
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
                iVar30 = save_index(local_3fc,&DAT_081eac52,local_378);
                if ((iVar30 == 0) ||
                   (iVar30 = rotate_index(local_3fc,&DAT_081eac52,"old"), iVar30 == 0))
                goto LAB_080594bd;
                if (local_374 != 0) {
                  BIO_printf(bio_err,"Done. %d entries marked as expired\n",local_410);
                }
              }
              goto LAB_08059709;
            }
            ASN1_UTCTIME_free((ASN1_UTCTIME *)local_424);
            CRYPTO_free((void *)0x0);
            pcVar35 = "Malloc failure\n";
LAB_080594af:
            BIO_printf(bio_err,pcVar35,pcVar5);
            goto LAB_080594bd;
          }
LAB_08059709:
          pEVar17 = local_3e4;
          if (local_3e4 != (EVP_MD *)0x0) {
            extconf = NCONF_new((CONF_METHOD *)0x0);
            iVar30 = NCONF_load(extconf,(char *)pEVar17,(long *)local_370);
            if (iVar30 < 1) {
              if ((int)local_35c < 1) {
                pcVar35 = "ERROR: loading the config file \'%s\'\n";
                pcVar5 = (char *)local_3e4;
              }
              else {
                pcVar35 = "ERROR: on line %ld of config file \'%s\'\n";
                pcVar5 = (char *)local_35c;
              }
              goto LAB_080594af;
            }
            if (local_374 != 0) {
              BIO_printf(bio_err,"Successfully loaded extensions file %s\n",local_3e4);
            }
            if (local_3b0 == (EVP_MD *)0x0) {
              pEVar17 = (EVP_MD *)NCONF_get_string(extconf,"default","extensions");
              local_3b0 = (EVP_MD *)0x822e390;
              if (pEVar17 != (EVP_MD *)0x0) {
                local_3b0 = pEVar17;
              }
            }
          }
          if (((uint)local_3d0 | local_3f4) != 0) {
            if (local_400 == (EVP_MD *)0x0) {
              BIO_ctrl(local_38c,0x6a,0x10,stdout);
            }
            else {
              lVar19 = BIO_ctrl(local_38c,0x6c,5,local_400);
              if (lVar19 < 1) {
                perror((char *)local_400);
                goto LAB_080594bd;
              }
            }
          }
          bVar39 = local_3d4 == (EVP_MD *)0x0;
          if (bVar39) {
            local_3d4 = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"default_md");
            bVar39 = local_3d4 == (EVP_MD *)0x0;
            if (bVar39) {
              pcVar35 = "variable lookup failed for %s::%s\n";
              pcVar5 = (char *)section;
              goto LAB_080594af;
            }
          }
          iVar30 = 8;
          pEVar17 = local_3d4;
          pcVar5 = "default";
          do {
            if (iVar30 == 0) break;
            iVar30 = iVar30 + -1;
            bVar39 = *(char *)&pEVar17->type == *pcVar5;
            pEVar17 = (EVP_MD *)((int)pEVar17 + (uint)bVar42 * -2 + 1);
            pcVar5 = pcVar5 + (uint)bVar42 * -2 + 1;
          } while (bVar39);
          if (bVar39) {
            iVar30 = EVP_PKEY_get_default_digest_nid(local_384,(int *)local_33c);
            if (iVar30 < 1) {
              BIO_puts(bio_err,"no default digest\n");
              goto LAB_080594bd;
            }
            local_3d4 = (EVP_MD *)OBJ_nid2sn(local_33c._0_4_);
          }
          local_3e4 = EVP_get_digestbyname((char *)local_3d4);
          if (local_3e4 == (EVP_MD *)0x0) {
            pcVar35 = "%s is an unsupported message digest type\n";
            pcVar5 = (char *)local_3d4;
            goto LAB_080594af;
          }
          if (local_3d0 == (X509 *)0x0) {
            local_370 = (BIGNUM *)0x0;
            goto LAB_0805a654;
          }
          if ((local_3cc == 1) &&
             (pbVar9 = (byte *)NCONF_get_string((CONF *)conf,(char *)section,"email_in_dn"),
             pbVar9 != (byte *)0x0)) {
            iVar30 = 0x6e - (uint)*pbVar9;
            if ((iVar30 == 0) && (iVar30 = 0x6f - (uint)pbVar9[1], iVar30 == 0)) {
              iVar30 = -(uint)pbVar9[2];
            }
            local_3cc = (uint)(iVar30 != 0);
          }
          if (local_374 == 0) {
            if ((local_3c4 == (EVP_MD *)0x0) &&
               (local_3c4 = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"policy"),
               local_3c4 == (EVP_MD *)0x0)) {
LAB_0805b293:
              pcVar35 = "variable lookup failed for %s::%s\n";
              pcVar5 = (char *)section;
              goto LAB_080594af;
            }
          }
          else {
            pcVar5 = OBJ_nid2ln((int)local_3e4->type);
            BIO_printf(bio_err,"message digest is %s\n",pcVar5);
            if ((local_3c4 == (EVP_MD *)0x0) &&
               (local_3c4 = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"policy"),
               local_3c4 == (EVP_MD *)0x0)) goto LAB_0805b293;
            BIO_printf(bio_err,"policy is %s\n",local_3c4);
          }
          pcVar5 = "serial";
          local_420 = NCONF_get_string((CONF *)conf,(char *)section,"serial");
          if (local_420 == (char *)0x0) {
            pcVar35 = "variable lookup failed for %s::%s\n";
            pcVar5 = (char *)section;
            goto LAB_080594af;
          }
          if (extconf == (CONF *)0x0) {
            if (local_3b0 == (EVP_MD *)0x0) {
              pcVar5 = "x509_extensions";
              local_3b0 = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"x509_extensions")
              ;
              if (local_3b0 == (EVP_MD *)0x0) {
                ERR_clear_error();
                goto LAB_080598bd;
              }
            }
            X509V3_set_ctx((X509V3_CTX *)local_33c,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,
                           (X509_CRL *)0x0,1);
            X509V3_set_nconf((X509V3_CTX *)local_33c,(CONF *)conf);
            iVar30 = X509V3_EXT_add_nconf
                               ((CONF *)conf,(X509V3_CTX *)local_33c,(char *)local_3b0,(X509 *)0x0);
            if (iVar30 == 0) {
              pcVar35 = "Error Loading extension section %s\n";
              pcVar5 = (char *)local_3b0;
              goto LAB_080594af;
            }
          }
LAB_080598bd:
          if (local_3b8 == (char *)0x0) {
            pcVar5 = "default_startdate";
            local_3b8 = NCONF_get_string((CONF *)conf,(char *)section,"default_startdate");
            if (local_3b8 != (char *)0x0) goto LAB_080598cb;
            ERR_clear_error();
            local_3b8 = "today";
          }
          else {
LAB_080598cb:
            iVar30 = ASN1_TIME_set_string((ASN1_TIME *)0x0,local_3b8);
            if (iVar30 == 0) {
              pcVar35 = "start date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n";
              goto LAB_080594af;
            }
          }
          if (local_3bc == (EVP_MD *)0x0) {
            pcVar5 = "default_enddate";
            local_3bc = (EVP_MD *)NCONF_get_string((CONF *)conf,(char *)section,"default_enddate");
            if (local_3bc != (EVP_MD *)0x0) goto LAB_080598f4;
            ERR_clear_error();
          }
          else {
LAB_080598f4:
            iVar30 = ASN1_TIME_set_string((ASN1_TIME *)0x0,(char *)local_3bc);
            if (iVar30 == 0) {
              pcVar35 = "end date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n";
              goto LAB_080594af;
            }
          }
          if (local_354 == (EVP_MD *)0x0) {
            pcVar5 = "default_days";
            iVar30 = NCONF_get_number_e((CONF *)conf,(char *)section,"default_days",
                                        (long *)&local_354);
            if (iVar30 == 0) {
              local_354 = (EVP_MD *)0x0;
              pEVar17 = local_3bc;
            }
            else {
              pEVar17 = local_354;
              if (local_3bc != (EVP_MD *)0x0) goto LAB_0805991d;
            }
            if (pEVar17 == (EVP_MD *)0x0) {
              pcVar35 = "cannot lookup how many days to certify for\n";
              goto LAB_080594af;
            }
          }
LAB_0805991d:
          pcVar5 = (char *)0x0;
          local_358 = (BIGNUM *)load_serial(local_420,local_3ac,0);
          if (local_358 == (BIGNUM *)0x0) {
            pcVar35 = "error while loading serial number\n";
            goto LAB_080594af;
          }
          if (local_374 != 0) {
            if (local_358->top == 0) {
              BIO_printf(bio_err,"next serial number is 00\n");
            }
            else {
              pEVar17 = (EVP_MD *)BN_bn2hex(local_358);
              if (pEVar17 == (EVP_MD *)0x0) goto LAB_080594bd;
              pcVar5 = (char *)pEVar17;
              BIO_printf(bio_err,"next serial number is %s\n",pEVar17);
              CRYPTO_free(pEVar17);
            }
          }
          local_410 = NCONF_get_section((CONF *)conf,(char *)local_3c4);
          if (local_410 == (stack_st_CONF_VALUE *)0x0) {
            pcVar35 = "unable to find \'section\' for %s\n";
            pcVar5 = (char *)local_3c4;
            goto LAB_080594af;
          }
          local_370 = (BIGNUM *)sk_new_null();
          if (local_370 == (BIGNUM *)0x0) {
LAB_0805b032:
            pcVar35 = "Memory allocation failure\n";
LAB_0805a8e8:
            x_00 = (X509_CRL *)0x0;
            pBVar36 = (BIGNUM *)0x0;
            iVar30 = 1;
            BIO_printf(bio_err,pcVar35,pcVar5);
            goto LAB_0805834a;
          }
          if (local_3dc == (EVP_MD *)0x0) {
            local_424 = (EVP_MD *)0x2;
            local_3dc = (EVP_MD *)0x2;
            pEVar17 = (EVP_MD *)0x0;
            local_3c4 = (EVP_MD *)0x1;
            local_3ac = (EVP_MD *)0x1;
            pEVar16 = (EVP_MD *)0x0;
            local_3d4 = (EVP_MD *)0x0;
            goto LAB_08059d4d;
          }
          local_428 = local_348;
          local_42c = local_350;
          local_430 = local_34c;
          local_434 = conf;
          local_438 = local_354;
          local_43c = local_358;
          pcVar5 = local_33c;
          local_3c4 = (EVP_MD *)
                      CONF_load((lhash_st_CONF_VALUE *)0x0,(char *)local_3dc,(long *)pcVar5);
          if (local_3c4 == (EVP_MD *)0x0) {
            x_00 = (X509_CRL *)0x0;
            pBVar36 = (BIGNUM *)0x0;
            iVar30 = 1;
            BIO_printf(bio_err,"error on line %ld of %s\n",local_33c._0_4_,local_3dc);
            ERR_print_errors(bio_err);
            goto LAB_0805834a;
          }
          local_440 = (_STACK *)CONF_get_section((lhash_st_CONF_VALUE *)local_3c4,"default");
          iVar30 = sk_num(local_440);
          if (iVar30 == 0) {
            BIO_printf(bio_err,"no name/value pairs found in %s\n",local_3dc);
            CONF_free((lhash_st_CONF_VALUE *)local_3c4);
LAB_0805af7e:
            CONF_free((lhash_st_CONF_VALUE *)local_3c4);
            goto LAB_080594c7;
          }
          local_3d0 = (X509 *)X509_REQ_new();
          if (local_3d0 == (X509 *)0x0) {
            ERR_print_errors(bio_err);
            goto LAB_0805af7e;
          }
          local_424 = (EVP_MD *)0x0;
          local_3ac = (EVP_MD *)0x0;
          local_444 = (X509_NAME *)local_3d0->cert_info->validity;
          local_3d4 = pEVar32;
          while (p_Var3 = local_440, iVar30 = sk_num(local_440), pEVar32 = local_3d4,
                (int)local_424 < iVar30) {
            pvVar20 = sk_value(p_Var3,(int)local_424);
            pbVar9 = *(byte **)((int)pvVar20 + 4);
            bVar2 = *pbVar9;
            pbVar21 = pbVar9;
            while (bVar2 != 0) {
              if (((bVar2 & 0xfd) == 0x2c) || (bVar2 == 0x3a)) {
                if (*(byte *)((int)pbVar21 + 1) != 0) {
                  pbVar9 = (byte *)((int)pbVar21 + 1);
                }
                break;
              }
              pbVar21 = (byte *)((int)pbVar21 + 1);
              bVar2 = *pbVar21;
            }
            bytes = *(uchar **)((int)pvVar20 + 8);
            iVar30 = OBJ_txt2nid((char *)pbVar9);
            bVar39 = iVar30 == 0;
            if (bVar39) {
              iVar30 = 6;
              pbVar21 = (byte *)0x8227806;
              do {
                if (iVar30 == 0) break;
                iVar30 = iVar30 + -1;
                bVar39 = *pbVar9 == *pbVar21;
                pbVar9 = pbVar9 + (uint)bVar42 * -2 + 1;
                pbVar21 = pbVar21 + (uint)bVar42 * -2 + 1;
              } while (bVar39);
              if ((bVar39) &&
                 (local_3ac = (EVP_MD *)NETSCAPE_SPKI_b64_decode(*(char **)((int)pvVar20 + 8),-1),
                 pEVar32 = local_3d4, local_3ac == (EVP_MD *)0x0)) {
                iVar30 = -1;
                BIO_printf(bio_err,"unable to load Netscape SPKAC structure\n");
                ERR_print_errors(bio_err);
                goto LAB_08059c64;
              }
            }
            else {
              pcVar5 = (char *)0x0;
              iVar30 = X509_NAME_add_entry_by_NID(local_444,iVar30,(int)local_3a0,bytes,-1,-1,0);
              if (iVar30 == 0) {
                iVar30 = -1;
                pEVar32 = local_3d4;
                goto LAB_08059c64;
              }
            }
            local_424 = (EVP_MD *)((int)&local_424->type + 1);
          }
          if (local_3ac == (EVP_MD *)0x0) {
            iVar30 = -1;
            pcVar5 = (char *)local_3dc;
            BIO_printf(bio_err,"Netscape SPKAC structure not found in %s\n",local_3dc);
          }
          else {
            BIO_printf(bio_err,"Check that the SPKAC request matches the signature\n");
            pEVar22 = NETSCAPE_SPKI_get_pubkey((NETSCAPE_SPKI *)local_3ac);
            if (pEVar22 == (EVP_PKEY *)0x0) {
              iVar30 = -1;
              BIO_printf(bio_err,"error unpacking SPKAC public key\n");
            }
            else {
              iVar30 = NETSCAPE_SPKI_verify((NETSCAPE_SPKI *)local_3ac,pEVar22);
              if (iVar30 < 1) {
                iVar30 = -1;
                BIO_printf(bio_err,"signature verification failed on SPKAC public key\n");
              }
              else {
                BIO_printf(bio_err,"Signature ok\n");
                pXVar29 = local_3d0;
                X509_REQ_set_pubkey((X509_REQ *)local_3d0,pEVar22);
                EVP_PKEY_free(pEVar22);
                iVar30 = do_body(local_3e4,local_3a4,local_410,local_378,local_43c,local_37c,
                                 local_3a0,local_3b4,local_3cc,local_3b8,local_3bc,local_438,1,
                                 local_374,pXVar29,local_3b0,local_434,local_430,local_42c,local_408
                                 ,local_428,0);
              }
            }
          }
LAB_08059c64:
          X509_REQ_free((X509_REQ *)local_3d0);
          CONF_free((lhash_st_CONF_VALUE *)local_3c4);
          if (local_3ac != (EVP_MD *)0x0) {
            NETSCAPE_SPKI_free((NETSCAPE_SPKI *)local_3ac);
          }
          if (iVar30 < 0) goto LAB_080594c7;
          if (iVar30 == 0) {
            local_424 = (EVP_MD *)0x2;
            local_3dc = (EVP_MD *)0x3;
            pEVar17 = (EVP_MD *)0x0;
            local_3c4 = (EVP_MD *)0x1;
            local_3ac = (EVP_MD *)0x2;
            pEVar16 = (EVP_MD *)0x1;
            local_3d4 = (EVP_MD *)0x0;
          }
          else {
            BIO_printf(bio_err,"\n");
            iVar30 = BN_add_word(local_358,1);
            if (iVar30 == 0) goto LAB_080594c7;
            iVar30 = sk_push((_STACK *)local_370,(void *)local_344);
            if (iVar30 == 0) goto LAB_0805b032;
            pEVar17 = (EVP_MD *)0x1;
            local_424 = (EVP_MD *)0x3;
            local_3dc = (EVP_MD *)0x3;
            local_3c4 = (EVP_MD *)0x2;
            local_3ac = (EVP_MD *)0x2;
            local_3d4 = (EVP_MD *)(uint)(local_400 != (EVP_MD *)0x0);
            pEVar16 = (EVP_MD *)0x1;
            if (local_400 != (EVP_MD *)0x0) {
              local_3d8 = 1;
            }
          }
LAB_08059d4d:
          pBVar36 = local_404;
          pEVar23 = local_3ac;
          if (local_404 == (BIGNUM *)0x0) goto LAB_08059ee4;
          local_400 = local_348;
          local_404 = local_350;
          local_428 = local_34c;
          local_42c = conf;
          local_430 = local_354;
          local_434 = local_358;
          local_3d0 = (X509 *)load_cert(bio_err,pBVar36,3,0,local_41c,pBVar36);
          if (local_3d0 == (X509 *)0x0) goto LAB_080594c7;
          if (local_374 != 0) {
            X509_print(bio_err,local_3d0);
          }
          BIO_printf(bio_err,"Check that the request matches the signature\n");
          pEVar22 = X509_get_pubkey(local_3d0);
          if (pEVar22 == (EVP_PKEY *)0x0) {
            iVar30 = -1;
            BIO_printf(bio_err,"error unpacking public key\n");
          }
          else {
            local_438 = (EVP_MD *)X509_verify(local_3d0,pEVar22);
            EVP_PKEY_free(pEVar22);
            if ((int)local_438 < 0) {
              iVar30 = 0;
              BIO_printf(bio_err,"Signature verification problems....\n");
            }
            else if (local_438 == (EVP_MD *)0x0) {
              iVar30 = 0;
              BIO_printf(bio_err,"Signature did not match the certificate\n");
            }
            else {
              BIO_printf(bio_err,"Signature ok\n");
              pcVar5 = (char *)EVP_md5();
              pEVar23 = (EVP_MD *)X509_to_X509_REQ(local_3d0,(EVP_PKEY *)0x0,(EVP_MD *)pcVar5);
              pEVar16 = local_400;
              if (pEVar23 == (EVP_MD *)0x0) {
                iVar30 = -1;
              }
              else {
                local_400 = pEVar23;
                iVar30 = do_body(local_3e4,local_3a4,local_410,local_378,local_434,local_37c,
                                 local_3a0,local_3b4,local_3cc,local_3b8,local_3bc,local_430,
                                 local_3d8,local_374,pEVar23,local_3b0,local_42c,local_428,local_404
                                 ,local_408,pEVar16,0);
                X509_REQ_free((X509_REQ *)local_400);
              }
            }
          }
          X509_free(local_3d0);
          if (iVar30 < 0) goto LAB_080594c7;
          pEVar23 = local_3dc;
          pEVar16 = local_3ac;
          if (iVar30 != 0) {
            BIO_printf(bio_err,"\n");
            iVar30 = BN_add_word(local_358,1);
            if (iVar30 == 0) goto LAB_080594c7;
            iVar30 = sk_push((_STACK *)local_370,(void *)local_344);
            pEVar17 = local_3c4;
            if (iVar30 == 0) goto LAB_0805b032;
            local_3c4 = local_424;
            pEVar23 = local_3dc;
            pEVar16 = local_3ac;
          }
LAB_08059ee4:
          local_3ac = pEVar16;
          pEVar16 = local_3ac;
          if (local_3e0 != (void *)0x0) {
            iVar30 = certify(local_414,local_3e4,local_3a4,local_410,local_378,local_358,local_37c,
                             local_3a0,local_3b4,local_3cc,local_3b8,local_3bc,local_354,local_3d8,
                             local_3b0,conf,local_374,local_34c,local_350,local_408,local_348,
                             local_3f0);
            if (iVar30 < 0) goto LAB_080594c7;
            pEVar16 = pEVar23;
            if (iVar30 != 0) {
              BIO_printf(bio_err,"\n");
              iVar30 = BN_add_word(local_358,1);
              if (iVar30 == 0) goto LAB_080594c7;
              iVar30 = sk_push((_STACK *)local_370,(void *)local_344);
              pEVar17 = local_3c4;
              if (iVar30 == 0) goto LAB_0805b032;
            }
          }
          pEVar23 = pEVar16;
          if (0 < (int)pEVar32) {
            pEVar23 = (EVP_MD *)
                      ((int)pEVar16->required_pkey_type + (int)(pEVar32->required_pkey_type + -0x16)
                      );
            local_3ac = (EVP_MD *)((int)local_3a8 + (int)pEVar16 * -4);
            local_3a8 = (BIGNUM *)local_344;
            do {
              pEVar16 = (EVP_MD *)((int)&pEVar16->type + 1);
              iVar30 = certify(local_414,local_3e4,local_3a4,local_410,local_378,local_358,local_37c
                               ,local_3a0,local_3b4,local_3cc,local_3b8,local_3bc,local_354,
                               local_3d8,local_3b0,conf,local_374,local_34c,local_350,local_408,
                               local_348,local_3f0);
              if (iVar30 < 0) goto LAB_080594c7;
              if (iVar30 != 0) {
                pEVar17 = (EVP_MD *)((int)&pEVar17->type + 1);
                BIO_printf(bio_err,"\n");
                iVar30 = BN_add_word(local_358,1);
                if (iVar30 == 0) goto LAB_080594c7;
                iVar30 = sk_push((_STACK *)local_370,(void *)local_344);
                if (iVar30 == 0) goto LAB_0805b032;
              }
            } while (pEVar23 != pEVar16);
          }
          iVar30 = sk_num((_STACK *)local_370);
          if (0 < iVar30) {
            if (local_3d8 != 0) {
LAB_0805a1a2:
              iVar30 = sk_num((_STACK *)local_370);
              BIO_printf(bio_err,"Write out database with %d new entries\n",iVar30);
              iVar30 = save_serial(local_420,&DAT_081eac52,local_358,0);
              if ((iVar30 == 0) ||
                 (pcVar5 = (char *)local_378, iVar30 = save_index(local_3fc,&DAT_081eac52,local_378)
                 , iVar30 == 0)) goto LAB_080594c7;
              goto LAB_0805a20b;
            }
            BIO_printf(bio_err,"\n%d out of %d certificate requests certified, commit? [y/n]",
                       pEVar17,pEVar23);
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            local_320[0]._0_1_ = 0;
            pFVar43 = stdin;
            pcVar5 = fgets((char *)local_320,10,stdin);
            if (pcVar5 == (char *)0x0) {
              pcVar5 = "CERTIFICATION CANCELED: I/O error\n";
            }
            else {
              if (((byte)local_320[0] & 0xdf) == 0x59) goto LAB_0805a1a2;
              pcVar5 = "CERTIFICATION CANCELED\n";
            }
            x_00 = (X509_CRL *)0x0;
            BIO_printf(bio_err,pcVar5,pFVar43,pEVar23);
LAB_0805a528:
            pBVar36 = (BIGNUM *)0x0;
            iVar30 = 0;
            goto LAB_0805834a;
          }
LAB_0805a20b:
          if (local_374 != 0) {
            BIO_printf(bio_err,"writing new certificates\n");
          }
          pBVar6 = local_394;
          local_37c = (char *)0x0;
          while (iVar30 = sk_num((_STACK *)local_370), (int)local_37c < iVar30) {
            local_344 = (undefined  [4])sk_value((_STACK *)local_370,(int)local_37c);
            pAVar28 = (*(X509_CINF **)local_344)->serialNumber;
            iVar30 = pAVar28->length;
            pbVar9 = pAVar28->data;
            sVar11 = strlen(local_3c0);
            if (iVar30 == 0) {
              if (0xf7 < sVar11) goto LAB_0805adaf;
              __memcpy_chk(local_120,local_3c0,sVar11 + 1,0x100);
              BUF_strlcat((char *)local_120,"/",0x100);
              puVar25 = local_120;
              do {
                puVar24 = puVar25;
                uVar31 = *puVar24 + 0xfefefeff & ~*puVar24;
                uVar10 = uVar31 & 0x80808080;
                puVar25 = puVar24 + 1;
              } while (uVar10 == 0);
              bVar39 = (uVar31 & 0x8080) == 0;
              if (bVar39) {
                uVar10 = uVar10 >> 0x10;
              }
              if (bVar39) {
                puVar25 = (uint *)((int)puVar24 + 6);
              }
              iVar37 = (int)puVar25 +
                       ((-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)) - (int)local_120);
              pBVar36 = (BIGNUM *)((undefined *)((int)register0x00000010 + -0x123) + iVar37 + 3);
LAB_0805a627:
              *(undefined *)((int)local_120 + iVar37) = 0x30;
              pBVar26 = (BIGNUM *)((int)&pBVar36->d + 2);
              *(undefined *)((int)&pBVar36->d + 1) = 0x30;
            }
            else {
              if ((uint)((0x7d - iVar30) * 2) <= sVar11) {
LAB_0805adaf:
                pcVar35 = "certificate file name too long\n";
                goto LAB_0805a8e8;
              }
              __memcpy_chk(local_120,local_3c0,sVar11 + 1,0x100);
              BUF_strlcat((char *)local_120,"/",0x100);
              puVar25 = local_120;
              do {
                puVar24 = puVar25;
                uVar31 = *puVar24 + 0xfefefeff & ~*puVar24;
                uVar10 = uVar31 & 0x80808080;
                puVar25 = puVar24 + 1;
              } while (uVar10 == 0);
              bVar39 = (uVar31 & 0x8080) == 0;
              if (bVar39) {
                uVar10 = uVar10 >> 0x10;
              }
              if (bVar39) {
                puVar25 = (uint *)((int)puVar24 + 6);
              }
              iVar37 = (int)puVar25 +
                       ((-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)) - (int)local_120);
              pBVar26 = (BIGNUM *)((undefined *)((int)register0x00000010 + -0x123) + iVar37 + 3);
              pBVar36 = pBVar26;
              if (iVar30 < 1) goto LAB_0805a627;
              if (pBVar26 < (BIGNUM *)&local_20) {
                local_3a8 = (BIGNUM *)&local_20;
                pbVar21 = pbVar9;
                do {
                  local_3a0 = pBVar26;
                  BIO_snprintf((char *)pBVar26,(int)local_3a8 - (int)pBVar26,"%02X",(uint)*pbVar21);
                  pBVar26 = (BIGNUM *)((int)&local_3a0->d + 2);
                  if (pbVar21 + 1 == pbVar9 + iVar30) break;
                  pbVar21 = pbVar21 + 1;
                } while (pBVar26 < local_3a8);
              }
            }
            *(undefined *)&pBVar26->d = 0x2e;
            *(undefined *)((int)&pBVar26->d + 1) = 0x70;
            *(undefined *)((int)&pBVar26->d + 2) = 0x65;
            *(undefined *)((int)&pBVar26->d + 3) = 0x6d;
            *(undefined *)&pBVar26->top = 0;
            if (local_374 != 0) {
              BIO_printf(bio_err,"writing %s\n",local_120);
            }
            pcVar5 = (char *)0x5;
            lVar19 = BIO_ctrl(pBVar6,0x6c,5,local_120);
            pXVar29 = (X509 *)local_344;
            if (lVar19 < 1) {
              x_00 = (X509_CRL *)0x0;
              pBVar36 = (BIGNUM *)0x0;
              iVar30 = 1;
              perror((char *)local_120);
              goto LAB_0805834a;
            }
            if (local_418 == 0) {
              X509_print(pBVar6,(X509 *)local_344);
              PEM_write_bio_X509(pBVar6,pXVar29);
              pXVar29 = (X509 *)local_344;
              if (local_3d4 == (EVP_MD *)0x0) {
                X509_print(local_38c,(X509 *)local_344);
                goto LAB_0805a3fc;
              }
LAB_0805adbc:
              i2d_X509_bio(local_38c,(X509 *)local_344);
            }
            else {
              PEM_write_bio_X509(pBVar6,(X509 *)local_344);
              pXVar29 = (X509 *)local_344;
              if (local_3d4 != (EVP_MD *)0x0) goto LAB_0805adbc;
LAB_0805a3fc:
              PEM_write_bio_X509(local_38c,pXVar29);
            }
            local_37c = local_37c + 1;
          }
          iVar30 = sk_num((_STACK *)local_370);
          if (iVar30 != 0) {
            iVar30 = rotate_serial(local_420,&DAT_081eac52,"old");
            if ((iVar30 == 0) || (iVar30 = rotate_index(local_3fc,&DAT_081eac52,"old"), iVar30 == 0)
               ) goto LAB_080594c7;
            BIO_printf(bio_err,"Data Base Updated\n");
          }
LAB_0805a654:
          if (local_3f4 == 0) {
            x_00 = (X509_CRL *)0x0;
LAB_0805aaf8:
            if (local_40c == 0) goto LAB_0805a528;
            if (local_3e0 == (void *)0x0) {
              pBVar36 = (BIGNUM *)0x0;
              iVar30 = 1;
              BIO_printf(bio_err,"no input files\n");
              goto LAB_0805834a;
            }
            pXVar29 = (X509 *)load_cert(bio_err,local_3e0,3,0,local_41c,local_3e0);
            pEVar32 = local_378;
            if ((pXVar29 != (X509 *)0x0) && (iVar30 = do_revoke(local_3ec), 0 < iVar30)) {
              iVar30 = 1;
              X509_free(pXVar29);
              pBVar36 = (BIGNUM *)0x0;
              iVar37 = save_index(local_3fc,&DAT_081eac52,pEVar32);
              if ((iVar37 != 0) &&
                 (iVar37 = rotate_index(local_3fc,&DAT_081eac52,"old"), iVar37 != 0)) {
                iVar30 = 0;
                BIO_printf(bio_err,"Data Base Updated\n");
              }
              goto LAB_0805834a;
            }
            goto LAB_08059048;
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
            iVar30 = X509V3_EXT_add_nconf
                               ((CONF *)conf,(X509V3_CTX *)local_33c,(char *)local_3c8,(X509 *)0x0);
            if (iVar30 == 0) {
              pcVar35 = "Error Loading CRL extension section %s\n";
              pcVar5 = (char *)local_3c8;
              goto LAB_0805a8e8;
            }
          }
          local_37c = NCONF_get_string((CONF *)conf,(char *)section,"crlnumber");
          if (local_37c == (char *)0x0) {
            pBVar36 = (BIGNUM *)0x0;
LAB_0805a6fb:
            if ((local_360 | local_364 | local_3f8) == 0) {
              iVar30 = NCONF_get_number_e((CONF *)conf,(char *)section,"default_crl_days",
                                          (long *)&local_364);
              if (iVar30 == 0) {
                local_364 = 0;
              }
              iVar30 = NCONF_get_number_e((CONF *)conf,(char *)section,"default_crl_hours",
                                          (long *)&local_360);
              if (iVar30 == 0) {
                local_360 = 0;
              }
              ERR_clear_error();
            }
            if ((local_364 == 0) && ((local_3f8 | local_360) == 0)) {
              pcVar5 = "cannot lookup how long until the next CRL is issued\n";
              goto LAB_0805a90c;
            }
            if (local_374 != 0) {
              BIO_printf(bio_err,"making CRL\n");
            }
            x_00 = X509_CRL_new();
            iVar30 = 1;
            if (x_00 == (X509_CRL *)0x0) goto LAB_0805834a;
            name = X509_get_subject_name(local_380);
            iVar37 = X509_CRL_set_issuer_name(x_00,name);
            if ((iVar37 == 0) || (pBVar26 = (BIGNUM *)ASN1_TIME_new(), pBVar26 == (BIGNUM *)0x0))
            goto LAB_0805834a;
            local_3a0 = pBVar26;
            X509_gmtime_adj((ASN1_TIME *)pBVar26,0);
            X509_CRL_set_lastUpdate(x_00,(ASN1_TIME *)local_3a0);
            pAVar27 = X509_time_adj_ex((ASN1_TIME *)local_3a0,local_364,
                                       local_360 * 0xe10 + local_3f8,(time_t *)0x0);
            pBVar26 = local_3a0;
            if (pAVar27 == (ASN1_TIME *)0x0) {
              BIO_puts(bio_err,"error setting CRL nextUpdate\n");
              goto LAB_0805834a;
            }
            X509_CRL_set_nextUpdate(x_00,(ASN1_TIME *)local_3a0);
            ASN1_TIME_free((ASN1_TIME *)pBVar26);
            local_3a8 = (BIGNUM *)0x0;
            local_3ac = (EVP_MD *)0x0;
            local_3a0 = pBVar36;
            while (iVar30 = sk_num(*(_STACK **)((int)local_378->pkey_type + 4)), pBVar36 = local_3a0
                  , (int)local_3ac < iVar30) {
              ppcVar15 = (char **)sk_value(*(_STACK **)((int)local_378->pkey_type + 4),
                                           (int)local_3ac);
              if (**ppcVar15 == 'R') {
                x = X509_REVOKED_new();
                pBVar36 = local_3a0;
                if ((x == (X509_REVOKED *)0x0) ||
                   (iVar30 = make_revoked(x,ppcVar15[2]), pBVar36 = local_3a0, iVar30 == 0))
                goto LAB_0805904a;
                pBVar36 = (BIGNUM *)0x1;
                if (iVar30 != 2) {
                  pBVar36 = local_3a8;
                }
                local_3a8 = pBVar36;
                iVar30 = BN_hex2bn(&local_358,ppcVar15[3]);
                pBVar36 = local_3a0;
                if (iVar30 == 0) goto LAB_0805904a;
                pAVar28 = BN_to_ASN1_INTEGER(local_358,(ASN1_INTEGER *)0x0);
                BN_free(local_358);
                local_358 = (BIGNUM *)0x0;
                pBVar36 = local_3a0;
                if (pAVar28 == (ASN1_INTEGER *)0x0) goto LAB_0805904a;
                X509_REVOKED_set_serialNumber(x,pAVar28);
                ASN1_INTEGER_free(pAVar28);
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
            uVar10 = (uint)local_3a0 & 0xffffff00;
            local_3a0 = (BIGNUM *)(uVar10 | (local_37c != (char *)0x0 || bVar39));
            if (local_37c == (char *)0x0 && !bVar39) {
              local_3a0 = (BIGNUM *)(uVar10 | local_3a8 != (BIGNUM *)0x0);
LAB_0805aa41:
              if ((char)local_3a0 != '\0') {
                iVar30 = 1;
                iVar37 = X509_CRL_set_version(x_00,1);
                if (iVar37 == 0) goto LAB_0805834a;
              }
              if (local_37c != (char *)0x0) {
                iVar30 = 1;
                iVar37 = save_serial(local_37c,&DAT_081eac52,pBVar36,0);
                if (iVar37 == 0) goto LAB_0805834a;
              }
              if (pBVar36 != (BIGNUM *)0x0) {
                BN_free(pBVar36);
              }
              pBVar36 = (BIGNUM *)0x0;
              iVar30 = 1;
              iVar37 = do_X509_CRL_sign(bio_err,x_00,local_384,local_3e4,local_3a4);
              if ((iVar37 == 0) ||
                 ((PEM_write_bio_X509_CRL(local_38c,x_00), local_37c != (char *)0x0 &&
                  (iVar37 = rotate_serial(local_37c,&DAT_081eac52,"old"), iVar37 == 0))))
              goto LAB_0805834a;
              goto LAB_0805aaf8;
            }
            X509V3_set_ctx((X509V3_CTX *)local_33c,local_380,(X509 *)0x0,(X509_REQ *)0x0,x_00,0);
            X509V3_set_nconf((X509V3_CTX *)local_33c,(CONF *)conf);
            if ((local_3c8 == (EVP_MD *)0x0) ||
               (iVar30 = X509V3_EXT_CRL_add_nconf
                                   ((CONF *)conf,(X509V3_CTX *)local_33c,(char *)local_3c8,x_00),
               iVar30 != 0)) {
              if (local_37c == (char *)0x0) {
                local_3a0 = (BIGNUM *)
                            ((uint)local_3a0 & 0xffffff00 |
                            (uint)(local_3a8 != (BIGNUM *)0x0 | (byte)local_374));
                goto LAB_0805aa41;
              }
              pAVar28 = BN_to_ASN1_INTEGER(pBVar36,(ASN1_INTEGER *)0x0);
              if (pAVar28 != (ASN1_INTEGER *)0x0) {
                X509_CRL_add1_ext_i2d(x_00,0x58,pAVar28,0,0);
                ASN1_INTEGER_free(pAVar28);
                iVar30 = BN_add_word(pBVar36,1);
                if (iVar30 != 0) goto LAB_0805aa41;
              }
            }
          }
          else {
            pBVar36 = (BIGNUM *)load_serial(local_37c,0,0);
            if (pBVar36 != (BIGNUM *)0x0) goto LAB_0805a6fb;
            pcVar5 = "error while loading CRL number\n";
LAB_0805a90c:
            x_00 = (X509_CRL *)0x0;
            BIO_printf(bio_err,pcVar5);
          }
        }
LAB_0805904a:
        iVar30 = 1;
        goto LAB_0805834a;
      }
      pcVar5 = NCONF_get_string((CONF *)conf,(char *)section,"database");
      if (pcVar5 == (char *)0x0) {
        pcVar5 = "database";
LAB_0805b7c5:
        BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,pcVar5);
        local_378 = (EVP_MD *)0x0;
      }
      else {
        local_378 = (EVP_MD *)load_index(pcVar5,local_344 + 4);
        if ((local_378 != (EVP_MD *)0x0) && (iVar30 = index_index(local_378), iVar30 != 0)) {
          value = local_320;
          uVar10 = 0;
          do {
            *(undefined4 *)((int)value + uVar10) = 0;
            uVar10 = uVar10 + 4;
          } while (uVar10 < 0x18);
          sVar11 = strlen((char *)local_380);
          p_Var12 = (_func_1084 *)CRYPTO_malloc(sVar11 + 2,"ca.c",0x9eb);
          pXVar29 = local_380;
          local_314 = p_Var12;
          if (p_Var12 == (_func_1084 *)0x0) {
            iVar30 = -1;
            BIO_printf(bio_err,"Malloc failure\n");
          }
          else {
            sVar11 = strlen((char *)local_380);
            if ((sVar11 & 1) == 0) {
              memcpy(p_Var12,pXVar29,sVar11);
              sVar11 = strlen((char *)pXVar29);
              local_314[sVar11] = (_func_1084)0x0;
            }
            else {
              *p_Var12 = (_func_1084)0x30;
              sVar11 = strlen((char *)pXVar29);
              memcpy(local_314 + 1,pXVar29,sVar11);
              sVar11 = strlen((char *)pXVar29);
              local_314[sVar11 + 1] = (_func_1084)0x0;
            }
            p_Var12 = local_314;
            if (*local_314 != (_func_1084)0x0) {
              local_370 = (BIGNUM *)((uint)local_370 & 0xffffff00 | (uint)(byte)*local_314);
              iVar30 = 0;
              pp_Var13 = __ctype_toupper_loc();
              do {
                iVar30 = iVar30 + 1;
                *p_Var12 = (_func_1084)(byte)(*pp_Var13)[(byte)local_370];
                p_Var12 = local_314 + iVar30;
                local_370._0_1_ = (byte)*p_Var12;
              } while ((byte)local_370 != 0);
            }
            ppcVar14 = TXT_DB_get_by_index((TXT_DB *)local_378->pkey_type,3,value);
            if (ppcVar14 == (OPENSSL_STRING *)0x0) {
              iVar30 = -1;
              BIO_printf(bio_err,"Serial %s not present in db.\n",local_314);
            }
            else {
              cVar1 = **ppcVar14;
              if (cVar1 == 'V') {
                iVar30 = 1;
                BIO_printf(bio_err,"%s=Valid (%c)\n",local_314,0x56);
              }
              else if (cVar1 == 'R') {
                iVar30 = 1;
                BIO_printf(bio_err,"%s=Revoked (%c)\n",local_314,0x52);
              }
              else if (cVar1 == 'E') {
                iVar30 = 1;
                BIO_printf(bio_err,"%s=Expired (%c)\n",local_314,0x45);
              }
              else if (cVar1 == 'S') {
                iVar30 = 1;
                BIO_printf(bio_err,"%s=Suspended (%c)\n",local_314,0x53);
              }
              else {
                iVar30 = -1;
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
          if (iVar30 != 1) {
            BIO_printf(bio_err,"Error verifying serial %s!\n",local_380);
          }
        }
      }
    }
  }
  else {
    pcVar5 = (char *)local_378;
    BIO_printf(bio_err,"Using configuration from %s\n",local_378);
    conf = (BIGNUM *)NCONF_new((CONF_METHOD *)0x0);
    local_370 = (BIGNUM *)&local_35c;
    pcVar35 = (char *)0x0;
    iVar30 = NCONF_load((CONF *)conf,pcVar5,(long *)local_370);
    pcVar5 = (char *)local_378;
    if (0 < iVar30) goto LAB_08058719;
LAB_080582a5:
    local_378 = (EVP_MD *)pcVar5;
    if ((int)local_35c < 1) {
      BIO_printf(bio_err,"error loading the config file \'%s\'\n",local_378);
    }
    else {
      BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_35c,local_378);
    }
    if (pcVar35 != (char *)0x0) {
      CRYPTO_free(pcVar35);
    }
LAB_080582dd:
    local_398 = (char *)0x0;
LAB_080582e7:
    local_378 = (EVP_MD *)0x0;
    local_394 = (BIO *)0x0;
    local_38c = (BIO *)0x0;
    local_390 = (BIO *)0x0;
    local_39c = (BIO *)0x0;
  }
  local_370 = (BIGNUM *)0x0;
  x_00 = (X509_CRL *)0x0;
  local_380 = (X509 *)0x0;
  pBVar36 = (BIGNUM *)0x0;
  local_384 = (EVP_PKEY *)0x0;
  iVar30 = 1;
  local_388 = (void *)0x0;
LAB_0805834a:
  BIO_free_all(local_394);
  BIO_free_all(local_38c);
  BIO_free_all(local_390);
  BIO_free_all(local_39c);
  if (local_370 != (BIGNUM *)0x0) {
    sk_pop_free((_STACK *)local_370,X509_free);
  }
  if (iVar30 != 0) {
    ERR_print_errors(bio_err);
  }
  app_RAND_write_file(local_398,bio_err);
  if ((local_388 != (void *)0x0) && (local_368 != (byte *)0x0)) {
    CRYPTO_free(local_368);
  }
  BN_free(local_358);
  BN_free(pBVar36);
  free_index(local_378);
  if (local_3a4 != (_STACK *)0x0) {
    sk_free(local_3a4);
  }
  EVP_PKEY_free(local_384);
  if (local_380 != (X509 *)0x0) {
    X509_free(local_380);
  }
  X509_CRL_free(x_00);
  NCONF_free((CONF *)conf);
  NCONF_free(extconf);
  OBJ_cleanup();
  if (local_20 != *(ulong **)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar30;
}
