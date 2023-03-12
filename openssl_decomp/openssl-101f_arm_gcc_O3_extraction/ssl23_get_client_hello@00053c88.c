
void ssl23_get_client_hello(SSL *param_1)

{
  SSL *pSVar1;
  SSL *pSVar2;
  uchar *puVar3;
  uchar *puVar4;
  uint uVar5;
  uchar *puVar6;
  ssl3_state_st *psVar7;
  ssl2_state_st *psVar8;
  uchar uVar9;
  byte bVar10;
  int iVar11;
  uint uVar12;
  BIO *pBVar13;
  SSL *unaff_r6;
  SSL *__n;
  uint uVar14;
  SSL **ppSVar15;
  char *pcVar16;
  uchar *puVar17;
  size_t __n_00;
  SSL *local_38;
  SSL *pSStack_34;
  undefined2 local_30;
  byte local_2e;
  int local_2c;
  
  iVar11 = param_1->state;
  if (iVar11 != 0x2210) {
    unaff_r6 = (SSL *)0x0;
  }
  local_2c = __TMC_END__;
  pSVar1 = param_1;
  pSVar2 = unaff_r6;
  if (iVar11 != 0x2210) {
LAB_00053cae:
    if (iVar11 == 0x2211) {
      ppSVar15 = (SSL **)param_1->packet;
LAB_00053d42:
      bVar10 = *(byte *)(ppSVar15 + 1);
      __n = (SSL *)((uint)*(byte *)((int)ppSVar15 + 1) | (*(byte *)ppSVar15 & 0x7f) << 8);
      if ((SSL *)0x1000 < __n) {
        ERR_put_error(0x14,0x76,0xd6,"s23_srvr.c",0x1c2);
        goto LAB_00053ef2;
      }
      pSVar2 = (SSL *)ssl23_read_bytes(param_1,(undefined *)((int)&__n->version + 2));
      if (0 < (int)pSVar2) {
        ssl3_finish_mac(param_1,param_1->packet + 2,param_1->packet_length - 2);
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (0,2,0,param_1->packet + 2,param_1->packet_length - 2,param_1,
                     param_1->msg_callback_arg);
        }
        puVar3 = param_1->packet;
        puVar17 = puVar3 + 0xb;
        uVar9 = puVar3[6];
        uVar14 = (uint)CONCAT11(puVar3[5],uVar9);
        pcVar16 = param_1->init_buf->data;
        uVar5 = (uint)CONCAT11(puVar3[9],puVar3[10]);
        iVar11 = CONCAT11(puVar3[7],puVar3[8]) + uVar14;
        if (uVar5 + 0xb + iVar11 == param_1->packet_length) {
          pcVar16[5] = bVar10;
          __n_00 = 0x20;
          if (uVar5 < 0x21) {
            __n_00 = uVar5;
          }
          *pcVar16 = '\x01';
          pcVar16[4] = '\x03';
          memset(pcVar16 + 6,0,0x20);
          memcpy(pcVar16 + 6 + (0x20 - __n_00),puVar17 + iVar11,__n_00);
          uVar5 = 0;
          puVar3 = (uchar *)(pcVar16 + 0x29);
          pcVar16[0x26] = '\0';
          if (uVar14 != 0) {
            uVar12 = 0;
            puVar4 = puVar17;
            puVar6 = puVar3;
            do {
              puVar3 = puVar6;
              if (puVar17[uVar12] == '\0') {
                uVar5 = uVar5 + 2;
                puVar3 = puVar6 + 2;
                *puVar6 = puVar4[1];
                puVar6[1] = puVar4[2];
              }
              uVar12 = uVar12 + 3;
              puVar4 = puVar4 + 3;
              puVar6 = puVar3;
            } while (uVar12 < uVar14);
            uVar9 = (uchar)(uVar5 >> 8);
            uVar14 = uVar5 & 0xff;
          }
          pcVar16[0x27] = uVar9;
          pcVar16[0x28] = (char)uVar14;
          *puVar3 = '\x01';
          puVar3[1] = '\0';
          unaff_r6 = (SSL *)0x2;
          puVar3 = puVar3 + (-2 - (int)param_1->init_buf->data);
          pcVar16[3] = (char)puVar3;
          pcVar16[2] = (char)((uint)puVar3 >> 8);
          pcVar16[1] = (char)((uint)puVar3 >> 0x10);
          psVar7 = param_1->s3;
          (psVar7->tmp).reuse_message = 1;
          (psVar7->tmp).message_type = 1;
          (psVar7->tmp).message_size = (ulong)puVar3;
          goto LAB_00053e8c;
        }
        ERR_put_error(0x14,0x76,0xd5,"s23_srvr.c",0x1d7);
        pSVar2 = (SSL *)0xffffffff;
      }
    }
    else {
LAB_00053cb8:
      __n = pSVar2;
      if ((undefined *)((int)&unaff_r6[-1].renegotiate + 2) < (undefined *)0x2) {
LAB_00053e8c:
        iVar11 = ssl_init_wbio_buffer(param_1,1);
        if (iVar11 == 0) goto LAB_00053ef2;
        param_1->state = 0x2110;
        if (unaff_r6 == (SSL *)0x3) {
          param_1->packet_length = (uint)__n;
          param_1->rstate = 0xf0;
          puVar3 = (param_1->s3->rbuf).buf;
          if (puVar3 == (uchar *)0x0) {
            iVar11 = ssl3_setup_read_buffer(param_1);
            if (iVar11 == 0) goto LAB_00053ef2;
            puVar3 = (param_1->s3->rbuf).buf;
          }
          param_1->packet = puVar3;
          memcpy(puVar3,&local_38,(size_t)__n);
          psVar7 = param_1->s3;
          (psVar7->rbuf).left = (int)__n;
          (psVar7->rbuf).offset = 0;
        }
        else {
          psVar7 = param_1->s3;
          param_1->packet_length = 0;
          (psVar7->rbuf).left = 0;
          (psVar7->rbuf).offset = 0;
        }
        iVar11 = param_1->version;
        if (iVar11 == 0x303) {
          pSVar1 = (SSL *)TLSv1_2_server_method();
          param_1->method = (SSL_METHOD *)pSVar1;
        }
        else if (iVar11 == 0x302) {
          pSVar1 = (SSL *)TLSv1_1_server_method();
          param_1->method = (SSL_METHOD *)pSVar1;
        }
        else if (iVar11 == 0x301) {
          pSVar1 = (SSL *)TLSv1_server_method();
          param_1->method = (SSL_METHOD *)pSVar1;
        }
        else {
          pSVar1 = (SSL *)SSLv3_server_method();
          param_1->method = (SSL_METHOD *)pSVar1;
        }
        param_1->handshake_func = (_func_3149 *)pSVar1->wbio;
      }
      if ((undefined *)((int)&unaff_r6[-1].renegotiate + 3) < (undefined *)0x3) goto LAB_00053cce;
      ERR_put_error(0x14,0x76,0xfc,"s23_srvr.c",0x274);
      pSVar2 = (SSL *)0xffffffff;
    }
  }
  else {
    iVar11 = ssl3_setup_buffers();
    if (iVar11 != 0) {
      pSVar2 = (SSL *)ssl23_read_bytes(param_1,0xb);
      if (pSVar2 != (SSL *)0xb) goto LAB_00053d02;
      ppSVar15 = (SSL **)param_1->packet;
      pSStack_34 = ppSVar15[1];
      local_38 = *ppSVar15;
      local_30 = *(undefined2 *)(ppSVar15 + 2);
      local_2e = *(byte *)((int)ppSVar15 + 10);
      pSVar1 = local_38;
      if (-1 < (int)((uint)*(byte *)ppSVar15 << 0x18)) {
        if (((*(byte *)ppSVar15 != 0x16) || (*(byte *)((int)ppSVar15 + 1) != 3)) ||
           (*(byte *)((int)ppSVar15 + 5) != 1)) goto LAB_00053f6c;
        if (*(byte *)((int)ppSVar15 + 3) == 0) {
          if (4 < *(byte *)(ppSVar15 + 1)) {
            bVar10 = *(byte *)((int)ppSVar15 + 9);
            if (bVar10 < 3) goto LAB_00053f6c;
            if (5 < *(byte *)(ppSVar15 + 1)) goto LAB_000540fc;
          }
          iVar11 = param_1->references;
LAB_00054180:
          pSVar1 = (SSL *)(iVar11 << 5);
          if ((int)pSVar1 < 0) {
            if (iVar11 << 6 < 0) goto LAB_00053fda;
LAB_0005418a:
            iVar11 = param_1->state;
            param_1->version = 0x300;
            unaff_r6 = (SSL *)0x3;
            goto LAB_00053cae;
          }
        }
        else {
          bVar10 = *(byte *)((int)ppSVar15 + 9);
          if (bVar10 < 3) goto LAB_00053f6c;
LAB_000540fc:
          if (3 < bVar10) {
LAB_000541c2:
            iVar11 = param_1->references;
            if (-1 < iVar11 << 4) {
              iVar11 = param_1->state;
              param_1->version = 0x303;
              unaff_r6 = (SSL *)0x3;
              goto LAB_00053cae;
            }
LAB_000541b2:
            if (-1 < iVar11 << 3) {
              iVar11 = param_1->state;
              param_1->version = 0x302;
              unaff_r6 = (SSL *)0x3;
              goto LAB_00053cae;
            }
            goto LAB_00054180;
          }
          bVar10 = *(byte *)((int)ppSVar15 + 10);
          if (bVar10 != 0) {
            if (2 < bVar10) goto LAB_000541c2;
            iVar11 = param_1->references;
            if (bVar10 == 1) goto LAB_00054180;
            goto LAB_000541b2;
          }
          if (-1 < param_1->references << 6) goto LAB_0005418a;
          if (param_1->references << 5 < 0) goto LAB_00053fda;
        }
        iVar11 = param_1->state;
        param_1->version = 0x301;
        unaff_r6 = (SSL *)0x3;
        goto LAB_00053cae;
      }
      if (*(byte *)((int)ppSVar15 + 2) != 1) {
LAB_00053f6c:
        iVar11 = strncmp("GET ",(char *)ppSVar15,4);
        if (((iVar11 == 0) || (iVar11 = strncmp("POST ",(char *)ppSVar15,5), iVar11 == 0)) ||
           ((iVar11 = strncmp("HEAD ",(char *)ppSVar15,5), iVar11 == 0 ||
            (iVar11 = strncmp("PUT ",(char *)ppSVar15,4), iVar11 == 0)))) {
          ERR_put_error(0x14,0x76,0x9c,"s23_srvr.c",0x1a2);
          pSVar2 = (SSL *)0xffffffff;
        }
        else {
          pSVar1 = (SSL *)strncmp("CONNECT",(char *)ppSVar15,7);
          if (pSVar1 != (SSL *)0x0) goto LAB_00053fda;
          ERR_put_error(0x14,0x76,0x9b,"s23_srvr.c",0x1a7);
          pSVar2 = (SSL *)0xffffffff;
        }
        goto LAB_00053d02;
      }
      if (*(byte *)((int)ppSVar15 + 3) != 0) {
        if (*(byte *)((int)ppSVar15 + 3) != 3) goto LAB_00053fda;
        bVar10 = *(byte *)(ppSVar15 + 1);
        if (bVar10 == 0) {
          uVar14 = param_1->references;
LAB_000541da:
          if ((int)(uVar14 << 6) < 0) {
            iVar11 = param_1->state;
            unaff_r6 = (SSL *)(((uVar14 ^ 0x1000000) << 7) >> 0x1f);
            goto LAB_00054020;
          }
          param_1->version = 0x300;
          param_1->state = 0x2211;
        }
        else {
          uVar14 = param_1->references;
          if (bVar10 < 3) {
            if (bVar10 == 2) {
LAB_000541ea:
              if (-1 < (int)(uVar14 << 3)) {
                param_1->version = 0x302;
                param_1->state = 0x2211;
                goto LAB_00053d42;
              }
            }
            pSVar1 = (SSL *)(uVar14 << 5);
            if ((int)(SSL *)(uVar14 << 5) < 0) goto LAB_000541da;
            param_1->version = 0x301;
            param_1->state = 0x2211;
          }
          else {
            if ((int)(uVar14 << 4) < 0) goto LAB_000541ea;
            param_1->version = 0x303;
            param_1->state = 0x2211;
          }
        }
        goto LAB_00053d42;
      }
      if (*(byte *)(ppSVar15 + 1) != 2) {
LAB_00053fda:
        iVar11 = param_1->state;
        unaff_r6 = (SSL *)0x0;
        goto LAB_00053cae;
      }
      iVar11 = param_1->state;
      unaff_r6 = (SSL *)((*(byte *)((int)&param_1->references + 3) ^ 1) & 1);
LAB_00054020:
      if (iVar11 == 0x2211) goto LAB_00053d42;
      if (unaff_r6 != (SSL *)0x1) goto LAB_00053cb8;
      if (param_1->s2 == (ssl2_state_st *)0x0) {
        iVar11 = ssl2_new(param_1);
        if (iVar11 == 0) goto LAB_00053ef2;
      }
      else {
        ssl2_clear();
      }
      if (param_1->s3 != (ssl3_state_st *)0x0) {
        ssl3_free(param_1);
      }
      iVar11 = BUF_MEM_grow_clean(param_1->init_buf,0x3fff);
      if (iVar11 == 0) goto LAB_00053ef2;
      param_1->state = 0x2010;
      psVar8 = param_1->s2;
      psVar8->ssl2_rollback = (uint)((param_1->references & 0x6000000U) != 0x6000000);
      ppSVar15 = (SSL **)psVar8->rbuf;
      param_1->rstate = 0xf0;
      param_1->packet = (uchar *)ppSVar15;
      param_1->packet_length = 0xb;
      *ppSVar15 = local_38;
      ppSVar15[1] = pSStack_34;
      *(undefined2 *)(ppSVar15 + 2) = local_30;
      *(byte *)((int)ppSVar15 + 10) = local_2e;
      psVar8 = param_1->s2;
      psVar8->rbuf_left = 0xb;
      psVar8->rbuf_offs = 0;
      pSVar1 = (SSL *)SSLv2_server_method();
      pBVar13 = pSVar1->wbio;
      param_1->method = (SSL_METHOD *)pSVar1;
      param_1->handshake_func = (_func_3149 *)pBVar13;
LAB_00053cce:
      iVar11 = __TMC_END__;
      param_1->init_num = 0;
      pSVar2 = pSVar1;
      if (local_2c == iVar11) {
        SSL_accept(param_1);
        return;
      }
      goto LAB_00054152;
    }
LAB_00053ef2:
    pSVar2 = (SSL *)0xffffffff;
  }
LAB_00053d02:
  if (local_2c == __TMC_END__) {
    return;
  }
LAB_00054152:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pSVar2);
}

