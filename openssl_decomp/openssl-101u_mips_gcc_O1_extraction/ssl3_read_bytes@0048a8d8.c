
ssl3_state_st *
ssl3_read_bytes(SSL *param_1,int param_2,ssl3_state_st *param_3,ssl3_state_st *param_4,int param_5)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  ssl3_state_st *psVar4;
  int iVar5;
  uint uVar6;
  ssl3_enc_method *psVar7;
  uint uVar8;
  SSL_METHOD *pSVar9;
  BIO *pBVar10;
  SSL_SESSION *pSVar11;
  undefined4 uVar12;
  byte *pbVar13;
  uint uVar14;
  uchar uVar15;
  ssl3_state_st *psVar16;
  int iVar17;
  uchar *puVar18;
  ssl3_state_st *psVar19;
  undefined *puVar20;
  uchar *puVar21;
  uint *puVar22;
  ssl3_state_st *psVar23;
  uint uVar24;
  int iVar25;
  undefined uVar26;
  _func_3152 *p_Var27;
  ssl3_state_st *psVar28;
  _func_3150 *p_Var29;
  ssl3_state_st *local_d4;
  _func_3152 *local_c0;
  ssl3_state_st *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  psVar16 = *(ssl3_state_st **)PTR___stack_chk_guard_006a9ae8;
  psVar19 = param_3;
  local_2c = psVar16;
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar3 = ssl3_setup_read_buffer(), iVar3 == 0)) {
    psVar23 = (ssl3_state_st *)0xffffffff;
    goto LAB_0048ab80;
  }
  if (param_2 == 0) {
    if (param_5 == 0) goto LAB_0048a97c;
LAB_0048b2b8:
    psVar19 = (ssl3_state_st *)0x44;
    uVar12 = 0x3eb;
  }
  else {
    if (param_2 != 0x17) {
      if ((param_2 != 0x16) || (param_5 != 0)) goto LAB_0048b2b8;
      psVar19 = param_1->s3;
      if (psVar19->handshake_fragment_len != 0) {
        puVar21 = psVar19->handshake_fragment;
        if ((int)param_4 < 1) {
          psVar23 = (ssl3_state_st *)0x0;
LAB_0048b594:
          psVar19->handshake_fragment[0] = *puVar21;
          if (1 < param_1->s3->handshake_fragment_len) {
            param_1->s3->handshake_fragment[1] = puVar21[1];
            if (2 < param_1->s3->handshake_fragment_len) {
              param_1->s3->handshake_fragment[2] = puVar21[2];
              if (3 < param_1->s3->handshake_fragment_len) {
                param_1->s3->handshake_fragment[3] = puVar21[3];
              }
            }
          }
        }
        else {
          psVar28 = param_3;
          puVar18 = puVar21;
          do {
            puVar21 = puVar18 + 1;
            psVar4 = (ssl3_state_st *)((int)&psVar28->flags + 1);
            psVar23 = (ssl3_state_st *)((int)psVar4 - (int)param_3);
            *(uchar *)&psVar28->flags = *puVar18;
            psVar19 = param_1->s3;
            psVar16 = (ssl3_state_st *)(psVar19->handshake_fragment_len - 1);
            psVar19->handshake_fragment_len = (uint)psVar16;
            if (psVar4 == (ssl3_state_st *)
                          (param_4->read_sequence + (int)(param_3->read_sequence + -0x10))) {
              if (psVar16 != (ssl3_state_st *)0x0) goto LAB_0048b594;
              break;
            }
            psVar28 = psVar4;
            puVar18 = puVar21;
          } while (psVar16 != (ssl3_state_st *)0x0);
        }
        goto LAB_0048ab80;
      }
    }
LAB_0048a97c:
    if ((param_1->in_handshake != 0) ||
       (uVar24 = (*(code *)PTR_SSL_state_006a7808)(param_1), (uVar24 & 0x3000) == 0)) {
LAB_0048a988:
      local_c0 = (_func_3152 *)0x0;
      psVar28 = param_1->s3;
LAB_0048a9ac:
      psVar19 = (ssl3_state_st *)(psVar28->rrec).length;
      param_1->rwstate = 1;
      if ((psVar19 != (ssl3_state_st *)0x0) && (psVar4 = psVar28, param_1->rstate != 0xf1))
      goto LAB_0048a9cc;
      pSVar11 = param_1->session;
      if ((param_1->references & 0x20U) == 0) {
        iVar3 = 0;
        local_d4 = (ssl3_state_st *)0x4540;
      }
      else {
        iVar3 = 0x4000;
        if (psVar28->init_extra == 0) {
          psVar19 = (ssl3_state_st *)0x44;
          uVar12 = 0x140;
LAB_0048b740:
          psVar16 = (ssl3_state_st *)0x8f;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8f,psVar19,"s3_pkt.c",uVar12);
          psVar23 = (ssl3_state_st *)0xffffffff;
          goto LAB_0048ab80;
        }
        local_d4 = (ssl3_state_st *)0x8540;
      }
      iVar25 = 0x21;
      uVar24 = iVar3 + 0x4400;
      do {
        if ((param_1->rstate != 0xf1) ||
           (uVar14 = param_1->packet_length, psVar16 = psVar19, uVar14 < 5)) {
          psVar16 = (ssl3_state_st *)&DAT_00000005;
          psVar19 = (ssl3_state_st *)(param_1->s3->rbuf).len;
          psVar23 = (ssl3_state_st *)ssl3_read_n(param_1,5,psVar19,0);
          if ((int)psVar23 < 1) goto LAB_0048ab80;
          pbVar13 = param_1->packet;
          iVar17 = param_1->max_cert_list;
          param_1->rstate = 0xf1;
          (psVar28->rrec).type = (uint)*pbVar13;
          psVar16 = (ssl3_state_st *)(uint)*(ushort *)(pbVar13 + 3);
          uVar14 = (uint)*(short *)(pbVar13 + 1);
          (psVar28->rrec).length = (uint)psVar16;
          if ((iVar17 != 0) || (uVar14 == param_1->version)) {
            if ((int)uVar14 >> 8 != 3) {
              psVar19 = (ssl3_state_st *)0x10b;
              uVar12 = 0x174;
              goto LAB_0048b740;
            }
            if (psVar16 <= (ssl3_state_st *)((param_1->s3->rbuf).len - 5)) {
              uVar14 = param_1->packet_length;
              goto LAB_0048acb0;
            }
            psVar19 = (ssl3_state_st *)0xc6;
            uVar12 = 0x17a;
LAB_0048b018:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8f,psVar19,"s3_pkt.c",uVar12);
            iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x30))(0x16);
            psVar16 = (ssl3_state_st *)param_1->version;
            goto joined_r0x0048ae78;
          }
          psVar19 = (ssl3_state_st *)0x10b;
          psVar16 = (ssl3_state_st *)0x8f;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8f,0x10b,"s3_pkt.c",0x15c);
          if (((((uVar14 ^ param_1->version) & 0xff00) == 0) &&
              (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) &&
             (param_1->write_hash == (EVP_MD_CTX *)0x0)) {
            if ((psVar28->rrec).type == 0x15) goto LAB_0048ab78;
            uVar12 = 0x46;
            param_1->version = uVar14 & 0xffff;
          }
          else {
            uVar12 = 0x46;
          }
          goto LAB_0048aaf4;
        }
LAB_0048acb0:
        if ((ssl3_state_st *)(uVar14 - 5) < psVar16) {
          psVar19 = psVar16;
          psVar23 = (ssl3_state_st *)ssl3_read_n(param_1,psVar16,psVar16,1);
          if ((int)psVar23 < 1) goto LAB_0048ab80;
          psVar16 = (ssl3_state_st *)(psVar28->rrec).length;
          puVar21 = param_1->packet + 5;
          param_1->rstate = 0xf0;
          (psVar28->rrec).input = puVar21;
        }
        else {
          puVar21 = param_1->packet + 5;
          param_1->rstate = 0xf0;
          (psVar28->rrec).input = puVar21;
        }
        if (local_d4 < psVar16) {
          psVar19 = (ssl3_state_st *)0x96;
          uVar12 = 0x1a6;
          goto LAB_0048b018;
        }
        pSVar9 = param_1->method;
        psVar16 = (ssl3_state_st *)0x0;
        (psVar28->rrec).data = puVar21;
        iVar17 = (**(code **)pSVar9->ssl3_enc)(param_1);
        if (iVar17 == 0) {
          psVar19 = (ssl3_state_st *)0x81;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8f,0x81,"s3_pkt.c",0x1b6);
          uVar12 = 0x15;
          goto LAB_0048aaf4;
        }
        if (((pSVar11 != (SSL_SESSION *)0x0) && (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) &&
           (iVar5 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1->read_hash), iVar5 != 0)) {
          uVar12 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1->read_hash);
          uVar14 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar12);
          if (0x40 < uVar14) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)("s3_pkt.c",0x1ca,"mac_size <= EVP_MAX_MD_SIZE");
          }
          uVar8 = ((uint)(psVar28->rrec).type >> 8) + (psVar28->rrec).length;
          if ((uVar14 <= uVar8) &&
             ((uVar6 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a8108)(param_1->enc_read_ctx),
              (uVar6 & 0xf0007) != 2 || (uVar14 + 1 <= uVar8)))) {
            uVar6 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a8108)(param_1->enc_read_ctx);
            psVar16 = (ssl3_state_st *)&stack0xffffff54;
            if ((uVar6 & 0xf0007) == 2) {
              psVar19 = (ssl3_state_st *)&stack0xffffff94;
              ssl3_cbc_copy_mac(psVar19,&psVar28->rrec,uVar14,uVar8);
              psVar7 = param_1->method->ssl3_enc;
              (psVar28->rrec).length = (psVar28->rrec).length - uVar14;
              iVar5 = (**(code **)(psVar7 + 4))(param_1,(ssl3_state_st *)&stack0xffffff54,0);
              if (-1 < iVar5) goto LAB_0048ae0c;
LAB_0048aed8:
              iVar17 = -1;
              if ((psVar28->rrec).length <= uVar24 + uVar14) goto LAB_0048aeec;
            }
            else {
              puVar21 = (psVar28->rrec).data;
              psVar7 = param_1->method->ssl3_enc;
              uVar8 = (psVar28->rrec).length - uVar14;
              (psVar28->rrec).length = uVar8;
              iVar5 = (**(code **)(psVar7 + 4))(param_1,(ssl3_state_st *)&stack0xffffff54,0);
              if ((iVar5 < 0) ||
                 (psVar19 = (ssl3_state_st *)(puVar21 + uVar8), psVar16 = psVar19,
                 psVar19 == (ssl3_state_st *)0x0)) goto LAB_0048aed8;
LAB_0048ae0c:
              iVar5 = (*(code *)PTR_CRYPTO_memcmp_006a8128)
                                ((ssl3_state_st *)&stack0xffffff54,psVar19,uVar14);
              psVar16 = psVar19;
              if (iVar5 != 0) goto LAB_0048aed8;
              if ((psVar28->rrec).length <= uVar24 + uVar14) goto LAB_0048aeec;
            }
LAB_0048ae3c:
            psVar19 = (ssl3_state_st *)0x119;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8f,0x119,"s3_pkt.c",0x206);
            iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x30))(0x14);
            psVar16 = (ssl3_state_st *)param_1->version;
            goto joined_r0x0048ae78;
          }
          psVar19 = (ssl3_state_st *)&DAT_000000a0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8f,0xa0,"s3_pkt.c",0x1dc);
          uVar12 = 0x32;
          goto LAB_0048aaf4;
        }
LAB_0048aeec:
        if (iVar17 < 0) goto LAB_0048ae3c;
        if (param_1->expand != (COMP_CTX *)0x0) {
          if (uVar24 < (psVar28->rrec).length) {
            psVar19 = (ssl3_state_st *)&DAT_0000008c;
            uVar12 = 0x20e;
            goto LAB_0048b018;
          }
          psVar19 = param_1->s3;
          psVar16 = (ssl3_state_st *)(psVar19->rrec).comp;
          uVar14 = (*(code *)PTR_COMP_expand_block_006a8118)
                             (param_1->expand,psVar16,0x4000,(psVar19->rrec).data,
                              (psVar19->rrec).length);
          if ((int)uVar14 < 0) {
            psVar19 = (ssl3_state_st *)&DAT_0000006b;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8f,0x6b,"s3_pkt.c",0x213);
            iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x30))(0x1e);
            psVar16 = (ssl3_state_st *)param_1->version;
            goto joined_r0x0048ae78;
          }
          (psVar19->rrec).length = uVar14;
          (psVar19->rrec).data = (psVar19->rrec).comp;
        }
        psVar19 = (ssl3_state_st *)(psVar28->rrec).length;
        if ((ssl3_state_st *)(iVar3 + 0x4000) < psVar19) {
          psVar19 = (ssl3_state_st *)&DAT_00000092;
          uVar12 = 0x21a;
          goto LAB_0048b018;
        }
        (psVar28->rrec).off = 0;
        param_1->packet_length = 0;
        if (psVar19 != (ssl3_state_st *)0x0) goto LAB_0048b714;
        iVar25 = iVar25 + -1;
        if (iVar25 == 0) {
          psVar19 = (ssl3_state_st *)0x12a;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8f,0x12a,"s3_pkt.c",0x230);
          iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x30))(10);
          psVar16 = (ssl3_state_st *)param_1->version;
          goto joined_r0x0048ae78;
        }
      } while( true );
    }
    psVar23 = (ssl3_state_st *)(*param_1->handshake_func)(param_1);
    if ((int)psVar23 < 0) goto LAB_0048ab80;
    if (psVar23 != (ssl3_state_st *)0x0) goto LAB_0048a988;
    psVar19 = (ssl3_state_st *)0xe5;
    uVar12 = 0x40e;
  }
LAB_0048b2c8:
  psVar16 = (ssl3_state_st *)&DAT_00000094;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x94,psVar19,"s3_pkt.c",uVar12);
  psVar23 = (ssl3_state_st *)0xffffffff;
LAB_0048ab80:
  if (local_2c == *(ssl3_state_st **)puVar2) {
    return psVar23;
  }
  psVar23 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = (**(code **)(*(int *)(*(int *)psVar23->read_sequence + 100) + 0x30))(psVar19);
  if ((psVar23->flags == 0x300) && (iVar3 == 0x46)) {
    uVar26 = 0x28;
  }
  else {
    uVar26 = (undefined)iVar3;
    if (iVar3 < 0) {
      return (ssl3_state_st *)0xffffffff;
    }
  }
  if ((psVar16 == (ssl3_state_st *)&SUB_00000002) && (*(int *)psVar23->client_random != 0)) {
    (*(code *)PTR_SSL_CTX_remove_session_006a807c)(psVar23->empty_fragment_done);
  }
  iVar3 = *(int *)(psVar23->write_sequence + 4);
  *(char *)(iVar3 + 400) = (char)psVar16;
  *(undefined4 *)(iVar3 + 0x18c) = 1;
  *(undefined *)(*(int *)(psVar23->write_sequence + 4) + 0x191) = uVar26;
  if (*(int *)(*(int *)(psVar23->write_sequence + 4) + 0x108) != 0) {
    return (ssl3_state_st *)0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x0048bc88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  psVar16 = (ssl3_state_st *)(**(code **)(*(int *)psVar23->read_sequence + 0x3c))(psVar23);
  return psVar16;
LAB_0048b714:
  psVar4 = param_1->s3;
LAB_0048a9cc:
  if ((psVar4->change_cipher_spec == 0) || ((psVar28->rrec).type == 0x16)) {
    psVar23 = (ssl3_state_st *)(param_1->shutdown & 2);
    if (psVar23 != (ssl3_state_st *)0x0) {
      (psVar28->rrec).length = 0;
      param_1->rwstate = 1;
      psVar23 = (ssl3_state_st *)0x0;
      goto LAB_0048ab80;
    }
    iVar3 = (psVar28->rrec).type;
    if (param_2 == iVar3) {
      uVar24 = (*(code *)PTR_SSL_state_006a7808)(param_1);
      if ((((uVar24 & 0x3000) == 0) || (param_2 != 0x17)) ||
         (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) {
        psVar23 = param_4;
        if (0 < (int)param_4) {
          psVar23 = (ssl3_state_st *)(psVar28->rrec).length;
          if (param_4 < psVar23) {
            psVar23 = param_4;
          }
          psVar16 = (ssl3_state_st *)((psVar28->rrec).data + (psVar28->rrec).off);
          psVar19 = psVar23;
          (*(code *)PTR_memcpy_006a9aec)(param_3,psVar16,psVar23);
          if (param_5 == 0) {
            uVar24 = (psVar28->rrec).length - (int)psVar23;
            (psVar28->rrec).length = uVar24;
            (psVar28->rrec).off = (uint)(psVar23->read_sequence + ((psVar28->rrec).off - 8));
            if (uVar24 == 0) {
              uVar24 = param_1->options;
              param_1->rstate = 0xf0;
              (psVar28->rrec).off = 0;
              if (((uVar24 & 0x10) != 0) && ((param_1->s3->rbuf).left == 0)) {
                ssl3_release_read_buffer(param_1);
              }
            }
          }
        }
        goto LAB_0048ab80;
      }
      psVar19 = (ssl3_state_st *)&DAT_00000064;
      uVar12 = 0x441;
      goto LAB_0048b780;
    }
    if (iVar3 == 0x16) {
      puVar21 = psVar4->handshake_fragment;
      uVar24 = 4;
      puVar22 = &psVar4->handshake_fragment_len;
LAB_0048b150:
      uVar14 = *puVar22;
      psVar16 = (ssl3_state_st *)(uVar24 - uVar14);
      if (psVar16 <= psVar19) {
        psVar19 = psVar16;
      }
      puVar20 = (undefined *)((int)&psVar19[-1].next_proto_neg_seen + 3);
      if (psVar19 != (ssl3_state_st *)0x0) {
        do {
          puVar18 = (psVar28->rrec).data;
          puVar20 = puVar20 + -1;
          *puVar22 = uVar14 + 1;
          uVar8 = (psVar28->rrec).off;
          psVar19 = (ssl3_state_st *)(uVar8 + 1);
          (psVar28->rrec).off = (uint)psVar19;
          puVar21[uVar14] = puVar18[uVar8];
          psVar16 = (ssl3_state_st *)((psVar28->rrec).length - 1);
          (psVar28->rrec).length = (uint)psVar16;
          uVar14 = *puVar22;
        } while (puVar20 != (undefined *)0xffffffff);
      }
      if (uVar14 < uVar24) {
        psVar28 = param_1->s3;
        goto LAB_0048a9ac;
      }
    }
    else {
      if (iVar3 == 0x15) {
        puVar21 = psVar4->alert_fragment;
        uVar24 = 2;
        puVar22 = &psVar4->alert_fragment_len;
        goto LAB_0048b150;
      }
      if (iVar3 == 0x18) {
        tls1_process_heartbeat(param_1);
        (psVar28->rrec).length = 0;
        param_1->rwstate = 3;
        pBVar10 = SSL_get_rbio(param_1);
        (*(code *)PTR_BIO_clear_flags_006a8138)(pBVar10,0xf);
        pBVar10 = SSL_get_rbio(param_1);
        psVar16 = (ssl3_state_st *)&DAT_00000009;
        (*(code *)PTR_BIO_set_flags_006a7570)(pBVar10);
        psVar23 = (ssl3_state_st *)0xffffffff;
        goto LAB_0048ab80;
      }
    }
    if (param_1->server == 0) {
      psVar4 = param_1->s3;
      if (((psVar4->handshake_fragment_len < 4) || (psVar4->handshake_fragment[0] != '\0')) ||
         ((param_1->session == (SSL_SESSION *)0x0 ||
          (*(int *)(param_1->session->krb5_client_princ + 0x24) == 0)))) goto LAB_0048aa3c;
      psVar4->handshake_fragment_len = 0;
      if ((*(uint *)psVar4->handshake_fragment & 0xffffff) == 0) {
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          psVar16 = (ssl3_state_st *)param_1->version;
          psVar19 = (ssl3_state_st *)&DAT_00000016;
          (*param_1->msg_callback)
                    (0,(int)psVar16,0x16,psVar4->handshake_fragment,4,param_1,
                     param_1->msg_callback_arg);
        }
        iVar3 = (*(code *)PTR_SSL_state_006a7808)(param_1);
        if (iVar3 == 3) {
          psVar28 = param_1->s3;
          if (((psVar28->flags & 1U) != 0) || (psVar28->renegotiate != 0)) goto LAB_0048a9ac;
          ssl3_renegotiate(param_1);
          iVar3 = ssl3_renegotiate_check(param_1);
          if (iVar3 != 0) {
            psVar23 = (ssl3_state_st *)(*param_1->handshake_func)(param_1);
            if ((int)psVar23 < 0) goto LAB_0048ab80;
            if (psVar23 == (ssl3_state_st *)0x0) {
              psVar19 = (ssl3_state_st *)0xe5;
              uVar12 = 0x4b4;
              goto LAB_0048b2c8;
            }
            if ((param_1->options & 4) == 0) {
              psVar28 = param_1->s3;
              if ((psVar28->rbuf).left == 0) goto code_r0x0048b670;
              goto LAB_0048a9ac;
            }
          }
        }
        goto LAB_0048b0ec;
      }
      psVar19 = (ssl3_state_st *)&DAT_00000069;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x94,0x69,"s3_pkt.c",0x4a1);
      uVar12 = 0x32;
    }
    else {
      iVar3 = (*(code *)PTR_SSL_state_006a7808)(param_1);
      if (iVar3 == 3) {
        psVar4 = param_1->s3;
        if (((((psVar4->send_connection_binding == 0) && (0x300 < param_1->version)) &&
             (3 < psVar4->handshake_fragment_len)) &&
            ((psVar4->handshake_fragment[0] == '\x01' && (param_1->session != (SSL_SESSION *)0x0))))
           && ((*(int *)(param_1->session->krb5_client_princ + 0x24) != 0 &&
               (-1 < *(int *)(param_1->psk_server_callback + 0xa4) << 0xd)))) {
          pSVar9 = param_1->method;
          (psVar28->rrec).length = 0;
          iVar3 = (**(code **)(pSVar9->ssl3_enc + 0x30))(100);
          psVar16 = (ssl3_state_st *)param_1->version;
          if ((psVar16 == (ssl3_state_st *)0x300) && (iVar3 == 0x46)) {
            uVar15 = '(';
          }
          else {
            uVar15 = (uchar)iVar3;
            if (iVar3 < 0) goto LAB_0048b0ec;
          }
          psVar19 = param_1->s3;
          psVar16 = (ssl3_state_st *)0x1;
          psVar19->send_alert[0] = '\x01';
          psVar19->alert_dispatch = 1;
          param_1->s3->send_alert[1] = uVar15;
          psVar28 = param_1->s3;
          if ((psVar28->wbuf).left == 0) {
            (*param_1->method->ssl_dispatch_alert)(param_1);
            psVar28 = param_1->s3;
          }
          goto LAB_0048a9ac;
        }
      }
      else {
        psVar4 = param_1->s3;
      }
LAB_0048aa3c:
      if (psVar4->alert_fragment_len < 2) {
        psVar16 = (ssl3_state_st *)&DAT_00000014;
        if ((param_1->shutdown & 1U) != 0) {
          param_1->rwstate = 1;
          (psVar28->rrec).length = 0;
          goto LAB_0048ab80;
        }
        iVar3 = (psVar28->rrec).type;
        if (iVar3 == 0x14) {
          if ((((psVar28->rrec).length != 1) || ((psVar28->rrec).off != 0)) ||
             (puVar21 = (psVar28->rrec).data, *puVar21 != '\x01')) {
            psVar19 = (ssl3_state_st *)0x67;
            uVar12 = 0x532;
            goto LAB_0048bb18;
          }
          psVar19 = (ssl3_state_st *)0x85;
          if ((psVar4->tmp).new_cipher == (SSL_CIPHER *)0x0) {
            uVar12 = 0x539;
          }
          else {
            if ((psVar4->flags & 0x80U) != 0) {
              p_Var29 = param_1->msg_callback;
              psVar4->flags = psVar4->flags & 0xffffff7f;
              (psVar28->rrec).length = 0;
              if (p_Var29 != (_func_3150 *)0x0) {
                psVar19 = (ssl3_state_st *)&DAT_00000014;
                (*p_Var29)(0,param_1->version,0x14,puVar21,1,param_1,param_1->msg_callback_arg);
                psVar4 = param_1->s3;
              }
              psVar16 = (ssl3_state_st *)0x1;
              psVar4->change_cipher_spec = 1;
              iVar3 = ssl3_do_change_cipher_spec(param_1);
              if (iVar3 != 0) {
                psVar28 = param_1->s3;
                goto LAB_0048a9ac;
              }
              goto LAB_0048ab78;
            }
            psVar19 = (ssl3_state_st *)0x85;
            uVar12 = 0x53f;
          }
        }
        else {
          if ((3 < psVar4->handshake_fragment_len) && (param_1->in_handshake == 0)) {
            psVar16 = (ssl3_state_st *)0x3;
            if (((param_1->state & 0xfffU) == 3) && (iVar3 = 0x2000, (psVar4->flags & 1U) == 0)) {
              psVar19 = (ssl3_state_st *)0x1000;
              psVar16 = (ssl3_state_st *)0x1;
              if (param_1->server == 0) {
                iVar3 = 0x1000;
              }
              param_1->tlsext_hb_seq = 1;
              param_1->new_session = 1;
              param_1->state = iVar3;
            }
            psVar23 = (ssl3_state_st *)(*param_1->handshake_func)(param_1);
            if ((int)psVar23 < 0) goto LAB_0048ab80;
            if (psVar23 == (ssl3_state_st *)0x0) {
              psVar19 = (ssl3_state_st *)0xe5;
              uVar12 = 0x568;
              goto LAB_0048b2c8;
            }
            if ((param_1->options & 4) == 0) {
              psVar28 = param_1->s3;
              if ((psVar28->rbuf).left == 0) {
                param_1->rwstate = 3;
                goto LAB_0048b678;
              }
              goto LAB_0048a9ac;
            }
LAB_0048b0ec:
            psVar28 = param_1->s3;
            goto LAB_0048a9ac;
          }
          psVar16 = (ssl3_state_st *)(uint)(iVar3 < 0x17);
          if (0x13 < iVar3) {
            bVar1 = psVar16 != (ssl3_state_st *)0x0;
            psVar16 = (ssl3_state_st *)&DAT_00000017;
            if (bVar1) {
              psVar19 = (ssl3_state_st *)0x44;
              uVar12 = 0x597;
              goto LAB_0048b780;
            }
            if (iVar3 == 0x17) {
              if (((psVar4->in_read_app_data != 0) && (psVar4->total_renegotiations != 0)) &&
                 (((uVar24 = param_1->state, (uVar24 & 0x1000) != 0 &&
                   (psVar16 = (ssl3_state_st *)(uint)(uVar24 - 0x1110 < 0x11),
                   psVar16 != (ssl3_state_st *)0x0)) ||
                  ((psVar16 = (ssl3_state_st *)(uVar24 & 0x2000), psVar16 != (ssl3_state_st *)0x0 &&
                   (uVar24 - 0x2110 < 0x11)))))) {
                psVar4->in_read_app_data = 2;
                psVar23 = (ssl3_state_st *)0xffffffff;
                goto LAB_0048ab80;
              }
              psVar19 = (ssl3_state_st *)0xf5;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x94,0xf5,"s3_pkt.c",0x5af);
              uVar12 = 10;
              goto LAB_0048aaf4;
            }
          }
          if (param_1->version - 0x301U < 2) {
            (psVar28->rrec).length = 0;
            psVar28 = psVar4;
            goto LAB_0048a9ac;
          }
          psVar19 = (ssl3_state_st *)0xf5;
          uVar12 = 0x58c;
        }
        goto LAB_0048b780;
      }
      p_Var29 = param_1->msg_callback;
      psVar28 = (ssl3_state_st *)(uint)*(ushort *)psVar4->alert_fragment;
      uVar15 = psVar4->alert_fragment[0];
      uVar24 = (uint)psVar4->alert_fragment[1];
      psVar4->alert_fragment_len = 0;
      if (p_Var29 != (_func_3150 *)0x0) {
        psVar19 = (ssl3_state_st *)&DAT_00000015;
        (*p_Var29)(0,param_1->version,0x15,psVar4->alert_fragment,2,param_1,
                   param_1->msg_callback_arg);
      }
      psVar16 = (ssl3_state_st *)0x4004;
      p_Var27 = param_1->info_callback;
      if (((param_1->info_callback != (_func_3152 *)0x0) ||
          (p_Var27 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
          *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
         (p_Var27 = local_c0, local_c0 != (_func_3152 *)0x0)) {
        (*p_Var27)(param_1,0x4004,(int)psVar28);
        psVar19 = psVar28;
        local_c0 = p_Var27;
      }
      puVar20 = PTR_ERR_put_error_006a7f34;
      if (uVar15 == '\x01') {
        psVar28 = param_1->s3;
        psVar28->warn_alert = uVar24;
        if (uVar24 == 0) {
          param_1->shutdown = param_1->shutdown | 2;
          goto LAB_0048ab80;
        }
        if (uVar24 != 100) goto LAB_0048a9ac;
        psVar19 = (ssl3_state_st *)0x153;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x94,0x153,"s3_pkt.c",0x508);
        uVar12 = 0x28;
      }
      else {
        if (uVar15 == '\x02') {
          param_1->rwstate = 1;
          param_1->s3->fatal_alert = uVar24;
          psVar19 = (ssl3_state_st *)&stack0xffffff94;
          (*(code *)puVar20)(0x14,0x94,uVar24 + 1000,"s3_pkt.c",0x514);
          (*(code *)PTR_BIO_snprintf_006a6f60)(psVar19,0x10,"%d",uVar24);
          (*(code *)PTR_ERR_add_error_data_006a813c)(2,"SSL alert number ",psVar19);
          puVar20 = PTR_SSL_CTX_remove_session_006a807c;
          psVar16 = (ssl3_state_st *)param_1->session;
          param_1->shutdown = param_1->shutdown | 2;
          (*(code *)puVar20)(param_1->psk_server_callback);
          goto LAB_0048ab80;
        }
        psVar19 = (ssl3_state_st *)0xf6;
        uVar12 = 0x51c;
LAB_0048bb18:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x94,psVar19,"s3_pkt.c",uVar12);
        uVar12 = 0x2f;
      }
    }
  }
  else {
    psVar19 = (ssl3_state_st *)0x91;
    uVar12 = 0x42a;
LAB_0048b780:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x94,psVar19,"s3_pkt.c",uVar12);
    uVar12 = 10;
  }
LAB_0048aaf4:
  iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x30))(uVar12);
  psVar16 = (ssl3_state_st *)param_1->version;
joined_r0x0048ae78:
  if ((psVar16 == (ssl3_state_st *)0x300) && (iVar3 == 0x46)) {
    uVar15 = '(';
  }
  else {
    uVar15 = (uchar)iVar3;
    if (iVar3 < 0) goto LAB_0048ab78;
  }
  psVar16 = (ssl3_state_st *)param_1->session;
  if (psVar16 != (ssl3_state_st *)0x0) {
    (*(code *)PTR_SSL_CTX_remove_session_006a807c)(param_1->psk_server_callback);
  }
  psVar23 = param_1->s3;
  psVar23->send_alert[0] = '\x02';
  psVar23->alert_dispatch = 1;
  param_1->s3->send_alert[1] = uVar15;
  psVar23 = (ssl3_state_st *)0xffffffff;
  if ((param_1->s3->wbuf).left != 0) goto LAB_0048ab80;
  (*param_1->method->ssl_dispatch_alert)(param_1);
LAB_0048ab78:
  psVar23 = (ssl3_state_st *)0xffffffff;
  goto LAB_0048ab80;
code_r0x0048b670:
  param_1->rwstate = 3;
LAB_0048b678:
  pBVar10 = SSL_get_rbio(param_1);
  (*(code *)PTR_BIO_clear_flags_006a8138)(pBVar10,0xf);
  psVar16 = (ssl3_state_st *)&DAT_00000009;
  (*(code *)PTR_BIO_set_flags_006a7570)(pBVar10);
  psVar23 = (ssl3_state_st *)0xffffffff;
  goto LAB_0048ab80;
}

