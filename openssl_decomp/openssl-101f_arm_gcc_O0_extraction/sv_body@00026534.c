
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
  BIO *b;
  SSL_CTX *pSVar6;
  long lVar7;
  char cVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  bool bVar14;
  timeval local_b0;
  fd_set local_a8;
  
  buf = (char *)CRYPTO_malloc(0x4000,"s_server.c",0x7b3);
  if (buf != (char *)0x0) {
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
    if (iVar1 == 0xfeff) {
      pBVar2 = BIO_new_dgram(param_2,0);
      if (enable_timeouts != 0) {
        local_b0.tv_sec = 0;
        local_b0.tv_usec = 250000;
        BIO_ctrl(pBVar2,0x21,0,&local_b0);
        local_b0.tv_usec = 250000;
        local_b0.tv_sec = 0;
        BIO_ctrl(pBVar2,0x23,0,&local_b0);
      }
      if (socket_mtu < 0x1d) {
        BIO_ctrl(pBVar2,0x27,0,(void *)0x0);
      }
      else {
        SSL_ctrl(ssl,0x20,0x1000,(void *)0x0);
        SSL_ctrl(ssl,0x11,socket_mtu + -0x1c,(void *)0x0);
      }
      SSL_ctrl(ssl,0x20,0x2000,(void *)0x0);
    }
    else {
      pBVar2 = BIO_new_socket(param_2,0);
    }
    if (s_nbio_test != 0) {
      type = BIO_f_nbio_test();
      b = BIO_new(type);
      pBVar2 = BIO_push(b,pBVar2);
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
    uVar9 = 1 << (param_2 % 0x20 & 0xffU);
switchD_00026b70_caseD_4:
    do {
      __timeout = (timeval *)SSL_pending(ssl);
      if (__timeout != (timeval *)0x0) goto LAB_00026664;
      memset(&local_a8,0,0x80);
      fileno(stdin);
      iVar1 = __fdelt_chk();
      uVar12 = local_a8.fds_bits[iVar1];
      iVar3 = fileno(stdin);
      local_a8.fds_bits[iVar1] = 1 << (iVar3 % 0x20 & 0xffU) | uVar12;
      iVar1 = __fdelt_chk(param_2);
      local_a8.fds_bits[iVar1] = local_a8.fds_bits[iVar1] | uVar9;
      iVar1 = SSL_version(ssl);
      if (iVar1 == 0xfeff) {
        __timeout = &local_b0;
        lVar7 = SSL_ctrl(ssl,0x49,0,__timeout);
        if (lVar7 == 0) {
          __timeout = (timeval *)0x0;
        }
      }
      iVar1 = select(param_2 + 1,&local_a8,(fd_set *)0x0,(fd_set *)0x0,__timeout);
      iVar3 = SSL_version(ssl);
      if ((iVar3 == 0xfeff) && (lVar7 = SSL_ctrl(ssl,0x4a,0,(void *)0x0), 0 < lVar7)) {
        BIO_printf(bio_err,"TIMEOUT occured\n");
      }
    } while (iVar1 < 1);
    fileno(stdin);
    iVar1 = __fdelt_chk();
    uVar11 = local_a8.fds_bits[iVar1];
    iVar1 = fileno(stdin);
    iVar3 = __fdelt_chk(param_2);
    uVar12 = local_a8.fds_bits[iVar3];
    if ((uVar11 & 1 << (iVar1 % 0x20 & 0xffU)) == 0) {
LAB_000269f0:
      if ((uVar12 & uVar9) != 0) goto LAB_00026664;
      goto switchD_00026b70_caseD_4;
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
        pcVar13 = buf;
        do {
          pcVar10 = pcVar13 + 1;
          if (*pcVar13 == '\n') {
            iVar3 = iVar3 + 1;
          }
          pcVar13 = pcVar10;
        } while (pcVar10 != buf + iVar1);
      }
      iVar4 = iVar1 + -1;
      if (-1 < iVar4) {
        pcVar13 = buf + iVar3;
        pcVar10 = buf + iVar1;
        do {
          pcVar13[iVar4] = pcVar10[-1];
          if (pcVar10[-1] == '\n') {
            iVar3 = iVar3 + -1;
            iVar1 = iVar1 + 1;
            pcVar13 = buf + iVar3;
            pcVar13[iVar4] = '\r';
          }
          bVar14 = iVar4 != 0;
          iVar4 = iVar4 + -1;
          pcVar10 = pcVar10 + -1;
        } while (bVar14);
      }
      if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("lf_num == 0","s_server.c",0x880,"sv_body");
      }
    }
    if (s_quiet == 0) {
      if ((iVar1 < 1) || (cVar8 = *buf, cVar8 == 'Q')) {
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
        goto LAB_0002667e;
      }
      if (cVar8 == 'q') {
        BIO_printf(bio_s_out,"DONE\n");
        iVar1 = SSL_version(ssl);
        if (iVar1 != 0xfeff) {
          shutdown(param_2,0);
          close(param_2);
        }
        goto LAB_0002667c;
      }
      if (cVar8 == 'B') {
        if (buf[1] == '\n' || buf[1] == '\r') {
          BIO_printf(bio_err,"HEARTBEATING\n");
          SSL_ctrl(ssl,0x55,0,(void *)0x0);
          goto switchD_00026b70_caseD_4;
        }
      }
      else {
        if (cVar8 != 'r') {
          if (cVar8 == 'R') {
            if (buf[1] == '\n' || buf[1] == '\r') {
              SSL_set_verify(ssl,5,(callback *)0x0);
              goto LAB_00026c2a;
            }
          }
          else {
            if (cVar8 == 'P') {
              pBVar2 = SSL_get_wbio(ssl);
              BIO_write(pBVar2,"Lets print some clear text\n",0x1b);
              cVar8 = *buf;
            }
            pBVar2 = bio_s_out;
            if (cVar8 == 'S') {
              pSVar6 = SSL_get_SSL_CTX(ssl);
              print_stats(pBVar2,pSVar6);
            }
          }
          goto LAB_00026866;
        }
        if (buf[1] == '\n' || buf[1] == '\r') {
LAB_00026c2a:
          SSL_renegotiate(ssl);
          iVar1 = SSL_do_handshake(ssl);
          __printf_chk(1,"SSL_do_handshake -> %d\n",iVar1);
          goto switchD_00026b70_caseD_4;
        }
      }
    }
LAB_00026866:
    iVar3 = 0;
    do {
      iVar4 = SSL_write(ssl,buf + iVar3,iVar1);
      while (iVar5 = SSL_get_error(ssl,iVar4), iVar5 == 4) {
        BIO_printf(bio_s_out,"LOOKUP renego during write\n");
        srp_callback_parm._8_4_ =
             SRP_VBASE_get_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
        if (srp_callback_parm._8_4_ == 0) {
          BIO_printf(bio_s_out,"LOOKUP not successful\n");
        }
        else {
          BIO_printf(bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
        }
        iVar4 = SSL_write(ssl,buf + iVar3,iVar1);
      }
      iVar5 = SSL_get_error(ssl,iVar4);
      switch(iVar5) {
      case 1:
      case 5:
        goto switchD_0002699a_caseD_1;
      case 2:
      case 3:
      case 4:
        BIO_printf(bio_s_out,"Write BLOCK\n");
        break;
      case 6:
        goto switchD_0002699a_caseD_6;
      }
      iVar1 = iVar1 - iVar4;
      iVar3 = iVar3 + iVar4;
    } while (0 < iVar1);
    goto LAB_000269f0;
  }
  BIO_printf(bio_err,"out of memory\n");
  iVar1 = 1;
  BIO_printf(bio_s_out,"CONNECTION CLOSED\n");
LAB_000266be:
  BIO_printf(bio_s_out,"ACCEPT\n");
  return iVar1;
LAB_00026664:
  iVar1 = SSL_state(ssl);
  if (iVar1 == 3) {
LAB_000266e4:
    while( true ) {
      iVar1 = SSL_read(ssl,buf,0x4000);
      iVar3 = SSL_get_error(ssl,iVar1);
      if (iVar3 != 4) break;
      BIO_printf(bio_s_out,"LOOKUP renego during read\n");
      srp_callback_parm._8_4_ =
           SRP_VBASE_get_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
      if (srp_callback_parm._8_4_ == 0) {
        BIO_printf(bio_s_out,"LOOKUP not successful\n");
      }
      else {
        BIO_printf(bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
      }
    }
    iVar3 = SSL_get_error(ssl,iVar1);
    switch(iVar3) {
    case 0:
      goto switchD_00026b70_caseD_0;
    case 1:
    case 5:
      goto switchD_0002699a_caseD_1;
    case 2:
    case 3:
      BIO_printf(bio_s_out,"Read BLOCK\n");
    default:
      goto switchD_00026b70_caseD_4;
    case 6:
      goto switchD_0002699a_caseD_6;
    }
  }
  iVar1 = init_ssl_connection(ssl);
  if (iVar1 < 0) {
    iVar1 = 0;
    goto LAB_0002667e;
  }
  if (iVar1 == 0) {
LAB_0002667c:
    iVar1 = 1;
    goto LAB_0002667e;
  }
  goto switchD_00026b70_caseD_4;
switchD_0002699a_caseD_6:
  iVar1 = 1;
  BIO_printf(bio_s_out,"DONE\n");
  goto LAB_0002667e;
switchD_00026b70_caseD_0:
  raw_write_stdout(buf,iVar1);
  iVar1 = SSL_pending(ssl);
  if (iVar1 == 0) goto switchD_00026b70_caseD_4;
  goto LAB_000266e4;
switchD_0002699a_caseD_1:
  iVar1 = 1;
  BIO_printf(bio_s_out,"ERROR\n");
  ERR_print_errors(bio_err);
LAB_0002667e:
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
  goto LAB_000266be;
}

