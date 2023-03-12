
int sv_body(undefined4 param_1,int param_2,uchar *param_3)

{
  byte bVar1;
  char cVar2;
  char *buf;
  SSL *ssl;
  size_t sid_ctx_len;
  int iVar3;
  BIO *pBVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  BIO *pBVar9;
  BIO_METHOD *type;
  long lVar10;
  timeval *__timeout;
  uint uVar11;
  __fd_mask *p_Var12;
  int in_GS_OFFSET;
  int local_c0;
  int local_b8;
  timeval local_a8;
  fd_set local_a0;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  buf = (char *)CRYPTO_malloc(0x4000,"s_server.c",0x7b3);
  if (buf != (char *)0x0) {
    if (s_nbio != 0) {
      local_a8.tv_sec = 1;
      if (s_quiet == 0) {
        BIO_printf(bio_err,"turning on non blocking io\n");
      }
      iVar3 = BIO_socket_ioctl(param_2,0x5421,&local_a8);
      if (iVar3 < 0) {
        ERR_print_errors(bio_err);
      }
    }
    ssl = SSL_new(ctx);
    if (s_tlsextdebug != 0) {
      SSL_callback_ctrl(ssl,0x38,tlsext_cb);
      SSL_ctrl(ssl,0x39,0,bio_s_out);
    }
    if (s_tlsextstatus != 0) {
      SSL_CTX_callback_ctrl(ctx,0x3f,cert_status_cb);
      tlscstatp._20_4_ = bio_err;
      SSL_CTX_ctrl(ctx,0x40,0,tlscstatp);
    }
    if (param_3 != (uchar *)0x0) {
      sid_ctx_len = strlen((char *)param_3);
      SSL_set_session_id_context(ssl,param_3,sid_ctx_len);
    }
    SSL_clear(ssl);
    iVar3 = SSL_version(ssl);
    if (iVar3 == 0xfeff) {
      pBVar4 = BIO_new_dgram(param_2,0);
      if (enable_timeouts != 0) {
        local_a8.tv_sec = 0;
        local_a8.tv_usec = 250000;
        BIO_ctrl(pBVar4,0x21,0,&local_a8);
        local_a8.tv_sec = 0;
        local_a8.tv_usec = 250000;
        BIO_ctrl(pBVar4,0x23,0,&local_a8);
      }
      if (socket_mtu < 0x1d) {
        BIO_ctrl(pBVar4,0x27,0,(void *)0x0);
      }
      else {
        SSL_ctrl(ssl,0x20,0x1000,(void *)0x0);
        SSL_ctrl(ssl,0x11,socket_mtu + -0x1c,(void *)0x0);
      }
      SSL_ctrl(ssl,0x20,0x2000,(void *)0x0);
    }
    else {
      pBVar4 = BIO_new_socket(param_2,0);
    }
    if (s_nbio_test != 0) {
      type = BIO_f_nbio_test();
      pBVar9 = BIO_new(type);
      pBVar4 = BIO_push(pBVar9,pBVar4);
    }
    SSL_set_bio(ssl,pBVar4,pBVar4);
    SSL_set_accept_state(ssl);
    if (s_debug != 0) {
      SSL_set_debug(ssl,1);
      pBVar4 = SSL_get_rbio(ssl);
      BIO_set_callback(pBVar4,bio_dump_callback);
      pBVar4 = bio_s_out;
      pBVar9 = SSL_get_rbio(ssl);
      BIO_set_callback_arg(pBVar9,(char *)pBVar4);
    }
    if (s_msg != 0) {
      SSL_set_msg_callback(ssl,msg_cb);
      SSL_ctrl(ssl,0x10,0,bio_s_out);
    }
    if (s_tlsextdebug != 0) {
      SSL_callback_ctrl(ssl,0x38,tlsext_cb);
      SSL_ctrl(ssl,0x39,0,bio_s_out);
    }
    bVar1 = (byte)(param_2 >> 0x1f);
    uVar5 = 1 << (((char)param_2 + (bVar1 >> 3) & 0x1f) - (bVar1 >> 3) & 0x1f);
switchD_080688d9_caseD_4:
    local_b8 = SSL_pending(ssl);
    if (local_b8 == 0) {
      iVar3 = 0x20;
      p_Var12 = local_a0.fds_bits;
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *p_Var12 = 0;
        p_Var12 = p_Var12 + 1;
      }
      iVar3 = fileno(stdin);
      iVar6 = fileno(stdin);
      iVar6 = __fdelt_chk(iVar6);
      bVar1 = (byte)(iVar3 >> 0x1f);
      local_a0.fds_bits[iVar6] =
           local_a0.fds_bits[iVar6] |
           1 << (((char)iVar3 + (bVar1 >> 3) & 0x1f) - (bVar1 >> 3) & 0x1f);
      iVar3 = __fdelt_chk(param_2);
      local_a0.fds_bits[iVar3] = local_a0.fds_bits[iVar3] | uVar5;
      iVar3 = SSL_version(ssl);
      if (iVar3 == 0xfeff) {
        lVar10 = SSL_ctrl(ssl,0x49,0,&local_a8);
        __timeout = &local_a8;
        if (lVar10 == 0) goto LAB_0806832a;
      }
      else {
LAB_0806832a:
        __timeout = (timeval *)0x0;
      }
      iVar3 = select(param_2 + 1,&local_a0,(fd_set *)0x0,(fd_set *)0x0,__timeout);
      iVar6 = SSL_version(ssl);
      if ((iVar6 == 0xfeff) && (lVar10 = SSL_ctrl(ssl,0x4a,0,(void *)0x0), 0 < lVar10)) {
        BIO_printf(bio_err,"TIMEOUT occured\n");
      }
      if (iVar3 < 1) goto switchD_080688d9_caseD_4;
      iVar3 = fileno(stdin);
      iVar3 = __fdelt_chk(iVar3);
      uVar11 = local_a0.fds_bits[iVar3];
      iVar3 = fileno(stdin);
      bVar1 = (byte)(iVar3 >> 0x1f);
      uVar11 = uVar11 & 1 << (((char)iVar3 + (bVar1 >> 3) & 0x1f) - (bVar1 >> 3) & 0x1f);
      iVar3 = __fdelt_chk(param_2);
      if ((local_a0.fds_bits[iVar3] & uVar5) == 0) {
        if (uVar11 == 0) goto switchD_080688d9_caseD_4;
      }
      else {
        if (uVar11 == 0) goto LAB_08068145;
        local_b8 = 1;
      }
      if (s_crlf == 0) {
        iVar3 = raw_read_stdin(buf,0x4000);
LAB_0806867b:
        if (s_quiet == 0) {
          if ((iVar3 < 1) || (cVar2 = *buf, cVar2 == 'Q')) goto LAB_08068a7e;
          if (cVar2 == 'q') {
            BIO_printf(bio_s_out,"DONE\n");
            iVar3 = SSL_version(ssl);
            if (iVar3 == 0xfeff) goto LAB_08068170;
            iVar3 = 1;
            shutdown(param_2,0);
            close(param_2);
            goto LAB_08068175;
          }
          if (cVar2 == 'B') {
            if ((buf[1] == '\n') || (buf[1] == '\r')) {
              BIO_printf(bio_err,"HEARTBEATING\n");
              SSL_ctrl(ssl,0x55,0,(void *)0x0);
              goto switchD_080688d9_caseD_4;
            }
          }
          else if (cVar2 == 'r') {
            if ((buf[1] == '\n') || (buf[1] == '\r')) {
LAB_08068946:
              SSL_renegotiate(ssl);
              iVar3 = SSL_do_handshake(ssl);
              __printf_chk(1,"SSL_do_handshake -> %d\n",iVar3);
              goto switchD_080688d9_caseD_4;
            }
          }
          else if (cVar2 == 'R') {
            if ((buf[1] == '\n') || (buf[1] == '\r')) {
              SSL_set_verify(ssl,5,(callback *)0x0);
              goto LAB_08068946;
            }
          }
          else {
            if (cVar2 == 'P') {
              pBVar4 = SSL_get_wbio(ssl);
              BIO_write(pBVar4,"Lets print some clear text\n",0x1b);
              cVar2 = *buf;
            }
            if (cVar2 == 'S') {
              SSL_get_SSL_CTX(ssl);
              print_stats();
            }
          }
        }
      }
      else {
        iVar3 = raw_read_stdin(buf,0x2000);
        if (0 < iVar3) {
          iVar6 = 0;
          pcVar7 = buf;
          do {
            cVar2 = *pcVar7;
            pcVar7 = pcVar7 + 1;
            iVar6 = iVar6 + (uint)(cVar2 == '\n');
          } while (buf + iVar3 != pcVar7);
          iVar8 = iVar3 + -1;
          pcVar7 = buf + iVar6;
          do {
            while (pcVar7[iVar8] = buf[iVar8], buf[iVar8] == '\n') {
              iVar6 = iVar6 + -1;
              iVar3 = iVar3 + 1;
              pcVar7 = buf + iVar6;
              pcVar7[iVar8] = '\r';
              iVar8 = iVar8 + -1;
              if (iVar8 == -1) goto LAB_0806844d;
            }
            iVar8 = iVar8 + -1;
          } while (iVar8 != -1);
LAB_0806844d:
          if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("lf_num == 0","s_server.c",0x880,"sv_body");
          }
          goto LAB_0806867b;
        }
        if (s_quiet == 0) {
LAB_08068a7e:
          BIO_printf(bio_s_out,"DONE\n");
          shutdown(param_2,0);
          close(param_2);
          iVar3 = -0xb;
          BIO_printf(bio_err,"shutdown accept socket\n");
          if (-1 < accept_socket) {
            shutdown(accept_socket,2);
            close(accept_socket);
          }
          goto LAB_08068175;
        }
      }
      local_c0 = 0;
      do {
        while( true ) {
          iVar6 = SSL_write(ssl,buf + local_c0,iVar3);
          iVar8 = SSL_get_error(ssl,iVar6);
          if (iVar8 != 4) break;
          BIO_printf(bio_s_out,"LOOKUP renego during write\n");
          srp_callback_parm._8_4_ =
               SRP_VBASE_get_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
          if (srp_callback_parm._8_4_ == 0) {
            BIO_printf(bio_s_out,"LOOKUP not successful\n");
          }
          else {
            BIO_printf(bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14))
            ;
          }
        }
        iVar8 = SSL_get_error(ssl,iVar6);
        switch(iVar8) {
        case 1:
        case 5:
          goto switchD_080688d9_caseD_1;
        case 2:
        case 3:
        case 4:
          BIO_printf(bio_s_out,"Write BLOCK\n");
          break;
        case 6:
          goto switchD_080688d9_caseD_6;
        }
        iVar3 = iVar3 - iVar6;
        local_c0 = local_c0 + iVar6;
      } while (0 < iVar3);
      if (local_b8 == 0) goto switchD_080688d9_caseD_4;
    }
LAB_08068145:
    iVar3 = SSL_state(ssl);
    if (iVar3 == 3) {
LAB_08068230:
      while( true ) {
        iVar3 = SSL_read(ssl,buf,0x4000);
        iVar6 = SSL_get_error(ssl,iVar3);
        if (iVar6 != 4) break;
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
      iVar6 = SSL_get_error(ssl,iVar3);
      switch(iVar6) {
      case 0:
        goto switchD_080688d9_caseD_0;
      case 1:
      case 5:
        goto switchD_080688d9_caseD_1;
      case 2:
      case 3:
        BIO_printf(bio_s_out,"Read BLOCK\n");
      default:
        goto switchD_080688d9_caseD_4;
      case 6:
        goto switchD_080688d9_caseD_6;
      }
    }
    iVar3 = init_ssl_connection();
    if (iVar3 < 0) {
      iVar3 = 0;
      goto LAB_08068175;
    }
    if (iVar3 == 0) goto LAB_08068170;
    goto switchD_080688d9_caseD_4;
  }
  iVar3 = 1;
  BIO_printf(bio_err,"out of memory\n");
  BIO_printf(bio_s_out,"CONNECTION CLOSED\n");
LAB_080681d0:
  BIO_printf(bio_s_out,"ACCEPT\n");
LAB_080681e6:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
switchD_080688d9_caseD_6:
  iVar3 = 1;
  BIO_printf(bio_s_out,"DONE\n");
  goto LAB_08068175;
switchD_080688d9_caseD_1:
  BIO_printf(bio_s_out,"ERROR\n");
  ERR_print_errors(bio_err);
LAB_08068170:
  iVar3 = 1;
LAB_08068175:
  if (ssl != (SSL *)0x0) {
    BIO_printf(bio_s_out,"shutting down SSL\n");
    SSL_set_shutdown(ssl,3);
    SSL_free(ssl);
  }
  BIO_printf(bio_s_out,"CONNECTION CLOSED\n");
  OPENSSL_cleanse(buf,0x4000);
  CRYPTO_free(buf);
  if (iVar3 < 0) goto LAB_080681e6;
  goto LAB_080681d0;
switchD_080688d9_caseD_0:
  raw_write_stdout(buf,iVar3);
  iVar3 = SSL_pending(ssl);
  if (iVar3 == 0) goto switchD_080688d9_caseD_4;
  goto LAB_08068230;
}

