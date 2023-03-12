
void ssl3_read(SSL *param_1,uchar *param_2,int param_3)

{
  int *piVar1;
  ssl3_state_st *psVar2;
  int iVar3;
  uint uVar4;
  
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
  psVar2->in_read_app_data = 1;
  iVar3 = (*param_1->method->ssl_read_bytes)(param_1,0x17,param_2,param_3,0);
  if ((iVar3 == -1) && (param_1->s3->in_read_app_data == 2)) {
    param_1->in_handshake = param_1->in_handshake + 1;
    (*param_1->method->ssl_read_bytes)(param_1,0x17,param_2,param_3,0);
    param_1->in_handshake = param_1->in_handshake + -1;
  }
  else {
    param_1->s3->in_read_app_data = 0;
  }
  return;
}

