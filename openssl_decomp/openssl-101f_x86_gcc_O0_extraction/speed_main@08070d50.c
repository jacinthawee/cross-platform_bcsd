
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
  EVP_MD *pEVar6;
  char *pcVar7;
  EVP_MD *type_00;
  int iVar8;
  EC_KEY *pEVar9;
  int iVar10;
  EC_KEY *key;
  int iVar11;
  void *__ptr;
  EC_GROUP *group;
  EC_POINT *pEVar12;
  FILE *pFVar13;
  long lVar14;
  uint uVar15;
  RSA_METHOD *meth;
  int iVar16;
  int iVar17;
  undefined2 *puVar18;
  byte *pbVar19;
  undefined4 uVar20;
  byte **ppbVar21;
  size_t sVar22;
  byte *pbVar23;
  EC_KEY **ppEVar24;
  undefined1 *puVar25;
  double *pdVar26;
  RSA **ppRVar27;
  DSA **ppDVar28;
  undefined4 *puVar29;
  byte *pbVar30;
  int in_GS_OFFSET;
  bool bVar31;
  undefined uVar32;
  bool bVar33;
  bool bVar34;
  undefined uVar35;
  byte bVar36;
  float10 fVar37;
  double dVar38;
  char *pcVar39;
  code *pcVar40;
  undefined8 in_stack_ffffd70c;
  ulonglong uVar41;
  undefined8 uVar42;
  double dVar43;
  int local_28e8;
  long local_28b8;
  int local_28b4;
  int local_28ac;
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
  
  pFVar13 = (FILE *)((ulonglong)in_stack_ffffd70c >> 0x20);
  bVar36 = 0;
  usertime = (code *)0xffffffff;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  signal(0xd,(__sighandler_t)0x1);
  local_2888[0] = (DSA *)0x0;
  puVar29 = (undefined4 *)results;
  for (iVar16 = 300; iVar16 != 0; iVar16 = iVar16 + -1) {
    *puVar29 = 0;
    puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
  }
  local_2888[1] = (DSA *)0x0;
  local_2888[2] = (DSA *)0x0;
  ppEVar24 = local_2830;
  for (iVar16 = 0x10; iVar16 != 0; iVar16 = iVar16 + -1) {
    *ppEVar24 = (EC_KEY *)0x0;
    ppEVar24 = ppEVar24 + (uint)bVar36 * -2 + 1;
  }
  ppEVar24 = local_27f0;
  for (iVar16 = 0x10; iVar16 != 0; iVar16 = iVar16 + -1) {
    *ppEVar24 = (EC_KEY *)0x0;
    ppEVar24 = ppEVar24 + (uint)bVar36 * -2 + 1;
  }
  ppEVar24 = local_27b0;
  for (iVar16 = 0x10; iVar16 != 0; iVar16 = iVar16 + -1) {
    *ppEVar24 = (EC_KEY *)0x0;
    ppEVar24 = ppEVar24 + (uint)bVar36 * -2 + 1;
  }
  if (bio_err == (BIO *)0x0) {
    pFVar13 = (FILE *)0x807110e;
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      pFVar13 = stderr;
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar16 = load_config(bio_err,0);
  if (iVar16 == 0) {
LAB_08070df8:
    ERR_print_errors(bio_err);
LAB_08070e06:
    uVar20 = 1;
    goto LAB_08070e1c;
  }
  local_2870[0] = (RSA *)0x0;
  local_2870[1] = (RSA *)0x0;
  local_2870[2] = (RSA *)0x0;
  local_2870[3] = (RSA *)0x0;
  data = (uchar *)CRYPTO_malloc(0x2001,"speed.c",0x29b);
  if (data == (uchar *)0x0) {
    BIO_printf(bio_err,"out of memory\n");
    goto LAB_08070df8;
  }
  uVar41 = CONCAT44(pFVar13,0x2a0);
  out = (uchar *)CRYPTO_malloc(0x2001,"speed.c",0x2a0);
  if (out == (uchar *)0x0) {
    BIO_printf(bio_err,"out of memory\n");
    ERR_print_errors(bio_err);
    CRYPTO_free(data);
    goto LAB_08070e06;
  }
  uVar3 = 0;
  local_790 = 0;
  local_78c = 0;
  puVar29 = local_1a30;
  for (iVar16 = 0x96; iVar16 != 0; iVar16 = iVar16 + -1) {
    *puVar29 = 0;
    puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
  }
  do {
    *(undefined4 *)((int)local_700 + uVar3) = 0;
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x20);
  local_2860 = (RSA *)0x0;
  local_285c = 0;
  piVar4 = local_2730 + 0x10;
  for (iVar16 = 0x1e; iVar16 != 0; iVar16 = iVar16 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + (uint)bVar36 * -2 + 1;
  }
  local_2858 = 0;
  local_2854 = 0;
  local_287c = 0;
  local_2878 = 0;
  local_2874 = 0;
  piVar4 = local_2770;
  for (iVar16 = 0x10; iVar16 != 0; iVar16 = iVar16 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + (uint)bVar36 * -2 + 1;
  }
  piVar4 = local_2730;
  for (iVar16 = 0x10; iVar16 != 0; iVar16 = iVar16 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + (uint)bVar36 * -2 + 1;
  }
  param_1 = param_1 + -1;
  if (param_1 == 0) {
    type_00 = (EVP_MD *)0x0;
    bVar33 = false;
    cipher = (EVP_CIPHER *)0x0;
    pcVar40 = usertime;
LAB_080712c3:
    for (iVar16 = 1; (iVar16 == 0x17 || (local_2730[iVar16 + 0xf] = 1, iVar16 != 0x1e));
        iVar16 = iVar16 + 1) {
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
LAB_08071474:
    piVar4 = local_2730 + 0x10;
    local_28e8 = 0;
    do {
      iVar16 = *piVar4;
      piVar4 = piVar4 + 1;
      local_28e8 = (local_28e8 + 1) - (uint)(iVar16 == 0);
    } while ((uint *)piVar4 != (uint *)((int)((SEED_KEY_SCHEDULE *)local_26f0)->data + 0x78U));
    if ((pcVar40 == (code *)0x0) && (mr == 0)) {
      BIO_printf(bio_err,"You have chosen to measure elapsed time instead of user CPU time.\n");
    }
    iVar16 = 0;
    do {
      local_288c = *(uchar **)(rsa_data_17967 + iVar16 * 4);
      pRVar5 = d2i_RSAPrivateKey((RSA **)0x0,&local_288c,
                                 *(long *)(rsa_data_length_17968 + iVar16 * 4));
      local_2870[iVar16] = pRVar5;
      if (pRVar5 == (RSA *)0x0) {
        uVar20 = 1;
        BIO_printf(bio_err,"internal error loading RSA key number %d\n",iVar16);
        goto LAB_0807189c;
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 != 4);
    local_2888[0] = (DSA *)get_dsa512();
    local_2888[1] = (DSA *)get_dsa1024();
    local_2888[2] = (DSA *)get_dsa2048();
    DES_set_key_unchecked((const_DES_cblock *)&key_17950,&local_25f8);
    DES_set_key_unchecked((const_DES_cblock *)&key2_17951,&local_2578);
    DES_set_key_unchecked((const_DES_cblock *)&key3_17952,&local_24f8);
    AES_set_encrypt_key(key16_17943,0x80,&local_224c);
    AES_set_encrypt_key(key24_17944,0xc0,&local_2158);
    AES_set_encrypt_key(key32_17945,0x100,&local_2064);
    Camellia_set_key(key16_17943,0x80,(CAMELLIA_KEY *)(local_1e6e + 0x102));
    Camellia_set_key(ckey24_17946,0xc0,&local_1c58);
    Camellia_set_key(ckey32_17947,0x100,&local_1b44);
    idea_set_encrypt_key(key16_17943,&local_2324);
    SEED_set_key(key16_17943,
                 (SEED_KEY_SCHEDULE *)((int)((SEED_KEY_SCHEDULE *)local_26f0)->data + 0x78));
    RC4_set_key((RC4_KEY *)local_1e6e,0x10,key16_17943);
    RC2_set_key(&local_1f70,0x10,key16_17943,0x80);
    BF_set_key(&local_17d8,0x10,key16_17943);
    uVar41 = 0x81f6ff8;
    CAST_set_key(&local_2478,0x10,key16_17943);
    uVar3 = 0;
    do {
      *(undefined4 *)((int)auStack_2850 + uVar3) = 0;
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x20);
    pcVar40 = sig_done;
    signal(0xe,sig_done);
    if (local_26f0[1] != 0) {
      puVar25 = lengths;
      sVar22 = 0x10;
      pdVar26 = (double *)(results + 0x28);
      do {
        if (mr == 0) {
          pcVar39 = "Doing %s for %ds on %d size blocks: ";
        }
        else {
          pcVar39 = "+DT:%s:%d:%d\n";
        }
        iVar16 = 0;
        BIO_printf(bio_err,pcVar39,names._4_4_,3,sVar22,pcVar40);
        uVar41 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        run = 1;
        do {
          uVar41 = CONCAT44(0x807175d,(int)uVar41);
          pEVar6 = (EVP_MD *)EVP_mdc2();
          iVar16 = iVar16 + 1;
          EVP_Digest(data,sVar22,local_788,(uint *)0x0,pEVar6,(ENGINE *)0x0);
          if (run == 0) break;
        } while (iVar16 != 0x7fffffff);
        fVar37 = (float10)app_tminterval(1,usertime);
        pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
        pcVar7 = "%d %s\'s in %.2fs\n";
        if (mr != 0) {
          pcVar7 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar7,iVar16,names._4_4_,SUB84((double)fVar37,0),pcVar39);
        puVar25 = (undefined1 *)((int)puVar25 + 4);
        fVar37 = (float10)(double)fVar37;
        *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
        if (puVar25 == &UNK_081f703c) goto LAB_080718d4;
        sVar22 = *(size_t *)puVar25;
        pcVar40 = (code *)pcVar39;
        pdVar26 = pdVar26 + 1;
      } while( true );
    }
    fVar37 = (float10)0;
    iVar16 = 0;
    pcVar39 = (char *)pcVar40;
LAB_080718d4:
    if (local_26f0[2] != 0) {
      puVar25 = lengths;
      sVar22 = 0x10;
      pdVar26 = (double *)(results + 0x50);
      do {
        if (mr == 0) {
          pcVar7 = "Doing %s for %ds on %d size blocks: ";
        }
        else {
          pcVar7 = "+DT:%s:%d:%d\n";
        }
        iVar16 = 0;
        BIO_printf(bio_err,pcVar7,names._8_4_,3,sVar22,pcVar39);
        uVar41 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        run = 1;
        do {
          uVar41 = CONCAT44(0x807197d,(int)uVar41);
          pEVar6 = EVP_md4();
          iVar16 = iVar16 + 1;
          EVP_Digest(data,sVar22,local_778,(uint *)0x0,pEVar6,(ENGINE *)0x0);
          if (run == 0) break;
        } while (iVar16 != 0x7fffffff);
        fVar37 = (float10)app_tminterval(1,usertime);
        pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
        pcVar7 = "%d %s\'s in %.2fs\n";
        if (mr != 0) {
          pcVar7 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar7,iVar16,names._8_4_,SUB84((double)fVar37,0),pcVar39);
        puVar25 = (undefined1 *)((int)puVar25 + 4);
        fVar37 = (float10)(double)fVar37;
        *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
        if (puVar25 == &UNK_081f703c) break;
        sVar22 = *(size_t *)puVar25;
        pdVar26 = pdVar26 + 1;
      } while( true );
    }
    if (local_26f0[3] != 0) {
      puVar25 = lengths;
      sVar22 = 0x10;
      pdVar26 = (double *)(results + 0x78);
      do {
        if (mr == 0) {
          pcVar7 = "Doing %s for %ds on %d size blocks: ";
        }
        else {
          pcVar7 = "+DT:%s:%d:%d\n";
        }
        iVar16 = 0;
        BIO_printf(bio_err,pcVar7,names._12_4_,3,sVar22,pcVar39);
        uVar41 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        run = 1;
        do {
          iVar16 = iVar16 + 1;
          pEVar6 = EVP_get_digestbyname("md5");
          EVP_Digest(data,sVar22,local_768,(uint *)0x0,pEVar6,(ENGINE *)0x0);
          if (run == 0) break;
        } while (iVar16 != 0x7fffffff);
        fVar37 = (float10)app_tminterval(1,usertime);
        pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
        pcVar7 = "%d %s\'s in %.2fs\n";
        if (mr != 0) {
          pcVar7 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar7,iVar16,names._12_4_,SUB84((double)fVar37,0),pcVar39);
        puVar25 = (undefined1 *)((int)puVar25 + 4);
        fVar37 = (float10)(double)fVar37;
        *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
        if (puVar25 == &UNK_081f703c) break;
        sVar22 = *(size_t *)puVar25;
        pdVar26 = pdVar26 + 1;
      } while( true );
    }
    if (local_26f0[4] != 0) {
      sVar22 = 0x10;
      HMAC_CTX_init(&local_23f4);
      pEVar6 = EVP_md5();
      HMAC_Init_ex(&local_23f4,"This is a key...",0x10,pEVar6,(ENGINE *)0x0);
      puVar25 = lengths;
      pdVar26 = (double *)(results + 0xa0);
      do {
        if (mr == 0) {
          pcVar7 = "Doing %s for %ds on %d size blocks: ";
        }
        else {
          pcVar7 = "+DT:%s:%d:%d\n";
        }
        iVar16 = 0;
        BIO_printf(bio_err,pcVar7,names._16_4_,3,sVar22,pcVar39);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        run = 1;
        do {
          iVar16 = iVar16 + 1;
          HMAC_Init_ex(&local_23f4,(void *)0x0,0,(EVP_MD *)0x0,(ENGINE *)0x0);
          HMAC_Update(&local_23f4,data,sVar22);
          uVar41 = 0;
          HMAC_Final(&local_23f4,local_758,(uint *)0x0);
          if (run == 0) break;
        } while (iVar16 != 0x7fffffff);
        fVar37 = (float10)app_tminterval(1,usertime);
        pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
        pcVar7 = "%d %s\'s in %.2fs\n";
        if (mr != 0) {
          pcVar7 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar7,iVar16,names._16_4_,SUB84((double)fVar37,0),pcVar39);
        puVar25 = (undefined1 *)((int)puVar25 + 4);
        *pdVar26 = (double)sVar22 * ((double)iVar16 / (double)fVar37);
        if (puVar25 == &UNK_081f703c) goto LAB_08076030;
        sVar22 = *(size_t *)puVar25;
        pdVar26 = pdVar26 + 1;
      } while( true );
    }
    goto LAB_08071bb6;
  }
  local_28b8 = 0;
  bVar33 = false;
  type_00 = (EVP_MD *)0x0;
  cipher = (EVP_CIPHER *)0x0;
  iVar16 = 0;
  do {
    ppbVar21 = param_2 + 1;
    pbVar23 = *ppbVar21;
    bVar31 = false;
    bVar34 = param_1 == 0;
    if (param_1 < 1) {
LAB_08071240:
      iVar17 = 5;
      pbVar19 = pbVar23;
      pbVar30 = &DAT_081ea220;
      do {
        if (iVar17 == 0) break;
        iVar17 = iVar17 + -1;
        bVar34 = *pbVar19 == *pbVar30;
        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
      } while (bVar34);
      if (bVar34) {
        local_26f0[1] = 1;
      }
      else {
        bVar1 = *pbVar23;
        bVar31 = bVar1 == 0x6d;
        if ((bVar31) && (bVar31 = pbVar23[1] == 100, bVar31)) {
          if ((pbVar23[2] == 0x34) && (pbVar23[3] == 0)) {
            local_26f0[2] = 1;
          }
          else {
            bVar31 = pbVar23[2] == 0x35;
            if ((!bVar31) || (bVar31 = pbVar23[3] == 0, !bVar31)) goto LAB_08071272;
            local_26f0[3] = 1;
          }
        }
        else {
LAB_08071272:
          iVar17 = 5;
          pbVar19 = pbVar23;
          pbVar30 = &DAT_081ec2ae;
          do {
            if (iVar17 == 0) break;
            iVar17 = iVar17 + -1;
            bVar31 = *pbVar19 == *pbVar30;
            pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
            pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
          } while (bVar31);
          if (bVar31) {
            local_26f0[4] = 1;
          }
          else {
            iVar17 = 5;
            pbVar19 = pbVar23;
            pbVar30 = &DAT_081ffb15;
            do {
              if (iVar17 == 0) break;
              iVar17 = iVar17 + -1;
              bVar31 = *pbVar19 == *pbVar30;
              pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
              pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
            } while (bVar31);
            if (bVar31) {
              local_26f0[5] = 1;
            }
            else {
              bVar31 = bVar1 == 0x73;
              if ((((bVar31) && (bVar31 = pbVar23[1] == 0x68, bVar31)) &&
                  (bVar31 = pbVar23[2] == 0x61, bVar31)) && (bVar31 = pbVar23[3] == 0, bVar31)) {
                local_26f0[5] = 1;
                local_26f0[23] = 1;
                local_26f0[24] = 1;
              }
              else {
                iVar17 = 7;
                pbVar19 = pbVar23;
                pbVar30 = (byte *)"sha256";
                do {
                  if (iVar17 == 0) break;
                  iVar17 = iVar17 + -1;
                  bVar31 = *pbVar19 == *pbVar30;
                  pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                  pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                } while (bVar31);
                if (bVar31) {
                  local_26f0[23] = 1;
                }
                else {
                  iVar17 = 7;
                  pbVar19 = pbVar23;
                  pbVar30 = (byte *)"sha512";
                  do {
                    if (iVar17 == 0) break;
                    iVar17 = iVar17 + -1;
                    bVar31 = *pbVar19 == *pbVar30;
                    pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                    pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                  } while (bVar31);
                  if (bVar31) {
                    local_26f0[24] = 1;
                  }
                  else {
                    iVar17 = 10;
                    pbVar19 = pbVar23;
                    pbVar30 = (byte *)"whirlpool";
                    do {
                      if (iVar17 == 0) break;
                      iVar17 = iVar17 + -1;
                      bVar31 = *pbVar19 == *pbVar30;
                      pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                      pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                    } while (bVar31);
                    if (bVar31) {
                      local_26f0[25] = 1;
                    }
                    else {
                      iVar17 = 7;
                      pbVar19 = pbVar23;
                      pbVar30 = (byte *)"ripemd";
                      do {
                        if (iVar17 == 0) break;
                        iVar17 = iVar17 + -1;
                        bVar31 = *pbVar19 == *pbVar30;
                        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                      } while (bVar31);
                      if (!bVar31) {
                        iVar17 = 7;
                        pbVar19 = pbVar23;
                        pbVar30 = (byte *)"rmd160";
                        do {
                          if (iVar17 == 0) break;
                          iVar17 = iVar17 + -1;
                          bVar31 = *pbVar19 == *pbVar30;
                          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                        } while (bVar31);
                        if (!bVar31) {
                          iVar17 = 10;
                          pbVar19 = pbVar23;
                          pbVar30 = (byte *)"ripemd160";
                          do {
                            if (iVar17 == 0) break;
                            iVar17 = iVar17 + -1;
                            bVar31 = *pbVar19 == *pbVar30;
                            pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                            pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                          } while (bVar31);
                          if (!bVar31) {
                            bVar31 = bVar1 == 0x72;
                            if (((bVar31) && (bVar31 = pbVar23[1] == 99, bVar31)) &&
                               ((bVar31 = pbVar23[2] == 0x34, bVar31 &&
                                (bVar31 = pbVar23[3] == 0, bVar31)))) {
                              local_26f0[7] = 1;
                            }
                            else {
                              iVar17 = 8;
                              pbVar19 = pbVar23;
                              pbVar30 = (byte *)"des-cbc";
                              do {
                                if (iVar17 == 0) break;
                                iVar17 = iVar17 + -1;
                                bVar31 = *pbVar19 == *pbVar30;
                                pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                              } while (bVar31);
                              if (bVar31) {
                                local_26f0[8] = 1;
                              }
                              else {
                                iVar17 = 9;
                                pbVar19 = pbVar23;
                                pbVar30 = (byte *)"des-ede3";
                                do {
                                  if (iVar17 == 0) break;
                                  iVar17 = iVar17 + -1;
                                  bVar31 = *pbVar19 == *pbVar30;
                                  pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                  pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                } while (bVar31);
                                if (bVar31) {
LAB_080776ee:
                                  local_26f0[9] = 1;
                                }
                                else {
                                  iVar17 = 0xc;
                                  pbVar19 = pbVar23;
                                  pbVar30 = (byte *)"aes-128-cbc";
                                  do {
                                    if (iVar17 == 0) break;
                                    iVar17 = iVar17 + -1;
                                    bVar31 = *pbVar19 == *pbVar30;
                                    pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                    pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                  } while (bVar31);
                                  if (bVar31) {
                                    local_26f0[16] = 1;
                                  }
                                  else {
                                    iVar17 = 0xc;
                                    pbVar19 = pbVar23;
                                    pbVar30 = (byte *)"aes-192-cbc";
                                    do {
                                      if (iVar17 == 0) break;
                                      iVar17 = iVar17 + -1;
                                      bVar31 = *pbVar19 == *pbVar30;
                                      pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                      pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                    } while (bVar31);
                                    if (bVar31) {
                                      local_26f0[17] = 1;
                                    }
                                    else {
                                      iVar17 = 0xc;
                                      pbVar19 = pbVar23;
                                      pbVar30 = (byte *)"aes-256-cbc";
                                      do {
                                        if (iVar17 == 0) break;
                                        iVar17 = iVar17 + -1;
                                        bVar31 = *pbVar19 == *pbVar30;
                                        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                      } while (bVar31);
                                      if (bVar31) {
LAB_0807778a:
                                        local_26f0[18] = 1;
                                      }
                                      else {
                                        iVar17 = 0xc;
                                        pbVar19 = pbVar23;
                                        pbVar30 = (byte *)"aes-128-ige";
                                        do {
                                          if (iVar17 == 0) break;
                                          iVar17 = iVar17 + -1;
                                          bVar31 = *pbVar19 == *pbVar30;
                                          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                        } while (bVar31);
                                        if (bVar31) {
                                          local_26f0[26] = 1;
                                        }
                                        else {
                                          iVar17 = 0xc;
                                          pbVar19 = pbVar23;
                                          pbVar30 = (byte *)"aes-192-ige";
                                          do {
                                            if (iVar17 == 0) break;
                                            iVar17 = iVar17 + -1;
                                            bVar31 = *pbVar19 == *pbVar30;
                                            pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                            pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                          } while (bVar31);
                                          if (bVar31) {
                                            local_26f0[27] = 1;
                                          }
                                          else {
                                            iVar17 = 0xc;
                                            pbVar19 = pbVar23;
                                            pbVar30 = (byte *)"aes-256-ige";
                                            do {
                                              if (iVar17 == 0) break;
                                              iVar17 = iVar17 + -1;
                                              bVar31 = *pbVar19 == *pbVar30;
                                              pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                              pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                            } while (bVar31);
                                            if (bVar31) {
                                              local_26f0[28] = 1;
                                            }
                                            else {
                                              iVar17 = 0x11;
                                              pbVar19 = pbVar23;
                                              pbVar30 = (byte *)"camellia-128-cbc";
                                              do {
                                                if (iVar17 == 0) break;
                                                iVar17 = iVar17 + -1;
                                                bVar31 = *pbVar19 == *pbVar30;
                                                pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                              } while (bVar31);
                                              if (bVar31) {
                                                local_26f0[19] = 1;
                                              }
                                              else {
                                                iVar17 = 0x11;
                                                pbVar19 = pbVar23;
                                                pbVar30 = (byte *)"camellia-192-cbc";
                                                do {
                                                  if (iVar17 == 0) break;
                                                  iVar17 = iVar17 + -1;
                                                  bVar31 = *pbVar19 == *pbVar30;
                                                  pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                  pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                } while (bVar31);
                                                if (bVar31) {
                                                  local_26f0[20] = 1;
                                                }
                                                else {
                                                  iVar17 = 0x11;
                                                  pbVar19 = pbVar23;
                                                  pbVar30 = (byte *)"camellia-256-cbc";
                                                  do {
                                                    if (iVar17 == 0) break;
                                                    iVar17 = iVar17 + -1;
                                                    bVar31 = *pbVar19 == *pbVar30;
                                                    pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                    pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                  } while (bVar31);
                                                  if (bVar31) {
LAB_0807785d:
                                                    local_26f0[21] = 1;
                                                  }
                                                  else {
                                                    iVar17 = 8;
                                                    pbVar19 = pbVar23;
                                                    pbVar30 = (byte *)"openssl";
                                                    do {
                                                      if (iVar17 == 0) break;
                                                      iVar17 = iVar17 + -1;
                                                      bVar31 = *pbVar19 == *pbVar30;
                                                      pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                      pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                    } while (bVar31);
                                                    if (bVar31) {
                                                      uVar41 = CONCAT44(0x8077890,(int)uVar41);
                                                      meth = RSA_PKCS1_SSLeay();
                                                      RSA_set_default_method(meth);
                                                      iVar16 = iVar16 + -1;
                                                    }
                                                    else {
                                                      iVar17 = 7;
                                                      pbVar19 = pbVar23;
                                                      pbVar30 = (byte *)"dsa512";
                                                      do {
                                                        if (iVar17 == 0) break;
                                                        iVar17 = iVar17 + -1;
                                                        bVar31 = *pbVar19 == *pbVar30;
                                                        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                      } while (bVar31);
                                                      if (bVar31) {
                                                        local_287c = 2;
                                                      }
                                                      else {
                                                        iVar17 = 8;
                                                        pbVar19 = pbVar23;
                                                        pbVar30 = &DAT_081f617e;
                                                        do {
                                                          if (iVar17 == 0) break;
                                                          iVar17 = iVar17 + -1;
                                                          bVar31 = *pbVar19 == *pbVar30;
                                                          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                        } while (bVar31);
                                                        if (bVar31) {
                                                          local_2878 = 2;
                                                        }
                                                        else {
                                                          iVar17 = 8;
                                                          pbVar19 = pbVar23;
                                                          pbVar30 = &DAT_081f6186;
                                                          do {
                                                            if (iVar17 == 0) break;
                                                            iVar17 = iVar17 + -1;
                                                            bVar31 = *pbVar19 == *pbVar30;
                                                            pbVar19 = pbVar19 + (uint)bVar36 * -2 +
                                                                                1;
                                                            pbVar30 = pbVar30 + (uint)bVar36 * -2 +
                                                                                1;
                                                          } while (bVar31);
                                                          if (bVar31) {
                                                            local_2874 = 2;
                                                          }
                                                          else {
                                                            iVar17 = 7;
                                                            pbVar19 = pbVar23;
                                                            pbVar30 = (byte *)"rsa512";
                                                            do {
                                                              if (iVar17 == 0) break;
                                                              iVar17 = iVar17 + -1;
                                                              bVar31 = *pbVar19 == *pbVar30;
                                                              pbVar19 = pbVar19 + (uint)bVar36 * -2
                                                                                  + 1;
                                                              pbVar30 = pbVar30 + (uint)bVar36 * -2
                                                                                  + 1;
                                                            } while (bVar31);
                                                            if (bVar31) {
                                                              local_2860 = (RSA *)0x2;
                                                            }
                                                            else {
                                                              iVar17 = 8;
                                                              pbVar19 = pbVar23;
                                                              pbVar30 = (byte *)"rsa1024";
                                                              do {
                                                                if (iVar17 == 0) break;
                                                                iVar17 = iVar17 + -1;
                                                                bVar31 = *pbVar19 == *pbVar30;
                                                                pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                                pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                              } while (bVar31);
                                                              if (bVar31) {
                                                                local_285c = 2;
                                                              }
                                                              else {
                                                                iVar17 = 8;
                                                                pbVar19 = pbVar23;
                                                                pbVar30 = (byte *)"rsa2048";
                                                                do {
                                                                  if (iVar17 == 0) break;
                                                                  iVar17 = iVar17 + -1;
                                                                  bVar31 = *pbVar19 == *pbVar30;
                                                                  pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                  pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                } while (bVar31);
                                                                if (bVar31) {
                                                                  local_2858 = 2;
                                                                }
                                                                else {
                                                                  iVar17 = 8;
                                                                  pbVar19 = pbVar23;
                                                                  pbVar30 = &DAT_081f61a5;
                                                                  do {
                                                                    if (iVar17 == 0) break;
                                                                    iVar17 = iVar17 + -1;
                                                                    bVar31 = *pbVar19 == *pbVar30;
                                                                    pbVar19 = pbVar19 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                    pbVar30 = pbVar30 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                  } while (bVar31);
                                                                  if (bVar31) {
                                                                    local_2854 = 2;
                                                                  }
                                                                  else {
                                                                    iVar17 = 8;
                                                                    pbVar19 = pbVar23;
                                                                    pbVar30 = (byte *)"rc2-cbc";
                                                                    do {
                                                                      if (iVar17 == 0) break;
                                                                      iVar17 = iVar17 + -1;
                                                                      bVar31 = *pbVar19 == *pbVar30;
                                                                      pbVar19 = pbVar19 + (uint)
                                                  bVar36 * -2 + 1;
                                                  pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                  } while (bVar31);
                                                  if ((bVar31) ||
                                                     (((bVar31 = bVar1 == 0x72, bVar31 &&
                                                       (bVar31 = pbVar23[1] == 99, bVar31)) &&
                                                      ((bVar31 = pbVar23[2] == 0x32, bVar31 &&
                                                       (bVar31 = pbVar23[3] == 0, bVar31)))))) {
                                                    local_26f0[12] = 1;
                                                  }
                                                  else {
                                                    iVar17 = 9;
                                                    pbVar19 = pbVar23;
                                                    pbVar30 = (byte *)"idea-cbc";
                                                    do {
                                                      if (iVar17 == 0) break;
                                                      iVar17 = iVar17 + -1;
                                                      bVar31 = *pbVar19 == *pbVar30;
                                                      pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                      pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                    } while (bVar31);
                                                    if (!bVar31) {
                                                      iVar17 = 5;
                                                      pbVar19 = pbVar23;
                                                      pbVar30 = &DAT_081f25f1;
                                                      do {
                                                        if (iVar17 == 0) break;
                                                        iVar17 = iVar17 + -1;
                                                        bVar31 = *pbVar19 == *pbVar30;
                                                        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                      } while (bVar31);
                                                      if (!bVar31) {
                                                        iVar17 = 9;
                                                        pbVar19 = pbVar23;
                                                        pbVar30 = (byte *)"seed-cbc";
                                                        do {
                                                          if (iVar17 == 0) break;
                                                          iVar17 = iVar17 + -1;
                                                          bVar31 = *pbVar19 == *pbVar30;
                                                          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                        } while (bVar31);
                                                        if (!bVar31) {
                                                          iVar17 = 5;
                                                          pbVar19 = pbVar23;
                                                          pbVar30 = (byte *)0x81f25f7;
                                                          do {
                                                            if (iVar17 == 0) break;
                                                            iVar17 = iVar17 + -1;
                                                            bVar31 = *pbVar19 == *pbVar30;
                                                            pbVar19 = pbVar19 + (uint)bVar36 * -2 +
                                                                                1;
                                                            pbVar30 = pbVar30 + (uint)bVar36 * -2 +
                                                                                1;
                                                          } while (bVar31);
                                                          if (!bVar31) {
                                                            iVar17 = 7;
                                                            pbVar19 = pbVar23;
                                                            pbVar30 = (byte *)"bf-cbc";
                                                            do {
                                                              if (iVar17 == 0) break;
                                                              iVar17 = iVar17 + -1;
                                                              bVar31 = *pbVar19 == *pbVar30;
                                                              pbVar19 = pbVar19 + (uint)bVar36 * -2
                                                                                  + 1;
                                                              pbVar30 = pbVar30 + (uint)bVar36 * -2
                                                                                  + 1;
                                                            } while (bVar31);
                                                            if (!bVar31) {
                                                              iVar17 = 9;
                                                              pbVar19 = pbVar23;
                                                              pbVar30 = (byte *)"blowfish";
                                                              do {
                                                                if (iVar17 == 0) break;
                                                                iVar17 = iVar17 + -1;
                                                                bVar31 = *pbVar19 == *pbVar30;
                                                                pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                                pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                              } while (bVar31);
                                                              if ((!bVar31) &&
                                                                 (((bVar31 = bVar1 == 0x62, !bVar31
                                                                   || (bVar31 = pbVar23[1] == 0x66,
                                                                      !bVar31)) ||
                                                                  (bVar31 = pbVar23[2] == 0, !bVar31
                                                                  )))) {
                                                                iVar17 = 9;
                                                                pbVar19 = pbVar23;
                                                                pbVar30 = (byte *)"cast-cbc";
                                                                do {
                                                                  if (iVar17 == 0) break;
                                                                  iVar17 = iVar17 + -1;
                                                                  bVar31 = *pbVar19 == *pbVar30;
                                                                  pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                  pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                } while (bVar31);
                                                                if (!bVar31) {
                                                                  iVar17 = 5;
                                                                  pbVar19 = pbVar23;
                                                                  pbVar30 = &DAT_081ea2f1;
                                                                  do {
                                                                    if (iVar17 == 0) break;
                                                                    iVar17 = iVar17 + -1;
                                                                    bVar31 = *pbVar19 == *pbVar30;
                                                                    pbVar19 = pbVar19 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                    pbVar30 = pbVar30 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                  } while (bVar31);
                                                                  if (!bVar31) {
                                                                    iVar17 = 6;
                                                                    pbVar19 = pbVar23;
                                                                    pbVar30 = (byte *)"cast5";
                                                                    do {
                                                                      if (iVar17 == 0) break;
                                                                      iVar17 = iVar17 + -1;
                                                                      bVar31 = *pbVar19 == *pbVar30;
                                                                      pbVar19 = pbVar19 + (uint)
                                                  bVar36 * -2 + 1;
                                                  pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                  } while (bVar31);
                                                  if (!bVar31) {
                                                    if (bVar1 == 100) {
                                                      bVar31 = pbVar23[1] == 0x65;
                                                      if (bVar31) {
                                                        if ((pbVar23[2] == 0x73) &&
                                                           (pbVar23[3] == 0)) {
                                                          local_26f0[8] = 1;
                                                          goto LAB_080776ee;
                                                        }
                                                        bVar31 = false;
                                                      }
                                                    }
                                                    else {
                                                      bVar31 = bVar1 == 0x61;
                                                      if (((bVar31) &&
                                                          (bVar31 = pbVar23[1] == 0x65, bVar31)) &&
                                                         ((bVar31 = pbVar23[2] == 0x73, bVar31 &&
                                                          (bVar31 = pbVar23[3] == 0, bVar31)))) {
                                                        local_26f0[16] = 1;
                                                        local_26f0[17] = 1;
                                                        goto LAB_0807778a;
                                                      }
                                                    }
                                                    iVar17 = 6;
                                                    pbVar19 = pbVar23;
                                                    pbVar30 = (byte *)"ghash";
                                                    do {
                                                      if (iVar17 == 0) break;
                                                      iVar17 = iVar17 + -1;
                                                      bVar31 = *pbVar19 == *pbVar30;
                                                      pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                      pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                    } while (bVar31);
                                                    if (bVar31) {
                                                      local_26f0[29] = 1;
                                                    }
                                                    else {
                                                      iVar17 = 9;
                                                      pbVar19 = pbVar23;
                                                      pbVar30 = (byte *)"camellia";
                                                      do {
                                                        if (iVar17 == 0) break;
                                                        iVar17 = iVar17 + -1;
                                                        bVar31 = *pbVar19 == *pbVar30;
                                                        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                      } while (bVar31);
                                                      if (bVar31) {
                                                        local_26f0[19] = 1;
                                                        local_26f0[20] = 1;
                                                        goto LAB_0807785d;
                                                      }
                                                      if (bVar1 == 0x72) {
                                                        bVar31 = pbVar23[1] == 0x73;
                                                        if (bVar31) {
                                                          if ((pbVar23[2] == 0x61) &&
                                                             (pbVar23[3] == 0)) {
                                                            local_2860 = (RSA *)0x1;
                                                            local_285c = 1;
                                                            local_2858 = 1;
                                                            local_2854 = 1;
                                                            goto LAB_08071079;
                                                          }
                                                          bVar31 = false;
                                                        }
                                                      }
                                                      else {
                                                        bVar31 = bVar1 == 100;
                                                        if ((((bVar31) &&
                                                             (bVar31 = pbVar23[1] == 0x73, bVar31))
                                                            && (bVar31 = pbVar23[2] == 0x61, bVar31)
                                                            ) && (bVar31 = pbVar23[3] == 0, bVar31))
                                                        {
                                                          local_287c = 1;
                                                          local_2878 = 1;
                                                          local_2874 = 1;
                                                          goto LAB_08071079;
                                                        }
                                                      }
                                                      iVar17 = 10;
                                                      pbVar19 = pbVar23;
                                                      pbVar30 = (byte *)"ecdsap160";
                                                      do {
                                                        if (iVar17 == 0) break;
                                                        iVar17 = iVar17 + -1;
                                                        bVar31 = *pbVar19 == *pbVar30;
                                                        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                      } while (bVar31);
                                                      if (bVar31) {
                                                        local_2770[0] = 2;
                                                      }
                                                      else {
                                                        iVar17 = 10;
                                                        pbVar19 = pbVar23;
                                                        pbVar30 = (byte *)"ecdsap192";
                                                        do {
                                                          if (iVar17 == 0) break;
                                                          iVar17 = iVar17 + -1;
                                                          bVar31 = *pbVar19 == *pbVar30;
                                                          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                        } while (bVar31);
                                                        if (bVar31) {
                                                          local_2770[1] = 2;
                                                        }
                                                        else {
                                                          iVar17 = 10;
                                                          pbVar19 = pbVar23;
                                                          pbVar30 = (byte *)"ecdsap224";
                                                          do {
                                                            if (iVar17 == 0) break;
                                                            iVar17 = iVar17 + -1;
                                                            bVar31 = *pbVar19 == *pbVar30;
                                                            pbVar19 = pbVar19 + (uint)bVar36 * -2 +
                                                                                1;
                                                            pbVar30 = pbVar30 + (uint)bVar36 * -2 +
                                                                                1;
                                                          } while (bVar31);
                                                          if (bVar31) {
                                                            local_2770[2] = 2;
                                                          }
                                                          else {
                                                            iVar17 = 10;
                                                            pbVar19 = pbVar23;
                                                            pbVar30 = (byte *)"ecdsap256";
                                                            do {
                                                              if (iVar17 == 0) break;
                                                              iVar17 = iVar17 + -1;
                                                              bVar31 = *pbVar19 == *pbVar30;
                                                              pbVar19 = pbVar19 + (uint)bVar36 * -2
                                                                                  + 1;
                                                              pbVar30 = pbVar30 + (uint)bVar36 * -2
                                                                                  + 1;
                                                            } while (bVar31);
                                                            if (bVar31) {
                                                              local_2770[3] = 2;
                                                            }
                                                            else {
                                                              iVar17 = 10;
                                                              pbVar19 = pbVar23;
                                                              pbVar30 = (byte *)"ecdsap384";
                                                              do {
                                                                if (iVar17 == 0) break;
                                                                iVar17 = iVar17 + -1;
                                                                bVar31 = *pbVar19 == *pbVar30;
                                                                pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                                pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                              } while (bVar31);
                                                              if (bVar31) {
                                                                local_2770[4] = 2;
                                                              }
                                                              else {
                                                                iVar17 = 10;
                                                                pbVar19 = pbVar23;
                                                                pbVar30 = (byte *)"ecdsap521";
                                                                do {
                                                                  if (iVar17 == 0) break;
                                                                  iVar17 = iVar17 + -1;
                                                                  bVar31 = *pbVar19 == *pbVar30;
                                                                  pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                  pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                } while (bVar31);
                                                                if (bVar31) {
                                                                  local_2770[5] = 2;
                                                                }
                                                                else {
                                                                  iVar17 = 10;
                                                                  pbVar19 = pbVar23;
                                                                  pbVar30 = (byte *)"ecdsak163";
                                                                  do {
                                                                    if (iVar17 == 0) break;
                                                                    iVar17 = iVar17 + -1;
                                                                    bVar31 = *pbVar19 == *pbVar30;
                                                                    pbVar19 = pbVar19 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                    pbVar30 = pbVar30 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                  } while (bVar31);
                                                                  if (bVar31) {
                                                                    local_2770[6] = 2;
                                                                  }
                                                                  else {
                                                                    iVar17 = 10;
                                                                    pbVar19 = pbVar23;
                                                                    pbVar30 = (byte *)"ecdsak233";
                                                                    do {
                                                                      if (iVar17 == 0) break;
                                                                      iVar17 = iVar17 + -1;
                                                                      bVar31 = *pbVar19 == *pbVar30;
                                                                      pbVar19 = pbVar19 + (uint)
                                                  bVar36 * -2 + 1;
                                                  pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                  } while (bVar31);
                                                  if (bVar31) {
                                                    local_2770[7] = 2;
                                                  }
                                                  else {
                                                    iVar17 = 10;
                                                    pbVar19 = pbVar23;
                                                    pbVar30 = (byte *)"ecdsak283";
                                                    do {
                                                      if (iVar17 == 0) break;
                                                      iVar17 = iVar17 + -1;
                                                      bVar31 = *pbVar19 == *pbVar30;
                                                      pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                      pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                    } while (bVar31);
                                                    if (bVar31) {
                                                      local_2770[8] = 2;
                                                    }
                                                    else {
                                                      iVar17 = 10;
                                                      pbVar19 = pbVar23;
                                                      pbVar30 = (byte *)"ecdsak409";
                                                      do {
                                                        if (iVar17 == 0) break;
                                                        iVar17 = iVar17 + -1;
                                                        bVar31 = *pbVar19 == *pbVar30;
                                                        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                      } while (bVar31);
                                                      if (bVar31) {
                                                        local_2770[9] = 2;
                                                      }
                                                      else {
                                                        iVar17 = 10;
                                                        pbVar19 = pbVar23;
                                                        pbVar30 = (byte *)"ecdsak571";
                                                        do {
                                                          if (iVar17 == 0) break;
                                                          iVar17 = iVar17 + -1;
                                                          bVar31 = *pbVar19 == *pbVar30;
                                                          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                        } while (bVar31);
                                                        if (bVar31) {
                                                          local_2770[10] = 2;
                                                        }
                                                        else {
                                                          iVar17 = 10;
                                                          pbVar19 = pbVar23;
                                                          pbVar30 = (byte *)"ecdsab163";
                                                          do {
                                                            if (iVar17 == 0) break;
                                                            iVar17 = iVar17 + -1;
                                                            bVar31 = *pbVar19 == *pbVar30;
                                                            pbVar19 = pbVar19 + (uint)bVar36 * -2 +
                                                                                1;
                                                            pbVar30 = pbVar30 + (uint)bVar36 * -2 +
                                                                                1;
                                                          } while (bVar31);
                                                          if (bVar31) {
                                                            local_2770[11] = 2;
                                                          }
                                                          else {
                                                            iVar17 = 10;
                                                            pbVar19 = pbVar23;
                                                            pbVar30 = (byte *)"ecdsab233";
                                                            do {
                                                              if (iVar17 == 0) break;
                                                              iVar17 = iVar17 + -1;
                                                              bVar31 = *pbVar19 == *pbVar30;
                                                              pbVar19 = pbVar19 + (uint)bVar36 * -2
                                                                                  + 1;
                                                              pbVar30 = pbVar30 + (uint)bVar36 * -2
                                                                                  + 1;
                                                            } while (bVar31);
                                                            if (bVar31) {
                                                              local_2770[12] = 2;
                                                            }
                                                            else {
                                                              iVar17 = 10;
                                                              pbVar19 = pbVar23;
                                                              pbVar30 = (byte *)"ecdsab283";
                                                              do {
                                                                if (iVar17 == 0) break;
                                                                iVar17 = iVar17 + -1;
                                                                bVar31 = *pbVar19 == *pbVar30;
                                                                pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                                pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                              } while (bVar31);
                                                              if (bVar31) {
                                                                local_2770[13] = 2;
                                                              }
                                                              else {
                                                                iVar17 = 10;
                                                                pbVar19 = pbVar23;
                                                                pbVar30 = (byte *)"ecdsab409";
                                                                do {
                                                                  if (iVar17 == 0) break;
                                                                  iVar17 = iVar17 + -1;
                                                                  bVar31 = *pbVar19 == *pbVar30;
                                                                  pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                  pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                } while (bVar31);
                                                                if (bVar31) {
                                                                  local_2770[14] = 2;
                                                                }
                                                                else {
                                                                  iVar17 = 10;
                                                                  pbVar19 = pbVar23;
                                                                  pbVar30 = (byte *)"ecdsab571";
                                                                  do {
                                                                    if (iVar17 == 0) break;
                                                                    iVar17 = iVar17 + -1;
                                                                    bVar31 = *pbVar19 == *pbVar30;
                                                                    pbVar19 = pbVar19 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                    pbVar30 = pbVar30 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                  } while (bVar31);
                                                                  if (bVar31) {
                                                                    local_2770[15] = 2;
                                                                  }
                                                                  else {
                                                                    iVar17 = 6;
                                                                    pbVar19 = pbVar23;
                                                                    pbVar30 = &DAT_081f626b;
                                                                    do {
                                                                      if (iVar17 == 0) break;
                                                                      iVar17 = iVar17 + -1;
                                                                      bVar31 = *pbVar19 == *pbVar30;
                                                                      pbVar19 = pbVar19 + (uint)
                                                  bVar36 * -2 + 1;
                                                  pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                  } while (bVar31);
                                                  if (bVar31) {
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
                                                    iVar17 = 9;
                                                    pbVar19 = pbVar23;
                                                    pbVar30 = (byte *)"ecdhp160";
                                                    do {
                                                      if (iVar17 == 0) break;
                                                      iVar17 = iVar17 + -1;
                                                      bVar31 = *pbVar19 == *pbVar30;
                                                      pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                      pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                    } while (bVar31);
                                                    if (bVar31) {
                                                      local_2730[0] = 2;
                                                    }
                                                    else {
                                                      iVar17 = 9;
                                                      pbVar19 = pbVar23;
                                                      pbVar30 = (byte *)"ecdhp192";
                                                      do {
                                                        if (iVar17 == 0) break;
                                                        iVar17 = iVar17 + -1;
                                                        bVar31 = *pbVar19 == *pbVar30;
                                                        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                      } while (bVar31);
                                                      if (bVar31) {
                                                        local_2730[1] = 2;
                                                      }
                                                      else {
                                                        iVar17 = 9;
                                                        pbVar19 = pbVar23;
                                                        pbVar30 = (byte *)"ecdhp224";
                                                        do {
                                                          if (iVar17 == 0) break;
                                                          iVar17 = iVar17 + -1;
                                                          bVar31 = *pbVar19 == *pbVar30;
                                                          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                        } while (bVar31);
                                                        if (bVar31) {
                                                          local_2730[2] = 2;
                                                        }
                                                        else {
                                                          iVar17 = 9;
                                                          pbVar19 = pbVar23;
                                                          pbVar30 = (byte *)"ecdhp256";
                                                          do {
                                                            if (iVar17 == 0) break;
                                                            iVar17 = iVar17 + -1;
                                                            bVar31 = *pbVar19 == *pbVar30;
                                                            pbVar19 = pbVar19 + (uint)bVar36 * -2 +
                                                                                1;
                                                            pbVar30 = pbVar30 + (uint)bVar36 * -2 +
                                                                                1;
                                                          } while (bVar31);
                                                          if (bVar31) {
                                                            local_2730[3] = 2;
                                                          }
                                                          else {
                                                            iVar17 = 9;
                                                            pbVar19 = pbVar23;
                                                            pbVar30 = (byte *)"ecdhp384";
                                                            do {
                                                              if (iVar17 == 0) break;
                                                              iVar17 = iVar17 + -1;
                                                              bVar31 = *pbVar19 == *pbVar30;
                                                              pbVar19 = pbVar19 + (uint)bVar36 * -2
                                                                                  + 1;
                                                              pbVar30 = pbVar30 + (uint)bVar36 * -2
                                                                                  + 1;
                                                            } while (bVar31);
                                                            if (bVar31) {
                                                              local_2730[4] = 2;
                                                            }
                                                            else {
                                                              iVar17 = 9;
                                                              pbVar19 = pbVar23;
                                                              pbVar30 = (byte *)"ecdhp521";
                                                              do {
                                                                if (iVar17 == 0) break;
                                                                iVar17 = iVar17 + -1;
                                                                bVar31 = *pbVar19 == *pbVar30;
                                                                pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                                pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                              } while (bVar31);
                                                              if (bVar31) {
                                                                local_2730[5] = 2;
                                                              }
                                                              else {
                                                                iVar17 = 9;
                                                                pbVar19 = pbVar23;
                                                                pbVar30 = (byte *)"ecdhk163";
                                                                do {
                                                                  if (iVar17 == 0) break;
                                                                  iVar17 = iVar17 + -1;
                                                                  bVar31 = *pbVar19 == *pbVar30;
                                                                  pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                  pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                } while (bVar31);
                                                                if (bVar31) {
                                                                  local_2730[6] = 2;
                                                                }
                                                                else {
                                                                  iVar17 = 9;
                                                                  pbVar19 = pbVar23;
                                                                  pbVar30 = (byte *)"ecdhk233";
                                                                  do {
                                                                    if (iVar17 == 0) break;
                                                                    iVar17 = iVar17 + -1;
                                                                    bVar31 = *pbVar19 == *pbVar30;
                                                                    pbVar19 = pbVar19 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                    pbVar30 = pbVar30 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                  } while (bVar31);
                                                                  if (bVar31) {
                                                                    local_2730[7] = 2;
                                                                  }
                                                                  else {
                                                                    iVar17 = 9;
                                                                    pbVar19 = pbVar23;
                                                                    pbVar30 = (byte *)"ecdhk283";
                                                                    do {
                                                                      if (iVar17 == 0) break;
                                                                      iVar17 = iVar17 + -1;
                                                                      bVar31 = *pbVar19 == *pbVar30;
                                                                      pbVar19 = pbVar19 + (uint)
                                                  bVar36 * -2 + 1;
                                                  pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                  } while (bVar31);
                                                  if (bVar31) {
                                                    local_2730[8] = 2;
                                                  }
                                                  else {
                                                    iVar17 = 9;
                                                    pbVar19 = pbVar23;
                                                    pbVar30 = (byte *)"ecdhk409";
                                                    do {
                                                      if (iVar17 == 0) break;
                                                      iVar17 = iVar17 + -1;
                                                      bVar31 = *pbVar19 == *pbVar30;
                                                      pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                      pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                    } while (bVar31);
                                                    if (bVar31) {
                                                      local_2730[9] = 2;
                                                    }
                                                    else {
                                                      iVar17 = 9;
                                                      pbVar19 = pbVar23;
                                                      pbVar30 = (byte *)"ecdhk571";
                                                      do {
                                                        if (iVar17 == 0) break;
                                                        iVar17 = iVar17 + -1;
                                                        bVar31 = *pbVar19 == *pbVar30;
                                                        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                      } while (bVar31);
                                                      if (bVar31) {
                                                        local_2730[10] = 2;
                                                      }
                                                      else {
                                                        iVar17 = 9;
                                                        pbVar19 = pbVar23;
                                                        pbVar30 = (byte *)"ecdhb163";
                                                        do {
                                                          if (iVar17 == 0) break;
                                                          iVar17 = iVar17 + -1;
                                                          bVar31 = *pbVar19 == *pbVar30;
                                                          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                                                          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
                                                        } while (bVar31);
                                                        if (bVar31) {
                                                          local_2730[11] = 2;
                                                        }
                                                        else {
                                                          iVar17 = 9;
                                                          pbVar19 = pbVar23;
                                                          pbVar30 = (byte *)"ecdhb233";
                                                          do {
                                                            if (iVar17 == 0) break;
                                                            iVar17 = iVar17 + -1;
                                                            bVar31 = *pbVar19 == *pbVar30;
                                                            pbVar19 = pbVar19 + (uint)bVar36 * -2 +
                                                                                1;
                                                            pbVar30 = pbVar30 + (uint)bVar36 * -2 +
                                                                                1;
                                                          } while (bVar31);
                                                          if (bVar31) {
                                                            local_2730[12] = 2;
                                                          }
                                                          else {
                                                            iVar17 = 9;
                                                            pbVar19 = pbVar23;
                                                            pbVar30 = (byte *)"ecdhb283";
                                                            do {
                                                              if (iVar17 == 0) break;
                                                              iVar17 = iVar17 + -1;
                                                              bVar31 = *pbVar19 == *pbVar30;
                                                              pbVar19 = pbVar19 + (uint)bVar36 * -2
                                                                                  + 1;
                                                              pbVar30 = pbVar30 + (uint)bVar36 * -2
                                                                                  + 1;
                                                            } while (bVar31);
                                                            if (bVar31) {
                                                              local_2730[13] = 2;
                                                            }
                                                            else {
                                                              iVar17 = 9;
                                                              pbVar19 = pbVar23;
                                                              pbVar30 = (byte *)"ecdhb409";
                                                              do {
                                                                if (iVar17 == 0) break;
                                                                iVar17 = iVar17 + -1;
                                                                bVar31 = *pbVar19 == *pbVar30;
                                                                pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                                pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                    -2 + 1;
                                                              } while (bVar31);
                                                              if (bVar31) {
                                                                local_2730[14] = 2;
                                                              }
                                                              else {
                                                                iVar17 = 9;
                                                                pbVar19 = pbVar23;
                                                                pbVar30 = (byte *)"ecdhb571";
                                                                do {
                                                                  if (iVar17 == 0) break;
                                                                  iVar17 = iVar17 + -1;
                                                                  bVar31 = *pbVar19 == *pbVar30;
                                                                  pbVar19 = pbVar19 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                  pbVar30 = pbVar30 + (uint)bVar36 *
                                                                                      -2 + 1;
                                                                } while (bVar31);
                                                                if (bVar31) {
                                                                  local_2730[15] = 2;
                                                                }
                                                                else {
                                                                  iVar17 = 5;
                                                                  pbVar19 = &DAT_081f6301;
                                                                  do {
                                                                    if (iVar17 == 0) break;
                                                                    iVar17 = iVar17 + -1;
                                                                    bVar31 = *pbVar23 == *pbVar19;
                                                                    pbVar23 = pbVar23 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                    pbVar19 = pbVar19 + (uint)bVar36
                                                                                        * -2 + 1;
                                                                  } while (bVar31);
                                                                  if (!bVar31) {
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
                                                  "ecdhp160  ecdhp192  ecdhp224  ecdhp256  ecdhp384  ecdhp521\n"
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
                                                  pcVar39 = 
                                                  "-multi n        run n benchmarks in parallel.\n";
                                                  goto LAB_0807187d;
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
                                                  goto LAB_08071079;
                                                  }
                                                  }
                                                  }
                                                  local_26f0[15] = 1;
                                                  goto LAB_08071079;
                                                  }
                                                  }
                                                  local_26f0[14] = 1;
                                                  goto LAB_08071079;
                                                  }
                                                  }
                                                  local_26f0[11] = 1;
                                                  goto LAB_08071079;
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
                            }
                            goto LAB_08071079;
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
      }
    }
    else {
      iVar17 = 9;
      pbVar19 = pbVar23;
      pbVar30 = (byte *)"-elapsed";
      do {
        if (iVar17 == 0) break;
        iVar17 = iVar17 + -1;
        bVar31 = *pbVar19 < *pbVar30;
        bVar34 = *pbVar19 == *pbVar30;
        pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
        pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
      } while (bVar34);
      bVar31 = (!bVar31 && !bVar34) == bVar31;
      if (bVar31) {
        iVar16 = iVar16 + -1;
        usertime = (code *)0x0;
      }
      else {
        iVar17 = 5;
        pbVar19 = pbVar23;
        pbVar30 = &DAT_081f60d0;
        do {
          if (iVar17 == 0) break;
          iVar17 = iVar17 + -1;
          bVar31 = *pbVar19 == *pbVar30;
          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
        } while (bVar31);
        if (bVar31) {
          param_1 = param_1 + -1;
          ppbVar21 = param_2 + 2;
          if (param_1 == 0) {
            pcVar39 = "no EVP given\n";
          }
          else {
            cipher = EVP_get_cipherbyname((char *)param_2[2]);
            if ((cipher != (EVP_CIPHER *)0x0) ||
               (type_00 = EVP_get_digestbyname((char *)param_2[2]), type_00 != (EVP_MD *)0x0)) {
              local_26f0[22] = 1;
              goto LAB_08071079;
            }
            uVar41 = uVar41 & 0xffffffff00000000 | ZEXT48(param_2[2]);
            pcVar39 = "%s is an unknown cipher or digest\n";
          }
          goto LAB_0807187d;
        }
        iVar17 = 9;
        pbVar19 = pbVar23;
        pbVar30 = (byte *)"-decrypt";
        do {
          if (iVar17 == 0) break;
          iVar17 = iVar17 + -1;
          bVar31 = *pbVar19 == *pbVar30;
          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
          pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
        } while (bVar31);
        if (bVar31) {
          iVar16 = iVar16 + -1;
          bVar33 = true;
        }
        else {
          iVar17 = 8;
          pbVar19 = pbVar23;
          pbVar30 = (byte *)"-engine";
          do {
            if (iVar17 == 0) break;
            iVar17 = iVar17 + -1;
            bVar31 = *pbVar19 == *pbVar30;
            pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
            pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
          } while (bVar31);
          uVar3 = (uint)(uVar41 >> 0x20);
          if (bVar31) {
            param_1 = param_1 + -1;
            ppbVar21 = param_2 + 2;
            if (param_1 == 0) {
              pcVar39 = "no engine given\n";
              goto LAB_0807187d;
            }
            uVar41 = (ulonglong)uVar3 << 0x20;
            setup_engine(bio_err,param_2[2],0);
            iVar16 = iVar16 + -1;
          }
          else {
            iVar17 = 7;
            pbVar19 = pbVar23;
            pbVar30 = (byte *)"-multi";
            do {
              if (iVar17 == 0) break;
              iVar17 = iVar17 + -1;
              bVar31 = *pbVar19 == *pbVar30;
              pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
              pbVar30 = pbVar30 + (uint)bVar36 * -2 + 1;
            } while (bVar31);
            if (bVar31) {
              param_1 = param_1 + -1;
              ppbVar21 = param_2 + 2;
              if (param_1 == 0) {
                pcVar39 = "no multi count given\n";
              }
              else {
                uVar41 = CONCAT44(uVar3,10);
                local_28b8 = strtol((char *)param_2[2],(char **)0x0,10);
                if (0 < local_28b8) {
                  iVar16 = iVar16 + -1;
                  goto LAB_08071079;
                }
                pcVar39 = "bad multi count\n";
              }
LAB_0807187d:
              uVar20 = 1;
              BIO_printf(bio_err,pcVar39,uVar41);
              goto LAB_0807189c;
            }
            bVar34 = *pbVar23 == 0x2d;
            if ((((!bVar34) || (bVar34 = pbVar23[1] == 0x6d, !bVar34)) ||
                (bVar34 = pbVar23[2] == 0x72, !bVar34)) || (bVar34 = pbVar23[3] == 0, !bVar34))
            goto LAB_08071240;
            mr = 1;
            iVar16 = iVar16 + -1;
          }
        }
      }
    }
LAB_08071079:
    iVar16 = iVar16 + 1;
    param_1 = param_1 + -1;
    param_2 = ppbVar21;
  } while (param_1 != 0);
  pcVar40 = usertime;
  if (local_28b8 == 0) {
LAB_080712b5:
    if (iVar16 == 0) goto LAB_080712c3;
    goto LAB_08071474;
  }
  __ptr = malloc(local_28b8 << 2);
  iVar17 = 0;
  do {
    iVar8 = pipe((int *)&local_17d8);
    if (iVar8 == -1) {
      fwrite("pipe failure\n",1,0xd,stderr);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    fflush(stdout);
    fflush(stderr);
    pcVar40 = (code *)fork();
    if (pcVar40 == (code *)0x0) {
      close(local_17d8.P[0]);
      close(1);
      iVar17 = dup(local_17d8.P[1]);
      if (iVar17 == -1) {
        fwrite("dup failed\n",1,0xb,stderr);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      close(local_17d8.P[1]);
      mr = 1;
      usertime = (code *)0x0;
      free(__ptr);
      goto LAB_080712b5;
    }
    close(local_17d8.P[1]);
    *(uint *)((int)__ptr + iVar17 * 4) = local_17d8.P[0];
    iVar8 = iVar17 + 1;
    __printf_chk(1,"Forked child %d\n",iVar17);
    iVar17 = iVar8;
  } while (iVar8 < local_28b8);
  iVar16 = 0;
  do {
    pFVar13 = fdopen(*(int *)((int)__ptr + iVar16 * 4),"r");
LAB_08076330:
    pcVar39 = (char *)0x400;
    dVar43 = (double)ZEXT48(pFVar13);
    pcVar7 = fgets((char *)local_420,0x400,pFVar13);
    if (pcVar7 != (char *)0x0) {
      pcVar39 = strchr((char *)local_420,10);
      if (pcVar39 != (char *)0x0) {
        *pcVar39 = '\0';
      }
      uVar32 = local_420[0] < 0x2b;
      uVar35 = local_420[0] == 0x2b;
      if ((bool)uVar35) {
        __printf_chk(1,"Got: %s from %d\n",local_420);
        iVar17 = 3;
        pbVar23 = local_420;
        pbVar19 = &DAT_081f6486;
        do {
          if (iVar17 == 0) break;
          iVar17 = iVar17 + -1;
          uVar32 = *pbVar23 < *pbVar19;
          uVar35 = *pbVar23 == *pbVar19;
          pbVar23 = pbVar23 + (uint)bVar36 * -2 + 1;
          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
        } while ((bool)uVar35);
        bVar33 = false;
        bVar31 = (!(bool)uVar32 && !(bool)uVar35) == (bool)uVar32;
        if (bVar31) {
          uVar3 = (uint)local_420[3];
          if (local_420[3] == 0) {
            pbVar23 = local_420 + 3;
            pbVar19 = (byte *)0x0;
          }
          else {
            puVar29 = &local_520;
            for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
              *puVar29 = 0;
              puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar18 = &sep_19180;
            bVar1 = (byte)sep_19180;
            while (bVar1 != 0) {
              puVar18 = (undefined2 *)((int)puVar18 + 1);
              *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
              bVar1 = *(byte *)puVar18;
            }
            pbVar23 = local_420 + 3;
            if (*(char *)((int)&local_520 + uVar3) == '\0') {
              do {
                pbVar23 = pbVar23 + 1;
              } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
              pbVar19 = local_420 + 3;
              if (*pbVar23 == 0) goto LAB_080765b8;
            }
            pbVar19 = local_420 + 3;
            *pbVar23 = 0;
            pbVar23 = pbVar23 + 1;
          }
LAB_080765b8:
          lVar14 = strtol((char *)pbVar19,(char **)0x0,10);
          uVar3 = (uint)*pbVar23;
          if (*pbVar23 != 0) {
            puVar29 = &local_520;
            for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
              *puVar29 = 0;
              puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar18 = &sep_19180;
            bVar1 = (byte)sep_19180;
            while (bVar1 != 0) {
              puVar18 = (undefined2 *)((int)puVar18 + 1);
              *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
              bVar1 = *(byte *)puVar18;
            }
            if (*(char *)((int)&local_520 + uVar3) == '\0') {
              do {
                pbVar23 = pbVar23 + 1;
                uVar3 = (uint)*pbVar23;
              } while (*(char *)((int)&local_520 + uVar3) == '\0');
              if (*pbVar23 == 0) goto LAB_08076640;
            }
            *pbVar23 = 0;
            uVar3 = (uint)pbVar23[1];
            pbVar23 = pbVar23 + 1;
          }
LAB_08076640:
          pdVar26 = (double *)(results + lVar14 * 0x28);
          do {
            pbVar19 = (byte *)0x0;
            if ((char)uVar3 != '\0') {
              puVar29 = &local_520;
              for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                *puVar29 = 0;
                puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar18 = &sep_19180;
              bVar1 = (byte)sep_19180;
              while (bVar1 != 0) {
                puVar18 = (undefined2 *)((int)puVar18 + 1);
                *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
                bVar1 = *(byte *)puVar18;
              }
              pbVar19 = pbVar23;
              if (*(char *)((int)&local_520 + uVar3) == '\0') {
                do {
                  pbVar23 = pbVar23 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                if (*pbVar23 == 0) goto LAB_080766e4;
              }
              *pbVar23 = 0;
              pbVar23 = pbVar23 + 1;
            }
LAB_080766e4:
            dVar38 = strtod((char *)pbVar19,(char **)0x0);
            *pdVar26 = dVar38 + *pdVar26;
            if (pdVar26 + 1 == (double *)(results + lVar14 * 0x28 + 0x28)) goto LAB_08076330;
            uVar3 = (uint)*pbVar23;
            pdVar26 = pdVar26 + 1;
          } while( true );
        }
        iVar17 = 4;
        pbVar23 = local_420;
        pbVar19 = &DAT_081f648a;
        do {
          if (iVar17 == 0) break;
          iVar17 = iVar17 + -1;
          bVar33 = *pbVar23 < *pbVar19;
          bVar31 = *pbVar23 == *pbVar19;
          pbVar23 = pbVar23 + (uint)bVar36 * -2 + 1;
          pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
        } while (bVar31);
        bVar34 = false;
        bVar33 = (!bVar33 && !bVar31) == bVar33;
        if (bVar33) {
          uVar3 = (uint)local_41c[0];
          if (local_41c[0] == 0) {
            pbVar23 = local_41c;
            pbVar19 = (byte *)0x0;
          }
          else {
            puVar29 = &local_520;
            for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
              *puVar29 = 0;
              puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar18 = &sep_19180;
            bVar1 = (byte)sep_19180;
            while (bVar1 != 0) {
              puVar18 = (undefined2 *)((int)puVar18 + 1);
              *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
              bVar1 = *(byte *)puVar18;
            }
            pbVar23 = local_41c;
            if (*(char *)((int)&local_520 + uVar3) == '\0') {
              do {
                pbVar23 = pbVar23 + 1;
              } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
              pbVar19 = local_41c;
              if (*pbVar23 == 0) goto LAB_080767b0;
            }
            pbVar19 = local_41c;
            *pbVar23 = 0;
            pbVar23 = pbVar23 + 1;
          }
LAB_080767b0:
          lVar14 = strtol((char *)pbVar19,(char **)0x0,10);
          bVar1 = *pbVar23;
          if (bVar1 == 0) {
LAB_08076a03:
            pbVar19 = (byte *)0x0;
          }
          else {
            uVar3 = (uint)(byte)sep_19180;
            puVar29 = &local_520;
            for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
              *puVar29 = 0;
              puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar18 = &sep_19180;
            uVar15 = uVar3;
            bVar2 = (byte)sep_19180;
            while (bVar2 != 0) {
              puVar18 = (undefined2 *)((int)puVar18 + 1);
              *(undefined *)((int)&local_520 + uVar15) = 1;
              bVar2 = *(byte *)puVar18;
              uVar15 = (uint)bVar2;
            }
            if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
              do {
                pbVar23 = pbVar23 + 1;
              } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
              if (*pbVar23 == 0) goto LAB_08076a03;
            }
            *pbVar23 = 0;
            pbVar19 = pbVar23 + 1;
            bVar1 = pbVar23[1];
            pbVar23 = pbVar19;
            if (bVar1 == 0) goto LAB_08076a03;
            puVar29 = &local_520;
            for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
              *puVar29 = 0;
              puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
            }
            local_520._0_1_ = 1;
            puVar18 = &sep_19180;
            bVar2 = (byte)sep_19180;
            while (bVar2 != 0) {
              puVar18 = (undefined2 *)((int)puVar18 + 1);
              *(undefined *)((int)&local_520 + uVar3) = 1;
              bVar2 = *(byte *)puVar18;
              uVar3 = (uint)bVar2;
            }
            if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
              do {
                pbVar23 = pbVar23 + 1;
              } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
              if (*pbVar23 != 0) goto LAB_080768ee;
            }
            else {
LAB_080768ee:
              *pbVar23 = 0;
              pbVar23 = pbVar23 + 1;
            }
          }
          dVar38 = strtod((char *)pbVar19,(char **)0x0);
          iVar17 = lVar14 * 0x10;
          if (iVar16 == 0) {
            bVar1 = *pbVar23;
            *(double *)(rsa_results + iVar17) = dVar38;
            if (bVar1 != 0) goto LAB_0807693e;
            dVar38 = strtod((char *)0x0,(char **)0x0);
LAB_0807766a:
            *(double *)(rsa_results + lVar14 * 0x10 + 8) = dVar38;
          }
          else {
            bVar1 = *pbVar23;
            *(double *)(rsa_results + iVar17) =
                 1.0 / (1.0 / dVar38 + 1.0 / *(double *)(rsa_results + iVar17));
            if (bVar1 == 0) {
              dVar38 = strtod((char *)0x0,(char **)0x0);
            }
            else {
LAB_0807693e:
              puVar29 = &local_520;
              for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                *puVar29 = 0;
                puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar18 = &sep_19180;
              bVar2 = (byte)sep_19180;
              while (bVar2 != 0) {
                puVar18 = (undefined2 *)((int)puVar18 + 1);
                *(undefined *)((int)&local_520 + (uint)bVar2) = 1;
                bVar2 = *(byte *)puVar18;
              }
              pbVar19 = pbVar23;
              if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                do {
                  pbVar19 = pbVar19 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar19) == '\0');
                if (*pbVar19 != 0) goto LAB_080769bc;
              }
              else {
LAB_080769bc:
                *pbVar19 = 0;
              }
              dVar38 = strtod((char *)pbVar23,(char **)0x0);
              if (iVar16 == 0) goto LAB_0807766a;
            }
            *(double *)(rsa_results + lVar14 * 0x10 + 8) =
                 1.0 / (1.0 / dVar38 + 1.0 / *(double *)(rsa_results + lVar14 * 0x10 + 8));
          }
        }
        else {
          iVar17 = 4;
          pbVar23 = local_420;
          pbVar19 = &DAT_081f648f;
          do {
            if (iVar17 == 0) break;
            iVar17 = iVar17 + -1;
            bVar34 = *pbVar23 < *pbVar19;
            bVar33 = *pbVar23 == *pbVar19;
            pbVar23 = pbVar23 + (uint)bVar36 * -2 + 1;
            pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
          } while (bVar33);
          bVar31 = false;
          bVar33 = (!bVar34 && !bVar33) == bVar34;
          if (bVar33) {
            uVar3 = (uint)local_41c[0];
            if (local_41c[0] == 0) {
              pbVar23 = local_41c;
              pbVar19 = (byte *)0x0;
            }
            else {
              puVar29 = &local_520;
              for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                *puVar29 = 0;
                puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar18 = &sep_19180;
              bVar1 = (byte)sep_19180;
              while (bVar1 != 0) {
                puVar18 = (undefined2 *)((int)puVar18 + 1);
                *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
                bVar1 = *(byte *)puVar18;
              }
              pbVar23 = local_41c;
              if (*(char *)((int)&local_520 + uVar3) == '\0') {
                do {
                  pbVar23 = pbVar23 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                pbVar19 = local_41c;
                if (*pbVar23 == 0) goto LAB_08076a90;
              }
              pbVar19 = local_41c;
              *pbVar23 = 0;
              pbVar23 = pbVar23 + 1;
            }
LAB_08076a90:
            lVar14 = strtol((char *)pbVar19,(char **)0x0,10);
            bVar1 = *pbVar23;
            if (bVar1 == 0) {
LAB_08076f66:
              pbVar19 = (byte *)0x0;
            }
            else {
              uVar3 = (uint)(byte)sep_19180;
              puVar29 = &local_520;
              for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                *puVar29 = 0;
                puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar18 = &sep_19180;
              uVar15 = uVar3;
              bVar2 = (byte)sep_19180;
              while (bVar2 != 0) {
                puVar18 = (undefined2 *)((int)puVar18 + 1);
                *(undefined *)((int)&local_520 + uVar15) = 1;
                bVar2 = *(byte *)puVar18;
                uVar15 = (uint)bVar2;
              }
              if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                do {
                  pbVar23 = pbVar23 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                if (*pbVar23 == 0) goto LAB_08076f66;
              }
              pbVar19 = pbVar23 + 1;
              *pbVar23 = 0;
              bVar1 = pbVar23[1];
              pbVar23 = pbVar19;
              if (bVar1 == 0) goto LAB_08076f66;
              puVar29 = &local_520;
              for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                *puVar29 = 0;
                puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
              }
              local_520._0_1_ = 1;
              puVar18 = &sep_19180;
              bVar2 = (byte)sep_19180;
              while (bVar2 != 0) {
                puVar18 = (undefined2 *)((int)puVar18 + 1);
                *(undefined *)((int)&local_520 + uVar3) = 1;
                bVar2 = *(byte *)puVar18;
                uVar3 = (uint)bVar2;
              }
              if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                do {
                  pbVar23 = pbVar23 + 1;
                } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                if (*pbVar23 != 0) goto LAB_08076bb6;
              }
              else {
LAB_08076bb6:
                *pbVar23 = 0;
                pbVar23 = pbVar23 + 1;
              }
            }
            dVar38 = strtod((char *)pbVar19,(char **)0x0);
            iVar17 = lVar14 * 0x10;
            if (iVar16 == 0) {
              bVar1 = *pbVar23;
              *(double *)(dsa_results + iVar17) = dVar38;
              if (bVar1 != 0) goto LAB_08076c00;
              dVar38 = strtod((char *)0x0,(char **)0x0);
LAB_080775b7:
              *(double *)(dsa_results + lVar14 * 0x10 + 8) = dVar38;
            }
            else {
              bVar1 = *pbVar23;
              *(double *)(dsa_results + iVar17) =
                   1.0 / (1.0 / dVar38 + 1.0 / *(double *)(dsa_results + iVar17));
              if (bVar1 == 0) {
                dVar38 = strtod((char *)0x0,(char **)0x0);
              }
              else {
LAB_08076c00:
                puVar29 = &local_520;
                for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                  *puVar29 = 0;
                  puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
                }
                local_520._0_1_ = 1;
                puVar18 = &sep_19180;
                bVar2 = (byte)sep_19180;
                while (bVar2 != 0) {
                  puVar18 = (undefined2 *)((int)puVar18 + 1);
                  *(undefined *)((int)&local_520 + (uint)bVar2) = 1;
                  bVar2 = *(byte *)puVar18;
                }
                pbVar19 = pbVar23;
                if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                  do {
                    pbVar19 = pbVar19 + 1;
                  } while (*(char *)((int)&local_520 + (uint)*pbVar19) == '\0');
                  if (*pbVar19 != 0) goto LAB_08076c64;
                }
                else {
LAB_08076c64:
                  *pbVar19 = 0;
                }
                dVar38 = strtod((char *)pbVar23,(char **)0x0);
                if (iVar16 == 0) goto LAB_080775b7;
              }
              *(double *)(dsa_results + lVar14 * 0x10 + 8) =
                   1.0 / (1.0 / dVar38 + 1.0 / *(double *)(dsa_results + lVar14 * 0x10 + 8));
            }
          }
          else {
            iVar17 = 4;
            pbVar23 = local_420;
            pbVar19 = &DAT_081f6494;
            do {
              if (iVar17 == 0) break;
              iVar17 = iVar17 + -1;
              bVar31 = *pbVar23 < *pbVar19;
              bVar33 = *pbVar23 == *pbVar19;
              pbVar23 = pbVar23 + (uint)bVar36 * -2 + 1;
              pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
            } while (bVar33);
            bVar34 = false;
            bVar33 = (!bVar31 && !bVar33) == bVar31;
            if (bVar33) {
              uVar3 = (uint)local_41c[0];
              if (local_41c[0] == 0) {
                pbVar23 = local_41c;
                pbVar19 = (byte *)0x0;
              }
              else {
                puVar29 = &local_520;
                for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                  *puVar29 = 0;
                  puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
                }
                local_520._0_1_ = 1;
                puVar18 = &sep_19180;
                bVar1 = (byte)sep_19180;
                while (bVar1 != 0) {
                  puVar18 = (undefined2 *)((int)puVar18 + 1);
                  *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
                  bVar1 = *(byte *)puVar18;
                }
                pbVar23 = local_41c;
                if (*(char *)((int)&local_520 + uVar3) == '\0') {
                  do {
                    pbVar23 = pbVar23 + 1;
                  } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                  pbVar19 = local_41c;
                  if (*pbVar23 == 0) goto LAB_08076d30;
                }
                pbVar19 = local_41c;
                *pbVar23 = 0;
                pbVar23 = pbVar23 + 1;
              }
LAB_08076d30:
              lVar14 = strtol((char *)pbVar19,(char **)0x0,10);
              bVar1 = *pbVar23;
              if (bVar1 == 0) {
LAB_08077165:
                pbVar19 = (byte *)0x0;
              }
              else {
                uVar3 = (uint)(byte)sep_19180;
                puVar29 = &local_520;
                for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                  *puVar29 = 0;
                  puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
                }
                local_520._0_1_ = 1;
                puVar18 = &sep_19180;
                uVar15 = uVar3;
                bVar2 = (byte)sep_19180;
                while (bVar2 != 0) {
                  puVar18 = (undefined2 *)((int)puVar18 + 1);
                  *(undefined *)((int)&local_520 + uVar15) = 1;
                  bVar2 = *(byte *)puVar18;
                  uVar15 = (uint)bVar2;
                }
                if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                  do {
                    pbVar23 = pbVar23 + 1;
                  } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                  if (*pbVar23 == 0) goto LAB_08077165;
                }
                pbVar19 = pbVar23 + 1;
                *pbVar23 = 0;
                bVar1 = pbVar23[1];
                pbVar23 = pbVar19;
                if (bVar1 == 0) goto LAB_08077165;
                puVar29 = &local_520;
                for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                  *puVar29 = 0;
                  puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
                }
                local_520._0_1_ = 1;
                puVar18 = &sep_19180;
                bVar2 = (byte)sep_19180;
                while (bVar2 != 0) {
                  puVar18 = (undefined2 *)((int)puVar18 + 1);
                  *(undefined *)((int)&local_520 + uVar3) = 1;
                  bVar2 = *(byte *)puVar18;
                  uVar3 = (uint)bVar2;
                }
                if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                  do {
                    pbVar23 = pbVar23 + 1;
                  } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                  if (*pbVar23 != 0) goto LAB_08076e66;
                }
                else {
LAB_08076e66:
                  *pbVar23 = 0;
                  pbVar23 = pbVar23 + 1;
                }
              }
              dVar38 = strtod((char *)pbVar19,(char **)0x0);
              iVar17 = lVar14 * 0x10;
              if (iVar16 == 0) {
                bVar1 = *pbVar23;
                *(double *)(ecdsa_results + iVar17) = dVar38;
                if (bVar1 != 0) goto LAB_08076eb0;
                dVar38 = strtod((char *)0x0,(char **)0x0);
LAB_080775e5:
                *(double *)(ecdsa_results + lVar14 * 0x10 + 8) = dVar38;
              }
              else {
                bVar1 = *pbVar23;
                *(double *)(ecdsa_results + iVar17) =
                     1.0 / (1.0 / dVar38 + 1.0 / *(double *)(ecdsa_results + iVar17));
                if (bVar1 == 0) {
                  dVar38 = strtod((char *)0x0,(char **)0x0);
                }
                else {
LAB_08076eb0:
                  puVar29 = &local_520;
                  for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                    *puVar29 = 0;
                    puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
                  }
                  local_520._0_1_ = 1;
                  puVar18 = &sep_19180;
                  bVar2 = (byte)sep_19180;
                  while (bVar2 != 0) {
                    puVar18 = (undefined2 *)((int)puVar18 + 1);
                    *(undefined *)((int)&local_520 + (uint)bVar2) = 1;
                    bVar2 = *(byte *)puVar18;
                  }
                  pbVar19 = pbVar23;
                  if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                    do {
                      pbVar19 = pbVar19 + 1;
                    } while (*(char *)((int)&local_520 + (uint)*pbVar19) == '\0');
                    if (*pbVar19 != 0) goto LAB_08076f14;
                  }
                  else {
LAB_08076f14:
                    *pbVar19 = 0;
                  }
                  dVar38 = strtod((char *)pbVar23,(char **)0x0);
                  if (iVar16 == 0) goto LAB_080775e5;
                }
                *(double *)(ecdsa_results + lVar14 * 0x10 + 8) =
                     1.0 / (1.0 / dVar38 + 1.0 / *(double *)(ecdsa_results + lVar14 * 0x10 + 8));
              }
            }
            else {
              iVar17 = 4;
              pbVar23 = local_420;
              pbVar19 = &DAT_081f6499;
              do {
                if (iVar17 == 0) break;
                iVar17 = iVar17 + -1;
                bVar34 = *pbVar23 < *pbVar19;
                bVar33 = *pbVar23 == *pbVar19;
                pbVar23 = pbVar23 + (uint)bVar36 * -2 + 1;
                pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
              } while (bVar33);
              bVar33 = (!bVar34 && !bVar33) == bVar34;
              if (bVar33) {
                uVar3 = (uint)local_41c[0];
                if (local_41c[0] == 0) {
                  pbVar23 = local_41c;
                  pbVar19 = (byte *)0x0;
                }
                else {
                  puVar29 = &local_520;
                  for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                    *puVar29 = 0;
                    puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
                  }
                  local_520._0_1_ = 1;
                  puVar18 = &sep_19180;
                  bVar1 = (byte)sep_19180;
                  while (bVar1 != 0) {
                    puVar18 = (undefined2 *)((int)puVar18 + 1);
                    *(undefined *)((int)&local_520 + (uint)bVar1) = 1;
                    bVar1 = *(byte *)puVar18;
                  }
                  pbVar23 = local_41c;
                  if (*(char *)((int)&local_520 + uVar3) == '\0') {
                    do {
                      pbVar23 = pbVar23 + 1;
                    } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                    pbVar19 = local_41c;
                    if (*pbVar23 == 0) goto LAB_08076ff0;
                  }
                  pbVar19 = local_41c;
                  *pbVar23 = 0;
                  pbVar23 = pbVar23 + 1;
                }
LAB_08076ff0:
                lVar14 = strtol((char *)pbVar19,(char **)0x0,10);
                bVar1 = *pbVar23;
                if (bVar1 == 0) {
LAB_080771b6:
                  pbVar19 = (byte *)0x0;
                }
                else {
                  uVar3 = (uint)(byte)sep_19180;
                  puVar29 = &local_520;
                  for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                    *puVar29 = 0;
                    puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
                  }
                  local_520._0_1_ = 1;
                  puVar18 = &sep_19180;
                  uVar15 = uVar3;
                  bVar2 = (byte)sep_19180;
                  while (bVar2 != 0) {
                    puVar18 = (undefined2 *)((int)puVar18 + 1);
                    *(undefined *)((int)&local_520 + uVar15) = 1;
                    bVar2 = *(byte *)puVar18;
                    uVar15 = (uint)bVar2;
                  }
                  if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                    do {
                      pbVar23 = pbVar23 + 1;
                    } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                    if (*pbVar23 == 0) goto LAB_080771b6;
                  }
                  *pbVar23 = 0;
                  pbVar19 = pbVar23 + 1;
                  bVar1 = pbVar23[1];
                  if (bVar1 == 0) goto LAB_080771b6;
                  puVar29 = &local_520;
                  for (iVar17 = 0x40; iVar17 != 0; iVar17 = iVar17 + -1) {
                    *puVar29 = 0;
                    puVar29 = puVar29 + (uint)bVar36 * -2 + 1;
                  }
                  local_520._0_1_ = 1;
                  puVar18 = &sep_19180;
                  bVar2 = (byte)sep_19180;
                  while (bVar2 != 0) {
                    puVar18 = (undefined2 *)((int)puVar18 + 1);
                    *(undefined *)((int)&local_520 + uVar3) = 1;
                    bVar2 = *(byte *)puVar18;
                    uVar3 = (uint)bVar2;
                  }
                  pbVar23 = pbVar19;
                  if (*(char *)((int)&local_520 + (uint)bVar1) == '\0') {
                    do {
                      pbVar23 = pbVar23 + 1;
                    } while (*(char *)((int)&local_520 + (uint)*pbVar23) == '\0');
                    if (*pbVar23 != 0) goto LAB_080770f8;
                  }
                  else {
LAB_080770f8:
                    *pbVar23 = 0;
                  }
                }
                dVar38 = strtod((char *)pbVar19,(char **)0x0);
                if (iVar16 == 0) {
                  *(double *)(ecdh_results + lVar14 * 8) = dVar38;
                }
                else {
                  *(double *)(ecdh_results + lVar14 * 8) =
                       1.0 / (1.0 / dVar38 + 1.0 / *(double *)(ecdh_results + lVar14 * 8));
                }
              }
              else {
                iVar17 = 3;
                pbVar23 = local_420;
                pbVar19 = &DAT_081f649e;
                do {
                  if (iVar17 == 0) break;
                  iVar17 = iVar17 + -1;
                  bVar33 = *pbVar23 == *pbVar19;
                  pbVar23 = pbVar23 + (uint)bVar36 * -2 + 1;
                  pbVar19 = pbVar19 + (uint)bVar36 * -2 + 1;
                } while (bVar33);
                if (!bVar33) {
                  __fprintf_chk(stderr,1,"Unknown type \'%s\' from child %d\n",local_420,iVar16);
                }
              }
            }
          }
        }
      }
      else {
        __fprintf_chk(stderr,1,"Don\'t understand line \'%s\' from child %d\n",local_420,iVar16);
      }
      goto LAB_08076330;
    }
    fclose(pFVar13);
    iVar16 = iVar16 + 1;
  } while (iVar16 < local_28b8);
  free(__ptr);
  if (mr == 0) {
    local_28e8 = 0;
    goto LAB_08075b8b;
  }
  goto LAB_08074aba;
LAB_08076030:
  HMAC_CTX_cleanup(&local_23f4);
  fVar37 = (float10)(double)fVar37;
LAB_08071bb6:
  if (local_26f0[5] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 200);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._20_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        uVar41 = CONCAT44(0x8071c65,(int)uVar41);
        pEVar6 = EVP_sha1();
        iVar16 = iVar16 + 1;
        EVP_Digest(data,sVar22,local_748,(uint *)0x0,pEVar6,(ENGINE *)0x0);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._20_4_,SUB84((double)fVar37,0),pcVar39);
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[23] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x398);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._92_4_,3,sVar22,pcVar39);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        uVar41 = ZEXT48(local_720);
        SHA256(data,sVar22,local_720);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._92_4_,SUB84((double)fVar37,0),pcVar39);
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[24] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x3c0);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._96_4_,3,sVar22,pcVar39);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        uVar41 = ZEXT48(local_6a0);
        SHA512(data,sVar22,local_6a0);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._96_4_,SUB84((double)fVar37,0),pcVar39);
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[25] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 1000);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._100_4_,3,sVar22,pcVar39);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        uVar41 = ZEXT48(local_660);
        WHIRLPOOL(data,sVar22,local_660);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._100_4_,SUB84((double)fVar37,0),pcVar39);
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[6] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0xf0);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._24_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        uVar41 = CONCAT44(0x80721ed,(int)uVar41);
        pEVar6 = EVP_ripemd160();
        iVar16 = iVar16 + 1;
        EVP_Digest(data,sVar22,local_734,(uint *)0x0,pEVar6,(ENGINE *)0x0);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._24_4_,SUB84((double)fVar37,0),pcVar39);
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[7] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x118);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._28_4_,3,sVar22,pcVar39);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        uVar41 = CONCAT44(data,data);
        RC4((RC4_KEY *)local_1e6e,sVar22,data,data);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      BIO_printf(bio_err,pcVar7,iVar16,names._28_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[8] != 0) {
    local_28ac = 0;
    do {
      lVar14 = *(long *)(lengths + local_28ac);
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._32_4_,3,lVar14,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        DES_ncbc_encrypt(data,data,lVar14,&local_25f8,(DES_cblock *)&local_790,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._32_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *(double *)(results + local_28ac * 2 + 0x140) =
           (double)((float10)lVar14 * ((float10)iVar16 / fVar37));
      local_28ac = local_28ac + 4;
    } while (local_28ac != 0x14);
  }
  if (local_26f0[9] != 0) {
    local_28ac = 0;
    do {
      lVar14 = *(long *)(lengths + local_28ac);
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._36_4_,3,lVar14,pcVar39);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        uVar41 = CONCAT44(1,(DES_cblock *)&local_790);
        iVar16 = iVar16 + 1;
        DES_ede3_cbc_encrypt
                  (data,data,lVar14,&local_25f8,&local_2578,&local_24f8,(DES_cblock *)&local_790,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._36_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *(double *)(results + local_28ac * 2 + 0x168) =
           (double)((float10)lVar14 * ((float10)iVar16 / fVar37));
      local_28ac = local_28ac + 4;
    } while (local_28ac != 0x14);
  }
  if (local_26f0[16] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x280);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._64_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        AES_cbc_encrypt(data,data,sVar22,&local_224c,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      BIO_printf(bio_err,pcVar7,iVar16,names._64_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[17] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x2a8);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._68_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        AES_cbc_encrypt(data,data,sVar22,&local_2158,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      BIO_printf(bio_err,pcVar7,iVar16,names._68_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[18] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x2d0);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._72_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        AES_cbc_encrypt(data,data,sVar22,&local_2064,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      BIO_printf(bio_err,pcVar7,iVar16,names._72_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[26] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x410);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._104_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        AES_ige_encrypt(data,out,sVar22,&local_224c,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      BIO_printf(bio_err,pcVar7,iVar16,names._104_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[27] != 0) {
    sVar22 = 0x10;
    puVar25 = lengths;
    pdVar26 = (double *)(results + 0x438);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._108_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        AES_ige_encrypt(data,out,sVar22,&local_2158,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._108_4_,SUB84((double)fVar37,0),pcVar39);
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[28] != 0) {
    sVar22 = 0x10;
    puVar25 = lengths;
    pdVar26 = (double *)(results + 0x460);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._112_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        AES_ige_encrypt(data,out,sVar22,&local_2064,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._112_4_,SUB84((double)fVar37,0),pcVar39);
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[29] != 0) {
    uVar3 = 0x10;
    uVar20 = CRYPTO_gcm128_new(&local_224c,AES_encrypt);
    pcVar39 = "0123456789ab";
    CRYPTO_gcm128_setiv(uVar20,"0123456789ab",0xc);
    puVar25 = lengths;
    pdVar26 = (double *)(results + 0x488);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._116_4_,3,uVar3,pcVar39);
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        uVar41 = (ulonglong)uVar3;
        CRYPTO_gcm128_aad(uVar20,data,uVar3);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._116_4_,SUB84((double)fVar37,0),pcVar39);
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      *pdVar26 = (double)uVar3 * ((double)iVar16 / (double)fVar37);
      if (puVar25 == &UNK_081f703c) goto LAB_08076013;
      uVar3 = *(uint *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  goto LAB_08072f2b;
LAB_08076013:
  CRYPTO_gcm128_release(uVar20);
  fVar37 = (float10)(double)fVar37;
LAB_08072f2b:
  if (local_26f0[19] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x2f8);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._76_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        Camellia_cbc_encrypt
                  (data,data,sVar22,(CAMELLIA_KEY *)(local_1e6e + 0x102),(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      BIO_printf(bio_err,pcVar7,iVar16,names._76_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[20] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 800);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._80_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        Camellia_cbc_encrypt(data,data,sVar22,&local_1c58,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      BIO_printf(bio_err,pcVar7,iVar16,names._80_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[21] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x348);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._84_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        Camellia_cbc_encrypt(data,data,sVar22,&local_1b44,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      BIO_printf(bio_err,pcVar7,iVar16,names._84_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[10] != 0) {
    iVar17 = 0;
    do {
      lVar14 = *(long *)(lengths + iVar17);
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._40_4_,3,lVar14,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        idea_cbc_encrypt(data,data,lVar14,&local_2324,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._40_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *(double *)(results + iVar17 * 2 + 400) =
           (double)((float10)lVar14 * ((float10)iVar16 / fVar37));
      iVar17 = iVar17 + 4;
    } while (iVar17 != 0x14);
  }
  if (local_26f0[11] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x1b8);
    do {
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._44_4_,3,sVar22,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        SEED_cbc_encrypt(data,data,sVar22,
                         (SEED_KEY_SCHEDULE *)((int)((SEED_KEY_SCHEDULE *)local_26f0)->data + 0x78),
                         (uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      BIO_printf(bio_err,pcVar7,iVar16,names._44_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  if (local_26f0[12] != 0) {
    iVar17 = 0;
    do {
      lVar14 = *(long *)(lengths + iVar17);
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._48_4_,3,lVar14,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        RC2_cbc_encrypt(data,data,lVar14,&local_1f70,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._48_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *(double *)(results + iVar17 * 2 + 0x1e0) =
           (double)((float10)lVar14 * ((float10)iVar16 / fVar37));
      iVar17 = iVar17 + 4;
    } while (iVar17 != 0x14);
  }
  if (local_26f0[14] != 0) {
    local_28ac = 0;
    do {
      lVar14 = *(long *)(lengths + local_28ac);
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._56_4_,3,lVar14,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        BF_cbc_encrypt(data,data,lVar14,&local_17d8,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._56_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *(double *)(results + local_28ac * 2 + 0x230) =
           (double)((float10)lVar14 * ((float10)iVar16 / fVar37));
      local_28ac = local_28ac + 4;
    } while (local_28ac != 0x14);
  }
  if (local_26f0[15] != 0) {
    iVar17 = 0;
    do {
      lVar14 = *(long *)(lengths + iVar17);
      if (mr == 0) {
        pcVar7 = "Doing %s for %ds on %d size blocks: ";
      }
      else {
        pcVar7 = "+DT:%s:%d:%d\n";
      }
      iVar16 = 0;
      BIO_printf(bio_err,pcVar7,names._60_4_,3,lVar14,pcVar39);
      uVar41 = 0;
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      alarm(3);
      app_tminterval(0,usertime);
      run = 1;
      do {
        iVar16 = iVar16 + 1;
        CAST_cbc_encrypt(data,data,lVar14,&local_2478,(uchar *)local_700,1);
        if (run == 0) break;
      } while (iVar16 != 0x7fffffff);
      fVar37 = (float10)app_tminterval(1,usertime);
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      BIO_printf(bio_err,pcVar7,iVar16,names._60_4_,SUB84((double)fVar37,0),pcVar39);
      fVar37 = (float10)(double)fVar37;
      *(double *)(results + iVar17 * 2 + 600) =
           (double)((float10)lVar14 * ((float10)iVar16 / fVar37));
      iVar17 = iVar17 + 4;
    } while (iVar17 != 0x14);
  }
  if (local_26f0[22] != 0) {
    puVar25 = lengths;
    sVar22 = 0x10;
    pdVar26 = (double *)(results + 0x370);
    do {
      if (cipher != (EVP_CIPHER *)0x0) {
        names._88_4_ = OBJ_nid2ln(cipher->nid);
        if (mr == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._88_4_,3,sVar22,pcVar39);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)&local_23f4);
          if (!bVar33) goto LAB_0807524e;
LAB_08073a73:
          iVar16 = 0;
          EVP_DecryptInit_ex((EVP_CIPHER_CTX *)&local_23f4,cipher,(ENGINE *)0x0,key16_17943,
                             (uchar *)local_700);
          EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)&local_23f4,0);
          app_tminterval(0,usertime);
          run = 1;
          do {
            iVar16 = iVar16 + 1;
            EVP_DecryptUpdate((EVP_CIPHER_CTX *)&local_23f4,data,(int *)&local_288c,data,sVar22);
            if (run == 0) break;
          } while (iVar16 != 0x7fffffff);
          uVar41 = ZEXT48(&local_288c);
          EVP_DecryptFinal_ex((EVP_CIPHER_CTX *)&local_23f4,data,(int *)&local_288c);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._88_4_,3,sVar22,pcVar39);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)&local_23f4);
          if (bVar33) goto LAB_08073a73;
LAB_0807524e:
          iVar16 = 0;
          EVP_EncryptInit_ex((EVP_CIPHER_CTX *)&local_23f4,cipher,(ENGINE *)0x0,key16_17943,
                             (uchar *)local_700);
          EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)&local_23f4,0);
          app_tminterval(0,usertime);
          run = 1;
          do {
            iVar16 = iVar16 + 1;
            EVP_EncryptUpdate((EVP_CIPHER_CTX *)&local_23f4,data,(int *)&local_288c,data,sVar22);
            if (run == 0) break;
          } while (iVar16 != 0x7fffffff);
          uVar41 = ZEXT48(&local_288c);
          EVP_EncryptFinal_ex((EVP_CIPHER_CTX *)&local_23f4,data,(int *)&local_288c);
        }
        pcVar39 = (char *)usertime;
        fVar37 = (float10)app_tminterval(1,usertime);
        EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)&local_23f4);
        fVar37 = (float10)(double)fVar37;
      }
      if (type_00 != (EVP_MD *)0x0) {
        names._88_4_ = OBJ_nid2ln(type_00->type);
        if (mr == 0) {
          pcVar7 = "Doing %s for %ds on %d size blocks: ";
        }
        else {
          pcVar7 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar7,names._88_4_,3,sVar22,pcVar39);
        uVar41 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        run = 1;
        iVar16 = 0;
        do {
          iVar16 = iVar16 + 1;
          EVP_Digest(data,sVar22,local_6e0,(uint *)0x0,type_00,(ENGINE *)0x0);
          if (run == 0) break;
        } while (iVar16 != 0x7fffffff);
        fVar37 = (float10)app_tminterval(1,usertime);
      }
      pcVar7 = "%d %s\'s in %.2fs\n";
      if (mr != 0) {
        pcVar7 = "+R:%d:%s:%f\n";
      }
      pcVar39 = (char *)((ulonglong)(double)fVar37 >> 0x20);
      BIO_printf(bio_err,pcVar7,iVar16,names._88_4_,SUB84((double)fVar37,0),pcVar39);
      puVar25 = (undefined1 *)((int)puVar25 + 4);
      fVar37 = (float10)(double)fVar37;
      *pdVar26 = (double)((float10)sVar22 * ((float10)iVar16 / fVar37));
      if (puVar25 == &UNK_081f703c) break;
      sVar22 = *(size_t *)puVar25;
      pdVar26 = pdVar26 + 1;
    } while( true );
  }
  RAND_pseudo_bytes(data,0x24);
  local_28a4._0_4_ = 0;
  do {
    iVar16 = local_28a4._0_4_;
    if ((&local_2860)[local_28a4._0_4_] != (RSA *)0x0) {
      pRVar5 = local_2870[local_28a4._0_4_];
      iVar17 = RSA_sign(0x72,data,0x24,out,&local_2890,pRVar5);
      if (iVar17 == 0) {
        BIO_printf(bio_err,"RSA sign failure.  No RSA sign will be done.\n");
        ERR_print_errors(bio_err);
        local_28b4 = 1;
      }
      else {
        uVar20 = *(undefined4 *)(rsa_bits_17966 + local_28a4._0_4_ * 4);
        if (mr == 0) {
          pcVar39 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar39 = "+DTP:%d:%s:%s:%d\n";
        }
        BIO_printf(bio_err,pcVar39,uVar20,"private","rsa",10);
        uVar41 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(10);
        app_tminterval(0,usertime);
        run = 1;
        local_28b4 = 0;
        while (iVar17 = RSA_sign(0x72,data,0x24,out,&local_2890,pRVar5), iVar17 != 0) {
          local_28b4 = local_28b4 + 1;
          if ((run == 0) || (local_28b4 == 0x7fffffff)) goto LAB_08074010;
        }
        BIO_printf(bio_err,"RSA sign failure\n");
        ERR_print_errors(bio_err);
        local_28b4 = 1;
LAB_08074010:
        fVar37 = (float10)app_tminterval(1,usertime);
        pcVar39 = "%ld %d bit private RSA\'s in %.2fs\n";
        if (mr != 0) {
          pcVar39 = "+R1:%ld:%d:%.2f\n";
        }
        BIO_printf(bio_err,pcVar39,local_28b4,uVar20,SUB84((double)fVar37,0),
                   (int)((ulonglong)(double)fVar37 >> 0x20));
        *(double *)(rsa_results + local_28a4._0_4_ * 0x10) = (double)fVar37 / (double)local_28b4;
      }
      iVar17 = RSA_verify(0x72,data,0x24,out,local_2890,pRVar5);
      if (iVar17 < 1) {
        BIO_printf(bio_err,"RSA verify failure.  No RSA verify will be done.\n");
        ERR_print_errors(bio_err);
        (&local_2860)[local_28a4._0_4_] = (RSA *)0x0;
      }
      else {
        uVar20 = *(undefined4 *)(rsa_bits_17966 + local_28a4._0_4_ * 4);
        if (mr == 0) {
          pcVar39 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar39 = "+DTP:%d:%s:%s:%d\n";
        }
        iVar17 = 0;
        BIO_printf(bio_err,pcVar39,uVar20,"public","rsa",10);
        uVar41 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(10);
        app_tminterval(0,usertime);
        run = 1;
        while (iVar8 = RSA_verify(0x72,data,0x24,out,local_2890,pRVar5), 0 < iVar8) {
          iVar17 = iVar17 + 1;
          if ((run == 0) || (iVar17 == 0x7fffffff)) goto LAB_08073e44;
        }
        iVar17 = 1;
        BIO_printf(bio_err,"RSA verify failure\n");
        ERR_print_errors(bio_err);
LAB_08073e44:
        fVar37 = (float10)app_tminterval(1,usertime);
        pcVar39 = "%ld %d bit public RSA\'s in %.2fs\n";
        if (mr != 0) {
          pcVar39 = "+R2:%ld:%d:%.2f\n";
        }
        BIO_printf(bio_err,pcVar39,iVar17,uVar20,SUB84((double)fVar37,0),
                   (int)((ulonglong)(double)fVar37 >> 0x20));
        *(double *)(rsa_results + local_28a4._0_4_ * 0x10 + 8) = (double)fVar37 / (double)iVar17;
      }
      if (local_28b4 == 1) {
        if (local_28a4._0_4_ + 1 == 4) break;
        (&local_2860)[local_28a4._0_4_ + 1] = (RSA *)0x0;
        iVar16 = local_28a4._0_4_ + 2;
        if (iVar16 < 4) {
          (&local_2860)[iVar16] = (RSA *)0x0;
          iVar16 = local_28a4._0_4_ + 3;
          if (iVar16 == 3) {
            local_2854 = 0;
            iVar16 = local_28a4._0_4_ + 4;
          }
        }
      }
    }
    local_28a4._0_4_ = iVar16 + 1;
  } while (local_28a4._0_4_ < 4);
  uVar3 = 0x14;
  RAND_pseudo_bytes(data,0x14);
  iVar16 = RAND_status();
  if (iVar16 != 1) {
    uVar3 = 0x40;
    RAND_seed("string to make the random number generator think it has entropy",0x40);
    rnd_fake = 1;
  }
  dVar38 = (double)((ulonglong)uVar3 << 0x20);
  iVar16 = 0;
  do {
    if (local_2888[iVar16 + 3] == (DSA *)0x0) {
      iVar17 = iVar16 + 1;
    }
    else {
      dsa = local_2888[iVar16];
      iVar17 = DSA_sign(0x74,data,0x14,out,(uint *)&local_288c,dsa);
      if (iVar17 == 0) {
        BIO_printf(bio_err,"DSA sign failure.  No DSA sign will be done.\n");
        ERR_print_errors(bio_err);
        local_28b4 = 1;
      }
      else {
        uVar20 = *(undefined4 *)(dsa_bits_17971 + iVar16 * 4);
        if (mr == 0) {
          pcVar39 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar39 = "+DTP:%d:%s:%s:%d\n";
        }
        BIO_printf(bio_err,pcVar39,uVar20,"sign",&DAT_081f626d,10);
        uVar41 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(10);
        app_tminterval(0,usertime);
        run = 1;
        local_28b4 = 0;
        while (iVar17 = DSA_sign(0x74,data,0x14,out,(uint *)&local_288c,dsa), iVar17 != 0) {
          local_28b4 = local_28b4 + 1;
          if ((run == 0) || (local_28b4 == 0x7fffffff)) goto LAB_080743e0;
        }
        BIO_printf(bio_err,"DSA sign failure\n");
        ERR_print_errors(bio_err);
        local_28b4 = 1;
LAB_080743e0:
        fVar37 = (float10)app_tminterval(1,usertime);
        pcVar39 = "%ld %d bit DSA signs in %.2fs\n";
        if (mr != 0) {
          pcVar39 = "+R3:%ld:%d:%.2f\n";
        }
        BIO_printf(bio_err,pcVar39,local_28b4,uVar20,SUB84((double)fVar37,0),
                   (int)((ulonglong)(double)fVar37 >> 0x20));
        *(double *)(dsa_results + iVar16 * 0x10) = (double)fVar37 / (double)local_28b4;
      }
      iVar17 = DSA_verify(0x74,data,0x14,out,(int)local_288c,dsa);
      if (iVar17 < 1) {
        pcVar39 = "DSA verify failure.  No DSA verify will be done.\n";
        BIO_printf(bio_err,"DSA verify failure.  No DSA verify will be done.\n");
        ERR_print_errors(bio_err);
        dVar38 = (double)(ZEXT48(pcVar39) << 0x20);
        local_2888[iVar16 + 3] = (DSA *)0x0;
      }
      else {
        uVar20 = *(undefined4 *)(dsa_bits_17971 + iVar16 * 4);
        if (mr == 0) {
          pcVar39 = "Doing %d bit %s %s\'s for %ds: ";
        }
        else {
          pcVar39 = "+DTP:%d:%s:%s:%d\n";
        }
        iVar17 = 0;
        BIO_printf(bio_err,pcVar39,uVar20,"verify",&DAT_081f626d,10);
        uVar41 = 0;
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(10);
        app_tminterval(0,usertime);
        run = 1;
        while (iVar8 = DSA_verify(0x74,data,0x14,out,(int)local_288c,dsa), 0 < iVar8) {
          iVar17 = iVar17 + 1;
          if ((run == 0) || (iVar17 == 0x7fffffff)) goto LAB_0807425c;
        }
        iVar17 = 1;
        BIO_printf(bio_err,"DSA verify failure\n");
        ERR_print_errors(bio_err);
LAB_0807425c:
        fVar37 = (float10)app_tminterval(1,usertime);
        pcVar39 = "%ld %d bit DSA verify in %.2fs\n";
        dVar38 = (double)fVar37;
        if (mr != 0) {
          pcVar39 = "+R4:%ld:%d:%.2f\n";
        }
        BIO_printf(bio_err,pcVar39,iVar17,uVar20,SUB84(dVar38,0),(int)((ulonglong)dVar38 >> 0x20));
        *(double *)(dsa_results + iVar16 * 0x10 + 8) = (double)fVar37 / (double)iVar17;
      }
      if (local_28b4 == 1) {
        iVar17 = 4;
        if (iVar16 != 2) {
          local_2888[iVar16 + 4] = (DSA *)0x0;
          if (iVar16 == 0) {
            local_2874 = 0;
            iVar17 = 4;
          }
          else {
            iVar17 = iVar16 + 3;
          }
        }
      }
      else {
        iVar17 = iVar16 + 1;
      }
    }
    uVar20 = (undefined4)uVar41;
    iVar16 = iVar17;
  } while (iVar17 < 3);
  if (rnd_fake != 0) {
    RAND_cleanup();
  }
  uVar42 = CONCAT44(0x8074458,uVar20);
  iVar16 = RAND_status();
  if (iVar16 != 1) {
    uVar3 = 0x40;
    RAND_seed("string to make the random number generator think it has entropy",0x40);
    dVar38 = (double)((ulonglong)uVar3 << 0x20);
    rnd_fake = 1;
  }
  iVar16 = 0;
  do {
    iVar17 = iVar16;
    if (local_2770[iVar16] != 0) {
      pEVar9 = EC_KEY_new_by_curve_name(*(int *)(test_curves_17972 + iVar16 * 4));
      local_2830[iVar16] = pEVar9;
      if (pEVar9 == (EC_KEY *)0x0) {
        pcVar39 = "ECDSA failure.\n";
        BIO_printf(bio_err,"ECDSA failure.\n");
        ERR_print_errors(bio_err);
        dVar38 = (double)(ZEXT48(pcVar39) << 0x20);
      }
      else {
        EC_KEY_precompute_mult(pEVar9,(BN_CTX *)0x0);
        EC_KEY_generate_key(pEVar9);
        iVar8 = ECDSA_sign(0,data,0x14,local_620,(uint *)&local_288c,pEVar9);
        if (iVar8 == 0) {
          BIO_printf(bio_err,"ECDSA sign failure.  No ECDSA sign will be done.\n");
          iVar8 = 1;
          ERR_print_errors(bio_err);
        }
        else {
          uVar20 = *(undefined4 *)(test_curves_bits_17974 + iVar16 * 4);
          if (mr == 0) {
            pcVar39 = "Doing %d bit %s %s\'s for %ds: ";
          }
          else {
            pcVar39 = "+DTP:%d:%s:%s:%d\n";
          }
          iVar8 = 0;
          BIO_printf(bio_err,pcVar39,uVar20,"sign",&DAT_081f626b,10);
          uVar42 = 0;
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          run = 1;
          while (iVar10 = ECDSA_sign(0,data,0x14,local_620,(uint *)&local_288c,pEVar9), iVar10 != 0)
          {
            iVar8 = iVar8 + 1;
            if ((run == 0) || (iVar8 == 0x7fffffff)) goto LAB_080747c3;
          }
          iVar8 = 1;
          BIO_printf(bio_err,"ECDSA sign failure\n");
          ERR_print_errors(bio_err);
LAB_080747c3:
          fVar37 = (float10)app_tminterval(1,usertime);
          pcVar39 = "%ld %d bit ECDSA signs in %.2fs \n";
          if (mr != 0) {
            pcVar39 = "+R5:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar39,iVar8,uVar20,SUB84((double)fVar37,0),
                     (int)((ulonglong)(double)fVar37 >> 0x20));
          *(double *)(ecdsa_results + iVar16 * 0x10) = (double)fVar37 / (double)iVar8;
        }
        iVar10 = ECDSA_verify(0,data,0x14,local_620,(int)local_288c,pEVar9);
        if (iVar10 == 1) {
          uVar20 = *(undefined4 *)(test_curves_bits_17974 + iVar16 * 4);
          if (mr == 0) {
            pcVar39 = "Doing %d bit %s %s\'s for %ds: ";
          }
          else {
            pcVar39 = "+DTP:%d:%s:%s:%d\n";
          }
          BIO_printf(bio_err,pcVar39,uVar20,"verify",&DAT_081f626b,10);
          uVar42 = 0;
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          run = 1;
          iVar10 = 0;
          while (iVar11 = ECDSA_verify(0,data,0x14,local_620,(int)local_288c,pEVar9), iVar11 == 1) {
            iVar10 = iVar10 + 1;
            if ((run == 0) || (iVar10 == 0x7fffffff)) goto LAB_08075501;
          }
          BIO_printf(bio_err,"ECDSA verify failure\n");
          ERR_print_errors(bio_err);
          iVar10 = 1;
LAB_08075501:
          fVar37 = (float10)app_tminterval(1,usertime);
          dVar38 = (double)fVar37;
          pcVar39 = "%ld %d bit ECDSA verify in %.2fs\n";
          if (mr != 0) {
            pcVar39 = "+R6:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar39,iVar10,uVar20,SUB84(dVar38,0),(int)((ulonglong)dVar38 >> 0x20))
          ;
          *(double *)(ecdsa_results + iVar16 * 0x10 + 8) = (double)fVar37 / (double)iVar10;
        }
        else {
          pcVar39 = "ECDSA verify failure.  No ECDSA verify will be done.\n";
          BIO_printf(bio_err,"ECDSA verify failure.  No ECDSA verify will be done.\n");
          ERR_print_errors(bio_err);
          dVar38 = (double)(ZEXT48(pcVar39) << 0x20);
          local_2770[iVar16] = 0;
        }
        uVar20 = (undefined4)uVar42;
        if (iVar8 == 1) {
          if (iVar16 + 1 == 0x10) break;
          local_2770[iVar16 + 1] = 0;
          iVar17 = iVar16 + 2;
          if (iVar17 < 0x10) {
            local_2770[iVar17] = 0;
            iVar17 = iVar16 + 3;
            if (iVar17 < 0x10) {
              local_2770[iVar17] = 0;
              iVar17 = iVar16 + 4;
              if (iVar17 < 0x10) {
                local_2770[iVar17] = 0;
                iVar17 = iVar16 + 5;
                if (iVar17 < 0x10) {
                  local_2770[iVar17] = 0;
                  iVar17 = iVar16 + 6;
                  if (iVar17 < 0x10) {
                    local_2770[iVar17] = 0;
                    iVar17 = iVar16 + 7;
                    if (iVar17 < 0x10) {
                      local_2770[iVar17] = 0;
                      iVar17 = iVar16 + 8;
                      if (iVar17 < 0x10) {
                        local_2770[iVar17] = 0;
                        iVar17 = iVar16 + 9;
                        if (iVar17 < 0x10) {
                          local_2770[iVar17] = 0;
                          iVar17 = iVar16 + 10;
                          if (iVar17 < 0x10) {
                            local_2770[iVar17] = 0;
                            iVar17 = iVar16 + 0xb;
                            if (iVar17 < 0x10) {
                              local_2770[iVar17] = 0;
                              iVar17 = iVar16 + 0xc;
                              if (iVar17 < 0x10) {
                                local_2770[iVar17] = 0;
                                iVar17 = iVar16 + 0xd;
                                if (iVar17 < 0x10) {
                                  local_2770[iVar17] = 0;
                                  iVar17 = iVar16 + 0xe;
                                  if (iVar17 < 0x10) {
                                    local_2770[iVar17] = 0;
                                    iVar17 = iVar16 + 0xf;
                                    if (iVar17 == 0xf) {
                                      local_2770[15] = 0;
                                      iVar17 = iVar16 + 0x10;
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
    uVar20 = (undefined4)uVar42;
    iVar16 = iVar17 + 1;
  } while (iVar16 < 0x10);
  if (rnd_fake != 0) {
    RAND_cleanup();
  }
  dVar43 = (double)CONCAT44(0x807483c,uVar20);
  iVar16 = RAND_status();
  if (iVar16 != 1) {
    uVar3 = 0x40;
    RAND_seed("string to make the random number generator think it has entropy",0x40);
    dVar38 = (double)((ulonglong)uVar3 << 0x20);
    rnd_fake = 1;
  }
  iVar16 = 0;
  do {
    iVar17 = iVar16;
    if (local_2730[iVar16] != 0) {
      iVar8 = *(int *)(test_curves_17972 + iVar16 * 4);
      pEVar9 = EC_KEY_new_by_curve_name(iVar8);
      local_27f0[iVar16] = pEVar9;
      key = EC_KEY_new_by_curve_name(iVar8);
      local_27b0[iVar16] = key;
      if ((key == (EC_KEY *)0x0) || (pEVar9 == (EC_KEY *)0x0)) {
        pcVar39 = "ECDH failure.\n";
      }
      else {
        iVar8 = EC_KEY_generate_key(pEVar9);
        if ((iVar8 != 0) && (iVar8 = EC_KEY_generate_key(key), iVar8 != 0)) {
          group = EC_KEY_get0_group(pEVar9);
          iVar8 = EC_GROUP_get_degree(group);
          if (iVar8 < 0xc1) {
            sVar22 = 0x14;
            pcVar40 = KDF1_SHA1;
          }
          else {
            pcVar40 = (KDF *)0x0;
            sVar22 = iVar8 + 7 >> 3;
          }
          pEVar12 = EC_KEY_get0_public_key(key);
          iVar8 = ECDH_compute_key(&local_520,sVar22,pEVar12,pEVar9,pcVar40);
          pEVar12 = EC_KEY_get0_public_key(pEVar9);
          iVar10 = ECDH_compute_key(local_420,sVar22,pEVar12,key,pcVar40);
          if (iVar8 == iVar10) {
            if (0 < iVar8) {
              iVar10 = 0;
              do {
                bVar36 = *(byte *)((int)&local_520 + iVar10);
                pbVar23 = local_420 + iVar10;
                iVar10 = iVar10 + 1;
                if (bVar36 != *pbVar23) break;
              } while (iVar10 < iVar8);
              if (bVar36 != *pbVar23) goto LAB_08076143;
            }
          }
          else {
LAB_08076143:
            BIO_printf(bio_err,"ECDH computations don\'t match.\n");
            ERR_print_errors(bio_err);
          }
          uVar20 = *(undefined4 *)(test_curves_bits_17974 + iVar16 * 4);
          if (mr == 0) {
            pcVar39 = "Doing %d bit %s %s\'s for %ds: ";
          }
          else {
            pcVar39 = "+DTP:%d:%s:%s:%d\n";
          }
          BIO_printf(bio_err,pcVar39,uVar20,&DAT_081ec74a,&DAT_081f6301,10);
          dVar43 = 0.0;
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          run = 1;
          iVar8 = 0;
          do {
            iVar8 = iVar8 + 1;
            pEVar12 = EC_KEY_get0_public_key(key);
            ECDH_compute_key(&local_520,sVar22,pEVar12,pEVar9,pcVar40);
            if (run == 0) {
              fVar37 = (float10)app_tminterval(1,usertime);
              dVar38 = (double)fVar37;
              pcVar39 = "%ld %d-bit ECDH ops in %.2fs\n";
              if (mr != 0) {
                pcVar39 = "+R7:%ld:%d:%.2f\n";
              }
              BIO_printf(bio_err,pcVar39,iVar8,uVar20,SUB84(dVar38,0),
                         (int)((ulonglong)dVar38 >> 0x20));
              *(double *)(ecdh_results + iVar16 * 8) = (double)fVar37 / (double)iVar8;
              if (iVar8 == 1) goto LAB_08074925;
              goto LAB_08074878;
            }
          } while (iVar8 != 0x7fffffff);
          fVar37 = (float10)app_tminterval(1,usertime);
          if (mr == 0) {
            pcVar39 = "%ld %d-bit ECDH ops in %.2fs\n";
          }
          else {
            pcVar39 = "+R7:%ld:%d:%.2f\n";
          }
          local_28a4 = (double)fVar37;
          dVar38 = (double)fVar37;
          BIO_printf(bio_err,pcVar39,0x7fffffff,uVar20,SUB84(dVar38,0),
                     (int)((ulonglong)dVar38 >> 0x20));
          *(double *)(ecdh_results + iVar16 * 8) = local_28a4 / _DAT_081f7090;
          goto LAB_08074878;
        }
        pcVar39 = "ECDH key generation failure.\n";
      }
      BIO_printf(bio_err,pcVar39);
      ERR_print_errors(bio_err);
      dVar38 = (double)(ZEXT48(pcVar39) << 0x20);
LAB_08074925:
      pcVar39 = (char *)((ulonglong)dVar38 >> 0x20);
      if (iVar16 + 1 == 0x10) break;
      local_2730[iVar16 + 1] = 0;
      iVar17 = iVar16 + 2;
      if (iVar17 < 0x10) {
        local_2730[iVar17] = 0;
        iVar17 = iVar16 + 3;
        if (iVar17 < 0x10) {
          local_2730[iVar17] = 0;
          iVar17 = iVar16 + 4;
          if (iVar17 < 0x10) {
            local_2730[iVar17] = 0;
            iVar17 = iVar16 + 5;
            if (iVar17 < 0x10) {
              local_2730[iVar17] = 0;
              iVar17 = iVar16 + 6;
              if (iVar17 < 0x10) {
                local_2730[iVar17] = 0;
                iVar17 = iVar16 + 7;
                if (iVar17 < 0x10) {
                  local_2730[iVar17] = 0;
                  iVar17 = iVar16 + 8;
                  if (iVar17 < 0x10) {
                    local_2730[iVar17] = 0;
                    iVar17 = iVar16 + 9;
                    if (iVar17 < 0x10) {
                      local_2730[iVar17] = 0;
                      iVar17 = iVar16 + 10;
                      if (iVar17 < 0x10) {
                        local_2730[iVar17] = 0;
                        iVar17 = iVar16 + 0xb;
                        if (iVar17 < 0x10) {
                          local_2730[iVar17] = 0;
                          iVar17 = iVar16 + 0xc;
                          if (iVar17 < 0x10) {
                            local_2730[iVar17] = 0;
                            iVar17 = iVar16 + 0xd;
                            if (iVar17 < 0x10) {
                              local_2730[iVar17] = 0;
                              iVar17 = iVar16 + 0xe;
                              if (iVar17 < 0x10) {
                                local_2730[iVar17] = 0;
                                iVar17 = iVar16 + 0xf;
                                if (iVar17 == 0xf) {
                                  local_2730[15] = 0;
                                  iVar17 = iVar16 + 0x10;
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
LAB_08074878:
    pcVar39 = (char *)((ulonglong)dVar38 >> 0x20);
    iVar16 = iVar17 + 1;
  } while (iVar16 < 0x10);
  if (rnd_fake != 0) {
    dVar43 = (double)CONCAT44(0x8076066,SUB84(dVar43,0));
    RAND_cleanup();
  }
  if (mr == 0) {
LAB_08075b8b:
    pcVar39 = SSLeay_version(0);
    __fprintf_chk(stdout,1,&DAT_081ed0e4,pcVar39);
    pcVar39 = SSLeay_version(3);
    __fprintf_chk(stdout,1,&DAT_081ed0e4,pcVar39);
    __printf_chk(1,"options:");
    pcVar39 = BN_options();
    __printf_chk(1,&DAT_081f6565,pcVar39);
    pcVar39 = RC4_options();
    __printf_chk(1,&DAT_081f6565,pcVar39);
    pcVar39 = DES_options();
    __printf_chk(1,&DAT_081f6565,pcVar39);
    pcVar39 = AES_options();
    __printf_chk(1,&DAT_081f6565,pcVar39);
    pcVar39 = idea_options();
    __printf_chk(1,&DAT_081f6565,pcVar39);
    pcVar7 = BF_options();
    dVar43 = (double)ZEXT48(pcVar7);
    pcVar39 = &DAT_081f6565;
    __printf_chk(1,&DAT_081f6565,pcVar7);
    pcVar7 = SSLeay_version(2);
    __fprintf_chk(stdout,1,&DAT_081f6569,pcVar7);
    if (local_28e8 != 0) {
      if (mr != 0) goto LAB_08074b71;
      fwrite("The \'numbers\' are in 1000s of bytes per second processed.\n",1,0x3a,stdout);
      fwrite("type        ",1,0xc,stdout);
LAB_08074b88:
      iVar16 = 0;
      do {
        pcVar39 = "%7d bytes";
        puVar29 = (undefined4 *)(lengths + iVar16);
        if (mr != 0) {
          pcVar39 = ":%d";
        }
        iVar16 = iVar16 + 4;
        dVar43 = (double)CONCAT44(*puVar29,pcVar39);
        __fprintf_chk(stdout,1,pcVar39,*puVar29);
      } while (iVar16 != 0x14);
      pcVar39 = (char *)stdout;
      fputc(10,stdout);
    }
  }
  else if (local_28e8 != 0) {
LAB_08074b71:
    fwrite(&DAT_081f656e,1,2,stdout);
    goto LAB_08074b88;
  }
LAB_08074aba:
  iVar16 = 0;
  do {
    if (local_2730[iVar16 + 0x10] != 0) {
      if (mr == 0) {
        dVar43 = (double)CONCAT44(*(undefined4 *)(names + iVar16 * 4),0x81f6587);
        __fprintf_chk(stdout,1,"%-13s",*(undefined4 *)(names + iVar16 * 4));
      }
      else {
        __fprintf_chk(stdout,1,"+F:%d:%s",iVar16,*(undefined4 *)(names + iVar16 * 4));
      }
      iVar17 = 0;
      do {
        dVar38 = *(double *)(results + iVar17 * 8 + iVar16 * 0x28);
        if ((double)_DAT_081f7084 < dVar38) {
          pcVar39 = ":%.2f";
          if (mr != 0) goto LAB_08074b23;
          __fprintf_chk(stdout,1," %11.2fk",dVar38 / (double)_DAT_081f7088);
        }
        else {
          pcVar39 = " %11.2f ";
          if (mr != 0) {
            pcVar39 = ":%.2f";
          }
LAB_08074b23:
          __fprintf_chk(stdout,1,pcVar39,SUB84(dVar38,0),(int)((ulonglong)dVar38 >> 0x20));
        }
        iVar17 = iVar17 + 1;
      } while (iVar17 != 5);
      pcVar39 = (char *)stdout;
      fputc(10,stdout);
    }
    iVar16 = iVar16 + 1;
  } while (iVar16 != 0x1e);
  if (local_2860 == (RSA *)0x0) {
    if (local_285c == 0) {
      if (local_2858 != 0) goto LAB_080757d3;
      bVar33 = true;
    }
    else {
LAB_08075774:
      bVar33 = true;
      if (mr == 0) {
        dVar43 = 6.733289811407329e-316;
        pcVar39 = "%18ssign    verify    sign/s verify/s\n";
        __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f84a7);
        goto LAB_08074c7d;
      }
LAB_08075786:
      __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",1,0x400,rsa_results._16_4_,rsa_results._20_4_,
                    rsa_results._24_4_,rsa_results._28_4_,pcVar39,dVar43);
LAB_080757bd:
      if (local_2858 != 0) {
        if (!bVar33) goto LAB_08075a7f;
LAB_080757d3:
        bVar33 = true;
        if (mr == 0) {
          dVar43 = 6.733289811407329e-316;
          pcVar39 = "%18ssign    verify    sign/s verify/s\n";
          __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f84a7);
          goto LAB_08075a7f;
        }
        goto LAB_080757e6;
      }
    }
LAB_08075612:
    if (local_2854 != 0) {
      if (bVar33) {
        if (mr == 0) {
          dVar43 = 6.733289811407329e-316;
          pcVar39 = "%18ssign    verify    sign/s verify/s\n";
          __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f84a7);
          goto LAB_08074ce4;
        }
      }
      else {
LAB_08074ce4:
        if (mr == 0) {
          dVar43 = 1.0 / (double)CONCAT44(rsa_results._60_4_,rsa_results._56_4_);
          dVar38 = 1.0 / (double)CONCAT44(rsa_results._52_4_,rsa_results._48_4_);
          pcVar39 = (char *)((ulonglong)dVar38 >> 0x20);
          __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x1000,
                        rsa_results._48_4_,rsa_results._52_4_,rsa_results._56_4_,rsa_results._60_4_,
                        dVar38,dVar43);
          goto LAB_08074d34;
        }
      }
      __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",3,0x1000,rsa_results._48_4_,rsa_results._52_4_,
                    rsa_results._56_4_,rsa_results._60_4_,pcVar39,dVar43);
    }
  }
  else {
    bVar33 = true;
    if (mr == 0) {
      dVar43 = 6.733289811407329e-316;
      pcVar39 = "%18ssign    verify    sign/s verify/s\n";
      __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f84a7);
      if (mr != 0) {
        bVar33 = false;
        goto LAB_08074c30;
      }
      dVar43 = 1.0 / (double)CONCAT44(rsa_results._12_4_,rsa_results._8_4_);
      dVar38 = 1.0 / (double)CONCAT44(rsa_results._4_4_,rsa_results._0_4_);
      pcVar39 = (char *)((ulonglong)dVar38 >> 0x20);
      __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x200,rsa_results._0_4_,
                    rsa_results._4_4_,rsa_results._8_4_,rsa_results._12_4_,dVar38,dVar43);
      if (local_285c != 0) goto LAB_08074c7d;
      if (local_2858 == 0) {
        bVar33 = false;
        goto LAB_08075612;
      }
LAB_08075a7f:
      if (mr != 0) {
        bVar33 = false;
LAB_080757e6:
        __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",2,0x800,rsa_results._32_4_,rsa_results._36_4_,
                      rsa_results._40_4_,rsa_results._44_4_,pcVar39,dVar43);
        goto LAB_08075612;
      }
      dVar43 = 1.0 / (double)CONCAT44(rsa_results._44_4_,rsa_results._40_4_);
      dVar38 = 1.0 / (double)CONCAT44(rsa_results._36_4_,rsa_results._32_4_);
      pcVar39 = (char *)((ulonglong)dVar38 >> 0x20);
      __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x800,rsa_results._32_4_,
                    rsa_results._36_4_,rsa_results._40_4_,rsa_results._44_4_,dVar38,dVar43);
      if (local_2854 == 0) goto LAB_08074d34;
      goto LAB_08074ce4;
    }
LAB_08074c30:
    __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",0,0x200,rsa_results._0_4_,rsa_results._4_4_,
                  rsa_results._8_4_,rsa_results._12_4_);
    if (local_285c == 0) goto LAB_080757bd;
    if (bVar33) goto LAB_08075774;
LAB_08074c7d:
    if (mr != 0) {
      bVar33 = false;
      goto LAB_08075786;
    }
    dVar43 = 1.0 / (double)CONCAT44(rsa_results._28_4_,rsa_results._24_4_);
    dVar38 = 1.0 / (double)CONCAT44(rsa_results._20_4_,rsa_results._16_4_);
    pcVar39 = (char *)((ulonglong)dVar38 >> 0x20);
    __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x400,rsa_results._16_4_,
                  rsa_results._20_4_,rsa_results._24_4_,rsa_results._28_4_,dVar38,dVar43);
    if (local_2858 != 0) goto LAB_08075a7f;
    if (local_2854 != 0) goto LAB_08074ce4;
  }
LAB_08074d34:
  if (local_287c == 0) {
    if (local_2878 == 0) {
      if (local_2874 != 0) goto LAB_0807568e;
    }
    else {
LAB_08075822:
      bVar33 = true;
      if (mr == 0) {
        dVar43 = 6.733289811407329e-316;
        pcVar39 = "%18ssign    verify    sign/s verify/s\n";
        __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f84a7);
        goto LAB_08074da1;
      }
LAB_08075835:
      __fprintf_chk(stdout,1,"+F3:%u:%u:%f:%f\n",1,0x400,dsa_results._16_4_,dsa_results._20_4_,
                    dsa_results._24_4_,dsa_results._28_4_,pcVar39,dVar43);
LAB_0807586c:
      if (local_2874 != 0) {
        if (!bVar33) goto LAB_08074dfa;
LAB_0807568e:
        if (mr == 0) {
          dVar43 = 6.733289811407329e-316;
          pcVar39 = "%18ssign    verify    sign/s verify/s\n";
          __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f84a7);
          goto LAB_08074dfa;
        }
        goto LAB_0807569c;
      }
    }
  }
  else {
    bVar33 = true;
    if (mr == 0) {
      dVar43 = 6.733289811407329e-316;
      pcVar39 = "%18ssign    verify    sign/s verify/s\n";
      __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_081f84a7);
      if (mr != 0) {
        bVar33 = false;
        goto LAB_08074d54;
      }
      dVar43 = 1.0 / (double)CONCAT44(dsa_results._12_4_,dsa_results._8_4_);
      dVar38 = 1.0 / (double)CONCAT44(dsa_results._4_4_,dsa_results._0_4_);
      pcVar39 = (char *)((ulonglong)dVar38 >> 0x20);
      __fprintf_chk(stdout,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x200,dsa_results._0_4_,
                    dsa_results._4_4_,dsa_results._8_4_,dsa_results._12_4_,dVar38,dVar43);
      if (local_2878 != 0) goto LAB_08074da1;
    }
    else {
LAB_08074d54:
      __fprintf_chk(stdout,1,"+F3:%u:%u:%f:%f\n",0,0x200,dsa_results._0_4_,dsa_results._4_4_,
                    dsa_results._8_4_,dsa_results._12_4_,pcVar39,dVar43);
      if (local_2878 == 0) goto LAB_0807586c;
      if (bVar33) goto LAB_08075822;
LAB_08074da1:
      if (mr != 0) {
        bVar33 = false;
        goto LAB_08075835;
      }
      dVar43 = 1.0 / (double)CONCAT44(dsa_results._28_4_,dsa_results._24_4_);
      dVar38 = 1.0 / (double)CONCAT44(dsa_results._20_4_,dsa_results._16_4_);
      pcVar39 = (char *)((ulonglong)dVar38 >> 0x20);
      __fprintf_chk(stdout,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x400,dsa_results._16_4_,
                    dsa_results._20_4_,dsa_results._24_4_,dsa_results._28_4_,dVar38,dVar43);
    }
    if (local_2874 == 0) goto LAB_08074e49;
LAB_08074dfa:
    if (mr == 0) {
      dVar43 = 1.0 / (double)CONCAT44(dsa_results._44_4_,dsa_results._40_4_);
      dVar38 = 1.0 / (double)CONCAT44(dsa_results._36_4_,dsa_results._32_4_);
      pcVar39 = (char *)((ulonglong)dVar38 >> 0x20);
      __fprintf_chk(stdout,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",0x800,dsa_results._32_4_,
                    dsa_results._36_4_,dsa_results._40_4_,dsa_results._44_4_,dVar38,dVar43);
    }
    else {
LAB_0807569c:
      __fprintf_chk(stdout,1,"+F3:%u:%u:%f:%f\n",2,0x800,dsa_results._32_4_,dsa_results._36_4_,
                    dsa_results._40_4_,dsa_results._44_4_,pcVar39,dVar43);
    }
  }
LAB_08074e49:
  iVar16 = 0;
  bVar33 = true;
  pdVar26 = (double *)(ecdsa_results + 8);
  do {
    while (local_2770[iVar16] == 0) {
LAB_08074e9d:
      iVar16 = iVar16 + 1;
      pdVar26 = pdVar26 + 2;
      if (iVar16 == 0x10) goto LAB_08074f15;
    }
    if (bVar33) {
      bVar33 = true;
      if (mr == 0) {
        dVar43 = 6.733289811407329e-316;
        pcVar39 = "%30ssign    verify    sign/s verify/s\n";
        __printf_chk(1,"%30ssign    verify    sign/s verify/s\n",&DAT_081f84a7);
        goto joined_r0x0807505f;
      }
LAB_08074e72:
      __fprintf_chk(stdout,1,"+F4:%u:%u:%f:%f\n",iVar16,
                    *(undefined4 *)(test_curves_bits_17974 + iVar16 * 4),
                    *(undefined4 *)(pdVar26 + -1),*(undefined4 *)((int)pdVar26 + -4),
                    *(undefined4 *)pdVar26,*(undefined4 *)((int)pdVar26 + 4),pcVar39,dVar43);
      goto LAB_08074e9d;
    }
joined_r0x0807505f:
    if (mr != 0) {
      bVar33 = false;
      goto LAB_08074e72;
    }
    dVar38 = *pdVar26;
    bVar33 = false;
    iVar17 = iVar16 * 4;
    iVar8 = iVar16 * 4;
    iVar16 = iVar16 + 1;
    __fprintf_chk(stdout,1,"%4u bit ecdsa (%s) %8.4fs %8.4fs %8.1f %8.1f\n",
                  *(undefined4 *)(test_curves_bits_17974 + iVar8),
                  *(undefined4 *)(test_curves_names_17973 + iVar17),pdVar26[-1],SUB84(dVar38,0),
                  (int)((ulonglong)dVar38 >> 0x20),1.0 / pdVar26[-1],1.0 / dVar38);
    pdVar26 = pdVar26 + 2;
  } while (iVar16 != 0x10);
LAB_08074f15:
  iVar16 = 0;
  bVar33 = true;
  do {
    while (local_2730[iVar16] == 0) {
LAB_08074f73:
      iVar16 = iVar16 + 1;
      if (iVar16 == 0x10) goto LAB_08074fde;
    }
    if (bVar33) {
      if (mr == 0) {
        __printf_chk(1,"%30sop      op/s\n",&DAT_081f84a7);
        goto joined_r0x0807508b;
      }
LAB_08074f3d:
      dVar38 = *(double *)(ecdh_results + iVar16 * 8);
      __fprintf_chk(stdout,1,"+F5:%u:%u:%f:%f\n",iVar16,
                    *(undefined4 *)(test_curves_bits_17974 + iVar16 * 4),SUB84(dVar38,0),
                    (int)((ulonglong)dVar38 >> 0x20),(double)_DAT_081f7080 / dVar38);
      goto LAB_08074f73;
    }
joined_r0x0807508b:
    if (mr != 0) {
      bVar33 = false;
      goto LAB_08074f3d;
    }
    dVar38 = *(double *)(ecdh_results + iVar16 * 8);
    bVar33 = false;
    iVar17 = iVar16 * 4;
    iVar8 = iVar16 * 4;
    iVar16 = iVar16 + 1;
    __fprintf_chk(stdout,1,"%4u bit ecdh (%s) %8.4fs %8.1f\n",
                  *(undefined4 *)(test_curves_bits_17974 + iVar8),
                  *(undefined4 *)(test_curves_names_17973 + iVar17),SUB84(dVar38,0),
                  (int)((ulonglong)dVar38 >> 0x20),(double)_DAT_081f7080 / dVar38);
  } while (iVar16 != 0x10);
LAB_08074fde:
  uVar20 = 0;
LAB_0807189c:
  ERR_print_errors(bio_err);
  CRYPTO_free(data);
  CRYPTO_free(out);
LAB_08070e1c:
  ppRVar27 = local_2870;
  do {
    if (*ppRVar27 != (RSA *)0x0) {
      RSA_free(*ppRVar27);
    }
    ppRVar27 = ppRVar27 + 1;
  } while (&local_2860 != ppRVar27);
  ppDVar28 = local_2888;
  do {
    if (*ppDVar28 != (DSA *)0x0) {
      DSA_free(*ppDVar28);
    }
    ppDVar28 = ppDVar28 + 1;
  } while (local_2888 + 3 != ppDVar28);
  ppEVar24 = local_2830;
  do {
    if (*ppEVar24 != (EC_KEY *)0x0) {
      EC_KEY_free(*ppEVar24);
    }
    ppEVar24 = ppEVar24 + 1;
  } while (local_27f0 != ppEVar24);
  iVar16 = 0;
  do {
    if (local_27f0[iVar16] != (EC_KEY *)0x0) {
      EC_KEY_free(local_27f0[iVar16]);
    }
    if (local_27b0[iVar16] != (EC_KEY *)0x0) {
      EC_KEY_free(local_27b0[iVar16]);
    }
    iVar16 = iVar16 + 1;
  } while (iVar16 != 0x10);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar20;
}

