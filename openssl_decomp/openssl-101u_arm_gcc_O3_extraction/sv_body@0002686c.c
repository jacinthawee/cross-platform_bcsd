
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int sv_body(undefined4 param_1,int param_2,uchar *param_3)

{
  char *buf;
  int iVar1;
  SSL *ssl;
  size_t sid_ctx_len;
  BIO *pBVar2;
  timeval *__timeout;
  int iVar3;
  int iVar4;
  int iVar5;
  BIO_METHOD *type;
  BIO *pBVar6;
  SSL_CTX *pSVar7;
  long lVar8;
  char cVar9;
  uint uVar10;
  char *pcVar11;
  uint uVar12;
  BIO **ppBVar13;
  BIO **ppBVar14;
  uint uVar15;
  char *pcVar16;
  bool bVar17;
  timeval local_b0;
  fd_set local_a8;
  
  buf = (char *)CRYPTO_malloc(0x4000,"s_server.c",0x7b6);
  if (buf == (char *)0x0) {
    BIO_printf(bio_err,"out of memory\n");
    iVar1 = 1;
    BIO_printf(bio_s_out,"CONNECTION CLOSED\n");
    goto LAB_000269f2;
  }
  if (s_nbio != 0) {
    local_a8.fds_bits[0] = 1;
    if (s_quiet == 0) {
      BIO_printf(bio_err,"turning on non blocking io\n");
    }
    iVar1 = BIO_socket_ioctl(param_2,0x5421,&local_a8);
    if (iVar1 < 0) {
      ERR_print_errors(bio_err);
    }
  }
  ssl = SSL_new(ctx);
  if (s_tlsextdebug != 0) {
    SSL_callback_ctrl(ssl,0x38,tlsext_cb + 1);
    SSL_ctrl(ssl,0x39,0,bio_s_out);
  }
  if (s_tlsextstatus != 0) {
    SSL_CTX_callback_ctrl(ctx,0x3f,cert_status_cb + 1);
    tlscstatp._20_4_ = bio_err;
    SSL_CTX_ctrl(ctx,0x40,0,tlscstatp);
  }
  if (param_3 != (uchar *)0x0) {
    sid_ctx_len = strlen((char *)param_3);
    SSL_set_session_id_context(ssl,param_3,sid_ctx_len);
  }
  SSL_clear(ssl);
  iVar1 = SSL_version(ssl);
  if (iVar1 != 0xfeff) {
    pBVar2 = BIO_new_socket(param_2,0);
    goto LAB_00026916;
  }
  pBVar2 = BIO_new_dgram(param_2,0);
  if (enable_timeouts != 0) {
    local_b0.tv_sec = 0;
    local_b0.tv_usec = 250000;
    BIO_ctrl(pBVar2,0x21,0,&local_b0);
    local_b0.tv_usec = 250000;
    local_b0.tv_sec = 0;
    BIO_ctrl(pBVar2,0x23,0,&local_b0);
  }
  if (socket_mtu != 0) {
    lVar8 = SSL_ctrl(ssl,0x79,0,(void *)0x0);
    pBVar6 = bio_err;
    if (socket_mtu < lVar8) {
      iVar1 = -1;
      lVar8 = SSL_ctrl(ssl,0x79,0,(void *)0x0);
      BIO_printf(pBVar6,"MTU too small. Must be at least %ld\n",lVar8);
      BIO_free(pBVar2);
    }
    else {
      SSL_ctrl(ssl,0x20,0x1000,(void *)0x0);
      lVar8 = SSL_ctrl(ssl,0x78,socket_mtu,(void *)0x0);
      if (lVar8 != 0) goto LAB_00026e58;
      iVar1 = -1;
      BIO_printf(bio_err,"Failed to set MTU\n");
      BIO_free(pBVar2);
    }
LAB_000269b2:
    if (ssl != (SSL *)0x0) {
      BIO_printf(bio_s_out,"shutting down SSL\n");
      SSL_set_shutdown(ssl,3);
      SSL_free(ssl);
    }
    BIO_printf(bio_s_out,"CONNECTION CLOSED\n");
    OPENSSL_cleanse(buf,0x4000);
    CRYPTO_free(buf);
    if (iVar1 < 0) {
      return iVar1;
    }
LAB_000269f2:
    BIO_printf(bio_s_out,"ACCEPT\n");
    return iVar1;
  }
  BIO_ctrl(pBVar2,0x27,0,(void *)0x0);
LAB_00026e58:
  SSL_ctrl(ssl,0x20,0x2000,(void *)0x0);
LAB_00026916:
  if (s_nbio_test != 0) {
    type = BIO_f_nbio_test();
    pBVar6 = BIO_new(type);
    pBVar2 = BIO_push(pBVar6,pBVar2);
  }
  SSL_set_bio(ssl,pBVar2,pBVar2);
  SSL_set_accept_state(ssl);
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
  if (s_tlsextdebug != 0) {
    SSL_callback_ctrl(ssl,0x38,tlsext_cb + 1);
    SSL_ctrl(ssl,0x39,0,bio_s_out);
  }
  uVar10 = 1 << (param_2 % 0x20 & 0xffU);
  ppBVar13 = &bio_s_out;
switchD_00026eea_caseD_4:
  do {
    __timeout = (timeval *)SSL_pending(ssl);
    if (__timeout != (timeval *)0x0) goto LAB_00026998;
    memset(&local_a8,0,0x80);
    fileno(stdin);
    iVar1 = __fdelt_chk();
    uVar15 = local_a8.fds_bits[iVar1];
    iVar3 = fileno(stdin);
    local_a8.fds_bits[iVar1] = 1 << (iVar3 % 0x20 & 0xffU) | uVar15;
    iVar1 = __fdelt_chk(param_2);
    local_a8.fds_bits[iVar1] = local_a8.fds_bits[iVar1] | uVar10;
    iVar1 = SSL_version(ssl);
    if (iVar1 == 0xfeff) {
      __timeout = &local_b0;
      lVar8 = SSL_ctrl(ssl,0x49,0,__timeout);
      if (lVar8 == 0) {
        __timeout = (timeval *)0x0;
      }
    }
    pBVar2 = (BIO *)0x0;
    iVar1 = select(param_2 + 1,&local_a8,(fd_set *)0x0,(fd_set *)0x0,__timeout);
    iVar3 = SSL_version(ssl);
    ppBVar14 = ppBVar13;
    if (iVar3 == 0xfeff) {
      if (iVar3 + -0xfeff < 0) {
        ppBVar14 = ppBVar13 + -0x3fbfc;
        *ppBVar13 = pBVar2;
      }
      lVar8 = SSL_ctrl((SSL *)0xfeff,0x4a,(long)pBVar2,pBVar2);
      if (0 < lVar8) {
        BIO_printf(bio_err,"TIMEOUT occured\n");
      }
    }
    ppBVar13 = ppBVar14;
  } while (iVar1 < 1);
  fileno(stdin);
  iVar1 = __fdelt_chk();
  uVar12 = local_a8.fds_bits[iVar1];
  iVar1 = fileno(stdin);
  iVar3 = __fdelt_chk(param_2);
  uVar15 = local_a8.fds_bits[iVar3];
  if ((uVar12 & 1 << (iVar1 % 0x20 & 0xffU)) == 0) {
LAB_00026d3a:
    if ((uVar15 & uVar10) != 0) goto LAB_00026998;
    goto switchD_00026eea_caseD_4;
  }
  if (s_crlf == 0) {
    iVar1 = raw_read_stdin(buf,0x4000);
  }
  else {
    iVar1 = raw_read_stdin(buf,0x2000);
    if (iVar1 < 1) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      pcVar16 = buf;
      do {
        pcVar11 = pcVar16 + 1;
        if (*pcVar16 == '\n') {
          iVar3 = iVar3 + 1;
        }
        pcVar16 = pcVar11;
      } while (pcVar11 != buf + iVar1);
    }
    iVar4 = iVar1 + -1;
    if (-1 < iVar4) {
      pcVar16 = buf + iVar3;
      pcVar11 = buf + iVar1;
      do {
        pcVar16[iVar4] = pcVar11[-1];
        if (pcVar11[-1] == '\n') {
          iVar3 = iVar3 + -1;
          iVar1 = iVar1 + 1;
          pcVar16 = buf + iVar3;
          pcVar16[iVar4] = '\r';
        }
        bVar17 = iVar4 != 0;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar11 + -1;
      } while (bVar17);
    }
    if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("lf_num == 0","s_server.c",0x87e,"sv_body");
    }
  }
  if (s_quiet == 0) {
    if ((iVar1 < 1) || (cVar9 = *buf, cVar9 == 'Q')) {
      BIO_printf(bio_s_out,"DONE\n");
      shutdown(param_2,0);
      close(param_2);
      BIO_printf(bio_err,"shutdown accept socket\n");
      if (accept_socket < 0) {
        iVar1 = -0xb;
      }
      else {
        shutdown(accept_socket,2);
        close(accept_socket);
        iVar1 = -0xb;
      }
      goto LAB_000269b2;
    }
    if (cVar9 == 'q') {
      BIO_printf(bio_s_out,"DONE\n");
      iVar1 = SSL_version(ssl);
      if (iVar1 != 0xfeff) {
        shutdown(param_2,0);
        close(param_2);
      }
      goto LAB_000269b0;
    }
    if (cVar9 == 'B') {
      if (buf[1] == '\n' || buf[1] == '\r') {
        BIO_printf(bio_err,"HEARTBEATING\n");
        SSL_ctrl(ssl,0x55,0,(void *)0x0);
        goto switchD_00026eea_caseD_4;
      }
    }
    else {
      if (cVar9 != 'r') {
        if (cVar9 == 'R') {
          if (buf[1] == '\n' || buf[1] == '\r') {
            SSL_set_verify(ssl,5,(callback *)0x0);
            goto LAB_00026fa6;
          }
        }
        else {
          if (cVar9 == 'P') {
            pBVar2 = SSL_get_wbio(ssl);
            BIO_write(pBVar2,"Lets print some clear text\n",0x1b);
            cVar9 = *buf;
          }
          pBVar2 = bio_s_out;
          if (cVar9 == 'S') {
            pSVar7 = SSL_get_SSL_CTX(ssl);
            print_stats(pBVar2,pSVar7);
          }
        }
        goto LAB_00026ba0;
      }
      if (buf[1] == '\n' || buf[1] == '\r') {
LAB_00026fa6:
        SSL_renegotiate(ssl);
        iVar1 = SSL_do_handshake(ssl);
        __printf_chk(1,"SSL_do_handshake -> %d\n",iVar1);
        goto switchD_00026eea_caseD_4;
      }
    }
  }
LAB_00026ba0:
  iVar3 = 0;
  do {
    iVar4 = SSL_write(ssl,buf + iVar3,iVar1);
    while (iVar5 = SSL_get_error(ssl,iVar4), iVar5 == 4) {
      BIO_printf(bio_s_out,"LOOKUP renego during write\n");
      SRP_user_pwd_free(srp_callback_parm._8_4_);
      srp_callback_parm._8_4_ =
           SRP_VBASE_get1_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
      if (srp_callback_parm._8_4_ == 0) {
        BIO_printf(*ppBVar14,"LOOKUP not successful\n");
      }
      else {
        BIO_printf(*ppBVar14,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
      }
      iVar4 = SSL_write(ssl,buf + iVar3,iVar1);
    }
    iVar5 = SSL_get_error(ssl,iVar4);
    switch(iVar5) {
    case 1:
    case 5:
      goto switchD_00026cde_caseD_1;
    case 2:
    case 3:
    case 4:
      BIO_printf(bio_s_out,"Write BLOCK\n");
      break;
    case 6:
      goto switchD_00026cde_caseD_6;
    }
    if (0 < iVar4) {
      iVar1 = iVar1 - iVar4;
      iVar3 = iVar3 + iVar4;
    }
  } while (0 < iVar1);
  goto LAB_00026d3a;
LAB_00026998:
  iVar1 = SSL_state(ssl);
  if (iVar1 == 3) {
LAB_00026a18:
    while( true ) {
      iVar1 = SSL_read(ssl,buf,0x4000);
      iVar3 = SSL_get_error(ssl,iVar1);
      if (iVar3 != 4) break;
      BIO_printf(bio_s_out,"LOOKUP renego during read\n");
      SRP_user_pwd_free(srp_callback_parm._8_4_);
      srp_callback_parm._8_4_ =
           SRP_VBASE_get1_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
      if (srp_callback_parm._8_4_ == 0) {
        BIO_printf(*ppBVar13,"LOOKUP not successful\n");
      }
      else {
        BIO_printf(*ppBVar13,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
      }
    }
    iVar3 = SSL_get_error(ssl,iVar1);
    switch(iVar3) {
    case 0:
      goto switchD_00026eea_caseD_0;
    case 1:
    case 5:
      goto switchD_00026cde_caseD_1;
    case 2:
    case 3:
      BIO_printf(bio_s_out,"Read BLOCK\n");
    default:
      goto switchD_00026eea_caseD_4;
    case 6:
      goto switchD_00026cde_caseD_6;
    }
  }
  iVar1 = init_ssl_connection(ssl);
  if (iVar1 < 0) {
    iVar1 = 0;
    goto LAB_000269b2;
  }
  if (iVar1 == 0) {
LAB_000269b0:
    iVar1 = 1;
    goto LAB_000269b2;
  }
  goto switchD_00026eea_caseD_4;
switchD_00026cde_caseD_6:
  iVar1 = 1;
  BIO_printf(bio_s_out,"DONE\n");
  goto LAB_000269b2;
switchD_00026eea_caseD_0:
  raw_write_stdout(buf,iVar1);
  iVar1 = SSL_pending(ssl);
  if (iVar1 == 0) goto switchD_00026eea_caseD_4;
  goto LAB_00026a18;
switchD_00026cde_caseD_1:
  iVar1 = 1;
  BIO_printf(bio_s_out,"ERROR\n");
  ERR_print_errors(bio_err);
  goto LAB_000269b2;
}

