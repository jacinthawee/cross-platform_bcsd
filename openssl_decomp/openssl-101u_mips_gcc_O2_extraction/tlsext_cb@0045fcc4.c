
void tlsext_cb(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6)

{
  char *pcVar1;
  char *pcVar2;
  
  if (param_3 == 9) {
    pcVar2 = "cert type";
    goto joined_r0x0045fd40;
  }
  if (param_3 < 10) {
    if (param_3 == 4) {
      pcVar2 = "truncated HMAC";
      goto joined_r0x0045fd40;
    }
    if (param_3 < 5) {
      if (param_3 == 1) {
        pcVar2 = "max fragment length";
        goto joined_r0x0045fd40;
      }
      if (param_3 < 2) {
        if (param_3 == 0) {
          pcVar2 = "server name";
          goto joined_r0x0045fd40;
        }
      }
      else {
        if (param_3 == 2) {
          pcVar2 = "client certificate URL";
          goto joined_r0x0045fd40;
        }
        if (param_3 == 3) {
          pcVar2 = "trusted CA keys";
          goto joined_r0x0045fd40;
        }
      }
    }
    else {
      if (param_3 == 6) {
        pcVar2 = "user mapping";
        goto joined_r0x0045fd40;
      }
      if (param_3 < 6) {
        pcVar2 = "status request";
        goto joined_r0x0045fd40;
      }
      if (param_3 == 7) {
        pcVar2 = "client authz";
        goto joined_r0x0045fd40;
      }
      if (param_3 == 8) {
        pcVar2 = "server authz";
        goto joined_r0x0045fd40;
      }
    }
  }
  else {
    if (param_3 == 0xe) {
      pcVar2 = "use SRTP";
      goto joined_r0x0045fd40;
    }
    if (param_3 < 0xf) {
      if (param_3 == 0xb) {
        pcVar2 = "EC point formats";
        goto joined_r0x0045fd40;
      }
      if (param_3 < 0xb) {
        pcVar2 = "elliptic curves";
        goto joined_r0x0045fd40;
      }
      if (param_3 == 0xc) {
        pcVar2 = "SRP";
        goto joined_r0x0045fd40;
      }
      if (param_3 == 0xd) {
        pcVar2 = "signature algorithms";
        goto joined_r0x0045fd40;
      }
    }
    else {
      if (param_3 == 0x23) {
        pcVar2 = "session ticket";
        goto joined_r0x0045fd40;
      }
      if (param_3 < 0x24) {
        if (param_3 == 0xf) {
          pcVar2 = "heartbeat";
          goto joined_r0x0045fd40;
        }
        if (param_3 == 0x15) {
          pcVar2 = "TLS padding";
          goto joined_r0x0045fd40;
        }
      }
      else {
        if (param_3 == 0x3374) {
          pcVar2 = "next protocol";
          goto joined_r0x0045fd40;
        }
        if (param_3 == 0xff01) {
          pcVar2 = "renegotiation info";
          goto joined_r0x0045fd40;
        }
      }
    }
  }
  pcVar2 = "unknown";
joined_r0x0045fd40:
  if (param_2 == 0) {
    pcVar1 = "SSL client";
  }
  else {
    pcVar1 = "TSA server";
  }
  (*(code *)PTR_BIO_printf_006a6e38)
            (param_6,"TLS %s extension \"%s\" (id=%d), len=%d\n",pcVar1 + 4,pcVar2,param_3,param_5);
  (*(code *)PTR_BIO_dump_006a7648)(param_6,param_4,param_5);
                    /* WARNING: Could not recover jumptable at 0x0045fdac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_ctrl_006a6e18)(param_6,0xb,0,0);
  return;
}

