
long SSL_CTX_ctrl(SSL_CTX *ctx,int cmd,long larg,void *parg)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  
  switch(cmd) {
  case 0x10:
    ctx->msg_callback_arg = parg;
    return 1;
  default:
                    /* WARNING: Could not recover jumptable at 0x004a84ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar2 = (*ctx->method->ssl_ctx_ctrl)(ctx,cmd,larg,parg);
    return lVar2;
  case 0x14:
                    /* WARNING: Could not recover jumptable at 0x004a84d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar2 = (*(code *)PTR_lh_num_items_006a8330)(ctx->sessions);
    return lVar2;
  case 0x15:
    return (ctx->stats).sess_connect;
  case 0x16:
    return (ctx->stats).sess_connect_good;
  case 0x17:
    return (ctx->stats).sess_connect_renegotiate;
  case 0x18:
    return (ctx->stats).sess_accept;
  case 0x19:
    return (ctx->stats).sess_accept_good;
  case 0x1a:
    return (ctx->stats).sess_accept_renegotiate;
  case 0x1b:
    return (ctx->stats).sess_hit;
  case 0x1c:
    return (ctx->stats).sess_cb_hit;
  case 0x1d:
    return (ctx->stats).sess_miss;
  case 0x1e:
    return (ctx->stats).sess_timeout;
  case 0x1f:
    return (ctx->stats).sess_cache_full;
  case 0x20:
    uVar3 = larg | ctx->options;
    ctx->options = uVar3;
    return uVar3;
  case 0x21:
    uVar3 = larg | ctx->mode;
    ctx->mode = uVar3;
    return uVar3;
  case 0x28:
    return ctx->read_ahead;
  case 0x29:
    lVar2 = ctx->read_ahead;
    ctx->read_ahead = larg;
    return lVar2;
  case 0x2a:
    uVar1 = ctx->session_cache_size;
    ctx->session_cache_size = larg;
    return uVar1;
  case 0x2b:
    return ctx->session_cache_size;
  case 0x2c:
    lVar2 = ctx->session_cache_mode;
    ctx->session_cache_mode = larg;
    return lVar2;
  case 0x2d:
    return ctx->session_cache_mode;
  case 0x32:
    return ctx->max_cert_list;
  case 0x33:
    lVar2 = ctx->max_cert_list;
    ctx->max_cert_list = larg;
    return lVar2;
  case 0x34:
    break;
  case 0x4d:
    uVar3 = ~larg & ctx->options;
    ctx->options = uVar3;
    return uVar3;
  case 0x4e:
    uVar3 = ~larg & ctx->mode;
    ctx->mode = uVar3;
    return uVar3;
  }
  if (larg - 0x200U < 0x3e01) {
    ctx->max_send_fragment = larg;
    return 1;
  }
  return 0;
}

