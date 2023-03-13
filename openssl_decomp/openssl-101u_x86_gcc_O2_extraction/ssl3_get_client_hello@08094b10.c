
long ssl3_get_client_hello(SSL *param_1)

{
  code *pcVar1;
  dtls1_state_st *pdVar2;
  bool bVar3;
  ushort uVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  void *pvVar9;
  int iVar10;
  _STACK *p_Var11;
  ssl3_state_st *psVar12;
  uchar *puVar13;
  uchar *puVar14;
  uchar *puVar15;
  SSL_CIPHER *pSVar16;
  SSL_CIPHER *pSVar17;
  uchar *extraout_ECX;
  SSL_SESSION *pSVar18;
  undefined4 *puVar19;
  tls_session_secret_cb_fn ptVar20;
  long lVar21;
  undefined4 *puVar22;
  SSL_CIPHER *pSVar23;
  int in_GS_OFFSET;
  byte bVar24;
  int iVar25;
  tls_session_secret_cb_fn ptVar26;
  uchar *puVar27;
  uint local_4c;
  SSL_COMP *local_44;
  int local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  _STACK *local_28;
  int local_24;
  int local_20;
  
  bVar24 = 0;
  local_28 = (_STACK *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1->state == 0x2110) {
    param_1->state = 0x2111;
  }
  param_1->max_cert_list = 1;
  lVar5 = (*param_1->method->ssl_get_message)(param_1,0x2111,0x2112,1,0x4000,&local_34);
  lVar21 = lVar5;
  if (local_34 == 0) goto LAB_08094c32;
  puVar19 = (undefined4 *)param_1->init_msg;
  param_1->max_cert_list = 0;
  if (lVar5 < 0x23) {
    iVar7 = 0x3ef;
    local_2c = puVar19;
    goto LAB_08094dc8;
  }
  local_2c = (undefined4 *)((int)puVar19 + 2);
  uVar4 = *(ushort *)puVar19 << 8 | *(ushort *)puVar19 >> 8;
  param_1->first_packet = (uint)uVar4;
  if (param_1->version != 0xfeff) {
    if (param_1->version <= (int)(uint)uVar4) goto LAB_08094c5a;
LAB_08094bc1:
    ERR_put_error(0x14,0x8a,0x10b,"s3_srvr.c",0x3fc);
    if (((param_1->first_packet >> 8 == 3) && (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) &&
       (param_1->write_hash == (EVP_MD_CTX *)0x0)) {
      param_1->version = param_1->first_packet;
    }
    local_30 = 0x46;
LAB_08094c03:
    ssl3_send_alert(param_1,2,local_30);
    goto LAB_08094c12;
  }
  if (0xfeff < uVar4) goto LAB_08094bc1;
LAB_08094c5a:
  uVar6 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if ((uVar6 & 0x2000) != 0) {
    if ((byte *)((int)puVar19 + (lVar5 - (int)local_2c)) <= (byte *)(*(byte *)(local_2c + 8) + 0x21)
       ) {
      iVar7 = 0x415;
      goto LAB_08094dc8;
    }
    lVar21 = 1;
    if (*(byte *)((int)local_2c + *(byte *)(local_2c + 8) + 0x21) == 0) goto LAB_08094c32;
  }
  puVar19 = (undefined4 *)(lVar5 + (int)puVar19);
  psVar12 = param_1->s3;
  *(undefined4 *)psVar12->client_random = *local_2c;
  *(undefined4 *)(psVar12->client_random + 4) = local_2c[1];
  *(undefined4 *)(psVar12->client_random + 8) = local_2c[2];
  *(undefined4 *)(psVar12->client_random + 0xc) = local_2c[3];
  *(undefined4 *)(psVar12->client_random + 0x10) = local_2c[4];
  *(undefined4 *)(psVar12->client_random + 0x14) = local_2c[5];
  *(undefined4 *)(psVar12->client_random + 0x18) = local_2c[6];
  *(undefined4 *)(psVar12->client_random + 0x1c) = local_2c[7];
  puVar22 = local_2c + 8;
  uVar6 = (uint)*(byte *)puVar22;
  local_2c = (undefined4 *)((int)local_2c + 0x21);
  if ((int)puVar19 - (int)local_2c < (int)uVar6) {
    iVar7 = 0x427;
    goto LAB_08094dc8;
  }
  if (0x20 < *(byte *)puVar22) {
    local_30 = 0x32;
    iVar7 = 0x42d;
    iVar25 = 0x9f;
    goto LAB_08094dd2;
  }
  param_1->hit = 0;
  if ((param_1->new_session == 0) || ((*(byte *)((int)&param_1->references + 2) & 1) == 0)) {
    iVar7 = ssl_get_prev_session(param_1,local_2c,uVar6,puVar19);
    if (iVar7 == 1) {
      iVar7 = param_1->version;
      if (iVar7 != param_1->session->ssl_version) goto LAB_08094d15;
      param_1->hit = 1;
      goto LAB_08094d2e;
    }
    if (iVar7 != -1) goto LAB_08094d15;
LAB_08094c12:
    param_1->state = 5;
    lVar21 = -1;
  }
  else {
LAB_08094d15:
    iVar7 = ssl_get_new_session(param_1,1);
    if (iVar7 == 0) goto LAB_08094c12;
    iVar7 = param_1->version;
LAB_08094d2e:
    puVar22 = (undefined4 *)(uVar6 + (int)local_2c);
    if ((iVar7 == 0xfeff) || (bVar3 = false, iVar7 == 0x100)) {
      if (puVar19 == puVar22 || (int)puVar19 - (int)puVar22 < 0) {
        iVar7 = 0x45f;
        local_2c = puVar22;
      }
      else {
        local_2c = (undefined4 *)((int)puVar22 + 1);
        uVar6 = (uint)*(byte *)puVar22;
        if (uVar6 <= (uint)((int)puVar19 - (int)local_2c)) {
          uVar8 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
          if (((uVar8 & 0x2000) == 0) || (uVar6 == 0)) {
            bVar3 = false;
LAB_08094f18:
            puVar22 = (undefined4 *)((int)local_2c + uVar6);
            goto LAB_08094d54;
          }
          local_44 = (SSL_COMP *)local_2c;
          puVar22 = local_2c;
          puVar15 = param_1->d1->rcvd_cookie;
          for (uVar8 = uVar6; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar15 = *(byte *)puVar22;
            puVar22 = (undefined4 *)((int)puVar22 + (uint)bVar24 * -2 + 1);
            puVar15 = puVar15 + (uint)bVar24 * -2 + 1;
          }
          if (*(code **)(param_1->psk_server_callback + 0x7c) == (code *)0x0) {
            pdVar2 = param_1->d1;
            iVar7 = memcmp(pdVar2->rcvd_cookie,pdVar2->cookie,pdVar2->cookie_len);
            if (iVar7 == 0) goto LAB_08095342;
            local_30 = 0x28;
            iVar7 = 0x488;
            iVar25 = 0x134;
          }
          else {
            iVar7 = (**(code **)(param_1->psk_server_callback + 0x7c))
                              (param_1,param_1->d1->rcvd_cookie,uVar6,puVar22);
            if (iVar7 != 0) {
              local_44 = (SSL_COMP *)local_2c;
LAB_08095342:
              bVar3 = true;
              local_2c = &local_44->id;
              goto LAB_08094f18;
            }
            local_30 = 0x28;
            iVar7 = 0x47f;
            iVar25 = 0x134;
          }
          goto LAB_08094dd2;
        }
        iVar7 = 0x466;
      }
LAB_08094dc8:
      local_30 = 0x32;
      iVar25 = 0xa0;
LAB_08094dd2:
      ERR_put_error(0x14,0x8a,iVar25,"s3_srvr.c",iVar7);
      goto LAB_08094c03;
    }
LAB_08094d54:
    if ((int)puVar19 - (int)puVar22 < 2) {
      iVar7 = 0x493;
      local_2c = puVar22;
      goto LAB_08094dc8;
    }
    local_2c = (undefined4 *)((int)puVar22 + 2);
    uVar4 = *(ushort *)puVar22 << 8 | *(ushort *)puVar22 >> 8;
    uVar6 = (uint)uVar4;
    if (uVar4 == 0) {
      local_30 = 0x2f;
      iVar7 = 0x49a;
      iVar25 = 0xb7;
      goto LAB_08094dd2;
    }
    if ((int)puVar19 - (int)local_2c <= (int)uVar6) {
      local_30 = 0x32;
      iVar7 = 0x4a2;
      iVar25 = 0x9f;
      goto LAB_08094dd2;
    }
    iVar7 = ssl_bytes_to_cipher_list(param_1,local_2c,uVar6,&local_28);
    if (iVar7 == 0) goto LAB_08094c12;
    local_2c = (undefined4 *)(uVar6 + (int)local_2c);
    puVar22 = local_2c;
    if (param_1->hit != 0) {
      iVar7 = *(int *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 8);
      for (iVar25 = 0; iVar10 = sk_num(local_28), iVar25 < iVar10; iVar25 = iVar25 + 1) {
        pvVar9 = sk_value(local_28,iVar25);
        puVar22 = local_2c;
        if (iVar7 == *(int *)((int)pvVar9 + 8)) goto LAB_08094fd5;
      }
      local_30 = 0x2f;
      iVar7 = 0x4da;
      iVar25 = 0xd7;
      goto LAB_08094dd2;
    }
LAB_08094fd5:
    local_2c = (undefined4 *)((int)puVar22 + 1);
    uVar6 = (uint)*(byte *)puVar22;
    if ((int)puVar19 - (int)local_2c < (int)uVar6) {
      local_30 = 0x32;
      iVar7 = 0x4e4;
      iVar25 = 0x9f;
      goto LAB_08094dd2;
    }
    if (uVar6 == 0) {
LAB_0809500e:
      local_2c = (undefined4 *)((int)local_2c + uVar6);
      local_30 = 0x32;
      iVar7 = 0x4f1;
      iVar25 = 0xbb;
      goto LAB_08094dd2;
    }
    if (*(byte *)((int)puVar22 + 1) != 0) {
      uVar8 = 0;
      do {
        if (uVar6 == uVar8 + 1) goto LAB_0809500e;
        iVar7 = uVar8 + 2;
        uVar8 = uVar8 + 1;
      } while (*(byte *)((int)puVar22 + iVar7) != 0);
    }
    local_2c = (undefined4 *)((int)local_2c + uVar6);
    if ((0x2ff < param_1->version) &&
       (iVar7 = ssl_parse_clienthello_tlsext(param_1,&local_2c,puVar19,&local_30), iVar7 == 0)) {
      iVar7 = 0x4f9;
      iVar25 = 0xe3;
      goto LAB_08094dd2;
    }
    iVar7 = ssl_check_clienthello_tlsext_early(param_1);
    if (iVar7 < 1) {
      iVar7 = 0x4fe;
LAB_08095360:
      ERR_put_error(0x14,0x8a,0xe2,"s3_srvr.c",iVar7);
      goto LAB_08094c12;
    }
    puVar27 = &DAT_00000020;
    puVar15 = param_1->s3->server_random;
    ptVar26 = (tls_session_secret_cb_fn)0x1;
    iVar7 = ssl_fill_hello_random(param_1,1,puVar15,0x20);
    if (iVar7 < 1) {
LAB_080952e0:
      local_30 = 0x50;
      goto LAB_08094c03;
    }
    if (((param_1->hit == 0) && (0x300 < param_1->version)) &&
       (pcVar1 = (code *)param_1->tls_session_ticket_ext_cb_arg, pcVar1 != (code *)0x0)) {
      pSVar18 = param_1->session;
      local_24 = 0;
      pSVar18->master_key_length = 0x30;
      ptVar26 = param_1->tls_session_secret_cb;
      puVar15 = extraout_ECX;
      puVar27 = extraout_ECX;
      iVar7 = (*pcVar1)(param_1,pSVar18->master_key,&pSVar18->master_key_length,local_28,&local_24,
                        ptVar26,extraout_ECX,extraout_ECX);
      p_Var11 = local_28;
      if (iVar7 != 0) {
        pSVar18 = param_1->session;
        param_1->hit = 1;
        local_28 = (_STACK *)0x0;
        *(_STACK **)(pSVar18->krb5_client_princ + 0x2c) = p_Var11;
        *(undefined4 *)(pSVar18->krb5_client_princ + 0x10) = 0;
        if (local_24 == 0) {
          puVar15 = (uchar *)SSL_get_ciphers(param_1);
          ptVar26 = *(tls_session_secret_cb_fn *)(param_1->session->krb5_client_princ + 0x2c);
          local_24 = ssl3_choose_cipher(param_1,ptVar26,puVar15);
          if (local_24 == 0) {
            local_30 = 0x28;
            iVar7 = 0x528;
            iVar25 = 0xc1;
            goto LAB_08094dd2;
          }
          pSVar18 = param_1->session;
        }
        *(int *)(pSVar18->krb5_client_princ + 0x24) = local_24;
        if ((_STACK *)param_1->cipher_list != (_STACK *)0x0) {
          sk_free((_STACK *)param_1->cipher_list);
        }
        if ((_STACK *)param_1->cipher_list_by_id != (_STACK *)0x0) {
          sk_free((_STACK *)param_1->cipher_list_by_id);
        }
        p_Var11 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
        param_1->cipher_list = (stack_st_SSL_CIPHER *)p_Var11;
        p_Var11 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
        param_1->cipher_list_by_id = (stack_st_SSL_CIPHER *)p_Var11;
      }
    }
    pSVar18 = param_1->session;
    (param_1->s3->tmp).new_compression = (SSL_COMP *)0x0;
    local_4c = *(uint *)(pSVar18->krb5_client_princ + 0x20);
    if (local_4c != 0) {
      if ((*(byte *)((int)&param_1->references + 2) & 2) == 0) {
        local_44 = (SSL_COMP *)0x0;
        for (ptVar20 = (tls_session_secret_cb_fn)0x0;
            iVar7 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98)), (int)ptVar20 < iVar7;
            ptVar20 = ptVar20 + 1) {
          ptVar26 = ptVar20;
          local_44 = (SSL_COMP *)
                     sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),(int)ptVar20);
          if (local_4c == local_44->id) {
            psVar12 = param_1->s3;
            (psVar12->tmp).new_compression = local_44;
            goto LAB_08095243;
          }
        }
        psVar12 = param_1->s3;
LAB_08095243:
        if ((psVar12->tmp).new_compression != (SSL_COMP *)0x0) {
          if (local_4c != *(byte *)((int)puVar22 + 1)) {
            uVar8 = 0;
            do {
              if (uVar6 == uVar8 + 1) {
                local_30 = 0x2f;
                iVar7 = 0x562;
                iVar25 = 0x156;
                goto LAB_08094dd2;
              }
              iVar7 = uVar8 + 2;
              uVar8 = uVar8 + 1;
            } while (local_4c != *(byte *)((int)puVar22 + iVar7));
          }
          pSVar18 = param_1->session;
          if (param_1->hit == 0) {
            local_4c = 0;
            if (local_44 != (SSL_COMP *)0x0) {
LAB_08095429:
              local_4c = local_44->id;
            }
            goto LAB_08095432;
          }
          goto LAB_080954f9;
        }
        local_30 = 0x50;
        iVar7 = 0x557;
        iVar25 = 0x155;
      }
      else {
        local_30 = 0x50;
        iVar7 = 0x549;
        iVar25 = 0x154;
      }
      goto LAB_08094dd2;
    }
    if (param_1->hit == 0) {
      if (((*(byte *)((int)&param_1->references + 2) & 2) == 0) &&
         (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
        puVar13 = (uchar *)sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
        puVar14 = puVar13;
        for (ptVar20 = (tls_session_secret_cb_fn)0x0; (int)ptVar20 < (int)puVar13;
            ptVar20 = ptVar20 + 1) {
          ptVar26 = ptVar20;
          puVar15 = puVar14;
          puVar27 = puVar14;
          local_44 = (SSL_COMP *)
                     sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),(int)ptVar20);
          if (local_44->id == (uint)*(byte *)((int)puVar22 + 1)) {
LAB_0809572d:
            iVar7 = param_1->hit;
            (param_1->s3->tmp).new_compression = local_44;
            if (iVar7 != 0) goto LAB_080954f3;
            pSVar18 = param_1->session;
            goto LAB_08095429;
          }
          puVar14 = (uchar *)0x0;
          while (puVar14 = puVar14 + 1, (int)puVar14 < (int)uVar6) {
            if (local_44->id == (uint)((byte *)((int)puVar22 + 1))[(int)puVar14]) goto LAB_0809572d;
          }
        }
        if (param_1->hit != 0) {
LAB_080954f3:
          pSVar18 = param_1->session;
          goto LAB_080954f9;
        }
        pSVar18 = param_1->session;
      }
LAB_08095432:
      *(uint *)(pSVar18->krb5_client_princ + 0x20) = local_4c;
      if (*(_STACK **)(pSVar18->krb5_client_princ + 0x2c) != (_STACK *)0x0) {
        sk_free(*(_STACK **)(pSVar18->krb5_client_princ + 0x2c));
        pSVar18 = param_1->session;
      }
      *(_STACK **)(pSVar18->krb5_client_princ + 0x2c) = local_28;
      if (local_28 == (_STACK *)0x0) {
        local_30 = 0x50;
        iVar7 = 0x598;
        iVar25 = 0x44;
      }
      else {
        local_28 = (_STACK *)0x0;
        puVar15 = (uchar *)SSL_get_ciphers(param_1);
        ptVar26 = *(tls_session_secret_cb_fn *)(param_1->session->krb5_client_princ + 0x2c);
        pSVar16 = (SSL_CIPHER *)ssl3_choose_cipher(param_1,ptVar26,puVar15);
        if (pSVar16 != (SSL_CIPHER *)0x0) {
          (param_1->s3->tmp).new_cipher = pSVar16;
          goto LAB_080954a4;
        }
        local_30 = 0x28;
        iVar7 = 0x5a0;
        iVar25 = 0xc1;
      }
      goto LAB_08094dd2;
    }
LAB_080954f9:
    if ((*(byte *)((int)&param_1->references + 3) & 0x40) == 0) {
      (param_1->s3->tmp).new_cipher = *(SSL_CIPHER **)(pSVar18->krb5_client_princ + 0x24);
    }
    else {
      p_Var11 = *(_STACK **)(pSVar18->krb5_client_princ + 0x2c);
      pSVar16 = (SSL_CIPHER *)0x0;
      pSVar23 = (SSL_CIPHER *)0x0;
      for (ptVar20 = (tls_session_secret_cb_fn)0x0; iVar7 = sk_num(p_Var11), (int)ptVar20 < iVar7;
          ptVar20 = ptVar20 + 1) {
        ptVar26 = ptVar20;
        pSVar17 = (SSL_CIPHER *)sk_value(p_Var11,(int)ptVar20);
        if ((*(byte *)&pSVar17->algorithm_enc & 0x20) != 0) {
          pSVar23 = pSVar17;
        }
        if ((*(byte *)&pSVar17->algo_strength & 2) != 0) {
          pSVar16 = pSVar17;
        }
      }
      psVar12 = param_1->s3;
      if (pSVar23 == (SSL_CIPHER *)0x0) {
        if (pSVar16 == (SSL_CIPHER *)0x0) {
          (psVar12->tmp).new_cipher = *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24);
        }
        else {
          (psVar12->tmp).new_cipher = pSVar16;
        }
      }
      else {
        (psVar12->tmp).new_cipher = pSVar23;
      }
    }
LAB_080954a4:
    if ((((param_1->version >> 8 != 3) || (param_1->version < 0x303)) ||
        ((*(byte *)&param_1->verify_mode & 1) == 0)) &&
       (iVar7 = ssl3_digest_cached_records(param_1,ptVar26,puVar15,puVar27), iVar7 == 0))
    goto LAB_080952e0;
    if ((0x2ff < param_1->version) &&
       (iVar7 = ssl_check_clienthello_tlsext_late(param_1), iVar7 < 1)) {
      iVar7 = 0x5d6;
      goto LAB_08095360;
    }
    lVar21 = 2 - (uint)!bVar3;
  }
  if (local_28 != (_STACK *)0x0) {
    sk_free(local_28);
  }
LAB_08094c32:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar21;
}

