
/* WARNING: Type propagation algorithm not settling */

undefined4
ssl_parse_serverhello_tlsext
          (SSL *param_1,undefined4 *param_2,int param_3,int param_4,undefined4 *param_5)

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
  undefined *puVar9;
  uint uVar10;
  SSL_SESSION *pSVar11;
  SRTP_PROTECTION_PROFILE *pSVar12;
  undefined *puVar13;
  uint uVar14;
  SSL_SESSION *pSVar15;
  undefined *puVar16;
  undefined *puVar17;
  code *pcVar18;
  byte local_30 [4];
  void *local_2c [2];
  
  puVar9 = (undefined *)*param_2;
  pSVar12 = param_1->srtp_profile;
  param_1->s3->next_proto_neg_seen = 0;
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar12 & 0xfffffffc);
  if ((undefined *)(param_3 + param_4 + -2) <= puVar9) {
LAB_00055e1e:
    if ((param_1->references & 0x40004U) == 0) {
      *param_5 = 0x28;
      ERR_put_error(0x14,0x12f,0x152,"t1_lib.c",0x6bc);
      return 0;
    }
    return 1;
  }
  puVar17 = puVar9 + 2 + CONCAT11(*puVar9,puVar9[1]);
  if (puVar17 == (undefined *)(param_3 + param_4)) {
    bVar4 = false;
    bVar3 = false;
    puVar9 = puVar9 + 2;
LAB_00055e90:
    puVar13 = puVar9;
    if ((undefined *)(param_3 + param_4 + -4) < puVar13) {
      if (puVar13 != puVar17) goto LAB_00055e46;
      if (((param_1->hit == 0) && (bVar3)) && ((char *)param_1->tlsext_debug_arg != (char *)0x0)) {
        pSVar15 = param_1->session;
        if (*(int *)(pSVar15->krb5_client_princ + 0x40) != 0) goto LAB_00055e46;
        pcVar8 = BUF_strdup((char *)param_1->tlsext_debug_arg);
        pSVar11 = param_1->session;
        *(char **)(pSVar15->krb5_client_princ + 0x40) = pcVar8;
        if (*(int *)(pSVar11->krb5_client_princ + 0x40) == 0) goto LAB_00056126;
      }
      *param_2 = puVar13;
LAB_000560f2:
      if (bVar4) {
        return 1;
      }
      goto LAB_00055e1e;
    }
    puVar16 = puVar13 + 4;
    uVar10 = (uint)CONCAT11(puVar13[2],puVar13[3]);
    puVar9 = puVar16 + uVar10;
    sVar2 = CONCAT11(*puVar13,puVar13[1]);
    if (puVar17 < puVar9) goto LAB_000560f2;
    if ((code *)param_1->max_send_fragment != (code *)0x0) {
      (*(code *)param_1->max_send_fragment)(param_1,1,sVar2,puVar16,uVar10,param_1->tlsext_debug_cb)
      ;
    }
    if (sVar2 == 0) {
      if ((param_1->tlsext_debug_arg == (void *)0x0) || (uVar10 != 0)) {
LAB_00056126:
        *param_5 = 0x70;
        return 0;
      }
      bVar3 = true;
      goto LAB_00055e90;
    }
    if (sVar2 == 0xb) {
      if (param_1->version != 0xfeff) {
        uVar14 = (uint)(byte)puVar13[4];
        uVar10 = uVar10 - 1;
        if ((uVar10 != uVar14) || (uVar10 == 0)) goto LAB_00055e46;
        pSVar15 = param_1->session;
        *(undefined4 *)(pSVar15->krb5_client_princ + 0x44) = 0;
        if (*(void **)(pSVar15->krb5_client_princ + 0x48) != (void *)0x0) {
          CRYPTO_free(*(void **)(pSVar15->krb5_client_princ + 0x48));
          pSVar15 = param_1->session;
        }
        pvVar6 = CRYPTO_malloc(uVar10,"t1_lib.c",0x5fb);
        *(void **)(pSVar15->krb5_client_princ + 0x48) = pvVar6;
        if (pvVar6 == (void *)0x0) {
LAB_00056144:
          *param_5 = 0x50;
          return 0;
        }
        pSVar15 = param_1->session;
        *(uint *)(pSVar15->krb5_client_princ + 0x44) = uVar14;
        memcpy(*(void **)(pSVar15->krb5_client_princ + 0x48),puVar13 + 5,uVar14);
      }
      goto LAB_00055e90;
    }
    if (sVar2 == 0x23) {
      if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
         (iVar5 = (*(code *)param_1->tlsext_session_ticket)
                            (param_1,puVar16,uVar10,param_1->tls_session_ticket_ext_cb), iVar5 == 0)
         ) goto LAB_00056144;
      lVar7 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((lVar7 << 0x11 < 0) || (uVar10 != 0)) {
LAB_0005613a:
        *param_5 = 0x6e;
        return 0;
      }
      param_1->tlsext_ocsp_resplen = 1;
      goto LAB_00055e90;
    }
    if (sVar2 == 5) {
      if (param_1->version != 0xfeff) {
        if ((param_1->servername_done == -1) || (uVar10 != 0)) goto LAB_0005613a;
        param_1->tlsext_status_type = 1;
      }
      goto LAB_00055e90;
    }
    if (sVar2 == 0x3374) {
      uVar14 = (param_1->s3->tmp).finish_md_len;
      if (uVar14 == 0) {
        pcVar18 = *(code **)(param_1->psk_server_callback + 0x1ac);
        if (pcVar18 == (code *)0x0) {
          *param_5 = 0x6e;
          return 0;
        }
        if (uVar10 != 0) {
          bVar1 = puVar13[4];
          while( true ) {
            if (bVar1 == 0) goto LAB_00056156;
            uVar14 = uVar14 + bVar1 + 1;
            if (uVar10 <= uVar14) break;
            bVar1 = puVar16[uVar14];
          }
          if (uVar10 != uVar14) {
LAB_00056156:
            *param_5 = 0x32;
            return 0;
          }
        }
        iVar5 = (*pcVar18)(param_1,local_2c,local_30,puVar16,uVar10,
                           *(undefined4 *)(param_1->psk_server_callback + 0x1b0));
        if (iVar5 == 0) {
          __dest = (SSL_CTX *)CRYPTO_malloc((uint)local_30[0],"t1_lib.c",0x662);
          param_1->initial_ctx = __dest;
          if (__dest != (SSL_CTX *)0x0) {
            memcpy(__dest,local_2c[0],(uint)local_30[0]);
            *(byte *)&param_1->next_proto_negotiated = local_30[0];
            param_1->s3->next_proto_neg_seen = 1;
            goto LAB_00055e90;
          }
        }
        *param_5 = 0x50;
        return 0;
      }
      goto LAB_00055e90;
    }
    if (sVar2 == -0xff) {
      iVar5 = ssl_parse_serverhello_renegotiate_ext(param_1,puVar16,uVar10,param_5);
      if (iVar5 == 0) {
        return 0;
      }
      bVar4 = true;
      goto LAB_00055e90;
    }
    if (sVar2 == 0xf) {
      if (puVar13[4] == '\x01') {
        param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
      }
      else {
        if (puVar13[4] != '\x02') {
          *param_5 = 0x2f;
          return 0;
        }
        param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
      }
      goto LAB_00055e90;
    }
    if ((sVar2 != 0xe) ||
       (iVar5 = ssl_parse_serverhello_use_srtp_ext(param_1,puVar16,uVar10,param_5), iVar5 == 0))
    goto LAB_00055e90;
  }
  else {
LAB_00055e46:
    *param_5 = 0x32;
  }
  return 0;
}

