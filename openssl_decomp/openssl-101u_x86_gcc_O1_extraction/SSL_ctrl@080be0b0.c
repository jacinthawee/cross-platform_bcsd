
long SSL_ctrl(SSL *ssl,int cmd,long larg,void *parg)

{
  uint uVar1;
  long lVar2;
  
  switch(cmd) {
  case 0x10:
    ssl->msg_callback_arg = parg;
    uVar1 = 1;
    break;
  default:
                    /* WARNING: Could not recover jumptable at 0x080be1b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar2 = (*ssl->method->ssl_ctrl)(ssl,cmd,larg,parg);
    return lVar2;
  case 0x20:
    uVar1 = ssl->references | larg;
    ssl->references = uVar1;
    break;
  case 0x21:
    uVar1 = ssl->options | larg;
    ssl->options = uVar1;
    break;
  case 0x28:
    uVar1 = ssl->read_ahead;
    break;
  case 0x29:
    uVar1 = ssl->read_ahead;
    ssl->read_ahead = larg;
    break;
  case 0x32:
    uVar1 = ssl->mode;
    break;
  case 0x33:
    uVar1 = ssl->mode;
    ssl->mode = larg;
    break;
  case 0x34:
    uVar1 = 0;
    if (larg - 0x200U < 0x3e01) {
      ssl->client_version = larg;
      uVar1 = 1;
    }
    break;
  case 0x4c:
    if (ssl->s3 == (ssl3_state_st *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = ssl->s3->send_connection_binding;
    }
    break;
  case 0x4d:
    uVar1 = ~larg & ssl->references;
    ssl->references = uVar1;
    break;
  case 0x4e:
    uVar1 = ~larg & ssl->options;
    ssl->options = uVar1;
  }
  return uVar1;
}

