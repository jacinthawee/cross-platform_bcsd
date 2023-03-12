
long msg_cb(int param_1,int param_2,int param_3,byte *param_4,uint param_5,undefined4 param_6,
           BIO *param_7)

{
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var1;
  uint uVar2;
  long lVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined *puVar6;
  uint uVar7;
  char *local_2c;
  char *local_28;
  char *local_20;
  
  puVar6 = &UNK_081f8146;
  if (param_1 == 0) {
    puVar6 = &UNK_081f814a;
  }
  if (param_2 == 0x301) {
    local_28 = "TLS 1.0 ";
LAB_0807da10:
    local_2c = "";
    local_20 = "";
    goto LAB_0807da20;
  }
  if (0x301 < param_2) {
    if (param_2 == 0x303) {
      local_28 = "TLS 1.2 ";
    }
    else if (param_2 < 0x303) {
      local_28 = "TLS 1.1 ";
    }
    else {
      local_28 = "DTLS 1.0 ";
      if (param_2 != 0xfeff) {
        if (param_2 == 2) {
          if (param_5 != 0) {
            local_28 = "???";
            goto LAB_0807dc40;
          }
          local_2c = "";
          pcVar5 = "???";
          puVar4 = &DAT_081ec74a;
          local_28 = "???";
          goto LAB_0807dcc8;
        }
        goto LAB_0807dabb;
      }
    }
    goto LAB_0807da10;
  }
  if (param_2 == 0x100) {
    local_28 = "DTLS 1.0 (bad) ";
    goto LAB_0807da10;
  }
  if (param_2 == 0x300) {
    local_28 = "SSL 3.0 ";
    goto LAB_0807da10;
  }
  if (param_2 != 2) {
LAB_0807dabb:
    local_28 = "???";
    local_2c = "";
    local_20 = "";
    goto LAB_0807da20;
  }
  if (param_5 == 0) {
    local_2c = "";
    pcVar5 = "???";
    puVar4 = &DAT_081ec74a;
    local_28 = "SSL 2.0";
LAB_0807dcc8:
    BIO_printf(param_7,"%s %s%s [length %04lx]%s%s\n",puVar6,local_28,puVar4,0,pcVar5,local_2c);
    goto BIO_ctrl;
  }
  local_28 = "SSL 2.0";
LAB_0807dc40:
  if (8 < *param_4) {
    local_2c = "";
    local_20 = "???";
    goto LAB_0807da20;
  }
  switch(*param_4) {
  case 0:
    if ((param_5 < 3) || (uVar7 = (uint)param_4[1] * 0x100 + -1 + (uint)param_4[2], 5 < uVar7)) {
      local_2c = " ???";
      local_20 = ", ERROR:";
    }
    else {
      local_2c = *(char **)(CSWTCH_26 + uVar7 * 4);
      local_20 = ", ERROR:";
    }
    break;
  case 1:
    local_2c = "";
    local_20 = ", CLIENT-HELLO";
    puVar4 = &DAT_081ec74a;
    goto LAB_0807da52;
  case 2:
    local_2c = "";
    local_20 = ", CLIENT-MASTER-KEY";
    break;
  case 3:
    local_2c = "";
    local_20 = ", CLIENT-FINISHED";
    break;
  case 4:
    local_2c = "";
    local_20 = ", SERVER-HELLO";
    break;
  case 5:
    local_2c = "";
    local_20 = ", SERVER-VERIFY";
    break;
  case 6:
    local_2c = "";
    local_20 = ", SERVER-FINISHED";
    break;
  case 7:
    local_2c = "";
    local_20 = ", REQUEST-CERTIFICATE";
    break;
  case 8:
    local_2c = "";
    local_20 = ", CLIENT-CERTIFICATE";
  }
LAB_0807da20:
  if ((param_2 == 0x100 || param_2 == 0xfeff) || (puVar4 = &DAT_081ec74a, param_2 - 0x300U < 4)) {
    if (param_3 - 0x14U < 3) {
      puVar4 = *(undefined1 **)(CSWTCH_27 + (param_3 - 0x14U) * 4);
      if (param_3 != 0x15) {
        if (param_3 != 0x16) goto LAB_0807db75;
        if (param_5 == 0) {
          pcVar5 = "???";
          goto LAB_0807dcc8;
        }
        pcVar5 = "???";
        if (*param_4 < 0x15) {
          pcVar5 = *(char **)(CSWTCH_28 + (uint)*param_4 * 4);
        }
        goto LAB_0807dbaa;
      }
      local_20 = ", ???";
      if (param_5 == 2) {
        local_20 = ", warning";
        if ((*param_4 != 1) && (local_20 = ", ???", *param_4 == 2)) {
          local_20 = ", fatal";
        }
        switch(param_4[1]) {
        case 0:
          local_2c = " close_notify";
          break;
        default:
          local_2c = " ???";
          break;
        case 10:
          local_2c = " unexpected_message";
          break;
        case 0x14:
          local_2c = " bad_record_mac";
          break;
        case 0x15:
          local_2c = " decryption_failed";
          break;
        case 0x16:
          local_2c = " record_overflow";
          break;
        case 0x1e:
          local_2c = " decompression_failure";
          break;
        case 0x28:
          local_2c = " handshake_failure";
          break;
        case 0x2a:
          local_2c = " bad_certificate";
          break;
        case 0x2b:
          local_2c = " unsupported_certificate";
          break;
        case 0x2c:
          local_2c = " certificate_revoked";
          break;
        case 0x2d:
          local_2c = " certificate_expired";
          break;
        case 0x2e:
          local_2c = " certificate_unknown";
          break;
        case 0x2f:
          local_2c = " illegal_parameter";
          break;
        case 0x30:
          local_2c = " unknown_ca";
          break;
        case 0x31:
          local_2c = " access_denied";
          break;
        case 0x32:
          local_2c = " decode_error";
          break;
        case 0x33:
          local_2c = " decrypt_error";
          break;
        case 0x3c:
          local_2c = " export_restriction";
          break;
        case 0x46:
          local_2c = " protocol_version";
          break;
        case 0x47:
          local_2c = " insufficient_security";
          break;
        case 0x50:
          local_2c = " internal_error";
          break;
        case 0x5a:
          local_2c = " user_canceled";
          break;
        case 100:
          local_2c = " no_renegotiation";
          break;
        case 0x6e:
          local_2c = " unsupported_extension";
          break;
        case 0x6f:
          local_2c = " certificate_unobtainable";
          break;
        case 0x70:
          local_2c = " unrecognized_name";
          break;
        case 0x71:
          local_2c = " bad_certificate_status_response";
          break;
        case 0x72:
          local_2c = " bad_certificate_hash_value";
          break;
        case 0x73:
          local_2c = " unknown_psk_identity";
        }
      }
      goto LAB_0807da52;
    }
    puVar4 = &DAT_081ec74a;
LAB_0807db75:
    if (param_3 != 0x18) goto LAB_0807da52;
    if (param_5 == 0) {
      pcVar5 = ", Heartbeat";
      goto LAB_0807dcc8;
    }
    pcVar5 = ", HeartbeatRequest";
    if ((*param_4 != 1) && (pcVar5 = ", Heartbeat", *param_4 == 2)) {
      pcVar5 = ", HeartbeatResponse";
    }
LAB_0807dbaa:
    BIO_printf(param_7,"%s %s%s [length %04lx]%s%s\n",puVar6,local_28,puVar4,param_5,pcVar5,local_2c
              );
  }
  else {
LAB_0807da52:
    BIO_printf(param_7,"%s %s%s [length %04lx]%s%s\n",puVar6,local_28,puVar4,param_5,local_20,
               local_2c);
    if (param_5 == 0) goto BIO_ctrl;
  }
  uVar7 = 0;
  BIO_printf(param_7,"   ");
  while( true ) {
    uVar2 = (uint)param_4[uVar7];
    uVar7 = uVar7 + 1;
    BIO_printf(param_7," %02x",uVar2);
    if (param_5 <= uVar7) break;
    if (((uVar7 & 0xf) == 0) && (uVar7 != 0)) {
      BIO_printf(param_7,"\n   ",uVar2);
    }
  }
  BIO_printf(param_7,"\n",uVar2);
BIO_ctrl:
  if (param_7 == (BIO *)0x0) {
    return 0;
  }
  if ((param_7->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = param_7->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    lVar3 = -2;
  }
  else {
    p_Var1 = param_7->callback;
    if (p_Var1 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08117b57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar3 = (*UNRECOVERED_JUMPTABLE)(param_7,0xb,0,(void *)0x0);
      return lVar3;
    }
    lVar3 = (*p_Var1)(param_7,6,(char *)0x0,0xb,0,1);
    if (0 < lVar3) {
      lVar3 = (*param_7->method->ctrl)(param_7,0xb,0,(void *)0x0);
      lVar3 = (*p_Var1)(param_7,0x86,(char *)0x0,0xb,0,lVar3);
    }
  }
  return lVar3;
}

