
int ssl3_write(SSL *param_1,void *param_2,int param_3)

{
  int *piVar1;
  ssl3_state_st *psVar2;
  int iVar3;
  uint uVar4;
  BIO *bp;
  
  piVar1 = __errno_location();
  *piVar1 = 0;
  psVar2 = param_1->s3;
  if (((psVar2->renegotiate != 0) && ((psVar2->rbuf).left == 0)) && ((psVar2->wbuf).left == 0)) {
    uVar4 = SSL_state(param_1);
    if ((uVar4 & 0x3000) == 0) {
      psVar2 = param_1->s3;
      param_1->state = 0x3004;
      psVar2->renegotiate = 0;
      psVar2->num_renegotiations = psVar2->num_renegotiations + 1;
      psVar2->total_renegotiations = psVar2->total_renegotiations + 1;
    }
    else {
      psVar2 = param_1->s3;
    }
  }
  if (((*(byte *)&psVar2->flags & 4) == 0) || (bp = param_1->wbio, bp != param_1->bbio)) {
    iVar3 = (*param_1->method->ssl_write_bytes)(param_1,0x17,param_2,param_3);
  }
  else {
    if (psVar2->delay_buf_pop_ret == 0) {
      iVar3 = ssl3_write_bytes(param_1,0x17,param_2,param_3);
      if (iVar3 < 1) {
        return iVar3;
      }
      param_1->s3->delay_buf_pop_ret = iVar3;
      bp = param_1->wbio;
    }
    param_1->rwstate = 2;
    iVar3 = BIO_ctrl(bp,0xb,0,(void *)0x0);
    if (0 < iVar3) {
      param_1->rwstate = 1;
      ssl_free_wbio_buffer(param_1);
      psVar2 = param_1->s3;
      iVar3 = psVar2->delay_buf_pop_ret;
      psVar2->flags = psVar2->flags & 0xfffffffb;
      psVar2->delay_buf_pop_ret = 0;
    }
  }
  return iVar3;
}

