
long SSL_CTX_ctrl(SSL_CTX *ctx,int cmd,long larg,void *parg)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  switch(cmd) {
  case 0x10:
    ctx->msg_callback_arg = parg;
    uVar1 = 1;
    break;
  default:
                    /* WARNING: Could not recover jumptable at 0x080be417. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar3 = (*ctx->method->ssl_ctx_ctrl)(ctx,cmd,larg,parg);
    return lVar3;
  case 0x14:
    uVar2 = lh_num_items((_LHASH *)ctx->sessions);
    return uVar2;
  case 0x15:
    uVar1 = (ctx->stats).sess_connect;
    break;
  case 0x16:
    uVar1 = (ctx->stats).sess_connect_good;
    break;
  case 0x17:
    uVar1 = (ctx->stats).sess_connect_renegotiate;
    break;
  case 0x18:
    uVar1 = (ctx->stats).sess_accept;
    break;
  case 0x19:
    uVar1 = (ctx->stats).sess_accept_good;
    break;
  case 0x1a:
    uVar1 = (ctx->stats).sess_accept_renegotiate;
    break;
  case 0x1b:
    uVar1 = (ctx->stats).sess_hit;
    break;
  case 0x1c:
    uVar1 = (ctx->stats).sess_cb_hit;
    break;
  case 0x1d:
    uVar1 = (ctx->stats).sess_miss;
    break;
  case 0x1e:
    uVar1 = (ctx->stats).sess_timeout;
    break;
  case 0x1f:
    uVar1 = (ctx->stats).sess_cache_full;
    break;
  case 0x20:
    uVar1 = ctx->options | larg;
    ctx->options = uVar1;
    break;
  case 0x21:
    uVar1 = ctx->mode | larg;
    ctx->mode = uVar1;
    break;
  case 0x28:
    uVar1 = ctx->read_ahead;
    break;
  case 0x29:
    uVar1 = ctx->read_ahead;
    ctx->read_ahead = larg;
    break;
  case 0x2a:
    uVar1 = ctx->session_cache_size;
    ctx->session_cache_size = larg;
    break;
  case 0x2b:
    uVar1 = ctx->session_cache_size;
    break;
  case 0x2c:
    uVar1 = ctx->session_cache_mode;
    ctx->session_cache_mode = larg;
    break;
  case 0x2d:
    uVar1 = ctx->session_cache_mode;
    break;
  case 0x32:
    uVar1 = ctx->max_cert_list;
    break;
  case 0x33:
    uVar1 = ctx->max_cert_list;
    ctx->max_cert_list = larg;
    break;
  case 0x34:
    uVar1 = 0;
    if (larg - 0x200U < 0x3e01) {
      ctx->max_send_fragment = larg;
      uVar1 = 1;
    }
    break;
  case 0x4d:
    uVar1 = ~larg & ctx->options;
    ctx->options = uVar1;
    break;
  case 0x4e:
    uVar1 = ~larg & ctx->mode;
    ctx->mode = uVar1;
  }
  return uVar1;
}

