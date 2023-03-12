
undefined4 tls1_ec_curve_id2nid(int param_1)

{
  if (param_1 - 1U < 0x19) {
    return *(undefined4 *)(nid_list + (param_1 - 1U) * 4);
  }
  return 0;
}

