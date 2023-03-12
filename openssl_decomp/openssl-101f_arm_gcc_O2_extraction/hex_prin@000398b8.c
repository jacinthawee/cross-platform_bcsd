
void hex_prin(BIO *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  
  if (0 < param_3) {
    pbVar2 = param_2;
    do {
      pbVar1 = pbVar2 + 1;
      BIO_printf(param_1,"%02X ",(uint)*pbVar2);
      pbVar2 = pbVar1;
    } while (pbVar1 != param_2 + param_3);
    return;
  }
  return;
}

