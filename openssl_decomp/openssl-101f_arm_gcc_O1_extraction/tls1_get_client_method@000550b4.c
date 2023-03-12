
undefined * tls1_get_client_method(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0x303) {
    return &TLSv1_2_client_method_data_18448;
  }
  if (param_1 != 0x302) {
    puVar1 = PTR_TLSv1_client_method_data_18456_000550e0;
    if (param_1 != 0x301) {
      puVar1 = (undefined *)0x0;
    }
    return puVar1;
  }
  return PTR_TLSv1_1_client_method_data_18452_000550e4;
}

