
undefined4 engine_main(int param_1,byte **param_2)

{
  byte bVar1;
  char cVar2;
  byte *data;
  bool bVar3;
  bool bVar4;
  _STACK *st;
  _STACK *st_00;
  _STACK *st_01;
  int iVar5;
  BIO *bio;
  char *pcVar6;
  ENGINE *pEVar7;
  char *pcVar8;
  RSA_METHOD *pRVar9;
  DSA_METHOD *pDVar10;
  size_t sVar11;
  DH_METHOD *pDVar12;
  RAND_METHOD *pRVar13;
  ENGINE_CIPHERS_PTR pEVar14;
  ENGINE *pEVar15;
  _STACK *st_02;
  uint uVar16;
  int iVar17;
  ENGINE_DIGESTS_PTR pEVar18;
  size_t sVar19;
  ENGINE_PKEY_METHS_PTR pEVar20;
  undefined4 uVar21;
  byte **ppbVar22;
  undefined1 *puVar23;
  uint uVar24;
  byte *pbVar25;
  byte *pbVar26;
  int in_GS_OFFSET;
  bool bVar27;
  bool bVar28;
  bool bVar29;
  byte bVar30;
  undefined *puVar31;
  undefined *puVar32;
  size_t local_64;
  void *local_60;
  int local_40;
  int local_3c;
  int local_38;
  int **local_30;
  int *local_24;
  int local_20;
  
  bVar30 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
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
    sk_pop_free(st,identity);
    uVar21 = 1;
    sk_pop_free(st_00,identity);
    sk_pop_free(st_01,identity);
    goto LAB_0808cf9b;
  }
  bio = BIO_new_fp(stdout,0);
  param_1 = param_1 + -1;
  local_3c = 0;
  bVar4 = false;
  bVar3 = false;
  local_64 = 0;
  bVar28 = param_1 == 0;
  if (0 < param_1) {
    do {
      ppbVar22 = param_2 + 1;
      data = *ppbVar22;
      iVar5 = 2;
      pbVar25 = data;
      pbVar26 = &DAT_081fc3f6;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar28 = *pbVar25 == *pbVar26;
        pbVar25 = pbVar25 + (uint)bVar30 * -2 + 1;
        pbVar26 = pbVar26 + (uint)bVar30 * -2 + 1;
      } while (bVar28);
      if (!bVar28) {
        bVar1 = *data;
        bVar28 = 0x2d < bVar1;
        bVar29 = bVar1 == 0x2d;
        if (bVar29) {
          bVar28 = data[1] < 99;
          bVar29 = data[1] == 99;
          if (bVar29) {
            bVar28 = false;
            bVar29 = data[2] == 0;
            if (bVar29) {
              bVar3 = true;
              goto LAB_0808d050;
            }
          }
        }
        iVar5 = 2;
        pbVar25 = data;
        pbVar26 = (byte *)0x8208d35;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar28 = *pbVar25 < *pbVar26;
          bVar29 = *pbVar25 == *pbVar26;
          pbVar25 = pbVar25 + (uint)bVar30 * -2 + 1;
          pbVar26 = pbVar26 + (uint)bVar30 * -2 + 1;
        } while (bVar29);
        bVar27 = (!bVar28 && !bVar29) < bVar28;
        bVar28 = (!bVar28 && !bVar29) == bVar28;
        uVar16 = 0;
        if (bVar28) {
          do {
            uVar24 = uVar16;
            uVar16 = uVar24 + 1;
          } while (data[uVar24 + 1] == 0x74);
          sVar19 = strlen((char *)(data + 1));
          if ((uVar24 < sVar19) || (local_3c = sVar19 - 1, 1 < local_3c)) goto LAB_0808d2b2;
          bVar4 = true;
          goto LAB_0808d050;
        }
        iVar5 = 5;
        pbVar25 = data;
        pbVar26 = &DAT_081fc3f9;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar27 = *pbVar25 < *pbVar26;
          bVar28 = *pbVar25 == *pbVar26;
          pbVar25 = pbVar25 + (uint)bVar30 * -2 + 1;
          pbVar26 = pbVar26 + (uint)bVar30 * -2 + 1;
        } while (bVar28);
        bVar29 = (!bVar27 && !bVar28) < bVar27;
        bVar28 = (!bVar27 && !bVar28) == bVar27;
        if (bVar28) {
          param_1 = param_1 + -1;
          ppbVar22 = param_2 + 2;
          if (param_1 == 0) goto LAB_0808d2b2;
          sk_push(st_00,param_2[2]);
          goto LAB_0808d050;
        }
        iVar5 = 6;
        pbVar25 = data;
        pbVar26 = (byte *)"-post";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar29 = *pbVar25 < *pbVar26;
          bVar28 = *pbVar25 == *pbVar26;
          pbVar25 = pbVar25 + (uint)bVar30 * -2 + 1;
          pbVar26 = pbVar26 + (uint)bVar30 * -2 + 1;
        } while (bVar28);
        bVar27 = (!bVar29 && !bVar28) < bVar29;
        bVar28 = (!bVar29 && !bVar28) == bVar29;
        if (bVar28) {
          param_1 = param_1 + -1;
          ppbVar22 = param_2 + 2;
          if (param_1 == 0) goto LAB_0808d2b2;
          sk_push(st_01,param_2[2]);
          goto LAB_0808d050;
        }
        iVar5 = 2;
        pbVar25 = data;
        pbVar26 = &DAT_081f9673;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar27 = *pbVar25 < *pbVar26;
          bVar28 = *pbVar25 == *pbVar26;
          pbVar25 = pbVar25 + (uint)bVar30 * -2 + 1;
          pbVar26 = pbVar26 + (uint)bVar30 * -2 + 1;
        } while (bVar28);
        if (((!bVar27 && !bVar28) != bVar27) &&
           (((bVar1 != 0x2d || (data[1] != 0x3f)) || (data[2] != 0)))) {
          sk_push(st,data);
          goto LAB_0808d050;
        }
LAB_0808d2b2:
        puVar23 = engine_usage;
        iVar5 = engine_usage._0_4_;
        while (iVar5 != 0) {
          puVar23 = (undefined1 *)((int)puVar23 + 4);
          BIO_printf(bio_err,"%s",iVar5);
          iVar5 = *(int *)puVar23;
        }
        goto LAB_0808d2e0;
      }
      uVar16 = 0;
      do {
        uVar24 = uVar16;
        uVar16 = uVar24 + 1;
      } while (data[uVar24 + 1] == 0x76);
      local_64 = strlen((char *)(data + 1));
      if ((uVar24 < local_64) || (4 < (int)local_64)) goto LAB_0808d2b2;
LAB_0808d050:
      param_1 = param_1 + -1;
      bVar28 = param_1 == 0;
      param_2 = ppbVar22;
    } while (!bVar28);
  }
  iVar5 = sk_num(st);
  if (iVar5 == 0) {
    for (pEVar7 = ENGINE_get_first(); pEVar7 != (ENGINE *)0x0; pEVar7 = ENGINE_get_next(pEVar7)) {
      pcVar6 = ENGINE_get_id(pEVar7);
      pEVar7 = (ENGINE *)sk_push(st,pcVar6);
    }
  }
  for (local_40 = 0; iVar5 = sk_num(st), local_40 < iVar5; local_40 = local_40 + 1) {
    pcVar6 = (char *)sk_value(st,local_40);
    pEVar7 = ENGINE_by_id(pcVar6);
    if (pEVar7 == (ENGINE *)0x0) {
      ERR_print_errors(bio_err);
    }
    else {
      pcVar8 = ENGINE_get_name(pEVar7);
      BIO_printf(bio,"(%s) %s\n",pcVar6,pcVar8);
      util_do_cmds_isra_0();
      pcVar8 = ENGINE_get_id(pEVar7);
      iVar5 = strcmp(pcVar8,pcVar6);
      if (iVar5 != 0) {
        pcVar6 = ENGINE_get_name(pEVar7);
        pcVar8 = ENGINE_get_id(pEVar7);
        BIO_printf(bio,"Loaded: (%s) %s\n",pcVar8,pcVar6);
      }
      if (bVar3) {
        pRVar9 = ENGINE_get_RSA(pEVar7);
        if (pRVar9 == (RSA_METHOD *)0x0) {
          pDVar10 = ENGINE_get_DSA(pEVar7);
          if (pDVar10 != (DSA_METHOD *)0x0) {
            pcVar6 = (char *)CRYPTO_malloc(0x100,"engine.c",0x68);
            if (pcVar6 != (char *)0x0) {
              *pcVar6 = '\0';
              sVar19 = 0x100;
              local_60 = (void *)0x100;
              goto LAB_0808d3d5;
            }
            goto LAB_0808d2e0;
          }
          pDVar12 = ENGINE_get_DH(pEVar7);
          if (pDVar12 != (DH_METHOD *)0x0) {
            pcVar6 = (char *)CRYPTO_malloc(0x100,"engine.c",0x68);
            if (pcVar6 != (char *)0x0) {
              *pcVar6 = '\0';
              sVar19 = 0x100;
              local_60 = (void *)0x100;
              goto LAB_0808d41e;
            }
            goto LAB_0808d2e0;
          }
          pRVar13 = ENGINE_get_RAND(pEVar7);
          if (pRVar13 != (RAND_METHOD *)0x0) {
            pcVar6 = (char *)CRYPTO_malloc(0x100,"engine.c",0x68);
            if (pcVar6 != (char *)0x0) {
              *pcVar6 = '\0';
              sVar19 = 0x100;
              local_60 = (void *)0x100;
              goto LAB_0808d45e;
            }
            goto LAB_0808d2e0;
          }
          pcVar6 = (char *)0x0;
          local_60 = (void *)0x100;
        }
        else {
          pcVar6 = (char *)CRYPTO_malloc(0x100,"engine.c",0x68);
          if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
          *pcVar6 = '\0';
          BUF_strlcat(pcVar6,"RSA",0x100);
          pDVar10 = ENGINE_get_DSA(pEVar7);
          if (pDVar10 == (DSA_METHOD *)0x0) {
            sVar19 = 0x100;
            local_60 = (void *)0x100;
          }
          else {
            sVar19 = 0x100;
            sVar11 = strlen(pcVar6);
            local_60 = (void *)0x100;
            if (0xff < sVar11 + 3) {
              pcVar6 = (char *)CRYPTO_realloc(pcVar6,0x200,"engine.c",0x70);
              if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
              sVar19 = 0x200;
              local_60 = (void *)0x200;
            }
            if (*pcVar6 != '\0') {
              BUF_strlcat(pcVar6,", ",sVar19);
            }
LAB_0808d3d5:
            BUF_strlcat(pcVar6,"DSA",sVar19);
          }
          pDVar12 = ENGINE_get_DH(pEVar7);
          if (pDVar12 != (DH_METHOD *)0x0) {
            sVar11 = strlen(pcVar6);
            if (sVar19 <= sVar11 + 2) {
              sVar19 = (int)local_60 + 0x100;
              pcVar6 = (char *)CRYPTO_realloc(pcVar6,sVar19,"engine.c",0x70);
              local_60 = (void *)sVar19;
              if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
            }
            if (*pcVar6 != '\0') {
              BUF_strlcat(pcVar6,", ",sVar19);
            }
LAB_0808d41e:
            BUF_strlcat(pcVar6,"DH",sVar19);
          }
          pRVar13 = ENGINE_get_RAND(pEVar7);
          if (pRVar13 != (RAND_METHOD *)0x0) {
            sVar11 = strlen(pcVar6);
            if (sVar19 <= sVar11 + 4) {
              sVar19 = (int)local_60 + 0x100;
              pcVar6 = (char *)CRYPTO_realloc(pcVar6,sVar19,"engine.c",0x70);
              local_60 = (void *)sVar19;
              if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
            }
            if (*pcVar6 != '\0') {
              BUF_strlcat(pcVar6,", ",sVar19);
            }
LAB_0808d45e:
            BUF_strlcat(pcVar6,"RAND",sVar19);
          }
        }
        pEVar14 = ENGINE_get_ciphers(pEVar7);
        if ((pEVar14 != (ENGINE_CIPHERS_PTR)0x0) &&
           (iVar5 = (*pEVar14)(pEVar7,(EVP_CIPHER **)0x0,&local_24,0), 0 < iVar5)) {
          iVar17 = 0;
          do {
            pcVar8 = OBJ_nid2sn(local_24[iVar17]);
            if (pcVar6 == (char *)0x0) {
              pcVar6 = (char *)CRYPTO_malloc(0x100,"engine.c",0x68);
              if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
              *pcVar6 = '\0';
              sVar19 = strlen(pcVar8);
              if (0xff < sVar19) {
                local_60 = (void *)0x200;
                goto LAB_0808d51a;
              }
              local_60 = (void *)0x100;
            }
            else {
              sVar19 = strlen(pcVar6);
              sVar11 = strlen(pcVar8);
              if (sVar19 + sVar11 < local_60) {
                cVar2 = *pcVar6;
              }
              else {
                local_60 = (void *)((int)local_60 + 0x100);
LAB_0808d51a:
                pcVar6 = (char *)CRYPTO_realloc(pcVar6,(int)local_60,"engine.c",0x70);
                if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
                cVar2 = *pcVar6;
              }
              if (cVar2 != '\0') {
                BUF_strlcat(pcVar6,", ",(size_t)local_60);
              }
            }
            iVar17 = iVar17 + 1;
            BUF_strlcat(pcVar6,pcVar8,(size_t)local_60);
          } while (iVar5 != iVar17);
        }
        pEVar18 = ENGINE_get_digests(pEVar7);
        if ((pEVar18 == (ENGINE_DIGESTS_PTR)0x0) ||
           (iVar5 = (*pEVar18)(pEVar7,(EVP_MD **)0x0,&local_24,0), iVar5 < 1)) {
          pEVar20 = ENGINE_get_pkey_meths(pEVar7);
          if (pEVar20 != (ENGINE_PKEY_METHS_PTR)0x0) goto LAB_0808d967;
LAB_0808e05d:
          if (pcVar6 != (char *)0x0) goto LAB_0808dd4f;
        }
        else {
          iVar17 = 0;
          do {
            pcVar8 = OBJ_nid2sn(local_24[iVar17]);
            if (pcVar6 == (char *)0x0) {
              pcVar6 = (char *)CRYPTO_malloc(0x100,"engine.c",0x68);
              if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
              *pcVar6 = '\0';
              sVar19 = strlen(pcVar8);
              if (0xff < sVar19) {
                local_60 = (void *)0x200;
                goto LAB_0808d8b2;
              }
              local_60 = (void *)0x100;
            }
            else {
              sVar19 = strlen(pcVar6);
              sVar11 = strlen(pcVar8);
              if (local_60 <= sVar19 + sVar11) {
                local_60 = (void *)((int)local_60 + 0x100);
LAB_0808d8b2:
                pcVar6 = (char *)CRYPTO_realloc(pcVar6,(int)local_60,"engine.c",0x70);
                if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
              }
              if (*pcVar6 != '\0') {
                BUF_strlcat(pcVar6,", ",(size_t)local_60);
              }
            }
            iVar17 = iVar17 + 1;
            BUF_strlcat(pcVar6,pcVar8,(size_t)local_60);
          } while (iVar5 != iVar17);
          pEVar20 = ENGINE_get_pkey_meths(pEVar7);
          if (pEVar20 != (ENGINE_PKEY_METHS_PTR)0x0) {
LAB_0808d967:
            local_30 = &local_24;
            iVar5 = (*pEVar20)(pEVar7,(EVP_PKEY_METHOD **)0x0,local_30,0);
            if (iVar5 < 1) goto LAB_0808e05d;
            iVar17 = 0;
            do {
              pcVar8 = OBJ_nid2sn(local_24[iVar17]);
              if (pcVar6 == (char *)0x0) {
                pcVar6 = (char *)CRYPTO_malloc(0x100,"engine.c",0x68);
                if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
                *pcVar6 = '\0';
                sVar19 = strlen(pcVar8);
                if (0xff < sVar19) {
                  local_60 = (void *)0x200;
                  goto LAB_0808d9f2;
                }
                local_60 = (void *)0x100;
              }
              else {
                sVar19 = strlen(pcVar6);
                sVar11 = strlen(pcVar8);
                if (local_60 <= sVar19 + sVar11) {
                  local_60 = (void *)((int)local_60 + 0x100);
LAB_0808d9f2:
                  pcVar6 = (char *)CRYPTO_realloc(pcVar6,(int)local_60,"engine.c",0x70);
                  if (pcVar6 == (char *)0x0) goto LAB_0808d2e0;
                }
                if (*pcVar6 != '\0') {
                  BUF_strlcat(pcVar6,", ",(size_t)local_60);
                }
              }
              iVar17 = iVar17 + 1;
              BUF_strlcat(pcVar6,pcVar8,(size_t)local_60);
            } while (iVar5 != iVar17);
          }
LAB_0808dd4f:
          if (*pcVar6 != '\0') {
            BIO_printf(bio," [%s]\n",pcVar6);
          }
        }
        CRYPTO_free(pcVar6);
      }
      if (bVar4) {
        puVar31 = &DAT_08228101;
        pEVar15 = (ENGINE *)BIO_printf(bio,"%s",&DAT_08228101);
        iVar5 = ENGINE_init(pEVar15);
        if (iVar5 == 0) {
          BIO_printf(bio,"[ unavailable ]\n",puVar31);
          if (local_3c != 0) {
            ERR_print_errors_fp(stdout);
          }
          ERR_clear_error();
        }
        else {
          BIO_printf(bio,"[ available ]\n",puVar31);
          pEVar15 = (ENGINE *)util_do_cmds_isra_0();
          ENGINE_finish(pEVar15);
        }
      }
      if (((0 < (int)local_64) &&
          (iVar5 = ENGINE_ctrl(pEVar7,10,0,(void *)0x0,(f *)0x0), iVar5 != 0)) &&
         (iVar5 = ENGINE_ctrl(pEVar7,0xb,0,(void *)0x0,(f *)0x0), 0 < iVar5)) {
        st_02 = sk_new_null();
        if (st_02 == (_STACK *)0x0) goto LAB_0808d2e0;
        local_38 = 0;
        do {
          uVar16 = ENGINE_ctrl(pEVar7,0x12,iVar5,(void *)0x0,(f *)0x0);
          if ((int)uVar16 < 0) {
LAB_0808de74:
            bVar28 = false;
            goto LAB_0808de76;
          }
          if ((3 < (int)local_64) || ((uVar16 & 8) == 0)) {
            iVar17 = ENGINE_ctrl(pEVar7,0xe,iVar5,(void *)0x0,(f *)0x0);
            if ((iVar17 < 1) ||
               (pcVar6 = (char *)CRYPTO_malloc(iVar17 + 1,"engine.c",0xda), pcVar6 == (char *)0x0))
            goto LAB_0808de74;
            iVar17 = ENGINE_ctrl(pEVar7,0xf,iVar5,pcVar6,(f *)0x0);
            if (iVar17 < 1) {
LAB_0808e049:
              local_60 = (void *)0x0;
            }
            else {
              iVar17 = ENGINE_ctrl(pEVar7,0x10,iVar5,(void *)0x0,(f *)0x0);
              if (iVar17 < 0) goto LAB_0808e049;
              if (iVar17 == 0) {
                local_60 = (void *)0x0;
LAB_0808d704:
                if (local_38 == 0) {
                  iVar17 = BIO_puts(bio,"     ");
                }
                else {
                  iVar17 = BIO_printf(bio,", ");
                  iVar17 = local_38 + iVar17;
                }
                if (local_64 == 1) {
                  if ((5 < iVar17) && (sVar19 = strlen(pcVar6), 0x4e < (int)(sVar19 + iVar17))) {
                    BIO_printf(bio,"\n");
                    iVar17 = BIO_puts(bio,"     ");
                  }
                  local_38 = BIO_printf(bio,"%s",pcVar6);
                  local_38 = local_38 + iVar17;
LAB_0808db34:
                  CRYPTO_free(pcVar6);
                  if (local_60 == (void *)0x0) goto LAB_0808d63b;
                }
                else {
                  if (local_60 == (void *)0x0) {
                    BIO_printf(bio,"%s: %s\n",pcVar6,"<no description>");
                    if (local_64 == 2) {
                      CRYPTO_free(pcVar6);
                      local_38 = 0;
                      goto LAB_0808d63b;
                    }
LAB_0808db7a:
                    puVar32 = &DAT_08228101;
                    puVar31 = &DAT_08228101;
                    BIO_printf(bio,"%s%s(input flags): ",&DAT_08228101,&DAT_08228101);
                    if (uVar16 == 0) {
                      BIO_printf(bio,"<no flags>\n",puVar31,puVar32);
                      local_38 = 0;
                    }
                    else {
                      if ((uVar16 & 8) != 0) {
                        BIO_printf(bio,"[Internal] ",puVar31,puVar32);
                      }
                      if ((uVar16 & 1) == 0) {
                        bVar28 = false;
                        if ((uVar16 & 2) != 0) {
LAB_0808ddd9:
                          BIO_printf(bio,"STRING",puVar31,puVar32);
                          if ((uVar16 & 4) != 0) goto LAB_0808e00f;
                          if ((uVar16 & 0xfffffff0) != 0) goto LAB_0808dfb0;
                          goto LAB_0808de02;
                        }
                        if ((uVar16 & 4) == 0) {
                          if ((uVar16 & 0xfffffff0) == 0) goto LAB_0808dbf2;
                          goto LAB_0808dfc4;
                        }
                        BIO_printf(bio,"NO_INPUT",puVar31,puVar32);
                        if ((uVar16 & 0xfffffff0) != 0) goto LAB_0808dfb0;
                      }
                      else {
                        BIO_printf(bio,"NUMERIC",puVar31,puVar32);
                        if ((uVar16 & 2) != 0) {
                          BIO_printf(bio,"|",puVar31,puVar32);
                          bVar28 = true;
                          goto LAB_0808ddd9;
                        }
                        if ((uVar16 & 4) == 0) {
                          if ((uVar16 & 0xfffffff0) != 0) {
                            bVar28 = false;
                            goto LAB_0808dfb0;
                          }
                          goto LAB_0808dbf2;
                        }
LAB_0808e00f:
                        BIO_printf(bio,"|",puVar31,puVar32);
                        BIO_printf(bio,"NO_INPUT");
                        if ((uVar16 & 0xfffffff0) != 0) {
                          bVar28 = true;
LAB_0808dfb0:
                          BIO_printf(bio,"|",puVar31,puVar32);
LAB_0808dfc4:
                          puVar31 = (undefined *)(uVar16 & 0xfffffff0);
                          BIO_printf(bio,"<0x%04X>",puVar31,puVar32);
LAB_0808de02:
                          if (!bVar28) goto LAB_0808dbf2;
                        }
                        BIO_printf(bio,"  <illegal flags!>",puVar31);
                      }
LAB_0808dbf2:
                      BIO_printf(bio,"\n",puVar31,puVar32);
                      local_38 = 0;
                    }
                    goto LAB_0808db34;
                  }
                  BIO_printf(bio,"%s: %s\n",pcVar6,local_60);
                  if (local_64 != 2) goto LAB_0808db7a;
                  CRYPTO_free(pcVar6);
                  local_38 = 0;
                }
                CRYPTO_free(local_60);
                goto LAB_0808d63b;
              }
              local_60 = CRYPTO_malloc(iVar17 + 1,"engine.c",0xe4);
              if ((local_60 != (void *)0x0) &&
                 (iVar17 = ENGINE_ctrl(pEVar7,0x11,iVar5,local_60,(f *)0x0), 0 < iVar17))
              goto LAB_0808d704;
            }
            sk_pop_free(st_02,identity);
            CRYPTO_free(pcVar6);
            if (local_60 != (void *)0x0) {
              CRYPTO_free(local_60);
            }
            goto LAB_0808d2e0;
          }
          CRYPTO_free((void *)0x0);
LAB_0808d63b:
          iVar5 = ENGINE_ctrl(pEVar7,0xc,iVar5,(void *)0x0,(f *)0x0);
        } while (0 < iVar5);
        bVar28 = true;
        if (0 < local_38) {
          BIO_printf(bio,"\n");
        }
LAB_0808de76:
        sk_pop_free(st_02,identity);
        if (!bVar28) goto LAB_0808d2e0;
      }
      ENGINE_free(pEVar7);
    }
  }
  uVar21 = 0;
LAB_0808d2e5:
  ERR_print_errors(bio_err);
  sk_pop_free(st,identity);
  sk_pop_free(st_00,identity);
  sk_pop_free(st_01,identity);
  if (bio != (BIO *)0x0) {
    BIO_free_all(bio);
  }
LAB_0808cf9b:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar21;
LAB_0808d2e0:
  uVar21 = 1;
  goto LAB_0808d2e5;
}

