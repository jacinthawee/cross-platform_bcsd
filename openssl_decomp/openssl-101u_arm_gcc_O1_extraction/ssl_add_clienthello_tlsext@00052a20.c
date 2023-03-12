
SSL * ssl_add_clienthello_tlsext(SSL *param_1,undefined *param_2,SSL *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  SSL *pSVar4;
  size_t sVar5;
  void *pvVar6;
  long lVar7;
  int iVar8;
  X509_EXTENSIONS *a;
  OCSP_RESPID *pOVar9;
  stack_st_SRTP_PROTECTION_PROFILE *psVar10;
  char cVar11;
  char cVar12;
  int iVar13;
  int iVar14;
  uchar *puVar15;
  undefined *puVar16;
  SSL_SESSION *pSVar17;
  int *__s;
  SSL *pSVar18;
  SSL *pSVar19;
  uint uVar20;
  SSL_SESSION *pSVar21;
  bool bVar22;
  bool bVar23;
  bool bVar24;
  SSL *local_28;
  int local_24;
  
  if ((param_1->first_packet == 0x300) && (param_1->s3->send_connection_binding == 0)) {
    return (SSL *)param_2;
  }
  local_28 = (SSL *)(param_2 + 2);
  if (param_3 <= local_28) {
    return (SSL *)(undefined *)0x0;
  }
  if ((char *)param_1->tlsext_debug_arg != (char *)0x0) {
    uVar20 = (int)param_3 + (-9 - (int)local_28);
    if ((int)uVar20 < 0) {
      return (SSL *)(undefined *)0x0;
    }
    sVar5 = strlen((char *)param_1->tlsext_debug_arg);
    if (uVar20 < sVar5) {
      return (SSL *)(undefined *)0x0;
    }
    local_28 = (SSL *)(param_2 + 0xb);
    cVar11 = (char)sVar5;
    param_2[10] = cVar11;
    param_2[5] = cVar11 + '\x05';
    param_2[4] = (char)(sVar5 + 5 >> 8);
    param_2[6] = (char)(sVar5 + 3 >> 8);
    param_2[7] = cVar11 + '\x03';
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[8] = 0;
    param_2[9] = (char)(sVar5 >> 8);
    pvVar6 = memcpy(local_28,param_1->tlsext_debug_arg,sVar5);
    local_28 = (SSL *)(sVar5 + (int)pvVar6);
  }
  if (param_1->tlsext_hb_seq != 0) {
    iVar14 = ssl_add_clienthello_renegotiate_ext(param_1,0,&local_24,0);
    iVar13 = 0x1a6;
    if (iVar14 == 0) goto LAB_00052d14;
    if ((int)param_3 + (-local_24 - (int)local_28) + -4 < 0) {
      return (SSL *)(undefined *)0x0;
    }
    *(undefined *)&local_28->version = 0xff;
    *(undefined *)((int)&local_28->version + 1) = 1;
    *(char *)((int)&local_28->version + 2) = (char)((uint)local_24 >> 8);
    *(char *)((int)&local_28->version + 3) = (char)local_24;
    local_28 = (SSL *)&local_28->type;
    iVar14 = ssl_add_clienthello_renegotiate_ext(param_1,local_28,&local_24,local_24);
    iVar13 = 0x1b1;
    if (iVar14 == 0) goto LAB_00052d14;
    local_28 = (SSL *)((int)&local_28->version + local_24);
  }
  pSVar18 = local_28;
  if (param_1[1].rbio != (BIO *)0x0) {
    sVar5 = strlen((char *)param_1[1].rbio);
    if (sVar5 == 0 || 0xff < (int)sVar5) {
      iVar13 = 0x1be;
      goto LAB_00052d14;
    }
    if ((int)((int)param_3 + (-sVar5 - (int)pSVar18) + -5) < 0) {
      return (SSL *)(undefined *)0x0;
    }
    *(undefined *)&pSVar18->version = 0;
    *(undefined *)((int)&local_28->version + 1) = 0xc;
    *(char *)((int)&local_28->version + 2) = (char)(sVar5 + 1 >> 8);
    *(char *)((int)&local_28->version + 3) = (char)sVar5 + '\x01';
    pSVar18 = (SSL *)((int)&local_28->type + 1);
    *(char *)&local_28->type = (char)sVar5;
    local_28 = pSVar18;
    memcpy(pSVar18,param_1[1].rbio,sVar5);
    local_28 = (SSL *)((int)&local_28->version + sVar5);
  }
  if (param_1->tlsext_ecpointformatlist_length != 0) {
    uVar20 = (int)param_3 + (-5 - (int)local_28);
    if ((int)uVar20 < 0) {
      return (SSL *)(undefined *)0x0;
    }
    if (uVar20 < (uint)param_1->tlsext_ticket_expected) {
      return (SSL *)(undefined *)0x0;
    }
    if (0xff < (uint)param_1->tlsext_ticket_expected) {
      iVar13 = 0x1e0;
      goto LAB_00052d14;
    }
    *(undefined *)&local_28->version = 0;
    *(undefined *)((int)&local_28->version + 1) = 0xb;
    *(char *)((int)&local_28->version + 2) =
         (char)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
    *(char *)((int)&local_28->version + 3) = (char)param_1->tlsext_ticket_expected + '\x01';
    pSVar18 = (SSL *)((int)&local_28->type + 1);
    *(char *)&local_28->type = (char)param_1->tlsext_ticket_expected;
    local_28 = pSVar18;
    memcpy(pSVar18,(void *)param_1->tlsext_ecpointformatlist_length,param_1->tlsext_ticket_expected)
    ;
    local_28 = (SSL *)((int)&local_28->version + param_1->tlsext_ticket_expected);
  }
  pSVar18 = local_28;
  if (param_1->tlsext_ellipticcurvelist_length != 0) {
    puVar15 = (uchar *)((int)param_3 + (-6 - (int)local_28));
    if ((int)puVar15 < 0) {
      return (SSL *)(undefined *)0x0;
    }
    if (puVar15 < param_1->tlsext_ecpointformatlist) {
      return (SSL *)(undefined *)0x0;
    }
    if ((uchar *)0xfffc < param_1->tlsext_ecpointformatlist) {
      iVar13 = 0x1f6;
      goto LAB_00052d14;
    }
    *(undefined *)&local_28->version = 0;
    *(undefined *)((int)&local_28->version + 1) = 10;
    *(char *)((int)&local_28->version + 2) =
         (char)((uint)(param_1->tlsext_ecpointformatlist + 2) >> 8);
    *(char *)((int)&local_28->version + 3) = (char)param_1->tlsext_ecpointformatlist + '\x02';
    *(char *)&local_28->type = (char)((uint)param_1->tlsext_ecpointformatlist >> 8);
    *(char *)((int)&local_28->type + 1) = (char)param_1->tlsext_ecpointformatlist;
    local_28 = (SSL *)((int)&local_28->type + 2);
    memcpy(local_28,(void *)param_1->tlsext_ellipticcurvelist_length,
           (size_t)param_1->tlsext_ecpointformatlist);
    local_28 = (SSL *)(param_1->tlsext_ecpointformatlist + (int)local_28);
  }
  lVar7 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if (-1 < lVar7 << 0x11) {
    pSVar21 = param_1->session;
    if (param_1->new_session == 0) {
      if (pSVar21 == (SSL_SESSION *)0x0) {
LAB_00053038:
        pSVar18 = (SSL *)param_1->tlsext_opaque_prf_input_len;
        if (pSVar18 != (SSL *)0x0) {
          if (pSVar18->type == 0) goto LAB_00052c14;
          pSVar18 = (SSL *)0x0;
        }
      }
      else {
        if (*(int *)(pSVar21->krb5_client_princ + 0x54) == 0) goto LAB_00052ec4;
        pSVar18 = *(SSL **)(pSVar21->krb5_client_princ + 0x58);
LAB_00052dc8:
        if (pSVar18 == (SSL *)0x0) goto LAB_00053038;
      }
LAB_00052dce:
      if ((int)param_3 + (-(int)pSVar18 - (int)local_28) + -4 < 0) {
        return (SSL *)(undefined *)0x0;
      }
      *(undefined *)&local_28->version = 0;
      *(undefined *)((int)&local_28->version + 1) = 0x23;
      *(char *)((int)&local_28->version + 2) = (char)((uint)pSVar18 >> 8);
      *(char *)((int)&local_28->version + 3) = (char)pSVar18;
      local_28 = (SSL *)&local_28->type;
      if (pSVar18 != (SSL *)0x0) {
        memcpy(local_28,*(void **)(param_1->session->krb5_client_princ + 0x54),(size_t)pSVar18);
        local_28 = (SSL *)((int)&pSVar18->version + (int)&local_28->version);
      }
    }
    else {
      if (pSVar21 == (SSL_SESSION *)0x0) goto LAB_00053038;
LAB_00052ec4:
      pSVar18 = (SSL *)param_1->tlsext_opaque_prf_input_len;
      if (pSVar18 == (SSL *)0x0) goto LAB_00052dce;
      if (pSVar18->type != 0) {
        pSVar18 = (SSL *)(uint)*(ushort *)&pSVar18->version;
        pvVar6 = CRYPTO_malloc((int)pSVar18,"t1_lib.c",0x20b);
        pSVar17 = param_1->session;
        *(void **)(pSVar21->krb5_client_princ + 0x54) = pvVar6;
        pvVar6 = *(void **)(pSVar17->krb5_client_princ + 0x54);
        if (pvVar6 == (void *)0x0) {
          return (SSL *)(undefined *)0x0;
        }
        memcpy(pvVar6,*(void **)(param_1->tlsext_opaque_prf_input_len + 4),(size_t)pSVar18);
        *(SSL **)(param_1->session->krb5_client_princ + 0x58) = pSVar18;
        goto LAB_00052dc8;
      }
    }
  }
LAB_00052c14:
  if ((param_1->first_packet >> 8 == 3) && (0x302 < param_1->first_packet)) {
    if ((uint)((int)param_3 - (int)local_28) < 0x24) {
      return (SSL *)(undefined *)0x0;
    }
    *(undefined *)&local_28->version = 0;
    *(undefined *)((int)&local_28->version + 1) = 0xd;
    *(undefined *)((int)&local_28->version + 2) = 0;
    *(undefined *)((int)&local_28->version + 3) = 0x20;
    *(undefined *)&local_28->type = 0;
    *(undefined *)((int)&local_28->type + 1) = 0x1e;
    uVar3 = DAT_0018ccd8;
    uVar2 = DAT_0018ccd4;
    uVar1 = tls12_sigalgs;
    *(undefined4 *)((int)&local_28->wbio + 2) = DAT_0018ccdc;
    *(undefined4 *)((int)&local_28->type + 2) = uVar1;
    *(undefined4 *)((int)&local_28->method + 2) = uVar2;
    *(undefined4 *)((int)&local_28->rbio + 2) = uVar3;
    uVar2 = DAT_0018cce8;
    uVar1 = DAT_0018cce4;
    pSVar18 = (SSL *)&DAT_0018ccec;
    *(undefined4 *)((int)&local_28->bbio + 2) = DAT_0018cce0;
    *(undefined4 *)((int)&local_28->rwstate + 2) = uVar1;
    *(undefined4 *)((int)&local_28->in_handshake + 2) = uVar2;
    *(undefined2 *)((int)&local_28->handshake_func + 2) = DAT_0018ccec;
    local_28 = (SSL *)&local_28->server;
  }
  if ((param_1->servername_done == 1) && (param_1->version != 0xfeff)) {
    iVar14 = 0;
    iVar13 = 0;
    while( true ) {
      iVar8 = sk_num((_STACK *)param_1->tlsext_status_expected);
      if (iVar8 <= iVar13) break;
      pOVar9 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar13);
      iVar8 = i2d_OCSP_RESPID(pOVar9,(uchar **)0x0);
      iVar14 = iVar14 + iVar8 + 2;
      iVar13 = iVar13 + 1;
      if (iVar8 < 1) {
        return (SSL *)(undefined *)0x0;
      }
    }
    a = (X509_EXTENSIONS *)param_1->tlsext_ocsp_ids;
    if ((a != (X509_EXTENSIONS *)0x0) &&
       (a = (X509_EXTENSIONS *)i2d_X509_EXTENSIONS(a,(uchar **)0x0), (int)a < 0)) {
      return (SSL *)(undefined *)0x0;
    }
    if ((int)param_3 + (((-7 - (int)local_28) - (int)a) - iVar14) < 0) {
      return (SSL *)(undefined *)0x0;
    }
    *(undefined *)&local_28->version = 0;
    iVar13 = (int)&(a->stack).num + iVar14;
    *(undefined *)((int)&local_28->version + 1) = 5;
    if (0xfff0 < iVar13) {
      return (SSL *)(undefined *)0x0;
    }
    *(char *)((int)&local_28->version + 2) = (char)((uint)(iVar13 + 5) >> 8);
    *(char *)((int)&local_28->version + 3) = (char)iVar14 + '\x05' + (char)a;
    *(undefined *)&local_28->type = 1;
    *(char *)((int)&local_28->type + 1) = (char)((uint)iVar14 >> 8);
    *(char *)((int)&local_28->type + 2) = (char)iVar14;
    local_28 = (SSL *)((int)&local_28->type + 3);
    pSVar19 = (SSL *)0x0;
    while( true ) {
      iVar13 = sk_num((_STACK *)param_1->tlsext_status_expected);
      pSVar4 = local_28;
      pSVar18 = (SSL *)((int)&pSVar19->version + 1);
      if (iVar13 <= (int)pSVar19) break;
      pOVar9 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,(int)pSVar19);
      local_28 = (SSL *)((int)&local_28->version + 2);
      iVar13 = i2d_OCSP_RESPID(pOVar9,(uchar **)&local_28);
      *(char *)((int)&pSVar4->version + 1) = (char)iVar13;
      *(char *)&pSVar4->version = (char)((uint)iVar13 >> 8);
      pSVar19 = pSVar18;
    }
    *(char *)&local_28->version = (char)((uint)a >> 8);
    *(char *)((int)&local_28->version + 1) = (char)a;
    local_28 = (SSL *)((int)&local_28->version + 2);
    if (a != (X509_EXTENSIONS *)0x0) {
      i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,(uchar **)&local_28);
    }
  }
  pSVar19 = local_28;
  if ((int)param_3 - (int)local_28 < 5) {
    return (SSL *)(undefined *)0x0;
  }
  *(undefined *)&local_28->version = 0;
  cVar11 = '\x01';
  *(undefined *)((int)&local_28->version + 1) = 0xf;
  *(undefined *)((int)&local_28->version + 2) = 0;
  *(undefined *)((int)&local_28->version + 3) = 1;
  bVar22 = (int)param_1->srtp_profile << 0x1d < 0;
  if (bVar22) {
    cVar11 = (char)local_28 + '\x05';
    cVar12 = '\x02';
  }
  else {
    cVar12 = (char)local_28 + '\x05';
  }
  local_28 = (SSL *)((int)&local_28->type + 1);
  if (bVar22) {
    *(char *)&pSVar19->type = cVar12;
  }
  if (!bVar22) {
    *(char *)&pSVar19->type = cVar11;
  }
  if ((*(int *)(param_1->psk_server_callback + 0x1ac) != 0) &&
     ((param_1->s3->tmp).finish_md_len == 0)) {
    if ((int)param_3 - (int)local_28 < 4) {
      return (SSL *)(undefined *)0x0;
    }
    *(undefined *)&local_28->version = 0x33;
    *(undefined *)((int)&pSVar19->type + 2) = 0x74;
    *(undefined *)((int)&pSVar19->type + 3) = 0;
    *(undefined *)&pSVar19->method = 0;
    local_28 = (SSL *)((int)&pSVar19->method + 1);
  }
  if ((param_1->method->version == 0xfeff) &&
     (psVar10 = SSL_get_srtp_profiles(param_1), psVar10 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0))
  {
    ssl_add_clienthello_use_srtp_ext(param_1,0,&local_24,0);
    if ((int)param_3 + (-local_24 - (int)local_28) + -4 < 0) {
      return (SSL *)(undefined *)0x0;
    }
    *(undefined *)&local_28->version = 0;
    *(undefined *)((int)&local_28->version + 1) = 0xe;
    param_3 = (SSL *)((int)&local_28->version + 2);
    *(char *)((int)&local_28->version + 2) = (char)((uint)local_24 >> 8);
    *(char *)((int)&local_28->version + 3) = (char)local_24;
    local_28 = (SSL *)&local_28->type;
    iVar14 = ssl_add_clienthello_use_srtp_ext(param_1,local_28,&local_24,local_24);
    iVar13 = 0x296;
    if (iVar14 != 0) {
LAB_00052d14:
      ERR_put_error(0x14,0x115,0x44,"t1_lib.c",iVar13);
      return (SSL *)(undefined *)0x0;
    }
    local_28 = (SSL *)((int)&local_28->version + local_24);
  }
  if (param_1->references << 0x1b < 0) {
    iVar13 = (int)local_28 - (int)param_1->init_buf->data;
    if (param_1->state == 0x1210) {
      iVar13 = iVar13 + -5;
    }
    if (iVar13 - 0x100U < 0x100) {
      iVar14 = -iVar13 + 0x200;
      bVar24 = SBORROW4(iVar14,3);
      bVar22 = -iVar13 + 0x1fd < 0;
      bVar23 = iVar14 == 3;
      *(undefined *)&local_28->version = 0;
      if (3 < iVar14) {
        param_1 = (SSL *)(0x1fc - iVar13);
      }
      if (bVar23 || bVar22 != bVar24) {
        param_1 = (SSL *)0x0;
      }
      if (!bVar23 && bVar22 == bVar24) {
        pSVar18 = (SSL *)((uint)((int)param_1 << 0x10) >> 0x18);
      }
      if (bVar23 || bVar22 != bVar24) {
        pSVar18 = param_1;
      }
      *(undefined *)((int)&local_28->version + 1) = 0x15;
      if (!bVar23 && bVar22 == bVar24) {
        param_3 = (SSL *)((uint)param_1 & 0xff);
      }
      if (bVar23 || bVar22 != bVar24) {
        param_3 = param_1;
      }
      *(char *)((int)&local_28->version + 2) = (char)pSVar18;
      *(char *)((int)&local_28->version + 3) = (char)param_3;
      __s = &local_28->type;
      local_28 = (SSL *)((int)&local_28->version + 2);
      memset(__s,0,(size_t)param_1);
      local_28 = (SSL *)((int)__s + (int)param_1);
    }
  }
  puVar16 = (undefined *)((int)local_28 + (-2 - (int)param_2));
  if (puVar16 == (undefined *)0x0) {
    return (SSL *)param_2;
  }
  param_2[1] = (char)puVar16;
  *param_2 = (char)((uint)puVar16 >> 8);
  return local_28;
}

