
undefined1 * tls1_get_server_method(int param_1)

{
  if (param_1 == 0x303) {
    return TLSv1_2_server_method_data_15817;
  }
  if (param_1 != 0x302) {
    if (param_1 == 0x301) {
      return TLSv1_server_method_data_15825;
    }
    return (undefined1 *)0x0;
  }
  return TLSv1_1_server_method_data_15821;
}

