
long SSL_ctrl(SSL *ssl,int cmd,long larg,void *parg)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  switch(cmd) {
  case 0x10:
    ssl->msg_callback_arg = parg;
    larg = 1;
    break;
  case 0x11:
    iVar2 = dtls1_min_mtu();
    if ((larg < iVar2) || ((ssl->version != 0x100 && (ssl->version != 0xfeff)))) {
      return 0;
    }
    *(long *)&ssl->d1->w_msg_hdr = larg;
    break;
  default:
                    /* WARNING: Could not recover jumptable at 0x080c0acb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar3 = (*ssl->method->ssl_ctrl)(ssl,cmd,larg,parg);
    return lVar3;
  case 0x20:
    larg = ssl->references | larg;
    ssl->references = larg;
    break;
  case 0x21:
    larg = ssl->options | larg;
    ssl->options = larg;
    break;
  case 0x28:
    larg = ssl->read_ahead;
    break;
  case 0x29:
    uVar1 = ssl->read_ahead;
    ssl->read_ahead = larg;
    larg = uVar1;
    break;
  case 0x32:
    larg = ssl->mode;
    break;
  case 0x33:
    uVar1 = ssl->mode;
    ssl->mode = larg;
    larg = uVar1;
    break;
  case 0x34:
    if (0x3e00 < larg - 0x200U) {
      return 0;
    }
    ssl->client_version = larg;
    larg = 1;
    break;
  case 0x4c:
    if (ssl->s3 == (ssl3_state_st *)0x0) {
      return 0;
    }
    larg = ssl->s3->send_connection_binding;
    break;
  case 0x4d:
    larg = ~larg & ssl->references;
    ssl->references = larg;
    break;
  case 0x4e:
    larg = ~larg & ssl->options;
    ssl->options = larg;
  }
  return larg;
}

