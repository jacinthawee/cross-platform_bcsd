
long ssl_callback_ctrl(int param_1,int param_2,fp *param_3)

{
  long lVar1;
  
  if (param_2 != 0xe) {
    lVar1 = BIO_callback_ctrl((**(SSL ***)(param_1 + 0x20))->rbio,param_2,param_3);
    return lVar1;
  }
  SSL_set_info_callback(**(SSL ***)(param_1 + 0x20),(cb *)param_3);
  return 1;
}

