
int ssl3_write(SSL *param_1,void *param_2,int param_3)

{
  int *piVar1;
  BIO *bp;
  int iVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  ssl3_state_st *psVar6;
  bool bVar7;
  
  iVar2 = param_3;
  piVar1 = __errno_location();
  psVar6 = param_1->s3;
  *piVar1 = 0;
  if (((psVar6->renegotiate != 0) && ((psVar6->rbuf).left == 0)) &&
     (iVar5 = (psVar6->wbuf).left, iVar5 == 0)) {
    uVar3 = SSL_state(param_1);
    psVar6 = param_1->s3;
    bVar7 = (uVar3 & 0x3000) == 0;
    if (bVar7) {
      iVar5 = 0x3004;
      iVar2 = psVar6->num_renegotiations;
    }
    if (bVar7) {
      param_1->state = iVar5;
      iVar5 = psVar6->total_renegotiations;
      iVar2 = iVar2 + 1;
    }
    if (bVar7) {
      psVar6->renegotiate = 0;
      iVar5 = iVar5 + 1;
    }
    if (bVar7) {
      psVar6->num_renegotiations = iVar2;
    }
    if (bVar7) {
      psVar6->total_renegotiations = iVar5;
    }
  }
  if ((-1 < psVar6->flags << 0x1d) || (bp = param_1->wbio, bp != param_1->bbio)) {
                    /* WARNING: Could not recover jumptable at 0x0004c9ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*param_1->method->ssl_write_bytes)(param_1,0x17,param_2,param_3);
    return iVar2;
  }
  if (psVar6->delay_buf_pop_ret == 0) {
    iVar2 = ssl3_write_bytes(param_1,0x17,param_2,param_3);
    if (iVar2 < 1) {
      return iVar2;
    }
    bp = param_1->wbio;
    param_1->s3->delay_buf_pop_ret = iVar2;
  }
  param_1->rwstate = 2;
  lVar4 = BIO_ctrl(bp,0xb,0,(void *)0x0);
  if (lVar4 < 1) {
    return lVar4;
  }
  param_1->rwstate = 1;
  ssl_free_wbio_buffer(param_1);
  psVar6 = param_1->s3;
  iVar2 = psVar6->delay_buf_pop_ret;
  psVar6->delay_buf_pop_ret = 0;
  psVar6->flags = psVar6->flags & 0xfffffffb;
  return iVar2;
}

