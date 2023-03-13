
undefined4 www_body(undefined4 param_1,int param_2,uchar *param_3)

{
  char cVar1;
  char *buf;
  undefined4 uVar2;
  BIO_METHOD *pBVar3;
  BIO *bp;
  BIO *pBVar4;
  int iVar5;
  long lVar6;
  SSL *ssl;
  size_t sVar7;
  BIO *pBVar8;
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  _STACK *p_Var12;
  SSL_CIPHER *pSVar13;
  char *pcVar14;
  undefined *data;
  char *pcVar15;
  SSL_SESSION *ses;
  X509 *x;
  BIO *b;
  int iVar16;
  char *pcVar17;
  uint uVar18;
  uint uVar19;
  int in_GS_OFFSET;
  bool bVar20;
  byte bVar21;
  undefined4 local_24;
  int local_20;
  
  bVar21 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  buf = (char *)CRYPTO_malloc(0x4000,"s_server.c",0x9f9);
  uVar2 = 0;
  if (buf == (char *)0x0) goto LAB_0806915a;
  pBVar3 = BIO_f_buffer();
  bp = BIO_new(pBVar3);
  pBVar3 = BIO_f_ssl();
  pBVar4 = BIO_new(pBVar3);
  if ((bp == (BIO *)0x0) || (pBVar4 == (BIO *)0x0)) goto LAB_08069190;
  if (s_nbio != 0) {
    local_24 = 1;
    if (s_quiet == 0) {
      BIO_printf(bio_err,"turning on non blocking io\n");
    }
    iVar5 = BIO_socket_ioctl(param_2,0x5421,&local_24);
    if (iVar5 < 0) {
      ERR_print_errors(bio_err);
    }
  }
  lVar6 = BIO_int_ctrl(bp,0x75,0x4000,1);
  if (lVar6 != 0) {
    ssl = SSL_new(ctx);
    if (ssl != (SSL *)0x0) {
      if (s_tlsextdebug != 0) {
        SSL_callback_ctrl(ssl,0x38,tlsext_cb);
        SSL_ctrl(ssl,0x39,0,bio_s_out);
      }
      if (param_3 != (uchar *)0x0) {
        sVar7 = strlen((char *)param_3);
        SSL_set_session_id_context(ssl,param_3,sVar7);
      }
      pBVar8 = BIO_new_socket(param_2,0);
      if (s_nbio_test != 0) {
        pBVar3 = BIO_f_nbio_test();
        b = BIO_new(pBVar3);
        pBVar8 = BIO_push(b,pBVar8);
      }
      SSL_set_bio(ssl,pBVar8,pBVar8);
      SSL_set_accept_state(ssl);
      BIO_ctrl(pBVar4,0x6d,1,ssl);
      BIO_push(bp,pBVar4);
      if (s_debug != 0) {
        SSL_set_debug(ssl,1);
        pBVar4 = SSL_get_rbio(ssl);
        BIO_set_callback(pBVar4,bio_dump_callback);
        pBVar4 = bio_s_out;
        pBVar8 = SSL_get_rbio(ssl);
        BIO_set_callback_arg(pBVar8,(char *)pBVar4);
      }
      if (s_msg != 0) {
        SSL_set_msg_callback(ssl,msg_cb);
        SSL_ctrl(ssl,0x10,0,bio_s_out);
      }
joined_r0x08069267:
      do {
        if (hack != 0) {
          while ((iVar5 = SSL_accept(ssl), iVar5 < 1 &&
                 (iVar9 = SSL_get_error(ssl,iVar5), iVar9 == 4))) {
            uVar2 = srp_callback_parm._0_4_;
            BIO_printf(bio_s_out,"LOOKUP during accept %s\n",srp_callback_parm._0_4_);
            SRP_user_pwd_free(srp_callback_parm._8_4_);
            srp_callback_parm._8_4_ =
                 SRP_VBASE_get1_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
            if (srp_callback_parm._8_4_ == 0) {
              BIO_printf(bio_s_out,"LOOKUP not successful\n",uVar2);
            }
            else {
              BIO_printf(bio_s_out,"LOOKUP done %s\n",
                         *(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
            }
          }
          uVar10 = SSL_get_error(ssl,iVar5);
          if (uVar10 < 7) {
            uVar10 = 1 << ((byte)uVar10 & 0x1f);
            if ((uVar10 & 0x62) != 0) goto LAB_08069190;
            if ((uVar10 & 0x1c) != 0) goto joined_r0x08069267;
          }
          SSL_renegotiate(ssl);
          SSL_write(ssl,(void *)0x0,0);
        }
        iVar5 = BIO_gets(bp,buf,0x3fff);
        if (iVar5 < 0) {
          iVar5 = BIO_test_flags(bp,8);
          if (iVar5 == 0) {
            if (s_quiet == 0) {
              ERR_print_errors(bio_err);
            }
            goto LAB_08069190;
          }
          BIO_printf(bio_s_out,"read R BLOCK\n");
          iVar5 = BIO_test_flags(bp,4);
          if ((iVar5 == 0) || (iVar5 = BIO_get_retry_reason(bp), iVar5 != 1)) {
            sleep(1);
          }
          else {
            BIO_printf(bio_s_out,"LOOKUP renego during read\n");
            SRP_user_pwd_free(srp_callback_parm._8_4_);
            srp_callback_parm._8_4_ =
                 SRP_VBASE_get1_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
            if (srp_callback_parm._8_4_ == 0) {
              BIO_printf(bio_s_out,"LOOKUP not successful\n");
            }
            else {
              BIO_printf(bio_s_out,"LOOKUP done %s\n",
                         *(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
            }
          }
          goto joined_r0x08069267;
        }
        if (iVar5 == 0) goto LAB_08069815;
        bVar20 = www == 1;
        if (!bVar20) {
          bVar20 = www == 2;
          if (bVar20) {
            iVar5 = 0xb;
            pcVar15 = "GET /stats ";
            pcVar14 = buf;
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar20 = *pcVar15 == *pcVar14;
              pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
              pcVar14 = pcVar14 + (uint)bVar21 * -2 + 1;
            } while (bVar20);
            if (bVar20) break;
          }
          else {
            bVar20 = www == 3;
            if (!bVar20) goto joined_r0x08069267;
          }
          iVar5 = 5;
          pcVar15 = "GET /";
          pcVar14 = buf;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar20 = *pcVar15 == *pcVar14;
            pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
            pcVar14 = pcVar14 + (uint)bVar21 * -2 + 1;
          } while (bVar20);
          if (bVar20) {
            pcVar15 = buf + 5;
            cVar1 = buf[5];
            if (cVar1 == '\0') goto LAB_080699ee;
            if (cVar1 == ' ') {
              buf[5] = '\0';
              goto LAB_08069a33;
            }
            uVar10 = 1;
            pcVar14 = pcVar15;
            goto LAB_08069671;
          }
          goto joined_r0x08069267;
        }
        iVar5 = 4;
        pcVar15 = "GET ";
        pcVar14 = buf;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar20 = *pcVar15 == *pcVar14;
          pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar21 * -2 + 1;
        } while (bVar20);
      } while (!bVar20);
      BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
      BIO_puts(bp,"<HTML><BODY BGCOLOR=\"#ffffff\">\n");
      BIO_puts(bp,"<pre>\n");
      BIO_puts(bp,"\n");
      if (0 < local_argc) {
        iVar5 = 0;
        do {
          iVar9 = iVar5 * 4;
          iVar5 = iVar5 + 1;
          BIO_puts(bp,*(char **)(local_argv + iVar9));
          BIO_write(bp,&DAT_081f8b67,1);
        } while (iVar5 < local_argc);
      }
      BIO_puts(bp,"\n");
      lVar6 = SSL_ctrl(ssl,0x4c,0,(void *)0x0);
      puVar11 = &DAT_081eca46;
      if (lVar6 == 0) {
        puVar11 = &DAT_081f4b16;
      }
      BIO_printf(bp,"Secure Renegotiation IS%s supported\n",puVar11);
      BIO_printf(bp,"Ciphers supported in s_server binary\n");
      p_Var12 = (_STACK *)SSL_get_ciphers(ssl);
      uVar10 = sk_num(p_Var12);
      if (0 < (int)uVar10) {
        pSVar13 = (SSL_CIPHER *)sk_value(p_Var12,0);
        pcVar15 = SSL_CIPHER_get_name(pSVar13);
        pcVar14 = SSL_CIPHER_get_version(pSVar13);
        uVar18 = 1;
        BIO_printf(bp,"%-11s:%-25s",pcVar14,pcVar15);
        while (uVar19 = uVar18, uVar10 != uVar18) {
          while( true ) {
            uVar18 = uVar19 + 1;
            pSVar13 = (SSL_CIPHER *)sk_value(p_Var12,uVar19);
            pcVar15 = SSL_CIPHER_get_name(pSVar13);
            pcVar14 = SSL_CIPHER_get_version(pSVar13);
            BIO_printf(bp,"%-11s:%-25s",pcVar14,pcVar15);
            if (((uVar18 & 1) != 0) || (uVar10 == uVar18)) break;
            BIO_puts(bp,"\n");
            uVar19 = uVar18;
            if (uVar10 == uVar18) goto LAB_08069555;
          }
        }
      }
LAB_08069555:
      BIO_puts(bp,"\n");
      pcVar15 = SSL_get_shared_ciphers(ssl,buf,0x4000);
      if (pcVar15 != (char *)0x0) {
        iVar5 = 0;
        BIO_printf(bp,"---\nCiphers common between both SSL end points:\n");
        cVar1 = *pcVar15;
        if (cVar1 != '\0') {
          iVar9 = 0;
          do {
            if (cVar1 == ':') {
              iVar9 = iVar9 + 1;
              BIO_write(bp,&DAT_081f4dc8,0x1a - iVar5);
              data = &DAT_081f15cb;
              if (iVar9 != (iVar9 / 3) * 3) {
                data = &DAT_081f8b67;
              }
              iVar5 = 0;
              BIO_write(bp,data,1);
            }
            else {
              iVar5 = iVar5 + 1;
              BIO_write(bp,pcVar15,1);
            }
            pcVar15 = pcVar15 + 1;
            cVar1 = *pcVar15;
          } while (cVar1 != '\0');
        }
        BIO_puts(bp,"\n");
      }
      iVar5 = SSL_cache_hit(ssl);
      pcVar15 = "---\nNew, ";
      if (iVar5 != 0) {
        pcVar15 = "---\nReused, ";
      }
      BIO_printf(bp,pcVar15);
      pSVar13 = SSL_get_current_cipher(ssl);
      pcVar15 = SSL_CIPHER_get_name(pSVar13);
      pcVar14 = SSL_CIPHER_get_version(pSVar13);
      BIO_printf(bp,"%s, Cipher is %s\n",pcVar14,pcVar15);
      ses = SSL_get_session(ssl);
      SSL_SESSION_print(bp,ses);
      BIO_printf(bp,"---\n");
      SSL_get_SSL_CTX(ssl);
      print_stats();
      BIO_printf(bp,"---\n");
      x = SSL_get_peer_certificate(ssl);
      if (x == (X509 *)0x0) {
        BIO_puts(bp,"no client certificate available\n");
      }
      else {
        BIO_printf(bp,"Client certificate\n");
        X509_print(bp,x);
        PEM_write_bio_X509(bp,x);
      }
      BIO_puts(bp,"</BODY></HTML>\r\n\r\n");
      goto LAB_08069802;
    }
    goto LAB_08069190;
  }
  BIO_printf(bio_s_out,"ACCEPT\n");
  CRYPTO_free(buf);
  goto LAB_08069149;
LAB_080699ee:
  BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
  BIO_printf(bp,"\'%s\' is an invalid file name\r\n",pcVar15);
  goto LAB_08069802;
LAB_08069671:
  do {
    pcVar17 = pcVar14;
    if (uVar10 == 1) {
      if (cVar1 == '.') {
        cVar1 = pcVar14[1];
        if (cVar1 == '\0') goto LAB_080699ee;
        if (cVar1 == ' ') {
          pcVar14[1] = '\0';
          goto LAB_08069a26;
        }
        pcVar17 = pcVar14 + 1;
        if (cVar1 == '.') {
          cVar1 = pcVar14[2];
          pcVar17 = pcVar14 + 2;
          if (cVar1 == '\0') goto LAB_080699ee;
          if (cVar1 != ' ') {
            if (cVar1 != '/') goto LAB_0806987a;
            pcVar17 = pcVar14 + 3;
            if (pcVar14[3] == '\0') goto LAB_080699ee;
            if (pcVar14[3] != ' ') {
              pcVar17 = pcVar14 + 4;
              pcVar14 = pcVar14 + 4;
              if (*pcVar17 == '\0') goto LAB_080699ee;
              if (*pcVar17 != ' ') {
                uVar10 = 0xffffffff;
                goto LAB_08069682;
              }
              uVar10 = 0xffffffff;
              break;
            }
          }
          *pcVar17 = '\0';
          goto LAB_08069aa4;
        }
      }
LAB_0806987a:
      pcVar14 = pcVar17;
      uVar10 = (uint)(cVar1 == '/');
    }
    else if (uVar10 == 0) goto LAB_0806987a;
LAB_08069682:
    cVar1 = pcVar14[1];
    pcVar14 = pcVar14 + 1;
    if (cVar1 == '\0') goto LAB_080699ee;
  } while (cVar1 != ' ');
  *pcVar14 = '\0';
  if ((uVar10 + 1 & 0xfffffffb) == 0) {
LAB_08069aa4:
    BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
    BIO_printf(bp,"\'%s\' contains \'..\' reference\r\n",pcVar15);
  }
  else {
LAB_08069a26:
    if (buf[5] == '/') {
      BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      BIO_printf(bp,"\'%s\' is an invalid path\r\n",pcVar15);
    }
    else {
LAB_08069a33:
      iVar5 = app_isdir(pcVar15);
      if (iVar5 < 1) {
        pBVar4 = BIO_new_file(pcVar15,"r");
        if (pBVar4 == (BIO *)0x0) {
          BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          BIO_printf(bp,"Error opening \'%s\'\r\n",pcVar15);
          ERR_print_errors(bp);
        }
        else {
          if (s_quiet == 0) {
            BIO_printf(bio_err,"FILE:%s\n",pcVar15);
          }
          if (www == 2) {
            sVar7 = strlen(pcVar15);
            bVar20 = sVar7 == 5;
            if ((int)sVar7 < 6) {
              if (bVar20) goto LAB_08069c63;
LAB_08069c8f:
              pcVar15 = "HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n";
            }
            else {
              iVar5 = 6;
              pcVar15 = buf + sVar7;
              pcVar14 = ".html";
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar20 = *pcVar15 == *pcVar14;
                pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
                pcVar14 = pcVar14 + (uint)bVar21 * -2 + 1;
              } while (bVar20);
              if (!bVar20) {
LAB_08069c63:
                iVar5 = 5;
                pcVar15 = buf + sVar7 + 1;
                pcVar14 = ".php";
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar20 = *pcVar15 == *pcVar14;
                  pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
                  pcVar14 = pcVar14 + (uint)bVar21 * -2 + 1;
                } while (bVar20);
                if (!bVar20) {
                  iVar5 = 5;
                  pcVar15 = buf + sVar7 + 1;
                  pcVar14 = ".htm";
                  do {
                    if (iVar5 == 0) break;
                    iVar5 = iVar5 + -1;
                    bVar20 = *pcVar15 == *pcVar14;
                    pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
                    pcVar14 = pcVar14 + (uint)bVar21 * -2 + 1;
                  } while (bVar20);
                  if (!bVar20) goto LAB_08069c8f;
                }
              }
              pcVar15 = "HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n";
            }
            BIO_puts(bp,pcVar15);
          }
          while (iVar5 = BIO_read(pBVar4,buf,0x4000), 0 < iVar5) {
            iVar9 = 0;
            do {
              iVar16 = BIO_write(bp,buf + iVar9,iVar5 - iVar9);
              if (iVar16 < 1) {
                iVar16 = BIO_test_flags(bp,8);
                if (iVar16 == 0) goto LAB_08069b89;
                BIO_printf(bio_s_out,"rwrite W BLOCK\n");
              }
              else {
                iVar9 = iVar9 + iVar16;
              }
            } while (iVar9 < iVar5);
          }
LAB_08069b89:
          BIO_free(pBVar4);
        }
      }
      else {
        BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        BIO_printf(bp,"\'%s\' is a directory\r\n",pcVar15);
      }
    }
  }
LAB_08069802:
  do {
    lVar6 = BIO_ctrl(bp,0xb,0,(void *)0x0);
    if (0 < lVar6) break;
    iVar5 = BIO_test_flags(bp,8);
  } while (iVar5 != 0);
LAB_08069815:
  SSL_set_shutdown(ssl,3);
LAB_08069190:
  BIO_printf(bio_s_out,"ACCEPT\n");
  CRYPTO_free(buf);
  uVar2 = 1;
  if (bp != (BIO *)0x0) {
LAB_08069149:
    BIO_free_all(bp);
    uVar2 = 1;
  }
LAB_0806915a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

