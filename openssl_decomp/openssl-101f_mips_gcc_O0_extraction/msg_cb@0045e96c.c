
void msg_cb(int param_1,int param_2,int param_3,char *param_4,uint param_5,undefined4 param_6,
           undefined4 param_7)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined *puVar5;
  char *pcVar6;
  uint uVar7;
  
  if (param_1 != 0) {
    puVar5 = &UNK_00640afc;
    if (param_2 != 0x301) goto LAB_0045e9c4;
LAB_0045eac4:
    pcVar6 = "TLS 1.0 ";
LAB_0045e9ec:
    pcVar2 = "";
    pcVar4 = pcVar2;
    goto LAB_0045e9f8;
  }
  puVar5 = &DAT_00640b00;
  if (param_2 == 0x301) goto LAB_0045eac4;
LAB_0045e9c4:
  if (0x301 < param_2) {
    if (param_2 == 0x303) {
      pcVar6 = "TLS 1.2 ";
    }
    else if (param_2 < 0x303) {
      pcVar6 = "TLS 1.1 ";
    }
    else {
      if (param_2 != 0xfeff) goto LAB_0045eae4;
      pcVar6 = "DTLS 1.0 ";
    }
    goto LAB_0045e9ec;
  }
  if (param_2 == 0x100) {
    pcVar6 = "DTLS 1.0 (bad) ";
    goto LAB_0045e9ec;
  }
  if (param_2 == 0x300) {
    pcVar6 = "SSL 3.0 ";
    goto LAB_0045e9ec;
  }
  if (param_2 != 2) {
LAB_0045eae4:
    if (param_2 == 2) {
      if (param_5 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (param_7,"%s %s%s [length %04lx]%s%s\n",puVar5,&DAT_00640b04,"",0,&DAT_00640b04,""
                  );
        goto LAB_0045ea74;
      }
      pcVar6 = "???";
      goto LAB_0045eb00;
    }
    pcVar2 = "";
    pcVar6 = "???";
    pcVar4 = pcVar2;
    goto LAB_0045e9f8;
  }
  if (param_5 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (param_7,"%s %s%s [length %04lx]%s%s\n",puVar5,"SSL 2.0","",0,&DAT_00640b04,"");
    goto LAB_0045ea74;
  }
  pcVar6 = "SSL 2.0";
LAB_0045eb00:
  switch(*param_4) {
  case '\0':
    if (param_5 < 3) {
LAB_0045f158:
      pcVar2 = " ???";
      pcVar4 = ", ERROR:";
    }
    else {
      uVar7 = (uint)(byte)param_4[1] * 0x100 + (uint)(byte)param_4[2];
      if (uVar7 == 2) {
        pcVar2 = " NO-CERTIFICATE-ERROR";
        pcVar4 = ", ERROR:";
      }
      else if (uVar7 < 3) {
        if (uVar7 != 1) goto LAB_0045f158;
        pcVar2 = " NO-CIPHER-ERROR";
        pcVar4 = ", ERROR:";
      }
      else if (uVar7 == 4) {
        pcVar2 = " BAD-CERTIFICATE-ERROR";
        pcVar4 = ", ERROR:";
      }
      else {
        if (uVar7 != 6) goto LAB_0045f158;
        pcVar2 = " UNSUPPORTED-CERTIFICATE-TYPE-ERROR";
        pcVar4 = ", ERROR:";
      }
    }
    break;
  case '\x01':
    pcVar2 = "";
    pcVar4 = ", CLIENT-HELLO";
    pcVar3 = pcVar2;
    goto LAB_0045ea48;
  case '\x02':
    pcVar2 = "";
    pcVar4 = ", CLIENT-MASTER-KEY";
    break;
  case '\x03':
    pcVar2 = "";
    pcVar4 = ", CLIENT-FINISHED";
    break;
  case '\x04':
    pcVar2 = "";
    pcVar4 = ", SERVER-HELLO";
    break;
  case '\x05':
    pcVar2 = "";
    pcVar4 = ", SERVER-VERIFY";
    break;
  case '\x06':
    pcVar2 = "";
    pcVar4 = ", SERVER-FINISHED";
    break;
  case '\a':
    pcVar2 = "";
    pcVar4 = ", REQUEST-CERTIFICATE";
    break;
  case '\b':
    pcVar2 = "";
    pcVar4 = ", CLIENT-CERTIFICATE";
    break;
  default:
    pcVar2 = "";
    pcVar4 = "???";
  }
LAB_0045e9f8:
  if (((3 < param_2 - 0x300U) && (param_2 != 0xfeff)) && (param_2 != 0x100)) {
    pcVar3 = "";
    goto LAB_0045ea48;
  }
  if (param_3 == 0x15) {
    pcVar3 = "Alert";
LAB_0045ecbc:
    if (param_5 == 2) {
      if (*param_4 == '\x01') {
        pcVar4 = ", warning";
      }
      else if (*param_4 == '\x02') {
        pcVar4 = ", fatal";
      }
      else {
        pcVar4 = ", ???";
      }
      switch(param_4[1]) {
      case '\0':
        pcVar2 = " close_notify";
        break;
      default:
        pcVar2 = " ???";
        break;
      case '\n':
        pcVar2 = " unexpected_message";
        break;
      case '\x14':
        pcVar2 = " bad_record_mac";
        break;
      case '\x15':
        pcVar2 = " decryption_failed";
        break;
      case '\x16':
        pcVar2 = " record_overflow";
        break;
      case '\x1e':
        pcVar2 = " decompression_failure";
        break;
      case '(':
        pcVar2 = " handshake_failure";
        break;
      case '*':
        pcVar2 = " bad_certificate";
        break;
      case '+':
        pcVar2 = " unsupported_certificate";
        break;
      case ',':
        pcVar2 = " certificate_revoked";
        break;
      case '-':
        pcVar2 = " certificate_expired";
        break;
      case '.':
        pcVar2 = " certificate_unknown";
        break;
      case '/':
        pcVar2 = " illegal_parameter";
        break;
      case '0':
        pcVar2 = " unknown_ca";
        break;
      case '1':
        pcVar2 = " access_denied";
        break;
      case '2':
        pcVar2 = " decode_error";
        break;
      case '3':
        pcVar2 = " decrypt_error";
        break;
      case '<':
        pcVar2 = " export_restriction";
        break;
      case 'F':
        pcVar2 = " protocol_version";
        break;
      case 'G':
        pcVar2 = " insufficient_security";
        break;
      case 'P':
        pcVar2 = " internal_error";
        break;
      case 'Z':
        pcVar2 = " user_canceled";
        break;
      case 'd':
        pcVar2 = " no_renegotiation";
        break;
      case 'n':
        pcVar2 = " unsupported_extension";
        break;
      case 'o':
        pcVar2 = " certificate_unobtainable";
        break;
      case 'p':
        pcVar2 = " unrecognized_name";
        break;
      case 'q':
        pcVar2 = " bad_certificate_status_response";
        break;
      case 'r':
        pcVar2 = " bad_certificate_hash_value";
        break;
      case 's':
        pcVar2 = " unknown_psk_identity";
      }
    }
    else {
      pcVar4 = ", ???";
    }
LAB_0045ea3c:
    if (param_3 == 0x18) {
      if (param_5 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (param_7,"%s %s%s [length %04lx]%s%s\n",puVar5,pcVar6,pcVar3,0,", Heartbeat",
                   pcVar2);
                    /* WARNING: Could not recover jumptable at 0x0045ed64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)PTR_BIO_ctrl_006a7f18)(param_7,0xb,0,0);
        return;
      }
      if (*param_4 == '\x01') {
        pcVar4 = ", HeartbeatRequest";
      }
      else if (*param_4 == '\x02') {
        pcVar4 = ", HeartbeatResponse";
      }
      else {
        pcVar4 = ", Heartbeat";
      }
      (*(code *)PTR_BIO_printf_006a7f38)
                (param_7,"%s %s%s [length %04lx]%s%s\n",puVar5,pcVar6,pcVar3,param_5,pcVar4,pcVar2);
      goto LAB_0045eb90;
    }
  }
  else {
    if (param_3 == 0x16) {
      pcVar3 = "Handshake";
    }
    else if (param_3 == 0x14) {
      pcVar3 = "ChangeCipherSpec";
    }
    else {
      if (param_3 == 0x15) {
        pcVar3 = "";
        goto LAB_0045ecbc;
      }
      pcVar3 = "";
    }
    if (param_3 != 0x16) goto LAB_0045ea3c;
    if (param_5 == 0) {
LAB_0045eca0:
      pcVar4 = "???";
    }
    else {
      switch(*param_4) {
      case '\0':
        pcVar4 = ", HelloRequest";
        break;
      case '\x01':
        pcVar4 = ", ClientHello";
        break;
      case '\x02':
        pcVar4 = ", ServerHello";
        break;
      case '\x03':
        pcVar4 = ", HelloVerifyRequest";
        break;
      default:
        goto LAB_0045eca0;
      case '\v':
        pcVar4 = ", Certificate";
        break;
      case '\f':
        pcVar4 = ", ServerKeyExchange";
        break;
      case '\r':
        pcVar4 = ", CertificateRequest";
        break;
      case '\x0e':
        pcVar4 = ", ServerHelloDone";
        break;
      case '\x0f':
        pcVar4 = ", CertificateVerify";
        break;
      case '\x10':
        pcVar4 = ", ClientKeyExchange";
        break;
      case '\x14':
        pcVar4 = ", Finished";
      }
    }
  }
LAB_0045ea48:
  (*(code *)PTR_BIO_printf_006a7f38)
            (param_7,"%s %s%s [length %04lx]%s%s\n",puVar5,pcVar6,pcVar3,param_5,pcVar4,pcVar2);
  if (param_5 == 0) {
LAB_0045ea74:
                    /* WARNING: Could not recover jumptable at 0x0045eaa4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_BIO_ctrl_006a7f18)(param_7,0xb,0,0);
    return;
  }
LAB_0045eb90:
  (*(code *)PTR_BIO_printf_006a7f38)(param_7,&DAT_0066a8f4);
  uVar7 = 0;
  do {
    if (((uVar7 & 0xf) == 0) && (uVar7 != 0)) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_7,&DAT_00641038);
    }
    uVar7 = uVar7 + 1;
    cVar1 = *param_4;
    param_4 = param_4 + 1;
    (*(code *)PTR_BIO_printf_006a7f38)(param_7," %02x",cVar1);
  } while (uVar7 < param_5);
  (*(code *)PTR_BIO_printf_006a7f38)(param_7,"\n");
                    /* WARNING: Could not recover jumptable at 0x0045ec4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_ctrl_006a7f18)(param_7,0xb,0,0);
  return;
}

