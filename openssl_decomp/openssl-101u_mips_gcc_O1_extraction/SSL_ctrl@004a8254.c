
long SSL_ctrl(SSL *ssl,int cmd,long larg,void *parg)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  
  switch(cmd) {
  case 0x10:
    ssl->msg_callback_arg = parg;
    return 1;
  default:
                    /* WARNING: Could not recover jumptable at 0x004a833c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar2 = (*ssl->method->ssl_ctrl)(ssl,cmd,larg,parg);
    return lVar2;
  case 0x20:
    uVar3 = larg | ssl->references;
    ssl->references = uVar3;
    return uVar3;
  case 0x21:
    uVar3 = larg | ssl->options;
    ssl->options = uVar3;
    return uVar3;
  case 0x28:
    return ssl->read_ahead;
  case 0x29:
    lVar2 = ssl->read_ahead;
    ssl->read_ahead = larg;
    return lVar2;
  case 0x32:
    return ssl->mode;
  case 0x33:
    uVar1 = ssl->mode;
    ssl->mode = larg;
    return uVar1;
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
    uVar3 = ~larg & ssl->references;
    ssl->references = uVar3;
    return uVar3;
  case 0x4e:
    uVar3 = ~larg & ssl->options;
    ssl->options = uVar3;
    return uVar3;
  }
  return 0;
}

