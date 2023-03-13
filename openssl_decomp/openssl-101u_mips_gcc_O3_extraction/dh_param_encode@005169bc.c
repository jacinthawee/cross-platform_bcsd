
void dh_param_encode(int param_1,uchar **param_2)

{
  i2d_DHparams(*(DH **)(param_1 + 0x14),param_2);
  return;
}

