
undefined4 www_body(undefined4 param_1,int param_2,uchar *param_3)

{
  char *buf;
  BIO_METHOD *pBVar1;
  BIO *bp;
  BIO *pBVar2;
  int iVar3;
  long lVar4;
  SSL *ssl;
  size_t sVar5;
  BIO *append;
  int iVar6;
  uint uVar7;
  _STACK *p_Var8;
  SSL_CIPHER *pSVar9;
  char *pcVar10;
  char *pcVar11;
  BIO *b;
  SSL_SESSION *ses;
  SSL_CTX *pSVar12;
  X509 *x;
  int iVar13;
  uint uVar14;
  byte *pbVar15;
  char cVar16;
  byte *filename;
  char *local_38;
  undefined4 local_2c [2];
  
  buf = (char *)CRYPTO_malloc(0x4000,"s_server.c",0xa09);
  if (buf == (char *)0x0) {
    return 0;
  }
  pBVar1 = BIO_f_buffer();
  bp = BIO_new(pBVar1);
  pBVar1 = BIO_f_ssl();
  pBVar2 = BIO_new(pBVar1);
  if (bp != (BIO *)0x0 && pBVar2 != (BIO *)0x0) {
    if (s_nbio != 0) {
      local_2c[0] = 1;
      if (s_quiet == 0) {
        BIO_printf(bio_err,"turning on non blocking io\n");
      }
      iVar3 = BIO_socket_ioctl(param_2,0x5421,local_2c);
      if (iVar3 < 0) {
        ERR_print_errors(bio_err);
      }
    }
    lVar4 = BIO_int_ctrl(bp,0x75,0x4000,1);
    if ((lVar4 != 0) && (ssl = SSL_new(ctx), ssl != (SSL *)0x0)) {
      if (s_tlsextdebug != 0) {
        SSL_callback_ctrl(ssl,0x38,tlsext_cb + 1);
        SSL_ctrl(ssl,0x39,0,bio_s_out);
      }
      if (param_3 != (uchar *)0x0) {
        sVar5 = strlen((char *)param_3);
        SSL_set_session_id_context(ssl,param_3,sVar5);
      }
      append = BIO_new_socket(param_2,0);
      if (s_nbio_test != 0) {
        pBVar1 = BIO_f_nbio_test();
        b = BIO_new(pBVar1);
        append = BIO_push(b,append);
      }
      SSL_set_bio(ssl,append,append);
      SSL_set_accept_state(ssl);
      BIO_ctrl(pBVar2,0x6d,1,ssl);
      BIO_push(bp,pBVar2);
      if (s_debug != 0) {
        SSL_set_debug(ssl,1);
        pBVar2 = SSL_get_rbio(ssl);
        BIO_set_callback(pBVar2,bio_dump_callback + 1);
        pBVar2 = SSL_get_rbio(ssl);
        BIO_set_callback_arg(pBVar2,(char *)bio_s_out);
      }
      if (s_msg != 0) {
        SSL_set_msg_callback(ssl,msg_cb + 1);
        SSL_ctrl(ssl,0x10,0,bio_s_out);
      }
joined_r0x00026e78:
      do {
        if (hack != 0) {
          while (iVar3 = SSL_accept(ssl), iVar3 < 1) {
            while( true ) {
              iVar6 = SSL_get_error(ssl,iVar3);
              if (iVar6 != 4) goto LAB_00026ef6;
              BIO_printf(bio_s_out,"LOOKUP during accept %s\n",srp_callback_parm._0_4_);
              srp_callback_parm._8_4_ =
                   SRP_VBASE_get_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
              if (srp_callback_parm._8_4_ == 0) break;
              BIO_printf(bio_s_out,"LOOKUP done %s\n",
                         *(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
              iVar3 = SSL_accept(ssl);
              if (0 < iVar3) goto LAB_00026ef6;
            }
            BIO_printf(bio_s_out,"LOOKUP not successful\n");
          }
LAB_00026ef6:
          iVar3 = SSL_get_error(ssl,iVar3);
          if (iVar3 - 1U < 6) {
            uVar7 = 1 << (iVar3 - 1U & 0xff);
            if ((uVar7 & 0x31) != 0) goto LAB_00026d8e;
            if ((uVar7 & 0xe) != 0) goto joined_r0x00026e78;
          }
          SSL_renegotiate(ssl);
          SSL_write(ssl,(void *)0x0,0);
        }
        iVar3 = BIO_gets(bp,buf,0x3fff);
        if (iVar3 < 0) {
          iVar3 = BIO_test_flags(bp,8);
          if (iVar3 == 0) {
            if (s_quiet != 0) goto LAB_00026d8e;
            ERR_print_errors(bio_err);
            goto LAB_000271e4;
          }
          BIO_printf(bio_s_out,"read R BLOCK\n");
          sleep(1);
          goto joined_r0x00026e78;
        }
        if (iVar3 == 0) goto LAB_00027394;
        if (www == 1) {
          iVar3 = strncmp("GET ",buf,4);
          if (iVar3 == 0) {
LAB_00026f50:
            BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
            BIO_puts(bp,"<HTML><BODY BGCOLOR=\"#ffffff\">\n");
            BIO_puts(bp,"<pre>\n");
            BIO_puts(bp,"\n");
            if (0 < local_argc) {
              iVar3 = 0;
              do {
                iVar6 = iVar3 * 4;
                iVar3 = iVar3 + 1;
                BIO_puts(bp,*(char **)(local_argv + iVar6));
                BIO_write(bp,&DAT_00131dd0,1);
              } while (iVar3 < local_argc);
            }
            BIO_puts(bp,"\n");
            lVar4 = SSL_ctrl(ssl,0x4c,0,(void *)0x0);
            pcVar10 = "";
            if (lVar4 == 0) {
              pcVar10 = " NOT";
            }
            BIO_printf(bp,"Secure Renegotiation IS%s supported\n",pcVar10);
            BIO_printf(bp,"Ciphers supported in s_server binary\n");
            p_Var8 = (_STACK *)SSL_get_ciphers(ssl);
            iVar3 = sk_num(p_Var8);
            if (0 < iVar3) {
              pSVar9 = (SSL_CIPHER *)sk_value(p_Var8,0);
              pcVar10 = SSL_CIPHER_get_version(pSVar9);
              pcVar11 = SSL_CIPHER_get_name(pSVar9);
              iVar6 = 1;
              BIO_printf(bp,"%-11s:%-25s",pcVar10,pcVar11);
              while (iVar13 = iVar6, iVar6 != iVar3) {
                while( true ) {
                  iVar6 = iVar13 + 1;
                  pSVar9 = (SSL_CIPHER *)sk_value(p_Var8,iVar13);
                  pcVar10 = SSL_CIPHER_get_version(pSVar9);
                  pcVar11 = SSL_CIPHER_get_name(pSVar9);
                  BIO_printf(bp,"%-11s:%-25s",pcVar10,pcVar11);
                  if (iVar6 * -0x80000000 < 0) break;
                  if ((iVar3 == iVar6) || (BIO_puts(bp,"\n"), iVar13 = iVar6, iVar6 == iVar3))
                  goto LAB_00027090;
                }
              }
            }
LAB_00027090:
            BIO_puts(bp,"\n");
            pcVar10 = SSL_get_shared_ciphers(ssl,buf,0x4000);
            if (pcVar10 != (char *)0x0) {
              BIO_printf(bp,"---\nCiphers common between both SSL end points:\n");
              cVar16 = *pcVar10;
              if (cVar16 != '\0') {
                iVar3 = 0;
                iVar6 = 0;
                local_38 = "\n";
                do {
                  if (cVar16 == ':') {
                    iVar6 = iVar6 + 1;
                    BIO_write(bp,&DAT_0012e5c0,0x1a - iVar3);
                    iVar3 = 0;
                    pcVar11 = local_38;
                    if (iVar6 % 3 != 0) {
                      pcVar11 = " ";
                    }
                    BIO_write(bp,pcVar11,1);
                  }
                  else {
                    BIO_write(bp,pcVar10,1);
                    iVar3 = iVar3 + 1;
                  }
                  pcVar10 = pcVar10 + 1;
                  cVar16 = *pcVar10;
                } while (cVar16 != '\0');
              }
              BIO_puts(bp,"\n");
            }
            iVar3 = SSL_cache_hit(ssl);
            pcVar10 = "---\nNew, ";
            if (iVar3 != 0) {
              pcVar10 = "---\nReused, ";
            }
            BIO_printf(bp,pcVar10);
            pSVar9 = SSL_get_current_cipher(ssl);
            pcVar10 = SSL_CIPHER_get_version(pSVar9);
            pcVar11 = SSL_CIPHER_get_name(pSVar9);
            BIO_printf(bp,"%s, Cipher is %s\n",pcVar10,pcVar11);
            ses = SSL_get_session(ssl);
            SSL_SESSION_print(bp,ses);
            BIO_printf(bp,"---\n");
            pSVar12 = SSL_get_SSL_CTX(ssl);
            print_stats(bp,pSVar12);
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
            goto LAB_00027380;
          }
          goto joined_r0x00026e78;
        }
        if (www == 2) {
          iVar3 = strncmp("GET /stats ",buf,10);
          if (iVar3 == 0) goto LAB_00026f50;
          goto LAB_0002715e;
        }
        if (www != 3) goto joined_r0x00026e78;
LAB_0002715e:
        iVar3 = strncmp("GET /",buf,5);
      } while (iVar3 != 0);
      uVar7 = (uint)(byte)buf[5];
      filename = (byte *)(buf + 5);
      if (uVar7 == 0) {
LAB_000273b8:
        BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        BIO_printf(bp,"\'%s\' is an invalid file name\r\n",filename);
      }
      else if (uVar7 == 0x20) {
        buf[5] = '\0';
LAB_000273f0:
        iVar3 = app_isdir(filename);
        if (iVar3 < 1) {
          pBVar2 = BIO_new_file((char *)filename,"r");
          if (pBVar2 == (BIO *)0x0) {
            BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
            BIO_printf(bp,"Error opening \'%s\'\r\n",filename);
            ERR_print_errors(bp);
          }
          else {
            if (s_quiet == 0) {
              BIO_printf(bio_err,"FILE:%s\n",filename);
            }
            if (www == 2) {
              sVar5 = strlen((char *)filename);
              if ((int)sVar5 < 6) {
                if (sVar5 == 5) goto LAB_00027528;
LAB_00027552:
                BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
              }
              else {
                iVar3 = strcmp((char *)(filename + (sVar5 - 5)),".html");
                if (iVar3 != 0) {
LAB_00027528:
                  iVar3 = strcmp((char *)(filename + (sVar5 - 4)),".php");
                  if ((iVar3 != 0) &&
                     (iVar3 = strcmp((char *)(filename + (sVar5 - 4)),".htm"), iVar3 != 0))
                  goto LAB_00027552;
                }
                BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
              }
            }
            while (iVar3 = BIO_read(pBVar2,buf,0x4000), 0 < iVar3) {
              iVar6 = 0;
              do {
                iVar13 = BIO_write(bp,buf + iVar6,iVar3 - iVar6);
                if (iVar13 < 1) {
                  iVar13 = BIO_test_flags(bp,8);
                  if (iVar13 == 0) goto LAB_000274d6;
                  BIO_printf(bio_s_out,"rwrite W BLOCK\n");
                }
                else {
                  iVar6 = iVar6 + iVar13;
                }
              } while (iVar6 < iVar3);
            }
LAB_000274d6:
            BIO_free(pBVar2);
          }
        }
        else {
          BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          BIO_printf(bp,"\'%s\' is a directory\r\n",filename);
        }
      }
      else {
        uVar14 = 1;
        pbVar15 = filename;
        do {
          if (uVar14 == 2) {
            if (uVar7 != 0x2e) goto LAB_000271b6;
            uVar14 = 3;
          }
          else if (uVar14 == 3) {
            if (uVar7 != 0x2f) goto LAB_000271b6;
            uVar14 = 0xffffffff;
          }
          else if (uVar14 == 1) {
            if (uVar7 != 0x2e) goto LAB_000271b6;
            uVar14 = 2;
          }
          else if (uVar14 == 0) {
LAB_000271b6:
            uVar14 = count_leading_zeroes(uVar7 - 0x2f);
            uVar14 = uVar14 >> 5;
          }
          pbVar15 = pbVar15 + 1;
          uVar7 = (uint)*pbVar15;
          if (uVar7 == 0) goto LAB_000273b8;
        } while (uVar7 != 0x20);
        *pbVar15 = 0;
        if (uVar14 == 3 || uVar14 == 0xffffffff) {
          BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          BIO_printf(bp,"\'%s\' contains \'..\' reference\r\n",filename);
        }
        else {
          if (buf[5] != '/') goto LAB_000273f0;
          BIO_puts(bp,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          BIO_printf(bp,"\'%s\' is an invalid path\r\n",filename);
        }
      }
LAB_00027380:
      do {
        lVar4 = BIO_ctrl(bp,0xb,0,(void *)0x0);
        if (0 < lVar4) break;
        iVar3 = BIO_test_flags(bp,8);
      } while (iVar3 != 0);
LAB_00027394:
      SSL_set_shutdown(ssl,3);
LAB_000271e4:
      BIO_printf(bio_s_out,"ACCEPT\n");
      CRYPTO_free(buf);
      goto LAB_00026da4;
    }
  }
LAB_00026d8e:
  BIO_printf(bio_s_out,"ACCEPT\n");
  CRYPTO_free(buf);
  if (bp == (BIO *)0x0) {
    return 1;
  }
LAB_00026da4:
  BIO_free_all(bp);
  return 1;
}

