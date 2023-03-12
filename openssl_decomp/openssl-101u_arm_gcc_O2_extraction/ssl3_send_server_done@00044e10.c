
void ssl3_send_server_done(int param_1)

{
  undefined *puVar1;
  
  if (*(int *)(param_1 + 0x34) != 0x2170) {
    ssl3_do_write(param_1,0x16);
    return;
  }
  puVar1 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
  *puVar1 = 0xe;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined4 *)(param_1 + 0x34) = 0x2171;
  *(undefined4 *)(param_1 + 0x44) = 4;
  *(undefined4 *)(param_1 + 0x48) = 0;
  ssl3_do_write(param_1,0x16);
  return;
}

