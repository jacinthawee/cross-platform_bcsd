
void CRYPTO_ccm128_init(undefined4 *param_1,char param_2,char param_3,undefined4 param_4,
                       undefined4 param_5)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(byte *)param_1 = param_3 - 1U & 7 | param_2 * '\x04' - 8U & 0x38;
  param_1[10] = param_5;
  param_1[0xb] = param_4;
  return;
}

