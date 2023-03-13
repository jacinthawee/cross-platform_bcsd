
undefined4 ssl3_renegotiate_check(SSL *param_1)

{
  ssl3_state_st *psVar1;
  uint uVar2;
  
  psVar1 = param_1->s3;
  if ((((psVar1->renegotiate != 0) && ((psVar1->rbuf).left == 0)) && ((psVar1->wbuf).left == 0)) &&
     (uVar2 = SSL_state(param_1), (uVar2 & 0x3000) == 0)) {
    psVar1 = param_1->s3;
    param_1->state = 0x3004;
    psVar1->renegotiate = 0;
    psVar1->num_renegotiations = psVar1->num_renegotiations + 1;
    psVar1->total_renegotiations = psVar1->total_renegotiations + 1;
    return 1;
  }
  return 0;
}

