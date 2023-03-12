
long tlsext_cb(undefined4 param_1,int param_2,int param_3,char *param_4,int param_5,BIO *param_6)

{
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var1;
  char *pcVar2;
  long lVar3;
  char *pcVar4;
  
  if (param_3 == 9) {
    pcVar4 = "cert type";
  }
  else {
    if (param_3 < 10) {
      if (param_3 == 4) {
        pcVar4 = "truncated HMAC";
        goto LAB_0807e062;
      }
      if (param_3 < 5) {
        pcVar4 = "max fragment length";
        if (param_3 == 1) goto LAB_0807e062;
        if (param_3 < 2) {
          pcVar4 = "server name";
          if (param_3 == 0) goto LAB_0807e062;
        }
        else {
          pcVar4 = "client certificate URL";
          if ((param_3 == 2) || (pcVar4 = "trusted CA keys", param_3 == 3)) goto LAB_0807e062;
        }
      }
      else {
        pcVar4 = "user mapping";
        if ((((param_3 == 6) || (pcVar4 = "status request", param_3 < 6)) ||
            (pcVar4 = "client authz", param_3 == 7)) || (pcVar4 = "server authz", param_3 == 8))
        goto LAB_0807e062;
      }
    }
    else {
      if (param_3 == 0xe) {
        pcVar4 = "use SRTP";
        goto LAB_0807e062;
      }
      if (param_3 < 0xf) {
        pcVar4 = "EC point formats";
        if ((param_3 == 0xb) ||
           (((pcVar4 = "elliptic curves", param_3 < 0xb || (pcVar4 = "SRP", param_3 == 0xc)) ||
            (pcVar4 = "signature algorithms", param_3 == 0xd)))) goto LAB_0807e062;
      }
      else {
        pcVar4 = "session ticket";
        if (param_3 == 0x23) goto LAB_0807e062;
        if (param_3 < 0x24) {
          pcVar4 = "heartbeat";
          if (param_3 == 0xf) goto LAB_0807e062;
        }
        else {
          pcVar4 = "next protocol";
          if ((param_3 == 0x3374) || (pcVar4 = "renegotiation info", param_3 == 0xff01))
          goto LAB_0807e062;
        }
      }
    }
    pcVar4 = "unknown";
  }
LAB_0807e062:
  pcVar2 = "TSA server";
  if (param_2 == 0) {
    pcVar2 = "SSL client";
  }
  BIO_printf(param_6,"TLS %s extension \"%s\" (id=%d), len=%d\n",pcVar2 + 4,pcVar4,param_3,param_5);
  BIO_dump(param_6,param_4,param_5);
  if (param_6 == (BIO *)0x0) {
    return 0;
  }
  if ((param_6->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = param_6->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    lVar3 = -2;
  }
  else {
    p_Var1 = param_6->callback;
    if (p_Var1 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08117b57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar3 = (*UNRECOVERED_JUMPTABLE)(param_6,0xb,0,(void *)0x0);
      return lVar3;
    }
    lVar3 = (*p_Var1)(param_6,6,(char *)0x0,0xb,0,1);
    if (0 < lVar3) {
      lVar3 = (*param_6->method->ctrl)(param_6,0xb,0,(void *)0x0);
      lVar3 = (*p_Var1)(param_6,0x86,(char *)0x0,0xb,0,lVar3);
    }
  }
  return lVar3;
}

