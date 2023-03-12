
/* WARNING: Type propagation algorithm not settling */

undefined4
ssl_parse_serverhello_tlsext
          (SSL *param_1,byte **param_2,int param_3,int param_4,undefined4 *param_5)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  void *pvVar6;
  long lVar7;
  SSL_CTX *__dest;
  char *pcVar8;
  byte *pbVar9;
  SSL_SESSION *pSVar10;
  SRTP_PROTECTION_PROFILE *pSVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  SSL_SESSION *pSVar15;
  byte *pbVar16;
  uint __n;
  code *pcVar17;
  byte *local_40;
  byte local_30 [4];
  void *local_2c [2];
  
  pbVar9 = *param_2;
  pbVar16 = (byte *)(param_3 + param_4);
  pSVar11 = param_1->srtp_profile;
  bVar3 = false;
  param_1->s3->next_proto_neg_seen = 0;
  param_1->tlsext_ocsp_resplen = 0;
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar11 & 0xfffffffc);
  if (2 < (int)pbVar16 - (int)pbVar9) {
    pbVar12 = pbVar9 + 2;
    if ((int)pbVar16 - (int)pbVar12 != (uint)CONCAT11(*pbVar9,pbVar9[1])) {
LAB_0005348c:
      *param_5 = 0x32;
      return 0;
    }
    if ((int)pbVar16 - (int)pbVar12 < 4) {
      bVar4 = false;
LAB_00053772:
      if (pbVar12 != pbVar16) goto LAB_0005348c;
      if (((param_1->hit == 0) && (bVar3)) && ((char *)param_1->tlsext_debug_arg != (char *)0x0)) {
        pSVar15 = param_1->session;
        if (*(int *)(pSVar15->krb5_client_princ + 0x40) != 0) goto LAB_0005348c;
        pcVar8 = BUF_strdup((char *)param_1->tlsext_debug_arg);
        pSVar10 = param_1->session;
        *(char **)(pSVar15->krb5_client_princ + 0x40) = pcVar8;
        if (*(int *)(pSVar10->krb5_client_princ + 0x40) == 0) {
LAB_00053764:
          *param_5 = 0x70;
          return 0;
        }
      }
      *param_2 = pbVar12;
    }
    else {
      local_40 = pbVar9 + 6;
      uVar14 = (uint)CONCAT11(pbVar9[4],pbVar9[5]);
      sVar2 = CONCAT11(pbVar9[2],pbVar9[3]);
      if ((int)pbVar16 - (int)local_40 < (int)uVar14) goto LAB_00053466;
      bVar3 = false;
      bVar4 = false;
      do {
        if ((code *)param_1->max_send_fragment != (code *)0x0) {
          (*(code *)param_1->max_send_fragment)
                    (param_1,1,sVar2,local_40,uVar14,param_1->tlsext_debug_cb);
        }
        if (sVar2 == 0) {
          if ((param_1->tlsext_debug_arg == (void *)0x0) || (uVar14 != 0)) goto LAB_00053764;
          bVar3 = true;
        }
        else if (sVar2 == 0xb) {
          __n = (uint)pbVar12[4];
          uVar13 = uVar14 - 1;
          if ((uVar13 != __n) || (uVar13 == 0)) goto LAB_0005348c;
          if (param_1->hit == 0) {
            pSVar15 = param_1->session;
            *(undefined4 *)(pSVar15->krb5_client_princ + 0x44) = 0;
            if (*(void **)(pSVar15->krb5_client_princ + 0x48) != (void *)0x0) {
              CRYPTO_free(*(void **)(pSVar15->krb5_client_princ + 0x48));
              pSVar15 = param_1->session;
            }
            pvVar6 = CRYPTO_malloc(uVar13,"t1_lib.c",0x5ea);
            *(void **)(pSVar15->krb5_client_princ + 0x48) = pvVar6;
            if (pvVar6 == (void *)0x0) goto LAB_000537a0;
            pSVar15 = param_1->session;
            *(uint *)(pSVar15->krb5_client_princ + 0x44) = __n;
            memcpy(*(void **)(pSVar15->krb5_client_princ + 0x48),pbVar12 + 5,__n);
          }
        }
        else if (sVar2 == 0x23) {
          if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
             (iVar5 = (*(code *)param_1->tlsext_session_ticket)
                                (param_1,local_40,uVar14,param_1->tls_session_ticket_ext_cb),
             iVar5 == 0)) {
LAB_000537a0:
            *param_5 = 0x50;
            return 0;
          }
          lVar7 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
          if ((lVar7 << 0x11 < 0) || (uVar14 != 0)) {
LAB_00053796:
            *param_5 = 0x6e;
            return 0;
          }
          param_1->tlsext_ocsp_resplen = 1;
        }
        else if (sVar2 == 5) {
          if (param_1->version != 0xfeff) {
            if ((param_1->servername_done == -1) || (uVar14 != 0)) goto LAB_00053796;
            param_1->tlsext_status_type = 1;
          }
        }
        else if (sVar2 == 0x3374) {
          uVar13 = (param_1->s3->tmp).finish_md_len;
          if (uVar13 == 0) {
            pcVar17 = *(code **)(param_1->psk_server_callback + 0x1ac);
            if (pcVar17 == (code *)0x0) {
              *param_5 = 0x6e;
              return 0;
            }
            if (uVar14 != 0) {
              bVar1 = *local_40;
              while( true ) {
                if (bVar1 == 0) goto LAB_000536ae;
                uVar13 = uVar13 + bVar1 + 1;
                if (uVar14 <= uVar13) break;
                bVar1 = local_40[uVar13];
              }
              if (uVar14 != uVar13) {
LAB_000536ae:
                *param_5 = 0x32;
                return 0;
              }
            }
            iVar5 = (*pcVar17)(param_1,local_2c,local_30,local_40,uVar14,
                               *(undefined4 *)(param_1->psk_server_callback + 0x1b0));
            if (iVar5 != 0) {
LAB_000537b0:
              *param_5 = 0x50;
              return 0;
            }
            __dest = (SSL_CTX *)CRYPTO_malloc((uint)local_30[0],"t1_lib.c",0x653);
            param_1->initial_ctx = __dest;
            if (__dest == (SSL_CTX *)0x0) goto LAB_000537b0;
            memcpy(__dest,local_2c[0],(uint)local_30[0]);
            *(byte *)&param_1->next_proto_negotiated = local_30[0];
            param_1->s3->next_proto_neg_seen = 1;
          }
        }
        else if (sVar2 == -0xff) {
          iVar5 = ssl_parse_serverhello_renegotiate_ext(param_1,local_40,uVar14,param_5);
          if (iVar5 == 0) {
            return 0;
          }
          bVar4 = true;
        }
        else if (sVar2 == 0xf) {
          if (pbVar12[4] == 1) {
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
          }
          else {
            if (pbVar12[4] != 2) {
              *param_5 = 0x2f;
              return 0;
            }
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
          }
        }
        else if (((param_1->method->version == 0xfeff) && (sVar2 == 0xe)) &&
                (iVar5 = ssl_parse_serverhello_use_srtp_ext(param_1,local_40,uVar14,param_5),
                iVar5 != 0)) {
          return 0;
        }
        pbVar12 = local_40 + uVar14;
        if ((int)pbVar16 - (int)pbVar12 < 4) goto LAB_00053772;
        pbVar9 = local_40 + uVar14;
        local_40 = pbVar12 + 4;
        uVar14 = (uint)CONCAT11(pbVar12[2],pbVar12[3]);
        sVar2 = CONCAT11(*pbVar9,pbVar12[1]);
      } while ((int)uVar14 <= (int)pbVar16 - (int)local_40);
    }
    if (bVar4) {
      return 1;
    }
  }
LAB_00053466:
  if ((param_1->references & 0x40004U) != 0) {
    return 1;
  }
  *param_5 = 0x28;
  ERR_put_error(0x14,0x12f,0x152,"t1_lib.c",0x6a0);
  return 0;
}

