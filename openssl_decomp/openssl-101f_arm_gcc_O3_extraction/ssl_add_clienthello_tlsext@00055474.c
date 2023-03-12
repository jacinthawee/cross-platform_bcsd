
uchar * ssl_add_clienthello_tlsext(SSL *param_1,uchar *param_2,uchar *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uchar *puVar4;
  void *pvVar5;
  size_t __n;
  long lVar6;
  stack_st_SRTP_PROTECTION_PROFILE *psVar7;
  int iVar8;
  int iVar9;
  X509_EXTENSIONS *a;
  OCSP_RESPID *pOVar10;
  uchar uVar11;
  uchar uVar12;
  int iVar13;
  SSL_SESSION *pSVar14;
  ushort *__n_00;
  SSL_SESSION *pSVar15;
  bool bVar16;
  uchar *local_28;
  int local_24;
  
  if ((param_1->first_packet == 0x300) && (param_1->s3->send_connection_binding == 0)) {
    return param_2;
  }
  local_28 = param_2 + 2;
  if (param_3 <= local_28) {
    return (uchar *)0x0;
  }
  if ((char *)param_1->tlsext_debug_arg != (char *)0x0) {
    iVar13 = -9 - (int)local_28;
    if ((int)(param_3 + iVar13) < 0) {
      return (uchar *)0x0;
    }
    puVar4 = (uchar *)strlen((char *)param_1->tlsext_debug_arg);
    if (param_3 + iVar13 < puVar4) {
      return (uchar *)0x0;
    }
    local_28 = param_2 + 0xb;
    uVar11 = (uchar)puVar4;
    param_2[10] = uVar11;
    param_2[5] = uVar11 + '\x05';
    param_2[4] = (uchar)((uint)(puVar4 + 5) >> 8);
    param_2[6] = (uchar)((uint)(puVar4 + 3) >> 8);
    param_2[7] = uVar11 + '\x03';
    param_2[2] = '\0';
    param_2[3] = '\0';
    param_2[8] = '\0';
    param_2[9] = (uchar)((uint)puVar4 >> 8);
    pvVar5 = memcpy(local_28,param_1->tlsext_debug_arg,(size_t)puVar4);
    local_28 = puVar4 + (int)pvVar5;
  }
  if (param_1->tlsext_hb_seq != 0) {
    iVar8 = ssl_add_clienthello_renegotiate_ext(param_1,0,&local_24,0);
    iVar13 = 0x198;
    if (iVar8 == 0) goto LAB_00055780;
    if ((int)(param_3 + (-local_24 - (int)param_2) + -4) < 0) {
      return (uchar *)0x0;
    }
    *local_28 = 0xff;
    local_28[1] = '\x01';
    local_28[2] = (uchar)((uint)local_24 >> 8);
    local_28[3] = (uchar)local_24;
    local_28 = local_28 + 4;
    iVar8 = ssl_add_clienthello_renegotiate_ext(param_1,local_28,&local_24,local_24);
    iVar13 = 0x1a3;
    if (iVar8 == 0) goto LAB_00055780;
    local_28 = local_28 + local_24;
  }
  puVar4 = local_28;
  if (param_1[1].rbio != (BIO *)0x0) {
    __n = strlen((char *)param_1[1].rbio);
    if (__n == 0 || 0xff < (int)__n) {
      iVar13 = 0x1b2;
      goto LAB_00055780;
    }
    if ((int)(param_3 + (-__n - (int)puVar4) + -5) < 0) {
      return (uchar *)0x0;
    }
    *puVar4 = '\0';
    local_28[1] = '\f';
    local_28[2] = (uchar)(__n + 1 >> 8);
    local_28[3] = (uchar)__n + '\x01';
    puVar4 = local_28 + 5;
    local_28[4] = (uchar)__n;
    local_28 = puVar4;
    memcpy(puVar4,param_1[1].rbio,__n);
    local_28 = local_28 + __n;
  }
  if ((param_1->tlsext_ecpointformatlist_length != 0) && (param_1->version != 0xfeff)) {
    if ((int)(param_3 + (-5 - (int)local_28)) < 0) {
      return (uchar *)0x0;
    }
    if (param_3 + (-5 - (int)local_28) < (uchar *)param_1->tlsext_ticket_expected) {
      return (uchar *)0x0;
    }
    if ((uchar *)0xff < (uchar *)param_1->tlsext_ticket_expected) {
      iVar13 = 0x1d1;
      goto LAB_00055780;
    }
    *local_28 = '\0';
    local_28[1] = '\v';
    local_28[2] = (uchar)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
    local_28[3] = (char)param_1->tlsext_ticket_expected + '\x01';
    puVar4 = local_28 + 5;
    local_28[4] = (uchar)param_1->tlsext_ticket_expected;
    local_28 = puVar4;
    memcpy(puVar4,(void *)param_1->tlsext_ecpointformatlist_length,param_1->tlsext_ticket_expected);
    local_28 = local_28 + param_1->tlsext_ticket_expected;
  }
  if ((param_1->tlsext_ellipticcurvelist_length != 0) && (param_1->version != 0xfeff)) {
    if ((int)(param_3 + (-6 - (int)local_28)) < 0) {
      return (uchar *)0x0;
    }
    if (param_3 + (-6 - (int)local_28) < param_1->tlsext_ecpointformatlist) {
      return (uchar *)0x0;
    }
    if ((uchar *)0xfffc < param_1->tlsext_ecpointformatlist) {
      iVar13 = 0x1e5;
      goto LAB_00055780;
    }
    *local_28 = '\0';
    local_28[1] = '\n';
    local_28[2] = (uchar)((uint)(param_1->tlsext_ecpointformatlist + 2) >> 8);
    local_28[3] = (char)param_1->tlsext_ecpointformatlist + '\x02';
    local_28[4] = (uchar)((uint)param_1->tlsext_ecpointformatlist >> 8);
    local_28[5] = (uchar)param_1->tlsext_ecpointformatlist;
    local_28 = local_28 + 6;
    memcpy(local_28,(void *)param_1->tlsext_ellipticcurvelist_length,
           (size_t)param_1->tlsext_ecpointformatlist);
    local_28 = param_1->tlsext_ecpointformatlist + (int)local_28;
  }
  lVar6 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if (-1 < lVar6 << 0x11) {
    pSVar15 = param_1->session;
    if (param_1->new_session == 0) {
      if (pSVar15 == (SSL_SESSION *)0x0) {
LAB_00055a76:
        __n_00 = (ushort *)param_1->tlsext_opaque_prf_input_len;
        if (__n_00 != (ushort *)0x0) {
          if (*(int *)(__n_00 + 2) == 0) goto LAB_0005567e;
          __n_00 = (ushort *)0x0;
        }
      }
      else {
        if (*(int *)(pSVar15->krb5_client_princ + 0x54) == 0) goto LAB_0005590c;
        __n_00 = *(ushort **)(pSVar15->krb5_client_princ + 0x58);
LAB_000557d0:
        if (__n_00 == (ushort *)0x0) goto LAB_00055a76;
      }
LAB_000557d6:
      if ((int)(param_3 + (-(int)__n_00 - (int)local_28) + -4) < 0) {
        return (uchar *)0x0;
      }
      *local_28 = '\0';
      local_28[1] = '#';
      local_28[2] = (uchar)((uint)__n_00 >> 8);
      local_28[3] = (uchar)__n_00;
      local_28 = local_28 + 4;
      if (__n_00 != (ushort *)0x0) {
        memcpy(local_28,*(void **)(param_1->session->krb5_client_princ + 0x54),(size_t)__n_00);
        local_28 = local_28 + (int)__n_00;
      }
    }
    else {
      if (pSVar15 == (SSL_SESSION *)0x0) goto LAB_00055a76;
LAB_0005590c:
      __n_00 = (ushort *)param_1->tlsext_opaque_prf_input_len;
      if (__n_00 == (ushort *)0x0) goto LAB_000557d6;
      if (*(int *)(__n_00 + 2) != 0) {
        __n_00 = (ushort *)(uint)*__n_00;
        pvVar5 = CRYPTO_malloc((int)__n_00,"t1_lib.c",0x200);
        pSVar14 = param_1->session;
        *(void **)(pSVar15->krb5_client_princ + 0x54) = pvVar5;
        pvVar5 = *(void **)(pSVar14->krb5_client_princ + 0x54);
        if (pvVar5 == (void *)0x0) {
          return (uchar *)0x0;
        }
        memcpy(pvVar5,*(void **)(param_1->tlsext_opaque_prf_input_len + 4),(size_t)__n_00);
        *(ushort **)(param_1->session->krb5_client_princ + 0x58) = __n_00;
        goto LAB_000557d0;
      }
    }
  }
LAB_0005567e:
  if ((param_1->first_packet >> 8 == 3) && (0x302 < param_1->first_packet)) {
    if ((uint)((int)param_3 - (int)local_28) < 0x24) {
      return (uchar *)0x0;
    }
    *local_28 = '\0';
    local_28[1] = '\r';
    local_28[2] = '\0';
    local_28[3] = ' ';
    local_28[4] = '\0';
    local_28[5] = '\x1e';
    uVar3 = DAT_0018dedc;
    uVar2 = DAT_0018ded8;
    uVar1 = tls12_sigalgs;
    *(undefined4 *)(local_28 + 0x12) = DAT_0018dee0;
    *(undefined4 *)(local_28 + 6) = uVar1;
    *(undefined4 *)(local_28 + 10) = uVar2;
    *(undefined4 *)(local_28 + 0xe) = uVar3;
    uVar2 = DAT_0018deec;
    uVar1 = DAT_0018dee8;
    *(undefined4 *)(local_28 + 0x16) = DAT_0018dee4;
    *(undefined4 *)(local_28 + 0x1a) = uVar1;
    *(undefined4 *)(local_28 + 0x1e) = uVar2;
    *(undefined2 *)(local_28 + 0x22) = DAT_0018def0;
    local_28 = local_28 + 0x24;
  }
  if ((param_1->servername_done == 1) && (param_1->version != 0xfeff)) {
    iVar8 = 0;
    iVar13 = 0;
    while( true ) {
      iVar9 = sk_num((_STACK *)param_1->tlsext_status_expected);
      if (iVar9 <= iVar13) break;
      pOVar10 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar13);
      iVar9 = i2d_OCSP_RESPID(pOVar10,(uchar **)0x0);
      iVar8 = iVar8 + iVar9 + 2;
      iVar13 = iVar13 + 1;
      if (iVar9 < 1) {
        return (uchar *)0x0;
      }
    }
    a = (X509_EXTENSIONS *)param_1->tlsext_ocsp_ids;
    if ((a != (X509_EXTENSIONS *)0x0) &&
       (a = (X509_EXTENSIONS *)i2d_X509_EXTENSIONS(a,(uchar **)0x0), (int)a < 0)) {
      return (uchar *)0x0;
    }
    if ((int)(param_3 + (((-7 - (int)local_28) - (int)a) - iVar8)) < 0) {
      return (uchar *)0x0;
    }
    *local_28 = '\0';
    iVar13 = (int)&(a->stack).num + iVar8;
    local_28[1] = '\x05';
    if (0xfff0 < iVar13) {
      return (uchar *)0x0;
    }
    local_28[2] = (uchar)((uint)(iVar13 + 5) >> 8);
    local_28[3] = (uchar)iVar8 + '\x05' + (uchar)a;
    local_28[4] = '\x01';
    local_28[5] = (uchar)((uint)iVar8 >> 8);
    local_28[6] = (uchar)iVar8;
    local_28 = local_28 + 7;
    iVar13 = 0;
    while( true ) {
      iVar8 = sk_num((_STACK *)param_1->tlsext_status_expected);
      puVar4 = local_28;
      if (iVar8 <= iVar13) break;
      pOVar10 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar13);
      local_28 = local_28 + 2;
      iVar8 = i2d_OCSP_RESPID(pOVar10,&local_28);
      puVar4[1] = (uchar)iVar8;
      *puVar4 = (uchar)((uint)iVar8 >> 8);
      iVar13 = iVar13 + 1;
    }
    *local_28 = (uchar)((uint)a >> 8);
    local_28[1] = (uchar)a;
    local_28 = local_28 + 2;
    if (a != (X509_EXTENSIONS *)0x0) {
      i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,&local_28);
    }
  }
  puVar4 = local_28;
  *local_28 = '\0';
  uVar11 = '\x01';
  local_28[1] = '\x0f';
  local_28[2] = '\0';
  local_28[3] = '\x01';
  bVar16 = (int)param_1->srtp_profile << 0x1d < 0;
  if (bVar16) {
    uVar11 = (char)local_28 + '\x05';
    uVar12 = '\x02';
  }
  else {
    uVar12 = (char)local_28 + '\x05';
  }
  local_28 = local_28 + 5;
  if (bVar16) {
    puVar4[4] = uVar12;
  }
  if (!bVar16) {
    puVar4[4] = uVar11;
  }
  if ((*(int *)(param_1->psk_server_callback + 0x1ac) != 0) &&
     ((param_1->s3->tmp).finish_md_len == 0)) {
    if ((int)param_3 - (int)local_28 < 4) {
      return (uchar *)0x0;
    }
    *local_28 = '3';
    puVar4[6] = 't';
    puVar4[7] = '\0';
    puVar4[8] = '\0';
    local_28 = puVar4 + 9;
  }
  psVar7 = SSL_get_srtp_profiles(param_1);
  if (psVar7 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0) {
    ssl_add_clienthello_use_srtp_ext(param_1,0,&local_24,0);
    if ((int)(param_3 + (-local_24 - (int)param_2) + -4) < 0) {
      return (uchar *)0x0;
    }
    *local_28 = '\0';
    local_28[1] = '\x0e';
    local_28[2] = (uchar)((uint)local_24 >> 8);
    local_28[3] = (uchar)local_24;
    local_28 = local_28 + 4;
    iVar8 = ssl_add_clienthello_use_srtp_ext(param_1,local_28,&local_24,local_24);
    iVar13 = 0x292;
    if (iVar8 != 0) {
LAB_00055780:
      ERR_put_error(0x14,0x115,0x44,"t1_lib.c",iVar13);
      return (uchar *)0x0;
    }
    local_28 = local_28 + local_24;
  }
  puVar4 = local_28 + (-2 - (int)param_2);
  if (puVar4 == (uchar *)0x0) {
    return param_2;
  }
  param_2[1] = (uchar)puVar4;
  *param_2 = (uchar)((uint)puVar4 >> 8);
  return local_28;
}

