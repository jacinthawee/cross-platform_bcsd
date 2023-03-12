
void msg_cb(int param_1,uint param_2,int param_3,byte *param_4,uint param_5,undefined4 param_6,
           BIO *param_7)

{
  byte *pbVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  undefined *puVar6;
  char *pcVar7;
  bool bVar8;
  
  puVar6 = &UNK_001328c8;
  if (param_1 != 0) {
    puVar6 = &UNK_001328c4;
  }
  if (param_2 == 0x301) {
    pcVar3 = "TLS 1.0 ";
LAB_000359e4:
    pcVar4 = "";
    pcVar7 = pcVar4;
  }
  else {
    if (0x301 < (int)param_2) {
      if (param_2 == 0x303) {
        pcVar3 = "TLS 1.2 ";
      }
      else if ((int)param_2 < 0x303) {
        pcVar3 = "TLS 1.1 ";
      }
      else {
        if (param_2 != 0xfeff) {
          if (param_2 == 2) {
            pcVar3 = "???";
            goto LAB_00035c90;
          }
          goto LAB_00035a56;
        }
        pcVar3 = "DTLS 1.0 ";
      }
      goto LAB_000359e4;
    }
    if (param_2 == 0x100) {
      pcVar3 = "DTLS 1.0 (bad) ";
      goto LAB_000359e4;
    }
    if (param_2 == 0x300) {
      pcVar3 = "SSL 3.0 ";
      goto LAB_000359e4;
    }
    if (param_2 != 2) {
LAB_00035a56:
      pcVar4 = "";
      pcVar3 = "???";
      pcVar7 = pcVar4;
      goto LAB_000359ee;
    }
    pcVar3 = "SSL 2.0";
LAB_00035c90:
    if (param_5 == 0) {
switchD_00035c98_caseD_9:
      pcVar4 = "";
      pcVar7 = "???";
    }
    else {
      switch(*param_4) {
      case 0:
        if ((param_5 < 3) || (uVar5 = ((uint)param_4[2] + (uint)param_4[1] * 0x100) - 1, 5 < uVar5))
        {
          pcVar4 = " ???";
          pcVar7 = ", ERROR:";
        }
        else {
          pcVar7 = ", ERROR:";
          pcVar4 = (&CSWTCH_26)[uVar5];
        }
        break;
      case 1:
        pcVar4 = "";
        pcVar7 = ", CLIENT-HELLO";
        break;
      case 2:
        pcVar4 = "";
        pcVar7 = ", CLIENT-MASTER-KEY";
        break;
      case 3:
        pcVar4 = "";
        pcVar7 = ", CLIENT-FINISHED";
        break;
      case 4:
        pcVar4 = "";
        pcVar7 = ", SERVER-HELLO";
        break;
      case 5:
        pcVar4 = "";
        pcVar7 = ", SERVER-VERIFY";
        break;
      case 6:
        pcVar4 = "";
        pcVar7 = ", SERVER-FINISHED";
        break;
      case 7:
        pcVar4 = "";
        pcVar7 = ", REQUEST-CERTIFICATE";
        break;
      case 8:
        pcVar4 = "";
        pcVar7 = ", CLIENT-CERTIFICATE";
        break;
      default:
        goto switchD_00035c98_caseD_9;
      }
    }
  }
LAB_000359ee:
  bVar8 = 0xfefe < param_2;
  if (param_2 != 0xfeff) {
    bVar8 = 2 < param_2 - 0x300;
  }
  if ((bVar8 && (param_2 != 0xfeff && param_2 - 0x300 != 3)) && (param_2 != 0x100)) {
    pcVar2 = "";
LAB_00035a10:
    BIO_printf(param_7,"%s %s%s [length %04lx]%s%s\n",puVar6,pcVar3,pcVar2,param_5,pcVar7,pcVar4);
    if (param_5 == 0) goto LAB_00035a30;
  }
  else {
    if (param_3 - 0x14U < 3) {
      pcVar2 = *(char **)(CSWTCH_27 + (param_3 - 0x14U) * 4);
      if (param_3 == 0x15) {
        if (param_5 == 2) {
          if (*param_4 == 1) {
            pcVar7 = ", warning";
          }
          else {
            pcVar7 = ", fatal";
            if (*param_4 != 2) {
              pcVar7 = ", ???";
            }
          }
          switch(param_4[1]) {
          case 0:
            pcVar4 = " close_notify";
            break;
          default:
            pcVar4 = " ???";
            break;
          case 10:
            pcVar4 = " unexpected_message";
            break;
          case 0x14:
            pcVar4 = " bad_record_mac";
            break;
          case 0x15:
            pcVar4 = " decryption_failed";
            break;
          case 0x16:
            pcVar4 = " record_overflow";
            break;
          case 0x1e:
            pcVar4 = " decompression_failure";
            break;
          case 0x28:
            pcVar4 = " handshake_failure";
            break;
          case 0x2a:
            pcVar4 = " bad_certificate";
            break;
          case 0x2b:
            pcVar4 = " unsupported_certificate";
            break;
          case 0x2c:
            pcVar4 = " certificate_revoked";
            break;
          case 0x2d:
            pcVar4 = " certificate_expired";
            break;
          case 0x2e:
            pcVar4 = " certificate_unknown";
            break;
          case 0x2f:
            pcVar4 = " illegal_parameter";
            break;
          case 0x30:
            pcVar4 = " unknown_ca";
            break;
          case 0x31:
            pcVar4 = " access_denied";
            break;
          case 0x32:
            pcVar4 = " decode_error";
            break;
          case 0x33:
            pcVar4 = " decrypt_error";
            break;
          case 0x3c:
            pcVar4 = " export_restriction";
            break;
          case 0x46:
            pcVar4 = " protocol_version";
            break;
          case 0x47:
            pcVar4 = " insufficient_security";
            break;
          case 0x50:
            pcVar4 = " internal_error";
            break;
          case 0x5a:
            pcVar4 = " user_canceled";
            break;
          case 100:
            pcVar4 = " no_renegotiation";
            break;
          case 0x6e:
            pcVar4 = " unsupported_extension";
            break;
          case 0x6f:
            pcVar4 = " certificate_unobtainable";
            break;
          case 0x70:
            pcVar4 = " unrecognized_name";
            break;
          case 0x71:
            pcVar4 = " bad_certificate_status_response";
            break;
          case 0x72:
            pcVar4 = " bad_certificate_hash_value";
            break;
          case 0x73:
            pcVar4 = " unknown_psk_identity";
          }
        }
        else {
          pcVar7 = ", ???";
        }
      }
      else {
        if (param_3 != 0x16) goto LAB_00035bc4;
        if ((param_5 == 0) || (0x14 < *param_4)) {
          pcVar7 = "???";
        }
        else {
          pcVar7 = *(char **)(CSWTCH_28 + (uint)*param_4 * 4);
        }
      }
      goto LAB_00035a10;
    }
    pcVar2 = "";
LAB_00035bc4:
    if (param_3 != 0x18) goto LAB_00035a10;
    if (param_5 == 0) {
      BIO_printf(param_7,"%s %s%s [length %04lx]%s%s\n",puVar6,pcVar3,pcVar2,0,", Heartbeat",pcVar4)
      ;
      goto LAB_00035a30;
    }
    if (*param_4 == 1) {
      pcVar7 = ", HeartbeatRequest";
    }
    else {
      pcVar7 = ", HeartbeatResponse";
      if (*param_4 != 2) {
        pcVar7 = ", Heartbeat";
      }
    }
    BIO_printf(param_7,"%s %s%s [length %04lx]%s%s\n",puVar6,pcVar3,pcVar2,param_5,pcVar7,pcVar4);
  }
  uVar5 = 0;
  BIO_printf(param_7,"   ");
  while( true ) {
    pbVar1 = param_4 + uVar5;
    uVar5 = uVar5 + 1;
    BIO_printf(param_7," %02x",(uint)*pbVar1);
    if (param_5 <= uVar5) break;
    if (((uVar5 & 0xf) == 0) && (uVar5 != 0)) {
      BIO_printf(param_7,"\n   ");
    }
  }
  BIO_printf(param_7,"\n");
LAB_00035a30:
  BIO_ctrl(param_7,0xb,0,(void *)0x0);
  return;
}

