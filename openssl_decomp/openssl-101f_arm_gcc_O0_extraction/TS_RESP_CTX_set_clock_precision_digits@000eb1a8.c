
bool TS_RESP_CTX_set_clock_precision_digits(int param_1,uint param_2)

{
  if (param_2 < 7) {
    *(uint *)(param_1 + 0x24) = param_2;
  }
  return param_2 < 7;
}

