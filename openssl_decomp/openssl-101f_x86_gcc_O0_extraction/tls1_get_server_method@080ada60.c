
undefined1 * tls1_get_server_method(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0x303) {
    return TLSv1_2_server_method_data_15797;
  }
  if (param_1 != 0x302) {
    puVar1 = TLSv1_server_method_data_15805;
    if (param_1 != 0x301) {
      puVar1 = (undefined1 *)0x0;
    }
    return puVar1;
  }
  return TLSv1_1_server_method_data_15801;
}

