
int ssl_parse_serverhello_tlsext
              (SSL *param_1,ushort **param_2,int param_3,int param_4,undefined4 *param_5)

{
  byte bVar1;
  ushort *puVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  SSL_CTX *pSVar9;
  char *pcVar10;
  uint uVar11;
  ushort *puVar12;
  ushort *puVar13;
  ushort uVar14;
  int iVar15;
  undefined4 *puVar16;
  ushort uVar17;
  SSL_SESSION *pSVar18;
  undefined4 *puVar19;
  int in_GS_OFFSET;
  byte bVar20;
  ushort *local_4c;
  byte local_25;
  SSL_METHOD **local_24;
  int local_20;
  
  bVar20 = 0;
  puVar2 = *param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  param_1->s3->next_proto_neg_seen = 0;
  puVar12 = (ushort *)(param_3 + param_4);
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile & 0xfffffffc);
  param_1->tlsext_ocsp_resplen = 0;
  if ((int)puVar12 - (int)puVar2 < 3) {
LAB_080ab99b:
    if ((param_1->references & 0x40004U) == 0) {
      *param_5 = 0x28;
      ERR_put_error(0x14,0x12f,0x152,"t1_lib.c",0x6a0);
LAB_080aba1b:
      iVar15 = 0;
      goto LAB_080ab9d3;
    }
  }
  else {
    puVar13 = puVar2 + 1;
    if ((int)puVar12 - (int)puVar13 != (uint)(ushort)(*puVar2 << 8 | *puVar2 >> 8)) {
LAB_080ab9c7:
      iVar15 = 0;
      *param_5 = 0x32;
      goto LAB_080ab9d3;
    }
    if ((int)puVar12 - (int)puVar13 < 4) {
      if (puVar12 != puVar13) goto LAB_080ab9c7;
      bVar5 = false;
LAB_080abee1:
      *param_2 = puVar13;
    }
    else {
      local_4c = puVar2 + 3;
      uVar17 = puVar2[2] << 8 | puVar2[2] >> 8;
      uVar14 = puVar2[1] << 8 | puVar2[1] >> 8;
      uVar6 = (uint)uVar17;
      if ((int)puVar12 - (int)local_4c < (int)uVar6) goto LAB_080ab99b;
      bVar5 = false;
      bVar4 = false;
      do {
        if ((code *)param_1->max_send_fragment != (code *)0x0) {
          (*(code *)param_1->max_send_fragment)
                    (param_1,1,uVar14,local_4c,uVar6,param_1->tlsext_debug_cb);
        }
        if (uVar14 == 0) {
          if ((param_1->tlsext_debug_arg != (void *)0x0) && (uVar17 == 0)) {
            uVar6 = 0;
            bVar4 = true;
            goto LAB_080aba91;
          }
LAB_080abf47:
          iVar15 = 0;
          *param_5 = 0x70;
          goto LAB_080ab9d3;
        }
        if (uVar14 == 0xb) {
          bVar1 = *(byte *)(puVar13 + 2);
          uVar11 = (uint)bVar1;
          if ((uVar6 - 1 != uVar11) || (uVar11 == 0)) goto LAB_080ab9c7;
          if (param_1->hit == 0) {
            pSVar18 = param_1->session;
            *(undefined4 *)(pSVar18->krb5_client_princ + 0x44) = 0;
            if (*(void **)(pSVar18->krb5_client_princ + 0x48) != (void *)0x0) {
              CRYPTO_free(*(void **)(pSVar18->krb5_client_princ + 0x48));
              pSVar18 = param_1->session;
            }
            pvVar7 = CRYPTO_malloc(uVar11,"t1_lib.c",0x5ea);
            *(void **)(pSVar18->krb5_client_princ + 0x48) = pvVar7;
            if (pvVar7 == (void *)0x0) goto LAB_080abf7f;
            pSVar18 = param_1->session;
            *(uint *)(pSVar18->krb5_client_princ + 0x44) = uVar11;
            puVar16 = *(undefined4 **)(pSVar18->krb5_client_princ + 0x48);
            if (uVar11 < 4) {
              if ((uVar11 != 0) &&
                 (*(byte *)puVar16 = *(byte *)((int)puVar13 + 5), (bVar1 & 2) != 0)) {
                *(undefined2 *)((int)puVar16 + (uVar11 - 2)) =
                     *(undefined2 *)((int)puVar13 + uVar11 + 3);
              }
            }
            else {
              *puVar16 = *(undefined4 *)((int)puVar13 + 5);
              *(undefined4 *)((int)puVar16 + (uVar11 - 4)) =
                   *(undefined4 *)((int)puVar13 + uVar11 + 1);
              iVar15 = (int)puVar16 - (int)(undefined4 *)((uint)(puVar16 + 1) & 0xfffffffc);
              puVar19 = (undefined4 *)((byte *)((int)puVar13 + 5) + -iVar15);
              puVar16 = (undefined4 *)((uint)(puVar16 + 1) & 0xfffffffc);
              for (uVar11 = iVar15 + uVar11 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                *puVar16 = *puVar19;
                puVar19 = puVar19 + (uint)bVar20 * -2 + 1;
                puVar16 = puVar16 + (uint)bVar20 * -2 + 1;
              }
            }
          }
        }
        else if (uVar14 == 0x23) {
          if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
             (iVar15 = (*(code *)param_1->tlsext_session_ticket)
                                 (param_1,local_4c,uVar6,param_1->tls_session_ticket_ext_cb),
             iVar15 == 0)) {
LAB_080abf7f:
            iVar15 = 0;
            *param_5 = 0x50;
            goto LAB_080ab9d3;
          }
          uVar6 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
          if (((uVar6 & 0x4000) != 0) || (uVar17 != 0)) {
LAB_080abf6e:
            iVar15 = 0;
            *param_5 = 0x6e;
            goto LAB_080ab9d3;
          }
          param_1->tlsext_ocsp_resplen = 1;
          uVar6 = 0;
        }
        else if (uVar14 == 5) {
          if (param_1->version != 0xfeff) {
            if ((param_1->servername_done == -1) || (uVar17 != 0)) goto LAB_080abf6e;
            param_1->tlsext_status_type = 1;
            uVar6 = 0;
          }
        }
        else if (uVar14 == 0x3374) {
          iVar15 = (param_1->s3->tmp).finish_md_len;
          if (iVar15 == 0) {
            pcVar3 = *(code **)(param_1->psk_server_callback + 0x1ac);
            if (pcVar3 == (code *)0x0) {
              *param_5 = 0x6e;
            }
            else if (uVar6 == 0) {
LAB_080abd90:
              iVar8 = (*pcVar3)(param_1,&local_24,&local_25,local_4c,uVar6,
                                *(undefined4 *)(param_1->psk_server_callback + 0x1b0));
              if (iVar8 == 0) {
                pSVar9 = (SSL_CTX *)CRYPTO_malloc((uint)local_25,"t1_lib.c",0x653);
                param_1->initial_ctx = pSVar9;
                if (pSVar9 != (SSL_CTX *)0x0) {
                  uVar11 = (uint)local_25;
                  if (uVar11 < 4) {
                    if ((uVar11 != 0) &&
                       (*(undefined *)&pSVar9->method = *(undefined *)local_24, (local_25 & 2) != 0)
                       ) {
                      *(undefined2 *)((int)pSVar9 + (uVar11 - 2)) =
                           *(undefined2 *)((int)local_24 + (uVar11 - 2));
                    }
                  }
                  else {
                    puVar19 = (undefined4 *)((uint)&pSVar9->cipher_list & 0xfffffffc);
                    pSVar9->method = *local_24;
                    *(undefined4 *)((int)pSVar9 + (uVar11 - 4)) =
                         *(undefined4 *)((int)local_24 + (uVar11 - 4));
                    iVar15 = (int)pSVar9 - (int)puVar19;
                    puVar16 = (undefined4 *)((int)local_24 - iVar15);
                    for (uVar11 = uVar11 + iVar15 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                      *puVar19 = *puVar16;
                      puVar16 = puVar16 + (uint)bVar20 * -2 + 1;
                      puVar19 = puVar19 + (uint)bVar20 * -2 + 1;
                    }
                  }
                  *(byte *)&param_1->next_proto_negotiated = local_25;
                  param_1->s3->next_proto_neg_seen = 1;
                  goto LAB_080aba91;
                }
              }
              *param_5 = 0x50;
            }
            else {
              bVar1 = *(byte *)local_4c;
              if (bVar1 != 0) {
                uVar11 = 0;
                while( true ) {
                  uVar11 = uVar11 + 1 + (uint)bVar1;
                  if (uVar6 <= uVar11) break;
                  bVar1 = *(byte *)((int)local_4c + uVar11);
                  if (bVar1 == 0) goto LAB_080abd30;
                }
                if (uVar6 == uVar11) goto LAB_080abd90;
              }
LAB_080abd30:
              *param_5 = 0x32;
            }
            goto LAB_080ab9d3;
          }
        }
        else if (uVar14 == 0xff01) {
          iVar15 = ssl_parse_serverhello_renegotiate_ext(param_1,local_4c,uVar6,param_5);
          if (iVar15 == 0) goto LAB_080aba1b;
          bVar5 = true;
        }
        else if (uVar14 == 0xf) {
          if (*(byte *)(puVar13 + 2) == 1) {
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
          }
          else {
            if (*(byte *)(puVar13 + 2) != 2) {
              iVar15 = 0;
              *param_5 = 0x2f;
              goto LAB_080ab9d3;
            }
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
          }
        }
        else if (((param_1->method->version == 0xfeff) && (uVar14 == 0xe)) &&
                (iVar15 = ssl_parse_serverhello_use_srtp_ext(param_1,local_4c,uVar6,param_5),
                iVar15 != 0)) goto LAB_080aba1b;
LAB_080aba91:
        puVar13 = (ushort *)(uVar6 + (int)local_4c);
        if ((int)puVar12 - (int)puVar13 < 4) {
          if (puVar12 != puVar13) goto LAB_080ab9c7;
          if (((param_1->hit != 0) || (!bVar4)) ||
             ((char *)param_1->tlsext_debug_arg == (char *)0x0)) goto LAB_080abee1;
          pSVar18 = param_1->session;
          if (*(int *)(pSVar18->krb5_client_princ + 0x40) != 0) goto LAB_080ab9c7;
          pcVar10 = BUF_strdup((char *)param_1->tlsext_debug_arg);
          *(char **)(pSVar18->krb5_client_princ + 0x40) = pcVar10;
          if (*(int *)(param_1->session->krb5_client_princ + 0x40) == 0) goto LAB_080abf47;
          goto LAB_080abee1;
        }
        local_4c = puVar13 + 2;
        uVar17 = puVar13[1] << 8 | puVar13[1] >> 8;
        uVar14 = *puVar13 << 8 | *puVar13 >> 8;
        uVar6 = (uint)uVar17;
      } while ((int)uVar6 <= (int)puVar12 - (int)local_4c);
    }
    if (!bVar5) goto LAB_080ab99b;
  }
  iVar15 = 1;
LAB_080ab9d3:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar15;
}

