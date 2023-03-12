
long SSL_ctrl(SSL *ssl,int cmd,long larg,void *parg)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  
  switch(cmd) {
  case 0x10:
    ssl->msg_callback_arg = parg;
    return 1;
  case 0x11:
    iVar1 = dtls1_min_mtu();
    if ((larg < iVar1) || ((ssl->version != 0xfeff && (ssl->version != 0x100)))) {
      larg = 0;
    }
    else {
      *(long *)&ssl->d1->w_msg_hdr = larg;
    }
    return larg;
  default:
                    /* WARNING: Could not recover jumptable at 0x004ab53c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar3 = (*ssl->method->ssl_ctrl)(ssl,cmd,larg,parg);
    return lVar3;
  case 0x20:
    uVar4 = larg | ssl->references;
    ssl->references = uVar4;
    return uVar4;
  case 0x21:
    uVar4 = larg | ssl->options;
    ssl->options = uVar4;
    return uVar4;
  case 0x28:
    return ssl->read_ahead;
  case 0x29:
    lVar3 = ssl->read_ahead;
    ssl->read_ahead = larg;
    return lVar3;
  case 0x32:
    return ssl->mode;
  case 0x33:
    uVar2 = ssl->mode;
    ssl->mode = larg;
    return uVar2;
  case 0x34:
    if (larg - 0x200U < 0x3e01) {
      ssl->client_version = larg;
      return 1;
    }
    break;
  case 0x4c:
    if (ssl->s3 != (ssl3_state_st *)0x0) {
      return ssl->s3->send_connection_binding;
    }
    break;
  case 0x4d:
    uVar4 = ~larg & ssl->references;
    ssl->references = uVar4;
    return uVar4;
  case 0x4e:
    uVar4 = ~larg & ssl->options;
    ssl->options = uVar4;
    return uVar4;
  }
  return 0;
}

