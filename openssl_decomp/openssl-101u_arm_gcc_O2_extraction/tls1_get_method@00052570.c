
undefined * tls1_get_method(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0x303) {
    return &TLSv1_2_method_data_18413;
  }
  if (param_1 != 0x302) {
    puVar1 = PTR_TLSv1_method_data_18421_0005259c;
    if (param_1 != 0x301) {
      puVar1 = (undefined *)0x0;
    }
    return puVar1;
  }
  return PTR_TLSv1_1_method_data_18417_000525a0;
}

