
void evp_pkey_set_cb_translate(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = param_2;
  *param_1 = 2;
  param_1[2] = trans_cb;
  return;
}

