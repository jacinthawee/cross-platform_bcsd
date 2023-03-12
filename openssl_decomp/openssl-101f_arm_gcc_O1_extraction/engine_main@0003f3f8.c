
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 engine_main(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  _STACK *st;
  _STACK *st_00;
  _STACK *st_01;
  int iVar5;
  BIO *bio;
  uint uVar6;
  ENGINE *pEVar7;
  char *pcVar8;
  RSA_METHOD *pRVar9;
  RAND_METHOD *dst;
  DSA_METHOD *pDVar10;
  DH_METHOD *pDVar11;
  size_t sVar12;
  RAND_METHOD *pRVar13;
  ENGINE_CIPHERS_PTR pEVar14;
  size_t sVar15;
  _STACK *st_02;
  uint uVar16;
  int iVar17;
  size_t sVar18;
  int iVar19;
  ENGINE_DIGESTS_PTR pEVar20;
  ENGINE_PKEY_METHS_PTR pEVar21;
  undefined *puVar22;
  uint uVar23;
  size_t sVar24;
  char *pcVar25;
  undefined4 uVar26;
  undefined **ppuVar27;
  char **ppcVar28;
  char **ppcVar29;
  char *pcVar30;
  int local_60;
  int local_54;
  char *local_38;
  int *local_2c [2];
  
  st = sk_new_null();
  st_00 = sk_new_null();
  st_01 = sk_new_null();
  signal(0xd,(__sighandler_t)0x1);
  SSL_load_error_strings();
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar5 = load_config(bio_err,0);
  if (iVar5 == 0) {
    ERR_print_errors(bio_err);
    sk_pop_free(st,(func *)0x3f2f5);
    sk_pop_free(st_00,(func *)0x3f2f5);
    sk_pop_free(st_01,(func *)0x3f2f5);
    return 1;
  }
  param_1 = param_1 + -1;
  bio = BIO_new_fp(stdout,0);
  ppcVar28 = (char **)(param_2 + 4);
  sVar24 = 0;
  if (param_1 < 1) {
    bVar3 = false;
    local_60 = 0;
    bVar4 = false;
  }
  else {
    sVar24 = 0;
    bVar3 = false;
    bVar4 = false;
    local_60 = 0;
    do {
      pcVar30 = *ppcVar28;
      uVar6 = strncmp(pcVar30,"-v",2);
      ppcVar29 = ppcVar28;
      if (uVar6 != 0) {
        cVar1 = *pcVar30;
        if (((cVar1 == '-') && (pcVar30[1] == 'c')) && (pcVar30[2] == '\0')) {
          bVar3 = true;
          goto LAB_0003f4e6;
        }
        uVar6 = strncmp(pcVar30,"-t",2);
        if (uVar6 == 0) {
          cVar1 = pcVar30[1];
          while (cVar1 == 't') {
            cVar1 = pcVar30[uVar6 + 2];
            uVar6 = uVar6 + 1;
          }
          sVar18 = strlen(pcVar30 + 1);
          if ((uVar6 < sVar18) || (local_60 = sVar18 - 1, 1 < local_60)) goto LAB_0003f670;
          bVar4 = true;
          goto LAB_0003f4e6;
        }
        iVar5 = strcmp(pcVar30,"-pre");
        if (iVar5 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0003f670;
          sk_push(st_00,ppcVar28[1]);
          ppcVar29 = ppcVar28 + 1;
          goto LAB_0003f4e6;
        }
        iVar5 = strcmp(pcVar30,"-post");
        if (iVar5 == 0) {
          param_1 = param_1 + -1;
          ppcVar29 = ppcVar28 + 1;
          if (param_1 == 0) goto LAB_0003f670;
          sk_push(st_01,ppcVar28[1]);
          goto LAB_0003f4e6;
        }
        iVar5 = strncmp(pcVar30,"-h",2);
        if ((iVar5 != 0) && (((cVar1 != '-' || (pcVar30[1] != '?')) || (pcVar30[2] != '\0')))) {
          sk_push(st,pcVar30);
          goto LAB_0003f4e6;
        }
LAB_0003f670:
        ppuVar27 = &engine_usage;
        puVar22 = engine_usage;
        while (puVar22 != (undefined *)0x0) {
          BIO_printf(bio_err,"%s");
          ppuVar27 = ppuVar27 + 1;
          puVar22 = *ppuVar27;
        }
        goto LAB_0003f694;
      }
      cVar1 = pcVar30[1];
      while (cVar1 == 'v') {
        cVar1 = pcVar30[uVar6 + 2];
        uVar6 = uVar6 + 1;
      }
      sVar24 = strlen(pcVar30 + 1);
      if ((uVar6 < sVar24) || (4 < (int)sVar24)) goto LAB_0003f670;
LAB_0003f4e6:
      param_1 = param_1 + -1;
      ppcVar28 = ppcVar29 + 1;
    } while (0 < param_1);
  }
  iVar5 = sk_num(st);
  if (iVar5 == 0) {
    for (pEVar7 = ENGINE_get_first(); pEVar7 != (ENGINE *)0x0; pEVar7 = ENGINE_get_next(pEVar7)) {
      pcVar30 = ENGINE_get_id(pEVar7);
      sk_push(st,pcVar30);
    }
  }
  local_54 = 0;
  local_38 = "<no description>";
  iVar5 = sk_num(st);
  if (iVar5 < 1) {
LAB_0003f5b4:
    uVar26 = 0;
LAB_0003f696:
    ERR_print_errors(bio_err);
    sk_pop_free(st,(func *)0x3f2f5);
    sk_pop_free(st_00,(func *)0x3f2f5);
    sk_pop_free(st_01,(func *)0x3f2f5);
    if (bio == (BIO *)0x0) {
      return uVar26;
    }
    BIO_free_all(bio);
    return uVar26;
  }
LAB_0003f528:
  pcVar30 = (char *)sk_value(st,local_54);
  pEVar7 = ENGINE_by_id(pcVar30);
  if (pEVar7 == (ENGINE *)0x0) {
    ERR_print_errors(bio_err);
    goto LAB_0003f5a2;
  }
  pcVar8 = ENGINE_get_name(pEVar7);
  BIO_printf(bio,"(%s) %s\n",pcVar30,pcVar8);
  util_do_cmds_isra_0(pEVar7,st_00,bio);
  pcVar8 = ENGINE_get_id(pEVar7);
  iVar5 = strcmp(pcVar8,pcVar30);
  if (iVar5 != 0) {
    pcVar30 = ENGINE_get_id(pEVar7);
    pcVar8 = ENGINE_get_name(pEVar7);
    BIO_printf(bio,"Loaded: (%s) %s\n",pcVar30,pcVar8);
  }
  if (bVar3) {
    pRVar9 = ENGINE_get_RSA(pEVar7);
    if (pRVar9 == (RSA_METHOD *)0x0) {
      pDVar10 = ENGINE_get_DSA(pEVar7);
      if (pDVar10 != (DSA_METHOD *)0x0) {
        dst = (RAND_METHOD *)CRYPTO_malloc(0x100,"engine.c",0x6b);
        if (dst != (RAND_METHOD *)0x0) {
          *(undefined *)&dst->seed = 0;
          goto LAB_0003f73c;
        }
LAB_0003f694:
        uVar26 = 1;
        goto LAB_0003f696;
      }
      pDVar11 = ENGINE_get_DH(pEVar7);
      if (pDVar11 == (DH_METHOD *)0x0) {
        sVar18 = 0x100;
        dst = ENGINE_get_RAND(pEVar7);
        if (dst != (RAND_METHOD *)0x0) goto LAB_0003fa8e;
        goto LAB_0003f7ca;
      }
      dst = (RAND_METHOD *)CRYPTO_malloc(0x100,"engine.c",0x6b);
      if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
      sVar18 = 0x100;
      *(undefined *)&dst->seed = 0;
LAB_0003f776:
      sVar12 = strlen((char *)dst);
      if (sVar18 <= sVar12 + 2) {
        sVar18 = sVar18 + 0x100;
        dst = (RAND_METHOD *)CRYPTO_realloc(dst,sVar18,"engine.c",0x77);
        if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
      }
      if (*(char *)&dst->seed != '\0') {
        BUF_strlcat((char *)dst,", ",sVar18);
      }
      BUF_strlcat((char *)dst,"DH",sVar18);
      pRVar13 = ENGINE_get_RAND(pEVar7);
      if (pRVar13 != (RAND_METHOD *)0x0) goto LAB_0003f7a4;
    }
    else {
      dst = (RAND_METHOD *)CRYPTO_malloc(0x100,"engine.c",0x6b);
      if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
      *(char *)&dst->seed = '\0';
      sVar18 = 0x100;
      BUF_strlcat((char *)dst,"RSA",0x100);
      pDVar10 = ENGINE_get_DSA(pEVar7);
      if (pDVar10 != (DSA_METHOD *)0x0) {
LAB_0003f73c:
        sVar18 = strlen((char *)dst);
        if (sVar18 + 3 < 0x100) {
          sVar18 = 0x100;
        }
        else {
          dst = (RAND_METHOD *)CRYPTO_realloc(dst,0x200,"engine.c",0x77);
          if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
          sVar18 = 0x200;
        }
        if (*(char *)&dst->seed != '\0') {
          BUF_strlcat((char *)dst,", ",sVar18);
        }
        BUF_strlcat((char *)dst,"DSA",sVar18);
      }
      pDVar11 = ENGINE_get_DH(pEVar7);
      if (pDVar11 != (DH_METHOD *)0x0) goto LAB_0003f776;
      pRVar13 = ENGINE_get_RAND(pEVar7);
      if (pRVar13 != (RAND_METHOD *)0x0) {
        if (dst == (RAND_METHOD *)0x0) {
LAB_0003fa8e:
          dst = (RAND_METHOD *)CRYPTO_malloc(0x100,"engine.c",0x6b);
          if (dst != (RAND_METHOD *)0x0) {
            sVar18 = 0x100;
            *(undefined *)&dst->seed = 0;
            goto LAB_0003f7a4;
          }
          goto LAB_0003f694;
        }
LAB_0003f7a4:
        sVar12 = strlen((char *)dst);
        if (sVar18 <= sVar12 + 4) {
          sVar18 = sVar18 + 0x100;
          dst = (RAND_METHOD *)CRYPTO_realloc(dst,sVar18,"engine.c",0x77);
          if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
        }
        if (*(char *)&dst->seed != '\0') {
          BUF_strlcat((char *)dst,", ",sVar18);
        }
        BUF_strlcat((char *)dst,"RAND",sVar18);
      }
    }
LAB_0003f7ca:
    pEVar14 = ENGINE_get_ciphers(pEVar7);
    if ((pEVar14 != (ENGINE_CIPHERS_PTR)0x0) &&
       (iVar5 = (*pEVar14)(pEVar7,(EVP_CIPHER **)0x0,local_2c,0), 0 < iVar5)) {
      iVar17 = 0;
      do {
        pcVar30 = OBJ_nid2sn(local_2c[0][iVar17]);
        if (dst == (RAND_METHOD *)0x0) {
          dst = (RAND_METHOD *)CRYPTO_malloc(0x100,"engine.c",0x6b);
          sVar18 = 0x100;
          if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
          *(undefined *)&dst->seed = 0;
        }
        iVar17 = iVar17 + 1;
        sVar12 = strlen((char *)dst);
        sVar15 = strlen(pcVar30);
        if (sVar18 <= sVar15 + sVar12) {
          sVar18 = sVar18 + 0x100;
          dst = (RAND_METHOD *)CRYPTO_realloc(dst,sVar18,"engine.c",0x77);
          if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
        }
        if (*(char *)&dst->seed != '\0') {
          BUF_strlcat((char *)dst,", ",sVar18);
        }
        BUF_strlcat((char *)dst,pcVar30,sVar18);
      } while (iVar17 != iVar5);
    }
    pEVar20 = ENGINE_get_digests(pEVar7);
    if ((pEVar20 != (ENGINE_DIGESTS_PTR)0x0) &&
       (iVar5 = (*pEVar20)(pEVar7,(EVP_MD **)0x0,local_2c,0), 0 < iVar5)) {
      iVar17 = 0;
      do {
        pcVar30 = OBJ_nid2sn(local_2c[0][iVar17]);
        if (dst == (RAND_METHOD *)0x0) {
          dst = (RAND_METHOD *)CRYPTO_malloc(0x100,"engine.c",0x6b);
          sVar18 = 0x100;
          if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
          *(undefined *)&dst->seed = 0;
        }
        iVar17 = iVar17 + 1;
        sVar12 = strlen((char *)dst);
        sVar15 = strlen(pcVar30);
        if (sVar18 <= sVar15 + sVar12) {
          sVar18 = sVar18 + 0x100;
          dst = (RAND_METHOD *)CRYPTO_realloc(dst,sVar18,"engine.c",0x77);
          if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
        }
        if (*(char *)&dst->seed != '\0') {
          BUF_strlcat((char *)dst,", ",sVar18);
        }
        BUF_strlcat((char *)dst,pcVar30,sVar18);
      } while (iVar17 != iVar5);
    }
    pEVar21 = ENGINE_get_pkey_meths(pEVar7);
    if ((pEVar21 == (ENGINE_PKEY_METHS_PTR)0x0) ||
       (iVar5 = (*pEVar21)(pEVar7,(EVP_PKEY_METHOD **)0x0,local_2c,0), iVar5 < 1)) {
      if (dst != (RAND_METHOD *)0x0) goto LAB_0003fe74;
    }
    else {
      iVar17 = 0;
      do {
        pcVar30 = OBJ_nid2sn(local_2c[0][iVar17]);
        if (dst == (RAND_METHOD *)0x0) {
          dst = (RAND_METHOD *)CRYPTO_malloc(0x100,"engine.c",0x6b);
          sVar18 = 0x100;
          if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
          *(undefined *)&dst->seed = 0;
        }
        iVar17 = iVar17 + 1;
        sVar12 = strlen((char *)dst);
        sVar15 = strlen(pcVar30);
        if (sVar18 <= sVar15 + sVar12) {
          sVar18 = sVar18 + 0x100;
          dst = (RAND_METHOD *)CRYPTO_realloc(dst,sVar18,"engine.c",0x77);
          if (dst == (RAND_METHOD *)0x0) goto LAB_0003f694;
        }
        if (*(char *)&dst->seed != '\0') {
          BUF_strlcat((char *)dst,", ",sVar18);
        }
        BUF_strlcat((char *)dst,pcVar30,sVar18);
      } while (iVar17 != iVar5);
LAB_0003fe74:
      if (*(char *)&dst->seed != '\0') {
        BIO_printf(bio," [%s]\n",dst);
      }
    }
    CRYPTO_free(dst);
  }
  if (bVar4) {
    BIO_printf(bio,"%s",&DAT_00131dcc);
    iVar5 = ENGINE_init(pEVar7);
    if (iVar5 == 0) {
      BIO_printf(bio,"[ unavailable ]\n");
      if (local_60 != 0) {
        ERR_print_errors_fp(stdout);
      }
      ERR_clear_error();
    }
    else {
      BIO_printf(bio,"[ available ]\n");
      util_do_cmds_isra_0(pEVar7,st_01,bio);
      ENGINE_finish(pEVar7);
    }
  }
  if (((0 < (int)sVar24) && (iVar5 = ENGINE_ctrl(pEVar7,10,0,(void *)0x0,(f *)0x0), iVar5 != 0)) &&
     (iVar5 = ENGINE_ctrl(pEVar7,0xb,0,(void *)0x0,(f *)0x0), 0 < iVar5)) {
    st_02 = sk_new_null();
    if (st_02 == (_STACK *)0x0) goto LAB_0003f694;
    uVar6 = 0;
    do {
      uVar16 = ENGINE_ctrl(pEVar7,0x12,iVar5,(void *)0x0,(f *)0x0);
      if ((int)uVar16 < 0) {
LAB_0003fe48:
        bVar2 = false;
        goto LAB_0003fe4a;
      }
      if (((uVar16 & 8) == 0) || (3 < (int)sVar24)) {
        iVar17 = ENGINE_ctrl(pEVar7,0xe,iVar5,(void *)0x0,(f *)0x0);
        if ((iVar17 < 1) ||
           (pcVar30 = (char *)CRYPTO_malloc(iVar17 + 1,"engine.c",0xe6), pcVar30 == (char *)0x0))
        goto LAB_0003fe48;
        iVar17 = ENGINE_ctrl(pEVar7,0xf,iVar5,pcVar30,(f *)0x0);
        if (iVar17 < 1) {
LAB_0003fec4:
          pcVar8 = (char *)0x0;
        }
        else {
          pcVar8 = (char *)ENGINE_ctrl(pEVar7,0x10,iVar5,(void *)0x0,(f *)0x0);
          if ((int)pcVar8 < 0) goto LAB_0003fec4;
          if ((pcVar8 == (char *)0x0) ||
             ((pcVar8 = (char *)CRYPTO_malloc((int)(pcVar8 + 1),"engine.c",0xf1),
              pcVar8 != (char *)0x0 &&
              (iVar17 = ENGINE_ctrl(pEVar7,0x11,iVar5,pcVar8,(f *)0x0), 0 < iVar17)))) {
            if (uVar6 == 0) {
              iVar17 = BIO_puts(bio,"     ");
            }
            else {
              iVar17 = BIO_printf(bio,", ");
              iVar17 = uVar6 + iVar17;
            }
            if (sVar24 == 1) {
              if ((5 < iVar17) && (sVar18 = strlen(pcVar30), 0x4e < (int)(sVar18 + iVar17))) {
                BIO_printf(bio,"\n");
                iVar17 = BIO_puts(bio,"     ");
              }
              iVar19 = BIO_printf(bio,"%s",pcVar30);
              uVar16 = iVar17 + iVar19;
            }
            else {
              pcVar25 = local_38;
              if (pcVar8 != (char *)0x0) {
                pcVar25 = pcVar8;
              }
              BIO_printf(bio,"%s: %s\n",pcVar30,pcVar25);
              if (sVar24 == 2) {
                uVar16 = 0;
              }
              else {
                BIO_printf(bio,"%s%s(input flags): ",&DAT_00131dcc,&DAT_00131dcc);
                if (uVar16 == 0) {
                  BIO_printf(bio,"<no flags>\n");
                }
                else {
                  if ((uVar16 & 8) != 0) {
                    BIO_printf(bio,"[Internal] ");
                  }
                  uVar6 = uVar16 & 1;
                  if (uVar6 == 0) {
                    uVar23 = uVar16 & 2;
                    if (uVar23 != 0) {
LAB_0003fe06:
                      BIO_printf(bio,"STRING");
                      if ((int)(uVar16 * 0x20000000) < 0) goto LAB_0003fe60;
                      goto joined_r0x0003fe1c;
                    }
                    uVar6 = uVar16 & 4;
                    if (uVar6 != 0) goto LAB_0003fbf6;
LAB_0003fc60:
                    if ((uVar16 & 0xfffffff0) != 0) {
                      if (uVar6 != 0) {
                        uVar6 = 0;
                        goto LAB_0003fc0a;
                      }
                      goto LAB_0003fc18;
                    }
                  }
                  else {
                    BIO_printf(bio,"NUMERIC");
                    if ((int)(uVar16 * 0x40000000) < 0) {
                      uVar6 = 1;
                      BIO_printf(bio,"|");
                      goto LAB_0003fe06;
                    }
                    if (-1 < (int)(uVar16 * 0x20000000)) {
                      uVar6 = 1;
                      goto LAB_0003fc60;
                    }
LAB_0003fe60:
                    uVar23 = 1;
                    BIO_printf(bio,"|");
LAB_0003fbf6:
                    BIO_printf(bio,"NO_INPUT");
                    uVar6 = uVar23;
joined_r0x0003fe1c:
                    if ((uVar16 & 0xfffffff0) != 0) {
LAB_0003fc0a:
                      BIO_printf(bio,"|");
LAB_0003fc18:
                      BIO_printf(bio,"<0x%04X>",uVar16 & 0xfffffff0);
                    }
                    if (uVar6 != 0) {
                      BIO_printf(bio,"  <illegal flags!>");
                    }
                  }
                  uVar16 = 0;
                  BIO_printf(bio,"\n");
                }
              }
            }
            CRYPTO_free(pcVar30);
            uVar6 = uVar16;
            if (pcVar8 != (char *)0x0) {
              CRYPTO_free(pcVar8);
            }
            goto LAB_0003f8a0;
          }
        }
        sk_pop_free(st_02,(func *)0x3f2f5);
        CRYPTO_free(pcVar30);
        if (pcVar8 != (char *)0x0) {
          CRYPTO_free(pcVar8);
        }
        goto LAB_0003f694;
      }
      CRYPTO_free((void *)0x0);
LAB_0003f8a0:
      iVar5 = ENGINE_ctrl(pEVar7,0xc,iVar5,(void *)0x0,(f *)0x0);
    } while (0 < iVar5);
    if ((int)uVar6 < 1) {
      bVar2 = true;
    }
    else {
      bVar2 = true;
      BIO_printf(bio,"\n");
    }
LAB_0003fe4a:
    sk_pop_free(st_02,(func *)0x3f2f5);
    if (!bVar2) goto LAB_0003f694;
  }
  ENGINE_free(pEVar7);
LAB_0003f5a2:
  local_54 = local_54 + 1;
  iVar5 = sk_num(st);
  if (iVar5 <= local_54) goto LAB_0003f5b4;
  goto LAB_0003f528;
}

