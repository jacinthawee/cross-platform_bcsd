
void dtls1_send_hello_request(int param_1)

{
  if (*(int *)(param_1 + 0x34) != 0x2120) {
    dtls1_do_write(param_1,0x16);
    return;
  }
  dtls1_set_message_header(param_1,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 4),0,0,0,0);
  *(undefined4 *)(param_1 + 0x34) = 0x2121;
  *(undefined4 *)(param_1 + 0x44) = 0xc;
  *(undefined4 *)(param_1 + 0x48) = 0;
  dtls1_do_write(param_1,0x16);
  return;
}

