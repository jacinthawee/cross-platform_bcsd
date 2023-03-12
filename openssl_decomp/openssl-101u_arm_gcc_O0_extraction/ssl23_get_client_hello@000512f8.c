
size_t ssl23_get_client_hello(SSL *param_1)

{
  SSL_METHOD *pSVar1;
  uchar *puVar2;
  uchar *puVar3;
  uint uVar4;
  uchar *puVar5;
  ssl3_state_st *psVar6;
  uchar uVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *__s2;
  size_t sVar12;
  uint uVar13;
  char *pcVar14;
  uchar *puVar15;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined2 local_30;
  byte local_2e;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (param_1->state == 0x2210) {
    iVar9 = ssl3_setup_buffers();
    if (iVar9 != 0) {
      sVar12 = ssl23_read_bytes(param_1,0xb);
      if (sVar12 == 0xb) {
        __s2 = (undefined4 *)param_1->packet;
        uStack_34 = __s2[1];
        local_38 = *__s2;
        local_30 = *(undefined2 *)(__s2 + 2);
        local_2e = *(byte *)((int)__s2 + 10);
        if ((int)((uint)*(byte *)__s2 << 0x18) < 0) {
          if (*(byte *)((int)__s2 + 2) != 1) goto LAB_000515b6;
          uVar11 = (uint)*(byte *)((int)__s2 + 3);
          if (uVar11 == 0) {
            if (*(byte *)(__s2 + 1) == 2) {
              iVar9 = param_1->version;
              uVar11 = (*(byte *)((int)&param_1->references + 3) ^ 1) & 1;
              goto LAB_0005131e;
            }
LAB_000516d8:
            iVar9 = param_1->version;
            goto LAB_0005131e;
          }
          if (uVar11 != 3) goto LAB_00051624;
          bVar8 = *(byte *)(__s2 + 1);
          if (bVar8 == 0) {
            uVar13 = param_1->references;
LAB_000517c0:
            if ((int)(uVar13 << 6) < 0) {
              uVar11 = ((uVar13 ^ 0x1000000) << 7) >> 0x1f;
              iVar9 = param_1->version;
              goto LAB_0005131e;
            }
            iVar9 = 0x300;
          }
          else {
            uVar13 = param_1->references;
            if (bVar8 < 3) {
              if (bVar8 == 2) goto LAB_00051812;
LAB_00051774:
              uVar11 = uVar13 & 0x4000000;
              if (uVar11 == 0) {
                iVar9 = 0x301;
                param_1->version = 0x301;
                param_1->state = 0x2211;
                goto LAB_0005131e;
              }
              goto LAB_000517c0;
            }
            if ((int)(uVar13 << 4) < 0) {
LAB_00051812:
              uVar11 = uVar13 & 0x10000000;
              if (uVar11 == 0) {
                param_1->version = 0x302;
                param_1->state = 0x2211;
                iVar9 = 0x302;
                goto LAB_0005131e;
              }
              goto LAB_00051774;
            }
            iVar9 = 0x303;
          }
          param_1->version = iVar9;
          param_1->state = 0x2211;
          uVar11 = 0;
          goto LAB_0005131e;
        }
        if (((*(byte *)__s2 != 0x16) || (*(byte *)((int)__s2 + 1) != 3)) ||
           (*(byte *)((int)__s2 + 5) != 1)) {
LAB_000515b6:
          iVar9 = strncmp("GET ",(char *)__s2,4);
          if (((iVar9 == 0) || (iVar9 = strncmp("POST ",(char *)__s2,5), iVar9 == 0)) ||
             ((iVar9 = strncmp("HEAD ",(char *)__s2,5), iVar9 == 0 ||
              (iVar9 = strncmp("PUT ",(char *)__s2,4), iVar9 == 0)))) {
            ERR_put_error(0x14,0x76,0x9c,"s23_srvr.c",0x18a);
            sVar12 = 0xffffffff;
          }
          else {
            iVar9 = strncmp("CONNECT",(char *)__s2,7);
            if (iVar9 != 0) {
LAB_00051624:
              uVar11 = 0;
              iVar9 = param_1->version;
              goto LAB_0005131e;
            }
            ERR_put_error(0x14,0x76,0x9b,"s23_srvr.c",0x18d);
            sVar12 = 0xffffffff;
          }
          goto LAB_00051566;
        }
        if (*(byte *)((int)__s2 + 3) == 0) {
          if (4 < *(byte *)(__s2 + 1)) {
            bVar8 = *(byte *)((int)__s2 + 9);
            if (bVar8 < 3) goto LAB_000515b6;
            if (5 < *(byte *)(__s2 + 1)) goto LAB_000516fc;
          }
          ERR_put_error(0x14,0x76,0x12a,"s23_srvr.c",0x15c);
          sVar12 = 0xffffffff;
          goto LAB_00051566;
        }
        bVar8 = *(byte *)((int)__s2 + 9);
        if (bVar8 < 3) goto LAB_000515b6;
LAB_000516fc:
        if (bVar8 < 4) {
          uVar11 = (uint)*(byte *)((int)__s2 + 10);
          if (uVar11 == 0) {
            if (-1 < param_1->references << 6) {
LAB_00051850:
              param_1->version = 0x300;
              goto LAB_0005171e;
            }
            if (param_1->references << 5 < 0) goto LAB_000516d8;
          }
          else {
            if (2 < uVar11) goto LAB_00051828;
            iVar9 = param_1->references;
            if (uVar11 != 1) goto LAB_00051858;
LAB_00051844:
            if (iVar9 << 5 < 0) {
              if (iVar9 << 6 < 0) goto LAB_00051624;
              goto LAB_00051850;
            }
          }
          param_1->version = 0x301;
        }
        else {
LAB_00051828:
          iVar9 = param_1->references;
          if (iVar9 << 4 < 0) {
LAB_00051858:
            if (iVar9 << 3 < 0) goto LAB_00051844;
            param_1->version = 0x302;
          }
          else {
            param_1->version = 0x303;
          }
        }
LAB_0005171e:
        if (param_1->state != 0x2211) {
          uVar11 = 3;
          goto LAB_000514ea;
        }
        goto LAB_00051392;
      }
      goto LAB_00051566;
    }
    goto LAB_000516a6;
  }
  iVar9 = param_1->version;
  uVar11 = 0;
  sVar12 = 0;
LAB_0005131e:
  if (iVar9 < 0x304) {
    iVar9 = param_1->state;
  }
  else {
    OpenSSLDie("s23_srvr.c",0x193,"s->version <= TLS_MAX_VERSION");
    iVar9 = param_1->state;
  }
  if (iVar9 == 0x2211) {
    __s2 = (undefined4 *)param_1->packet;
LAB_00051392:
    bVar8 = *(byte *)(__s2 + 1);
    uVar13 = (uint)*(byte *)((int)__s2 + 1) | (*(byte *)__s2 & 0x7f) << 8;
    if (0x1000 < uVar13) {
      ERR_put_error(0x14,0x76,0xd6,"s23_srvr.c",0x1b7);
      goto LAB_000516a6;
    }
    if (uVar13 < 9) {
      iVar9 = 0x1bc;
    }
    else {
      sVar12 = ssl23_read_bytes(param_1,uVar13 + 2);
      if ((int)sVar12 < 1) goto LAB_00051566;
      ssl3_finish_mac(param_1,param_1->packet + 2,param_1->packet_length - 2);
      if (param_1->msg_callback != (_func_3150 *)0x0) {
        (*param_1->msg_callback)
                  (0,2,0,param_1->packet + 2,param_1->packet_length - 2,param_1,
                   param_1->msg_callback_arg);
      }
      puVar2 = param_1->packet;
      puVar15 = puVar2 + 0xb;
      uVar7 = puVar2[6];
      uVar11 = (uint)CONCAT11(puVar2[5],uVar7);
      pcVar14 = param_1->init_buf->data;
      uVar4 = (uint)CONCAT11(puVar2[9],puVar2[10]);
      iVar9 = CONCAT11(puVar2[7],puVar2[8]) + uVar11;
      if (uVar4 + 0xb + iVar9 == param_1->packet_length) {
        pcVar14[5] = bVar8;
        sVar12 = 0x20;
        if (uVar4 < 0x21) {
          sVar12 = uVar4;
        }
        *pcVar14 = '\x01';
        pcVar14[4] = '\x03';
        memset(pcVar14 + 6,0,0x20);
        memcpy(pcVar14 + 6 + (0x20 - sVar12),puVar15 + iVar9,sVar12);
        uVar4 = 0;
        puVar2 = (uchar *)(pcVar14 + 0x29);
        pcVar14[0x26] = '\0';
        if (uVar11 != 0) {
          uVar10 = 0;
          puVar3 = puVar15;
          puVar5 = puVar2;
          do {
            puVar2 = puVar5;
            if (puVar15[uVar10] == '\0') {
              uVar4 = uVar4 + 2;
              puVar2 = puVar5 + 2;
              *puVar5 = puVar3[1];
              puVar5[1] = puVar3[2];
            }
            uVar10 = uVar10 + 3;
            puVar3 = puVar3 + 3;
            puVar5 = puVar2;
          } while (uVar10 < uVar11);
          uVar7 = (uchar)(uVar4 >> 8);
          uVar11 = uVar4 & 0xff;
        }
        pcVar14[0x27] = uVar7;
        pcVar14[0x28] = (char)uVar11;
        *puVar2 = '\x01';
        puVar2[1] = '\0';
        uVar11 = 2;
        puVar2 = puVar2 + (-2 - (int)param_1->init_buf->data);
        pcVar14[3] = (char)puVar2;
        pcVar14[2] = (char)((uint)puVar2 >> 8);
        pcVar14[1] = (char)((uint)puVar2 >> 0x10);
        psVar6 = param_1->s3;
        (psVar6->tmp).reuse_message = 1;
        (psVar6->tmp).message_type = 1;
        (psVar6->tmp).message_size = (ulong)puVar2;
        sVar12 = uVar13;
        goto LAB_000514ea;
      }
      iVar9 = 0x1de;
    }
    ERR_put_error(0x14,0x76,0xd5,"s23_srvr.c",iVar9);
    sVar12 = 0xffffffff;
  }
  else {
    if (uVar11 == 1) {
      iVar9 = 0x21d;
    }
    else {
      if (1 < uVar11 - 2) {
LAB_00051348:
        iVar9 = __stack_chk_guard;
        if (uVar11 - 1 < 3) {
          param_1->init_num = 0;
          if (local_2c == iVar9) {
            sVar12 = SSL_accept(param_1);
            return sVar12;
          }
          goto LAB_0005178a;
        }
        ERR_put_error(0x14,0x76,0xfc,"s23_srvr.c",0x27b);
        sVar12 = 0xffffffff;
        goto LAB_00051566;
      }
LAB_000514ea:
      iVar9 = param_1->version;
      if (iVar9 == 0x300) {
        pSVar1 = SSLv3_server_method();
LAB_00051514:
        if (pSVar1 != (SSL_METHOD *)0x0) {
          param_1->method = pSVar1;
          iVar9 = ssl_init_wbio_buffer(param_1,1);
          if (iVar9 == 0) {
LAB_000516a6:
            sVar12 = 0xffffffff;
            goto LAB_00051566;
          }
          param_1->state = 0x2110;
          if (uVar11 == 3) {
            param_1->packet_length = sVar12;
            param_1->rstate = 0xf0;
            puVar2 = (param_1->s3->rbuf).buf;
            if (puVar2 == (uchar *)0x0) {
              iVar9 = ssl3_setup_read_buffer(param_1);
              if (iVar9 == 0) goto LAB_000516a6;
              puVar2 = (param_1->s3->rbuf).buf;
            }
            param_1->packet = puVar2;
            memcpy(puVar2,&local_38,sVar12);
            psVar6 = param_1->s3;
            (psVar6->rbuf).left = sVar12;
            (psVar6->rbuf).offset = 0;
          }
          else {
            psVar6 = param_1->s3;
            param_1->packet_length = 0;
            (psVar6->rbuf).left = 0;
            (psVar6->rbuf).offset = 0;
          }
          param_1->handshake_func = (_func_3149 *)param_1->method->ssl_accept;
          goto LAB_00051348;
        }
      }
      else {
        if (iVar9 == 0x301) {
          pSVar1 = TLSv1_server_method();
          goto LAB_00051514;
        }
        if (iVar9 == 0x302) {
          pSVar1 = TLSv1_1_server_method();
          goto LAB_00051514;
        }
        if (iVar9 == 0x303) {
          pSVar1 = TLSv1_2_server_method();
          goto LAB_00051514;
        }
      }
      iVar9 = 0x255;
    }
    ERR_put_error(0x14,0x76,0x102,"s23_srvr.c",iVar9);
    sVar12 = 0xffffffff;
  }
LAB_00051566:
  if (local_2c == __stack_chk_guard) {
    return sVar12;
  }
LAB_0005178a:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

