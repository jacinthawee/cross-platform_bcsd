
undefined1 * tls1_get_method(int param_1)

{
  if (param_1 == 0x303) {
    return TLSv1_2_method_data_15782;
  }
  if (param_1 != 0x302) {
    if (param_1 == 0x301) {
      return TLSv1_method_data_15790;
    }
    return (undefined1 *)0x0;
  }
  return TLSv1_1_method_data_15786;
}

