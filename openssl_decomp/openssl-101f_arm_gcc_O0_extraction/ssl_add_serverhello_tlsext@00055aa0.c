
void ssl_add_serverhello_tlsext(SSL *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  code *pcVar16;
  undefined4 *puVar17;
  void *local_50;
  size_t local_4c;
  undefined4 local_48 [8];
  undefined4 uStack_28;
  int local_24;
  
  local_24 = __TMC_END__;
  if ((param_1->version == 0x300) && (puVar11 = param_2, param_1->s3->send_connection_binding == 0))
  goto LAB_00055c72;
  puVar11 = (undefined4 *)((int)param_2 + 2);
  if (puVar11 < param_3) {
    if (((param_1->hit == 0) && (param_1->tlsext_hostname == (char *)0x1)) &&
       (*(int *)(param_1->session->krb5_client_princ + 0x40) != 0)) {
      if ((int)param_3 - (int)puVar11 < 4) goto LAB_00055cd8;
      puVar11 = (undefined4 *)((int)param_2 + 6);
      *(undefined *)((int)param_2 + 2) = 0;
      *(undefined *)((int)param_2 + 3) = 0;
      *(undefined *)(param_2 + 1) = 0;
      *(undefined *)((int)param_2 + 5) = 0;
    }
    if (param_1->s3->send_connection_binding == 0) {
LAB_00055ade:
      if ((param_1->tlsext_ecpointformatlist_length != 0) && (param_1->version != 0xfeff)) {
        puVar8 = (undefined *)((int)param_3 + (-5 - (int)puVar11));
        if (((int)puVar8 < 0) || (puVar8 < (undefined *)param_1->tlsext_ticket_expected))
        goto LAB_00055cd8;
        if ((undefined *)0xff < (undefined *)param_1->tlsext_ticket_expected) {
          iVar6 = 0x2da;
          goto LAB_00055cc6;
        }
        *(undefined *)puVar11 = 0;
        *(undefined *)((int)puVar11 + 1) = 0xb;
        *(char *)((int)puVar11 + 2) = (char)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
        *(char *)((int)puVar11 + 3) = (char)param_1->tlsext_ticket_expected + '\x01';
        *(char *)(puVar11 + 1) = (char)param_1->tlsext_ticket_expected;
        pvVar1 = memcpy((undefined *)((int)puVar11 + 5),
                        (void *)param_1->tlsext_ecpointformatlist_length,
                        param_1->tlsext_ticket_expected);
        puVar11 = (undefined4 *)(param_1->tlsext_ticket_expected + (int)pvVar1);
      }
      puVar12 = puVar11;
      if ((param_1->tlsext_ocsp_resplen != 0) &&
         (uVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0), (uVar3 & 0x4000) == 0)) {
        if ((int)param_3 - (int)puVar11 < 4) goto LAB_00055cd8;
        *(undefined *)puVar11 = 0;
        *(undefined *)((int)puVar11 + 2) = 0;
        puVar12 = puVar11 + 1;
        *(undefined *)((int)puVar11 + 3) = 0;
        *(undefined *)((int)puVar11 + 1) = 0x23;
      }
      puVar11 = puVar12;
      if (param_1->tlsext_status_type != 0) {
        if ((int)param_3 - (int)puVar12 < 4) goto LAB_00055cd8;
        *(undefined *)puVar12 = 0;
        puVar11 = puVar12 + 1;
        *(undefined *)((int)puVar12 + 2) = 0;
        *(undefined *)((int)puVar12 + 3) = 0;
        *(undefined *)((int)puVar12 + 1) = 5;
      }
      if (param_1->srtp_profiles != (stack_st_SRTP_PROTECTION_PROFILE *)0x0) {
        ssl_add_serverhello_use_srtp_ext(param_1,0,&local_4c,0);
        if ((int)((int)param_3 + (-local_4c - (int)param_2) + -4) < 0) goto LAB_00055cd8;
        *(char *)((int)puVar11 + 3) = (char)local_4c;
        *(undefined *)puVar11 = 0;
        *(undefined *)((int)puVar11 + 1) = 0xe;
        *(char *)((int)puVar11 + 2) = (char)(local_4c >> 8);
        iVar2 = ssl_add_serverhello_use_srtp_ext(param_1,puVar11 + 1,&local_4c);
        iVar6 = 0x318;
        if (iVar2 != 0) goto LAB_00055cc6;
        puVar11 = (undefined4 *)(local_4c + (int)(puVar11 + 1));
      }
      if ((*(ushort *)&((param_1->s3->tmp).new_cipher)->id - 0x80 < 2) &&
         (lVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar4 < 0)) {
        puVar15 = (undefined4 *)(PTR_DAT_00055df0 + 0x20);
        puVar12 = local_48;
        puVar14 = (undefined4 *)PTR_DAT_00055df0;
        do {
          puVar17 = puVar14 + 4;
          uVar5 = puVar14[1];
          uVar7 = puVar14[2];
          puVar13 = puVar12 + 4;
          uVar9 = puVar14[3];
          *puVar12 = *puVar14;
          puVar12[1] = uVar5;
          puVar12[2] = uVar7;
          puVar12[3] = uVar9;
          puVar12 = puVar13;
          puVar14 = puVar17;
        } while (puVar17 != puVar15);
        if (0x23 < (int)param_3 - (int)puVar11) {
          puVar15 = &uStack_28;
        }
        *puVar13 = *puVar17;
        if ((int)param_3 - (int)puVar11 < 0x24) goto LAB_00055cd8;
        puVar14 = local_48;
        puVar12 = puVar11;
        do {
          puVar13 = puVar12 + 4;
          uVar5 = *puVar14;
          uVar7 = puVar14[1];
          uVar9 = puVar14[2];
          uVar10 = puVar14[3];
          puVar17 = puVar14 + 4;
          puVar14 = puVar14 + 4;
          *puVar12 = uVar5;
          puVar12[1] = uVar7;
          puVar12[2] = uVar9;
          puVar12[3] = uVar10;
          puVar12 = puVar13;
        } while (puVar17 != puVar15);
        puVar11 = puVar11 + 9;
        *puVar13 = *puVar14;
      }
      puVar12 = puVar11;
      if ((int)param_1->srtp_profile << 0x1f < 0) {
        *(undefined *)puVar11 = 0;
        *(undefined *)((int)puVar11 + 2) = 0;
        puVar12 = (undefined4 *)((int)puVar11 + 5);
        *(undefined *)((int)puVar11 + 1) = 0xf;
        *(undefined *)((int)puVar11 + 3) = 1;
        if ((int)param_1->srtp_profile << 0x1d < 0) {
          *(undefined *)(puVar11 + 1) = 2;
        }
        else {
          *(undefined *)(puVar11 + 1) = 1;
        }
      }
      iVar6 = param_1->s3->next_proto_neg_seen;
      param_1->s3->next_proto_neg_seen = 0;
      if (iVar6 != 0) {
        pcVar16 = *(code **)(param_1->psk_server_callback + 0x1a4);
        if ((pcVar16 != (code *)0x0) &&
           (puVar11 = (undefined4 *)
                      (*pcVar16)(param_1,&local_50,&local_4c,
                                 *(undefined4 *)(param_1->psk_server_callback + 0x1a8)),
           puVar11 == (undefined4 *)0x0)) {
          if ((int)((int)param_3 + ((-4 - local_4c) - (int)puVar12)) < 0) goto LAB_00055c72;
          puVar11 = puVar12 + 1;
          *(char *)((int)puVar12 + 3) = (char)local_4c;
          *(undefined *)puVar12 = 0x33;
          *(undefined *)((int)puVar12 + 1) = 0x74;
          *(char *)((int)puVar12 + 2) = (char)(local_4c >> 8);
          puVar12 = (undefined4 *)((int)puVar11 + local_4c);
          memcpy(puVar11,local_50,local_4c);
          param_1->s3->next_proto_neg_seen = 1;
        }
      }
      puVar8 = (undefined *)((int)puVar12 + (-2 - (int)param_2));
      puVar11 = param_2;
      if (puVar8 != (undefined *)0x0) {
        *(char *)((int)param_2 + 1) = (char)puVar8;
        *(char *)param_2 = (char)((uint)puVar8 >> 8);
        puVar11 = puVar12;
      }
      goto LAB_00055c72;
    }
    iVar2 = ssl_add_serverhello_renegotiate_ext(param_1,0,&local_4c,0);
    iVar6 = 0x2bd;
    if (iVar2 != 0) {
      if ((int)((int)param_3 + (-local_4c - (int)param_2) + -4) < 0) goto LAB_00055cd8;
      *(char *)((int)puVar11 + 3) = (char)local_4c;
      *(undefined *)puVar11 = 0xff;
      *(undefined *)((int)puVar11 + 1) = 1;
      *(char *)((int)puVar11 + 2) = (char)(local_4c >> 8);
      iVar2 = ssl_add_serverhello_renegotiate_ext(param_1,puVar11 + 1,&local_4c);
      iVar6 = 0x2c8;
      if (iVar2 != 0) {
        puVar11 = (undefined4 *)(local_4c + (int)(puVar11 + 1));
        goto LAB_00055ade;
      }
    }
LAB_00055cc6:
    ERR_put_error(0x14,0x116,0x44,"t1_lib.c",iVar6);
  }
LAB_00055cd8:
  puVar11 = (undefined4 *)0x0;
LAB_00055c72:
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar11);
}

