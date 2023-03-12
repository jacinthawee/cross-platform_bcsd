
void ssl_add_serverhello_tlsext(SSL *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  uint uVar2;
  long lVar3;
  undefined4 uVar4;
  int iVar5;
  int line;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  code *pcVar15;
  undefined4 *puVar16;
  void *local_50;
  size_t local_4c;
  undefined4 local_48 [8];
  undefined4 uStack_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if ((param_1->version == 0x300) && (puVar10 = param_2, param_1->s3->send_connection_binding == 0))
  goto LAB_0005324a;
  puVar10 = (undefined4 *)((int)param_2 + 2);
  if (puVar10 < param_3) {
    if (((param_1->hit == 0) && (param_1->tlsext_hostname == (char *)0x1)) &&
       (*(int *)(param_1->session->krb5_client_princ + 0x40) != 0)) {
      if ((int)param_3 - (int)puVar10 < 4) goto LAB_000532fc;
      puVar10 = (undefined4 *)((int)param_2 + 6);
      *(undefined *)((int)param_2 + 2) = 0;
      *(undefined *)((int)param_2 + 3) = 0;
      *(undefined *)(param_2 + 1) = 0;
      *(undefined *)((int)param_2 + 5) = 0;
    }
    if (param_1->s3->send_connection_binding == 0) {
LAB_000530fa:
      if (param_1->tlsext_ecpointformatlist_length != 0) {
        puVar7 = (undefined *)((int)param_3 + (-5 - (int)puVar10));
        if (((int)puVar7 < 0) || (puVar7 < (undefined *)param_1->tlsext_ticket_expected))
        goto LAB_000532fc;
        if ((undefined *)0xff < (undefined *)param_1->tlsext_ticket_expected) {
          ERR_put_error(0x14,0x116,0x44,"t1_lib.c",0x2fe);
          puVar10 = (undefined4 *)0x0;
          goto LAB_0005324a;
        }
        *(undefined *)puVar10 = 0;
        *(undefined *)((int)puVar10 + 1) = 0xb;
        *(char *)((int)puVar10 + 2) = (char)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
        *(char *)((int)puVar10 + 3) = (char)param_1->tlsext_ticket_expected + '\x01';
        *(char *)(puVar10 + 1) = (char)param_1->tlsext_ticket_expected;
        pvVar1 = memcpy((undefined *)((int)puVar10 + 5),
                        (void *)param_1->tlsext_ecpointformatlist_length,
                        param_1->tlsext_ticket_expected);
        puVar10 = (undefined4 *)(param_1->tlsext_ticket_expected + (int)pvVar1);
      }
      puVar11 = puVar10;
      if ((param_1->tlsext_ocsp_resplen != 0) &&
         (uVar2 = SSL_ctrl(param_1,0x20,0,(void *)0x0), (uVar2 & 0x4000) == 0)) {
        if ((int)param_3 - (int)puVar10 < 4) goto LAB_000532fc;
        *(undefined *)puVar10 = 0;
        *(undefined *)((int)puVar10 + 2) = 0;
        puVar11 = puVar10 + 1;
        *(undefined *)((int)puVar10 + 3) = 0;
        *(undefined *)((int)puVar10 + 1) = 0x23;
      }
      puVar10 = puVar11;
      if (param_1->tlsext_status_type != 0) {
        if ((int)param_3 - (int)puVar11 < 4) goto LAB_000532fc;
        *(undefined *)puVar11 = 0;
        puVar10 = puVar11 + 1;
        *(undefined *)((int)puVar11 + 2) = 0;
        *(undefined *)((int)puVar11 + 3) = 0;
        *(undefined *)((int)puVar11 + 1) = 5;
      }
      if ((param_1->method->version == 0xfeff) &&
         (param_1->srtp_profiles != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) {
        ssl_add_serverhello_use_srtp_ext(param_1,0,&local_4c,0);
        if ((int)((int)param_3 + (-local_4c - (int)puVar10) + -4) < 0) goto LAB_000532fc;
        *(char *)((int)puVar10 + 3) = (char)local_4c;
        *(undefined *)puVar10 = 0;
        *(undefined *)((int)puVar10 + 1) = 0xe;
        *(char *)((int)puVar10 + 2) = (char)(local_4c >> 8);
        iVar5 = ssl_add_serverhello_use_srtp_ext(param_1,puVar10 + 1,&local_4c);
        line = 0x33b;
        if (iVar5 != 0) goto LAB_000532ea;
        puVar10 = (undefined4 *)(local_4c + (int)(puVar10 + 1));
      }
      if ((*(ushort *)&((param_1->s3->tmp).new_cipher)->id - 0x80 < 2) &&
         (lVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar3 < 0)) {
        puVar14 = (undefined4 *)(PTR_DAT_00053430 + 0x20);
        puVar11 = local_48;
        puVar13 = (undefined4 *)PTR_DAT_00053430;
        do {
          puVar16 = puVar13 + 4;
          uVar4 = puVar13[1];
          uVar6 = puVar13[2];
          puVar12 = puVar11 + 4;
          uVar8 = puVar13[3];
          *puVar11 = *puVar13;
          puVar11[1] = uVar4;
          puVar11[2] = uVar6;
          puVar11[3] = uVar8;
          puVar11 = puVar12;
          puVar13 = puVar16;
        } while (puVar16 != puVar14);
        if (0x23 < (int)param_3 - (int)puVar10) {
          puVar14 = &uStack_28;
        }
        *puVar12 = *puVar16;
        if ((int)param_3 - (int)puVar10 < 0x24) goto LAB_000532fc;
        puVar13 = local_48;
        puVar11 = puVar10;
        do {
          puVar12 = puVar11 + 4;
          uVar4 = *puVar13;
          uVar6 = puVar13[1];
          uVar8 = puVar13[2];
          uVar9 = puVar13[3];
          puVar16 = puVar13 + 4;
          puVar13 = puVar13 + 4;
          *puVar11 = uVar4;
          puVar11[1] = uVar6;
          puVar11[2] = uVar8;
          puVar11[3] = uVar9;
          puVar11 = puVar12;
        } while (puVar16 != puVar14);
        puVar10 = puVar10 + 9;
        *puVar12 = *puVar13;
      }
      puVar11 = puVar10;
      if ((int)param_1->srtp_profile << 0x1f < 0) {
        if ((int)param_3 - (int)puVar10 < 5) goto LAB_000532fc;
        *(undefined *)puVar10 = 0;
        *(undefined *)((int)puVar10 + 2) = 0;
        puVar11 = (undefined4 *)((int)puVar10 + 5);
        *(undefined *)((int)puVar10 + 1) = 0xf;
        *(undefined *)((int)puVar10 + 3) = 1;
        if ((int)param_1->srtp_profile << 0x1d < 0) {
          *(undefined *)(puVar10 + 1) = 2;
        }
        else {
          *(undefined *)(puVar10 + 1) = 1;
        }
      }
      iVar5 = param_1->s3->next_proto_neg_seen;
      param_1->s3->next_proto_neg_seen = 0;
      if (iVar5 != 0) {
        pcVar15 = *(code **)(param_1->psk_server_callback + 0x1a4);
        if ((pcVar15 != (code *)0x0) &&
           (puVar10 = (undefined4 *)
                      (*pcVar15)(param_1,&local_50,&local_4c,
                                 *(undefined4 *)(param_1->psk_server_callback + 0x1a8)),
           puVar10 == (undefined4 *)0x0)) {
          if ((int)((int)param_3 + ((-4 - local_4c) - (int)puVar11)) < 0) goto LAB_0005324a;
          puVar10 = puVar11 + 1;
          *(char *)((int)puVar11 + 3) = (char)local_4c;
          *(undefined *)puVar11 = 0x33;
          *(undefined *)((int)puVar11 + 1) = 0x74;
          *(char *)((int)puVar11 + 2) = (char)(local_4c >> 8);
          puVar11 = (undefined4 *)((int)puVar10 + local_4c);
          memcpy(puVar10,local_50,local_4c);
          param_1->s3->next_proto_neg_seen = 1;
        }
      }
      puVar7 = (undefined *)((int)puVar11 + (-2 - (int)param_2));
      puVar10 = param_2;
      if (puVar7 != (undefined *)0x0) {
        *(char *)((int)param_2 + 1) = (char)puVar7;
        *(char *)param_2 = (char)((uint)puVar7 >> 8);
        puVar10 = puVar11;
      }
      goto LAB_0005324a;
    }
    iVar5 = ssl_add_serverhello_renegotiate_ext(param_1,0,&local_4c,0);
    line = 0x2e1;
    if (iVar5 != 0) {
      if ((int)((int)param_3 + (-local_4c - (int)puVar10) + -4) < 0) goto LAB_000532fc;
      *(char *)((int)puVar10 + 3) = (char)local_4c;
      *(undefined *)puVar10 = 0xff;
      *(undefined *)((int)puVar10 + 1) = 1;
      *(char *)((int)puVar10 + 2) = (char)(local_4c >> 8);
      iVar5 = ssl_add_serverhello_renegotiate_ext(param_1,puVar10 + 1,&local_4c);
      puVar10 = (undefined4 *)(local_4c + (int)(puVar10 + 1));
      if (iVar5 != 0) goto LAB_000530fa;
      line = 0x2ec;
    }
LAB_000532ea:
    ERR_put_error(0x14,0x116,0x44,"t1_lib.c",line);
  }
LAB_000532fc:
  puVar10 = (undefined4 *)0x0;
LAB_0005324a:
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar10);
}

