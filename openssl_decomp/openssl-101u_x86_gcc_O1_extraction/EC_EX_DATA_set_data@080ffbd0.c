
undefined4 EC_EX_DATA_set_data(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  puVar1 = (undefined4 *)*param_1;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      if (param_2 != 0) {
        puVar1 = (undefined4 *)CRYPTO_malloc(0x14,"ec_lib.c",0x21e);
        if (puVar1 == (undefined4 *)0x0) {
          return 0;
        }
        puVar1[2] = param_3;
        puVar1[3] = param_4;
        puVar1[1] = param_2;
        puVar1[4] = param_5;
        *puVar1 = *param_1;
        *param_1 = puVar1;
      }
      return 1;
    }
    if (((puVar1[2] == param_3) && (puVar1[3] == param_4)) && (puVar1[4] == param_5)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  ERR_put_error(0x10,0xd3,0x6c,"ec_lib.c",0x215);
  return 0;
}

