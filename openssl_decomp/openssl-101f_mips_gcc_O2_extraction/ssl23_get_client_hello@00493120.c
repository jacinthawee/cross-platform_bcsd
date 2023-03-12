
uint ssl23_get_client_hello(SSL *param_1)

{
  ushort uVar1;
  undefined *puVar2;
  undefined *puVar3;
  uchar *puVar4;
  undefined4 *puVar5;
  char cVar10;
  ssl3_state_st *psVar6;
  SSL_METHOD *pSVar7;
  ssl2_state_st *psVar8;
  byte bVar11;
  undefined4 uVar9;
  int iVar12;
  uint uVar13;
  _func_3056 *p_Var14;
  int iVar15;
  uint uVar16;
  byte *pbVar17;
  byte *pbVar18;
  undefined4 uVar19;
  undefined4 *puVar20;
  uint unaff_s3;
  int iVar21;
  char *pcVar22;
  undefined4 local_38;
  undefined4 local_34;
  byte local_30;
  byte local_2f;
  byte local_2e;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iVar12 = param_1->state;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar20 = (undefined4 *)0x0;
  if (iVar12 != 0x2210) {
    iVar15 = -2;
    iVar21 = 0;
    unaff_s3 = 0;
    goto LAB_00493184;
  }
  iVar12 = ssl3_setup_buffers();
  if (iVar12 == 0) goto LAB_00493470;
  unaff_s3 = ssl23_read_bytes(param_1,0xb);
  uVar16 = unaff_s3;
  if (unaff_s3 != 0xb) goto LAB_00493474;
  puVar20 = (undefined4 *)param_1->packet;
  local_38 = *puVar20;
  local_34 = puVar20[1];
  local_30 = *(byte *)(puVar20 + 2);
  local_2f = *(byte *)((int)puVar20 + 9);
  local_2e = *(byte *)((int)puVar20 + 10);
  if (-1 < (char)*(byte *)puVar20) {
    if (*(byte *)puVar20 != 0x16) goto LAB_0049353c;
    if (*(byte *)((int)puVar20 + 1) != 3) goto LAB_0049353c;
    if (*(byte *)((int)puVar20 + 5) != 1) goto LAB_0049353c;
    if (*(byte *)((int)puVar20 + 3) != 0) goto LAB_00493904;
    if (*(byte *)(puVar20 + 1) < 5) goto LAB_00493864;
    bVar11 = *(byte *)((int)puVar20 + 9);
    if (bVar11 < 3) goto LAB_0049353c;
    if (*(byte *)(puVar20 + 1) < 6) goto LAB_00493864;
    goto LAB_0049381c;
  }
  if (*(byte *)((int)puVar20 + 2) != 1) goto LAB_0049353c;
  if (*(byte *)((int)puVar20 + 3) == 0) {
    if (*(byte *)(puVar20 + 1) != 2) goto LAB_004935d4;
    uVar16 = (uint)*(byte *)&param_1->references;
    goto LAB_004936b0;
  }
  if (*(byte *)((int)puVar20 + 3) != 3) goto LAB_004935d4;
  bVar11 = *(byte *)(puVar20 + 1);
  if (bVar11 == 0) {
    uVar13 = param_1->references;
  }
  else {
    if (bVar11 < 3) {
      if (bVar11 == 2) {
        uVar13 = param_1->references;
        goto LAB_004939f0;
      }
      uVar13 = param_1->references;
    }
    else {
      uVar13 = param_1->references;
      if (-1 < (int)(uVar13 << 4)) {
        param_1->version = 0x303;
        param_1->state = 0x2211;
        goto LAB_00493194;
      }
LAB_004939f0:
      if (-1 < (int)(uVar13 << 3)) {
        param_1->version = 0x302;
        param_1->state = 0x2211;
        goto LAB_00493194;
      }
    }
    if (-1 < (int)(uVar13 << 5)) {
      param_1->version = 0x301;
      param_1->state = 0x2211;
      goto LAB_00493194;
    }
  }
  uVar16 = uVar13 >> 0x18;
  if (-1 < (int)(uVar13 << 6)) {
    param_1->version = 0x300;
    param_1->state = 0x2211;
    goto LAB_00493194;
  }
LAB_004936b0:
  if (param_1->state == 0x2211) goto LAB_00493194;
  if (((uVar16 ^ 1) & 1) != 0) {
    if (param_1->s2 == (ssl2_state_st *)0x0) {
      iVar12 = ssl2_new(param_1);
      if (iVar12 == 0) {
        uVar16 = 0xffffffff;
        goto LAB_00493474;
      }
    }
    else {
      ssl2_clear(param_1);
    }
    if (param_1->s3 != (ssl3_state_st *)0x0) {
      ssl3_free(param_1);
    }
    iVar12 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(param_1->init_buf,0x3fff);
    if (iVar12 == 0) goto LAB_00493470;
    param_1->state = 0x2010;
    if ((param_1->references & 0x6000000U) == 0x6000000) {
      psVar8 = param_1->s2;
      psVar8->ssl2_rollback = 0;
    }
    else {
      psVar8 = param_1->s2;
      psVar8->ssl2_rollback = 1;
    }
    puVar5 = (undefined4 *)psVar8->rbuf;
    param_1->packet_length = 0xb;
    param_1->packet = (uchar *)puVar5;
    param_1->rstate = 0xf0;
    *puVar5 = local_38;
    puVar5[1] = local_34;
    *(byte *)(puVar5 + 2) = local_30;
    *(byte *)((int)puVar5 + 9) = local_2f;
    *(byte *)((int)puVar5 + 10) = local_2e;
    psVar8 = param_1->s2;
    psVar8->rbuf_left = 0xb;
    psVar8->rbuf_offs = 0;
    pSVar7 = SSLv2_server_method();
    p_Var14 = pSVar7->ssl_accept;
    param_1->method = pSVar7;
    param_1->handshake_func = (_func_3149 *)p_Var14;
    goto LAB_00493404;
  }
  puVar20 = (undefined4 *)0x0;
LAB_004933f8:
  do {
    puVar20 = (undefined4 *)(uint)((byte *)((int)puVar20 + -1) < (byte *)0x3);
    if (puVar20 == (undefined4 *)0x0) {
      uVar19 = 0xfc;
      uVar9 = 0x274;
      goto LAB_0049345c;
    }
LAB_00493404:
    iVar12 = *(int *)puVar3;
    param_1->init_num = 0;
    if (local_2c == iVar12) {
      uVar16 = SSL_accept(param_1);
      return uVar16;
    }
LAB_004938f8:
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00493904:
    bVar11 = *(byte *)((int)puVar20 + 9);
    if (bVar11 < 3) {
LAB_0049353c:
      iVar12 = (*(code *)PTR_strncmp_006aaa7c)(&DAT_0063b950,puVar20,4);
      if ((((iVar12 == 0) ||
           (iVar12 = (*(code *)PTR_strncmp_006aaa7c)("POST ",puVar20,5), iVar12 == 0)) ||
          (iVar12 = (*(code *)PTR_strncmp_006aaa7c)("HEAD ",puVar20,5), iVar12 == 0)) ||
         (iVar12 = (*(code *)PTR_strncmp_006aaa7c)(&DAT_006479f0,puVar20,4), iVar12 == 0)) {
        uVar19 = 0x9c;
        uVar9 = 0x1a2;
      }
      else {
        iVar12 = (*(code *)PTR_strncmp_006aaa7c)("CONNECT",puVar20,7);
        if (iVar12 != 0) {
LAB_004935d4:
          iVar12 = param_1->state;
          iVar15 = -2;
          puVar20 = (undefined4 *)0x0;
          iVar21 = 0;
          goto LAB_00493184;
        }
        uVar19 = 0x9b;
        uVar9 = 0x1a7;
      }
LAB_0049345c:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x76,uVar19,"s23_srvr.c",uVar9);
LAB_00493470:
      uVar16 = 0xffffffff;
      goto LAB_00493474;
    }
LAB_0049381c:
    if (bVar11 < 4) {
      bVar11 = *(byte *)((int)puVar20 + 10);
      if (bVar11 == 0) {
        if (param_1->references << 6 < 0) {
          if (param_1->references << 5 < 0) goto LAB_00493650;
          goto LAB_00493848;
        }
LAB_0049387c:
        iVar12 = param_1->state;
        iVar15 = 1;
        puVar20 = (undefined4 *)0x3;
        param_1->version = 0x300;
        iVar21 = 3;
        goto LAB_00493184;
      }
      if (2 < bVar11) goto LAB_0049396c;
      if (bVar11 != 1) {
        iVar12 = param_1->references;
        goto LAB_00493948;
      }
LAB_00493864:
      iVar12 = param_1->references;
LAB_00493868:
      if (-1 < iVar12 << 5) {
LAB_00493848:
        iVar12 = param_1->state;
        iVar15 = 1;
        puVar20 = (undefined4 *)0x3;
        param_1->version = 0x301;
        iVar21 = 3;
        goto LAB_00493184;
      }
      if (-1 < iVar12 << 6) goto LAB_0049387c;
LAB_00493650:
      puVar20 = (undefined4 *)0x0;
      if (param_1->state == 0x2211) {
LAB_00493660:
        uVar19 = 0xd6;
        uVar9 = 0x1c2;
        goto LAB_0049345c;
      }
      goto LAB_004933f8;
    }
LAB_0049396c:
    iVar12 = param_1->references;
    iVar15 = 1;
    if (iVar12 << 4 < 0) {
LAB_00493948:
      iVar15 = 1;
      if (iVar12 << 3 < 0) goto LAB_00493868;
      iVar12 = param_1->state;
      puVar20 = (undefined4 *)0x3;
      param_1->version = 0x302;
      iVar21 = 3;
    }
    else {
      iVar12 = param_1->state;
      puVar20 = (undefined4 *)0x3;
      param_1->version = 0x303;
      iVar21 = 3;
    }
LAB_00493184:
    if (iVar12 != 0x2211) {
      if (iVar15 != 1) goto LAB_004933f8;
      iVar12 = ssl_init_wbio_buffer(param_1,1);
      if (iVar12 == 0) goto LAB_00493470;
      param_1->state = 0x2110;
      if (iVar21 != 3) goto LAB_0049339c;
      param_1->packet_length = unaff_s3;
      param_1->rstate = 0xf0;
      puVar4 = (param_1->s3->rbuf).buf;
      if (puVar4 == (uchar *)0x0) {
        iVar12 = ssl3_setup_read_buffer(param_1);
        if (iVar12 == 0) goto LAB_00493470;
        puVar4 = (param_1->s3->rbuf).buf;
      }
      puVar2 = PTR_memcpy_006aabf4;
      param_1->packet = puVar4;
      (*(code *)puVar2)(puVar4,&local_38,unaff_s3);
      psVar6 = param_1->s3;
      (psVar6->rbuf).left = unaff_s3;
      (psVar6->rbuf).offset = 0;
      goto LAB_004933ac;
    }
    puVar20 = (undefined4 *)param_1->packet;
LAB_00493194:
    uVar16 = (*(byte *)puVar20 & 0x7f) << 8 | (uint)*(byte *)((int)puVar20 + 1);
    if (0x1000 < uVar16) goto LAB_00493660;
    bVar11 = *(byte *)(puVar20 + 1);
    uVar16 = ssl23_read_bytes(param_1,uVar16 + 2);
    if ((int)uVar16 < 1) {
LAB_00493474:
      if (local_2c == *(int *)puVar3) {
        return uVar16;
      }
      goto LAB_004938f8;
    }
    ssl3_finish_mac(param_1,param_1->packet + 2,param_1->packet_length - 2);
    if (param_1->msg_callback != (_func_3150 *)0x0) {
      (*param_1->msg_callback)
                (0,2,0,param_1->packet + 2,param_1->packet_length - 2,param_1,
                 param_1->msg_callback_arg);
    }
    puVar2 = PTR_memset_006aab00;
    puVar4 = param_1->packet;
    puVar20 = (undefined4 *)(puVar4 + 0xb);
    uVar1 = *(ushort *)(puVar4 + 7);
    unaff_s3 = (uint)*(ushort *)(puVar4 + 5);
    uVar16 = (uint)*(ushort *)(puVar4 + 9);
    pcVar22 = param_1->init_buf->data;
    if (uVar16 + 0xb + uVar1 + unaff_s3 != param_1->packet_length) {
      uVar19 = 0xd5;
      uVar9 = 0x1d7;
      goto LAB_0049345c;
    }
    pcVar22[5] = bVar11;
    if (0x20 < uVar16) {
      uVar16 = 0x20;
    }
    *pcVar22 = '\x01';
    pcVar22[4] = '\x03';
    (*(code *)puVar2)(pcVar22 + 6,0,0x20);
    (*(code *)PTR_memcpy_006aabf4)
              (pcVar22 + 6 + (0x20 - uVar16),(byte *)((int)puVar20 + uVar1 + unaff_s3),uVar16);
    pbVar17 = (byte *)(pcVar22 + 0x29);
    uVar16 = 0;
    pcVar22[0x26] = '\0';
    if (unaff_s3 == 0) {
      cVar10 = '\0';
    }
    else {
      uVar13 = 0;
      puVar5 = puVar20;
      pbVar18 = pbVar17;
      do {
        pbVar17 = pbVar18;
        if (*(byte *)puVar5 == 0) {
          pbVar17 = pbVar18 + 2;
          uVar16 = uVar16 + 2;
          *pbVar18 = *(byte *)((int)puVar5 + 1);
          pbVar18[1] = *(byte *)((int)puVar5 + 2);
        }
        uVar13 = uVar13 + 3;
        puVar5 = (undefined4 *)((int)puVar5 + 3);
        pbVar18 = pbVar17;
      } while (uVar13 < unaff_s3);
      cVar10 = (char)(uVar16 >> 8);
      uVar16 = uVar16 & 0xff;
    }
    pcVar22[0x27] = cVar10;
    pcVar22[0x28] = (char)uVar16;
    pbVar17[1] = 0;
    *pbVar17 = 1;
    pbVar17 = pbVar17 + (-2 - (int)param_1->init_buf->data);
    pcVar22[3] = (char)pbVar17;
    pcVar22[2] = (char)((uint)pbVar17 >> 8);
    pcVar22[1] = (char)((uint)pbVar17 >> 0x10);
    psVar6 = param_1->s3;
    (psVar6->tmp).reuse_message = 1;
    (psVar6->tmp).message_type = 1;
    (psVar6->tmp).message_size = (ulong)pbVar17;
    iVar12 = ssl_init_wbio_buffer(param_1,1);
    if (iVar12 == 0) goto LAB_00493470;
    puVar20 = (undefined4 *)&SUB_00000002;
    param_1->state = 0x2110;
LAB_0049339c:
    psVar6 = param_1->s3;
    param_1->packet_length = 0;
    (psVar6->rbuf).left = 0;
    (psVar6->rbuf).offset = 0;
LAB_004933ac:
    iVar12 = param_1->version;
    if (iVar12 == 0x303) {
      pSVar7 = TLSv1_2_server_method();
      param_1->method = pSVar7;
    }
    else if (iVar12 == 0x302) {
      pSVar7 = TLSv1_1_server_method();
      param_1->method = pSVar7;
    }
    else if (iVar12 == 0x301) {
      pSVar7 = TLSv1_server_method();
      param_1->method = pSVar7;
    }
    else {
      pSVar7 = SSLv3_server_method();
      param_1->method = pSVar7;
    }
    param_1->handshake_func = (_func_3149 *)pSVar7->ssl_accept;
  } while( true );
}

