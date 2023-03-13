
uchar * ssl_add_clienthello_tlsext(SSL *param_1,uchar *param_2,uchar *param_3)

{
  SSL_SESSION *pSVar1;
  ushort *puVar2;
  uchar *puVar3;
  size_t sVar4;
  uint uVar5;
  void *pvVar6;
  int iVar7;
  OCSP_RESPID *pOVar8;
  stack_st_SRTP_PROTECTION_PROFILE *psVar9;
  uint uVar10;
  int iVar11;
  uchar uVar12;
  uchar *puVar13;
  int iVar14;
  undefined4 *puVar15;
  int in_GS_OFFSET;
  byte bVar16;
  int local_34;
  uchar *local_28;
  int local_24;
  int local_20;
  
  bVar16 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = param_2;
  if ((param_1->first_packet == 0x300) && (param_1->s3->send_connection_binding == 0))
  goto LAB_080aafc2;
  puVar13 = param_2 + 2;
  if (param_3 <= puVar13) goto LAB_080aafc0;
  if ((char *)param_1->tlsext_debug_arg != (char *)0x0) {
    if (((int)(param_3 + (-9 - (int)puVar13)) < 0) ||
       (local_28 = puVar13, puVar3 = (uchar *)strlen((char *)param_1->tlsext_debug_arg),
       puVar13 = local_28, param_3 + (-9 - (int)puVar13) < puVar3)) goto LAB_080aafc0;
    local_28 = param_2 + 0xb;
    param_2[2] = '\0';
    param_2[3] = '\0';
    param_2[8] = '\0';
    param_2[4] = (uchar)((uint)(puVar3 + 5) >> 8);
    uVar12 = (uchar)puVar3;
    param_2[5] = uVar12 + '\x05';
    param_2[6] = (uchar)((uint)(puVar3 + 3) >> 8);
    param_2[7] = uVar12 + '\x03';
    param_2[9] = (uchar)((uint)puVar3 >> 8);
    param_2[10] = uVar12;
    puVar13 = local_28 + (int)puVar3;
    memcpy(local_28,param_1->tlsext_debug_arg,(size_t)puVar3);
  }
  local_28 = puVar13;
  if (param_1->tlsext_hb_seq == 0) {
LAB_080aaaac:
    puVar3 = local_28;
    if (param_1[1].rbio != (BIO *)0x0) {
      sVar4 = strlen((char *)param_1[1].rbio);
      if ((0xff < (int)sVar4) || (sVar4 == 0)) {
        iVar11 = 0x1be;
        goto LAB_080aafa0;
      }
      puVar13 = local_28;
      if ((int)(param_3 + ((-5 - (int)puVar3) - sVar4)) < 0) goto LAB_080aafc0;
      *puVar3 = '\0';
      local_28[1] = '\f';
      local_28[2] = (uchar)(sVar4 + 1 >> 8);
      local_28[3] = (uchar)sVar4 + '\x01';
      puVar13 = local_28 + 5;
      local_28[4] = (uchar)sVar4;
      local_28 = puVar13;
      memcpy(puVar13,param_1[1].rbio,sVar4);
      local_28 = local_28 + sVar4;
    }
    if (param_1->tlsext_ecpointformatlist_length != 0) {
      puVar13 = local_28;
      if (((int)(param_3 + (-5 - (int)local_28)) < 0) ||
         (param_3 + (-5 - (int)local_28) < (uchar *)param_1->tlsext_ticket_expected))
      goto LAB_080aafc0;
      if ((uchar *)0xff < (uchar *)param_1->tlsext_ticket_expected) {
        iVar11 = 0x1e0;
        goto LAB_080aafa0;
      }
      *local_28 = '\0';
      local_28[1] = '\v';
      local_28[2] = (uchar)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
      local_28[3] = *(char *)&param_1->tlsext_ticket_expected + '\x01';
      puVar13 = local_28 + 5;
      local_28[4] = (uchar)param_1->tlsext_ticket_expected;
      local_28 = puVar13;
      memcpy(puVar13,(void *)param_1->tlsext_ecpointformatlist_length,
             param_1->tlsext_ticket_expected);
      local_28 = local_28 + param_1->tlsext_ticket_expected;
    }
    if (param_1->tlsext_ellipticcurvelist_length != 0) {
      puVar13 = local_28;
      if (((int)(param_3 + (-6 - (int)local_28)) < 0) ||
         (param_3 + (-6 - (int)local_28) < param_1->tlsext_ecpointformatlist)) goto LAB_080aafc0;
      if ((uchar *)0xfffc < param_1->tlsext_ecpointformatlist) {
        iVar11 = 0x1f6;
        goto LAB_080aafa0;
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
    uVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar5 & 0x4000) == 0) {
      pSVar1 = param_1->session;
      if (param_1->new_session == 0) {
        if (pSVar1 == (SSL_SESSION *)0x0) {
LAB_080ab2c0:
          if ((param_1->tlsext_opaque_prf_input_len != 0) &&
             (*(int *)(param_1->tlsext_opaque_prf_input_len + 4) == 0)) goto LAB_080aad49;
          goto LAB_080ab2d5;
        }
        if (*(int *)(pSVar1->krb5_client_princ + 0x54) == 0) goto LAB_080ab0a8;
        sVar4 = *(size_t *)(pSVar1->krb5_client_princ + 0x58);
LAB_080aacf2:
        if (sVar4 == 0) goto LAB_080ab2c0;
      }
      else {
        if (pSVar1 == (SSL_SESSION *)0x0) goto LAB_080ab2c0;
LAB_080ab0a8:
        puVar2 = (ushort *)param_1->tlsext_opaque_prf_input_len;
        if (puVar2 != (ushort *)0x0) {
          if (*(int *)(puVar2 + 2) != 0) {
            sVar4 = (size_t)*puVar2;
            pvVar6 = CRYPTO_malloc(sVar4,"t1_lib.c",0x20b);
            *(void **)(pSVar1->krb5_client_princ + 0x54) = pvVar6;
            pvVar6 = *(void **)(param_1->session->krb5_client_princ + 0x54);
            puVar13 = local_28;
            if (pvVar6 == (void *)0x0) goto LAB_080aafc0;
            memcpy(pvVar6,*(void **)(param_1->tlsext_opaque_prf_input_len + 4),sVar4);
            *(size_t *)(param_1->session->krb5_client_princ + 0x58) = sVar4;
            goto LAB_080aacf2;
          }
          goto LAB_080aad49;
        }
LAB_080ab2d5:
        sVar4 = 0;
      }
      puVar13 = local_28;
      if ((int)(param_3 + ((-4 - (int)local_28) - sVar4)) < 0) goto LAB_080aafc0;
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
LAB_080aad49:
    if ((param_1->first_packet >> 8 == 3) && (0x302 < param_1->first_packet)) {
      puVar13 = local_28;
      if ((uint)((int)param_3 - (int)local_28) < 0x24) goto LAB_080aafc0;
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
    if ((param_1->servername_done == 1) && (param_1->version != 0xfeff)) {
      iVar11 = 0;
      for (iVar14 = 0; iVar7 = sk_num((_STACK *)param_1->tlsext_status_expected), iVar14 < iVar7;
          iVar14 = iVar14 + 1) {
        pOVar8 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar14);
        iVar7 = i2d_OCSP_RESPID(pOVar8,(uchar **)0x0);
        puVar13 = local_28;
        if (iVar7 < 1) goto LAB_080aafc0;
        iVar11 = iVar11 + 2 + iVar7;
      }
      if ((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids == (X509_EXTENSIONS *)0x0) {
        local_34 = 0;
      }
      else {
        local_34 = i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,(uchar **)0x0);
        puVar13 = local_28;
        if (local_34 < 0) goto LAB_080aafc0;
      }
      puVar13 = local_28;
      if (-1 < (int)(param_3 + (((-7 - (int)local_28) - local_34) - iVar11))) {
        *local_28 = '\0';
        local_28[1] = '\x05';
        puVar13 = local_28 + 2;
        if (local_34 + iVar11 < 0xfff1) {
          local_28[2] = (uchar)((uint)(local_34 + iVar11 + 5) >> 8);
          local_28[3] = (uchar)iVar11 + '\x05' + (uchar)local_34;
          local_28[4] = '\x01';
          local_28[5] = (uchar)((uint)iVar11 >> 8);
          local_28[6] = (uchar)iVar11;
          local_28 = local_28 + 7;
          for (iVar11 = 0; iVar14 = sk_num((_STACK *)param_1->tlsext_status_expected),
              puVar13 = local_28, iVar11 < iVar14; iVar11 = iVar11 + 1) {
            pOVar8 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar11);
            local_28 = local_28 + 2;
            iVar14 = i2d_OCSP_RESPID(pOVar8,&local_28);
            puVar13[1] = (uchar)iVar14;
            *puVar13 = (uchar)((uint)iVar14 >> 8);
          }
          *local_28 = (uchar)((uint)local_34 >> 8);
          local_28[1] = (uchar)local_34;
          local_28 = local_28 + 2;
          if (local_34 != 0) {
            i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,&local_28);
          }
          goto LAB_080aae21;
        }
      }
    }
    else {
LAB_080aae21:
      puVar13 = local_28;
      if (4 < (int)param_3 - (int)local_28) {
        *local_28 = '\0';
        local_28[1] = '\x0f';
        local_28[2] = '\0';
        local_28[3] = '\x01';
        puVar13 = local_28 + 5;
        if ((*(byte *)&param_1->srtp_profile & 4) == 0) {
          local_28[4] = '\x01';
        }
        else {
          local_28[4] = '\x02';
        }
        if ((*(int *)(param_1->psk_server_callback + 0x1ac) != 0) &&
           ((param_1->s3->tmp).finish_md_len == 0)) {
          if ((int)param_3 - (int)puVar13 < 4) goto LAB_080aafc0;
          *puVar13 = '3';
          local_28[6] = 't';
          local_28[7] = '\0';
          local_28[8] = '\0';
          puVar13 = local_28 + 9;
        }
        local_28 = puVar13;
        if ((param_1->method->version == 0xfeff) &&
           (psVar9 = SSL_get_srtp_profiles(param_1),
           psVar9 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) {
          ssl_add_clienthello_use_srtp_ext(param_1,0,&local_24,0);
          puVar13 = local_28;
          if ((int)(param_3 + ((-4 - (int)local_28) - local_24)) < 0) goto LAB_080aafc0;
          *local_28 = '\0';
          local_28[1] = '\x0e';
          local_28[2] = (uchar)((uint)local_24 >> 8);
          local_28[3] = (uchar)local_24;
          local_28 = local_28 + 4;
          iVar11 = ssl_add_clienthello_use_srtp_ext(param_1,local_28,&local_24,local_24);
          if (iVar11 != 0) {
            iVar11 = 0x296;
            goto LAB_080aafa0;
          }
          local_28 = local_28 + local_24;
        }
        puVar13 = local_28;
        if ((*(byte *)&param_1->references & 0x10) != 0) {
          iVar11 = (int)local_28 - (int)param_1->init_buf->data;
          if (param_1->state == 0x1210) {
            iVar11 = iVar11 + -5;
          }
          if (iVar11 - 0x100U < 0x100) {
            if (0x200 - iVar11 < 4) {
              uVar5 = 0;
              uVar12 = '\0';
            }
            else {
              uVar5 = 0x1fc - iVar11;
              uVar12 = (uchar)(uVar5 >> 8);
            }
            *local_28 = '\0';
            local_28[1] = '\x15';
            local_28[2] = uVar12;
            local_28[3] = (uchar)uVar5;
            puVar3 = local_28 + 4;
            if (uVar5 < 4) {
              if ((uVar5 != 0) && (*puVar3 = '\0', (uVar5 & 2) != 0)) {
                *(undefined2 *)(local_28 + uVar5 + 2) = 0;
              }
            }
            else {
              *(undefined4 *)(local_28 + 4) = 0;
              *(undefined4 *)(local_28 + uVar5) = 0;
              puVar15 = (undefined4 *)((uint)(local_28 + 8) & 0xfffffffc);
              for (uVar10 = (uint)(puVar3 + (uVar5 - (int)(undefined4 *)
                                                          ((uint)(local_28 + 8) & 0xfffffffc))) >> 2
                  ; uVar10 != 0; uVar10 = uVar10 - 1) {
                *puVar15 = 0;
                puVar15 = puVar15 + (uint)bVar16 * -2 + 1;
              }
            }
            puVar13 = puVar3 + uVar5;
            local_28 = puVar3;
          }
        }
        puVar3 = puVar13 + (-2 - (int)param_2);
        if (puVar3 != (uchar *)0x0) {
          param_2[1] = (uchar)puVar3;
          *param_2 = (uchar)((uint)puVar3 >> 8);
          param_2 = puVar13;
        }
        goto LAB_080aafc2;
      }
    }
  }
  else {
    iVar11 = ssl_add_clienthello_renegotiate_ext(param_1,0,&local_24,0);
    if (iVar11 == 0) {
      iVar11 = 0x1a6;
    }
    else {
      puVar13 = local_28;
      if ((int)(param_3 + ((-4 - (int)local_28) - local_24)) < 0) goto LAB_080aafc0;
      *local_28 = 0xff;
      local_28[1] = '\x01';
      local_28[2] = (uchar)((uint)local_24 >> 8);
      local_28[3] = (uchar)local_24;
      local_28 = local_28 + 4;
      iVar11 = ssl_add_clienthello_renegotiate_ext(param_1,local_28,&local_24,local_24);
      if (iVar11 != 0) {
        local_28 = local_28 + local_24;
        goto LAB_080aaaac;
      }
      iVar11 = 0x1b1;
    }
LAB_080aafa0:
    ERR_put_error(0x14,0x115,0x44,"t1_lib.c",iVar11);
    puVar13 = local_28;
  }
LAB_080aafc0:
  local_28 = puVar13;
  param_2 = (uchar *)0x0;
LAB_080aafc2:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}

