
undefined * ssl_add_serverhello_tlsext(SSL *param_1,undefined *param_2,undefined *param_3)

{
  code *pcVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined *puVar6;
  undefined *puVar7;
  int in_GS_OFFSET;
  void *local_28;
  size_t local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((param_1->version == 0x300) && (puVar6 = param_2, param_1->s3->send_connection_binding == 0))
  goto LAB_080ab68a;
  puVar6 = param_2 + 2;
  if (puVar6 < param_3) {
    if (((param_1->hit == 0) && (param_1->tlsext_hostname == (char *)0x1)) &&
       (*(int *)(param_1->session->krb5_client_princ + 0x40) != 0)) {
      if ((int)param_3 - (int)puVar6 < 4) goto LAB_080ab726;
      param_2[2] = 0;
      param_2[3] = 0;
      puVar6 = param_2 + 6;
      param_2[4] = 0;
      param_2[5] = 0;
    }
    if (param_1->s3->send_connection_binding == 0) {
LAB_080ab4c2:
      if (param_1->tlsext_ecpointformatlist_length != 0) {
        if (((int)(param_3 + (-5 - (int)puVar6)) < 0) ||
           (param_3 + (-5 - (int)puVar6) < (undefined *)param_1->tlsext_ticket_expected))
        goto LAB_080ab726;
        if ((undefined *)0xff < (undefined *)param_1->tlsext_ticket_expected) {
          iVar4 = 0x2fe;
          goto LAB_080ab710;
        }
        *puVar6 = 0;
        puVar6[1] = 0xb;
        puVar6[2] = (char)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
        puVar6[3] = *(char *)&param_1->tlsext_ticket_expected + '\x01';
        puVar6[4] = (char)param_1->tlsext_ticket_expected;
        memcpy(puVar6 + 5,(void *)param_1->tlsext_ecpointformatlist_length,
               param_1->tlsext_ticket_expected);
        puVar6 = puVar6 + 5 + param_1->tlsext_ticket_expected;
      }
      puVar7 = puVar6;
      if ((param_1->tlsext_ocsp_resplen != 0) &&
         (uVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0), (uVar3 & 0x4000) == 0)) {
        if ((int)param_3 - (int)puVar6 < 4) goto LAB_080ab726;
        *puVar6 = 0;
        puVar6[1] = 0x23;
        puVar7 = puVar6 + 4;
        puVar6[2] = 0;
        puVar6[3] = 0;
      }
      puVar6 = puVar7;
      if (param_1->tlsext_status_type != 0) {
        if ((int)param_3 - (int)puVar7 < 4) goto LAB_080ab726;
        *puVar7 = 0;
        puVar7[1] = 5;
        puVar6 = puVar7 + 4;
        puVar7[2] = 0;
        puVar7[3] = 0;
      }
      if ((param_1->method->version == 0xfeff) &&
         (param_1->srtp_profiles != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) {
        ssl_add_serverhello_use_srtp_ext(param_1,0,&local_24,0);
        if ((int)(param_3 + ((-4 - (int)puVar6) - local_24)) < 0) goto LAB_080ab726;
        *puVar6 = 0;
        puVar6[1] = 0xe;
        puVar6[3] = (char)local_24;
        puVar6[2] = (char)(local_24 >> 8);
        iVar4 = ssl_add_serverhello_use_srtp_ext(param_1,puVar6 + 4,&local_24,local_24);
        puVar6 = puVar6 + 4 + local_24;
        if (iVar4 != 0) {
          iVar4 = 0x33b;
          goto LAB_080ab710;
        }
      }
      puVar7 = puVar6;
      if ((*(ushort *)&((param_1->s3->tmp).new_cipher)->id - 0x80 < 2) &&
         (lVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar5 < 0)) {
        if ((int)param_3 - (int)puVar6 < 0x24) goto LAB_080ab726;
        *puVar6 = 0xfd;
        puVar6[1] = 0xe8;
        puVar7 = puVar6 + 0x24;
        puVar6[2] = 0;
        puVar6[3] = 0x20;
        puVar6[4] = 0x30;
        puVar6[5] = 0x1e;
        puVar6[6] = 0x30;
        puVar6[7] = 8;
        puVar6[8] = 6;
        puVar6[9] = 6;
        puVar6[10] = 0x2a;
        puVar6[0xb] = 0x85;
        puVar6[0xc] = 3;
        puVar6[0xd] = 2;
        puVar6[0xe] = 2;
        puVar6[0xf] = 9;
        puVar6[0x10] = 0x30;
        puVar6[0x11] = 8;
        puVar6[0x12] = 6;
        puVar6[0x13] = 6;
        puVar6[0x14] = 0x2a;
        puVar6[0x15] = 0x85;
        puVar6[0x16] = 3;
        puVar6[0x17] = 2;
        puVar6[0x18] = 2;
        puVar6[0x19] = 0x16;
        puVar6[0x1a] = 0x30;
        puVar6[0x1b] = 8;
        puVar6[0x1c] = 6;
        puVar6[0x1d] = 6;
        puVar6[0x1e] = 0x2a;
        puVar6[0x1f] = 0x85;
        puVar6[0x20] = 3;
        puVar6[0x21] = 2;
        puVar6[0x22] = 2;
        puVar6[0x23] = 0x17;
      }
      if ((*(byte *)&param_1->srtp_profile & 1) != 0) {
        if ((int)param_3 - (int)puVar7 < 5) goto LAB_080ab726;
        *puVar7 = 0;
        puVar7[1] = 0xf;
        puVar7[2] = 0;
        puVar7[3] = 1;
        if ((*(byte *)&param_1->srtp_profile & 4) == 0) {
          puVar7[4] = 1;
          puVar7 = puVar7 + 5;
        }
        else {
          puVar7[4] = 2;
          puVar7 = puVar7 + 5;
        }
      }
      iVar4 = param_1->s3->next_proto_neg_seen;
      param_1->s3->next_proto_neg_seen = 0;
      if (iVar4 != 0) {
        pcVar1 = *(code **)(param_1->psk_server_callback + 0x1a4);
        if ((pcVar1 != (code *)0x0) &&
           (puVar6 = (undefined *)
                     (*pcVar1)(param_1,&local_28,&local_24,
                               *(undefined4 *)(param_1->psk_server_callback + 0x1a8)),
           puVar6 == (undefined *)0x0)) {
          if ((int)(param_3 + (-local_24 - (int)puVar7) + -4) < 0) goto LAB_080ab68a;
          puVar7[3] = (char)local_24;
          *puVar7 = 0x33;
          puVar7[1] = 0x74;
          puVar7[2] = (char)(local_24 >> 8);
          memcpy(puVar7 + 4,local_28,local_24);
          puVar7 = puVar7 + 4 + local_24;
          param_1->s3->next_proto_neg_seen = 1;
        }
      }
      puVar2 = puVar7 + (-2 - (int)param_2);
      puVar6 = param_2;
      if (puVar2 != (undefined *)0x0) {
        param_2[1] = (char)puVar2;
        *param_2 = (char)((uint)puVar2 >> 8);
        puVar6 = puVar7;
      }
      goto LAB_080ab68a;
    }
    iVar4 = ssl_add_serverhello_renegotiate_ext(param_1,0,&local_24,0);
    if (iVar4 == 0) {
      iVar4 = 0x2e1;
    }
    else {
      if ((int)(param_3 + ((-4 - (int)puVar6) - local_24)) < 0) goto LAB_080ab726;
      *puVar6 = 0xff;
      puVar6[1] = 1;
      puVar6[3] = (char)local_24;
      puVar6[2] = (char)(local_24 >> 8);
      iVar4 = ssl_add_serverhello_renegotiate_ext(param_1,puVar6 + 4,&local_24,local_24);
      puVar6 = puVar6 + 4 + local_24;
      if (iVar4 != 0) goto LAB_080ab4c2;
      iVar4 = 0x2ec;
    }
LAB_080ab710:
    ERR_put_error(0x14,0x116,0x44,"t1_lib.c",iVar4);
  }
LAB_080ab726:
  puVar6 = (undefined *)0x0;
LAB_080ab68a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar6;
}

