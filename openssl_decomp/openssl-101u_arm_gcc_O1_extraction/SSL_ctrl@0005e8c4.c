
long SSL_ctrl(SSL *ssl,int cmd,long larg,void *parg)

{
  long lVar1;
  ssl3_state_st *psVar2;
  
  switch(cmd) {
  case 0x10:
    ssl->msg_callback_arg = parg;
    psVar2 = (ssl3_state_st *)0x1;
    break;
  default:
                    /* WARNING: Could not recover jumptable at 0x0005e99e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar1 = (*ssl->method->ssl_ctrl)(ssl,cmd,larg,parg);
    return lVar1;
  case 0x20:
    psVar2 = (ssl3_state_st *)(larg | ssl->references);
    ssl->references = (int)psVar2;
    break;
  case 0x21:
    psVar2 = (ssl3_state_st *)(larg | ssl->options);
    ssl->options = (ulong)psVar2;
    break;
  case 0x28:
    psVar2 = (ssl3_state_st *)ssl->read_ahead;
    break;
  case 0x29:
    psVar2 = (ssl3_state_st *)ssl->read_ahead;
    ssl->read_ahead = larg;
    break;
  case 0x32:
    psVar2 = (ssl3_state_st *)ssl->mode;
    break;
  case 0x33:
    psVar2 = (ssl3_state_st *)ssl->mode;
    ssl->mode = larg;
    break;
  case 0x34:
    if (larg - 0x200U < 0x3e01) {
      ssl->client_version = larg;
      psVar2 = (ssl3_state_st *)0x1;
    }
    else {
      psVar2 = (ssl3_state_st *)0x0;
    }
    break;
  case 0x4c:
    psVar2 = ssl->s3;
    if (psVar2 != (ssl3_state_st *)0x0) {
      psVar2 = (ssl3_state_st *)psVar2->send_connection_binding;
    }
    break;
  case 0x4d:
    psVar2 = (ssl3_state_st *)(ssl->references & ~larg);
    ssl->references = (int)psVar2;
    break;
  case 0x4e:
    psVar2 = (ssl3_state_st *)(ssl->options & ~larg);
    ssl->options = (ulong)psVar2;
  }
  return (long)psVar2;
}

