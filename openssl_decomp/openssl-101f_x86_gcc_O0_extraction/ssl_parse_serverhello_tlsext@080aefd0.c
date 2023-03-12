
int ssl_parse_serverhello_tlsext
              (SSL *param_1,ushort **param_2,int param_3,int param_4,undefined4 *param_5)

{
  ushort *puVar1;
  byte bVar2;
  ushort *puVar3;
  code *pcVar4;
  bool bVar5;
  bool bVar6;
  ushort uVar7;
  ushort *puVar8;
  void *pvVar9;
  int iVar10;
  SSL_CTX *pSVar11;
  char *pcVar12;
  int iVar13;
  ushort uVar14;
  uint uVar15;
  ushort *puVar16;
  SSL_SESSION *pSVar17;
  undefined4 *puVar18;
  uint uVar19;
  undefined4 *puVar20;
  int in_GS_OFFSET;
  byte bVar21;
  byte local_25;
  SSL_METHOD **local_24;
  int local_20;
  
  bVar21 = 0;
  puVar3 = *param_2;
  param_1->s3->next_proto_neg_seen = 0;
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile & 0xfffffffc);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (puVar3 < (ushort *)(param_3 + -2 + param_4)) {
    puVar8 = (ushort *)((uint)(ushort)(*puVar3 << 8 | *puVar3 >> 8) + (int)(puVar3 + 1));
    if (puVar8 == (ushort *)(param_3 + param_4)) {
      bVar6 = false;
      bVar5 = false;
      puVar3 = puVar3 + 1;
LAB_080af0f6:
      puVar16 = puVar3;
      if ((ushort *)(param_3 + -4 + param_4) < puVar16) {
        if (puVar16 != puVar8) goto LAB_080af054;
        if (((param_1->hit == 0) && (bVar5)) && ((char *)param_1->tlsext_debug_arg != (char *)0x0))
        {
          pSVar17 = param_1->session;
          if (*(int *)(pSVar17->krb5_client_princ + 0x40) != 0) goto LAB_080af054;
          pcVar12 = BUF_strdup((char *)param_1->tlsext_debug_arg);
          *(char **)(pSVar17->krb5_client_princ + 0x40) = pcVar12;
          if (*(int *)(param_1->session->krb5_client_princ + 0x40) == 0) {
LAB_080af51f:
            iVar13 = 0;
            *param_5 = 0x70;
            goto LAB_080af060;
          }
        }
        *param_2 = puVar16;
LAB_080af4d0:
        if (bVar6) goto LAB_080af02a;
        goto LAB_080af01e;
      }
      uVar7 = puVar16[1] << 8 | puVar16[1] >> 8;
      uVar14 = *puVar16 << 8 | *puVar16 >> 8;
      uVar19 = (uint)uVar7;
      puVar1 = puVar16 + 2;
      puVar3 = (ushort *)((int)puVar1 + uVar19);
      if (puVar8 < puVar3) goto LAB_080af4d0;
      if ((code *)param_1->max_send_fragment != (code *)0x0) {
        (*(code *)param_1->max_send_fragment)
                  (param_1,1,uVar14,puVar1,uVar19,param_1->tlsext_debug_cb);
      }
      if (uVar14 == 0) {
        if ((param_1->tlsext_debug_arg == (void *)0x0) || (uVar7 != 0)) goto LAB_080af51f;
        bVar5 = true;
        goto LAB_080af0f6;
      }
      if (uVar14 == 0xb) {
        if (param_1->version != 0xfeff) {
          bVar2 = *(byte *)(puVar16 + 2);
          uVar15 = (uint)bVar2;
          puVar18 = (undefined4 *)((int)puVar16 + 5);
          if ((uVar19 - 1 != uVar15) || (uVar15 == 0)) goto LAB_080af054;
          pSVar17 = param_1->session;
          *(undefined4 *)(pSVar17->krb5_client_princ + 0x44) = 0;
          if (*(void **)(pSVar17->krb5_client_princ + 0x48) != (void *)0x0) {
            CRYPTO_free(*(void **)(pSVar17->krb5_client_princ + 0x48));
            pSVar17 = param_1->session;
          }
          pvVar9 = CRYPTO_malloc(uVar15,"t1_lib.c",0x5fb);
          *(void **)(pSVar17->krb5_client_princ + 0x48) = pvVar9;
          if (pvVar9 == (void *)0x0) {
LAB_080af594:
            iVar13 = 0;
            *param_5 = 0x50;
            goto LAB_080af060;
          }
          pSVar17 = param_1->session;
          *(uint *)(pSVar17->krb5_client_princ + 0x44) = uVar15;
          puVar20 = *(undefined4 **)(pSVar17->krb5_client_princ + 0x48);
          if (uVar15 < 4) {
            if ((uVar15 != 0) && (*(undefined *)puVar20 = *(undefined *)puVar18, (bVar2 & 2) != 0))
            {
              *(undefined2 *)((int)puVar20 + (uVar15 - 2)) =
                   *(undefined2 *)((int)puVar16 + uVar15 + 3);
            }
          }
          else {
            *puVar20 = *puVar18;
            *(undefined4 *)((int)puVar20 + (uVar15 - 4)) =
                 *(undefined4 *)((int)puVar16 + uVar15 + 1);
            iVar13 = (int)puVar20 - (int)(undefined4 *)((uint)(puVar20 + 1) & 0xfffffffc);
            puVar18 = (undefined4 *)((int)puVar18 - iVar13);
            puVar20 = (undefined4 *)((uint)(puVar20 + 1) & 0xfffffffc);
            for (uVar19 = iVar13 + uVar15 >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {
              *puVar20 = *puVar18;
              puVar18 = puVar18 + (uint)bVar21 * -2 + 1;
              puVar20 = puVar20 + (uint)bVar21 * -2 + 1;
            }
          }
        }
        goto LAB_080af0f6;
      }
      if (uVar14 == 0x23) {
        if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
           (iVar13 = (*(code *)param_1->tlsext_session_ticket)
                               (param_1,puVar1,uVar19,param_1->tls_session_ticket_ext_cb),
           iVar13 == 0)) goto LAB_080af594;
        uVar19 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
        if (((uVar19 & 0x4000) != 0) || (uVar7 != 0)) {
LAB_080af583:
          iVar13 = 0;
          *param_5 = 0x6e;
          goto LAB_080af060;
        }
        param_1->tlsext_ocsp_resplen = 1;
        goto LAB_080af0f6;
      }
      if (uVar14 == 5) {
        if (param_1->version != 0xfeff) {
          if ((param_1->servername_done == -1) || (uVar7 != 0)) goto LAB_080af583;
          param_1->tlsext_status_type = 1;
        }
        goto LAB_080af0f6;
      }
      if (uVar14 == 0x3374) {
        iVar13 = (param_1->s3->tmp).finish_md_len;
        if (iVar13 == 0) {
          pcVar4 = *(code **)(param_1->psk_server_callback + 0x1ac);
          if (pcVar4 == (code *)0x0) {
            *param_5 = 0x6e;
            goto LAB_080af060;
          }
          if (uVar7 != 0) {
            bVar2 = *(byte *)(puVar16 + 2);
            if (bVar2 != 0) {
              uVar15 = 0;
              while( true ) {
                uVar15 = uVar15 + 1 + (uint)bVar2;
                if (uVar19 <= uVar15) break;
                bVar2 = *(byte *)((int)puVar1 + uVar15);
                if (bVar2 == 0) goto LAB_080af548;
              }
              if (uVar19 == uVar15) goto LAB_080af382;
            }
LAB_080af548:
            *param_5 = 0x32;
            goto LAB_080af060;
          }
LAB_080af382:
          iVar10 = (*pcVar4)(param_1,&local_24,&local_25,puVar1,uVar19,
                             *(undefined4 *)(param_1->psk_server_callback + 0x1b0));
          if (iVar10 == 0) {
            pSVar11 = (SSL_CTX *)CRYPTO_malloc((uint)local_25,"t1_lib.c",0x662);
            param_1->initial_ctx = pSVar11;
            if (pSVar11 != (SSL_CTX *)0x0) {
              uVar19 = (uint)local_25;
              if (uVar19 < 4) {
                if ((uVar19 != 0) &&
                   (*(undefined *)&pSVar11->method = *(undefined *)local_24, (local_25 & 2) != 0)) {
                  *(undefined2 *)((int)pSVar11 + (uVar19 - 2)) =
                       *(undefined2 *)((int)local_24 + (uVar19 - 2));
                }
              }
              else {
                puVar20 = (undefined4 *)((uint)&pSVar11->cipher_list & 0xfffffffc);
                pSVar11->method = *local_24;
                *(undefined4 *)((int)pSVar11 + (uVar19 - 4)) =
                     *(undefined4 *)((int)local_24 + (uVar19 - 4));
                iVar13 = (int)pSVar11 - (int)puVar20;
                puVar18 = (undefined4 *)((int)local_24 - iVar13);
                for (uVar19 = uVar19 + iVar13 >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {
                  *puVar20 = *puVar18;
                  puVar18 = puVar18 + (uint)bVar21 * -2 + 1;
                  puVar20 = puVar20 + (uint)bVar21 * -2 + 1;
                }
              }
              *(byte *)&param_1->next_proto_negotiated = local_25;
              param_1->s3->next_proto_neg_seen = 1;
              goto LAB_080af0f6;
            }
          }
          *param_5 = 0x50;
          goto LAB_080af060;
        }
        goto LAB_080af0f6;
      }
      if (uVar14 == 0xff01) {
        iVar13 = ssl_parse_serverhello_renegotiate_ext(param_1,puVar1,uVar19,param_5);
        if (iVar13 == 0) goto LAB_080af0ab;
        bVar6 = true;
        goto LAB_080af0f6;
      }
      if (uVar14 == 0xf) {
        if (*(char *)(puVar16 + 2) == '\x01') {
          param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
        }
        else {
          if (*(char *)(puVar16 + 2) != '\x02') {
            iVar13 = 0;
            *param_5 = 0x2f;
            goto LAB_080af060;
          }
          param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
        }
        goto LAB_080af0f6;
      }
      if ((uVar14 != 0xe) ||
         (iVar13 = ssl_parse_serverhello_use_srtp_ext(param_1,puVar1,uVar19,param_5), iVar13 == 0))
      goto LAB_080af0f6;
      iVar13 = 0;
    }
    else {
LAB_080af054:
      iVar13 = 0;
      *param_5 = 0x32;
    }
  }
  else {
LAB_080af01e:
    if ((param_1->references & 0x40004U) == 0) {
      *param_5 = 0x28;
      ERR_put_error(0x14,0x12f,0x152,"t1_lib.c",0x6bc);
LAB_080af0ab:
      iVar13 = 0;
    }
    else {
LAB_080af02a:
      iVar13 = 1;
    }
  }
LAB_080af060:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar13;
}

