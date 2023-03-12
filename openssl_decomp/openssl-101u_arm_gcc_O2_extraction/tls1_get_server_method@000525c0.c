
undefined * tls1_get_server_method(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0x303) {
    return &TLSv1_2_server_method_data_18478;
  }
  if (param_1 != 0x302) {
    puVar1 = PTR_TLSv1_server_method_data_18486_000525ec;
    if (param_1 != 0x301) {
      puVar1 = (undefined *)0x0;
    }
    return puVar1;
  }
  return PTR_TLSv1_1_server_method_data_18482_000525f0;
}

