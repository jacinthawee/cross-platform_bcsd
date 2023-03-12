
void tlsext_cb(undefined4 param_1,int param_2,int param_3,char *param_4,int param_5,BIO *param_6)

{
  char *pcVar1;
  char *pcVar2;
  
  if (param_3 == 9) {
    pcVar2 = "cert type";
    goto LAB_00036344;
  }
  if (param_3 < 10) {
    if (param_3 == 4) {
      pcVar2 = "truncated HMAC";
      goto LAB_00036344;
    }
    if (param_3 < 5) {
      if (param_3 == 1) {
        pcVar2 = "max fragment length";
        goto LAB_00036344;
      }
      if (param_3 < 2) {
        pcVar2 = "server name";
        if (param_3 == 0) goto LAB_00036344;
      }
      else {
        if (param_3 == 2) {
          pcVar2 = "client certificate URL";
          goto LAB_00036344;
        }
        if (param_3 == 3) {
          pcVar2 = "trusted CA keys";
          goto LAB_00036344;
        }
      }
    }
    else {
      if (param_3 == 6) {
        pcVar2 = "user mapping";
        goto LAB_00036344;
      }
      if (param_3 < 6) {
        pcVar2 = "status request";
        goto LAB_00036344;
      }
      if (param_3 == 7) {
        pcVar2 = "client authz";
        goto LAB_00036344;
      }
      if (param_3 == 8) {
        pcVar2 = "server authz";
        goto LAB_00036344;
      }
    }
  }
  else {
    if (param_3 == 0xe) {
      pcVar2 = "use SRTP";
      goto LAB_00036344;
    }
    if (param_3 < 0xf) {
      if (param_3 == 0xb) {
        pcVar2 = "EC point formats";
        goto LAB_00036344;
      }
      if (param_3 < 0xb) {
        pcVar2 = "elliptic curves";
        goto LAB_00036344;
      }
      if (param_3 == 0xc) {
        pcVar2 = "SRP";
        goto LAB_00036344;
      }
      if (param_3 == 0xd) {
        pcVar2 = "signature algorithms";
        goto LAB_00036344;
      }
    }
    else {
      if (param_3 == 0x23) {
        pcVar2 = "session ticket";
        goto LAB_00036344;
      }
      if (param_3 < 0x24) {
        if (param_3 == 0xf) {
          pcVar2 = "heartbeat";
          goto LAB_00036344;
        }
      }
      else {
        if (param_3 == 0x3374) {
          pcVar2 = "next protocol";
          goto LAB_00036344;
        }
        if (param_3 == 0xff01) {
          pcVar2 = "renegotiation info";
          goto LAB_00036344;
        }
      }
    }
  }
  pcVar2 = "unknown";
LAB_00036344:
  pcVar1 = "TSA server";
  if (param_2 == 0) {
    pcVar1 = "SSL client";
  }
  BIO_printf(param_6,"TLS %s extension \"%s\" (id=%d), len=%d\n",pcVar1 + 4,pcVar2,param_3,param_5);
  BIO_dump(param_6,param_4,param_5);
  BIO_ctrl(param_6,0xb,0,(void *)0x0);
  return;
}

