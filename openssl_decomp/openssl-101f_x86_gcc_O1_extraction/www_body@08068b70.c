
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
  size_t sid_ctx_len;
  BIO *pBVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  _STACK *p_Var11;
  SSL_CIPHER *pSVar12;
  char *pcVar13;
  undefined *data;
  char *pcVar14;
  BIO *b;
  SSL_SESSION *ses;
  X509 *x;
  int iVar15;
  undefined4 extraout_ECX;
  uint uVar16;
  uint uVar17;
  char *pcVar18;
  int in_GS_OFFSET;
  bool bVar19;
  byte bVar20;
  char *pcVar21;
  undefined4 local_24;
  int local_20;
  
  bVar20 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  buf = (char *)CRYPTO_malloc(0x4000,"s_server.c",0xa09);
  uVar2 = 0;
  if (buf == (char *)0x0) goto LAB_08068c6a;
  pBVar3 = BIO_f_buffer();
  bp = BIO_new(pBVar3);
  pBVar3 = BIO_f_ssl();
  pBVar4 = BIO_new(pBVar3);
  if ((bp == (BIO *)0x0) || (pBVar4 == (BIO *)0x0)) goto LAB_08068cc0;
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
        sid_ctx_len = strlen((char *)param_3);
        SSL_set_session_id_context(ssl,param_3,sid_ctx_len);
      }
      pBVar7 = BIO_new_socket(param_2,0);
      if (s_nbio_test != 0) {
        pBVar3 = BIO_f_nbio_test();
        b = BIO_new(pBVar3);
        pBVar7 = BIO_push(b,pBVar7);
      }
      SSL_set_bio(ssl,pBVar7,pBVar7);
      SSL_set_accept_state(ssl);
      BIO_ctrl(pBVar4,0x6d,1,ssl);
      BIO_push(bp,pBVar4);
      if (s_debug != 0) {
        SSL_set_debug(ssl,1);
        pBVar4 = SSL_get_rbio(ssl);
        BIO_set_callback(pBVar4,bio_dump_callback);
        pBVar4 = bio_s_out;
        pBVar7 = SSL_get_rbio(ssl);
        BIO_set_callback_arg(pBVar7,(char *)pBVar4);
      }
      if (s_msg != 0) {
        SSL_set_msg_callback(ssl,msg_cb);
        SSL_ctrl(ssl,0x10,0,bio_s_out);
      }
joined_r0x08068da8:
      do {
        if (hack != 0) {
          while ((iVar5 = SSL_accept(ssl), iVar5 < 1 &&
                 (iVar8 = SSL_get_error(ssl,iVar5), iVar8 == 4))) {
            uVar2 = srp_callback_parm._0_4_;
            BIO_printf(bio_s_out,"LOOKUP during accept %s\n",srp_callback_parm._0_4_);
            srp_callback_parm._8_4_ =
                 SRP_VBASE_get_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
            if (srp_callback_parm._8_4_ == 0) {
              BIO_printf(bio_s_out,"LOOKUP not successful\n",uVar2);
            }
            else {
              BIO_printf(bio_s_out,"LOOKUP done %s\n",
                         *(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
            }
          }
          uVar9 = SSL_get_error(ssl,iVar5);
          if (uVar9 < 7) {
            uVar9 = 1 << ((byte)uVar9 & 0x1f);
            if ((uVar9 & 0x62) != 0) goto LAB_08068cc0;
            if ((uVar9 & 0x1c) != 0) goto joined_r0x08068da8;
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
            goto LAB_08068cc0;
          }
          BIO_printf(bio_s_out,"read R BLOCK\n");
          sleep(1);
          goto joined_r0x08068da8;
        }
        if (iVar5 == 0) goto LAB_080693e5;
        bVar19 = www == 1;
        if (!bVar19) {
          bVar19 = www == 2;
          if (bVar19) {
            iVar5 = 10;
            pcVar21 = "GET /stats ";
            pcVar13 = buf;
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar19 = *pcVar21 == *pcVar13;
              pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
              pcVar13 = pcVar13 + (uint)bVar20 * -2 + 1;
            } while (bVar19);
            if (bVar19) break;
          }
          else {
            bVar19 = www == 3;
            if (!bVar19) goto joined_r0x08068da8;
          }
          iVar5 = 5;
          pcVar21 = "GET /";
          pcVar13 = buf;
          do {
            pcVar18 = pcVar13;
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            pcVar18 = pcVar13 + (uint)bVar20 * -2 + 1;
            bVar19 = *pcVar21 == *pcVar13;
            pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
            pcVar13 = pcVar18;
          } while (bVar19);
          if (bVar19) {
            cVar1 = buf[5];
            pcVar21 = buf + 5;
            if (cVar1 == '\0') goto LAB_08069470;
            if (cVar1 == ' ') {
              buf[5] = '\0';
              goto LAB_080694d5;
            }
            uVar9 = 1;
            pcVar13 = pcVar21;
            goto LAB_0806919c;
          }
          goto joined_r0x08068da8;
        }
        iVar5 = 4;
        pcVar21 = "GET ";
        pcVar13 = buf;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar19 = *pcVar21 == *pcVar13;
          pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
          pcVar13 = pcVar13 + (uint)bVar20 * -2 + 1;
        } while (bVar19);
      } while (!bVar19);
      BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
      BIO_puts(bp,"<HTML><BODY BGCOLOR=\"#ffffff\">\n");
      BIO_puts(bp,"<pre>\n");
      BIO_puts(bp,"\n");
      if (0 < local_argc) {
        iVar5 = 0;
        do {
          iVar8 = iVar5 * 4;
          iVar5 = iVar5 + 1;
          BIO_puts(bp,*(char **)(local_argv + iVar8));
          BIO_write(bp,&DAT_081f84a7,1);
        } while (iVar5 < local_argc);
      }
      BIO_puts(bp,"\n");
      lVar6 = SSL_ctrl(ssl,0x4c,0,(void *)0x0);
      puVar10 = &DAT_081ec74a;
      if (lVar6 == 0) {
        puVar10 = &DAT_081f450a;
      }
      BIO_printf(bp,"Secure Renegotiation IS%s supported\n",puVar10);
      BIO_printf(bp,"Ciphers supported in s_server binary\n");
      p_Var11 = (_STACK *)SSL_get_ciphers(ssl);
      uVar9 = sk_num(p_Var11);
      if (0 < (int)uVar9) {
        pSVar12 = (SSL_CIPHER *)sk_value(p_Var11,0);
        pcVar21 = SSL_CIPHER_get_name(pSVar12);
        pcVar13 = SSL_CIPHER_get_version(pSVar12);
        uVar16 = 1;
        BIO_printf(bp,"%-11s:%-25s",pcVar13,pcVar21);
        while (uVar17 = uVar16, uVar9 != uVar16) {
          while( true ) {
            uVar16 = uVar17 + 1;
            pSVar12 = (SSL_CIPHER *)sk_value(p_Var11,uVar17);
            pcVar21 = SSL_CIPHER_get_name(pSVar12);
            pcVar13 = SSL_CIPHER_get_version(pSVar12);
            BIO_printf(bp,"%-11s:%-25s",pcVar13,pcVar21);
            if (((uVar16 & 1) != 0) || (uVar9 == uVar16)) break;
            BIO_puts(bp,"\n");
            uVar17 = uVar16;
            if (uVar9 == uVar16) goto LAB_08069085;
          }
        }
      }
LAB_08069085:
      BIO_puts(bp,"\n");
      pcVar21 = SSL_get_shared_ciphers(ssl,buf,0x4000);
      if (pcVar21 != (char *)0x0) {
        iVar5 = 0;
        BIO_printf(bp,"---\nCiphers common between both SSL end points:\n");
        cVar1 = *pcVar21;
        if (cVar1 != '\0') {
          iVar8 = 0;
          do {
            if (cVar1 == ':') {
              iVar8 = iVar8 + 1;
              BIO_write(bp,&DAT_081f47a9,0x1a - iVar5);
              data = &DAT_081f84a7;
              if (iVar8 == (iVar8 / 3) * 3) {
                data = &DAT_081f11d3;
              }
              iVar5 = 0;
              BIO_write(bp,data,1);
            }
            else {
              iVar5 = iVar5 + 1;
              BIO_write(bp,pcVar21,1);
            }
            pcVar21 = pcVar21 + 1;
            cVar1 = *pcVar21;
          } while (cVar1 != '\0');
        }
        BIO_puts(bp,"\n");
      }
      iVar5 = SSL_cache_hit(ssl);
      pcVar21 = "---\nReused, ";
      if (iVar5 == 0) {
        pcVar21 = "---\nNew, ";
      }
      BIO_printf(bp,pcVar21);
      pSVar12 = SSL_get_current_cipher(ssl);
      pcVar21 = SSL_CIPHER_get_name(pSVar12);
      pcVar13 = SSL_CIPHER_get_version(pSVar12);
      BIO_printf(bp,"%s, Cipher is %s\n",pcVar13,pcVar21);
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
      goto LAB_080693d2;
    }
    goto LAB_08068cc0;
  }
  BIO_printf(bio_s_out,"ACCEPT\n");
  CRYPTO_free(buf);
  goto LAB_08068c59;
LAB_08069470:
  BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
  BIO_printf(bp,"\'%s\' is an invalid file name\r\n",pcVar21);
  goto LAB_080693d2;
LAB_0806919c:
  do {
    pcVar14 = pcVar13;
    if (uVar9 == 1) {
      if (cVar1 == '.') {
        cVar1 = pcVar13[1];
        pcVar14 = pcVar13 + 1;
        if (cVar1 == '\0') goto LAB_08069470;
        if (cVar1 == ' ') {
          pcVar13[1] = '\0';
          goto LAB_080694c8;
        }
        if (cVar1 == '.') {
          cVar1 = pcVar13[2];
          pcVar14 = pcVar13 + 2;
          if (cVar1 == '\0') goto LAB_08069470;
          if (cVar1 != ' ') {
            if (cVar1 != '/') goto LAB_08069418;
            pcVar14 = pcVar13 + 3;
            if (pcVar13[3] == '\0') goto LAB_08069470;
            if (pcVar13[3] != ' ') {
              pcVar14 = pcVar13 + 4;
              if (pcVar13[4] == '\0') goto LAB_08069470;
              if (pcVar13[4] != ' ') {
                uVar9 = 0xffffffff;
                goto LAB_080691ad;
              }
              pcVar13[4] = '\0';
              pcVar14 = pcVar13;
              goto LAB_08069498;
            }
          }
          *pcVar14 = '\0';
          pcVar14 = pcVar13;
          goto LAB_08069498;
        }
      }
LAB_08069418:
      uVar9 = (uint)(cVar1 == '/');
    }
    else if (uVar9 == 0) goto LAB_08069418;
LAB_080691ad:
    cVar1 = pcVar14[1];
    pcVar13 = pcVar14 + 1;
    if (cVar1 == '\0') goto LAB_08069470;
    pcVar18 = pcVar13;
  } while (cVar1 != ' ');
  pcVar14[1] = '\0';
  if ((uVar9 + 1 & 0xfffffffb) == 0) {
LAB_08069498:
    BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
    BIO_printf(bp,"\'%s\' contains \'..\' reference\r\n",pcVar21,pcVar14);
  }
  else {
LAB_080694c8:
    if (buf[5] == '/') {
      pcVar13 = buf;
      BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      BIO_printf(bp,"\'%s\' is an invalid path\r\n",pcVar21,pcVar13);
    }
    else {
LAB_080694d5:
      iVar5 = app_isdir(pcVar21);
      if (iVar5 < 1) {
        pBVar4 = BIO_new_file(pcVar21,"r");
        if (pBVar4 == (BIO *)0x0) {
          BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          BIO_printf(bp,"Error opening \'%s\'\r\n",pcVar21,pcVar18);
          ERR_print_errors(bp);
        }
        else {
          if (s_quiet == 0) {
            BIO_printf(bio_err,"FILE:%s\n",pcVar21,extraout_ECX);
          }
          if (www == 2) {
            uVar9 = 0xffffffff;
            do {
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              cVar1 = *pcVar21;
              pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
            } while (cVar1 != '\0');
            uVar9 = ~uVar9;
            if ((int)(uVar9 - 1) < 6) {
              if (uVar9 - 1 == 5) goto LAB_080696a4;
LAB_080696d0:
              pcVar21 = "HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n";
            }
            else {
              iVar5 = strcmp(buf + (uVar9 - 1),".html");
              if (iVar5 != 0) {
LAB_080696a4:
                iVar5 = strcmp(buf + uVar9,".php");
                if ((iVar5 != 0) && (iVar5 = strcmp(buf + uVar9,".htm"), iVar5 != 0))
                goto LAB_080696d0;
              }
              pcVar21 = "HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n";
            }
            BIO_puts(bp,pcVar21);
          }
          while (iVar5 = BIO_read(pBVar4,buf,0x4000), 0 < iVar5) {
            iVar8 = 0;
            do {
              iVar15 = BIO_write(bp,buf + iVar8,iVar5 - iVar8);
              if (iVar15 < 1) {
                iVar15 = BIO_test_flags(bp,8);
                if (iVar15 == 0) goto LAB_080695c9;
                BIO_printf(bio_s_out,"rwrite W BLOCK\n");
              }
              else {
                iVar8 = iVar8 + iVar15;
              }
            } while (iVar8 < iVar5);
          }
LAB_080695c9:
          BIO_free(pBVar4);
        }
      }
      else {
        BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        BIO_printf(bp,"\'%s\' is a directory\r\n",pcVar21);
      }
    }
  }
LAB_080693d2:
  do {
    lVar6 = BIO_ctrl(bp,0xb,0,(void *)0x0);
    if (0 < lVar6) break;
    iVar5 = BIO_test_flags(bp,8);
  } while (iVar5 != 0);
LAB_080693e5:
  SSL_set_shutdown(ssl,3);
LAB_08068cc0:
  BIO_printf(bio_s_out,"ACCEPT\n");
  CRYPTO_free(buf);
  uVar2 = 1;
  if (bp != (BIO *)0x0) {
LAB_08068c59:
    BIO_free_all(bp);
    uVar2 = 1;
  }
LAB_08068c6a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

