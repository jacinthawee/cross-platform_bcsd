
uint ssl23_get_client_hello(SSL *param_1)

{
  ushort uVar1;
  undefined *puVar2;
  undefined *puVar3;
  uchar *puVar4;
  char cVar9;
  ssl3_state_st *psVar5;
  SSL_METHOD *pSVar6;
  undefined4 uVar7;
  uint uVar8;
  byte bVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  undefined4 uVar15;
  undefined4 *unaff_s1;
  uint unaff_s3;
  uint uVar16;
  undefined4 *puVar17;
  char *pcVar18;
  undefined4 local_38;
  undefined4 local_34;
  byte local_30;
  byte local_2f;
  byte local_2e;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar17 = (undefined4 *)0x0;
  if (param_1->state != 0x2210) {
    uVar16 = 0;
    goto LAB_0048f308;
  }
  iVar11 = ssl3_setup_buffers();
  if (iVar11 == 0) goto LAB_0048f670;
  uVar16 = ssl23_read_bytes(param_1,0xb);
  unaff_s3 = uVar16;
  if (uVar16 != 0xb) goto LAB_0048f674;
  unaff_s1 = (undefined4 *)param_1->packet;
  local_34 = unaff_s1[1];
  local_38 = *unaff_s1;
  local_30 = *(byte *)(unaff_s1 + 2);
  local_2f = *(byte *)((int)unaff_s1 + 9);
  local_2e = *(byte *)((int)unaff_s1 + 10);
  if ((char)*(byte *)unaff_s1 < '\0') {
    if (*(byte *)((int)unaff_s1 + 2) == 1) {
      if (*(byte *)((int)unaff_s1 + 3) == 0) {
        if (*(byte *)(unaff_s1 + 1) == 2) {
          puVar17 = (undefined4 *)((*(byte *)&param_1->references ^ 1) & 1);
          goto LAB_0048f308;
        }
        puVar17 = (undefined4 *)0x0;
        goto LAB_0048f308;
      }
      puVar17 = (undefined4 *)0x0;
      if (*(byte *)((int)unaff_s1 + 3) != 3) goto LAB_0048f308;
      bVar10 = *(byte *)(unaff_s1 + 1);
      if (bVar10 == 0) goto LAB_0048f9fc;
      if (bVar10 < 3) {
        if (bVar10 != 2) {
          uVar8 = param_1->references;
          goto LAB_0048f9d4;
        }
        uVar8 = param_1->references;
      }
      else {
        uVar8 = param_1->references;
        if (-1 < (int)(uVar8 << 4)) {
          param_1->version = 0x303;
          param_1->state = 0x2211;
          goto LAB_0048f3c8;
        }
      }
      if (-1 < (int)(uVar8 << 3)) {
        param_1->version = 0x302;
        param_1->state = 0x2211;
        goto LAB_0048f3c8;
      }
LAB_0048f9d4:
      if ((int)(uVar8 << 5) < 0) goto LAB_0048fa04;
      param_1->version = 0x301;
      param_1->state = 0x2211;
      goto LAB_0048f3c8;
    }
  }
  else if (((*(byte *)unaff_s1 == 0x16) && (*(byte *)((int)unaff_s1 + 1) == 3)) &&
          (*(byte *)((int)unaff_s1 + 5) == 1)) {
    if (*(byte *)((int)unaff_s1 + 3) == 0) {
      if (4 < *(byte *)(unaff_s1 + 1)) {
        bVar10 = *(byte *)((int)unaff_s1 + 9);
        if (bVar10 < 3) goto LAB_0048f738;
        if (5 < *(byte *)(unaff_s1 + 1)) goto LAB_0048fa2c;
      }
      uVar15 = 0x12a;
      uVar7 = 0x15c;
      goto LAB_0048f65c;
    }
    bVar10 = *(byte *)((int)unaff_s1 + 9);
    if (bVar10 < 3) goto LAB_0048f738;
LAB_0048fa2c:
    if (bVar10 < 4) {
      bVar10 = *(byte *)((int)unaff_s1 + 10);
      if (bVar10 != 0) {
        if (2 < bVar10) goto LAB_0048fb30;
        if (bVar10 != 1) {
          iVar11 = param_1->references;
          goto LAB_0048fb54;
        }
        iVar11 = param_1->references;
        goto LAB_0048fb14;
      }
      if (-1 < param_1->references << 6) goto LAB_0048fb24;
      puVar17 = (undefined4 *)0x0;
      if (param_1->references << 5 < 0) goto LAB_0048f308;
    }
    else {
LAB_0048fb30:
      iVar11 = param_1->references;
      if (-1 < iVar11 << 4) {
        param_1->version = 0x303;
        goto LAB_0048fa64;
      }
LAB_0048fb54:
      if (-1 < iVar11 << 3) {
        param_1->version = 0x302;
        goto LAB_0048fa64;
      }
LAB_0048fb14:
      if (iVar11 << 5 < 0) {
        puVar17 = (undefined4 *)0x0;
        if (iVar11 << 6 < 0) goto LAB_0048f308;
LAB_0048fb24:
        param_1->version = 0x300;
        goto LAB_0048fa64;
      }
    }
    param_1->version = 0x301;
LAB_0048fa64:
    if (param_1->state == 0x2211) goto LAB_0048f3c8;
    puVar17 = (undefined4 *)0x3;
    goto LAB_0048f330;
  }
LAB_0048f738:
  iVar11 = (*(code *)PTR_strncmp_006a9970)(&DAT_0063b16c,unaff_s1,4);
  if (((iVar11 == 0) || (iVar11 = (*(code *)PTR_strncmp_006a9970)("POST ",unaff_s1,5), iVar11 == 0))
     || ((iVar11 = (*(code *)PTR_strncmp_006a9970)("HEAD ",unaff_s1,5), iVar11 == 0 ||
         (iVar11 = (*(code *)PTR_strncmp_006a9970)(&DAT_00647400,unaff_s1,4), iVar11 == 0)))) {
    uVar15 = 0x9c;
    uVar7 = 0x18a;
  }
  else {
    iVar11 = (*(code *)PTR_strncmp_006a9970)("CONNECT",unaff_s1,7);
    puVar17 = (undefined4 *)0x0;
    if (iVar11 != 0) goto LAB_0048f308;
    uVar15 = 0x9b;
    uVar7 = 0x18d;
  }
LAB_0048f65c:
  do {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x76,uVar15,"s23_srvr.c",uVar7);
    unaff_s3 = uVar16;
LAB_0048f670:
    uVar16 = 0xffffffff;
LAB_0048f674:
    do {
      if (local_2c == *(int *)puVar3) {
        return uVar16;
      }
      while( true ) {
        uVar16 = unaff_s3;
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0048f9fc:
        uVar8 = param_1->references;
LAB_0048fa04:
        if (-1 < (int)(uVar8 << 6)) break;
        puVar17 = (undefined4 *)((uVar8 >> 0x18 ^ 1) & 1);
LAB_0048f308:
        if (param_1->version < 0x304) {
          iVar11 = param_1->state;
        }
        else {
          (*(code *)PTR_OpenSSLDie_006a7c5c)("s23_srvr.c",0x193,"s->version <= TLS_MAX_VERSION");
          iVar11 = param_1->state;
        }
        if (iVar11 == 0x2211) {
          unaff_s1 = (undefined4 *)param_1->packet;
          goto LAB_0048f3c8;
        }
        if (puVar17 == (undefined4 *)0x1) {
          uVar15 = 0x102;
          uVar7 = 0x21d;
          goto LAB_0048f65c;
        }
LAB_0048f330:
        unaff_s1 = puVar17;
        if ((byte *)((int)unaff_s1 + -2) < &SUB_00000002) goto LAB_0048f5c4;
LAB_0048f340:
        unaff_s1 = (undefined4 *)(uint)((byte *)((int)unaff_s1 + -1) < (byte *)0x3);
        if (unaff_s1 == (undefined4 *)0x0) {
          uVar15 = 0xfc;
          uVar7 = 0x27b;
          goto LAB_0048f65c;
        }
        iVar11 = *(int *)puVar3;
        param_1->init_num = 0;
        unaff_s3 = uVar16;
        if (local_2c == iVar11) {
          uVar16 = SSL_accept(param_1);
          return uVar16;
        }
      }
      param_1->version = 0x300;
      param_1->state = 0x2211;
LAB_0048f3c8:
      unaff_s3 = (*(byte *)unaff_s1 & 0x7f) << 8 | (uint)*(byte *)((int)unaff_s1 + 1);
      bVar10 = *(byte *)(unaff_s1 + 1);
      uVar16 = unaff_s3;
      if (0x1000 < unaff_s3) {
        uVar15 = 0xd6;
        uVar7 = 0x1b7;
        goto LAB_0048f65c;
      }
      if (unaff_s3 < 9) {
        uVar15 = 0xd5;
        uVar7 = 0x1bc;
        goto LAB_0048f65c;
      }
      uVar16 = ssl23_read_bytes(param_1,unaff_s3 + 2);
    } while ((int)uVar16 < 1);
    ssl3_finish_mac(param_1,param_1->packet + 2,param_1->packet_length - 2);
    if (param_1->msg_callback != (_func_3150 *)0x0) {
      (*param_1->msg_callback)
                (0,2,0,param_1->packet + 2,param_1->packet_length - 2,param_1,
                 param_1->msg_callback_arg);
    }
    puVar2 = PTR_memset_006a99f4;
    puVar4 = param_1->packet;
    unaff_s1 = (undefined4 *)(puVar4 + 0xb);
    uVar1 = *(ushort *)(puVar4 + 7);
    uVar8 = (uint)*(ushort *)(puVar4 + 5);
    uVar16 = (uint)*(ushort *)(puVar4 + 9);
    pcVar18 = param_1->init_buf->data;
    if (uVar16 + 0xb + uVar1 + uVar8 == param_1->packet_length) {
      pcVar18[5] = bVar10;
      if (0x20 < uVar16) {
        uVar16 = 0x20;
      }
      *pcVar18 = '\x01';
      pcVar18[4] = '\x03';
      (*(code *)puVar2)(pcVar18 + 6,0,0x20);
      (*(code *)PTR_memcpy_006a9aec)
                (pcVar18 + 6 + (0x20 - uVar16),(byte *)((int)unaff_s1 + uVar1 + uVar8),uVar16);
      pbVar13 = (byte *)(pcVar18 + 0x29);
      uVar16 = 0;
      pcVar18[0x26] = '\0';
      if (uVar8 == 0) {
        cVar9 = '\0';
      }
      else {
        uVar12 = 0;
        pbVar14 = pbVar13;
        do {
          pbVar13 = pbVar14;
          if (*(byte *)unaff_s1 == 0) {
            pbVar13 = pbVar14 + 2;
            uVar16 = uVar16 + 2;
            *pbVar14 = *(byte *)((int)unaff_s1 + 1);
            pbVar14[1] = *(byte *)((int)unaff_s1 + 2);
          }
          uVar12 = uVar12 + 3;
          unaff_s1 = (undefined4 *)((int)unaff_s1 + 3);
          pbVar14 = pbVar13;
        } while (uVar12 < uVar8);
        cVar9 = (char)(uVar16 >> 8);
        uVar16 = uVar16 & 0xff;
      }
      pcVar18[0x27] = cVar9;
      pcVar18[0x28] = (char)uVar16;
      pbVar13[1] = 0;
      unaff_s1 = (undefined4 *)&SUB_00000002;
      *pbVar13 = 1;
      pbVar13 = pbVar13 + (-2 - (int)param_1->init_buf->data);
      pcVar18[3] = (char)pbVar13;
      pcVar18[2] = (char)((uint)pbVar13 >> 8);
      pcVar18[1] = (char)((uint)pbVar13 >> 0x10);
      psVar5 = param_1->s3;
      (psVar5->tmp).reuse_message = 1;
      (psVar5->tmp).message_type = 1;
      (psVar5->tmp).message_size = (ulong)pbVar13;
      uVar16 = unaff_s3;
LAB_0048f5c4:
      iVar11 = param_1->version;
      if (iVar11 == 0x300) {
        pSVar6 = SSLv3_server_method();
LAB_0048f5f8:
        if (pSVar6 != (SSL_METHOD *)0x0) {
          param_1->method = pSVar6;
          iVar11 = ssl_init_wbio_buffer(param_1,1);
          unaff_s3 = uVar16;
          if (iVar11 == 0) goto LAB_0048f670;
          param_1->state = 0x2110;
          if (unaff_s1 == (undefined4 *)0x3) {
            param_1->packet_length = uVar16;
            param_1->rstate = 0xf0;
            puVar4 = (param_1->s3->rbuf).buf;
            if (puVar4 == (uchar *)0x0) {
              iVar11 = ssl3_setup_read_buffer(param_1);
              if (iVar11 == 0) goto LAB_0048f670;
              puVar4 = (param_1->s3->rbuf).buf;
            }
            puVar2 = PTR_memcpy_006a9aec;
            param_1->packet = puVar4;
            (*(code *)puVar2)(puVar4,&local_38,uVar16);
            psVar5 = param_1->s3;
            (psVar5->rbuf).left = uVar16;
            (psVar5->rbuf).offset = 0;
          }
          else {
            psVar5 = param_1->s3;
            param_1->packet_length = 0;
            (psVar5->rbuf).left = 0;
            (psVar5->rbuf).offset = 0;
          }
          param_1->handshake_func = (_func_3149 *)param_1->method->ssl_accept;
          goto LAB_0048f340;
        }
      }
      else {
        if (iVar11 == 0x301) {
          pSVar6 = TLSv1_server_method();
          goto LAB_0048f5f8;
        }
        if (iVar11 == 0x302) {
          pSVar6 = TLSv1_1_server_method();
          goto LAB_0048f5f8;
        }
        if (iVar11 == 0x303) {
          pSVar6 = TLSv1_2_server_method();
          goto LAB_0048f5f8;
        }
      }
      uVar15 = 0x102;
      uVar7 = 0x255;
    }
    else {
      uVar15 = 0xd5;
      uVar7 = 0x1de;
      uVar16 = unaff_s3;
    }
  } while( true );
}

