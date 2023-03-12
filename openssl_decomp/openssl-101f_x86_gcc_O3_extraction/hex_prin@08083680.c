
void hex_prin(BIO *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  
  pbVar1 = param_2 + param_3;
  if (0 < param_3) {
    do {
      bVar2 = *param_2;
      param_2 = param_2 + 1;
      BIO_printf(param_1,"%02X ",(uint)bVar2);
    } while (param_2 != pbVar1);
  }
  return;
}

