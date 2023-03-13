
/* WARNING: Removing unreachable block (ram,0x08075029) */
/* WARNING: Removing unreachable block (ram,0x08074aa4) */
/* WARNING: Removing unreachable block (ram,0x08074665) */
/* WARNING: Removing unreachable block (ram,0x0807431c) */
/* WARNING: Removing unreachable block (ram,0x080759c0) */
/* WARNING: Removing unreachable block (ram,0x0807401d) */
/* WARNING: Removing unreachable block (ram,0x08073d5b) */
/* WARNING: Removing unreachable block (ram,0x08073aa7) */
/* WARNING: Removing unreachable block (ram,0x080737db) */
/* WARNING: Removing unreachable block (ram,0x080731f6) */
/* WARNING: Removing unreachable block (ram,0x0807308f) */
/* WARNING: Removing unreachable block (ram,0x08072dcd) */
/* WARNING: Removing unreachable block (ram,0x08072b02) */
/* WARNING: Removing unreachable block (ram,0x08072833) */
/* WARNING: Removing unreachable block (ram,0x08072561) */
/* WARNING: Removing unreachable block (ram,0x0807654f) */
/* WARNING: Removing unreachable block (ram,0x080720e8) */
/* WARNING: Removing unreachable block (ram,0x08071ebb) */
/* WARNING: Removing unreachable block (ram,0x08072260) */
/* WARNING: Removing unreachable block (ram,0x080723ee) */
/* WARNING: Removing unreachable block (ram,0x080726c9) */
/* WARNING: Removing unreachable block (ram,0x08072999) */
/* WARNING: Removing unreachable block (ram,0x08072c6d) */
/* WARNING: Removing unreachable block (ram,0x08072f2c) */
/* WARNING: Removing unreachable block (ram,0x080763c8) */
/* WARNING: Removing unreachable block (ram,0x0807393f) */
/* WARNING: Removing unreachable block (ram,0x08073c0d) */
/* WARNING: Removing unreachable block (ram,0x08073ebd) */
/* WARNING: Removing unreachable block (ram,0x0807416d) */
/* WARNING: Removing unreachable block (ram,0x0807441f) */
/* WARNING: Removing unreachable block (ram,0x08077a01) */
/* WARNING: Removing unreachable block (ram,0x080779f2) */
/* WARNING: Removing unreachable block (ram,0x08077acd) */
/* WARNING: Removing unreachable block (ram,0x08077b53) */
/* WARNING: Removing unreachable block (ram,0x08077ae9) */
/* WARNING: Removing unreachable block (ram,0x08077b02) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 speed_main(int param_1,byte **param_2)

{
  byte bVar1;
  byte bVar2;
  DSA *dsa;
  uchar *data;
  uchar *out;
  uint uVar3;
  EVP_CIPHER *cipher;
  BIO_METHOD *type;
  int *piVar4;
  RSA *pRVar5;
  char *pcVar6;
  char *pcVar7;
  EVP_MD *type_00;
  EVP_MD *pEVar8;
  EC_KEY *pEVar9;
  int iVar10;
  int iVar11;
  EC_KEY *key;
  int iVar12;
  void *__ptr;
  EC_GROUP *group;
  EC_POINT *pEVar13;
  FILE *pFVar14;
  long lVar15;
  uint uVar16;
  RSA_METHOD *meth;
  int iVar17;
  int iVar18;
  undefined2 *puVar19;
  byte *pbVar20;
  undefined4 uVar21;
  byte **ppbVar22;
  size_t sVar23;
  byte *pbVar24;
  EC_KEY **ppEVar25;
  undefined1 *puVar26;
  double *pdVar27;
  RSA **ppRVar28;
  DSA **ppDVar29;
  undefined4 *puVar30;
  byte *pbVar31;
  int in_GS_OFFSET;
  bool bVar32;
  undefined uVar33;
  bool bVar34;
  bool bVar35;
  bool bVar36;
  undefined uVar37;
  byte bVar38;
  float10 fVar39;
  double dVar40;
  code *pcVar41;
  undefined8 in_stack_ffffd70c;
  ulonglong uVar42;
  undefined8 uVar43;
  double dVar44;
  int local_28e8;
  long local_28b8;
  code *local_28b4;
  undefined1 *local_28ac;
  double local_28a4;
  uint local_2890;
  uchar *local_288c;
  DSA *local_2888 [3];
  int local_287c;
  int local_2878;
  int local_2874;
  RSA *local_2870 [4];
  RSA *local_2860;
  int local_285c;
  int local_2858;
  int local_2854;
  undefined4 auStack_2850 [8];
  EC_KEY *local_2830 [16];
  EC_KEY *local_27f0 [16];
  EC_KEY *local_27b0 [16];
  int local_2770 [16];
  int local_2730 [16];
  int local_26f0 [30];
  uint local_2678 [32];
  DES_key_schedule local_25f8;
  DES_key_schedule local_2578;
  DES_key_schedule local_24f8;
  CAST_KEY local_2478;
  HMAC_CTX local_23f4;
  IDEA_KEY_SCHEDULE local_2324;
  AES_KEY local_224c;
  AES_KEY local_2158;
  AES_KEY local_2064;
  RC2_KEY local_1f70;
  undefined local_1e6e [534];
  CAMELLIA_KEY local_1c58;
  CAMELLIA_KEY local_1b44;
  undefined4 local_1a30 [150];
  BF_KEY local_17d8;
  undefined4 local_790;
  undefined4 local_78c;
  uchar local_788 [16];
  uchar local_778 [16];
  uchar local_768 [16];
  uchar local_758 [16];
  uchar local_748 [20];
  uchar local_734 [20];
  uchar local_720 [32];
  undefined4 local_700 [8];
  uchar local_6e0 [64];
  uchar local_6a0 [64];
  uchar local_660 [64];
  uchar local_620 [256];
  undefined4 local_520;
  byte local_420 [4];
  byte local_41c [1020];
  int local_20;
  
  pFVar14 = (FILE *)((ulonglong)in_stack_ffffd70c >> 0x20);
  bVar38 = 0;
  usertime = (code *)0xffffffff;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  signal(0xd,(__sighandler_t)0x1);
  local_2888[0] = (DSA *)0x0;
  puVar30 = (undefined4 *)results;
  for (iVar17 = 300; iVar17 != 0; iVar17 = iVar17 + -1) {
    *puVar30 = 0;
    puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
  }
  local_2888[1] = (DSA *)0x0;
  local_2888[2] = (DSA *)0x0;
  ppEVar25 = local_2830;
  for (iVar17 = 0x10; iVar17 != 0; iVar17 = iVar17 + -1) {
    *ppEVar25 = (EC_KEY *)0x0;
    ppEVar25 = ppEVar25 + (uint)bVar38 * -2 + 1;
  }
  ppEVar25 = local_27f0;
  for (iVar17 = 0x10; iVar17 != 0; iVar17 = iVar17 + -1) {
    *ppEVar25 = (EC_KEY *)0x0;
    ppEVar25 = ppEVar25 + (uint)bVar38 * -2 + 1;
  }
  ppEVar25 = local_27b0;
  for (iVar17 = 0x10; iVar17 != 0; iVar17 = iVar17 + -1) {
    *ppEVar25 = (EC_KEY *)0x0;
    ppEVar25 = ppEVar25 + (uint)bVar38 * -2 + 1;
  }
  if (bio_err == (BIO *)0x0) {
    pFVar14 = (FILE *)0x807186e;
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      pFVar14 = stderr;
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar17 = load_config(bio_err,0);
  if (iVar17 == 0) {
LAB_08071558:
    ERR_print_errors(bio_err);
LAB_08071566:
    uVar21 = 1;
    goto LAB_0807157c;
  }
  local_2870[0] = (RSA *)0x0;
  local_2870[1] = (RSA *)0x0;
  local_2870[2] = (RSA *)0x0;
  local_2870[3] = (RSA *)0x0;
  data = (uchar *)CRYPTO_malloc(0x2001,"speed.c",0x2ab);
  if (data == (uchar *)0x0) {
    BIO_printf(bio_err,"out of memory\n");
    goto LAB_08071558;
  }
  uVar42 = CONCAT44(pFVar14,0x2af);
  out = (uchar *)CRYPTO_malloc(0x2001,"speed.c",0x2af);
  if (out == (uchar *)0x0) {
    BIO_printf(bio_err,"out of memory\n");
    ERR_print_errors(bio_err);
    CRYPTO_free(data);
    goto LAB_08071566;
  }
  uVar3 = 0;
  local_790 = 0;
  local_78c = 0;
  puVar30 = local_1a30;
  for (iVar17 = 0x96; iVar17 != 0; iVar17 = iVar17 + -1) {
    *puVar30 = 0;
    puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
  }
  do {
    *(undefined4 *)((int)local_700 + uVar3) = 0;
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x20);
  local_2860 = (RSA *)0x0;
  local_285c = 0;
  piVar4 = local_2730 + 0x10;
  for (iVar17 = 0x1e; iVar17 != 0; iVar17 = iVar17 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + (uint)bVar38 * -2 + 1;
  }
  local_2858 = 0;
  local_2854 = 0;
  local_287c = 0;
  local_2878 = 0;
  local_2874 = 0;
  piVar4 = local_2770;
  for (iVar17 = 0x10; iVar17 != 0; iVar17 = iVar17 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + (uint)bVar38 * -2 + 1;
  }
  piVar4 = local_2730;
  for (iVar17 = 0x10; iVar17 != 0; iVar17 = iVar17 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + (uint)bVar38 * -2 + 1;
  }
  param_1 = param_1 + -1;
  if (param_1 == 0) {
    bVar34 = false;
    type_00 = (EVP_MD *)0x0;
    cipher = (EVP_CIPHER *)0x0;
    pcVar41 = usertime;
LAB_08071a23:
    for (iVar17 = 1; (iVar17 == 0x17 || (local_2730[iVar17 + 0xf] = 1, iVar17 != 0x1e));
        iVar17 = iVar17 + 1) {
    }
    local_2860 = (RSA *)0x1;
    local_285c = 1;
    local_2858 = 1;
    local_2854 = 1;
    local_287c = 1;
    local_2878 = 1;
    local_2874 = 1;
    local_2770[0] = 1;
    local_2770[1] = 1;
    local_2770[2] = 1;
    local_2770[3] = 1;
    local_2770[4] = 1;
    local_2770[5] = 1;
    local_2770[6] = 1;
    local_2770[7] = 1;
    local_2770[8] = 1;
    local_2770[9] = 1;
    local_2770[10] = 1;
    local_2770[11] = 1;
    local_2770[12] = 1;
    local_2770[13] = 1;
    local_2770[14] = 1;
    local_2770[15] = 1;
    local_2730[0] = 1;
    local_2730[1] = 1;
    local_2730[2] = 1;
    local_2730[3] = 1;
    local_2730[4] = 1;
    local_2730[5] = 1;
    local_2730[6] = 1;
    local_2730[7] = 1;
    local_2730[8] = 1;
    local_2730[9] = 1;
    local_2730[10] = 1;
    local_2730[11] = 1;
    local_2730[12] = 1;
    local_2730[13] = 1;
    local_2730[14] = 1;
    local_2730[15] = 1;
LAB_08071bdc:
    piVar4 = local_2730 + 0x10;
    local_28e8 = 0;
    do {
      iVar17 = *piVar4;
      piVar4 = piVar4 + 1;
      local_28e8 = (local_28e8 + 1) - (uint)(iVar17 == 0);
    } while ((uint *)piVar4 != (uint *)((int)((SEED_KEY_SCHEDULE *)local_26f0)->data + 0x78U));
    if ((pcVar41 == (code *)0x0) && (mr == 0)) {
      BIO_printf(bio_err,"You have chosen to measure elapsed time instead of user CPU time.\n");
    }
    iVar17 = 0;
    do {
      local_288c = *(uchar **)(rsa_data_17977 + iVar17 * 4);
      pRVar5 = d2i_RSAPrivateKey((RSA **)0x0,&local_288c,
                                 *(long *)(rsa_data_length_17978 + iVar17 * 4));
      local_2870[iVar17] = pRVar5;
      if (pRVar5 == (RSA *)0x0) {
        uVar21 = 1;
        BIO_printf(bio_err,"internal error loading RSA key number %d\n",iVar17);
        goto LAB_0807200c;
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 != 4);
    local_2888[0] = (DSA *)get_dsa512();
    local_2888[1] = (DSA *)get_dsa1024();
    local_2888[2] = (DSA *)get_dsa2048();
    DES_set_key_unchecked((const_DES_cblock *)&key_17960,&local_25f8);
    DES_set_key_unchecked((const_DES_cblock *)&key2_17961,&local_2578);
    DES_set_key_unchecked((const_DES_cblock *)&key3_17962,&local_24f8);
    AES_set_encrypt_key(key16_17953,0x80,&local_224c);
    AES_set_encrypt_key(key24_17954,0xc0,&local_2158);
    AES_set_encrypt_key(key32_17955,0x100,&local_2064);
    Camellia_set_key(key16_17953,0x80,(CAMELLIA_KEY *)(local_1e6e + 0x102));
    Camellia_set_key(ckey24_17956,0xc0,&local_1c58);
    Camellia_set_key(ckey32_17957,0x100,&local_1b44);
    idea_set_encrypt_key(key16_17953,&local_2324);
    SEED_set_key(key16_17953,
                 (SEED_KEY_SCHEDULE *)((int)((SEED_KEY_SCHEDULE *)local_26f0)->data + 0x78));
    RC4_set_key((RC4_KEY *)local_1e6e,0x10,key16_17953);
    RC2_set_key(&local_1f70,0x10,key16_17953,0x80);
    BF_set_key(&local_17d8,0x10,key16_17953);
    uVar42 = 0x81f7698;
    CAST_set_key(&local_2478,0x10,key16_17953);
    uVar3 = 0;
    do {
      *(undefined4 *)((int)auStack_2850 + uVar3) = 0;
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x20);
    pcVar41 = sig_done;
    signal(0xe,sig_done);
    if (local_26f0[1] != 0) {
      puVar26 = lengths;
      sVar23 = 0x10;
      pdVar27 = (double *)(results + 0x28);
      do {
        pcVar6 = "Doing %s for %ds on %d size blocks: ";
        if (mr != 0) {
          pcVar6 = "+DT:%s:%d:%d\n";
        }
        iVar17 = 0;
        BIO_printf(bio_err,pcVar6,names._4_4_,3,sVar23,pcVar41);
        uVar42 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        run = 1;
        do {
          uVar42 = CONCAT44(0x8071ecd,(int)uVar42);
          pEVar8 = (EVP_MD *)EVP_mdc2();
          iVar17 = iVar17 + 1;
          EVP_Digest(data,sVar23,local_788,(uint *)0x0,pEVar8,(ENGINE *)0x0);
          if (run == 0) break;
        } while (iVar17 != 0x7fffffff);
        fVar39 = (float10)app_tminterval(1,usertime);
        pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
        pcVar7 = "%d %s\'s in %.2fs\n";
        if (mr != 0) {
          pcVar7 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar7,iVar17,names._4_4_,SUB84((double)fVar39,0),pcVar6);
        puVar26 = (undefined1 *)((int)puVar26 + 4);
        fVar39 = (float10)(double)fVar39;
        *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
        if (puVar26 == &DAT_081f76dc) goto LAB_08072044;
        sVar23 = *(size_t *)puVar26;
        pcVar41 = (code *)pcVar6;
        pdVar27 = pdVar27 + 1;
      } while( true );
    }
    fVar39 = (float10)0;
    iVar17 = 0;
    pcVar6 = (char *)pcVar41;
LAB_08072044:
    if (local_26f0[2] != 0) {
      puVar26 = lengths;
      sVar23 = 0x10;
      pdVar27 = (double *)(results + 0x50);
      do {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
        if (mr != 0) {
          pcVar7 = "+DT:%s:%d:%d\n";
        }
        iVar17 = 0;
        BIO_printf(bio_err,pcVar7,names._8_4_,3,sVar23,pcVar6);
        uVar42 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        run = 1;
        do {
          uVar42 = CONCAT44(0x80720fd,(int)uVar42);
          pEVar8 = EVP_md4();
          iVar17 = iVar17 + 1;
          EVP_Digest(data,sVar23,local_778,(uint *)0x0,pEVar8,(ENGINE *)0x0);
          if (run == 0) break;
        } while (iVar17 != 0x7fffffff);
        fVar39 = (float10)app_tminterval(1,usertime);
        pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
        pcVar7 = "%d %s\'s in %.2fs\n";
        if (mr != 0) {
          pcVar7 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar7,iVar17,names._8_4_,SUB84((double)fVar39,0),pcVar6);
        puVar26 = (undefined1 *)((int)puVar26 + 4);
        fVar39 = (float10)(double)fVar39;
        *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
        if (puVar26 == &DAT_081f76dc) break;
        sVar23 = *(size_t *)puVar26;
        pdVar27 = pdVar27 + 1;
      } while( true );
    }
    if (local_26f0[3] != 0) {
      puVar26 = lengths;
      sVar23 = 0x10;
      pdVar27 = (double *)(results + 0x78);
      do {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
        if (mr != 0) {
          pcVar7 = "+DT:%s:%d:%d\n";
        }
        iVar17 = 0;
        BIO_printf(bio_err,pcVar7,names._12_4_,3,sVar23,pcVar6);
        uVar42 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        run = 1;
        do {
          iVar17 = iVar17 + 1;
          pEVar8 = EVP_get_digestbyname("md5");
          EVP_Digest(data,sVar23,local_768,(uint *)0x0,pEVar8,(ENGINE *)0x0);
          if (run == 0) break;
        } while (iVar17 != 0x7fffffff);
        fVar39 = (float10)app_tminterval(1,usertime);
        pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
        pcVar7 = "%d %s\'s in %.2fs\n";
        if (mr != 0) {
          pcVar7 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar7,iVar17,names._12_4_,SUB84((double)fVar39,0),pcVar6);
        puVar26 = (undefined1 *)((int)puVar26 + 4);
        fVar39 = (float10)(double)fVar39;
        *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
        if (puVar26 == &DAT_081f76dc) break;
        sVar23 = *(size_t *)puVar26;
        pdVar27 = pdVar27 + 1;
      } while( true );
    }
    if (local_26f0[4] != 0) {
      sVar23 = 0x10;
      HMAC_CTX_init(&local_23f4);
      pEVar8 = EVP_md5();
      HMAC_Init_ex(&local_23f4,"This is a key...",0x10,pEVar8,(ENGINE *)0x0);
      local_28ac = lengths;
      pdVar27 = (double *)(results + 0xa0);
      do {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
        if (mr != 0) {
          pcVar7 = "+DT:%s:%d:%d\n";
        }
        iVar17 = 0;
        BIO_printf(bio_err,pcVar7,names._16_4_,3,sVar23,pcVar6);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        run = 1;
        do {
          iVar17 = iVar17 + 1;
          HMAC_Init_ex(&local_23f4,(void *)0x0,0,(EVP_MD *)0x0,(ENGINE *)0x0);
          HMAC_Update(&local_23f4,data,sVar23);
          uVar42 = 0;
          HMAC_Final(&local_23f4,local_758,(uint *)0x0);
          if (run == 0) break;
        } while (iVar17 != 0x7fffffff);
        fVar39 = (float10)app_tminterval(1,usertime);
        pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
        pcVar7 = "%d %s\'s in %.2fs\n";
        if (mr != 0) {
          pcVar7 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar7,iVar17,names._16_4_,SUB84((double)fVar39,0),pcVar6);
        local_28ac = (undefined1 *)((int)local_28ac + 4);
        *pdVar27 = (double)sVar23 * ((double)iVar17 / (double)fVar39);
        if (local_28ac == &DAT_081f76dc) goto LAB_08076657;
        sVar23 = *(size_t *)local_28ac;
        pdVar27 = pdVar27 + 1;
      } while( true );
    }
    goto LAB_08072346;
  }
  local_28b8 = 0;
  bVar34 = false;
  type_00 = (EVP_MD *)0x0;
  cipher = (EVP_CIPHER *)0x0;
  iVar17 = 0;
  do {
    ppbVar22 = param_2 + 1;
    pbVar24 = *ppbVar22;
    bVar32 = false;
    bVar36 = param_1 == 0;
    if (param_1 < 1) {
LAB_080719a0:
      iVar18 = 5;
      pbVar20 = pbVar24;
      pbVar31 = &DAT_081ea4a0;
      do {
        if (iVar18 == 0) break;
        iVar18 = iVar18 + -1;
        bVar36 = *pbVar20 == *pbVar31;
        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
      } while (bVar36);
      if (bVar36) {
        local_26f0[1] = 1;
      }
      else {
        bVar1 = *pbVar24;
        bVar32 = bVar1 < 0x6d;
        bVar36 = bVar1 == 0x6d;
        if (bVar36) {
          bVar32 = pbVar24[1] < 100;
          bVar36 = pbVar24[1] == 100;
          if (bVar36) {
            if ((pbVar24[2] == 0x34) && (pbVar24[3] == 0)) {
              local_26f0[2] = 1;
              goto LAB_080717d9;
            }
            bVar32 = pbVar24[2] < 0x35;
            bVar36 = pbVar24[2] == 0x35;
            if (bVar36) {
              bVar32 = false;
              bVar36 = pbVar24[3] == 0;
              if (bVar36) {
                local_26f0[3] = 1;
                goto LAB_080717d9;
              }
            }
          }
        }
        iVar18 = 5;
        pbVar20 = pbVar24;
        pbVar31 = &DAT_081ec59e;
        do {
          if (iVar18 == 0) break;
          iVar18 = iVar18 + -1;
          bVar32 = *pbVar20 < *pbVar31;
          bVar36 = *pbVar20 == *pbVar31;
          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
        } while (bVar36);
        if (bVar36) {
          local_26f0[4] = 1;
        }
        else {
          iVar18 = 5;
          pbVar20 = pbVar24;
          pbVar31 = &DAT_08200112;
          do {
            if (iVar18 == 0) break;
            iVar18 = iVar18 + -1;
            bVar32 = *pbVar20 < *pbVar31;
            bVar36 = *pbVar20 == *pbVar31;
            pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
            pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
          } while (bVar36);
          if ((!bVar32 && !bVar36) == bVar32) {
            local_26f0[5] = 1;
          }
          else {
            bVar32 = bVar1 < 0x73;
            bVar36 = bVar1 == 0x73;
            if (bVar36) {
              bVar32 = pbVar24[1] < 0x68;
              bVar36 = pbVar24[1] == 0x68;
              if (bVar36) {
                bVar32 = pbVar24[2] < 0x61;
                bVar36 = pbVar24[2] == 0x61;
                if (bVar36) {
                  bVar32 = false;
                  bVar36 = pbVar24[3] == 0;
                  if (bVar36) {
                    local_26f0[5] = 1;
                    local_26f0[23] = 1;
                    local_26f0[24] = 1;
                    goto LAB_080717d9;
                  }
                }
              }
            }
            iVar18 = 7;
            pbVar20 = pbVar24;
            pbVar31 = (byte *)"sha256";
            do {
              if (iVar18 == 0) break;
              iVar18 = iVar18 + -1;
              bVar32 = *pbVar20 < *pbVar31;
              bVar36 = *pbVar20 == *pbVar31;
              pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
              pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
            } while (bVar36);
            bVar35 = (!bVar32 && !bVar36) < bVar32;
            bVar32 = (!bVar32 && !bVar36) == bVar32;
            if (bVar32) {
              local_26f0[23] = 1;
            }
            else {
              iVar18 = 7;
              pbVar20 = pbVar24;
              pbVar31 = (byte *)"sha512";
              do {
                if (iVar18 == 0) break;
                iVar18 = iVar18 + -1;
                bVar35 = *pbVar20 < *pbVar31;
                bVar32 = *pbVar20 == *pbVar31;
                pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
              } while (bVar32);
              bVar36 = (!bVar35 && !bVar32) < bVar35;
              bVar32 = (!bVar35 && !bVar32) == bVar35;
              if (bVar32) {
                local_26f0[24] = 1;
              }
              else {
                iVar18 = 10;
                pbVar20 = pbVar24;
                pbVar31 = (byte *)"whirlpool";
                do {
                  if (iVar18 == 0) break;
                  iVar18 = iVar18 + -1;
                  bVar36 = *pbVar20 < *pbVar31;
                  bVar32 = *pbVar20 == *pbVar31;
                  pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                  pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                } while (bVar32);
                bVar35 = (!bVar36 && !bVar32) < bVar36;
                bVar32 = (!bVar36 && !bVar32) == bVar36;
                if (bVar32) {
                  local_26f0[25] = 1;
                }
                else {
                  iVar18 = 7;
                  pbVar20 = pbVar24;
                  pbVar31 = (byte *)"ripemd";
                  do {
                    if (iVar18 == 0) break;
                    iVar18 = iVar18 + -1;
                    bVar35 = *pbVar20 < *pbVar31;
                    bVar32 = *pbVar20 == *pbVar31;
                    pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                    pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                  } while (bVar32);
                  bVar36 = (!bVar35 && !bVar32) < bVar35;
                  bVar32 = (!bVar35 && !bVar32) == bVar35;
                  if (!bVar32) {
                    iVar18 = 7;
                    pbVar20 = pbVar24;
                    pbVar31 = (byte *)"rmd160";
                    do {
                      if (iVar18 == 0) break;
                      iVar18 = iVar18 + -1;
                      bVar36 = *pbVar20 < *pbVar31;
                      bVar32 = *pbVar20 == *pbVar31;
                      pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                      pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                    } while (bVar32);
                    bVar35 = (!bVar36 && !bVar32) < bVar36;
                    bVar32 = (!bVar36 && !bVar32) == bVar36;
                    if (!bVar32) {
                      iVar18 = 10;
                      pbVar20 = pbVar24;
                      pbVar31 = (byte *)"ripemd160";
                      do {
                        if (iVar18 == 0) break;
                        iVar18 = iVar18 + -1;
                        bVar35 = *pbVar20 < *pbVar31;
                        bVar32 = *pbVar20 == *pbVar31;
                        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                      } while (bVar32);
                      if ((!bVar35 && !bVar32) != bVar35) {
                        bVar32 = 0x72 < bVar1;
                        bVar36 = bVar1 == 0x72;
                        if (bVar36) {
                          bVar32 = pbVar24[1] < 99;
                          bVar36 = pbVar24[1] == 99;
                          if (bVar36) {
                            bVar32 = pbVar24[2] < 0x34;
                            bVar36 = pbVar24[2] == 0x34;
                            if (bVar36) {
                              bVar32 = false;
                              bVar36 = pbVar24[3] == 0;
                              if (bVar36) {
                                local_26f0[7] = 1;
                                goto LAB_080717d9;
                              }
                            }
                          }
                        }
                        iVar18 = 8;
                        pbVar20 = pbVar24;
                        pbVar31 = (byte *)"des-cbc";
                        do {
                          if (iVar18 == 0) break;
                          iVar18 = iVar18 + -1;
                          bVar32 = *pbVar20 < *pbVar31;
                          bVar36 = *pbVar20 == *pbVar31;
                          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                        } while (bVar36);
                        bVar35 = (!bVar32 && !bVar36) < bVar32;
                        bVar32 = (!bVar32 && !bVar36) == bVar32;
                        if (bVar32) {
                          local_26f0[8] = 1;
                        }
                        else {
                          iVar18 = 9;
                          pbVar20 = pbVar24;
                          pbVar31 = (byte *)"des-ede3";
                          do {
                            if (iVar18 == 0) break;
                            iVar18 = iVar18 + -1;
                            bVar35 = *pbVar20 < *pbVar31;
                            bVar32 = *pbVar20 == *pbVar31;
                            pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                            pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                          } while (bVar32);
                          bVar36 = (!bVar35 && !bVar32) < bVar35;
                          bVar32 = (!bVar35 && !bVar32) == bVar35;
                          if (bVar32) {
LAB_08077de7:
                            local_26f0[9] = 1;
                          }
                          else {
                            iVar18 = 0xc;
                            pbVar20 = pbVar24;
                            pbVar31 = (byte *)"aes-128-cbc";
                            do {
                              if (iVar18 == 0) break;
                              iVar18 = iVar18 + -1;
                              bVar36 = *pbVar20 < *pbVar31;
                              bVar32 = *pbVar20 == *pbVar31;
                              pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                              pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                            } while (bVar32);
                            bVar35 = (!bVar36 && !bVar32) < bVar36;
                            bVar32 = (!bVar36 && !bVar32) == bVar36;
                            if (bVar32) {
                              local_26f0[16] = 1;
                            }
                            else {
                              iVar18 = 0xc;
                              pbVar20 = pbVar24;
                              pbVar31 = (byte *)"aes-192-cbc";
                              do {
                                if (iVar18 == 0) break;
                                iVar18 = iVar18 + -1;
                                bVar35 = *pbVar20 < *pbVar31;
                                bVar32 = *pbVar20 == *pbVar31;
                                pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                              } while (bVar32);
                              bVar36 = (!bVar35 && !bVar32) < bVar35;
                              bVar32 = (!bVar35 && !bVar32) == bVar35;
                              if (bVar32) {
                                local_26f0[17] = 1;
                              }
                              else {
                                iVar18 = 0xc;
                                pbVar20 = pbVar24;
                                pbVar31 = (byte *)"aes-256-cbc";
                                do {
                                  if (iVar18 == 0) break;
                                  iVar18 = iVar18 + -1;
                                  bVar36 = *pbVar20 < *pbVar31;
                                  bVar32 = *pbVar20 == *pbVar31;
                                  pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                  pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                } while (bVar32);
                                bVar35 = (!bVar36 && !bVar32) < bVar36;
                                bVar32 = (!bVar36 && !bVar32) == bVar36;
                                if (bVar32) {
LAB_08077e7c:
                                  local_26f0[18] = 1;
                                }
                                else {
                                  iVar18 = 0xc;
                                  pbVar20 = pbVar24;
                                  pbVar31 = (byte *)"aes-128-ige";
                                  do {
                                    if (iVar18 == 0) break;
                                    iVar18 = iVar18 + -1;
                                    bVar35 = *pbVar20 < *pbVar31;
                                    bVar32 = *pbVar20 == *pbVar31;
                                    pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                    pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                  } while (bVar32);
                                  bVar36 = (!bVar35 && !bVar32) < bVar35;
                                  bVar32 = (!bVar35 && !bVar32) == bVar35;
                                  if (bVar32) {
                                    local_26f0[26] = 1;
                                  }
                                  else {
                                    iVar18 = 0xc;
                                    pbVar20 = pbVar24;
                                    pbVar31 = (byte *)"aes-192-ige";
                                    do {
                                      if (iVar18 == 0) break;
                                      iVar18 = iVar18 + -1;
                                      bVar36 = *pbVar20 < *pbVar31;
                                      bVar32 = *pbVar20 == *pbVar31;
                                      pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                      pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                    } while (bVar32);
                                    bVar35 = (!bVar36 && !bVar32) < bVar36;
                                    bVar32 = (!bVar36 && !bVar32) == bVar36;
                                    if (bVar32) {
                                      local_26f0[27] = 1;
                                    }
                                    else {
                                      iVar18 = 0xc;
                                      pbVar20 = pbVar24;
                                      pbVar31 = (byte *)"aes-256-ige";
                                      do {
                                        if (iVar18 == 0) break;
                                        iVar18 = iVar18 + -1;
                                        bVar35 = *pbVar20 < *pbVar31;
                                        bVar32 = *pbVar20 == *pbVar31;
                                        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                      } while (bVar32);
                                      bVar36 = (!bVar35 && !bVar32) < bVar35;
                                      bVar32 = (!bVar35 && !bVar32) == bVar35;
                                      if (bVar32) {
                                        local_26f0[28] = 1;
                                      }
                                      else {
                                        iVar18 = 0x11;
                                        pbVar20 = pbVar24;
                                        pbVar31 = (byte *)"camellia-128-cbc";
                                        do {
                                          if (iVar18 == 0) break;
                                          iVar18 = iVar18 + -1;
                                          bVar36 = *pbVar20 < *pbVar31;
                                          bVar32 = *pbVar20 == *pbVar31;
                                          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                        } while (bVar32);
                                        bVar35 = (!bVar36 && !bVar32) < bVar36;
                                        bVar32 = (!bVar36 && !bVar32) == bVar36;
                                        if (bVar32) {
                                          local_26f0[19] = 1;
                                        }
                                        else {
                                          iVar18 = 0x11;
                                          pbVar20 = pbVar24;
                                          pbVar31 = (byte *)"camellia-192-cbc";
                                          do {
                                            if (iVar18 == 0) break;
                                            iVar18 = iVar18 + -1;
                                            bVar35 = *pbVar20 < *pbVar31;
                                            bVar32 = *pbVar20 == *pbVar31;
                                            pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                            pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                          } while (bVar32);
                                          bVar36 = (!bVar35 && !bVar32) < bVar35;
                                          bVar32 = (!bVar35 && !bVar32) == bVar35;
                                          if (bVar32) {
                                            local_26f0[20] = 1;
                                          }
                                          else {
                                            iVar18 = 0x11;
                                            pbVar20 = pbVar24;
                                            pbVar31 = (byte *)"camellia-256-cbc";
                                            do {
                                              if (iVar18 == 0) break;
                                              iVar18 = iVar18 + -1;
                                              bVar36 = *pbVar20 < *pbVar31;
                                              bVar32 = *pbVar20 == *pbVar31;
                                              pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                              pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                            } while (bVar32);
                                            bVar35 = (!bVar36 && !bVar32) < bVar36;
                                            bVar32 = (!bVar36 && !bVar32) == bVar36;
                                            if (bVar32) {
LAB_08077fd2:
                                              local_26f0[21] = 1;
                                            }
                                            else {
                                              iVar18 = 8;
                                              pbVar20 = pbVar24;
                                              pbVar31 = (byte *)"openssl";
                                              do {
                                                if (iVar18 == 0) break;
                                                iVar18 = iVar18 + -1;
                                                bVar35 = *pbVar20 < *pbVar31;
                                                bVar32 = *pbVar20 == *pbVar31;
                                                pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                              } while (bVar32);
                                              bVar36 = (!bVar35 && !bVar32) < bVar35;
                                              bVar32 = (!bVar35 && !bVar32) == bVar35;
                                              if (bVar32) {
                                                uVar42 = CONCAT44(0x8078011,(int)uVar42);
                                                meth = RSA_PKCS1_SSLeay();
                                                RSA_set_default_method(meth);
                                                iVar17 = iVar17 + -1;
                                              }
                                              else {
                                                iVar18 = 7;
                                                pbVar20 = pbVar24;
                                                pbVar31 = (byte *)"dsa512";
                                                do {
                                                  if (iVar18 == 0) break;
                                                  iVar18 = iVar18 + -1;
                                                  bVar36 = *pbVar20 < *pbVar31;
                                                  bVar32 = *pbVar20 == *pbVar31;
                                                  pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                  pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                } while (bVar32);
                                                bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                if (bVar32) {
                                                  local_287c = 2;
                                                }
                                                else {
                                                  iVar18 = 8;
                                                  pbVar20 = pbVar24;
                                                  pbVar31 = &DAT_081f683a;
                                                  do {
                                                    if (iVar18 == 0) break;
                                                    iVar18 = iVar18 + -1;
                                                    bVar35 = *pbVar20 < *pbVar31;
                                                    bVar32 = *pbVar20 == *pbVar31;
                                                    pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                    pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                  } while (bVar32);
                                                  bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                  bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                  if (bVar32) {
                                                    local_2878 = 2;
                                                  }
                                                  else {
                                                    iVar18 = 8;
                                                    pbVar20 = pbVar24;
                                                    pbVar31 = &DAT_081f6842;
                                                    do {
                                                      if (iVar18 == 0) break;
                                                      iVar18 = iVar18 + -1;
                                                      bVar36 = *pbVar20 < *pbVar31;
                                                      bVar32 = *pbVar20 == *pbVar31;
                                                      pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                      pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                    } while (bVar32);
                                                    bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                    bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                    if (bVar32) {
                                                      local_2874 = 2;
                                                    }
                                                    else {
                                                      iVar18 = 7;
                                                      pbVar20 = pbVar24;
                                                      pbVar31 = (byte *)"rsa512";
                                                      do {
                                                        if (iVar18 == 0) break;
                                                        iVar18 = iVar18 + -1;
                                                        bVar35 = *pbVar20 < *pbVar31;
                                                        bVar32 = *pbVar20 == *pbVar31;
                                                        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                      } while (bVar32);
                                                      bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                      bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                      if (bVar32) {
                                                        local_2860 = (RSA *)0x2;
                                                      }
                                                      else {
                                                        iVar18 = 8;
                                                        pbVar20 = pbVar24;
                                                        pbVar31 = (byte *)"rsa1024";
                                                        do {
                                                          if (iVar18 == 0) break;
                                                          iVar18 = iVar18 + -1;
                                                          bVar36 = *pbVar20 < *pbVar31;
                                                          bVar32 = *pbVar20 == *pbVar31;
                                                          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                        } while (bVar32);
                                                        bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                        bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                        if (bVar32) {
                                                          local_285c = 2;
                                                        }
                                                        else {
                                                          iVar18 = 8;
                                                          pbVar20 = pbVar24;
                                                          pbVar31 = (byte *)"rsa2048";
                                                          do {
                                                            if (iVar18 == 0) break;
                                                            iVar18 = iVar18 + -1;
                                                            bVar35 = *pbVar20 < *pbVar31;
                                                            bVar32 = *pbVar20 == *pbVar31;
                                                            pbVar20 = pbVar20 + (uint)bVar38 * -2 +
                                                                                1;
                                                            pbVar31 = pbVar31 + (uint)bVar38 * -2 +
                                                                                1;
                                                          } while (bVar32);
                                                          bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                          bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                          if (bVar32) {
                                                            local_2858 = 2;
                                                          }
                                                          else {
                                                            iVar18 = 8;
                                                            pbVar20 = pbVar24;
                                                            pbVar31 = &DAT_081f6861;
                                                            do {
                                                              if (iVar18 == 0) break;
                                                              iVar18 = iVar18 + -1;
                                                              bVar36 = *pbVar20 < *pbVar31;
                                                              bVar32 = *pbVar20 == *pbVar31;
                                                              pbVar20 = pbVar20 + (uint)bVar38 * -2
                                                                                  + 1;
                                                              pbVar31 = pbVar31 + (uint)bVar38 * -2
                                                                                  + 1;
                                                            } while (bVar32);
                                                            bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                            bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                            if (bVar32) {
                                                              local_2854 = 2;
                                                            }
                                                            else {
                                                              iVar18 = 8;
                                                              pbVar20 = pbVar24;
                                                              pbVar31 = (byte *)"rc2-cbc";
                                                              do {
                                                                if (iVar18 == 0) break;
                                                                iVar18 = iVar18 + -1;
                                                                bVar35 = *pbVar20 < *pbVar31;
                                                                bVar32 = *pbVar20 == *pbVar31;
                                                                pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                                pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                              } while (bVar32);
                                                              if ((!bVar35 && !bVar32) == bVar35) {
LAB_08078138:
                                                                local_26f0[12] = 1;
                                                              }
                                                              else {
                                                                bVar32 = false;
                                                                bVar36 = bVar1 == 0x72;
                                                                if (bVar36) {
                                                                  bVar32 = pbVar24[1] < 99;
                                                                  bVar36 = pbVar24[1] == 99;
                                                                  if (bVar36) {
                                                                    bVar32 = pbVar24[2] < 0x32;
                                                                    bVar36 = pbVar24[2] == 0x32;
                                                                    if (bVar36) {
                                                                      bVar32 = false;
                                                                      bVar36 = pbVar24[3] == 0;
                                                                      if (bVar36) goto LAB_08078138;
                                                                    }
                                                                  }
                                                                }
                                                                iVar18 = 9;
                                                                pbVar20 = pbVar24;
                                                                pbVar31 = (byte *)"idea-cbc";
                                                                do {
                                                                  if (iVar18 == 0) break;
                                                                  iVar18 = iVar18 + -1;
                                                                  bVar32 = *pbVar20 < *pbVar31;
                                                                  bVar36 = *pbVar20 == *pbVar31;
                                                                  pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                  pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                } while (bVar36);
                                                                bVar35 = (!bVar32 && !bVar36) <
                                                                         bVar32;
                                                                bVar32 = (!bVar32 && !bVar36) ==
                                                                         bVar32;
                                                                if (!bVar32) {
                                                                  iVar18 = 5;
                                                                  pbVar20 = pbVar24;
                                                                  pbVar31 = &DAT_081f2a0d;
                                                                  do {
                                                                    if (iVar18 == 0) break;
                                                                    iVar18 = iVar18 + -1;
                                                                    bVar35 = *pbVar20 < *pbVar31;
                                                                    bVar32 = *pbVar20 == *pbVar31;
                                                                    pbVar20 = pbVar20 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                    pbVar31 = pbVar31 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                  } while (bVar32);
                                                                  bVar36 = (!bVar35 && !bVar32) <
                                                                           bVar35;
                                                                  bVar32 = (!bVar35 && !bVar32) ==
                                                                           bVar35;
                                                                  if (!bVar32) {
                                                                    iVar18 = 9;
                                                                    pbVar20 = pbVar24;
                                                                    pbVar31 = (byte *)"seed-cbc";
                                                                    do {
                                                                      if (iVar18 == 0) break;
                                                                      iVar18 = iVar18 + -1;
                                                                      bVar36 = *pbVar20 < *pbVar31;
                                                                      bVar32 = *pbVar20 == *pbVar31;
                                                                      pbVar20 = pbVar20 + (uint)
                                                  bVar38 * -2 + 1;
                                                  pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                  } while (bVar32);
                                                  bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                  bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                  if (!bVar32) {
                                                    iVar18 = 5;
                                                    pbVar20 = pbVar24;
                                                    pbVar31 = (byte *)0x81f2a13;
                                                    do {
                                                      if (iVar18 == 0) break;
                                                      iVar18 = iVar18 + -1;
                                                      bVar35 = *pbVar20 < *pbVar31;
                                                      bVar32 = *pbVar20 == *pbVar31;
                                                      pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                      pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                    } while (bVar32);
                                                    bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                    bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                    if (!bVar32) {
                                                      iVar18 = 7;
                                                      pbVar20 = pbVar24;
                                                      pbVar31 = (byte *)"bf-cbc";
                                                      do {
                                                        if (iVar18 == 0) break;
                                                        iVar18 = iVar18 + -1;
                                                        bVar36 = *pbVar20 < *pbVar31;
                                                        bVar32 = *pbVar20 == *pbVar31;
                                                        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                      } while (bVar32);
                                                      bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                      bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                      if (!bVar32) {
                                                        iVar18 = 9;
                                                        pbVar20 = pbVar24;
                                                        pbVar31 = (byte *)"blowfish";
                                                        do {
                                                          if (iVar18 == 0) break;
                                                          iVar18 = iVar18 + -1;
                                                          bVar35 = *pbVar20 < *pbVar31;
                                                          bVar32 = *pbVar20 == *pbVar31;
                                                          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                        } while (bVar32);
                                                        if ((!bVar35 && !bVar32) != bVar35) {
                                                          bVar32 = bVar1 < 0x62;
                                                          bVar36 = bVar1 == 0x62;
                                                          if (bVar36) {
                                                            bVar32 = pbVar24[1] < 0x66;
                                                            bVar36 = pbVar24[1] == 0x66;
                                                            if (bVar36) {
                                                              bVar32 = false;
                                                              bVar36 = pbVar24[2] == 0;
                                                              if (bVar36) goto LAB_08078222;
                                                            }
                                                          }
                                                          iVar18 = 9;
                                                          pbVar20 = pbVar24;
                                                          pbVar31 = (byte *)"cast-cbc";
                                                          do {
                                                            if (iVar18 == 0) break;
                                                            iVar18 = iVar18 + -1;
                                                            bVar32 = *pbVar20 < *pbVar31;
                                                            bVar36 = *pbVar20 == *pbVar31;
                                                            pbVar20 = pbVar20 + (uint)bVar38 * -2 +
                                                                                1;
                                                            pbVar31 = pbVar31 + (uint)bVar38 * -2 +
                                                                                1;
                                                          } while (bVar36);
                                                          bVar35 = (!bVar32 && !bVar36) < bVar32;
                                                          bVar32 = (!bVar32 && !bVar36) == bVar32;
                                                          if (!bVar32) {
                                                            iVar18 = 5;
                                                            pbVar20 = pbVar24;
                                                            pbVar31 = &DAT_081ea571;
                                                            do {
                                                              if (iVar18 == 0) break;
                                                              iVar18 = iVar18 + -1;
                                                              bVar35 = *pbVar20 < *pbVar31;
                                                              bVar32 = *pbVar20 == *pbVar31;
                                                              pbVar20 = pbVar20 + (uint)bVar38 * -2
                                                                                  + 1;
                                                              pbVar31 = pbVar31 + (uint)bVar38 * -2
                                                                                  + 1;
                                                            } while (bVar32);
                                                            bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                            bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                            if (!bVar32) {
                                                              iVar18 = 6;
                                                              pbVar20 = pbVar24;
                                                              pbVar31 = (byte *)"cast5";
                                                              do {
                                                                if (iVar18 == 0) break;
                                                                iVar18 = iVar18 + -1;
                                                                bVar36 = *pbVar20 < *pbVar31;
                                                                bVar32 = *pbVar20 == *pbVar31;
                                                                pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                                pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                              } while (bVar32);
                                                              if ((!bVar36 && !bVar32) != bVar36) {
                                                                if (bVar1 == 100) {
                                                                  bVar32 = pbVar24[1] < 0x65;
                                                                  bVar36 = pbVar24[1] == 0x65;
                                                                  if (bVar36) {
                                                                    if ((pbVar24[2] == 0x73) &&
                                                                       (pbVar24[3] == 0)) {
                                                                      local_26f0[8] = 1;
                                                                      goto LAB_08077de7;
                                                                    }
                                                                    bVar32 = false;
                                                                    bVar36 = false;
                                                                  }
                                                                }
                                                                else {
                                                                  bVar32 = bVar1 < 0x61;
                                                                  bVar36 = bVar1 == 0x61;
                                                                  if (bVar36) {
                                                                    bVar32 = pbVar24[1] < 0x65;
                                                                    bVar36 = pbVar24[1] == 0x65;
                                                                    if (bVar36) {
                                                                      bVar32 = pbVar24[2] < 0x73;
                                                                      bVar36 = pbVar24[2] == 0x73;
                                                                      if (bVar36) {
                                                                        bVar32 = false;
                                                                        bVar36 = pbVar24[3] == 0;
                                                                        if (bVar36) {
                                                                          local_26f0[16] = 1;
                                                                          local_26f0[17] = 1;
                                                                          goto LAB_08077e7c;
                                                                        }
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                                iVar18 = 6;
                                                                pbVar20 = pbVar24;
                                                                pbVar31 = (byte *)"ghash";
                                                                do {
                                                                  if (iVar18 == 0) break;
                                                                  iVar18 = iVar18 + -1;
                                                                  bVar32 = *pbVar20 < *pbVar31;
                                                                  bVar36 = *pbVar20 == *pbVar31;
                                                                  pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                  pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                } while (bVar36);
                                                                bVar35 = (!bVar32 && !bVar36) <
                                                                         bVar32;
                                                                bVar32 = (!bVar32 && !bVar36) ==
                                                                         bVar32;
                                                                if (bVar32) {
                                                                  local_26f0[29] = 1;
                                                                }
                                                                else {
                                                                  iVar18 = 9;
                                                                  pbVar20 = pbVar24;
                                                                  pbVar31 = (byte *)"camellia";
                                                                  do {
                                                                    if (iVar18 == 0) break;
                                                                    iVar18 = iVar18 + -1;
                                                                    bVar35 = *pbVar20 < *pbVar31;
                                                                    bVar32 = *pbVar20 == *pbVar31;
                                                                    pbVar20 = pbVar20 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                    pbVar31 = pbVar31 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                  } while (bVar32);
                                                                  if ((!bVar35 && !bVar32) == bVar35
                                                                     ) {
                                                                    local_26f0[19] = 1;
                                                                    local_26f0[20] = 1;
                                                                    goto LAB_08077fd2;
                                                                  }
                                                                  if (bVar1 == 0x72) {
                                                                    bVar32 = pbVar24[1] < 0x73;
                                                                    bVar36 = pbVar24[1] == 0x73;
                                                                    if (bVar36) {
                                                                      if ((pbVar24[2] == 0x61) &&
                                                                         (pbVar24[3] == 0)) {
                                                                        local_2860 = (RSA *)0x1;
                                                                        local_285c = 1;
                                                                        local_2858 = 1;
                                                                        local_2854 = 1;
                                                                        goto LAB_080717d9;
                                                                      }
                                                                      bVar32 = false;
                                                                      bVar36 = false;
                                                                    }
                                                                  }
                                                                  else {
                                                                    bVar32 = false;
                                                                    bVar36 = bVar1 == 100;
                                                                    if (bVar36) {
                                                                      bVar32 = pbVar24[1] < 0x73;
                                                                      bVar36 = pbVar24[1] == 0x73;
                                                                      if (bVar36) {
                                                                        bVar32 = pbVar24[2] < 0x61;
                                                                        bVar36 = pbVar24[2] == 0x61;
                                                                        if (bVar36) {
                                                                          bVar32 = false;
                                                                          bVar36 = pbVar24[3] == 0;
                                                                          if (bVar36) {
                                                                            local_287c = 1;
                                                                            local_2878 = 1;
                                                                            local_2874 = 1;
                                                                            goto LAB_080717d9;
                                                                          }
                                                                        }
                                                                      }
                                                                    }
                                                                  }
                                                                  iVar18 = 10;
                                                                  pbVar20 = pbVar24;
                                                                  pbVar31 = (byte *)"ecdsap160";
                                                                  do {
                                                                    if (iVar18 == 0) break;
                                                                    iVar18 = iVar18 + -1;
                                                                    bVar32 = *pbVar20 < *pbVar31;
                                                                    bVar36 = *pbVar20 == *pbVar31;
                                                                    pbVar20 = pbVar20 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                    pbVar31 = pbVar31 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                  } while (bVar36);
                                                                  bVar35 = (!bVar32 && !bVar36) <
                                                                           bVar32;
                                                                  bVar32 = (!bVar32 && !bVar36) ==
                                                                           bVar32;
                                                                  if (bVar32) {
                                                                    local_2770[0] = 2;
                                                                  }
                                                                  else {
                                                                    iVar18 = 10;
                                                                    pbVar20 = pbVar24;
                                                                    pbVar31 = (byte *)"ecdsap192";
                                                                    do {
                                                                      if (iVar18 == 0) break;
                                                                      iVar18 = iVar18 + -1;
                                                                      bVar35 = *pbVar20 < *pbVar31;
                                                                      bVar32 = *pbVar20 == *pbVar31;
                                                                      pbVar20 = pbVar20 + (uint)
                                                  bVar38 * -2 + 1;
                                                  pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                  } while (bVar32);
                                                  bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                  bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                  if (bVar32) {
                                                    local_2770[1] = 2;
                                                  }
                                                  else {
                                                    iVar18 = 10;
                                                    pbVar20 = pbVar24;
                                                    pbVar31 = (byte *)"ecdsap224";
                                                    do {
                                                      if (iVar18 == 0) break;
                                                      iVar18 = iVar18 + -1;
                                                      bVar36 = *pbVar20 < *pbVar31;
                                                      bVar32 = *pbVar20 == *pbVar31;
                                                      pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                      pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                    } while (bVar32);
                                                    bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                    bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                    if (bVar32) {
                                                      local_2770[2] = 2;
                                                    }
                                                    else {
                                                      iVar18 = 10;
                                                      pbVar20 = pbVar24;
                                                      pbVar31 = (byte *)"ecdsap256";
                                                      do {
                                                        if (iVar18 == 0) break;
                                                        iVar18 = iVar18 + -1;
                                                        bVar35 = *pbVar20 < *pbVar31;
                                                        bVar32 = *pbVar20 == *pbVar31;
                                                        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                      } while (bVar32);
                                                      bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                      bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                      if (bVar32) {
                                                        local_2770[3] = 2;
                                                      }
                                                      else {
                                                        iVar18 = 10;
                                                        pbVar20 = pbVar24;
                                                        pbVar31 = (byte *)"ecdsap384";
                                                        do {
                                                          if (iVar18 == 0) break;
                                                          iVar18 = iVar18 + -1;
                                                          bVar36 = *pbVar20 < *pbVar31;
                                                          bVar32 = *pbVar20 == *pbVar31;
                                                          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                        } while (bVar32);
                                                        bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                        bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                        if (bVar32) {
                                                          local_2770[4] = 2;
                                                        }
                                                        else {
                                                          iVar18 = 10;
                                                          pbVar20 = pbVar24;
                                                          pbVar31 = (byte *)"ecdsap521";
                                                          do {
                                                            if (iVar18 == 0) break;
                                                            iVar18 = iVar18 + -1;
                                                            bVar35 = *pbVar20 < *pbVar31;
                                                            bVar32 = *pbVar20 == *pbVar31;
                                                            pbVar20 = pbVar20 + (uint)bVar38 * -2 +
                                                                                1;
                                                            pbVar31 = pbVar31 + (uint)bVar38 * -2 +
                                                                                1;
                                                          } while (bVar32);
                                                          bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                          bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                          if (bVar32) {
                                                            local_2770[5] = 2;
                                                          }
                                                          else {
                                                            iVar18 = 10;
                                                            pbVar20 = pbVar24;
                                                            pbVar31 = (byte *)"ecdsak163";
                                                            do {
                                                              if (iVar18 == 0) break;
                                                              iVar18 = iVar18 + -1;
                                                              bVar36 = *pbVar20 < *pbVar31;
                                                              bVar32 = *pbVar20 == *pbVar31;
                                                              pbVar20 = pbVar20 + (uint)bVar38 * -2
                                                                                  + 1;
                                                              pbVar31 = pbVar31 + (uint)bVar38 * -2
                                                                                  + 1;
                                                            } while (bVar32);
                                                            bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                            bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                            if (bVar32) {
                                                              local_2770[6] = 2;
                                                            }
                                                            else {
                                                              iVar18 = 10;
                                                              pbVar20 = pbVar24;
                                                              pbVar31 = (byte *)"ecdsak233";
                                                              do {
                                                                if (iVar18 == 0) break;
                                                                iVar18 = iVar18 + -1;
                                                                bVar35 = *pbVar20 < *pbVar31;
                                                                bVar32 = *pbVar20 == *pbVar31;
                                                                pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                                pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                              } while (bVar32);
                                                              bVar36 = (!bVar35 && !bVar32) < bVar35
                                                              ;
                                                              bVar32 = (!bVar35 && !bVar32) ==
                                                                       bVar35;
                                                              if (bVar32) {
                                                                local_2770[7] = 2;
                                                              }
                                                              else {
                                                                iVar18 = 10;
                                                                pbVar20 = pbVar24;
                                                                pbVar31 = (byte *)"ecdsak283";
                                                                do {
                                                                  if (iVar18 == 0) break;
                                                                  iVar18 = iVar18 + -1;
                                                                  bVar36 = *pbVar20 < *pbVar31;
                                                                  bVar32 = *pbVar20 == *pbVar31;
                                                                  pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                  pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                } while (bVar32);
                                                                bVar35 = (!bVar36 && !bVar32) <
                                                                         bVar36;
                                                                bVar32 = (!bVar36 && !bVar32) ==
                                                                         bVar36;
                                                                if (bVar32) {
                                                                  local_2770[8] = 2;
                                                                }
                                                                else {
                                                                  iVar18 = 10;
                                                                  pbVar20 = pbVar24;
                                                                  pbVar31 = (byte *)"ecdsak409";
                                                                  do {
                                                                    if (iVar18 == 0) break;
                                                                    iVar18 = iVar18 + -1;
                                                                    bVar35 = *pbVar20 < *pbVar31;
                                                                    bVar32 = *pbVar20 == *pbVar31;
                                                                    pbVar20 = pbVar20 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                    pbVar31 = pbVar31 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                  } while (bVar32);
                                                                  bVar36 = (!bVar35 && !bVar32) <
                                                                           bVar35;
                                                                  bVar32 = (!bVar35 && !bVar32) ==
                                                                           bVar35;
                                                                  if (bVar32) {
                                                                    local_2770[9] = 2;
                                                                  }
                                                                  else {
                                                                    iVar18 = 10;
                                                                    pbVar20 = pbVar24;
                                                                    pbVar31 = (byte *)"ecdsak571";
                                                                    do {
                                                                      if (iVar18 == 0) break;
                                                                      iVar18 = iVar18 + -1;
                                                                      bVar36 = *pbVar20 < *pbVar31;
                                                                      bVar32 = *pbVar20 == *pbVar31;
                                                                      pbVar20 = pbVar20 + (uint)
                                                  bVar38 * -2 + 1;
                                                  pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                  } while (bVar32);
                                                  bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                  bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                  if (bVar32) {
                                                    local_2770[10] = 2;
                                                  }
                                                  else {
                                                    iVar18 = 10;
                                                    pbVar20 = pbVar24;
                                                    pbVar31 = (byte *)"ecdsab163";
                                                    do {
                                                      if (iVar18 == 0) break;
                                                      iVar18 = iVar18 + -1;
                                                      bVar35 = *pbVar20 < *pbVar31;
                                                      bVar32 = *pbVar20 == *pbVar31;
                                                      pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                      pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                    } while (bVar32);
                                                    bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                    bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                    if (bVar32) {
                                                      local_2770[11] = 2;
                                                    }
                                                    else {
                                                      iVar18 = 10;
                                                      pbVar20 = pbVar24;
                                                      pbVar31 = (byte *)"ecdsab233";
                                                      do {
                                                        if (iVar18 == 0) break;
                                                        iVar18 = iVar18 + -1;
                                                        bVar36 = *pbVar20 < *pbVar31;
                                                        bVar32 = *pbVar20 == *pbVar31;
                                                        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                      } while (bVar32);
                                                      bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                      bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                      if (bVar32) {
                                                        local_2770[12] = 2;
                                                      }
                                                      else {
                                                        iVar18 = 10;
                                                        pbVar20 = pbVar24;
                                                        pbVar31 = (byte *)"ecdsab283";
                                                        do {
                                                          if (iVar18 == 0) break;
                                                          iVar18 = iVar18 + -1;
                                                          bVar35 = *pbVar20 < *pbVar31;
                                                          bVar32 = *pbVar20 == *pbVar31;
                                                          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                        } while (bVar32);
                                                        bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                        bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                        if (bVar32) {
                                                          local_2770[13] = 2;
                                                        }
                                                        else {
                                                          iVar18 = 10;
                                                          pbVar20 = pbVar24;
                                                          pbVar31 = (byte *)"ecdsab409";
                                                          do {
                                                            if (iVar18 == 0) break;
                                                            iVar18 = iVar18 + -1;
                                                            bVar36 = *pbVar20 < *pbVar31;
                                                            bVar32 = *pbVar20 == *pbVar31;
                                                            pbVar20 = pbVar20 + (uint)bVar38 * -2 +
                                                                                1;
                                                            pbVar31 = pbVar31 + (uint)bVar38 * -2 +
                                                                                1;
                                                          } while (bVar32);
                                                          bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                          bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                          if (bVar32) {
                                                            local_2770[14] = 2;
                                                          }
                                                          else {
                                                            iVar18 = 10;
                                                            pbVar20 = pbVar24;
                                                            pbVar31 = (byte *)"ecdsab571";
                                                            do {
                                                              if (iVar18 == 0) break;
                                                              iVar18 = iVar18 + -1;
                                                              bVar35 = *pbVar20 < *pbVar31;
                                                              bVar32 = *pbVar20 == *pbVar31;
                                                              pbVar20 = pbVar20 + (uint)bVar38 * -2
                                                                                  + 1;
                                                              pbVar31 = pbVar31 + (uint)bVar38 * -2
                                                                                  + 1;
                                                            } while (bVar32);
                                                            bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                            bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                            if (bVar32) {
                                                              local_2770[15] = 2;
                                                            }
                                                            else {
                                                              iVar18 = 6;
                                                              pbVar20 = pbVar24;
                                                              pbVar31 = &DAT_081f6927;
                                                              do {
                                                                if (iVar18 == 0) break;
                                                                iVar18 = iVar18 + -1;
                                                                bVar36 = *pbVar20 < *pbVar31;
                                                                bVar32 = *pbVar20 == *pbVar31;
                                                                pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                                pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                              } while (bVar32);
                                                              bVar35 = (!bVar36 && !bVar32) < bVar36
                                                              ;
                                                              bVar32 = (!bVar36 && !bVar32) ==
                                                                       bVar36;
                                                              if (bVar32) {
                                                                local_2770[0] = 1;
                                                                local_2770[1] = 1;
                                                                local_2770[2] = 1;
                                                                local_2770[3] = 1;
                                                                local_2770[4] = 1;
                                                                local_2770[5] = 1;
                                                                local_2770[6] = 1;
                                                                local_2770[7] = 1;
                                                                local_2770[8] = 1;
                                                                local_2770[9] = 1;
                                                                local_2770[10] = 1;
                                                                local_2770[11] = 1;
                                                                local_2770[12] = 1;
                                                                local_2770[13] = 1;
                                                                local_2770[14] = 1;
                                                                local_2770[15] = 1;
                                                              }
                                                              else {
                                                                iVar18 = 9;
                                                                pbVar20 = pbVar24;
                                                                pbVar31 = (byte *)"ecdhp160";
                                                                do {
                                                                  if (iVar18 == 0) break;
                                                                  iVar18 = iVar18 + -1;
                                                                  bVar35 = *pbVar20 < *pbVar31;
                                                                  bVar32 = *pbVar20 == *pbVar31;
                                                                  pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                  pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                } while (bVar32);
                                                                bVar36 = (!bVar35 && !bVar32) <
                                                                         bVar35;
                                                                bVar32 = (!bVar35 && !bVar32) ==
                                                                         bVar35;
                                                                if (bVar32) {
                                                                  local_2730[0] = 2;
                                                                }
                                                                else {
                                                                  iVar18 = 9;
                                                                  pbVar20 = pbVar24;
                                                                  pbVar31 = (byte *)"ecdhp192";
                                                                  do {
                                                                    if (iVar18 == 0) break;
                                                                    iVar18 = iVar18 + -1;
                                                                    bVar36 = *pbVar20 < *pbVar31;
                                                                    bVar32 = *pbVar20 == *pbVar31;
                                                                    pbVar20 = pbVar20 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                    pbVar31 = pbVar31 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                  } while (bVar32);
                                                                  bVar35 = (!bVar36 && !bVar32) <
                                                                           bVar36;
                                                                  bVar32 = (!bVar36 && !bVar32) ==
                                                                           bVar36;
                                                                  if (bVar32) {
                                                                    local_2730[1] = 2;
                                                                  }
                                                                  else {
                                                                    iVar18 = 9;
                                                                    pbVar20 = pbVar24;
                                                                    pbVar31 = (byte *)"ecdhp224";
                                                                    do {
                                                                      if (iVar18 == 0) break;
                                                                      iVar18 = iVar18 + -1;
                                                                      bVar35 = *pbVar20 < *pbVar31;
                                                                      bVar32 = *pbVar20 == *pbVar31;
                                                                      pbVar20 = pbVar20 + (uint)
                                                  bVar38 * -2 + 1;
                                                  pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                  } while (bVar32);
                                                  bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                  bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                  if (bVar32) {
                                                    local_2730[2] = 2;
                                                  }
                                                  else {
                                                    iVar18 = 9;
                                                    pbVar20 = pbVar24;
                                                    pbVar31 = (byte *)"ecdhp256";
                                                    do {
                                                      if (iVar18 == 0) break;
                                                      iVar18 = iVar18 + -1;
                                                      bVar36 = *pbVar20 < *pbVar31;
                                                      bVar32 = *pbVar20 == *pbVar31;
                                                      pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                      pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                    } while (bVar32);
                                                    bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                    bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                    if (bVar32) {
                                                      local_2730[3] = 2;
                                                    }
                                                    else {
                                                      iVar18 = 9;
                                                      pbVar20 = pbVar24;
                                                      pbVar31 = (byte *)"ecdhp384";
                                                      do {
                                                        if (iVar18 == 0) break;
                                                        iVar18 = iVar18 + -1;
                                                        bVar35 = *pbVar20 < *pbVar31;
                                                        bVar32 = *pbVar20 == *pbVar31;
                                                        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                      } while (bVar32);
                                                      bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                      bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                      if (bVar32) {
                                                        local_2730[4] = 2;
                                                      }
                                                      else {
                                                        iVar18 = 9;
                                                        pbVar20 = pbVar24;
                                                        pbVar31 = (byte *)"ecdhp521";
                                                        do {
                                                          if (iVar18 == 0) break;
                                                          iVar18 = iVar18 + -1;
                                                          bVar36 = *pbVar20 < *pbVar31;
                                                          bVar32 = *pbVar20 == *pbVar31;
                                                          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                        } while (bVar32);
                                                        bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                        bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                        if (bVar32) {
                                                          local_2730[5] = 2;
                                                        }
                                                        else {
                                                          iVar18 = 9;
                                                          pbVar20 = pbVar24;
                                                          pbVar31 = (byte *)"ecdhk163";
                                                          do {
                                                            if (iVar18 == 0) break;
                                                            iVar18 = iVar18 + -1;
                                                            bVar35 = *pbVar20 < *pbVar31;
                                                            bVar32 = *pbVar20 == *pbVar31;
                                                            pbVar20 = pbVar20 + (uint)bVar38 * -2 +
                                                                                1;
                                                            pbVar31 = pbVar31 + (uint)bVar38 * -2 +
                                                                                1;
                                                          } while (bVar32);
                                                          bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                          bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                          if (bVar32) {
                                                            local_2730[6] = 2;
                                                          }
                                                          else {
                                                            iVar18 = 9;
                                                            pbVar20 = pbVar24;
                                                            pbVar31 = (byte *)"ecdhk233";
                                                            do {
                                                              if (iVar18 == 0) break;
                                                              iVar18 = iVar18 + -1;
                                                              bVar36 = *pbVar20 < *pbVar31;
                                                              bVar32 = *pbVar20 == *pbVar31;
                                                              pbVar20 = pbVar20 + (uint)bVar38 * -2
                                                                                  + 1;
                                                              pbVar31 = pbVar31 + (uint)bVar38 * -2
                                                                                  + 1;
                                                            } while (bVar32);
                                                            bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                            bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                            if (bVar32) {
                                                              local_2730[7] = 2;
                                                            }
                                                            else {
                                                              iVar18 = 9;
                                                              pbVar20 = pbVar24;
                                                              pbVar31 = (byte *)"ecdhk283";
                                                              do {
                                                                if (iVar18 == 0) break;
                                                                iVar18 = iVar18 + -1;
                                                                bVar35 = *pbVar20 < *pbVar31;
                                                                bVar32 = *pbVar20 == *pbVar31;
                                                                pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                                pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                    -2 + 1;
                                                              } while (bVar32);
                                                              bVar36 = (!bVar35 && !bVar32) < bVar35
                                                              ;
                                                              bVar32 = (!bVar35 && !bVar32) ==
                                                                       bVar35;
                                                              if (bVar32) {
                                                                local_2730[8] = 2;
                                                              }
                                                              else {
                                                                iVar18 = 9;
                                                                pbVar20 = pbVar24;
                                                                pbVar31 = (byte *)"ecdhk409";
                                                                do {
                                                                  if (iVar18 == 0) break;
                                                                  iVar18 = iVar18 + -1;
                                                                  bVar36 = *pbVar20 < *pbVar31;
                                                                  bVar32 = *pbVar20 == *pbVar31;
                                                                  pbVar20 = pbVar20 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                  pbVar31 = pbVar31 + (uint)bVar38 *
                                                                                      -2 + 1;
                                                                } while (bVar32);
                                                                bVar35 = (!bVar36 && !bVar32) <
                                                                         bVar36;
                                                                bVar32 = (!bVar36 && !bVar32) ==
                                                                         bVar36;
                                                                if (bVar32) {
                                                                  local_2730[9] = 2;
                                                                }
                                                                else {
                                                                  iVar18 = 9;
                                                                  pbVar20 = pbVar24;
                                                                  pbVar31 = (byte *)"ecdhk571";
                                                                  do {
                                                                    if (iVar18 == 0) break;
                                                                    iVar18 = iVar18 + -1;
                                                                    bVar35 = *pbVar20 < *pbVar31;
                                                                    bVar32 = *pbVar20 == *pbVar31;
                                                                    pbVar20 = pbVar20 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                    pbVar31 = pbVar31 + (uint)bVar38
                                                                                        * -2 + 1;
                                                                  } while (bVar32);
                                                                  bVar36 = (!bVar35 && !bVar32) <
                                                                           bVar35;
                                                                  bVar32 = (!bVar35 && !bVar32) ==
                                                                           bVar35;
                                                                  if (bVar32) {
                                                                    local_2730[10] = 2;
                                                                  }
                                                                  else {
                                                                    iVar18 = 9;
                                                                    pbVar20 = pbVar24;
                                                                    pbVar31 = (byte *)"ecdhb163";
                                                                    do {
                                                                      if (iVar18 == 0) break;
                                                                      iVar18 = iVar18 + -1;
                                                                      bVar36 = *pbVar20 < *pbVar31;
                                                                      bVar32 = *pbVar20 == *pbVar31;
                                                                      pbVar20 = pbVar20 + (uint)
                                                  bVar38 * -2 + 1;
                                                  pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                  } while (bVar32);
                                                  bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                  bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                  if (bVar32) {
                                                    local_2730[11] = 2;
                                                  }
                                                  else {
                                                    iVar18 = 9;
                                                    pbVar20 = pbVar24;
                                                    pbVar31 = (byte *)"ecdhb233";
                                                    do {
                                                      if (iVar18 == 0) break;
                                                      iVar18 = iVar18 + -1;
                                                      bVar35 = *pbVar20 < *pbVar31;
                                                      bVar32 = *pbVar20 == *pbVar31;
                                                      pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                      pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                    } while (bVar32);
                                                    bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                    bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                    if (bVar32) {
                                                      local_2730[12] = 2;
                                                    }
                                                    else {
                                                      iVar18 = 9;
                                                      pbVar20 = pbVar24;
                                                      pbVar31 = (byte *)"ecdhb283";
                                                      do {
                                                        if (iVar18 == 0) break;
                                                        iVar18 = iVar18 + -1;
                                                        bVar36 = *pbVar20 < *pbVar31;
                                                        bVar32 = *pbVar20 == *pbVar31;
                                                        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                      } while (bVar32);
                                                      bVar35 = (!bVar36 && !bVar32) < bVar36;
                                                      bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                      if (bVar32) {
                                                        local_2730[13] = 2;
                                                      }
                                                      else {
                                                        iVar18 = 9;
                                                        pbVar20 = pbVar24;
                                                        pbVar31 = (byte *)"ecdhb409";
                                                        do {
                                                          if (iVar18 == 0) break;
                                                          iVar18 = iVar18 + -1;
                                                          bVar35 = *pbVar20 < *pbVar31;
                                                          bVar32 = *pbVar20 == *pbVar31;
                                                          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                                                          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
                                                        } while (bVar32);
                                                        bVar36 = (!bVar35 && !bVar32) < bVar35;
                                                        bVar32 = (!bVar35 && !bVar32) == bVar35;
                                                        if (bVar32) {
                                                          local_2730[14] = 2;
                                                        }
                                                        else {
                                                          iVar18 = 9;
                                                          pbVar20 = pbVar24;
                                                          pbVar31 = (byte *)"ecdhb571";
                                                          do {
                                                            if (iVar18 == 0) break;
                                                            iVar18 = iVar18 + -1;
                                                            bVar36 = *pbVar20 < *pbVar31;
                                                            bVar32 = *pbVar20 == *pbVar31;
                                                            pbVar20 = pbVar20 + (uint)bVar38 * -2 +
                                                                                1;
                                                            pbVar31 = pbVar31 + (uint)bVar38 * -2 +
                                                                                1;
                                                          } while (bVar32);
                                                          bVar32 = (!bVar36 && !bVar32) == bVar36;
                                                          if (bVar32) {
                                                            local_2730[15] = 2;
                                                          }
                                                          else {
                                                            iVar18 = 5;
                                                            pbVar20 = &DAT_081f69bd;
                                                            do {
                                                              if (iVar18 == 0) break;
                                                              iVar18 = iVar18 + -1;
                                                              bVar32 = *pbVar24 == *pbVar20;
                                                              pbVar24 = pbVar24 + (uint)bVar38 * -2
                                                                                  + 1;
                                                              pbVar20 = pbVar20 + (uint)bVar38 * -2
                                                                                  + 1;
                                                            } while (bVar32);
                                                            if (!bVar32) {
                                                              BIO_printf(bio_err,
                                                  "Error: bad option or value\n");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"Available values:\n");
                                                  BIO_printf(bio_err,"mdc2     ");
                                                  BIO_printf(bio_err,"md4      ");
                                                  BIO_printf(bio_err,"md5      ");
                                                  BIO_printf(bio_err,"hmac     ");
                                                  BIO_printf(bio_err,"sha1     ");
                                                  BIO_printf(bio_err,"sha256   ");
                                                  BIO_printf(bio_err,"sha512   ");
                                                  BIO_printf(bio_err,"whirlpool");
                                                  BIO_printf(bio_err,"rmd160");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"idea-cbc ");
                                                  BIO_printf(bio_err,"seed-cbc ");
                                                  BIO_printf(bio_err,"rc2-cbc  ");
                                                  BIO_printf(bio_err,"bf-cbc");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"des-cbc  des-ede3 ");
                                                  BIO_printf(bio_err,
                                                  "aes-128-cbc aes-192-cbc aes-256-cbc ");
                                                  BIO_printf(bio_err,
                                                  "aes-128-ige aes-192-ige aes-256-ige ");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,
                                                  "camellia-128-cbc camellia-192-cbc camellia-256-cbc "
                                                  );
                                                  BIO_printf(bio_err,"rc4");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,
                                                  "rsa512   rsa1024  rsa2048  rsa4096\n");
                                                  BIO_printf(bio_err,"dsa512   dsa1024  dsa2048\n");
                                                  BIO_printf(bio_err,
                                                  "ecdsap160 ecdsap192 ecdsap224 ecdsap256 ecdsap384 ecdsap521\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "ecdsak163 ecdsak233 ecdsak283 ecdsak409 ecdsak571\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "ecdsab163 ecdsab233 ecdsab283 ecdsab409 ecdsab571\n"
                                                  );
                                                  BIO_printf(bio_err,"ecdsa\n");
                                                  BIO_printf(bio_err,
                                                  "ecdhp160  ecdhp192  ecdhp224 ecdhp256  ecdhp384  ecdhp521\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "ecdhk163  ecdhk233  ecdhk283  ecdhk409  ecdhk571\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "ecdhb163  ecdhb233  ecdhb283  ecdhb409  ecdhb571\n"
                                                  );
                                                  BIO_printf(bio_err,"ecdh\n");
                                                  BIO_printf(bio_err,"idea     ");
                                                  BIO_printf(bio_err,"seed     ");
                                                  BIO_printf(bio_err,"rc2      ");
                                                  BIO_printf(bio_err,"des      ");
                                                  BIO_printf(bio_err,"aes      ");
                                                  BIO_printf(bio_err,"camellia ");
                                                  BIO_printf(bio_err,"rsa      ");
                                                  BIO_printf(bio_err,"blowfish");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"Available options:\n");
                                                  BIO_printf(bio_err,
                                                  "-engine e       use engine e, possibly a hardware device.\n"
                                                  );
                                                  BIO_printf(bio_err,"-evp e          use EVP e.\n")
                                                  ;
                                                  BIO_printf(bio_err,
                                                  "-decrypt        time decryption instead of encryption (only EVP).\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "-mr             produce machine readable output.\n"
                                                  );
                                                  pcVar6 = 
                                                  "-multi n        run n benchmarks in parallel.\n";
                                                  goto LAB_08071fed;
                                                  }
                                                  local_2730[0] = 1;
                                                  local_2730[1] = 1;
                                                  local_2730[2] = 1;
                                                  local_2730[3] = 1;
                                                  local_2730[4] = 1;
                                                  local_2730[5] = 1;
                                                  local_2730[6] = 1;
                                                  local_2730[7] = 1;
                                                  local_2730[8] = 1;
                                                  local_2730[9] = 1;
                                                  local_2730[10] = 1;
                                                  local_2730[11] = 1;
                                                  local_2730[12] = 1;
                                                  local_2730[13] = 1;
                                                  local_2730[14] = 1;
                                                  local_2730[15] = 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_080717d9;
                                                  }
                                                  }
                                                  }
                                                  local_26f0[15] = 1;
                                                  goto LAB_080717d9;
                                                  }
                                                  }
LAB_08078222:
                                                  local_26f0[14] = 1;
                                                  goto LAB_080717d9;
                                                  }
                                                  }
                                                  local_26f0[11] = 1;
                                                  goto LAB_080717d9;
                                                  }
                                                  }
                                                  local_26f0[10] = 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        goto LAB_080717d9;
                      }
                    }
                  }
                  local_26f0[6] = 1;
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar18 = 9;
      pbVar20 = pbVar24;
      pbVar31 = (byte *)"-elapsed";
      do {
        if (iVar18 == 0) break;
        iVar18 = iVar18 + -1;
        bVar32 = *pbVar20 < *pbVar31;
        bVar36 = *pbVar20 == *pbVar31;
        pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
        pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
      } while (bVar36);
      bVar32 = (!bVar32 && !bVar36) == bVar32;
      if (bVar32) {
        iVar17 = iVar17 + -1;
        usertime = (code *)0x0;
      }
      else {
        iVar18 = 5;
        pbVar20 = pbVar24;
        pbVar31 = &DAT_081f678c;
        do {
          if (iVar18 == 0) break;
          iVar18 = iVar18 + -1;
          bVar32 = *pbVar20 == *pbVar31;
          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
        } while (bVar32);
        if (bVar32) {
          param_1 = param_1 + -1;
          ppbVar22 = param_2 + 2;
          if (param_1 == 0) {
            pcVar6 = "no EVP given\n";
          }
          else {
            cipher = EVP_get_cipherbyname((char *)param_2[2]);
            if ((cipher != (EVP_CIPHER *)0x0) ||
               (type_00 = EVP_get_digestbyname((char *)param_2[2]), type_00 != (EVP_MD *)0x0)) {
              local_26f0[22] = 1;
              goto LAB_080717d9;
            }
            uVar42 = uVar42 & 0xffffffff00000000 | ZEXT48(param_2[2]);
            pcVar6 = "%s is an unknown cipher or digest\n";
          }
          goto LAB_08071fed;
        }
        iVar18 = 9;
        pbVar20 = pbVar24;
        pbVar31 = (byte *)"-decrypt";
        do {
          if (iVar18 == 0) break;
          iVar18 = iVar18 + -1;
          bVar32 = *pbVar20 == *pbVar31;
          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
          pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
        } while (bVar32);
        if (bVar32) {
          iVar17 = iVar17 + -1;
          bVar34 = true;
        }
        else {
          iVar18 = 8;
          pbVar20 = pbVar24;
          pbVar31 = (byte *)"-engine";
          do {
            if (iVar18 == 0) break;
            iVar18 = iVar18 + -1;
            bVar32 = *pbVar20 == *pbVar31;
            pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
            pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
          } while (bVar32);
          uVar3 = (uint)(uVar42 >> 0x20);
          if (bVar32) {
            param_1 = param_1 + -1;
            ppbVar22 = param_2 + 2;
            if (param_1 == 0) {
              pcVar6 = "no engine given\n";
              goto LAB_08071fed;
            }
            uVar42 = (ulonglong)uVar3 << 0x20;
            setup_engine(bio_err,param_2[2],0);
            iVar17 = iVar17 + -1;
          }
          else {
            iVar18 = 7;
            pbVar20 = pbVar24;
            pbVar31 = (byte *)"-multi";
            do {
              if (iVar18 == 0) break;
              iVar18 = iVar18 + -1;
              bVar32 = *pbVar20 == *pbVar31;
              pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
              pbVar31 = pbVar31 + (uint)bVar38 * -2 + 1;
            } while (bVar32);
            if (bVar32) {
              param_1 = param_1 + -1;
              ppbVar22 = param_2 + 2;
              if (param_1 == 0) {
                pcVar6 = "no multi count given\n";
              }
              else {
                uVar42 = CONCAT44(uVar3,10);
                local_28b8 = strtol((char *)param_2[2],(char **)0x0,10);
                if (0 < local_28b8) {
                  iVar17 = iVar17 + -1;
                  goto LAB_080717d9;
                }
                pcVar6 = "bad multi count\n";
              }
LAB_08071fed:
              uVar21 = 1;
              BIO_printf(bio_err,pcVar6,uVar42);
              goto LAB_0807200c;
            }
            bVar36 = *pbVar24 == 0x2d;
            if ((((!bVar36) || (bVar36 = pbVar24[1] == 0x6d, !bVar36)) ||
                (bVar36 = pbVar24[2] == 0x72, !bVar36)) || (bVar36 = pbVar24[3] == 0, !bVar36))
            goto LAB_080719a0;
            mr = 1;
            iVar17 = iVar17 + -1;
          }
        }
      }
    }
LAB_080717d9:
    iVar17 = iVar17 + 1;
    param_1 = param_1 + -1;
    param_2 = ppbVar22;
  } while (param_1 != 0);
  pcVar41 = usertime;
  if (local_28b8 == 0) {
LAB_08071a15:
    if (iVar17 == 0) goto LAB_08071a23;
    goto LAB_08071bdc;
  }
  __ptr = malloc(local_28b8 << 2);
  iVar18 = 0;
  do {
    iVar10 = pipe((int *)&local_17d8);
    if (iVar10 == -1) {
      fwrite("pipe failure\n",1,0xd,stderr);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    fflush(stdout);
    fflush(stderr);
    pcVar41 = (code *)fork();
    if (pcVar41 == (code *)0x0) {
      close(local_17d8.P[0]);
      close(1);
      iVar18 = dup(local_17d8.P[1]);
      if (iVar18 == -1) {
        fwrite("dup failed\n",1,0xb,stderr);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      close(local_17d8.P[1]);
      mr = 1;
      usertime = (code *)0x0;
      free(__ptr);
      goto LAB_08071a15;
    }
    close(local_17d8.P[1]);
    *(uint *)((int)__ptr + iVar18 * 4) = local_17d8.P[0];
    iVar10 = iVar18 + 1;
    __printf_chk(1,"Forked child %d\n",iVar18);
    iVar18 = iVar10;
  } while (iVar10 < local_28b8);
  iVar17 = 0;
  do {
    pFVar14 = fdopen(*(int *)((int)__ptr + iVar17 * 4),"r");
LAB_08076958:
    pcVar6 = (char *)0x400;
    dVar44 = (double)ZEXT48(pFVar14);
    pcVar7 = fgets((char *)local_420,0x400,pFVar14);
    if (pcVar7 != (char *)0x0) {
      pcVar6 = strchr((char *)local_420,10);
      if (pcVar6 != (char *)0x0) {
        *pcVar6 = '\0';
      }
      uVar33 = local_420[0] < 0x2b;
      uVar37 = local_420[0] == 0x2b;
      if ((bool)uVar37) {
        __printf_chk(1,"Got: %s from %d\n",local_420);
        iVar18 = 3;
        pbVar24 = local_420;
        pbVar20 = &DAT_081f6b42;
        do {
          if (iVar18 == 0) break;
          iVar18 = iVar18 + -1;
          uVar33 = *pbVar24 < *pbVar20;
          uVar37 = *pbVar24 == *pbVar20;
          pbVar24 = pbVar24 + (uint)bVar38 * -2 + 1;
          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
        } while ((bool)uVar37);
        bVar34 = false;
        bVar32 = (!(bool)uVar33 && !(bool)uVar37) == (bool)uVar33;
        if (bVar32) {
          uVar3 = (uint)local_420[3];
          if (local_420[3] == 0) {
            pbVar24 = local_420 + 3;
            pbVar20 = (byte *)0x0;
          }
          else {
            puVar30 = &local_520;
            for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
              *puVar30 = 0;
              puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar19 = &sep_19190;
            bVar1 = (byte)sep_19190;
            while (bVar1 != 0) {
              puVar19 = (undefined2 *)((int)puVar19 + 1);
              *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
              bVar1 = *(byte *)puVar19;
            }
            pbVar24 = local_420 + 3;
            if (*(char *)((int)&local_520 + uVar3) == '\0') {
              do {
                pbVar24 = pbVar24 + 1;
              } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
              pbVar20 = local_420 + 3;
              if (*pbVar24 == 0) goto LAB_08076be0;
            }
            pbVar20 = local_420 + 3;
            *pbVar24 = 0;
            pbVar24 = pbVar24 + 1;
          }
LAB_08076be0:
          lVar15 = strtol((char *)pbVar20,(char **)0x0,10);
          uVar3 = (uint)*pbVar24;
          if (*pbVar24 != 0) {
            puVar30 = &local_520;
            for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
              *puVar30 = 0;
              puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar19 = &sep_19190;
            bVar1 = (byte)sep_19190;
            while (bVar1 != 0) {
              puVar19 = (undefined2 *)((int)puVar19 + 1);
              *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
              bVar1 = *(byte *)puVar19;
            }
            if (*(char *)((int)&local_520 + uVar3) == '\0') {
              do {
                pbVar24 = pbVar24 + 1;
                uVar3 = (uint)*pbVar24;
              } while (*(char *)((int)&local_520 + uVar3) == '\0');
              if (*pbVar24 == 0) goto LAB_08076c60;
            }
            *pbVar24 = 0;
            uVar3 = (uint)pbVar24[1];
            pbVar24 = pbVar24 + 1;
          }
LAB_08076c60:
          pdVar27 = (double *)(results + lVar15 * 0x28);
          do {
            pbVar20 = (byte *)0x0;
            if ((char)uVar3 != '\0') {
              puVar30 = &local_520;
              for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                *puVar30 = 0;
                puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar19 = &sep_19190;
              bVar1 = (byte)sep_19190;
              while (bVar1 != 0) {
                puVar19 = (undefined2 *)((int)puVar19 + 1);
                *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
                bVar1 = *(byte *)puVar19;
              }
              pbVar20 = pbVar24;
              if (*(char *)((int)&local_520 + uVar3) == '\0') {
                do {
                  pbVar24 = pbVar24 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                if (*pbVar24 == 0) goto LAB_08076d04;
              }
              *pbVar24 = 0;
              pbVar24 = pbVar24 + 1;
            }
LAB_08076d04:
            dVar40 = strtod((char *)pbVar20,(char **)0x0);
            *pdVar27 = dVar40 + *pdVar27;
            if (pdVar27 + 1 == (double *)(results + lVar15 * 0x28 + 0x28)) goto LAB_08076958;
            uVar3 = (uint)*pbVar24;
            pdVar27 = pdVar27 + 1;
          } while( true );
        }
        iVar18 = 4;
        pbVar24 = local_420;
        pbVar20 = &DAT_081f6b46;
        do {
          if (iVar18 == 0) break;
          iVar18 = iVar18 + -1;
          bVar34 = *pbVar24 < *pbVar20;
          bVar32 = *pbVar24 == *pbVar20;
          pbVar24 = pbVar24 + (uint)bVar38 * -2 + 1;
          pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
        } while (bVar32);
        bVar36 = false;
        bVar34 = (!bVar34 && !bVar32) == bVar34;
        if (bVar34) {
          uVar3 = (uint)local_41c[0];
          if (local_41c[0] == 0) {
            pbVar24 = local_41c;
            pbVar20 = (byte *)0x0;
          }
          else {
            puVar30 = &local_520;
            for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
              *puVar30 = 0;
              puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar19 = &sep_19190;
            bVar1 = (byte)sep_19190;
            while (bVar1 != 0) {
              puVar19 = (undefined2 *)((int)puVar19 + 1);
              *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
              bVar1 = *(byte *)puVar19;
            }
            pbVar24 = local_41c;
            if (*(char *)((int)&local_520 + uVar3) == '\0') {
              do {
                pbVar24 = pbVar24 + 1;
              } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
              pbVar20 = local_41c;
              if (*pbVar24 == 0) goto LAB_08076dd0;
            }
            pbVar20 = local_41c;
            *pbVar24 = 0;
            pbVar24 = pbVar24 + 1;
          }
LAB_08076dd0:
          lVar15 = strtol((char *)pbVar20,(char **)0x0,10);
          bVar1 = *pbVar24;
          if (bVar1 == 0) {
LAB_080772c5:
            pbVar20 = (byte *)0x0;
          }
          else {
            uVar3 = (uint)(byte)sep_19190;
            puVar30 = &local_520;
            for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
              *puVar30 = 0;
              puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar19 = &sep_19190;
            uVar16 = uVar3;
            bVar2 = (byte)sep_19190;
            while (bVar2 != 0) {
              puVar19 = (undefined2 *)((int)puVar19 + 1);
              *(undefined *)((int)&local_520 + uVar16) = 1;
              bVar2 = *(byte *)puVar19;
              uVar16 = (uint)bVar2;
            }
            if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
              do {
                pbVar24 = pbVar24 + 1;
              } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
              if (*pbVar24 == 0) goto LAB_080772c5;
            }
            *pbVar24 = 0;
            pbVar20 = pbVar24 + 1;
            bVar1 = pbVar24[1];
            pbVar24 = pbVar20;
            if (bVar1 == 0) goto LAB_080772c5;
            puVar30 = &local_520;
            for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
              *puVar30 = 0;
              puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar19 = &sep_19190;
            bVar2 = (byte)sep_19190;
            while (bVar2 != 0) {
              puVar19 = (undefined2 *)((int)puVar19 + 1);
              *(undefined *)((int)&local_520 + uVar3) = 1;
              bVar2 = *(byte *)puVar19;
              uVar3 = (uint)bVar2;
            }
            if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
              do {
                pbVar24 = pbVar24 + 1;
              } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
              if (*pbVar24 != 0) goto LAB_08076f0e;
            }
            else {
LAB_08076f0e:
              *pbVar24 = 0;
              pbVar24 = pbVar24 + 1;
            }
          }
          dVar40 = strtod((char *)pbVar20,(char **)0x0);
          iVar18 = lVar15 * 0x10;
          if (iVar17 == 0) {
            bVar1 = *pbVar24;
            *(double *)(rsa_results + iVar18) = dVar40;
            if (bVar1 != 0) goto LAB_08076f5e;
            dVar40 = strtod((char *)0x0,(char **)0x0);
LAB_08077d3c:
            *(double *)(rsa_results + lVar15 * 0x10 + 8) = dVar40;
          }
          else {
            bVar1 = *pbVar24;
            *(double *)(rsa_results + iVar18) =
                 1.0 / (1.0 / dVar40 + 1.0 / *(double *)(rsa_results + iVar18));
            if (bVar1 == 0) {
              dVar40 = strtod((char *)0x0,(char **)0x0);
            }
            else {
LAB_08076f5e:
              puVar30 = &local_520;
              for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                *puVar30 = 0;
                puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar19 = &sep_19190;
              bVar2 = (byte)sep_19190;
              while (bVar2 != 0) {
                puVar19 = (undefined2 *)((int)puVar19 + 1);
                *(undefined *)((int)&local_520 + (uint)bVar2) = 1;
                bVar2 = *(byte *)puVar19;
              }
              pbVar20 = pbVar24;
              if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                do {
                  pbVar20 = pbVar20 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar20) == '\0');
                if (*pbVar20 != 0) goto LAB_08076fdc;
              }
              else {
LAB_08076fdc:
                *pbVar20 = 0;
              }
              dVar40 = strtod((char *)pbVar24,(char **)0x0);
              if (iVar17 == 0) goto LAB_08077d3c;
            }
            *(double *)(rsa_results + lVar15 * 0x10 + 8) =
                 1.0 / (1.0 / dVar40 + 1.0 / *(double *)(rsa_results + lVar15 * 0x10 + 8));
          }
        }
        else {
          iVar18 = 4;
          pbVar24 = local_420;
          pbVar20 = &DAT_081f6b4b;
          do {
            if (iVar18 == 0) break;
            iVar18 = iVar18 + -1;
            bVar36 = *pbVar24 < *pbVar20;
            bVar34 = *pbVar24 == *pbVar20;
            pbVar24 = pbVar24 + (uint)bVar38 * -2 + 1;
            pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
          } while (bVar34);
          bVar32 = false;
          bVar34 = (!bVar36 && !bVar34) == bVar36;
          if (bVar34) {
            uVar3 = (uint)local_41c[0];
            if (local_41c[0] == 0) {
              pbVar24 = local_41c;
              pbVar20 = (byte *)0x0;
            }
            else {
              puVar30 = &local_520;
              for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                *puVar30 = 0;
                puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar19 = &sep_19190;
              bVar1 = (byte)sep_19190;
              while (bVar1 != 0) {
                puVar19 = (undefined2 *)((int)puVar19 + 1);
                *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
                bVar1 = *(byte *)puVar19;
              }
              pbVar24 = local_41c;
              if (*(char *)((int)&local_520 + uVar3) == '\0') {
                do {
                  pbVar24 = pbVar24 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                pbVar20 = local_41c;
                if (*pbVar24 == 0) goto LAB_080770a8;
              }
              pbVar20 = local_41c;
              *pbVar24 = 0;
              pbVar24 = pbVar24 + 1;
            }
LAB_080770a8:
            lVar15 = strtol((char *)pbVar20,(char **)0x0,10);
            bVar1 = *pbVar24;
            if (bVar1 == 0) {
LAB_08077579:
              pbVar20 = (byte *)0x0;
            }
            else {
              uVar3 = (uint)(byte)sep_19190;
              puVar30 = &local_520;
              for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                *puVar30 = 0;
                puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar19 = &sep_19190;
              uVar16 = uVar3;
              bVar2 = (byte)sep_19190;
              while (bVar2 != 0) {
                puVar19 = (undefined2 *)((int)puVar19 + 1);
                *(undefined *)((int)&local_520 + uVar16) = 1;
                bVar2 = *(byte *)puVar19;
                uVar16 = (uint)bVar2;
              }
              if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                do {
                  pbVar24 = pbVar24 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                if (*pbVar24 == 0) goto LAB_08077579;
              }
              pbVar20 = pbVar24 + 1;
              *pbVar24 = 0;
              bVar1 = pbVar24[1];
              pbVar24 = pbVar20;
              if (bVar1 == 0) goto LAB_08077579;
              puVar30 = &local_520;
              for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                *puVar30 = 0;
                puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar19 = &sep_19190;
              bVar2 = (byte)sep_19190;
              while (bVar2 != 0) {
                puVar19 = (undefined2 *)((int)puVar19 + 1);
                *(undefined *)((int)&local_520 + uVar3) = 1;
                bVar2 = *(byte *)puVar19;
                uVar3 = (uint)bVar2;
              }
              if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                do {
                  pbVar24 = pbVar24 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                if (*pbVar24 != 0) goto LAB_080771d6;
              }
              else {
LAB_080771d6:
                *pbVar24 = 0;
                pbVar24 = pbVar24 + 1;
              }
            }
            dVar40 = strtod((char *)pbVar20,(char **)0x0);
            iVar18 = lVar15 * 0x10;
            if (iVar17 == 0) {
              bVar1 = *pbVar24;
              *(double *)(dsa_results + iVar18) = dVar40;
              if (bVar1 != 0) goto LAB_08077220;
              dVar40 = strtod((char *)0x0,(char **)0x0);
LAB_08077c91:
              *(double *)(dsa_results + lVar15 * 0x10 + 8) = dVar40;
            }
            else {
              bVar1 = *pbVar24;
              *(double *)(dsa_results + iVar18) =
                   1.0 / (1.0 / dVar40 + 1.0 / *(double *)(dsa_results + iVar18));
              if (bVar1 == 0) {
                dVar40 = strtod((char *)0x0,(char **)0x0);
              }
              else {
LAB_08077220:
                puVar30 = &local_520;
                for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                  *puVar30 = 0;
                  puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
                }
                local_520._0_1_ = 1;
                puVar19 = &sep_19190;
                bVar2 = (byte)sep_19190;
                while (bVar2 != 0) {
                  puVar19 = (undefined2 *)((int)puVar19 + 1);
                  *(undefined *)((int)&local_520 + (uint)bVar2) = 1;
                  bVar2 = *(byte *)puVar19;
                }
                pbVar20 = pbVar24;
                if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                  do {
                    pbVar20 = pbVar20 + 1;
                  } while (*(char *)((int)&local_520 + (uint)*pbVar20) == '\0');
                  if (*pbVar20 != 0) goto LAB_08077284;
                }
                else {
LAB_08077284:
                  *pbVar20 = 0;
                }
                dVar40 = strtod((char *)pbVar24,(char **)0x0);
                if (iVar17 == 0) goto LAB_08077c91;
              }
              *(double *)(dsa_results + lVar15 * 0x10 + 8) =
                   1.0 / (1.0 / dVar40 + 1.0 / *(double *)(dsa_results + lVar15 * 0x10 + 8));
            }
          }
          else {
            iVar18 = 4;
            pbVar24 = local_420;
            pbVar20 = &DAT_081f6b50;
            do {
              if (iVar18 == 0) break;
              iVar18 = iVar18 + -1;
              bVar32 = *pbVar24 < *pbVar20;
              bVar34 = *pbVar24 == *pbVar20;
              pbVar24 = pbVar24 + (uint)bVar38 * -2 + 1;
              pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
            } while (bVar34);
            bVar36 = false;
            bVar34 = (!bVar32 && !bVar34) == bVar32;
            if (bVar34) {
              uVar3 = (uint)local_41c[0];
              if (local_41c[0] == 0) {
                pbVar24 = local_41c;
                pbVar20 = (byte *)0x0;
              }
              else {
                puVar30 = &local_520;
                for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                  *puVar30 = 0;
                  puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
                }
                local_520._0_1_ = 1;
                puVar19 = &sep_19190;
                bVar1 = (byte)sep_19190;
                while (bVar1 != 0) {
                  puVar19 = (undefined2 *)((int)puVar19 + 1);
                  *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
                  bVar1 = *(byte *)puVar19;
                }
                pbVar24 = local_41c;
                if (*(char *)((int)&local_520 + uVar3) == '\0') {
                  do {
                    pbVar24 = pbVar24 + 1;
                  } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                  pbVar20 = local_41c;
                  if (*pbVar24 == 0) goto LAB_08077350;
                }
                pbVar20 = local_41c;
                *pbVar24 = 0;
                pbVar24 = pbVar24 + 1;
              }
LAB_08077350:
              lVar15 = strtol((char *)pbVar20,(char **)0x0,10);
              bVar1 = *pbVar24;
              if (bVar1 == 0) {
LAB_0807777f:
                pbVar20 = (byte *)0x0;
              }
              else {
                uVar3 = (uint)(byte)sep_19190;
                puVar30 = &local_520;
                for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                  *puVar30 = 0;
                  puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
                }
                local_520._0_1_ = 1;
                puVar19 = &sep_19190;
                uVar16 = uVar3;
                bVar2 = (byte)sep_19190;
                while (bVar2 != 0) {
                  puVar19 = (undefined2 *)((int)puVar19 + 1);
                  *(undefined *)((int)&local_520 + uVar16) = 1;
                  bVar2 = *(byte *)puVar19;
                  uVar16 = (uint)bVar2;
                }
                if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                  do {
                    pbVar24 = pbVar24 + 1;
                  } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                  if (*pbVar24 == 0) goto LAB_0807777f;
                }
                pbVar20 = pbVar24 + 1;
                *pbVar24 = 0;
                bVar1 = pbVar24[1];
                pbVar24 = pbVar20;
                if (bVar1 == 0) goto LAB_0807777f;
                puVar30 = &local_520;
                for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                  *puVar30 = 0;
                  puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
                }
                local_520._0_1_ = 1;
                puVar19 = &sep_19190;
                bVar2 = (byte)sep_19190;
                while (bVar2 != 0) {
                  puVar19 = (undefined2 *)((int)puVar19 + 1);
                  *(undefined *)((int)&local_520 + uVar3) = 1;
                  bVar2 = *(byte *)puVar19;
                  uVar3 = (uint)bVar2;
                }
                if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                  do {
                    pbVar24 = pbVar24 + 1;
                  } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                  if (*pbVar24 != 0) goto LAB_08077486;
                }
                else {
LAB_08077486:
                  *pbVar24 = 0;
                  pbVar24 = pbVar24 + 1;
                }
              }
              dVar40 = strtod((char *)pbVar20,(char **)0x0);
              iVar18 = lVar15 * 0x10;
              if (iVar17 == 0) {
                bVar1 = *pbVar24;
                *(double *)(ecdsa_results + iVar18) = dVar40;
                if (bVar1 != 0) goto LAB_080774d0;
                dVar40 = strtod((char *)0x0,(char **)0x0);
LAB_08077d0e:
                *(double *)(ecdsa_results + lVar15 * 0x10 + 8) = dVar40;
              }
              else {
                bVar1 = *pbVar24;
                *(double *)(ecdsa_results + iVar18) =
                     1.0 / (1.0 / dVar40 + 1.0 / *(double *)(ecdsa_results + iVar18));
                if (bVar1 == 0) {
                  dVar40 = strtod((char *)0x0,(char **)0x0);
                }
                else {
LAB_080774d0:
                  puVar30 = &local_520;
                  for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                    *puVar30 = 0;
                    puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
                  }
                  local_520._0_1_ = 1;
                  puVar19 = &sep_19190;
                  bVar2 = (byte)sep_19190;
                  while (bVar2 != 0) {
                    puVar19 = (undefined2 *)((int)puVar19 + 1);
                    *(undefined *)((int)&local_520 + (uint)bVar2) = 1;
                    bVar2 = *(byte *)puVar19;
                  }
                  pbVar20 = pbVar24;
                  if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                    do {
                      pbVar20 = pbVar20 + 1;
                    } while (*(char *)((int)&local_520 + (uint)*pbVar20) == '\0');
                    if (*pbVar20 != 0) goto LAB_08077534;
                  }
                  else {
LAB_08077534:
                    *pbVar20 = 0;
                  }
                  dVar40 = strtod((char *)pbVar24,(char **)0x0);
                  if (iVar17 == 0) goto LAB_08077d0e;
                }
                *(double *)(ecdsa_results + lVar15 * 0x10 + 8) =
                     1.0 / (1.0 / dVar40 + 1.0 / *(double *)(ecdsa_results + lVar15 * 0x10 + 8));
              }
            }
            else {
              iVar18 = 4;
              pbVar24 = local_420;
              pbVar20 = &DAT_081f6b55;
              do {
                if (iVar18 == 0) break;
                iVar18 = iVar18 + -1;
                bVar36 = *pbVar24 < *pbVar20;
                bVar34 = *pbVar24 == *pbVar20;
                pbVar24 = pbVar24 + (uint)bVar38 * -2 + 1;
                pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
              } while (bVar34);
              bVar34 = (!bVar36 && !bVar34) == bVar36;
              if (bVar34) {
                uVar3 = (uint)local_41c[0];
                if (local_41c[0] == 0) {
                  pbVar24 = local_41c;
                  pbVar20 = (byte *)0x0;
                }
                else {
                  puVar30 = &local_520;
                  for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                    *puVar30 = 0;
                    puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
                  }
                  local_520._0_1_ = 1;
                  puVar19 = &sep_19190;
                  bVar1 = (byte)sep_19190;
                  while (bVar1 != 0) {
                    puVar19 = (undefined2 *)((int)puVar19 + 1);
                    *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
                    bVar1 = *(byte *)puVar19;
                  }
                  pbVar24 = local_41c;
                  if (*(char *)((int)&local_520 + uVar3) == '\0') {
                    do {
                      pbVar24 = pbVar24 + 1;
                    } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                    pbVar20 = local_41c;
                    if (*pbVar24 == 0) goto LAB_08077608;
                  }
                  pbVar20 = local_41c;
                  *pbVar24 = 0;
                  pbVar24 = pbVar24 + 1;
                }
LAB_08077608:
                lVar15 = strtol((char *)pbVar20,(char **)0x0,10);
                bVar1 = *pbVar24;
                if (bVar1 == 0) {
LAB_080777a7:
                  pbVar20 = (byte *)0x0;
                }
                else {
                  uVar3 = (uint)(byte)sep_19190;
                  puVar30 = &local_520;
                  for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                    *puVar30 = 0;
                    puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
                  }
                  local_520._0_1_ = 1;
                  puVar19 = &sep_19190;
                  uVar16 = uVar3;
                  bVar2 = (byte)sep_19190;
                  while (bVar2 != 0) {
                    puVar19 = (undefined2 *)((int)puVar19 + 1);
                    *(undefined *)((int)&local_520 + uVar16) = 1;
                    bVar2 = *(byte *)puVar19;
                    uVar16 = (uint)bVar2;
                  }
                  if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                    do {
                      pbVar24 = pbVar24 + 1;
                    } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                    if (*pbVar24 == 0) goto LAB_080777a7;
                  }
                  pbVar20 = pbVar24 + 1;
                  *pbVar24 = 0;
                  bVar1 = pbVar24[1];
                  if (bVar1 == 0) goto LAB_080777a7;
                  puVar30 = &local_520;
                  for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
                    *puVar30 = 0;
                    puVar30 = puVar30 + (uint)bVar38 * -2 + 1;
                  }
                  local_520._0_1_ = 1;
                  puVar19 = &sep_19190;
                  bVar2 = (byte)sep_19190;
                  while (bVar2 != 0) {
                    puVar19 = (undefined2 *)((int)puVar19 + 1);
                    *(undefined *)((int)&local_520 + uVar3) = 1;
                    bVar2 = *(byte *)puVar19;
                    uVar3 = (uint)bVar2;
                  }
                  pbVar24 = pbVar20;
                  if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                    do {
                      pbVar24 = pbVar24 + 1;
                    } while (*(char *)((int)&local_520 + (uint)*pbVar24) == '\0');
                    if (*pbVar24 != 0) goto LAB_0807772e;
                  }
                  else {
LAB_0807772e:
                    *pbVar24 = 0;
                  }
                }
                dVar40 = strtod((char *)pbVar20,(char **)0x0);
                if (iVar17 == 0) {
                  *(double *)(ecdh_results + lVar15 * 8) = dVar40;
                }
                else {
                  *(double *)(ecdh_results + lVar15 * 8) =
                       1.0 / (1.0 / dVar40 + 1.0 / *(double *)(ecdh_results + lVar15 * 8));
                }
              }
              else {
                iVar18 = 3;
                pbVar24 = local_420;
                pbVar20 = &DAT_081f6b5a;
                do {
                  if (iVar18 == 0) break;
                  iVar18 = iVar18 + -1;
                  bVar34 = *pbVar24 == *pbVar20;
                  pbVar24 = pbVar24 + (uint)bVar38 * -2 + 1;
                  pbVar20 = pbVar20 + (uint)bVar38 * -2 + 1;
                } while (bVar34);
                if (!bVar34) {
                  __fprintf_chk(stderr,1,"Unknown type \'%s\' from child %d\n",local_420,iVar17);
                }
              }
            }
          }
        }
      }
      else {
        __fprintf_chk(stderr,1,"Don\'t understand line \'%s\' from child %d\n",local_420,iVar17);
      }
      goto LAB_08076958;
    }
    fclose(pFVar14);
    iVar17 = iVar17 + 1;
  } while (iVar17 < local_28b8);
  free(__ptr);
  if (mr == 0) {
    local_28e8 = 0;
    goto LAB_080761b7;
  }
  goto LAB_08075396;
LAB_08076657:
  HMAC_CTX_cleanup(&local_23f4);
  fVar39 = (float10)(double)fVar39;
LAB_08072346:
  if (local_26f0[5] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 200);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._20_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        uVar42 = CONCAT44(0x80723fd,(int)uVar42);
        pEVar8 = EVP_sha1();
        iVar17 = iVar17 + 1;
        EVP_Digest(data,sVar23,local_748,(uint *)0x0,pEVar8,(ENGINE *)0x0);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._20_4_,SUB84((double)fVar39,0),pcVar6);
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[23] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x398);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._92_4_,3,sVar23,pcVar6);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        uVar42 = ZEXT48(local_720);
        SHA256(data,sVar23,local_720);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._92_4_,SUB84((double)fVar39,0),pcVar6);
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[24] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x3c0);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._96_4_,3,sVar23,pcVar6);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        uVar42 = ZEXT48(local_6a0);
        SHA512(data,sVar23,local_6a0);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._96_4_,SUB84((double)fVar39,0),pcVar6);
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[25] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 1000);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._100_4_,3,sVar23,pcVar6);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        uVar42 = ZEXT48(local_660);
        WHIRLPOOL(data,sVar23,local_660);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._100_4_,SUB84((double)fVar39,0),pcVar6);
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[6] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0xf0);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._24_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        uVar42 = CONCAT44(0x80729ad,(int)uVar42);
        pEVar8 = EVP_ripemd160();
        iVar17 = iVar17 + 1;
        EVP_Digest(data,sVar23,local_734,(uint *)0x0,pEVar8,(ENGINE *)0x0);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._24_4_,SUB84((double)fVar39,0),pcVar6);
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[7] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x118);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._28_4_,3,sVar23,pcVar6);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        uVar42 = CONCAT44(data,data);
        RC4((RC4_KEY *)local_1e6e,sVar23,data,data);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._28_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[8] != 0) {
    local_28ac = (undefined1 *)0x0;
    do {
      lVar15 = *(long *)(lengths + (int)local_28ac);
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._32_4_,3,lVar15,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        DES_ncbc_encrypt(data,data,lVar15,&local_25f8,(DES_cblock *)&local_790,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._32_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *(double *)(results + (int)local_28ac * 2 + 0x140) =
           (double)((float10)lVar15 * ((float10)iVar17 / fVar39));
      local_28ac = (undefined1 *)((int)local_28ac + 4);
    } while (local_28ac != (undefined1 *)0x14);
  }
  if (local_26f0[9] != 0) {
    local_28ac = (undefined1 *)0x0;
    do {
      lVar15 = *(long *)(lengths + (int)local_28ac);
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._36_4_,3,lVar15,pcVar6);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        uVar42 = CONCAT44(1,(DES_cblock *)&local_790);
        iVar17 = iVar17 + 1;
        DES_ede3_cbc_encrypt
                  (data,data,lVar15,&local_25f8,&local_2578,&local_24f8,(DES_cblock *)&local_790,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._36_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *(double *)(results + (int)local_28ac * 2 + 0x168) =
           (double)((float10)lVar15 * ((float10)iVar17 / fVar39));
      local_28ac = (undefined1 *)((int)local_28ac + 4);
    } while (local_28ac != (undefined1 *)0x14);
  }
  if (local_26f0[16] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x280);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._64_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        AES_cbc_encrypt(data,data,sVar23,&local_224c,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._64_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[17] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x2a8);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._68_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        AES_cbc_encrypt(data,data,sVar23,&local_2158,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._68_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[18] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x2d0);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._72_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        AES_cbc_encrypt(data,data,sVar23,&local_2064,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._72_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[26] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x410);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._104_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        AES_ige_encrypt(data,out,sVar23,&local_224c,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._104_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[27] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x438);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._108_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        AES_ige_encrypt(data,out,sVar23,&local_2158,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._108_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[28] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x460);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._112_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        AES_ige_encrypt(data,out,sVar23,&local_2064,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._112_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[29] != 0) {
    uVar3 = 0x10;
    uVar21 = CRYPTO_gcm128_new(&local_224c,AES_encrypt);
    pcVar6 = "0123456789ab";
    CRYPTO_gcm128_setiv(uVar21,"0123456789ab",0xc);
    local_28ac = lengths;
    pdVar27 = (double *)(results + 0x488);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._116_4_,3,uVar3,pcVar6);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        uVar42 = (ulonglong)uVar3;
        CRYPTO_gcm128_aad(uVar21,data,uVar3);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._116_4_,SUB84((double)fVar39,0),pcVar6);
      local_28ac = (undefined1 *)((int)local_28ac + 4);
      *pdVar27 = (double)uVar3 * ((double)iVar17 / (double)fVar39);
      if (local_28ac == &DAT_081f76dc) goto LAB_0807663a;
      uVar3 = *(uint *)local_28ac;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  goto LAB_08073742;
LAB_0807663a:
  CRYPTO_gcm128_release(uVar21);
  fVar39 = (float10)(double)fVar39;
LAB_08073742:
  if (local_26f0[19] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x2f8);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._76_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        Camellia_cbc_encrypt
                  (data,data,sVar23,(CAMELLIA_KEY *)(local_1e6e + 0x102),(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._76_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[20] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 800);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._80_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        Camellia_cbc_encrypt(data,data,sVar23,&local_1c58,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._80_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[21] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x348);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._84_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        Camellia_cbc_encrypt(data,data,sVar23,&local_1b44,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._84_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[10] != 0) {
    iVar18 = 0;
    do {
      lVar15 = *(long *)(lengths + iVar18);
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._40_4_,3,lVar15,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        idea_cbc_encrypt(data,data,lVar15,&local_2324,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._40_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *(double *)(results + iVar18 * 2 + 400) =
           (double)((float10)lVar15 * ((float10)iVar17 / fVar39));
      iVar18 = iVar18 + 4;
    } while (iVar18 != 0x14);
  }
  if (local_26f0[11] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x1b8);
    do {
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._44_4_,3,sVar23,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        SEED_cbc_encrypt(data,data,sVar23,
                         (SEED_KEY_SCHEDULE *)((int)((SEED_KEY_SCHEDULE *)local_26f0)->data + 0x78),
                         (uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      BIO_printf(bio_err,pcVar7,iVar17,names._44_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  if (local_26f0[12] != 0) {
    iVar18 = 0;
    do {
      lVar15 = *(long *)(lengths + iVar18);
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._48_4_,3,lVar15,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        RC2_cbc_encrypt(data,data,lVar15,&local_1f70,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._48_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *(double *)(results + iVar18 * 2 + 0x1e0) =
           (double)((float10)lVar15 * ((float10)iVar17 / fVar39));
      iVar18 = iVar18 + 4;
    } while (iVar18 != 0x14);
  }
  if (local_26f0[14] != 0) {
    local_28ac = (undefined1 *)0x0;
    do {
      lVar15 = *(long *)(lengths + (int)local_28ac);
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._56_4_,3,lVar15,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        BF_cbc_encrypt(data,data,lVar15,&local_17d8,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._56_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *(double *)(results + (int)local_28ac * 2 + 0x230) =
           (double)((float10)lVar15 * ((float10)iVar17 / fVar39));
      local_28ac = (undefined1 *)((int)local_28ac + 4);
    } while (local_28ac != (undefined1 *)0x14);
  }
  if (local_26f0[15] != 0) {
    iVar18 = 0;
    do {
      lVar15 = *(long *)(lengths + iVar18);
      pcVar7 = "Doing %s for %ds on %d size blocks: ";
      if (mr != 0) {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar17 = 0;
      BIO_printf(bio_err,pcVar7,names._60_4_,3,lVar15,pcVar6);
      uVar42 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar17 = iVar17 + 1;
        CAST_cbc_encrypt(data,data,lVar15,&local_2478,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar17 != 0x7fffffff);
      fVar39 = (float10)app_tminterval(1,usertime);
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar17,names._60_4_,SUB84((double)fVar39,0),pcVar6);
      fVar39 = (float10)(double)fVar39;
      *(double *)(results + iVar18 * 2 + 600) =
           (double)((float10)lVar15 * ((float10)iVar17 / fVar39));
      iVar18 = iVar18 + 4;
    } while (iVar18 != 0x14);
  }
  if (local_26f0[22] != 0) {
    puVar26 = lengths;
    sVar23 = 0x10;
    pdVar27 = (double *)(results + 0x370);
    do {
      if (cipher != (EVP_CIPHER *)0x0) {
        names._88_4_ = OBJ_nid2ln(cipher->nid);
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
        if (mr != 0) {
          pcVar7 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar7,names._88_4_,3,sVar23,pcVar6);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)&local_23f4);
        if (bVar34) {
          EVP_DecryptInit_ex((EVP_CIPHER_CTX *)&local_23f4,cipher,(ENGINE *)0x0,key16_17953,
                             (uchar *)local_700);
          EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)&local_23f4,0);
          iVar17 = 0;
          app_tminterval(0,usertime);
          run = 1;
          do {
            iVar17 = iVar17 + 1;
            EVP_DecryptUpdate((EVP_CIPHER_CTX *)&local_23f4,data,(int *)&local_288c,data,sVar23);
            if (run == 0) break;
          } while (iVar17 != 0x7fffffff);
          uVar42 = ZEXT48(&local_288c);
          EVP_DecryptFinal_ex((EVP_CIPHER_CTX *)&local_23f4,data,(int *)&local_288c);
        }
        else {
          iVar17 = 0;
          EVP_EncryptInit_ex((EVP_CIPHER_CTX *)&local_23f4,cipher,(ENGINE *)0x0,key16_17953,
                             (uchar *)local_700);
          EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)&local_23f4,0);
          app_tminterval(0,usertime);
          run = 1;
          do {
            iVar17 = iVar17 + 1;
            EVP_EncryptUpdate((EVP_CIPHER_CTX *)&local_23f4,data,(int *)&local_288c,data,sVar23);
            if (run == 0) break;
          } while (iVar17 != 0x7fffffff);
          uVar42 = ZEXT48(&local_288c);
          EVP_EncryptFinal_ex((EVP_CIPHER_CTX *)&local_23f4,data,(int *)&local_288c);
        }
        pcVar6 = (char *)usertime;
        fVar39 = (float10)app_tminterval(1,usertime);
        EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)&local_23f4);
        fVar39 = (float10)(double)fVar39;
      }
      if (type_00 != (EVP_MD *)0x0) {
        names._88_4_ = OBJ_nid2ln(type_00->type);
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
        if (mr != 0) {
          pcVar7 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar7,names._88_4_,3,sVar23,pcVar6);
        uVar42 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        iVar17 = 0;
        app_tminterval(0,usertime);
        run = 1;
        do {
          iVar17 = iVar17 + 1;
          EVP_Digest(data,sVar23,local_6e0,(uint *)0x0,type_00,(ENGINE *)0x0);
          if (run == 0) break;
        } while (iVar17 != 0x7fffffff);
        fVar39 = (float10)app_tminterval(1,usertime);
      }
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      pcVar6 = (char *)((ulonglong)(double)fVar39 >> 0x20);
      BIO_printf(bio_err,pcVar7,iVar17,names._88_4_,SUB84((double)fVar39,0),pcVar6);
      puVar26 = (undefined1 *)((int)puVar26 + 4);
      fVar39 = (float10)(double)fVar39;
      *pdVar27 = (double)((float10)sVar23 * ((float10)iVar17 / fVar39));
      if (puVar26 == &DAT_081f76dc) break;
      sVar23 = *(size_t *)puVar26;
      pdVar27 = pdVar27 + 1;
    } while( true );
  }
  RAND_pseudo_bytes(data,0x24);
  local_28a4._0_4_ = 0;
  do {
    iVar17 = local_28a4._0_4_;
    if ((&local_2860)[local_28a4._0_4_] != (RSA *)0x0) {
      pRVar5 = local_2870[local_28a4._0_4_];
      iVar18 = RSA_sign(0x72,data,0x24,out,&local_2890,pRVar5);
      if (iVar18 == 0) {
        BIO_printf(bio_err,"RSA sign failure.  No RSA sign will be done.\n");
        ERR_print_errors(bio_err);
        local_28b4 = (code *)0x1;
      }
      else {
        uVar21 = *(undefined4 *)(rsa_bits_17976 + local_28a4._0_4_ * 4);
        pcVar6 = "Doing %d bit %s %s\'s for %ds: ";
        if (mr != 0) {
          pcVar6 = "+DTP:%d:%s:%s:%d\n";
        }
        BIO_printf(bio_err,pcVar6,uVar21,"private","rsa",10);
        uVar42 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(10);
        app_tminterval(0,usertime);
        run = 1;
        local_28b4 = (code *)0x0;
        while (iVar18 = RSA_sign(0x72,data,0x24,out,&local_2890,pRVar5), iVar18 != 0) {
          local_28b4 = (code *)((int)local_28b4 + 1);
          if ((run == 0) || (local_28b4 == (code *)0x7fffffff)) goto LAB_080748b0;
        }
        BIO_printf(bio_err,"RSA sign failure\n");
        ERR_print_errors(bio_err);
        local_28b4 = (code *)0x1;
LAB_080748b0:
        fVar39 = (float10)app_tminterval(1,usertime);
        pcVar6 = "%ld %d bit private RSA\'s in %.2fs\n";
        if (mr != 0) {
          pcVar6 = "+R1:%ld:%d:%.2f\n";
        }
        BIO_printf(bio_err,pcVar6,local_28b4,uVar21,SUB84((double)fVar39,0),
                   (int)((ulonglong)(double)fVar39 >> 0x20));
        *(double *)(rsa_results + local_28a4._0_4_ * 0x10) =
             (double)fVar39 / (double)(int)local_28b4;
      }
      iVar18 = RSA_verify(0x72,data,0x24,out,local_2890,pRVar5);
      if (iVar18 < 1) {
        BIO_printf(bio_err,"RSA verify failure.  No RSA verify will be done.\n");
        ERR_print_errors(bio_err);
        (&local_2860)[local_28a4._0_4_] = (RSA *)0x0;
      }
      else {
        uVar21 = *(undefined4 *)(rsa_bits_17976 + local_28a4._0_4_ * 4);
        pcVar6 = "Doing %d bit %s %s\'s for %ds: ";
        if (mr != 0) {
          pcVar6 = "+DTP:%d:%s:%s:%d\n";
        }
        iVar18 = 0;
        BIO_printf(bio_err,pcVar6,uVar21,"public","rsa",10);
        uVar42 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(10);
        app_tminterval(0,usertime);
        run = 1;
        while (iVar10 = RSA_verify(0x72,data,0x24,out,local_2890,pRVar5), 0 < iVar10) {
          iVar18 = iVar18 + 1;
          if ((run == 0) || (iVar18 == 0x7fffffff)) goto LAB_080746cc;
        }
        iVar18 = 1;
        BIO_printf(bio_err,"RSA verify failure\n");
        ERR_print_errors(bio_err);
LAB_080746cc:
        fVar39 = (float10)app_tminterval(1,usertime);
        pcVar6 = "%ld %d bit public RSA\'s in %.2fs\n";
        if (mr != 0) {
          pcVar6 = "+R2:%ld:%d:%.2f\n";
        }
        BIO_printf(bio_err,pcVar6,iVar18,uVar21,SUB84((double)fVar39,0),
                   (int)((ulonglong)(double)fVar39 >> 0x20));
        *(double *)(rsa_results + local_28a4._0_4_ * 0x10 + 8) = (double)fVar39 / (double)iVar18;
      }
      if ((int)local_28b4 < 2) {
        if (local_28a4._0_4_ + 1 == 4) break;
        (&local_2860)[local_28a4._0_4_ + 1] = (RSA *)0x0;
        iVar17 = local_28a4._0_4_ + 2;
        if (iVar17 < 4) {
          (&local_2860)[iVar17] = (RSA *)0x0;
          iVar17 = local_28a4._0_4_ + 3;
          if (iVar17 == 3) {
            local_2854 = 0;
            iVar17 = local_28a4._0_4_ + 4;
          }
        }
      }
    }
    local_28a4._0_4_ = iVar17 + 1;
  } while (local_28a4._0_4_ < 4);
  uVar3 = 0x14;
  RAND_pseudo_bytes(data,0x14);
  iVar17 = RAND_status();
  if (iVar17 != 1) {
    uVar3 = 0x40;
    RAND_seed("string to make the random number generator think it has entropy",0x40);
    rnd_fake = 1;
  }
  dVar40 = (double)((ulonglong)uVar3 << 0x20);
  iVar17 = 0;
  do {
    if (local_2888[iVar17 + 3] == (DSA *)0x0) {
      iVar18 = iVar17 + 1;
    }
    else {
      dsa = local_2888[iVar17];
      iVar18 = DSA_sign(0x74,data,0x14,out,(uint *)&local_288c,dsa);
      if (iVar18 == 0) {
        BIO_printf(bio_err,"DSA sign failure.  No DSA sign will be done.\n");
        ERR_print_errors(bio_err);
        local_28b4 = (code *)0x1;
      }
      else {
        uVar21 = *(undefined4 *)(dsa_bits_17981 + iVar17 * 4);
        pcVar6 = "Doing %d bit %s %s\'s for %ds: ";
        if (mr != 0) {
          pcVar6 = "+DTP:%d:%s:%s:%d\n";
        }
        BIO_printf(bio_err,pcVar6,uVar21,"sign",&DAT_081f6929,10);
        uVar42 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(10);
        app_tminterval(0,usertime);
        run = 1;
        local_28b4 = (code *)0x0;
        while (iVar18 = DSA_sign(0x74,data,0x14,out,(uint *)&local_288c,dsa), iVar18 != 0) {
          local_28b4 = (code *)((int)local_28b4 + 1);
          if ((run == 0) || (local_28b4 == (code *)0x7fffffff)) goto LAB_08074ca0;
        }
        BIO_printf(bio_err,"DSA sign failure\n");
        ERR_print_errors(bio_err);
        local_28b4 = (code *)0x1;
LAB_08074ca0:
        fVar39 = (float10)app_tminterval(1,usertime);
        pcVar6 = "%ld %d bit DSA signs in %.2fs\n";
        if (mr != 0) {
          pcVar6 = "+R3:%ld:%d:%.2f\n";
        }
        BIO_printf(bio_err,pcVar6,local_28b4,uVar21,SUB84((double)fVar39,0),
                   (int)((ulonglong)(double)fVar39 >> 0x20));
        *(double *)(dsa_results + iVar17 * 0x10) = (double)fVar39 / (double)(int)local_28b4;
      }
      iVar18 = DSA_verify(0x74,data,0x14,out,(int)local_288c,dsa);
      if (iVar18 < 1) {
        pcVar6 = "DSA verify failure.  No DSA verify will be done.\n";
        BIO_printf(bio_err,"DSA verify failure.  No DSA verify will be done.\n");
        ERR_print_errors(bio_err);
        dVar40 = (double)(ZEXT48(pcVar6) << 0x20);
        local_2888[iVar17 + 3] = (DSA *)0x0;
      }
      else {
        uVar21 = *(undefined4 *)(dsa_bits_17981 + iVar17 * 4);
        pcVar6 = "Doing %d bit %s %s\'s for %ds: ";
        if (mr != 0) {
          pcVar6 = "+DTP:%d:%s:%s:%d\n";
        }
        BIO_printf(bio_err,pcVar6,uVar21,"verify",&DAT_081f6929,10);
        uVar42 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(10);
        iVar18 = 0;
        app_tminterval(0,usertime);
        run = 1;
        while (iVar10 = DSA_verify(0x74,data,0x14,out,(int)local_288c,dsa), 0 < iVar10) {
          iVar18 = iVar18 + 1;
          if ((run == 0) || (iVar18 == 0x7fffffff)) goto LAB_08074b0c;
        }
        iVar18 = 1;
        BIO_printf(bio_err,"DSA verify failure\n");
        ERR_print_errors(bio_err);
LAB_08074b0c:
        fVar39 = (float10)app_tminterval(1,usertime);
        dVar40 = (double)fVar39;
        pcVar6 = "%ld %d bit DSA verify in %.2fs\n";
        if (mr != 0) {
          pcVar6 = "+R4:%ld:%d:%.2f\n";
        }
        BIO_printf(bio_err,pcVar6,iVar18,uVar21,SUB84(dVar40,0),(int)((ulonglong)dVar40 >> 0x20));
        *(double *)(dsa_results + iVar17 * 0x10 + 8) = (double)fVar39 / (double)iVar18;
      }
      if ((int)local_28b4 < 2) {
        iVar18 = 4;
        if (iVar17 != 2) {
          local_2888[iVar17 + 4] = (DSA *)0x0;
          if (iVar17 == 0) {
            local_2874 = 0;
            iVar18 = 4;
          }
          else {
            iVar18 = iVar17 + 3;
          }
        }
      }
      else {
        iVar18 = iVar17 + 1;
      }
    }
    uVar21 = (undefined4)uVar42;
    iVar17 = iVar18;
  } while (iVar18 < 3);
  if (rnd_fake != 0) {
    RAND_cleanup();
  }
  uVar43 = CONCAT44(0x8074d17,uVar21);
  iVar17 = RAND_status();
  if (iVar17 != 1) {
    uVar3 = 0x40;
    RAND_seed("string to make the random number generator think it has entropy",0x40);
    dVar40 = (double)((ulonglong)uVar3 << 0x20);
    rnd_fake = 1;
  }
  iVar17 = 0;
  do {
    iVar18 = iVar17;
    if (local_2770[iVar17] != 0) {
      pEVar9 = EC_KEY_new_by_curve_name(*(int *)(test_curves_17982 + iVar17 * 4));
      local_2830[iVar17] = pEVar9;
      if (pEVar9 == (EC_KEY *)0x0) {
        pcVar6 = "ECDSA failure.\n";
        BIO_printf(bio_err,"ECDSA failure.\n");
        ERR_print_errors(bio_err);
        dVar40 = (double)(ZEXT48(pcVar6) << 0x20);
      }
      else {
        EC_KEY_precompute_mult(pEVar9,(BN_CTX *)0x0);
        EC_KEY_generate_key(pEVar9);
        iVar10 = ECDSA_sign(0,data,0x14,local_620,(uint *)&local_288c,pEVar9);
        if (iVar10 == 0) {
          iVar10 = 1;
          BIO_printf(bio_err,"ECDSA sign failure.  No ECDSA sign will be done.\n");
          ERR_print_errors(bio_err);
        }
        else {
          uVar21 = *(undefined4 *)(test_curves_bits_17984 + iVar17 * 4);
          pcVar6 = "Doing %d bit %s %s\'s for %ds: ";
          if (mr != 0) {
            pcVar6 = "+DTP:%d:%s:%s:%d\n";
          }
          iVar10 = 0;
          BIO_printf(bio_err,pcVar6,uVar21,"sign",&DAT_081f6927,10);
          uVar43 = 0;
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          run = 1;
          while (iVar11 = ECDSA_sign(0,data,0x14,local_620,(uint *)&local_288c,pEVar9), iVar11 != 0)
          {
            iVar10 = iVar10 + 1;
            if ((run == 0) || (iVar10 == 0x7fffffff)) goto LAB_08075093;
          }
          iVar10 = 1;
          BIO_printf(bio_err,"ECDSA sign failure\n");
          ERR_print_errors(bio_err);
LAB_08075093:
          fVar39 = (float10)app_tminterval(1,usertime);
          pcVar6 = "%ld %d bit ECDSA signs in %.2fs \n";
          if (mr != 0) {
            pcVar6 = "+R5:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar6,iVar10,uVar21,SUB84((double)fVar39,0),
                     (int)((ulonglong)(double)fVar39 >> 0x20));
          *(double *)(ecdsa_results + iVar17 * 0x10) = (double)fVar39 / (double)iVar10;
        }
        iVar11 = ECDSA_verify(0,data,0x14,local_620,(int)local_288c,pEVar9);
        if (iVar11 == 1) {
          uVar21 = *(undefined4 *)(test_curves_bits_17984 + iVar17 * 4);
          pcVar6 = "Doing %d bit %s %s\'s for %ds: ";
          if (mr != 0) {
            pcVar6 = "+DTP:%d:%s:%s:%d\n";
          }
          BIO_printf(bio_err,pcVar6,uVar21,"verify",&DAT_081f6927,10);
          uVar43 = 0;
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          run = 1;
          iVar11 = 0;
          while (iVar12 = ECDSA_verify(0,data,0x14,local_620,(int)local_288c,pEVar9), iVar12 == 1) {
            iVar11 = iVar11 + 1;
            if ((run == 0) || (iVar11 == 0x7fffffff)) goto LAB_08075bf9;
          }
          BIO_printf(bio_err,"ECDSA verify failure\n");
          ERR_print_errors(bio_err);
          iVar11 = 1;
LAB_08075bf9:
          fVar39 = (float10)app_tminterval(1,usertime);
          dVar40 = (double)fVar39;
          pcVar6 = "%ld %d bit ECDSA verify in %.2fs\n";
          if (mr != 0) {
            pcVar6 = "+R6:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar6,iVar11,uVar21,SUB84(dVar40,0),(int)((ulonglong)dVar40 >> 0x20));
          *(double *)(ecdsa_results + iVar17 * 0x10 + 8) = (double)fVar39 / (double)iVar11;
        }
        else {
          pcVar6 = "ECDSA verify failure.  No ECDSA verify will be done.\n";
          BIO_printf(bio_err,"ECDSA verify failure.  No ECDSA verify will be done.\n");
          ERR_print_errors(bio_err);
          dVar40 = (double)(ZEXT48(pcVar6) << 0x20);
          local_2770[iVar17] = 0;
        }
        uVar21 = (undefined4)uVar43;
        if (iVar10 < 2) {
          if (iVar17 + 1 == 0x10) break;
          local_2770[iVar17 + 1] = 0;
          iVar18 = iVar17 + 2;
          if (iVar18 < 0x10) {
            local_2770[iVar18] = 0;
            iVar18 = iVar17 + 3;
            if (iVar18 < 0x10) {
              local_2770[iVar18] = 0;
              iVar18 = iVar17 + 4;
              if (iVar18 < 0x10) {
                local_2770[iVar18] = 0;
                iVar18 = iVar17 + 5;
                if (iVar18 < 0x10) {
                  local_2770[iVar18] = 0;
                  iVar18 = iVar17 + 6;
                  if (iVar18 < 0x10) {
                    local_2770[iVar18] = 0;
                    iVar18 = iVar17 + 7;
                    if (iVar18 < 0x10) {
                      local_2770[iVar18] = 0;
                      iVar18 = iVar17 + 8;
                      if (iVar18 < 0x10) {
                        local_2770[iVar18] = 0;
                        iVar18 = iVar17 + 9;
                        if (iVar18 < 0x10) {
                          local_2770[iVar18] = 0;
                          iVar18 = iVar17 + 10;
                          if (iVar18 < 0x10) {
                            local_2770[iVar18] = 0;
                            iVar18 = iVar17 + 0xb;
                            if (iVar18 < 0x10) {
                              local_2770[iVar18] = 0;
                              iVar18 = iVar17 + 0xc;
                              if (iVar18 < 0x10) {
                                local_2770[iVar18] = 0;
                                iVar18 = iVar17 + 0xd;
                                if (iVar18 < 0x10) {
                                  local_2770[iVar18] = 0;
                                  iVar18 = iVar17 + 0xe;
                                  if (iVar18 < 0x10) {
                                    local_2770[iVar18] = 0;
                                    iVar18 = iVar17 + 0xf;
                                    if (iVar18 == 0xf) {
                                      local_2770[15] = 0;
                                      iVar18 = iVar17 + 0x10;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar21 = (undefined4)uVar43;
    iVar17 = iVar18 + 1;
  } while (iVar17 < 0x10);
  if (rnd_fake != 0) {
    RAND_cleanup();
  }
  dVar44 = (double)CONCAT44(0x807510c,uVar21);
  iVar17 = RAND_status();
  if (iVar17 != 1) {
    uVar3 = 0x40;
    RAND_seed("string to make the random number generator think it has entropy",0x40);
    dVar40 = (double)((ulonglong)uVar3 << 0x20);
    rnd_fake = 1;
  }
  iVar17 = 0;
  do {
    iVar18 = iVar17;
    if (local_2730[iVar17] != 0) {
      iVar10 = *(int *)(test_curves_17982 + iVar17 * 4);
      pEVar9 = EC_KEY_new_by_curve_name(iVar10);
      local_27f0[iVar17] = pEVar9;
      key = EC_KEY_new_by_curve_name(iVar10);
      local_27b0[iVar17] = key;
      if ((pEVar9 == (EC_KEY *)0x0) || (key == (EC_KEY *)0x0)) {
        pcVar6 = "ECDH failure.\n";
      }
      else {
        iVar10 = EC_KEY_generate_key(pEVar9);
        if ((iVar10 != 0) && (iVar10 = EC_KEY_generate_key(key), iVar10 != 0)) {
          group = EC_KEY_get0_group(pEVar9);
          iVar10 = EC_GROUP_get_degree(group);
          if (iVar10 < 0xc1) {
            sVar23 = 0x14;
            local_28b4 = KDF1_SHA1;
          }
          else {
            local_28b4 = (KDF *)0x0;
            sVar23 = iVar10 + 7 >> 3;
          }
          pEVar13 = EC_KEY_get0_public_key(key);
          iVar10 = ECDH_compute_key(&local_520,sVar23,pEVar13,pEVar9,local_28b4);
          pEVar13 = EC_KEY_get0_public_key(pEVar9);
          iVar11 = ECDH_compute_key(local_420,sVar23,pEVar13,key,local_28b4);
          if (iVar10 == iVar11) {
            if (0 < iVar10) {
              iVar11 = 0;
              do {
                bVar38 = *(byte *)((int)&local_520 + iVar11);
                pbVar24 = local_420 + iVar11;
                iVar11 = iVar11 + 1;
                if (bVar38 != *pbVar24) break;
              } while (iVar11 < iVar10);
              if (bVar38 != *pbVar24) goto LAB_0807677a;
            }
          }
          else {
LAB_0807677a:
            BIO_printf(bio_err,"ECDH computations don\'t match.\n");
            ERR_print_errors(bio_err);
          }
          uVar21 = *(undefined4 *)(test_curves_bits_17984 + iVar17 * 4);
          pcVar6 = "Doing %d bit %s %s\'s for %ds: ";
          if (mr != 0) {
            pcVar6 = "+DTP:%d:%s:%s:%d\n";
          }
          BIO_printf(bio_err,pcVar6,uVar21,&DAT_081eca46,&DAT_081f69bd,10);
          dVar44 = 0.0;
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          run = 1;
          iVar10 = 0;
          do {
            iVar10 = iVar10 + 1;
            pEVar13 = EC_KEY_get0_public_key(key);
            ECDH_compute_key(&local_520,sVar23,pEVar13,pEVar9,local_28b4);
            if (run == 0) {
              fVar39 = (float10)app_tminterval(1,usertime);
              dVar40 = (double)fVar39;
              pcVar6 = "%ld %d-bit ECDH ops in %.2fs\n";
              if (mr != 0) {
                pcVar6 = "+R7:%ld:%d:%.2f\n";
              }
              BIO_printf(bio_err,pcVar6,iVar10,uVar21,SUB84(dVar40,0),
                         (int)((ulonglong)dVar40 >> 0x20));
              *(double *)(ecdh_results + iVar17 * 8) = (double)fVar39 / (double)iVar10;
              if (iVar10 == 1) goto LAB_080751f5;
              goto LAB_08075148;
            }
          } while (iVar10 != 0x7fffffff);
          fVar39 = (float10)app_tminterval(1,usertime);
          if (mr == 0) {
            pcVar6 = "%ld %d-bit ECDH ops in %.2fs\n";
          }
          else {
            pcVar6 = "+R7:%ld:%d:%.2f\n";
          }
          local_28a4 = (double)fVar39;
          dVar40 = (double)fVar39;
          BIO_printf(bio_err,pcVar6,0x7fffffff,uVar21,SUB84(dVar40,0),
                     (int)((ulonglong)dVar40 >> 0x20));
          *(double *)(ecdh_results + iVar17 * 8) = local_28a4 / _DAT_081f7730;
          goto LAB_08075148;
        }
        pcVar6 = "ECDH key generation failure.\n";
      }
      BIO_printf(bio_err,pcVar6);
      ERR_print_errors(bio_err);
      dVar40 = (double)(ZEXT48(pcVar6) << 0x20);
LAB_080751f5:
      pcVar6 = (char *)((ulonglong)dVar40 >> 0x20);
      if (iVar17 + 1 == 0x10) break;
      local_2730[iVar17 + 1] = 0;
      iVar18 = iVar17 + 2;
      if (iVar18 < 0x10) {
        local_2730[iVar18] = 0;
        iVar18 = iVar17 + 3;
        if (iVar18 < 0x10) {
          local_2730[iVar18] = 0;
          iVar18 = iVar17 + 4;
          if (iVar18 < 0x10) {
            local_2730[iVar18] = 0;
            iVar18 = iVar17 + 5;
            if (iVar18 < 0x10) {
              local_2730[iVar18] = 0;
              iVar18 = iVar17 + 6;
              if (iVar18 < 0x10) {
                local_2730[iVar18] = 0;
                iVar18 = iVar17 + 7;
                if (iVar18 < 0x10) {
                  local_2730[iVar18] = 0;
                  iVar18 = iVar17 + 8;
                  if (iVar18 < 0x10) {
                    local_2730[iVar18] = 0;
                    iVar18 = iVar17 + 9;
                    if (iVar18 < 0x10) {
                      local_2730[iVar18] = 0;
                      iVar18 = iVar17 + 10;
                      if (iVar18 < 0x10) {
                        local_2730[iVar18] = 0;
                        iVar18 = iVar17 + 0xb;
                        if (iVar18 < 0x10) {
                          local_2730[iVar18] = 0;
                          iVar18 = iVar17 + 0xc;
                          if (iVar18 < 0x10) {
                            local_2730[iVar18] = 0;
                            iVar18 = iVar17 + 0xd;
                            if (iVar18 < 0x10) {
                              local_2730[iVar18] = 0;
                              iVar18 = iVar17 + 0xe;
                              if (iVar18 < 0x10) {
                                local_2730[iVar18] = 0;
                                iVar18 = iVar17 + 0xf;
                                if (iVar18 == 0xf) {
                                  local_2730[15] = 0;
                                  iVar18 = iVar17 + 0x10;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_08075148:
    pcVar6 = (char *)((ulonglong)dVar40 >> 0x20);
    iVar17 = iVar18 + 1;
  } while (iVar17 < 0x10);
  if (rnd_fake != 0) {
    dVar44 = (double)CONCAT44(0x8076679,SUB84(dVar44,0));
    RAND_cleanup();
  }
  if (mr == 0) {
LAB_080761b7:
    pcVar6 = SSLeay_version(0);
    __fprintf_chk(stdout,1,&DAT_081ed464,pcVar6);
    pcVar6 = SSLeay_version(3);
    __fprintf_chk(stdout,1,&DAT_081ed464,pcVar6);
    __printf_chk(1,"options:");
    pcVar6 = BN_options();
    __printf_chk(1,&DAT_081f6c21,pcVar6);
    pcVar6 = RC4_options();
    __printf_chk(1,&DAT_081f6c21,pcVar6);
    pcVar6 = DES_options();
    __printf_chk(1,&DAT_081f6c21,pcVar6);
    pcVar6 = AES_options();
    __printf_chk(1,&DAT_081f6c21,pcVar6);
    pcVar6 = idea_options();
    __printf_chk(1,&DAT_081f6c21,pcVar6);
    pcVar7 = BF_options();
    dVar44 = (double)ZEXT48(pcVar7);
    pcVar6 = &DAT_081f6c21;
    __printf_chk(1,&DAT_081f6c21,pcVar7);
    pcVar7 = SSLeay_version(2);
    __fprintf_chk(stdout,1,&DAT_081f6c25,pcVar7);
    if (local_28e8 != 0) {
      if (mr != 0) goto LAB_08075451;
      fwrite("The \'numbers\' are in 1000s of bytes per second processed.\n",1,0x3a,stdout);
      fwrite("type        ",1,0xc,stdout);
LAB_08075468:
      iVar17 = 0;
      do {
        pcVar6 = "%7d bytes";
        puVar30 = (undefined4 *)(lengths + iVar17);
        if (mr != 0) {
          pcVar6 = ":%d";
        }
        iVar17 = iVar17 + 4;
        dVar44 = (double)CONCAT44(*puVar30,pcVar6);
        __fprintf_chk(stdout,1,pcVar6,*puVar30);
      } while (iVar17 != 0x14);
      pcVar6 = (char *)stdout;
      fputc(10,stdout);
    }
  }
  else if (local_28e8 != 0) {
LAB_08075451:
    fwrite(&DAT_081f6c2a,1,2,stdout);
    goto LAB_08075468;
  }
LAB_08075396:
  iVar17 = 0;
  do {
    if (local_2730[iVar17 + 0x10] != 0) {
      if (mr == 0) {
        dVar44 = (double)CONCAT44(*(undefined4 *)(names + iVar17 * 4),0x81f6c43);
        __fprintf_chk(stdout,1,"%-13s",*(undefined4 *)(names + iVar17 * 4));
      }
      else {
        __fprintf_chk(stdout,1,"+F:%d:%s",iVar17,*(undefined4 *)(names + iVar17 * 4));
      }
      iVar18 = 0;
      do {
        dVar40 = *(double *)(results + iVar18 * 8 + iVar17 * 0x28);
        if ((double)_DAT_081f7728 < dVar40) {
          pcVar6 = ":%.2f";
          if (mr != 0) goto LAB_08075403;
          __fprintf_chk(stdout,1," %11.2fk",dVar40 / (double)_DAT_081f772c);
        }
        else {
          pcVar6 = " %11.2f ";
          if (mr != 0) {
            pcVar6 = ":%.2f";
          }
LAB_08075403:
          __fprintf_chk(stdout,1,pcVar6,SUB84(dVar40,0),(int)((ulonglong)dVar40 >> 0x20));
        }
        iVar18 = iVar18 + 1;
      } while (iVar18 != 5);
      pcVar6 = (char *)stdout;
      fputc(10,stdout);
    }
    iVar17 = iVar17 + 1;
  } while (iVar17 != 0x1e);
  if (local_2860 == (RSA *)0x0) {
    if (local_285c == 0) {
      if (local_2858 != 0) goto LAB_08075e39;
      bVar34 = true;
    }
    else {
LAB_08075dda:
      bVar34 = true;
      if (mr == 0) {
        dVar44 = 6.733375185950931e-316;
        pcVar6 = "%18ssign    verify    sign/s verify/s\n";
        __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f8b67);
        goto LAB_0807555d;
      }
LAB_08075dec:
      __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",1,0x400,rsa_results._16_4_,rsa_results._20_4_,
                    rsa_results._24_4_,rsa_results._28_4_,pcVar6,dVar44);
LAB_08075e23:
      if (local_2858 != 0) {
        if (!bVar34) goto LAB_08076021;
LAB_08075e39:
        bVar34 = true;
        if (mr == 0) {
          dVar44 = 6.733375185950931e-316;
          pcVar6 = "%18ssign    verify    sign/s verify/s\n";
          __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f8b67);
          goto LAB_08076021;
        }
        goto LAB_08075e4c;
      }
    }
LAB_08075cf3:
    if (local_2854 != 0) {
      if (bVar34) {
        if (mr == 0) {
          dVar44 = 6.733375185950931e-316;
          pcVar6 = "%18ssign    verify    sign/s verify/s\n";
          __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f8b67);
          goto LAB_080755c4;
        }
      }
      else {
LAB_080755c4:
        if (mr == 0) {
          dVar44 = 1.0 / (double)CONCAT44(rsa_results._60_4_,rsa_results._56_4_);
          dVar40 = 1.0 / (double)CONCAT44(rsa_results._52_4_,rsa_results._48_4_);
          pcVar6 = (char *)((ulonglong)dVar40 >> 0x20);
          __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x1000,
                        rsa_results._48_4_,rsa_results._52_4_,rsa_results._56_4_,rsa_results._60_4_,
                        dVar40,dVar44);
          goto LAB_08075614;
        }
      }
      __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",3,0x1000,rsa_results._48_4_,rsa_results._52_4_,
                    rsa_results._56_4_,rsa_results._60_4_,pcVar6,dVar44);
    }
  }
  else {
    bVar34 = true;
    if (mr == 0) {
      dVar44 = 6.733375185950931e-316;
      pcVar6 = "%18ssign    verify    sign/s verify/s\n";
      __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f8b67);
      if (mr != 0) {
        bVar34 = false;
        goto LAB_08075510;
      }
      dVar44 = 1.0 / (double)CONCAT44(rsa_results._12_4_,rsa_results._8_4_);
      dVar40 = 1.0 / (double)CONCAT44(rsa_results._4_4_,rsa_results._0_4_);
      pcVar6 = (char *)((ulonglong)dVar40 >> 0x20);
      __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x200,rsa_results._0_4_,
                    rsa_results._4_4_,rsa_results._8_4_,rsa_results._12_4_,dVar40,dVar44);
      if (local_285c != 0) goto LAB_0807555d;
      if (local_2858 == 0) {
        bVar34 = false;
        goto LAB_08075cf3;
      }
LAB_08076021:
      if (mr != 0) {
        bVar34 = false;
LAB_08075e4c:
        __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",2,0x800,rsa_results._32_4_,rsa_results._36_4_,
                      rsa_results._40_4_,rsa_results._44_4_,pcVar6,dVar44);
        goto LAB_08075cf3;
      }
      dVar44 = 1.0 / (double)CONCAT44(rsa_results._44_4_,rsa_results._40_4_);
      dVar40 = 1.0 / (double)CONCAT44(rsa_results._36_4_,rsa_results._32_4_);
      pcVar6 = (char *)((ulonglong)dVar40 >> 0x20);
      __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x800,rsa_results._32_4_,
                    rsa_results._36_4_,rsa_results._40_4_,rsa_results._44_4_,dVar40,dVar44);
      if (local_2854 == 0) goto LAB_08075614;
      goto LAB_080755c4;
    }
LAB_08075510:
    __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",0,0x200,rsa_results._0_4_,rsa_results._4_4_,
                  rsa_results._8_4_,rsa_results._12_4_);
    if (local_285c == 0) goto LAB_08075e23;
    if (bVar34) goto LAB_08075dda;
LAB_0807555d:
    if (mr != 0) {
      bVar34 = false;
      goto LAB_08075dec;
    }
    dVar44 = 1.0 / (double)CONCAT44(rsa_results._28_4_,rsa_results._24_4_);
    dVar40 = 1.0 / (double)CONCAT44(rsa_results._20_4_,rsa_results._16_4_);
    pcVar6 = (char *)((ulonglong)dVar40 >> 0x20);
    __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x400,rsa_results._16_4_,
                  rsa_results._20_4_,rsa_results._24_4_,rsa_results._28_4_,dVar40,dVar44);
    if (local_2858 != 0) goto LAB_08076021;
    if (local_2854 != 0) goto LAB_080755c4;
  }
LAB_08075614:
  if (local_287c == 0) {
    if (local_2878 == 0) {
      if (local_2874 != 0) goto LAB_08075c88;
    }
    else {
LAB_08075d75:
      bVar34 = true;
      if (mr == 0) {
        dVar44 = 6.733375185950931e-316;
        pcVar6 = "%18ssign    verify    sign/s verify/s\n";
        __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f8b67);
        goto LAB_08075681;
      }
LAB_08075d88:
      __fprintf_chk(stdout,1,"+F3:%u:%u:%f:%f\n",1,0x400,dsa_results._16_4_,dsa_results._20_4_,
                    dsa_results._24_4_,dsa_results._28_4_,pcVar6,dVar44);
LAB_08075dbf:
      if (local_2874 != 0) {
        if (!bVar34) goto LAB_080756da;
LAB_08075c88:
        if (mr == 0) {
          dVar44 = 6.733375185950931e-316;
          pcVar6 = "%18ssign    verify    sign/s verify/s\n";
          __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f8b67);
          goto LAB_080756da;
        }
        goto LAB_08075c96;
      }
    }
  }
  else {
    bVar34 = true;
    if (mr == 0) {
      dVar44 = 6.733375185950931e-316;
      pcVar6 = "%18ssign    verify    sign/s verify/s\n";
      __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f8b67);
      if (mr != 0) {
        bVar34 = false;
        goto LAB_08075634;
      }
      dVar44 = 1.0 / (double)CONCAT44(dsa_results._12_4_,dsa_results._8_4_);
      dVar40 = 1.0 / (double)CONCAT44(dsa_results._4_4_,dsa_results._0_4_);
      pcVar6 = (char *)((ulonglong)dVar40 >> 0x20);
      __fprintf_chk(stdout,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x200,dsa_results._0_4_,
                    dsa_results._4_4_,dsa_results._8_4_,dsa_results._12_4_,dVar40,dVar44);
      if (local_2878 != 0) goto LAB_08075681;
    }
    else {
LAB_08075634:
      __fprintf_chk(stdout,1,"+F3:%u:%u:%f:%f\n",0,0x200,dsa_results._0_4_,dsa_results._4_4_,
                    dsa_results._8_4_,dsa_results._12_4_,pcVar6,dVar44);
      if (local_2878 == 0) goto LAB_08075dbf;
      if (bVar34) goto LAB_08075d75;
LAB_08075681:
      if (mr != 0) {
        bVar34 = false;
        goto LAB_08075d88;
      }
      dVar44 = 1.0 / (double)CONCAT44(dsa_results._28_4_,dsa_results._24_4_);
      dVar40 = 1.0 / (double)CONCAT44(dsa_results._20_4_,dsa_results._16_4_);
      pcVar6 = (char *)((ulonglong)dVar40 >> 0x20);
      __fprintf_chk(stdout,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x400,dsa_results._16_4_,
                    dsa_results._20_4_,dsa_results._24_4_,dsa_results._28_4_,dVar40,dVar44);
    }
    if (local_2874 == 0) goto LAB_0807572a;
LAB_080756da:
    if (mr == 0) {
      dVar44 = 1.0 / (double)CONCAT44(dsa_results._44_4_,dsa_results._40_4_);
      dVar40 = 1.0 / (double)CONCAT44(dsa_results._36_4_,dsa_results._32_4_);
      pcVar6 = (char *)((ulonglong)dVar40 >> 0x20);
      __fprintf_chk(stdout,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x800,dsa_results._32_4_,
                    dsa_results._36_4_,dsa_results._40_4_,dsa_results._44_4_,dVar40,dVar44);
    }
    else {
LAB_08075c96:
      __fprintf_chk(stdout,1,"+F3:%u:%u:%f:%f\n",2,0x800,dsa_results._32_4_,dsa_results._36_4_,
                    dsa_results._40_4_,dsa_results._44_4_,pcVar6,dVar44);
    }
  }
LAB_0807572a:
  iVar17 = 0;
  bVar34 = true;
  pdVar27 = (double *)(ecdsa_results + 8);
  do {
    while (local_2770[iVar17] == 0) {
LAB_0807577d:
      iVar17 = iVar17 + 1;
      pdVar27 = pdVar27 + 2;
      if (iVar17 == 0x10) goto LAB_080757f5;
    }
    if (bVar34) {
      bVar34 = true;
      if (mr == 0) {
        dVar44 = 6.733375185950931e-316;
        pcVar6 = "%30ssign    verify    sign/s verify/s\n";
        __printf_chk(1,"%30ssign    verify    sign/s verify/s\n",&DAT_081f8b67);
        goto LAB_08075797;
      }
LAB_08075752:
      __fprintf_chk(stdout,1,"+F4:%u:%u:%f:%f\n",iVar17,
                    *(undefined4 *)(test_curves_bits_17984 + iVar17 * 4),
                    *(undefined4 *)(pdVar27 + -1),*(undefined4 *)((int)pdVar27 + -4),
                    *(undefined4 *)pdVar27,*(undefined4 *)((int)pdVar27 + 4),pcVar6,dVar44);
      goto LAB_0807577d;
    }
LAB_08075797:
    if (mr != 0) {
      bVar34 = false;
      goto LAB_08075752;
    }
    dVar40 = *pdVar27;
    bVar34 = false;
    iVar18 = iVar17 * 4;
    iVar10 = iVar17 * 4;
    iVar17 = iVar17 + 1;
    __fprintf_chk(stdout,1,"%4u bit ecdsa (%s) %8.4fs %8.4fs %8.1f %8.1f\n",
                  *(undefined4 *)(test_curves_bits_17984 + iVar10),
                  *(undefined4 *)(test_curves_names_17983 + iVar18),pdVar27[-1],SUB84(dVar40,0),
                  (int)((ulonglong)dVar40 >> 0x20),1.0 / pdVar27[-1],1.0 / dVar40);
    pdVar27 = pdVar27 + 2;
  } while (iVar17 != 0x10);
LAB_080757f5:
  iVar17 = 0;
  bVar34 = true;
  do {
    while (local_2730[iVar17] == 0) {
LAB_08075853:
      iVar17 = iVar17 + 1;
      if (iVar17 == 0x10) goto LAB_080758bd;
    }
    if (bVar34) {
      if (mr == 0) {
        __printf_chk(1,"%30sop      op/s\n",&DAT_081f8b67);
        goto joined_r0x08075962;
      }
LAB_0807581d:
      dVar40 = *(double *)(ecdh_results + iVar17 * 8);
      __fprintf_chk(stdout,1,"+F5:%u:%u:%f:%f\n",iVar17,
                    *(undefined4 *)(test_curves_bits_17984 + iVar17 * 4),SUB84(dVar40,0),
                    (int)((ulonglong)dVar40 >> 0x20),(double)_DAT_081f7724 / dVar40);
      goto LAB_08075853;
    }
joined_r0x08075962:
    if (mr != 0) {
      bVar34 = false;
      goto LAB_0807581d;
    }
    dVar40 = *(double *)(ecdh_results + iVar17 * 8);
    bVar34 = false;
    iVar18 = iVar17 * 4;
    iVar10 = iVar17 * 4;
    iVar17 = iVar17 + 1;
    __fprintf_chk(stdout,1,"%4u bit ecdh (%s) %8.4fs %8.1f\n",
                  *(undefined4 *)(test_curves_bits_17984 + iVar10),
                  *(undefined4 *)(test_curves_names_17983 + iVar18),SUB84(dVar40,0),
                  (int)((ulonglong)dVar40 >> 0x20),(double)_DAT_081f7724 / dVar40);
  } while (iVar17 != 0x10);
LAB_080758bd:
  uVar21 = 0;
LAB_0807200c:
  ERR_print_errors(bio_err);
  CRYPTO_free(data);
  CRYPTO_free(out);
LAB_0807157c:
  ppRVar28 = local_2870;
  do {
    if (*ppRVar28 != (RSA *)0x0) {
      RSA_free(*ppRVar28);
    }
    ppRVar28 = ppRVar28 + 1;
  } while (&local_2860 != ppRVar28);
  ppDVar29 = local_2888;
  do {
    if (*ppDVar29 != (DSA *)0x0) {
      DSA_free(*ppDVar29);
    }
    ppDVar29 = ppDVar29 + 1;
  } while (local_2888 + 3 != ppDVar29);
  ppEVar25 = local_2830;
  do {
    if (*ppEVar25 != (EC_KEY *)0x0) {
      EC_KEY_free(*ppEVar25);
    }
    ppEVar25 = ppEVar25 + 1;
  } while (ppEVar25 != local_27f0);
  iVar17 = 0;
  do {
    if (local_27f0[iVar17] != (EC_KEY *)0x0) {
      EC_KEY_free(local_27f0[iVar17]);
    }
    if (local_27b0[iVar17] != (EC_KEY *)0x0) {
      EC_KEY_free(local_27b0[iVar17]);
    }
    iVar17 = iVar17 + 1;
  } while (iVar17 != 0x10);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar21;
}

