
void dtls1_send_server_done(int param_1)

{
  if (*(int *)(param_1 + 0x34) == 0x2170) {
    dtls1_set_message_header(param_1,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 4),0xe,0,0,0);
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0x2171;
    *(undefined4 *)(param_1 + 0x44) = 0xc;
    dtls1_buffer_message(param_1,0);
  }
  dtls1_do_write(param_1,0x16);
  return;
}

