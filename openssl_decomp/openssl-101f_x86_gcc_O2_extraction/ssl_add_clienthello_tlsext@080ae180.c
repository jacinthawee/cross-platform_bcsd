
uchar * ssl_add_clienthello_tlsext(SSL *param_1,uchar *param_2,uchar *param_3)

{
  SSL_SESSION *pSVar1;
  ushort *puVar2;
  uchar *puVar3;
  size_t sVar4;
  uint uVar5;
  stack_st_SRTP_PROTECTION_PROFILE *psVar6;
  int iVar7;
  uchar *puVar8;
  void *pvVar9;
  int iVar10;
  OCSP_RESPID *pOVar11;
  uchar uVar12;
  int iVar13;
  int in_GS_OFFSET;
  int local_34;
  uchar *local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = param_2;
  if ((param_1->first_packet == 0x300) && (param_1->s3->send_connection_binding == 0))
  goto LAB_080ae782;
  local_28 = param_2 + 2;
  puVar8 = local_28;
  if (param_3 <= local_28) goto LAB_080ae780;
  if ((char *)param_1->tlsext_debug_arg != (char *)0x0) {
    iVar7 = -9 - (int)local_28;
    if (((int)(param_3 + iVar7) < 0) ||
       (puVar3 = (uchar *)strlen((char *)param_1->tlsext_debug_arg), puVar8 = local_28,
       param_3 + iVar7 < puVar3)) goto LAB_080ae780;
    puVar8 = param_2 + 0xb;
    uVar12 = (uchar)puVar3;
    param_2[10] = uVar12;
    param_2[2] = '\0';
    param_2[3] = '\0';
    param_2[4] = (uchar)((uint)(puVar3 + 5) >> 8);
    param_2[8] = '\0';
    param_2[5] = uVar12 + '\x05';
    param_2[6] = (uchar)((uint)(puVar3 + 3) >> 8);
    param_2[7] = uVar12 + '\x03';
    param_2[9] = (uchar)((uint)puVar3 >> 8);
    local_28 = puVar8;
    memcpy(puVar8,param_1->tlsext_debug_arg,(size_t)puVar3);
    local_28 = puVar8 + (int)puVar3;
  }
  if (param_1->tlsext_hb_seq == 0) {
LAB_080ae266:
    puVar3 = local_28;
    if (param_1[1].rbio != (BIO *)0x0) {
      sVar4 = strlen((char *)param_1[1].rbio);
      if ((0xff < (int)sVar4) || (sVar4 == 0)) {
        iVar7 = 0x1b2;
        goto LAB_080ae760;
      }
      puVar8 = local_28;
      if ((int)(param_3 + ((-5 - (int)puVar3) - sVar4)) < 0) goto LAB_080ae780;
      *puVar3 = '\0';
      local_28[1] = '\f';
      local_28[2] = (uchar)(sVar4 + 1 >> 8);
      local_28[3] = (uchar)sVar4 + '\x01';
      puVar8 = local_28 + 5;
      local_28[4] = (uchar)sVar4;
      local_28 = puVar8;
      memcpy(puVar8,param_1[1].rbio,sVar4);
      local_28 = local_28 + sVar4;
    }
    if (param_1->tlsext_ecpointformatlist_length == 0) {
LAB_080ae3b5:
      if ((param_1->tlsext_ellipticcurvelist_length != 0) && (param_1->version != 0xfeff)) {
        puVar8 = local_28;
        if (((int)(param_3 + (-6 - (int)local_28)) < 0) ||
           (param_3 + (-6 - (int)local_28) < param_1->tlsext_ecpointformatlist)) goto LAB_080ae780;
        if ((uchar *)0xfffc < param_1->tlsext_ecpointformatlist) {
          iVar7 = 0x1e5;
          goto LAB_080ae760;
        }
        *local_28 = '\0';
        local_28[1] = '\n';
        local_28[2] = (uchar)((uint)(param_1->tlsext_ecpointformatlist + 2) >> 8);
        local_28[3] = *(char *)&param_1->tlsext_ecpointformatlist + '\x02';
        local_28[4] = (uchar)((uint)param_1->tlsext_ecpointformatlist >> 8);
        local_28[5] = (uchar)param_1->tlsext_ecpointformatlist;
        local_28 = local_28 + 6;
        memcpy(local_28,(void *)param_1->tlsext_ellipticcurvelist_length,
               (size_t)param_1->tlsext_ecpointformatlist);
        local_28 = local_28 + (int)param_1->tlsext_ecpointformatlist;
      }
    }
    else if (param_1->version != 0xfeff) {
      puVar8 = local_28;
      if (((int)(param_3 + (-5 - (int)local_28)) < 0) ||
         (param_3 + (-5 - (int)local_28) < (uchar *)param_1->tlsext_ticket_expected))
      goto LAB_080ae780;
      if ((uchar *)0xff < (uchar *)param_1->tlsext_ticket_expected) {
        iVar7 = 0x1d1;
        goto LAB_080ae760;
      }
      *local_28 = '\0';
      local_28[1] = '\v';
      local_28[2] = (uchar)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
      local_28[3] = *(char *)&param_1->tlsext_ticket_expected + '\x01';
      puVar8 = local_28 + 5;
      local_28[4] = (uchar)param_1->tlsext_ticket_expected;
      local_28 = puVar8;
      memcpy(puVar8,(void *)param_1->tlsext_ecpointformatlist_length,param_1->tlsext_ticket_expected
            );
      local_28 = local_28 + param_1->tlsext_ticket_expected;
      goto LAB_080ae3b5;
    }
    uVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar5 & 0x4000) == 0) {
      pSVar1 = param_1->session;
      if (param_1->new_session == 0) {
        if (pSVar1 == (SSL_SESSION *)0x0) {
LAB_080aea80:
          if ((param_1->tlsext_opaque_prf_input_len != 0) &&
             (*(int *)(param_1->tlsext_opaque_prf_input_len + 4) == 0)) goto LAB_080ae538;
          goto LAB_080aea95;
        }
        if (*(int *)(pSVar1->krb5_client_princ + 0x54) == 0) goto LAB_080ae868;
        sVar4 = *(size_t *)(pSVar1->krb5_client_princ + 0x58);
LAB_080ae4c4:
        if (sVar4 == 0) goto LAB_080aea80;
      }
      else {
        if (pSVar1 == (SSL_SESSION *)0x0) goto LAB_080aea80;
LAB_080ae868:
        puVar2 = (ushort *)param_1->tlsext_opaque_prf_input_len;
        if (puVar2 != (ushort *)0x0) {
          if (*(int *)(puVar2 + 2) != 0) {
            sVar4 = (size_t)*puVar2;
            pvVar9 = CRYPTO_malloc(sVar4,"t1_lib.c",0x200);
            *(void **)(pSVar1->krb5_client_princ + 0x54) = pvVar9;
            pvVar9 = *(void **)(param_1->session->krb5_client_princ + 0x54);
            puVar8 = local_28;
            if (pvVar9 == (void *)0x0) goto LAB_080ae780;
            memcpy(pvVar9,*(void **)(param_1->tlsext_opaque_prf_input_len + 4),sVar4);
            *(size_t *)(param_1->session->krb5_client_princ + 0x58) = sVar4;
            goto LAB_080ae4c4;
          }
          goto LAB_080ae538;
        }
LAB_080aea95:
        sVar4 = 0;
      }
      puVar8 = local_28;
      if ((int)(param_3 + ((-4 - (int)local_28) - sVar4)) < 0) goto LAB_080ae780;
      *local_28 = '\0';
      local_28[1] = '#';
      local_28[2] = (uchar)(sVar4 >> 8);
      local_28[3] = (uchar)sVar4;
      local_28 = local_28 + 4;
      if (sVar4 != 0) {
        memcpy(local_28,*(void **)(param_1->session->krb5_client_princ + 0x54),sVar4);
        local_28 = local_28 + sVar4;
      }
    }
LAB_080ae538:
    if ((param_1->first_packet >> 8 == 3) && (0x302 < param_1->first_packet)) {
      puVar8 = local_28;
      if ((uint)((int)param_3 - (int)local_28) < 0x24) goto LAB_080ae780;
      *local_28 = '\0';
      local_28[1] = '\r';
      local_28[2] = '\0';
      local_28[3] = ' ';
      local_28[4] = '\0';
      local_28[5] = '\x1e';
      *(undefined4 *)(local_28 + 6) = tls12_sigalgs._0_4_;
      *(undefined4 *)(local_28 + 10) = tls12_sigalgs._4_4_;
      *(undefined4 *)(local_28 + 0xe) = tls12_sigalgs._8_4_;
      *(undefined4 *)(local_28 + 0x12) = tls12_sigalgs._12_4_;
      *(undefined4 *)(local_28 + 0x16) = tls12_sigalgs._16_4_;
      *(undefined4 *)(local_28 + 0x1a) = tls12_sigalgs._20_4_;
      *(undefined4 *)(local_28 + 0x1e) = tls12_sigalgs._24_4_;
      *(undefined2 *)(local_28 + 0x22) = tls12_sigalgs._28_2_;
      local_28 = local_28 + 0x24;
    }
    if ((param_1->servername_done != 1) || (param_1->version == 0xfeff)) {
LAB_080ae611:
      *local_28 = '\0';
      local_28[1] = '\x0f';
      local_28[2] = '\0';
      local_28[3] = '\x01';
      puVar8 = local_28 + 5;
      if ((*(byte *)&param_1->srtp_profile & 4) == 0) {
        local_28[4] = '\x01';
      }
      else {
        local_28[4] = '\x02';
      }
      if ((*(int *)(param_1->psk_server_callback + 0x1ac) != 0) &&
         ((param_1->s3->tmp).finish_md_len == 0)) {
        if ((int)param_3 - (int)puVar8 < 4) goto LAB_080ae780;
        *puVar8 = '3';
        local_28[6] = 't';
        local_28[7] = '\0';
        local_28[8] = '\0';
        puVar8 = local_28 + 9;
      }
      local_28 = puVar8;
      psVar6 = SSL_get_srtp_profiles(param_1);
      puVar8 = local_28;
      if (psVar6 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0) {
        ssl_add_clienthello_use_srtp_ext(param_1,0,&local_24,0);
        puVar8 = local_28;
        if ((int)(param_3 + ((-4 - (int)param_2) - local_24)) < 0) goto LAB_080ae780;
        *local_28 = '\0';
        local_28[1] = '\x0e';
        local_28[2] = (uchar)((uint)local_24 >> 8);
        local_28[3] = (uchar)local_24;
        local_28 = local_28 + 4;
        iVar7 = ssl_add_clienthello_use_srtp_ext(param_1,local_28,&local_24,local_24);
        if (iVar7 != 0) {
          iVar7 = 0x292;
          goto LAB_080ae760;
        }
        puVar8 = local_28 + local_24;
      }
      puVar3 = puVar8 + (-2 - (int)param_2);
      if (puVar3 != (uchar *)0x0) {
        param_2[1] = (uchar)puVar3;
        *param_2 = (uchar)((uint)puVar3 >> 8);
        param_2 = puVar8;
      }
      goto LAB_080ae782;
    }
    iVar7 = 0;
    for (iVar13 = 0; iVar10 = sk_num((_STACK *)param_1->tlsext_status_expected), iVar13 < iVar10;
        iVar13 = iVar13 + 1) {
      pOVar11 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar13);
      iVar10 = i2d_OCSP_RESPID(pOVar11,(uchar **)0x0);
      puVar8 = local_28;
      if (iVar10 < 1) goto LAB_080ae780;
      iVar7 = iVar7 + 2 + iVar10;
    }
    if ((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids == (X509_EXTENSIONS *)0x0) {
      local_34 = 0;
    }
    else {
      local_34 = i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,(uchar **)0x0);
      puVar8 = local_28;
      if (local_34 < 0) goto LAB_080ae780;
    }
    puVar8 = local_28;
    if (-1 < (int)(param_3 + (((-7 - (int)local_28) - local_34) - iVar7))) {
      *local_28 = '\0';
      local_28[1] = '\x05';
      puVar8 = local_28 + 2;
      if (local_34 + iVar7 < 0xfff1) {
        local_28[2] = (uchar)((uint)(local_34 + iVar7 + 5) >> 8);
        local_28[3] = (uchar)iVar7 + '\x05' + (uchar)local_34;
        local_28[4] = '\x01';
        local_28[5] = (uchar)((uint)iVar7 >> 8);
        local_28[6] = (uchar)iVar7;
        local_28 = local_28 + 7;
        for (iVar7 = 0; iVar13 = sk_num((_STACK *)param_1->tlsext_status_expected),
            puVar8 = local_28, iVar7 < iVar13; iVar7 = iVar7 + 1) {
          pOVar11 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar7);
          local_28 = local_28 + 2;
          iVar13 = i2d_OCSP_RESPID(pOVar11,&local_28);
          puVar8[1] = (uchar)iVar13;
          *puVar8 = (uchar)((uint)iVar13 >> 8);
        }
        *local_28 = (uchar)((uint)local_34 >> 8);
        local_28[1] = (uchar)local_34;
        local_28 = local_28 + 2;
        if (local_34 != 0) {
          i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,&local_28);
        }
        goto LAB_080ae611;
      }
    }
  }
  else {
    iVar7 = ssl_add_clienthello_renegotiate_ext(param_1,0,&local_24,0);
    if (iVar7 == 0) {
      iVar7 = 0x198;
    }
    else {
      puVar8 = local_28;
      if ((int)(param_3 + ((-4 - (int)param_2) - local_24)) < 0) goto LAB_080ae780;
      *local_28 = 0xff;
      local_28[1] = '\x01';
      local_28[2] = (uchar)((uint)local_24 >> 8);
      local_28[3] = (uchar)local_24;
      local_28 = local_28 + 4;
      iVar7 = ssl_add_clienthello_renegotiate_ext(param_1,local_28,&local_24,local_24);
      if (iVar7 != 0) {
        local_28 = local_28 + local_24;
        goto LAB_080ae266;
      }
      iVar7 = 0x1a3;
    }
LAB_080ae760:
    ERR_put_error(0x14,0x115,0x44,"t1_lib.c",iVar7);
    puVar8 = local_28;
  }
LAB_080ae780:
  local_28 = puVar8;
  param_2 = (uchar *)0x0;
LAB_080ae782:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}

