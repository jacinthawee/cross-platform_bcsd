
void MDC2_Init(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined *)(param_1 + 3) = 0x52;
  *(undefined *)((int)param_1 + 0xd) = 0x52;
  param_1[7] = 1;
  *(undefined *)((int)param_1 + 0xe) = 0x52;
  *(undefined *)((int)param_1 + 0xf) = 0x52;
  *(undefined *)(param_1 + 4) = 0x52;
  *(undefined *)((int)param_1 + 0x11) = 0x52;
  *(undefined *)((int)param_1 + 0x12) = 0x52;
  *(undefined *)((int)param_1 + 0x13) = 0x52;
  *(undefined *)(param_1 + 5) = 0x25;
  *(undefined *)((int)param_1 + 0x15) = 0x25;
  *(undefined *)((int)param_1 + 0x16) = 0x25;
  *(undefined *)((int)param_1 + 0x17) = 0x25;
  *(undefined *)(param_1 + 6) = 0x25;
  *(undefined *)((int)param_1 + 0x19) = 0x25;
  *(undefined *)((int)param_1 + 0x1a) = 0x25;
  *(undefined *)((int)param_1 + 0x1b) = 0x25;
  return;
}

