
int ssl2_pending(SSL *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = SSL_state(param_1);
  iVar2 = 0;
  if ((uVar1 & 0x3000) == 0) {
    iVar2 = param_1->s2->ract_data_length;
  }
  return iVar2;
}

