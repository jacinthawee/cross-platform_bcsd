
bool conn_callback_ctrl(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 0xe) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x28) = param_3;
  }
  return param_2 == 0xe;
}

